// ??? ???? ? ??? ??? ? ??? ???? ???     ??? ??? ? 
// ??? ???? ? ??? ??? ? ??? ???? ???     ??? ??? ? 
// ??? ???? ? ??? ??? ? ??? ???? ???     ??? ??? ? 


// Форматированное сообщение
#define 	SendMessage(%1, %2, %3, %4)			format(global, 128, %3, %4), SendClientMessage(%1, %2, %3);

// 


// Отправить игроку подсказку
SendPond(playerid, text[]) {
	SendMessage(playerid, COLOR_YELLOW_L, POND_TEXT, text);
}

// Отправить игроку информацию
SendInfo(playerid, text[]) {
	SendMessage(playerid, COLOR_GREEN_L, INFO_TEXT, text);
}

// Отправить игроку сообщение об успешном выполнении
SendSuccess(playerid, text[]) {
	SendMessage(playerid, COLOR_HAKI_L, SUCCESS_TEXT, text);
}



// ERRORS

enum ERRORS_LIST {
	ERROR_OUT_OF_MEMORY,
	ERROR_UNAVAIBLE_TEXT,
	ERROR_DATA_ZERO,
	ERROR_CUSTOM
};




// Отправить игроку ошибку
SendError(playerid, text[], error_id = 0) {
	if(error_id == 0) SendMessage(playerid, COLOR_RED_L, ERROR_TEXT, text);
	else {
		if (1 <= error_id <= 11) SendMessage(playerid, COLOR_RED_L, ERROR_TEXT_WITH_ID, error_id, text);
		else if (11 < error_id <= 20) {
			SendMessage(playerid, COLOR_RED_L, ERROR_TEXT_WITH_ID, error_id, text);
			SendPond(playerid, ERROR_CONTACT_US);
		}
	}
}


// 


// PLAYER

#define GetPlayerSex(%0)		PI[%0][PLAYER_Sex]
#define GetMoney(%0)			PI[%0][PLAYER_Money]
#define GetBankMoney(%0, %1)	PI[%0][PLAYER_BankMoney][%1]
#define GetPlayerLevel(%0)		PI[%0][PLAYER_Level]
#define GetPlayerExp(%0)		PI[%0][PLAYER_Exp]
#define GetPlayerMuteTime(%0)	PI[%0][PLAYER_MuteTime]
#define IsPlayerMuted(playerid) if(PI[playerid][PLAYER_MuteTime]) return true, else return false;
#define GetPlayerBanTime(%0)	PI[%0][PLAYER_BanTime]
#define GetPlayerReputation(%0)	PI[%0][PLAYER_Reputation]
#define GetPlayerAge(%0)		PI[%0][PLAYER_Age]
#define GetPlayerAdminLevel(%0)	PI[%0][PLAYER_Admin]
PlayerTheAdmin(playerid, minlevel = 1) 
{
	if(GetPlayerAdminLevel(playerid) < minlevel) return false;
	else return true;
}

SetPlayerSex(playerid, sex) {
	if(sex == 3) return 0;
	PI[playerid][PLAYER_Sex] = sex;
	SendPond
}


// END PLAYER

new SYSTEM_HI_RU[] = "Привет, мир!";

