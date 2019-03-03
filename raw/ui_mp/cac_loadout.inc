#define LOADOUT_WIDTH 			270

#ifndef PC
	#define LOADOUT_IMAGE_X			110
	#define LOADOUT_IMAGE_Y			0

	#define LOADOUT_TITLE_X			20
	#define LOADOUT_TITLE_Y			(LOADOUT_IMAGE_Y + 100)

	#define LOADOUT_DESC_X			(LOADOUT_TITLE_X)
	#define LOADOUT_DESC_Y			(LOADOUT_TITLE_Y + 20)
	#define ORIGIN_LOADOUT			((-(LOADOUT_WIDTH - RIGHTITEM_OFFSET))-10) 38
#else
	#define LOADOUT_IMAGE_X			100
	#define LOADOUT_IMAGE_Y			0

	#define LOADOUT_TITLE_X			30
	#define LOADOUT_TITLE_Y			(LOADOUT_IMAGE_Y + 100)

	#define LOADOUT_DESC_X			(LOADOUT_TITLE_X)
	#define LOADOUT_DESC_Y			(LOADOUT_TITLE_Y + 20)
	#define ORIGIN_LOADOUT			((-(LOADOUT_WIDTH - RIGHTITEM_OFFSET))-10) 75	
#endif

#define RATEBAR_FRAME_BORDER		0//WINDOW_BORDER_SUNKEN
#define RATEBAR_FRAME_BORDERSIZE	2
#define RATEBAR_FRAME_BORDERCOLOR	0.4 0.4 0.425 1

#define RATEBAR_BAR_SHADER			"gradient_fadein"
#define RATEBAR_BAR_COLOR			1 1 1 0.3

#define ATTRIBUTE_BACK_COLOR		0.1804 0.1961 0.2078 0.5
#define ATTRIBUTE_FILL_COLOR		0.2862 0.3098 0.3098 0.8

#define RATE_BAR_WIDTH				98
#define RATE_BAR_HEIGHT				12
	
#define VIS_WHEN_ATTACH_PLUS(pweapon,pattribute) visible when( (STAT_CAC_PRIMARY_ATTACHMENT != 0) && (int(tablelookup("mp/attributesTable.csv",1,pweapon,pattribute)) > 0) )
#define VIS_WHEN_ATTACH_MINUS(pweapon,pattribute) visible when( (STAT_CAC_PRIMARY_ATTACHMENT != 0) && (int(tablelookup("mp/attributesTable.csv",1,pweapon,pattribute)) < 0) ) 

#define VIS_WHEN_ATTACH_PLUS_PREVIEW(pweapon,pattribute,extraArg) visible when( (int(tablelookup("mp/attributesTable.csv",1,pweapon,pattribute)) > 0) && extraArg )
#define VIS_WHEN_ATTACH_MINUS_PREVIEW(pweapon,pattribute,extraArg) visible when( (int(tablelookup("mp/attributesTable.csv",1,pweapon,pattribute)) < 0) && extraArg ) 

#define IS_ONE_PRIME ("specialty_twoprimaries" != tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_WEAPON, 4 ) )
#define IS_TWO_PRIME ("specialty_twoprimaries" == tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_WEAPON, 4 ) )
#define VIS_WHEN_DEFAULT_ONE_PRIME visible when( "specialty_twoprimaries" != tablelookup( "mp/statstable.csv", 1, CAC_DEFAULT_SPECIALTY_WEAPON, 4 ) ) 
#define VIS_WHEN_DEFAULT_TWO_PRIME visible when( "specialty_twoprimaries" == tablelookup( "mp/statstable.csv", 1, CAC_DEFAULT_SPECIALTY_WEAPON , 4 ) )

#define CAC_PRI_ATTACHMENT_SLOT \
	tablelookup( "mp/statsTable.csv", 0, STAT_CAC_PRIMARY, int(STAT_CAC_PRIMARY_ATTACHMENT)+11 )

#define CAC_SEC_ATTACHMENT_SLOT \
	tablelookup( "mp/statsTable.csv", 0, STAT_CAC_SECONDARY, int(STAT_CAC_SECONDARY_ATTACHMENT)+11 )

/* ================================================================================= */
/* ================================ LOADOUT DISPLAY ================================ */
/* ================================================================================= */

	#define LOADOUT_ALIGN 	HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP
	
	#define LOADOUT_PLATING( py, ph, vis_gradient_top, vis_gradient_bottom ) \
			LOADOUT_PLATING_RAW( ORIGIN_LOADOUT, 0, py, (LOADOUT_WIDTH+8), ph, LOADOUT_ALIGN, vis_gradient_top, vis_gradient_bottom )
		
#ifdef PC
	//PREPROC_SHADER_DRAW_ALIGNED( -24 -4 -20 358 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )
#else
	//PREPROC_SHADER_DRAW_ALIGNED( -24 -4 -20 342 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )
#endif
	//PREPROC_SHADER_DRAW_ALIGNED( (LOADOUT_WIDTH+4) -4 20 358 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )

// attributes box ======================

#ifndef HIDE_WEAPON_ATTRIBUTE		

	#define INFO_BOX_ORIENT			0
	#define INFO_BOX_WIDTH			222
	#define INFO_BOX_HEIGHT			126
	#define INFO_BOX_X				(CHOICE_X_START+CHOICE_SIZE_X-INFO_BOX_WIDTH)

	#ifdef PC  
		#define INFO_BOX_Y				320
	#else     
		#define INFO_BOX_Y				285//274
	#endif     
	
	#define ORIGIN_ATTRIBUTE_LABEL	(INFO_BOX_X) (INFO_BOX_Y)//(INFO_BOX_Y+10)

	// meter bar unit dividers
	#define ATTRIBUTE_UNITS( px, py ) \
		PREPROC_SHADER_DRAW_ALIGNED( (px+(RATE_BAR_WIDTH/4)) py 1 3 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 0 RATE_BAR_HEIGHT, "line_vertical", 1 1 1 0.2, 0, 0, 0 0 0 0 ) \
		PREPROC_SHADER_DRAW_ALIGNED( (px+(RATE_BAR_WIDTH/2)) py 1 3 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 0 RATE_BAR_HEIGHT, "line_vertical", 1 1 1 0.2, 0, 0, 0 0 0 0 ) \
		PREPROC_SHADER_DRAW_ALIGNED( (px+((RATE_BAR_WIDTH/4)*3)) py 1 3 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 0 RATE_BAR_HEIGHT, "line_vertical", 1 1 1 0.2, 0, 0, 0 0 0 0 )
		
	// weapon attribut meter bars
	#define ATTRIBUTE_BAR_FORMAT( px, py, pnum ) \
		ATTRIBUTE_UNITS( px, py )\
		PREPROC_SHADER_DRAW_ALIGNED( px py (-(RATE_BAR_WIDTH)) RATE_BAR_HEIGHT CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 0 0, "white", ATTRIBUTE_BACK_COLOR, 0, 0, 0 0 0 0 ) \
		PREPROC_SHADER_DRAW_ADV( px, py, \
		(int(tablelookup("mp/attributestable.csv", 1, tablelookup("mp/statsTable.csv",0,STAT_CAC_PRIMARY,4), pnum ))+ \
		(int(tablelookup("mp/attributestable.csv", 1, tablelookup("mp/statsTable.csv",0,STAT_CAC_PRIMARY,4)+"_"+ \
		CAC_PRI_ATTACHMENT_SLOT, pnum ))))*RATE_BAR_WIDTH/100, RATE_BAR_HEIGHT, \
		"white", ATTRIBUTE_FILL_COLOR, RATEBAR_FRAME_BORDER, RATEBAR_FRAME_BORDERSIZE, RATEBAR_FRAME_BORDERCOLOR rect 0 0 0 0 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP )\
		PREPROC_SHADER_DRAW_ADV( px, py, \
		(int(tablelookup("mp/attributestable.csv", 1, tablelookup("mp/statsTable.csv",0,STAT_CAC_PRIMARY,4), pnum ))+ \
		(int(tablelookup("mp/attributestable.csv", 1, tablelookup("mp/statsTable.csv",0,STAT_CAC_PRIMARY,4)+"_"+ \
		CAC_PRI_ATTACHMENT_SLOT, pnum ))))*RATE_BAR_WIDTH/100, RATE_BAR_HEIGHT, \
		RATEBAR_BAR_SHADER, ATTRIBUTE_BACK_COLOR, RATEBAR_FRAME_BORDER, RATEBAR_FRAME_BORDERSIZE, RATEBAR_FRAME_BORDERCOLOR rect 0 0 0 0 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP ) \
		/* attachment delta bar -*/ \
		PREPROC_SHADER_DRAW_ADV( px+(int(tablelookup("mp/attributestable.csv", 1, tablelookup("mp/statsTable.csv",0,STAT_CAC_PRIMARY,4), pnum )))*RATE_BAR_WIDTH/100+\
		((int(tablelookup("mp/attributestable.csv", 1, tablelookup("mp/statsTable.csv",0,STAT_CAC_PRIMARY,4)+"_"+ \
		CAC_PRI_ATTACHMENT_SLOT, pnum )))*RATE_BAR_WIDTH/100), py, \
		(int(tablelookup("mp/attributestable.csv", 1, tablelookup("mp/statsTable.csv",0,STAT_CAC_PRIMARY,4)+"_"+ \
		CAC_PRI_ATTACHMENT_SLOT, pnum )))*RATE_BAR_WIDTH/100, RATE_BAR_HEIGHT, \
		"white", 0.4 0.15 0.15 1, RATEBAR_FRAME_BORDER, RATEBAR_FRAME_BORDERSIZE, RATEBAR_FRAME_BORDERCOLOR VIS_WHEN_ATTACH_MINUS(tablelookup("mp/statsTable.csv",0,STAT_CAC_PRIMARY,4)+"_"+ \
		CAC_PRI_ATTACHMENT_SLOT,pnum) rect 0 0 0 0 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP )\
		/* attachment delta bar +*/ \
		PREPROC_SHADER_DRAW_ADV( px+(int(tablelookup("mp/attributestable.csv", 1, tablelookup("mp/statsTable.csv",0,STAT_CAC_PRIMARY,4), pnum )))*RATE_BAR_WIDTH/100, py, \
		(int(tablelookup("mp/attributestable.csv", 1, tablelookup("mp/statsTable.csv",0,STAT_CAC_PRIMARY,4)+"_"+ \
		CAC_PRI_ATTACHMENT_SLOT, pnum )))*RATE_BAR_WIDTH/100, RATE_BAR_HEIGHT, \
		"white", 0.3 0.8 0.3 0.5, RATEBAR_FRAME_BORDER, RATEBAR_FRAME_BORDERSIZE, RATEBAR_FRAME_BORDERCOLOR VIS_WHEN_ATTACH_PLUS(tablelookup("mp/statsTable.csv",0,STAT_CAC_PRIMARY,4)+"_"+ \
		CAC_PRI_ATTACHMENT_SLOT,pnum) rect 0 0 0 0 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP )\

	#define PREVIEW_VIS_CONDITION visible when( PREVIEW_VIS_CONDITION_RAW );
	#define PREVIEW_VIS_CONDITION_RAW dvarInt( ui_show_preview )

	#define ATTRIBUTE_BAR_FORMAT_PREVIEW( px, py, pnum ) \
		ATTRIBUTE_UNITS( px, py )\
		PREPROC_SHADER_DRAW_ALIGNED( px py (-(RATE_BAR_WIDTH)) RATE_BAR_HEIGHT CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 0 0, "white", 0 0 0 1, 0, 0, 0 0 0 0 PREVIEW_VIS_CONDITION ) \
		PREPROC_SHADER_DRAW_ADV( px, py, \
		(int(tablelookup("mp/attributestable.csv", 1, dvarString(ui_primary_highlighted), pnum ))+ \
		(int(tablelookup("mp/attributestable.csv", 1, dvarString(ui_primary_highlighted)+"_"+ \
		dvarString(ui_attachment_highlighted), pnum ))))*RATE_BAR_WIDTH/100, RATE_BAR_HEIGHT, \
		"white",ATTRIBUTE_FILL_COLOR, RATEBAR_FRAME_BORDER, RATEBAR_FRAME_BORDERSIZE, RATEBAR_FRAME_BORDERCOLOR rect 0 0 0 0 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP PREVIEW_VIS_CONDITION )\
		PREPROC_SHADER_DRAW_ADV( px, py, \
		(100)*RATE_BAR_WIDTH/100, RATE_BAR_HEIGHT, \
		RATEBAR_BAR_SHADER, ATTRIBUTE_BACK_COLOR, RATEBAR_FRAME_BORDER, RATEBAR_FRAME_BORDERSIZE, RATEBAR_FRAME_BORDERCOLOR rect 0 0 0 0 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP PREVIEW_VIS_CONDITION ) \
		/* attachment delta bar -*/ \
		PREPROC_SHADER_DRAW_ADV( px+(int(tablelookup("mp/attributestable.csv", 1, dvarString(ui_primary_highlighted), pnum )))*RATE_BAR_WIDTH/100+\
		((int(tablelookup("mp/attributestable.csv", 1, dvarString(ui_primary_highlighted)+"_"+ \
		dvarString(ui_attachment_highlighted), pnum )))*RATE_BAR_WIDTH/100), py, \
		(int(tablelookup("mp/attributestable.csv", 1, dvarString(ui_primary_highlighted)+"_"+ \
		dvarString(ui_attachment_highlighted), pnum )))*RATE_BAR_WIDTH/100, RATE_BAR_HEIGHT, \
		"white", 0.4 0.15 0.15 1, RATEBAR_FRAME_BORDER, RATEBAR_FRAME_BORDERSIZE, RATEBAR_FRAME_BORDERCOLOR \
		VIS_WHEN_ATTACH_MINUS_PREVIEW(dvarString(ui_primary_highlighted)+"_"+dvarString(ui_attachment_highlighted),pnum, PREVIEW_VIS_CONDITION_RAW ) \
		rect 0 0 0 0 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP )\
		/* attachment delta bar +*/ \
		PREPROC_SHADER_DRAW_ADV( px+(int(tablelookup("mp/attributestable.csv", 1, dvarString(ui_primary_highlighted), pnum )))*RATE_BAR_WIDTH/100, py, \
		(int(tablelookup("mp/attributestable.csv", 1, dvarString(ui_primary_highlighted)+"_"+ \
		dvarString(ui_attachment_highlighted), pnum )))*RATE_BAR_WIDTH/100, RATE_BAR_HEIGHT, \
		"white", 0.3 0.8 0.3 0.5, RATEBAR_FRAME_BORDER, RATEBAR_FRAME_BORDERSIZE, RATEBAR_FRAME_BORDERCOLOR \
		VIS_WHEN_ATTACH_PLUS_PREVIEW(dvarString(ui_primary_highlighted)+"_"+dvarString(ui_attachment_highlighted),pnum, PREVIEW_VIS_CONDITION_RAW ) \
		rect 0 0 0 0 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP )
		
	#define ATTRIBUTE_BAR_FORMAT_PREVIEW_NA( px, py, pnum ) \
		ATTRIBUTE_UNITS( px, py )\
		PREPROC_SHADER_DRAW_ALIGNED( px py (-(RATE_BAR_WIDTH)) RATE_BAR_HEIGHT CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 0 0, "white", 0 0 0 1, 0, 0, 0 0 0 0 PREVIEW_VIS_CONDITION ) \
		\
		PREPROC_SHADER_DRAW_ADV( px, py, \
		(int(tablelookup("mp/attributestable.csv", 1, dvarString(ui_primary_highlighted), pnum )))*RATE_BAR_WIDTH/100, RATE_BAR_HEIGHT, \
		"white", ATTRIBUTE_FILL_COLOR, RATEBAR_FRAME_BORDER, RATEBAR_FRAME_BORDERSIZE, RATEBAR_FRAME_BORDERCOLOR rect 0 0 0 0 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP PREVIEW_VIS_CONDITION )\
		\
		PREPROC_SHADER_DRAW_ADV( px, py, \
		(100)*RATE_BAR_WIDTH/100, RATE_BAR_HEIGHT, \
		RATEBAR_BAR_SHADER, ATTRIBUTE_BACK_COLOR, RATEBAR_FRAME_BORDER, RATEBAR_FRAME_BORDERSIZE, RATEBAR_FRAME_BORDERCOLOR rect 0 0 0 0 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP PREVIEW_VIS_CONDITION ) \
	
#endif

// ------------------------- RENAME BUTTON ------------------------------
	#ifdef PC
		#define CAC_SETUP_ACTION_RENAME \		
			open "pc_rename";
	#else
		#define CAC_SETUP_ACTION_RENAME \		
			play "mouse_click"; \
			execOnDvarStringValue ui_custom_name customclass1 "ui_keyboard MENU_CUSTOMCLASS_KEYBOARD customclass1"; \
			execOnDvarStringValue ui_custom_name customclass2 "ui_keyboard MENU_CUSTOMCLASS_KEYBOARD customclass2"; \
			execOnDvarStringValue ui_custom_name customclass3 "ui_keyboard MENU_CUSTOMCLASS_KEYBOARD customclass3"; \
			execOnDvarStringValue ui_custom_name customclass4 "ui_keyboard MENU_CUSTOMCLASS_KEYBOARD customclass4"; \
			execOnDvarStringValue ui_custom_name customclass5 "ui_keyboard MENU_CUSTOMCLASS_KEYBOARD customclass5"; \
			execOnDvarStringValue ui_custom_name prestigeclass1 "ui_keyboard MENU_CUSTOMCLASS_KEYBOARD prestigeclass1"; \
			execOnDvarStringValue ui_custom_name prestigeclass2 "ui_keyboard MENU_CUSTOMCLASS_KEYBOARD prestigeclass2"; \
			execOnDvarStringValue ui_custom_name prestigeclass3 "ui_keyboard MENU_CUSTOMCLASS_KEYBOARD prestigeclass3"; \
			execOnDvarStringValue ui_custom_name prestigeclass4 "ui_keyboard MENU_CUSTOMCLASS_KEYBOARD prestigeclass4"; \
			execOnDvarStringValue ui_custom_name prestigeclass5 "ui_keyboard MENU_CUSTOMCLASS_KEYBOARD prestigeclass5";
	#endif		

// ------------------------- RESET BUTTON -------------------------------	
	#define CAC_SETUP_ACTION_RESET \		
		exec "set ui_menu_selection_title @MENU_RESET_TO_DEFAULT"; \
		play "mouse_click"; \
		open "popup_cac_template";			

#ifdef PC
	#define CAC_POPUP_BACK_BUTTON \
		itemDef \
		{ \
			name			back \
			text			"@MENU_BACK" \
			type			1 \
			style			WINDOW_STYLE_FILLED \
			textstyle		ITEM_TEXTSTYLE_SHADOWED \
			rect			-250 -26 40 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM \
			textfont		UI_FONT_NORMAL \
			textalign		ITEM_ALIGN_LEFT \
			textscale		TEXTSIZE_SMALL \
			textaligny		18 \
			visible			1 \
			mouseEnter		{ play "mouse_over"; } \
			action \
			{ \
				play "mouse_click"; \
				close self; \
			}	\
		}
#else
	#define CAC_POPUP_BACK_BUTTON
#endif

	#define CAC_POPUP_SWAP( nameArg, onOpenArg, onCloseArg ) \
			CAC_POPUP_SWAP_VIS( nameArg, onOpenArg, onCloseArg, 1 )

	#define CAC_POPUP_SWAP_VIS( nameArg, onOpenArg, onCloseArg, visArg ) \
		name			nameArg \
		rect			0 0 640 480 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
		focusColor		COLOR_FOCUSED \
		style			WINDOW_STYLE_FILLED \
		popup \
		visible			1 \
		onOpen \
		{ \
			onOpenArg; \
			setdvar ui_show_reset "0"; \
		} \
		onESC \
		{ \
			play "mouse_click"; \
			close self; \
		} \
		onClose { onCloseArg } \
		OVERLAY_BACKGROUND_VIS( 0 ) \
		CHOICE_OVERLAY_TITLE_VIS( dvarString( dvarString( ui_custom_name ) ), when( !menuIsOpen( "cac_main" ) && !menuIsOpen( "changeclass" ) && !menuIsOpen( "changeclass_offline" ) ) ) \
		CHOICE_OVERLAY_SUB_TITLE( dvarstring(ui_menu_selection_title) ) \
		INDIV_COL_GRADIENT_VIS( visArg ) \
		CAC_POPUP_BACK_BUTTON \
		/* RENAME BUTTON ==========================================================*/ \
		itemDef \
		{ \
			rect			90 -4 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_BOTTOM \
			origin			0 0 \
			text			"@PLATFORM_RENAME" \
			textfont		UI_FONT_NORMAL \
			textscale		TEXTSIZE_SMALL \
			textalign		ITEM_ALIGN_BOTTOM_LEFT \
			visible			when( !menuIsOpen( "menu_cac_custom" ) ); \
			decoration \
		} \
		itemDef \
		{ \
			execkeyint		BUTTON_X {CAC_SETUP_ACTION_RENAME} \
			visible			1 \
			decoration \
		}

// perk loadout info display =============
	#ifdef PC
		#define PERK_DESC_TEXTSIZE	0.25
	#else
		#define PERK_DESC_TEXTSIZE 	TEXTSIZE_SMALL
	#endif
	
	#define PERK_IMAGE_X		25//(PERK_TITLE_X+25)
	#define PERK_IMAGE_Y		198//196(g@20) //(PERK_TITLE_Y)//190

	#define PERK_TITLE_X		(PERK_IMAGE_X+35)
	#define PERK_TITLE_Y		(PERK_IMAGE_Y)

	#define PERK_DESC_X			(PERK_TITLE_X-4)
	#define PERK_DESC_Y			(PERK_IMAGE_Y+15)

	#define PERK_Y_OFFSET		38//204//206
	#define GRENADE_Y_OFFSET	24//20(d-176)//21//36

	// perk 1 name -------------
	#define LOCAL_PERK1( ptext, visArg ) \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( PERK_TITLE_X (PERK_TITLE_Y) (LOADOUT_WIDTH-50) 18 LOADOUT_ALIGN, ORIGIN_LOADOUT, ptext, TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW visible when( visArg ); )

#define CAC_LOADOUT_PERKS_GRENADES \
		CAC_LOADOUT_PERKS_GRENADES_VIS( 1 ) 

#define CAC_LOADOUT_PERKS_GRENADES_VIS( visArg ) \
	/* primary grenade name */\
	PREPROC_TEXT_DRAW_ALIGNED_VIS( PERK_TITLE_X (PERK_TITLE_Y-GRENADE_Y_OFFSET+2) (LOADOUT_WIDTH-20) 18 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",0,STAT_CAC_PRIMARY_GRENADE,3), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when( visArg ) ) \
	\
	/* primary grenade icon */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( (PERK_IMAGE_X-19) (PERK_IMAGE_Y-GRENADE_Y_OFFSET) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1, when( visArg ) ) \
	PREPROC_SHADER_DRAW_ALIGNED_VIS( (PERK_IMAGE_X+5) (PERK_IMAGE_Y-GRENADE_Y_OFFSET) 20 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statstable.csv", 0, STAT_CAC_PRIMARY_GRENADE, 6 )+"_cac", 1 1 1 1, 0, 1, 1 1 1 1, when( visArg ) ) \
	\
	/* special grenade name */\
	PREPROC_TEXT_DRAW_ALIGNED_VIS( (PERK_TITLE_X+125) (PERK_TITLE_Y-GRENADE_Y_OFFSET+2) (LOADOUT_WIDTH-20) 18 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv",0,STAT_CAC_SPECIAL_GRENADE,3), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when( visArg ) ) \
	\
	/* special grenade icon */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( (PERK_IMAGE_X+130) (PERK_IMAGE_Y-GRENADE_Y_OFFSET) 20 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statstable.csv", 0, STAT_CAC_SPECIAL_GRENADE, 6 )+"_cac", 1 1 1 1, 0, 1, 1 1 1 1, when( visArg ) ) \
	\
	/* perk loadout info display ============= */\
	\	
	/* perk 1 name ------------- */\
	LOCAL_PERK1( "@" + tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_EQUIPMENT, 3 ), tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_EQUIPMENT, 4 ) != "specialty_specialgrenade" && tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_EQUIPMENT, 4 ) != "specialty_fraggrenade" && visArg )\
	LOCAL_PERK1( "@PERKS_3X_" + tablelookup("mp/statstable.csv",0,STAT_CAC_SPECIAL_GRENADE,3), tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_EQUIPMENT, 4 ) == "specialty_specialgrenade" && visArg )\
	LOCAL_PERK1( "@PERKS_3X_" + tablelookup("mp/statstable.csv",0,STAT_CAC_PRIMARY_GRENADE,3), tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_EQUIPMENT, 4 ) == "specialty_fraggrenade" && visArg )\
	\
	/* perk 1 icon */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( (PERK_IMAGE_X-19) (PERK_IMAGE_Y-4) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1, when( visArg ) ) \
	PREPROC_SHADER_DRAW_ALIGNED_VIS( PERK_IMAGE_X (PERK_IMAGE_Y) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_EQUIPMENT, 6 ), 1 1 1 0.75, 0, 1, 1 1 1 1, when( visArg ) ) \
	\
	/* perk 1 desc */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( PERK_DESC_X (PERK_DESC_Y) 14 14 LOADOUT_ALIGN, ORIGIN_LOADOUT, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1, when( visArg ) ) \
	PREPROC_TEXT_DRAW_ALIGNED_VIS( (PERK_DESC_X+16) (PERK_DESC_Y) (LOADOUT_WIDTH-63) 18 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup("mp/statstable.csv", 1, STAT_CAC_SPECIALTY_EQUIPMENT, 7), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when( visArg ) ) \
	\
	/* perk 2 name ------------- */\
	PREPROC_TEXT_DRAW_ALIGNED_VIS( (PERK_TITLE_X) (PERK_TITLE_Y+PERK_Y_OFFSET) (LOADOUT_WIDTH-50) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_WEAPON, 3 ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW, when( visArg ) )\
	\
	/* perk 2 icon */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( (PERK_IMAGE_X-19) (PERK_IMAGE_Y+PERK_Y_OFFSET-4) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1, when( visArg ) ) \
	PREPROC_SHADER_DRAW_ALIGNED_VIS( PERK_IMAGE_X (PERK_IMAGE_Y+PERK_Y_OFFSET) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_WEAPON, 6 ), 1 1 1 0.75, 0, 1, 1 1 1 1, when( visArg ) ) \
	\
	/* perk 2 desc */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( PERK_DESC_X (PERK_DESC_Y+PERK_Y_OFFSET) 14 14 LOADOUT_ALIGN, ORIGIN_LOADOUT, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1, when( visArg ) ) \
	PREPROC_TEXT_DRAW_ALIGNED_VIS( (PERK_DESC_X+16) (PERK_DESC_Y+PERK_Y_OFFSET) (LOADOUT_WIDTH-63) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup("mp/statstable.csv", 1, STAT_CAC_SPECIALTY_WEAPON, 7), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when( visArg ) )	\
	\
	/* perk 3 name ------------- */\
	PREPROC_TEXT_DRAW_ALIGNED_VIS( PERK_TITLE_X (PERK_TITLE_Y+PERK_Y_OFFSET*2) (LOADOUT_WIDTH-50) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_ABILITY, 3 ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW, when( visArg ) ) \
	\
	/* perk 3 icon */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( (PERK_IMAGE_X-19) (PERK_IMAGE_Y+PERK_Y_OFFSET*2-4) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1, when( visArg ) ) \
	PREPROC_SHADER_DRAW_ALIGNED_VIS( PERK_IMAGE_X (PERK_IMAGE_Y+PERK_Y_OFFSET*2) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_ABILITY, 6 ), 1 1 1 0.75, 0, 1, 1 1 1 1, when( visArg ) ) \
	\
	/* perk 3 desc */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( PERK_DESC_X (PERK_DESC_Y+PERK_Y_OFFSET*2) 14 14 LOADOUT_ALIGN, ORIGIN_LOADOUT, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1, when( visArg ) ) \
	PREPROC_TEXT_DRAW_ALIGNED_VIS( (PERK_DESC_X+16) (PERK_DESC_Y+PERK_Y_OFFSET*2) (LOADOUT_WIDTH-63) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup("mp/statstable.csv", 1, STAT_CAC_SPECIALTY_ABILITY, 7), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when( visArg ) ) \
	\
	/* perk 4 name ------------- */\
	PREPROC_TEXT_DRAW_ALIGNED_VIS( PERK_TITLE_X (PERK_TITLE_Y+PERK_Y_OFFSET*3) (LOADOUT_WIDTH-50) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_VEHICLE, 3 ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW, when( visArg ) ) \
	\
	/* perk 4 icon */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( (PERK_IMAGE_X-19) (PERK_IMAGE_Y+PERK_Y_OFFSET*3-4) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1, when( visArg ) ) \
	PREPROC_SHADER_DRAW_ALIGNED_VIS( PERK_IMAGE_X (PERK_IMAGE_Y+PERK_Y_OFFSET*3) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_VEHICLE, 6 ), 1 1 1 0.75, 0, 1, 1 1 1 1, when( visArg ) ) \
	\
	/* perk 4 desc */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( PERK_DESC_X (PERK_DESC_Y+PERK_Y_OFFSET*3) 14 14 LOADOUT_ALIGN, ORIGIN_LOADOUT, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1, when( visArg ) ) \
	PREPROC_TEXT_DRAW_ALIGNED_VIS( (PERK_DESC_X+16) (PERK_DESC_Y+PERK_Y_OFFSET*3) (LOADOUT_WIDTH-63) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup("mp/statstable.csv", 1, STAT_CAC_SPECIALTY_VEHICLE, 7), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when( visArg ) ) \


#define CAC_LOADOUT_DEFAULT_PERKS_GRENADES \
	/*custom class name*/ \
	CHOICE_OVERLAY_TITLE_VIS( dvarString( dvarString( ui_custom_name ) ), when( !menuIsOpen( "cac_main" ) ) ) \
	/* primary grenade name */\
	PREPROC_TEXT_DRAW_ALIGNED_EXP( PERK_TITLE_X (PERK_TITLE_Y-GRENADE_Y_OFFSET+2) (LOADOUT_WIDTH-20) 18 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/classTable.csv",1,CAC_DEFAULT_PRIMARY_GRENADE,8), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR ) \
	\
	/* primary grenade icon */\
	PREPROC_SHADER_DRAW_ALIGNED( (PERK_IMAGE_X-19) (PERK_IMAGE_Y-GRENADE_Y_OFFSET) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) \
	PREPROC_SHADER_DRAW_ALIGNED( PERK_IMAGE_X (PERK_IMAGE_Y-GRENADE_Y_OFFSET) 20 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_PRIMARY_GRENADE, 7 )+"_cac", 1 1 1 1, 0, 1, 1 1 1 1 ) \
	\
	/* special grenade name */\
	PREPROC_TEXT_DRAW_ALIGNED_EXP( (PERK_TITLE_X+125) (PERK_TITLE_Y-GRENADE_Y_OFFSET+2) (LOADOUT_WIDTH-20) 18 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/classTable.csv",1,CAC_DEFAULT_SPECIAL_GRENADE,8), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR ) \
	\
	/* special grenade icon */\
	PREPROC_SHADER_DRAW_ALIGNED( (PERK_IMAGE_X+115) (PERK_IMAGE_Y-GRENADE_Y_OFFSET) 20 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIAL_GRENADE, 7 )+"_cac", 1 1 1 1, 0, 1, 1 1 1 1 ) \
	\
	/* perk loadout info display ============= */\
	\	
	/* perk 1 name ------------- */\
	LOCAL_PERK1( "@" + tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_EQUIPMENT, 8 ), tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_EQUIPMENT, 4 ) != "specialty_specialgrenade" && tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_EQUIPMENT, 4 ) != "specialty_fraggrenade")\
	LOCAL_PERK1( "@PERKS_3X_" + tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIAL_GRENADE, 8 ), tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_EQUIPMENT, 4 ) == "specialty_specialgrenade" )\
	LOCAL_PERK1( "@PERKS_3X_" + tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_PRIMARY_GRENADE, 8 ), tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_EQUIPMENT, 4 ) == "specialty_fraggrenade" )\
	\
	/* perk 1 icon */\
	PREPROC_SHADER_DRAW_ALIGNED( (PERK_IMAGE_X-19) (PERK_IMAGE_Y-4) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) \
	PREPROC_SHADER_DRAW_ALIGNED( PERK_IMAGE_X (PERK_IMAGE_Y) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_EQUIPMENT, 7 ), 1 1 1 0.75, 0, 1, 1 1 1 1) \
	\
	/* perk 1 desc */\
	PREPROC_SHADER_DRAW_ALIGNED( PERK_DESC_X (PERK_DESC_Y) 14 14 LOADOUT_ALIGN, ORIGIN_LOADOUT, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1) \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( (PERK_DESC_X+16) (PERK_DESC_Y) (LOADOUT_WIDTH-63) 18 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" +  tablelookup("mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_EQUIPMENT, 9 ), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )		\
	\
	/* perk 2 name ------------- */\
	PREPROC_TEXT_DRAW_ALIGNED_EXP( (PERK_TITLE_X) (PERK_TITLE_Y+PERK_Y_OFFSET) (LOADOUT_WIDTH-50) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_WEAPON, 8 ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW )\
	\
	/* perk 2 icon */\
	PREPROC_SHADER_DRAW_ALIGNED( (PERK_IMAGE_X-19) (PERK_IMAGE_Y+PERK_Y_OFFSET-4) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) \
	PREPROC_SHADER_DRAW_ALIGNED( PERK_IMAGE_X (PERK_IMAGE_Y+PERK_Y_OFFSET) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_WEAPON, 7 ), 1 1 1 0.75, 0, 1, 1 1 1 1) \
	\
	/* perk 2 desc */\
	PREPROC_SHADER_DRAW_ALIGNED( PERK_DESC_X (PERK_DESC_Y+PERK_Y_OFFSET) 14 14 LOADOUT_ALIGN, ORIGIN_LOADOUT, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1) \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( (PERK_DESC_X+16) (PERK_DESC_Y+PERK_Y_OFFSET) (LOADOUT_WIDTH-63) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup("mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_WEAPON, 9 ), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )		\
	\
	/* perk 3 name ------------- */\
	PREPROC_TEXT_DRAW_ALIGNED_EXP( PERK_TITLE_X (PERK_TITLE_Y+PERK_Y_OFFSET*2) (LOADOUT_WIDTH-50) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_ABILITY, 8 ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW )\
	\
	/* perk 3 icon */\
	PREPROC_SHADER_DRAW_ALIGNED( (PERK_IMAGE_X-19) (PERK_IMAGE_Y+PERK_Y_OFFSET*2-4) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) \
	PREPROC_SHADER_DRAW_ALIGNED( PERK_IMAGE_X (PERK_IMAGE_Y+PERK_Y_OFFSET*2) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_ABILITY, 7 ), 1 1 1 0.75, 0, 1, 1 1 1 1) \
	\
	/* perk 3 desc */\
	PREPROC_SHADER_DRAW_ALIGNED( PERK_DESC_X (PERK_DESC_Y+PERK_Y_OFFSET*2) 14 14 LOADOUT_ALIGN, ORIGIN_LOADOUT, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1) \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( (PERK_DESC_X+16) (PERK_DESC_Y+PERK_Y_OFFSET*2) (LOADOUT_WIDTH-63) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup("mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_ABILITY, 9), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )		\
	\
	/* perk 4 name ------------- */\
	PREPROC_TEXT_DRAW_ALIGNED_EXP( PERK_TITLE_X (PERK_TITLE_Y+PERK_Y_OFFSET*3) (LOADOUT_WIDTH-50) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_VEHICLE, 8 ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW )\
	\
	/* perk 4 icon */\
	PREPROC_SHADER_DRAW_ALIGNED( (PERK_IMAGE_X-19) (PERK_IMAGE_Y+PERK_Y_OFFSET*3-4) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) \
	PREPROC_SHADER_DRAW_ALIGNED( PERK_IMAGE_X (PERK_IMAGE_Y+PERK_Y_OFFSET*3) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_VEHICLE, 7 ), 1 1 1 0.75, 0, 1, 1 1 1 1) \
	\
	/* perk 4 desc */\
	PREPROC_SHADER_DRAW_ALIGNED( PERK_DESC_X (PERK_DESC_Y+PERK_Y_OFFSET*3) 14 14 LOADOUT_ALIGN, ORIGIN_LOADOUT, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1) \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( (PERK_DESC_X+16) (PERK_DESC_Y+PERK_Y_OFFSET*3) (LOADOUT_WIDTH-63) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup("mp/classTable.csv", 1, CAC_DEFAULT_SPECIALTY_VEHICLE, 9), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )		\



#define CAC_LOADOUT_ATTRIBUTES \
	/* primary weapon attributes title */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( ORIGIN_ATTRIBUTE_LABEL INFO_BOX_WIDTH 25 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, -2 -20, "@MENU_PRIMARY_ATTRIBUTES", TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_RIGHT, COLOR_TITLE ) \
	/* drawing attributes */ \
	PREPROC_TEXT_DRAW_ALIGNED( ORIGIN_ATTRIBUTE_LABEL INFO_BOX_WIDTH 20 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, -42 2, text "@MENU_ACCURACY1", TEXTSIZE_SMALL, -68, 16, ITEM_ALIGN_RIGHT, COLOR_BODY_TEXT name accuracy) \
	PREPROC_TEXT_DRAW_ALIGNED( ORIGIN_ATTRIBUTE_LABEL INFO_BOX_WIDTH 20 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, -42 20, text "@MENU_DAMAGE", TEXTSIZE_SMALL, -68, 16, ITEM_ALIGN_RIGHT, COLOR_BODY_TEXT name damage) \
	PREPROC_TEXT_DRAW_ALIGNED( ORIGIN_ATTRIBUTE_LABEL INFO_BOX_WIDTH 20 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, -42 38, text "@MENU_RANGE", TEXTSIZE_SMALL, -68, 16, ITEM_ALIGN_RIGHT, COLOR_BODY_TEXT name range) \
	PREPROC_TEXT_DRAW_ALIGNED( ORIGIN_ATTRIBUTE_LABEL INFO_BOX_WIDTH 20 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, -42 56, text "@MENU_FIRE_RATE", TEXTSIZE_SMALL, -68, 16, ITEM_ALIGN_RIGHT, COLOR_BODY_TEXT name fire_rate) \
	PREPROC_TEXT_DRAW_ALIGNED( ORIGIN_ATTRIBUTE_LABEL INFO_BOX_WIDTH 20 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, -42 74, text "@MENU_MOBILITY", TEXTSIZE_SMALL, -68, 16, ITEM_ALIGN_RIGHT, COLOR_BODY_TEXT name mobility) \
	\
	ATTRIBUTE_BAR_FORMAT( (INFO_BOX_X+118), (INFO_BOX_Y+6), 2 ) \
	ATTRIBUTE_BAR_FORMAT( (INFO_BOX_X+118), (INFO_BOX_Y+24), 3 ) \
	ATTRIBUTE_BAR_FORMAT( (INFO_BOX_X+118), (INFO_BOX_Y+42), 4 ) \
	ATTRIBUTE_BAR_FORMAT( (INFO_BOX_X+118), (INFO_BOX_Y+60), 5 ) \
	ATTRIBUTE_BAR_FORMAT( (INFO_BOX_X+118), (INFO_BOX_Y+78), 6 ) \

#define CAC_LOADOUT_ATTRIBUTES_PREVIEW \
	ATTRIBUTE_BAR_FORMAT_PREVIEW( (INFO_BOX_X+118), (INFO_BOX_Y+6), 2 ) \
	ATTRIBUTE_BAR_FORMAT_PREVIEW( (INFO_BOX_X+118), (INFO_BOX_Y+24), 3 ) \
	ATTRIBUTE_BAR_FORMAT_PREVIEW( (INFO_BOX_X+118), (INFO_BOX_Y+42), 4 ) \
	ATTRIBUTE_BAR_FORMAT_PREVIEW( (INFO_BOX_X+118), (INFO_BOX_Y+60), 5 ) \
	ATTRIBUTE_BAR_FORMAT_PREVIEW( (INFO_BOX_X+118), (INFO_BOX_Y+78), 6 )

#define CAC_LOADOUT_ATTRIBUTES_PREVIEW_NA \
	ATTRIBUTE_BAR_FORMAT_PREVIEW_NA( (INFO_BOX_X+118), (INFO_BOX_Y+6), 2 ) \
	ATTRIBUTE_BAR_FORMAT_PREVIEW_NA( (INFO_BOX_X+118), (INFO_BOX_Y+24), 3 ) \
	ATTRIBUTE_BAR_FORMAT_PREVIEW_NA( (INFO_BOX_X+118), (INFO_BOX_Y+42), 4 ) \
	ATTRIBUTE_BAR_FORMAT_PREVIEW_NA( (INFO_BOX_X+118), (INFO_BOX_Y+60), 5 ) \
	ATTRIBUTE_BAR_FORMAT_PREVIEW_NA( (INFO_BOX_X+118), (INFO_BOX_Y+78), 6 )

//SPEICAL LOADOUT SCREENS FOR CREATE A CLASS MENUS
#define CAC_LOADOUT_CAC_TITLE1 \
	/*custom class name*/ \
	CHOICE_OVERLAY_TITLE_VIS( dvarString( dvarString( ui_custom_name ) ), when( !menuIsOpen( "cac_main" ) && !menuIsOpen( "changeclass" ) && !menuIsOpen( "changeclass_offline" ) ) )

#define CAC_LOADOUT_CAC_TITLE2 \
	/*custom class name*/ \
	CHOICE_OVERLAY_TITLE_VIS( dvarString( dvarString( ui_custom_name ) ), when( !menuIsOpen( "cac_main" ) && !menuIsOpen( "changeclass" ) && !menuIsOpen( "changeclass_offline" ) ) )



#define WEAPON_TITLE_X		-5
#define WEAPON_TITLE_Y		-10

#define WEAPON_IMAGE_X		130//90//74
#define WEAPON_IMAGE_Y		(WEAPON_TITLE_Y+20)

#define ATTACHMENT_TITLE_X	10
#define ATTACHMENT_TITLE_Y	(WEAPON_TITLE_Y+72)//64

#define ATTACHMENT_IMAGE_X	30
#define ATTACHMENT_IMAGE_Y	(WEAPON_IMAGE_Y)//32

#define SECONDARY_OFFSET_Y	92

#define CAC_LOADOUT_NORMAL \
		CAC_LOADOUT_NORMAL_VIS( 1 )

#define CAC_LOADOUT_NORMAL_VIS( visArg ) \
	INDIV_COL_GRADIENT_VIS( 0 ) \
	/*primary weapon camo =====================*/ \
	PREPROC_SHADER_DRAW_ALIGNED_VIS( 0 (16-20) ((LOADOUT_WIDTH+8)/4) 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 11, STAT_CAC_CAMO, 6 ), 1 1 1 0.8, 0, 1, 1 1 1 1, when( visArg ); ) \
	PREPROC_SHADER_DRAW_ALIGNED_VIS( (((LOADOUT_WIDTH+8)/4)) (16-20) ((LOADOUT_WIDTH+8)/4) 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 11, STAT_CAC_CAMO, 6 ), 1 1 1 0.8, 0, 1, 1 1 1 1, when( visArg ); ) \
	PREPROC_SHADER_DRAW_ALIGNED_VIS( (((LOADOUT_WIDTH+8)/2)) (16-20) ((LOADOUT_WIDTH+8)/4) 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 11, STAT_CAC_CAMO, 6 ), 1 1 1 0.8, 0, 1, 1 1 1 1, when( visArg ); ) \
	PREPROC_SHADER_DRAW_ALIGNED_VIS( ((((LOADOUT_WIDTH+8)/4)*3)) (16-20) ((LOADOUT_WIDTH+8)/4) 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 11, STAT_CAC_CAMO, 6 ), 1 1 1 0.8, 0, 1, 1 1 1 1, when( visArg ); ) \
	\
	/*weapon loadout info display =============*/ \
	\
	/* primary weapon name */ \
	PREPROC_TEXT_DRAW_ALIGNED_VIS( WEAPON_TITLE_X WEAPON_TITLE_Y (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv", 0, STAT_CAC_PRIMARY, 3), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_RIGHT, COLOR_INFO_YELLOW, when( visArg ); )\
	/* primary weapon attachment name */\
	PREPROC_TEXT_DRAW_ALIGNED_VIS( ATTACHMENT_TITLE_X ATTACHMENT_TITLE_Y (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statsTable.csv",0,STAT_CAC_PRIMARY,3)+"_"+tablelookup("mp/attachmentTable.csv",4,CAC_PRI_ATTACHMENT_SLOT,7), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when( visArg ); )\
	/* primary weapon image */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( WEAPON_IMAGE_X WEAPON_IMAGE_Y 140 70 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statstable.csv", 0, STAT_CAC_PRIMARY, 6 ), 1 1 1 1, 0, 1, 1 1 1 1, when( visArg ); ) \
	/* primary weapon attachment image */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( ATTACHMENT_IMAGE_X ATTACHMENT_IMAGE_Y 48 48 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 4, CAC_PRI_ATTACHMENT_SLOT, 6 ), 1 1 1 1, 0, 1, 1 1 1 1, when( visArg ); ) \
	\
	/* second weapon name */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( (WEAPON_TITLE_X+11) (WEAPON_TITLE_Y+SECONDARY_OFFSET_Y) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1, when( visArg ); ) \
	PREPROC_TEXT_DRAW_ALIGNED_VIS( WEAPON_TITLE_X (WEAPON_TITLE_Y+SECONDARY_OFFSET_Y) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup("mp/statstable.csv", 0, STAT_CAC_SECONDARY, 3), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_RIGHT, COLOR_INFO_YELLOW, when( visArg ); )\
	/* second weapon attachment name */\
	PREPROC_TEXT_DRAW_ALIGNED_VIS( ATTACHMENT_TITLE_X (ATTACHMENT_TITLE_Y+SECONDARY_OFFSET_Y) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statsTable.csv",0,STAT_CAC_SECONDARY,3)+"_"+tablelookup("mp/attachmentTable.csv",4,CAC_SEC_ATTACHMENT_SLOT,7), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when( visArg ); )\
	/* second weapon image */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( WEAPON_IMAGE_X (WEAPON_IMAGE_Y+SECONDARY_OFFSET_Y) 140 70 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statstable.csv", 0, STAT_CAC_SECONDARY, 6 ), 1 1 1 1, 0, 1, 1 1 1 1, when( IS_TWO_PRIME && visArg ); ) \
	PREPROC_SHADER_DRAW_ALIGNED_VIS( (WEAPON_IMAGE_X+60) (WEAPON_IMAGE_Y+SECONDARY_OFFSET_Y-5) 80 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statstable.csv", 0, STAT_CAC_SECONDARY, 6 ), 1 1 1 1, 0, 1, 1 1 1 1, when( IS_ONE_PRIME && visArg ); ) \
	/* second weapon attachment image */\
	PREPROC_SHADER_DRAW_ALIGNED_VIS( ATTACHMENT_IMAGE_X (ATTACHMENT_IMAGE_Y+SECONDARY_OFFSET_Y) 48 48 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 4, CAC_SEC_ATTACHMENT_SLOT, 6 ), 1 1 1 1, 0, 1, 1 1 1 1, when( visArg ); )	\
	\
	/* perk loadout info display ============= */\
	CAC_LOADOUT_PERKS_GRENADES_VIS( visArg )

//SPEICAL LOADOUT SCREENS FOR CREATE A CLASS DEFAULT MENUS
#define CAC_LOADOUT_DEFAULT_CLASSES \
	/*primary weapon camo =====================*/ \
	PREPROC_SHADER_DRAW_ALIGNED( -4 (16-20) ((LOADOUT_WIDTH+8)/4) 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_CAMO, 7 ), 1 1 1 0.8, 0, 1, 1 1 1 1) \
	PREPROC_SHADER_DRAW_ALIGNED( (((LOADOUT_WIDTH+8)/4)-4) (16-20) ((LOADOUT_WIDTH+8)/4) 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_CAMO, 7 ), 1 1 1 0.8, 0, 1, 1 1 1 1) \
	PREPROC_SHADER_DRAW_ALIGNED( (((LOADOUT_WIDTH+8)/2)-4) (16-20) ((LOADOUT_WIDTH+8)/4) 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_CAMO, 7 ), 1 1 1 0.8, 0, 1, 1 1 1 1) \
	PREPROC_SHADER_DRAW_ALIGNED( ((((LOADOUT_WIDTH+8)/4)*3)-4) (16-20) ((LOADOUT_WIDTH+8)/4) 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_CAMO, 7 ), 1 1 1 0.8, 0, 1, 1 1 1 1) \
	\
	/*weapon loadout info display =============*/ \
	\
	/* primary weapon name */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( WEAPON_TITLE_X WEAPON_TITLE_Y (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/classTable.csv", 1, CAC_DEFAULT_PRIMARY, 8), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_RIGHT, COLOR_INFO_YELLOW )\
	/* primary weapon attachment name */\
	PREPROC_TEXT_DRAW_ALIGNED_EXP( ATTACHMENT_TITLE_X ATTACHMENT_TITLE_Y (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT,  "@"+tablelookup("mp/classTable.csv", 1, CAC_DEFAULT_PRIMARY, 8)+"_"+tablelookup("mp/classTable.csv",1 , CAC_DEFAULT_PRIMARY_ATTACHMENT, 8), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )\
	/* primary weapon image */\
	PREPROC_SHADER_DRAW_ALIGNED( WEAPON_IMAGE_X WEAPON_IMAGE_Y 140 70 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_PRIMARY, 7 ), 1 1 1 1, 0, 1, 1 1 1 1) \
	/* primary weapon attachment image */\
	PREPROC_SHADER_DRAW_ALIGNED( ATTACHMENT_IMAGE_X ATTACHMENT_IMAGE_Y 48 48 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_PRIMARY_ATTACHMENT, 7 ), 1 1 1 1, 0, 1, 1 1 1 1) 	\
	\
	/* second weapon name */\
	PREPROC_SHADER_DRAW_ALIGNED( (WEAPON_TITLE_X+11) (WEAPON_TITLE_Y+SECONDARY_OFFSET_Y) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( WEAPON_TITLE_X (WEAPON_TITLE_Y+SECONDARY_OFFSET_Y) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/classTable.csv", 1, CAC_DEFAULT_SECONDARY, 8), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_RIGHT, COLOR_INFO_YELLOW )\
	/* second weapon attachment name */\
	PREPROC_TEXT_DRAW_ALIGNED_EXP( ATTACHMENT_TITLE_X (ATTACHMENT_TITLE_Y+SECONDARY_OFFSET_Y) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/classTable.csv", 1, CAC_DEFAULT_SECONDARY_ATTACHMENT, 8), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )\
	/* second weapon image */\
	PREPROC_SHADER_DRAW_ALIGNED( WEAPON_IMAGE_X (WEAPON_IMAGE_Y+SECONDARY_OFFSET_Y) 140 70 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SECONDARY, 7 ), 1 1 1 1, 0, 1, 1 1 1 1 VIS_WHEN_DEFAULT_TWO_PRIME ) \
	PREPROC_SHADER_DRAW_ALIGNED( (WEAPON_IMAGE_X+60) (WEAPON_IMAGE_Y+SECONDARY_OFFSET_Y-5) 80 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SECONDARY, 7 ), 1 1 1 1, 0, 1, 1 1 1 1 VIS_WHEN_DEFAULT_ONE_PRIME ) \
	/* second weapon attachment image */\
	PREPROC_SHADER_DRAW_ALIGNED( ATTACHMENT_IMAGE_X (ATTACHMENT_IMAGE_Y+SECONDARY_OFFSET_Y) 48 48 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/classTable.csv", 1, CAC_DEFAULT_SECONDARY_ATTACHMENT, 7 ), 1 1 1 1, 0, 1, 1 1 1 1) 	\
	\
	/* perk loadout info display ============= */\
	CAC_LOADOUT_DEFAULT_PERKS_GRENADES

#define LOCKED_CLASS \
		LOCKED_CLASS_VIS( 1 )

#ifdef CONSOLE
#define	LOCKED_CLASS_Y	137
#else
#define	LOCKED_CLASS_Y	171
#endif

#define LOCKED_CLASS_VIS( visArg ) \
		itemDef \
		{ \
			style			WINDOW_STYLE_SHADER \
			rect			-274 LOCKED_CLASS_Y 342 1 HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP \
			background		"menu_white_line_faded" \
			forecolor		1 1 1 0.1 \
			visible			visArg \
			decoration \
		} \
		/* image*/ \
		PREPROC_SHADER_DRAW_ALIGNED_VIS( LOADOUT_IMAGE_X  LOADOUT_IMAGE_Y 90 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, "specialty_locked_big", 1 1 1 0.75, 0, 0, 0.2 0.2 0.225 1, visArg ) \
		/* title*/\
		PREPROC_TEXT_DRAW_ALIGNED_VIS( LOADOUT_TITLE_X LOADOUT_TITLE_Y (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, dvarString( ui_custom_name ), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_INFO_YELLOW, visArg ) \
		/* perk desc unlocked*/\
		PREPROC_TEXT_DRAW_ALIGNED_VIS( LOADOUT_DESC_X LOADOUT_DESC_Y (LOADOUT_WIDTH-30) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, dvarString( ui_prestige_unlock_desc ), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, visArg )

