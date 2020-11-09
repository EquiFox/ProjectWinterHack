#pragma once
#include "pch.h"
#include "utils.hpp"
#include "offsets.hpp"
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
    Medic_S = 4,
    Soldier = 5,
    Medium = 6,
    Padre = 7,
    Hunter = 8,
    Hacker_S = 9,
    Lumberjack = 10,
    Scientist_S = 11,
    ClassicSurvivor = 12,
    Detective = 13,
    ClassicTraitor = 1000,
    Saboteur = 1001,
    Peeker = 1002,
    Looter = 1003,
    Medic_T = 1004,
    Hacker_T = 1005,
    Demon = 1006,
    Whisperer = 1007,
    Sleeper = 1008,
    Scientist_T = 1009,
    Yeti = 2000,
    IdentityThief = 2001,
    None = 10000
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
        return Utilities::FindFunction<il2cpp_string_new>(Offsets::Methods::String_New)(str);
    }

    static Il2CppString* Concat(Il2CppString* str0, Il2CppString* str1)
    {
        return Utilities::FindFunction<Il2CppString__Concat>(Offsets::Methods::String_Concat)(str0, str1);
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

template<class T>
struct Il2CppStructList
{
    char pad_0[0x10];
    Il2CppArray<T>* items; // 0x10
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

struct CamZoomFX
{
    typedef void __fastcall CamZoomFX__StartZooming(CamZoomFX* camZoomFX, float a, float b, bool flag);
  
    void StartZooming(float a, float b, bool flag = false)
    {
        Utilities::FindFunction<CamZoomFX__StartZooming>(Offsets::Methods::CamZoomFX_StartZooming)(this, a, b, flag);
    }
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
    char pad_1[0x38];
    ObscuredFloat currentValue; // 0x88
};

struct TextMeshProUGUI
{
    char pad_0[0x17C];
    Color32 fontColor; // 0x17C

    typedef void __fastcall TextMeshProUGUI__SetText(TextMeshProUGUI* textMeshProUGUI, Il2CppString* text);
    typedef void __fastcall TextMeshProUGUI__SetFaceColor(TextMeshProUGUI* textMeshProUGUI, Color32 newColor);
    typedef void __fastcall TextMeshProUGUI__SetAllDirty(TextMeshProUGUI* textMeshProUGUI);
    
    void SetText(Il2CppString* text)
    {		
        Utilities::FindFunction<TextMeshProUGUI__SetText>(Offsets::Methods::TextMeshProUGUI_SetText)(this, text);
        Utilities::FindFunction<TextMeshProUGUI__SetAllDirty>(Offsets::Methods::TextMeshProUGUI_SetAllDirty)(this);
    }

    void SetFaceColor(Color32 newColor)
    {
        Utilities::FindFunction<TextMeshProUGUI__SetFaceColor>(Offsets::Methods::TextMeshProUGUI_SetFaceColor)(this, newColor);
        Utilities::FindFunction<TextMeshProUGUI__SetAllDirty>(Offsets::Methods::TextMeshProUGUI_SetAllDirty)(this);
    }
};

struct PlayerHoverUIHandler
{
    char pad_0[0x28];
    TextMeshProUGUI* nameField; // 0x28
};

struct TextChatBox
{
    typedef void __fastcall TextChat__DisplayLocalMessage(TextChatBox* textChat, Il2CppString* message);

    void DisplayLocalMessage(const char* message)
    {
        Il2CppString* messageString = Il2CppString::New(message);
        Utilities::FindFunction<TextChat__DisplayLocalMessage>(Offsets::Methods::TextChat_DisplayLocalMessage)(this, messageString);
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
    char pad_0[0xA0];
    bool canCraft; // 0xA0
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
    char pad_0[0x98];
    TextChatBox* textChatBox; // 0x98;
    char pad_1[0x10];
    CraftingUI* craftingUI; // 0xB0
};

struct PlayerRoleData
{
    char pad_0[0x18];
    ePlayerRole playerRole; // 0x18
    char pad_1[0x14];
    bool isTraitorRole; // 0x30
    char pad_2[0x47];
    float maxCharge; // 0x78

    Il2CppString* GetPlayerRoleString()
    {
        const std::map<ePlayerRole, Il2CppString*> roleStrings{
            { ePlayerRole::ClassicSurvivor, Il2CppString::New(" [Survivor]") },
            { ePlayerRole::ClassicTraitor, Il2CppString::New(" [Traitor]") },
            { ePlayerRole::Defector, Il2CppString::New(" [Defector]") },
            { ePlayerRole::Demon, Il2CppString::New(" [Demon]") },
            { ePlayerRole::Detective, Il2CppString::New(" [Detective]") },
            { ePlayerRole::Hacker_S, Il2CppString::New(" [Hacker]") },
            { ePlayerRole::Hacker_T, Il2CppString::New(" [Hacker]") },
            { ePlayerRole::Hunter, Il2CppString::New(" [Hunter]") },
            { ePlayerRole::IdentityThief, Il2CppString::New(" [ID Thief]") },
            { ePlayerRole::Innocent, Il2CppString::New(" [Innocent]") },
            { ePlayerRole::Investigator, Il2CppString::New(" [Investigator]") },
            { ePlayerRole::Looter, Il2CppString::New(" [Looter]") },
            { ePlayerRole::Lumberjack, Il2CppString::New(" [Lumberjack]") },
            { ePlayerRole::Medic_S, Il2CppString::New(" [Medic]") },
            { ePlayerRole::Medic_T, Il2CppString::New(" [Medic]") },
            { ePlayerRole::Medium, Il2CppString::New(" [Medium]") },
            { ePlayerRole::None, Il2CppString::New(" [Unknown]") },
            { ePlayerRole::Padre, Il2CppString::New(" [Padre]") },
            { ePlayerRole::Peeker, Il2CppString::New(" [Peeker]") },
            { ePlayerRole::Saboteur, Il2CppString::New(" [Saboteur]") },
            { ePlayerRole::Scientist_S, Il2CppString::New(" [Scientist]") },
            { ePlayerRole::Scientist_T, Il2CppString::New(" [Scientist]") },
            { ePlayerRole::Sleeper, Il2CppString::New(" [Sleeper]") },
            { ePlayerRole::Soldier, Il2CppString::New(" [Soldier]") },
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
    float abilityCharge; //0x28
};

struct PlayerHandler
{
    char pad_0[0xA8];
    PlayerHoverUIHandler* playerHoverUIHandler; // 0xA8
    char pad_1[0x28];
    BaseStatScript* healthScript; // 0xD8
    BaseStatScript* warmthScript; // 0xE0
    BaseStatScript* hungerScript; // 0xE8
    char pad_2[0x8];
    HudManager* hudManager; // 0xF8
    char pad_3[0xC0];
    PlayerRoleHandler* playerRoleHandler; // 0x1C0
    char pad_4[0x180];
    bool isConvertedTraitor; // 0x348

    typedef void __fastcall PlayerHandler__SwapPlayerRole(PlayerHandler* playerHandler, ePlayerRole playerRole, bool arg2, int arg3);

    void SwapPlayerRole(ePlayerRole playerRole)
    {
        Utilities::FindFunction<PlayerHandler__SwapPlayerRole>(Offsets::Methods::PlayerHandler_SwapPlayerRole)(this, playerRole, false, 9);
    }
};

struct PhotonPlayer
{
    char pad_0[0x18];
    int actorID; // 0x18
    bool isLocal; // 0x1C
    char pad_1[0x3];
    Il2CppString* nameField; // 0x20
};

struct PhotonNetwork
{
    typedef Il2CppArray<PhotonPlayer*>* __fastcall PhotonNetwork__GetPlayerList();

    static Il2CppArray<PhotonPlayer*>* GetPlayerList()
    {
        return Utilities::FindFunction<PhotonNetwork__GetPlayerList>(Offsets::Methods::PhotonNetwork_GetPlayerList)();
    }
};

struct LobbyHandler
{
    char pad_0[0x40];
    eQuickMatchLobbyState lobbyState; // 0x40
};

struct UnityText
{
    char pad_0[0xD0];
    Il2CppString* text; // 0xD0

    typedef void __fastcall UnityText__ChangeText(UnityText* unityText, Il2CppString* text);
    typedef void __fastcall UnityText__SetAllDirty(UnityText* unityText);
        
    void ChangeText(const char* text)
    {
        Utilities::FindFunction<UnityText__ChangeText>(Offsets::Methods::UnityText_ChangeText)(this, Il2CppString::New(text));
        Utilities::FindFunction<UnityText__SetAllDirty>(Offsets::Methods::UnityText_SetAllDirty)(this);
    }
};

struct PlayMenuController
{
    char pad_0[0x118];
    UnityText* versionText; // 0x118
};

struct UIManager
{
    char pad_0[0x28];
    PlayMenuController* playMenuController; // 0x28
};

struct SocialRatingManager
{
    char pad_0[0x18];
    bool enabledInGame; // 0x18
    char pad_1[0x3];
    ObscuredInt rateUpValue; // 0x1C
    ObscuredInt rateDownValue; // 0x30
    float degradationTime; // 0x44
    int degradationValue; // 0x48
    int numberOfVotes; // 0x4C

    typedef void __fastcall SocialRatingManager__UpdateSocialRatingOnPlayFab(SocialRatingManager* socialRatingManager, ObscuredInt value, Il2CppString* playFabId);
   
    void UpdateSocialRatingOnPlayFab(int value, Il2CppString* playFabId) 
    {
        ObscuredInt* obsInt = new ObscuredInt();
        obsInt->inited = true;
        obsInt->currentCryptoKey = 0x0;
        obsInt->hiddenValue = value;

        Utilities::FindFunction<SocialRatingManager__UpdateSocialRatingOnPlayFab>(Offsets::Methods::SocialRatingManager_UpdateSocialRatingOnPlayFab)(this, *obsInt, playFabId);
        delete obsInt;
    }
};

struct LevelManager
{
    char pad_0[0x20];
    CamZoomFX* mainCameraZoomFX; // 0x20
    char pad_1[0x3A];
    bool hasSessionStarted; // 0x62
};

struct DlcManager
{
    char pad_0[0x1C];
    bool hasSupernaturalDlc; // 0x1C
};

struct GameManager
{
    char pad_0[0x38];
    LobbyHandler* lobbyHandler; // 0x38
    char pad_1[0x10];
    UIManager* uiManager; // 0x50
    char pad_2[0x18];
    SocialRatingManager* socialRatingManager; // 0x70
    char pad_3[0x18];
    LevelManager* levelManager; // 0x90
    char pad_4[0xC0];
    DlcManager* dlcManager; // 0x158
    char pad_5[0x8];
    Il2CppString* playFabId; // 0x168

    typedef PlayerHandler* __fastcall GameManager__GetPlayerHandler(GameManager* gameManager, int playerId, bool includeGhost);
    typedef void __fastcall GameManager__SetAwardedPoints(GameManager* gameManager, int points, bool awardImmediate, bool localOnly);
    typedef void (__fastcall* GameManager__Update)(GameManager* instance);

    PlayerHandler* GetPlayerHandler(int playerId, bool includeGhost)
    {
        return Utilities::FindFunction<GameManager__GetPlayerHandler>(Offsets::Methods::GameManager_GetPlayerHandler)(this, playerId, includeGhost);
    }

    void SetAwardedPoints(int points, bool awardImmediate, bool localOnly)
    {
        Utilities::FindFunction<GameManager__SetAwardedPoints>(Offsets::Methods::GameManager_SetAwardedPoints)(this, points, awardImmediate, localOnly);
    }

    static GameManager* Instance()
    {
        static GameManager* ptr = nullptr;
        if (!ptr) ptr = *(GameManager**)Utilities::FindClass<GameManager>(Offsets::Classes::GameManager);
        return ptr;
    }
};

typedef void(__fastcall* UnlocksEntryUI__Init)(__int64 a1, __int64 a2, int a3, unsigned int a4, __int64 a5, __int64 a6, UnlockProgress* unlockProgress, __int64 a8);
typedef void(__fastcall* VFXManager__DoCameraZoom)(float a1, float a2, bool a3);
typedef void(__fastcall* VFXManager__ResetCameraZoom)(float a1, bool a2, bool a3);
typedef void ObscuredCheatingDetector__Dispose();