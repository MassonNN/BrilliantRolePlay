public OnPlayerSpawn(playerid)
{
	FreezePlayer(playerid, 2300);
	switch(random(5))
	{
		case 0: SetPlayerPos(playerid, 2507.1040, -2121.2522, 23.4558), SetPlayerFacingAngle(playerid, 180);
		case 1: SetPlayerPos(playerid, 2507.0884, -2124.2639, 23.4558), SetPlayerFacingAngle(playerid, 180);
		case 2: SetPlayerPos(playerid, 2506.5117, -2130.1980, 23.4558), SetPlayerFacingAngle(playerid, 0.0);
		case 3: SetPlayerPos(playerid, 2511.4604, -2120.7002, 23.4558), SetPlayerFacingAngle(playerid, 180);
		case 4: SetPlayerPos(playerid, 2511.4373, -2123.5974, 23.4558), SetPlayerFacingAngle(playerid, 180);
	}
	SetPlayerSkin(playerid, PI[playerid][PLAYER_Skin]);
	SetCameraBehindPlayer(playerid);

	return 1;
}
