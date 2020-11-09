#pragma once
#include "pch.h"
#include "utils.hpp"

namespace Offsets
{
	namespace Classes
	{
		DWORD64 GameManager;
	}

	namespace Methods
	{
		DWORD64 GameManager_Update;
		DWORD64 GameManager_SetAwardedPoints;
		DWORD64 GameManager_GetPlayerHandler;
		DWORD64 PhotonNetwork_GetPlayerList;
		DWORD64 PlayerHandler_SwapPlayerRole;

		DWORD64 TextMeshProUGUI_SetText;
		DWORD64 TextMeshProUGUI_SetFaceColor;
		DWORD64 TextMeshProUGUI_SetAllDirty;
		DWORD64 TextChat_DisplayLocalMessage;
		DWORD64 UnityText_ChangeText;
		DWORD64 UnityText_SetAllDirty;

		DWORD64 UnlocksEntryUI_Init;
		DWORD64 SocialRatingManager_UpdateSocialRatingOnPlayFab;
		DWORD64 ObscuredCheatingDetector_Dispose;

		DWORD64 CamZoomFX_StartZooming;
		DWORD64 VFXManager_DoCameraZoom;
		DWORD64 VFXManager_ResetCameraZoom;

		DWORD64 String_New;
		DWORD64 String_Concat;
	}

	void Initialize()
	{
		Classes::GameManager = 0x598AF10;

		Methods::GameManager_Update = 0x4205A70;
		Methods::GameManager_SetAwardedPoints = 0x4202250;
		Methods::GameManager_GetPlayerHandler = 0x4201280;
		Methods::PhotonNetwork_GetPlayerList = 0xBEE260;
		Methods::PlayerHandler_SwapPlayerRole = 0x373010;

		Methods::TextMeshProUGUI_SetText = 0x4E6C50;
		Methods::TextMeshProUGUI_SetFaceColor = 0x28FECA0;
		Methods::TextMeshProUGUI_SetAllDirty = 0x117B2B0;
		Methods::TextChat_DisplayLocalMessage = 0x691130;
		Methods::UnityText_ChangeText = 0x40EDAC0;
		Methods::UnityText_SetAllDirty = 0x215A000;
		
		Methods::CamZoomFX_StartZooming = 0x2015FA0;
		Methods::VFXManager_DoCameraZoom = 0x15D8F10;
		Methods::VFXManager_ResetCameraZoom = 0x15D92B0;

		Methods::UnlocksEntryUI_Init = 0x1086F80;
		Methods::SocialRatingManager_UpdateSocialRatingOnPlayFab = 0x24A71E0;
		Methods::ObscuredCheatingDetector_Dispose = 0x2A36E90;

		Methods::String_New = 0x243DB0;
		Methods::String_Concat = 0x17F1F60;

#if _DEBUG
		printf("---- Offsets Dump ----\n");
		printf("Classes::GameManager: 0x%p\n", Classes::GameManager);
		printf("Methods::GameManager_Update: 0x%p\n", Methods::GameManager_Update);
		printf("Methods::GameManager_SetAwardedPoints: 0x%p\n", Methods::GameManager_SetAwardedPoints);
		printf("Methods::GameManager_GetPlayerHandler: 0x%p\n", Methods::GameManager_GetPlayerHandler);
		printf("Methods::PhotonNetwork_GetPlayerList: 0x%p\n", Methods::PhotonNetwork_GetPlayerList);
		printf("Methods::PlayerHandler_SwapPlayerRole: 0x%p\n", Methods::PlayerHandler_SwapPlayerRole);
		printf("Methods::TextMeshProUGUI_SetText: 0x%p\n", Methods::TextMeshProUGUI_SetText);
		printf("Methods::TextMeshProUGUI_SetFaceColor: 0x%p\n", Methods::TextMeshProUGUI_SetFaceColor);
		printf("Methods::TextMeshProUGUI_SetAllDirty: 0x%p\n", Methods::TextMeshProUGUI_SetAllDirty);
		printf("Methods::TextChat_DisplayLocalMessage: 0x%p\n", Methods::TextChat_DisplayLocalMessage);
		printf("Methods::UnityText_ChangeText: 0x%p\n", Methods::UnityText_ChangeText);
		printf("Methods::UnityText_SetAllDirty: 0x%p\n", Methods::UnityText_SetAllDirty);
		printf("Methods::CamZoomFX_StartZooming: 0x%p\n", Methods::CamZoomFX_StartZooming);
		printf("Methods::VFXManager_DoCameraZoom: 0x%p\n", Methods::VFXManager_DoCameraZoom);
		printf("Methods::VFXManager_ResetCameraZoom: 0x%p\n", Methods::VFXManager_ResetCameraZoom);
		printf("Methods::SocialRatingManager_UpdateSocialRatingOnPlayFab: 0x%p\n", Methods::SocialRatingManager_UpdateSocialRatingOnPlayFab);
		printf("Methods::UnlocksEntryUI_Init: 0x%p\n", Methods::UnlocksEntryUI_Init);
		printf("Methods::ObscuredCheatingDetector_Dispose: 0x%p\n", Methods::ObscuredCheatingDetector_Dispose);
		printf("Methods::String_New: 0x%p\n", Methods::String_New);
		printf("Methods::String_Concat: 0x%p\n", Methods::String_Concat);
#endif
	}
}