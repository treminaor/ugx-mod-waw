#undef		OPTIONS_STYLE
#undef		STYLE2_NOPOSITION
#define		OPTIONS_LEFT
#include "ui_mp/menustyle.inc"
#undef		OPTIONS_LEFT

#ifndef BACKGROUND_BLACK_LETTERBOX_BLURWORLD_VIS
#include "ui/overlaybg.inc"
#endif

#ifdef PC_INGAME
	BACKGROUND_BLACK_LETTERBOX_BLURWORLD_VIS( 1 , 1 )
	OVERLAY_BACKGROUND
	CHOICE_MENU_TITLE( "@MENU_OPTIONS_UPPER_CASE" )
#else
	CHOICE_OVERLAY_TITLE( "@MENU_OPTIONS_UPPER_CASE" )
#endif

#undef BACK_OPEN
#define BACK_OPEN exec "wait";
#include "ui_mp/navcontrols.inc"

#undef CHOICE_X_START
#define CHOICE_X_START		30

#undef CHOICE_Y_START
#define CHOICE_Y_START		65

#undef		CHOICE_SIZE_Y
#define		CHOICE_SIZE_Y		22

fullScreen		0
rect			0 0 640 480	HORIZONTAL_ALIGN_FULLSCREEN

//#define INIT_UGX_SETTINGS_VARS	exec "exec ugx_testconfig"

CHOICE_BUTTON( 1, "@MENU_GRAPHICS_CAP", LOCAL_CLOSE_ALL open options_graphics )
CHOICE_BUTTON( 2, "@MENU_TEXTURE_SETTINGS_CAP", LOCAL_CLOSE_ALL open options_graphics_texture )
CHOICE_BUTTON( 3, "@MENU_SOUND_CAP", LOCAL_CLOSE_ALL open options_sound )
CHOICE_BUTTON( 4, "@MENU_VOICECHAT_CAP", LOCAL_CLOSE_ALL open options_voice )
CHOICE_BUTTON( 5, "@MENU_GAME_OPTIONS_CAP", LOCAL_CLOSE_ALL open options_game )
CHOICE_BUTTON( 6, "^2UGX Mod Options", LOCAL_CLOSE_ALL open overheadmap )
//CHOICE_BUTTON( 6, "^2UGX Mod Options", LOCAL_CLOSE_ALL; INIT_UGX_SETTINGS_VARS open overheadmap )
CHOICE_NEWICON_VIS( 6, "specialty_new", when( dvarInt(ugx_client_seen_settings) == 0 ); )
CHOICE_BUTTON_VIS( 7, "@MENU_MULTIPLAYER_OPTIONS_CAP", LOCAL_CLOSE_ALL open options_multi, when( dvarbool( ui_multiplayer ) ); )
CHOICE_BUTTON_VIS( 7, "@MENU_COOPERATIVE_OPTIONS_CAP", LOCAL_CLOSE_ALL open options_multi, when( !dvarbool( ui_multiplayer ) ); )
#ifdef PC_INGAME
CHOICE_DBUTTON_VIS( 8, "@PLATFORM_DEFAULT_SYSTEM_SETTINGS_CAP", 1; )
#else // #ifdef PC_INGAME
CHOICE_BUTTON( 8, "@PLATFORM_DEFAULT_SYSTEM_SETTINGS_CAP", LOCAL_CLOSE_ALL open options_graphics_defaults )
#endif // #ifdef PC_INGAME
CHOICE_BUTTON( 9, "@MENU_CONTROLS_CAP", LOCAL_CLOSE_ALL open options_controls_new_pc; close options_new_pc )

#undef		CHOICE_SIZE_X
#undef		CHOICE_SIZE_Y

#define CHOICE_SIZE_X			150//250
#define CHOICE_SIZE_Y			20

#define		OPTIONS_STYLE			1
#undef		STYLE2_NOPOSITION
#define STYLE2_NOPOSITION
#include "ui_mp/menustyle.inc"

#undef CHOICE_TEXTSIZE
#define CHOICE_TEXTSIZE 	TEXTSIZE_SMALL
#undef	CHOICE_TEXTALIGN
#define	CHOICE_TEXTALIGN	ITEM_ALIGN_MIDDLE_RIGHT
#undef	CHOICE_TEXT_OFFSET_X
#define CHOICE_TEXT_OFFSET_X	(-(4+CHOICE_SIZE_Y)) //22

#undef  CHOICE_DVAR_OFFSET_X
#define CHOICE_DVAR_OFFSET_X	(CHOICE_SIZE_X+20)
#undef  CHOICE_DVAR_TEXTALIGN
#define CHOICE_DVAR_TEXTALIGN	ITEM_ALIGN_MIDDLE_LEFT
#undef CHOICE_DVAR_WIDTH_OFFSET
#define CHOICE_DVAR_WIDTH_OFFSET	120
#undef CHOICE_ACTION_SOUND	
#define CHOICE_ACTION_SOUND		"mouse_click_t"

#undef CHOICE_Y_START
#define CHOICE_Y_START		25

#undef CHOICE_X_START
#define CHOICE_X_START		75