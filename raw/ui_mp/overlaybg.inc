#ifndef PC
	#define GRADIENT_LEFT_LINE_X	-290
	#define GRADIENT_LEFT_LINE_Y	29
	#define BOTTOM_LINE_Y			443
	#define INDIV_COL_GRADIENT_Y	137
	#define SHOW_BG	1
	#define OVERLAY_RECT			0 65 640 355
#else
	#define GRADIENT_LEFT_LINE_X	-290
	#define GRADIENT_LEFT_LINE_Y	65
	#define BOTTOM_LINE_Y			419
	#define INDIV_COL_GRADIENT_Y	174
	#define OVERLAY_RECT			-100 65 840 355

	#ifndef PC_INGAME
		#define SHOW_BG	1
	#else
		#define SHOW_BG	0
	#endif

#endif

#define OVERLAY_BACKGROUND \
	OVERLAY_BACKGROUND_VIS( 1 ) \

#define OVERLAY_BACKGROUND_VIS( visArg ) \
	/*fade out*/ \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			-600 -800 2000 2000 0 0 \
		forecolor		/*COLOR_FADEOUT*/ 0 0 0 0.65 \
		background		"white" \
		visible			when( visArg ); \
		decoration \
	} \
	/*top white line*/ \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			0 64 640 1 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN \
		forecolor		0.5 0.5 0.5 0.65  \
		background		"menu_white_line_faded" \
		visible			when( visArg ); \
		decoration \
	} \
	/*overlay texture*/ \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			OVERLAY_RECT HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN \
		background		"menu_background_mp_tank_blurred" \
		forecolor		1 1 1 1 \
		visible			when( dvarBool( ui_mulitplayer_menu ) && SHOW_BG ) \
		decoration \
	} \
	/*bottom white line*/ \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			0 BOTTOM_LINE_Y 640 1 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN \
		forecolor		0.5 0.5 0.5 0.65  \
		background		"menu_white_line_faded" \
		visible			when( visArg ); \
		decoration \
	}

#define OVERLAY_BACKGROUND_NO_FADE \
		OVERLAY_BACKGROUND_NO_FADE_VIS( 1 )

#define OVERLAY_BACKGROUND_NO_FADE_VIS( visArg ) \
	/*top white line*/ \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			0 64 640 1 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN \
		forecolor		0.5 0.5 0.5 0.65  \
		background		"menu_white_line_faded" \
		visible			when( visArg ); \
		decoration \
	} \
	/*overlay texture*/ \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			0 65 640 355 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN \
		background		"menu_background_mp_tank_blurred" \
		forecolor		1 1 1 1 \
		visible			SHOW_BG \
		decoration \
	} \
	/*bottom white line*/ \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			0 BOTTOM_LINE_Y 640 0.5 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN \
		forecolor		0.5 0.5 0.5 0.65  \
		background		"menu_white_line_faded" \
		visible			when( visArg ); \
		decoration \
	}

#define LISTBOX_GRADIENT( rectArg ) \
	LISTBOX_GRADIENT_VIS( rectArg, 1 )

#define LISTBOX_GRADIENT_VIS( rectArg, visArg ) \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			rectArg \
		background		"menu_white_line_faded" \
		forecolor		0.1 0.1 0.1 0.7 \
		visible			when( visArg ) \
		decoration \
	}


#define THIRD_RIGHT_COL_GRADIENT \
	/* left line and gradient */ \
	PREPROC_GRADIENT_LEFT_LINE_DRAW_ALIGNED( 0, -9, 16, 355, HORIZONTAL_ALIGN_RIGHT, VERTICAL_ALIGN_TOP, -225 38 )
	/* grey box to come */ 

#define MAIN_COL_GRADIENT \
	INDIV_COL_GRADIENT_VIS( 0 )

// create a class color gradients
#define INDIV_COL_GRADIENT_VIS( visArg ) \
	/* left line and gradient */ \
	PREPROC_GRADIENT_LEFT_LINE_DRAW_ALIGNED( GRADIENT_LEFT_LINE_X, GRADIENT_LEFT_LINE_Y, 16, 355, HORIZONTAL_ALIGN_RIGHT, VERTICAL_ALIGN_TOP, 0 0 ) \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			-275 29 342 108 HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP \
		background		"menu_white_line_faded" \
		forecolor		0 0 0 0.6 \
		visible			0 \
		decoration \
	} \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			-275 INDIV_COL_GRADIENT_Y 342 248 HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP \
		background		"menu_white_line_faded" \
		forecolor		0.15 0.15 0.15 0.6 \
		visible			visArg \
		decoration \
	} \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			-274 INDIV_COL_GRADIENT_Y 342 1 HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP \
		background		"menu_white_line_faded" \
		forecolor		1 1 1 0.1 \
		visible			visArg \
		decoration \
	}

#ifdef PC_INGAME
	#define VISIBLE_INGAME 1
#else
	#define VISIBLE_INGAME 0
#endif
// Letterbox background...
#define BACKGROUND_BLACK_LETTERBOX_BLURWORLD( blurWorldArg ) \
	BACKGROUND_BLACK_LETTERBOX_BLURWORLD_VIS( blurWorldArg, 1 )

#define BACKGROUND_BLACK_LETTERBOX_BLURWORLD_VIS( blurWorldArg, showArg )	\
		blurWorld		blurWorldArg \
	itemDef \
	{ \
		style			WINDOW_STYLE_FILLED \
		rect			0 0 640 480 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN \
		backcolor		0 0 0 0 \
		visible			1 \
		decoration \
	} \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			-107 0 854 64 0 0\
		forecolor		1 1 1 1 \
		background		"menu_black_line" \
		visible			showArg \
		decoration \
	} \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			-107 420 854 70 0 0\
		forecolor		1 1 1 1 \
		background		"menu_black_line" \
		visible			showArg \
		decoration \
	} \
	/*top white line*/ \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			0 64 640 1 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN \
		forecolor		0.5 0.5 0.5 0.65  \
		background		"menu_white_line_faded" \
		visible			when( visArg ); \
		decoration \
	} \
	itemDef \
	{ \
		style			WINDOW_STYLE_SHADER \
		rect			0 BOTTOM_LINE_Y 640 1 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN \
		forecolor		0.5 0.5 0.5 0.65  \
		background		"menu_white_line_faded" \
		visible			when( visArg ); \
		decoration \
	}

