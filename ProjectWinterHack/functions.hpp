#pragma once
#include "classes.hpp"

typedef PlayerHandler* __fastcall GameManager__GetPlayerHandler(GameManager* gameManager, int playerId, bool includeGhost);
typedef void __fastcall TextMeshProUGUI__SetFaceColor(DWORD64* textMeshProUGUI, Color32 newColor);
typedef void __fastcall TextMeshProUGUI__SetAllDirty(DWORD64* textMeshProUGUI);
typedef void ObscuredCheatingDetector__StopDetection();
