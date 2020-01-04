#pragma once
#include "pch.h"
#include "utils.hpp"
#include <map>

enum class ePlayerClass : int
{
    SURVIVOR = 2,
    TRAITOR = 4,
    BOTH = 6,
    NONE = 9
};

enum class eQuickMatchLobbyState : int
{
    LS_Idle = 0,
    LS_WaitingForPlayers = 1,
    LS_AllPlayersReady = 2,
    LS_Loading = 3,
    LS_MasterSwitchWait = 4,
    LS_Count = 5
};

enum class ePlayerRole : int
{
    Innocent = 0,
    Defector = 1,
    Investigator = 2,
    TreasureHunter = 3,
    Medic = 4,
    Soldier = 5,
    Medium = 6,
    Padre = 7,
    Hunter = 8,
    ClassicSurvivor = 9,
    ClassicTraitor = 1000,
    Saboteur = 1001,
    Peeker = 1002,
    Looter = 1003,
    Stitcher = 1004,
    Hacker = 1005,
    Demon = 1006,
    Whisperer = 1007,
    Yeti = 2000,
    None = 2002
};

struct Il2CppString
{
    char pad_0[0x10];
    int length; // 0x10
    wchar_t data[1]; // 0x14

    typedef Il2CppString* __fastcall il2cpp_string_new(const char* str);
    typedef Il2CppString* __fastcall Il2CppString__Concat(Il2CppString* str0, Il2CppString* str1);

    static Il2CppString* New(const char* str)
    {
        return Utilities::FindFunction<il2cpp_string_new>(0x89EC0)(str);
    }

    static Il2CppString* Concat(Il2CppString* str0, Il2CppString* str1)
    {
        return Utilities::FindFunction<Il2CppString__Concat>(0xC47430)(str0, str1);
    }
};

template<class T>
struct Il2CppArray
{
    char pad_0[0x18];
    int length; // 0x18

    T GetItem(int index)
    {
        return *(T*)((DWORD64)&pad_0 + (sizeof(T) * index) + 0x20);
    }

    void SetItem(int index, T value)
    {
        *(T*)((DWORD64)&pad_0 + (sizeof(T) * index) + 0x20) = value;
    }
};

template<class T>
struct Il2CppList
{
    char pad_0[0x10];
    Il2CppArray<T*>* items; // 0x10
    int length; // 0x18
};

struct UnityVector3
{
    float x; // 0x0
    float y; // 0x4
    float z; // 0x8
};

struct Color32
{
    BYTE r; // 0x0
    BYTE g; // 0x1
    BYTE b; // 0x2
    BYTE a; // 0x3
};

struct UnlockProgressNodeInfo
{
    char pad_0[0x10];
    int treeId; // 0x10
    int tier; // 0x14
    int tierLevel; // 0x18
    int progressMade; // 0x1C
    bool branchStarted; // 0x20
    bool branchDone; // 0x21
};

struct UnlockProgress
{
    char pad_0[0x10];
    Il2CppString* unlockId; // 0x10
    Il2CppArray<UnlockProgressNodeInfo*>* treeNodeInfo; // 0x18
};

struct ObscuredFloat
{
    int currentCryptoKey; // 0x0
    float hiddenValue; // 0x4
    char pad_0[0x4];
    bool inited; // 0xC
    char pad_1[0x3];
    float fakeValue; // 0x10
    bool fakeValueActive; // 0x14
    char pad_2[0x3];
};

struct ObscuredInt
{
    int currentCryptoKey; // 0x0
    int hiddenValue; // 0x4
    bool inited; // 0x8
    char pad_1[0x3];
    float fakeValue; // 0xC
    bool fakeValueActive; // 0x10
    char pad_2[0x3];
};

struct BaseStatScript
{
    char pad_0[0x20];
    ObscuredFloat maxValue; // 0x20
    ObscuredFloat startValue; // 0x38
    char pad_1[0x20];
    ObscuredFloat currentValue; // 0x70
};

struct TextMeshProUGUI
{
    char pad_0[0x17C];
    Color32 fontColor; // 0x17C

    typedef void __fastcall TextMeshProUGUI__SetText(DWORD64* textMeshProUGUI, Il2CppString* text);
    typedef void __fastcall TextMeshProUGUI__SetFaceColor(DWORD64* textMeshProUGUI, Color32 newColor);
    typedef void __fastcall TextMeshProUGUI__SetAllDirty(DWORD64* textMeshProUGUI);
    
    void SetText(Il2CppString* text)
    {		
        Utilities::FindFunction<TextMeshProUGUI__SetText>(0x3D1BC0)((DWORD64*)&pad_0, text);
    }

    void SetFaceColor(Color32 newColor)
    {
        Utilities::FindFunction<TextMeshProUGUI__SetFaceColor>(0xF5B4F0)((DWORD64*)&pad_0, newColor);
    }

    void SetAllDirty()
    {
        Utilities::FindFunction<TextMeshProUGUI__SetAllDirty>(0x7CB900)((DWORD64*)&pad_0);
    }
};

struct PlayerHoverUIHandler
{
    char pad_0[0x28];
    TextMeshProUGUI* nameField; // 0x28
};

struct TextChatBox
{
    char pad_0[0xE8];
    Il2CppString* localPlayerName; // 0xE8

    typedef void __fastcall TextChat__DisplayLocalMessage(DWORD64* textChat, Il2CppString* message);

    void DisplayLocalMessage(const char* message)
    {
        Il2CppString* messageString = Il2CppString::New(message);
        Utilities::FindFunction<TextChat__DisplayLocalMessage>(0x14A8340)((DWORD64*)&pad_0, messageString);
    }
};

struct Ingredient
{
    char pad_0[0x10];
    int itemId; // 0x10
    int count; // 0x14
};

struct Recipe
{
    char pad_0[0x18];
    float craftTime; // 0x18
    char pad_1[0x4];
    Il2CppArray<Ingredient*>* ingredients; // 0x20;
};

struct CraftingEntryUI
{
    char pad_0[0x88];
    bool canCraft; // 0x88
};

struct CraftingUI
{
    char pad_0[0x90];
    Il2CppList<Recipe>* currentRecipes; // 0x90
    char pad_1[0x50];
    CraftingEntryUI* craftingEntryUI; // 0xE8
};

struct HudManager
{
    char pad_0[0x80];
    TextChatBox* textChatBox; // 0x80;
    char pad_1[0x10];
    CraftingUI* craftingUI; // 0x98
};

struct PlayerRoleData
{
    char pad_0[0x18];
    ePlayerRole playerRole; //0x18
    int oppositeClassEquivalent; //0x1C
    bool isTraitorRole; //0x20

    Il2CppString* GetPlayerRoleString()
    {
        const std::map<ePlayerRole, Il2CppString*> roleStrings{
            { ePlayerRole::ClassicSurvivor, Il2CppString::New(" [Survivor]") },
            { ePlayerRole::ClassicTraitor, Il2CppString::New(" [Traitor]") },
            { ePlayerRole::Defector, Il2CppString::New(" [Defector]") },
            { ePlayerRole::Demon, Il2CppString::New(" [Demon]") },
            { ePlayerRole::Hacker, Il2CppString::New(" [Hacker]") },
            { ePlayerRole::Hunter, Il2CppString::New(" [Hunter]") },
            { ePlayerRole::Innocent, Il2CppString::New(" [Innocent]") },
            { ePlayerRole::Investigator, Il2CppString::New(" [Investigator]") },
            { ePlayerRole::Looter, Il2CppString::New(" [Looter]") },
            { ePlayerRole::Medic, Il2CppString::New(" [Medic]") },
            { ePlayerRole::Medium, Il2CppString::New(" [Medium]") },
            { ePlayerRole::None, Il2CppString::New(" [Unknown]") },
            { ePlayerRole::Padre, Il2CppString::New(" [Padre]") },
            { ePlayerRole::Peeker, Il2CppString::New(" [Peeker]") },
            { ePlayerRole::Saboteur, Il2CppString::New(" [Saboteur]") },
            { ePlayerRole::Soldier, Il2CppString::New(" [Soldier]") },
            { ePlayerRole::Stitcher, Il2CppString::New(" [Stitcher]") },
            { ePlayerRole::TreasureHunter, Il2CppString::New("Treasure Hunter]") },
            { ePlayerRole::Whisperer, Il2CppString::New(" [Whisperer]") },
            { ePlayerRole::Yeti, Il2CppString::New(" [Yeti]") }
        };
        auto   it = roleStrings.find(playerRole);
        return it == roleStrings.end() ? roleStrings.find(ePlayerRole::None)->second : it->second;
    }
};

struct PlayerRoleHandler
{
    char pad_0[0x20];
    PlayerRoleData* playerRoleData; // 0x20
};

struct PlayerHandler
{
    char pad_0[0x20];
    bool originalOwner; // 0x20
    char pad_1[0x3];
    int currentPlayerOutfitOwnerId; // 0x24
    char pad_2[0x70];
    PlayerHoverUIHandler* playerHoverUIHandler; // 0x98
    char pad_3[0x20];
    BaseStatScript* healthScript; // 0xC0
    BaseStatScript* warmthScript; // 0xC8
    BaseStatScript* hungerScript; // 0xD0
    char pad_4[0x8];
    HudManager* hudManager; // 0xE0
    char pad_5[0x80];
    DWORD64* playerNameOverride; // 0x168
    DWORD64* playerName; // 0x170
    bool isInCabin; // 0x178
    bool isInRestrictedItemZone; // 0x179
    bool isUsingMainCamera; // 0x17A
    bool isInFlagArea; // 0x17B
    char pad_6[0x4];
    DWORD64* cameraTarget; //0x180
    ePlayerClass playerClass; // 0x188
    bool isRevealed; // 0x18C
    char pad_7[0x3];
    PlayerRoleHandler* playerRoleHandler; // 0x190
    int playerState; // 0x198
    bool shouldRespawnInCabin; // 0x19C
    bool haveClothesBeenSwapped; // 0x19D
    char pad_8[0x2];
    Il2CppString* playFabID; // 0x1A0
    char pad_9[0xE8];
    DWORD64* currentHealth; // 0x290
    char pad_10[0x10];
    DWORD64* currentHunger; // 0x2A8
    char pad_11[0x10];
    DWORD64* currentWarmth; // 0x2C0
    char pad_12[0x10];
    float dragBreakForce; // 0x2D8
    UnityVector3 lastPosition; // 0x2DC
    char pad_13[0x21];
    bool isConvertedTraitor; // 0x309

    typedef void __fastcall PlayerHandler__SwapPlayerRole(PlayerHandler* playerHandler, ePlayerRole playerRole);

    void SwapPlayerRole(ePlayerRole playerRole)
    {
        Utilities::FindFunction<PlayerHandler__SwapPlayerRole>(0x159E770)(this, playerRole);
    }
};

struct PhotonPlayer
{
    char pad_0[0x10];
    int actorID; // 0x10
    char pad_1[0x4];
    Il2CppString* nameField; // 0x18
    Il2CppString* userId; // 0x20
    bool isLocal; // 0x28
    bool isInactive; // 0x29
};

struct NetworkingPeer
{
    char pad_0[0x1C8];
    Il2CppArray<PhotonPlayer*>* playerList; // 0x1C8
};

struct PhotonNetwork
{
    char pad_0[0x10];
    NetworkingPeer* networkingPeer; // 0x10

    static PhotonNetwork* Instance()
    {
        static PhotonNetwork* ptr = nullptr;
        if (!ptr) ptr = Utilities::FindClass<PhotonNetwork>(0x2657508);
        return ptr;
    }
};

struct LobbyHandler
{
    char pad_0[0x58];
    eQuickMatchLobbyState lobbyState; // 0x58
};

struct LevelManager
{
    char pad_0[0x6A];
    bool hasSessionStarted; // 0x6A
};

struct GameManager
{
    char pad_0[0x38];
    LobbyHandler* lobbyHandler; // 0x38
    char pad_1[0x48];
    LevelManager* levelManager; // 0x88

    typedef PlayerHandler* __fastcall GameManager__GetPlayerHandler(DWORD64* gameManager, int playerId, bool includeGhost);
    typedef void __fastcall GameManager__SetAwardedPoints(DWORD64* gameManager, int points, bool awardImmediate, bool localOnly);
    typedef void (__fastcall* GameManager_Update)(GameManager* instance);

    PlayerHandler* GetPlayerHandler(int playerId, bool includeGhost)
    {
        return Utilities::FindFunction<GameManager__GetPlayerHandler>(0x1482190)((DWORD64*)&pad_0, playerId, includeGhost);
    }

    void SetAwardedPoints(int points, bool awardImmediate, bool localOnly)
    {
        Utilities::FindFunction<GameManager__SetAwardedPoints>(0x14827E0)((DWORD64*)&pad_0, points, awardImmediate, localOnly);
    }

    static GameManager* Instance()
    {
        static GameManager* ptr = nullptr;
        if (!ptr) ptr = *(GameManager**)Utilities::FindClass<GameManager>(0x2657708);
        return ptr;
    }
};

typedef void(__fastcall* UnlocksEntryUI__Init)(__int64 a1, __int64 a2, int a3, unsigned int a4, __int64 a5, __int64 a6, UnlockProgress* unlockProgress, __int64 a8);
typedef void(__fastcall* PlayFabLogin__FlagAsCheater)(__int64 a1, __int64 a2, __int64 a3);
typedef void ObscuredCheatingDetector__StopDetection();