// general definitions

#ifdef CONSOLE
	#define CHOICE_X_START			0//22
	#define CHOICE_Y_START			65//85//58//34
	
	#undef ORIGIN_TITLE
	#define ORIGIN_TITLE			0 0
#else
	#define CHOICE_X_START			30//22
	#define CHOICE_Y_START			65//85//58//34
#endif



#include "ui_mp/menustyle.inc"
//#undef CHOICE_SIZE_X
//#define CHOICE_SIZE_X			216

#include "ui/choices_setup_common.menu"
 
#define ORIGIN_STATUS			390 64
#define MENU_FONT_COLOR2		1 1 1 0.5

#undef NEW_X_OFFSET			
#define NEW_X_OFFSET			(-CHOICE_SIZE_Y)

#include "ui_mp/stats_info.inc"
#include "ui_mp/overlaybg.inc"


	menuDef	{
		name			CAC_MENU_NAME
		//fullscreen		1
		rect			0 0 640 480 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN
		focuscolor		COLOR_FOCUSED
		style			WINDOW_STYLE_EMPTY //style			WINDOW_STYLE_FILLED
		soundloop 		"music_mainmenu"
		//popup
		onOpen {			
			// load perk 2's selection into ui_perk2_selection so we can check if dual primaries perk is selected
			statGetInDvarUsingTable( CAC_SPECIALTY_WEAPON, ui_perk2_selection );
			// Set weapon dvars to enable check for Overkill
			setDvarStringUsingTable( ui_primary_weapon, tableLookup( "mp/statstable.csv", 0, STAT_CAC_PRIMARY, 1 ) );
			setDvarStringUsingTable( ui_secondary_weapon, tableLookup( "mp/statstable.csv", 0, STAT_CAC_SECONDARY, 1 ) ); 
			
			execnow "set ui_dual_primaries false";
			execOnDvarIntValue ui_perk2_selection 158 "set ui_dual_primaries true";
			
			// open auto rename popup
			/*
			statGetInDvarUsingTable( CAC_CLASS, ui_cac_autorename );
			execNowOnDvarIntValue ui_cac_autorename 1 "ui_keyboard MENU_CUSTOMCLASS_KEYBOARD "CAC_CUSTOM_NAME;
			statSetUsingTable( CAC_CLASS, 0 );
			*/
					
			// set focus to first menu selection	
			setfocus primary_weapon_selection;		
		}
		onEsc {
#ifdef PC
			execnow "uploadstats";
#endif
			close CAC_MENU_NAME;
			open cac_main;
		}
		onFocus { setdvar ui_show_reset "1" }

		// background from overlaybg.inc
#ifdef PC
		BACKGROUND_BLACK_LETTERBOX_BLURWORLD_VIS( 1.0, 0 )
#endif
		OVERLAY_BACKGROUND

		#include "ui_mp/cac_loadout.inc"
		CAC_LOADOUT_CAC_TITLE1
		CAC_LOADOUT_NORMAL
		CAC_LOADOUT_ATTRIBUTES
		CAC_LOADOUT_ATTRIBUTES_PREVIEW

		#undef BACK_OPEN
		#define BACK_OPEN 	close CAC_MENU_NAME; open cac_main;
		#include "ui_mp/navcontrols.inc"

		#include "ui/safearea.menu"
		//=========================================================
		//===================== MENU SELECTION ====================
		//=========================================================
		
		// PRIMARY WEAPON BUTTON =============================================================
		#define CAC_SETUP_ACTION1 \
			execnow "set ui_primary_selected Primary Weapon"; \
			exec "set ui_menu_selection_title @MPUI_PRIMARY_WEAPON1"; \
			play "mouse_click"; \
			open "popup_cac_primary"; \
		
		CHOICE_BUTTON_EX( 1, "@MPUI_PRIMARY_WEAPON1", CAC_SETUP_ACTION1, name primary_weapon_selection )
		CHOICE_NEWICON_VIS( 1, "specialty_new", when( statRangeAnyBitsSet( 3010, 3089, WEAPON_NEW_BITMASK ) ); )

		// SECONDARY WEAPON/SIDE ARM BUTTON =============================================================
		#define CAC_SETUP_ACTION2 \
			exec "set ui_menu_selection_title @MPUI_SIDE_ARM1"; \
			play "mouse_click"; \
			open "popup_cac_secondary";

		#define CAC_SETUP_ACTION2_2 \
			execnow "set ui_primary_selected Secondary Weapon"; \
			exec "set ui_menu_selection_title @MPUI_SECONDARY_WEAPON"; \
			play "mouse_click"; \
			open "popup_cac_primary_2";
					
		CHOICE_BUTTON_BG( 2, 1 )
		CHOICE_HIGHLIGHT( 2, 1 )
		CHOICE_BUTTON_VIS_NOHI( 2, "@MPUI_SIDE_ARM1", CAC_SETUP_ACTION2, when( "specialty_twoprimaries" != tablelookup( "mp/statstable.csv", 1, stat(CAC_SPECIALTY_WEAPON) , 4 ) ); )
		CHOICE_NEWICON_VIS( 2, "specialty_new", when( statRangeAnyBitsSet( 3000, 3009, WEAPON_NEW_BITMASK ) && "specialty_twoprimaries" != tablelookup( "mp/statstable.csv", 1, stat(CAC_SPECIALTY_WEAPON) , 4  ) ); )
		CHOICE_BUTTON_VIS_NOHI( 2, "@MPUI_SECONDARY_WEAPON", CAC_SETUP_ACTION2_2, when( "specialty_twoprimaries" == tablelookup( "mp/statstable.csv", 1, stat(CAC_SPECIALTY_WEAPON) , 4  ) ); )
	
		// PRIMARY GRENADE BUTTON =============================================================
		#define CAC_SETUP_ACTION3 \
			exec "set ui_menu_selection_title @MPUI_PRIMARY_GRENADE"; \
			play "mouse_click"; \
			open "popup_cac_pgrenade";
			
		CHOICE_BUTTON( 3, "@MPUI_PRIMARY_GRENADE", CAC_SETUP_ACTION3 )
		CHOICE_NEWICON_VIS( 3, "specialty_new", when( ANY_NEW_PGRENADE ); )

		// SPECIAL GRENADE BUTTON =============================================================
		#define CAC_SETUP_ACTION4 \
			exec "set ui_menu_selection_title @MPUI_SPECIAL_GRENADE"; \
			play "mouse_click"; \
			open "popup_cac_sgrenade";
			
		CHOICE_BUTTON( 4, "@MPUI_SPECIAL_GRENADE", CAC_SETUP_ACTION4 )
		// PERK 1 BUTTON =============================================================
		// perk 1 empty warning
		CHOICE_BUTTON_BG_RAW( 5, "gradient_fadein", 0.5 0.15 0 0.5, when(stat(CAC_SPECIALTY_EQUIPMENT) == 190); )
		
		#define CAC_SETUP_ACTION5 \
			exec "set ui_menu_selection_title @MPUI_PERK_1"; \
			play "mouse_click"; \
			open "popup_cac_perk1";	
		
		#define LOCAL_VIS5_WHEN \
			( "gl" == CAC_PRI_ATTACHMENT_SLOT ) || \
			( "gl" == CAC_SEC_ATTACHMENT_SLOT ) || \
			( "grip" == CAC_PRI_ATTACHMENT_SLOT ) || \
			( "grip" == CAC_SEC_ATTACHMENT_SLOT )

		#define LOCAL_VIS5_WHEN_NOT \
			( "gl" != CAC_PRI_ATTACHMENT_SLOT ) && \
			( "gl" != CAC_SEC_ATTACHMENT_SLOT ) && \
			( "grip" != CAC_PRI_ATTACHMENT_SLOT ) && \
			( "grip" != CAC_SEC_ATTACHMENT_SLOT )

		CHOICE_BUTTON_BG( 5, 1 )
		CHOICE_HIGHLIGHT( 5, 1 )
		CHOICE_BUTTON_VIS_NOHI( 5, "@MPUI_PERK_1", CAC_SETUP_ACTION5, when( LOCAL_VIS5_WHEN_NOT ) )
		CHOICE_BUTTON_VIS_NOHI( 5, "", ;, when( LOCAL_VIS5_WHEN ) )
		CHOICE_DBUTTON_VIS( 5, "@MPUI_PERK_1", when( LOCAL_VIS5_WHEN ) )
		CHOICE_NEWICON_VIS( 5, "specialty_new", when( ANY_NEW_PERK1 ) )

		// PERK 2 BUTTON =============================================================
		#define CAC_SETUP_ACTION6 \		
			exec "set ui_menu_selection_title @MPUI_PERK_2"; \
			play "mouse_click"; \
			open "popup_cac_perk2";		

		CHOICE_BUTTON( 6, "@MPUI_PERK_2", CAC_SETUP_ACTION6 )
		CHOICE_NEWICON_VIS( 6, "specialty_new", when( ANY_NEW_PERK2 ) )
		
		// PERK 3 BUTTON =============================================================
		#define CAC_SETUP_ACTION7 \		
			exec "set ui_menu_selection_title @MPUI_PERK_3"; \
			play "mouse_click"; \
			open "popup_cac_perk3";		

		CHOICE_BUTTON( 7, "@MPUI_PERK_3", CAC_SETUP_ACTION7 )
		CHOICE_NEWICON_VIS( 7, "specialty_new", when( ANY_NEW_PERK3 ) )

		// PERK 4 (VEHICLE) BUTTON ===================================================
		#define CAC_SETUP_ACTION8 \		
			exec "set ui_menu_selection_title @MPUI_VEHICLE_PERK"; \
			play "mouse_click"; \
			open "popup_cac_perk4";		

		CHOICE_BUTTON( 8, "@MPUI_VEHICLE_PERK", CAC_SETUP_ACTION8 )
		CHOICE_NEWICON_VIS( 8, "specialty_new", when( ANY_NEW_PERK4 ) )

		// RENAME BUTTON =============================================================
#ifndef PC		
		itemDef
		{
			rect			90 -4 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_BOTTOM
			origin			0 0
			text			"@PLATFORM_RENAME"
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textalign		ITEM_ALIGN_BOTTOM_LEFT
			execkeyint		BUTTON_X {CAC_SETUP_ACTION_RENAME}
			visible			1
			decoration
		}		
#else
		itemDef
		{
			text			"@PLATFORM_RENAME"
			type			1
			style			WINDOW_STYLE_FILLED
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			rect			-150 -26 50 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
			textalign		ITEM_ALIGN_LEFT
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textaligny		18
			visible			when( dvarBool( ui_show_reset ) )
			mouseEnter		{ play "mouse_over"; }
			action			{ play "mouse_click"; CAC_SETUP_ACTION_RENAME }
		}
#endif	// #ifndef PC

		// RESET BUTTON ==============================================================	
#ifndef PC	
		itemDef
		{
			rect			0 -4 0 0 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
			origin			0 0
			text			"@PLATFORM_RESET_TO_DEFAULT"
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textalign		ITEM_ALIGN_BOTTOM_LEFT
			execkeyint		BUTTON_BACK {CAC_SETUP_ACTION_RESET}
			visible			when( dvarBool( ui_show_reset ) )
			decoration
		}
#else
		itemDef
		{
			text			"@PLATFORM_RESET_TO_DEFAULT"
			rect			-50 -26 100 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
			style			WINDOW_STYLE_FILLED
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textalign		ITEM_ALIGN_LEFT
			textaligny		18
			mouseEnter		{ play "mouse_over"; }
			action			{ CAC_SETUP_ACTION_RESET }
			visible			when( dvarBool( ui_show_reset ) )
		}
#endif	// #ifndef PC
	}

	// close all 2nd and 3rd layer popups on end action
	#define PREPROC_ATTACH_CLOSEALL \
	close "popup_cac_primary"; \
	close "popup_cac_primary_2"; \
	close "popup_cac_secondary"; \
	close "popup_cac_assault"; \
	close "popup_cac_SMG"; \
	close "popup_cac_LMG"; \
	close "popup_cac_HMG"; \
	close "popup_cac_sniper"; \
	close "popup_cac_shotgun"; \
	close "popup_cac_assault_2"; \
	close "popup_cac_SMG_2"; \
	close "popup_cac_LMG_2"; \
	close "popup_cac_HMG_2"; \
	close "popup_cac_sniper_2"; \
	close "popup_cac_shotgun_2"; \
	close "attachment_popup_rifle"; \
	close "attachment_popup_rifle2"; \
	close "attachment_popup_assault1"; \
	close "attachment_popup_assault2"; \
	close "attachment_popup_assault3"; \
	close "attachment_popup_assault4"; \
	close "attachment_popup_SMG1"; \
	close "attachment_popup_SMG2"; \
	close "attachment_popup_LMG1"; \
	close "attachment_popup_LMG2"; \
	close "attachment_popup_LMG3"; \
	close "attachment_popup_LMG4"; \
	close "attachment_popup_shotgun1"; \
	close "attachment_popup_shotgun2"; \
	close "attachment_popup_fake"; \
	close "attachment_popup_fake_2"; \
	close "popup_cac_template"; \
	close "attachment_popup_rifle_2"; \
	close "attachment_popup_rifle_2_2"; \
	close "attachment_popup_assault1_2"; \
	close "attachment_popup_assault2_2"; \
	close "attachment_popup_assault3_2"; \
	close "attachment_popup_assault4_2"; \	
	close "attachment_popup_SMG1_2"; \
	close "attachment_popup_SMG2_2"; \
	close "attachment_popup_LMG1_2"; \
	close "attachment_popup_LMG2_2"; \
	close "attachment_popup_LMG3_2"; \
	close "attachment_popup_LMG4_2"; \
	close "attachment_popup_shotgun1_2"; \
	close "attachment_popup_shotgun2_2"; \
	close "popup_cac_camo"; \
	close "popup_cac_camo_2";
	
	
	// including weapon data
	#include "ui_mp/weaponinfo.menu"
	
	// ========================== Perk 1 special cases ===========================
	
	#define PERK1_RESET1 \
		statSetOnDvarStringValue( ui_perk1_slot, 193, CAC_SPECIALTY_EQUIPMENT, 190 ); \
		statSetOnDvarStringValue( ui_perk1_slot, 192, CAC_SPECIALTY_EQUIPMENT, 190 ); \
		statSetOnDvarStringValue( ui_perk1_slot, 191, CAC_SPECIALTY_EQUIPMENT, 190 ); 


	#define PERK1_RESET \
		statGetInDvarUsingTable( CAC_SPECIALTY_EQUIPMENT, ui_perk1_slot ); \
	    PERK1_RESET1 \
		statSetOnDvarStringValue( ui_secondary_attachment_slot, "gl", CAC_SPECIALTY_EQUIPMENT, 193 ); \
		statSetOnDvarStringValue( ui_secondary_attachment_slot, "grip", CAC_SPECIALTY_EQUIPMENT, 193 ); \
		statSetOnDvarStringValue( ui_primary_attachment_slot, "gl", CAC_SPECIALTY_EQUIPMENT, 193 ); \
		statSetOnDvarStringValue( ui_primary_attachment_slot, "grip", CAC_SPECIALTY_EQUIPMENT, 193 );

// ===========================================================================================================================
// ===========================================================================================================================
// ===========================================================================================================================

#ifdef CONSOLE
	#undef CHOICE_X_START
	#define CHOICE_X_START			0
	#undef CHOICE_Y_START
	#define CHOICE_Y_START			90

	#undef ORIGIN_TITLE
	#define ORIGIN_TITLE			0 0
#else
	#undef CHOICE_X_START
	#define CHOICE_X_START			30
	#undef CHOICE_Y_START
	#define CHOICE_Y_START			90
#endif


	#define LOCAL_WEAPON_CLASS_INFO_WINDOW \
		/* weapon class title*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_TITLE_X LOADOUT_TITLE_Y (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, dvarString( ui_weapon_class ), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW ) \
		/* weapon class description */\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, dvarString( ui_weapon_class )+"_DESC", TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )\

	#define LOCAL_WEAPON_CLASS( suffix, itemNum, ptext, plabel, pVis ) \
		CHOICE_BUTTON_FOCUS_VIS_EX( itemNum, plabel, play "mouse_click"; execnow "set selected_weapon_class "ptext"; set ui_weapon_class_selected "plabel; open "popup_cac_"ptext""suffix;, exec "set ui_weapon_class "plabel, ;, 1, name ptext ) \
		CHOICE_NEWICON_VIS( itemNum, "specialty_new", when( pVis ) )		

	#define LOCAL_MASTER_PRIMARY_WEAPON_GROUP( suffix, pos, y_offset )\
	menuDef	{\
		CAC_POPUP_SWAP( "popup_cac_primary"suffix, execnow "set ui_inside_popup weapon_class; set ui_show_preview 1; set ui_weapon_class @MPUI_BOLT_ACTION_RIFLES", execnow "set ui_show_preview 0; set ui_primary_highlighted 0; set ui_attachment_highlighted 0"; )\
		LOCAL_WEAPON_CLASS_INFO_WINDOW \
		LOCAL_WEAPON_CLASS( suffix, 1, "sniper", "@MPUI_BOLT_ACTION_RIFLES", statRangeAnyBitsSet( 3060, 3069, WEAPON_NEW_BITMASK ) ) \
		LOCAL_WEAPON_CLASS( suffix, 2, "assault", "@MPUI_RIFLES", statRangeAnyBitsSet( 3020, 3026, WEAPON_NEW_BITMASK ) ) \
		LOCAL_WEAPON_CLASS( suffix, 3, "SMG", "@MPUI_SUB_MACHINE_GUNS", statRangeAnyBitsSet( 3010, 3019, WEAPON_NEW_BITMASK ) ) \
		LOCAL_WEAPON_CLASS( suffix, 4, "shotgun", "@MPUI_SHOTGUNS", statRangeAnyBitsSet( 3070, 3079, WEAPON_NEW_BITMASK ) ) \
		LOCAL_WEAPON_CLASS( suffix, 5, "LMG", "@MPUI_LIGHT_MACHINE_GUNS", ( statRangeAnyBitsSet( 3040, 3042, WEAPON_NEW_BITMASK ) || statRangeAnyBitsSet( 3080, 3089, WEAPON_NEW_BITMASK ) ) ) \
	}
	
	LOCAL_MASTER_PRIMARY_WEAPON_GROUP( "", 1, 0 )
	LOCAL_MASTER_PRIMARY_WEAPON_GROUP( "_2", 2, 4 )


// ====================================================================================================
// primary weapon selection ===========================================================================
// ====================================================================================================
	#define LOCAL_WEAPON_INFO_WINDOW( highlight_dvar ) \
		/* weapon image*/ \
		PREPROC_SHADER_DRAW_ALIGNED( (LOADOUT_IMAGE_X-45) LOADOUT_IMAGE_Y 180 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),6), 1 1 1 1, 0, 2, 0 0 0 0 visible when( dvarString(ui_inside_popup) != "attachment" && dvarString(ui_inside_popup) != "camo" ); ) \
		/* weapon title*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_TITLE_X LOADOUT_TITLE_Y (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",4,dvarString(highlight_dvar),3), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW visible when( dvarString(ui_inside_popup) != "attachment" && dvarString(ui_inside_popup) != "camo" ); ) \
		/* weapon desc unlocked*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",4,dvarString(highlight_dvar),7), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR visible when( ( stat(int(tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),1))) & 1 ) && ( ( dvarString( ui_primary_selected ) != "Primary Weapon" || dvarString( ui_primary_highlighted ) != tablelookup("mp/statsTable.csv",1,dvarInt(ui_secondary_weapon), 4 ) ) && ( dvarString( ui_primary_selected ) != "Secondary Weapon" || dvarString( ui_primary_highlighted ) != tablelookup("mp/statsTable.csv",1,dvarInt(ui_primary_weapon), 4 ) ) ) ); )\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",4,dvarString(highlight_dvar),10), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_RED_TEXT visible when( ( stat(int(tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),1))) & 1 ) == 0 ); )\
		/* Weapon already selected description */ \
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@MPUI_ALREADY_SELECTED", TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR visible when( ( stat(int(tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),1))) & 1 ) && ( ( dvarString( ui_primary_selected ) == "Primary Weapon" && dvarString( ui_primary_highlighted ) == tablelookup("mp/statsTable.csv",1,dvarInt(ui_secondary_weapon), 4 ) ) || ( dvarString( ui_primary_selected ) == "Secondary Weapon" && dvarString( ui_primary_highlighted ) == tablelookup("mp/statsTable.csv",1,dvarInt(ui_primary_weapon), 4 ) ) ) ); ) \
		/* attributes info display =============== */\
		CAC_LOADOUT_ATTRIBUTES \
		CAC_LOADOUT_ATTRIBUTES_PREVIEW_NA
		
	#define LOCAL_PRIMARY_WEAPON_ACTION( suffix, pstat, weapRef, attachRef ) \
		statSetUsingTable( CAC_PRIMARY_ATTACHMENT, 0 ); \
		statSetUsingTable( CAC_CAMO, 0 ); \
		play "mouse_click"; \
		statSetUsingTable( CAC_PRIMARY, pstat ); \
		statSetUsingTable( CAC_PRIMARY_STORAGE, tableLookup( "mp/statstable.csv", 4, weapRef, 1 ) ); \
		statGetInDvarUsingTable(CAC_PRIMARY_STORAGE, ui_primary_weapon ); \
		CLEAR_NEW( ui_primary_weapon, WEAPON_NEW_BITMASK ); \
		statGetInDvarUsingTable( CAC_SPECIALTY_EQUIPMENT, ui_perk1_slot ); \
		PERK1_RESET1; \
		setDvarStringUsingTable( ui_secondary_attachment_slot, CAC_SEC_ATTACHMENT_SLOT ); \
		statSetOnDvarStringValue( ui_secondary_attachment_slot, "gl", CAC_SPECIALTY_EQUIPMENT, 193 ); \
		statSetOnDvarStringValue( ui_secondary_attachment_slot, "grip", CAC_SPECIALTY_EQUIPMENT, 193 ); \
		setdvar ui_popup_menu_name "attachment_popup_"attachRef""; \
		open "attachment_popup_"attachRef"";

	#define LOCAL_PRIMARY_WEAPON_ACTION2( suffix, pstat, weapRef, attachRef ) \		
		statSetUsingTable( CAC_SECONDARY_ATTACHMENT, 0 ); \
		play "mouse_click"; \
		statSetUsingTable( CAC_SECONDARY, pstat ); \
		statSetUsingTable( CAC_SECONDARY_STORAGE, tableLookup( "mp/statstable.csv", 4, weapRef, 1 ) ); \
		statGetInDvarUsingTable( CAC_SECONDARY_STORAGE, ui_secondary_weapon ); \
		CLEAR_NEW( ui_secondary_weapon, WEAPON_NEW_BITMASK ); \
		statGetInDvarUsingTable( CAC_SPECIALTY_EQUIPMENT, ui_perk1_slot ); \
		setDvarStringUsingTable( ui_primary_attachment_slot, CAC_PRI_ATTACHMENT_SLOT ); \
		statSetOnDvarStringValue( ui_primary_attachment_slot, "gl", CAC_SPECIALTY_EQUIPMENT, 193 ); \
		statSetOnDvarStringValue( ui_primary_attachment_slot, "grip", CAC_SPECIALTY_EQUIPMENT, 193 ); \
		open "attachment_popup_"attachRef""suffix;

	// hacked to hide the second primary if same weapon is selected in first primary
	#define LOCAL_WEAPON_ITEM( suffix, itemNum, weaponName, weaponStat, weaponRef, highlight_dvar, attachRef, rawStat )\
		CHOICE_DBUTTON_VIS( itemNum, weaponName, when( 1 ); ) \
		CHOICE_HIGHLIGHT( itemNum, 1 ) \
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, "", ;, execnow "set "highlight_dvar" "weaponRef"", ;, when( ( stat( int(weaponStat)+3000 ) & 1 ) == 0 ); ) \
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, "", ;, execnow "set "highlight_dvar" "weaponRef"", ;, when( ( stat( int(weaponStat)+3000 ) & 1 ) == 1 && dvarString( ui_primary_selected ) == "Primary Weapon" && dvarInt( ui_secondary_weapon ) == ( int( weaponStat ) + 3000 ) ); ) \
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, "", ;, execnow "set "highlight_dvar" "weaponRef"", ;, when( ( stat( int(weaponStat)+3000 ) & 1 ) == 1 && dvarString( ui_primary_selected ) == "Secondary Weapon" && dvarInt( ui_primary_weapon ) == ( int( weaponStat ) + 3000 ) ); ) \
		\
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, \
			weaponName, \
			LOCAL_PRIMARY_WEAPON_ACTION( suffix, weaponStat, weaponRef, attachRef ), \
			execnow "set "highlight_dvar" "weaponRef;, \
			CLEAR_WEAP_NEW( weaponRef );, \
			when( ( stat( int(weaponStat)+3000 ) & 1 ) && dvarString( ui_primary_selected ) == "Primary Weapon" && int(weaponStat) != stat(CAC_SECONDARY) ); ) \
		\
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, \
			weaponName, \
			LOCAL_PRIMARY_WEAPON_ACTION2( suffix, weaponStat, weaponRef, attachRef ), \
			execnow "set "highlight_dvar" "weaponRef;, \
			CLEAR_WEAP_NEW( weaponRef );, \
			when( ( stat( int(weaponStat)+3000 ) & 1 ) && dvarString( ui_primary_selected ) == "Secondary Weapon" && int(weaponStat) != stat(CAC_PRIMARY) ); ) \
		\
		CHOICE_NEWICON_VIS( itemNum, "specialty_new", when( ( stat( int(weaponStat)+3000 ) & (NEW_WEAPON_BITMASK+NEW_ITEMS_MASK)) > 0 ) ) \
		CHOICE_LOCKEDICON_VIS( itemNum, "specialty_locked", when( ( stat( int(weaponStat)+3000 ) & 1 ) == 0 ); ) 		
				
	// hackaround to work for PC's floating mouse unfocusing
	#undef  UI_FOCUSFIRST
	#ifdef PC
		#define UI_FOCUSFIRST "ui_primary_highlighted"
	#else
		#define UI_FOCUSFIRST "ui_fake_focus"
	#endif

	#define LOCAL_MASTER_WEAPON_GROUP( suffix, pos, y_offset )\
	menuDef	{\
		CAC_POPUP_SWAP( "popup_cac_assault"suffix, execnow "set "UI_FOCUSFIRST" "REF_GEWEHR43"; set ui_inside_popup assault", ; )\
		LOCAL_WEAPON_INFO_WINDOW( "ui_primary_highlighted" )\
		LOCAL_WEAPON_ITEM( suffix, 1, "@WEAPON_SVT40", STAT_ASSAULT_SVT40, REF_SVT40, "ui_primary_highlighted", "assault1", 3024 )\
		LOCAL_WEAPON_ITEM( suffix, 2, "@WEAPON_GEWEHR43", STAT_ASSAULT_GEWEHR43, REF_GEWEHR43, "ui_primary_highlighted", "assault2", 3023 )\
		LOCAL_WEAPON_ITEM( suffix, 3, "@WEAPON_M1GARAND", STAT_ASSAULT_M1GARAND, REF_M1GARAND, "ui_primary_highlighted", "assault3", 3020 )\
		LOCAL_WEAPON_ITEM( suffix, 4, "@WEAPON_STG-44", STAT_ASSAULT_STG44, REF_STG44, "ui_primary_highlighted", "assault1", 3021 )\
		LOCAL_WEAPON_ITEM( suffix, 5, "@WEAPON_M1A1CARBINE", STAT_ASSAULT_M1A1CARBINE, REF_M1A1CARBINE, "ui_primary_highlighted", "assault4", 3022 )\
	}\
	menuDef	{\
		CAC_POPUP_SWAP( "popup_cac_LMG"suffix, execnow "set "UI_FOCUSFIRST" "REF_FG42"; set ui_inside_popup lmg", ; )\
		LOCAL_WEAPON_INFO_WINDOW( "ui_primary_highlighted" )\
		LOCAL_WEAPON_ITEM( suffix, 1, "@WEAPON_TYPE99_LMG", STAT_LMG_TYPE99_LMG, REF_TYPE99_LMG, "ui_primary_highlighted", "LMG3", 3080 )\
		LOCAL_WEAPON_ITEM( suffix, 2, "@WEAPON_BAR", STAT_LMG_BAR, REF_BAR, "ui_primary_highlighted", "LMG1", 3082 )\
		LOCAL_WEAPON_ITEM( suffix, 3, "@WEAPON_DP28", STAT_LMG_DP28, REF_DP28, "ui_primary_highlighted", "LMG1", 3083 )\
		LOCAL_WEAPON_ITEM( suffix, 4, "@WEAPON_MG42", STAT_LMG_MG42, REF_MG42, "ui_primary_highlighted", "LMG4", 3041 )\
		LOCAL_WEAPON_ITEM( suffix, 5, "@WEAPON_FG42", STAT_LMG_FG42, REF_FG42, "ui_primary_highlighted", "LMG2", 3081 )\
		LOCAL_WEAPON_ITEM( suffix, 6, "@WEAPON_30CAL", STAT_LMG_30CAL, REF_30CAL, "ui_primary_highlighted", "LMG4", 3040 )\
	}\
	menuDef	{\
		CAC_POPUP_SWAP( "popup_cac_SMG"suffix, execnow "set "UI_FOCUSFIRST" "REF_TYPE100_SMG";set ui_inside_popup smg", ; )\
		LOCAL_WEAPON_INFO_WINDOW( "ui_primary_highlighted" )\
		LOCAL_WEAPON_ITEM( suffix, 1, "@WEAPON_THOMPSON", STAT_SMG_THOMPSON, REF_THOMPSON, "ui_primary_highlighted", "SMG1", 3010 )\
		LOCAL_WEAPON_ITEM( suffix, 2, "@WEAPON_MP40", STAT_SMG_MP40, REF_MP40, "ui_primary_highlighted", "SMG1", 3011 )\
		LOCAL_WEAPON_ITEM( suffix, 3, "@WEAPON_TYPE100_SMG", STAT_SMG_TYPE100_SMG, REF_TYPE100_SMG, "ui_primary_highlighted", "SMG1", 3012 )\
		LOCAL_WEAPON_ITEM( suffix, 4, "@WEAPON_PPSH", STAT_SMG_PPSH, REF_PPSH, "ui_primary_highlighted", "SMG2", 3013 )\
	}\
	menuDef	{\
		CAC_POPUP_SWAP( "popup_cac_shotgun"suffix, execnow "set "UI_FOCUSFIRST" "REF_SHOTGUN"; set ui_inside_popup shotgun", ; )\
		LOCAL_WEAPON_INFO_WINDOW( "ui_primary_highlighted" )\
		LOCAL_WEAPON_ITEM( suffix, 1, "@WEAPON_SHOTGUN", STAT_SHOTGUN_SHOTGUN, REF_SHOTGUN, "ui_primary_highlighted", "shotgun1", 3070 )\
		LOCAL_WEAPON_ITEM( suffix, 2, "@WEAPON_SHOTGUN_DOUBLE_BARRELED", STAT_DOUBLE_BARRELED_SHOTGUN, REF_DOUBLE_BARRELED_SHOTGUN, "ui_primary_highlighted", "shotgun2", 3071 )\
	}\
	menuDef	{\
		CAC_POPUP_SWAP( "popup_cac_sniper"suffix, execnow "set "UI_FOCUSFIRST" "REF_SPRINGFIELD"; set ui_inside_popup sniper", ; )\
		LOCAL_WEAPON_INFO_WINDOW( "ui_primary_highlighted" )\
		LOCAL_WEAPON_ITEM( suffix, 1, "@WEAPON_SPRINGFIELD", STAT_SNIPER_SPRINGFIELD, REF_SPRINGFIELD, "ui_primary_highlighted", "rifle", 3060 )\
		LOCAL_WEAPON_ITEM( suffix, 2, "@WEAPON_TYPE99_RIFLE", STAT_SNIPER_TYPE99_RIFLE, REF_TYPE99_RIFLE, "ui_primary_highlighted", "rifle", 3062 )\
		LOCAL_WEAPON_ITEM( suffix, 3, "@WEAPON_MOSIN_RIFLE", STAT_SNIPER_MOSIN, REF_MOSIN, "ui_primary_highlighted", "rifle", 3061 )\
		LOCAL_WEAPON_ITEM( suffix, 4, "@WEAPON_KAR98K", STAT_SNIPER_KAR98K, REF_KAR98K, "ui_primary_highlighted", "rifle", 3063 )\
		LOCAL_WEAPON_ITEM( suffix, 5, "@WEAPON_PTRS41", STAT_SNIPER_PTRS41, REF_PTRS41, "ui_primary_highlighted", "fake", 3064 )\
	}
	
	// primary and second primary weapon selection popup menus
	LOCAL_MASTER_WEAPON_GROUP( "", 1, 0 )
	LOCAL_MASTER_WEAPON_GROUP( "_2", 2, 4 )

// ====================================================================================================
// primary and second primary attachment selection ====================================================
// ====================================================================================================
	#define LOCAL_ATTACHMENT_INFO_WINDOW( pslot ) \
		/* attachment image*/ \
		PREPROC_SHADER_DRAW_ALIGNED( LOADOUT_IMAGE_X LOADOUT_IMAGE_Y 90 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup("mp/attachmentTable.csv",4,dvarString(ui_attachment_highlighted),6), 1 1 1 1, 0, 2, 0 0 0 0 visible when( dvarString(ui_inside_popup) != "camo" ); ) \
		/* attachment title*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_TITLE_X LOADOUT_TITLE_Y (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statsTable.csv",4,dvarString(ui_primary_highlighted),3)+"_"+tablelookup("mp/attachmentTable.csv",4,dvarString(ui_attachment_highlighted),7), CHOICE_TEXTSIZE, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW visible when( dvarString(ui_inside_popup) != "camo" ); ) \
		/* attachment desc unlocked*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statsTable.csv",4,dvarString(ui_primary_highlighted),3)+"_"+tablelookup("mp/attachmentTable.csv",4,dvarString(ui_attachment_highlighted),7)+"_DESC", TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR visible when( ( stat( stat( pslot-1 )+3000 ) & int(tablelookup( "mp/attachmenttable.csv", 2, dvarInt(ui_attachment_statslot), 3 ) ) ) && ( ( dvarString( ui_primary_selected ) != "Primary Weapon" || dvarString(ui_attachment_highlighted) != "gl" || dvarString( ui_secondary_attachment_slot ) != "gl" ) && ( dvarString( ui_primary_selected ) != "Secondary Weapon" || dvarString(ui_attachment_highlighted) != "gl" || dvarString( ui_primary_attachment_slot ) != "gl" ) ) ); ) \
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statsTable.csv",4,dvarString(ui_primary_highlighted),3)+"_"+tablelookup("mp/attachmentTable.csv",4,dvarString(ui_attachment_highlighted),8)+"_DESC", TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_RED_TEXT visible when( (  stat( stat( pslot-1 )+3000 ) & int(tablelookup( "mp/attachmenttable.csv", 2, dvarInt(ui_attachment_statslot), 3 ) ) ) == 0 ); )\
		/* Grenade launcher already selected */ \
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@MPUI_ALREADY_SELECTED", TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR visible when( ( stat( stat( pslot-1 )+3000 ) & int(tablelookup( "mp/attachmenttable.csv", 2, dvarInt(ui_attachment_statslot), 3 ) ) ) && ( ( dvarString( ui_primary_selected ) == "Primary Weapon" && dvarString(ui_attachment_highlighted) == "gl" && dvarString( ui_secondary_attachment_slot ) == "gl" ) || ( dvarString( ui_primary_selected ) == "Secondary Weapon" && dvarString(ui_attachment_highlighted) == "gl" && dvarString( ui_primary_attachment_slot ) == "gl" ) ) ); )\
		/* attributes info display =============== */\
		CAC_LOADOUT_ATTRIBUTES \
		CAC_LOADOUT_ATTRIBUTES_PREVIEW

	#define LOCAL_ATTACHMENT_ACTION( pslot, pnum, paction, ptype, pname ) \
		paction; \
		statSetUsingTable( pslot, pnum ); \
		setAttachmentOnType( ptype, pname ); \
		PERK1_RESET \
		PREPROC_ATTACH_CLOSEALL
		/*open "popup_cac_camo";*/
		
	#define LOCAL_ATTACHMENT_ACTION2( pslot, pnum, paction, ptype, pname ) \
		paction; \
		statSetUsingTable( pslot, pnum ); \
		setAttachmentOnType( ptype, pname ); \
		PERK1_RESET \
		PREPROC_ATTACH_CLOSEALL

	#define LOCAL_ATTACHMENT_ITEM( itemNum, p_setstat, p_numref, p_numref_s, pname, paction, ptype, statDvar, bitMask )\
		CHOICE_DBUTTON_VIS( itemNum, "@"+tablelookup("mp/statsTable.csv",4,dvarString(ui_primary_highlighted),3)+"_"+tablelookup("mp/attachmentTable.csv",4,pname,7), when( 1 ); ) \
		CHOICE_HIGHLIGHT( itemNum, 1 ) \
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, "", ;, execNow "set ui_attachment_highlighted "pname;, ;, when( ptype == "primary" && ( stat( stat( p_setstat-1 )+3000 ) & int(tablelookup( "mp/attachmenttable.csv", 2, p_numref, 3 ) ) ) && ( pname == "gl" && dvarString( ui_secondary_attachment_slot ) == "gl" ) ); ) \
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, "", ;, execNow "set ui_attachment_highlighted "pname;, ;, when( ptype == "secondary" && ( stat( stat( p_setstat-1 )+3000 ) & int(tablelookup( "mp/attachmenttable.csv", 2, p_numref, 3 ) ) ) && ( pname == "gl" && dvarString( ui_primary_attachment_slot ) == "gl" ) ); ) \
		\
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, \
			"@"+tablelookup("mp/statsTable.csv",4,dvarString(ui_primary_highlighted),3)+"_"+tablelookup("mp/attachmentTable.csv",4,pname,7), \
			LOCAL_ATTACHMENT_ACTION( p_setstat, p_numref, paction, ptype, pname );CLEAR_NEW( statDvar, bitMask );, \
			execnow "set ui_attachment_highlighted "pname; execnow "set ui_attachment_statslot "p_numref_s;,\
			CLEAR_NEW( statDvar, bitMask );, \
			when( ptype == "primary" && ( stat( stat( p_setstat-1 )+3000 ) & int(tablelookup( "mp/attachmenttable.csv", 2, p_numref, 3 ) ) ) && ( pname != "gl" || dvarString( ui_secondary_attachment_slot ) != "gl" ) ) ) \
		\
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, \
			"@"+tablelookup("mp/statsTable.csv",4,dvarString(ui_primary_highlighted),3)+"_"+tablelookup("mp/attachmentTable.csv",4,pname,7), \
			LOCAL_ATTACHMENT_ACTION2( p_setstat, p_numref, paction, ptype, pname );CLEAR_NEW( statDvar, bitMask );, \
			execnow "set ui_attachment_highlighted "pname; execnow "set ui_attachment_statslot "p_numref_s;, \
			CLEAR_NEW( statDvar, bitMask );, \
			when( ptype == "secondary" && ( stat( stat( p_setstat-1 )+3000 ) & int(tablelookup( "mp/attachmenttable.csv", 2, p_numref, 3 ) ) ) && ( pname != "gl" || dvarString( ui_primary_attachment_slot ) != "gl" ) ) ) \
		\
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, "", ;, execnow "set ui_attachment_highlighted "pname; execnow "set ui_attachment_statslot "p_numref_s; execnow "set ui_attachment_loadout "pname, ;, when( ( stat( stat( p_setstat-1 )+3000 ) & int(tablelookup( "mp/attachmenttable.csv", 2, p_numref, 3 ))) == 0 ); ) \
		CHOICE_DBUTTON_VIS( itemNum, "@"+tablelookup("mp/statsTable.csv",4,dvarString(ui_primary_highlighted),3)+"_"+tablelookup("mp/attachmentTable.csv",4,pname,7), when( ( stat( stat( p_setstat-1 )+3000 ) & int(tablelookup( "mp/attachmenttable.csv", 2, p_numref, 3 ))) == 0 ); ) \
		CHOICE_NEWICON_VIS( itemNum, "specialty_new", when( ( int(tablelookup( "mp/attachmenttable.csv", 2, p_numref, 3 )) != 1 ) && (stat( stat( p_setstat-1 )+3000 ) & int(tablelookup( "mp/attachmenttable.csv", 2, p_numref, 3 ))<<16 )) ) \
		CHOICE_LOCKEDICON_VIS( itemNum, "specialty_locked", when( ( stat( stat( p_setstat-1 )+3000 ) & int(tablelookup( "mp/attachmenttable.csv", 2, p_numref, 3 ))) == 0 ); )

	// hackaround to work for PC's floating mouse unfocusing
	#undef  UI_FOCUSFIRST
	#ifdef PC
		#define UI_FOCUSFIRST "ui_attachment_highlighted"
	#else
		#define UI_FOCUSFIRST "ui_fake_focus"
	#endif


	#define LOCAL_MASTER_ATTACHMENT_GROUP( stat_slot, suffix, pos, ptype, y_offset, statDvar )\
	menuDef { /* springfield, kar98, mosinrifle, type99rifle attachments */ \
		CAC_POPUP_SWAP( "attachment_popup_rifle"suffix, execnow "set "UI_FOCUSFIRST" "REF_ATTACHMENT_NONE"; set ui_inside_popup attachment", execnow "set ui_inside_popup 0"; )\
		LOCAL_ATTACHMENT_INFO_WINDOW( stat_slot )\
		LOCAL_ATTACHMENT_ITEM( 1, stat_slot, NUM_NONE, "0", "none", PERK1_RESET, ptype, statDvar, 0 )\
		LOCAL_ATTACHMENT_ITEM( 2, stat_slot, NUM_ATTACHMENT1, "1", "scoped", PERK1_RESET, ptype, statDvar, ATTACHMENT1_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 3, stat_slot, NUM_ATTACHMENT2, "2", "bayonet", PERK1_RESET, ptype, statDvar, ATTACHMENT2_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 4, stat_slot, NUM_ATTACHMENT3, "3", "gl", PERK1_RESET, ptype, statDvar, ATTACHMENT3_NEW_BITMASK )\
	}\
	menuDef { /* svt40, stg44*/ \
		CAC_POPUP_SWAP( "attachment_popup_assault1"suffix, execnow "set "UI_FOCUSFIRST" "REF_ATTACHMENT_NONE"; set ui_inside_popup attachment", execnow "set ui_inside_popup 0"; )\
		LOCAL_ATTACHMENT_INFO_WINDOW( stat_slot )\
		LOCAL_ATTACHMENT_ITEM( 1, stat_slot, NUM_NONE, "0", "none", PERK1_RESET, ptype, statDvar, 0 )\
		LOCAL_ATTACHMENT_ITEM( 2, stat_slot, NUM_ATTACHMENT1, "1", "flash", PERK1_RESET, ptype, statDvar, ATTACHMENT1_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 3, stat_slot, NUM_ATTACHMENT2, "2", "aperture", PERK1_RESET, ptype, statDvar, ATTACHMENT2_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 4, stat_slot, NUM_ATTACHMENT3, "3", "telescopic", PERK1_RESET, ptype, statDvar, ATTACHMENT3_NEW_BITMASK )\
	}\
	menuDef { /* gewehr43 */ \
		CAC_POPUP_SWAP( "attachment_popup_assault2"suffix,  execnow "set "UI_FOCUSFIRST" "REF_ATTACHMENT_NONE"; set ui_inside_popup attachment", execnow "set ui_inside_popup 0"; )\
		LOCAL_ATTACHMENT_INFO_WINDOW( stat_slot )\
		LOCAL_ATTACHMENT_ITEM( 1, stat_slot, NUM_NONE, "0", "none", PERK1_RESET, ptype, statDvar, 0 )\
		LOCAL_ATTACHMENT_ITEM( 2, stat_slot, NUM_ATTACHMENT1, "1", "silenced", PERK1_RESET, ptype, statDvar, ATTACHMENT1_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 3, stat_slot, NUM_ATTACHMENT2, "2", "aperture", PERK1_RESET, ptype, statDvar, ATTACHMENT2_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 4, stat_slot, NUM_ATTACHMENT3, "3", "telescopic", PERK1_RESET, ptype, statDvar, ATTACHMENT3_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 5, stat_slot, NUM_ATTACHMENT4, "4", "gl", PERK1_RESET, ptype, statDvar, ATTACHMENT4_NEW_BITMASK )\
	}\
	menuDef { /* m1garand */ \
		CAC_POPUP_SWAP( "attachment_popup_assault3"suffix, execnow "set "UI_FOCUSFIRST" "REF_ATTACHMENT_NONE"; set ui_inside_popup attachment", execnow "set ui_inside_popup 0"; )\
		LOCAL_ATTACHMENT_INFO_WINDOW( stat_slot )\
		LOCAL_ATTACHMENT_ITEM( 1, stat_slot, NUM_NONE, "0", "none", PERK1_RESET, ptype, statDvar, 0 )\
		LOCAL_ATTACHMENT_ITEM( 2, stat_slot, NUM_ATTACHMENT1, "1", "flash", PERK1_RESET, ptype, statDvar, ATTACHMENT1_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 3, stat_slot, NUM_ATTACHMENT2, "2", "bayonet", PERK1_RESET, ptype, statDvar, ATTACHMENT2_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 4, stat_slot, NUM_ATTACHMENT3, "3", "gl", PERK1_RESET, ptype, statDvar, ATTACHMENT3_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 5, stat_slot, NUM_ATTACHMENT4, "4", "scoped", PERK1_RESET, ptype, statDvar, ATTACHMENT4_NEW_BITMASK )\
	}\
	menuDef { /* m1carbine */ \
		CAC_POPUP_SWAP( "attachment_popup_assault4"suffix, execnow "set "UI_FOCUSFIRST" "REF_ATTACHMENT_NONE"; set ui_inside_popup attachment", execnow "set ui_inside_popup 0"; )\
		LOCAL_ATTACHMENT_INFO_WINDOW( stat_slot )\
		LOCAL_ATTACHMENT_ITEM( 1, stat_slot, NUM_NONE, "0", "none", PERK1_RESET, ptype, statDvar, 0 )\
		LOCAL_ATTACHMENT_ITEM( 2, stat_slot, NUM_ATTACHMENT1, "1", "flash", PERK1_RESET, ptype, statDvar, ATTACHMENT1_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 3, stat_slot, NUM_ATTACHMENT2, "2", "aperture", PERK1_RESET, ptype, statDvar, ATTACHMENT2_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 4, stat_slot, NUM_ATTACHMENT3, "3", "bayonet", PERK1_RESET, ptype, statDvar, ATTACHMENT3_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 5, stat_slot, NUM_ATTACHMENT4, "4", "bigammo", PERK1_RESET, ptype, statDvar, ATTACHMENT4_NEW_BITMASK )\
	}\
	menuDef { /* thompson, mp40. type100smg attachments */ \
		CAC_POPUP_SWAP( "attachment_popup_SMG1"suffix, execnow "set "UI_FOCUSFIRST" "REF_ATTACHMENT_NONE"; set ui_inside_popup attachment", execnow "set ui_inside_popup 0"; )\
		LOCAL_ATTACHMENT_INFO_WINDOW( stat_slot )\
		LOCAL_ATTACHMENT_ITEM( 1, stat_slot, NUM_NONE, "0", "none", PERK1_RESET, ptype, statDvar, 0 )\
		LOCAL_ATTACHMENT_ITEM( 2, stat_slot, NUM_ATTACHMENT1, "1", "silenced", PERK1_RESET, ptype, statDvar, ATTACHMENT1_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 3, stat_slot, NUM_ATTACHMENT2, "2", "aperture", PERK1_RESET, ptype, statDvar, ATTACHMENT2_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 4, stat_slot, NUM_ATTACHMENT3, "3", "bigammo", PERK1_RESET, ptype, statDvar, ATTACHMENT3_NEW_BITMASK )\
	}\
	menuDef { /* ppsh attachments */ \
		CAC_POPUP_SWAP( "attachment_popup_SMG2"suffix,  execnow "set "UI_FOCUSFIRST" "REF_ATTACHMENT_NONE"; set ui_inside_popup attachment", execnow "set ui_inside_popup 0"; )\
		LOCAL_ATTACHMENT_INFO_WINDOW( stat_slot )\
		LOCAL_ATTACHMENT_ITEM( 1, stat_slot, NUM_NONE, "0", "none", PERK1_RESET, ptype, statDvar, 0 )\
		LOCAL_ATTACHMENT_ITEM( 2, stat_slot, NUM_ATTACHMENT1, "1", "aperture", PERK1_RESET, ptype, statDvar, ATTACHMENT1_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 3, stat_slot, NUM_ATTACHMENT2, "2", "bigammo", PERK1_RESET, ptype, statDvar, ATTACHMENT2_NEW_BITMASK )\
	}\
	menuDef { /* LMGs */ \
		CAC_POPUP_SWAP( "attachment_popup_LMG1"suffix, execnow "set "UI_FOCUSFIRST" "REF_ATTACHMENT_NONE"; set ui_inside_popup attachment", execnow "set ui_inside_popup 0"; )\
		LOCAL_ATTACHMENT_INFO_WINDOW( stat_slot )\
		LOCAL_ATTACHMENT_ITEM( 1, stat_slot, NUM_NONE, "0", "none", PERK1_RESET, ptype, statDvar, 0 )\
		LOCAL_ATTACHMENT_ITEM( 2, stat_slot, NUM_ATTACHMENT1, "1", "bipod", PERK1_RESET, ptype, statDvar, ATTACHMENT1_NEW_BITMASK )\
	}\
	menuDef { /* FG42 */ \
		CAC_POPUP_SWAP( "attachment_popup_LMG2"suffix, execnow "set "UI_FOCUSFIRST" "REF_ATTACHMENT_NONE"; set ui_inside_popup attachment", execnow "set ui_inside_popup 0"; )\
		LOCAL_ATTACHMENT_INFO_WINDOW( stat_slot )\
		LOCAL_ATTACHMENT_ITEM( 1, stat_slot, NUM_NONE, "0", "none", PERK1_RESET, ptype, statDvar, 0 )\
		LOCAL_ATTACHMENT_ITEM( 2, stat_slot, NUM_ATTACHMENT1, "1", "bipod", PERK1_RESET, ptype, statDvar, ATTACHMENT1_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 3, stat_slot, NUM_ATTACHMENT2, "2", "telescopic", PERK1_RESET, ptype, statDvar, ATTACHMENT2_NEW_BITMASK )\
	}\
	menuDef { /* Type99 */ \
		CAC_POPUP_SWAP( "attachment_popup_LMG3"suffix, execnow "set "UI_FOCUSFIRST" "REF_ATTACHMENT_NONE"; set ui_inside_popup attachment", execnow "set ui_inside_popup 0"; )\
		LOCAL_ATTACHMENT_INFO_WINDOW( stat_slot )\
		LOCAL_ATTACHMENT_ITEM( 1, stat_slot, NUM_NONE, "0", "none", PERK1_RESET, ptype, statDvar, 0 )\
		LOCAL_ATTACHMENT_ITEM( 2, stat_slot, NUM_ATTACHMENT1, "1", "bipod", PERK1_RESET, ptype, statDvar, ATTACHMENT1_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 3, stat_slot, NUM_ATTACHMENT2, "2", "bayonet", PERK1_RESET, ptype, statDvar, ATTACHMENT2_NEW_BITMASK )\
	}\
	menuDef { /* mg30, mg40 */ \
		CAC_POPUP_SWAP( "attachment_popup_LMG4"suffix, execnow "set "UI_FOCUSFIRST" "REF_ATTACHMENT_NONE"; set ui_inside_popup attachment", execnow "set ui_inside_popup 0"; )\
		LOCAL_ATTACHMENT_INFO_WINDOW( stat_slot )\
		LOCAL_ATTACHMENT_ITEM( 1, stat_slot, NUM_NONE, "0", "none", PERK1_RESET, ptype, statDvar, 0 )\
		LOCAL_ATTACHMENT_ITEM( 2, stat_slot, NUM_ATTACHMENT1, "1", "bipod", PERK1_RESET, ptype, statDvar, ATTACHMENT1_NEW_BITMASK )\
	}\
	menuDef { /* shotgun attachments */ \
		CAC_POPUP_SWAP( "attachment_popup_shotgun1"suffix,  execnow "set "UI_FOCUSFIRST" "REF_ATTACHMENT_NONE"; set ui_inside_popup attachment", execnow "set ui_inside_popup 0"; )\
		LOCAL_ATTACHMENT_INFO_WINDOW( stat_slot )\
		LOCAL_ATTACHMENT_ITEM( 1, stat_slot, NUM_NONE, "0", "none", PERK1_RESET, ptype, statDvar, 0 )\
		LOCAL_ATTACHMENT_ITEM( 2, stat_slot, NUM_ATTACHMENT1, "1", "grip", PERK1_RESET, ptype, statDvar, ATTACHMENT1_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 3, stat_slot, NUM_ATTACHMENT2, "2", "bayonet", PERK1_RESET, ptype, statDvar, ATTACHMENT2_NEW_BITMASK )\
	}\
	menuDef { /* doublebarreldshotgun attachments */ \
		CAC_POPUP_SWAP( "attachment_popup_shotgun2"suffix, execnow "set "UI_FOCUSFIRST" "REF_ATTACHMENT_NONE"; set ui_inside_popup attachment" , execnow "set ui_inside_popup 0";)\
		LOCAL_ATTACHMENT_INFO_WINDOW( stat_slot )\
		LOCAL_ATTACHMENT_ITEM( 1, stat_slot, NUM_NONE, "0", "none", PERK1_RESET, ptype, statDvar, 0 )\
		LOCAL_ATTACHMENT_ITEM( 2, stat_slot, NUM_ATTACHMENT1, "1", "grip", PERK1_RESET, ptype, statDvar, ATTACHMENT1_NEW_BITMASK )\
		LOCAL_ATTACHMENT_ITEM( 3, stat_slot, NUM_ATTACHMENT2, "2", "sawoff", PERK1_RESET, ptype, statDvar, ATTACHMENT2_NEW_BITMASK )\
	}

	menuDef { //fake attachment heading for weapons without attachments to be displayed on top of camo popup
		name "attachment_popup_fake";
		onOpen { close self; PREPROC_ATTACH_CLOSEALL }
	}

	menuDef { //fake attachment for secondary weapons
		name "attachment_popup_fake_2";
		onOpen { close self; PREPROC_ATTACH_CLOSEALL }
	}

	// primary and second primary attachment popup menus
	LOCAL_MASTER_ATTACHMENT_GROUP( CAC_PRIMARY_ATTACHMENT, "", 1, "primary", 0, "ui_primary_weapon" )
	LOCAL_MASTER_ATTACHMENT_GROUP( CAC_SECONDARY_ATTACHMENT, "_2", 2, "secondary", 4, "ui_secondary_weapon" )

	// ====================================================================================================
	// camo skin selection ================================================================================
	// ====================================================================================================

	#define LOCAL_CAMO_INFO_WINDOW( highlight_dvar ) \
		/* camo image*/ \
		PREPROC_SHADER_DRAW_ALIGNED( LOADOUT_IMAGE_X LOADOUT_IMAGE_Y 64 64 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup("mp/attachmentTable.csv",4,dvarString(highlight_dvar),6), 1 1 1 0.75, 1, 2, 0.2 0.2 0.225 1 ) \
		/* camo title*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_TITLE_X LOADOUT_TITLE_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/attachmenttable.csv",4,dvarString(highlight_dvar),3), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW ) \
		/* camo desc unlocked*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/attachmenttable.csv",4,dvarString(highlight_dvar),7), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR visible when( stat(stat(CAC_PRIMARY)+3000) & int(tablelookup( "mp/attachmenttable.csv", 4, dvarString(ui_camo_highlighted), 10 )) ); )\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/attachmenttable.csv",4,dvarString(highlight_dvar),8), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_RED_TEXT visible when( ( stat(stat(CAC_PRIMARY)+3000) & int(tablelookup( "mp/attachmenttable.csv", 4, dvarString(ui_camo_highlighted), 10 )) ) == 0 ); )\
		/* attributes info display =============== */\
		CAC_LOADOUT_ATTRIBUTES \
		CAC_LOADOUT_ATTRIBUTES_PREVIEW

	#define LOCAL_CAMO_ACTION( pnum ) \
			play "mouse_click"; \
			statsetusingtable( CAC_CAMO, pnum ); \
			PREPROC_ATTACH_CLOSEALL
		
	#define LOCAL_CAMO_ITEM( itemNum, camoName, pnum, camoRef, highlight_dvar, bitMask, visArg )\
		CHOICE_BUTTON_FOCUS_VIS( itemNum, camoName, LOCAL_CAMO_ACTION( pnum );CLEAR_NEW( "ui_primary_weapon", bitMask );, execnow "set "highlight_dvar" "camoRef, CLEAR_NEW( "ui_primary_weapon", bitMask );, \
		when( stat(stat(CAC_PRIMARY)+3000) & int(tablelookup( "mp/attachmenttable.csv", 11, pnum, 10 )) && ( visArg ) ); )  \
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, "", ;, execnow "set "highlight_dvar" "camoRef, ;, when( ( stat(stat(CAC_PRIMARY)+3000) & int(tablelookup( "mp/attachmenttable.csv", 11, pnum, 10 )) ) == 0 && ( visArg ) ); ) \
		CHOICE_DBUTTON_VIS( itemNum, camoName, when( ( stat(stat(CAC_PRIMARY)+3000) & int(tablelookup( "mp/attachmenttable.csv", 11, pnum, 10 )) ) == 0 && ( visArg ) ); ) \
		CHOICE_NEWICON_VIS( itemNum, "specialty_new", when( ( int(tablelookup( "mp/attachmenttable.csv", 11, pnum, 10 )) != 1 ) && \
		( stat(stat(CAC_PRIMARY)+3000) & int(tablelookup( "mp/attachmenttable.csv", 11, pnum, 10 ))<<16 ) && ( visArg ) ) ) \
		CHOICE_LOCKEDICON_VIS( itemNum, "specialty_locked", when( ( stat(stat(CAC_PRIMARY)+3000) & int(tablelookup( "mp/attachmenttable.csv", 11, pnum, 10 )) ) == 0 && ( visArg ) ); )
				
	#define GOLDEN_VIS_CONDITION \
		tablelookup("mp/statstable.csv",1,dvarString(ui_primary_weapon),4)==REF_UZI ||\
		tablelookup("mp/statstable.csv",1,dvarString(ui_primary_weapon),4)==REF_AK47 ||\
		tablelookup("mp/statstable.csv",1,dvarString(ui_primary_weapon),4)==REF_DRAGUNOVSVD ||\
		tablelookup("mp/statstable.csv",1,dvarString(ui_primary_weapon),4)==REF_BENELLIM4 ||\
		tablelookup("mp/statstable.csv",1,dvarString(ui_primary_weapon),4)==REF_M60E4
	
	// BRENT ATTENTION
	#define PRESTIGE_VIS_CONDITION \
		0

	// hackaround to work for PC's floating mouse unfocusing
	#undef  UI_FOCUSFIRST
	#ifdef PC
		#define UI_FOCUSFIRST "ui_camo_highlighted"
	#else
		#define UI_FOCUSFIRST "ui_fake_focus"
	#endif

	// camo skin selection for primary weapon popup menu
	#define LOCAL_CAMO_GROUP( prefix, onLeave )\
	menuDef	\
	{\
		CAC_POPUP_SWAP(  "popup_cac_camo"prefix, execnow "set "UI_FOCUSFIRST" "REF_CAMO_NONE"; set ui_inside_popup camo", onLeave; close "attachment_popup_fake"; ) \
		LOCAL_CAMO_INFO_WINDOW( "ui_camo_highlighted" ) \
		LOCAL_CAMO_ITEM( 1, "@MPUI_NONE", CAMO_NONE, REF_CAMO_NONE, "ui_camo_highlighted", 0, 1 )\
		LOCAL_CAMO_ITEM( 2, "@MPUI_REICH", CAMO_REICH, REF_REICH, "ui_camo_highlighted", REICH_NEW_BITMASK, 1 )\
		LOCAL_CAMO_ITEM( 3, "@MPUI_SIBERIAN", CAMO_SIBERIAN, REF_SIBERIAN, "ui_camo_highlighted", SIBERIAN_NEW_BITMASK, 1 )\
		LOCAL_CAMO_ITEM( 4, "@MPUI_ROYAL", CAMO_ROYAL, REF_ROYAL, "ui_camo_highlighted", ROYAL_NEW_BITMASK, 1 )\
		LOCAL_CAMO_ITEM( 5, "@MPUI_GOLDEN", CAMO_GOLDEN, REF_GOLDEN, "ui_camo_highlighted", GOLDEN_NEW_BITMASK, GOLDEN_VIS_CONDITION )\
		LOCAL_CAMO_ITEM( 6, "@MPUI_PRESTIGE", CAMO_PRESTIGE, REF_PRESTIGE, "ui_camo_highlighted", PRESTIGE_NEW_BITMASK, PRESTIGE_VIS_CONDITION )\
	}

	// camo skin selection for primary weapon popup menu
	LOCAL_CAMO_GROUP( "", execnow "set ui_inside_popup attachment"; )


	// ====================================================================================================
	// side arm selection =================================================================================
	// ====================================================================================================
	#define LOCAL_SIDEARM_INFO_WINDOW( highlight_dvar ) \
		/* weapon image*/ \
		PREPROC_SHADER_DRAW_ALIGNED( LOADOUT_IMAGE_X LOADOUT_IMAGE_Y 90 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),6), 1 1 1 1, 0, 2, 0 0 0 0 visible when( dvarString(ui_inside_popup) != "attachment" ); ) \
		/* weapon title*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_TITLE_X LOADOUT_TITLE_Y (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",4,dvarString(highlight_dvar),3), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW visible when( dvarString(ui_inside_popup) != "attachment" && dvarString(ui_inside_popup) != "camo" ); ) \
		/* weapon desc unlocked*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",4,dvarString(highlight_dvar),7), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR visible when( stat(int(tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),1))) & 1 ); )\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",4,dvarString(highlight_dvar),10), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_RED_TEXT visible when( ( stat(int(tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),1))) & 1 ) == 0 ); )\

	#define LOCAL_SIDEARM_ACTION( pstat, weapRef ) \
			statSetUsingTable( CAC_SECONDARY_ATTACHMENT, 0 ); \
			play "mouse_click"; \
			statSetUsingTable( CAC_SECONDARY, pstat ); \
			statSetUsingTable( CAC_SECONDARY_STORAGE, tableLookup( "mp/statstable.csv", 4, weapRef, 1 ) ); \
			statGetInDvarUsingTable( CAC_SECONDARY_STORAGE, ui_secondary_weapon ); \
			CLEAR_NEW( ui_secondary_weapon, WEAPON_NEW_BITMASK ); \
			PREPROC_ATTACH_CLOSEALL

	#define LOCAL_SIDEARM_ACTION2( pstat, weapRef ) \		
			execNow "set ui_perk1_slot 0"; \
			statSetUsingTable( CAC_SECONDARY_ATTACHMENT, 0 ); \
			play "mouse_click"; \
			statSetUsingTable( CAC_SECONDARY, pstat ); \
			statSetUsingTable( CAC_SECONDARY_STORAGE, tableLookup( "mp/statstable.csv", 4, weapRef, 1 ) ); \
			statGetInDvarUsingTable( CAC_SECONDARY_STORAGE, ui_secondary_weapon ); \
			CLEAR_NEW( ui_secondary_weapon, WEAPON_NEW_BITMASK ); \
			PREPROC_ATTACH_CLOSEALL
			// currently side arms will have no attachments
			//uiScript openMenuOnDvar "selected_weapon_class" pistol "attachment_popup_pistol";

	#define LOCAL_SIDEARM_ITEM( itemNum, weaponName, weaponStat, weaponRef, highlight_dvar )\
		CHOICE_BUTTON_FOCUS_VIS( itemNum, weaponName, LOCAL_SIDEARM_ACTION( weaponStat, weaponRef ), execnow "set "highlight_dvar" "weaponRef, CLEAR_WEAP_NEW( weaponRef );, \
		when( stat( int(weaponStat)+3000 ) & 1) ) \
		\
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, "", ;, execnow "set "highlight_dvar" "weaponRef, ;, when( ( stat(int(weaponStat)+3000) & 1 ) == 0 ); ) \
		CHOICE_DBUTTON_VIS( itemNum, weaponName, when( ( stat( int(weaponStat)+3000 ) & 1 ) == 0 ) ) \
		CHOICE_NEWICON_VIS( itemNum, "specialty_new", when( ( (stat(int(weaponStat)+3000)) & (NEW_WEAPON_BITMASK+NEW_ITEMS_MASK) ) > 0 ) ) \
		CHOICE_LOCKEDICON_VIS( itemNum, "specialty_locked", when( ( stat(int(weaponStat)+3000) & 1 ) == 0 ); )
	// side arm selection popup menu
	
	// hackaround to work for PC's floating mouse unfocusing
	#undef  UI_FOCUSFIRST
	#ifdef PC
		#define UI_FOCUSFIRST "ui_sidearm_highlighted"
	#else
		#define UI_FOCUSFIRST "ui_fake_focus"
	#endif
	
	menuDef	
	{
		CAC_POPUP_SWAP( "popup_cac_secondary", execnow "set "UI_FOCUSFIRST" "REF_COLT"; set selected_weapon_class pistol; set ui_inside_popup pistol", execnow "set ui_inside_popup 0" )
		LOCAL_SIDEARM_INFO_WINDOW( "ui_sidearm_highlighted" )
		LOCAL_SIDEARM_ITEM( 1, "@WEAPON_COLT45", STAT_PISTOL_COLT, REF_COLT, "ui_sidearm_highlighted" )
		LOCAL_SIDEARM_ITEM( 2, "@WEAPON_NAMBU", STAT_PISTOL_NAMBU, REF_NAMBU, "ui_sidearm_highlighted" )
		LOCAL_SIDEARM_ITEM( 3, "@WEAPON_WALTHER_P38", STAT_PISTOL_WALTHER, REF_WALTHER, "ui_sidearm_highlighted" )
		LOCAL_SIDEARM_ITEM( 4, "@WEAPON_TOKAREV", STAT_PISTOL_TOKAREV, REF_TOKAREV, "ui_sidearm_highlighted" )
		LOCAL_SIDEARM_ITEM( 5, "@WEAPON_357MAGNUM", STAT_PISTOL_357MAGNUM, REF_357MAGNUM, "ui_sidearm_highlighted" )
	}

	// ====================================================================================================
	// primary grenade selection ==========================================================================
	// ====================================================================================================
	#define LOCAL_PGRENADE_INFO_WINDOW( highlight_dvar ) \
		/* primary grenade image*/ \
		PREPROC_SHADER_DRAW_ALIGNED( LOADOUT_IMAGE_X LOADOUT_IMAGE_Y 90 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),6), 1 1 1 1, 0, 2, 0 0 0 0 ) \
		/* primary grenade title*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_TITLE_X LOADOUT_TITLE_Y (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",4,dvarString(highlight_dvar),3), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW ) \
		/* primary grenade desc unlocked*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",4,dvarString(highlight_dvar),7), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR visible when( stat(int(tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),1))) & 1 ); )\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",4,dvarString(highlight_dvar),10), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_RED_TEXT visible when( ( stat(int(tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),1))) & 1 ) == 0 ); )\
		
	#define LOCAL_PGRENADE_ACTION( pstat ) \
			play "mouse_click"; \
			statsetusingtable( CAC_PRIMARY_GRENADE, pstat ); \
			close "popup_cac_pgrenade"
		
	#define LOCAL_PGRENADE_ITEM( itemNum, weaponName, weaponStat, weaponRef, highlight_dvar )\
		CHOICE_BUTTON_FOCUS_VIS( itemNum, weaponName, LOCAL_PGRENADE_ACTION( weaponStat ), execnow "set "highlight_dvar" "weaponRef, CLEAR_WEAP_NEW( weaponRef );, \
		when( stat( int(weaponStat)+3000 ) & 1) ) \
		\
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, "", ;, execnow "set "highlight_dvar" "weaponRef, ;, when( ( stat(int(weaponStat)+3000) & 1 ) == 0 ); ) \
		CHOICE_DBUTTON_VIS( itemNum, weaponName, when( ( stat( int(weaponStat)+3000 ) & 1 ) == 0 ) ) \
		CHOICE_NEWICON_VIS( itemNum, "specialty_new", when( ( (stat(int(weaponStat)+3000)) & (NEW_WEAPON_BITMASK+NEW_ITEMS_MASK) ) > 0 ) ) \
		CHOICE_LOCKEDICON_VIS( itemNum, "specialty_locked", when( ( stat(int(weaponStat)+3000) & 1 ) == 0 ); )
	
	// hackaround to work for PC's floating mouse unfocusing
	#undef  UI_FOCUSFIRST
	#ifdef PC
		#define UI_FOCUSFIRST "ui_pgrenade_highlighted"
	#else
		#define UI_FOCUSFIRST "ui_fake_focus"
	#endif
	
	// primary grenade selection popup menus
	menuDef	
	{
		CAC_POPUP_SWAP( "popup_cac_pgrenade", execnow "set "UI_FOCUSFIRST" "REF_FRAG_X1"; set ui_inside_popup pgrenade", execnow "set ui_inside_popup 0" )
		LOCAL_PGRENADE_INFO_WINDOW( "ui_pgrenade_highlighted" )
		LOCAL_PGRENADE_ITEM( 1, "@WEAPON_FRAGGRENADE", STAT_FRAG_X1, REF_FRAG_X1, "ui_pgrenade_highlighted" )
		LOCAL_PGRENADE_ITEM( 2, "@WEAPON_STICKY_GRENADE", STAT_STICKY_X1, REF_STICKY_X1, "ui_pgrenade_highlighted" )
		LOCAL_PGRENADE_ITEM( 3, "@WEAPON_MOLOTOV", STAT_MOLOTOV_X1, REF_MOLOTOV_X1, "ui_pgrenade_highlighted" )
	}
		
	// ====================================================================================================
	// special grenade selection ==========================================================================
	// ====================================================================================================
	#define LOCAL_SGRENADE_INFO_WINDOW( highlight_dvar ) \
		/* special grenade image*/ \
		PREPROC_SHADER_DRAW_ALIGNED( LOADOUT_IMAGE_X LOADOUT_IMAGE_Y 90 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),6), 1 1 1 1, 0, 2, 0 0 0 0 ) \
		/* special grenade title*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_TITLE_X LOADOUT_TITLE_Y (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",4,dvarString(highlight_dvar),3), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW ) \
		/* special grenade desc unlocked*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",4,dvarString(highlight_dvar),7), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR \
			visible when( ( ( dvarString(ui_sgrenade_highlighted)=="m8_white_smoke") && (tableLookup("mp/statsTable.csv",0,stat(CAC_SPECIALTY_EQUIPMENT),4)=="specialty_specialgrenade") ) == 0 ); )\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",4,dvarString(highlight_dvar),10), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_RED_TEXT \
			visible when( (dvarString(ui_sgrenade_highlighted)=="m8_white_smoke") && (tableLookup("mp/statsTable.csv",0,stat(CAC_SPECIALTY_EQUIPMENT),4)=="specialty_specialgrenade") ); )

	#define LOCAL_SGRENADE_ACTION( pstat ) \
			play "mouse_click"; \
			statsetusingtable( CAC_SPECIAL_GRENADE, pstat ); \
			close "popup_cac_sgrenade"
		
	#define LOCAL_SGRENADE_ITEM( itemNum, weaponName, weaponStat, weaponRef, highlight_dvar )\
		CHOICE_BUTTON_FOCUS_VIS( itemNum, weaponName, LOCAL_SGRENADE_ACTION( weaponStat ), execnow "set "highlight_dvar" "weaponRef, ;, \
			when( ( (tableLookup("mp/statsTable.csv",0,weaponStat,4)=="m8_white_smoke") && (tableLookup("mp/statsTable.csv",0,stat(CAC_SPECIALTY_EQUIPMENT),4)=="specialty_specialgrenade") ) == 0 ); ) \
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, "", ;, execnow "set "highlight_dvar" "weaponRef, ;, when( (tableLookup("mp/statsTable.csv",0,weaponStat,4)=="m8_white_smoke") && (tableLookup("mp/statsTable.csv",0,stat(CAC_SPECIALTY_EQUIPMENT),4)=="specialty_specialgrenade") ); ) \
		CHOICE_DBUTTON_VIS( itemNum, weaponName, when( (tableLookup("mp/statsTable.csv",0,weaponStat,4)=="m8_white_smoke") && (tableLookup("mp/statsTable.csv",0,stat(CAC_SPECIALTY_EQUIPMENT),4)=="specialty_specialgrenade") ); ) \
	
	// hackaround to work for PC's floating mouse unfocusing
	#undef  UI_FOCUSFIRST
	#ifdef PC
		#define UI_FOCUSFIRST "ui_sgrenade_highlighted"
	#else
		#define UI_FOCUSFIRST "ui_fake_focus"
	#endif
	
	// special grenade selection popup menus
	menuDef	
	{
		CAC_POPUP_SWAP( "popup_cac_sgrenade", execnow "set "UI_FOCUSFIRST" "REF_SMOKE_X1"; set ui_inside_popup sgrenade", execnow "set ui_inside_popup 0" )
		LOCAL_SGRENADE_INFO_WINDOW( "ui_sgrenade_highlighted" )
		LOCAL_SGRENADE_ITEM( 1, "@WEAPON_M8_WHITE_SMOKE", STAT_SMOKE_X1, REF_SMOKE_X1, "ui_sgrenade_highlighted" )
		LOCAL_SGRENADE_ITEM( 2, "@WEAPON_TABUN_GRENADE", STAT_TABUN_X1, REF_TABUN_X1, "ui_sgrenade_highlighted" )
		LOCAL_SGRENADE_ITEM( 3, "@WEAPON_SIGNAL_FLARE", STAT_FLARE_X1, REF_FLARE_X1, "ui_sgrenade_highlighted" )
	}

	// ====================================================================================================
	// perk selection =====================================================================================
	// ====================================================================================================
	#define LOCAL_PERK_INFO_WINDOW( highlight_dvar ) \
		/* perk image*/ \
		PREPROC_SHADER_DRAW_ALIGNED( LOADOUT_IMAGE_X  LOADOUT_IMAGE_Y 90 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),6), 1 1 1 0.75, 0, 0, 0.2 0.2 0.225 1 ) \
		/* perk title*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_TITLE_X LOADOUT_TITLE_Y (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),3), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW ) \
		/* perk desc unlocked*/\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT,  "@"+tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),7), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR \
			visible when( stat( int(tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),1)) ) > 0 && ( tableLookup("mp/statsTable.csv",0,stat(CAC_SPECIAL_GRENADE),4)=="m8_white_smoke" && dvarString(highlight_dvar)=="specialty_specialgrenade" )==0 ); )\
		PREPROC_TEXT_DRAW_ALIGNED_EXP( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT,  "@"+tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),10), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_RED_TEXT \
			visible when( stat( int(tablelookup("mp/statsTable.csv",4,dvarString(highlight_dvar),1)) ) == 0 || ( tableLookup("mp/statsTable.csv",0,stat(CAC_SPECIAL_GRENADE),4)=="m8_white_smoke" && dvarString(highlight_dvar)=="specialty_specialgrenade" ) ); )\

	#define LOCAL_PERK_ACTION( pslot, pstat, paction ) \
			play "mouse_click"; \
			close self \
			statsetusingtable( pslot, pstat ); \
			paction
		
	#define LOCAL_PERK_ITEM( itemNum, camoName, pstat, perkRef, pslot, highlight_dvar, paction )\
		LOCAL_PERK_ITEM_VIS( itemNum, camoName, pstat, perkRef, pslot, highlight_dvar, paction, 1, 1 )
		
	#define LOCAL_PERK_ITEM_VIS( itemNum, camoName, pstat, perkRef, pslot, highlight_dvar, paction, visArg, vis )\
		CHOICE_BUTTON_BG( itemNum, vis ) \
		CHOICE_HIGHLIGHT( itemNum, visArg ) \
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, camoName, LOCAL_PERK_ACTION( pslot, pstat, paction );CLEAR_PERK_NEW( perkRef, 2 );, execnow "set "highlight_dvar" "perkRef, CLEAR_PERK_NEW( perkRef, 2 );, \
		when( stat( pstat ) > 0 && ( tableLookup("mp/statsTable.csv",0,stat(CAC_SPECIAL_GRENADE),4)=="m8_white_smoke" && tableLookup("mp/statsTable.csv",0,pstat,4)=="specialty_specialgrenade" )==0 && visArg ); ) \
		CHOICE_BUTTON_FOCUS_VIS_NOHI( itemNum, "", ;, execnow "set "highlight_dvar" "perkRef, ;, \
		when( ( stat( pstat ) == 0 || ( tableLookup("mp/statsTable.csv",0,stat(CAC_SPECIAL_GRENADE),4)=="m8_white_smoke" && tableLookup("mp/statsTable.csv",0,pstat,4)=="specialty_specialgrenade" ) ) && visArg ); ) \
		CHOICE_DBUTTON_VIS( itemNum, camoName, \
		when( ( stat( pstat ) == 0 || tableLookup("mp/statsTable.csv",0,stat(CAC_SPECIAL_GRENADE),4)=="m8_white_smoke" && tableLookup("mp/statsTable.csv",0,pstat,4)=="specialty_specialgrenade" ) && visArg ); ) \
		CHOICE_NEWICON_VIS( itemNum, "specialty_new", when( stat( pstat ) > 1 && visArg ); ) \
		CHOICE_LOCKEDICON_VIS( itemNum, "specialty_locked", when( stat( pstat ) == 0 && visArg ); )

	// hackaround to work for PC's floating mouse unfocusing
	#undef  UI_FOCUSFIRST
	#ifdef PC
		#define UI_FOCUSFIRST "ui_perk_highlighted"
	#else
		#define UI_FOCUSFIRST "ui_fake_focus"
	#endif

	// perk1 selection for primary weapon popup menu
	menuDef	
	{
		CAC_POPUP_SWAP( "popup_cac_perk1", execnow "set "UI_FOCUSFIRST" "REF_SPECIALGRENADE_X3"; set ui_inside_popup perk1", execnow "set ui_inside_popup 0" )
		LOCAL_PERK_INFO_WINDOW( "ui_perk_highlighted" )

		LOCAL_PERK_ITEM( 1, "@PERKS_SPECIAL_GRENADES_X_3", STAT_SPECIALGRENADE_X3, REF_SPECIALGRENADE_X3, CAC_SPECIALTY_EQUIPMENT, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 2, "@PERKS_SATCHEL_CHARGE_X_2", STAT_SATCHEL_CHARGE_X_2, REF_SATCHEL_CHARGE_X_2, CAC_SPECIALTY_EQUIPMENT, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 3, "@PERKS_BAZOOKA_X_2", STAT_BAZOOKA_X2, REF_BAZOOKA_X2, CAC_SPECIALTY_EQUIPMENT, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 4, "@PERKS_BOMB_SQUAD", STAT_DETECTEXPLOSIVE, REF_DETECTEXPLOSIVE, CAC_SPECIALTY_EQUIPMENT, "ui_perk_highlighted", ; )	
		LOCAL_PERK_ITEM( 5, "@PERKS_BETTY_X_2", STAT_BETTY_X2, REF_BETTY_X2, CAC_SPECIALTY_EQUIPMENT, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 6, "@PERKS_BANDOLIER", STAT_EXTRAAMMO, REF_EXTRAAMMO, CAC_SPECIALTY_EQUIPMENT, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 7, "@PERKS_PRIMARY_GRENADES_X_2", STAT_PRIMARYGRENADE_X3, REF_PRIMARYGRENADE_X3, CAC_SPECIALTY_EQUIPMENT, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 8, "@PERKS_FLAMETHROWER", STAT_FLAMETHROWER, REF_FLAMETHROWER, CAC_SPECIALTY_EQUIPMENT, "ui_perk_highlighted", ; )
	}
	
	#define LOCAL_RESET_PISTOL \
		statSetOnDvarStringValue( ui_dual_primaries, "true", CAC_SECONDARY, 0 ); \
		statSetOnDvarStringValue( ui_dual_primaries, "true", CAC_SECONDARY_ATTACHMENT, 0 ); \
		setDvarStringUsingTable( ui_secondary_weapon, tableLookup( "mp/statstable.csv", 0, STAT_CAC_SECONDARY, 1 ) ); \
		execNow "set ui_dual_primaries false"; \
		statGetInDvarUsingTable( CAC_SPECIALTY_EQUIPMENT, ui_perk1_slot ); \
		PERK1_RESET1 \
		statGetInDvarUsingTable( CAC_PRIMARY_ATTACHMENT, ui_primary_attachment_slot ); \
		statSetOnDvarStringValue( ui_primary_attachment_slot, "gl", CAC_SPECIALTY_EQUIPMENT, 193 ); \
		statSetOnDvarStringValue( ui_primary_attachment_slot, "grip", CAC_SPECIALTY_EQUIPMENT, 193 ); 


	#define LOCAL_INIT_DUAL_PRIMARY_CHOICE1 \
		statSetUsingTable( CAC_SECONDARY, 10 ); \
		statSetUsingTable( CAC_SECONDARY_ATTACHMENT, 0 ); \
		setDvarStringUsingTable( ui_secondary_weapon, tableLookup( "mp/statstable.csv", 0, STAT_CAC_SECONDARY, 1 ) ); \
		execNow "set ui_dual_primaries true";

	#define LOCAL_INIT_DUAL_PRIMARY_CHOICE2 \
		statSetUsingTable( CAC_SECONDARY, 20 ); \
		statSetUsingTable( CAC_SECONDARY_ATTACHMENT, 0 ); \
		setDvarStringUsingTable( ui_secondary_weapon, tableLookup( "mp/statstable.csv", 0, STAT_CAC_SECONDARY, 1 ) ); \
		execNow "set ui_dual_primaries true";	
		
	// perk2 selection for primary weapon popup menu
	menuDef	
	{
		CAC_POPUP_SWAP( "popup_cac_perk2", execnow "set "UI_FOCUSFIRST" "REF_BULLETDAMAGE"; set ui_inside_popup perk2", execnow "set ui_inside_popup 0" )
		LOCAL_PERK_INFO_WINDOW( "ui_perk_highlighted" )
		
		LOCAL_PERK_ITEM( 1, "@PERKS_STOPPING_POWER", STAT_BULLETDAMAGE, REF_BULLETDAMAGE, CAC_SPECIALTY_WEAPON, "ui_perk_highlighted", LOCAL_RESET_PISTOL )
		LOCAL_PERK_ITEM( 2, "@PERKS_SONIC_BOOM", STAT_EXPLOSIVEDAMAGE, REF_EXPLOSIVEDAMAGE, CAC_SPECIALTY_WEAPON, "ui_perk_highlighted", LOCAL_RESET_PISTOL )
		LOCAL_PERK_ITEM( 3, "@PERKS_FLAK_JACKET", STAT_FLAKJACKET, REF_FLAKJACKET, CAC_SPECIALTY_WEAPON, "ui_perk_highlighted", LOCAL_RESET_PISTOL )		
		LOCAL_PERK_ITEM( 4, "@PERKS_GASMASK", STAT_GASMASK, REF_GASMASK, CAC_SPECIALTY_WEAPON, "ui_perk_highlighted", LOCAL_RESET_PISTOL )		
		LOCAL_PERK_ITEM( 5, "@PERKS_JUGGERNAUT", STAT_ARMORVEST, REF_ARMORVEST, CAC_SPECIALTY_WEAPON, "ui_perk_highlighted", LOCAL_RESET_PISTOL )
		LOCAL_PERK_ITEM( 6, "@PERKS_UAV_JAMMER", STAT_GPSJAMMER, REF_GPSJAMMER, CAC_SPECIALTY_WEAPON, "ui_perk_highlighted", LOCAL_RESET_PISTOL )	
		LOCAL_PERK_ITEM( 7, "@PERKS_SLEIGHT_OF_HAND", STAT_FASTRELOAD, REF_FASTRELOAD, CAC_SPECIALTY_WEAPON, "ui_perk_highlighted", LOCAL_RESET_PISTOL )
		LOCAL_PERK_ITEM( 8, "@PERKS_SHADES", STAT_SHADES, REF_SHADES, CAC_SPECIALTY_WEAPON, "ui_perk_highlighted", LOCAL_RESET_PISTOL )
		LOCAL_PERK_ITEM( 9, "@PERKS_DOUBLE_TAP", STAT_ROF, REF_ROF, CAC_SPECIALTY_WEAPON, "ui_perk_highlighted", LOCAL_RESET_PISTOL )
		/*hacked, init to thompson if not thompson *to be changed* */	LOCAL_PERK_ITEM_VIS( 10, "@PERKS_OVERKILL", STAT_TWOPRIMARIES, REF_TWOPRIMARIES, CAC_SPECIALTY_WEAPON, "ui_perk_highlighted", LOCAL_INIT_DUAL_PRIMARY_CHOICE1, (stat(CAC_PRIMARY) != 10), 1 )
		/*hacked, init to m1garand if thompson *to be changed* */		LOCAL_PERK_ITEM_VIS( 10, "@PERKS_OVERKILL", STAT_TWOPRIMARIES, REF_TWOPRIMARIES, CAC_SPECIALTY_WEAPON, "ui_perk_highlighted", LOCAL_INIT_DUAL_PRIMARY_CHOICE2, (stat(CAC_PRIMARY) == 10), 0 )
	}
				
	// perk3 selection for primary weapon popup menu
	menuDef	
	{
		CAC_POPUP_SWAP( "popup_cac_perk3", execnow "set "UI_FOCUSFIRST" "REF_LONGERSPRINT"; set ui_inside_popup perk3", execnow "set ui_inside_popup 0" )
		LOCAL_PERK_INFO_WINDOW( "ui_perk_highlighted" )
		
		LOCAL_PERK_ITEM( 1, "@PERKS_DEEP_IMPACT", STAT_BULLETPENETRATION, REF_BULLETPENETRATION, CAC_SPECIALTY_ABILITY, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 2, "@PERKS_EXTREME_CONDITIONING", STAT_LONGERSPRINT, REF_LONGERSPRINT, CAC_SPECIALTY_ABILITY, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 3, "@PERKS_STEADY_AIM", STAT_BULLETACCURACY, REF_BULLETACCURACY, CAC_SPECIALTY_ABILITY, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 4, "@PERKS_TOSSBACK", STAT_TOSSBACK, REF_TOSSBACK, CAC_SPECIALTY_ABILITY, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 5, "@PERKS_LAST_STAND", STAT_PISTOLDEATH, REF_PISTOLDEATH, CAC_SPECIALTY_ABILITY, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 6, "@PERKS_MARTYRDOM", STAT_GRENADEPULLDEATH, REF_GRENADEPULLDEATH, CAC_SPECIALTY_ABILITY, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 7, "@PERKS_FIREPROOF", STAT_FIREPROOF, REF_FIREPROOF, CAC_SPECIALTY_ABILITY, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 8, "@PERKS_DEAD_SILENCE", STAT_QUIETER, REF_QUIETER, CAC_SPECIALTY_ABILITY, "ui_perk_highlighted", ; )	
		LOCAL_PERK_ITEM( 9, "@PERKS_IRON_LUNGS", STAT_HOLDBREATH, REF_HOLDBREATH, CAC_SPECIALTY_ABILITY, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 10, "@PERKS_RECONNAISSANCE", STAT_RECONNAISSANCE, REF_RECONNAISSANCE, CAC_SPECIALTY_ABILITY, "ui_perk_highlighted", ; )
	}

	// perk4 selection for primary weapon popup menu
	menuDef	
	{
		CAC_POPUP_SWAP( "popup_cac_perk4", execnow "set "UI_FOCUSFIRST" "REF_LONGERSPRINT"; set ui_inside_popup perk4", execnow "set ui_inside_popup 0" )
		LOCAL_PERK_INFO_WINDOW( "ui_perk_highlighted" )
		LOCAL_PERK_ITEM( 1, "@PERKS_WATER_COOLER", STAT_WATERCOOLER, REF_WATERCOOLER, CAC_SPECIALTY_VEHICLE, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 2, "@PERKS_GREASED_BEARINGS", STAT_GREASEDBEARINGS, REF_GREASEDBEARINGS, CAC_SPECIALTY_VEHICLE, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 3, "@PERKS_ORDINANCE", STAT_ORDINANCE, REF_ORDINANCE, CAC_SPECIALTY_VEHICLE, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 4, "@PERKS_LEADFOOT", STAT_LEADFOOT, REF_LEADFOOT, CAC_SPECIALTY_VEHICLE, "ui_perk_highlighted", ; )
		LOCAL_PERK_ITEM( 5, "@PERKS_BOOST", STAT_BOOST, REF_BOOST, CAC_SPECIALTY_VEHICLE, "ui_perk_highlighted", ; )
	}
	
	// ====================================================================================================
	// reset to default class selection ===================================================================
	// ====================================================================================================
	#define LOCAL_RESET_DEFAULT_ACTION( ptype ) \
			play "mouse_click"; \
			open "popup_cac_defaultclasswarning"ptype;

	// reset to default class selection popup menu
	menuDef	
	{
		CAC_POPUP_SWAP_VIS( "popup_cac_template", execnow "set ui_inside_popup perk1", execnow "set ui_inside_popup 0", 0 )
		CHOICE_BUTTON_FOCUS_VIS( 1, "@CLASS_CLASS1", LOCAL_RESET_DEFAULT_ACTION( "_assault" ), setdvar ui_default_class_highlighted "0"; setDvarFromLocString( ui_default_name, "@CLASS_CLASS1" );, ;, 1 )
		CHOICE_BUTTON_FOCUS_VIS( 2, "@CLASS_CLASS2", LOCAL_RESET_DEFAULT_ACTION( "_spec_ops" ), setdvar ui_default_class_highlighted "10"; setDvarFromLocString( ui_default_name, "@CLASS_CLASS2" );, ;, 1 )
		CHOICE_BUTTON_FOCUS_VIS( 3, "@CLASS_CLASS3", LOCAL_RESET_DEFAULT_ACTION( "_heavy_gunner" ), setdvar ui_default_class_highlighted "20"; setDvarFromLocString( ui_default_name, "@CLASS_CLASS3" );, ;, 1 )
		CHOICE_BUTTON_FOCUS_VIS( 4, "@CLASS_CLASS4", LOCAL_RESET_DEFAULT_ACTION( "_demolitions" ), setdvar ui_default_class_highlighted "30"; setDvarFromLocString( ui_default_name, "@CLASS_CLASS4" );, ;, 1 )
		CHOICE_BUTTON_FOCUS_VIS( 5, "@CLASS_CLASS5", LOCAL_RESET_DEFAULT_ACTION( "_sniper" ), setdvar ui_default_class_highlighted "40"; setDvarFromLocString( ui_default_name, "@CLASS_CLASS5" );, ;, 1 )
		CAC_LOADOUT_DEFAULT_CLASSES
	}

	// ====================================================================================================
	// reset to default class confirmation ================================================================
	// ====================================================================================================

	#include "ui_mp/popupstyle.inc"	
	#include "ui/choices_setup_popmenu.menu"

	#undef CHOICE_Y_START
	#define CHOICE_Y_START			230
	
	#define LOCAL_ACCEPT_ACTION( pclass, pclass_s, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 )						\
		setDvarFromLocString( dvarString( ui_custom_name ), pclass );													\
		statSetUsingTable( CAC_PRIMARY_GRENADE, tablelookup( "mp/classTable.csv", 1, p0, 5 ) );							\
		statSetUsingTable( CAC_PRIMARY, tablelookup( "mp/classTable.csv", 1, p1, 5 ) );									\
		statSetUsingTable( CAC_PRIMARY_ATTACHMENT, tablelookup( "mp/classTable.csv", 1, p2, 5 ) );						\
		statSetUsingTable( CAC_SECONDARY, tablelookup( "mp/classTable.csv", 1, p3, 5 ) );								\
		statSetUsingTable( CAC_SECONDARY_ATTACHMENT, tablelookup( "mp/classTable.csv", 1, p4, 5 ) );					\
		statSetUsingTable( CAC_SPECIALTY_EQUIPMENT, tablelookup( "mp/classTable.csv", 1, p5, 5 ) );						\
		statSetUsingTable( CAC_SPECIALTY_WEAPON, tablelookup( "mp/classTable.csv", 1, p6, 5 ) );						\
		statSetUsingTable( CAC_SPECIALTY_ABILITY, tablelookup( "mp/classTable.csv", 1, p7, 5 ) );						\
		statSetUsingTable( CAC_SPECIAL_GRENADE, tablelookup( "mp/classTable.csv", 1, p8, 5 ) );							\
		statSetUsingTable( CAC_CAMO, tablelookup( "mp/classTable.csv", 1, p9, 5 ) );									\
		statSetUsingTable( CAC_SPECIALTY_VEHICLE, tablelookup( "mp/classTable.csv", 1, p10, 5 ) );						\
		execNow "updategamerprofile";																					\
		/*execNow "ui_keyboard MENU_CUSTOMCLASS_KEYBOARD "CAC_CUSTOM_NAME;*/											\
		play "mouse_click";																								\
		close "popup_cac_defaultclasswarning"pclass_s;																	\
		close "popup_cac_template"; 																			
			
	#define LOCAL_CANCEL_ACTION( pclass, pclass_s, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 )						\
		play "mouse_click"; 																							\
		close "popup_cac_defaultclasswarning"pclass_s; 	

	// reset to default class confirmation popup menu
	#define RESET_WARNING_POPUP( pclass, pclass_s, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 ) 						\
	menuDef																												\
	{																													\
		CENTER_POPUP_SETUP_ONOPEN( "popup_cac_defaultclasswarning"pclass_s, 2, ;, setfocus choice_no, 1 ) \
		\
		CHOICE_POPMENU_TITLE( "@MENU_RESET_TO_DEFAULT" ) \
		CHOICE_POPMENU_SUBTITLE( "@MENU_CUSTOM_CLASS_RESET_WARNING" ) \
		\
		CHOICE_BUTTON( 1, "@MPUI_YES", LOCAL_ACCEPT_ACTION( pclass, pclass_s, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 ) ) \
		CHOICE_BUTTON_EX( 2, "@MPUI_NO", LOCAL_CANCEL_ACTION( pclass, pclass_s, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 ), name choice_no ) \
	}

	RESET_WARNING_POPUP( "@CLASS_CLASS1", "_assault", 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 305 )
	RESET_WARNING_POPUP( "@CLASS_CLASS2", "_spec_ops", 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 315 )
	RESET_WARNING_POPUP( "@CLASS_CLASS3", "_heavy_gunner", 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 325 )
	RESET_WARNING_POPUP( "@CLASS_CLASS4", "_demolitions", 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 335 )
	RESET_WARNING_POPUP( "@CLASS_CLASS5", "_sniper", 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 345 )



// ===========================================================================================================================
// ===========================================================================================================================
// ===========================================================================================================================
// ===========================================================================================================================

	#undef CHOICE_SIZE_X
	#define CHOICE_SIZE_X			280

	#undef CHOICE_Y_START
	#define CHOICE_Y_START			0
	#undef CHOICE_X_START
	#define CHOICE_X_START			-242
	
	#undef CHOICE_HORIZONTAL_ALIGN
	#define CHOICE_HORIZONTAL_ALIGN	HORIZONTAL_ALIGN_CENTER
	#undef CHOICE_VERTICAL_ALIGN
	#define CHOICE_VERTICAL_ALIGN	VERTICAL_ALIGN_CENTER
	
	#define SIDE_MARGIN		40

	menuDef
	{
		CENTER_POPUP_SETUP( "pc_rename", 5, ;, 1 )
		onOpen { exec "getOldCustomName"; setFocus nameEntry; }
		CHOICE_POPMENU_TITLE( "@MPUI_RENAME_CLASS" )
		itemDef {
			name			nameEntry
			TYPE			ITEM_TYPE_VALIDFILEFIELD
			text			"@MENU_NAME1"
			dvar			"ui_custom_newname"
			rect			60 200 (CHOICE_SIZE_X+24) 22 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
			origin			SIDE_MARGIN -8
			textaligny		2
			maxchars		15
			maxpaintchars	15
			textalign		ITEM_ALIGN_MIDDLE_LEFT
			textfont		UI_FONT_NORMAL
			textscale		TEXTSIZE_DEFAULT
			forecolor		.9 .9 .9 1
			style			WINDOW_STYLE_FILLED
			backcolor		0 0 0 .3
			visible			1
			mouseenter		{ show keyBindStatus; play "mouse_over"; }
			mouseexit		{ hide keyBindStatus; setfocus ok_button; }
			accept			{ exec "setNewCustomName"; close self; }
		}

		CHOICE_DBUTTON_VIS( 1, "@MENU_OK", when( dvarString( ui_custom_newname ) == "" ); )
		CHOICE_BUTTON_VIS_NOHI( 1, "", ;, when( dvarString( ui_custom_newname ) == "" ); )
		CHOICE_BUTTON_VIS( 1, "@MENU_OK", exec "setNewCustomName"; close self;, when( dvarString( ui_custom_newname ) != "" ); )
		
		CHOICE_BUTTON( 2, "@MENU_CANCEL", close self; setDvar ui_custom_newname ""; )
	}

