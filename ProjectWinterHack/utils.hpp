#pragma once
#include <Psapi.h>

#define VK_H 0x48

#define INRANGE(x,a,b)    (x >= a && x <= b) 
#define getBits( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )    (getBits(x[0]) << 4 | getBits(x[1]))

namespace Utilities
{
    namespace Memory
    {
        DWORD64 moduleBase = (DWORD64)GetModuleHandle(L"GameAssembly.dll");

        DWORD64 CalcRelativeOffset(DWORD64 address)
        {
            if (address < moduleBase)
                address += moduleBase;

            return *(int32_t*)address + (address + 4) - moduleBase;
        }

        DWORD64 FindPattern(const char* pattern)
        {
            const char* pat = pattern;
            DWORD64 firstMatch = 0;
            DWORD64 rangeStart = moduleBase;
            MODULEINFO miModInfo;
            GetModuleInformation(GetCurrentProcess(), (HMODULE)rangeStart, &miModInfo, sizeof(MODULEINFO));
            DWORD64 rangeEnd = rangeStart + miModInfo.SizeOfImage;

            for (DWORD64 pCur = rangeStart; pCur < rangeEnd; pCur++)
            {
                if (!*pat)
                    return firstMatch - moduleBase;

                if (*(PBYTE)pat == '\?' || *(BYTE*)pCur == getByte(pat))
                {
                    if (!firstMatch)
                        firstMatch = pCur;

                    if (!pat[2])
                    {
                        if (pattern[0] == 'E' && (pattern[1] == '8' || pattern[1] == '9'))
                            return CalcRelativeOffset(firstMatch + 1);
                        return firstMatch - moduleBase;
                    }

                    if (*(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?')
                        pat += 3;
                    else
                        pat += 2;
                }
                else
                {
                    pat = pattern;
                    firstMatch = 0;
                }
            }
            return NULL;
        }
    }

    namespace Hook
    {
        struct HookContext
        {
            BYTE original_code[64];
            SIZE_T dst_ptr;
            BYTE far_jmp[6];
        };

        HookContext* presenthook64;
        void* detourBuffer[3];

        const void* DetourFunc64(BYTE* const src, const BYTE* dest, const unsigned int jumplength)
        {
            // Allocate a memory page that is going to contain executable code.
            MEMORY_BASIC_INFORMATION mbi;
            for (SIZE_T addr = (SIZE_T)src; addr > (SIZE_T)src - 0x80000000; addr = (SIZE_T)mbi.BaseAddress - 1)
            {
                if (!VirtualQuery((LPCVOID)addr, &mbi, sizeof(mbi)))
                {
                    break;
                }

                if (mbi.State == MEM_FREE)
                {
                    if (presenthook64 = (HookContext*)VirtualAlloc(mbi.BaseAddress, 0x1000, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE))
                    {
                        break;
                    }
                }
            }

            // If allocating a memory page failed, the function failed.
            if (!presenthook64)
            {
                return NULL;
            }

            // Select a pointer slot for the memory page to be freed on unload.
            for (int i = 0; i < sizeof(detourBuffer) / sizeof(void*); ++i)
            {
                if (!detourBuffer[i])
                {
                    detourBuffer[i] = presenthook64;
                    break;
                }
            }

            // Save original code and apply detour. The detour code is:
            // push rax
            // movabs rax, 0xCCCCCCCCCCCCCCCC
            // xchg rax, [rsp]
            // ret
            BYTE detour[] = { 0x50, 0x48, 0xB8, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0x48, 0x87, 0x04, 0x24, 0xC3 };
            memcpy(presenthook64->original_code, src, jumplength);
            memcpy(&presenthook64->original_code[jumplength], detour, sizeof(detour));
            *(SIZE_T*)&presenthook64->original_code[jumplength + 3] = (SIZE_T)src + jumplength;

            // Build a far jump to the destination function.
            *(WORD*)&presenthook64->far_jmp = 0x25FF;
            *(DWORD*)(presenthook64->far_jmp + 2) = (DWORD)((SIZE_T)presenthook64 - (SIZE_T)src + FIELD_OFFSET(HookContext, dst_ptr) - 6);
            presenthook64->dst_ptr = (SIZE_T)dest;

            // Write the hook to the original function.
            DWORD flOld = 0;
            VirtualProtect(src, 6, PAGE_EXECUTE_READWRITE, &flOld);
            memcpy(src, presenthook64->far_jmp, sizeof(presenthook64->far_jmp));
            VirtualProtect(src, 6, flOld, &flOld);

            // Return a pointer to the original code.
            return presenthook64->original_code;
        }
    }


    bool AttachDebugConsole(void)
    {
        FreeConsole();
        if (!AllocConsole())
            return false;

        FILE* pConOutput = nullptr;
        return (freopen_s(&pConOutput, "CONOUT$", "w", stdout) == 0);
    }

    template<class T>
    T* FindClass(DWORD64 offset)
    {
        return *(T**)(*(DWORD64*)(Memory::moduleBase + offset) + 0xB8);
    }

    template<class T>
    T* FindFunction(DWORD64 offset)
    {
        return (T*)(Memory::moduleBase + offset);
    }
}