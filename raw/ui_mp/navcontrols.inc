#ifndef ALT_PANEL
#define ALT_PANEL		0
#endif

#ifdef CONSOLE
		#undef	LOCAL_NOT_IN_CAC
		#define LOCAL_NOT_IN_CAC ( !menuisopen("menu_cac_custom") )
		#undef	LOCAL_IN_CAC
		#define LOCAL_IN_CAC ( menuisopen("menu_cac_custom") )
		
		#ifndef BUTTON_Y_FILTER
		#define BUTTON_Y_FILTER		0
		#endif
		
		#undef NAV_FONT
		#ifdef SPLITSCREEN_ENABLED
			#define NAV_FONT	UI_FONT_SMALL
		#else
			#define NAV_FONT	UI_FONT_NORMAL
		#endif	
		
		// change filter Y button for leaderboards
		itemDef
		{
			name			change_filter
			text			"@PLATFORM_CHANGE_FILTER"
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			rect			90 -4 0 0 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_BOTTOM
			visible			when( BUTTON_Y_FILTER );
			decoration
			execKeyInt BUTTON_Y
			{
				play "mouse_click";
	#ifdef XENON
				execNow "toggle lb_filter 0 1 2";
	#endif // #ifdef XENON
	#ifdef PS3
				execNow "toggle lb_filter 0 1";
	#endif // #ifdef PS3
			}
	#ifdef XENON
			execKeyInt BUTTON_LSHLDR
			{ 
				execNow "toggle lb_gamemode 15 12 10 9 8 7 6 5 4 3 2 1 0";
				uiScript RefreshLeaderboards;
			}
			execKeyInt BUTTON_RSHLDR
			{
				execNow "toggle lb_gamemode 0 1 2 3 4 5 6 7 8 9 10 12 15";
				uiScript RefreshLeaderboards;
			}
	#endif // #ifdef XENON
		}

		#ifndef BUTTON_X_GOTOTOP
		#define BUTTON_X_GOTOTOP	0
		#endif

		#ifndef BUTTON_ACCEPT
		#define BUTTON_ACCEPT		0
		#endif
				
		// jump to top X button for leaderboards
		itemDef
		{
			name			goto_top
			text			"@PLATFORM_GOTOTOP"
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textalign		ITEM_ALIGN_CENTER
			rect			-40 -4 0 0 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
			visible			when( BUTTON_X_GOTOTOP );
			decoration
		}
		
		itemDef
		{
			name			accept_button
			text			"@PLATFORM_SELECT"
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textalign		ITEM_ALIGN_CENTER
			rect			44 -4 0 0 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
			visible			when( BUTTON_ACCEPT );
			decoration
		}
		
		#ifndef BUTTON_PGUP
		#define BUTTON_PGUP		0
		#endif
		#ifndef BUTTON_PGDOWN
		#define BUTTON_PGDOWN	0
		#endif
				
		#ifndef	BUTTON_REFRESH
		#define BUTTON_REFRESH	0
		#endif
				
		// refresh button for systemlink 
		itemDef
		{
			name			refresh
			text			"@PLATFORM_REFRESH"
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textalign		ITEM_ALIGN_RIGHT
			rect			-20 -4 0 0 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
			visible			when( BUTTON_REFRESH );
			decoration
		}		

		// page up and down 
		itemDef
		{
			name			pgup
			text			"@PLATFORM_PGUP"
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textalign		ITEM_ALIGN_LEFT
			rect			-180 -4 0 0 HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_BOTTOM
			visible			when( BUTTON_PGUP );
			decoration
		}
		itemDef
		{
			name			pgdown
			text			"@PLATFORM_PGDOWN"
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textalign		ITEM_ALIGN_LEFT
			rect			-90 -4 0 0 HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_BOTTOM
			visible			when( BUTTON_PGDOWN );
			decoration
		}
		
		
		itemDef {
			style			WINDOW_STYLE_SHADER
			rect			0 -20 16 16 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_BOTTOM
			origin			0 0
			background		"ui_arrow_left"
			forecolor		1 1 1 1
			visible			1
			decoration
		}
		itemDef
		{
			rect			18 -4 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_BOTTOM
			origin			0 0
			text			"@PLATFORM_BACK"
			textfont		CHOICE_TEXTFONT
			textscale		TEXTSIZE_SMALL
			textalign		ITEM_ALIGN_BOTTOM_LEFT
			visible			1
			decoration
		}
		
#endif // #ifdef CONSOLE

#ifdef PC

	#ifndef BACK_ENABLE
	#define BACK_ENABLE	1
	#endif

	#ifndef BACK_OPEN
	#define BACK_OPEN	open main_text;
	#endif
	
	itemDef 
	{
		name			back
		text			"@MENU_BACK"
		type			1
		style			WINDOW_STYLE_FILLED
		textstyle		ITEM_TEXTSTYLE_SHADOWED
		rect			-250 -26 40 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
		textalign		ITEM_ALIGN_LEFT
		textfont		CHOICE_TEXTFONT
		textscale		TEXTSIZE_SMALL
		textaligny		18
		visible			when(BACK_ENABLE);
		mouseEnter		{ play "mouse_over"; }
		action 
		{
			play "mouse_click";
			close self;
			BACK_OPEN
		}	
	}
	
#endif // #ifdef PC