public OnPlayerCommandReceived(playerid, cmd[], params[], flags) {
	if(!PI[playerid][PLAYER_Logged]) return 0;
	return 1;
}

hook OnPlayerDisconnect(playerid) {
	DestroyVehicle(AVeh[playerid]);
	return 1;
}


///////////////////////////////////////////////////[������� ��� �������������� 1+ ������]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[������� ��� �������������� 2+ ������]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[������� ��� �������������� 3+ ������]////////////////////////////////////////////////////////////////////

cmd:setskin(playerid, params[])
{
	if(PI[playerid][PLAYER_Admin] < 3) return UnknownCommand(playerid);
    if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_WHITE_L, !"����������� /setskin [ID ������] [ID �����]");
    if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_WHITE_L, !"������ �� ����������");
    if(params[1] < 0 || params[1] > 311) return SendClientMessage(playerid, COLOR_WHITE_L, !"ID ������ �� 0 �� 311");
	if(!PI[params[0]][PLAYER_Logged]) return SendClientMessage(playerid, COLOR_WHITE_L, !"����� ��� �� �����");
    SetPlayerSkin(params[0], params[1]);
	return 1;
}

cmd:veh(playerid, params[])
{
    if(PI[playerid][PLAYER_Admin] < 3) return UnknownCommand(playerid);
    if(!sscanf(params, "ddd", params[0], params[1], params[2]))
	{
        if(params[0] < 400 || params[0] > 611) return SendClientMessage(playerid, COLOR_WHITE_L, !"ID ���������� �� 400 �� 611");
        if(params[1] < 0 || params[1] > 255 || params[2] < 0 || params[2] > 255) return SendClientMessage(playerid, COLOR_WHITE_L, !"ID ����� �� 0 �� 255");
        if(AVeh[playerid] != 0) DestroyVehicle(AVeh[playerid]);
        new Float:x, Float:y, Float:z, Float:a;
        GetPlayerTurn(playerid, x, y, z, 5, 180);
        AVeh[playerid] = CreateVehicle(params[0], x, y, z, a, params[1], params[2], 0, 0);
        LinkVehicleToInterior(AVeh[playerid], GetPlayerInterior(playerid));
		SetVehicleVirtualWorld(AVeh[playerid], GetPlayerVirtualWorld(playerid));
	}
	else if(!sscanf(params, "k<vehiclemodel>dd", params[0], params[1], params[2]))
	{
        if(params[1] < 0 || params[1] > 255 || params[2] < 0 || params[2] > 255) return SendClientMessage(playerid, COLOR_WHITE_L, !"ID ����� �� 0 �� 255");
        if(AVeh[playerid] != 0) DestroyVehicle(AVeh[playerid]);
        new Float:x, Float:y, Float:z, Float:a;
        GetPlayerTurn(playerid, x, y, z, 5, 180);
        AVeh[playerid] = CreateVehicle(params[0], x, y, z, a, 1, 1, 0, 0);
        LinkVehicleToInterior(AVeh[playerid], GetPlayerInterior(playerid));
		SetVehicleVirtualWorld(AVeh[playerid], GetPlayerVirtualWorld(playerid));
	}
	else return SendClientMessage(playerid, COLOR_WHITE_L, !"����������� /veh [ID/���] [ID �����] [ID �����]");
	ChangeVehicleColor(AVeh[playerid], params[1], params[2]);
	return 1;
}

///////////////////////////////////////////////////[������� ��� �������������� 4+ ������]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[������� ��� �������������� 5+ ������]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[������� ��� �������������� 6+ ������]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[������� ��� �������������� 7+ ������]////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////[������� ��� �������������� 8+ ������]////////////////////////////////////////////////////////////////////

cmd:makeadmin(playerid, params[])
{
    if(strcmp(PI[playerid][PLAYER_Name], "Selena_Lunysh") && PI[playerid][PLAYER_Admin] < 8 && strcmp(PI[playerid][PLAYER_Name], "Folinq_Weard")) return UnknownCommand(playerid);
    if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, COLOR_WHITE_L, !"����������� /makeadmin [ID] [��.]");
    if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_WHITE_L, !"������ � ����� ID �� ����������");
	if(!PI[params[0]][PLAYER_Logged]) return SendClientMessage(playerid, COLOR_WHITE_L, !"����� ��� �� �����");
	if(params[1] > 7 || params[1] < 0) return SendClientMessage(playerid, COLOR_WHITE_L, !"�� 0 �� 7 ������");
    PI[params[0]][PLAYER_Admin] = params[1];
    new string[120];
	format(string, sizeof(string), "UPDATE `accounts` SET `admin` = '%d' WHERE `id` = '%d'", PI[params[0]][PLAYER_Admin], PI[params[0]][PLAYER_ID]);
	mysql_tquery(dbHandle, string);
	return 1;
}