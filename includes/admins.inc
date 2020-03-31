#include <YSI_Coding/y_hooks>

#define IsPlayerAdmin(%0) 			if(playerinfo[%0][PLAYER_Admin]<1)return false

static const AdminLevelName[][] = {

	{"{ECFC03}Мл. Модератор"},
	{"{FCD303}Модератор"},
	{"{FC8C03}Мл. Администратор"},
	{"{FC3D03}Администратор"},
	{"{FC033D}Ст. Администратор"},
	{"{8803FC}Спец. Администратор"},
	{"{FC03E7}Основатель"},
	{"Разработчик"}
};

hook OnPlayerLogin(playerid)
{
	if(IsPlayerAdmin(playerid)) {

		new str[50];
		format(str, sizeof(str), "Вы вошли как %s", AdminLeveName[playerinfo[playerid][PLAYER_Admin]-1])
		SendClientMessage(playerid, 0xFFFFFFFF, str)
	}
	return 1;
}