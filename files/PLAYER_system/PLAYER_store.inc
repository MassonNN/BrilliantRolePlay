#include <YSI_Coding/y_hooks>

hook OnPlayerLogin(playerid)
{
	new ip[18];
	GetPlayerIp(playerid, ip, 18)æ
	format(global, sizeof(global), "UPDATE `accounts` SET `lastip` = '%s' WHERE `id` = '%d'", ip, PI[playerid][PLAYER_ID]);
	mysql_tquery(bHandle, global);
	return Y_HOOKS_CONTINUE_RETURN_1;
}
aaaaaa