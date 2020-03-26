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

