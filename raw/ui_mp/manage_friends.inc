//#include "ui_mp/stats_info.inc"
#include "ui_mp/friends_common.inc"	

#undef	SIGNED_IN_RECT
#define SIGNED_IN_RECT			-350 60 250 15

	menuDef
	{
		name			manage_friends
		fullscreen		1
		rect			0 0 640 480 //RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		focuscolor		COLOR_FOCUSED
		style			WINDOW_STYLE_FILLED
		soundloop 		"music_mainmenu"
		onOpen			{ }
		onclose			{ setLocalVarBool ui_showGameInvites 0; setLocalVarBool ui_showInviteFriend 0; }
		onESC 			{ setLocalVarBool ui_showGameInvites 0; setLocalVarBool ui_showInviteFriend 0; close self; }

		#undef BACK_OPEN
		#define BACK_OPEN	;

#ifdef PC_INGAME
		#include "ui/overlaybg.inc"
		BACKGROUND_BLACK_LETTERBOX_BLURWORLD_VIS( 0 , 0 )
		OVERLAY_BACKGROUND
#else
		#include "ui/blurredbg_online.inc"
#endif
		#include "ui_mp/navcontrols.inc"

		// draws signin status
		SIGNIN_STATUS

		FRIEND_CAPTION_VIS( "@MENU_MANAGEFRIENDS_CAP", 22, 5, 100, 100, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP,when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )); )
		FRIEND_CAPTION_VIS( "@MENU_INVITE_FRIEND_CAP", 22, 5, 100, 100, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, when( localVarBool( ui_showInviteFriend )); )
		FRIEND_CAPTION_VIS( "@MENU_GAME_INVITES_CAP", 22, 5, 100, 100, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, when( localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )); )
		//FRIEND_CAPTION_RIGHT( dvarString( com_playerProfile ), 487, 5, 100, 100, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP )

		FRIEND_LOGO_VIS( LOGO_START_X, LOGO_START_Y, when( localVarBool( ui_showGameInvites ) || localVarBool( ui_showInviteFriend )); )

		// player list frame clone
		// background
		PREPROC_SHADER_DRAW_ALIGNED( 0 12 LIST_BOX_FR_SIZE HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "gradient_center", 0.3 0.3 0.3 0.6, 0, 0, 0 0 0 0 )
		PREPROC_SHADER_DRAW_ALIGNED( -20 -4 -20 (LIST_BOX_FR_HEIGHT+24) HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )
		// right vertical shadow
		PREPROC_SHADER_DRAW_ALIGNED( LIST_BOX_FR_WIDTH -4 20 (LIST_BOX_FR_HEIGHT+24) HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )
		// caption liner
		PREPROC_SHADER_DRAW_ALIGNED( 0 -4 LIST_BOX_FR_WIDTH 16 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "white", PLATING_COLOR, 0, 0, 0 0 0 0 )
		// caption liner ( underliner  )
		//PREPROC_SHADER_DRAW_ALIGNED( 0 -4 LIST_BOX_FR_WIDTH 16 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "line_horizontal", 0.9 0.9 0.95 0.5, 0, 0, 0 0 0 0 )
		PREPROC_SHADER_DRAW_ALIGNED( 0 12 LIST_BOX_FR_WIDTH 16 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "gradient_top", 1 1 1 0.2, 0, 0, 0 0 0 0 )
		PREPROC_SHADER_DRAW_ALIGNED( 0 (LIST_BOX_FR_HEIGHT-4) LIST_BOX_FR_WIDTH 16 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "gradient_bottom", 1 1 1 0.2, 0, 0, 0 0 0 0 )
		// highliter at the bottom of the list box ( underliner )
		PREPROC_SHADER_DRAW_ALIGNED( 0 (LIST_BOX_FR_HEIGHT+12) LIST_BOX_FR_WIDTH 8 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "white", PLATING_COLOR, 0, 0, 0 0 0 0 )
		// highliter at the bottom of the list box
		PREPROC_SHADER_DRAW_ALIGNED( 0 (LIST_BOX_FR_HEIGHT+12) LIST_BOX_FR_WIDTH 8 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "line_horizontal", 0.9 0.9 0.95 0.5, 0, 0, 0 0 0 0 )

		// Friends listbox section
#undef SECTION_X_OFFSET
#define SECTION_X_OFFSET 5
#undef CHOICE_Y_START
#define CHOICE_Y_START   20
		CHOICE_SECTION_TITLE_VIS( 1, "@MENU_FRIENDS_CAP", when( !localVarBool( ui_showGameInvites ) || localVarBool( ui_showInviteFriend )) )
		CHOICE_SECTION_TITLE_VIS( 1, "@MENU_GAME_INVITES", when( localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )) )
		
		FRIEND_COLUMN_VIS( "@MENU_NAME", LB_COLUMN1_OFFSET_X, 0, 50, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, uiScript sortFriends 0;, MENU_TRUE )
		FRIEND_COLUMN_VIS( "@MENU_STATUS1", LB_COLUMN3_OFFSET_X, 0, 50, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, uiScript sortFriends 2;, when( !localVarBool( ui_showGameInvites ) ))
		itemDef 
		{
			name			friend_list
			type			ITEM_TYPE_LISTBOX
			feeder			FEEDER_FRIENDS
			rect			0 LB_BOX_OFFSET_Y (LIST_BOX_FR_WIDTH-2) (LIST_BOX_FR_HEIGHT-4) HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
			origin          LB_GROUP_ORIGIN
			elementwidth	120
			elementheight	18
			textalignx		2
			textaligny		0
			textscale		TEXTSIZE_SMALL
			textfont		UI_FONT_NORMAL
			forecolor		CHOICE_TEXTCOLOR
			focusColor		CHOICE_TEXTCOLOR
			disableColor 	CHOICE_TEXTCOLOR
			outlinecolor	0.9 0.9 0.925 0.2
			selectBorder	0.8 0.95 1 0
			columns			2 
			                LB_COLUMN1_OFFSET_X 0 20 
			                LB_COLUMN3_OFFSET_X 0 8
			visible			when( !localVarBool( ui_showGameInvites ) );
			
			onfocus 
			{
				play "mouse_over";
			}
			execkeyint 13
			{
				play "mouse_click";
				close manage_friends;
			}
			doubleclick
			{
				play "mouse_click";
			}
		}
		itemDef 
		{
			name			invite_list
			type			ITEM_TYPE_LISTBOX
			feeder			FEEDER_INVITES
			rect			0 LB_BOX_OFFSET_Y (LIST_BOX_FR_WIDTH-2) (LIST_BOX_FR_HEIGHT-4) HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
			origin          LB_GROUP_ORIGIN
			elementwidth	120
			elementheight	18
			textalignx		2
			textaligny		0
			textscale		TEXTSIZE_SMALL
			textfont		UI_FONT_NORMAL
			forecolor		CHOICE_TEXTCOLOR
			focusColor		CHOICE_TEXTCOLOR
			disableColor 	CHOICE_TEXTCOLOR
			outlinecolor	0.9 0.9 0.925 0.2
			selectBorder	0.8 0.95 1 0
			columns			1
			                LB_COLUMN1_OFFSET_X 0 20 
			visible			when( localVarBool( ui_showGameInvites ) );
			
			onfocus 
			{
				play "mouse_over";
			}
			execkeyint 13
			{
				play "mouse_click";
				close manage_friends;
			}
		}

		// --------------------  buttons ---------------------------------
  		FRIEND_BUTTON_VIS( "@MENU_SENDREQUEST", 30, 420, 80, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, open friend_add_popmenu;, when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend ) ); )
  		FRIEND_BUTTON_VIS( "@MENU_DELETEFRIEND", 220, 420, 80, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, open friend_del_sure_popmenu;, when ( ( hasfriends() > 0 ) && !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend ) ) ; )
  		FRIEND_DBUTTON_VIS( "@MENU_DELETEFRIEND", 220, 420, 80, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, when ( ( hasfriends() == 0 ) && !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend ) ) ; )
  		FRIEND_BUTTON_VIS( "@MENU_ACCEPT_INVITE", 220, 420, 80, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, uiScript acceptInvite;, when (( hasinvites() > 0 ) && localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )) ; )
  		FRIEND_DBUTTON_VIS( "@MENU_ACCEPT_INVITE", 220, 420, 80, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, when (( hasinvites() == 0 ) && localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )) ; )
  		FRIEND_BUTTON_VIS( "@MENU_SEND_INVITE", 220, 420, 80, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, uiScript inviteFriend, when (hasfriends()> 0 && localVarBool( ui_showInviteFriend ));  )
  		FRIEND_DBUTTON_VIS( "@MENU_SEND_INVITE", 220, 420, 80, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, when (hasfriends()== 0 && localVarBool( ui_showInviteFriend ) ) ; )

		// Pending listbox section
#undef SECTION_X_OFFSET
#define SECTION_X_OFFSET 330
		CHOICE_SECTION_TITLE_VIS( 1, "@MENU_PENDING", when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )) )

#undef  LB_GROUP_ORIGIN
#define LB_GROUP_ORIGIN          340 90
		PREPROC_SHADER_DRAW_ALIGNED_VIS( -20 -4 -20 (LIST_BOX_FR_HEIGHT+24) HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0, when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )); )
		PREPROC_SHADER_DRAW_ALIGNED_VIS( 0 12 LIST_BOX_FR_SIZE HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "gradient_center", 0.3 0.3 0.3 0.6, 0, 0, 0 0 0 0, when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )); )
		PREPROC_SHADER_DRAW_ALIGNED_VIS( LIST_BOX_FR_WIDTH -4 20 (LIST_BOX_FR_HEIGHT+24) HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0, when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )); )
		// caption liner
		PREPROC_SHADER_DRAW_ALIGNED_VIS( 0 -4 LIST_BOX_FR_WIDTH 16 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "white", PLATING_COLOR, 0, 0, 0 0 0 0, when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )); )
		// caption liner ( underliner  )
		//PREPROC_SHADER_DRAW_ALIGNED_VIS( 0 -4 LIST_BOX_FR_WIDTH 16 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "line_horizontal", 0.9 0.9 0.95 0.5, 0, 0, 0 0 0 0, when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend ));  )
		// gradient top
		PREPROC_SHADER_DRAW_ALIGNED_VIS( 0 12 LIST_BOX_FR_WIDTH 16 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "gradient_top", 1 1 1 0.2, 0, 0, 0 0 0 0, when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )); )
		// gradient bottom
		PREPROC_SHADER_DRAW_ALIGNED_VIS( -4 (LIST_BOX_FR_HEIGHT-4) LIST_BOX_FR_WIDTH 16 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "gradient_bottom", 1 1 1 0.2, 0, 0, 0 0 0 0, when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )); )
		// highliter at the bottom of the list box ( underliner )
		PREPROC_SHADER_DRAW_ALIGNED_VIS( 0 (LIST_BOX_FR_HEIGHT+12) LIST_BOX_FR_WIDTH 8 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "white", PLATING_COLOR, 0, 0, 0 0 0 0, when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )); )
		// highliter at the bottom of the list box
		PREPROC_SHADER_DRAW_ALIGNED_VIS( 0 (LIST_BOX_FR_HEIGHT+12) LIST_BOX_FR_WIDTH 8 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, "line_horizontal", 0.9 0.9 0.95 0.5, 0, 0, 0 0 0 0, when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )); )


		FRIEND_COLUMN_VIS( "@MENU_NAME", LB_COLUMN1_OFFSET_X, 0, 50, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, LB_GROUP_ORIGIN, uiScript sortFriends 3;, when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend ) ) ; )
		
		itemDef 
		{
			name			invite_friend_list
			type			ITEM_TYPE_LISTBOX
			feeder			FEEDER_PENDINGFRIENDS
			rect			0 LB_BOX_OFFSET_Y (LIST_BOX_FR_WIDTH-2) (LIST_BOX_FR_HEIGHT-4) HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
			origin          LB_GROUP_ORIGIN
			elementwidth	120
			elementheight	18
			textalignx		2
			textaligny		0
			textscale		TEXTSIZE_SMALL
			textfont		UI_FONT_NORMAL
			forecolor		CHOICE_TEXTCOLOR
			focusColor		CHOICE_TEXTCOLOR
			disableColor 	CHOICE_TEXTCOLOR
			outlinecolor	0.9 0.9 0.925 0.2
			selectBorder	0.8 0.95 1 0
			columns			1 
			                LB_COLUMN1_OFFSET_X 0 20 
			visible         when( !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend ) ) ;
			
			onfocus 
			{
				play "mouse_over";
			}
			execkeyint 13
			{
				play "mouse_click";
				close manage_friends;
			}
		}

		// --------------------  buttons ---------------------------------
  		FRIEND_BUTTON_VIS( "@MENU_ACCEPT", 340, 420, 50, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, uiScript acceptFriend;, when ( ( haspendingfriends() > 0 ) && !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend ) ) ; )
  		FRIEND_DBUTTON_VIS( "@MENU_ACCEPT", 340, 420, 50, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, when ( (haspendingfriends() == 0 ) && !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend ) ) ; )
  		FRIEND_BUTTON_VIS( "@MENU_DECLINE", 405, 420, 50, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, uiScript declineFriend;, when (( haspendingfriends() > 0 ) && !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend ) ) ; )
  		FRIEND_DBUTTON_VIS( "@MENU_DECLINE", 405, 420, 50, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, when ( ( haspendingfriends() == 0 ) && !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend )) ; )
  		FRIEND_BUTTON_VIS( "@MENU_ACCEPT_ALL", 470, 420, 70, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, uiScript acceptAllFriend;, when (( haspendingfriends() > 0 ) && !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend ) ) ; )
  		FRIEND_DBUTTON_VIS( "@MENU_ACCEPT_ALL", 470, 420, 70, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, when ( ( haspendingfriends() == 0 ) && !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend ) ) ; )
  		FRIEND_BUTTON_VIS( "@MENU_DECLINE_ALL", 552, 420, 70, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, uiScript declineAllFriend;, when ( ( haspendingfriends() > 0 ) && !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend ) ) ; )
  		FRIEND_DBUTTON_VIS( "@MENU_DECLINE_ALL", 552, 420, 70, 20, HORIZONTAL_ALIGN_LEFT, VERTICAL_ALIGN_TOP, when ( ( haspendingfriends() == 0 ) && !localVarBool( ui_showGameInvites ) && !localVarBool( ui_showInviteFriend ) ) ; )
  	}//menuDef manage_friends
