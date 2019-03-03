//COD4 BACKGROUND
#if !COOP_EPD
itemDef
{
	style			WINDOW_STYLE_SHADER
	rect			FULLSCREEN_WIDE
	background		"ugx_main_menu_user"
	visible			1
	decoration
}
/*itemDef 
{
	style			WINDOW_STYLE_FILLED
	rect			FULLSCREEN_WIDE
	backcolor		0 0 0 1
	visible			1
	background		"white"
	decoration
}
itemDef
{
	style			WINDOW_STYLE_SHADER
	rect			FULLSCREEN_WIDE
	backcolor		0 0 0 1
	background		"$levelBriefing"
	visible			when( ( dvarbool(onlinegame) || dvarbool(systemlink) ) && dvarbool(widescreen) )
	decoration
}
itemDef 
{
	style			WINDOW_STYLE_FILLED
	rect			FULLSCREEN_WIDE
	backcolor		1 1 1 1
	visible			when( !dvarbool(onlinegame) && !dvarbool(systemlink) )
	background		cinematic
	ownerdraw		UI_CINEMATIC
	decoration
}*/
#endif

#undef	FOG_SCROLL_TIME
#define FOG_SCROLL_TIME 60000 //30000

 #undef	THINFOG_SCROLL_TIME
 #define THINFOG_SCROLL_TIME 50000 //50000

#if !COOP_EPD
itemDef
{
	style			WINDOW_STYLE_SHADER
	rect			FULLSCREEN_WIDE
	background		"ugx_main_menu_user"
	visible			when( !dvarBool( ui_mulitplayer_menu ) )
	decoration
}
itemDef
{
	style			WINDOW_STYLE_SHADER
	rect			FULLSCREEN_WIDE
	background		"ugx_main_menu_user"
	visible			when( dvarBool( ui_mulitplayer_menu ) )
	decoration
}
#endif