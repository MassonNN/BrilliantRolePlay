/*==============================================================================
		Animations System v1.2
			by Daniel_Cortez

http://pro-pawn.ru/showthread.php?9482-dc_anims

Copyright (c) 2014-2015 Daniel_Cortez
This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the
use of this software. Permission is granted to anyone to use this software for
any purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:
	1.	The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software. If you use this software in
		a product, an acknowledgment in the product documentation would be
		appreciated but is not required.
	2.	Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
	3.	This notice may not be removed or altered from any source distribution.
==============================================================================*/


#if defined DC__ANIMS
	#endinput
#endif
#define	DC__ANIMS


#include <a_samp>

#if defined CMD
	#define anim__func:%0(%1) CMD:%0(%1)
#else
	#define anim__func:%0(%1) anim__func_%0(%1)
	#if	!defined	isnull
		#define isnull(%0) \
			((%0[0]) == EOS)
	#endif
	#if	!defined	MAX_FUNCTION_NAME
		#define	MAX_FUNCTION_NAME	31
	#endif
#endif


#if	!defined	SPECIAL_ACTION_PISSING
	#define	SPECIAL_ACTION_PISSING	68
#endif

#if	!defined	DC_ANIMS_COLOR
	#define	DC_ANIMS_COLOR	"{70A0E0}"
#endif
#if	!defined	DC_ANIMS_ERROR_COLOR
	#define	DC_ANIMS_ERROR_COLOR	"{A0A0A0}"
#endif

#if	!defined	MAX_ACTION_NAME
	#define MAX_ACTION_NAME 7
#endif
#if	!defined	MAX_ANIM_LIB_NAME
	#define	MAX_ANIM_LIB_NAME 15
#endif
#if	!defined MAX_ANIM_NAME
	#define	MAX_ANIM_NAME 23
#endif

#define	_AnimLib(%0)	{{!#%0}, -1, -1}
#define	_Anim(%0,%1)	{ANIMLIB_%0, {!#%1}}

enum e_ANIM_LIB_INFO
{
	eAnimLib_Name[(MAX_ANIM_LIB_NAME+1)/(cellbits/charbits)],
	eAnimLib_FirstAnim,
	eAnimLib_LastAnim
};

enum e_ANIM_INFO
{
	eAnim_LibID,
	eAnim_Name[(MAX_ANIM_NAME+1)/(cellbits/charbits)]
};


enum
{
	ANIMLIB_AIRPORT = 0,
	ANIMLIB_Attractors,
	ANIMLIB_BAR,
	ANIMLIB_BASEBALL,
	ANIMLIB_BD_FIRE,
	ANIMLIB_BEACH,
	ANIMLIB_benchpress,
	ANIMLIB_BF_injection,
	ANIMLIB_BIKED,
	ANIMLIB_BIKEH,
	ANIMLIB_BIKELEAP,
	ANIMLIB_BIKES,
	ANIMLIB_BIKEV,
	ANIMLIB_BIKE_DBZ,
	ANIMLIB_BLOWJOBZ,
	ANIMLIB_BMX,
	ANIMLIB_BOMBER,
	ANIMLIB_BOX,
	ANIMLIB_BSKTBALL,
	ANIMLIB_BUDDY,
	ANIMLIB_BUS,
	ANIMLIB_CAMERA,
	ANIMLIB_CAR,
	ANIMLIB_CARRY,
	ANIMLIB_CAR_CHAT,
	ANIMLIB_CASINO,
	ANIMLIB_CHAINSAW,
	ANIMLIB_CHOPPA,
	ANIMLIB_CLOTHES,
	ANIMLIB_COACH,
	ANIMLIB_COLT45,
	ANIMLIB_COP_AMBIENT,
	ANIMLIB_COP_DVBYZ,
	ANIMLIB_CRACK,
	ANIMLIB_CRIB,
	ANIMLIB_DAM_JUMP,
	ANIMLIB_DANCING,
	ANIMLIB_DEALER,
	ANIMLIB_DILDO,
	ANIMLIB_DODGE,
	ANIMLIB_DOZER,
	ANIMLIB_DRIVEBYS,
	ANIMLIB_FAT,
	ANIMLIB_FIGHT_B,
	ANIMLIB_FIGHT_C,
	ANIMLIB_FIGHT_D,
	ANIMLIB_FIGHT_E,
	ANIMLIB_FINALE,
	ANIMLIB_FINALE2,
	ANIMLIB_FLAME,
	ANIMLIB_Flowers,
	ANIMLIB_FOOD,
	ANIMLIB_Freeweights,
	ANIMLIB_GANGS,
	ANIMLIB_GFUNK,
	ANIMLIB_GHANDS,
	ANIMLIB_GHETTO_DB,
	ANIMLIB_goggles,
	ANIMLIB_GRAFFITI,
	ANIMLIB_GRAVEYARD,
	ANIMLIB_GRENADE,
	ANIMLIB_GYMNASIUM,
	ANIMLIB_HAIRCUTS,
	ANIMLIB_HEIST9,
	ANIMLIB_INT_HOUSE,
	ANIMLIB_INT_OFFICE,
	ANIMLIB_INT_SHOP,
	ANIMLIB_JST_BUISNESS,
	ANIMLIB_KART,
	ANIMLIB_KISSING,
	ANIMLIB_KNIFE,
	ANIMLIB_LAPDAN1,
	ANIMLIB_LAPDAN2,
	ANIMLIB_LAPDAN3,
	ANIMLIB_LOWRIDER,
	ANIMLIB_MD_CHASE,
	ANIMLIB_MD_END,
	ANIMLIB_MEDIC,
	ANIMLIB_MISC,
	ANIMLIB_MTB,
	ANIMLIB_MUSCULAR,
	ANIMLIB_NEVADA,
	ANIMLIB_ON_LOOKERS,
	ANIMLIB_OTB,
	ANIMLIB_PARACHUTE,
	ANIMLIB_PARK,
	ANIMLIB_PAULNMAC,
	ANIMLIB_ped,
	ANIMLIB_PLAYER_DVBYS,
	ANIMLIB_PLAYIDLES,
	ANIMLIB_POLICE,
	ANIMLIB_POOL,
	ANIMLIB_POOR,
	ANIMLIB_PYTHON,
	ANIMLIB_QUAD,
	ANIMLIB_QUAD_DBZ,
	ANIMLIB_RAPPING,
	ANIMLIB_RIFLE,
	ANIMLIB_RIOT,
	ANIMLIB_ROB_BANK,
	ANIMLIB_ROCKET,
	ANIMLIB_RUNNINGMAN,
	ANIMLIB_RUSTLER,
	ANIMLIB_RYDER,
	ANIMLIB_SCRATCHING,
	ANIMLIB_SEX,
	ANIMLIB_SHAMAL,
	ANIMLIB_SHOP,
	ANIMLIB_SHOTGUN,
	ANIMLIB_SILENCED,
	ANIMLIB_SKATE,
	ANIMLIB_SMOKING,
	ANIMLIB_SNIPER,
	ANIMLIB_SnM,
	ANIMLIB_SPRAYCAN,
	ANIMLIB_STRIP,
	ANIMLIB_SUNBATHE,
	ANIMLIB_SWAT,
	ANIMLIB_SWEET,
	ANIMLIB_SWIM,
	ANIMLIB_SWORD,
	ANIMLIB_TANK,
	ANIMLIB_TATTOOS,
	ANIMLIB_TEC,
	ANIMLIB_TRAIN,
	ANIMLIB_TRUCK,
	ANIMLIB_UZI,
	ANIMLIB_VAN,
	ANIMLIB_VENDING,
	ANIMLIB_VORTEX,
	ANIMLIB_WAYFARER,
	ANIMLIB_WEAPONS,
	ANIMLIB_WOP,
	ANIMLIB_WUZI
};

static const anim__libs[][e_ANIM_LIB_INFO] =
{
	_AnimLib(AIRPORT),
	_AnimLib(Attractors),
	_AnimLib(BAR),
	_AnimLib(BASEBALL),
	_AnimLib(BD_FIRE),
	_AnimLib(BEACH),
	_AnimLib(benchpress),
	_AnimLib(BF_injection),
	_AnimLib(BIKED),
	_AnimLib(BIKEH),
	_AnimLib(BIKELEAP),
	_AnimLib(BIKES),
	_AnimLib(BIKEV),
	_AnimLib(BIKE_DBZ),
	_AnimLib(BLOWJOBZ),
	_AnimLib(BMX),
	_AnimLib(BOMBER),
	_AnimLib(BOX),
	_AnimLib(BSKTBALL),
	_AnimLib(BUDDY),
	_AnimLib(BUS),
	_AnimLib(CAMERA),
	_AnimLib(CAR),
	_AnimLib(CARRY),
	_AnimLib(CAR_CHAT),
	_AnimLib(CASINO),
	_AnimLib(CHAINSAW),
	_AnimLib(CHOPPA),
	_AnimLib(CLOTHES),
	_AnimLib(COACH),
	_AnimLib(COLT45),
	_AnimLib(COP_AMBIENT),
	_AnimLib(COP_DVBYZ),
	_AnimLib(CRACK),
	_AnimLib(CRIB),
	_AnimLib(DAM_JUMP),
	_AnimLib(DANCING),
	_AnimLib(DEALER),
	_AnimLib(DILDO),
	_AnimLib(DODGE),
	_AnimLib(DOZER),
	_AnimLib(DRIVEBYS),
	_AnimLib(FAT),
	_AnimLib(FIGHT_B),
	_AnimLib(FIGHT_C),
	_AnimLib(FIGHT_D),
	_AnimLib(FIGHT_E),
	_AnimLib(FINALE),
	_AnimLib(FINALE2),
	_AnimLib(FLAME),
	_AnimLib(Flowers),
	_AnimLib(FOOD),
	_AnimLib(Freeweights),
	_AnimLib(GANGS),
	_AnimLib(GFUNK),
	_AnimLib(GHANDS),
	_AnimLib(GHETTO_DB),
	_AnimLib(goggles),
	_AnimLib(GRAFFITI),
	_AnimLib(GRAVEYARD),
	_AnimLib(GRENADE),
	_AnimLib(GYMNASIUM),
	_AnimLib(HAIRCUTS),
	_AnimLib(HEIST9),
	_AnimLib(INT_HOUSE),
	_AnimLib(INT_OFFICE),
	_AnimLib(INT_SHOP),
	_AnimLib(JST_BUISNESS),
	_AnimLib(KART),
	_AnimLib(KISSING),
	_AnimLib(KNIFE),
	_AnimLib(LAPDAN1),
	_AnimLib(LAPDAN2),
	_AnimLib(LAPDAN3),
	_AnimLib(LOWRIDER),
	_AnimLib(MD_CHASE),
	_AnimLib(MD_END),
	_AnimLib(MEDIC),
	_AnimLib(MISC),
	_AnimLib(MTB),
	_AnimLib(MUSCULAR),
	_AnimLib(NEVADA),
	_AnimLib(ON_LOOKERS),
	_AnimLib(OTB),
	_AnimLib(PARACHUTE),
	_AnimLib(PARK),
	_AnimLib(PAULNMAC),
	_AnimLib(ped),
	_AnimLib(PLAYER_DVBYS),
	_AnimLib(PLAYIDLES),
	_AnimLib(POLICE),
	_AnimLib(POOL),
	_AnimLib(POOR),
	_AnimLib(PYTHON),
	_AnimLib(QUAD),
	_AnimLib(QUAD_DBZ),
	_AnimLib(RAPPING),
	_AnimLib(RIFLE),
	_AnimLib(RIOT),
	_AnimLib(ROB_BANK),
	_AnimLib(ROCKET),
	_AnimLib(RUNNINGMAN),
	_AnimLib(RUSTLER),
	_AnimLib(RYDER),
	_AnimLib(SCRATCHING),
	_AnimLib(SEX),
	_AnimLib(SHAMAL),
	_AnimLib(SHOP),
	_AnimLib(SHOTGUN),
	_AnimLib(SILENCED),
	_AnimLib(SKATE),
	_AnimLib(SMOKING),
	_AnimLib(SNIPER),
	_AnimLib(SnM),
	_AnimLib(SPRAYCAN),
	_AnimLib(STRIP),
	_AnimLib(SUNBATHE),
	_AnimLib(SWAT),
	_AnimLib(SWEET),
	_AnimLib(SWIM),
	_AnimLib(SWORD),
	_AnimLib(TANK),
	_AnimLib(TATTOOS),
	_AnimLib(TEC),
	_AnimLib(TRAIN),
	_AnimLib(TRUCK),
	_AnimLib(UZI),
	_AnimLib(VAN),
	_AnimLib(VENDING),
	_AnimLib(VORTEX),
	_AnimLib(WAYFARER),
	_AnimLib(WEAPONS),
	_AnimLib(WOP),
	_AnimLib(WUZI)
};

static const anim__info[][e_ANIM_INFO] =
{
// Name: AIRPORT, animations count: 1
	_Anim(AIRPORT, thrw_barl_thrw),
// Name: Attractors, animations count: 3
	_Anim(Attractors, Stepsit_in),
	_Anim(Attractors, Stepsit_loop),
	_Anim(Attractors, Stepsit_out),
// Name: BAR, animations count: 12
	_Anim(BAR, Barcustom_get),
	_Anim(BAR, Barcustom_loop),
	_Anim(BAR, Barcustom_order),
	_Anim(BAR, BARman_idle),
	_Anim(BAR, Barserve_bottle),
	_Anim(BAR, Barserve_give),
	_Anim(BAR, Barserve_glass),
	_Anim(BAR, Barserve_in),
	_Anim(BAR, Barserve_loop),
	_Anim(BAR, Barserve_order),
	_Anim(BAR, dnk_stndF_loop),
	_Anim(BAR, dnk_stndM_loop),
// Name: BASEBALL, animations count: 11
	_Anim(BASEBALL, Bat_1),
	_Anim(BASEBALL, Bat_2),
	_Anim(BASEBALL, Bat_3),
	_Anim(BASEBALL, Bat_4),
	_Anim(BASEBALL, Bat_block),
	_Anim(BASEBALL, Bat_Hit_1),
	_Anim(BASEBALL, Bat_Hit_2),
	_Anim(BASEBALL, Bat_Hit_3),
	_Anim(BASEBALL, Bat_IDLE),
	_Anim(BASEBALL, Bat_M),
	_Anim(BASEBALL, BAT_PART),
// Name: BD_FIRE, animations count: 13
	_Anim(BD_FIRE, BD_Fire1),
	_Anim(BD_FIRE, BD_Fire2),
	_Anim(BD_FIRE, BD_Fire3),
	_Anim(BD_FIRE, BD_GF_Wave),
	_Anim(BD_FIRE, BD_Panic_01),
	_Anim(BD_FIRE, BD_Panic_02),
	_Anim(BD_FIRE, BD_Panic_03),
	_Anim(BD_FIRE, BD_Panic_04),
	_Anim(BD_FIRE, BD_Panic_Loop),
	_Anim(BD_FIRE, Grlfrd_Kiss_03),
	_Anim(BD_FIRE, M_smklean_loop),
	_Anim(BD_FIRE, Playa_Kiss_03),
	_Anim(BD_FIRE, wash_up),
// Name: BEACH, animations count: 5
	_Anim(BEACH, bather),
	_Anim(BEACH, Lay_Bac_Loop),
	_Anim(BEACH, ParkSit_M_loop),
	_Anim(BEACH, ParkSit_W_loop),
	_Anim(BEACH, SitnWait_loop_W),
// Name: benchpress, animations count: 7
	_Anim(benchpress, gym_bp_celebrate),
	_Anim(benchpress, gym_bp_down),
	_Anim(benchpress, gym_bp_getoff),
	_Anim(benchpress, gym_bp_geton),
	_Anim(benchpress, gym_bp_up_A),
	_Anim(benchpress, gym_bp_up_B),
	_Anim(benchpress, gym_bp_up_smooth),
// Name: BF_injection, animations count: 4
	_Anim(BF_injection, BF_getin_LHS),
	_Anim(BF_injection, BF_getin_RHS),
	_Anim(BF_injection, BF_getout_LHS),
	_Anim(BF_injection, BF_getout_RHS),
// Name: BIKED, animations count: 19
	_Anim(BIKED, BIKEd_Back),
	_Anim(BIKED, BIKEd_drivebyFT),
	_Anim(BIKED, BIKEd_drivebyLHS),
	_Anim(BIKED, BIKEd_drivebyRHS),
	_Anim(BIKED, BIKEd_Fwd),
	_Anim(BIKED, BIKEd_getoffBACK),
	_Anim(BIKED, BIKEd_getoffLHS),
	_Anim(BIKED, BIKEd_getoffRHS),
	_Anim(BIKED, BIKEd_hit),
	_Anim(BIKED, BIKEd_jumponL),
	_Anim(BIKED, BIKEd_jumponR),
	_Anim(BIKED, BIKEd_kick),
	_Anim(BIKED, BIKEd_Left),
	_Anim(BIKED, BIKEd_passenger),
	_Anim(BIKED, BIKEd_pushes),
	_Anim(BIKED, BIKEd_Ride),
	_Anim(BIKED, BIKEd_Right),
	_Anim(BIKED, BIKEd_shuffle),
	_Anim(BIKED, BIKEd_Still),
// Name: BIKEH, animations count: 18
	_Anim(BIKEH, BIKEh_Back),
	_Anim(BIKEH, BIKEh_drivebyFT),
	_Anim(BIKEH, BIKEh_drivebyLHS),
	_Anim(BIKEH, BIKEh_drivebyRHS),
	_Anim(BIKEH, BIKEh_Fwd),
	_Anim(BIKEH, BIKEh_getoffBACK),
	_Anim(BIKEH, BIKEh_getoffLHS),
	_Anim(BIKEH, BIKEh_getoffRHS),
	_Anim(BIKEH, BIKEh_hit),
	_Anim(BIKEH, BIKEh_jumponL),
	_Anim(BIKEH, BIKEh_jumponR),
	_Anim(BIKEH, BIKEh_kick),
	_Anim(BIKEH, BIKEh_Left),
	_Anim(BIKEH, BIKEh_passenger),
	_Anim(BIKEH, BIKEh_pushes),
	_Anim(BIKEH, BIKEh_Ride),
	_Anim(BIKEH, BIKEh_Right),
	_Anim(BIKEH, BIKEh_Still),
// Name: BIKELEAP, animations count: 9
	_Anim(BIKELEAP, bk_blnce_in),
	_Anim(BIKELEAP, bk_blnce_out),
	_Anim(BIKELEAP, bk_jmp),
	_Anim(BIKELEAP, bk_rdy_in),
	_Anim(BIKELEAP, bk_rdy_out),
	_Anim(BIKELEAP, struggle_cesar),
	_Anim(BIKELEAP, struggle_driver),
	_Anim(BIKELEAP, truck_driver),
	_Anim(BIKELEAP, truck_getin),
// Name: BIKES, animations count: 20
	_Anim(BIKES, BIKEs_Back),
	_Anim(BIKES, BIKEs_drivebyFT),
	_Anim(BIKES, BIKEs_drivebyLHS),
	_Anim(BIKES, BIKEs_drivebyRHS),
	_Anim(BIKES, BIKEs_Fwd),
	_Anim(BIKES, BIKEs_getoffBACK),
	_Anim(BIKES, BIKEs_getoffLHS),
	_Anim(BIKES, BIKEs_getoffRHS),
	_Anim(BIKES, BIKEs_hit),
	_Anim(BIKES, BIKEs_jumponL),
	_Anim(BIKES, BIKEs_jumponR),
	_Anim(BIKES, BIKEs_kick),
	_Anim(BIKES, BIKEs_Left),
	_Anim(BIKES, BIKEs_passenger),
	_Anim(BIKES, BIKEs_pushes),
	_Anim(BIKES, BIKEs_Ride),
	_Anim(BIKES, BIKEs_Right),
	_Anim(BIKES, BIKEs_Snatch_L),
	_Anim(BIKES, BIKEs_Snatch_R),
	_Anim(BIKES, BIKEs_Still),
// Name: BIKEV, animations count: 18
	_Anim(BIKEV, BIKEv_Back),
	_Anim(BIKEV, BIKEv_drivebyFT),
	_Anim(BIKEV, BIKEv_drivebyLHS),
	_Anim(BIKEV, BIKEv_drivebyRHS),
	_Anim(BIKEV, BIKEv_Fwd),
	_Anim(BIKEV, BIKEv_getoffBACK),
	_Anim(BIKEV, BIKEv_getoffLHS),
	_Anim(BIKEV, BIKEv_getoffRHS),
	_Anim(BIKEV, BIKEv_hit),
	_Anim(BIKEV, BIKEv_jumponL),
	_Anim(BIKEV, BIKEv_jumponR),
	_Anim(BIKEV, BIKEv_kick),
	_Anim(BIKEV, BIKEv_Left),
	_Anim(BIKEV, BIKEv_passenger),
	_Anim(BIKEV, BIKEv_pushes),
	_Anim(BIKEV, BIKEv_Ride),
	_Anim(BIKEV, BIKEv_Right),
	_Anim(BIKEV, BIKEv_Still),
// Name: BIKE_DBZ, animations count: 4
	_Anim(BIKE_DBZ, Pass_Driveby_BWD),
	_Anim(BIKE_DBZ, Pass_Driveby_FWD),
	_Anim(BIKE_DBZ, Pass_Driveby_LHS),
	_Anim(BIKE_DBZ, Pass_Driveby_RHS),
// Name: BLOWJOBZ, animations count: 18
	_Anim(BLOWJOBZ, BJ_Car_End_P),
	_Anim(BLOWJOBZ, BJ_Car_End_W),
	_Anim(BLOWJOBZ, BJ_Car_Loop_P),
	_Anim(BLOWJOBZ, BJ_Car_Loop_W),
	_Anim(BLOWJOBZ, BJ_Car_Start_P),
	_Anim(BLOWJOBZ, BJ_Car_Start_W),
	_Anim(BLOWJOBZ, BJ_Couch_End_P),
	_Anim(BLOWJOBZ, BJ_Couch_End_W),
	_Anim(BLOWJOBZ, BJ_Couch_Loop_P),
	_Anim(BLOWJOBZ, BJ_Couch_Loop_W),
	_Anim(BLOWJOBZ, BJ_Couch_Start_P),
	_Anim(BLOWJOBZ, BJ_Couch_Start_W),
	_Anim(BLOWJOBZ, BJ_Stand_End_P),
	_Anim(BLOWJOBZ, BJ_Stand_End_W),
	_Anim(BLOWJOBZ, BJ_Stand_Loop_P),
	_Anim(BLOWJOBZ, BJ_Stand_Loop_W),
	_Anim(BLOWJOBZ, BJ_Stand_Start_P),
	_Anim(BLOWJOBZ, BJ_Stand_Start_W),
// Name: BMX, animations count: 18
	_Anim(BMX, BMX_back),
	_Anim(BMX, BMX_bunnyhop),
	_Anim(BMX, BMX_drivebyFT),
	_Anim(BMX, BMX_driveby_LHS),
	_Anim(BMX, BMX_driveby_RHS),
	_Anim(BMX, BMX_fwd),
	_Anim(BMX, BMX_getoffBACK),
	_Anim(BMX, BMX_getoffLHS),
	_Anim(BMX, BMX_getoffRHS),
	_Anim(BMX, BMX_jumponL),
	_Anim(BMX, BMX_jumponR),
	_Anim(BMX, BMX_Left),
	_Anim(BMX, BMX_pedal),
	_Anim(BMX, BMX_pushes),
	_Anim(BMX, BMX_Ride),
	_Anim(BMX, BMX_Right),
	_Anim(BMX, BMX_sprint),
	_Anim(BMX, BMX_still),
// Name: BOMBER, animations count: 6
	_Anim(BOMBER, BOM_Plant),
	_Anim(BOMBER, BOM_Plant_2Idle),
	_Anim(BOMBER, BOM_Plant_Crouch_In),
	_Anim(BOMBER, BOM_Plant_Crouch_Out),
	_Anim(BOMBER, BOM_Plant_In),
	_Anim(BOMBER, BOM_Plant_Loop),
// Name: BOX, animations count: 10
	_Anim(BOX, boxhipin),
	_Anim(BOX, boxhipup),
	_Anim(BOX, boxshdwn),
	_Anim(BOX, boxshup),
	_Anim(BOX, bxhipwlk),
	_Anim(BOX, bxhwlki),
	_Anim(BOX, bxshwlk),
	_Anim(BOX, bxshwlki),
	_Anim(BOX, bxwlko),
	_Anim(BOX, catch_box),
// Name: BSKTBALL, animations count: 41
	_Anim(BSKTBALL, BBALL_def_jump_shot),
	_Anim(BSKTBALL, BBALL_def_loop),
	_Anim(BSKTBALL, BBALL_def_stepL),
	_Anim(BSKTBALL, BBALL_def_stepR),
	_Anim(BSKTBALL, BBALL_Dnk),
	_Anim(BSKTBALL, BBALL_Dnk_Gli),
	_Anim(BSKTBALL, BBALL_Dnk_Gli_O),
	_Anim(BSKTBALL, BBALL_Dnk_Lnch),
	_Anim(BSKTBALL, BBALL_Dnk_Lnch_O),
	_Anim(BSKTBALL, BBALL_Dnk_Lnd),
	_Anim(BSKTBALL, BBALL_Dnk_O),
	_Anim(BSKTBALL, BBALL_idle),
	_Anim(BSKTBALL, BBALL_idle2),
	_Anim(BSKTBALL, BBALL_idle2_O),
	_Anim(BSKTBALL, BBALL_idleloop),
	_Anim(BSKTBALL, BBALL_idleloop_O),
	_Anim(BSKTBALL, BBALL_idle_O),
	_Anim(BSKTBALL, BBALL_Jump_Cancel),
	_Anim(BSKTBALL, BBALL_Jump_Cancel_O),
	_Anim(BSKTBALL, BBALL_Jump_End),
	_Anim(BSKTBALL, BBALL_Jump_Shot),
	_Anim(BSKTBALL, BBALL_Jump_Shot_O),
	_Anim(BSKTBALL, BBALL_Net_Dnk_O),
	_Anim(BSKTBALL, BBALL_pickup),
	_Anim(BSKTBALL, BBALL_pickup_O),
	_Anim(BSKTBALL, BBALL_react_miss),
	_Anim(BSKTBALL, BBALL_react_score),
	_Anim(BSKTBALL, BBALL_run),
	_Anim(BSKTBALL, BBALL_run_O),
	_Anim(BSKTBALL, BBALL_SkidStop_L),
	_Anim(BSKTBALL, BBALL_SkidStop_L_O),
	_Anim(BSKTBALL, BBALL_SkidStop_R),
	_Anim(BSKTBALL, BBALL_SkidStop_R_O),
	_Anim(BSKTBALL, BBALL_walk),
	_Anim(BSKTBALL, BBALL_WalkStop_L),
	_Anim(BSKTBALL, BBALL_WalkStop_L_O),
	_Anim(BSKTBALL, BBALL_WalkStop_R),
	_Anim(BSKTBALL, BBALL_WalkStop_R_O),
	_Anim(BSKTBALL, BBALL_walk_O),
	_Anim(BSKTBALL, BBALL_walk_start),
	_Anim(BSKTBALL, BBALL_walk_start_O),
// Name: BUDDY, animations count: 5
	_Anim(BUDDY, buddy_crouchfire),
	_Anim(BUDDY, buddy_crouchreload),
	_Anim(BUDDY, buddy_fire),
	_Anim(BUDDY, buddy_fire_poor),
	_Anim(BUDDY, buddy_reload),
// Name: BUS, animations count: 9
	_Anim(BUS, BUS_close),
	_Anim(BUS, BUS_getin_LHS),
	_Anim(BUS, BUS_getin_RHS),
	_Anim(BUS, BUS_getout_LHS),
	_Anim(BUS, BUS_getout_RHS),
	_Anim(BUS, BUS_jacked_LHS),
	_Anim(BUS, BUS_open),
	_Anim(BUS, BUS_open_RHS),
	_Anim(BUS, BUS_pullout_LHS),
// Name: CAMERA, animations count: 14
	_Anim(CAMERA, camcrch_cmon),
	_Anim(CAMERA, camcrch_idleloop),
	_Anim(CAMERA, camcrch_stay),
	_Anim(CAMERA, camcrch_to_camstnd),
	_Anim(CAMERA, camstnd_cmon),
	_Anim(CAMERA, camstnd_idleloop),
	_Anim(CAMERA, camstnd_lkabt),
	_Anim(CAMERA, camstnd_to_camcrch),
	_Anim(CAMERA, piccrch_in),
	_Anim(CAMERA, piccrch_out),
	_Anim(CAMERA, piccrch_take),
	_Anim(CAMERA, picstnd_in),
	_Anim(CAMERA, picstnd_out),
	_Anim(CAMERA, picstnd_take),
// Name: CAR, animations count: 11
	_Anim(CAR, Fixn_Car_Loop),
	_Anim(CAR, Fixn_Car_Out),
	_Anim(CAR, flag_drop),
	_Anim(CAR, Sit_relaxed),
	_Anim(CAR, Tap_hand),
	_Anim(CAR, Tyd2car_bump),
	_Anim(CAR, Tyd2car_high),
	_Anim(CAR, Tyd2car_low),
	_Anim(CAR, Tyd2car_med),
	_Anim(CAR, Tyd2car_TurnL),
	_Anim(CAR, Tyd2car_TurnR),
// Name: CARRY, animations count: 7
	_Anim(CARRY, crry_prtial),
	_Anim(CARRY, liftup),
	_Anim(CARRY, liftup05),
	_Anim(CARRY, liftup105),
	_Anim(CARRY, putdwn),
	_Anim(CARRY, putdwn05),
	_Anim(CARRY, putdwn105),
// Name: CAR_CHAT, animations count: 21
	_Anim(CAR_CHAT, carfone_in),
	_Anim(CAR_CHAT, carfone_loopA),
	_Anim(CAR_CHAT, carfone_loopA_to_B),
	_Anim(CAR_CHAT, carfone_loopB),
	_Anim(CAR_CHAT, carfone_loopB_to_A),
	_Anim(CAR_CHAT, carfone_out),
	_Anim(CAR_CHAT, CAR_Sc1_BL),
	_Anim(CAR_CHAT, CAR_Sc1_BR),
	_Anim(CAR_CHAT, CAR_Sc1_FL),
	_Anim(CAR_CHAT, CAR_Sc1_FR),
	_Anim(CAR_CHAT, CAR_Sc2_FL),
	_Anim(CAR_CHAT, CAR_Sc3_BR),
	_Anim(CAR_CHAT, CAR_Sc3_FL),
	_Anim(CAR_CHAT, CAR_Sc3_FR),
	_Anim(CAR_CHAT, CAR_Sc4_BL),
	_Anim(CAR_CHAT, CAR_Sc4_BR),
	_Anim(CAR_CHAT, CAR_Sc4_FL),
	_Anim(CAR_CHAT, CAR_Sc4_FR),
	_Anim(CAR_CHAT, car_talkm_in),
	_Anim(CAR_CHAT, car_talkm_loop),
	_Anim(CAR_CHAT, car_talkm_out),
// Name: CASINO, animations count: 25
	_Anim(CASINO, cards_in),
	_Anim(CASINO, cards_loop),
	_Anim(CASINO, cards_lose),
	_Anim(CASINO, cards_out),
	_Anim(CASINO, cards_pick_01),
	_Anim(CASINO, cards_pick_02),
	_Anim(CASINO, cards_raise),
	_Anim(CASINO, cards_win),
	_Anim(CASINO, dealone),
	_Anim(CASINO, manwinb),
	_Anim(CASINO, manwind),
	_Anim(CASINO, Roulette_bet),
	_Anim(CASINO, Roulette_in),
	_Anim(CASINO, Roulette_loop),
	_Anim(CASINO, Roulette_lose),
	_Anim(CASINO, Roulette_out),
	_Anim(CASINO, Roulette_win),
	_Anim(CASINO, Slot_bet_01),
	_Anim(CASINO, Slot_bet_02),
	_Anim(CASINO, Slot_in),
	_Anim(CASINO, Slot_lose_out),
	_Anim(CASINO, Slot_Plyr),
	_Anim(CASINO, Slot_wait),
	_Anim(CASINO, Slot_win_out),
	_Anim(CASINO, wof),
// Name: CHAINSAW, animations count: 11
	_Anim(CHAINSAW, CSAW_1),
	_Anim(CHAINSAW, CSAW_2),
	_Anim(CHAINSAW, CSAW_3),
	_Anim(CHAINSAW, CSAW_G),
	_Anim(CHAINSAW, CSAW_Hit_1),
	_Anim(CHAINSAW, CSAW_Hit_2),
	_Anim(CHAINSAW, CSAW_Hit_3),
	_Anim(CHAINSAW, csaw_part),
	_Anim(CHAINSAW, IDLE_csaw),
	_Anim(CHAINSAW, WEAPON_csaw),
	_Anim(CHAINSAW, WEAPON_csawlo),
// Name: CHOPPA, animations count: 18
	_Anim(CHOPPA, CHOPPA_back),
	_Anim(CHOPPA, CHOPPA_bunnyhop),
	_Anim(CHOPPA, CHOPPA_drivebyFT),
	_Anim(CHOPPA, CHOPPA_driveby_LHS),
	_Anim(CHOPPA, CHOPPA_driveby_RHS),
	_Anim(CHOPPA, CHOPPA_fwd),
	_Anim(CHOPPA, CHOPPA_getoffBACK),
	_Anim(CHOPPA, CHOPPA_getoffLHS),
	_Anim(CHOPPA, CHOPPA_getoffRHS),
	_Anim(CHOPPA, CHOPPA_jumponL),
	_Anim(CHOPPA, CHOPPA_jumponR),
	_Anim(CHOPPA, CHOPPA_Left),
	_Anim(CHOPPA, CHOPPA_pedal),
	_Anim(CHOPPA, CHOPPA_Pushes),
	_Anim(CHOPPA, CHOPPA_ride),
	_Anim(CHOPPA, CHOPPA_Right),
	_Anim(CHOPPA, CHOPPA_sprint),
	_Anim(CHOPPA, CHOPPA_Still),
// Name: CLOTHES, animations count: 13
	_Anim(CLOTHES, CLO_Buy),
	_Anim(CLOTHES, CLO_In),
	_Anim(CLOTHES, CLO_Out),
	_Anim(CLOTHES, CLO_Pose_Hat),
	_Anim(CLOTHES, CLO_Pose_In),
	_Anim(CLOTHES, CLO_Pose_In_O),
	_Anim(CLOTHES, CLO_Pose_Legs),
	_Anim(CLOTHES, CLO_Pose_Loop),
	_Anim(CLOTHES, CLO_Pose_Out),
	_Anim(CLOTHES, CLO_Pose_Out_O),
	_Anim(CLOTHES, CLO_Pose_Shoes),
	_Anim(CLOTHES, CLO_Pose_Torso),
	_Anim(CLOTHES, CLO_Pose_Watch),
// Name: COACH, animations count: 6
	_Anim(COACH, COACH_inL),
	_Anim(COACH, COACH_inR),
	_Anim(COACH, COACH_opnL),
	_Anim(COACH, COACH_opnR),
	_Anim(COACH, COACH_outL),
	_Anim(COACH, COACH_outR),
// Name: COLT45, animations count: 7
	_Anim(COLT45, 2guns_crouchfire),
	_Anim(COLT45, colt45_crouchfire),
	_Anim(COLT45, colt45_crouchreload),
	_Anim(COLT45, colt45_fire),
	_Anim(COLT45, colt45_fire_2hands),
	_Anim(COLT45, colt45_reload),
	_Anim(COLT45, sawnoff_reload),
// Name: COP_AMBIENT, animations count: 12
	_Anim(COP_AMBIENT, Copbrowse_in),
	_Anim(COP_AMBIENT, Copbrowse_loop),
	_Anim(COP_AMBIENT, Copbrowse_nod),
	_Anim(COP_AMBIENT, Copbrowse_out),
	_Anim(COP_AMBIENT, Copbrowse_shake),
	_Anim(COP_AMBIENT, Coplook_in),
	_Anim(COP_AMBIENT, Coplook_loop),
	_Anim(COP_AMBIENT, Coplook_nod),
	_Anim(COP_AMBIENT, Coplook_out),
	_Anim(COP_AMBIENT, Coplook_shake),
	_Anim(COP_AMBIENT, Coplook_think),
	_Anim(COP_AMBIENT, Coplook_watch),
// Name: COP_DVBYZ, animations count: 4
	_Anim(COP_DVBYZ, COP_Dvby_B),
	_Anim(COP_DVBYZ, COP_Dvby_FT),
	_Anim(COP_DVBYZ, COP_Dvby_L),
	_Anim(COP_DVBYZ, COP_Dvby_R),
// Name: CRACK, animations count: 10
	_Anim(CRACK, Bbalbat_Idle_01),
	_Anim(CRACK, Bbalbat_Idle_02),
	_Anim(CRACK, crckdeth1),
	_Anim(CRACK, crckdeth2),
	_Anim(CRACK, crckdeth3),
	_Anim(CRACK, crckdeth4),
	_Anim(CRACK, crckidle1),
	_Anim(CRACK, crckidle2),
	_Anim(CRACK, crckidle3),
	_Anim(CRACK, crckidle4),
// Name: CRIB, animations count: 5
	_Anim(CRIB, CRIB_Console_Loop),
	_Anim(CRIB, CRIB_Use_Switch),
	_Anim(CRIB, PED_Console_Loop),
	_Anim(CRIB, PED_Console_Loose),
	_Anim(CRIB, PED_Console_Win),
// Name: DAM_JUMP, animations count: 5
	_Anim(DAM_JUMP, DAM_Dive_Loop),
	_Anim(DAM_JUMP, DAM_Land),
	_Anim(DAM_JUMP, DAM_Launch),
	_Anim(DAM_JUMP, Jump_Roll),
	_Anim(DAM_JUMP, SF_JumpWall),
// Name: DANCING, animations count: 13
	_Anim(DANCING, bd_clap),
	_Anim(DANCING, bd_clap1),
	_Anim(DANCING, dance_loop),
	_Anim(DANCING, DAN_Down_A),
	_Anim(DANCING, DAN_Left_A),
	_Anim(DANCING, DAN_Loop_A),
	_Anim(DANCING, DAN_Right_A),
	_Anim(DANCING, DAN_Up_A),
	_Anim(DANCING, dnce_M_a),
	_Anim(DANCING, dnce_M_b),
	_Anim(DANCING, dnce_M_c),
	_Anim(DANCING, dnce_M_d),
	_Anim(DANCING, dnce_M_e),
// Name: DEALER, animations count: 7
	_Anim(DEALER, DEALER_DEAL),
	_Anim(DEALER, DEALER_IDLE),
	_Anim(DEALER, DEALER_IDLE_01),
	_Anim(DEALER, DEALER_IDLE_02),
	_Anim(DEALER, DEALER_IDLE_03),
	_Anim(DEALER, DRUGS_BUY),
	_Anim(DEALER, shop_pay),
// Name: DILDO, animations count: 9
	_Anim(DILDO, DILDO_1),
	_Anim(DILDO, DILDO_2),
	_Anim(DILDO, DILDO_3),
	_Anim(DILDO, DILDO_block),
	_Anim(DILDO, DILDO_G),
	_Anim(DILDO, DILDO_Hit_1),
	_Anim(DILDO, DILDO_Hit_2),
	_Anim(DILDO, DILDO_Hit_3),
	_Anim(DILDO, DILDO_IDLE),
// Name: DODGE, animations count: 4
	_Anim(DODGE, Cover_Dive_01),
	_Anim(DODGE, Cover_Dive_02),
	_Anim(DODGE, Crushed),
	_Anim(DODGE, Crush_Jump),
// Name: DOZER, animations count: 10
	_Anim(DOZER, DOZER_Align_LHS),
	_Anim(DOZER, DOZER_Align_RHS),
	_Anim(DOZER, DOZER_getin_LHS),
	_Anim(DOZER, DOZER_getin_RHS),
	_Anim(DOZER, DOZER_getout_LHS),
	_Anim(DOZER, DOZER_getout_RHS),
	_Anim(DOZER, DOZER_Jacked_LHS),
	_Anim(DOZER, DOZER_Jacked_RHS),
	_Anim(DOZER, DOZER_pullout_LHS),
	_Anim(DOZER, DOZER_pullout_RHS),
// Name: DRIVEBYS, animations count: 8
	_Anim(DRIVEBYS, Gang_DrivebyLHS),
	_Anim(DRIVEBYS, Gang_DrivebyLHS_Bwd),
	_Anim(DRIVEBYS, Gang_DrivebyLHS_Fwd),
	_Anim(DRIVEBYS, Gang_DrivebyRHS),
	_Anim(DRIVEBYS, Gang_DrivebyRHS_Bwd),
	_Anim(DRIVEBYS, Gang_DrivebyRHS_Fwd),
	_Anim(DRIVEBYS, Gang_DrivebyTop_LHS),
	_Anim(DRIVEBYS, Gang_DrivebyTop_RHS),
// Name: FAT, animations count: 18
	_Anim(FAT, FatIdle),
	_Anim(FAT, FatIdle_armed),
	_Anim(FAT, FatIdle_Csaw),
	_Anim(FAT, FatIdle_Rocket),
	_Anim(FAT, FatRun),
	_Anim(FAT, FatRun_armed),
	_Anim(FAT, FatRun_Csaw),
	_Anim(FAT, FatRun_Rocket),
	_Anim(FAT, FatSprint),
	_Anim(FAT, FatWalk),
	_Anim(FAT, FatWalkstart),
	_Anim(FAT, FatWalkstart_Csaw),
	_Anim(FAT, FatWalkSt_armed),
	_Anim(FAT, FatWalkSt_Rocket),
	_Anim(FAT, FatWalk_armed),
	_Anim(FAT, FatWalk_Csaw),
	_Anim(FAT, FatWalk_Rocket),
	_Anim(FAT, IDLE_tired),
// Name: FIGHT_B, animations count: 10
	_Anim(FIGHT_B, FightB_1),
	_Anim(FIGHT_B, FightB_2),
	_Anim(FIGHT_B, FightB_3),
	_Anim(FIGHT_B, FightB_block),
	_Anim(FIGHT_B, FightB_G),
	_Anim(FIGHT_B, FightB_IDLE),
	_Anim(FIGHT_B, FightB_M),
	_Anim(FIGHT_B, HitB_1),
	_Anim(FIGHT_B, HitB_2),
	_Anim(FIGHT_B, HitB_3),
// Name: FIGHT_C, animations count: 12
	_Anim(FIGHT_C, FightC_1),
	_Anim(FIGHT_C, FightC_2),
	_Anim(FIGHT_C, FightC_3),
	_Anim(FIGHT_C, FightC_block),
	_Anim(FIGHT_C, FightC_blocking),
	_Anim(FIGHT_C, FightC_G),
	_Anim(FIGHT_C, FightC_IDLE),
	_Anim(FIGHT_C, FightC_M),
	_Anim(FIGHT_C, FightC_Spar),
	_Anim(FIGHT_C, HitC_1),
	_Anim(FIGHT_C, HitC_2),
	_Anim(FIGHT_C, HitC_3),
// Name: FIGHT_D, animations count: 10
	_Anim(FIGHT_D, FightD_1),
	_Anim(FIGHT_D, FightD_2),
	_Anim(FIGHT_D, FightD_3),
	_Anim(FIGHT_D, FightD_block),
	_Anim(FIGHT_D, FightD_G),
	_Anim(FIGHT_D, FightD_IDLE),
	_Anim(FIGHT_D, FightD_M),
	_Anim(FIGHT_D, HitD_1),
	_Anim(FIGHT_D, HitD_2),
	_Anim(FIGHT_D, HitD_3),
// Name: FIGHT_E, animations count: 4
	_Anim(FIGHT_E, FightKick),
	_Anim(FIGHT_E, FightKick_B),
	_Anim(FIGHT_E, Hit_fightkick),
	_Anim(FIGHT_E, Hit_fightkick_B),
// Name: FINALE, animations count: 16
	_Anim(FINALE, FIN_Climb_In),
	_Anim(FINALE, FIN_Cop1_ClimbOut2),
	_Anim(FINALE, FIN_Cop1_Loop),
	_Anim(FINALE, FIN_Cop1_Stomp),
	_Anim(FINALE, FIN_Hang_L),
	_Anim(FINALE, FIN_Hang_Loop),
	_Anim(FINALE, FIN_Hang_R),
	_Anim(FINALE, FIN_Hang_Slip),
	_Anim(FINALE, FIN_Jump_On),
	_Anim(FINALE, FIN_Land_Car),
	_Anim(FINALE, FIN_Land_Die),
	_Anim(FINALE, FIN_LegsUp),
	_Anim(FINALE, FIN_LegsUp_L),
	_Anim(FINALE, FIN_LegsUp_Loop),
	_Anim(FINALE, FIN_LegsUp_R),
	_Anim(FINALE, FIN_Let_Go),
// Name: FINALE2, animations count: 8
	_Anim(FINALE2, FIN_Cop1_ClimbOut),
	_Anim(FINALE2, FIN_Cop1_Fall),
	_Anim(FINALE2, FIN_Cop1_Loop),
	_Anim(FINALE2, FIN_Cop1_Shot),
	_Anim(FINALE2, FIN_Cop1_Swing),
	_Anim(FINALE2, FIN_Cop2_ClimbOut),
	_Anim(FINALE2, FIN_Switch_P),
	_Anim(FINALE2, FIN_Switch_S),
// Name: FLAME, animations count: 1
	_Anim(FLAME, FLAME_fire),
// Name: Flowers, animations count: 3
	_Anim(Flowers, Flower_attack),
	_Anim(Flowers, Flower_attack_M),
	_Anim(Flowers, Flower_Hit),
// Name: FOOD, animations count: 33
	_Anim(FOOD, EAT_Burger),
	_Anim(FOOD, EAT_Chicken),
	_Anim(FOOD, EAT_Pizza),
	_Anim(FOOD, EAT_Vomit_P),
	_Anim(FOOD, EAT_Vomit_SK),
	_Anim(FOOD, FF_Dam_Bkw),
	_Anim(FOOD, FF_Dam_Fwd),
	_Anim(FOOD, FF_Dam_Left),
	_Anim(FOOD, FF_Dam_Right),
	_Anim(FOOD, FF_Die_Bkw),
	_Anim(FOOD, FF_Die_Fwd),
	_Anim(FOOD, FF_Die_Left),
	_Anim(FOOD, FF_Die_Right),
	_Anim(FOOD, FF_Sit_Eat1),
	_Anim(FOOD, FF_Sit_Eat2),
	_Anim(FOOD, FF_Sit_Eat3),
	_Anim(FOOD, FF_Sit_In),
	_Anim(FOOD, FF_Sit_In_L),
	_Anim(FOOD, FF_Sit_In_R),
	_Anim(FOOD, FF_Sit_Look),
	_Anim(FOOD, FF_Sit_Loop),
	_Anim(FOOD, FF_Sit_Out_180),
	_Anim(FOOD, FF_Sit_Out_L_180),
	_Anim(FOOD, FF_Sit_Out_R_180),
	_Anim(FOOD, SHP_Thank),
	_Anim(FOOD, SHP_Tray_In),
	_Anim(FOOD, SHP_Tray_Lift),
	_Anim(FOOD, SHP_Tray_Lift_In),
	_Anim(FOOD, SHP_Tray_Lift_Loop),
	_Anim(FOOD, SHP_Tray_Lift_Out),
	_Anim(FOOD, SHP_Tray_Out),
	_Anim(FOOD, SHP_Tray_Pose),
	_Anim(FOOD, SHP_Tray_Return),
// Name: Freeweights, animations count: 9
	_Anim(Freeweights, gym_barbell),
	_Anim(Freeweights, gym_free_A),
	_Anim(Freeweights, gym_free_B),
	_Anim(Freeweights, gym_free_celebrate),
	_Anim(Freeweights, gym_free_down),
	_Anim(Freeweights, gym_free_loop),
	_Anim(Freeweights, gym_free_pickup),
	_Anim(Freeweights, gym_free_putdown),
	_Anim(Freeweights, gym_free_up_smooth),
// Name: GANGS, animations count: 33
	_Anim(GANGS, DEALER_DEAL),
	_Anim(GANGS, DEALER_IDLE),
	_Anim(GANGS, drnkbr_prtl),
	_Anim(GANGS, drnkbr_prtl_F),
	_Anim(GANGS, DRUGS_BUY),
	_Anim(GANGS, hndshkaa),
	_Anim(GANGS, hndshkba),
	_Anim(GANGS, hndshkca),
	_Anim(GANGS, hndshkcb),
	_Anim(GANGS, hndshkda),
	_Anim(GANGS, hndshkea),
	_Anim(GANGS, hndshkfa),
	_Anim(GANGS, hndshkfa_swt),
	_Anim(GANGS, Invite_No),
	_Anim(GANGS, Invite_Yes),
	_Anim(GANGS, leanIDLE),
	_Anim(GANGS, leanIN),
	_Anim(GANGS, leanOUT),
	_Anim(GANGS, prtial_gngtlkA),
	_Anim(GANGS, prtial_gngtlkB),
	_Anim(GANGS, prtial_gngtlkC),
	_Anim(GANGS, prtial_gngtlkD),
	_Anim(GANGS, prtial_gngtlkE),
	_Anim(GANGS, prtial_gngtlkF),
	_Anim(GANGS, prtial_gngtlkG),
	_Anim(GANGS, prtial_gngtlkH),
	_Anim(GANGS, prtial_hndshk_01),
	_Anim(GANGS, prtial_hndshk_biz_01),
	_Anim(GANGS, shake_cara),
	_Anim(GANGS, shake_carK),
	_Anim(GANGS, shake_carSH),
	_Anim(GANGS, smkcig_prtl),
	_Anim(GANGS, smkcig_prtl_F),
// Name: GFUNK, animations count: 33
	_Anim(GFUNK, Dance_B1),
	_Anim(GFUNK, Dance_B10),
	_Anim(GFUNK, Dance_B11),
	_Anim(GFUNK, Dance_B12),
	_Anim(GFUNK, Dance_B13),
	_Anim(GFUNK, Dance_B14),
	_Anim(GFUNK, Dance_B15),
	_Anim(GFUNK, Dance_B16),
	_Anim(GFUNK, Dance_B2),
	_Anim(GFUNK, Dance_B3),
	_Anim(GFUNK, Dance_B4),
	_Anim(GFUNK, Dance_B5),
	_Anim(GFUNK, Dance_B6),
	_Anim(GFUNK, Dance_B7),
	_Anim(GFUNK, Dance_B8),
	_Anim(GFUNK, Dance_B9),
	_Anim(GFUNK, Dance_G1),
	_Anim(GFUNK, Dance_G10),
	_Anim(GFUNK, Dance_G11),
	_Anim(GFUNK, Dance_G12),
	_Anim(GFUNK, Dance_G13),
	_Anim(GFUNK, Dance_G14),
	_Anim(GFUNK, Dance_G15),
	_Anim(GFUNK, Dance_G16),
	_Anim(GFUNK, Dance_G2),
	_Anim(GFUNK, Dance_G3),
	_Anim(GFUNK, Dance_G4),
	_Anim(GFUNK, Dance_G5),
	_Anim(GFUNK, Dance_G6),
	_Anim(GFUNK, Dance_G7),
	_Anim(GFUNK, Dance_G8),
	_Anim(GFUNK, Dance_G9),
	_Anim(GFUNK, dance_loop),
// Name: GHANDS, animations count: 20
	_Anim(GHANDS, gsign1),
	_Anim(GHANDS, gsign1LH),
	_Anim(GHANDS, gsign2),
	_Anim(GHANDS, gsign2LH),
	_Anim(GHANDS, gsign3),
	_Anim(GHANDS, gsign3LH),
	_Anim(GHANDS, gsign4),
	_Anim(GHANDS, gsign4LH),
	_Anim(GHANDS, gsign5),
	_Anim(GHANDS, gsign5LH),
	_Anim(GHANDS, LHGsign1),
	_Anim(GHANDS, LHGsign2),
	_Anim(GHANDS, LHGsign3),
	_Anim(GHANDS, LHGsign4),
	_Anim(GHANDS, LHGsign5),
	_Anim(GHANDS, RHGsign1),
	_Anim(GHANDS, RHGsign2),
	_Anim(GHANDS, RHGsign3),
	_Anim(GHANDS, RHGsign4),
	_Anim(GHANDS, RHGsign5),
// Name: GHETTO_DB, animations count: 7
	_Anim(GHETTO_DB, GDB_Car2_PLY),
	_Anim(GHETTO_DB, GDB_Car2_SMO),
	_Anim(GHETTO_DB, GDB_Car2_SWE),
	_Anim(GHETTO_DB, GDB_Car_PLY),
	_Anim(GHETTO_DB, GDB_Car_RYD),
	_Anim(GHETTO_DB, GDB_Car_SMO),
	_Anim(GHETTO_DB, GDB_Car_SWE),
// Name: goggles, animations count: 1
	_Anim(goggles, goggles_put_on),
// Name: GRAFFITI, animations count: 2
	_Anim(GRAFFITI, graffiti_Chkout),
	_Anim(GRAFFITI, spraycan_fire),
// Name: GRAVEYARD, animations count: 3
	_Anim(GRAVEYARD, mrnF_loop),
	_Anim(GRAVEYARD, mrnM_loop),
	_Anim(GRAVEYARD, prst_loopa),
// Name: GRENADE, animations count: 3
	_Anim(GRENADE, WEAPON_start_throw),
	_Anim(GRENADE, WEAPON_throw),
	_Anim(GRENADE, WEAPON_throwu),
// Name: GYMNASIUM, animations count: 24
	_Anim(GYMNASIUM, GYMshadowbox),
	_Anim(GYMNASIUM, gym_bike_celebrate),
	_Anim(GYMNASIUM, gym_bike_fast),
	_Anim(GYMNASIUM, gym_bike_faster),
	_Anim(GYMNASIUM, gym_bike_getoff),
	_Anim(GYMNASIUM, gym_bike_geton),
	_Anim(GYMNASIUM, gym_bike_pedal),
	_Anim(GYMNASIUM, gym_bike_slow),
	_Anim(GYMNASIUM, gym_bike_still),
	_Anim(GYMNASIUM, gym_jog_falloff),
	_Anim(GYMNASIUM, gym_shadowbox),
	_Anim(GYMNASIUM, gym_tread_celebrate),
	_Anim(GYMNASIUM, gym_tread_falloff),
	_Anim(GYMNASIUM, gym_tread_getoff),
	_Anim(GYMNASIUM, gym_tread_geton),
	_Anim(GYMNASIUM, gym_tread_jog),
	_Anim(GYMNASIUM, gym_tread_sprint),
	_Anim(GYMNASIUM, gym_tread_tired),
	_Anim(GYMNASIUM, gym_tread_walk),
	_Anim(GYMNASIUM, gym_walk_falloff),
	_Anim(GYMNASIUM, Pedals_fast),
	_Anim(GYMNASIUM, Pedals_med),
	_Anim(GYMNASIUM, Pedals_slow),
	_Anim(GYMNASIUM, Pedals_still),
// Name: HAIRCUTS, animations count: 13
	_Anim(HAIRCUTS, BRB_Beard_01),
	_Anim(HAIRCUTS, BRB_Buy),
	_Anim(HAIRCUTS, BRB_Cut),
	_Anim(HAIRCUTS, BRB_Cut_In),
	_Anim(HAIRCUTS, BRB_Cut_Out),
	_Anim(HAIRCUTS, BRB_Hair_01),
	_Anim(HAIRCUTS, BRB_Hair_02),
	_Anim(HAIRCUTS, BRB_In),
	_Anim(HAIRCUTS, BRB_Loop),
	_Anim(HAIRCUTS, BRB_Out),
	_Anim(HAIRCUTS, BRB_Sit_In),
	_Anim(HAIRCUTS, BRB_Sit_Loop),
	_Anim(HAIRCUTS, BRB_Sit_Out),
// Name: HEIST9, animations count: 10
	_Anim(HEIST9, CAS_G2_GasKO),
	_Anim(HEIST9, swt_wllpk_L),
	_Anim(HEIST9, swt_wllpk_L_back),
	_Anim(HEIST9, swt_wllpk_R),
	_Anim(HEIST9, swt_wllpk_R_back),
	_Anim(HEIST9, swt_wllshoot_in_L),
	_Anim(HEIST9, swt_wllshoot_in_R),
	_Anim(HEIST9, swt_wllshoot_out_L),
	_Anim(HEIST9, swt_wllshoot_out_R),
	_Anim(HEIST9, Use_SwipeCard),
// Name: INT_HOUSE, animations count: 10
	_Anim(INT_HOUSE, BED_In_L),
	_Anim(INT_HOUSE, BED_In_R),
	_Anim(INT_HOUSE, BED_Loop_L),
	_Anim(INT_HOUSE, BED_Loop_R),
	_Anim(INT_HOUSE, BED_Out_L),
	_Anim(INT_HOUSE, BED_Out_R),
	_Anim(INT_HOUSE, LOU_In),
	_Anim(INT_HOUSE, LOU_Loop),
	_Anim(INT_HOUSE, LOU_Out),
	_Anim(INT_HOUSE, wash_up),
// Name: INT_OFFICE, animations count: 10
	_Anim(INT_OFFICE, FF_Dam_Fwd),
	_Anim(INT_OFFICE, OFF_Sit_2Idle_180),
	_Anim(INT_OFFICE, OFF_Sit_Bored_Loop),
	_Anim(INT_OFFICE, OFF_Sit_Crash),
	_Anim(INT_OFFICE, OFF_Sit_Drink),
	_Anim(INT_OFFICE, OFF_Sit_Idle_Loop),
	_Anim(INT_OFFICE, OFF_Sit_In),
	_Anim(INT_OFFICE, OFF_Sit_Read),
	_Anim(INT_OFFICE, OFF_Sit_Type_Loop),
	_Anim(INT_OFFICE, OFF_Sit_Watch),
// Name: INT_SHOP, animations count: 8
	_Anim(INT_SHOP, shop_cashier),
	_Anim(INT_SHOP, shop_in),
	_Anim(INT_SHOP, shop_lookA),
	_Anim(INT_SHOP, shop_lookB),
	_Anim(INT_SHOP, shop_loop),
	_Anim(INT_SHOP, shop_out),
	_Anim(INT_SHOP, shop_pay),
	_Anim(INT_SHOP, shop_shelf),
// Name: JST_BUISNESS, animations count: 4
	_Anim(JST_BUISNESS, girl_01),
	_Anim(JST_BUISNESS, girl_02),
	_Anim(JST_BUISNESS, player_01),
	_Anim(JST_BUISNESS, smoke_01),
// Name: KART, animations count: 4
	_Anim(KART, KART_getin_LHS),
	_Anim(KART, KART_getin_RHS),
	_Anim(KART, KART_getout_LHS),
	_Anim(KART, KART_getout_RHS),
// Name: KISSING, animations count: 15
	_Anim(KISSING, BD_GF_Wave),
	_Anim(KISSING, gfwave2),
	_Anim(KISSING, GF_CarArgue_01),
	_Anim(KISSING, GF_CarArgue_02),
	_Anim(KISSING, GF_CarSpot),
	_Anim(KISSING, GF_StreetArgue_01),
	_Anim(KISSING, GF_StreetArgue_02),
	_Anim(KISSING, gift_get),
	_Anim(KISSING, gift_give),
	_Anim(KISSING, Grlfrd_Kiss_01),
	_Anim(KISSING, Grlfrd_Kiss_02),
	_Anim(KISSING, Grlfrd_Kiss_03),
	_Anim(KISSING, Playa_Kiss_01),
	_Anim(KISSING, Playa_Kiss_02),
	_Anim(KISSING, Playa_Kiss_03),
// Name: KNIFE, animations count: 16
	_Anim(KNIFE, KILL_Knife_Ped_Damage),
	_Anim(KNIFE, KILL_Knife_Ped_Die),
	_Anim(KNIFE, KILL_Knife_Player),
	_Anim(KNIFE, KILL_Partial),
	_Anim(KNIFE, knife_1),
	_Anim(KNIFE, knife_2),
	_Anim(KNIFE, knife_3),
	_Anim(KNIFE, Knife_4),
	_Anim(KNIFE, knife_block),
	_Anim(KNIFE, Knife_G),
	_Anim(KNIFE, knife_hit_1),
	_Anim(KNIFE, knife_hit_2),
	_Anim(KNIFE, knife_hit_3),
	_Anim(KNIFE, knife_IDLE),
	_Anim(KNIFE, knife_part),
	_Anim(KNIFE, WEAPON_knifeidle),
// Name: LAPDAN1, animations count: 2
	_Anim(LAPDAN1, LAPDAN_D),
	_Anim(LAPDAN1, LAPDAN_P),
// Name: LAPDAN2, animations count: 2
	_Anim(LAPDAN2, LAPDAN_D),
	_Anim(LAPDAN2, LAPDAN_P),
// Name: LAPDAN3, animations count: 2
	_Anim(LAPDAN3, LAPDAN_D),
	_Anim(LAPDAN3, LAPDAN_P),
// Name: LOWRIDER, animations count: 39
	_Anim(LOWRIDER, F_smklean_loop),
	_Anim(LOWRIDER, lrgirl_bdbnce),
	_Anim(LOWRIDER, lrgirl_hair),
	_Anim(LOWRIDER, lrgirl_hurry),
	_Anim(LOWRIDER, lrgirl_idleloop),
	_Anim(LOWRIDER, lrgirl_idle_to_l0),
	_Anim(LOWRIDER, lrgirl_l0_bnce),
	_Anim(LOWRIDER, lrgirl_l0_loop),
	_Anim(LOWRIDER, lrgirl_l0_to_l1),
	_Anim(LOWRIDER, lrgirl_l12_to_l0),
	_Anim(LOWRIDER, lrgirl_l1_bnce),
	_Anim(LOWRIDER, lrgirl_l1_loop),
	_Anim(LOWRIDER, lrgirl_l1_to_l2),
	_Anim(LOWRIDER, lrgirl_l2_bnce),
	_Anim(LOWRIDER, lrgirl_l2_loop),
	_Anim(LOWRIDER, lrgirl_l2_to_l3),
	_Anim(LOWRIDER, lrgirl_l345_to_l1),
	_Anim(LOWRIDER, lrgirl_l3_bnce),
	_Anim(LOWRIDER, lrgirl_l3_loop),
	_Anim(LOWRIDER, lrgirl_l3_to_l4),
	_Anim(LOWRIDER, lrgirl_l4_bnce),
	_Anim(LOWRIDER, lrgirl_l4_loop),
	_Anim(LOWRIDER, lrgirl_l4_to_l5),
	_Anim(LOWRIDER, lrgirl_l5_bnce),
	_Anim(LOWRIDER, lrgirl_l5_loop),
	_Anim(LOWRIDER, M_smklean_loop),
	_Anim(LOWRIDER, M_smkstnd_loop),
	_Anim(LOWRIDER, prtial_gngtlkB),
	_Anim(LOWRIDER, prtial_gngtlkC),
	_Anim(LOWRIDER, prtial_gngtlkD),
	_Anim(LOWRIDER, prtial_gngtlkE),
	_Anim(LOWRIDER, prtial_gngtlkF),
	_Anim(LOWRIDER, prtial_gngtlkG),
	_Anim(LOWRIDER, prtial_gngtlkH),
	_Anim(LOWRIDER, RAP_A_Loop),
	_Anim(LOWRIDER, RAP_B_Loop),
	_Anim(LOWRIDER, RAP_C_Loop),
	_Anim(LOWRIDER, Sit_relaxed),
	_Anim(LOWRIDER, Tap_hand),
// Name: MD_CHASE, animations count: 25
	_Anim(MD_CHASE, Carhit_Hangon),
	_Anim(MD_CHASE, Carhit_Tumble),
	_Anim(MD_CHASE, donutdrop),
	_Anim(MD_CHASE, Fen_Choppa_L1),
	_Anim(MD_CHASE, Fen_Choppa_L2),
	_Anim(MD_CHASE, Fen_Choppa_L3),
	_Anim(MD_CHASE, Fen_Choppa_R1),
	_Anim(MD_CHASE, Fen_Choppa_R2),
	_Anim(MD_CHASE, Fen_Choppa_R3),
	_Anim(MD_CHASE, Hangon_Stun_loop),
	_Anim(MD_CHASE, Hangon_Stun_Turn),
	_Anim(MD_CHASE, MD_BIKE_2_HANG),
	_Anim(MD_CHASE, MD_BIKE_Jmp_BL),
	_Anim(MD_CHASE, MD_BIKE_Jmp_F),
	_Anim(MD_CHASE, MD_BIKE_Lnd_BL),
	_Anim(MD_CHASE, MD_BIKE_Lnd_Die_BL),
	_Anim(MD_CHASE, MD_BIKE_Lnd_Die_F),
	_Anim(MD_CHASE, MD_BIKE_Lnd_F),
	_Anim(MD_CHASE, MD_BIKE_Lnd_Roll),
	_Anim(MD_CHASE, MD_BIKE_Lnd_Roll_F),
	_Anim(MD_CHASE, MD_BIKE_Punch),
	_Anim(MD_CHASE, MD_BIKE_Punch_F),
	_Anim(MD_CHASE, MD_BIKE_Shot_F),
	_Anim(MD_CHASE, MD_HANG_Lnd_Roll),
	_Anim(MD_CHASE, MD_HANG_Loop),
// Name: MD_END, animations count: 8
	_Anim(MD_END, END_SC1_PLY),
	_Anim(MD_END, END_SC1_RYD),
	_Anim(MD_END, END_SC1_SMO),
	_Anim(MD_END, END_SC1_SWE),
	_Anim(MD_END, END_SC2_PLY),
	_Anim(MD_END, END_SC2_RYD),
	_Anim(MD_END, END_SC2_SMO),
	_Anim(MD_END, END_SC2_SWE),
// Name: MEDIC, animations count: 1
	_Anim(MEDIC, CPR),
// Name: MISC, animations count: 41
	_Anim(MISC, bitchslap),
	_Anim(MISC, BMX_celebrate),
	_Anim(MISC, BMX_comeon),
	_Anim(MISC, bmx_idleloop_01),
	_Anim(MISC, bmx_idleloop_02),
	_Anim(MISC, bmx_talkleft_in),
	_Anim(MISC, bmx_talkleft_loop),
	_Anim(MISC, bmx_talkleft_out),
	_Anim(MISC, bmx_talkright_in),
	_Anim(MISC, bmx_talkright_loop),
	_Anim(MISC, bmx_talkright_out),
	_Anim(MISC, bng_wndw),
	_Anim(MISC, bng_wndw_02),
	_Anim(MISC, Case_pickup),
	_Anim(MISC, door_jet),
	_Anim(MISC, GRAB_L),
	_Anim(MISC, GRAB_R),
	_Anim(MISC, Hiker_Pose),
	_Anim(MISC, Hiker_Pose_L),
	_Anim(MISC, Idle_Chat_02),
	_Anim(MISC, KAT_Throw_K),
	_Anim(MISC, KAT_Throw_O),
	_Anim(MISC, KAT_Throw_P),
	_Anim(MISC, PASS_Rifle_O),
	_Anim(MISC, PASS_Rifle_Ped),
	_Anim(MISC, PASS_Rifle_Ply),
	_Anim(MISC, pickup_box),
	_Anim(MISC, Plane_door),
	_Anim(MISC, Plane_exit),
	_Anim(MISC, Plane_hijack),
	_Anim(MISC, Plunger_01),
	_Anim(MISC, Plyrlean_loop),
	_Anim(MISC, plyr_shkhead),
	_Anim(MISC, Run_Dive),
	_Anim(MISC, Scratchballs_01),
	_Anim(MISC, SEAT_LR),
	_Anim(MISC, Seat_talk_01),
	_Anim(MISC, Seat_talk_02),
	_Anim(MISC, SEAT_watch),
	_Anim(MISC, smalplane_door),
	_Anim(MISC, smlplane_door),
// Name: MTB, animations count: 18
	_Anim(MTB, MTB_back),
	_Anim(MTB, MTB_bunnyhop),
	_Anim(MTB, MTB_drivebyFT),
	_Anim(MTB, MTB_driveby_LHS),
	_Anim(MTB, MTB_driveby_RHS),
	_Anim(MTB, MTB_fwd),
	_Anim(MTB, MTB_getoffBACK),
	_Anim(MTB, MTB_getoffLHS),
	_Anim(MTB, MTB_getoffRHS),
	_Anim(MTB, MTB_jumponL),
	_Anim(MTB, MTB_jumponR),
	_Anim(MTB, MTB_Left),
	_Anim(MTB, MTB_pedal),
	_Anim(MTB, MTB_pushes),
	_Anim(MTB, MTB_Ride),
	_Anim(MTB, MTB_Right),
	_Anim(MTB, MTB_sprint),
	_Anim(MTB, MTB_still),
// Name: MUSCULAR, animations count: 17
	_Anim(MUSCULAR, MscleWalkst_armed),
	_Anim(MUSCULAR, MscleWalkst_Csaw),
	_Anim(MUSCULAR, Mscle_rckt_run),
	_Anim(MUSCULAR, Mscle_rckt_walkst),
	_Anim(MUSCULAR, Mscle_run_Csaw),
	_Anim(MUSCULAR, MuscleIdle),
	_Anim(MUSCULAR, MuscleIdle_armed),
	_Anim(MUSCULAR, MuscleIdle_Csaw),
	_Anim(MUSCULAR, MuscleIdle_rocket),
	_Anim(MUSCULAR, MuscleRun),
	_Anim(MUSCULAR, MuscleRun_armed),
	_Anim(MUSCULAR, MuscleSprint),
	_Anim(MUSCULAR, MuscleWalk),
	_Anim(MUSCULAR, MuscleWalkstart),
	_Anim(MUSCULAR, MuscleWalk_armed),
	_Anim(MUSCULAR, Musclewalk_Csaw),
	_Anim(MUSCULAR, Musclewalk_rocket),
// Name: NEVADA, animations count: 2
	_Anim(NEVADA, NEVADA_getin),
	_Anim(NEVADA, NEVADA_getout),
// Name: ON_LOOKERS, animations count: 29
	_Anim(ON_LOOKERS, lkaround_in),
	_Anim(ON_LOOKERS, lkaround_loop),
	_Anim(ON_LOOKERS, lkaround_out),
	_Anim(ON_LOOKERS, lkup_in),
	_Anim(ON_LOOKERS, lkup_loop),
	_Anim(ON_LOOKERS, lkup_out),
	_Anim(ON_LOOKERS, lkup_point),
	_Anim(ON_LOOKERS, panic_cower),
	_Anim(ON_LOOKERS, panic_hide),
	_Anim(ON_LOOKERS, panic_in),
	_Anim(ON_LOOKERS, panic_loop),
	_Anim(ON_LOOKERS, panic_out),
	_Anim(ON_LOOKERS, panic_point),
	_Anim(ON_LOOKERS, panic_shout),
	_Anim(ON_LOOKERS, Pointup_in),
	_Anim(ON_LOOKERS, Pointup_loop),
	_Anim(ON_LOOKERS, Pointup_out),
	_Anim(ON_LOOKERS, Pointup_shout),
	_Anim(ON_LOOKERS, point_in),
	_Anim(ON_LOOKERS, point_loop),
	_Anim(ON_LOOKERS, point_out),
	_Anim(ON_LOOKERS, shout_01),
	_Anim(ON_LOOKERS, shout_02),
	_Anim(ON_LOOKERS, shout_in),
	_Anim(ON_LOOKERS, shout_loop),
	_Anim(ON_LOOKERS, shout_out),
	_Anim(ON_LOOKERS, wave_in),
	_Anim(ON_LOOKERS, wave_loop),
	_Anim(ON_LOOKERS, wave_out),
// Name: OTB, animations count: 11
	_Anim(OTB, betslp_in),
	_Anim(OTB, betslp_lkabt),
	_Anim(OTB, betslp_loop),
	_Anim(OTB, betslp_out),
	_Anim(OTB, betslp_tnk),
	_Anim(OTB, wtchrace_cmon),
	_Anim(OTB, wtchrace_in),
	_Anim(OTB, wtchrace_loop),
	_Anim(OTB, wtchrace_lose),
	_Anim(OTB, wtchrace_out),
	_Anim(OTB, wtchrace_win),
// Name: PARACHUTE, animations count: 22
	_Anim(PARACHUTE, FALL_skyDive),
	_Anim(PARACHUTE, FALL_SkyDive_Accel),
	_Anim(PARACHUTE, FALL_skyDive_DIE),
	_Anim(PARACHUTE, FALL_SkyDive_L),
	_Anim(PARACHUTE, FALL_SkyDive_R),
	_Anim(PARACHUTE, PARA_decel),
	_Anim(PARACHUTE, PARA_decel_O),
	_Anim(PARACHUTE, PARA_float),
	_Anim(PARACHUTE, PARA_float_O),
	_Anim(PARACHUTE, PARA_Land),
	_Anim(PARACHUTE, PARA_Land_O),
	_Anim(PARACHUTE, PARA_Land_Water),
	_Anim(PARACHUTE, PARA_Land_Water_O),
	_Anim(PARACHUTE, PARA_open),
	_Anim(PARACHUTE, PARA_open_O),
	_Anim(PARACHUTE, PARA_Rip_Land_O),
	_Anim(PARACHUTE, PARA_Rip_Loop_O),
	_Anim(PARACHUTE, PARA_Rip_O),
	_Anim(PARACHUTE, PARA_steerL),
	_Anim(PARACHUTE, PARA_steerL_O),
	_Anim(PARACHUTE, PARA_steerR),
	_Anim(PARACHUTE, PARA_steerR_O),
// Name: PARK, animations count: 3
	_Anim(PARK, Tai_Chi_in),
	_Anim(PARK, Tai_Chi_Loop),
	_Anim(PARK, Tai_Chi_Out),
// Name: PAULNMAC, animations count: 12
	_Anim(PAULNMAC, Piss_in),
	_Anim(PAULNMAC, Piss_loop),
	_Anim(PAULNMAC, Piss_out),
	_Anim(PAULNMAC, PnM_Argue1_A),
	_Anim(PAULNMAC, PnM_Argue1_B),
	_Anim(PAULNMAC, PnM_Argue2_A),
	_Anim(PAULNMAC, PnM_Argue2_B),
	_Anim(PAULNMAC, PnM_Loop_A),
	_Anim(PAULNMAC, PnM_Loop_B),
	_Anim(PAULNMAC, wank_in),
	_Anim(PAULNMAC, wank_loop),
	_Anim(PAULNMAC, wank_out),
// Name: ped, animations count: 294
	_Anim(ped, abseil),
	_Anim(ped, ARRESTgun),
	_Anim(ped, ATM),
	_Anim(ped, BIKE_elbowL),
	_Anim(ped, BIKE_elbowR),
	_Anim(ped, BIKE_fallR),
	_Anim(ped, BIKE_fall_off),
	_Anim(ped, BIKE_pickupL),
	_Anim(ped, BIKE_pickupR),
	_Anim(ped, BIKE_pullupL),
	_Anim(ped, BIKE_pullupR),
	_Anim(ped, bomber),
	_Anim(ped, CAR_alignHI_LHS),
	_Anim(ped, CAR_alignHI_RHS),
	_Anim(ped, CAR_align_LHS),
	_Anim(ped, CAR_align_RHS),
	_Anim(ped, CAR_closedoorL_LHS),
	_Anim(ped, CAR_closedoorL_RHS),
	_Anim(ped, CAR_closedoor_LHS),
	_Anim(ped, CAR_closedoor_RHS),
	_Anim(ped, CAR_close_LHS),
	_Anim(ped, CAR_close_RHS),
	_Anim(ped, CAR_crawloutRHS),
	_Anim(ped, CAR_dead_LHS),
	_Anim(ped, CAR_dead_RHS),
	_Anim(ped, CAR_doorlocked_LHS),
	_Anim(ped, CAR_doorlocked_RHS),
	_Anim(ped, CAR_fallout_LHS),
	_Anim(ped, CAR_fallout_RHS),
	_Anim(ped, CAR_getinL_LHS),
	_Anim(ped, CAR_getinL_RHS),
	_Anim(ped, CAR_getin_LHS),
	_Anim(ped, CAR_getin_RHS),
	_Anim(ped, CAR_getoutL_LHS),
	_Anim(ped, CAR_getoutL_RHS),
	_Anim(ped, CAR_getout_LHS),
	_Anim(ped, CAR_getout_RHS),
	_Anim(ped, car_hookertalk),
	_Anim(ped, CAR_jackedLHS),
	_Anim(ped, CAR_jackedRHS),
	_Anim(ped, CAR_jumpin_LHS),
	_Anim(ped, CAR_LB),
	_Anim(ped, CAR_LB_pro),
	_Anim(ped, CAR_LB_weak),
	_Anim(ped, CAR_LjackedLHS),
	_Anim(ped, CAR_LjackedRHS),
	_Anim(ped, CAR_Lshuffle_RHS),
	_Anim(ped, CAR_Lsit),
	_Anim(ped, CAR_open_LHS),
	_Anim(ped, CAR_open_RHS),
	_Anim(ped, CAR_pulloutL_LHS),
	_Anim(ped, CAR_pulloutL_RHS),
	_Anim(ped, CAR_pullout_LHS),
	_Anim(ped, CAR_pullout_RHS),
	_Anim(ped, CAR_Qjacked),
	_Anim(ped, CAR_rolldoor),
	_Anim(ped, CAR_rolldoorLO),
	_Anim(ped, CAR_rollout_LHS),
	_Anim(ped, CAR_rollout_RHS),
	_Anim(ped, CAR_shuffle_RHS),
	_Anim(ped, CAR_sit),
	_Anim(ped, CAR_sitp),
	_Anim(ped, CAR_sitpLO),
	_Anim(ped, CAR_sit_pro),
	_Anim(ped, CAR_sit_weak),
	_Anim(ped, CAR_tune_radio),
	_Anim(ped, CLIMB_idle),
	_Anim(ped, CLIMB_jump),
	_Anim(ped, CLIMB_jump2fall),
	_Anim(ped, CLIMB_jump_B),
	_Anim(ped, CLIMB_Pull),
	_Anim(ped, CLIMB_Stand),
	_Anim(ped, CLIMB_Stand_finish),
	_Anim(ped, cower),
	_Anim(ped, Crouch_Roll_L),
	_Anim(ped, Crouch_Roll_R),
	_Anim(ped, DAM_armL_frmBK),
	_Anim(ped, DAM_armL_frmFT),
	_Anim(ped, DAM_armL_frmLT),
	_Anim(ped, DAM_armR_frmBK),
	_Anim(ped, DAM_armR_frmFT),
	_Anim(ped, DAM_armR_frmRT),
	_Anim(ped, DAM_LegL_frmBK),
	_Anim(ped, DAM_LegL_frmFT),
	_Anim(ped, DAM_LegL_frmLT),
	_Anim(ped, DAM_LegR_frmBK),
	_Anim(ped, DAM_LegR_frmFT),
	_Anim(ped, DAM_LegR_frmRT),
	_Anim(ped, DAM_stomach_frmBK),
	_Anim(ped, DAM_stomach_frmFT),
	_Anim(ped, DAM_stomach_frmLT),
	_Anim(ped, DAM_stomach_frmRT),
	_Anim(ped, DOOR_LHinge_O),
	_Anim(ped, DOOR_RHinge_O),
	_Anim(ped, DrivebyL_L),
	_Anim(ped, DrivebyL_R),
	_Anim(ped, Driveby_L),
	_Anim(ped, Driveby_R),
	_Anim(ped, DRIVE_BOAT),
	_Anim(ped, DRIVE_BOAT_back),
	_Anim(ped, DRIVE_BOAT_L),
	_Anim(ped, DRIVE_BOAT_R),
	_Anim(ped, Drive_L),
	_Anim(ped, Drive_LO_l),
	_Anim(ped, Drive_LO_R),
	_Anim(ped, Drive_L_pro),
	_Anim(ped, Drive_L_pro_slow),
	_Anim(ped, Drive_L_slow),
	_Anim(ped, Drive_L_weak),
	_Anim(ped, Drive_L_weak_slow),
	_Anim(ped, Drive_R),
	_Anim(ped, Drive_R_pro),
	_Anim(ped, Drive_R_pro_slow),
	_Anim(ped, Drive_R_slow),
	_Anim(ped, Drive_R_weak),
	_Anim(ped, Drive_R_weak_slow),
	_Anim(ped, Drive_truck),
	_Anim(ped, DRIVE_truck_back),
	_Anim(ped, DRIVE_truck_L),
	_Anim(ped, DRIVE_truck_R),
	_Anim(ped, Drown),
	_Anim(ped, DUCK_cower),
	_Anim(ped, endchat_01),
	_Anim(ped, endchat_02),
	_Anim(ped, endchat_03),
	_Anim(ped, EV_dive),
	_Anim(ped, EV_step),
	_Anim(ped, facanger),
	_Anim(ped, facgum),
	_Anim(ped, facsurp),
	_Anim(ped, facsurpm),
	_Anim(ped, factalk),
	_Anim(ped, facurios),
	_Anim(ped, FALL_back),
	_Anim(ped, FALL_collapse),
	_Anim(ped, FALL_fall),
	_Anim(ped, FALL_front),
	_Anim(ped, FALL_glide),
	_Anim(ped, FALL_land),
	_Anim(ped, FALL_skyDive),
	_Anim(ped, Fight2Idle),
	_Anim(ped, FightA_1),
	_Anim(ped, FightA_2),
	_Anim(ped, FightA_3),
	_Anim(ped, FightA_block),
	_Anim(ped, FightA_G),
	_Anim(ped, FightA_M),
	_Anim(ped, FIGHTIDLE),
	_Anim(ped, FightShB),
	_Anim(ped, FightShF),
	_Anim(ped, FightSh_BWD),
	_Anim(ped, FightSh_FWD),
	_Anim(ped, FightSh_Left),
	_Anim(ped, FightSh_Right),
	_Anim(ped, flee_lkaround_01),
	_Anim(ped, FLOOR_hit),
	_Anim(ped, FLOOR_hit_f),
	_Anim(ped, fucku),
	_Anim(ped, gang_gunstand),
	_Anim(ped, gas_cwr),
	_Anim(ped, getup),
	_Anim(ped, getup_front),
	_Anim(ped, gum_eat),
	_Anim(ped, GunCrouchBwd),
	_Anim(ped, GunCrouchFwd),
	_Anim(ped, GunMove_BWD),
	_Anim(ped, GunMove_FWD),
	_Anim(ped, GunMove_L),
	_Anim(ped, GunMove_R),
	_Anim(ped, Gun_2_IDLE),
	_Anim(ped, GUN_BUTT),
	_Anim(ped, GUN_BUTT_crouch),
	_Anim(ped, Gun_stand),
	_Anim(ped, handscower),
	_Anim(ped, handsup),
	_Anim(ped, HitA_1),
	_Anim(ped, HitA_2),
	_Anim(ped, HitA_3),
	_Anim(ped, HIT_back),
	_Anim(ped, HIT_behind),
	_Anim(ped, HIT_front),
	_Anim(ped, HIT_GUN_BUTT),
	_Anim(ped, HIT_L),
	_Anim(ped, HIT_R),
	_Anim(ped, HIT_walk),
	_Anim(ped, HIT_wall),
	_Anim(ped, Idlestance_fat),
	_Anim(ped, idlestance_old),
	_Anim(ped, IDLE_armed),
	_Anim(ped, IDLE_chat),
	_Anim(ped, IDLE_csaw),
	_Anim(ped, Idle_Gang1),
	_Anim(ped, IDLE_HBHB),
	_Anim(ped, IDLE_ROCKET),
	_Anim(ped, IDLE_stance),
	_Anim(ped, IDLE_taxi),
	_Anim(ped, IDLE_tired),
	_Anim(ped, Jetpack_Idle),
	_Anim(ped, JOG_femaleA),
	_Anim(ped, JOG_maleA),
	_Anim(ped, JUMP_glide),
	_Anim(ped, JUMP_land),
	_Anim(ped, JUMP_launch),
	_Anim(ped, JUMP_launch_R),
	_Anim(ped, KART_drive),
	_Anim(ped, KART_L),
	_Anim(ped, KART_LB),
	_Anim(ped, KART_R),
	_Anim(ped, KD_left),
	_Anim(ped, KD_right),
	_Anim(ped, KO_shot_face),
	_Anim(ped, KO_shot_front),
	_Anim(ped, KO_shot_stom),
	_Anim(ped, KO_skid_back),
	_Anim(ped, KO_skid_front),
	_Anim(ped, KO_spin_L),
	_Anim(ped, KO_spin_R),
	_Anim(ped, pass_Smoke_in_car),
	_Anim(ped, phone_in),
	_Anim(ped, phone_out),
	_Anim(ped, phone_talk),
	_Anim(ped, Player_Sneak),
	_Anim(ped, Player_Sneak_walkstart),
	_Anim(ped, roadcross),
	_Anim(ped, roadcross_female),
	_Anim(ped, roadcross_gang),
	_Anim(ped, roadcross_old),
	_Anim(ped, run_1armed),
	_Anim(ped, run_armed),
	_Anim(ped, run_civi),
	_Anim(ped, run_csaw),
	_Anim(ped, run_fat),
	_Anim(ped, run_fatold),
	_Anim(ped, run_gang1),
	_Anim(ped, run_left),
	_Anim(ped, run_old),
	_Anim(ped, run_player),
	_Anim(ped, run_right),
	_Anim(ped, run_rocket),
	_Anim(ped, Run_stop),
	_Anim(ped, Run_stopR),
	_Anim(ped, Run_Wuzi),
	_Anim(ped, SEAT_down),
	_Anim(ped, SEAT_idle),
	_Anim(ped, SEAT_up),
	_Anim(ped, SHOT_leftP),
	_Anim(ped, SHOT_partial),
	_Anim(ped, SHOT_partial_B),
	_Anim(ped, SHOT_rightP),
	_Anim(ped, Shove_Partial),
	_Anim(ped, Smoke_in_car),
	_Anim(ped, sprint_civi),
	_Anim(ped, sprint_panic),
	_Anim(ped, Sprint_Wuzi),
	_Anim(ped, swat_run),
	_Anim(ped, Swim_Tread),
	_Anim(ped, Tap_hand),
	_Anim(ped, Tap_handP),
	_Anim(ped, turn_180),
	_Anim(ped, Turn_L),
	_Anim(ped, Turn_R),
	_Anim(ped, WALK_armed),
	_Anim(ped, WALK_civi),
	_Anim(ped, WALK_csaw),
	_Anim(ped, Walk_DoorPartial),
	_Anim(ped, WALK_drunk),
	_Anim(ped, WALK_fat),
	_Anim(ped, WALK_fatold),
	_Anim(ped, WALK_gang1),
	_Anim(ped, WALK_gang2),
	_Anim(ped, WALK_old),
	_Anim(ped, WALK_player),
	_Anim(ped, WALK_rocket),
	_Anim(ped, WALK_shuffle),
	_Anim(ped, WALK_start),
	_Anim(ped, WALK_start_armed),
	_Anim(ped, WALK_start_csaw),
	_Anim(ped, WALK_start_rocket),
	_Anim(ped, Walk_Wuzi),
	_Anim(ped, WEAPON_crouch),
	_Anim(ped, woman_idlestance),
	_Anim(ped, woman_run),
	_Anim(ped, WOMAN_runbusy),
	_Anim(ped, WOMAN_runfatold),
	_Anim(ped, woman_runpanic),
	_Anim(ped, WOMAN_runsexy),
	_Anim(ped, WOMAN_walkbusy),
	_Anim(ped, WOMAN_walkfatold),
	_Anim(ped, WOMAN_walknorm),
	_Anim(ped, WOMAN_walkold),
	_Anim(ped, WOMAN_walkpro),
	_Anim(ped, WOMAN_walksexy),
	_Anim(ped, WOMAN_walkshop),
	_Anim(ped, XPRESSscratch),
// Name: PLAYER_DVBYS, animations count: 4
	_Anim(PLAYER_DVBYS, Plyr_DrivebyBwd),
	_Anim(PLAYER_DVBYS, Plyr_DrivebyFwd),
	_Anim(PLAYER_DVBYS, Plyr_DrivebyLHS),
	_Anim(PLAYER_DVBYS, Plyr_DrivebyRHS),
// Name: PLAYIDLES, animations count: 5
	_Anim(PLAYIDLES, shift),
	_Anim(PLAYIDLES, shldr),
	_Anim(PLAYIDLES, stretch),
	_Anim(PLAYIDLES, strleg),
	_Anim(PLAYIDLES, time),
// Name: POLICE, animations count: 10
	_Anim(POLICE, CopTraf_Away),
	_Anim(POLICE, CopTraf_Come),
	_Anim(POLICE, CopTraf_Left),
	_Anim(POLICE, CopTraf_Stop),
	_Anim(POLICE, COP_getoutcar_LHS),
	_Anim(POLICE, Cop_move_FWD),
	_Anim(POLICE, crm_drgbst_01),
	_Anim(POLICE, Door_Kick),
	_Anim(POLICE, plc_drgbst_01),
	_Anim(POLICE, plc_drgbst_02),
// Name: POOL, animations count: 21
	_Anim(POOL, POOL_ChalkCue),
	_Anim(POOL, POOL_Idle_Stance),
	_Anim(POOL, POOL_Long_Shot),
	_Anim(POOL, POOL_Long_Shot_O),
	_Anim(POOL, POOL_Long_Start),
	_Anim(POOL, POOL_Long_Start_O),
	_Anim(POOL, POOL_Med_Shot),
	_Anim(POOL, POOL_Med_Shot_O),
	_Anim(POOL, POOL_Med_Start),
	_Anim(POOL, POOL_Med_Start_O),
	_Anim(POOL, POOL_Place_White),
	_Anim(POOL, POOL_Short_Shot),
	_Anim(POOL, POOL_Short_Shot_O),
	_Anim(POOL, POOL_Short_Start),
	_Anim(POOL, POOL_Short_Start_O),
	_Anim(POOL, POOL_Walk),
	_Anim(POOL, POOL_Walk_Start),
	_Anim(POOL, POOL_XLong_Shot),
	_Anim(POOL, POOL_XLong_Shot_O),
	_Anim(POOL, POOL_XLong_Start),
	_Anim(POOL, POOL_XLong_Start_O),
// Name: POOR, animations count: 2
	_Anim(POOR, WINWASH_Start),
	_Anim(POOR, WINWASH_Wash2Beg),
// Name: PYTHON, animations count: 5
	_Anim(PYTHON, python_crouchfire),
	_Anim(PYTHON, python_crouchreload),
	_Anim(PYTHON, python_fire),
	_Anim(PYTHON, python_fire_poor),
	_Anim(PYTHON, python_reload),
// Name: QUAD, animations count: 17
	_Anim(QUAD, QUAD_back),
	_Anim(QUAD, QUAD_driveby_FT),
	_Anim(QUAD, QUAD_driveby_LHS),
	_Anim(QUAD, QUAD_driveby_RHS),
	_Anim(QUAD, QUAD_FWD),
	_Anim(QUAD, QUAD_getoff_B),
	_Anim(QUAD, QUAD_getoff_LHS),
	_Anim(QUAD, QUAD_getoff_RHS),
	_Anim(QUAD, QUAD_geton_LHS),
	_Anim(QUAD, QUAD_geton_RHS),
	_Anim(QUAD, QUAD_hit),
	_Anim(QUAD, QUAD_kick),
	_Anim(QUAD, QUAD_Left),
	_Anim(QUAD, QUAD_passenger),
	_Anim(QUAD, QUAD_reverse),
	_Anim(QUAD, QUAD_ride),
	_Anim(QUAD, QUAD_Right),
// Name: QUAD_DBZ, animations count: 4
	_Anim(QUAD_DBZ, Pass_Driveby_BWD),
	_Anim(QUAD_DBZ, Pass_Driveby_FWD),
	_Anim(QUAD_DBZ, Pass_Driveby_LHS),
	_Anim(QUAD_DBZ, Pass_Driveby_RHS),
// Name: RAPPING, animations count: 8
	_Anim(RAPPING, Laugh_01),
	_Anim(RAPPING, RAP_A_IN),
	_Anim(RAPPING, RAP_A_Loop),
	_Anim(RAPPING, RAP_A_OUT),
	_Anim(RAPPING, RAP_B_IN),
	_Anim(RAPPING, RAP_B_Loop),
	_Anim(RAPPING, RAP_B_OUT),
	_Anim(RAPPING, RAP_C_Loop),
// Name: RIFLE, animations count: 5
	_Anim(RIFLE, RIFLE_crouchfire),
	_Anim(RIFLE, RIFLE_crouchload),
	_Anim(RIFLE, RIFLE_fire),
	_Anim(RIFLE, RIFLE_fire_poor),
	_Anim(RIFLE, RIFLE_load),
// Name: RIOT, animations count: 7
	_Anim(RIOT, RIOT_ANGRY),
	_Anim(RIOT, RIOT_ANGRY_B),
	_Anim(RIOT, RIOT_challenge),
	_Anim(RIOT, RIOT_CHANT),
	_Anim(RIOT, RIOT_FUKU),
	_Anim(RIOT, RIOT_PUNCHES),
	_Anim(RIOT, RIOT_shout),
// Name: ROB_BANK, animations count: 5
	_Anim(ROB_BANK, CAT_Safe_End),
	_Anim(ROB_BANK, CAT_Safe_Open),
	_Anim(ROB_BANK, CAT_Safe_Open_O),
	_Anim(ROB_BANK, CAT_Safe_Rob),
	_Anim(ROB_BANK, SHP_HandsUp_Scr),
// Name: ROCKET, animations count: 5
	_Anim(ROCKET, idle_rocket),
	_Anim(ROCKET, RocketFire),
	_Anim(ROCKET, run_rocket),
	_Anim(ROCKET, walk_rocket),
	_Anim(ROCKET, WALK_start_rocket),
// Name: RUNNINGMAN, animations count: 33
	_Anim(RUNNINGMAN, Dance_B1),
	_Anim(RUNNINGMAN, Dance_B10),
	_Anim(RUNNINGMAN, Dance_B11),
	_Anim(RUNNINGMAN, Dance_B12),
	_Anim(RUNNINGMAN, Dance_B13),
	_Anim(RUNNINGMAN, Dance_B14),
	_Anim(RUNNINGMAN, Dance_B15),
	_Anim(RUNNINGMAN, Dance_B16),
	_Anim(RUNNINGMAN, Dance_B2),
	_Anim(RUNNINGMAN, Dance_B3),
	_Anim(RUNNINGMAN, Dance_B4),
	_Anim(RUNNINGMAN, Dance_B5),
	_Anim(RUNNINGMAN, Dance_B6),
	_Anim(RUNNINGMAN, Dance_B7),
	_Anim(RUNNINGMAN, Dance_B8),
	_Anim(RUNNINGMAN, Dance_B9),
	_Anim(RUNNINGMAN, Dance_G1),
	_Anim(RUNNINGMAN, Dance_G10),
	_Anim(RUNNINGMAN, Dance_G11),
	_Anim(RUNNINGMAN, Dance_G12),
	_Anim(RUNNINGMAN, Dance_G13),
	_Anim(RUNNINGMAN, Dance_G14),
	_Anim(RUNNINGMAN, Dance_G15),
	_Anim(RUNNINGMAN, Dance_G16),
	_Anim(RUNNINGMAN, Dance_G2),
	_Anim(RUNNINGMAN, Dance_G3),
	_Anim(RUNNINGMAN, Dance_G4),
	_Anim(RUNNINGMAN, Dance_G5),
	_Anim(RUNNINGMAN, Dance_G6),
	_Anim(RUNNINGMAN, Dance_G7),
	_Anim(RUNNINGMAN, Dance_G8),
	_Anim(RUNNINGMAN, Dance_G9),
	_Anim(RUNNINGMAN, dance_loop),
// Name: RUSTLER, animations count: 5
	_Anim(RUSTLER, Plane_align_LHS),
	_Anim(RUSTLER, Plane_close),
	_Anim(RUSTLER, Plane_getin),
	_Anim(RUSTLER, Plane_getout),
	_Anim(RUSTLER, Plane_open),
// Name: RYDER, animations count: 16
	_Anim(RYDER, RYD_Beckon_01),
	_Anim(RYDER, RYD_Beckon_02),
	_Anim(RYDER, RYD_Beckon_03),
	_Anim(RYDER, RYD_Die_PT1),
	_Anim(RYDER, RYD_Die_PT2),
	_Anim(RYDER, Van_Crate_L),
	_Anim(RYDER, Van_Crate_R),
	_Anim(RYDER, Van_Fall_L),
	_Anim(RYDER, Van_Fall_R),
	_Anim(RYDER, Van_Lean_L),
	_Anim(RYDER, Van_Lean_R),
	_Anim(RYDER, VAN_PickUp_E),
	_Anim(RYDER, VAN_PickUp_S),
	_Anim(RYDER, Van_Stand),
	_Anim(RYDER, Van_Stand_Crate),
	_Anim(RYDER, Van_Throw),
// Name: SCRATCHING, animations count: 12
	_Anim(SCRATCHING, scdldlp),
	_Anim(SCRATCHING, scdlulp),
	_Anim(SCRATCHING, scdrdlp),
	_Anim(SCRATCHING, scdrulp),
	_Anim(SCRATCHING, sclng_l),
	_Anim(SCRATCHING, sclng_r),
	_Anim(SCRATCHING, scmid_l),
	_Anim(SCRATCHING, scmid_r),
	_Anim(SCRATCHING, scshrtl),
	_Anim(SCRATCHING, scshrtr),
	_Anim(SCRATCHING, sc_ltor),
	_Anim(SCRATCHING, sc_rtol),
// Name: SEX, animations count: 20
	_Anim(SEX, SEX_1to2_P),
	_Anim(SEX, SEX_1to2_W),
	_Anim(SEX, SEX_1_Cum_P),
	_Anim(SEX, SEX_1_Cum_W),
	_Anim(SEX, SEX_1_Fail_P),
	_Anim(SEX, SEX_1_Fail_W),
	_Anim(SEX, SEX_1_P),
	_Anim(SEX, SEX_1_W),
	_Anim(SEX, SEX_2to3_P),
	_Anim(SEX, SEX_2to3_W),
	_Anim(SEX, SEX_2_Fail_P),
	_Anim(SEX, SEX_2_Fail_W),
	_Anim(SEX, SEX_2_P),
	_Anim(SEX, SEX_2_W),
	_Anim(SEX, SEX_3to1_P),
	_Anim(SEX, SEX_3to1_W),
	_Anim(SEX, SEX_3_Fail_P),
	_Anim(SEX, SEX_3_Fail_W),
	_Anim(SEX, SEX_3_P),
	_Anim(SEX, SEX_3_W),
// Name: SHAMAL, animations count: 4
	_Anim(SHAMAL, SHAMAL_align),
	_Anim(SHAMAL, SHAMAL_getin_LHS),
	_Anim(SHAMAL, SHAMAL_getout_LHS),
	_Anim(SHAMAL, SHAMAL_open),
// Name: SHOP, animations count: 25
	_Anim(SHOP, ROB_2Idle),
	_Anim(SHOP, ROB_Loop),
	_Anim(SHOP, ROB_Loop_Threat),
	_Anim(SHOP, ROB_Shifty),
	_Anim(SHOP, ROB_StickUp_In),
	_Anim(SHOP, SHP_Duck),
	_Anim(SHOP, SHP_Duck_Aim),
	_Anim(SHOP, SHP_Duck_Fire),
	_Anim(SHOP, SHP_Gun_Aim),
	_Anim(SHOP, SHP_Gun_Duck),
	_Anim(SHOP, SHP_Gun_Fire),
	_Anim(SHOP, SHP_Gun_Grab),
	_Anim(SHOP, SHP_Gun_Threat),
	_Anim(SHOP, SHP_HandsUp_Scr),
	_Anim(SHOP, SHP_Jump_Glide),
	_Anim(SHOP, SHP_Jump_Land),
	_Anim(SHOP, SHP_Jump_Launch),
	_Anim(SHOP, SHP_Rob_GiveCash),
	_Anim(SHOP, SHP_Rob_HandsUp),
	_Anim(SHOP, SHP_Rob_React),
	_Anim(SHOP, SHP_Serve_End),
	_Anim(SHOP, SHP_Serve_Idle),
	_Anim(SHOP, SHP_Serve_Loop),
	_Anim(SHOP, SHP_Serve_Start),
	_Anim(SHOP, Smoke_RYD),
// Name: SHOTGUN, animations count: 3
	_Anim(SHOTGUN, shotgun_crouchfire),
	_Anim(SHOTGUN, shotgun_fire),
	_Anim(SHOTGUN, shotgun_fire_poor),
// Name: SILENCED, animations count: 4
	_Anim(SILENCED, CrouchReload),
	_Anim(SILENCED, SilenceCrouchfire),
	_Anim(SILENCED, Silence_fire),
	_Anim(SILENCED, Silence_reload),
// Name: SKATE, animations count: 3
	_Anim(SKATE, skate_idle),
	_Anim(SKATE, skate_run),
	_Anim(SKATE, skate_sprint),
// Name: SMOKING, animations count: 8
	_Anim(SMOKING, F_smklean_loop),
	_Anim(SMOKING, M_smklean_loop),
	_Anim(SMOKING, M_smkstnd_loop),
	_Anim(SMOKING, M_smk_drag),
	_Anim(SMOKING, M_smk_in),
	_Anim(SMOKING, M_smk_loop),
	_Anim(SMOKING, M_smk_out),
	_Anim(SMOKING, M_smk_tap),
// Name: SNIPER, animations count: 1
	_Anim(SNIPER, WEAPON_sniper),
// Name: SnM, animations count: 22
	_Anim(SnM, SnM_Caned_Idle_P),
	_Anim(SnM, SnM_Caned_Idle_W),
	_Anim(SnM, SnM_Caned_P),
	_Anim(SnM, SnM_Caned_W),
	_Anim(SnM, SnM_Cane_Idle_P),
	_Anim(SnM, SnM_Cane_Idle_W),
	_Anim(SnM, SnM_Cane_P),
	_Anim(SnM, SnM_Cane_W),
	_Anim(SnM, SpankedP),
	_Anim(SnM, SpankedW),
	_Anim(SnM, Spanked_IdleP),
	_Anim(SnM, Spanked_IdleW),
	_Anim(SnM, SpankingP),
	_Anim(SnM, SpankingW),
	_Anim(SnM, Spanking_endP),
	_Anim(SnM, Spanking_endW),
	_Anim(SnM, Spanking_IdleP),
	_Anim(SnM, Spanking_IdleW),
	_Anim(SnM, Spanking_SittingIdleP),
	_Anim(SnM, Spanking_SittingIdleW),
	_Anim(SnM, Spanking_SittingP),
	_Anim(SnM, Spanking_SittingW),
// Name: SPRAYCAN, animations count: 2
	_Anim(SPRAYCAN, spraycan_fire),
	_Anim(SPRAYCAN, spraycan_full),
// Name: STRIP, animations count: 20
	_Anim(STRIP, PLY_CASH),
	_Anim(STRIP, PUN_CASH),
	_Anim(STRIP, PUN_HOLLER),
	_Anim(STRIP, PUN_LOOP),
	_Anim(STRIP, strip_A),
	_Anim(STRIP, strip_B),
	_Anim(STRIP, strip_C),
	_Anim(STRIP, strip_D),
	_Anim(STRIP, strip_E),
	_Anim(STRIP, strip_F),
	_Anim(STRIP, strip_G),
	_Anim(STRIP, STR_A2B),
	_Anim(STRIP, STR_B2A),
	_Anim(STRIP, STR_B2C),
	_Anim(STRIP, STR_C1),
	_Anim(STRIP, STR_C2),
	_Anim(STRIP, STR_C2B),
	_Anim(STRIP, STR_Loop_A),
	_Anim(STRIP, STR_Loop_B),
	_Anim(STRIP, STR_Loop_C),
// Name: SUNBATHE, animations count: 18
	_Anim(SUNBATHE, batherdown),
	_Anim(SUNBATHE, batherup),
	_Anim(SUNBATHE, Lay_Bac_in),
	_Anim(SUNBATHE, Lay_Bac_out),
	_Anim(SUNBATHE, ParkSit_M_IdleA),
	_Anim(SUNBATHE, ParkSit_M_IdleB),
	_Anim(SUNBATHE, ParkSit_M_IdleC),
	_Anim(SUNBATHE, ParkSit_M_in),
	_Anim(SUNBATHE, ParkSit_M_out),
	_Anim(SUNBATHE, ParkSit_W_idleA),
	_Anim(SUNBATHE, ParkSit_W_idleB),
	_Anim(SUNBATHE, ParkSit_W_idleC),
	_Anim(SUNBATHE, ParkSit_W_in),
	_Anim(SUNBATHE, ParkSit_W_out),
	_Anim(SUNBATHE, SBATHE_F_LieB2Sit),
	_Anim(SUNBATHE, SBATHE_F_Out),
	_Anim(SUNBATHE, SitnWait_in_W),
	_Anim(SUNBATHE, SitnWait_out_W),
// Name: SWAT, animations count: 23
	_Anim(SWAT, gnstwall_injurd),
	_Anim(SWAT, JMP_Wall1m_180),
	_Anim(SWAT, Rail_fall),
	_Anim(SWAT, Rail_fall_crawl),
	_Anim(SWAT, swt_breach_01),
	_Anim(SWAT, swt_breach_02),
	_Anim(SWAT, swt_breach_03),
	_Anim(SWAT, swt_go),
	_Anim(SWAT, swt_lkt),
	_Anim(SWAT, swt_sty),
	_Anim(SWAT, swt_vent_01),
	_Anim(SWAT, swt_vent_02),
	_Anim(SWAT, swt_vnt_sht_die),
	_Anim(SWAT, swt_vnt_sht_in),
	_Anim(SWAT, swt_vnt_sht_loop),
	_Anim(SWAT, swt_wllpk_L),
	_Anim(SWAT, swt_wllpk_L_back),
	_Anim(SWAT, swt_wllpk_R),
	_Anim(SWAT, swt_wllpk_R_back),
	_Anim(SWAT, swt_wllshoot_in_L),
	_Anim(SWAT, swt_wllshoot_in_R),
	_Anim(SWAT, swt_wllshoot_out_L),
	_Anim(SWAT, swt_wllshoot_out_R),
// Name: SWEET, animations count: 7
	_Anim(SWEET, ho_ass_slapped),
	_Anim(SWEET, LaFin_Player),
	_Anim(SWEET, LaFin_Sweet),
	_Anim(SWEET, plyr_hndshldr_01),
	_Anim(SWEET, sweet_ass_slap),
	_Anim(SWEET, sweet_hndshldr_01),
	_Anim(SWEET, Sweet_injuredloop),
// Name: SWIM, animations count: 7
	_Anim(SWIM, Swim_Breast),
	_Anim(SWIM, SWIM_crawl),
	_Anim(SWIM, Swim_Dive_Under),
	_Anim(SWIM, Swim_Glide),
	_Anim(SWIM, Swim_jumpout),
	_Anim(SWIM, Swim_Tread),
	_Anim(SWIM, Swim_Under),
// Name: SWORD, animations count: 10
	_Anim(SWORD, sword_1),
	_Anim(SWORD, sword_2),
	_Anim(SWORD, sword_3),
	_Anim(SWORD, sword_4),
	_Anim(SWORD, sword_block),
	_Anim(SWORD, Sword_Hit_1),
	_Anim(SWORD, Sword_Hit_2),
	_Anim(SWORD, Sword_Hit_3),
	_Anim(SWORD, sword_IDLE),
	_Anim(SWORD, sword_part),
// Name: TANK, animations count: 6
	_Anim(TANK, TANK_align_LHS),
	_Anim(TANK, TANK_close_LHS),
	_Anim(TANK, TANK_doorlocked),
	_Anim(TANK, TANK_getin_LHS),
	_Anim(TANK, TANK_getout_LHS),
	_Anim(TANK, TANK_open_LHS),
// Name: TATTOOS, animations count: 57
	_Anim(TATTOOS, TAT_ArmL_In_O),
	_Anim(TATTOOS, TAT_ArmL_In_P),
	_Anim(TATTOOS, TAT_ArmL_In_T),
	_Anim(TATTOOS, TAT_ArmL_Out_O),
	_Anim(TATTOOS, TAT_ArmL_Out_P),
	_Anim(TATTOOS, TAT_ArmL_Out_T),
	_Anim(TATTOOS, TAT_ArmL_Pose_O),
	_Anim(TATTOOS, TAT_ArmL_Pose_P),
	_Anim(TATTOOS, TAT_ArmL_Pose_T),
	_Anim(TATTOOS, TAT_ArmR_In_O),
	_Anim(TATTOOS, TAT_ArmR_In_P),
	_Anim(TATTOOS, TAT_ArmR_In_T),
	_Anim(TATTOOS, TAT_ArmR_Out_O),
	_Anim(TATTOOS, TAT_ArmR_Out_P),
	_Anim(TATTOOS, TAT_ArmR_Out_T),
	_Anim(TATTOOS, TAT_ArmR_Pose_O),
	_Anim(TATTOOS, TAT_ArmR_Pose_P),
	_Anim(TATTOOS, TAT_ArmR_Pose_T),
	_Anim(TATTOOS, TAT_Back_In_O),
	_Anim(TATTOOS, TAT_Back_In_P),
	_Anim(TATTOOS, TAT_Back_In_T),
	_Anim(TATTOOS, TAT_Back_Out_O),
	_Anim(TATTOOS, TAT_Back_Out_P),
	_Anim(TATTOOS, TAT_Back_Out_T),
	_Anim(TATTOOS, TAT_Back_Pose_O),
	_Anim(TATTOOS, TAT_Back_Pose_P),
	_Anim(TATTOOS, TAT_Back_Pose_T),
	_Anim(TATTOOS, TAT_Back_Sit_In_P),
	_Anim(TATTOOS, TAT_Back_Sit_Loop_P),
	_Anim(TATTOOS, TAT_Back_Sit_Out_P),
	_Anim(TATTOOS, TAT_Bel_In_O),
	_Anim(TATTOOS, TAT_Bel_In_T),
	_Anim(TATTOOS, TAT_Bel_Out_O),
	_Anim(TATTOOS, TAT_Bel_Out_T),
	_Anim(TATTOOS, TAT_Bel_Pose_O),
	_Anim(TATTOOS, TAT_Bel_Pose_T),
	_Anim(TATTOOS, TAT_Che_In_O),
	_Anim(TATTOOS, TAT_Che_In_P),
	_Anim(TATTOOS, TAT_Che_In_T),
	_Anim(TATTOOS, TAT_Che_Out_O),
	_Anim(TATTOOS, TAT_Che_Out_P),
	_Anim(TATTOOS, TAT_Che_Out_T),
	_Anim(TATTOOS, TAT_Che_Pose_O),
	_Anim(TATTOOS, TAT_Che_Pose_P),
	_Anim(TATTOOS, TAT_Che_Pose_T),
	_Anim(TATTOOS, TAT_Drop_O),
	_Anim(TATTOOS, TAT_Idle_Loop_O),
	_Anim(TATTOOS, TAT_Idle_Loop_T),
	_Anim(TATTOOS, TAT_Sit_In_O),
	_Anim(TATTOOS, TAT_Sit_In_P),
	_Anim(TATTOOS, TAT_Sit_In_T),
	_Anim(TATTOOS, TAT_Sit_Loop_O),
	_Anim(TATTOOS, TAT_Sit_Loop_P),
	_Anim(TATTOOS, TAT_Sit_Loop_T),
	_Anim(TATTOOS, TAT_Sit_Out_O),
	_Anim(TATTOOS, TAT_Sit_Out_P),
	_Anim(TATTOOS, TAT_Sit_Out_T),
// Name: TEC, animations count: 4
	_Anim(TEC, TEC_crouchfire),
	_Anim(TEC, TEC_crouchreload),
	_Anim(TEC, TEC_fire),
	_Anim(TEC, TEC_reload),
// Name: TRAIN, animations count: 4
	_Anim(TRAIN, tran_gtup),
	_Anim(TRAIN, tran_hng),
	_Anim(TRAIN, tran_ouch),
	_Anim(TRAIN, tran_stmb),
// Name: TRUCK, animations count: 17
	_Anim(TRUCK, TRUCK_ALIGN_LHS),
	_Anim(TRUCK, TRUCK_ALIGN_RHS),
	_Anim(TRUCK, TRUCK_closedoor_LHS),
	_Anim(TRUCK, TRUCK_closedoor_RHS),
	_Anim(TRUCK, TRUCK_close_LHS),
	_Anim(TRUCK, TRUCK_close_RHS),
	_Anim(TRUCK, TRUCK_getin_LHS),
	_Anim(TRUCK, TRUCK_getin_RHS),
	_Anim(TRUCK, TRUCK_getout_LHS),
	_Anim(TRUCK, TRUCK_getout_RHS),
	_Anim(TRUCK, TRUCK_jackedLHS),
	_Anim(TRUCK, TRUCK_jackedRHS),
	_Anim(TRUCK, TRUCK_open_LHS),
	_Anim(TRUCK, TRUCK_open_RHS),
	_Anim(TRUCK, TRUCK_pullout_LHS),
	_Anim(TRUCK, TRUCK_pullout_RHS),
	_Anim(TRUCK, TRUCK_Shuffle),
// Name: UZI, animations count: 5
	_Anim(UZI, UZI_crouchfire),
	_Anim(UZI, UZI_crouchreload),
	_Anim(UZI, UZI_fire),
	_Anim(UZI, UZI_fire_poor),
	_Anim(UZI, UZI_reload),
// Name: VAN, animations count: 8
	_Anim(VAN, VAN_close_back_LHS),
	_Anim(VAN, VAN_close_back_RHS),
	_Anim(VAN, VAN_getin_Back_LHS),
	_Anim(VAN, VAN_getin_Back_RHS),
	_Anim(VAN, VAN_getout_back_LHS),
	_Anim(VAN, VAN_getout_back_RHS),
	_Anim(VAN, VAN_open_back_LHS),
	_Anim(VAN, VAN_open_back_RHS),
// Name: VENDING, animations count: 6
	_Anim(VENDING, VEND_Drink2_P),
	_Anim(VENDING, VEND_Drink_P),
	_Anim(VENDING, vend_eat1_P),
	_Anim(VENDING, VEND_Eat_P),
	_Anim(VENDING, VEND_Use),
	_Anim(VENDING, VEND_Use_pt2),
// Name: VORTEX, animations count: 4
	_Anim(VORTEX, CAR_jumpin_LHS),
	_Anim(VORTEX, CAR_jumpin_RHS),
	_Anim(VORTEX, vortex_getout_LHS),
	_Anim(VORTEX, vortex_getout_RHS),
// Name: WAYFARER, animations count: 18
	_Anim(WAYFARER, WF_Back),
	_Anim(WAYFARER, WF_drivebyFT),
	_Anim(WAYFARER, WF_drivebyLHS),
	_Anim(WAYFARER, WF_drivebyRHS),
	_Anim(WAYFARER, WF_Fwd),
	_Anim(WAYFARER, WF_getoffBACK),
	_Anim(WAYFARER, WF_getoffLHS),
	_Anim(WAYFARER, WF_getoffRHS),
	_Anim(WAYFARER, WF_hit),
	_Anim(WAYFARER, WF_jumponL),
	_Anim(WAYFARER, WF_jumponR),
	_Anim(WAYFARER, WF_kick),
	_Anim(WAYFARER, WF_Left),
	_Anim(WAYFARER, WF_passenger),
	_Anim(WAYFARER, WF_pushes),
	_Anim(WAYFARER, WF_Ride),
	_Anim(WAYFARER, WF_Right),
	_Anim(WAYFARER, WF_Still),
// Name: WEAPONS, animations count: 17
	_Anim(WEAPONS, SHP_1H_Lift),
	_Anim(WEAPONS, SHP_1H_Lift_End),
	_Anim(WEAPONS, SHP_1H_Ret),
	_Anim(WEAPONS, SHP_1H_Ret_S),
	_Anim(WEAPONS, SHP_2H_Lift),
	_Anim(WEAPONS, SHP_2H_Lift_End),
	_Anim(WEAPONS, SHP_2H_Ret),
	_Anim(WEAPONS, SHP_2H_Ret_S),
	_Anim(WEAPONS, SHP_Ar_Lift),
	_Anim(WEAPONS, SHP_Ar_Lift_End),
	_Anim(WEAPONS, SHP_Ar_Ret),
	_Anim(WEAPONS, SHP_Ar_Ret_S),
	_Anim(WEAPONS, SHP_G_Lift_In),
	_Anim(WEAPONS, SHP_G_Lift_Out),
	_Anim(WEAPONS, SHP_Tray_In),
	_Anim(WEAPONS, SHP_Tray_Out),
	_Anim(WEAPONS, SHP_Tray_Pose),
// Name: WOP, animations count: 33
	_Anim(WOP, Dance_B1),
	_Anim(WOP, Dance_B10),
	_Anim(WOP, Dance_B11),
	_Anim(WOP, Dance_B12),
	_Anim(WOP, Dance_B13),
	_Anim(WOP, Dance_B14),
	_Anim(WOP, Dance_B15),
	_Anim(WOP, Dance_B16),
	_Anim(WOP, Dance_B2),
	_Anim(WOP, Dance_B3),
	_Anim(WOP, Dance_B4),
	_Anim(WOP, Dance_B5),
	_Anim(WOP, Dance_B6),
	_Anim(WOP, Dance_B7),
	_Anim(WOP, Dance_B8),
	_Anim(WOP, Dance_B9),
	_Anim(WOP, Dance_G1),
	_Anim(WOP, Dance_G10),
	_Anim(WOP, Dance_G11),
	_Anim(WOP, Dance_G12),
	_Anim(WOP, Dance_G13),
	_Anim(WOP, Dance_G14),
	_Anim(WOP, Dance_G15),
	_Anim(WOP, Dance_G16),
	_Anim(WOP, Dance_G2),
	_Anim(WOP, Dance_G3),
	_Anim(WOP, Dance_G4),
	_Anim(WOP, Dance_G5),
	_Anim(WOP, Dance_G6),
	_Anim(WOP, Dance_G7),
	_Anim(WOP, Dance_G8),
	_Anim(WOP, Dance_G9),
	_Anim(WOP, dance_loop),
// Name: WUZI, animations count: 12
	_Anim(WUZI, CS_Dead_Guy),
	_Anim(WUZI, CS_Plyr_pt1),
	_Anim(WUZI, CS_Plyr_pt2),
	_Anim(WUZI, CS_Wuzi_pt1),
	_Anim(WUZI, CS_Wuzi_pt2),
	_Anim(WUZI, Walkstart_Idle_01),
	_Anim(WUZI, Wuzi_follow),
	_Anim(WUZI, Wuzi_Greet_Plyr),
	_Anim(WUZI, Wuzi_Greet_Wuzi),
	_Anim(WUZI, Wuzi_grnd_chk),
	_Anim(WUZI, Wuzi_stand_loop),
	_Anim(WUZI, Wuzi_Walk)
};

#undef	_Anim
#undef	_AnimLib


static anim__preload_status[MAX_PLAYERS char];
static anim__initialization_status = 0;

static anim__PreloadLibraries(playerid)
{
	if(anim__preload_status{playerid} == 0)
	{
		for(new i=0; i<sizeof(anim__libs); ++i)
			ApplyAnimation(	playerid, anim__libs[i][eAnimLib_Name], "nope",
							4.1, 0, 0, 0, 0, 1, 1);
		anim__preload_status{playerid} = 1;
	}
	return 1;
}

public OnPlayerSpawn(playerid)
{
	// preload all animation libraries
	anim__PreloadLibraries(playerid);
#if	defined	anim__OnPlayerSpawn
	anim__OnPlayerSpawn(playerid);
#endif
	return 1;
}
#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn anim__OnPlayerSpawn
#if defined anim__OnPlayerSpawn
    forward anim__OnPlayerSpawn(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	anim__preload_status{playerid} = 0;
#if	defined	anim__OnPlayerDisconnect
	anim__OnPlayerDisconnect(playerid, reason);
#endif
	return 1;
}
#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect anim__OnPlayerDisconnect
#if defined anim__OnPlayerDisconnect
    forward anim__OnPlayerDisconnect(playerid, reason);
#endif

static anim__Initialize()
{
	new i = GetMaxPlayers();
	do{
		if(IsPlayerConnected(--i))
			anim__PreloadLibraries(i);
	}while(i);
	new j;
	// convert names of all animation libraries to lowercase
	{
		new k, c[(cellbits/charbits) char], break_flag;
		for(i=0; i<sizeof(anim__libs); ++i)
		{
			break_flag = 0;
			for(j=0; ; ++j)
			{
				c[0] = anim__libs[i][eAnimLib_Name][j];
				for(k=0; k<sizeof(c)*(cellbits/charbits); ++k)
				{
					if('A' <= c{k} <= 'Z')
					{
						c{k} += 'a'-'A';
					}
					else if(c{k} == EOS)
					{
						break_flag = 1;
						break;
					}
				}
				anim__libs[i][eAnimLib_Name][j] = c[0];
				if(break_flag)
					break;
			}
		}
	}
	new cur_animlib_name[MAX_ANIM_LIB_NAME+1], cur_animlib_id = -1;
	cur_animlib_name[0] = EOS;
	for(i=0; ; ++i)
	{
		if(anim__info[i][eAnim_LibID] != cur_animlib_id)
		{
			if(cur_animlib_id != -1)
				anim__libs[cur_animlib_id][eAnimLib_LastAnim] = i-1;
			cur_animlib_id = anim__info[i][eAnim_LibID];
			if(cur_animlib_id == sizeof(anim__libs)
			|| anim__libs[cur_animlib_id][eAnimLib_FirstAnim] != -1)
			{
#if defined DC_ANIMS_LANG_EN
				print(!"dc_anims.inc: Invalid animations table");
#else // LANG = RU
				print(!"dc_anims.inc: Неправильная таблица анимаций");
#endif
				return 0;
			}
			cur_animlib_name[0] = EOS;
			strcat(cur_animlib_name, anim__libs[cur_animlib_id][eAnimLib_Name]);
			anim__libs[cur_animlib_id][eAnimLib_FirstAnim] = i;
		}
		if(i == sizeof(anim__info)-1)
		{
			anim__libs[cur_animlib_id][eAnimLib_LastAnim] = i-1;
			break;
		}
	}
	anim__initialization_status = 1;
	return 1;
}

public OnGameModeInit()
{
	anim__Initialize();
#if	defined	anim__OnGameModeInit
	anim__OnGameModeInit();
#endif
	return 1;
}
#if	defined	_ALS_OnGameModeInit
	#undef	OnGameModeInit
#else
	#define	_ALS_OnGameModeInit
#endif
#define	OnGameModeInit	anim__OnGameModeInit
#if	defined	anim__OnGameModeInit
	forward anim__OnGameModeInit();
#endif

public OnFilterScriptInit()
{
	anim__Initialize();
#if	defined	anim__OnFilterScriptInit
	anim__OnFilterScriptInit();
#endif
	return 1;
}
#if	defined	_ALS_OnFilterScriptInit
	#undef	OnFilterScriptInit
#else
	#define	_ALS_OnFilterScriptInit
#endif
#define	OnFilterScriptInit	anim__OnFilterScriptInit
#if	defined	anim__OnFilterScriptInit
	forward anim__OnFilterScriptInit();
#endif


anim__func:anim(playerid, params[])
{
	if(anim__initialization_status == 0)
	{
	#if defined DC_ANIMS_LANG_EN
		static const str_initialization_error[] =
			!DC_ANIMS_ERROR_COLOR"Error: Invalid animations table!";
	#else // LANG = RU
		static const str_initialization_error[] =
			!DC_ANIMS_ERROR_COLOR"Ошибка: Неправильная таблица анимаций!";
	#endif
		return SendClientMessage(playerid, -1, str_initialization_error);
	}
	// if no parameters specified - display help message
	if(isnull(params))
	{
	#if defined DC_ANIMS_LANG_EN
		static const str_usage[] =
			!DC_ANIMS_COLOR"Usage: {ffffff}/anim [animlib] [animation ID]";
		static const str_available_libs[] =
			DC_ANIMS_COLOR"Available animation libraries:{ffffff}";
		static const str_total_anims[] =
			DC_ANIMS_COLOR"Total: {ffffff}%d animations in %d libraries.";
	#else // LANG = RU
		static const str_usage[] =
			!DC_ANIMS_COLOR"Использование: {ffffff}/anim [набор] [ID анимации]";
		static const str_available_libs[] =
			DC_ANIMS_COLOR"Доступные наборы:{ffffff}";
		static const str_total_anims[] =
			DC_ANIMS_COLOR"Итого: {ffffff}%d анимаций в %d наборах.";
	#endif
		SendClientMessage(playerid, -1, str_usage);
list_animlibs:
		// list all animation libraries
		// (dynamic systems are so dynamic...)
		new string[144];
		string = str_available_libs;
		new len = sizeof(str_available_libs)-1;
		for(new i=0; ; )
		{
			if(strlen(anim__libs[i][eAnimLib_Name])+1 > sizeof(string)-len)
			{
				SendClientMessage(playerid, -1, string);
				len = strunpack(string, anim__libs[i][eAnimLib_Name]);
			}
			else
			{
				if(i != 0)
					string[len++] = ',';
				string[len++] = ' ';
				string[len] = ' ';	// I dunno why, but strunpack
									// won't work without this
				len += strunpack(	string[len], anim__libs[i][eAnimLib_Name],
									sizeof(string)-len);
			}
			if(++i == sizeof(anim__libs))
			{
				SendClientMessage(playerid, -1, string);
				break;
			}
		}
		format(	string, sizeof(string), str_total_anims,
				sizeof(anim__info), sizeof(anim__libs));
		return SendClientMessage(playerid, -1, string);
	}
	// hardcore parameters processing without using sscanf2
	// due to its lack of specifier alternates
	// (even thougs alternates were implemented in sscanf3,
	// it's not released yet, so it's better not use it in production)
	//
	// TODO: rewrite all this **** when the sscanf3 will be released
	new pos = 1;
	for(; ; ++pos)
	{
		switch(params[pos])
		{
			case EOS:
			{
				break;
			}
			case ' ':
			{
				params[pos++] = EOS;
				break;
			}
		}
	}
	// there is no animation library with name shorter than 3 symbols
	// so there's no point in searching for it
	if(pos < 3)
		goto unknown_animlib;
	new animlib_id=0;
	for( ; animlib_id<sizeof(anim__libs); ++animlib_id)
		if(0 == strcmp(params, anim__libs[animlib_id][eAnimLib_Name]))
			goto found_animlib;
	if(animlib_id == sizeof(anim__libs))
	{
unknown_animlib:
	#if defined DC_ANIMS_LANG_EN
		static const str_unknown_animlib[] =
			!DC_ANIMS_ERROR_COLOR"Unknown library name.";
	#else // LANG = RU
		static const str_unknown_animlib[] =
			!DC_ANIMS_ERROR_COLOR"Неизвестное название библиотеки!";
	#endif
		SendClientMessage(playerid, -1, str_unknown_animlib);
		goto list_animlibs;
	}
found_animlib:
	new anim_id;
	if(anim__libs[animlib_id][eAnimLib_FirstAnim]
	== anim__libs[animlib_id][eAnimLib_LastAnim])
	{
		anim_id = anim__libs[animlib_id][eAnimLib_FirstAnim];
		goto play_animation;
	}
	while(params[pos] == ' '){pos++;}
	if(params[pos] == '\0' || !('0' <= params[pos] <= '9'))
		goto invalid_anim_id;
	for(new i=pos+1;;++i)
		if(params[i] == '\0')
			goto valid_anim_id;
		else if(!('0' <= params[i] <= '9'))
			goto invalid_anim_id;
	if(pos != 0)// this condition actually does nothing and supposed to
				// trick compiler to avoid "unreachable code" warning
	{
invalid_anim_id:
	#if defined DC_ANIMS_LANG_EN
		static const str_no_animid[] =
			DC_ANIMS_COLOR"Usage: {ffffff}/anim %s [1-%d]";
	#else // LANG = RU
		static const str_no_animid[] =
			DC_ANIMS_COLOR"Использование: {ffffff}/anim %s [1-%d]";
	#endif
		new string[sizeof(str_no_animid)-2+MAX_ANIM_LIB_NAME-2+3];
		strunpack(string, anim__libs[animlib_id][eAnimLib_Name]);
		format(	string, sizeof(string), str_no_animid,
				string,
				anim__libs[animlib_id][eAnimLib_LastAnim]
				-anim__libs[animlib_id][eAnimLib_FirstAnim]+1);
		return SendClientMessage(playerid, -1, string);
	}
valid_anim_id:
	anim_id=anim__libs[animlib_id][eAnimLib_FirstAnim]+(strval(params[pos])-1);
	if(anim_id < anim__libs[animlib_id][eAnimLib_FirstAnim]
	|| anim_id > anim__libs[animlib_id][eAnimLib_LastAnim])
	{
	#if defined DC_ANIMS_LANG_EN
		static const str_invalid_animid[] =
			DC_ANIMS_ERROR_COLOR"Invalid animation ID!";
	#else // LANG = RU
		static const str_invalid_animid[] =
			DC_ANIMS_ERROR_COLOR"Неправильный ID анимации!";
	#endif
		SendClientMessage(playerid, -1, str_invalid_animid);
		goto invalid_anim_id;
	}
play_animation:
	return ApplyAnimation(	playerid,
							anim__libs[animlib_id][eAnimLib_Name],
							anim__info[anim_id][eAnim_Name],
							4.1, 0, 1, 1, 1, 1);
}


anim__func:stopanim(playerid, params[])
{
	#pragma	unused	params
	return ApplyAnimation(playerid,"BD_FIRE","BD_FIRE1",8.2,0,0,0,0,1,1);
}

#if !defined DC_ANIMS_DISABLE_ACTIONS

#define _Action(%0,%1)	{{!#%1}, SPECIAL_ACTION_%0}

enum e_ACTION_INFO
{
	eAction_Name[(MAX_ACTION_NAME+1)/(cellbits/charbits)],
	eAction_Value
};

static const anim__actions[][e_ACTION_INFO] =
{
	_Action(DANCE1,			dance1),
	_Action(DANCE2,			dance2),
	_Action(DANCE3,			dance3),
	_Action(DANCE4,			dance4),
	_Action(DRINK_BEER,		beer),
	_Action(DRINK_SPRUNK,	sprunk),
	_Action(DRINK_WINE,		wine),
	_Action(PISSING,		pee),
	_Action(SMOKE_CIGGY,	smoke)
};

#undef	_Action

anim__func:action(playerid, params[])
{
	if(isnull(params))
	{
	#if defined DC_ANIMS_LANG_EN
		static const str_incorrect_params[] =
			!DC_ANIMS_COLOR"Usage: {ffffff}/action [special action]";
		static const str_available_actions[] =
			DC_ANIMS_COLOR"Available actions:{ffffff}";
	#else // LANG = RU
		static const str_incorrect_params[] =
			!DC_ANIMS_COLOR"Использование: {ffffff}/action [действие]";
		static const str_available_actions[] =
			DC_ANIMS_COLOR"Доступные действия:{ffffff}";
	#endif
		SendClientMessage(playerid, -1, str_incorrect_params);
available_actions:
		// list all actions in the same way as in /anim
		new string[144];
		string = str_available_actions;
		new len = sizeof(str_available_actions)-1;
		for(new i=0; ; )
		{
			if(strlen(anim__actions[i][eAction_Name])+1 > sizeof(string)-len)
			{
				SendClientMessage(playerid, -1, string);
				len = strunpack(string, anim__actions[i][eAction_Name]);
			}
			else
			{
				if(i != 0)
					string[len++] = ',';
				string[len++] = ' ';
				string[len] = ' ';
				len += strunpack(	string[len], anim__actions[i][eAction_Name],
									sizeof(string)-len);
			}
			if(++i == sizeof(anim__actions))
			{
				SendClientMessage(playerid, -1, string);
				break;
			}
		}
		return 1;
	}
	// and again, hardcore parameters processing -_-
	// (this time just to remove dependency from sscanf2)
	new pos = 1;
	for(; ; ++pos)
	{
		switch(params[pos])
		{
			case EOS:
			{
				break;
			}
			case ' ':
			{
				// don't give a **** to excessive parameters, just cut them off
				params[pos] = EOS;
				break;
			}
		}
	}
	// there is no action with name shorter than 3 symbols
	// so there's no point in searching for it
	if(pos < 3)
	{
incorrect_action_name:
	#if defined DC_ANIMS_LANG_EN
		static const str_incorrect_action[] =
			!DC_ANIMS_ERROR_COLOR"Incorrect action name!";
	#else // LANG = RU
		static const str_incorrect_action[] =
			!DC_ANIMS_ERROR_COLOR"Неизвестное название действия!";
	#endif
		SendClientMessage(playerid, -1, str_incorrect_action);
		goto available_actions;
	}
	new action_id = 0;
	for(; action_id<sizeof(anim__actions); ++action_id)
		if(0 == strcmp(params, anim__actions[action_id][eAction_Name]))
			goto found_action;
	if(action_id == sizeof(anim__actions))
		goto incorrect_action_name;
found_action:
	return SetPlayerSpecialAction(	playerid,
									anim__actions[action_id][eAction_Value]);
}

#endif	//#if !defined DC_ANIMS_DISABLE_ACTIONS

#if !defined CMD

public OnPlayerCommandText(playerid, cmdtext[])
{
	// remove excessive space characters at the end of cmdtext
	new cmd_end = 0, params_pos = 0;
	for(new i=0; ; ++i)
	{
		if(cmdtext[i] == '\0')
		{
			break;
		}
		if(cmdtext[i] == ' ')
		{
			// remove excessive space characters at the end of cmdtext
			new j=strlen(cmdtext)-1;
			if(cmdtext[j] == ' ')
				for(--j; j>i; --j)
					if(cmdtext[j] != ' ')
					{
						cmdtext[j+1] = '\0';
						break;
					}
			// separate command from its parameters
			cmdtext[i] = '\0';
			// if parameters weren't just a heap of useless spaces
			if(cmdtext[i+1] != '\0')
			{
				// save command end position to restore ' ' character
				// before calling original OPCT
				cmd_end = i;
				// skip excessive spaces before parameters
				params_pos = i+1;
				while(cmdtext[params_pos] == ' '){++params_pos;}
			}
			break;
		}
	}
	// find and call matching command
	if(0 == strcmp(cmdtext, "/anim"))
		return anim__func_anim(playerid, cmdtext[params_pos]);
	if(0 == strcmp(cmdtext, "/stopanim"))
		return anim__func_stopanim(playerid, cmdtext[params_pos]);
#if !defined DC_ANIMS_DISABLE_ACTIONS
	if(0 == strcmp(cmdtext, "/action"))
		return anim__func_action(playerid, cmdtext[params_pos]);
#endif
#if	defined	anim__OnPlayerCommandText
	/*
	// if cmdtext has params - it has been modified, so we need to restore it
	if(params_pos != 0)
		cmdtext[pos] = ' ';
	*/
	// restore ' ' character if it's needed
	if(cmd_end != 0)
		cmdtext[cmd_end] = ' ';
	// call the original OPCT
	return anim__OnPlayerCommandText(playerid, cmdtext);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerCommandText
	#undef OnPlayerCommandText
#else
	#define _ALS_OnPlayerCommandText
#endif
#if defined anim__OnPlayerCommandText
	forward anim__OnPlayerCommandText(playerid, cmdtext[]);
#endif
#define	OnPlayerCommandText anim__OnPlayerCommandText

#endif	//#if !defined CMD