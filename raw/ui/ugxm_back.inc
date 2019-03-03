itemDef 
{
	name		back
	text		"Close"
	type		ITEM_TYPE_BUTTON
	style		WINDOW_STYLE_FILLED
	textstyle	ITEM_TEXTSTYLE_SHADOWED
	rect		UGXM_BACK_X 450 45 12
	textalign	ITEM_ALIGN_CENTER
	textscale	0.3
	textaligny	11
	visible		1
	forecolor	.9 .9 .95 1
	action 
	{
		play "mouse_click";
		close UGXM_CURRENT_MENU ;
	}
	mouseEnter		
	{  
		play "mouse_over"; 
	}
}