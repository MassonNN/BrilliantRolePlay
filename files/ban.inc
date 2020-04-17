// ������� ���������� ��������

new const BAN_REASON = 1010;
new ban_string[1000];

new const ban_reason[8][54] = {
	"����, ���������� � ������������",
	"����, ���������� � ������ ��� ��������",
	"����, ���������� � ���������� �����",
	"����, ���������� � �������� ��� ��������� �����",
	"����, ���������� � ��������� ��������� � ����������",
	"����, �������� ��� �������� ������ �������",
	"����, �������� �������",
	"���, ������������� ��������"
};

new const engl_ban_reason[8][54] = {

	"Cheats that help you move around",
	"Cheats that help you fly or swim",
	"Cheats, aiding in the preservation of life",
	"Cheats that help in killing or dealing damage",
	"Cheats that help you get values and achievements",
	"Cheats that interfere with or harm other players",
	"Cheats that harm the server",
	"Bot, automation of actions"
};

new const ban_desc[8][256] = {
	"����� �����, ���������� � ������������ �� ����� ������ ��� �������� �����������.\n\
	� ����� ����� ��������� speedhack, auto bunny hop, travellev, ������������ � ������.",
	"����� �����, ���������� � ������ ��� ��������, � ����� �� ��������� Fly, AirBreak. ���������: ����������� ��������,\n\
	������� ������ � ���� ��� � �������, ���������� ����� ��� ������/��������� ���������� ����� �� ������/��������",
	"����� �����, ���������� � ���������� �����. ��������: �������, godmode, �����, ���������� ����� � ��� �����.",
	"����� �����, ���������� � �������� ��� ��������� �����. � ����� ���������, ��� ���, ��������� ������ � ������������,\n\
	��� � ��������� ������ � ����������� (��������: �������). ����� ������ �������� � ��� �����, �� ��������� � ����� ������.",
	"����� �����, ���������� � ��������� ������� ��������� � ����������. ����, ���������� � ��������� �����\n\
	�������, ������� � ������ ���� ��������� � ���������� � ����. � ����� ������ �� ��������� ����.",
	"����� �����, �������� ��� �������� ������ ������� ��� ������ �������������. ��� ������������ �����, ��� � ������, ��� �\n\
	������ � ����� ��������.",
	"����� �����, �������� �������. ��������, ������������� ����������� ����, �������� ����, ��� ����, ����� ��������� �������.",
	"����, ��������� ������������� ��������. ������������� �����-���� ��������, ���������� ������� ��������, �������� ��������� ���������\n\
	� ��� �����."
};

new const ban_time[8][19] = {
	"��������",
	"�� ���������� ����",
	"�� ���������� ����",
	"�� ���������� ����",
	"��������",
	"��������",
	"��������",
	"��������"
};

enum cheat_Info {
	Enable_MoveCheats,
	Enable_TransportCheats,
	Enable_LivingCheats,
	Enable_KillingCheats,
	Enable_AchievCheats,
	Enable_HarmPlayerCheats,
	Enable_HarmServerCheats,
	Enable_Bot
};

enum cheat_Player {
	suspicion,				// ���������������� ������
	cheatReport[10],		// ������ ������ �� ������� ������
	cheatReportReason[10], 	// ������� ������
	preason					// �������� ������� ����������
};

new cheatPlayer[MAX_PLAYERS][cheat_Player];

stock OpenOptions(playerid) {

	return 1;
}



SEC_GetPlayerStatus(playerid) {
	new toreturn[28];
	if(cheatPlayer[playerid][suspicion] < 10) toreturn = "���";
	if(10 < cheatPlayer[playerid][suspicion] < 20) toreturn = "������� ����������";
	if(20 < cheatPlayer[playerid][suspicion] < 30) toreturn = "������� �������� ����������";
	if(30 < cheatPlayer[playerid][suspicion] < 40) toreturn = "�������������";
	else toreturn = "����� �������������";
	return toreturn;
}


cmd:cheatreport(playerid, params[]) return callcmd::crep(playerid, params);
cmd:crep(playerid, params[]) {
	if(PI[playerid][pAdmin] < 3) {
		if(sscanf(params, "d", params[0])) return SendErr(playerid, "�������������: /cheatreport(/crep) [id]");
		if(!IsPlayerConnected(params[0]) || params[0] == INVALID_PLAYER_ID || params[0] == playerid) return SendErr(playerid, "�������� ID");

		new str[128];
		new ban_str[60*8], ban_string2[60];

		for(new i, j = sizeof(ban_reason); i < j; i++) {
			format(ban_string2, 128, "%s\n", ban_reason[i]);
			strcat(ban_str, ban_string2);
		}

		format(str, 128, "{FFFFFF}������ �� ������ {FFCC00}%s {FFFFFF}\t|\t�������� �������", GetName(params[0]));
		Dialog_Open(playerid, "cheatReport", DIALOG_STYLE_LIST, str, ban_str, "�����", "������");
		SetPVarInt(playerid, "cRepID", params[0]);
	} else {
		if(sscanf(params, "dD(-1)", params[0], params[1])) return SendErr(playerid, "/crep [id, ��� ����� ������] (id, �� ����)");
		else if(params[1] == -1) {

			new 
				reports_str[128*10],
				report_str[128];

			for(new i; i < 10; i++) {
				if(!cheatPlayer[params[0]][cheatReport][i]) {
					strcat(reports_str, "{FFFFFF}�����\n");
				}
				else {
					format(report_str, 128, "{FFCC00}\t%s[%d] \t|\t %s\n", \
					GetName(cheatPlayer[params[0]][cheatReport][i]), ban_reason[cheatPlayer[params[0]][cheatReportReason][i]]);
					strcat(reports_str, report_str);
				}
			}
			new str[64];
			SetPVarInt(playerid, "cheatReportsCheckID", params[0]);

			format(str, 64, "{FFFFFF}������ ������ %s", GetName(params[0]));
			Dialog_Open(playerid, "cheatReports", DIALOG_STYLE_LIST, str, reports_str, "�����", "�������");
			return 1;

		} else {
			
			for(new i; i < 10; i++) {
				if(cheatPlayer[params[0]][cheatReport][i] != params[1]) continue;
				else {
					new dialogstr[512];
					format(dialogstr, 512, \
					"\\c{FFFFFF}������ ������ %s\n\n\n\n\
					�������������: {FFCC00}%s [%d]{FFFFFF}\n\
					������������� �: {FFCC00}%s{FFFFFF}\n\
					��������� �������: {FFCC00}%s",\
					GetName(params[0]), GetName(params[1]), params[1], ban_reason[ cheatPlayer[params[0]][cheatReportReason][i] ],\
					SEC_GetPlayerStatus(params[1]));

					Dialog_Open(playerid, "cheatReportsCheck", DIALOG_STYLE_MSGBOX, "{FFFFFF}�������� ������", dialogstr, "�������", "");
					SetPVarInt(playerid, "cheatReportsCheckID", params[0]);
					SetPVarInt(playerid, "cheatReportsCheckItem", i);

					return 1;
				}
			}

		}
	}
	
	return 1;
}

DialogResponse:cheatReports(playerid, response, listitem) {
	if(!response) return 1;
	
	new idx = GetPVarInt(playerid, "cheatReportsCheckID");

	if(!IsPlayerConnected(cheatPlayer[idx][cheatReport][listitem])) return 1;

	new dialogstr[512];
	
	format(dialogstr, 512, "{FFFFFF}�����: {FFCC00}%s[%d]{FFFFFF}\n\
	������������� ������ ������� � �������������: {FFCC00}%s{FFFFFF}\n\
	��������� �������: {FFCC00}%s", \
	GetName(cheatPlayer[idx][cheatReport][listitem]), cheatPlayer[idx][cheatReport][listitem],\
	ban_reason[cheatPlayer[idx][cheatReportReason][listitem]], SEC_GetPlayerStatus(cheatPlayer[idx][cheatReport][listitem]));
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{FFFFFF}������ ������", dialogstr, "�������", "");
	return 1;
}

DialogResponse:cheatReportsCheck(playerid, response, listitem) {
	if(!response) return 1;
	new dialogstr[256];
	new dialogname[50];
	new idx = GetPVarInt(playerid, "cheatReportsCheckID");
	new ltm = GetPVarInt(playerid, "cheatReportsCheckItem");

	format(dialogname, 128, "{FFFFFF}������ ������ %s �� %s", GetName(idx), GetName(cheatPlayer[idx][cheatReport][ltm]));
	format(dialogstr, 256, "{FFFFFF}�����: {FFCC00}%s[%d]{FFFFFF}\n\
	������������� ������ ������� � �������������: {FFCC00}%s{FFFFFF}\n\
	��������� �������: {FFCC00}%s", \
	GetName(idx), GetName(cheatPlayer[idx][cheatReport][ltm]), GetName(cheatPlayer[idx][cheatReport][ltm]), cheatPlayer[idx][cheatReport][ltm],\
	ban_reason[cheatPlayer[idx][cheatReportReason][ltm]], SEC_GetPlayerStatus(cheatPlayer[idx][cheatReport][ltm]));
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, dialogname, dialogstr, "�������", "");
	return 1;
}


DialogResponse:cheatReport(playerid, response, listitem) {
	if(!response) return 1;
	else {
		new idx = GetPVarInt(playerid, "ban_id");
		format(ban_string, 1000, \
		"\\c{FFCC00}"SERVER_NAME" Security\n\
		\n\n\
		\\c{ffffff}���������� � ������������� �����.\n\n\
		����� %s[%d] ���������� ����������� ���� ������: %s. \n\
		��������� ���� �������� ������� %s, � ��� �������� ��� ��������� ��������:\n\
		\\c{FFCC00}'%s'.\n\
		\n\n\n\n\n\n\
		{ffffff}������� {ffcc00}'�����������'{ffffff}, ���� ��� ���������� ���� �����, ������� {ffcc00}'���������'{ffffff}, ���� ���������� �����������.",\
		GetName(idx), idx,\
		ban_reason[listitem],\
		GetName(playerid),\
		ban_desc[listitem],\
		SetPVarInt(playerid, "crep_reas", listitem));
		Dialog_Open(playerid, "cheatReportAccept", DIALOG_STYLE_MSGBOX, "����������� ����������", ban_string, "{FF0000}�����������", "{FF0000}���������");
	}
	return 1;
}

DialogResponse:cheatReportAccept(playerid, response, listitem) {
	if(!response) return SendInfo(playerid, "������� �� ������������");
	else {

		new idx = GetPVarInt(playerid, "cRepID");

		// �������� ��������
		for(new i; i < 10; i++) {
			if(i == 9 && cheatPlayer[playerid][cheatReport][i]) cheatPlayer[playerid][cheatReport][0] = idx; 
			if(cheatPlayer[playerid][cheatReport][i]) continue;
			else cheatPlayer[playerid][cheatReport][i] = idx;
		}
		
		

		new adminsnum;
		foreach(new i : Player) {
			if(PI[i][pAdmin] < 3) continue;
			else adminsnum++;
		}

		if(!adminsnum) SendSucces(playerid, "���� ������ ����� ���������� ��������");
		else {

			new str[128];
			format(str, 128, "{FF0000}[CHEAT REPORT]{FFCC00} ����� %s �������� ������ �� ������ %s[%d]. ���������: /crep %d %d",\
			GetName(playerid), GetName(idx), idx, playerid, idx);
			SendAdminMessage(-1, str, 3);

			SendSucces(playerid, "���� ������ ����� ����������� �������������� ��� ���������� ��������");
		}
	}
	return 1;
}

cmd:cban(playerid, params[]) {
	if(CheckAdmin(playerid, 1)) return 1;
	new id;
	if(sscanf(params, "d", id)) return SendErr(playerid, "�������������: /cban [id ������]");
	if(id == playerid) return SendErr(playerid, "�� �� ������ ������������� ���� �� ������������� �����");
	if(PI[id][pAdmin] && PI[playerid][pAdmin] < 7) return SendErr(playerid, "����� �������������!");
	new ban_str[60*8], ban_string2[60];

	for(new i, j = sizeof(ban_reason); i < j; i++) {
		format(ban_string2, 128, "%s\n", ban_reason[i]);
		strcat(ban_str, ban_string2);
	}

	ShowPlayerDialog(playerid, BAN_REASON, DIALOG_STYLE_LIST, "�������� �������", ban_str, "����������", "������");
	SetPVarInt(playerid, "ban_id", id);
	return 1;
}


public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{

	if(dialogid == BAN_REASON) {
		if(!response) return 1;
		new idx = GetPVarInt(playerid, "ban_id");

		format(ban_string, 1000, \
		"\t\t\t\t{FFCC00}"SERVER_NAME" Security\n\
		\n\n\
		\t\t\t\t{ffffff}���������� � ������������� �����.\n\n\
		����� %s[%d] ���������� ����������� ���� ������: %s. \n\
		��������� ���� �������� �������������� �������, � ��� �������� ��� ��������� ��������:\n\
		'%s'.\n\
		������������� %s {ffcc00}��������� ������ � ���, ��� ����� ������������� ���������� ���� � �������� ����������� ���,{ffffff}�������� ����������� ��������������.\
		\n\n\n\n\n\n\
		������� {ffcc00}'�����������'{ffffff}, ���� ��� ���������� ���� �����, ������� {ffcc00}'���������'{ffffff}, ���� ���������� �����������.",\
		GetName(idx), idx,\
		ban_reason[listitem],\
		ban_desc[listitem],\
		GetName(playerid));
		SetPVarInt(playerid, "ban_reas", listitem);
		ShowPlayerDialog(playerid, BAN_REASON+1, DIALOG_STYLE_MSGBOX, "����������� ����������", ban_string, "{FF0000}�����������", "{FF0000}���������");
	} else if(dialogid == BAN_REASON+1) {
		if(!response) {
			SendClientMessage(playerid, -1, "������� �� ������������. ���������� �������� ���������.");
			return 1;
		} else {

			new idx = GetPVarInt(playerid, "ban_id");
			new sreason = GetPVarInt(playerid, "ban_reas");
			if(PI[playerid][pAdmin] < 3) {
				SendSucces(playerid, "������� �� ���������� ����������. ������� �������� ������� ������!");
				// �������� ��������
				
			} else {
			
				format(ban_string, 1000, \
				"� ���������, ��� ������� ��� ������������. �� �������� �� ����.\n\n\n\
				�� ���� ������� � ��������� ����, ��������� � ������������� ���������� ������ �����: \n\
				'%s'.\n\
				��� ������� ������������ {ffcc00}%s{ffffff}, ���� �� �� �������� � �������� ��� ���������� ����������\n\
				�� ��� ����������� ����� ��� ���� � ��������� ��������� ����������:\n\
				[%d/%d/%d] ���������� �������� {ffcc00}%s{ffffff}.", ban_reason[sreason], ban_time[sreason],\
				gDay, gMonth, gYear, ban_time[sreason]);

				ShowPlayerDialog(idx, D_NULL, DIALOG_STYLE_MSGBOX, "������� ������������ "SERVER_NAME"", ban_string, "/q", "");
				new data[15];
				format(data, sizeof(data), "%02d.%02d.%04d", gDay, gMonth, gYear);
				format(query, sizeof(query), "INSERT INTO CheatBan (Name, IP, BanReason, BanDate, AdminName) VALUES ('%s', '%s', '%d', '%s', '%s')", GetName(idx), PI[idx][pIP], sreason, data, GetName(playerid));
				mysql_tquery(dbHandle, query, "", "");
				
				format(ban_string, 128, "[ADMIN] ����� %s ��� ������������ ��������������� %s �� �������������: %s", GetName(idx), GetName(playerid), ban_reason[sreason]);
				SendAdminMessage(COLOR_GREY, ban_string);
				KickPlayer(idx);
			}
			new str[128];
			format(str, 128, "Player %s was caught in foul play by %s and banned permanently", GetName(idx), engl_ban_reason[sreason]);
			D_Message(p_Admins, str);
		}
	}

    #if defined ban_OnDialogResponse
        return ban_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnDialogResponse
    #undef OnDialogResponse
#else
    #define _ALS_OnDialogResponse
#endif
#define OnDialogResponse ban_OnDialogResponse
#if defined ban_OnDialogResponse
    forward ban_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif 