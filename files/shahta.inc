
new shahtapick[2];
new STREAMER_TAG_PICKUP:tmp_shahta[MAX_PLAYERS];
new shahtaEarn[MAX_PLAYERS];
new shahtaStatus[MAX_PLAYERS];

new shahta_Bot;



hook OnGameModeInit() {
	shahta_Bot = CreateActor(202, 2571.5457,-1328.9038,9.1300,10);
	Create3DTextLabel("Прораб", -1, 2571.5457,-1328.9038,10,100.0,0,1);
	shahtapick[0] = CreateDynamicPickup(1318,23,2571.5127,-1327.8333,9.1300); // прораб
	return 1;
}

publics shahta_work(playerid) {
	SendSucces(playerid, "Отлично, теперь отнеси на переработку");
	shahtaStatus[playerid] = 1;
	ShahtaNext(playerid, 1);
	ClearAnimations(playerid);
	ClearSlots(playerid);
	SetPlayerAttachedObject(playerid,2, 905, 5, 0.020944, 0.039285, -0.035010, 0.000000, 0.000000, 0.000000, 0.301603, 0.125763, 0.233199);
    SetPlayerAttachedObject(playerid,3, 906, 6, -0.032336, 0.111448, 0.001745, 0.000000, 0.000000, 0.000000, 0.026124, 0.048238, 0.048593);
	return 1;
}

shahta_pickup(playerid, pickupid) {

	if(pickupid == tmp_shahta[playerid]) {
		if(shahtaStatus[playerid] == 0) {
			ClearAnimations(playerid);
            ApplyAnimation(playerid,"BASEBALL","Bat_4",4.1,1,0,0,1,11000);
			SetTimerEx("shahta_work", 10000, false, "d", playerid);
			return 1;
		} else if (shahtaStatus[playerid] == 1) {
			ClearSlots(playerid);
			shahtaEarn[playerid] += 250;
			SendSucces(playerid, "Вы принесли камень.");
			SendPond(playerid, "Если Вы хотите закончить подработку на шахте, то подойдите к прорабу.");
			ShahtaNext(playerid, 1);
		}
	}
	else if(pickupid == shahtapick[0])
	{
		if(PI[playerid][pShahtaWork] == false) {
			SendTimeMessage(playerid, "{FFCC00}Прораб: {FFFFFF}Привет! Если хочешь подзаработать денег, то шахта - твой вариант.", 1000, MESSAGE_TYPE);
			ApplyActorAnimation(shahta_Bot, "PED", "IDLE_CHAT", 4.1, 0, 1, 1, 0, 0);
			new dds[800];
			format(dds, 800, "\t\t\t\t{ffffff}Шахта - подработка.\n\
			\t\tЗаработай неплохие деньги, всего лишь за пару минут. Приноси камни с камневала и отправляй их на переработку.\n\
			\t\tКогда твой суммарный доход на шахте дойдет до какой-либо отметки, ты получишь одну из привилегий или подарков от прораба:\n\n\n\
			- {adff2f}10 000 рублей{ffffff} \t\tУвеличение дохода в 1,5 раза\n\
			- {adff2f}30 000 рублей{ffffff} \t\tУвеличение дохода в 2 раза\n\
			- {adff2f}50 000 рублей{ffffff} \t\tДостижение 'Шахтер' и памятный акссесуар\n\
			- {adff2f}100 000 рублей{ffffff} \t\tУвеличение дохода в 3 раза\n\
			- {adff2f}500 000 рублей{ffffff} \t\t1 000 000 рублей премиальных!\n\n\n\
			В настоящее время твой доход составляет: {ffcc00}%d{ffffff} рублей\n\n", PI[playerid][pShahtaEarn]);
			ShowPlayerDialog(playerid, SHAHTA, DIALOG_STYLE_MSGBOX, "{FFCC00}Шахта", dds, "Согласиться", "Отмена");
			return 1;
		} else {
			ApplyActorAnimation(shahta_Bot, "PED", "IDLE_CHAT", 4.1, 0, 1, 1, 0, 0);
			new dds[800];
			format(dds, 800, "{ffffff}\t\t\t\t{ffffff}Шахта - подработка.\n\
			Уже все? Ты заработал {adff2f}%d{ffffff} рублей и можешь завершить подработку.", shahtaEarn[playerid]);
			ShowPlayerDialog(playerid, SHAHTA+1, DIALOG_STYLE_MSGBOX, "{FFCC00}Шахта", dds, "Согласиться", "Отмена");
		}
	}
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {

	if(dialogid == SHAHTA) {
		if(!response) return 1;
		else {
			SetPlayerSkin(playerid, 260);
			SetPlayerAttachedObject(playerid, 1, 18634, 14, 0.333391, 0.000000, 0.042249, 358.219909, 268.014739, 170.032974, 2.003867, 1.764811, 1.579773);
			SendPond(playerid, "Приступайте к работе, идите к камневалу (появился пикап) и отломите камень.");
			PI[playerid][pShahtaWork] = true;
			ShahtaNext(playerid, 0);
			return 1;
		}
	} else if(dialogid == SHAHTA+1) {
		if(!response) return 1;
		else {
			SetPlayerSkin(playerid, PI[playerid][pModel]);
			ClearSlots(playerid);
			PI[playerid][pShahtaEarn] += shahtaEarn[playerid];
			PI[playerid][pShahtaWork] = false;
			PI[playerid][pCash] += shahtaEarn[playerid];
			GiveMoney(playerid, shahtaEarn[playerid]);
			switch(random(3)) {
				case 1: SendClientMessage(playerid, -1,"{FFCC00}Прораб:{FFFFFF} Удачи тебе");
				case 2: SendClientMessage(playerid, -1,"{FFCC00}Прораб:{FFFFFF} Буду ждать тебя снова");
				default: SendClientMessage(playerid, -1,"{FFCC00}Прораб:{FFFFFF} Деньги заработал, потратить не забудь");
			}
		}
	}

	return 1;

}


ShahtaNext(playerid, status) {

	DestroyDynamicPickup(STREAMER_TAG_PICKUP:tmp_shahta[playerid]);

	if(IsValidDynamicPickup(tmp_shahta[playerid])) return print("shahta wasn`t delete the pickup");

	if(status == 0) {
		new Float:shahta_x,Float:shahta_y,Float:shahta_z;
		switch(random(7)) {
			case 0: shahta_x = 2572.0210, shahta_y = -1337.1841, shahta_z = 16.5915;
			case 1: shahta_x = 2567.3933, shahta_y = -1337.6980, shahta_z = 16.5915;
			case 2: shahta_x = 2563.0530, shahta_y = -1334.7219, shahta_z = 16.5915;
			case 3: shahta_x = 2554.2764, shahta_y = -1338.8025, shahta_z = 16.5915;
			case 4: shahta_x = 2537.9490, shahta_y = -1334.4852, shahta_z = 16.5915;
			case 5: shahta_x = 2533.6277, shahta_y = -1338.9635, shahta_z = 16.5915;
			case 6: shahta_x = 2528.8311, shahta_y = -1335.0293, shahta_z = 16.5915;
			default: shahta_x = 2528.8311, shahta_y = -1335.0293, shahta_z = 16.5915;
		}

		shahtaStatus[playerid] = 0;
		new Float:xy_z;
		FindZ(shahta_x, shahta_y, xy_z);
		printf("%d", xy_z);

		
		tmp_shahta[playerid] = CreateDynamicPickup(1318, 15, shahta_x, shahta_y, shahta_z, -1, -1, playerid);
		SendPond(playerid, "Отправляйтесь к пикапу");
		return 1;
	}
	else if(status == 1) {

		shahtaStatus[playerid] = 1;
		tmp_shahta[playerid] = CreateDynamicPickup(1318, 15, 2544.1550,-1329.8337,9.1300, -1, -1, playerid);
		SendPond(playerid, "Отправляйтесь к пикапу");
	}
	return 1;
}

static ClearSlots(playerid) {
	if(IsPlayerAttachedObjectSlotUsed(playerid, 0)) RemovePlayerAttachedObject(playerid, 0);
	if(IsPlayerAttachedObjectSlotUsed(playerid, 1)) RemovePlayerAttachedObject(playerid, 1);
	if(IsPlayerAttachedObjectSlotUsed(playerid, 2)) RemovePlayerAttachedObject(playerid, 2);
	return 1;
}