// ??? ???? ? ??? ??? ? ??? ???? ???     ??? ??? ? 
// ??? ???? ? ??? ??? ? ??? ???? ???     ??? ??? ? 
// ??? ???? ? ??? ??? ? ??? ???? ???     ??? ??? ? 


// Форматированное сообщение
#define 	SendFormatMessage(%1,%2,%3,%4)			format(global,128,%3,%4), SendMessage(%1,%2,%3)

stock UnknownCommand(playerid) {
	SendClientMessage(playerid, COLOR_WHITE_L, !"Этой команды не существует. Используйте "COLOR_HAKI_S"/mm "COLOR_WHITE_S"-> "COLOR_HAKI_S"команды "COLOR_WHITE_S"для просмотра списка команд");
	return 1;
}

stock LoggedInAdmin(playerid) {
	format(global, sizeof(global), "<ADM> %s вошел в систему администрирования", PI[playerid][PLAYER_Name]);
	SendAdmin(global, COLOR_HAKI_S);
	return 1;
}

//Игрок не зареган в админке
stock NotLoggedInAdmin(playerid) {
	SendClientMessage(playerid, COLOR_WHITE_L, !"Для того, чтобы использывать эту "COLOR_HAKI_S"команду "COLOR_WHITE_S"- войдите в систему администрирования используя "COLOR_HAKI_S"/alogin");
	return 1;
}

//Задержка для кика (fix)
stock GKick(playerid) {
	SetTimerEx("KickPlayer", 50, false, "d", playerid);
	return 1;
}

forward KickPlayer(playerid);
public KickPlayer(playerid) {
	Kick(playerid);
	return 1;
}

//Заморозить игрока
stock FreezePlayer(playerid, time) {
	TogglePlayerControllable(playerid, 0);
	SetTimerEx("UnFreezePlayer", time, false, "d", playerid);
}

forward UnFreezePlayer(playerid);
public UnFreezePlayer(playerid) {
	TogglePlayerControllable(playerid, 1);
	return 1;
}

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


stock GetPlayerTurn(playerid, &Float:x, &Float:y, &Float:z, Float:distance, turn)
{
    new Float:angle,Float:dis;
    dis = dis/2 - distance;
    GetPlayerPos(playerid, x, y, z),GetPlayerFacingAngle(playerid, angle);
    x += (dis * floatsin(-angle+turn, degrees)),y += (dis * floatcos(-angle+turn, degrees));
    return 1;
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
stock SendAdmin(const text[], color = -1, minlevel = 1) {
	foreach(new i : Player) {
		if(PI[i][PLAYER_Admin] < minlevel) continue;
		else {
			SendClientMessage(i, color, text);
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

stock SetPlayerSex(playerid, sex) {
	if(sex == 1 || sex == 2) 
		PI[playerid][PLAYER_Sex] = sex;
	else
	return 0;
}


// END PLAYER

new SYSTEM_HI_RU[] = "Привет, мир!";
new SYSTEM_HI_EN[] = "Hi, World!";