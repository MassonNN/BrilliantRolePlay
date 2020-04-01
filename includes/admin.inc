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
	if(PI[playerid][PLAYER_Admin] > 0) 
	{
		new str[50];
		format(str, sizeof(str), "Вы вошли как %s", AdminLevelName[PI[playerid][PLAYER_Admin]-1]);
		SendClientMessage(playerid, 0xFFFFFFFF, str);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}