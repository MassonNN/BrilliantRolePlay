public OnPlayerText(playerid, text[])
{
    if(!PI[playerid][PLAYER_Logged]) return Kick(playerid);
    if(PI[playerid][PLAYER_Admin] < 6)
	{
	    if(gettime()<GetPVarInt(playerid, "CMD"))
	    {
	        SendClientMessage(playerid, COLOR_ADM_L, !"Не флуди!");
	        return 0;
	    }
	    SetPVarInt(playerid, "CMD", gettime() + 1);
    }
	new string[144];
	if(strlen(text) < 113)
	{
	    format(string, sizeof(string), "%s[%d]: %s", PI[playerid][PLAYER_Name], playerid, text);
	    ProxDetector(20.0, playerid, string, COLOR_GRAY_L, COLOR_GRAY_L, COLOR_GRAY_L, COLOR_GRAY_L, COLOR_GRAY_L);
	    SetPlayerChatBubble(playerid, text, COLOR_WHITE_L, 20, 7500);
	    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	    {
			ApplyAnimation(playerid, "PED", "IDLE_chat", 4.1, 0, 1, 1, 1, 1);
			SetTimerEx("StopAnim", 3000, false, "d", playerid);
		}
	}
 	else
	{
		return 0;
	}
    return 0;
}

forward StopAnim(playerid);
public StopAnim(playerid)
{
    ApplyAnimation(playerid, "PED", "facanger", 4.1, 0, 1, 1, 1, 1);
    return 1;
}

stock ProxDetector(Float:radi, playerid, const string[],col1,col2,col3,col4,col5)
{
	if(IsPlayerConnected(playerid))
	{
		new Float:posx;new Float:posy;new Float:posz;new Float:oldposx;new Float:oldposy;new Float:oldposz;new Float:tempposx;new Float:tempposy;new Float:tempposz;
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		foreach(new i: Player)
		{
			if(IsPlayerConnected(i))
			{
				if(GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(i))
				{
					GetPlayerPos(i, posx, posy, posz);
					tempposx = (oldposx -posx);
					tempposy = (oldposy -posy);
					tempposz = (oldposz -posz);
					if(((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16))) SendClientMessage(i, col1, string);
					else if(((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8))) SendClientMessage(i, col2, string);
					else if(((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4))) SendClientMessage(i, col3, string);
					else if(((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2))) SendClientMessage(i, col4, string);
					else if(((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi))) SendClientMessage(i, col5, string);
				}
			}
		}
	}
	return 1;
}