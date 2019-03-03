#define STAT_CAC			260
#define	STAT_CHALLENGES		263
#define STAT_CLAN_TAG		261
#define STAT_PRESTIGE		259

#define STAT_CHALLENGE_TIER1	270
#define STAT_CHALLENGE_TIER2	271
#define STAT_CHALLENGE_TIER3	272
#define STAT_CHALLENGE_TIER4	273
#define STAT_CHALLENGE_TIER5	274
#define STAT_CHALLENGE_TIER6	275
#define STAT_CHALLENGE_TIER7	276
#define STAT_CHALLENGE_TIER8	277
#define STAT_CHALLENGE_TIER9	278
#define STAT_CHALLENGE_TIER10	279

#define WEAPON_NEW_BITMASK		65536
#define NEW_WEAPON_BITMASK		65536

#define ATTACHMENT1_NEW_BITMASK	131072
#define ATTACHMENT2_NEW_BITMASK	262144
#define ATTACHMENT3_NEW_BITMASK	524288
#define ATTACHMENT4_NEW_BITMASK	1048576

/*
#define SCOPED_NEW_BITMASK		131072
#define APERTURE_NEW_BITMASK	262144
#define SILENCED_NEW_BITMASK	524288
#define GRIP_NEW_BITMASK		1048576
#define RG_NEW_BITMASK			2097152
#define COMP_NEW_BITMASK		4194304
#define BIGAMMO_NEW_BITMASK		8388608
#define FLASH_NEW_BITMASK		16777216
#define BIPOD_NEW_BITMASK		33554432
#define SAWOFF_NEW_BITMASK		67108864
#define BAYONET_NEW_BITMASK	134217728
#define TELESCOPIC_NEW_BITMASK	268435456
*/

#define REICH_NEW_BITMASK		16777216
#define SIBERIAN_NEW_BITMASK	33554432	
#define ROYAL_NEW_BITMASK		67108864
#define YANKEE_NEW_BITMASK		134217728
#define RISINGSUN_NEW_BITMASK	268435456	
#define GOLDEN_NEW_BITMASK		536870912
#define PRESTIGE_NEW_BITMASK	1073741824

#define NEW_ATTACHMENTS_MASK	(ATTACHMENT1_NEW_BITMASK + ATTACHMENT2_NEW_BITMASK + ATTACHMENT3_NEW_BITMASK + ATTACHMENT4_NEW_BITMASK)
#define NEW_CAMO_MASK			(REICH_NEW_BITMASK + SIBERIAN_NEW_BITMASK + ROYAL_NEW_BITMASK + YANKEE_NEW_BITMASK + RISINGSUN_NEW_BITMASK + GOLDEN_NEW_BITMASK + PRESTIGE_NEW_BITMASK)
#define NEW_ITEMS_MASK			NEW_ATTACHMENTS_MASK

#define ANY_NEW_WEAPONS_ITEMS	(statRangeAnyBitsSet( 3000, 3089, NEW_ITEMS_MASK ))
#define ANY_NEW_WEAPONS			(statRangeAnyBitsSet( 3000, 3089, WEAPON_NEW_BITMASK ))

#define ANY_NEW_PERK1			( stat(150) > 1 || stat(151) > 1 || stat(180) > 1 || stat(182) > 1 || statRangeAnyBitsSet( 184, 187, 2 ) )
#define ANY_NEW_PERK2			( statRangeAnyBitsSet( 152, 159, 2 ) || stat(161) > 1 || stat(162) > 1 )
#define ANY_NEW_PERK3			( stat(160) > 1 || statRangeAnyBitsSet( 163, 171, 2 ) )
#define ANY_NEW_PERK4			( statRangeAnyBitsSet( 172, 176, 2 ) )
#define ANY_NEW_PERKS			( ANY_NEW_PERK1 || ANY_NEW_PERK2 || ANY_NEW_PERK3 || ANY_NEW_PERK4 )
#define ANY_NEW_PGRENADE		( stat(3100) > 1 || stat(3101) > 1 )

#define ANY_NEW_CAC				( ( ANY_NEW_WEAPONS || ANY_NEW_PERKS || ANY_NEW_PGRENADE ) && stat(260) >= 1 )

#define ANY_NEW_CHALLENGES		(statRangeAnyBitsSet(270, 281, 2) || stat(263) > 1)

#define ANY_NEW_BARRACKS		(ANY_NEW_CHALLENGES||stat(261)>1||stat(259)>1)

#define CAC_PRIMARY_STORAGE		2400
#define CAC_SECONDARY_STORAGE	2401
#define CAC_S_PRIMARY_STORAGE	"2400"
#define CAC_S_SECONDARY_STORAGE	"2401"
#define CAC_TEMP_STORAGE		2402
#define CAC_S_TEMP_STORAGE		"2402"

/* 	refString: "m16", "m4", etc...
	Puts the weapons stat index (3000 to 3089) into temp storage stat.
	Puts that into a temp dvar.
	Clear the weapon new bit at that stat address.
	Clears the temp storage stat good measure.
*/
#define CLEAR_WEAP_NEW( refString ) \
	statsetusingtable( CAC_TEMP_STORAGE, tableLookup( "mp/statstable.csv", 4, refString, 1 ) ); \
	statGetInDvarUsingTable( CAC_S_TEMP_STORAGE, ui_tempStorage ); \
	CLEAR_NEW( ui_tempStorage, WEAPON_NEW_BITMASK ); \
	setDvar ui_tempStorage "";

#define CLEAR_PERK_NEW( refString, bitMask ) \
	statsetusingtable( CAC_PRIMARY_STORAGE, tablelookup( "mp/statstable.csv", 4, refString, 1 ) ); \
	statGetInDvarUsingTable( CAC_S_PRIMARY_STORAGE, ui_evil_dvar ); \
	setDvar ui_tempMask bitMask; \
	statClearBitMask ui_evil_dvar ui_tempMask; \
	setDvar ui_tempMask 1; \
	statSetBitMask ui_evil_dvar ui_tempMask;

#define CLEAR_NEW( statDvar, bitMask ) \
	setDvar ui_tempMask bitMask; \
	statClearBitMask statDvar ui_tempMask;
