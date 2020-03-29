// Переменные для системы игрока
// v.01.02


#define MAX_BANK_ACCOUNTS 	10
#define MAX_PLAYER_VEHICLES	3
#define MAX_BUSINESSES		3


// SEX
#define MAN					1
#define WOMAN				2
#define NOT_SET				0

enum PLAYER_Stats {
	PLAYER_Name[MAX_PLAYER_NAME], 	// Имя игрока
	PLAYER_Sex, 					// пол игрока. 1 - мужчина, 2 - женщина, 0 - не выбрал
	PLAYER_Money, 					// Деньги игрока на руках
	PLAYER_BankMoney[MAX_BANK_ACCOUNTS], // Деньги игрока в банке на разных счетах (максимально пока 10, но можно поменять)
	PLAYER_Level, 					// Уровень игрока
	PLAYER_Exp, 					// Опыта у игрока
	PLAYER_MuteTime, 				// Время в минутах до окончания затычки
	PLAYER_BanTime, 				// Время в часах до окончания времени действия блокировки
	PLAYER_Warns, 					// Количество варнов
	PLAYER_Reputation, 				// Игровая репутация игрока, не путать с системной репутацией для BrilliantAntiCheat
	PLAYER_Age, 					// Игровой возраст игрока
	PLAYER_Admin,					// Уровень администратора
	PLAYER_Logged,					// Вошел ли игрок в аккаунт. 0 - нет, 1 - да, 2 - вытолкнут с аккаунта
	PLAYER_Language,				// ID языка игрока

}; // под каждую переменную создан getter и setter, см. API

new PI[MAX_PLAYERS][PLAYER_Stats];

enum PLAYER_Licenses {
	PLAYER_LIC_CAR_EXP_TIME, 		// время в часах до окончания срока водительских прав
	PLAYER_LIC_FLY_EXP_TIME, 		// время в часах до окончания срока лицензии пилота
	PLAYER_LIC_WATER_EXP_TIME, 		// время в часах до окончания срока лицензии водного т/c
	PLAYER_LIC_GUN_EXP_TIME 		// время в часах до окончания срока лицензии на оружие
}; // под каждую переменную создан getter и setter, см. API

new PL[MAX_PLAYERS][PLAYER_Licenses];


enum PLAYER_Property { // имущество игрока
	PLAYER_House,					// дом игрока
	PLAYER_Vehicle[MAX_PLAYER_VEHICLES],	// машины игрока
	PLAYER_Model,					// скин игрока
	PLAYER_Business[MAX_BUSINESSES] // бизнес игрока
}; 

new PP[MAX_PLAYERS][PLAYER_Property];


enum PLAYER_Organization {
	PLAYER_Fraction,
	PLAYER_Rank,
	PLAYER_FracWarns,
	PLAYER_TimeInFrac[MAX_FRACS]
}