enum ADMIN_PickupInfo {

	Float:pickup_x,
	Float:pickup_y,
	Float:pickup_z,
	Pickupid,
	World,
	Interior,
	NicknameADM,
	Text3D:PickupText,
	Action[32]

};

new ADMIN_CreatedPickups[MAX_PLAYERS];

stock GetCreatedAdminPickups(playerid) {
	return ADMIN_CreatedPickups[playerid];
}


#define MAX_ADMIN_PICKUP 20

new ADMIN_PrePickup[MAX_PLAYERS][MAX_ADMIN_PICKUP][ADMIN_PickupInfo];


cmd:createpickup(playerid,params[]) {

	if(!CheckAdmin(playerid, 5)) return 1;
	if(GetCreatedAdminPickups(playerid) == MAX_ADMIN_PICKUP-1) return SendClientMessage(playerid, -1, "�� ������� ������������� ���������� �������.");
	sscanf(params, "dds[32]", params[0], params[1], params[2]);
	// createpickup [���=19] [model=1559] [�����]

	if(!params[0]) params[0] = 19;
	if(!params[1]) params[1] = 1559;
	
	ADMIN_CreatedPickups[playerid]++;
	new playerWorld = GetPlayerVirtualWorld(playerid);
	new playerInterior = GetPlayerInterior(playerid);
	
	GetPlayerPos(playerid,\
	ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][pickup_x],\
	ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][pickup_y],\
	ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][pickup_z]);

	ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][Pickupid] = CreateDynamicPickup(params[1], params[0],\
	ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][pickup_x],\
	ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][pickup_y],\
	ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][pickup_z],\
	playerWorld, \
	playerInterior);

	if(strlen(params[2]) <= 0) {
		new st[28];
		format(st, sizeof st, "������� ��������������\nID:%d", playerid);
		ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][PickupText] = CreateDynamic3DTextLabel(st,\
		-1,\
		ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][pickup_x],\
		ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][pickup_y], \
		ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][pickup_z]+1.0, 10);
	}
	else {
		ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][PickupText] = CreateDynamic3DTextLabel(params[2],\
		-1,\
		ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][pickup_x],\
		ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][pickup_y], \
		ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][pickup_z]+1.0, 10);
	}

	ADMIN_PrePickup[playerid][GetCreatedAdminPickups(playerid)][NicknameADM] = GetName(playerid);


	new str[128];
	format(str, sizeof(str), "�� ������� �����: %d/19", GetCreatedAdminPickups(playerid));
	SendClientMessage(playerid, -1, str);
	SendClientMessage(playerid, -1, "������ � ��������: /deletepick /editpick");
	return 1;
}


cmd:deletepick(playerid, params[]) {

	if(!CheckAdmin(playerid, 5)) return 1;
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, -1, "�����������: /deletepick [id]");
	DestroyDynamicPickup(ADMIN_PrePickup[playerid][params[0]][Pickupid]);
	DestroyDynamic3DTextLabel(ADMIN_PrePickup[playerid][params[0]][PickupText]);
	ADMIN_CreatedPickups[playerid]--;
	new str[128];
	format(str, sizeof(str), "�� ������� ����� ����� %d", params[0]);
	return SendClientMessage(playerid, -1, str);
}

cmd:exportinfopick(playerid) {
	if(!CheckAdmin(playerid, 7)) return 1;
	new export[512], string[128];
	for(new i, j = GetCreatedAdminPickups(playerid); i <= j; i++) {
		format(string, sizeof (string), "ID: %d || X: %0.0f || Y: %0.0f || Z: %0.0f \n",\
		ADMIN_PrePickup[playerid][i][Pickupid],\
		ADMIN_PrePickup[playerid][i][pickup_x],\
		ADMIN_PrePickup[playerid][i][pickup_y],\
		ADMIN_PrePickup[playerid][i][pickup_z]);
		strcat(export, string);
	}
	return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "������� ����������", export, "�������", "");
}

/*
// #define PICK_DIALOG_EDIT	5101

// cmd:editpick(playerid, params[]) {

// 	if(!CheckAdmin(playerid, 5)) return 1;
// 	else if(CheckAdmin(playerid, 5)) {

// 		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, -1, "�����������: /editpick [id]");
// 		new str[256];
// 		format(str, sizeof(str), 
// 		"����� ID: %d\n
// 		X: %0.0f \n
// 		Y: %0.0f \n
// 		Z: %0.0f \n
// 		��������: %s \n
// 		������� �� ����������, ����� �������������",
// 		ADMIN_PrePickup[playerid][params[0]][Pickupid],
// 		ADMIN_PrePickup[playerid][params[0]][x],
// 		ADMIN_PrePickup[playerid][params[0]][y],
// 		ADMIN_PrePickup[playerid][params[0]][z]);

// 		SetPVarInt(playerid, "PICK_CHANGE_ID", params[0]);

// 		ShowPlayerDialog(playerid, PICK_DIALOG_EDIT, DIALOG_STYLE_LIST, "�������� �����", str, "�����", "������");
// 	}
// 	else if(CheckAdmin(playerid, 7)) {

// 		sscanf(params, "dd", params[0], params[1]);
// 		if(!params[0]) return SendClientMessage(playerid, "���������: /editpick [id pick] [id ������]");
// 		if(params[1] == INVALID_PLAYER_ID) {

// 			new str[256];
// 			format(str, sizeof(str), 
// 			"����� ID: %d\n
// 			X: %0.0f \n
// 			Y: %0.0f \n
// 			Z: %0.0f \n
// 			��������: %s \n
// 			������� �� ����������, ����� �������������\n
// 			������ �����: %s",
// 			ADMIN_PrePickup[playerid][params[0]][Pickupid],
// 			ADMIN_PrePickup[playerid][params[0]][x],
// 			ADMIN_PrePickup[playerid][params[0]][y],
// 			ADMIN_PrePickup[playerid][params[0]][z],
// 			GetName(playerid));

// 			SetPVarInt(playerid, "PICK_CHANGE_ID", params[0]);
// 		}
// 		else {

// 			new str[256];
// 			format(str, sizeof(str), 
// 			"����� ID: %d\n
// 			X: %0.0f \n
// 			Y: %0.0f \n
// 			Z: %0.0f \n
// 			��������: %s \n
// 			������� �� ����������, ����� �������������\n
// 			������ �����: %s",
// 			ADMIN_PrePickup[params[1]][params[0]][Pickupid],
// 			ADMIN_PrePickup[params[1]][params[0]][x],
// 			ADMIN_PrePickup[params[1]][params[0]][y],
// 			ADMIN_PrePickup[params[1]][params[0]][z],
// 			GetName(params[1]));	

// 			SetPVarInt(playerid, "PICK_CHANGE_ID", params[0]);

// 		}
// 		ShowPlayerDialog(playerid, PICK_DIALOG_EDIT, DIALOG_STYLE_LIST, "�������� �����", str, "�����", "������");

// 	}
// 	else return 1;


// }


// public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
// {
// 	if(dialogid == PICK_DIALOG_EDIT) {
// 		if(!response) return 1;
// 		new str[128];
// 		else switch(listitem) {

// 			case 1: {
// 				SetPVarInt(playerid, "PICK_EDIT_PICKUP", 1);
// 				ShowPlayerDialog(playerid, PICK_DIALOG_EDIT2, DIALOG_STYLE_INPUT, "���������", "������� ����� �������� ��� X ���������� ������", "�����", "������");
// 			}
// 			case 2: {
// 				SetPVarInt(playerid, "PICK_EDIT_PICKUP", 2);
// 				ShowPlayerDialog(playerid, PICK_DIALOG_EDIT2, DIALOG_STYLE_INPUT, "���������", "������� ����� �������� ��� Y ���������� ������", "�����", "������");
// 			}
// 			case 3: {
// 				SetPVarInt(playerid, "PICK_EDIT_PICKUP", 3);
// 				ShowPlayerDialog(playerid, PICK_DIALOG_EDIT2, DIALOG_STYLE_INPUT, "���������", "������� ����� �������� ��� Z ���������� ������", "�����", "������");
// 			}
// 			case 4: SendClientMessage(playerid, -1, "�������� �� ��������");
// 		}
// 	}
// 	else if(dialogid == PICK_DIALOG_EDIT2) {
// 		if(!response) return 1;
// 		switch(GetPVarInt(playerid, "PICK_EDIT_PICKUP")) {

// 			case 0: return 1;
// 			case 1: {
// 				if(!strlen(inputtext)) SendClientMessage(playerid, -1, "������� ��������!");
// 				ADMIN_PrePickup[playerid][GetPVarInt(playerid, "PICK_CHANGE_ID")][x] = floatstr(inputtext);
// 				new str[128];
// 				format(str, 128, "���������� X ������ %d �������� �� %0.0f", GetPVarInt(playerid, "PICK_CHANGE_ID"), 
// 				ADMIN_PrePickup[playerid][GetPVarInt(playerid, "PICK_CHANGE_ID")][x]);
// 				SendClientMessage(playerid, -1, str);
// 			} 
// 			case 2: {
// 				if(!strlen(inputtext)) SendClientMessage(playerid, -1, "������� ��������!");
// 				ADMIN_PrePickup[playerid][GetPVarInt(playerid, "PICK_CHANGE_ID")][y] = floatstr(inputtext);
// 				new str[128];
// 				format(str, 128, "���������� Y ������ %d �������� �� %0.0f", GetPVarInt(playerid, "PICK_CHANGE_ID"), 
// 				ADMIN_PrePickup[playerid][GetPVarInt(playerid, "PICK_CHANGE_ID")][y]);
// 				SendClientMessage(playerid, -1, str);
// 			}
// 			case 3: {
// 				if(!strlen(inputtext)) SendClientMessage(playerid, -1, "������� ��������!");
// 				ADMIN_PrePickup[playerid][GetPVarInt(playerid, "PICK_CHANGE_ID")][z] = floatstr(inputtext);
// 				new str[128];
// 				format(str, 128, "���������� Z ������ %d �������� �� %0.0f", GetPVarInt(playerid, "PICK_CHANGE_ID"), 
// 				ADMIN_PrePickup[playerid][GetPVarInt(playerid, "PICK_CHANGE_ID")][z]);
// 				SendClientMessage(playerid, -1, str);
// 			}


// 		}



// 	}
// #if	defined	dynpick_OnDialogResponse
// 	dynpick_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
// #endif
// }
// #if defined _ALS_OnDialogResponse
// 	#undef	OnDialogResponse
// #else
// 	#define	_ALS_OnDialogResponse
// #endif
// #if	defined	dynpick_OnDialogResponse
// forward dynpick_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
// #endif
// #define	OnDialogResponse	dynpick_OnDialogResponse
*/