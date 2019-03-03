#ifndef GAMEINFO_ORIENTATION
	#define GAMEINFO_X				(CHOICE_X_START+CHOICE_SIZE_X-GAMEINFO_WIDTH-10)
	#define GAMEINFO_Y				226
	#define GAMEINFO_ORIGIN			GAMEINFO_X GAMEINFO_Y
	#define GAMEINFO_WIDTH			200
	#define GAMEINFO_WIDTH2			213
	#define GAMEINFO_HEIGHT			120
#endif

#define GAME_INFO( mapImageExp, mapNameExp, gameTypeExp, visArg )\
	/* map image */ \
	PREPROC_SHADER_DRAW_ALIGNED( GAMEINFO_ORIGIN GAMEINFO_WIDTH2 GAMEINFO_HEIGHT CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 0 20, mapImageExp, 1 1 1 1, 0, 0, 0 0 0 0 visible when( visArg ); ) \
	/* new gametype on mapname */ \
	itemDef \
	{ \
		type			ITEM_TYPE_TEXT \
		rect			GAMEINFO_ORIGIN GAMEINFO_WIDTH 16 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP \
		origin			0 155 \
		forecolor		CHOICE_TEXTCOLOR \
		ownerdraw		UI_GAMETYPE_MAPNAME \
		textfont		CHOICE_TEXTFONT \
		textscale		TEXTSIZE_SMALL \
		textstyle		CHOICE_TEXTSTYLE \
		textalign		ITEM_ALIGN_LEFT \
		visible			1 \
		decoration \
	} \

#define GAME_INFO_VETO( mapImageExp, mapNameExp, gameTypeExp, visArg )\
	/* bg gradient */ \
	PREPROC_GRADIENT_TOP_LINE_DRAW_ALIGNED( (GAMEINFO_X-10), 207, (GAMEINFO_WIDTH2+20), (GAMEINFO_HEIGHT+38), CHOICE_HORIZONTAL_ALIGN, VERTICAL_ALIGN_TOP, 0 20, "menu_white_line_faded", 0 0 0 0.7 ) \
	/* map image */ \
	PREPROC_SHADER_DRAW_ALIGNED( GAMEINFO_ORIGIN GAMEINFO_WIDTH2 GAMEINFO_HEIGHT CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 0 20, mapImageExp, 1 1 1 1, 0, 0, 0 0 0 0 visible when( visArg ); ) \
	/* new gametype on mapname */ \
	itemDef \
	{ \
		type			ITEM_TYPE_TEXT \
		rect			GAMEINFO_ORIGIN GAMEINFO_WIDTH 16 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP \
		origin			0 155 \
		forecolor		CHOICE_TEXTCOLOR \
		ownerdraw		UI_GAMETYPE_MAPNAME \
		textfont		CHOICE_TEXTFONT \
		textscale		TEXTSIZE_SMALL \
		textstyle		CHOICE_TEXTSTYLE \
		textalign		ITEM_ALIGN_LEFT \
		visible			1 \
		decoration \
	} \
	/* veto status */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( GAMEINFO_ORIGIN GAMEINFO_WIDTH 16 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 2 35, ( dvarstring( party_vetoStatus ) ), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_LEFT, 1 .4 .4 1 visible when( inlobby() ); )

#define GAME_INFO_VETO_COOP( mapImageExp, mapNameExp, gameTypeExp, visArg )\
	/* bg gradient */ \
	PREPROC_GRADIENT_TOP_LINE_DRAW_ALIGNED_VIS( GAMEINFO_X, 207, (GAMEINFO_WIDTH2+20), (GAMEINFO_HEIGHT+38), CHOICE_HORIZONTAL_ALIGN, VERTICAL_ALIGN_TOP, 0 20, "menu_white_line_faded", 0 0 0 0.7, when( visArg ) ) \
	/* map image */ \
	PREPROC_SHADER_DRAW_ALIGNED( GAMEINFO_ORIGIN GAMEINFO_WIDTH2 GAMEINFO_HEIGHT CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 0 20, mapImageExp, 1 1 1 1, 0, 0, 0 0 0 0 visible when( visArg ); ) \
	/* new gametype on mapname */ \
	itemDef \
	{ \
		type			ITEM_TYPE_TEXT \
		rect			GAMEINFO_ORIGIN GAMEINFO_WIDTH 16 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP \
		origin			0 155 \
		forecolor		CHOICE_TEXTCOLOR \
		ownerdraw		mapNameExp \
		textfont		CHOICE_TEXTFONT \
		textscale		TEXTSIZE_SMALL \
		textstyle		CHOICE_TEXTSTYLE \
		textalign		ITEM_ALIGN_LEFT \
		visible			1 \
		decoration \
	} \
	/* veto status */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( GAMEINFO_ORIGIN GAMEINFO_WIDTH 16 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 2 35, ( dvarstring( party_vetoStatus ) ), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_LEFT, 1 .4 .4 1 visible when( inlobby() ); ) \

#define GAME_INFO3( mapImageExp, gameTypeImageExp, gameTypeExp, mapNameExp, gameTypeDescExp, mapSizeExp, vehicleExp, visArg )\
	/* map image */ \
	PREPROC_SHADER_DRAW_ALIGNED( GAMEINFO_RECT HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 0 0, mapImageExp, 1 1 1 1, 0, 0, 0 0 0 0 visible when( visArg ); ) \
	/* game type image */ \
	PREPROC_SHADER_DRAW_ALIGNED( GAMEINFO_ORIGIN 45 45 HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 150 55, gameTypeImageExp, 1 1 1 1, 0, 0, 0 0 0 0 visible when( visArg ); ) \
	/* game type name */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( GAMEINFO_RECT HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 0 120, gameTypeExp, CHOICE_TEXTSIZE, 0, 0, ITEM_ALIGN_LEFT, COLOR_INFO_YELLOW visible when( visArg ); ) \
	/* mapname */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( GAMEINFO_RECT HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 0 (120+15), mapNameExp, CHOICE_TEXTSIZE, 0, 0, ITEM_ALIGN_LEFT, COLOR_INFO_YELLOW visible when( visArg ); )\
	/* game type description */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( GAMEINFO_RECT HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 0 (120+50), gameTypeDescExp, TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_LEFT, COLOR_BODY_TEXT visible when( visArg ); ) \
	/* map size */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( GAMEINFO_RECT HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 0 (120+175), mapSizeExp, TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_LEFT, COLOR_FOCUSED visible when( visArg ); ) \
	/* vehicle */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( GAMEINFO_RECT HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 0 (120+195), vehicleExp, TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_LEFT, COLOR_FOCUSED visible when( visArg ); )
	
#define GAME_INFO3_COOP( mapImageExp, gameTypeImageExp, gameTypeExp, mapNameExp, gameTypeDescExp, visArg )\
	/* map image */ \
	PREPROC_SHADER_DRAW_ALIGNED( GAMEINFO_RECT HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 0 0, mapImageExp, 1 1 1 1, 0, 0, 0 0 0 0 visible when( visArg ); ) \
	/* game type image */ \
	PREPROC_SHADER_DRAW_ALIGNED( (GAMEINFO_ORIGIN_X-40) GAMEINFO_ORIGIN_Y 45 45 HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 150 55, gameTypeImageExp, 1 1 1 1, 0, 0, 0 0 0 0 visible when( visArg ); ) \
	/* game type name */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( GAMEINFO_RECT HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 0 120, gameTypeExp, TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_LEFT, CHOICE_TEXTCOLOR visible when( visArg ); ) \
	/* mapname */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( GAMEINFO_RECT HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 0 (120+15), mapNameExp, TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_LEFT, CHOICE_TEXTCOLOR visible when( visArg ); )\
	/* game type description */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( GAMEINFO_RECT HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 0 (120+50), gameTypeDescExp, TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_LEFT, COLOR_BODY_TEXT visible when( visArg ); ) 

#define GAME_INFO3_COOP_LOCKED( mapImageExp, gameTypeImageExp, gameTypeExp, mapNameExp, gameTypeDescExp, visArg )\
	/* map image */ \
	PREPROC_SHADER_DRAW_ALIGNED( GAMEINFO_RECT HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 0 0, mapImageExp, 1 1 1 1, 0, 0, 0 0 0 0 visible when( visArg ); ) \
	/* game type image */ \
	PREPROC_SHADER_DRAW_ALIGNED( (GAMEINFO_ORIGIN_X-40) GAMEINFO_ORIGIN_Y 45 45 HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 150 55, gameTypeImageExp, 1 1 1 1, 0, 0, 0 0 0 0 visible when( visArg ); ) \
	/* game type name */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( GAMEINFO_RECT HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 0 120, gameTypeExp, TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_LEFT, CHOICE_TEXTCOLOR visible when( visArg ); ) \
	/* game type description */ \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( GAMEINFO_RECT HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP, 0 (120+50), gameTypeDescExp, TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_LEFT, COLOR_BODY_TEXT visible when( visArg ); ) 
