#undef	FOG_SCROLL_TIME
#define FOG_SCROLL_TIME 60000 //30000

#undef	THINFOG_SCROLL_TIME
#define THINFOG_SCROLL_TIME 50000 //50000

itemDef
{
	style			WINDOW_STYLE_SHADER
	rect			FULLSCREEN_WIDE
	background		"menu_background_mp_tank"
	visible			1
	decoration
}
itemDef
{
	style			WINDOW_STYLE_SHADER
	rect			-107 0 1708 480
	exp				rect X((-961) + ((float(milliseconds() % THINFOG_SCROLL_TIME) / THINFOG_SCROLL_TIME) * (854)))
	background		"animbg_fogscrollthin"
	visible			1
	decoration
}

// top black border
itemDef
{
	style			WINDOW_STYLE_SHADER
	rect			-107 0 854 66 
	forecolor		1 1 1 1
	background		"menu_black_line"
	visible			1
	decoration
}
// bottom black border
itemDef
{
	style			WINDOW_STYLE_SHADER
	rect			-107 420 854 70 
	forecolor		1 1 1 1
	background		"menu_black_line"
	visible			1
	decoration
}
