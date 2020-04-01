static const AdminLevelName[][] = {

	{"{ECFC03}��. ���������"},
	{"{FCD303}���������"},
	{"{FC8C03}��. �������������"},
	{"{FC3D03}�������������"},
	{"{FC033D}��. �������������"},
	{"{8803FC}����. �������������"},
	{"{FC03E7}����������"},
	{"�����������"}
};

hook OnPlayerLogin(playerid)
{
	if(PI[playerid][PLAYER_Admin] > 0) 
	{
		new str[50];
		format(str, sizeof(str), "�� ����� ��� %s", AdminLevelName[PI[playerid][PLAYER_Admin]-1]);
		SendClientMessage(playerid, 0xFFFFFFFF, str);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}