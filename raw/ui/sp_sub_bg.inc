//SUBMENU BACKGROUND FOR SINGLE PLAYER

itemDef
{
	style			WINDOW_STYLE_SHADER
	rect			FULLSCREEN_WIDE
	background		"animbg_blur_back"
	visible			1
	decoration
}

itemDef
{
	style			WINDOW_STYLE_SHADER
	rect			FULLSCREEN_WIDE
	background		"menu_background_sp_blurred"
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

#include "ui/sepia.inc"
