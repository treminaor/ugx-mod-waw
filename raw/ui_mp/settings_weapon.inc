// -- weapon options
#define CHOICE_HEADSHOTS_TEXT		"@MPUI_RULES_HEADSHOTS_ONLY"
#define CHOICE_HEADSHOTS_DVAR		"scr_game_onlyheadshots"
#define CHOICE_HEADSHOTS_DVARTEXT	CHOICE_HEADSHOTS_DVAR"_text"
#define CHOICE_HEADSHOTS_SHOW		1
#define CHOICE_HEADSHOTS_STRLIST	{ "@MENU_DISABLED" 0 "@MENU_ENABLED" 1}
#ifndef PC
	#define CHOICE_HEADSHOTS_EXEC	exec "toggle "CHOICE_HEADSHOTS_DVAR" 0 1"; play "mouse_click";
#else
	#define CHOICE_HEADSHOTS_EXEC	play "mouse_click";
#endif

#define CHOICE_PERKS_TEXT		"@MPUI_RULES_ALLOW_PERKS"
#define CHOICE_PERKS_DVAR		"scr_game_perks"
#define CHOICE_PERKS_DVARTEXT	CHOICE_PERKS_DVAR"_text"
#define CHOICE_PERKS_SHOW		1
#define CHOICE_PERKS_STRLIST	{ "@MENU_DISABLED" 0 "@MENU_ENABLED" 1}
#ifndef PC
	#define CHOICE_PERKS_EXEC		exec "toggle "CHOICE_PERKS_DVAR" 0 1"; play "mouse_click";
#else
	#define CHOICE_PERKS_EXEC	play "mouse_click";
#endif

#define CHOICE_VEHICLES_TEXT		"@MPUI_VEHICLES"
#define CHOICE_VEHICLES_DVAR		"scr_vehicles_enabled"
#define CHOICE_VEHICLES_DVARTEXT	CHOICE_VEHICLES_DVAR"_text"
#define CHOICE_VEHICLES_SHOW		1
#define CHOICE_VEHICLES_STRLIST	{ "@MENU_DISABLED" 0 "@MENU_ENABLED" 1}
#ifndef PC
	#define CHOICE_VEHICLES_EXEC		execNow "toggle "CHOICE_VEHICLES_DVAR" 0 1"; play "mouse_click";
#else
	#define CHOICE_VEHICLES_EXEC	play "mouse_click";
#endif

#define CHOICE_HARDCORE_TEXT		"@MPUI_RULES_HARDCORE"
#define CHOICE_HARDCORE_DVAR		"scr_hardcore"
#define CHOICE_HARDCORE_DVARTEXT	CHOICE_HARDCORE_DVAR"_text"
#define CHOICE_HARDCORE_SHOW		1
#define CHOICE_HARDCORE_EXEC1		execNowOnDvarIntValue scr_hardcore 0 "exec hardcore_disable.cfg";
#define CHOICE_HARDCORE_EXEC2		execNowOnDvarIntValue scr_hardcore 1 "exec hardcore_settings.cfg";
#define CHOICE_HARDCORE_STRLIST	{ "@MENU_DISABLED" 0 "@MENU_ENABLED" 1}
#ifndef PC
	#define CHOICE_HARDCORE_EXEC		execNow "toggle "CHOICE_HARDCORE_DVAR" 0 1"; play "mouse_click"; CHOICE_HARDCORE_EXEC1 CHOICE_HARDCORE_EXEC2
#else
	#define CHOICE_HARDCORE_EXEC	play "mouse_click"; CHOICE_HARDCORE_EXEC1 CHOICE_HARDCORE_EXEC2
#endif

#define CHOICE_HARDPOINTS_TEXT		"@MPUI_RULES_AIRSUPPORT"
#define CHOICE_HARDPOINTS_DVAR		"scr_game_hardpoints"
#define CHOICE_HARDPOINTS_DVARTEXT	CHOICE_HARDPOINTS_DVAR"_text"
#define CHOICE_HARDPOINTS_SHOW		1
#define CHOICE_HARDPOINTS_STRLIST	{ "@MENU_DISABLED" 0 "@MENU_ENABLED" 1}
#ifndef PC
	#define CHOICE_HARDPOINTS_EXEC		exec "toggle "CHOICE_HARDPOINTS_DVAR" 0 1"; play "mouse_click";
#else
	#define CHOICE_HARDPOINTS_EXEC	play "mouse_click";
#endif