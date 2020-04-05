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

///////////////////////////////////////////////////[ÊÎÌÀÍÄÛ ÄËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ 1+ ÓĞÎÂÍß]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[ÊÎÌÀÍÄÛ ÄËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ 2+ ÓĞÎÂÍß]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[ÊÎÌÀÍÄÛ ÄËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ 3+ ÓĞÎÂÍß]////////////////////////////////////////////////////////////////////

cmd:setskin(playerid, params[])
{
	if(PI[playerid][PLAYER_Admin] < 3) return UnknownCommand(playerid);
    if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_WHITE_L, !"Èñïîëüçóéòå /setskin [ID èãğîêà] [ID ñêèíà]");
    if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_WHITE_L, !"Èãğîêà íå ñóùåñòâóåò");
    if(params[1] < 0 || params[1] > 311) return SendClientMessage(playerid, COLOR_WHITE_L, !"ID ñêèíîâ îò 0 äî 311");
	if(!PI[params[0]][PLAYER_Logged]) return SendClientMessage(playerid, COLOR_WHITE_L, !"Èãğîê åùå íå âîøåë");
    SetPlayerSkin(params[0], params[1]);
	return 1;
}

///////////////////////////////////////////////////[ÊÎÌÀÍÄÛ ÄËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ 4+ ÓĞÎÂÍß]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[ÊÎÌÀÍÄÛ ÄËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ 5+ ÓĞÎÂÍß]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[ÊÎÌÀÍÄÛ ÄËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ 6+ ÓĞÎÂÍß]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[ÊÎÌÀÍÄÛ ÄËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ 7+ ÓĞÎÂÍß]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[ÊÎÌÀÍÄÛ ÄËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ 8+ ÓĞÎÂÍß]////////////////////////////////////////////////////////////////////

cmd:makeadmin(playerid, params[])
{
    if(strcmp(PI[playerid][PLAYER_Name], "Marshall_Mathers") && PI[playerid][PLAYER_Admin] < 8 && strcmp(PI[playerid][PLAYER_Name], "Folinq_Weard")) return UnknownCommand(playerid);
    if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_WHITE_L, !"Èñïîëüçóéòå /makeadmin [ID] [Óğ.]");
    if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_WHITE_L, !"Èãğîêà ñ òàêèì ID íå ñóùåñòâóåò");
	if(!PI[params[0]][PLAYER_Logged]) return SendClientMessage(playerid, COLOR_WHITE_L, !"Èãğîê åùå íå âîøåë");
	if(params[1] > 7 || params[1] < 0) return SendClientMessage(playerid, COLOR_WHITE_L, !"Îò 0 äî 7 óğîâíÿ");
    PI[params[0]][PLAYER_Admin] = params[1];
    new string[120];
	format(string, sizeof(string), "UPDATE `accounts` SET `admin` = '%d' WHERE `id` = '%d'", PI[params[0]][PLAYER_Admin], PI[params[0]][PLAYER_ID]);
	mysql_tquery(dbHandle, string);
	return 1;
}