#define ORIGIN_COLUMN_RANK_X 0
#define ORIGIN_COLUMN_NAME_X 32
#define ORIGIN_COLUMN_SCORE_X 225//236
#define COLUMN_RANK_WIDTH 36
#define COLUMN_NAME_WIDTH 256
#define COLUMN_SCORE_WIDTH 34
#define BACKGROUND_TEXTURE_COLOR 0 0 0 0.7

#define LIST_BOX_WIDTH		278
#define LIST_BOX_HEIGHT		334//326
#define LIST_BOX_SIZE 		LIST_BOX_WIDTH LIST_BOX_HEIGHT

#define COLUMN_HEADER_COLOR 0.6 0.6 0.6 1

#ifndef PLAYERLIST_SELECTED_ACTIONS
	#define PLAYERLIST_SELECTED_ACTIONS ;
#endif

#ifndef PLAYERLIST_SCOREVIS
	#define PLAYERLIST_SCOREVIS ((!dvarbool( party_timerVisible ) || !dvarbool( party_teambased ) || !dvarbool( party_autoteams )) && !dvarInt( splitscreen ))
#endif

#ifdef PARTY_THEME
	#define PLATING_COLOR		0.3 0.225 0.2 1
	#define HL_COLOR			1 0.85 0.825 0.2
	#define PARTY_LABEL_COLOR	1 0.925 0.7 0.07
	#define PARTY_LABEL_SCALE	1.75
#else
	#define PLATING_COLOR		0.175 0.2 0.25 1
	#define HL_COLOR			0.85 0.85 0.925 0.2
	#define PARTY_LABEL_COLOR	0.9 0.925 1 0.07
	#define PARTY_LABEL_SCALE	1.75
#endif

#ifdef SPLITSCREEN_PLAYERLIST

	#undef PLATING_COLOR		
	#undef HL_COLOR			
	#undef PARTY_LABEL_COLOR	
	#undef PARTY_LABEL			
	#undef PARTY_LABEL_SCALE	
	#define PLATING_COLOR		0.2 0.2 0.225 1
	#define HL_COLOR			0.85 0.85 0.925 0.2
	#define PARTY_LABEL_COLOR	0.9 0.925 1 0.07
	#define PARTY_LABEL			""
	#define PARTY_LABEL_SCALE	1.75
	
	#ifndef PS3
		#undef	LIST_BOX_HEIGHT
		#define LIST_BOX_HEIGHT		149
	#else
		#undef	LIST_BOX_HEIGHT
		#define LIST_BOX_HEIGHT		310
	#endif
#endif

#ifdef XENON

#define PLAYERLIST_PLAYERFEEDER( feederName, feederArg, yOffsetArg, heightArg, disableColorArg, backColorArg, actionsArg, visArg ) \	
	itemDef	{ \
		name			feederName \
		feeder			feederArg \
		type			ITEM_TYPE_LISTBOX \
		rect			(ORIGIN_COLUMN_NAME_X-COLUMN_RANK_WIDTH) yOffsetArg (COLUMN_NAME_WIDTH+COLUMN_RANK_WIDTH) heightArg RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP \
		origin			ORIGIN_PLAYERLIST \
		elementwidth	COLUMN_NAME_WIDTH \
		elementheight	18 \
		textfont		UI_FONT_SMALL \
		textscale		FONTSCALE_LOBBY \
		textalignx		COLUMN_RANK_WIDTH \
		textaligny		-1 \
		forecolor		CHOICE_TEXTCOLOR \
		focusColor		1 1 1 1 \
		disableColor	disableColorArg \
		outlinecolor	1 0.97 0.72 0.5 \
		highlightTexture	"menu_button_backing_highlight" \
		selectBorder	0.8 0.95 1 0 \
		backcolor		backColorArg \
		backgroundItemListbox	"menu_lobby_strip_whole" \
		visible			when( visArg ) \
		columns			1		6		(PLAYERLIST_WIDTH-COLUMN_NAME_WIDTH) 40			0 \
		noscrollbars \
		actionsArg \
		onFocus	{ \
			play "mouse_over"; \
			hide selection_left; \
			show selection_right; \
		} \
		dvarTest		ui_selectlobby \
		enableDvar		{ "1" } \
	}
#else // #ifdef XENON

#define PLAYERLIST_PLAYERFEEDER( feederName, feederArg, yOffsetArg, heightArg, disableColorArg, backColorArg, actionsArg, visArg ) \	
	itemDef	{ \
		name			feederName \
		feeder			feederArg \
		type			ITEM_TYPE_LISTBOX \
		rect			(ORIGIN_COLUMN_NAME_X-COLUMN_RANK_WIDTH) yOffsetArg (COLUMN_NAME_WIDTH+COLUMN_RANK_WIDTH) heightArg RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP \
		origin			ORIGIN_PLAYERLIST \
		elementwidth	COLUMN_NAME_WIDTH \
		elementheight	18 \
		textfont		UI_FONT_SMALL \
		textscale		FONTSCALE_LOBBY \
		textalignx		COLUMN_RANK_WIDTH \
		textaligny		-1 \
		forecolor		CHOICE_TEXTCOLOR \
		focusColor		1 1 1 1 \
		disableColor	disableColorArg \
		outlinecolor	1 0.97 0.72 0.5 \
		highlightTexture	"menu_button_backing_highlight" \
		selectBorder	0.8 0.95 1 0 \
		backcolor		backColorArg \
		backgroundItemListbox	"menu_lobby_strip_whole" \
		visible			when( visArg ) \
		columns			1		6		(PLAYERLIST_WIDTH-COLUMN_NAME_WIDTH) 40			0 \
		noscrollbars \
		actionsArg \
		onFocus	{ \
			hide selection_left; \
			show selection_right; \
		} \
		dvarTest		ui_selectlobby \
		enableDvar		{ "1" } \
	}
#endif // #else #ifdef XENON
	


#define PLAYERLIST_SCOREFEEDER( feederArg, yOffsetArg, heightArg, visArg ) \	
	itemDef { \
		feeder			feederArg \
		type			ITEM_TYPE_LISTBOX \
		rect			(ORIGIN_COLUMN_SCORE_X+10) yOffsetArg COLUMN_SCORE_WIDTH heightArg RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP \
		origin			ORIGIN_PLAYERLIST \
		elementwidth	COLUMN_SCORE_WIDTH \
		elementheight	18 \
		textfont		UI_FONT_SMALL \
		textscale		FONTSCALE_LOBBY \
		textaligny		-1 \
		forecolor		1 1 1 0.65 \	
		focusColor		1 1 1 0.65 \
		disableColor	1 1 1 0.65 \
		noscrollbars \
		columns			1		-4		COLUMN_SCORE_WIDTH		5		ITEM_ALIGN_RIGHT \
		visible 		when( visArg ) \
		decoration \
		onFocus	{ \
			hide selection_left; \
			show selection_right; \
		} \
	}

#define PLAYERLIST_TALKFEEDER( feederArg, yOffsetArg, heightArg, visArg ) \	
	itemDef	{ \
		feeder			feederArg \
		type			ITEM_TYPE_LISTBOX \
		rect			-20 (yOffsetArg+1) 20 heightArg RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP \
		origin			ORIGIN_PLAYERLIST \
		elementwidth	18 \
		elementheight	18 \
		forecolor		1 1 1 1 \
		focusColor		1 1 1 1 \
		disableColor	1 1 1 1 \
		visible			when( visArg ) \
		noscrollbars \
		decoration \
		onFocus	{ \
			hide selection_left; \
			show selection_right; \
		} \
	}
#define PLAYERLIST_RANKFEEDER( feederArg, yOffsetArg, heightArg, visArg ) \
	itemDef	{ \
		feeder			feederArg \
		type			ITEM_TYPE_LISTBOX \
		rect			ORIGIN_COLUMN_RANK_X yOffsetArg 36 heightArg RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP \
		origin			ORIGIN_PLAYERLIST \
		elementwidth	18 \
		elementheight	18 \
		textfont		UI_FONT_SMALL \
		textscale		FONTSCALE_LOBBY \
		textstyle 		ITEM_TEXTSTYLE_SHADOWED \
		textaligny		-1 \
		textalignx		0 \
		forecolor		1 1 1 1 \
		focusColor		1 1 1 1 \
		disableColor	1 1 1 1 \
		noscrollbars \
		columns	2		18		18		3		ITEM_ALIGN_LEFT \
						0		18		2		ITEM_ALIGN_LEFT \				
		visible			when( visArg ) \
		decoration \
		onFocus	{ \
			hide selection_left; \
			show selection_right; \
		} \
	}

#define PLAYERLIST_SQUADFEEDER( feederArg, yOffsetArg, heightArg, visArg ) \	
	itemDef	{ \
		feeder			feederArg \
		type			ITEM_TYPE_LISTBOX \
		rect			230 yOffsetArg 18 heightArg RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP \
		origin			ORIGIN_PLAYERLIST \
		elementwidth	18 \
		elementheight	18 \
		forecolor		1 1 1 1 \
		focusColor		1 1 1 1 \
		disableColor	1 1 1 1 \
		visible			when( visArg ) \
		noscrollbars \
		decoration \
		onFocus	{ \
			hide selection_left; \
			show selection_right; \
		} \
	}
					
	// UI art
	// lobby title bar
	PREPROC_SHADER_DRAW_ALIGNED( -2 -6 (COLUMN_NAME_WIDTH+16) 16 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERLIST, "menu_lobby_title_strip", 0.8 0.8 0.8 0.4, 0, 0, 0 0 0 0 )
#ifdef SPLITSCREEN_PLAYERLIST
	PREPROC_SHADER_DRAW_ALIGNED( -22 -8 -20 (326+30) RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERLIST, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )
	PREPROC_SHADER_DRAW_ALIGNED( 270 -8 20 (326+30) RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERLIST, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )

	#ifdef PS3
		PREPROC_SHADER_DRAW_ALIGNED( -2 (LIST_BOX_HEIGHT/2+6) (COLUMN_NAME_WIDTH+16) 16 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERLIST, "white", PLATING_COLOR, 0, 0, 0 0 0 0 )
		PREPROC_SHADER_DRAW_ALIGNED( -2 (LIST_BOX_HEIGHT/2+6) (COLUMN_NAME_WIDTH+16) 16 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERLIST, "line_horizontal", 0.9 0.9 0.95 0.5, 0, 0, 0 0 0 0 )
	#else
		PREPROC_SHADER_DRAW_ALIGNED( -2 (LIST_BOX_HEIGHT+12) (COLUMN_NAME_WIDTH+16) 16 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERLIST, "white", PLATING_COLOR, 0, 0, 0 0 0 0 )
		PREPROC_SHADER_DRAW_ALIGNED( -2 (LIST_BOX_HEIGHT+12) (COLUMN_NAME_WIDTH+16) 16 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERLIST, "line_horizontal", 0.9 0.9 0.95 0.5, 0, 0, 0 0 0 0 )
	#endif //#ifdef PS3

#endif	
		

	#ifndef SPLITSCREEN_PLAYERLIST
		itemDef
		{
			type			ITEM_TYPE_TEXT
			visible			1
			rect			ORIGIN_COLUMN_RANK_X -2 0 0 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
			origin			ORIGIN_PLAYERLIST
			text			"@MPUI_RANK"
			align			ITEM_ALIGN_LEFT
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textaligny 		12
			forecolor		COLUMN_HEADER_COLOR
			visible 		1
			decoration
		}
	
		itemDef
		{
			type			ITEM_TYPE_TEXT
			rect			ORIGIN_COLUMN_NAME_X -2 0 0 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
			origin			ORIGIN_PLAYERLIST
			text			"@MPUI_NAME"
			align			ITEM_ALIGN_LEFT
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textalignx		6
			textaligny 		12
			forecolor		COLUMN_HEADER_COLOR
			visible 		1
			decoration
		}		
		itemDef
		{
			type			ITEM_TYPE_TEXT
			rect			ORIGIN_COLUMN_SCORE_X -2 30 0 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
			origin			ORIGIN_PLAYERLIST
			text			"@MPUI_SCORE"
			align			ITEM_ALIGN_RIGHT
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textaligny 		12
			forecolor		COLUMN_HEADER_COLOR
			visible 		when( PLAYERLIST_SCOREVIS )
			decoration
		}
	#else
		itemDef
		{
			type			ITEM_TYPE_TEXT
			rect			ORIGIN_COLUMN_NAME_X -2 0 0 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
			origin			ORIGIN_PLAYERLIST
			text			"@MPUI_NAME"
			align			ITEM_ALIGN_LEFT
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textalignx		-20//6
			textaligny 		12
			forecolor		COLUMN_HEADER_COLOR
			visible 		1
			decoration
		}		
		itemDef
		{
			type			ITEM_TYPE_TEXT
			rect			ORIGIN_COLUMN_SCORE_X -2 30 0 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
			origin			ORIGIN_PLAYERLIST
			text			"@MPUI_SCORE"
			align			ITEM_ALIGN_RIGHT
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textalignx		-26
			textaligny 		12
			forecolor		COLUMN_HEADER_COLOR
			visible 		when( PLAYERLIST_SCOREVIS )
			decoration
		}
	#endif


		
	#ifndef SPLITSCREEN_PLAYERLIST
	
		#define PLAYERLIST_PARTYVIS ((!dvarbool( party_timerVisible ) || !dvarbool( party_teambased ) || !dvarbool( party_autoteams )) && !InLobby())
		#define PLAYERLIST_MEMBERVIS ((!dvarbool( party_timerVisible ) || !dvarbool( party_teambased ) || !dvarbool( party_autoteams )) && InLobby())
		#define PLAYERLIST_TEAMSVIS (dvarbool( party_timerVisible ) && dvarbool( party_teambased ) && dvarbool( party_autoteams ))
		// && (tableLookup( "mp/mapsTable.csv", 0, dvarString( "ui_mapname" ), 1 ) == setting) && player( teamname ) == "TEAM_ALLIES" ); \

		PLAYERLIST_PLAYERFEEDER( "partyList", FEEDER_PARTY_MEMBERS, 8, 334, CHOICE_TEXTCOLOR, BACKGROUND_TEXTURE_COLOR, PLAYERLIST_SELECTED_ACTIONS, PLAYERLIST_PARTYVIS )
		PLAYERLIST_TALKFEEDER( FEEDER_PARTY_MEMBERS_TALK, 8, 334, PLAYERLIST_PARTYVIS )
		PLAYERLIST_RANKFEEDER( FEEDER_PARTY_MEMBERS_RANK, 8, 334, PLAYERLIST_PARTYVIS )

		PLAYERLIST_PLAYERFEEDER( "lobbyList", FEEDER_LOBBY_MEMBERS, 8, 334, CHOICE_TEXTCOLOR, BACKGROUND_TEXTURE_COLOR, PLAYERLIST_SELECTED_ACTIONS, PLAYERLIST_MEMBERVIS )
		PLAYERLIST_SCOREFEEDER( FEEDER_LOBBY_MEMBERS_STAT, 8, 334, PLAYERLIST_SCOREVIS && PLAYERLIST_MEMBERVIS )
		PLAYERLIST_TALKFEEDER( FEEDER_LOBBY_MEMBERS_TALK, 8, 334, PLAYERLIST_MEMBERVIS )
		PLAYERLIST_RANKFEEDER( FEEDER_LOBBY_MEMBERS_RANK, 8, 334, PLAYERLIST_MEMBERVIS )
								
		PLAYERLIST_PLAYERFEEDER( "myMembersList", FEEDER_MYTEAM_MEMBERS, 8, 167, CHOICE_TEXTCOLOR, COLOR_USMC 0.7, PLAYERLIST_SELECTED_ACTIONS, PLAYERLIST_TEAMSVIS && ((tableLookup( "mp/mapsTable.csv", 0, dvarString( "ui_mapname" ), 1 ) == "pacific") && player( teamname ) == "TEAM_ALLIES") )
		PLAYERLIST_PLAYERFEEDER( "myMembersList", FEEDER_MYTEAM_MEMBERS, 8, 167, CHOICE_TEXTCOLOR, COLOR_USSR 0.7, PLAYERLIST_SELECTED_ACTIONS, PLAYERLIST_TEAMSVIS && ((tableLookup( "mp/mapsTable.csv", 0, dvarString( "ui_mapname" ), 1 ) != "pacific") && player( teamname ) == "TEAM_ALLIES") )
		PLAYERLIST_PLAYERFEEDER( "myMembersList", FEEDER_MYTEAM_MEMBERS, 8, 167, CHOICE_TEXTCOLOR, COLOR_JPN 0.7, PLAYERLIST_SELECTED_ACTIONS, PLAYERLIST_TEAMSVIS && ((tableLookup( "mp/mapsTable.csv", 0, dvarString( "ui_mapname" ), 1 ) == "pacific") && player( teamname ) == "TEAM_AXIS") )
		PLAYERLIST_PLAYERFEEDER( "myMembersList", FEEDER_MYTEAM_MEMBERS, 8, 167, CHOICE_TEXTCOLOR, COLOR_GER 0.7, PLAYERLIST_SELECTED_ACTIONS, PLAYERLIST_TEAMSVIS && ((tableLookup( "mp/mapsTable.csv", 0, dvarString( "ui_mapname" ), 1 ) != "pacific") && player( teamname ) == "TEAM_AXIS") )
		PLAYERLIST_SCOREFEEDER( FEEDER_MYTEAM_MEMBERS_STAT, 8, 167, PLAYERLIST_SCOREVIS && PLAYERLIST_TEAMSVIS )
		PLAYERLIST_TALKFEEDER( FEEDER_MYTEAM_MEMBERS_TALK, 8, 167, PLAYERLIST_TEAMSVIS )
		PLAYERLIST_RANKFEEDER( FEEDER_MYTEAM_MEMBERS_RANK, 8, 167, PLAYERLIST_TEAMSVIS )
		PLAYERLIST_SQUADFEEDER( FEEDER_MYTEAM_MEMBERS_SQUAD, 10, 334, PLAYERLIST_TEAMSVIS )
		
		PLAYERLIST_PLAYERFEEDER( "enemyMembersList", FEEDER_ENEMY_MEMBERS, (8 + 0 + 167), 167, CHOICE_TEXTCOLOR, COLOR_JPN 0.7, PLAYERLIST_SELECTED_ACTIONS, PLAYERLIST_TEAMSVIS && ((tableLookup( "mp/mapsTable.csv", 0, dvarString( "ui_mapname" ), 1 ) == "pacific") && player( teamname ) == "TEAM_ALLIES") )
		PLAYERLIST_PLAYERFEEDER( "enemyMembersList", FEEDER_ENEMY_MEMBERS, (8 + 0 + 167), 167, CHOICE_TEXTCOLOR, COLOR_GER 0.7, PLAYERLIST_SELECTED_ACTIONS, PLAYERLIST_TEAMSVIS && ((tableLookup( "mp/mapsTable.csv", 0, dvarString( "ui_mapname" ), 1 ) != "pacific") && player( teamname ) == "TEAM_ALLIES") )
		PLAYERLIST_PLAYERFEEDER( "enemyMembersList", FEEDER_ENEMY_MEMBERS, (8 + 0 + 167), 167, CHOICE_TEXTCOLOR, COLOR_USMC 0.7, PLAYERLIST_SELECTED_ACTIONS, PLAYERLIST_TEAMSVIS && ((tableLookup( "mp/mapsTable.csv", 0, dvarString( "ui_mapname" ), 1 ) == "pacific") && player( teamname ) == "TEAM_AXIS") )
		PLAYERLIST_PLAYERFEEDER( "enemyMembersList", FEEDER_ENEMY_MEMBERS, (8 + 0 + 167), 167, CHOICE_TEXTCOLOR, COLOR_USSR 0.7, PLAYERLIST_SELECTED_ACTIONS, PLAYERLIST_TEAMSVIS && ((tableLookup( "mp/mapsTable.csv", 0, dvarString( "ui_mapname" ), 1 ) != "pacific") && player( teamname ) == "TEAM_AXIS") )
		PLAYERLIST_SCOREFEEDER( FEEDER_ENEMY_MEMBERS_STAT, (8 + 0 + 167), 167, PLAYERLIST_SCOREVIS && PLAYERLIST_TEAMSVIS )
		PLAYERLIST_TALKFEEDER( FEEDER_ENEMY_MEMBERS_TALK, (8 + 0 + 167), 167, PLAYERLIST_TEAMSVIS )
		PLAYERLIST_RANKFEEDER( FEEDER_ENEMY_MEMBERS_RANK, (8 + 0 + 167), 167, PLAYERLIST_TEAMSVIS )
		PLAYERLIST_SQUADFEEDER( FEEDER_ENEMY_MEMBERS_SQUAD, (10 + 0 + 167), 334, PLAYERLIST_TEAMSVIS )

	#else

		#undef ORIGIN_COLUMN_NAME_X
		#define ORIGIN_COLUMN_NAME_X 6
		PLAYERLIST_PLAYERFEEDER( "splitscreen_playerlist", FEEDER_SPLITSCREENPLAYERS, 14, 324, CHOICE_TEXTCOLOR, 0.5 0.5 0.5 0, decoration, 1 )
		
	#endif
	
	// private party host icon
	#ifdef SHOW_PRIVATE_PARTY_HOST
		PREPROC_SHADER_DRAW_ALIGNED( 252 13 14 14 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERLIST, "ui_host", 0.825 0.825 0.825 0.7, 0, 0, 0 0 0 0 )
	#endif	
	



