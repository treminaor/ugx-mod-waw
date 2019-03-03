//#undef	FOG_SCROLL_TIME
//#define FOG_SCROLL_TIME 60000 //30000
//
//#undef	THINFOG_SCROLL_TIME
//#define THINFOG_SCROLL_TIME 100000 //50000
//
//itemDef
//{
//	style			WINDOW_STYLE_SHADER
//	rect			-107 0 1708 480
//	exp				rect X((-107) - ((float(milliseconds() % FOG_SCROLL_TIME) / FOG_SCROLL_TIME) * (854)))
//	background		"animbg_fogscroll"
//	visible			1
//	decoration
//}
//itemDef
//{
//	style			WINDOW_STYLE_SHADER
//	rect			-107 0 1708 480
//	exp				rect X((-961) + ((float(milliseconds() % THINFOG_SCROLL_TIME) / THINFOG_SCROLL_TIME) * (854)))
//	background		"animbg_fogscrollthin"
//	visible			1
//	decoration
//}

#ifdef PS3
itemDef
{
	style			WINDOW_STYLE_SHADER
	rect			FULLSCREEN_WIDE
	background		"menu_background_coop"
	visible			1
	decoration
}
#endif // #ifdef PS3

// top black border
itemDef
{
	style			WINDOW_STYLE_SHADER
	rect			-107 0 854 66 
	forecolor		1 1 1 1
	background		"menu_black_line"
	visible			0
	decoration
}
// bottom black border
itemDef
{
	style			WINDOW_STYLE_SHADER
	rect			-107 420 854 70 //-50 0 50 480 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_BOTTOM
	forecolor		1 1 1 1
	background		"menu_black_line"
	visible			0
	decoration
}

#include "ui/blurredbg.inc"
