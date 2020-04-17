// система блокировки аккаунта

new const BAN_REASON = 1010;
new ban_string[1000];

new const ban_reason[8][54] = {
	"Читы, помогающие в передвижении",
	"Читы, помогающие в полете или плавании",
	"Читы, помогающие в сохранении жизни",
	"Читы, помогающие в убийстве или нанесении урона",
	"Читы, помогающие в получении ценностей и достижений",
	"Читы, мещающие или вредящие другим игрокам",
	"Читы, вредящие серверу",
	"Бот, автоматизация действий"
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
	"Класс читов, помогающие в передвижении по земле пешком или наземным транспортом.\n\
	К таким могут относится speedhack, auto bunny hop, travellev, телепортация и другие.",
	"Класс читов, помогающие в полете или плавании, к таким НЕ относится Fly, AirBreak. Относятся: бесконечный кислород,\n\
	быстрый подъем в воде или в воздухе, отсутствие урона или полное/частичное отсутствие урона от полета/плавания",
	"Класс читов, помогающих в сохранении жизни. Например: лечение, godmode, броня, отсутствие урона и так далее.",
	"Класс читов, помогающих в убийстве или нанесении урона. К таким относятся, как аим, различная помощь в прицеливании,\n\
	так и различная помощь в перестрелке (например: стрейфы). Софты сбития анимаций и так далее, НЕ относятся к этому классу.",
	"Класс читов, помогающих в получении игровых ценностей и достижений. Софт, помогающий в получении денег\n\
	скиллов, навыков и вообще всех ценностей и достижений в игре. К этому классу НЕ относятся боты.",
	"Класс читов, мешающих или вредящих другим игрокам или работе администрации. Как обыкновенные краши, так и рванка, так и\n\
	взрывы и всему подобное.",
	"Класс читов, вредящих серверу. Например, использование уязвимостей игры, игрового мода, для того, чтобы навредить серверу.",
	"Боты, различная автоматизация действий. Использование каких-либо скриптов, помогающих сбивать анимации, изменять состояние персонажа\n\
	и так далее."
};

new const ban_time[8][19] = {
	"навсегда",
	"до следующего года",
	"до следующего года",
	"до следующего года",
	"навсегда",
	"навсегда",
	"навсегда",
	"навсегда"
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
	suspicion,				// подозрительность игрока
	cheatReport[10],		// жалобы игрока на другого игрока
	cheatReportReason[10], 	// причина жалобы
	preason					// основная причина подозрения
};

new cheatPlayer[MAX_PLAYERS][cheat_Player];

stock OpenOptions(playerid) {

	return 1;
}



SEC_GetPlayerStatus(playerid) {
	new toreturn[28];
	if(cheatPlayer[playerid][suspicion] < 10) toreturn = "Нет";
	if(10 < cheatPlayer[playerid][suspicion] < 20) toreturn = "Ведется наблюдение";
	if(20 < cheatPlayer[playerid][suspicion] < 30) toreturn = "Ведется активное наблюдение";
	if(30 < cheatPlayer[playerid][suspicion] < 40) toreturn = "Подозревается";
	else toreturn = "Особо подозревается";
	return toreturn;
}


cmd:cheatreport(playerid, params[]) return callcmd::crep(playerid, params);
cmd:crep(playerid, params[]) {
	if(PI[playerid][pAdmin] < 3) {
		if(sscanf(params, "d", params[0])) return SendErr(playerid, "Использование: /cheatreport(/crep) [id]");
		if(!IsPlayerConnected(params[0]) || params[0] == INVALID_PLAYER_ID || params[0] == playerid) return SendErr(playerid, "Неверный ID");

		new str[128];
		new ban_str[60*8], ban_string2[60];

		for(new i, j = sizeof(ban_reason); i < j; i++) {
			format(ban_string2, 128, "%s\n", ban_reason[i]);
			strcat(ban_str, ban_string2);
		}

		format(str, 128, "{FFFFFF}Жалоба на игрока {FFCC00}%s {FFFFFF}\t|\tВыберите причину", GetName(params[0]));
		Dialog_Open(playerid, "cheatReport", DIALOG_STYLE_LIST, str, ban_str, "Далее", "Отмена");
		SetPVarInt(playerid, "cRepID", params[0]);
	} else {
		if(sscanf(params, "dD(-1)", params[0], params[1])) return SendErr(playerid, "/crep [id, кто подал жалобу] (id, на кого)");
		else if(params[1] == -1) {

			new 
				reports_str[128*10],
				report_str[128];

			for(new i; i < 10; i++) {
				if(!cheatPlayer[params[0]][cheatReport][i]) {
					strcat(reports_str, "{FFFFFF}Пусто\n");
				}
				else {
					format(report_str, 128, "{FFCC00}\t%s[%d] \t|\t %s\n", \
					GetName(cheatPlayer[params[0]][cheatReport][i]), ban_reason[cheatPlayer[params[0]][cheatReportReason][i]]);
					strcat(reports_str, report_str);
				}
			}
			new str[64];
			SetPVarInt(playerid, "cheatReportsCheckID", params[0]);

			format(str, 64, "{FFFFFF}Жалобы игрока %s", GetName(params[0]));
			Dialog_Open(playerid, "cheatReports", DIALOG_STYLE_LIST, str, reports_str, "Далее", "Закрыть");
			return 1;

		} else {
			
			for(new i; i < 10; i++) {
				if(cheatPlayer[params[0]][cheatReport][i] != params[1]) continue;
				else {
					new dialogstr[512];
					format(dialogstr, 512, \
					"\\c{FFFFFF}Жалоба игрока %s\n\n\n\n\
					Подозреваемый: {FFCC00}%s [%d]{FFFFFF}\n\
					Подозревается в: {FFCC00}%s{FFFFFF}\n\
					Состояние системы: {FFCC00}%s",\
					GetName(params[0]), GetName(params[1]), params[1], ban_reason[ cheatPlayer[params[0]][cheatReportReason][i] ],\
					SEC_GetPlayerStatus(params[1]));

					Dialog_Open(playerid, "cheatReportsCheck", DIALOG_STYLE_MSGBOX, "{FFFFFF}Проверка жалобы", dialogstr, "Закрыть", "");
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
	
	format(dialogstr, 512, "{FFFFFF}Игрок: {FFCC00}%s[%d]{FFFFFF}\n\
	Подозревается другим игроком в использовании: {FFCC00}%s{FFFFFF}\n\
	Состояние системы: {FFCC00}%s", \
	GetName(cheatPlayer[idx][cheatReport][listitem]), cheatPlayer[idx][cheatReport][listitem],\
	ban_reason[cheatPlayer[idx][cheatReportReason][listitem]], SEC_GetPlayerStatus(cheatPlayer[idx][cheatReport][listitem]));
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{FFFFFF}Жалоба игрока", dialogstr, "Закрыть", "");
	return 1;
}

DialogResponse:cheatReportsCheck(playerid, response, listitem) {
	if(!response) return 1;
	new dialogstr[256];
	new dialogname[50];
	new idx = GetPVarInt(playerid, "cheatReportsCheckID");
	new ltm = GetPVarInt(playerid, "cheatReportsCheckItem");

	format(dialogname, 128, "{FFFFFF}Жалоба игрока %s на %s", GetName(idx), GetName(cheatPlayer[idx][cheatReport][ltm]));
	format(dialogstr, 256, "{FFFFFF}Игрок: {FFCC00}%s[%d]{FFFFFF}\n\
	Подозревается другим игроком в использовании: {FFCC00}%s{FFFFFF}\n\
	Состояние системы: {FFCC00}%s", \
	GetName(idx), GetName(cheatPlayer[idx][cheatReport][ltm]), GetName(cheatPlayer[idx][cheatReport][ltm]), cheatPlayer[idx][cheatReport][ltm],\
	ban_reason[cheatPlayer[idx][cheatReportReason][ltm]], SEC_GetPlayerStatus(cheatPlayer[idx][cheatReport][ltm]));
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, dialogname, dialogstr, "Закрыть", "");
	return 1;
}


DialogResponse:cheatReport(playerid, response, listitem) {
	if(!response) return 1;
	else {
		new idx = GetPVarInt(playerid, "ban_id");
		format(ban_string, 1000, \
		"\\c{FFCC00}"SERVER_NAME" Security\n\
		\n\n\
		\\c{ffffff}Подозрение в использовании читов.\n\n\
		Игрок %s[%d] использует посторонний софт класса: %s. \n\
		Нарушение было замечено игроком %s, и оно попадает под следующее описание:\n\
		\\c{FFCC00}'%s'.\n\
		\n\n\n\n\n\n\
		{ffffff}Нажмите {ffcc00}'подтвердить'{ffffff}, если вся информация выше верна, нажмите {ffcc00}'отклонить'{ffffff}, если информация некорректна.",\
		GetName(idx), idx,\
		ban_reason[listitem],\
		GetName(playerid),\
		ban_desc[listitem],\
		SetPVarInt(playerid, "crep_reas", listitem));
		Dialog_Open(playerid, "cheatReportAccept", DIALOG_STYLE_MSGBOX, "Подтвердите информацию", ban_string, "{FF0000}Подтвердить", "{FF0000}Отклонить");
	}
	return 1;
}

DialogResponse:cheatReportAccept(playerid, response, listitem) {
	if(!response) return SendInfo(playerid, "Спасибо за бдительность");
	else {

		new idx = GetPVarInt(playerid, "cRepID");

		// добавить проверку
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

		if(!adminsnum) SendSucces(playerid, "Ваша жалоба будет обработана системой");
		else {

			new str[128];
			format(str, 128, "{FF0000}[CHEAT REPORT]{FFCC00} Игрок %s отправил жалобу на игрока %s[%d]. Подробнее: /crep %d %d",\
			GetName(playerid), GetName(idx), idx, playerid, idx);
			SendAdminMessage(-1, str, 3);

			SendSucces(playerid, "Ваша жалоба будет рассмотрена администрацией или обработана системой");
		}
	}
	return 1;
}

cmd:cban(playerid, params[]) {
	if(CheckAdmin(playerid, 1)) return 1;
	new id;
	if(sscanf(params, "d", id)) return SendErr(playerid, "Использование: /cban [id игрока]");
	if(!IsPlayerConnected(id) || id = INVALID_PLAYER_ID) return SendErr(playerid, "Такого игрока нет");
	if(id == playerid) return SendErr(playerid, "Вы не можете заблокировать себя за использование читов");
	if(PI[id][pAdmin] && PI[playerid][pAdmin] < 7) return SendErr(playerid, "Игрок администратор!");

	new ban_str[60*8], ban_string2[60];

	for(new i, j = sizeof(ban_reason); i < j; i++) {
		format(ban_string2, 128, "%s\n", ban_reason[i]);
		strcat(ban_str, ban_string2);
	}

	ShowPlayerDialog(playerid, BAN_REASON, DIALOG_STYLE_LIST, "Выберите причину", ban_str, "Продолжить", "Отмена");
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
		\t\t\t\t{ffffff}Подозрение в использовании читов.\n\n\
		Игрок %s[%d] использует посторонний софт класса: %s. \n\
		Нарушение было замечено администрацией сервера, и оно попадает под следующее описание:\n\
		'%s'.\n\
		Администратор %s {ffcc00}полностью уверен в том, что игрок действительно использует софт и способен подтвердить это,{ffffff}приложив необходимые доказательства.\
		\n\n\n\n\n\n\
		Нажмите {ffcc00}'подтвердить'{ffffff}, если вся информация выше верна, нажмите {ffcc00}'отклонить'{ffffff}, если информация некорректна.",\
		GetName(idx), idx,\
		ban_reason[listitem],\
		ban_desc[listitem],\
		GetName(playerid));
		SetPVarInt(playerid, "ban_reas", listitem);
		ShowPlayerDialog(playerid, BAN_REASON+1, DIALOG_STYLE_MSGBOX, "Подтвердите информацию", ban_string, "{FF0000}Подтвердить", "{FF0000}Отклонить");
	} else if(dialogid == BAN_REASON+1) {
		if(!response) {
			SendClientMessage(playerid, -1, "Спасибо за бдительность. Блокировка аккаунта отклонена.");
			return 1;
		} else {

			new idx = GetPVarInt(playerid, "ban_id");
			new sreason = GetPVarInt(playerid, "ban_reas");
			if(PI[playerid][pAdmin] < 3) {
				SendSucces(playerid, "Спасибо за доложенную информацию. Система проверит данного игрока!");
				// добавить проверку
				
			} else {
			
				format(ban_string, 1000, \
				"К сожалению, Ваш аккаунт был заблокирован. Мы сожалеем об этом.\n\n\n\
				Вы были уличены в нечестной игре, конкретно в использовании следующего класса читов: \n\
				'%s'.\n\
				Ваш аккаунт заблокирован {ffcc00}%s{ffffff}, если Вы не согласны с выданным Вам наказанием обратитесь\n\
				на наш официальный форум или сайт и приложите следующую информацию:\n\
				[%d/%d/%d] Блокировка аккаунта {ffcc00}%s{ffffff}.", ban_reason[sreason], ban_time[sreason],\
				gDay, gMonth, gYear, ban_time[sreason]);

				ShowPlayerDialog(idx, D_NULL, DIALOG_STYLE_MSGBOX, "Аккаунт заблокирован "SERVER_NAME"", ban_string, "/q", "");
				new data[15];
				format(data, sizeof(data), "%02d.%02d.%04d", gDay, gMonth, gYear);
				format(query, sizeof(query), "INSERT INTO CheatBan (Name, IP, BanReason, BanDate, AdminName) VALUES ('%s', '%s', '%d', '%s', '%s')", GetName(idx), PI[idx][pIP], sreason, data, GetName(playerid));
				mysql_tquery(dbHandle, query, "", "");
				
				format(ban_string, 128, "[ADMIN] Игрок %s был заблокирован администратором %s за использование: %s", GetName(idx), GetName(playerid), ban_reason[sreason]);
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