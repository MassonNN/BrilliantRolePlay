/* 

	?????????????????????????????????????????????????????     ????????????????????????     ????????????????????????????
	?????????????????????????????????????????????????????     ????????????????????????     ????????????????????????????
	?????????????????????????????????????????????????????     ????????????????????????     ????????????????????????????


	CEO: Roma Omegov
	Gamemode Developer: Folinq Weard
	Gamemode Developer: Selena_Lunysh (Female)

	��������� ��������� ��������� ���� ��� ����, ����� ��� ���� ������ �� �������� ���� � �������:

	��� ������� ����� ���� ���, �������� ������� ����� ����� ��� VEH_, ��� ������, ��� ��� ���������� ���� ������� ���������� � ����� ����:
	new VEH_id[100];
	new VEH_colors[10];

	� ����� ��� �������:

	VEH_CreatePlayerVehicle(playerid) {
		return 1;
	}

	���� ��� ���� ������� ��������� �� ����: includes / VEH / ...... 
	��: ������ � includes, � �� pawno/includes, � pawno/includes ����� ��������� �������, ������� ����� ���������� �����, � �� ���� �����������

	����� � (folinq weard) ������� ����������� API. �� ��������� ��������� ������� ����� ���-������, ������� �������� �� ���, ����� ������� ����
	����������� �������������� � ��������, � ����� ����� ������ API �������� ������ ���������� ������� ������������!:

	// �������� ������ ������, ������� ������ �� ���� ������
	// VEH_CreatePlayerVehicle(playerid) {
		........
	}

	�������, ������������ �����, ������ ������������ ������ ����!



*/


// ��������� �������
#include <a_samp>
#include <includes/API.inc>


// ������������ �������
#include <YSF.inc>
#include <YSI/y_hooks>
#include <mdialog>
#include <Pawn.CMD>
#include <Pawn.RakNet>
#include <foreach>
#include <mxINI>
