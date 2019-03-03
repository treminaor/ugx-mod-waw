//controls_common_info.inc

// control settings

#define LOCALIZATION_FILE	"@MENU"

#ifdef SINGLE_PLAYER
#undef	LOCALIZATION_FILE
#define LOCALIZATION_FILE	"@MENU"
#endif

#undef OPTIONS_MENU_NAME
#define OPTIONS_MENU_NAME "options"

#undef CONTROL_THUMBSTICK_NAME
#define CONTROL_THUMBSTICK_NAME "thumbstick"

#undef CONTROL_BUTTONS_NAME
#define CONTROL_BUTTONS_NAME "buttons"

#undef CONTROL_SENSITIVITY_NAME
#define CONTROL_SENSITIVITY_NAME "sensitivity"

#undef CONTROL_SENSITIVITY_CUSTOM_NAME
#define CONTROL_SENSITIVITY_CUSTOM_NAME "sensitivity_custom"

#undef CONTROL_TEAM_INDICATOR_NAME
#define CONTROL_TEAM_INDICATOR_NAME "team_indicator"

#undef CONTROL_VOLUME_NAME
#define CONTROL_VOLUME_NAME "volume"

#undef CONTROL_BRIGHTNESS_NAME
#define CONTROL_BRIGHTNESS_NAME "brightness"

#define BG_SHADE_COLOR	0 0 0 0.75

#ifdef	CONTROL_IN_GAME
	#undef OPTIONS_MENU_NAME
	#define OPTIONS_MENU_NAME "ingameoptions"
	
	#undef CONTROL_THUMBSTICK_NAME
	#define CONTROL_THUMBSTICK_NAME "ingameoptions_thumbstick"
	
	#undef CONTROL_BUTTONS_NAME
	#define CONTROL_BUTTONS_NAME "ingameoptions_buttons"
	
	#undef CONTROL_SENSITIVITY_NAME
	#define CONTROL_SENSITIVITY_NAME "ingameoptions_sensitivity"

	#undef CONTROL_SENSITIVITY_CUSTOM_NAME
	#define CONTROL_SENSITIVITY_CUSTOM_NAME "ingameoptions_sensitivity_custom"

	#undef CONTROL_TEAM_INDICATOR_NAME
	#define CONTROL_TEAM_INDICATOR_NAME "ingameoptions_team_indicator"

	#undef CONTROL_VOLUME_NAME
	#define CONTROL_VOLUME_NAME "ingameoptions_volume"

	#undef CONTROL_BRIGHTNESS_NAME
	#define CONTROL_BRIGHTNESS_NAME "ingameoptions_brightness"
	
	#undef BG_SHADE_COLOR
	#define BG_SHADE_COLOR	0 0 0 0.75
#endif

#ifdef	CONTROL_IN_GAME_SPLITSCREEN
	#undef OPTIONS_MENU_NAME
	#define OPTIONS_MENU_NAME "ingameoptions_splitscreen"
	
	#undef CONTROL_THUMBSTICK_NAME
	#define CONTROL_THUMBSTICK_NAME "ingameoptions_thumbstick_splitscreen"
	
	#undef CONTROL_BUTTONS_NAME
	#define CONTROL_BUTTONS_NAME "ingameoptions_buttons_splitscreen"
	
	#undef CONTROL_SENSITIVITY_NAME
	#define CONTROL_SENSITIVITY_NAME "ingameoptions_sensitivity_splitscreen"

	#undef CONTROL_SENSITIVITY_CUSTOM_NAME
	#define CONTROL_SENSITIVITY_CUSTOM_NAME "ingameoptions_sensitivity_splitscreen_custom"

	#undef CONTROL_TEAM_INDICATOR_NAME
	#define CONTROL_TEAM_INDICATOR_NAME "ingameoptions_team_indicator_splitscreen"
	
	#undef CONTROL_VOLUME_NAME
	#define CONTROL_VOLUME_NAME "ingameoptions_volume_splitscreen"

	#undef CONTROL_BRIGHTNESS_NAME
	#define CONTROL_BRIGHTNESS_NAME "ingameoptions_brightness_splitscreen"

	#undef BG_SHADE_COLOR
	#define BG_SHADE_COLOR	0 0 0 0.85
#endif

#ifdef PS3
	// ps3 voice volume control ==================
	#define LOCAL_VOICE_METER_RAW( dvar1, dvar2 )\
			execOnDvarFloatValue ps3_voiceSpeakerGain dvar1 "set ps3_voiceSpeakerGain "dvar2;
			
	#define LOCAL_VOICE_METER_1 \
			LOCAL_VOICE_METER_RAW( 1.2, "1.5" )\
			LOCAL_VOICE_METER_RAW( 1.5, "2.0" )\
			LOCAL_VOICE_METER_RAW( 2.0, "2.5" )\
			LOCAL_VOICE_METER_RAW( 2.5, "3.0" )\
			LOCAL_VOICE_METER_RAW( 3.0, "3.5" )\
			LOCAL_VOICE_METER_RAW( 3.5, "4.0" )\
			LOCAL_VOICE_METER_RAW( 4.0, "4.5" )\
			LOCAL_VOICE_METER_RAW( 4.5, "5.0" )\
			LOCAL_VOICE_METER_RAW( 5.0, "6.0" )\
			LOCAL_VOICE_METER_RAW( 6.0, "7.0" )\
			LOCAL_VOICE_METER_RAW( 7.0, "8.0" )\
			LOCAL_VOICE_METER_RAW( 8.0, "9.0" )\
			LOCAL_VOICE_METER_RAW( 9.0, "10.0")
			
	#define LOCAL_VOICE_METER_2 \
			LOCAL_VOICE_METER_RAW( 10.0, "9.0")\
			LOCAL_VOICE_METER_RAW( 9.0, "8.0" )\
			LOCAL_VOICE_METER_RAW( 8.0, "7.0" )\
			LOCAL_VOICE_METER_RAW( 7.0, "6.0" )\
			LOCAL_VOICE_METER_RAW( 6.0, "5.0" )\
			LOCAL_VOICE_METER_RAW( 5.0, "4.5" )\
			LOCAL_VOICE_METER_RAW( 4.5, "4.0" )\
			LOCAL_VOICE_METER_RAW( 4.0, "3.5" )\
			LOCAL_VOICE_METER_RAW( 3.5, "3.0" )\
			LOCAL_VOICE_METER_RAW( 3.0, "2.5" )\
			LOCAL_VOICE_METER_RAW( 2.5, "2.0" )\
			LOCAL_VOICE_METER_RAW( 2.0, "1.5" )\
			LOCAL_VOICE_METER_RAW( 1.5, "1.2" )
			
	#define LOCAL_VOICE_EXTRA \
		execKeyInt DPAD_RIGHT { LOCAL_VOICE_METER_1 }\
		execKeyInt APAD_RIGHT { LOCAL_VOICE_METER_1 }\
		execKeyInt DPAD_LEFT { LOCAL_VOICE_METER_2 }\
		execKeyInt APAD_LEFT { LOCAL_VOICE_METER_2 }
#endif

#define LOCAL_BG \
itemDef	{\
	style			WINDOW_STYLE_FILLED\
	rect			0 0 640 480 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN\
	backcolor		BG_SHADE_COLOR\
	visible			1	decoration}\
itemDef	{\
	style			WINDOW_STYLE_SHADER\
	rect			0 0 854 75 HORIZONTAL_ALIGN_FULLSCREEN 0\
	background		"gradient_top"\
	visible			1	decoration}\
itemDef	{\
	style			WINDOW_STYLE_SHADER\
	rect			0 410 854 75 HORIZONTAL_ALIGN_FULLSCREEN 0\
	background		"gradient_bottom"\
	visible			1	decoration}


// THUMBSTICK LAYOUT MENU
menuDef 
{
	name			CONTROL_THUMBSTICK_NAME
#ifdef	CONTROL_IN_GAME	
	rect			0 0 640 480
	focuscolor		COLOR_FOCUSED
	style			WINDOW_STYLE_EMPTY
	blurWorld		6.0
	legacySplitScreenScale
	onOpen 	
	{
		setdvar cg_drawhud "0";
		setDvar ui_allow_controlschange "0";
	}
	onclose	
	{
		setdvar cg_drawhud "1";
		setDvar ui_allow_controlschange "1";
		exec "updategamerprofile";
		open OPTIONS_MENU_NAME;
	}
	onEsc
	{ 
		close CONTROL_THUMBSTICK_NAME; 
		open OPTIONS_MENU_NAME;
	}
	LOCAL_BG
#else
	fullscreen		1
	rect			0 0 640 480
	focuscolor		COLOR_FOCUSED
	soundloop 		"music_mainmenu"
	style			WINDOW_STYLE_EMPTY
	legacySplitScreenScale
	onEsc
	{ 
		close CONTROL_THUMBSTICK_NAME; 
	}
	#ifndef SINGLE_PLAYER
		#include "ui_mp/blurredbg.inc"
	#else
		#include "ui/bg.inc"
	#endif
#endif

	// ------------------ TREE TITLE ------------------
	#ifdef	CONTROL_IN_GAME_SPLITSCREEN
		CHOICE_MENU_TITLE_SS( "@MENU_STICK_LAYOUT_CAP" )
	#else
		CHOICE_MENU_TITLE( "@MENU_STICK_LAYOUT_CAP" )
	#endif
	// ------------------ buttons ---------------------
	#undef	LOCAL_NOT_IN_CAC
	#undef	LOCAL_IN_CAC
	#include "ui/navcontrols.inc"
	
	#define SETUP_ACTION( pconfig ) \
		setDvar gpad_sticksConfig pconfig \
		execNow "updategamerprofile"; \
		close CONTROL_THUMBSTICK_NAME;

#ifndef	CONTROL_IN_GAME_SPLITSCREEN

	#include "ui/controls_thumbstick_set.menu"
	
	#define SETUP_FOCUS( pnum ) \
		show "controls_thumbstick_set"pnum;
	
	#define SETUP_UNFOCUS( pnum ) \
		hide "controls_thumbstick_set"pnum;
#else
	#define SETUP_FOCUS( pnum ) ;
	#define SETUP_UNFOCUS( pnum ) ;
#endif
	
	CHOICE_BUTTON_FOCUS( 1, "@MENU_DEFAULT", SETUP_ACTION( "thumbstick_default" ), SETUP_FOCUS( "1" ), SETUP_UNFOCUS( "1" ) )
	CHOICE_BUTTON_FOCUS( 2, "@MENU_SOUTHPAW", SETUP_ACTION( "thumbstick_southpaw" ), SETUP_FOCUS( "2" ), SETUP_UNFOCUS( "2" ) )
	CHOICE_BUTTON_FOCUS( 3, "@MENU_LEGACY", SETUP_ACTION( "thumbstick_legacy" ), SETUP_FOCUS( "3" ), SETUP_UNFOCUS( "3" ) )
	CHOICE_BUTTON_FOCUS( 4, "@MENU_LEGACY_SOUTHPAW", SETUP_ACTION( "thumbstick_legacysouthpaw" ), SETUP_FOCUS( "4" ), SETUP_UNFOCUS( "4" ) )

	#include "ui/safearea.menu"
}

// BUTTON LAYOUT MENU
menuDef 
{
	name			CONTROL_BUTTONS_NAME
#ifdef	CONTROL_IN_GAME	
	rect			0 0 640 480
	focuscolor		COLOR_FOCUSED
	style			WINDOW_STYLE_EMPTY
	blurWorld		6.0
	legacySplitScreenScale
	onOpen 	
	{
		setdvar cg_drawhud "0";
		setDvar ui_allow_controlschange "0";
	}
	onclose	
	{
		setdvar cg_drawhud "1";
		setDvar ui_allow_controlschange "1";
		exec "updategamerprofile";
		open OPTIONS_MENU_NAME;
	}
	onEsc 	
	{
		close CONTROL_BUTTONS_NAME;
		open OPTIONS_MENU_NAME;
	}
	LOCAL_BG
#else
	fullscreen		1
	rect			0 0 640 480
	focuscolor		COLOR_FOCUSED
	soundloop 		"music_mainmenu"
	style			WINDOW_STYLE_EMPTY
	legacySplitScreenScale
	onEsc
	{
		close CONTROL_BUTTONS_NAME;
	}
	#ifndef SINGLE_PLAYER
		#include "ui_mp/blurredbg.inc"
	#else
		#include "ui/bg.inc"
	#endif
#endif

	// ------------------ TREE TITLE ------------------
	#ifdef	CONTROL_IN_GAME_SPLITSCREEN
		CHOICE_MENU_TITLE_SS( "@MENU_BUTTON_LAYOUT_CAP" )
	#else
		CHOICE_MENU_TITLE( "@MENU_BUTTON_LAYOUT_CAP" )
	#endif
	// ------------------ buttons ---------------------
	#undef	LOCAL_NOT_IN_CAC
	#undef	LOCAL_IN_CAC
	#include "ui/navcontrols.inc"
	
	#define SETUP_ACTION2( pconfig ) \
		setDvar gpad_buttonsConfig pconfig \
		execNow "updategamerprofile"; \
		close CONTROL_BUTTONS_NAME;
		
#ifndef	CONTROL_IN_GAME_SPLITSCREEN

	#include "ui_mp/controls_buttons_set.menu"

	#define SETUP_FOCUS2( pnum ) \
		show "controls_buttons_set"pnum;
	
	#define SETUP_UNFOCUS2( pnum ) \
		hide "controls_buttons_set"pnum;
#else
	#define SETUP_FOCUS2( pnum ) ;
	#define SETUP_UNFOCUS2( pnum ) ;
#endif

	CHOICE_BUTTON_FOCUS( 1, "@MENU_DEFAULT", SETUP_ACTION2( "buttons_default" ), SETUP_FOCUS2( "1" ), SETUP_UNFOCUS2( "1" ) )
	CHOICE_BUTTON_FOCUS( 2, "@MENU_TACTICAL", SETUP_ACTION2( "buttons_experimental" ), SETUP_FOCUS2( "2" ), SETUP_UNFOCUS2( "2" ) )
	CHOICE_BUTTON_FOCUS( 3, "@MENU_LEFTY", SETUP_ACTION2( "buttons_lefty" ), SETUP_FOCUS2( "3" ), SETUP_UNFOCUS2( "3" ) )
	#ifdef PS3
	CHOICE_BUTTON_FOCUS( 4, "@MENU_DEFAULT_ALT", SETUP_ACTION2( "buttons_default_alt" ), SETUP_FOCUS2( "4" ), SETUP_UNFOCUS2( "4" ) )
	CHOICE_BUTTON_FOCUS( 5, "@MENU_TACTICAL_ALT", SETUP_ACTION2( "buttons_experimental_alt" ), SETUP_FOCUS2( "5" ), SETUP_UNFOCUS2( "5" ) )
	CHOICE_BUTTON_FOCUS( 6, "@MENU_LEFTY_ALT", SETUP_ACTION2( "buttons_lefty_alt" ), SETUP_FOCUS2( "6" ), SETUP_UNFOCUS2( "6" ) )
	#else
	CHOICE_BUTTON_FOCUS( 4, "@PATCH_NOMAD", SETUP_ACTION2( "buttons_nomad" ), SETUP_FOCUS2( "4" ), SETUP_UNFOCUS2( "4" ) )

	#endif

	#include "ui/safearea.menu"
}

// LOOK SENSITIVITY MENU
menuDef 
{
	name			CONTROL_SENSITIVITY_NAME
#ifdef	CONTROL_IN_GAME	
	rect			0 0 640 480
	focuscolor		COLOR_FOCUSED
	style			WINDOW_STYLE_EMPTY
	blurWorld		6.0
	legacySplitScreenScale
	onclose	
	{
		setdvar cg_drawhud "1";
		setDvar ui_allow_controlschange "1";
		exec "updategamerprofile";
	}
	onOpen 	
	{
		setfocusbydvar "input_viewSensitivity";
		setdvar cg_drawhud "0";
		setDvar ui_allow_controlschange "0";
	}
	onEsc 
	{	
		close CONTROL_SENSITIVITY_NAME;	
		open OPTIONS_MENU_NAME;
	}
	LOCAL_BG
#else
	fullscreen		1
	rect			0 0 640 480
	focuscolor		COLOR_FOCUSED
	soundloop 		"music_mainmenu"
	style			WINDOW_STYLE_EMPTY
	legacySplitScreenScale
	onOpen
	{
		setfocusbydvar "input_viewSensitivity";
	}
	onEsc
	{	
		close CONTROL_SENSITIVITY_NAME;
		open OPTIONS_MENU_NAME;
	}
	#ifndef SINGLE_PLAYER
		#include "ui_mp/blurredbg.inc"
	#else
		#include "ui/bg.inc"
	#endif
#endif
	
	// ------------------ TREE TITLE ------------------
	#ifdef	CONTROL_IN_GAME_SPLITSCREEN
		CHOICE_MENU_TITLE_SS( "@MENU_SENSITIVITY_CAP" )
	#else
		CHOICE_MENU_TITLE( "@MENU_SENSITIVITY_CAP" )
	#endif
	// ------------------ buttons ---------------------
	#undef	LOCAL_NOT_IN_CAC
	#undef	LOCAL_IN_CAC
	#include "ui/navcontrols.inc"

	#define SETUP_ACTION3( pconfig ) \
		exec pconfig \
		execNow "updategamerprofile"; \
		close CONTROL_SENSITIVITY_NAME; \
		open OPTIONS_MENU_NAME;

	#define SETUP_EXTRA( pnum ) \
		dvartest "input_viewSensitivity" focusdvar { pnum }

	CHOICE_BUTTON_FOCUS_VIS_EX( 1, "@MENU_LOW", SETUP_ACTION3( "exec viewSensitivity_low" ), ;, ;, when( 1 ), SETUP_EXTRA( SENSITIVITY_1_S ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 2, "@MENU_MEDIUM", SETUP_ACTION3( "exec viewSensitivity_med" ), ;, ;, when( 1 ), SETUP_EXTRA( SENSITIVITY_2_S ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 3, "@MENU_HIGH", SETUP_ACTION3( "exec viewSensitivity_high" ), ;, ;, when( 1 ), SETUP_EXTRA( SENSITIVITY_4_S ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 4, "@MENU_CUSTOM", close CONTROL_SENSITIVITY_NAME; open CONTROL_SENSITIVITY_CUSTOM_NAME, ;, ;, when( 1 ), name sensitivity_custom; )	

	#include "ui/safearea.menu"
}



// CUSTOM LOOK SENSITIVITY MENU
menuDef 
{
	name			CONTROL_SENSITIVITY_CUSTOM_NAME
#ifdef	CONTROL_IN_GAME	
	rect			0 0 640 480
	focuscolor		COLOR_FOCUSED
	style			WINDOW_STYLE_EMPTY
	blurWorld		6.0
	legacySplitScreenScale
	onclose	
	{
		setdvar cg_drawhud "1";
		setDvar ui_allow_controlschange "1";
	}
	onOpen 	
	{
		setfocusbydvar "input_viewSensitivity";
		setdvar cg_drawhud "0";
		setDvar ui_allow_controlschange "0";
	}
	onEsc 
	{	
		close CONTROL_SENSITIVITY_CUSTOM_NAME;	
		open CONTROL_SENSITIVITY_NAME;
	}
	LOCAL_BG
#else
	fullscreen		1
	rect			0 00 640 480
	focuscolor		COLOR_FOCUSED
	soundloop 		"music_mainmenu"
	style			WINDOW_STYLE_EMPTY
	legacySplitScreenScale
	onOpen 	
	{
		setfocusbydvar "input_viewSensitivity";
	}
	onEsc
	{	
		close CONTROL_SENSITIVITY_CUSTOM_NAME;	
		open CONTROL_SENSITIVITY_NAME;
	}
	#ifndef SINGLE_PLAYER
		#include "ui_mp/blurredbg.inc"
	#else
		#include "ui/bg.inc"
	#endif
#endif
	
	// ------------------ TREE TITLE ------------------
	#ifdef	CONTROL_IN_GAME_SPLITSCREEN
		CHOICE_MENU_TITLE_SS( "@MENU_SENSITIVITY_CUSTOM_CAP" )
	#else
		CHOICE_MENU_TITLE( "@MENU_SENSITIVITY_CUSTOM_CAP" )
	#endif
	// ------------------ buttons ---------------------
	#undef	LOCAL_NOT_IN_CAC
	#undef	LOCAL_IN_CAC
	#include "ui/navcontrols.inc"

	#define SETUP_CUSTOM_ACTION( pval ) \
		setDvar input_viewSensitivity pval; \
		execNow "updategamerprofile"; \
		close self; \
		open OPTIONS_MENU_NAME;

	#define SETUP_CUSTOM_EXTRA( pnum ) \
		dvartest "input_viewSensitivity" focusdvar { pnum }
	
	#ifdef	CONTROL_IN_GAME_SPLITSCREEN
		#undef CHOICE_Y_COUNT
		#define CHOICE_Y_COUNT	5
		#undef CHOICE_X_SPACING
		#define CHOICE_X_SPACING	180
	#endif

	CHOICE_BUTTON_FOCUS_VIS_EX( 1, locString( "@MENU_SENSITIVITY_LOW_N", 1 ), SETUP_CUSTOM_ACTION( SENSITIVITY_1 ), ;, ;, when( 1 ), SETUP_CUSTOM_EXTRA( SENSITIVITY_1_S ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 2, locString( "@MENU_SENSITIVITY_MEDIUM_N", 2 ), SETUP_CUSTOM_ACTION( SENSITIVITY_2 ), ;, ;, when( 1 ), SETUP_CUSTOM_EXTRA( SENSITIVITY_2_S ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 3, 3, SETUP_CUSTOM_ACTION( SENSITIVITY_3 ), ;, ;, when( 1 ), SETUP_CUSTOM_EXTRA( SENSITIVITY_3_S ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 4, locString( "@MENU_SENSITIVITY_HIGH_N", 4 ), SETUP_CUSTOM_ACTION( SENSITIVITY_4 ), ;, ;, when( 1 ), SETUP_CUSTOM_EXTRA( SENSITIVITY_4_S ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 5, 5, SETUP_CUSTOM_ACTION( SENSITIVITY_5 ), ;, ;, when( 1 ), SETUP_CUSTOM_EXTRA( SENSITIVITY_5_S ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 6, 6, SETUP_CUSTOM_ACTION( SENSITIVITY_6 ), ;, ;, when( 1 ), SETUP_CUSTOM_EXTRA( SENSITIVITY_6_S ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 7, locString( "@MENU_SENSITIVITY_VERY_HIGH_N", 7 ), SETUP_CUSTOM_ACTION( SENSITIVITY_7 ), ;, ;, when( 1 ), SETUP_CUSTOM_EXTRA( SENSITIVITY_7_S ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 8, 8, SETUP_CUSTOM_ACTION( SENSITIVITY_8 ), ;, ;, when( 1 ), SETUP_CUSTOM_EXTRA( SENSITIVITY_8_S ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 9, 9, SETUP_CUSTOM_ACTION( SENSITIVITY_9 ), ;, ;, when( 1 ), SETUP_CUSTOM_EXTRA( SENSITIVITY_9_S ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 10, locString( "@MENU_SENSITIVITY_INSANE_N", 10 ), SETUP_CUSTOM_ACTION( SENSITIVITY_10 ), ;, ;, when( 1 ), SETUP_CUSTOM_EXTRA( SENSITIVITY_10_S ) )

	#ifdef	CONTROL_IN_GAME_SPLITSCREEN
		#undef CHOICE_Y_COUNT
		#define CHOICE_Y_COUNT	20
		#undef CHOICE_X_SPACING
		#define CHOICE_X_SPACING	280
	#endif

	#include "ui/safearea.menu"
}

// LOOK TEAM INDICATOR MENU
menuDef 
{
	name			CONTROL_TEAM_INDICATOR_NAME
#ifdef	CONTROL_IN_GAME	
	rect			0 0 640 480
	focuscolor		COLOR_FOCUSED
	style			WINDOW_STYLE_EMPTY
	blurWorld		6.0
	legacySplitScreenScale
	onclose	
	{
		setdvar cg_drawhud "1";
		setDvar ui_allow_controlschange "1";
		exec "updategamerprofile";
		open OPTIONS_MENU_NAME;
	}
	onOpen 	
	{
		setfocusbydvar "team_indicator";
		setdvar cg_drawhud "0";
		setDvar ui_allow_controlschange "0";
	}
	onEsc 
	{	
		close CONTROL_TEAM_INDICATOR_NAME;	
		open OPTIONS_MENU_NAME;
	}
	LOCAL_BG
#else
	fullscreen		1
	rect			0 0 640 480
	focuscolor		COLOR_FOCUSED
	soundloop 		"music_mainmenu"
	style			WINDOW_STYLE_EMPTY
	legacySplitScreenScale
	onOpen
	{
		setfocusbydvar "team_indicator";
	}
	onEsc
	{	
		close CONTROL_TEAM_INDICATOR_NAME;
		open OPTIONS_MENU_NAME;
	}
	#ifndef SINGLE_PLAYER
		#include "ui_mp/blurredbg.inc"
	#else
		#include "ui/bg.inc"
	#endif
#endif
	
	// ------------------ TREE TITLE ------------------
	#ifdef	CONTROL_IN_GAME_SPLITSCREEN
		CHOICE_MENU_TITLE_SS( "@MENU_TEAM_INDICATOR_CAP" )
	#else
		CHOICE_MENU_TITLE( "@MENU_TEAM_INDICATOR_CAP" )
	#endif
	// ------------------ buttons ---------------------
	#undef	LOCAL_NOT_IN_CAC
	#undef	LOCAL_IN_CAC
	#include "ui/navcontrols.inc"

	#define TEAM_INDICATOR_ACTION( pconfig ) \
		exec pconfig; \
		execNow "updategamerprofile"; \
		close CONTROL_TEAM_INDICATOR_NAME; \
		open OPTIONS_MENU_NAME;

	#define SETUP_FOCUS_ON_INDICATOR( pnum ) \
		dvartest "team_indicator" focusdvar { pnum }

	CHOICE_BUTTON_FOCUS_VIS_EX( 1, "@MENU_FULL_TEAM_INDICATOR", TEAM_INDICATOR_ACTION( "set team_indicator 0" );, ;, ;, when( 1 ), SETUP_FOCUS_ON_INDICATOR( 0 ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 2, "@MENU_ABBREVIATED_TEAM_INDICATOR", TEAM_INDICATOR_ACTION( "set team_indicator 1" ) ;, ;, ;, when( 1 ), SETUP_FOCUS_ON_INDICATOR( 1 ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 3, "@MENU_ICON_TEAM_INDICATOR", TEAM_INDICATOR_ACTION( "set team_indicator 2" );, ;, ;, when( 1 ), SETUP_FOCUS_ON_INDICATOR( 2 ) )
	CHOICE_BUTTON_FOCUS_VIS_EX( 4, "@PATCH_TEAM_ALTERNATE_COLOR", TEAM_INDICATOR_ACTION( "set team_indicator 3" );, ;, ;, when( 1 ), SETUP_FOCUS_ON_INDICATOR( 3 ) )

	#include "ui/safearea.menu"
}

// VOLUME MENU
menuDef 
{
	name			CONTROL_VOLUME_NAME
#ifdef	CONTROL_IN_GAME	
	rect			0 0 640 480
	focuscolor		COLOR_FOCUSED
	style			WINDOW_STYLE_EMPTY
	blurWorld		6.0
	legacySplitScreenScale
	onclose	
	{
		setdvar cg_drawhud "1";
		setDvar ui_allow_controlschange "1";
		exec "updategamerprofile";
	}
	onOpen 	
	{
		setdvar cg_drawhud "0";
		setDvar ui_allow_controlschange "0";
	}
	onEsc 
	{	
		close CONTROL_VOLUME_NAME;	
		open OPTIONS_MENU_NAME;
	}
	LOCAL_BG
#else
	fullscreen		1
	rect			0 0 640 480
	focuscolor		COLOR_FOCUSED
	soundloop 		"music_mainmenu"
	style			WINDOW_STYLE_EMPTY
	legacySplitScreenScale
	onEsc
	{	
		close CONTROL_VOLUME_NAME;
	}
	#ifndef SINGLE_PLAYER
		#include "ui_mp/blurredbg.inc"
	#else
		#include "ui/bg.inc"
	#endif
#endif
	
	// ------------------ TREE TITLE ------------------
	#ifdef	CONTROL_IN_GAME_SPLITSCREEN
		CHOICE_MENU_TITLE_SS( "@MENU_VOLUME" )
	#else
		CHOICE_MENU_TITLE( "@MENU_VOLUME" )
	#endif
	// ------------------ buttons ---------------------
	#undef	LOCAL_NOT_IN_CAC
	#undef	LOCAL_IN_CAC
	#include "ui/navcontrols.inc"

	#undef A_BUTTON_OFFSET_X
	#define A_BUTTON_OFFSET_X 100000

	CHOICE_DVARSLIDER( 1, "@MENU_VOICE_VOLUME", snd_menu_voice, 1.0, 0.0, 1.0, ; )
	CHOICE_DVARSLIDER( 2, "@MENU_MUSIC_VOLUME", snd_menu_music, 1.0, 0.0, 1.0, ; )
	CHOICE_DVARSLIDER( 3, "@MENU_SFX_VOLUME", snd_menu_sfx, 1.0, 0.0, 1.0, ; )
	CHOICE_DVARSLIDER( 4, "@MENU_CINEMATICS_VOLUME", snd_cinematicVolumeScale, 1.0, 0.0, 1.0, ; )
	CHOICE_DVARSLIDER( 5, "@MENU_MASTER_VOLUME", snd_menu_master, 1.0, 0.0, 1.0, ; )
	#ifdef PS3
	CHOICE_DVARSLIDER( 6, "@MENU_VOIP_VOLUME", ps3_voiceSpeakerGain, 1.2, 0.0, 5.0, ; );
	#endif //PS3

	#undef A_BUTTON_OFFSET_X
	#define A_BUTTON_OFFSET_X (0-4)

	#include "ui/safearea.menu"
}

// BRIGHTNESS MENU
menuDef 
{
	name			CONTROL_BRIGHTNESS_NAME
#ifdef	CONTROL_IN_GAME	
	rect			0 0 640 480
	focuscolor		COLOR_FOCUSED
	style			WINDOW_STYLE_EMPTY
	#ifndef PS3
	blurWorld		2.0
	#endif //#ifndef PS3
	legacySplitScreenScale
	onclose	
	{
		exec "updategamerprofile";
		setdvar cg_drawhud "1";
		setDvar ui_allow_controlschange "1";
		open OPTIONS_MENU_NAME;
	}
	execkeyint BUTTON_START
	{
		exec "updategamerprofile";
		close CONTROL_BRIGHTNESS_NAME;
	}
	onOpen
	{
		setdvar cg_drawhud "0";
		setDvar ui_allow_controlschange "0";
	}
	onEsc {	
		close CONTROL_BRIGHTNESS_NAME;
		exec "updategamerprofile";
		#ifndef CONTROL_IN_GAME_SPLITSCREEN
			#ifndef SINGLE_PLAYER
				open OPTIONS_MENU_NAME;
			#else
				open OPTIONS_MENU_NAME;
			#endif
		#endif
	}
	#ifndef PS3
	itemDef	
	{
		style			WINDOW_STYLE_FILLED
		rect			0 0 640 480 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN
		backcolor		BG_SHADE_COLOR
		visible			1
		decoration
	}
	#endif
	itemDef	
	{
		style			WINDOW_STYLE_SHADER
		rect			0 0 854 75 HORIZONTAL_ALIGN_FULLSCREEN 0
		background		"gradient_top"
		visible			1
		decoration
	}
	itemDef	
	{
		style			WINDOW_STYLE_SHADER
		rect			0 410 854 75 HORIZONTAL_ALIGN_FULLSCREEN 0
		background		"gradient_bottom"
		visible			1
		decoration
	}
#else 
	fullscreen		1
	rect			0 0 640 480
	focuscolor		COLOR_FOCUSED
	soundloop 		"music_mainmenu"
	style			WINDOW_STYLE_EMPTY
	legacySplitScreenScale
	onEsc {	
		execNow "updategamerprofile";
		close CONTROL_BRIGHTNESS_NAME;	
		#ifndef CONTROL_IN_GAME_SPLITSCREEN
			#ifndef SINGLE_PLAYER
				open OPTIONS_MENU_NAME;
			#endif
		#endif
	}
	#ifndef SINGLE_PLAYER
		#include "ui_mp/blurredbg.inc"
	#else
		#include "ui/bg.inc"
	#endif
#endif
	
	// ------------------ TREE TITLE ------------------
	#ifdef	CONTROL_IN_GAME_SPLITSCREEN
		CHOICE_MENU_TITLE_SS( "@MENU_BRIGHTNESS_CAP" )
	#else
		CHOICE_MENU_TITLE( "@MENU_BRIGHTNESS_CAP" )
	#endif
	// ------------------ buttons ---------------------
	#undef	LOCAL_NOT_IN_CAC
	#undef	LOCAL_IN_CAC
	#include "ui/navcontrols.inc"

	#define SETUP_BRIGHNESS_EXTRA \
		execKeyInt DPAD_LEFT { \
			execOnDvarFloatValue r_gamma 1.50 "set r_gamma 1.33"; \
			execOnDvarFloatValue r_gamma 1.33 "set r_gamma 1.21"; \
			execOnDvarFloatValue r_gamma 1.21 "set r_gamma 1.10"; \
			execOnDvarFloatValue r_gamma 1.10 "set r_gamma 1.00"; \
			execOnDvarFloatValue r_gamma 1.00 "set r_gamma 0.90"; \
			execOnDvarFloatValue r_gamma 0.90 "set r_gamma 0.82"; \
			execOnDvarFloatValue r_gamma 0.82 "set r_gamma 0.75"; \
			execOnDvarFloatValue r_gamma 0.75 "set r_gamma 0.68"; \
			execOnDvarFloatValue r_gamma 0.68 "set r_gamma 0.62"; \
			execOnDvarFloatValue r_gamma 0.62 "set r_gamma 0.56"; \
			execOnDvarFloatValue r_gamma 0.56 "set r_gamma 0.50"; \
		} \
		execKeyInt APAD_LEFT { \
			execOnDvarFloatValue r_gamma 1.50 "set r_gamma 1.33"; \
			execOnDvarFloatValue r_gamma 1.33 "set r_gamma 1.21"; \
			execOnDvarFloatValue r_gamma 1.21 "set r_gamma 1.10"; \
			execOnDvarFloatValue r_gamma 1.10 "set r_gamma 1.00"; \
			execOnDvarFloatValue r_gamma 1.00 "set r_gamma 0.90"; \
			execOnDvarFloatValue r_gamma 0.90 "set r_gamma 0.82"; \
			execOnDvarFloatValue r_gamma 0.82 "set r_gamma 0.75"; \
			execOnDvarFloatValue r_gamma 0.75 "set r_gamma 0.68"; \
			execOnDvarFloatValue r_gamma 0.68 "set r_gamma 0.62"; \
			execOnDvarFloatValue r_gamma 0.62 "set r_gamma 0.56"; \
			execOnDvarFloatValue r_gamma 0.56 "set r_gamma 0.50"; \
		} \
		execKeyInt DPAD_RIGHT { \
			execOnDvarFloatValue r_gamma 0.50 "set r_gamma 0.56"; \
			execOnDvarFloatValue r_gamma 0.56 "set r_gamma 0.62"; \
			execOnDvarFloatValue r_gamma 0.62 "set r_gamma 0.68"; \
			execOnDvarFloatValue r_gamma 0.68 "set r_gamma 0.75"; \
			execOnDvarFloatValue r_gamma 0.75 "set r_gamma 0.82"; \
			execOnDvarFloatValue r_gamma 0.82 "set r_gamma 0.90"; \
			execOnDvarFloatValue r_gamma 0.90 "set r_gamma 1.00"; \
			execOnDvarFloatValue r_gamma 1.00 "set r_gamma 1.10"; \
			execOnDvarFloatValue r_gamma 1.10 "set r_gamma 1.21"; \
			execOnDvarFloatValue r_gamma 1.21 "set r_gamma 1.33"; \
			execOnDvarFloatValue r_gamma 1.33 "set r_gamma 1.50"; \
		} \
		execKeyInt APAD_RIGHT { \
			execOnDvarFloatValue r_gamma 0.50 "set r_gamma 0.56"; \
			execOnDvarFloatValue r_gamma 0.56 "set r_gamma 0.62"; \
			execOnDvarFloatValue r_gamma 0.62 "set r_gamma 0.68"; \
			execOnDvarFloatValue r_gamma 0.68 "set r_gamma 0.75"; \
			execOnDvarFloatValue r_gamma 0.75 "set r_gamma 0.82"; \
			execOnDvarFloatValue r_gamma 0.82 "set r_gamma 0.90"; \
			execOnDvarFloatValue r_gamma 0.90 "set r_gamma 1.00"; \
			execOnDvarFloatValue r_gamma 1.00 "set r_gamma 1.10"; \
			execOnDvarFloatValue r_gamma 1.10 "set r_gamma 1.21"; \
			execOnDvarFloatValue r_gamma 1.21 "set r_gamma 1.33"; \
			execOnDvarFloatValue r_gamma 1.33 "set r_gamma 1.50"; \
		}

	#define CHOICE_BG_BOX( itemIndex, blackLevel, visArg ) \
		itemDef \
		{ \
			style			WINDOW_STYLE_SHADER \
			rect			CHOICE_ORIGIN( itemIndex ) (CHOICE_SIZE_X-(CHOICE_SIZE_Y/4)) CHOICE_SIZE_Y CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			exp				material( "white" ); \
			forecolor		blackLevel blackLevel blackLevel 1 \
			visible			visArg \
			decoration \
		}

	#undef A_BUTTON_OFFSET_X
	#define A_BUTTON_OFFSET_X 100000
	
	CHOICE_DVARSLIDER_VIS_EX( 1, "@MENU_BRIGHTNESS", r_gamma, 1, 0.5, 1.50, ;, SETUP_BRIGHNESS_EXTRA, 1 )

	#undef CHOICE_TEXTSIZE
	#define CHOICE_TEXTSIZE			TEXTSIZE_SMALL

	#undef CHOICE_HORIZONTAL_ALIGN
	#define CHOICE_HORIZONTAL_ALIGN HORIZONTAL_ALIGN_CENTER

	#undef CHOICE_TEXTALIGN
	#define	CHOICE_TEXTALIGN		ITEM_ALIGN_MIDDLE_LEFT

	#undef CHOICE_X_START
	#define CHOICE_X_START			(0-(CHOICE_SIZE_X/2))

	CHOICE_CAPTION_COLOR_VIS( 3, "@MENU_BRIGHTNESS_DESC1", CHOICE_TEXTCOLOR, 1 );
#ifndef PS3
	CHOICE_CAPTION_COLOR_VIS( 4, "@MENU_BRIGHTNESS_DESC2", CHOICE_TEXTCOLOR, 1 );

	#undef CHOICE_HORIZONTAL_ALIGN
	#define CHOICE_HORIZONTAL_ALIGN HORIZONTAL_ALIGN_CENTER

	#undef CHOICE_TEXTALIGN
	#define	CHOICE_TEXTALIGN		ITEM_ALIGN_MIDDLE_CENTER

	#undef CHOICE_TEXTSIZE
	#define CHOICE_TEXTSIZE			TEXTSIZE_DEFAULT

	#undef CHOICE_SIZE_X
	#define CHOICE_SIZE_X			300

	#undef CHOICE_X_START
	#define CHOICE_X_START			(0-(CHOICE_SIZE_X/2))

	#undef CHOICE_SIZE_Y
	#define CHOICE_SIZE_Y			60

	#undef CHOICE_Y_SPACING
	#define CHOICE_Y_SPACING		60

	#undef CHOICE_TEXT_OFFSET_X
	#define CHOICE_TEXT_OFFSET_X	0

	#undef CHOICE_TEXTSTYLE
	#define CHOICE_TEXTSTYLE		0

	CHOICE_BG_BOX( 3, 0.062, 1 );
	CHOICE_BG_BOX( 4, 0.125, 1 );
	CHOICE_BG_BOX( 5, 0.250, 1 );

	CHOICE_CAPTION_COLOR_VIS( 3, "@MENU_BRIGHTNESS_NOT_VISIBLE", 0 0 0 1, 1 );
	CHOICE_CAPTION_COLOR_VIS( 4, "@MENU_BRIGHTNESS_BARELY_VISIBLE", 0 0 0 1, 1 );
	CHOICE_CAPTION_COLOR_VIS( 5, "@MENU_BRIGHTNESS_EASILY_VISIBLE", 0 0 0 1, 1 );
#endif
	#include "ui/safearea.menu"
}

	#include "ui_mp/popupstyle.inc"
	#include "ui/choices_setup_popmenu.menu"
	
	#undef CHOICE_SIZE_X
	#define CHOICE_SIZE_X				180

	#undef CHOICE_SIZE_Y
	#define CHOICE_SIZE_Y				22

	#undef CHOICE_TEXTALIGN
	#define	CHOICE_TEXTALIGN			ITEM_ALIGN_MIDDLE_LEFT

	#undef CHOICE_Y_SPACING
	#define CHOICE_Y_SPACING			(CHOICE_SIZE_Y+2)

	#undef CHOICE_TEXT_OFFSET_X
	#define CHOICE_TEXT_OFFSET_X		22

#ifdef PC
	#undef CHOICE_Y_START
	#define CHOICE_Y_START			235
#else
	#undef CHOICE_Y_START
	#define CHOICE_Y_START			200
#endif //#ifdef PC

	#define OPEN_MATURE_DISABLE \
		setfocus "no"; \
		execondvarstringvalue cg_mature 0 "set cg_mature 1; set cg_blood 1; closemenu mature_content_disable_warning"; \

	menuDef
	{
		CENTER_POPUP_SETUP_ONOPEN( mature_content_disable_warning, 4, ;, OPEN_MATURE_DISABLE, 1 )
		CHOICE_POPMENU_TITLE( "@MENU_WARNING_CAP" )

		CHOICE_POPMENU_SUBTITLE( "@MENU_WARNING_DISABLE_MATURE_CONTENT" )

		CHOICE_BUTTON( 1, "@MENU_YES", close self; exec "set cg_blood 0"; exec "set cg_mature 0"; )
		CHOICE_BUTTON_EX( 2, "@MENU_NO", close self;, name "no" )
	}



