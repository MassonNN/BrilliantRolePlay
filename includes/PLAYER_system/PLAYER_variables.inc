// v.01.02


#define MAX_BANK_ACCOUNTS 	10
#define MAX_PLAYER_VEHICLES	3
#define MAX_BUSINESSES		3
#define MAX_FRACS	10


// SEX
#define MAN					1
#define WOMAN				2
#define NOT_SET				0

enum PLAYER_Stats {

	PLAYER_Name[MAX_PLAYER_NAME],
	PLAYER_IP[17], 
	PLAYER_Sex, 					
	PLAYER_Money, 					
	PLAYER_BankMoney[MAX_BANK_ACCOUNTS], 
	PLAYER_Level, 					
	PLAYER_Exp, 					
	PLAYER_MuteTime, 				
	PLAYER_BanTime, 				
	PLAYER_Warns, 					
	PLAYER_Reputation, 				
	PLAYER_Age, 					
	PLAYER_Admin,					
	PLAYER_Logged,					
	PLAYER_Language,				

}; 

new PI[MAX_PLAYERS][PLAYER_Stats];

enum PLAYER_Licenses {

	PLAYER_LIC_CAR_EXP_TIME, 		
	PLAYER_LIC_FLY_EXP_TIME, 		
	PLAYER_LIC_WATER_EXP_TIME, 		
	PLAYER_LIC_GUN_EXP_TIME 		
};

new PL[MAX_PLAYERS][PLAYER_Licenses];


enum PLAYER_Property { 

	PLAYER_House,					
	PLAYER_Vehicle[MAX_PLAYER_VEHICLES],
	PLAYER_Model,					
	PLAYER_Business[MAX_BUSINESSES] 
}; 

new PP[MAX_PLAYERS][PLAYER_Property];



enum PLAYER_Organization { 

	PLAYER_Fraction,				
	PLAYER_Rank,					
	PLAYER_FracWarns,				
	PLAYER_TimeInFrac[MAX_FRACS],	
	PLAYER_FracModel				
};

new PO[MAX_PLAYERS][PLAYER_Organization]; 