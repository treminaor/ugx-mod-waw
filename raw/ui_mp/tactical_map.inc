#ifndef SPLITSCREEN_ENABLED
	#ifndef MAP_X
	#define MAP_X					(- (MAP_WIDTH - RIGHTITEM_OFFSET + 20 ))
	#endif
	
	#ifndef MAP_Y
	#define MAP_Y					114
	#endif
	
	#ifndef MAP_WIDTH
	#define MAP_WIDTH				240
	#endif
	
	#ifndef MAP_HEIGHT	
	#define MAP_HEIGHT				268
	#endif
	
	#define ORIGIN_MAP_FRAME		MAP_X MAP_Y
	#define MAP_WIDTH2				(MAP_WIDTH+5)
#else
	#ifndef MAP_X
	#define MAP_X					(- (MAP_WIDTH - RIGHTITEM_OFFSET+4 ))
	#endif
	
	#ifndef MAP_Y
	#define MAP_Y					27
	#endif
	
	#ifndef MAP_WIDTH
	#define MAP_WIDTH				140
	#endif
	
	#ifndef MAP_HEIGHT	
	#define MAP_HEIGHT				120
	#endif
	
	#define ORIGIN_MAP_FRAME		MAP_X MAP_Y
	#define MAP_WIDTH2				(MAP_WIDTH+5)
#endif

#ifndef TEAM_IS_MARINES
#error "TEAM_IS_MARINES undefined"
#endif

#ifndef TEAM_IS_OPFOR
#error "TEAM_IS_OPFOR undefined"
#endif

#define ALLIES_HAVE_UAV (dvarint( ui_uav_allies ) && team( name ) == "TEAM_ALLIES" )
#define AXIS_HAVE_UAV (dvarint( ui_uav_axis ) && team( name ) == "TEAM_AXIS" )
#define CLIENT_HAS_UAV (dvarint( ui_uav_client ) && team( name ) == "TEAM_FREE" )
//#define SHOULD_SHOW_MAP ( dvarbool( ui_hud_hardcore ) == 0 || ALLIES_HAVE_UAV || AXIS_HAVE_UAV || CLIENT_HAS_UAV )
#ifndef SHOULD_SHOW_MAP
#define SHOULD_SHOW_MAP 1
#endif

#ifndef SPLITSCREEN_ENABLED
	#define GAMETYPE_HEIGHT MAP_HEIGHT
#else
	#define GAMETYPE_HEIGHT (MAP_WIDTH+5)
#endif 

// map display ================================================

#define UI_MAP_NAME		"@"+tablelookup("mp/mapsTable.csv",0,dvarString(mapname),3)
#define MAP_OFFSET		0 21 //2 20

	itemDef
   	{
		name			"mini_map2"
		rect			ORIGIN_MAP_FRAME MAP_WIDTH MAP_WIDTH RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		origin			MAP_OFFSET
		forecolor		1 1 1 1
		background		"compass_map_default"
		ownerdraw		CG_PLAYER_FULLMAP_MAP
		visible			when ( SHOULD_SHOW_MAP );
		decoration
   	}

	itemDef
   	{
		style			WINDOW_STYLE_SHADER
		name			"mini_map2_overlay"
		rect			ORIGIN_MAP_FRAME MAP_WIDTH MAP_WIDTH RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		origin			MAP_OFFSET
		forecolor		1 1 1 1
		exp				material( tableLookup( "mp/mapsTable.csv", 0, dvarString( mapname ), 7 ) )
		visible			when ( SHOULD_SHOW_MAP );
		decoration
   	}
   	
	// Objective pointers
	itemDef
	{
		name			"compasspointers2"
		rect			ORIGIN_MAP_FRAME MAP_WIDTH MAP_WIDTH RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		origin			MAP_OFFSET
		forecolor		1 1 1 1
		background		"objective_line"
		ownerdraw		CG_PLAYER_FULLMAP_POINTERS
		visible			when ( SHOULD_SHOW_MAP );
		decoration
	}
   	// Friendlies pointers
	itemDef
	{
		name			"compassfriendlies2"
		rect			ORIGIN_MAP_FRAME MAP_WIDTH MAP_WIDTH RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		origin			MAP_OFFSET
		forecolor		1 1 1 1
		background		"compassping_friendly"
		ownerdraw		CG_PLAYER_FULLMAP_FRIENDS
		visible			when ( SHOULD_SHOW_MAP );
		decoration
	}
   	// Enemy pings
	itemDef
	{
		name			"compassenemies2"
		rect			ORIGIN_MAP_FRAME MAP_WIDTH MAP_WIDTH RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		origin			MAP_OFFSET
		forecolor		1 1 1 1
		background		"compassping_enemy"
		ownerdraw		CG_PLAYER_FULLMAP_ENEMIES
		visible			when ( SHOULD_SHOW_MAP );
		decoration
	}
	// Player direction indicator
	itemDef
	{
		name			"compassplayer2"
		rect			ORIGIN_MAP_FRAME MAP_WIDTH MAP_WIDTH RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		origin			MAP_OFFSET
		forecolor		1 1 1 1
		background		"compassping_player"
		ownerdraw		CG_PLAYER_FULLMAP_PLAYER
		visible			when ( SHOULD_SHOW_MAP );
		decoration
	}		
	// Vehicles
	itemDef
	{
		name			"mapvehicles"
		rect			ORIGIN_MAP_FRAME MAP_WIDTH MAP_WIDTH RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		origin			MAP_OFFSET
		forecolor		1 1 1 1
		ownerdraw		CG_PLAYER_FULLMAP_VEHICLES
		visible			when ( SHOULD_SHOW_MAP );
		decoration
	}	
   	// Squad Objective
	itemDef
	{
		name			"mapsquadobjective"
		rect			ORIGIN_MAP_FRAME MAP_WIDTH MAP_WIDTH RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		origin			MAP_OFFSET
		forecolor		1 1 1 1
		ownerdraw		CG_PLAYER_FULLMAP_SQUAD_OBJECTIVE
		visible			when ( SHOULD_SHOW_MAP );
		decoration
	}
   	// Artillery Icon
	itemDef
	{
		name			"mapartilleryicon"
		rect			ORIGIN_MAP_FRAME MAP_WIDTH MAP_WIDTH RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		origin			MAP_OFFSET
		forecolor		1 1 1 1
		ownerdraw		CG_PLAYER_FULLMAP_ARTILLERY_ICON
		visible			when ( SHOULD_SHOW_MAP );
		decoration
	}
	// Dogs
	itemDef
	{
		name			"mapdogs"
		rect			ORIGIN_MAP_FRAME MAP_WIDTH MAP_WIDTH RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		origin			MAP_OFFSET
		forecolor		1 1 1 1
		ownerdraw		CG_PLAYER_FULLMAP_DOGS
		visible			when ( SHOULD_SHOW_MAP );
		decoration
	}

	// Map name and gametype
	PREPROC_TEXT_DRAW_ALIGNED_VIS( ORIGIN_MAP_FRAME MAP_WIDTH 20 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, 5 20, UI_MAP_NAME, TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_LEFT, 1 1 1 0.7, when( SHOULD_SHOW_MAP ) )
	itemDef	{
		rect			ORIGIN_MAP_FRAME MAP_WIDTH 20 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		origin			-4 (GAMETYPE_HEIGHT+16)
		textfont		UI_FONT_NORMAL
		textstyle		ITEM_TEXTSTYLE_SHADOWED
		textscale		CHOICE_TEXTSIZE
		textalign		ITEM_ALIGN_RIGHT
		forecolor		1 1 1 0.85
		exp text ( gametypename() );
		visible			when ( SHOULD_SHOW_MAP );
		decoration
	}
