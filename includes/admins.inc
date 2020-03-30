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
	if(IsPlayerAdmin(playerid) {

		new str[125];
		format(str, sizeof(str), "Вы в%s", )
		SendClientMessage(playerid, 0xFFFFFFFF, !"Hi"))
	}
	return 1;
}