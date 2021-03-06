#include "dcf.h"
#include "helper/eKeyboardMan.h"
#include "GameInfo.h"
#include <vector>

enum eCustomCameras {
	CAMERA_3RDPERSON,
	TOTAL_CUSTOM_CAMERAS
};

enum eMenuSubMenus {
	SUBMENU_SETTINGS,
	TOTAL_SUBMENUS
};

enum eScriptExecuteType {
	SCRIPT_P1,
	SCRIPT_P2,
	SCRIPT_GLOBAL
};

struct eScriptKeyBind {
	eScriptExecuteType type;
	eVKKeyCode key;
	char scriptName[128] = {};
	char functionHash[128] = {};
};

// as usual, based on mh2 debug menu

class DCFMenu {
public:
	bool	 m_bIsActive = false;
	bool	 m_bSubmenuActive[TOTAL_SUBMENUS] = {};
	bool     m_bPressingKey = false;
	bool	 m_bSlowMotion = false;
	bool     m_bFreezeWorld = false;
	bool	 m_bIsFocused = false;
	bool	 m_bCustomCameraPos = false;
	bool	 m_bCustomCameraRot = false;
	bool	 m_bCustomCameraFOV = false;
	bool	 m_bFreeCam = false;
	bool	 m_bCustomCameras = false;
	bool	 m_bYObtained = false;
	bool	 m_bStageModifier = false;
	// cheats
	bool	m_bInfiniteHealthP1 = false;
	bool	m_bInfiniteHealthP2 = false;
	bool	m_bInfiniteMeterP1 = false;
	bool	m_bInfiniteMeterP2 = false;
	bool	m_bNoHealthP1 = false;
	bool	m_bNoHealthP2 = false;
	bool	m_bZeroMeterP1 = false;
	bool	m_bZeroMeterP2 = false;

	bool	m_bPlayer1Modifier = false;
	bool	m_bPlayer2Modifier = false;

	int		 m_nFreeCameraRotationSpeed = 20;
	float	 m_fFreeCameraSpeed = 1.0f;


	int* m_pCurrentVarToChange = nullptr;

	int  m_nScriptExecuteType = 0;
	char* m_nHash = 0;
	MKScript* m_pScript;

	char szPlayer1ModifierCharacter[128] = {};
	char szPlayer2ModifierCharacter[128] = {};
	char szStageModifierStage[128] = {};

	FVector camPos;
	FRotator camRot;
	float camFov;

	std::vector<eScriptKeyBind> m_vKeyBinds;

	void Initialize();
	void Process();
	void Draw();
	void UpdateControls();

	void DrawCharacterTab();
	void DrawStageTab();
	void DrawCameraTab();
	void DrawCheatsTab();
	void DrawScriptTab();

	void DrawSettings();

	void DrawKeyBind(char* name, int* var);
	void KeyBind(int* var, char* bindName, char* name);

	void RunLastScript();

	void ProcessScriptHotkeys();

	bool GetActiveState();
};



extern DCFMenu* TheMenu;

char* GetINJHookVersion();