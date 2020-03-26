// ���������� ��� ������� ������
// v.01.02


#define MAX_BANK_ACCOUNTS 	10
#define MAX_VEHICLES		3
#define MAX_BUSINESSES		3


// SEX
#define MAN					1
#define WOMAN				2
#define NOT_SET				0

// LANGUAGE
#define RUSSIAN				0 // default
#define ENGLISH				1
#define UKRAINIAN			2
#define POLISH				3
#define 		

enum PLAYER_Stats {
	PLAYER_Name[MAX_PLAYER_NAME], 	// ��� ������
	PLAYER_Sex, 					// ��� ������. 1 - �������, 2 - �������, 0 - �� ������
	PLAYER_Money, 					// ������ ������ �� �����
	PLAYER_BankMoney[MAX_BANK_ACCOUNTS], // ������ ������ � ����� �� ������ ������ (����������� ���� 10, �� ����� ��������)
	PLAYER_Level, 					// ������� ������
	PLAYER_Exp, 					// ����� � ������
	PLAYER_MuteTime, 				// ����� � ������� �� ��������� �������
	PLAYER_BanTime, 				// ����� � ����� �� ��������� ������� �������� ����������
	PLAYER_Warns, 					// ���������� ������
	PLAYER_Reputation, 				// ������� ��������� ������, �� ������ � ��������� ���������� ��� BrilliantAntiCheat
	PLAYER_Age, 					// ������� ������� ������
	PLAYER_Admin,					// ������� ��������������
	PLAYER_Logged,					// ����� �� ����� � �������. 0 - ���, 1 - ��, 2 - ��������� � ��������
	PLAYER_Language					// ID ����� ������

}; // ��� ������ ���������� ������ getter � setter, ��. API

new PI[MAX_PLAYERS][PLAYER_Stats];

enum PLAYER_Licenses {
	PLAYER_LIC_CAR_EXP_TIME, 		// ����� � ����� �� ��������� ����� ������������ ����
	PLAYER_LIC_FLY_EXP_TIME, 		// ����� � ����� �� ��������� ����� �������� ������
	PLAYER_LIC_WATER_EXP_TIME, 		// ����� � ����� �� ��������� ����� �������� ������� �/c
	PLAYER_LIC_GUN_EXP_TIME 		// ����� � ����� �� ��������� ����� �������� �� ������
}; // ��� ������ ���������� ������ getter � setter, ��. API

new PL[MAX_PLAYERS][PLAYER_Licenses];


enum PLAYER_Property { // ��������� ������
	PLAYER_House,					// ��� ������
	PLAYER_Vehicle[MAX_VEHICLES],	// ������ ������
	PLAYER_Model,					// ���� ������
	PLAYER_Business[MAX_BUSINESSES] // ������ ������
}; 

new PP[MAX_PLAYERS][PLAYER_Property];