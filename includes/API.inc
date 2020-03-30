// ??? ???? ? ??? ??? ? ??? ???? ???     ??? ??? ? 
// ??? ???? ? ??? ??? ? ??? ???? ???     ??? ??? ? 
// ??? ???? ? ??? ??? ? ??? ???? ???     ??? ??? ? 


// Форматированное сообщение
#define 	SendFormatMessage(%1, %2, %3, %4)			format(global, 128, %3, %4), SendMessage(%1, %2, %3);

// 


// Отправить игроку подсказку
stock SendPond(playerid, text[]) {
	SendFormatMessage(playerid, COLOR_YELLOW_L, POND_TEXT, text);
}

// Отправить игроку информацию
stock SendInfo(playerid, text[]) {
	SendFormatMessage(playerid, COLOR_GREEN_L, INFO_TEXT, text);
}

// Отправить игроку сообщение об успешном выполнении
stock SendSuccess(playerid, text[]) {
	SendFormatMessage(playerid, COLOR_HAKI_L, SUCCESS_TEXT, text);
}



// ERRORS

enum ERRORS_LIST {
	ERROR_OUT_OF_MEMORY,
	ERROR_UNAVAIBLE_TEXT,
	ERROR_DATA_ZERO,
	ERROR_CUSTOM
};




// Отправить игроку ошибку
stock SendError(playerid, text[], error_id = 0) {
	if(error_id == 0) SendFormatMessage(playerid, COLOR_RED_L, ERROR_TEXT, text);
	else {
		if (1 <= error_id <= 11) SendFormatMessage(playerid, COLOR_RED_L, ERROR_TEXT_WITH_ID, error_id, text);
		else if (11 < error_id <= 20) {
			SendFormatMessage(playerid, COLOR_RED_L, ERROR_TEXT_WITH_ID, error_id, text);
			SendPond(playerid, ERROR_CONTACT_US);
		}
	}
}

// Отправить сообщение администрации, где color - цвет, minlevel - минимальный уровень админа для отправления сообщения
stock SendAdmin(text[], color = -1, minlevel = 1) {
	foreach(new i : Player) {
		if(PI[i][PLAYER_Admin] < minlevel) continue;
		else {
			SendMessage(i, color, text);
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

stock CheckAdmin(playerid, minlevel = 1) 
{
	if(GetPlayerAdminLevel(playerid) < minlevel) return SendErr(playerid, "Неизвестная команда. Воспользуйтесь /mm - Помощь.");
	else return 1;
}

stock SetPlayerSex(playerid, sex) {
	if(sex == 3) return 0;
	PI[playerid][PLAYER_Sex] = sex;
	return sex;
}


// END PLAYER

