#define SIDE_MARGIN		40
	/////////////////////
	//
	// Enter Friend's name
	//
	/////////////////////

	#undef CHOICE_Y_START
	#define CHOICE_Y_START			230

	#undef CHOICE_X_START
	#define CHOICE_X_START			78

	menuDef
	{
		CENTER_POPUP_SETUP( friend_add_popmenu, 3, ;, 1 )
		onOpen { setdvar ui_friendNameNew ""; setfocus friend_add; }
		onClose { }
		
		CHOICE_POPMENU_TITLE( "@PLATFORM_FRIEND_NAME" )
		itemDef
		{
			name			friend_add
			TYPE			ITEM_TYPE_VALIDFILEFIELD
			text			"@MENU_NAME"
			dvar			"ui_friendNameNew"
			rect			60 200 310 18 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
			//rect			60 200 (CHOICE_SIZE_X-(SIDE_MARGIN*2)) 18 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
			origin			SIDE_MARGIN -8
			textaligny		-2
			maxchars		12
			maxpaintchars	12
			textalign		ITEM_ALIGN_MIDDLE_LEFT
			textfont		UI_FONT_NORMAL
			textscale		TEXTSIZE_SMALL
			forecolor		.9 .9 .9 1
			style			WINDOW_STYLE_FILLED
			backcolor		0 0 0 .3
			visible			1
			accept			{ uiScript sendRequestFriend; close self; }
		}
		CHOICE_BUTTON( 2, "@MENU_OK", uiScript sendRequestFriend; close self; )
		CHOICE_BUTTON( 3, "@MENU_CANCEL", close self; )
	}

	#undef CHOICE_Y_START
	#define CHOICE_Y_START			230

	/////////////////////
	//
	// Delete for sure? popup
	//
	/////////////////////
	
	menuDef
	{
		CENTER_POPUP_SETUP( friend_del_sure_popmenu, 3, ;, 1 )
		CHOICE_POPMENU_TITLE( "@MENU_DELETEFRIEND" )
		CHOICE_POPMENU_SUBTITLE( "@PLATFORM_DELETE_FRIEND" )
		
		CHOICE_BUTTON( 2, "@MENU_YES", uiScript deleteFriend; close self; )
		CHOICE_BUTTON( 3, "@MENU_NO", close self; )
	}

	/////////////////////
	//
	// Delete for sure? popup
	//
	/////////////////////
	menuDef
	{
		#define DELETE_ONESC \
			uiScript clearError; \
			close self;

		CENTER_POPUP_SETUP_ONOPEN( delete_choice_popmenu, 4, DELETE_ONESC, setfocus yes_button;, 1 )
		
		#undef DELETE_ACTION
		#define DELETE_ACTION \
				play "mouse_click"; \
				uiScript clearError; \
				uiScript deleteFriend; \
				close self;
				
		CHOICE_POPMENU_TITLE( dvarString( "com_errorTitle" ) )
		CHOICE_POPMENU_SUBTITLE( dvarString( "ui_friendMessage" ) )

		CHOICE_BUTTON_FOCUS_VIS_EX( 3, "@MENU_YES", DELETE_ACTION, play "mouse_over", ;, 1, name yes_button; )
		CHOICE_BUTTON_FOCUS_VIS_EX( 4, "@MENU_NO", DELETE_ONESC, play "mouse_over", ;, 1, name no_button; )
	}
	
	/////////////////////
	//
	// Check for number of friends limit.
	//
	/////////////////////

	menuDef
	{
		CENTER_POPUP_SETUP( friends_too_many, 3, ;, 1 )
		onClose { }
		
		CHOICE_POPMENU_TITLE( "@PLATFORM_FRIEND_LIMIT_TITLE" )
		CHOICE_POPMENU_SUBTITLE( "@MENU_FRIENDSLIMIT" )

		CHOICE_BUTTON( 3, "@MENU_OK", close self; )
	}

	/////////////////////
	//
	// Expired invite - friend not online.
	//
	/////////////////////

	menuDef
	{
		CENTER_POPUP_SETUP( friends_not_online, 3, ;, 1 )
		onClose { }
		
		CHOICE_POPMENU_TITLE( "@PLATFORM_EXPIRED_INVITE_TITLE" )
		CHOICE_POPMENU_SUBTITLE( "@MENU_EXPIRED_INVITE" )

		CHOICE_BUTTON( 3, "@MENU_OK", close self; )
	}

	/////////////////////
	//
	// Invite sent confirmation popup.
	//
	/////////////////////

	menuDef
	{
		CENTER_POPUP_SETUP( invite_sent, 3, ;, 1 )
		onClose { }
		
		CHOICE_POPMENU_TITLE( "@PLATFORM_INVITE_SENT_TITLE" )
		CHOICE_POPMENU_SUBTITLE( "@MENU_INVITE_SENT" )

		CHOICE_BUTTON( 3, "@MENU_OK", close self; )
	}

	/////////////////////
	//
	// Invite accpeted confirmation popup.
	//
	/////////////////////

	menuDef
	{
		CENTER_POPUP_SETUP( invite_accepted, 3, ;, 1 )
		onClose { }
		
		CHOICE_POPMENU_TITLE( "@PLATFORM_INVITE_ACCEPTED_TITLE" )
		CHOICE_POPMENU_SUBTITLE( "@MENU_INVITE_ACCEPTED" )

		CHOICE_BUTTON( 3, "@MENU_OK", close self; )
	}

	/////////////////////
	//
	// Outgoing request to friend already sent.
	//
	/////////////////////

	menuDef
	{
		CENTER_POPUP_SETUP( request_sent, 3, ;, 1 )
		onClose { }
		
		CHOICE_POPMENU_TITLE( "@PLATFORM_REQUEST_SENT_TITLE" )
		CHOICE_POPMENU_SUBTITLE( "@MENU_REQUEST_SENT" )

		CHOICE_BUTTON( 3, "@MENU_OK", close self; )
	}

	/////////////////////
	//
	// Friend name doesn not exist.
	//
	/////////////////////

	menuDef
	{
		CENTER_POPUP_SETUP( invalid_friend, 3, ;, 1 )
		onClose { }
		
		CHOICE_POPMENU_TITLE( "@PLATFORM_INVALID_ID_TITLE" )
		CHOICE_POPMENU_SUBTITLE( "@MENU_INVALID_FRIEND_ID" )

		CHOICE_BUTTON( 3, "@MENU_OK", close self; )
	}

	/////////////////////
	//
	// Can not send game invite to this person yet.
	//
	/////////////////////

	menuDef
	{
		CENTER_POPUP_SETUP( not_friends_yet, 3, ;, 1 )
		onClose { }
		
		CHOICE_POPMENU_TITLE( "@PLATFORM_NOT_FRIENDS_YET_TITLE" )
		CHOICE_POPMENU_SUBTITLE( "@MENU_NOT_FRIENDS_YET" )

		CHOICE_BUTTON( 3, "@MENU_OK", close self; )
	}

	/////////////////////
	//
	// Can not send friend request to yourself.
	//
	/////////////////////

	menuDef
	{
		CENTER_POPUP_SETUP( no_self_request_allowed, 3, ;, 1 )
		onClose { }
		
		CHOICE_POPMENU_TITLE( "@MENU_ERROR" )
		CHOICE_POPMENU_SUBTITLE( "@MENU_NO_SELF_REQUEST_ALLOWED" )

		CHOICE_BUTTON( 1, "@MENU_OK", close self; )
	}
	
	/////////////////////
	//
	// Already friends popup.
	//
	/////////////////////

	menuDef
	{
		CENTER_POPUP_SETUP( already_friends, 3, ;, 1 )
		onClose { }
		
		CHOICE_POPMENU_TITLE( "@PLATFORM_ALREADY_FRIENDS_TITLE" )
		CHOICE_POPMENU_SUBTITLE( "@PLATFORM_ALREADY_FRIENDS" )

		CHOICE_BUTTON( 3, "@MENU_OK", close self; )
	}

	/////////////////////
	//
	// Popup that appears whenever connection is lost and friends functionality is not accessible.
	//
	/////////////////////

	menuDef
	{
		CENTER_POPUP_SETUP( not_online_popmenu, 3, ;, 1 )
		onClose { }
		
		CHOICE_POPMENU_TITLE( "@PLATFORM_NOT_ONLINE_TITLE" )
		CHOICE_POPMENU_SUBTITLE( "@PLATFORM_NOT_ONLINE" )

		CHOICE_BUTTON( 3, "@MENU_OK", close self; )
	}
