/* ������� ����������� 
	������: 0.1 ALPHA
	���������� ������� � 3 ������ 2020 ����
	Senior Gamemode Developer: Folinq Weard
	CEO: Roma Omegov
	
	
	
    ----------- Todo list
	- ������� ���������
	- ������� ����������/�������� ����������
	- ������� ����������� ���������/�������� ����������
	- ������� ��������� �����������

	
*/



// acc - ������� ��� ������� �����������

// #define acc_NUM 3 // ������� ������ ������� �����������
// #define acc_MaxName 32 // ������������ ���������� �������� � �������� ����������


// // -------- [�������� ����������] --------------

// #define COMMON 		1 // �������
// #define RARE		2 // ������
// #define SUPER_RARE	3 // �����������
// #define EXCLUSIVE	4 // ������������


/* -------- [���������� ID �����������] --------



*/
// ---------------------------------------------

// enum acc_Inform { // ���������� �� ����������
// 	acc_id, // id ���������� ��� ���������� ���������� � �����������
// 	acc_name[acc_MaxName], // ��� ����������
// 	acc_cost, // ���.��������� ����������
// 	acc_game_id, // ������� id ������� ����������
// 	acc_bone, // �����, � ������� �������� ��������� �� ���������
// 	acc_rarity // �������� ��������
// };

// new const static acc_Info[acc_NUM][acc_Inform] = {
// 	{0, "������", 			5000, 	18644, 	5, COMMON}, 
// 	{1, "������� �����", 	2000, 	18950, 	2, COMMON}, 
// 	{2, "������ �����", 	2000, 	18951,	2, COMMON} 
// };

// #define GetAccName(%1)		acc_Info[%1][acc_name]
// #define GetAccCost(%1)		acc_Info[%1][acc_cost]
// #define GetAccRarity(%1)	acc_Info[%1][acc_rarity]
// #define GetAccBone(%1)		acc_Info[%1][acc_bone]
// #define GetAccModel(%1)		acc_Info[%1][acc_game_id]

// #define IsValidAcc(%1)		(0 < %1 < acc_NUM)



 
// ------------------------------------------


// enum acc_PlayerInfo { // ���������� �� ������ �� ������� �����������
// 	bool:acc_bone_used[18], // ��������� ������ (����� 18)
// 	bool:acc_is_wear[18], // ��������� ������ (����� 18)
// 	bool:acc_is_have_acc[acc_NUM], // ���� �� � ������ ��������� (�� ���� ���-��)
// 	bool:acc_banned[acc_NUM] // ������������ �� ��������� � ����������� � ������
// }

// new acc_PI[MAX_PLAYERS][acc_PlayerInfo];

// #define IsBoneUsed(%1,%2) 		acc_PI[%1][acc_bone_used][%2]
// #define IsAccBanned(%1,%2)		acc_PI[%1][acc_banned][%2]
// #define IsPlayerHaveAcc(%1,%2)	acc_PI[%1][acc_is_have_acc][%2]
// #define IsPlayerWearAcc(%1,%2) acc_PI[%1][acc_is_wear][%2]


// AddAccToPlayer(playerid, acces_id, bool:banned = false) {
// 	if(!IsValidAcc(acces_id)) return 0;
// 	else {
// 		if(!IsPlayerConnected(playerid)) return 0;
// 		if(!PlayerLogged[playerid]) return 0;

// 		if(IsPlayerHaveAcc(playerid, acces_id)) { // ���������� ��� ���������� ���������� �� ����
// 			if(FindFreeSlot(playerid) > 9) { 
// 				SendErr(playerid, "���������� ������������ ���������� �����������");
// 				if(!PI[playerid][pVip]) SendTimeMessage(playerid, "��� ����, ����� ���������� ����� ���� ����������� ������������, ����������� VIP", 1000, POND_TYPE);
// 				return 0;
// 			}
			
// 			SetPlayerAttachedObject(playerid, \
// 			FindFreeSlot(playerid), \
// 			GetAccModel(acces_id), \
// 			GetAccBone(acces_id));
// 		}
// 		else  { // ���������� ������ ����������
// 			if (IsBoneUsed(playerid, GetAccBone(acces_id)) || FindFreeSlot(playerid) > 9) SendErr(playerid, "����� ��� ����� ��������� ������, �� �������� � ��� � ���������.");
// 			acc_PI[playerid][acc_is_have_acc][acces_id] = true;
// 			acc_PI[playerid][acc_banned][acces_id] = banned;
// 		}
// 	}
// 	return 1;
// }

// stock FindFreeSlot(playerid) {
// 	new maxss;
// 	if(PI[playerid][pVip]) maxss = 9;
// 	else maxss = 3;

// 	for(new i; i < maxss; i++) {
// 		if(IsPlayerAttachedObjectSlotUsed(playerid, i)) continue;
// 		else return i;
// 	} 
// 	return 10;
// }


// AccesList (playerid, id) {

// 	new string[128*acc_NUM], tmp[128];
// 	for(new i; i < acc_NUM; i++) {
// 		if(IsPlayerHaveAcc(playerid, i)) {
// 			format(tmp, sizeof tmp, "{FFFFFF}%s\t\t|\t\t%s{FFFFFF}\t\t|\t\t%s", GetAccName(i), \
// 			(IsPlayerWearAcc(playerid, i)) ? ("{63BD4E}�����") : ("{FFFF00}����"), \
// 			IsAccBanned(playerid, id) ? ("{FF0000}������������") : ("�� ������������"));
// 			strcat(string, tmp);
// 		} else continue;
// 	}
// 	if(!strlen(string)) string = "{FFFFFF}� ������ ��� �����������.";
// 	ShowPlayerDialog(playerid, ACCESLIST, \
// 	(PI[playerid][pAdmin] > 6) ? DIALOG_STYLE_LIST : DIALOG_STYLE_INPUT, \
// 	GetName(id), string, "�����", "�������");
// 	return 1;
// }
