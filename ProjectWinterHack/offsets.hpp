#pragma once
#include "pch.h"
#include "utils.hpp"

namespace Offsets
{
	namespace Classes
	{
		DWORD64 GameManager;
		DWORD64 PhotonNetwork;
	}

	namespace Methods
	{
		DWORD64 GameManager_Update;
		DWORD64 GameManager_SetAwardedPoints;
		DWORD64 GameManager_GetPlayerHandler;
		DWORD64 PlayerHandler_SwapPlayerRole;

		DWORD64 TextMeshProUGUI_SetText;
		DWORD64 TextMeshProUGUI_SetFaceColor;
		DWORD64 TextMeshProUGUI_SetAllDirty;
		DWORD64 TextChat_DisplayLocalMessage;

		DWORD64 UnlocksEntryUI_Init;
		DWORD64 SocialRatingManager_UpdateSocialRatingOnPlayFab;
		DWORD64 ObscuredCheatingDetector_Dispose;

		DWORD64 String_New;
		DWORD64 String_Concat;
	}

	//Yeah I know some sigs are terrible, I was lazy
	void Initialize()
	{
		Classes::GameManager = Utilities::Memory::CalcRelativeOffset(
			Utilities::Memory::FindPattern("E8 ? ? ? ? 48 85 C0 74 09 48 8B 88 ? ? ? ? EB 02 33 C9 48 89 4B 48 48 85 C9 74 1F 48 8B 53 18 45 33 C9 45 33 C0") + 0x170);
		Classes::PhotonNetwork = Utilities::Memory::CalcRelativeOffset(
			Utilities::Memory::FindPattern("E8 ? ? ? ? 83 F8 03 75 5A") + 0x22);

		Methods::GameManager_Update = Utilities::Memory::FindPattern("40 53 48 83 EC 30 48 83 B9 ? ? ? ? ?");
		Methods::GameManager_SetAwardedPoints = Utilities::Memory::FindPattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 40 80 3D ? ? ? ? ? 41 0F B6 E9 41 0F B6 F0 8B FA");
		Methods::GameManager_GetPlayerHandler = Utilities::Memory::FindPattern("E8 ? ? ? ? 4C 8B 73 78 48 8B F0");
		Methods::PlayerHandler_SwapPlayerRole = Utilities::Memory::FindPattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 41 56 48 83 EC 20 80 3D ? ? ? ? ? 41 8B F1");

		Methods::TextMeshProUGUI_SetText = Utilities::Memory::FindPattern("E8 ? ? ? ? 4D 85 E4 0F 84 ? ? ? ? 4C 8B 05 ? ? ? ? 33 D2");
		Methods::TextMeshProUGUI_SetFaceColor = Utilities::Memory::FindPattern("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 30 80 3D ? ? ? ? ? 8B DA 48 8B F9 75 12 8B 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ? 48 8B 0D ? ? ? ? 48 8B B7 ? ? ? ? F6 81 ? ? ? ? ? 74 0E 83 B9 ? ? ? ? ? 75 05 E8 ? ? ? ? 45 33 C0 33 D2 48 8B CE E8 ? ? ? ? 84 C0 74 21 48 8B 07 48 8B CF 48 8B 97 ? ? ? ? 4C 8B 80 ? ? ? ? FF 90 ? ? ? ? 48 89 87 ? ? ? ? 48 8B 87 ? ? ? ? 48 8B CF 48 89 87 ? ? ? ? 48 8B 07 48 8B 90 ? ? ? ? FF 90 ? ? ? ? F3 0F 11 87 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B BF ? ? ? ? F6 80 ? ? ? ? ? 74 18 83 B8 ? ? ? ? ? 75 0F 48 8B C8 E8 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 80 ? ? ? ? 48 8D 4C 24 ? 45 33 C0 8B D3 8B 70 08");
		Methods::TextMeshProUGUI_SetAllDirty = Utilities::Memory::FindPattern("40 53 48 83 EC 20 48 8B 01 48 8B D9 C6 81 ? ? ? ? ? 48 8B 90 ? ? ? ? FF 90 ? ? ? ? 48 8B 03 48 8B CB 48 8B 90 ? ? ? ? FF 90 ? ? ? ?");
		Methods::TextChat_DisplayLocalMessage = Utilities::Memory::FindPattern("48 89 5C 24 ? 57 48 83 EC 40 80 3D ? ? ? ? ? 48 8B FA 48 8B D9 75 12 8B 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ? 33 D2 48 8B CF E8 ? ? ? ? 84 C0 0F 85 ? ? ? ? 83 BB ? ? ? ? ? 75 0F");
		
		Methods::UnlocksEntryUI_Init = Utilities::Memory::FindPattern("E8 ? ? ? ? 48 8B 5D 40 48 85 DB 0F 84 ? ? ? ? 44 39 6B 18");
		Methods::SocialRatingManager_UpdateSocialRatingOnPlayFab = Utilities::Memory::FindPattern("E8 ? ? ? ? 45 33 C0 48 8D 4D F7 41 8D 50 01 E8 ? ? ? ? 0F 10 30 8B 70 10 F3 0F 10 47 ? 0F 2F F8 77 71 48 8B 0D ? ? ? ? F6 81 ? ? ? ? ? 74 0E 83 B9 ? ? ? ? ? 75 05 E8 ? ? ? ? 48 8B 0D ? ? ? ? 33 D2 E8 ? ? ? ? 44 0F 28 44 24 ? 0F 28 B4 24 ? ? ? ? 4C 8B B4 24 ? ? ? ? 48 8B B4 24 ? ? ? ? 48 8B 9C 24 ? ? ? ? 44 0F 28 4C 24 ? 48 8B BC 24 ? ? ? ? 0F 28 BC 24 ? ? ? ? 48 81 C4 ? ? ? ? 5D C3 48 8B 0D ? ? ? ? 8B 5F 48 F3 0F 5E F8 F6 81 ? ? ? ? ? 74 0E 83 B9 ? ? ? ? ? 75 05 E8 ? ? ? ? 66 0F 6E C3 33 D2 0F 5B C0 F3 0F 59 C7 E8 ? ? ? ? 45 33 C0 48 8D 4D F7 8B D0 E8 ? ? ? ? 33 D2 89 75 E7 48 8D 4D D7 0F 11 75 D7 44 8B 70 10 0F 10 38 E8 ? ? ? ? 33 D2 89 75 E7 48 8D 4D D7 0F 11 75 D7 3B 47 60 0F 8F ? ? ? ? E8 ? ? ? ? 3B 47 60 0F 8D ? ? ? ? 33 D2 89 75 E7 48 8D 4D D7 0F 11 75 D7 E8 ? ? ? ? 33 D2 44 89 75 E7 48 8D 4D D7 8B D8 0F 11 7D D7 E8 ? ? ? ? 8D 0C 18 8B 5F 60 3B CB 7E 29 33 D2 89 75 E7 48 8D 4D D7 0F 11 75 D7 E8 ? ? ? ? 2B D8 48 8D 4D F7 8B D3 45 33 C0 E8 ? ? ? ? 0F 10 38 44 8B 70 10 48 8B 0D ? ? ? ? F6 81 ? ? ? ? ? 74 0E 83 B9 ? ? ? ? ? 75 05 E8 ? ? ? ? 33 C9 E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 0F 11 7D D7");
		Methods::ObscuredCheatingDetector_Dispose = Utilities::Memory::FindPattern("40 53 48 83 EC 20 80 3D ? ? ? ? ? 75 12 8B 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 58 18 F6 83 ? ? ? ? ? 75 08 48 8B CB E8 ? ? ? ? 48 8B 83 ? ? ? ? 48 8B 18 F6 83 ? ? ? ? ? 75 08 48 8B CB E8 ? ? ? ? 48 8B 0D ? ? ? ? 48 8B 83 ? ? ? ? F6 81 ? ? ? ? ? 48 8B 18 74 0E 83 B9 ? ? ? ? ? 75 05 E8 ? ? ? ? 45 33 C0 33 D2 48 8B CB E8 ? ? ? ? 84 C0 74 5C 48 8B 05 ? ? ? ? 48 8B 58 18 F6 83 ? ? ? ? ? 75 08 48 8B CB E8 ? ? ? ? 48 8B 83 ? ? ? ? 48 8B 18 F6 83 ? ? ? ? ? 75 08 48 8B CB E8 ? ? ? ? 48 8B 83 ? ? ? ? 48 8B 08 48 85 C9 74 1C 48 8B 01 48 8B 90 ? ? ? ? 48 83 C4 20 5B 48 FF A0 C0 01 00 00");

		Methods::String_New = Utilities::Memory::FindPattern("E8 ? ? ? ? 49 89 06 48 8B CB");
		Methods::String_Concat = Utilities::Memory::FindPattern("E9 ? ? ? ? 83 F9 10");

#if _DEBUG
		printf("---- Offsets Dump ----\n");
		printf("Classes::GameManager: 0x%p\n", Classes::GameManager);
		printf("Classes::PhotonNetwork: 0x%p\n", Classes::PhotonNetwork);
		printf("Methods::GameManager_Update: 0x%p\n", Methods::GameManager_Update);
		printf("Methods::GameManager_SetAwardedPoints: 0x%p\n", Methods::GameManager_SetAwardedPoints);
		printf("Methods::GameManager_GetPlayerHandler: 0x%p\n", Methods::GameManager_GetPlayerHandler);
		printf("Methods::PlayerHandler_SwapPlayerRole: 0x%p\n", Methods::PlayerHandler_SwapPlayerRole);
		printf("Methods::TextMeshProUGUI_SetText: 0x%p\n", Methods::TextMeshProUGUI_SetText);
		printf("Methods::TextMeshProUGUI_SetFaceColor: 0x%p\n", Methods::TextMeshProUGUI_SetFaceColor);
		printf("Methods::TextMeshProUGUI_SetAllDirty: 0x%p\n", Methods::TextMeshProUGUI_SetAllDirty);
		printf("Methods::TextChat_DisplayLocalMessage: 0x%p\n", Methods::TextChat_DisplayLocalMessage);
		printf("Methods::SocialRatingManager_UpdateSocialRatingOnPlayFab: 0x%p\n", Methods::SocialRatingManager_UpdateSocialRatingOnPlayFab);
		printf("Methods::UnlocksEntryUI_Init: 0x%p\n", Methods::UnlocksEntryUI_Init);
		printf("Methods::ObscuredCheatingDetector_Dispose: 0x%p\n", Methods::ObscuredCheatingDetector_Dispose);
		printf("Methods::String_New: 0x%p\n", Methods::String_New);
		printf("Methods::String_Concat: 0x%p\n", Methods::String_Concat);
#endif
	}
}