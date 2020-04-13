public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
	if(result == -1) return UnknownCommand(playerid);
	return 1;
}

public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
	if(!PI[playerid][PLAYER_Logged]) return 0;
	return 1;
}
///////////////////////////////////////////////////[КОМАНДЫ ДЛЯ АДМИНИСТРАТОРА 1+ УРОВНЯ]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[КОМАНДЫ ДЛЯ АДМИНИСТРАТОРА 2+ УРОВНЯ]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[КОМАНДЫ ДЛЯ АДМИНИСТРАТОРА 3+ УРОВНЯ]////////////////////////////////////////////////////////////////////

cmd:setskin(playerid, params[])
{
	if(PI[playerid][PLAYER_Admin] < 4) return UnknownCommand(playerid);
    if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_WHITE_L, !"Используйте /setskin [ID игрока] [ID скина]");
    if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_WHITE_L, !"Игрока не существует");
    if(params[1] < 0 || params[1] > 311) return SendClientMessage(playerid, COLOR_WHITE_L, !"ID скинов от 0 до 311");
	if(!PI[params[0]][PLAYER_Logged]) return SendClientMessage(playerid, COLOR_WHITE_L, !"Игрок еще не вошел");
    SetPlayerSkin(params[0], params[1]);
	return 1;
}

///////////////////////////////////////////////////[КОМАНДЫ ДЛЯ АДМИНИСТРАТОРА 4+ УРОВНЯ]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[КОМАНДЫ ДЛЯ АДМИНИСТРАТОРА 5+ УРОВНЯ]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[КОМАНДЫ ДЛЯ АДМИНИСТРАТОРА 6+ УРОВНЯ]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[КОМАНДЫ ДЛЯ АДМИНИСТРАТОРА 7+ УРОВНЯ]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[КОМАНДЫ ДЛЯ АДМИНИСТРАТОРА 8+ УРОВНЯ]////////////////////////////////////////////////////////////////////

cmd:makeadmin(playerid, params[])
{
    if(strcmp(PI[playerid][PLAYER_Name], "Marshall_Mathers") && PI[playerid][PLAYER_Admin] < 8 && strcmp(PI[playerid][PLAYER_Name], "Folinq_Weard")) return UnknownCommand(playerid);
    if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_WHITE_L, !"Используйте /makeadmin [ID] [Ур.]");
    if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_WHITE_L, !"Игрока с таким ID не существует");
	if(!PI[params[0]][PLAYER_Logged]) return SendClientMessage(playerid, COLOR_WHITE_L, !"Игрок еще не вошел");
	if(params[0] == playerid) return SendClientMessage(playerid, COLOR_WHITE_L, !"Нельзя изменять свой уровень администрирования");
	if(params[1] > 7 || params[1] < 0) return SendClientMessage(playerid, COLOR_WHITE_L, !"От 0 до 7 уровня");
    PI[params[0]][PLAYER_Admin] = params[1];
    new string[120];
	format(string, sizeof(string), "UPDATE `accounts` SET `admin` = '%d' WHERE `id` = '%d'", PI[params[0]][PLAYER_Admin], PI[params[0]][PLAYER_ID]);
	mysql_tquery(dbHandle, string);
	return 1;
}