// Commands Perfomance Role Play





//==============================================================================
CMD:mynumber(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 10, -101.0118,737.2228,1620.9200))
	{
		ShowPlayerDialog(playerid, D_NUMBER_MENU, DIALOG_STYLE_LIST, "{ffcc00}Получение номеров", "{ffcc00}1. {ffffff}Получить номера\n{ffcc00}2. {ffffff}Снять Т/С с учета", "Выбрать", "Отмена");
	}
	else SCM(playerid, COLOR_RED, "Вы должны находится в здании ДПС");
	return 1;
}
//==============================================================================
/*CMD:td_off(playerid, params[])
{
	for(new i; i < sizeof gps_support_td; i ++) TextDrawHideForPlayer(playerid, gps_support_td[i]);
//	for(new i; i < sizeof arzp_PTD; i ++) TextDrawHideForPlayer(playerid, arzp_PTD[i]);
}
CMD:td_on(playerid, params[])
{
	for(new i; i < sizeof gps_support_td; i ++) TextDrawShowForPlayer(playerid, gps_support_td[i]);
//	for(new i; i < sizeof arzp_PTD; i ++) TextDrawShowForPlayer(playerid, arzp_PTD[i]);
}*/
CMD:getnumber(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 10, -101.0118,737.2228,1620.9200))
	{
		if(PI[playerid][PlayerCarID] == INVALID_VEHICLE_ID) return SendClientMessage(playerid, COLOR_RED, "У Вас нет автомобиля");
		if(PI[playerid][pRegVehicle] == 1) return SendClientMessage(playerid, COLOR_RED, "У Вас уже имеется номерной знак на этом авто!");
		if(strlen(params) < 1 || params[0] != '1') return ShowPlayerDialog(playerid, D_CARNUMBER, DIALOG_STYLE_MSGBOX, "{FFCC00}Получение номеров", "{FFFFFF}Вы уверены что хотите поставить транспорт на учет?\nЦена: {FFCC00}25000 рублей", "Ок", "Отмена");
		//if(GetPVarInt(playerid, "get_number") > gettime()) return SCM(playerid, COLOR_RED, "Подождите %d сек.", (GetPVarInt(playerid, "get_number")-gettime()));
		new number[20];//, string[200];
		Delete3DTextLabel(VehicleLabel[PI[playerid][PlayerCarID]]);
		for(new i; i != 6; i++)
		{
			if(!i) number[i] = random('М' - 'А') + 'А';
			if(i >= 1 && i <=3) number[i] = random('9' - '0') + '0';
			if(i > 3) number[i] = random('М' - 'А') + 'А';
		}
		strmid(PI[playerid][pNumberVehicle], number, 0, strlen(number), 20);
		PI[playerid][pRegVehicle] = 1;
		VehicleLabel[PI[playerid][PlayerCarID]] = Create3DTextLabel(PI[playerid][pNumberVehicle], 0xFFFFFFFF, 0, 0, 0, 10.0, 0);
		Attach3DTextLabelToVehicle(VehicleLabel[PI[playerid][PlayerCarID]], PI[playerid][PlayerCarID], 0, 0, 0.2);
		SetVehicleNumberPlate(PI[playerid][PlayerCarID], "-----");
		GiveMoney(playerid, -25000);
		SendMes(playerid, COLOR_BLUE, "Вы получили гос.номера {FFFFFF}\"%s\" {0099FF}на свой транспорт", number);
		MysqlUpdatePlayerInt(playerid, "veh_reg", PI[playerid][pRegVehicle]);
		MysqlUpdatePlayerStr(playerid, "veh_number", PI[playerid][pNumberVehicle]);

		SetPVarInt(playerid, "get_number", gettime()+300);
	}
	else SCM(playerid, COLOR_RED, "Вы должны находится в здании ДПС");
	return 1;
}
//==============================================================================
CMD:delnumber(playerid)
{
	if(IsPlayerInRangeOfPoint(playerid, 10, -101.0118,737.2228,1620.9200))
	{
		if(PI[playerid][PlayerCarID] == INVALID_VEHICLE_ID) return SendClientMessage(playerid, COLOR_RED, "У Вас нет автомобиля");
		if(PI[playerid][pRegVehicle] == 0) return SendClientMessage(playerid, COLOR_RED, "Транспорт не зарегистрирован");
		Delete3DTextLabel(VehicleLabel[PI[playerid][PlayerCarID]]);
		format(PI[playerid][pNumberVehicle], 20, "[ НЕТ НОМЕРОВ ]");
		PI[playerid][pRegVehicle] = 0;
		VehicleLabel[PI[playerid][PlayerCarID]] = Create3DTextLabel(PI[playerid][pNumberVehicle], 0xFFFFFFFF, 0, 0, 0, 10.0, 0);
		Attach3DTextLabelToVehicle(VehicleLabel[PI[playerid][PlayerCarID]], PI[playerid][PlayerCarID], 0, 0, 0.2);
		SetVehicleNumberPlate(PI[playerid][PlayerCarID], "-----");

		MysqlUpdatePlayerInt(playerid, "veh_reg", PI[playerid][pRegVehicle]);
		MysqlUpdatePlayerStr(playerid, "veh_number", PI[playerid][pNumberVehicle]);

		SCM(playerid, COLOR_LIME, "Вы успешно сняли свой транспорт с учета!");
	}
	else SCM(playerid, COLOR_RED, "Вы должны находится в здании ДПС");
	return 1;
}
CMD:findcar(playerid)
{
    new Float:pos[3], locname[30];
    if(PI[playerid][cModel][0] == 0)
	    return SendClientMessage(playerid,COLOR_RED,"У Вас нет автомобиля");
    if(PI[playerid][PlayerCarID][0] == INVALID_VEHICLE_ID)
	    return SendClientMessage(playerid, COLOR_RED, "Ваш автомобиль не создан, введите: /car");
    GetVehiclePos(PI[playerid][PlayerCarID],pos[0],pos[1],pos[2]);
	locname = "Автомобиль №1";
	GPSPlayer_(playerid, pos[0],pos[1],pos[2], locname);
	return true;
}
CMD:gpsavto(playerid) return callcmd::findcar(playerid);
/*CMD:fixcar(playerid)
{
	new full = 0;
	foreach(new i: Player)
	{
		if(!IsPlayerConnected(i)) continue;
		if(IsPlayerInVehicle(i, GetPlayerCar(playerid))) full++; break;
	}
	if(full != 0) return SendClientMessage(playerid, COLOR_RED, "В транспорте находится игрок");
	DestroyVehicleOP(GetPlayerCar(playerid));
	LoadMyCar(playerid);
	SendClientMessage(playerid, COLOR_LIME, "Ваш транспорт был доставлен на парковку около дома / подъезда");
	SendClientMessage(playerid, COLOR_LIME, "Чтобы найти транспорт, введите: {FFFFFF}/gpsavto");
	return true;
}*/
CMD:car(playerid, params[])
{
	//new h = GetPlayerHouse(playerid) || GetPlayerPorchHouse(playerid);
	new h = GetPlayerHouse(playerid);
	if(!h) return SendClientMessage(playerid, COLOR_RED, "У Вас нет дома/квартиры");
	if(PI[playerid][cModel] < 400) return SendClientMessage(playerid, COLOR_RED, "У Вас нет автомобиля");
	if(PI[playerid][PlayerCarID] == INVALID_PLAYER_ID) LoadMyCar(playerid);

	if(strval(params) == 1)
	{
		if(PI[playerid][pCash] < 10000) return SendClientMessage(playerid, COLOR_RED, "У Вас недостаточно денег");
		else TransferMoney(playerid,-1, 10000);

		/*SetPlayerPosEx(playerid, HouseInfo[h][hCarx], HouseInfo[h][hCary], HouseInfo[h][hCarz]);
		foreach(new i : Player)
		{
			if(GetPlayerVehicleID(i) == PI[playerid][PlayerCarID]) RemovePlayerFromVehicle(i);
		}
		DestroyVehicleOP(GetPlayerCar(playerid));
		SetVehiclePos(PI[playerid][PlayerCarID], HouseInfo[h][hCarx], HouseInfo[h][hCary], HouseInfo[h][hCarz]);
		SetVehicleZAngle(PI[playerid][PlayerCarID], HouseInfo[h][hCarfa]);
		SetVehicleVirtualWorld(PI[playerid][PlayerCarID], 0);
		LinkVehicleToInterior(PI[playerid][PlayerCarID], 0);
		Engine[PI[playerid][PlayerCarID]] = Lights[PI[playerid][PlayerCarID]] = false;
		IsLocked[PI[playerid][PlayerCarID]] = true;
		VehicleArentPlayer[PI[playerid][PlayerCarID]] = INVALID_PLAYER_ID;*/
		DestroyVehicleOP(GetPlayerCar(playerid));
		LoadMyCar(playerid);
		SendClientMessage(playerid, COLOR_LIME, "Ваш транспорт был доставлен на парковку около дома / подъезда");
		SendClientMessage(playerid, COLOR_LIME, "Чтобы найти транспорт, введите: {FFFFFF}/gpsavto");
	}
	else ShowPlayerDialog(playerid, D_HOME+3, 0, "{FFCC00}Доставка транспорта", "{FFFFFF}Вы хотите чтобы Ваш транспорт доставили к дому?\nЦена: {FFCC00}10000 рублей", "Да", "Нет");

	return 1;
}

CMD:untow(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		new vehplid=GetPlayerVehicleID(playerid);
		DetachTrailerFromVehicle(vehplid);
		SendClientMessage(playerid, COLOR_GRAD1, "Вы отцепили тросс от авто");
	}
	return 1;
}
CMD:towncar(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 509 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 510 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 462 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 481 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 522) return SendClientMessage(playerid, COLOR_GREY, "На это транспортное средство нельзя установить трос!");
		new vehplid=GetPlayerVehicleID(playerid);
		new Float:plAngle;    GetVehicleZAngle(vehplid, plAngle);
		new Float:crAngle,Float:Angle,Float:Angle2;
		//====================
		new Float:posx, Float:posy, Float:posz;
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		new Float:Radi=6.0;        //Расстояние от тачки
		new Float:AngRange=90.0;    //максимальный радиус
		//======================
		for(new i = 0; i < MAX_VEHICLES; i++)   //700
		{
			if(i == vehplid) continue;    //себя цеплять ненадо
			GetVehiclePos(vehplid, posx, posy, posz); //координаты тачки
			GetVehiclePos(i, oldposx, oldposy, oldposz); //координаты ближайшей
			tempposx = (oldposx -posx);
			tempposy = (oldposy -posy);
			tempposz = (oldposz -posz);
			if (((tempposx < Radi) && (tempposx > -Radi)) && ((tempposy < Radi) && (tempposy > -Radi)) && ((tempposz < Radi) && (tempposz > -Radi)))
			{
				GetVehicleZAngle(i, crAngle);
				Angle = (plAngle -crAngle);
				Angle2= (Angle-180.0);
				if (( ((Angle < AngRange) && (Angle > -AngRange)) || ((Angle2 < AngRange) && (Angle2 > -AngRange)) ))
				{
					AttachTrailerToVehicle(i, vehplid);
					new string[128];
					format(string,sizeof(string),"Автомобиль подцеплен. Отцепить: /untown");
					SendClientMessage(playerid, COLOR_GRAD1, string);
					return 1;
				}
			}
		}
		SendClientMessage(playerid, COLOR_GRAD1, " * Подъедьте поближе к автомобилю.");
		return 1;
	}
	return 1;
}
//==============================================================================
cmd:createradar(playerid)
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pAdmin] > 6)
	{
		ShowPlayerDialogEx(playerid, D_RADAR, DIALOG_STYLE_LIST, "{0099FF}>> Создание радара","\
			{FFFFFF}1. Дворовая территория {99CC00}(Макс. доп. скорость: 20км/ч)\n\
			{FFFFFF}2. Населенные пункты {99CC00}(Макс. доп. скорость: 60км/ч)\n\
			{FFFFFF}3. Автомагистрали {99CC00}(Макс. доп. скорость: 110км/ч)\n\
			{FFFFFF}4. Вне населенных пунктов(ост. дороги): {99CC00}(Макс. доп. скорость: 90км/ч)",
		"Выбрать","Отмена");
	}
	else SendClientMessage(playerid,COLOR_GREEN,"Радар имеет право устанавливать только Гл.Администратор сервера");
	return 1;
}
//==============================================================================
CMD:mycar(playerid)
{
    if(PI[playerid][pAdmin] < ADM_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(PI[playerid][PlayerCarID] == INVALID_VEHICLE_ID) return SendClientMessage(playerid, COLOR_RED, "У Вас нет автомобиля");
	PutPlayerInVehicle(playerid, PI[playerid][PlayerCarID], 0);
	return 1;
}
CMD:buymet(playerid)
{
	if(IsPlayerInRangeOfPoint(playerid, 8.0, 1646.49, 1409.40, 12.00))
	{
		if(IsPlayerInVehicle(playerid, 578))
		{
			ShowPlayerDialog
			(
				playerid, DIALOG_BUY_METALL, DIALOG_STYLE_MSGBOX,
				"{FFCC00}Шахта",
				"{ffffff}Вы действительно хотите купить {FFCC00}500 кг. {FFFFFF}металла за {FFFFFF}4000 рублей?",
				"Да", "Нет"
			);
		}
	}
}
CMD:pov(playerid, params[])
{
    if(!IsPlayerConnected(playerid)) return 1;
    switch(switch_fp[playerid])
    {
        case false:
        {
            switch_fp[playerid] = true, SendClientMessage(playerid, COLOR_LIME, "Вы включили вид от 1-го лица");
            FirstPerson[playerid] = CreateObject(19300, 0, 0, 0, 0, 0, 0);
            ChangeView(playerid, 0, GetPlayerState(playerid));
        }
        case true: switch_fp[playerid] = false, SetCameraBehindPlayer(playerid), SendClientMessage(playerid, COLOR_LIME, "Вы выключили вид от 1-го лица");
    }
    return 1;
}
/*CMD:fmenu(playerid)
{
    new String[156];
    //if(PI[playerid][pLogin] == 0) return true;
    if(PI[playerid][pFamily] == 0) return SendClientMessage(playerid, COLOR_RED,"Вы не состоите не в какой семье");
    //
    format(String, sizeof(String), "1. Информация о семье\n2. {FFA54F}Покинуть семью{FFFFFF}\n3. Изменить цвет рации семьи\n4. Смена названия семьи\n5. Члены семьи онлайн: %d\n6. Склад", family_info [PI[playerid][pFamily]] [f_online]);
	ShowPlayerDialog(playerid, 702, DIALOG_STYLE_LIST, "{FFCC00}Меню семьи", String, "Выбор", "Выход");
    return true;
}*/

/*CMD:fmenu(playerid)
{
	STRING_GLOBAL = "";
	if(PI[playerid][pFamily] == 0) return SendClientMessage(playerid, COLOR_RED,"Вы не состоите ни в какой семье");
	new famonline = 0;
    foreach(new i: Player)
	{
		if(PI[playerid][pFamily] == PI[i][pFamily]) famonline++;
	}
	if(family_info [ PI[playerid][pFamily] ] [ f_spawn_virt ] == 0)
	{
	    format(STRING_GLOBAL, 400, "{FFCC00}1. {FFFFFF}Информация о семье\n{FFCC00}2. {FFFFFF}Покинуть семью\n{FFCC00}3. {FFFFFF}Изменить цвет рации семьи\n{FFCC00}4. {FFFFFF}Смена названия семьи\n{FFCC00}5. {FFFFFF}Дом семьи: {FF6347}Нет{FFFFFF}\n{FFCC00}6. {FFFFFF}Общак семьи\n{FFCC00}7. {FFFFFF}Автопарк семьи\n{FFCC00}8. {FFFFFF}Весь состав семьи\n{FFCC00}9. {FFFFFF}Члены семьи онлайн: {FFCC00}%d{FFFFFF} человек(а)", famonline);
		ShowPlayerDialogEx(playerid, 702, DIALOG_STYLE_LIST, "{FFCC00} Меню семьи", STRING_GLOBAL, "Выбор", "Выход");
	}
	else
	{
	    format(STRING_GLOBAL, 400, "{FFCC00}1. {FFFFFF}Информация о семье\n{FFCC00}2. {FFFFFF}Покинуть семью\n{FFCC00}3. {FFFFFF}Изменить цвет рации семьи\n{FFCC00}4. {FFFFFF}Смена названия семьи\n{FFCC00}5. {FFFFFF}Дом семьи: {FFCC00}№%d{FFFFFF}\n{FFCC00}6. {FFFFFF}Общак семьи\n{FFCC00}7. {FFFFFF}Автопарк семьи\n{FFCC00}8. {FFFFFF}Весь состав семьи\n{FFCC00}9. {FFFFFF}Члены семьи онлайн: {FFCC00}%d{FFFFFF} человек(а)", family_info [ PI[playerid][pFamily] ] [ f_spawn_virt ], famonline);
		ShowPlayerDialogEx(playerid, 702, DIALOG_STYLE_LIST, "{FFCC00} Меню семьи", STRING_GLOBAL, "Выбор", "Выход");
	}
	return 1;
}*/

/*CMD:family(playerid, params[])
{
	new familyid = PI[playerid][P_FAMILY];

	if(familyid == 0)
		return SendMess(playerid, MSG_NO_PLAYER_CONSIST_FAMILY);

	STRING_GLOBAL[0] = EOS;

	strcat(STRING_GLOBAL, "1. Информация о семье\n");
	strcat(STRING_GLOBAL, "2. Состав семьи онлайн\n");
	strcat(STRING_GLOBAL, "3. Состав семьи оффлайн\n");
	strcat(STRING_GLOBAL, "4. Изменить цвет чата\n");
	strcat(STRING_GLOBAL, "5. Покинуть семью\n");
	strcat(STRING_GLOBAL, "6. Найти семейный транспорт\n");

	if(GetFamilyRang(playerid) != 1)
	{
		strcat(STRING_GLOBAL, "7. Загрузить/выгрузить семейный транспорт\n");
		strcat(STRING_GLOBAL, "8. Продать семейный транспорт\n");
	}

	if(GetFamilyRang(playerid) != 1)
	{
		strcat(STRING_GLOBAL, "9. Заказать продукты\n");
	}

	if(GetFamilyData(familyid, F_OWNED) == PI[playerid][pID])
	{
		strcat(STRING_GLOBAL, "10. Изменить спавн семьи\n");
	}

	ShowPlayerDialog
	(
		playerid, DIALOG_FAMILY, DIALOG_STYLE_LIST,
		"{ffcc00}Меню семьи",
		STRING_GLOBAL,
		"Далее", "Отмена"
	);

	return 1;
}*/

/*CMD:finvite(playerid, params[])
{
    new String[128];
    //if(PI[playerid][pLogin] == 0) return true;
    if(PI[playerid][pFamilySozd] == 0 && PI[playerid][pFamilyZam] == 0) return SendClientMessage(playerid, COLOR_RED, "Принимать в семью может только создатель и заместитель семьи");
    if(sscanf(params, "d", params [0])) return SendClientMessage(playerid, COLOR_RED, "Ввведите: /finvite [id]");
    if(!IsPlayerConnected(params [0])) return SendClientMessage(playerid, COLOR_RED, "Указан не верный ID игрока");
    if(GetDistanceBetweenPlayers(playerid, params[0]) > 5.0) return SendClientMessage(playerid, COLOR_RED, "Этот игрок находится далеко от Вас");
    if(PI[params[0]][pFamily] > 0) return SendClientMessage(playerid, COLOR_RED, "Этот игрок уже состоит в семье!");
    new text_string [46 + MAX_PLAYER_NAME + 32];
    format(text_string,sizeof(text_string),"Вы пригласили %s присоединиться к семье %s",GetName(params[0]),family_info [PI[playerid][pFamily]] [f_name]);
    SendClientMessage(playerid,-1,text_string);
	//
    format(String,sizeof(String),"{ffffff}%s приглашает Вас присоединиться к семье %s.\nВы согласны присоединиться?",GetName(playerid),family_info[PI[playerid][pFamily]] [f_name]);
    ShowPlayerDialog(params[0],707,DIALOG_STYLE_MSGBOX,"{FFCC00}Приглашение в семью",String,"Да","Нет");
	//
    SetPVarInt(params [0],"family_id",PI[playerid][pFamily]);
    SetPVarInt(params [0],"family_playerid",playerid);
    return 1;
}
CMD:funinvite(playerid, params[])
{
    new String[128], YCMDstr[64];
    //if(PI[playerid][pLogin] == 0) return true;
    if(sscanf(params, "ds[128]",params[0],String)) return SendClientMessage(playerid, COLOR_RED, "Используйте: /funinvite [id] [причина]");
	{
	    if(PI[playerid][pFamilySozd] == 0 && PI[playerid][pFamilyZam] == 0) return SendClientMessage(playerid, COLOR_RED,"Выгонять из семьи может только заместитель и создатель");
	    if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете выгнать самого себя!");
	    if(PI[params[0]][pFamilySozd] > 0) return SendClientMessage(playerid, COLOR_RED, "Вы не можете уволить создателя семьи!");
	    if(PI[playerid][pFamily] != PI[params[0]][pFamily]) return SendClientMessage(playerid, COLOR_RED, "Данный игрок не состоит в Вашей семье");
	    format(YCMDstr, sizeof(YCMDstr), "%s выгнал Вас из семьи. Причина: %s",GetName(playerid), String);
		SendClientMessage(params[0], 0xFFD39BFF, YCMDstr);
		format(YCMDstr, sizeof(YCMDstr), "Вы выгнали игрока %s из семьи. Причина %s",GetName(params[0]), String);
		SendClientMessage(playerid, 0xFFD39BFF, YCMDstr);
		family_info [ PI[params[0]][pFamily]] [ f_online ] -= 1;
	 	family_info [ PI[params[0]][pFamily] ] [ f_members_amount ] -= 1;
	 	PI[params[0]][pFamily] = 0;
	 	PI[params[0]][pFamilyZam] = 0;
        format(String,sizeof(String),"{%s}[%s]{FFD39B} %s выгнал игрока %s из семьи. Причина: %s",family_chat_color [family_info[PI[playerid][pFamily]] [f_chat_color ]],family_info [PI[playerid][pFamily]] [f_name],GetName(playerid),GetName(params[0]),String);
	  	family_message(PI[playerid][pFamily],-1, String);
	  	SaveAccount(params[0]);
	  	//
		format ( String, sizeof String, "UPDATE "T_FAMILY" SET `fam_members_amount` = '%d' WHERE `fam_id` = '%d' LIMIT 1",family_info [PI[playerid][pFamily]] [f_members_amount], PI[playerid][pFamily]);
		mysql_function_query ( dbHandle, String, false, "", "" ) ;
		return true;
	}
}*/
/*CMD:f(playerid, params[])
{
	new String[128];
	if(PI[playerid][pFamily] == 0) return SendClientMessage(playerid, COLOR_RED, "Вы не состоите в семье!");
    if(sscanf(params, "s[128]", params[0]))return SendClientMessage(playerid, COLOR_LIME, "Информация:{FFFFFF} /f [текст]");
	if(PI[playerid][pMuted] > 0) return SendClientMessage(playerid, COLOR_RED, "У Вас затычка. Узнать подробней: /time");
	else if(IsIpFound(params[0]) || CheckString(params[0])) return PlayerGetsChatBan(playerid, params[0]);
    format(String, sizeof(String), "{%s}[%s]{FFD39B} %s [%d]: %s",family_chat_color [family_info [PI[playerid][pFamily]] [f_chat_color]],family_info [PI[playerid][pFamily]] [f_name],GetName(playerid),playerid,params);
    family_message(PI[playerid][pFamily],-1, String);
    SetPlayerChatBubble(playerid, "Отправляет сообщение в рацию",COLOR_PURPLE,30.0,10000);
    return true;
}*/
CMD:help(playerid)
{
	ShowPlayerDialog(playerid, 3794, DIALOG_STYLE_LIST, "{FFCC00}Помощь", "{FFCC00}1.{FFFFFF} Начало игры\n{FFCC00}2.{FFFFFF} Предыстория\n{FFCC00}3.{FFFFFF} Первоначальный заработок\n{FFCC00}4.{FFFFFF} Шаги к приобретению первого имущества\n{FFCC00}5.{FFFFFF} Водительские права\n{FFCC00}6.{FFFFFF} Доступные работы и устройство в организацию\n{FFCC00}8.{FFFFFF} Дополнение списка необходимых правил\n{FFCC00}9.{FFFFFF} Будь с нами!", "Выбрать", "Назад");
}
CMD:buyk(playerid)
{
	if(PlayerLogged[playerid] == false) return true;
	new full;
	if(full == 0)
	for(new i = 1; i <= TOTALBIZZ; i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 5.0, BizzInfo[i][bEntrx], BizzInfo[i][bEntry], BizzInfo[i][bEntrz])
				&& BizzInfo[i][bType] == 2)
		{
		
			if(!GetPVarInt(playerid, "have_jerrican"))
			{
				if(PI[playerid][pCash] >= 500)
				{
					GiveMoney(playerid, -500);

					SetPVarInt(playerid, "have_jerrican", 1);
					SetPlayerAttachedObject(playerid, 3, 1650, 5, 0.15, 0.0, 0.0, 0.0, -90.0, 180.0, 1.0, 1.0, 1.0, 0);

					SCM(playerid, 0x99CC00FF, "Вы купили канистру");
				}
				else SCM(playerid, COLOR_RED, "У Вас недостаточно денег. Для покупки канистры нужно 500 рублей");
			}
		}
	}
	return 1;
}
//==============================================================================
CMD:backpack(playerid)
{
    if(PI[playerid][pWatch] == 0) return SendClientMessage(playerid, COLOR_RED, "У Вас нет рюкзака, Вы можете купить его в 24/7");
	{
		if(PI[playerid][pWatch] == 1)
		{
			SetPlayerAttachedObject(playerid, 1, 3026, 1, -0.176000, -0.066000, 0.0000,0.0000, 0.0000, 0.0000, 1.07600, 1.079999, 1.029000);
			SCM(playerid, COLOR_LIME, "Вы надели рюкзак");
		}
		else
		{
			RemovePlayerAttachedObject(playerid, 1);
	    	SCM(playerid, COLOR_LIME, "Вы сняли рюкзак");
		}
	}
	return 1;
}
//==============================================================================
CMD:unrent(playerid)
{
    if(GetPVarInt(playerid, "arendkey") == -1) return SendClientMessage(playerid, COLOR_RED, "Вы не арендуете транспорт");
	new rc = GetPVarInt(playerid, "arendkey");
	if(ArendInfo[rc][aPlayerID] != playerid)
	{
	    SendClientMessage(playerid, COLOR_RED, "Вы не арендуете транспорт");
	    SetPVarInt(playerid, "arendkey", -1);
	    return 1;
	}
	ShowPlayerDialog(playerid, D_CANCELRENT, 0, "{FFCC00}Отмена аренды", "\n\n{FF6600}Вы действительно хотите отменить аренду транспорта?\n{FFFFFF}Дальнейшее его использование станет недоступным,\nдо нового заключения договора на аренду транспорта.\n\n", "Принять", "Отмена");
	return 1;
}
CMD:en(playerid)
{
    if(IsPlayerInAnyVehicle(playerid))
    {
	    new vehicleid = GetPlayerVehicleID(playerid);
		GetVehicleParamsEx(vehicleid,engine,lights,alarm,doors,bonnet,boot,objective);
		SetVehicleParamsEx(vehicleid,(Engine[vehicleid])?(false):(true),lights,alarm,doors,bonnet,boot,objective);
		Engine[vehicleid] = (Engine[vehicleid])?(false):(true);
    }
    return 1;
}
CMD:slimit(playerid, params[])
{
    if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, !"• Информация:{FFFFFF} /slimit [скорость (0-60)] (0 - снять ограничение)");
    new speed_ts = strval(params);

    if(speed_ts < 0 || speed_ts > 60) return SendClientMessage(playerid, COLOR_RED, !"Значение скорости должно быть от 0 до 60");
    SetPVarInt(playerid, "speed_test", speed_ts);
    return true;
}
CMD:gotohouse(playerid,params[])
{
    if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(sscanf(params, "d",params[0])) return SendClientMessage(playerid,COLOR_LIME, "Информация: {ffffff}/gotohouse [номер дома]");
	new string[145];
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid,0);
	SetPlayerPos(playerid,HouseInfo[params[0]][hEntrx],HouseInfo[params[0]][hEntry],HouseInfo[params[0]][hEntrz]);
	format(string, sizeof(string), "Вы телепортировались к дому №%d",params[0]);
	SendClientMessage(playerid,COLOR_LIME,string);
	return true;
}
CMD:gotobiz(playerid,params[])
{
    if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(sscanf(params, "d",params[0])) return SendClientMessage(playerid,COLOR_LIME, "Информация: {ffffff}/gotobiz [номер бизнеса]");
	new string[145];
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid,0);
	SetPlayerPos(playerid,BizzInfo[params[0]][bEntrx],BizzInfo[params[0]][bEntry],BizzInfo[params[0]][bEntrz]);
	format(string, sizeof(string), "Вы телепортировались к бизнесу №%d",params[0]);
	SendClientMessage(playerid,COLOR_LIME,string);
	return true;
}
//==============================================================================
CMD:setnomer(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_GRAND) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    if(sscanf(params, "is", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/setnomer [id игрока] [номера]");
	Delete3DTextLabel(VehicleLabel[PI[params[0]][PlayerCarID]]);
	strmid(PI[params[0]][pNumberVehicle], params[1], 0, strlen(params[1]), 20);
    MysqlUpdatePlayerStr(playerid, "veh_number", PI[playerid][pNumberVehicle]);
    SetVehicleNumberPlate(PI[params[0]][PlayerCarID], PI[params[0]][pNumberVehicle]);
	return true;
}
//==============================================================================
CMD:agivevoen(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/agivevoen [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_DARKORANGE, PlayerIsNotOnline);
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_DARKORANGE, PlayerIsNotAuthorized);
	else if(PI[params[0]][pVoennik]) return SendClientMessage(playerid, COLOR_DARKORANGE, "У игрока уже имеется военный билет!");
	PI[params[0]][pVoennik] = 1;
	SendClientMessage(params[0], COLOR_BLUE, "Поздравляем! Вы получили военный билет");
	SendClientMessage(playerid, COLOR_LIME, "Вы выдали военный билет!");
    return 1;
}
//==============================================================================
CMD:tp(playerid)
{
	if(PI[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	ShowPlayerDialog(playerid, D_JOB+139, DIALOG_STYLE_LIST, "{FFCC00}Телепорт", "{FFC000}1. {FFFFFF}Города\n{FFC000}2. {FFFFFF}Общественные места\n{FFC000}3. {FFFFFF}Работы\n{FFC000}4. {FFFFFF}Базы организаций", "Выбрать", "Закрыть");
	return 1;
}
//==============================================================================

CMD:setvw(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    if(sscanf(params, "ii", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/setvw [id игрока] [Вирт.мир]");
	SetPlayerVirtualWorld(params[0], params[1]);
	new string[128];
	format(string, sizeof(string), "Вы установили игроку %s [%d] виртуальный мир %i", GetName(params[0]), params[0], params[1]);
	SendClientMessage(playerid, COLOR_BLUE, string);
	format(string, sizeof(string), "[A] %s [%d] установил игроку %s [%d] виртуальный мир %i", GetName(playerid), playerid, GetName(params[0]), params[0], params[1]);
	SendAdminMessage(COLOR_GREY, string);
	format(string, sizeof(string), "Администратор %s установил Вам виртуальный мир %i", GetName(playerid), params[1]);
	SendClientMessage(params[0], COLOR_BLUE, string);
    return 1;
}
CMD:setint(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(sscanf(params, "ui", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/setint [id игрока] [id интерьера]");
    SetPlayerInterior(params[0], params[1]);
	new string[128];
	format(string, sizeof(string), "Вы установили игроку %s [%d] интерьер %i", GetName(params[0]), params[0], params[1]);
	SendClientMessage(playerid, COLOR_BLUE, string);
	format(string, sizeof(string), "[A] %s [%d] изменил %s [%d] виртуальный интерьер на №%i", GetName(playerid), playerid, GetName(params[0]), params[0], params[1]);
	SendAdminMessage(COLOR_GREY, string);
	format(string, sizeof(string), "Администратор %s установил Вам интерьер %i", GetName(playerid), params[1]);
	SendClientMessage(params[0], COLOR_BLUE, string);
	return true;
}

cmd:alogs(playerid, params[])
{
	if(PI[playerid][pAdmin] < 1)
	return 1;

	if(AdminInfo[playerid][admAlog] == 0)
	{
		AdminInfo[playerid][admAlog] = 1;

		SendClientMessage(playerid, COLOR_BLUE, "Вы включили информацию о входах/выходах");
	}
	else
	{
		AdminInfo[playerid][admAlog] = 0;

		SendClientMessage(playerid, COLOR_BLUE, "Вы выключили информацию о входах/выходах");
	}

	new fmt_query[80];

	mysql_format(dbHandle, fmt_query, sizeof fmt_query, "UPDATE "T_ADMIN" SET alog=%d WHERE name='%s' LIMIT 1", AdminInfo[playerid][admAlog], GetName(playerid));
	mysql_tquery(dbHandle, fmt_query, "", "");

	return 1;
}

CMD:agivevb(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/agivevb [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pVoennik]) return SendClientMessage(playerid, COLOR_RED, "У игрока уже имеется военный билет!");
	PI[params[0]][pVoennik] = 1;
	SendClientMessage(params[0], COLOR_BLUE, "Поздравляем! Вы получили военный билет");
	SendClientMessage(playerid, COLOR_LIME, "Вы выдали военный билет!");
    return 1;
}
CMD:givevb(playerid, params[])
{
	if(PI[playerid][pMember] != TEAM_VDV) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/givevb [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pVoennik]) return SendClientMessage(playerid, COLOR_RED, "У игрока уже имеется военный билет!");
	else if(PI[params[0]][pMember] != TEAM_VDV) return SendClientMessage(playerid, COLOR_RED, "Игрок не служит в армии!");
	else if(IsPlayerInAnyVehicle(params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок не должен находится в транспорте!");
	else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	if(PI[playerid][pMember] == TEAM_VDV && PI[playerid][pRank] >= 9)
	{
        PI[params[0]][pVoennik] = 1;
		SendClientMessage(params[0], COLOR_BLUE, "Поздравляем! Вы получили военный билет");
		SendClientMessage(playerid, COLOR_LIME, "Вы выдали военный билет!");
	}
    else SendClientMessage(playerid, COLOR_WHITE, "Вы не можете выдавать военный билет!");
    return 1;
}
CMD:takevb(playerid, params[])
{
	if(PI[playerid][pMember] != TEAM_VDV) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/takevb [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pMember] != TEAM_VDV) return SendClientMessage(playerid, COLOR_RED, "Игрок не служит в армии!");
	else if(IsPlayerInAnyVehicle(params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок не должен находится в транспорте!");
	else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	if(PI[playerid][pMember] == TEAM_VDV && PI[playerid][pRank] >= 9)
	{
        PI[params[0]][pVoennik] = 0;
		SendClientMessage(params[0], COLOR_BLUE, "У Вас забрали военный билет");
		SendClientMessage(playerid, COLOR_LIME, "Вы забрали военный билет!");
	}
    else SendClientMessage(playerid, COLOR_WHITE, "Вы не можете забрать военный билет!");
    return 1;
}
CMD:mp(playerid)
{
	if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(Teleport == 0)
	{
		GetPlayerPos(playerid, TeleportFloat[0], TeleportFloat[1], TeleportFloat[2]);
		TeleportInfo[0] = GetPlayerInterior(playerid);
		TeleportInfo[1] = GetPlayerVirtualWorld(playerid);
		Teleport = 1;
		new string[120];
		format(string, sizeof(string), "Вы включили телепорт на МП");
		SendClientMessage(playerid, COLOR_LIME, string);
		format(string, sizeof(string), "[A] %s [%d] открыл телепортацию на МП: /gotomp", GetName(playerid), playerid);
		SendAdminMessage(COLOR_YELLOW, string);
	}
	else if(Teleport == 1)
	{
		new string[120];
		format(string, sizeof(string), "Вы закрыли телепорт МП");
		SendClientMessage(playerid, COLOR_LIME, string);
		format(string, sizeof(string), "[A] %s [%d] прекратил МП", GetName(playerid), playerid);
		SendAdminMessage(COLOR_GREY, string);
		Teleport = 0;
	}
	return 1;
}
CMD:gotomp(playerid)
{
    if(PI[playerid][pJail] > 0) return SendClientMessage(playerid, COLOR_RED, "Заключённым нельзя телепортироваться");
    if(Teleport == 0) return true;
    else
    SetPlayerPos(playerid, TeleportFloat[0], TeleportFloat[1], TeleportFloat[2]);
    SetPlayerInterior(playerid, TeleportInfo[0]);
    SetPlayerVirtualWorld(playerid, TeleportInfo[1]);
    return true;
}
/*CMD:createobject(playerid)
{
	if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
  	ShowPlayerDialog(playerid, dLego, DIALOG_STYLE_LIST, "Редактор объектов", "Инструкция\nСоздать объект\nИзменить карту\nУдалить все","Выбрать","Отмена");
  	return 1;
}*/
CMD:startmp(playerid)
{
    if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Команда не обнаружена! {FFCC00}/menu {FFFFFF}для просмотра команд");
	if(paintt[1] == 1)
	   return SendClientMessage(playerid, COLOR_RED, "[МП] Матч по пейнтболу уже начался!");

    if(GetPVarInt(playerid, "paintball") == 2)
       return SendClientMessage(playerid, COLOR_RED, "[МП] Матч по пейнтболу уже начался!");

    SendClientMessageToAll(0xFFCC00FF, "[МП] Внимание! Начало пейнтбола через 5 минут!!");

    paintt[0] = 300;
    paintt[1] = 1;

	foreach(new i: Player)
	{
        if(GetPVarInt(i, "paintball") == 1)
        {
            DeletePVar(i, "paintball");
		}
	}

	return 1;
}
//==============================================================================
CMD:sethp(playerid, params[])
{
	if(PI[playerid][pAdmin] < 4) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "ui", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/sethp [ид игрока] [HP]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	PI[params[0]][pHeal] = params[1];
	PI[params[0]][pHealthS] = params[1];
	SetHealth(params[0], params[1]);
	new string[128];
	format(string, sizeof(string), "Вы изменили здоровье %s [%d] на %i hp", GetName(params[0]), params[0], params[1]);
	SendClientMessage(playerid, COLOR_WHITE, string);
	format(string, sizeof(string), "Администратор %s изменил Ваше здоровье", GetName(playerid));
	SendClientMessage(params[0], COLOR_BLUE, string);
	format(string, sizeof(string), "[A] %s [%d] изменил %s [%d] здоровье на %i", GetName(playerid), playerid, GetName(params[0]), params[0], params[1]);
	SendAdminMessage(COLOR_GREY, string);
	return 1;
}
//==============================================================================
CMD:setarmour(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "ui", params[0],params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/setarmour [ид игрока] [кол-во брони]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(params[1] > 100 || params[1] < 0) return SendClientMessage(playerid, COLOR_RED, "Количество брони от 0 до 100!");
	SetArmour(params[0], params[1]);
	new string[128];
	format(string, sizeof(string), "Администратор %s [%d] изменил Вам показатель брони на %i", GetName(playerid), playerid, params[1]);
	SendClientMessage(params[0], COLOR_WHITE, string);
	format(string, sizeof(string), "[A] %s [%d] изменил показатель брони игроку %s [%d] на %i", GetName(playerid), playerid, GetName(params[0]), params[0], params[1]);
	SendAdminMessage(COLOR_GREY, string);
	return 1;
}
//==============================================================================
CMD:hbject(playerid, params[])
{
	if(PI[playerid][pAdmin] < 5) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/hbject [id игрока]");
	else if(PlayerLogged[params[0]] == false) return 1;
 	objectplayerid = params[0];
	ShowPlayerDialog(playerid,8420,DIALOG_STYLE_LIST,"{FFCC00}Выдать объект игроку","1. Шляпа курицы\n2. Огонек на голову\n3. Мигалка на голову\n4. Черная маска\n5. Бандана №1\n6. Бандана №2\n7. Бандана №3\n8. Бандана №4\n9. Бандана №5\n10. Маска дракона\n11. Лазер на голову\n12. Комплект всемогущий\n13. Попугай на плечо\n14. Яркий свет\n15. Большой М4 в руку\n16. Пенис\n17. Костюм попугая\n18. Удалить все объекты","Выбрать","Закрыть");
	return 1;
}
//==============================================================================
CMD:okay(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(set_name == -1) return SendClientMessage(playerid, COLOR_RED, "Никто не предлагал сменить ник!");
	else if(!strcmp(PlayerName[set_name], "None", true)) return SendClientMessage(playerid, COLOR_RED, "Этот игрок не предлагал сменить ник!");
	if(GetPlayerHouse(set_name))
	{
		new i = GetPVarInt(set_name, "PlayerHouse");
		if(!strcmp(HouseInfo[i][hOwner], GetName(set_name), true))
		{
			format(HouseInfo[i][hOwner], MAX_PLAYER_NAME, PlayerName[set_name]);
			MysqlUpdateHouseStr(i, "hOwner", PlayerName[set_name]);
		}
	}
	if(GetPlayerBizz(set_name))
	{
		new i = GetPVarInt(set_name, "PlayerBizz");
		if(!strcmp(BizzInfo[i][bOwner], GetName(set_name), true))
		{
			format(BizzInfo[i][bOwner], MAX_PLAYER_NAME, PlayerName[set_name]);
			MysqlUpdateBizzStr(i, "owner", PlayerName[set_name]);
			UpdateBizz(i);
		}
	}
	new string[128];
	format(string, sizeof(string), "[A] Заявку одобрил Администратор %s", GetName(playerid));
	SendAdminMessage(COLOR_LIME, string);
	format(string, sizeof(string), "[НонРП] %s одобрил смену нонРП ника %s на %s", GetName(playerid), GetName(set_name), PlayerName[set_name]);
	SendLog("SetName", string);
	format(string, sizeof(string), "%s сменил ник на %s", GetName(set_name), PlayerName[set_name]);
	SendClientMessageToAll(COLOR_LIME, string);
	format(query, sizeof(query),"UPDATE `accounts` SET name='%s' WHERE name='%s'", PlayerName[set_name], GetName(set_name));
	mysql_tquery(dbHandle, query, "", "");
	if(PI[set_name][pAdmin])
	{
		format(query, sizeof(query), "UPDATE `admins` SET name='%s' WHERE name='%s'", PlayerName[set_name], GetName(set_name));
		mysql_tquery(dbHandle, query, "", "");
	}
	format(query, sizeof(query), "INSERT INTO `historyname` (`idacca`, `Name`) VALUE ('%d', '%s')", PI[set_name][pID], PlayerName[set_name]);
	mysql_tquery(dbHandle, query, "", "");
	format(GetName(set_name), MAX_PLAYER_NAME, PlayerName[set_name]);
	SetPlayerName(set_name, PlayerName[set_name]);
	SendMes(set_name, COLOR_GREEN, "Ваше новое имя: {ffffff}%s", PlayerName[set_name]);
	SendClientMessage(set_name, COLOR_GREEN, "Обязательно нужно сделать скриншот. Клавиша: {ffffff}F8");
	SendClientMessage(set_name, COLOR_GREEN, "Пропишите свой новый ник в окне {ffffff}SA:MP");
	strmid(PlayerName[set_name], "None", 0, strlen("None"), MAX_PLAYER_NAME);
	Kick(set_name);
	set_name = -1;
	return 1;
}

CMD:tie(playerid, params[])
{
	if(!IsAMafia(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(pCuff[playerid][pCuffee] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы в наручниках, Вы не можете связывать!");
	if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/tie [id игрока]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	new Float:possed[4];
	GetPlayerPos(params[0],possed[0],possed[1],possed[2]);
	if(!IsPlayerInRangeOfPoint(playerid, 1, possed[0],possed[1],possed[2])) return SendClientMessage(playerid, COLOR_RED, "Вы слишком далеко от данного игрока");
	if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете связать себя!");
	if(PlayerTied[params[0]]) return SendClientMessage(playerid, COLOR_RED, "Игрок уже связан!");
	new string[100];
	SendMes(playerid, 0x6495EDFF, "Вы связали %s", GetName(params[0]));
	if(PI[playerid][pSex] == 1)
	{
		SendMes(params[0], 0x6495EDFF, "%s связал Вас", GetName(playerid));
		format(string, sizeof(string), "связал %s", GetName(params[0]));
	}
	else
	{
	    SendMes(params[0], 0x6495EDFF, "%s связала Вас", GetName(playerid));
		format(string, sizeof(string), "связала %s", GetName(params[0]));
	}
	MeAction(playerid, string);
	GameTextForPlayer(playerid, "~r~tieted", 5000, 5);
	GameTextForPlayer(params[0], "~r~tieted", 5000, 5);
	TogglePlayerControllable(params[0], 0);
	PlayerTied[params[0]] = true;
	return 1;
}
//==============================================================================
CMD:untie(playerid, params[])
{
	if(!IsAMafia(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/untie [id игрока]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	new Float:possed[4];
	GetPlayerPos(params[0],possed[0],possed[1],possed[2]);
	if(!IsPlayerInRangeOfPoint(playerid, 4, possed[0],possed[1],possed[2])) return SendClientMessage(playerid, COLOR_RED, "Вы слишком далеко от данного игрока");
	if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете развязать себя!");
	if(!PlayerTied[params[0]]) return SendClientMessage(playerid, COLOR_RED, "Игрок не связан!");
	new string[100];
	SendMes(playerid, 0x6495EDFF, "Вы развязали %s", GetName(params[0]));
	if(PI[playerid][pSex] == 1)
	{
		SendMes(params[0], 0x6495EDFF, "%s развязал Вас", GetName(playerid));
		format(string, sizeof(string), "развязал %s", GetName(params[0]));
	}
	else
	{
	    SendMes(params[0], 0x6495EDFF, "%s развязала Вас", GetName(playerid));
		format(string, sizeof(string), "развязала %s", GetName(params[0]));
	}
	MeAction(playerid, string);
	GameTextForPlayer(playerid, "~g~untied", 5000,5);
	GameTextForPlayer(params[0], "~g~untied", 5000,5);
	TogglePlayerControllable(params[0], 1);
	PlayerTied[params[0]] = false;
	return 1;
}
CMD:spawn(playerid)
{
    if(PI[playerid][pAdmin] < ADM_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");

	SpawnPlayer(playerid);
	FreezePlayer(playerid, 4000);

    SendClientMessage(playerid, COLOR_LIME, "Вы заспавнили себя");
    SendClientMessage(playerid, COLOR_LIME, "Заспавнить игрока с возможностью выбора места появления: {FFCC00}/spa");
    return 1;
}
CMD:spa(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/spa [ид игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	new string[128];
	format(string, sizeof(string), "Вы заспавнили %s [%d]", GetName(params[0]), params[0]);
	SendClientMessage(playerid, COLOR_LIME, string);
	ShowPlayerDialog(params[0], SelectSpawn, DIALOG_STYLE_LIST, "{FFCC00}Выберите спавн:", "- Вокзал\n- Дом\n- Квартира\n- База организации", "Выбрать", "Отмена");
	return 1;
}
cmd:jet(playerid,  params[])
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pAdmin] < 5) return 1;
	if(sscanf(params, "d", params[0])) return SendInf(playerid, "/jet [id игрока]");
	if(PI[params[0]][pAdmin] < 1) return SendErr(playerid, "Данный игрок не администратор");

	new string[128];
	format(string, sizeof(string), "[A] %s[%d] выдал(а) JetPack %s[%d]", GetName(playerid), playerid, GetName(params[0]), params[0]);
	SendAdminMessage(COLOR_GREY, string);

	SetPlayerSpecialAction(params[0],SPECIAL_ACTION_USEJETPACK);
	return 1;
}
CMD:g(playerid, params[]) return callcmd::goto(playerid, params);
CMD:goto(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/goto [ид игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[playerid][pAdmin] < ADM_TOP && AdminInfo[params[0]][admGoto]) return SendClientMessage(playerid, COLOR_RED, "Телепорт к этому администратору запрещён");
	else if(playerid == params[0]) return SendClientMessage(playerid, COLOR_RED, "Телепортироваться к себе - не получится");
	new Float:plocx,Float:plocy,Float:plocz;
 	GetPlayerPos(params[0], plocx, plocy, plocz);
	if(GetPlayerState(playerid) == 2) SetVehiclePos(GetPlayerVehicleID(playerid), plocx+2, plocy+2, plocz);
	else SetPlayerPos(playerid, plocx+2, plocy+2, plocz);
	SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(params[0]));
	SetPlayerInterior(playerid, GetPlayerInterior(params[0]));
	new string[128];
	if(PI[playerid][pSex] == 1) format(string, sizeof(string), "[A] %s [%d] телепортировался к %s [%d]", GetName(playerid), playerid, GetName(params[0]), params[0]);
	else format(string, sizeof(string), "[A] %s [%d] телепортировалась к %s [%d]", GetName(playerid), playerid, GetName(params[0]), params[0]);
	SendAdminMessage(COLOR_GREY, string);
	GameTextForPlayer(playerid, "~y~TELEPORT", 2000, 5);
	return 1;
}
//==============================================================================
CMD:up(playerid)
{
    new Float:plocx,Float:plocy,Float:plocz;
    if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    GetPlayerPos(playerid, plocx, plocy, plocz);
    SetPlayerPos(playerid, plocx, plocy, plocz+2);
	return 1;
}
//==============================================================================
CMD:down(playerid)
{
    new Float:plocx,Float:plocy,Float:plocz;
    if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    GetPlayerPos(playerid, plocx, plocy, plocz);
    SetPlayerPos(playerid, plocx, plocy, plocz-2);
	return 1;
}
//==============================================================================
CMD:left(playerid)
{
    new Float:plocx,Float:plocy,Float:plocz;
    if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    GetPlayerPos(playerid, plocx, plocy, plocz);
    SetPlayerPos(playerid, plocx, plocy-2, plocz);
	return 1;
}
//==============================================================================
CMD:right(playerid)
{
    new Float:plocx,Float:plocy,Float:plocz;
    if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    GetPlayerPos(playerid, plocx, plocy, plocz);
    SetPlayerPos(playerid, plocx, plocy+2, plocz);
	return 1;
}
//==============================================================================
CMD:gotocar(playerid, params[])
{
	if(PI[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "i", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/gotocar [id транспорта]");
	new Float:x, Float:y, Float:z;
	GetVehiclePos(params[0], x, y, z);
	SetPlayerPos(playerid, x+2, y+2, z);
	GameTextForPlayer(playerid, "~y~TELEPORT", 2000, 5);
	return 1;
}
//==============================================================================
CMD:getcar(playerid, params[])
{
    if(PI[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/getcar [ID Авто]");
    new Float:plocx,Float:plocy,Float:plocz;
    GetPlayerPos(playerid, plocx, plocy, plocz);
    SetVehiclePos(params[0],plocx,plocy+4, plocz);
    return true;
}
//==============================================================================
cmd:setyoutube(playerid, params[])
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
    if(IsPlayerGrandAdmin(playerid))
	{
		if(PlayerLogged[playerid] == false) return 1;
		new playername[24], admin_level;
		if(sscanf(params, "s[64]i", playername, admin_level)) return SendInf(playerid, "/setyt [ник игрока] [уровень ютубера]");
		new string[128];
		format(string, sizeof(string), "SELECT * FROM "T_YOUTUBER" WHERE `name` = '%s'", playername);
		mysql_tquery(dbHandle, string, "SetYouTuber", "isi", playerid, playername, admin_level);
	}
	return 1;
}
//==============================================================================
forward SetYouTuber(playerid, name[], level);
public SetYouTuber(playerid, name[], level)
{
	new rows, fields, string[256];
	cache_get_data(rows, fields);
	if(rows)
	{
		if(!level)
		{
			if(GetPlayerID(name) != INVALID_PLAYER_ID) PI[GetPlayerID(name)][pYouTuber] = 0;
			mysql_format(dbHandle, string, sizeof(string), "DELETE FROM "T_YOUTUBER" WHERE `name`='%s'", name);
			mysql_tquery(dbHandle, string, "", "");
			mysql_format(dbHandle, string, sizeof(string), "UPDATE "T_YOUTUBER" SET `admin` = '0' WHERE `name` = '%s'", name);
			mysql_tquery(dbHandle, string, "", "");
			format(string, sizeof(string), "Вы сняли %s с должности ютубера", name);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		else
		{
			if(GetPlayerID(name) != INVALID_PLAYER_ID) PI[GetPlayerID(name)][pYouTuber] = level;
			mysql_format(dbHandle, string, sizeof(string), "UPDATE "T_YOUTUBER" SET `level` = '%d' WHERE `name` = '%s' LIMIT 1", level, name);
			mysql_tquery(dbHandle, string, "", "");
			format(string, sizeof(string), "Вы установили уровень ютубера %s на %i", name, level);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
	}
	else
	{
		if(!level) return SendErr(playerid, "Игрок не администратор");
		new data[15];
		getdate(years, months, days);
		format(data, sizeof(data), "%02d.%02d.%04d", days, months, years);
		mysql_format(dbHandle, string, sizeof(string), "INSERT INTO "T_YOUTUBER" (`name`, `level`, `last_connect`, `put_admin`, `data`) VALUES ('%s', %d, '%s', '%s', '%s')", name, level, data, GetName(playerid), data);
		mysql_tquery(dbHandle, string, "", "");
		format(string, sizeof(string), "%s добавлен в список ютуберов. Уровень полномочий %i", name, level);
		SendClientMessage(playerid, COLOR_GREEN, string);
		if(GetPlayerID(name) != INVALID_PLAYER_ID)
		{
		    PI[GetPlayerID(name)][pYouTuber] = 1;
			format(string, sizeof(string), "%s назначил Вас ютубером", GetName(playerid));
			SendClientMessage(GetPlayerID(name), COLOR_YELLOW, string);
		}
	}
	return 1;
}
//==============================================================================
/*CMD:setadmin(playerid, params[])
{
	if(IsPlayerGrandAdmin(playerid))
	{
		if(PlayerLogged[playerid] == false) return 1;
		new playername[24], admin_level;

		if(strlen(playername) > 24)
			return SendClientMessage(playerid, COLOR_RED, "Вы ввели слишком длинный ник");

		if(sscanf(params, "s[24]i", playername, admin_level)) return SendClientMessage(playerid, COLOR_LIME, "Информация:{ffffff} /setadmin [ник игрока] [уровень админа]");
		new string[128];
		format(string, sizeof(string), "SELECT * FROM "T_ADMIN" WHERE `name` = '%s'", playername);
		mysql_tquery(dbHandle, string, "SetAdmin", "isi", playerid, playername, admin_level);
	}
	return 1;
}*/

/*CMD:fullaccess(playerid, params[])
{
	if(!IsPlayerGrandAdmin(playerid))
		return 1;

	ShowPlayerDialog
	(
		playerid, DIALOG_FULL_ACCESS, DIALOG_STYLE_LIST,
		"{FFCC00}Полный доступ",
		"{E4D122}1. {FFFFFF}Выдать полный доступ администратору\n\
		{E4D122}2. {FFFFFF}Список администраторов с полным доступом",
		"Выбрать", "Отмена"
	);

	return 1;
}*/

CMD:setadmin(playerid, params[])
{
    if(IsPlayerGrandAdmin(playerid))
	{
		if(PlayerLogged[playerid] == false) return 1;
		new playername[24], admin_level;

		if(strlen(playername) > 24)
			return SendClientMessage(playerid, COLOR_RED, "Вы ввели слишком длинный ник");

		if(sscanf(params, "s[24]i", playername, admin_level)) return SendClientMessage(playerid, COLOR_LIME, "Информация:{ffffff} /setadmin [ник игрока] [уровень админа]");
        SendClientMessage(playerid, COLOR_LIME, "7 лвл макс. Таблице {FFFFFF}'fullaccess' {99CC00}доступно {FFFFFF}/setadmin");
		new string[128];
		format(string, sizeof(string), "SELECT * FROM "T_ADMIN" WHERE `name` = '%s'", playername);
		mysql_tquery(dbHandle, string, "SetAdmin", "isii", playerid, playername, admin_level, 0);
	}
	return 1;
}

CMD:admremove(playerid, params[])
{
    if(IsPlayerGrandAdmin(playerid))
    {
		if(PI[playerid][pAdmin] < 7)
		if(sscanf(params, "i", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация:{ffffff} /admremove [id игрока]");
		else if(PI[params[0]][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "Этот игрок не является администратором");
		RemoveAdmin(params[0], GetName(params[0]));
		new string[128];
		SendMes(playerid, COLOR_GREEN, "Вы сняли %s с должности администратора", GetName(params[0]));
		format(string, sizeof(string), "[Внимание] %s [%i] снял %s с должности администратора", GetName(playerid), playerid, GetName(params[0]));
		SendAdminMessageEx(COLOR_RED, string, 5);
	}
	return 1;
}

CMD:admdown(playerid, params[])
{
    if(IsPlayerGrandAdmin(playerid))
    {
		if(sscanf(params, "i", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация:{ffffff} /admdown [id игрока]");
		else if(PI[params[0]][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "Этот игрок не является администратором");
		else if(PI[params[0]][pAdmin] > 9) return SendClientMessage(playerid, COLOR_RED, "Этот администратор не может быть понижен");
		else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Нельзя изменить свой уровень");
		new string[128];
		if(PI[params[0]][pAdmin] > 1)
		{
			PI[params[0]][pAdmin]--;
			MysqlUpdatePlayerInt(params[0], "admin", PI[params[0]][pAdmin]);
			format(string, sizeof(string), "%s понизил Ваш уровень администратора", GetName(playerid));
			SendClientMessage(params[0], COLOR_YELLOW, string);
			format(string, sizeof(string), "[A] %s [%d] понизил администратора %s [%d] до %d уровня", GetName(playerid), playerid, GetName(params[0]), params[0], PI[params[0]][pAdmin]);
			SendAdminMessageEx(COLOR_RED, string, 5);
			mysql_format(dbHandle, string, sizeof(string), "UPDATE "T_ADMIN" SET `level` = '%d' WHERE `name` = '%s' LIMIT 1", PI[params[0]][pAdmin], GetName(params[0]));
			mysql_tquery(dbHandle, string, "", "");
		}
		else if(PI[params[0]][pAdmin] == 1)
		{
			RemoveAdmin(params[0], GetName(params[0]));
			format(string, sizeof(string), "[A] %s снял %s с должности администратора", GetName(playerid), GetName(params[0]));
			SendAdminMessageEx(COLOR_RED, string, 5);
		}
	}
	return 1;
}
//==============================================================================
CMD:admup(playerid, params[])
{
    if(IsPlayerGrandAdmin(playerid))
    {
		if(sscanf(params, "i", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация:{ffffff} /admup [id игрока]");
		else if(PI[params[0]][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "Этот игрок не является администратором");
		else if(PI[params[0]][pAdmin] > 9) return SendClientMessage(playerid, COLOR_RED, "Этот администратор не может быть повышен");
		else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Нельзя изменить свой уровень");
		new string[128];
		PI[params[0]][pAdmin]++;
		MysqlUpdatePlayerInt(params[0], "admin", PI[params[0]][pAdmin]);
		format(string, sizeof(string), "%s повысил Ваш уровень администратора", GetName(playerid));
		SendClientMessage(params[0], COLOR_YELLOW, string);
		format(string, sizeof(string), "[A] %s [%d] повысил администратора %s [%d] до %d уровня", GetName(playerid), playerid, GetName(params[0]), params[0], PI[params[0]][pAdmin]);
		SendAdminMessageEx(COLOR_RED, string, 5);
		mysql_format(dbHandle, string, sizeof(string), "UPDATE "T_ADMIN" SET `level` = '%d' WHERE `name` = '%s' LIMIT 1", PI[params[0]][pAdmin], GetName(params[0]));
		mysql_tquery(dbHandle, string, "", "");
	}
	return 1;
}
//==============================================================================
CMD:gethere(playerid, params[])
{
	if(PI[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/gethere [ид игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[playerid][pAdmin] < ADM_GRAND && AdminInfo[params[0]][admGethere]) return SendClientMessage(playerid, COLOR_RED, "Телепорт этого администратора запрещён");
	new Float:plocx, Float:plocy, Float:plocz;
	GetPlayerPos(playerid, plocx, plocy, plocz);
	if(GetPlayerState(params[0]) == 2) SetVehiclePos(GetPlayerVehicleID(params[0]), plocx, plocy, plocz);
	else SetPlayerPos(params[0], plocx, plocy, plocz);
	SetPlayerVirtualWorld(params[0], GetPlayerVirtualWorld(playerid));
	SetPlayerInterior(params[0], GetPlayerInterior(playerid));
	if(InHospital[params[0]]) InHospital[params[0]] = false;
	new string[128];
	format(string, sizeof(string), "Администратор %s телепортировал Вас к себе", GetName(playerid));
	SendClientMessage(params[0], COLOR_BLUE, string);
	format(string, sizeof(string), "[A] %s [%d] телепортировал к себе %s [%d]", GetName(playerid), playerid, GetName(params[0]), params[0]);
	SendAdminMessage(COLOR_GREY, string);
	format(string, sizeof(string), "Вы телепортировали к себе %s [%d]", GetName(params[0]), params[0]);
	SendClientMessage(playerid, COLOR_LIME, string);
	return 1;
}
//==============================================================================
CMD:settime(playerid, params[])
{
	if(PI[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	{
		if(AdminLogged[playerid] == false) return SendErr(playerid, "Вы не авторизованы. Используйте {FFFFFF}/alogin");
		if(sscanf(params, "i", params[0])) return SendInf(playerid, "/settime [время]");
		else if(params[0] < 0 || params[0] > 23) return SendErr(playerid, "Время от 0 до 23!");
		SetWorldTime(params[0]);
		new string[128];
		format(string, sizeof(string), "[A] %s[%d] изменил(а) время на %i часа", GetName(playerid), playerid, params[0]);
		SendAdminMessage(COLOR_GREY, string);
	}
	return 1;
}
//==============================================================================
CMD:weather(playerid, params[])
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pAdmin] < 5) return 1;
	else if(AdminLogged[playerid] == false) return SendErr(playerid, "Вы не авторизованы. Используйте {f1c40f}/alogin");
	ShowPlayerDialogEx(playerid, D_WEATHER, 2, "{3498db}>> Погода", "\
		1. Разные версии синих небес/облаков\n\
		2. Разные версии синих небес/облаков\n\
		3. Разные версии синих небес/облаков\n\
		4. Разные версии синих небес/облаков\n\
		5. Разные версии синих небес/облаков\n\
		6. Разные версии синих небес/облаков\n\
		7. Разные версии синих небес/облаков\n\
		8. Гроза\n\
		9. Пасмурно и туман\n\
		10. Ясное синее небо\
	", "Принять", "Отмена");
	return 1;
}
//==============================================================================
CMD:msg(playerid, params[])
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pAdmin] < 3) return 1;
	//else if(AdminLogged[playerid] == false) return SendErr(playerid, "Вы не авторизованы. Используйте {f1c40f}/alogin");
	else if(isnull(params)) return SendInf(playerid, "/msg [текст]");
	else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SendErr(playerid, "Вы слишком часто пытаетесь отправить сообщение");
	new string[128];
	format(string, sizeof(string), "Администратор %s[%d]: %s", GetName(playerid), playerid, params[0]);
	SendClientMessageToAll(0xFFCC00FF, string);
	SetString(OldMessage[playerid], params[0]);
	TextReset[playerid] = gettime()+3;
	return 1;
}
//==============================================================================
CMD:mostup(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	MoveObject(Most1,2747.3701, -1142.8600, 21.5900, 0.1, 60.00, 0.00, 180.00);
	MoveObject(Most2,2747.3701, -1261.9200, 21.5900, 0.1, 60.00, 0.00, 0.00);
	SendClientMessageToAll(0xFFCC00FF,"Осторожно, поднимается мост в г. Южный!");
	return 1;
}
//==============================================================================
CMD:mostdown(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	MoveObject(Most1,2747.3711, -1142.8318, 21.5900, 0.1, 0, 0, 180.0);
	MoveObject(Most2,2747.3701, -1261.9200, 21.5900, 0.1, 0, 0, 0);
	SendClientMessageToAll(0xFFCC00FF,"Осторожно, опускается мост в г. Южный!");
	return 1;
}
//==============================================================================
CMD:mpsay(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/mpsay [текст]");
	else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SendClientMessage(playerid,COLOR_RED, "Не флудите");
	new string[128];
	format(string, sizeof(string), "МП | Администратор %s: %s", GetName(playerid), params[0]);
 	SendClientMessageToAll(0x0099FFAA, string);
 	SetString(OldMessage[playerid], params[0]);
	TextReset[playerid] = gettime()+3;
 	SendLog("MsgLog",string);
	return 1;
}
//==============================================================================
CMD:hstats(playerid)
{
	if(PI[playerid][pAdmin] < ADM_SUPER_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");

    new fmt_dialog[120];

	format
	(
		fmt_dialog, sizeof fmt_dialog,
		"{FFFFFF}Свободно квартир: {FFCC00}%d\n\
		{FFFFFF}Свободно домов: {FFCC00}%d",
		TotalFreeApartments,
		TotalFreeHouses
	);

	ShowPlayerDialog
	(
		playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX,
		"{99CC00}Статистика домов",
		fmt_dialog,
		"Закрыть", ""
	);

	return 1;
}
//==============================================================================
CMD:a(playerid,params[])
{
	if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/a [текст]");
	else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SendClientMessage(playerid, COLOR_RED, "Не флудите");
	new string[128];
	format(string, sizeof(string), "[ADM-CHAT]{FFFFFF} %s[%d]: %s", GetName(playerid), playerid, params[0]);
	SendAdminMessage(COLOR_SERVER, string);
	SetString(OldMessage[playerid], params[0]);
	TextReset[playerid] = gettime()+3;
	return 1;
}
//==============================================================================
cmd:ya(playerid,params[])
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pYouTuber] < 1) return 1;
	else if(isnull(params)) return SendInf(playerid, "/ya [текст]");
	else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SendErr(playerid, "Вы слишком часто пытаетесь отправить сообщение");
	new string[128];
	format(string, sizeof(string), "[Y] %s[%d]: %s", GetName(playerid), playerid, params[0]);
	SendYouTuberMessage(COLOR_YT, string);
	SetString(OldMessage[playerid], params[0]);
	TextReset[playerid] = gettime()+3;
	return 1;
}
//==============================================================================
cmd:b(playerid, params[]) return callcmd::n(playerid, params);
cmd:n(playerid, params[])
{
	if(PI[playerid][pMuted] > 0) return SendErr(playerid, "У вас бан чата. {FFFFFF}(/time)");
	else if(isnull(params)) return SendInf(playerid, "/n [текст]");
	else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SendErr(playerid, "Вы слишком часто пытаетесь отправить сообщение");
	else if(IsIpFound(params[0]) || CheckString(params[0])) return PlayerGetsChatBan(playerid, params[0]);
	new string[128];
	format(string, sizeof(string), "(( %s[%i]: %s ))", GetName(playerid), playerid, params);
	ProxDetector(20.0, playerid, string, 0xCCCC99FF, 0xCCCC99FF, 0xCCCC99FF, 0xCCCC99FF, 0xCCCC99FF);
	SetPlayerChatBubble(playerid, params, 0xCCCC99FF, 20.0, 7000);
	SetString(OldMessage[playerid], params[0]);
	TextReset[playerid] = gettime()+3;
	return 1;
}
//==============================================================================
CMD:s(playerid, params[])
{
    if(PI[playerid][pTime] < 0) return SendClientMessage(playerid, COLOR_RED, "Вы должны играть на сервере более 1 часа!");
	else if(PI[playerid][pMuted] > 0) return SendClientMessage(playerid, 0xff6600AA, "У Вас затычка. Узнать подробней: /time");
	else if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/s [текст]");
	else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SendClientMessage(playerid,COLOR_RED, "Не флудите!");
	else if(IsIpFound(params[0]) || CheckString(params[0])) return PlayerGetsChatBan(playerid, params[0]);
	new string[128];
	format(string, sizeof(string), "- %s[%d] кричит: %s", GetName(playerid), playerid, params[0]);
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) ApplyAnimation(playerid,"RIOT","RIOT_shout",4.1,0,0,0,0,1);
	foreach(new i: Player)
	{
		if(!IsPlayerConnected(i)) continue;
		new Float:rdist, c;
		rdist = GetPlayerDistanceToPlayer(playerid, i);
		if(!PlayerLogged[i] || rdist > 13.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(i)) continue;
		switch(floatround(rdist))
		{
			case 0..3: c = 0xFFFFFFFF;
			case 4..8: c = 0xCCCCCCFF;
			case 9..13: c = 0xAAAAAAFF;
			default: c = 0x888888FF;
		}
		SendClientMessage(i, c, string);
	}
	SetString(OldMessage[playerid], params[0]);
	TextReset[playerid] = gettime()+3;
	return 1;
}
//==============================================================================
CMD:gov(playerid, params[])
{
	if(!IsTheMember(PI[playerid][pMember])) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(PI[playerid][pMuted] > 0) return SendClientMessage(playerid, 0xff6600AA, "У Вас затычка. Узнать подробней: /time");
	else if(PI[playerid][pGovMute] > 0) return SendClientMessage(playerid, 0xff6600AA, "У Вас имеется ограничение на подачу гос. новостей");
	else if(!IsAbleToGosNewsRank(playerid)) return SendClientMessage(playerid, COLOR_RED, "Канал гос. новостей не доступен для Вас!");
	else if(sscanf(params, "s[128]", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/gov [текст]");
	else if(IsIpFound(params[0]) || CheckString(params[0])) return PlayerGetsChatBan(playerid, params[0]);
	new string[128];
	format(string, sizeof(string), "[Государственные новости]: {FFFFFF}%s", params[0]);
//	format(string, sizeof(string), "[Государственные новости]: {FFFFFF}%s [%d]: %s", GetName(playerid), playerid, params[0]);
	SendClientMessageToAll(0x4466CCFF, string);
	return 1;
}
//==============================================================================
CMD:ans(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "us[128]", params[0],params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/ans [ид игрока] [текст]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	new string[228];
	format(string, sizeof(string), "Администратор %s [%d] для %s [%d]: %s", PI[playerid][pName],playerid,PI[params[0]][pName],params[0], params[1]);
	SendClientMessage(params[0], 0xFF9945FF, string);
	format(string, sizeof(string), "Администратор %s [%d] для %s [%d]: %s", PI[playerid][pName],playerid,PI[params[0]][pName],params[0], params[1]);
	SendAdminMessage(0xFF9945FF, string);
	format(string, sizeof(string), "Ответ от администратора: %s[%d]: %s", PI[playerid][pName],playerid, params[1]);
	SendClientMessage(playerid,0xFF9945FF, string);
	
	
	SetPVarInt(params[0], "AnsReport", 1);
	SetPVarString(params[0], "AnsReportText", params[1]);
	TextDrawShowForPlayer(params[0], TDmessage);
	SendClientMessage(params[0],-1,"У вас новое уведомление! Для скрытие введите: {FF00FF} /uved");
	PI[playerid][pCREPORT] ++;
	return 1;
}
CMD:uved(playerid)
{
	if(GetPVarInt(playerid, "AnsReport") != 1) return SendClientMessage(playerid, COLOR_RED, "У вас нет уведомлений");
	new string[228], otvet[199];
	GetPVarString(playerid, "AnsReportText", otvet, sizeof otvet);
	format(string, sizeof(string), "Ответ от администрации: %s",otvet);
	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFA500}Ответ от администрации", string, "Хорошо", "");
	TextDrawHideForPlayer(playerid, TDmessage);
	DeletePVar(playerid, "AnsReportText");
	DeletePVar(playerid, "AnsReport");
	return 1;
}
/*CMD:ansp(playerid, params[])
{
	if(PI[playerid][pSupports] != 1) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "us[128]", params[0],params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/ansp [ид игрока] [текст]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	new string[228];
	format(string, sizeof(string), "Агент поддержки %s [%d] для %s [%d]: %s", PI[playerid][pName],playerid,PI[params[0]][pName],params[0], params[1]);
	SendClientMessage(params[0], 0xFF9945FF, string);
	format(string, sizeof(string), "Агент поддержки %s [%d] для %s [%d]: %s", PI[playerid][pName],playerid,PI[params[0]][pName],params[0], params[1]);
	SendAdminMessage(0xFF9945FF, string);
	PI[playerid][pCREPORT] ++;
	return 1;
}*/
//==============================================================================
cmd:check(playerid, params[])
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pAdmin] < 1) return 1;
	//else if(AdminLogged[playerid] == false) return SendErr(playerid, "Вы не авторизованы. Используйте {3399FF}/alogin");
	else if(sscanf(params, "u", params[0])) return SendInf(playerid, "/check [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendErr(playerid, "Игрок не в игре");
	else if(PlayerLogged[params[0]] == false) return SendErr(playerid, "Игрок не авторизован");
	ShowPlayerStatsDialog(playerid, params[0]);
	return 1;
}
CMD:mparm(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_ADMIN) return 1;
	new arm;
	if(sscanf(params, "udS()[32]", arm)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/mparm(our) [кол-во брони]");
	new Float:PlayerPos[3];
	GetPlayerPos(playerid, PlayerPos[0], PlayerPos[1], PlayerPos[2]);
	foreach(new i:Player)
	{
		if(PlayerToPoint(10.0, i, PlayerPos[0], PlayerPos[1], PlayerPos[2]))
	{
		SetArmour(i, arm);
	}
	}
	return 1;
}
CMD:mphp(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_ADMIN) return 1;
	new hp;
	if(sscanf(params, "udS()[32]", hp)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/mphp [кол-во ХП]");
	new Float:PlayerPos[3];
	GetPlayerPos(playerid, PlayerPos[0], PlayerPos[1], PlayerPos[2]);
	foreach(new i:Player)
    {
		if(PlayerToPoint(10.0, i, PlayerPos[0], PlayerPos[1], PlayerPos[2]))
    {
		SetHealth(i, hp);
	}
	}
    return 1;
}
CMD:mpskin(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_ADMIN) return 1;
	if(sscanf(params, "udS()[32]", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/mpskin [номер команды] [скин]");
	if(params[1] > 297) return true;
	new team_1[250],team_2[250], all, team1, team2, string[128];
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid, x,y,z);
   	foreach(new i: Player)
	{
	    if(i == playerid) continue;
		if(!IsPlayerConnected(i)) continue;
		if(PlayerToPoint(10.0, i, x,y,z))
		{
			all++;
			if(params[0] == 3)
			{
			    SetPlayerSkin(i,params[1]);
				format(string, sizeof(string), "Мероприятие (ООС): Люди на МП получили %i скин", params[1]);
			    SendClientMessage(playerid, COLOR_YELLOW, string);
			    continue;
			}
			if(params[0] == 2 && all%2 == 0)
			{
			    team2++;
				team_2[team2] = i;
				SetPlayerSkin(i,params[1]);
			    format(string, sizeof(string), "Мероприятие (ООС): Люди на МП получили %i скин", params[1]);
			    SendClientMessage(playerid, COLOR_YELLOW, string);
				continue;
			}
			if(params[0] == 1 && all%2 == 1)
			{
			    team1++;
			    team_1[team1] = i;
			    SetPlayerSkin(i,params[1]);
				format(string, sizeof(string), "Мероприятие (ООС): Люди на МП получили %i скин", params[1]);
			    SendClientMessage(playerid, COLOR_YELLOW, string);
			    continue;
			}
			if(params[0] < 1 || params[0] > 3)
			{
			    SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/mpskin [номер команды] [скин]");
			    break;
			}
		}
   	}
    return true;
}
CMD:mphere(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_ADMIN) return 1;
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid, x,y,z);
	foreach(new i: Player)
	{
		if(i == playerid) continue;
		if(!IsPlayerConnected(i)) continue;
		if(PlayerToPoint(100.0, i, x,y,z))
		{
			SetPlayerPos(i, x-5,y,z);
		}
	}
	return true;
}
CMD:mpgun(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_ADMIN) return 1;
	if(sscanf(params, "ddd", params[0], params[1], params[2])) return SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/mpgun [номер команды] [номер оружия] [кол-во пт]");
  	else if(params[1] > 47 || params[1] < 1) return SendClientMessage(playerid, COLOR_RED,"Такого оружия не существует!");
    else if(params[2] > 1000 || params[2] < 1) return SendClientMessage(playerid, COLOR_RED,"Неверное количество патрон!");

	new team_1[250],team_2[250], all, team1, team2;
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid, x,y,z);

	foreach(new i: Player)
	{
		if(i == playerid) continue;
		if(!IsPlayerConnected(i)) continue;
		if(PlayerToPoint(100.0, i, x,y,z))
		{
		    all++;
            if(params[0] == 3)
			{
			    GivePlayerWeaponAC(i,params[1], params[2]);
			    continue;
			}
            if(params[0] == 2 && all%2 == 0)
            {
                team2++;
            	team_2[team2] = i;
            	GivePlayerWeaponAC(i,params[1], params[2]);
            	continue;
			}
			if(params[0] == 1 && all%2 == 1)
			{
			    team1++;
				team_1[team1] = i;
			    GivePlayerWeaponAC(i,params[1], params[2]);
			    continue;
			}
			if(params[0] < 1 || params[0] > 2)
			{
			    SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/mpgun [номер команды] [номер оружия] [кол-во пт]");
			    break;
			}
		}
   	}
	
	return 1;
}
//==============================================================================
CMD:freeze(playerid, params[])
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pAdmin] < 3) return 1;
	//else if(AdminLogged[playerid] == false) return SendErr(playerid, "Вы не авторизованы. Используйте {FFFFFF}/alogin");
	if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, -1, "Введите: /freeze [id игрока] [время (мин)]");
	else if(!IsPlayerConnected(params[0])) return SendErr(playerid, "Игрок не в игре");
	else if(PlayerLogged[params[0]] == false) return SendErr(playerid, "Игрок не авторизован");
	new string[128];
	format(string, sizeof(string), "[A] %s [%i] заморозил %s [%d] на %d мин", GetName(playerid), playerid, GetName(params[0]), params[0], params[1]);
	SendAdminMessage(COLOR_GREY, string);
	format(string, sizeof(string), "Администратор %s заморозил Вас на %d мин", GetName(playerid), params[1]);
	SendClientMessage(params[0], COLOR_BLUE, string);

	TogglePlayerControllable(params[0], 0);
	SetTimerEx("UnFreezePlayer2", 60000*params[1], false, "i", params[0]);
	return true;
}
//==============================================================================
forward UnFreezePlayer2(playerid);
public UnFreezePlayer2(playerid)
{
    TogglePlayerControllable(playerid, true);
    return true;
}
//==============================================================================
cmd:unfreeze(playerid, params[])
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pAdmin] < 3) return 1;
	//else if(AdminLogged[playerid] == false) return SendErr(playerid, "Вы не авторизованы. Используйте {FFFFFF}/alogin");
	else if(sscanf(params, "u", params[0])) return SendInf(playerid, "/unfreeze [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendErr(playerid, "Игрок не в игре");
	else if(PlayerLogged[params[0]] == false) return SendErr(playerid, "Игрок не авторизован");
	//lse if(FreezePlayer1[params[0]] == false) return SendErr(playerid, "Этот игрок не заморожен");
	new string[128];
	format(string, sizeof(string), "[A] %s[%i] разморозил(а) %s[%d]", GetName(playerid), playerid, GetName(params[0]), params[0]);
	SendAdminMessage(COLOR_GREY, string);
	format(string, sizeof(string), "Администратор %s разморозил(а) Вас", GetName(playerid));
	SendClientMessage(params[0], COLOR_BLUE, string);
	TogglePlayerControllable(params[0], 1);
	SetTimerEx("UnFreezePlayer2", 50, false, "i", params[0]);
//	FreezePlayer1[params[0]] = false;
	return 1;
}
//==============================================================================
CMD:kick(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "uS()[32]", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/kick [ид игрока] [причина]");
	else if(!IsPlayerConnected(params[0]) || params[0] == INVALID_PLAYER_ID || params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
   	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
    else if(PI[playerid][pAdmin] <= PI[params[0]][pAdmin]) return AttemptRemoveAdmin(playerid);
    else if(IsIpFound(params[1]) || CheckString(params[1])) return AdminAntisliv(playerid, params[1]);
    new string[128];
    if(PI[playerid][pSex] == 1) format(string, sizeof(string), "Администратор %s кикнул игрока %s. Причина: %s", GetName(playerid), GetName(params[0]), params[1]);
    else format(string, sizeof(string), "Администратор %s кикнула игрока %s. Причина: %s", GetName(playerid), GetName(params[0]), params[1]);
	SendAdminMessageToAll(COLOR_RED, string);
	SendLog("Kick",string);
	Kick(params[0]);
	PI[playerid][pCKICK] ++;
	return 1;
}

CMD:skick(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/skick [ид игрока]");
	else if(!IsPlayerConnected(params[0]) || params[0] == INVALID_PLAYER_ID || params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	if(PI[playerid][pAdmin] <= PI[params[0]][pAdmin]) return AttemptRemoveAdmin(playerid);
	new string[128];
	format(string, sizeof(string), "[A] %s [%d] кикнул игрока %s [%d] без лишнего шума", GetName(playerid), playerid, GetName(params[0]), params[0]);
	SendAdminMessage(COLOR_GREY, string);
	SendLog("Skick", string);
	Kick(params[0]);
	PI[playerid][pCKICK] ++;
	return 1;
}

CMD:stat(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/stat [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	ShowPlayerStatsDialog(playerid, params[0]);
	return 1;
}

CMD:setstat(playerid, params[])
{
    if(PI[playerid][pAdmin] < 7) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	{
		if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/setstat [ид игрока]");
		else if(!IsPlayerConnected(params[0])) return SCM(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[params[0]] == false) return SCM(playerid, COLOR_RED, "Игрок не ввел пароль!");
		NameStats[playerid] = params[0];
		ShowPlayerDialog(playerid, D_UCPADMIN, DIALOG_STYLE_LIST, GetName(params[0]), "Ник\nУровень\nОпыт\nПол\nУровень дальнобойщика", "Принять", "Отмена");
	}
	return 1;
}

CMD:sban(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "ids[32]", params[0], params[1], params[2])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/sban [id игрока] [кол-во дней] [причина]");
	else if(!IsPlayerConnected(params[0]) || params[0] == INVALID_PLAYER_ID || params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
    else if(PI[playerid][pAdmin] <= PI[params[0]][pAdmin]) return AttemptRemoveAdmin(playerid);
    else if(IsIpFound(params[2]) || CheckString(params[2])) return AdminAntisliv(playerid, params[2]);
	else if(params[1] > 30 || params[1] < 1) return SendClientMessage(playerid, COLOR_RED, "Количество дней от 1 до 30!");
	new string[128];
	format(string, sizeof(string), "[A] %s [%d] тихо забанил игрока %s на %d дней. Причина: %s", GetName(playerid), playerid, GetName(params[0]),params[1], params[2]);
	SendAdminMessage(COLOR_GREY,string);
	new data[15], unbandate;
	getdate(years, months, days);
	unbandate = gettime() + params[1]*86400;
	format(data, sizeof(data), "%02d.%02d.%04d", days, months, years);
	format(query, sizeof(query), "INSERT INTO bans (name, whobanned, ip, bandate, time, unbandate, reason) VALUES ('%s', '%s', '%s', '%s', %d, %d, '%s')", GetName(params[0]), GetName(playerid), PI[params[0]][pIP], data, params[1], unbandate, params[2]);
	mysql_tquery(dbHandle, query, "", "");
	Kick(params[0]);
	return 1;
}

cmd:getip(playerid, params[])
{
	//new gownogol[90];
	/*if(PI[playerid][pAccep] == 0)
	{
		SendClientMessage(playerid,COLOR_RED,"Наблюдается попытка взлома!");
		format(gownogol,sizeof(gownogol),"-[G-GUARD] %s подозревается во зломе, проверьте его и авторизируйте /acceptadmin [5 lvl]", GetName(playerid));
		SendAdminMessage(COLOR_RED,gownogol);
		return false;
	}*/
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pAdmin] < 3) return 1;
	//else if(AdminLogged[playerid] == false) return SendErr(playerid, "Вы не авторизованы. Используйте {3399FF}/alogin");
	else if(sscanf(params, "u", params[0])) return SendInf(playerid, "/getip [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendErr(playerid, "Игрок не в игре");
	//else if(GetString(GetName(playerid), NGA1)) return SendErr(playerid, "Нельзя просмотреть IP данного администратора!");

	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "[%s] [IP: %s]-[RegIP: %s]-[LastIP: %s]", GetName(params[0]),PI[params[0]][pIP],PI[params[0]][pRegIP],PI[params[0]][pLastIP]);
	SendClientMessage(playerid, COLOR_YELLOW, STRING_GLOBAL);
	return 1;
}

cmd:allheal(playerid)
{
	if(PI[playerid][pAdmin] >= 3)
	{
		for(new i; i<MAX_PLAYERS; i++)
		{
			SetPlayerHealth(i,100);
			SendClientMessage(i,COLOR_BLUE,"Администратор всех вылечил");
		}
	}
	return 1;
}

CMD:pgetip(playerid,params[])
{
	//new gownogol[90];
	/*if(PI[playerid][pAccep] == 0)
	{
		SendClientMessage(playerid,COLOR_RED,"Наблюдается попытка взлома!");
		format(gownogol,sizeof(gownogol),"-[G-GUARD] %s подозревается во зломе, проверьте его и авторизируйте /acceptadmin [5 lvl]", GetName(playerid));
		SendAdminMessage(COLOR_RED,gownogol);
		return false;
	}*/
	if(PI[playerid][pAdmin] < 3) return 1;
	if(sscanf(params,"s[60]",params[0])) return SendInf(playerid, "/pgetip [ip]");

	STRING_GLOBAL = "";
	format(STRING_GLOBAL, 300, "SELECT `name` FROM `accounts` WHERE `ip` = '%s'", params[0]);
	mysql_tquery(dbHandle, STRING_GLOBAL, "p_get_ip", "i", playerid);

	return 1;
}

forward p_get_ip(playerid);
public p_get_ip(playerid)
{
	new rows, fields;
	cache_get_data(rows, fields);

	if(rows)
	{
		new name[MAX_PLAYER_NAME+1];
		for(new i = 0; i < rows; i++)
		{
			cache_get_row(i, 3, name, dbHandle, MAX_PLAYER_NAME);
			format(STRING_GLOBAL, 128, "%i. %s", i+1, name);
			SendInf(playerid, STRING_GLOBAL);
		}
	}
	else SendErr(playerid, "IP адресов по Вашему запросу не найдено");

	return 1;
}

cmd:hgps(playerid)
{
	if(GetPlayerHouse(playerid) == 0) return SendErr(playerid, "Вы не владеете домом");
	for(new i = TOTALHOUSE; i > 0; i --)
	{
		if(strcmp(GetName(playerid),HouseInfo[i][hOwner], true) == 0)
		{
			SetPlayerRaceCheckpoint(playerid,1, HouseInfo[i][hEntrx],HouseInfo[i][hEntry],HouseInfo[i][hEntrz],0.0,0.0,0.0, 4.0);
			SendClientMessage(playerid, COLOR_WHITE, "Ваш дом обозначен на карте {FF6347}красной меткой");
			SetPVarInt(playerid, "Home", 1);
		}
	}
	return 1;
}

CMD:saveacc(playerid, params[])
{
	if(PI[playerid][pAdmin] < 7) return 1;
	SaveAcc();
	SCM(playerid, COLOR_RED, "Вы успешно сохранили все аккаунты");
	new string[128];
	format(string, sizeof(string), "[A] Разработчик %s [%d] сделал сохранение всех аккаунтов", GetName(playerid), playerid);
	SendAdminMessage(COLOR_GREY, string);
	return 1;
}
CMD:setorg(playerid)
{
    if(PI[playerid][pAdmin] < 5) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	Dialog(playerid,1984,DSL,"{FFCC00}Список организаций","{FFCC00}1. {ffffff}Армия\n{FFCC00}2. {ffffff}ОПГ ''Ореховское\n{FFCC00}3. {ffffff}ОПГ Южное","Выбрать","Закрыть");
	return 1;
}
CMD:hclose(playerid)
{
    new a = GetPVarInt(playerid, "PlayerHouse");
	if(GetPlayerHouse(playerid) == 0) return SendClientMessage(playerid, COLOR_RED, "У Вас нет дома!");

	if(IsPlayerInRangeOfPoint(playerid, 15.0, HouseInfo[a][hEntrx], HouseInfo[a][hEntrz], HouseInfo[a][hEntrz]) || IsPlayerInRangeOfPoint(playerid, 15.0, HouseInfo[a][hEntrx], HouseInfo[a][hEntry], HouseInfo[a][hEntrz]))
	{
		HouseInfo[a][hLock] = 1;
		GameTextForPlayer(playerid, "~w~ДОМ ~r~ЗАКРЫТ", 2000, 5);
	}
	return 1;
}
CMD:hopen(playerid)
{
    new a = GetPVarInt(playerid, "PlayerHouse");
	if(GetPlayerHouse(playerid) == 0) return SendClientMessage(playerid, COLOR_RED, "У Вас нет дома!");
	
	if(IsPlayerInRangeOfPoint(playerid, 15.0, HouseInfo[a][hEntrx], HouseInfo[a][hEntrz], HouseInfo[a][hEntrz]) || IsPlayerInRangeOfPoint(playerid, 15.0, HouseInfo[a][hEntrx], HouseInfo[a][hEntry], HouseInfo[a][hEntrz]))
	{
		HouseInfo[a][hLock] = 0;
		GameTextForPlayer(playerid, "~w~ДОМ ~r~ОТКРЫТ", 2000, 5);
	}
	return 1;
}
CMD:openvdv(playerid)
{
    if(PI[playerid][pMember] == TEAM_VDV && PI[playerid][pRank] >= 4 && IsPlayerInRangeOfPoint(playerid, 10.0, 1891.0800, 1722.3900, 16.2200))
	{
		if(ope == 1)
		{
	    	MoveDynamicObject(openvdv, 1891.0800, 1722.3900, 16.2200, 1, 0.0000, 0.0000, -90.0000);
	    	ope = 0;
	    	SCM(playerid,COLOR_RED,"Вы закрыли ворота");
	    	SetPlayerChatBubble(playerid,"Закрывает ворота",COLOR_RED,30.0,10000);
		}
		else
		{
		    MoveDynamicObject(openvdv, 1891.0800, 1733.5000, 16.2200, 1, 0.0000, 0.0000, -90.0000);
		    ope = 1;
		    SCM(playerid,COLOR_LIME,"Вы открыли ворота");
		    SetPlayerChatBubble(playerid,"Открывает ворота",COLOR_LIME,30.0,10000);
		}
	}
	return 1;
}
/*CMD:open(playerid)
{
	if(!IsAMafia(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(!IsPlayerInRangeOfPoint(playerid, 10.0, 1900.79, 2157.29, 15.19)) return 1;
	if(status_slak == 0)
    {
		MoveObject(policeobject_slak, 1900.79, 2157.29, 15.19, 0.004, 0.00, 4.00, -91.00);
		status_slak = 1;
		SendClientMessage(playerid, COLOR_LIME, "Вы открыли шлагбаум");
    }
	else if(status_slak == 1)
	{
		MoveObject(policeobject_slak, 1900.79, 2157.29, 15.19, 0.004, 0.00, 88.00, -91.00);
		status_slak = 0;
		SendClientMessage(playerid, COLOR_RED, "Вы закрыли шлагбаум");
    }
   	return 1;
}*/
//==============================================================================
CMD:ban(playerid, params[])
{
	if(PI[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(sscanf(params, "udS()[32]", params[0], params[1], params[2])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/ban [id игрока] [количество дней] [причина]");
	else if(!IsPlayerConnected(params[0]) || params[0] == INVALID_PLAYER_ID || params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(params[1] > 30 || params[1] < 1) return SendClientMessage(playerid, COLOR_RED, "Количество дней от 1 до 30!");
	else if(PI[playerid][pAdmin] <= PI[params[0]][pAdmin]) return AttemptRemoveAdmin(playerid);
	else if(IsIpFound(params[2]) || CheckString(params[2])) return AdminAntisliv(playerid, params[2]);
	PI[params[0]][pSpawnChange] = 0;
	new string[128];
	if(PI[playerid][pSex] == 1) format(string, sizeof(string), "Администратор %s забанил игрока %s на %d дней. Причина: %s", GetName(playerid), GetName(params[0]), params[1], params[2]);
    else format(string, sizeof(string), "Администратор %s забанила игрока %s на %d дней. Причина: %s", GetName(playerid), GetName(params[0]), params[1], params[2]);
	SendAdminMessageToAll(COLOR_RED, string);
	format(string, sizeof(string), "- %s [%d] | IP: %s | L-IP: %s | R-IP: %s",PI[params[0]][pName],  params[0],PI[params[0]][pIP],PI[params[0]][pLastIP],PI[params[0]][pRegIP]);
	SendAdminMessage(COLOR_RED,string);
	new data[15], unbandate;
	getdate(years, months, days);
	unbandate = gettime() + params[1]*86400;
	format(data, sizeof(data), "%02d.%02d.%04d", days, months, years);
	format(query, sizeof(query), "INSERT INTO bans (name, whobanned, ip, bandate, time, unbandate, reason) VALUES ('%s', '%s', '%s', '%s', %d, %d, '%s')", GetName(params[0]), GetName(playerid), PI[params[0]][pIP], data, params[1], unbandate, params[2]);
	mysql_tquery(dbHandle, query, "", "");
	ResetPlayerWeaponsAC(params[0]);
	Kick(params[0]);
	PI[playerid][pCBAN] ++;
	return 1;
}
//==============================================================================
CMD:iban(playerid, params[])
{
	if(PI[playerid][pAdmin] < 4) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(sscanf(params, "udS()[32]", params[0], params[2])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/iban [id игрока] [причина]");
	else if(!IsPlayerConnected(params[0]) || params[0] == INVALID_PLAYER_ID || params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[playerid][pAdmin] <= PI[params[0]][pAdmin]) return AttemptRemoveAdmin(playerid);
	else if(IsIpFound(params[2]) || CheckString(params[2])) return AdminAntisliv(playerid, params[2]);
	PI[params[0]][pSpawnChange] = 0;
	new string[128];
	format(string, sizeof(string), "[A] %s [%d] забанил игрока %s [%d] навсегда. Причина: %s", GetName(playerid), playerid, GetName(params[0]), params[0], params[2]);
	SendAdminMessage(COLOR_BLUE,string);
	format(string, sizeof(string), "[A] - Ник: %s | IP: %s | L-IP: %s | R-IP: %s",PI[params[0]][pName],PI[params[0]][pIP],PI[params[0]][pLastIP],PI[params[0]][pRegIP]);
	SendAdminMessage(COLOR_BLUE,string);
	new data[15], unbandate;
	getdate(years, months, days);
	unbandate = gettime() + 86400*999;
	format(data, sizeof(data), "%02d.%02d.%04d", days, months, years);
	format(query, sizeof(query), "INSERT INTO bans (name, whobanned, ip, bandate, time, unbandate, reason) VALUES ('%s', '%s', '%s', '%s', %d, %d, '%s')", GetName(params[0]), GetName(playerid), PI[params[0]][pIP], data, params[1], unbandate, params[2]);
	mysql_tquery(dbHandle, query, "", "");
	format(string, sizeof(string), "Руководитель %s [%d] забанил Ваш аккаунт навсегда. Причина: %s", GetName(playerid), playerid, params[2]);
	SendClientMessage(params[0], COLOR_REDD, string);
	Kick(params[0]);
	PI[playerid][pCBAN] ++;
	return 1;
}
//==============================================================================
CMD:cmd(playerid, params[])
{ 
	if(!IsPlayerGrandAdmin(playerid))
		return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
					
	if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(sscanf(params, "ds[90]", params[0], params[1],params[2])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/cmd [ид игрока] [команда] [текст]");
	new mess[100];format(mess, sizeof(mess), "%s", params[1]);CallLocalFunction("OnPlayerCommandText", "is", params[0], mess);
	return 1;
}
//==============================================================================
forward ActivateAccount(playerid, name[]);
public ActivateAccount(playerid, name[])
{
	new r, f;
	cache_get_data(r, f);
	if(!r) return SendErr(playerid, "Аккаунт этого игрока не деактивирован или его нет в базе данных");

	STRING_GLOBAL[0] = EOS;
	mysql_format(dbHandle, STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_ACCOUNTS" SET `deactivate` = '0' WHERE `name` = '%s'", name);
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");

	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, 128, "[{0099FF}A{999999}] Администратор %s активировал аккаунт игрока %s", GetName(playerid), name);
	SendAdminMessage(COLOR_ADMIN, STRING_GLOBAL);
	return 1;
}
stock SaveSalary()
{
	new String[200];
	for(new A; A != 18; A++)
	{
	    //if(A >= 4 && A <= 7 || A >= 16 && A <= 18) continue;
		format(String, sizeof(String), "UPDATE `salary` SET `Salary` = '%d' WHERE `Organise` = '%d'", SalaryStatus[A], A);
		mysql_tquery(dbHandle, String, "", "");
	}
	for(new A; A != 44; A++)
	{
		format(String, sizeof(String), "UPDATE `work_salary` SET `Salary` = '%d' WHERE `Work` = '%d'", WorkSalary[A], A);
		mysql_tquery(dbHandle, String, "", "");
	}
	return 1;
}
forward LoadSalary();
public LoadSalary()
{
    new Rows, Fields;
    cache_get_data(Rows, Fields);
    for(new A; A != Rows; A++)
	{
 		new LoadOrganise = cache_get_field_content_int(A, "Organise");
   		SalaryStatus[LoadOrganise] = cache_get_field_content_int(A, "Salary");
	}
	return 1;
}

forward LoadWorkSalary();
public LoadWorkSalary()
{
    new Rows, Fields;
    cache_get_data(Rows, Fields);
    for(new A; A != Rows; A++)
	{
 		new LoadWork = cache_get_field_content_int(A, "Work");
   		WorkSalary[LoadWork] = cache_get_field_content_int(A, "Salary");
	}
	return 1;
}
CMD:offwarn(playerid, params[])
{
	if(PI[playerid][pAdmin] < 4) return 1;
	//else if(AdminLogged[playerid] == false) return SendMess(playerid, MSG_YOU_NOT_LOGGED_AS_ADMIN);
	new playername[MAX_PLAYER_NAME], reason[32];
	if(sscanf(params, "s[60]s[60]", playername, reason)) return SendClientMessage(playerid, 0x99CC00FF, "Информация: {FFFFFF}/offwarn [ник игрока] [причина]");
	//else if(CheckExceptionName(playername)) return AttemptRemoveChiefAdmin(playerid);
	//else if(IsIpFound(reason) || CheckString(reason)) return AdminAntisliv(playerid, reason);
	else if(GetPlayerID(playername) != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "Игрок в сети, используйте команду /warn");

	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "SELECT * FROM "T_ACCOUNTS" WHERE `name`='%s'", playername);
	mysql_tquery(dbHandle, STRING_GLOBAL, "OnPlayerOffwarn", "iss", playerid, playername, reason);

	//ServerProtection(playerid);
	return 1;
}
//==============================================================================
CMD:warn(playerid, params[])
{
	if(PI[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "us", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/warn [ID игрока] [Причина]");
	else if(!IsPlayerConnected(params[0]) || params[0] == INVALID_PLAYER_ID || params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[playerid][pAdmin] <= PI[params[0]][pAdmin]) return AttemptRemoveAdmin(playerid);
	else if(IsIpFound(params[1]) || CheckString(params[1])) return AdminAntisliv(playerid, params[1]);
	PI[params[0]][pWarn]++;
	new string[128];
	if(PI[params[0]][pWarn] < 3) format(string, sizeof(string), "Администратор %s выдал предупреждение %s [%i|3]. Причина: %s", GetName(playerid), GetName(params[0]), PI[params[0]][pWarn], params[1]);
	else
	{
	    new data[15], unbandate;
		PI[params[0]][pWarn] = 0;
		format(string, sizeof(string), "Администратор %s забанил игрока %s (3 предупреждения). Причина: %s", GetName(playerid), GetName(params[0]), params[1]);
		getdate(years, months, days);
		unbandate = gettime() + 7*86400;
		format(data, sizeof(data), "%02d.%02d.%04d", days, months, years);
		format(query, sizeof(query), "INSERT INTO bans (name, whobanned, ip, bandate, time, unbandate, reason) VALUES ('%s', '%s', '%s', '%s', 7, %d, '%s')", GetName(params[0]), GetName(playerid), PI[params[0]][pIP], data, unbandate, params[1]);
		mysql_tquery(dbHandle, query, "", "");
	}
	SendAdminMessageToAll(COLOR_RED, string);
	LeaveFractionPlayer(params[0]);
	PI[params[0]][pSpawnChange] = 0;
	format(string, sizeof(string), "Администратор %s выдал предупреждение %s [%i|3]. Причина: %s", GetName(playerid), GetName(params[0]), PI[params[0]][pWarn], params[1]);
	format(string, sizeof(string), "Вы выдали предупреждение %s (%i из 3). Причина: %s", GetName(params[0]), PI[params[0]][pWarn],params[1]);
	SendClientMessage(playerid, COLOR_RED, string);
	SendClientMessage(params[0], COLOR_RED, "До снятия всех предупреждений Вам запрещено вступать в любые организации{FF6600}");
	SendClientMessage(params[0], COLOR_RED, "Для просмотра информации про предупреждения перезайдите и введите {FFCC00}/unwarn{FF6600}");
	SendLog("WarnLog",string);
	Kick(params[0]);
	return 1;
}
//==============================================================================
CMD:offawarn(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	new playername[MAX_PLAYER_NAME], reason[32];
	if(sscanf(params, "s[24]s[24]", playername, reason)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/offawarn [ник] [причина]");
	else if(IsIpFound(reason) || CheckString(reason)) return AdminAntisliv(playerid, reason);
	else if(GetPlayerID(playername) != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "Игрок в сети, используйте команду /warn");
	format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `name`='%s'", playername);
	mysql_tquery(dbHandle, query, "OnPlayerOffawarn", "iss", playerid, playername, reason);
	return 1;
}
//==============================================================================
CMD:unwarn(playerid, params[])
{
    if(PI[playerid][pWarn] == 0)
		return SendClientMessage(playerid, COLOR_RED, "На Вашем аккаунте нет предупреждений");
	return 1;
}
//==============================================================================
CMD:unwarnplayer(playerid, params[])
{
	if(PI[playerid][pAdmin] != 0)
	{
		if(PI[playerid][pAdmin] < ADM_SUPER_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
		else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/unwarn [ID Игрока]");
		else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
		else if(PI[params[0]][pWarn] == 0) return SendClientMessage(playerid, COLOR_RED, "У данного игрока нету предупреждений!");
		PI[params[0]][pWarn]--;
		new string[128];
		format(string, sizeof(string), "Администратор %s [%d] снял Вам 1 предупреждение", GetName(playerid), playerid);
		SendClientMessage(params[0], COLOR_BLUE, string);
		format(string, sizeof(string), "[A] %s [%d] снял 1 предупреждение игроку %s [%d]", GetName(playerid), playerid, GetName(params[0]), params[0]);
		SendAdminMessage(COLOR_GREY, string);
	}
	else if(PI[playerid][pAdmin] == 0)
	{
	    if(PI[playerid][pWarn] == 0)
			return SendClientMessage(playerid, 0xDF5600FF, "На Вашем аккаунте нет предупреждений");

		format(query, sizeof(query), "DELETE FROM `unwarn` WHERE `name` = '%s'", PI[playerid][pName]);
		mysql_query(dbHandle, query);
		format(query, sizeof(query), "DELETE FROM `warns` WHERE `nick` = '%s'", PI[playerid][pName]);
		mysql_query(dbHandle, query);

		PI[playerid][pWarn] = 0;

		format(query, sizeof(query), "UPDATE `accounts` SET `warn` = '%d' WHERE `id` = '%d'", PI[playerid][pWarn], PI[playerid][pID]);
		mysql_query(dbHandle, query);
	}
	return 1;
}
CMD:delacc(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	new playername[MAX_PLAYER_NAME];
	if(sscanf(params, "s[32]", playername) && !GetPVarInt(playerid, "deleting_account")) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/delacc [ник игрока]");
	else if(sscanf(params, "s[32]", playername) && !GetPVarInt(playerid, "deleting_account"))
	{
		DeletePVar(playerid, "deleting_account");
		SendClientMessage(playerid, COLOR_RED, "Вы отменили удаление аккаунта");
		return 1;
	}
	format(query, sizeof(query), "SELECT `id`,`level` FROM `accounts` WHERE `name`='%s'", playername);
	mysql_tquery(dbHandle, query, "OnPlayerDeleteAccount", "is", playerid, playername);
	return 1;
}
CMD:nb(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	new playername[MAX_PLAYER_NAME];
	if(sscanf(params, "s[32]", playername) && !GetPVarInt(playerid, "deleting_account")) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/nb [ник игрока]");
	else if(sscanf(params, "s[32]", playername) && !GetPVarInt(playerid, "deleting_account"))
	{
		DeletePVar(playerid, "deleting_account");
		SendClientMessage(playerid, COLOR_RED, "Вы отменили деактивацию аккаунта");
		return 1;
	}
	format(query, sizeof(query), "SELECT `id`,`level` FROM `accounts` WHERE `name`='%s'", playername);
	mysql_tquery(dbHandle, query, "OnPlayerDeleteAccount1", "is", playerid, playername);
	return 1;
}
CMD:unb(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "s[32]", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/unb [имя игрока]");
	format(query, sizeof(query), "SELECT * FROM bans WHERE name = '%s'", params[0]);
	mysql_tquery(dbHandle, query, "OnPlayerActiva", "is", playerid, params[0]);
	return 1;
}
//==============================================================================
CMD:unban(playerid, params[])
{
	if(PI[playerid][pAdmin] < 5) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "s[32]", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/unban [имя игрока]");
	format(query, sizeof(query), "SELECT * FROM bans WHERE name = '%s'", params[0]);
	mysql_tquery(dbHandle, query, "OnPlayerUnban", "is", playerid, params[0]);
	return 1;
}
//==============================================================================
CMD:banip(playerid, params[])
{
	if(PI[playerid][pAdmin] < 5) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/banip [ip адрес]");
	new string[100];
	format(string, sizeof(string), "[A] %s заблокировал IP адрес %s", GetName(playerid), params);
	SendAdminMessageEx(COLOR_RED, string, 4);
	format(string, sizeof(string), "banip %s", params);
	SendRconCommand(string);
	return 1;
}
//==============================================================================
CMD:unbanip(playerid, params[])
{
	if(PI[playerid][pAdmin] < 5) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/unbanip [ip адрес]");
	new string[100];
	format(string, sizeof(string), "[A] %s разблокировал IP адрес %s", GetName(playerid), params);
	SendAdminMessageEx(COLOR_RED, string, 4);
	format(string, sizeof(string), "unbanip %s", params);
	SendRconCommand(string);
	return 1;
}
//==============================================================================
/*CMD:engine(playerid)
{
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return 0;
	new vehicleid = GetPlayerVehicleID(playerid);
	if(!IsAPlane(vehicleid)) return 0;
	GetVehicleParamsEx(vehicleid,engine,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(vehicleid,(Engine[vehicleid])?(false):(true),lights,alarm,doors,bonnet,boot,objective);
	Engine[vehicleid] = (Engine[vehicleid])?(false):(true);
	return 1;
}
*/

CMD:unmute(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/unmute [ID игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pMuted] == 0) return SendClientMessage(playerid, COLOR_RED, "Игрок не имеет бан чата!");
	PI[params[0]][pMuted] = 0;
	SendClientMessage(params[0], COLOR_LIME, "Доступ в чат разблокирован");
	new string[100];
	format(string, sizeof(string), "Администратор %s снял затычку игроку %s",GetName(playerid),GetName(params[0]));
	SendAdminMessageToAll(COLOR_RED, string);
	return 1;
}
CMD:epp(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/epp [ид игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pJail] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок уже находится в тюрьме!");
	ResetPlayerWeaponsAC(params[0]);
	PI[params[0]][pJailTime] = 5*60;
	if(pCuff[params[0]][pCuffer] != INVALID_PLAYER_ID)
	{
		new cuffer = pCuff[params[0]][pCuffer];
		SetPlayerSpecialAction(params[0], SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(params[0], 0);
		pCuff[params[0]][pCuffer] = INVALID_PLAYER_ID;
		pCuff[params[0]][pCuffee] = INVALID_PLAYER_ID;
		pCuff[cuffer][pCuffee] = INVALID_PLAYER_ID;
		pCuff[cuffer][pCuffer] = INVALID_PLAYER_ID;
	}
	SetPlayerVirtualWorld(params[0], 1);
	new string[128];
	format(string, sizeof(string), "[A] %s [%i] посадил %s [%i] на 5 мин", GetName(playerid), playerid, GetName(params[0]), params[0]);
	SendAdminMessage(COLOR_GREY, string);
	format(string, sizeof(string), "Администратор %s посадил Вас в деморган на 5 мин. (NonRP езда (поля))", GetName(playerid));
	SendClientMessage(params[0], COLOR_BLUE, string);
	format(string, sizeof(string), "Администратор %s посадил в деморган %s. Причина: NonRP езда по полям", GetName(playerid), GetName(params[0]));
	SendClientMessageToAll(COLOR_RED, string);
	format(string, sizeof(string), "Время до окончания деморгана: {FFCC00}/time");
	SendClientMessage(params[0], COLOR_WHITE, string);
    FreezePlayer(playerid, 2000);
    SetPlayerInterior(params[0], 0);
	SetPlayerPos(params[0],449.9814,1320.2548,1723.5298);
	SetPlayerFacingAngle(params[0], 360.0000);
	PI[params[0]][pJail] = 3;
	SetPlayerWantedLevel(params[0], 0);
	PI[playerid][pCJAIL] ++;
	return 1;
}
CMD:dm(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/dm [ид игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pJail] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок уже находится в тюрьме!");
	ResetPlayerWeaponsAC(params[0]);
	PI[params[0]][pJailTime] = 10*60;
	if(pCuff[params[0]][pCuffer] != INVALID_PLAYER_ID)
	{
		new cuffer = pCuff[params[0]][pCuffer];
		SetPlayerSpecialAction(params[0], SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(params[0], 0);
		pCuff[params[0]][pCuffer] = INVALID_PLAYER_ID;
		pCuff[params[0]][pCuffee] = INVALID_PLAYER_ID;
		pCuff[cuffer][pCuffee] = INVALID_PLAYER_ID;
		pCuff[cuffer][pCuffer] = INVALID_PLAYER_ID;
	}
	SetPlayerVirtualWorld(params[0], 1);
	new string[128];
	format(string, sizeof(string), "[A] %s [%i] посадил %s [%i] на 10 мин", GetName(playerid), playerid, GetName(params[0]), params[0]);
	SendAdminMessage(COLOR_GREY, string);
	format(string, sizeof(string), "Администратор %s посадил Вас в деморган на 10 мин. (DM)", GetName(playerid));
	SendClientMessage(params[0], COLOR_BLUE, string);
	format(string, sizeof(string), "Администратор %s наказал игрока %s. Причина: DM", GetName(playerid), GetName(params[0]));
	SendClientMessageToAll(COLOR_RED, string);
	format(string, sizeof(string), "Время до окончания деморгана: {FFCC00}/time");
	SendClientMessage(params[0], COLOR_WHITE, string);
    FreezePlayer(playerid, 2000);
    SetPlayerInterior(params[0], 0);
	SetPlayerPos(params[0],449.9814,1320.2548,1723.5298);
	SetPlayerFacingAngle(params[0], 360.0000);
	PI[params[0]][pJail] = 3;
	SetPlayerWantedLevel(params[0], 0);
	PI[playerid][pCJAIL] ++;
	return 1;
}
//==============================================================================
CMD:nrp(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/nrp [ид игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pJail] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок уже находится в тюрьме!");
	ResetPlayerWeaponsAC(params[0]);
	PI[params[0]][pJailTime] = 10*60;
	if(pCuff[params[0]][pCuffer] != INVALID_PLAYER_ID)
	{
		new cuffer = pCuff[params[0]][pCuffer];
		SetPlayerSpecialAction(params[0], SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(params[0], 0);
		pCuff[params[0]][pCuffer] = INVALID_PLAYER_ID;
		pCuff[params[0]][pCuffee] = INVALID_PLAYER_ID;
		pCuff[cuffer][pCuffee] = INVALID_PLAYER_ID;
		pCuff[cuffer][pCuffer] = INVALID_PLAYER_ID;
	}
	SetPlayerVirtualWorld(params[0], 1);
	new string[128];
	format(string, sizeof(string), "[A] %s [%i] посадил %s [%i] на 10 мин", GetName(playerid), playerid, GetName(params[0]), params[0]);
	SendAdminMessage(COLOR_GREY, string);
	format(string, sizeof(string), "Администратор %s посадил Вас в деморган на 10 мин. (NonRP)", GetName(playerid));
	SendClientMessage(params[0], COLOR_BLUE, string);
	format(string, sizeof(string), "Администратор %s посадил в деморган %s. Причина: NonRP", GetName(playerid), GetName(params[0]));
	SendClientMessageToAll(COLOR_RED, string);
	format(string, sizeof(string), "Время до окончания деморгана: {FFCC00}/time");
	SendClientMessage(params[0], COLOR_WHITE, string);
    FreezePlayer(playerid, 2000);
    SetPlayerInterior(params[0], 0);
	SetPlayerPos(params[0],449.9814,1320.2548,1723.5298);
	SetPlayerFacingAngle(params[0], 360.0000);
	PI[params[0]][pJail] = 3;
	SetPlayerWantedLevel(params[0], 0);
	PI[playerid][pCJAIL] ++;
	return 1;
}
/*CMD:jail(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");
	//else if(sscanf(params, "uiis[64]", params[0], params[1], params[2],  params[3])) return SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/jail [id игрока] [минуты] [причина]");
	else if(sscanf(params, "uiis[64]", params[0], params[2])) return SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/jail [id игрока] [минуты] [причина]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pJail] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок уже в деморгане");
	//else if(params[1] < 1 || params[1] > 2) return SendClientMessage(playerid, COLOR_RED, "Номер тюрьмы от 1 до 2");
	else if(params[2] < 1 || params[2] > 180) return SendClientMessage(playerid, COLOR_RED, "Время заключения от 1 до 180 минут");
	ResetPlayerWeaponsAC(params[0]);
	PI[params[0]][pJailTime] = params[2]*60;
	if(pCuff[params[0]][pCuffer] != INVALID_PLAYER_ID)
	{
		new cuffer = pCuff[params[0]][pCuffer];
		SetPlayerSpecialAction(params[0], SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(params[0], 0);
		pCuff[params[0]][pCuffer] = INVALID_PLAYER_ID;
		pCuff[params[0]][pCuffee] = INVALID_PLAYER_ID;
		pCuff[cuffer][pCuffee] = INVALID_PLAYER_ID;
		pCuff[cuffer][pCuffer] = INVALID_PLAYER_ID;
	}
	SetPlayerVirtualWorld(params[0], 1);
	new string[128];
	format(string, sizeof(string), "[A] %s [%i] посадил %s [%i] на %i мин", GetName(playerid), playerid, GetName(params[0]), params[0], params[2]);
	SendAdminMessage(COLOR_GREY, string);
	format(string, sizeof(string), "Администратор %s посадил Вас в деморган на %i мин. (%s)", GetName(playerid), params[2], params[3]);
	SendClientMessage(params[0], COLOR_BLUE, string);
	format(string, sizeof(string), "Администратор %s посадил в деморган %s. Причина: %s", GetName(playerid), GetName(params[0]), params[3]);
	SendClientMessageToAll(COLOR_RED, string);
	format(string, sizeof(string), "Время до окончания деморгана: {FFCC00}/time");
	SendClientMessage(params[0], COLOR_WHITE, string);
    FreezePlayer(playerid, 2000);
    SetPlayerInterior(params[0], 0);
	SetPlayerPos(params[0], -1157.8915,352.7553,1769.3417);
	SetPlayerFacingAngle(params[0], 190.0000);
	PI[params[0]][pJail] = 3;
	SetPlayerWantedLevel(params[0], 0);
	PI[playerid][pCJAIL] ++;
	return 1;
}
*/
	/*switch(params[1])
	{
	    case 1:
	    {
            FreezePlayer(playerid, 2000);
	        SetPlayerInterior(params[0], 0);
			SetPlayerPos(params[0], 449.9814,1320.2548,1723.5298);
			SetPlayerFacingAngle(params[0], 360.0000);
			PI[params[0]][pJail] = 3;
			SetPlayerWantedLevel(params[0], 0);
	    }
	    case 2:
	    {
            FreezePlayer(playerid, 2000);
	        SetPlayerInterior(params[0], 0);
			SetPlayerPos(params[0], 450.0131,1332.1290,1723.5298);
			SetPlayerFacingAngle(params[0], 180.2417);
			PI[params[0]][pJail] = 4;
			SetPlayerWantedLevel(params[0], 0);
	    }
	}*/
//==============================================================================
CMD:jail(playerid, params[])
{
	if(PI[playerid][pAdmin] < 2) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	//else if(AdminLogged[playerid] == false) return SendClientMessage(playerid, COLOR_RED, YouAreNotLoggedInAsAdmin);
	else if(sscanf(params, "uiis[64]", params[0], params[1], params[2],  params[3])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/jail [id игрока] [1/2] [минуты] [причина]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pJail] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок уже находится в тюрьме!");
	else if(params[1] < 1 || params[1] > 2) return SendClientMessage(playerid, COLOR_RED, "Номер тюрьмы от 1 до 2!"); // 3 номер тюрьмы удалил
	else if(params[2] < 1 || params[2] > 180) return SendClientMessage(playerid, COLOR_RED, "Количество минут от 1 до 180!");
	ResetPlayerWeaponsAC(params[0]);
	PI[params[0]][pJailTime] = params[2] * 60;
	PI[params[0]][pWanted] = 0;
	if(pCuff[params[0]][pCuffer] != INVALID_PLAYER_ID)
	{
		new cuffer = pCuff[params[0]][pCuffer];
		SetPlayerSpecialAction(params[0], SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(params[0], 0);
		pCuff[params[0]][pCuffer] = INVALID_PLAYER_ID;
		pCuff[params[0]][pCuffee] = INVALID_PLAYER_ID;
		pCuff[cuffer][pCuffee] = INVALID_PLAYER_ID;
		pCuff[cuffer][pCuffer] = INVALID_PLAYER_ID;
	}
	SetPlayerVirtualWorld(params[0], 1);
	new string[128];
	format(string, sizeof(string), "Администратор %s [%i] посадил игрока %s [%i] в Деморган. Причина: %s", GetName(playerid), playerid, GetName(params[0]), params[0], params[2], params[3]);
	SendClientMessageToAll(COLOR_RED, string);
	format(string, sizeof(string), "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~y~JAILED: ~w~%d", PI[playerid][pJailTime]);
	GameTextForPlayer(params[0], string, 3000, 3);
	format(string, sizeof(string), "[A] %s [%i] посадил в тюрьму %s [%i] на %i минут (%s)", GetName(playerid), playerid, GetName(params[0]), params[0], params[2], params[3]);
	SendAdminMessage(COLOR_GREY, string);
	switch(params[1])
	{
	case 1:
		{
			FreezePlayer(playerid, 2000);
			SetPlayerInterior(params[0], 0);
			SetPlayerPos(params[0],449.9814,1320.2548,1723.5298);
			SetPlayerFacingAngle(params[0], 360.0000);
			PI[params[0]][pJail] = 3;
			SetPlayerWantedLevel(params[0], 0);
		}
	case 2:
		{
			FreezePlayer(playerid, 2000);
			SetPlayerInterior(params[0], 0);
			SetPlayerPos(params[0],450.0131,1332.1290,1723.5298);
			SetPlayerFacingAngle(params[0], 180.2417);
			PI[params[0]][pJail] = 3;
			SetPlayerWantedLevel(params[0], 0);
		}
	}
	return 1;
}
//==============================================================================
CMD:mute(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "udS()[64]", params[0], params[1], params[2])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/mute [id игрока] [Минуты] [Причина]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pMuted] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок уже имеет бан чата!");
	else if(params[1] > 300 || params[1] < 1) return SendClientMessage(playerid, COLOR_RED, "Время от 1 до 300 минут!");
	else if(IsIpFound(params[2]) || CheckString(params[2])) return AdminAntisliv(playerid, params[2]);
	PI[params[0]][pMuted] = params[1]*60;
	new string[128];
	if(strlen(params[2])) format(string, sizeof(string), "%s получил бан чата от администратора %s",GetName(params[0]), GetName(playerid));
//	SendClientMessage(params[0], 0xFFFFFFFF, "Вам дали бан чата на %d минут(ы). Причина: %s", params[1], params[2]);
	SendClientMessage(params[0], 0xFFFFFFFF, "Что бы посмотреть время до разблокировки чата введите /mutetime");
	PI[playerid][pCMUTE] ++;
	return 1;
}
//==============================================================================
CMD:offmute(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	new playername[MAX_PLAYER_NAME], time, reason[32];
    if(sscanf(params, "s[24]is[24]", playername, time, reason)) return SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/offmute [ник игрока] [время (минуты)] [причина]");
	else if(GetPlayerID(playername) != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "Игрок в сети, используйте команду /mute");
	else if(time > 300 || time < 1) return SendClientMessage(playerid, COLOR_RED, "Время от 1 до 300 минут!");
 	mysql_tquery(dbHandle, "SET NAMES 'cp1251'", "", "");
	mysql_tquery(dbHandle, "SET CHARACTER SET 'cp1251'", "", "");
	format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `name`='%s'", playername);
    mysql_tquery(dbHandle, query, "OnPlayerOffMute", "isis", playerid, playername, time, reason);
    PI[playerid][pCMUTE] ++;
    return 1;
}
//==============================================================================
CMD:offjail(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	new playername[MAX_PLAYER_NAME], time, reason[32];
    if(sscanf(params, "s[24]is[24]", playername, time, reason)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/offjail [ник игрока] [время (минуты)] [причина]");
	else if(GetPlayerID(playername) != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "Игрок в сети, используйте команду /jail");
	else if(time > 300 || time < 1) return SendClientMessage(playerid, COLOR_RED, "Время от 1 до 300 минут!");
 	mysql_tquery(dbHandle, "SET NAMES 'cp1251'", "", "");
	mysql_tquery(dbHandle, "SET CHARACTER SET 'cp1251'", "", "");
	format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `name`='%s'", playername);
    mysql_tquery(dbHandle, query, "OnPlayerOffJail", "isis", playerid, playername, time, reason);
    return 1;
}
//==============================================================================
CMD:offban(playerid, params[])
{
	if(PI[playerid][pAdmin] < 4) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	new playername[MAX_PLAYER_NAME], countday, reason[32];
	if(sscanf(params, "s[24]is[24]", playername, countday, reason)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/offban [Ник игрока] [Кол-во дней] [Причина]");
	else if(IsIpFound(reason) || CheckString(reason)) return AdminAntisliv(playerid, reason);
	else if(GetPlayerID(playername) != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "Игрок в сети, используйте команду /ban");
	else if(countday > 30 || countday < 1) return SendClientMessage(playerid, COLOR_RED, "Количество дней от 1 до 30!");
    mysql_tquery(dbHandle, "SET NAMES 'cp1251'", "", "");
	mysql_tquery(dbHandle, "SET CHARACTER SET 'cp1251'", "", "");
	format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `name`='%s'", playername);
	mysql_tquery(dbHandle, query, "OnPlayerOffban", "isis", playerid, playername, countday, reason);
	return 1;
}
//==============================================================================
CMD:mg(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "udS()[64]", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/mg [ид игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pMuted] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок уже имеет бан чата!");
	PI[params[0]][pMuted] = 10*60;
	new string[128];
	if(strlen(params[2])) format(string, sizeof(string), "Администратор %s поставил затычку игроку %s на 10 мин. Причина: MG",GetName(playerid), GetName(params[0]));
	else format(string, sizeof(string), "Администратор %s поставил затычку игроку %s на 10 минут. Причина: MG",GetName(playerid), GetName(params[0]));
	SendAdminMessageToAll(COLOR_RED, string);
	SendClientMessage(params[0], 0xFFFFFFFF, "Время до окончания бана чата: {CCCC00}/time");
	PI[playerid][pCMUTE] ++;
	return 1;
}
//==============================================================================
CMD:aunjail(playerid, params[])
{
	if(PI[playerid][pAdmin] < 2) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/aunjail [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pJail] == 0) return SendClientMessage(playerid, COLOR_RED, "Игрок не находится в деморгане!");
	PI[params[0]][pJailTime] = 1;
	ResetPlayerWeaponsAC(params[0]);
	new string[128];
	format(string, sizeof(string), "[A] %s [%i] выпустил из деморгана %s [%i]",GetName(playerid),playerid,GetName(params[0]),params[0]);
	SendAdminMessage(COLOR_GREY, string);
	format(string, sizeof(string), "Администратор %s выпустил Вас из деморгана", GetName(playerid));
	SendClientMessage(params[0], COLOR_BLUE, string);
	return 1;
}
//==============================================================================
CMD:free(playerid, params[])
{
	if(PI[playerid][pMember] != TEAM_AO) return 1;
	else if(!IsPlayerInRangeOfPoint(playerid, 60.0,450.2789,1325.9873,1723.5300)) return true;
 	else if(PI[playerid][pRank] != 5) return SendClientMessage(playerid, COLOR_RED, "Доступно только адвокатам!");
	else if(sscanf(params, "i", params[0])) return SendClientMessage(playerid,  COLOR_LIME, "Информация: {ffffff}/free [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	else if(PI[params[0]][pJail] == 0) return SendClientMessage(playerid, COLOR_RED, "Игрок не находится в тюрьме!");
	SendMes(params[0], COLOR_BLUE, "Адвокат %s оформил(а) документы по освобождению в размере 5000", GetName(playerid));
	SendClientMessage(params[0], COLOR_WHITE, "{FFFFFF}Нажмите {03c03c}Y {FFFFFF}чтобы согласиться или {ff7518}N {FFFFFF}для отказа");
	SetPVarInt(params[0], "JailPlayer", playerid);
	SetPVarInt(params[0], "JailSumma", 5000);
	SetPVarInt(params[0], "KeyJail", 1);
	return 1;
}
CMD:id(playerid, params[])
{
	if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/id [ник игрока]");
	new fmt_str[64];
	new count;
	foreach(new idx : Player)
	{
		if(!IsPlayerConnected(idx)) continue;

		if(strfind(PI[idx][pName], params, true) != -1)
		{
			count ++;

			SendClientMessage(playerid, 0x33adffFF, "Игроки онлайн:");

			format(fmt_str, sizeof fmt_str, "%s [%d]", PI[idx][pName], idx);
			SendClientMessage(playerid, 0xFFFFFFFF, fmt_str);

			if(count >= 5)
			{
				SendClientMessage(playerid, 0x999999FF, "Показаны первые 5 совпадений");
				break;
			}
		}
	}
	if(!count)
		SendClientMessage(playerid, 0x999999FF, "Совпадений не найдено");

	return 1;
}
//==============================================================================
CMD:givegun(playerid, params[])
{
	if(PI[playerid][pAdmin] < 4) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "uii", params[0],params[1],params[2]))
	{
		SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/givegun [id игрока] [id оружия] [патроны]");
		SendClientMessage(playerid, COLOR_WHITE, "[3] дубинка [4] нож [5] бита [6] лопата [7] кий [8] катана [9] бензопила [10-13] дилдо [14] цветы [15] топор [16-18] гранаты [22] пистолет");
		SendClientMessage(playerid, COLOR_WHITE, "[23] пистолет с глушителем [24] Desert Eagle [25] дробовик [26] обрез [27] боевой дробовик [28] UZI [29] АКС-У (MP5)");
		SendClientMessage(playerid, COLOR_WHITE, "[30] AK-105 (AK-47) [31] Винторез (M4) [32] TEC9 [33] County Rifle [34] Sniper Rifle [35] Rocket Launcher [36] Heat Speaker");
		SendClientMessage(playerid, COLOR_WHITE, "[37] Flamethrower [38] Minigun [41] Spray Can [42] Fire Extinguisher [43] Camera [46] Parachute");
		return 1;
	}
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(params[1] > 47 || params[1] < 1) return SendClientMessage(playerid, COLOR_RED, "ID оружия от 1 до 47!");
	else if(params[1] > 1000 || params[1] < 1) return SendClientMessage(playerid, COLOR_RED, "Количество патрон от 1 до 1000");
	GivePlayerWeaponAC(params[0], params[1], params[2]);
	new string[120];
	format(string, sizeof(string), "[A] %s [%d] выдал %s [%d] %s с %d пт", GetName(playerid), playerid, GetName(params[0]), params[0], WeaponNames[params[1]], params[2]);
	SendAdminMessage(COLOR_GREY, string);
	format(string, sizeof(string), "Администратор %s выдал Вам %s и %d пт", GetName(playerid), WeaponNames[params[1]], params[2]);
	SendClientMessage(params[0], COLOR_BLUE, string);
	return 1;
}
//==============================================================================
CMD:resguns(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/resguns [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	ResetPlayerWeaponsAC(params[0]);
	SendMes(playerid, COLOR_YELLOW, "Вы сбросили оружие игроку %s",GetName(params[0]));
	new string[120];
	format(string, sizeof(string), "[A] %s [%d] сбросил оружие игроку %s [%d]", GetName(playerid), playerid, GetName(params[0]), params[0]);
	SendAdminMessage(COLOR_GREY, string);
	SendMes(params[0], COLOR_GREEN, "Администратор %s обнулил ваше оружие",GetName(playerid));
	return 1;
}
CMD:givemoney(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	{
	    new string[128];
		if(sscanf(params, "ui", params[0],params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/givemoney [id игрока] [количество]");
		if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
		if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
		if(params[1] > 25000000 || params[1] < 1) return SendClientMessage(playerid, COLOR_RED, "Количество денег от 1 до 25000000!");
	    TransferMoney(-1,params[0],params[1]);
		SendMes(playerid, COLOR_BLUE, "Игрок %s [%d] получил от Вас %d рублей", GetName(params[0]),params[0],params[1]);
		SendMes(params[0], COLOR_BLUE, "Администратор %s выдал Вам %d рублей", GetName(playerid),params[1]);
		format(string, sizeof(string), "Администратор %s выдал %d рублей игроку %s", GetName(playerid), params[1], GetName(params[0]));
		SendLog("GiveMoney",string);
 	}
	return 1;
}
CMD:givedonate(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	{
		if(sscanf(params, "ui", params[0],params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/givedonate [ид игрока] [кол-во]");
		else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
		else if(params[1] > 10000 || params[1] < 1) return SendClientMessage(playerid, COLOR_RED, "Количество от 1 до 10000!");
		PI[params[0]][pCredits] += params[1];
		PI[params[0]][pTotalCredits] += params[1];
		new string[128];
		format(string, sizeof(string), "Вы выдали %i кредитов игроку %s", params[1], GetName(params[0]));
        SendClientMessage(playerid, COLOR_LIME, string);
		format(string, sizeof(string), "%s перевёл %d кредитов на счёт игроку %s [%d]", GetName(playerid), params[1], GetName(params[0]), params[0]);
		SendLog("givedonate",string);
		format(string, sizeof(string), "UPDATE `accounts` SET credits=%d,totalcredits=%d WHERE id=%d", PI[playerid][pCredits], PI[playerid][pTotalCredits], PI[playerid][pID]);
		mysql_tquery(dbHandle, string, "", "");
	}
	return 1;
}
CMD:kills(playerid)
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(killused[playerid] == 1) return SendClientMessage(playerid, COLOR_BLUE, "Вы отключили информацию о убийствах."), killused[playerid] = 0;
	killused[playerid] = 1;
	SendClientMessage(playerid, COLOR_BLUE, "Вы включили информацию о убийствах");
	return 1;
}
CMD:resetmoney(playerid, params[])
{
	if(PI[playerid][pAdmin] < 7) return SendClientMessage(playerid, COLOR_RED, "У Вас нет доступа!");
	{
		if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/resetmoney [id игрока]");
		if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
		if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
		ResetMoney(params[0]);
		SendMes(playerid, COLOR_LIME, "Вы сбросили денег игроку %s", GetName(params[0]));
	}
	return 1;
}
//==============================================================================
CMD:setnumber(playerid, params[])
{
    if(IsPlayerGrandAdmin(playerid))
    {
		if(sscanf(params, "is", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/setnomer [playerid] [nomer]");
		Delete3DTextLabel(VehicleLabel[PI[params[0]][PlayerCarID]]);
		strmid(PI[params[0]][pNumberVehicle], params[1], 0, strlen(params[1]), 20);
		new stringnumber1[40];
		format(stringnumber1, sizeof(stringnumber1), "%s", PI[playerid][pNumberVehicle]);
		VehicleLabel[PI[playerid][PlayerCarID]] = Create3DTextLabel(stringnumber1, 0xFFFFFFFF, 0, 0, 0, 10.0, 0);
		Attach3DTextLabelToVehicle(VehicleLabel[PI[playerid][PlayerCarID]], PI[playerid][PlayerCarID], 0, 0, 0.2);
		MysqlUpdatePlayerStr(playerid, "veh_number", PI[playerid][pNumberVehicle]);
	}
	return true;
}
//==============================================================================
CMD:drop(playerid, params[])
{
	if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация:{FFFFFF} /drop [сумма] (Пожертвовать деньги)");
	/*new string[500];
	format(string, sizeof(string), "{FFFFFF}Пожертвование денег области заключает в себе моментальный перевод средств с Вашего счета в фонд области\n\{FFCC00}Вы уверены, что хотите перевести %s руб.?", params[0]);
	Dialog(playerid,15420,DSL,"{FFCC00}Подтверждение пожертвования",string,"Да","Отмена");*/
 	GiveMoney(playerid, -params[0]);
	return 1;
}
//==============================================================================
CMD:slap(playerid, params[])
{
	if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/slap [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	new Float:shealth,Float:slx, Float:sly, Float:slz;
	GetPlayerHealth(params[0], shealth);
	SetHealth(params[0], shealth-5);
	GetPlayerPos(params[0], slx, sly, slz);
	SetPlayerPos(params[0], slx, sly, slz+5);
	PlayerPlaySound(params[0], 1130, slx, sly, slz+5);
	new string[128];
	format(string, sizeof(string), "Администратор %s Вас слапнул", GetName(playerid));
	SendClientMessage(params[0], COLOR_BLUE, string);
	format(string, sizeof(string), "[A] %s [%d] слапнул %s [%d]", GetName(playerid), playerid, GetName(params[0]), params[0]);
	SendAdminMessage(COLOR_GREY, string);
	PI[playerid][pCSLAP] ++;
	return 1;
}
//==============================================================================
CMD:nick(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	extract params -> new to_player; else return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/nick [id игрока]");
	new fmt_msg[128];
	format(fmt_msg, sizeof fmt_msg, "Администратор %s кикнул игрока %s. Причина: смените ник. (Формат: Имя_Фамилия)", PI[playerid][pName], PI[to_player][pName]);
	SendClientMessageToAll(0xFF4530FF, fmt_msg);
	Kick(to_player);
	PI[playerid][pCKICK] ++;
	return 1;
}
CMD:setsex(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_GRAND_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/setsex [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	new string[128];
	switch(PI[params[0]][pSex])
	{
	case 1:
		{
		    format(string, sizeof(string), "Вы изменили пол игроку %s на женский", GetName(params[0]));
			SendClientMessage(playerid, COLOR_LIME, string);
			SendClientMessage(params[0], COLOR_LIME, "Администратор изменил ваш пол на женский");
			PI[params[0]][pSex] = 2;
		}
	case 2:
		{
		    format(string, sizeof(string), "Вы изменили пол игроку %s на мужской",GetName(params[0]));
			SendClientMessage(playerid, COLOR_LIME, string);
			SendClientMessage(params[0], COLOR_LIME, "Администратор изменил ваш пол на мужской");
			PI[params[0]][pSex] = 1;
		}
	}
	return 1;
}
CMD:report(playerid, params[])
{
	new string[128];
    format(string, sizeof(string), "/menu > 4. Вопросы/жалобы на игроков");
	SendClientMessage(playerid, COLOR_LIME, string);
	return 1;
}
//==============================================================================
CMD:tsetskin(playerid, params[])
{
	if(PI[playerid][pAdmin] < 5) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "ui", params[0],params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/skin [id игрока] [id внешности]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(params[1] > 299 || params[1] < 1) return SendClientMessage(playerid, COLOR_RED, "Неверный скин");
	SetPlayerSkin(params[0], params[1]);
	new string[128];
	if(PI[playerid][pSex] == 1) format(string, sizeof(string), "Администратор %s выдал Вам временный скин №%i", GetName(playerid), params[1]);
	else format(string, sizeof(string), "Администратор %s выдала Вам временный скин №%i", GetName(playerid), params[1]);
	SendClientMessage(params[0], COLOR_BLUE, string);
	format(string, sizeof(string), "Вы выдали %s [%d] временный скин №%i", GetName(params[0]), params[0], params[1]);
	SendClientMessage(playerid, COLOR_BLUE, string);
	if(PI[playerid][pSex] == 1) format(string, sizeof(string), "[A] %s [%i] выдал %s [%d] временный скин №%i", GetName(playerid), playerid, GetName(params[0]), params[0], params[1]);
	format(string, sizeof(string), "[A] %s [%i] выдала %s [%d] временный скин №%i", GetName(playerid), playerid, GetName(params[0]), params[0], params[1]);
	SendAdminMessage(COLOR_GREY, string);
	return 1;
}
//==============================================================================
cmd:getskin(playerid, params[])
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pYouTuber] < 1) return 1;
	//else if(AdminLogged[playerid] == false) return SendErr(playerid, "Вы не авторизованы. Используйте {f1c40f}/alogin");
	else if(sscanf(params, "d", params[0])) return SendInf(playerid, "/getskin [id внешности]");
	//else if(!IsPlayerConnected(params[0])) return SendErr(playerid, "Игрок не в игре");
	//else if(PlayerLogged[params[0]] == false) return SendErr(playerid, "Игрок не авторизован");
	else if(params[0] > 299 || params[0] < 1) return SendErr(playerid, "Неверный id внешности. Можно установить от 1 до 299");
 	//else if(sscanf(params, "d", params[0])) return SCM(playerid, COLOR_LIME, "Информация: {ffffff}/getskin [skinid]");
	//else if(params[0] > 299 || params[0] < 1) { SCM(playerid, COLOR_DARKORANGE, "Неверный скин"); return true; }
	/*if(PI[params[0]][pMember])
	{
		PI[params[0]][pMemberSkin] = params[1];
		SetPlayerSkin(params[0], PI[params[0]][pMemberSkin]);
		MysqlUpdatePlayerInt(params[0], "memberskin", PI[params[0]][pMemberSkin]);
	}
	else
	{
		ClosetSkins[params[0]][0] = params[1];
		SetPlayerSkin(params[0], ClosetSkins[params[0]][0]);
		MysqlUpdatePlayerInt(params[0], "Skin", ClosetSkins[params[0]][0]);
	}*/
	SetPlayerSkin(playerid, params[0]);
    SendClientMessage(playerid, COLOR_LIME, "Вы выдали себе временный скин");
	return 1;
}
//==============================================================================
CMD:setskin(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "ui", params[0],params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/setskin [id игрока] [id внешности]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(params[1] > 299 || params[1] < 1) return SendClientMessage(playerid, COLOR_RED, "Неверный скин");
	if(PI[params[0]][pMember])
	{
		PI[params[0]][pMemberSkin] = params[1];
		SetPlayerSkin(params[0], PI[params[0]][pMemberSkin]);
		MysqlUpdatePlayerInt(params[0], "memberskin", PI[params[0]][pMemberSkin]);
	}
	else
	{
		PI[params[0]][pModel] = params[1];
		SetPlayerSkin(params[0], PI[params[0]][pModel]);
		MysqlUpdatePlayerInt(params[0], "model", PI[params[0]][pModel]);
	}
	new string[128];
	format(string, sizeof(string), "Администратор %s выдал Вам статический скин", GetName(playerid));
	SendClientMessage(params[0], COLOR_BLUE, string);
	format(string, sizeof(string), "Вы выдали %s [%d] постоянный скин №%i", GetName(params[0]), params[0], params[1]);
	SendClientMessage(playerid, COLOR_BLUE, string);
	return 1;
}
CMD:skill(playerid, params[])
{
	if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/skill [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	else if(playerid == params[0]) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/myskill");

	if(params[0] == playerid)
	{
	    new fmt_dialog[200];

		format
		(
			fmt_dialog, sizeof fmt_dialog,
			"{ffffff}SDPistol:\t%d / 100%%\n\
			Deagle:\t\t%d / 100%%\n\
			ShotGun:\t%d / 100%%\n\
			MP5:\t\t%d / 100%%\n\
			AK-47:\t\t%d / 100%%\n\
			M4A1:\t\t%d / 100%",
			PI[playerid][pSkill],
			PI[playerid][pSkill][1],
			PI[playerid][pSkill][2],
			PI[playerid][pSkill][3],
			PI[playerid][pSkill][4],
			PI[playerid][pSkill][5]
		);

		ShowPlayerDialog
		(
			playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX,
			"{FFCC00}Навыки владения оружием",
			fmt_dialog,
			"Закрыть", ""
		);

	   	MeAction(playerid, "просматривает свои навыки владения оружием");
	}
	return 1;
}
CMD:myskill(playerid)
{
	new fmt_dialog[200];

	format
	(
		fmt_dialog, sizeof fmt_dialog,
		"{ffffff}SDPistol:\t%d / 100%%\n\
		Deagle:\t\t%d / 100%%\n\
		ShotGun:\t%d / 100%%\n\
		MP5:\t\t%d / 100%%\n\
		AK-47:\t\t%d / 100%%\n\
		M4A1:\t\t%d / 100%",
		PI[playerid][pSkill],
		PI[playerid][pSkill][1],
		PI[playerid][pSkill][2],
		PI[playerid][pSkill][3],
		PI[playerid][pSkill][4],
		PI[playerid][pSkill][5]
	);

	ShowPlayerDialog
	(
		playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX,
		"{FFCC00}Навыки владения оружием",
		fmt_dialog,
		"Закрыть", ""
	);

	return 1;
}
CMD:jskill(playerid)
{
	new string[130];
	format(string, sizeof(string), "{ffffff}Дальнобойщики\n\n{FFFFFF}Уровень: {FFCC00}%d\n{FFFFFF}Рейсов: {FFCC00}%d/30", PI[playerid][pTruckLevel], PI[playerid][pTruckSkill]);
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{FFCC00}Рабочие навыки", string, "Закрыть", "");
	return true;
}

CMD:smoke(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid,100.0,-1519.6149,1342.5447,1523.7000)) return SendClientMessage(playerid, COLOR_RED, "В больнице запрещено курить!");
	else if(PI[playerid][pCiggare] == 0) return SendClientMessage(playerid, COLOR_RED, "У Вас нет сигарет, купите их в супермаркете или 24/7!");
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_SMOKE_CIGGY);
	if(PI[playerid][pHunger] <= 93) GiveHunger(playerid, 7);
	else SetHunger(playerid, 100);
	PI[playerid][pCiggare]--;
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) ApplyAnimation(playerid,"SMOKING","M_smk_drag",4.1,0,0,0,0,0,1);
	if(PI[playerid][pSex] == 1) MeAction(playerid, "достал сигарету и скурил её");
	else MeAction(playerid, "достала сигарету и скурила её");
	return 1;
}
CMD:pepsi(playerid, params[])
{
	if(PI[playerid][pSprunk] == 0) return SendClientMessage(playerid,COLOR_RED,"У Вас нет бутылки пепси");
	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DRINK_SPRUNK);
	//GiveZhazhda(playerid, 25);
	GiveHunger(playerid, 25);
	PI[playerid][pSprunk]--;
	format(query, sizeof(query), "{FFCC00}Вы выпили бутылочку пепси");
	SendClientMessage(playerid,-1, query);
	PlayerPlaySound(playerid,42600,0.0,0.0,0.0);
	return 1;
}
CMD:eat(playerid)
{
	if(PI[playerid][pCHIPS] == 0) return SendClientMessage(playerid, COLOR_RED, "У Вас нет чипс");
	if((20 + PI[playerid][pHunger]) > 100)
 		return SendClientMessage(playerid, COLOR_RED,"Вы не голодны!");
	PI[playerid][pCHIPS] -= 1;
	PI[playerid][pHunger] += 20;
	SendClientMessage(playerid, COLOR_WHITE, "Вы съели чипсы. Некоторые нужды пополнены: {FFCC00}(/need)");
    return 1;
}
CMD:repaircar(playerid, params[])
{
    if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится в транспорте!");
    else if(PI[playerid][pRepairCar] == 0) return SendClientMessage(playerid, COLOR_RED, "У Вас нет набора инструментов");
	RepairVehicle(GetPlayerVehicleID(playerid));
	PI[playerid][pRepairCar] = 0;
	SendClientMessage(playerid, COLOR_BLUE, "Вы использовали набор инструментов. Ваш транспорт починен");
	MeAction(playerid, "использовал набор инструментов");
	return 1;
}
CMD:mask(playerid, params[])
{
	if(PI[playerid][pMask] == 0) return SendClientMessage(playerid,COLOR_RED,"У Вас нет маски, купите ее в супермаркете или 24/7!");
	if(!PlayerUseMask[playerid])
	{
		SetPlayerColor(playerid, 0x00000000);
		PlayerUseMask[playerid] = true;
		if(!IsPlayerInAnyVehicle(playerid)) ApplyAnimation(playerid, "SHOP", "ROB_Shifty", 4.1, 0, 0, 0, 0, 0);
		SendClientMessage(playerid, COLOR_YELLOW, "Ваше местоположение на GPS {ffffff}скрыто{FFCC00} на 10 минут!");
		SetPlayerChatBubble(playerid, "одевает маску", COLOR_ORANGE, 20.0, 500);
		GameTextForPlayer(playerid, "~b~INVISABLE ON", 800, 4);
		PlayerPlaySound(playerid, 21000, 0.0, 0.0, 0.0);
		MeAction(playerid, "одевает маску");
		
		//mask_off_timer[playerid] = 1;
	}
	else
	{
		SetPlayerColorEx(playerid,COLOR_WHITE);
		PlayerUseMask[playerid] = false;
		PI[playerid][pMask]--;
	    GameTextForPlayer(playerid, "~y~INVISABLE OFF", 800, 4);
	    PlayerPlaySound(playerid, 21001, 0.0, 0.0, 0.0);
		MeAction(playerid, "снимает маску");
		SetPlayerChatBubble(playerid, "{FF9900}снимает маску", -1, 20.0, 500);
	}
	return 1;
}
//==============================================================================
//==============================================================================
CMD:healme(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid,100.0,-1519.6149,1342.5447,1523.7000)) return SendClientMessage(playerid,COLOR_RED,"В больнице запрещено использовать аптечку!");
	else if(PI[playerid][pAptechka] == 0) return SendClientMessage(playerid, COLOR_RED,"У Вас нет аптечки");
	new Float:shealth;
	GetPlayerHealth(playerid, shealth);
	if(shealth >= 100) return SendClientMessage(playerid, COLOR_RED, "Твое здоровье вполне в хорошем состоянии!");
	SetHealth(playerid, shealth+40);
	GetPlayerHealth(playerid, shealth);
	if(shealth > 100) SetHealth(playerid, 100);
	if(!IsPlayerInAnyVehicle(playerid)) { ApplyAnimation(playerid,"ped","gum_eat",4.0,0,0,0,0,0,1); }
	PI[playerid][pAptechka]--;
	if(PI[playerid][pSex] == 1) SetPlayerChatBubble(playerid,"перебинтовал раны",COLOR_PURPLE,30.0,1000);
	else SetPlayerChatBubble(playerid,"перебинтовала раны",COLOR_PURPLE,30.0,1000);
    GameTextForPlayer(playerid, "~b~+40 HP", 100, 1);
	return 1;
}
//==============================================================================
CMD:mutetime(playerid, params[])
{
	if(PI[playerid][pMuted] >= 1)
	{
	    format(query, sizeof(query), "{FFCC00}Время до окончания затычки: {FFCC00}%d:%02d", floatround(PI[playerid][pMuted] / 60) % 60, (PI[playerid][pMuted] % 60));
	    SendClientMessage(playerid,-1, query);
	}
}
//==============================================================================
CMD:time(playerid, params[])
{
	new hour, minuite, second, year, month, day, string[256], saturday = 1310155200, w = gettime(), day_week;
	gettime(hour, minuite, second);
	getdate(year, month, day);
	while(w - saturday > 60 * 60 * 24)
    {
        w -= 60 * 60 * 24;
        day_week ++;
    }
    while(day_week >= 7) day_week -= 7;
	format(string, sizeof(string), "%02d:%02d~n~~b~%02d-%02d-%04d~n~~b~in game %d~n~~b~", hour, minuite, day, month, year, PI[playerid][pTime]/60);
	GameTextForPlayer(playerid, string, 5000, 1);
	if(PI[playerid][pMuted] >= 1)
	{
	    format(query, sizeof(query), "{FFCC00}Время до окончания затычки: {FFCC00}%d:%02d", floatround(PI[playerid][pMuted] / 60) % 60, (PI[playerid][pMuted] % 60));
	    SendClientMessage(playerid,-1, query);
	}
	if(PI[playerid][pJail] >= 1)
	{
	    format(query, sizeof(query), "{FFCC00}Времени до выхода из КПЗ: {FFCC00}%d минут", PI[playerid][pJailTime] / 60);
	    SendClientMessage(playerid,-1, query);
	}
	if(PI[playerid][pJail] >= 2)
	{
	    format(query, sizeof(query), "{FFCC00}Времени до выхода из КПЗ: {FFCC00}%d минут", PI[playerid][pJailTime] / 60);
	    SendClientMessage(playerid,-1, query);
	}
	if(PI[playerid][pJail] >= 3)
	{
	    format(query, sizeof(query), "{FFCC00}Времени до выхода из деморгана: {FFCC00}%d минут", PI[playerid][pJailTime] / 60);
	    SendClientMessage(playerid,-1, query);
	}
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) ApplyAnimation(playerid,"COP_AMBIENT","Coplook_watch",4.1,0,0,0,0,0,1);
	return 1;
}
//==============================================================================
cmd:veh(playerid, params[])
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pAdmin] < 5) return 1;

	else if(AdminLogged[playerid] == false)
	return SendClientMessage(playerid, COLOR_RED, "Вы не авторизованы. Используйте {FFFFFF}/alogin");
/*	else if(GetPlayerInterior(playerid) > 0)
	return SendErr(playerid, "В интерьере нельзя создавать транспорт!");*/
	else if(sscanf(params, "ddd", params[0], params[1], params[2]))
	return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/veh [id машины] [цвет 1] [цвет 2]");
	else if(params[0] > 611 || params[0] < 400)
	return SendClientMessage(playerid, COLOR_RED, "ID машины не может быть меньше 400 и больше чем 611");//SendErr(playerid, "ID машины не может быть меньше 400 и больше чем 611");
	else if(params[1] > 255 || params[1] < 0)
	return SendClientMessage(playerid, COLOR_RED, "Номер цвета не может быть меньше 0 и больше 255");//SendErr(playerid, "Номер цвета не может быть меньше 0 и больше 255");
	else if(params[2] > 255 || params[2] < 0)
	return SendClientMessage(playerid, COLOR_RED, "Номер цвета не может быть меньше 0 и больше 255");//SendErr(playerid, "Номер цвета не может быть меньше 0 и больше 255");
	else if(TotalAdminVehicles > 80)
	return SendClientMessage(playerid, COLOR_RED, "Лимит админ-машин превышен");

	new Float:X,
Float:Y,
Float:Z;

	GetPlayerPos(playerid, X,Y,Z);
	X += 1.5;

	AVehicle[TotalAdminVehicles] = CreateVehicle(params[0], X,Y,Z, 0.0, params[1], params[2], -1);
	SetVehicleVirtualWorld(TotalAdminVehicles, GetPlayerVirtualWorld(playerid));
	LinkVehicleToInterior(TotalAdminVehicles, GetPlayerInterior(playerid));

	Fuel[TotalAdminVehicles] = 100;
	Engine[TotalAdminVehicles] = Lights[TotalAdminVehicles] = IsLocked[TotalAdminVehicles] = false;
//	SetVehicleNumberPlate(TotalAdminVehicles,"{FF0000}ADMIN");
	SetVehicleNumberPlate(TotalAdminVehicles, "{FFCC00}"SERVER_NAME_UK"");
	
	/*new veh_id = 0;
	veh_id = CreateVehicle(params[0], X,Y,Z, 0.0, params[1], params[2], -1);
	SetVehicleVirtualWorld(veh_id, GetPlayerVirtualWorld(playerid));
	LinkVehicleToInterior(veh_id, GetPlayerInterior(playerid));
	Fuel[veh_id] = 100;
	Engine[veh_id] = Lights[veh_id] = IsLocked[veh_id] = false;
	SetVehicleNumberPlate(veh_id,"{FF0000}ADMIN");*/

	TotalAdminVehicles++;
	return 1;
}
//==============================================================================
cmd:vehtube(playerid, params[])
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pYouTuber] < 1) return 1;

	//else if(AdminLogged[playerid] == false)
	//return SendClientMessage(playerid, COLOR_RED, "Вы не авторизованы. Используйте {FFFFFF}/alogin");//SendErr(playerid, "Вы не авторизованы. Используйте {f1c40f}/alogin");
	else if(GetPlayerInterior(playerid) > 0)
	return SendErr(playerid, "В интерьере нельзя создавать транспорт!");
	else if(sscanf(params, "ddd", params[0], params[1], params[2]))
	return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/vehtube [id машины] [цвет 1] [цвет 2]");
	else if(params[0] > 611 || params[0] < 400)
	return SendClientMessage(playerid, COLOR_RED, "ID машины не может быть меньше 400 и больше чем 611");//SendErr(playerid, "ID машины не может быть меньше 400 и больше чем 611");
	else if(params[1] > 255 || params[1] < 0)
	return SendClientMessage(playerid, COLOR_RED, "Номер цвета не может быть меньше 0 и больше 255");//SendErr(playerid, "Номер цвета не может быть меньше 0 и больше 255");
	else if(params[2] > 255 || params[2] < 0)
	return SendClientMessage(playerid, COLOR_RED, "Номер цвета не может быть меньше 0 и больше 255");//SendErr(playerid, "Номер цвета не может быть меньше 0 и больше 255");
	else if(TotalAdminVehicles > 30)
	return SendClientMessage(playerid, COLOR_RED, "Лимит ютуб-машин превыше");

	new Float:X,
Float:Y,
Float:Z;

	GetPlayerPos(playerid, X,Y,Z);
	X += 1.5;

	AVehicle[TotalAdminVehicles] = CreateVehicle(params[0], X,Y,Z, 0.0, params[1], params[2], -1);
	SetVehicleVirtualWorld(TotalAdminVehicles, GetPlayerVirtualWorld(playerid));
	LinkVehicleToInterior(TotalAdminVehicles, GetPlayerInterior(playerid));

	Fuel[TotalAdminVehicles] = 100;
	Engine[TotalAdminVehicles] = Lights[TotalAdminVehicles] = IsLocked[TotalAdminVehicles] = false;
	//SetVehicleNumberPlate(TotalAdminVehicles,"{FF0000}YOUTUBE");

	/*new veh_id = 0;
	veh_id = CreateVehicle(params[0], X,Y,Z, 0.0, params[1], params[2], -1);
	SetVehicleVirtualWorld(veh_id, GetPlayerVirtualWorld(playerid));
	LinkVehicleToInterior(veh_id, GetPlayerInterior(playerid));
	Fuel[veh_id] = 100;
	Engine[veh_id] = Lights[veh_id] = IsLocked[veh_id] = false;
	SetVehicleNumberPlate(veh_id,"{FF0000}YOUTUBE");*/

	TotalAdminVehicles++;
	return 1;
}

cmd:alldelveh(playerid, params[])
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pAdmin] < 5) return 1;
	//else if(AdminLogged[playerid] == false) return SendErr(playerid, "Вы не авторизованы. Используйте {f1c40f}/alogin");
	new string[128];
	format(string, sizeof(string), "[A] %s[%i] удалил все автомобили созданные администраторами", GetName(playerid), playerid);
	SendAdminMessage(COLOR_GREY, string);
	for(new i = 0; i < TotalAdminVehicles; i++)
	{
		if(IsValidVehicle(AVehicle[i]))
		{
			DestroyVehicle(AVehicle[i]);
		}
		AVehicle[i] = 0;
	}
	TotalAdminVehicles = 0;
	return 1;
}

CMD:respawncar(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(sscanf(params, "d", params[0])) return SCM(playerid, COLOR_LIME, "Информация: {ffffff}/respawncar [id т.с]");
	SetVehicleToRespawn(params[0]);
	new string[128];
	SendClientMessage(playerid, COLOR_BLUE, "Транспорт зареспавнен");
	format(string, sizeof(string), "[A] %s [%d] зареспавнил транспорт №%d", GetName(playerid), playerid, params[0]);
	SendAdminMessage(COLOR_GREY, string);
	return true;
}
cmd:res(playerid, params[])
{
	//if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pAdmin] < 7) return 1;
	//else if(AdminLogged[playerid] == false) return SendErr(playerid, "Вы не авторизованы. Используйте {f1c40f}/alogin");
	new radius;
	if(sscanf(params, "d", radius)) return SendInf(playerid, "/res [радиус] (радиус от 1 до 80 | значение радиуса '-1' зареспавнит весь транспорт на сервере)");
	else if(!(radius >= -100 && radius <= 0x50)) return SendErr(playerid, "Неверное значение радиуса");
	if(radius == -1)
	{
		for(new i = 1; i < MAX_VEHICLES; i++)
		{
			if(IsVehicleOccupied(i)) continue;
			AC_SetVehicleToRespawn(i);
		}
		new string[128];
		format(string, sizeof(string), "[A] %s зареспавнил весь транспорт на сервере", GetName(playerid));
		SendAdminMessage(COLOR_ADMIN, string);
	}
	else
	{
		new Float:x, Float:y, Float:z;
		for(new i = 1; i < MAX_VEHICLES; i++)
		{
			GetPlayerPos(playerid, x, y, z);
			if(IsVehicleInRangeOfPoint(i, radius, x, y, z))
			{
			    if(IsVehicleOccupied(i)) continue;
				AC_SetVehicleToRespawn(i);
			}
		}
		new string[128];
		format(string, sizeof(string), "[{A] %s зареспавнил весь транспорт в радиусе %d м", GetName(playerid), radius);
		SendAdminMessage(COLOR_ADMIN, string);
	}
	return 1;
}

CMD:fv(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/fv [id транспорта]");
	if(IsValidVehicle(params[0]))
	{
		RepairVehicle(params[0]);
		new string[100];
		format(string, sizeof(string), "Вы установили 1000 HP транспорту");
		SendClientMessage(playerid, COLOR_WHITE, string);
	}
	return 1;
}
CMD:fixveh(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится в транспорте!");
	RepairVehicle(GetPlayerVehicleID(playerid));
	SendClientMessage(playerid, COLOR_BLUE, "Транспорт починен");
	return 1;
}
CMD:do(playerid, params[])
{
    if(PI[playerid][pMuted] > 0) return SendClientMessage(playerid, 0xff6600AA, "У Вас затычка. Узнать подробней: /time");
	else if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/do [описание]");
	else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SendClientMessage(playerid,COLOR_RED,"Не флудите");
	else if(IsIpFound(params[0]) || CheckString(params[0])) return PlayerGetsChatBan(playerid, params[0]);
	DoAction(playerid, params[0]);
	SetString(OldMessage[playerid], params[0]);
	TextReset[playerid] = gettime()+3;
	return 1;
}

CMD:try(playerid, params[])
{
    if(PI[playerid][pMuted] > 0) return SendClientMessage(playerid, 0xff6600AA, "У Вас затычка. Узнать подробней: /time");
	if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/try [*действие]");
	else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SendClientMessage(playerid,COLOR_RED,"Не флудите");
	else if(IsIpFound(params[0]) || CheckString(params[0])) return PlayerGetsChatBan(playerid, params[0]);
	TryAction(playerid, params[0]);
	SetString(OldMessage[playerid], params[0]);
	TextReset[playerid] = gettime()+3;
	return 1;
}

CMD:me(playerid, params[])
{
    if(PI[playerid][pMuted] > 0) return SendClientMessage(playerid, 0xff6600AA, "У Вас затычка. Узнать подробней: /time");
	if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/me [действие]");
	else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SendClientMessage(playerid,COLOR_RED,"Посылать сообщение можно раз в 2 секунды!");
	else if(IsIpFound(params[0]) || CheckString(params[0])) return PlayerGetsChatBan(playerid, params[0]);
	MeAction(playerid, params[0]);
	SetString(OldMessage[playerid], params[0]);
	TextReset[playerid] = gettime()+3;
	return 1;
}
CMD:setfuel(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится в транспорте!");
	else if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/setfuel [кол-во бензина]");
	else if(params[0] > 100 || params[0] < 1) return SendClientMessage(playerid, COLOR_RED, "Неверное кол-во литров. Можно установить от 1 до 100 л");
	Fuel[GetPlayerVehicleID(playerid)] = params[0];
	SendClientMessage(playerid, COLOR_BLUE, "Транспорт заправлен");
	return 1;
}
CMD:setfuelall(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	for(new i; i != lastveh; i++) Fuel[i] = 100;
    new string[128];
    format(string, sizeof(string), "[A] %s [%d] поставил 100 литров всему серверу", GetName(playerid), playerid);
	SendAdminMessage(COLOR_GREY, string);
	SendClientMessage(playerid, COLOR_BLUE, "Вы установили 100 литров всему транспорту");
	return 1;
}
CMD:hp(playerid)
{
	if(PI[playerid][pAdmin] < ADM_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");

	SetHealth(playerid, 100);

	return SCM(playerid, COLOR_LIME, "Вы вылечели себя");
}
//==============================================================================
cmd:adm(playerid, params[])
{
	if(PI[playerid][pAdmin] < 1) return 1;
	//if(GetPVarInt(playerid, "check_alogin") > gettime()) return 1;
	else if(AdminLogged[playerid]) return SendErr(playerid, "Вы уже авторизовались как администратор!");
	AdminLogged[playerid] = true;
	/*new string[128];
	format(string, sizeof(string), "SELECT * FROM "T_ADMIN" WHERE `name` = '%s'", GetName(playerid));
	mysql_tquery(dbHandle, string, "Alogin", "is", playerid, GetName(playerid));
	SetPVarInt(playerid, "check_alogin", gettime()+5);*/
	return 1;
}
//==============================================================================
cmd:alogin(playerid, params[])
{
	if(GetPVarInt(playerid, "check_alogin") > gettime()) return 1;
	else if(AdminLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Вы уже авторизовались как администратор!");
	new string[128];
	format(string, sizeof(string), "SELECT * FROM "T_ADMIN" WHERE `name` = '%s'", GetName(playerid));
	mysql_tquery(dbHandle, string, "Alogin", "is", playerid, GetName(playerid));
	SetPVarInt(playerid, "check_alogin", gettime()+5);
	return 1;
}
//==============================================================================
cmd:admins(playerid)
{
	if(PI[playerid][pAdmin] > ADM_NONE || PI[playerid][pVip] > 0)
	{
		new info[29], str[170];
		format(info, sizeof(info), "Администрация в сети:");
//		format(info, sizeof(info), "Администраторы онлайн: (%i)", GetAdminsOnline());
		SendClientMessage(playerid, COLOR_GREEN, info);
		foreach(new i: Admins)
		{
		    if(PI[i][pAdmin] != ADM_NONE)
		    {
				format(str, sizeof(str), "%s[%d] [%i уровень] ", GetName(i), i, PI[i][pAdmin]);
				if(PI[i][Spectating][0] == INVALID_PLAYER_ID && PI[i][pAFK] >= 3)
				format(str, sizeof(str), "%s AFK %s", str, Converts(PI[i][pAFK]));
				else if(PI[i][Spectating][0] != INVALID_PLAYER_ID && PI[i][pAFK] < 3)
				format(str, sizeof(str), "%s {e74c3c}(SP >> %i)", str, PI[i][Spectating][0]);
				else if(PI[i][Spectating][0] != INVALID_PLAYER_ID && PI[i][pAFK] >= 3)
				format(str, sizeof(str), "%s AFK %s {e74c3c}(SP >> %i)", str, Converts(PI[i][pAFK]), PI[i][Spectating][0]);
				SendClientMessage(playerid, COLOR_WHITE, str);
			}
		}
	}
	return 1;
}
//==============================================================================
cmd:supports(playerid)
{
	if(PI[playerid][pAdmin] > 0 || PI[playerid][pSupport] > 0 || PI[playerid][pVip] > 0)
	{
		new info[29], str[170];
		format(info, sizeof(info), "Хелперы онлайн: (%i)", GetSupportsOnline());
		SendClientMessage(playerid, COLOR_GREEN, info);
		foreach(new i: Supports)
		{
		    if(PI[i][pSupport] != 0)
		    {
				format(str, sizeof(str), "%s[%d] (%i lvl) ", GetName(i), i, PI[i][pSupport]);
				if(PI[i][Spectating][0] == INVALID_PLAYER_ID && PI[i][pAFK] >= 3)
				format(str, sizeof(str), "%s AFK %s", str, Converts(PI[i][pAFK]));
				else if(PI[i][Spectating][0] != INVALID_PLAYER_ID && PI[i][pAFK] < 3)
				format(str, sizeof(str), "%s {e74c3c}(SP >> %i)", str, PI[i][Spectating][0]);
				else if(PI[i][Spectating][0] != INVALID_PLAYER_ID && PI[i][pAFK] >= 3)
				format(str, sizeof(str), "%s AFK %s {e74c3c}(SP >> %i)", str, Converts(PI[i][pAFK]), PI[i][Spectating][0]);
				SendClientMessage(playerid, COLOR_WHITE, str);
			}
		}
	}
	return 1;
}
//==============================================================================
cmd:yt(playerid)
{
	if(PI[playerid][pAdmin] > 0 || PI[playerid][pSupport] > 0 || PI[playerid][pYouTuber] > 0 || PI[playerid][pVip] > 0)
	{
		new info[29], str[170];
		format(info, sizeof(info), "Ютуберы онлайн: (%i)", GetYouTubersOnline());
		SendClientMessage(playerid, COLOR_LIME, info);
		foreach(new i: YouTubers)
		{
		    if(PI[i][pYouTuber] != 0)
		    {
				format(str, sizeof(str), "%s[%d] (%i lvl) ", GetName(i), i, PI[i][pYouTuber]);
				if(PI[i][Spectating][0] == INVALID_PLAYER_ID && PI[i][pAFK] >= 3)
				format(str, sizeof(str), "%s AFK %s", str, Converts(PI[i][pAFK]));
				else if(PI[i][Spectating][0] != INVALID_PLAYER_ID && PI[i][pAFK] < 3)
				format(str, sizeof(str), "%s {e74c3c}(SP >> %i)", str, PI[i][Spectating][0]);
				else if(PI[i][Spectating][0] != INVALID_PLAYER_ID && PI[i][pAFK] >= 3)
				format(str, sizeof(str), "%s AFK %s {e74c3c}(SP >> %i)", str, Converts(PI[i][pAFK]), PI[i][Spectating][0]);
				SendClientMessage(playerid, COLOR_WHITE, str);
			}
		}
	}
	return 1;
}
//==============================================================================
/*CMD:admins(playerid)
{
    if(PI[playerid][pAdmin] > ADM_MODER)

	SendClientMessage(playerid, 0x99CC00FF, "Администрация онлайн:");

	new fmt_msg[85], afk[25], spec[20];

	foreach(new i: Player)
	{
        if(PI[i][pAdmin] == 0) continue;
        {
			if(1 <= PI[i][pAdmin] <= 7)
			{
				format(fmt_msg, sizeof fmt_msg, "%s [%d] (%d уровень)", PI[i][pName], i, PI[i][pAdmin]);

				if(IsPlayerAfk(i))
					format(afk, sizeof afk, " - {FF9900}AFK [%02d:%02d]", (floatround(player_afk_time[i] / 60) % 60), player_afk_time[i] % 60), strcat(fmt_msg, afk);

				if(GetPlayerState(i) == PLAYER_STATE_SPECTATING)
		        {
		            format(spec, sizeof spec, "{FF0000} > /sp %d", PI[i][Spectating][0]), strcat(fmt_msg, spec);
				}
				SendClientMessage(playerid, COLOR_YELLOW, fmt_msg);
			}
		}
	}
	return 1;
}*/
/*CMD:admins(playerid)
{
	if(PI[playerid][pAdmin] > ADM_MODER)
{
	new str[300];
	SendClientMessage(playerid, COLOR_BLUE, "Администрация онлайн:");
	for(new i = 0; i < GetMaxPlayers(); i++)
{
	if(!PlayerLogged[i]) continue;
	if(PI[i][pAdmin] > ADM_NONE)
{
	format(str, sizeof(str), "%s [%d] - %s (%i уровень)", GetName(i), i, GetAdminRang(i), PI[i][pAdmin]);
	if(PI[i][Spectating][0] == INVALID_PLAYER_ID && PI[i][pAFK] >= 3)
	format(str, sizeof(str), "%s {FF0000}[AFK %s]", str, Converts(PI[i][pAFK]));
	else if(PI[i][Spectating][0] != INVALID_PLAYER_ID && PI[i][pAFK] < 3)
	format(str, sizeof(str), "%s {FF0000}/sp %i", str, PI[i][Spectating][0]);
	else if(PI[i][Spectating][0] != INVALID_PLAYER_ID && PI[i][pAFK] >= 3)
	format(str, sizeof(str), "%s {FF9900}[AFK %s] {FF0000}/spec %i", str, Converts(PI[i][pAFK]), PI[i][Spectating][0]);
	SendClientMessage(playerid, COLOR_WHITE, str);
	}
}
	new string[128];
	format(string, sizeof(string), "Время администратирования за сегодня: %i минут", AdminInfo[playerid][admTimeMin] / 60);
	SendClientMessage(playerid, 0x99CCFFFF, string);
	}
	return 1;
}*/
CMD:weap(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/weap [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	new strings[1000],strin[70],strs[100],gunname[32];
	new weapons[13][2];
	format(strs, 100, "Игрок:\t\t\t%s{FFFFFF}", GetName(params[0]));
	strcat(strings, strs);
	for(new i = 0; i != 12; i ++)
	{
		GetPlayerWeaponData(params[0], i, weapons[i][0], weapons[i][1]);
		GetWeaponName(weapons[i][0],gunname,32);
		if(weapons[i][0] != 0)
		{
			format(strin,70,"\n\nОружие:\t\t%s (%d)\nПатроны:\t\t%d",gunname,weapons[i][0],weapons[i][1]);
			strcat(strings,strin);
		}
	}
	ShowPlayerDialog(playerid,D_NULL,0,"{FFCC00}Оружие игрока",strings,"Закрыть","");
	return 1;
}
//==============================================================================
CMD:add(playerid, params[])
{
	if(!IsPlayerGrandAdmin(playerid))
		return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	ShowPlayerDialog(playerid, D_ADDNED, 2, "{FFCC00}Меню создания", "Добавить дом\nДобавить бизнес\nДобавить транспорт\nДобавить ATM\nДобавить подъезд", "Добавить", "Отмена");
	return 1;
}
//==============================================================================

//==============================================================================
CMD:changehouse(playerid, params[])
{
	if(GetPlayerHouse(playerid) == 0) return SendClientMessage(playerid, COLOR_RED, "У Вас нет дома!");
	else if(sscanf(params, "ud", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/changehouse [id игрока] [доплата]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(GetPlayerHouse(params[0]) == 0) return SendClientMessage(playerid, COLOR_RED, "У игрока нет дома!");
	else if(params[1] < 0 || params[1] > 15000000) return SendClientMessage(playerid, COLOR_RED, "Количество доплаты от 1 до 15000000!");
	new i = GetPVarInt(playerid, "PlayerHouse");
	new i2 = GetPVarInt(params[0], "PlayerHouse");
	if(IsPlayerInRangeOfPoint(playerid, 5.0, HouseInfo[i][hEntrx], HouseInfo[i][hEntry], HouseInfo[i][hEntrz]) || IsPlayerInRangeOfPoint(playerid, 15.0, HouseInfo[i][hExitx], HouseInfo[i][hExity], HouseInfo[i][hExitz]))
	{
		if(IsPlayerInRangeOfPlayer(3.0, playerid, params[0]) && params[0] != INVALID_PLAYER_ID)
		{
			if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете обменять дом себе!");
			new string[256];
			SendMes(playerid, COLOR_LIGHTBLUE, "Вы предлежили обменяться домами с %s. Твоя доплата: %d",GetName(params[0]), params[1]);
			SendMes(params[0], COLOR_LIGHTBLUE, "%s предлежил обменяться домами с Вами. Доплата: %d",GetName(playerid), params[1]);
			format(string, sizeof(string), "{FFCC00}%s предложил обменять свой дом\n\n\t\t{ffffff}(Номер: %d, Класс: %s, Доплата: %d)\n{FFCC00}На Ваш дом\n\t\t{ffffff}(Номер: %d, Тип: %s)\n\n{FFCC00}Вы согласны?", GetName(playerid), i, HouseInfo[i][hDiscript], params[1], i2, HouseInfo[i2][hDiscript]);
			ShowPlayerDialog(params[0], D_SELLHOUSE+1, 0, "{FFCC00}Обменять дом", string, "Да", "Нет");
			format(string, sizeof(string), "{FFCC00}Вы предложили %s обменять свой дом\n\n\t\t{ffffff}(Номер: %d, Тип: %s, Доплата: %d)\n{FFCC00}на его дом\n\t\t{ffffff}(Номер: %d, Тип: %s)", GetName(params[0]), i, HouseInfo[i][hDiscript], params[1], i2, HouseInfo[i2][hDiscript]);
			ShowPlayerDialog(playerid, D_NULL, 0, "{FFCC00}Обменять дом", string, "Закрыть", "");
			HouseOffer[params[0]] = playerid;
			HousePrice[params[0]] = params[1];
		}
		else SendClientMessage(playerid, COLOR_RED, "Игрок должен находится рядом с тобой!");
	}
	else SendClientMessage(playerid, COLOR_RED, "Вы должны находится в вашем доме!");
	return 1;
}
//==============================================================================
CMD:givekey(playerid, params[])
{
	if(sscanf(params,"ui",params[0],params[1])) return SendClientMessage(playerid, COLOR_LIME,"Информация:{FFFFFF} /givekey [id игрока] [1]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(GetPlayerDistanceToPlayer(playerid, params[0]) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	if(params[1] == 1)
	{
		if(PI[playerid][PlayerCarID][0] == INVALID_VEHICLE_ID) return SendClientMessage(playerid, COLOR_RED, "Команда доступна только владельцам авто");
		else if(PI[params[0]][pVehicleKey][0]) return SendClientMessage(playerid, COLOR_RED, "У игрока уже есть ключи от транспорта #1");
		PI[params[0]][pVehicleKey][0] = PI[playerid][PlayerCarID][0];
		new string[128];
		format(string, sizeof(string), "Вы получили ключи от транспорта #1 от %s", GetName(playerid));
		SendClientMessage(params[0], COLOR_BLUE, string);
		format(string, sizeof(string), "Вы выдали %s ключи от вашего транспорта #1", GetName(params[0]));
		SendClientMessage(playerid, COLOR_LIME, string);
	}
	return 1;
}

CMD:takekey(playerid, params[])
{
	if(sscanf(params,"ui",params[0],params[1])) return SendClientMessage(playerid,COLOR_LIME,"Информация: /takekey [id игрока] [1]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(GetPlayerDistanceToPlayer(playerid, params[0]) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	if(params[1] == 1)
	{
		if(PI[playerid][PlayerCarID][0] == INVALID_VEHICLE_ID) return SendClientMessage(playerid, COLOR_RED, "Команда доступна только владельцам авто");
		PI[params[0]][pVehicleKey][0] = 0;
		new string[128];
		format(string, sizeof(string), "%s забрал У Вас ключи от транспорта", GetName(playerid));
		SendClientMessage(params[0], COLOR_BLUE, string);
		format(string, sizeof(string), "Вы забрали у %s ключи от вашего транспорта", GetName(params[0]));
		SendClientMessage(playerid, COLOR_LIME, string);
	}
	return 1;
}

CMD:offkey(playerid, params[])
{
	if(sscanf(params,"i",params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: /offkey [1]");
	if(params[0] == 1)
	{
        if(!PI[playerid][pVehicleKey][0]) return SendClientMessage(playerid, COLOR_RED, "У Вас нет дубликатов ключей от транспорта #1");
		PI[playerid][pVehicleKey][0] = 0;
		SendClientMessage(playerid, COLOR_RED, "Вы выбросили ключи от транспорта #1");
  	}
	return 1;
}

CMD:vpc(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(GetPVarInt(playerid, "AddVehicleFrac") == 0) return 1;
	else if(GetPlayerState(playerid) != 2) return 1;
	else if(!IsPlayerInVehicle(playerid, GetPVarInt(playerid, "AddVehicleFrac"))) return 1;
	new Float:X,Float:Y,Float:Z,Float:FA;
	GetVehicleZAngle(GetPlayerVehicleID(playerid), FA);
	GetVehiclePos(GetPlayerVehicleID(playerid), X,Y,Z);
	DestroyVehicle(GetPVarInt(playerid, "AddVehicleFrac"));
	TOTALVEH++;
	sscanf(coordv, "p<,>iiiiiii", VehInfo[TOTALVEH][vModel], VehInfo[TOTALVEH][vColor][0],
	VehInfo[TOTALVEH][vColor][1],VehInfo[TOTALVEH][vFraction],VehInfo[TOTALVEH][vInt],VehInfo[TOTALVEH][vWorld], VehInfo[TOTALVEH][vStatus]);
	format(VehInfo[TOTALVEH][vColors], 16, "%i, %i", VehInfo[TOTALVEH][vColor][0],VehInfo[TOTALVEH][vColor][1]);
	VehInfo[TOTALVEH][vPos_X] = X;
	VehInfo[TOTALVEH][vPos_Y] = Y;
	VehInfo[TOTALVEH][vPos_Z] = Z;
	VehInfo[TOTALVEH][vPos_FA] = FA;
	VehInfo[TOTALVEH][vVehicle] = CreateVehicle(VehInfo[TOTALVEH][vModel], VehInfo[TOTALVEH][vPos_X], VehInfo[TOTALVEH][vPos_Y], VehInfo[TOTALVEH][vPos_Z], VehInfo[TOTALVEH][vPos_FA],VehInfo[TOTALVEH][vColor][0],VehInfo[TOTALVEH][vColor][1], 300);
	LinkVehicleToInterior(VehInfo[TOTALVEH][vVehicle], VehInfo[TOTALVEH][vInt]);
	SetVehicleVirtualWorld(VehInfo[TOTALVEH][vVehicle], VehInfo[TOTALVEH][vWorld]);
	Fuel[VehInfo[TOTALVEH][vVehicle]] = 150;
	Engine[VehInfo[TOTALVEH][vVehicle]] = false;
	Lights[VehInfo[TOTALVEH][vVehicle]] = false;
	DeletePVar(playerid, "AddVehicleFrac");
	new totalstring[512];
	format(totalstring,sizeof(totalstring),"INSERT INTO `vehicle` (id, model, x, y, z, fa, vint, world, colors, fraction, status) VALUES (%i, %i, '%f', '%f', '%f', '%f', %i, %i, '%s', %i, %i)",
	TOTALVEH,VehInfo[TOTALVEH][vModel],VehInfo[TOTALVEH][vPos_X],VehInfo[TOTALVEH][vPos_Y],VehInfo[TOTALVEH][vPos_Z],VehInfo[TOTALVEH][vPos_FA],VehInfo[TOTALVEH][vInt],
	VehInfo[TOTALVEH][vWorld],VehInfo[TOTALVEH][vColors],VehInfo[TOTALVEH][vFraction], VehInfo[TOTALVEH][vStatus]);
	mysql_tquery(dbHandle, totalstring, "", "");
	SendMes(playerid, COLOR_LIME, "Транспорт номер %i создан", TOTALVEH);
	return 1;
}

CMD:tpcor(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(TPC[playerid] == false)
	{
		if(!IsPlayerInVehicle(playerid, VehTest[playerid])) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится в транспорте!");
		new Float:X,Float:Y,Float:Z,Float:FA;
		GetVehicleZAngle(VehTest[playerid], FA);
		GetVehiclePos(VehTest[playerid], X,Y,Z);
		format(coordh, sizeof(coordh), "%f, %f, %f, %f", X, Y, Z, FA);
		DestroyVehicle(VehTest[playerid]);
		VehTest[playerid] = INVALID_VEHICLE_ID;
		TPC[playerid] = true;
		return SendClientMessage(playerid, COLOR_LIME, "Координаты созданы. Установите интерьер: /tpc");
	}
	if(TPC[playerid] == true)
	{
		new string1[850];
		strcat(string1,"ВАЖНО: Тип интерьера\n\nПРИМЕР: 1\n\n");
		strcat(string1,"1. Низкий класс\n");
		strcat(string1,"2. Средний класс\n");
		strcat(string1,"3. Высокий класс\n");
		strcat(string1,"4. Элитный класс (рублевка)\n");
		strcat(string1,"5. Дэлюксовый класс (топ место, редкий)\n");
		strcat(string1,"6. Особняк (р-н элитный, для семей)\n");
		strcat(string1,"6. Квартира\n");
		ShowPlayerDialog(playerid,D_ADDNED+1,1,"Добавить дом",string1,"Выбрать","Закрыть");
	}
	return 1;
}
CMD:alock(playerid)
{
	new Float: pos[3];
	new string[128];
	if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	for(new i = 1; i < MAX_VEHICLES; i++)
	{
	    GetVehiclePos(i, pos[0], pos[1], pos[2]);
	    if(PlayerToPoint(4.0, playerid, pos[0], pos[1], pos[2]))
	    {
	        if(IsLocked[i] == false)
			{
	        	IsLocked[i] = true;
				CarDoors(i, 1);
				format(string, 16, "~r~LOCK");
				GameTextForPlayer(playerid, string, 2000,3);
//				PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
			}
			else
			{
				IsLocked[i] = false;
				CarDoors(i, 0);
				format(string, 16, "~g~OPEN");
				GameTextForPlayer(playerid, string, 2000,3);
//				PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
			}
			break;
		}
	}
	return 1;
}
CMD:lock(playerid, params[])
{
	if(TextResetCMD[playerid] > gettime()) return SendClientMessage(playerid, COLOR_RED, "Не флудите!");
	new Float:x, Float:y, Float:z, type = 1;
	if(sscanf(params,"i",type))
	{
		SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/lock [номер транспорта]\n");
		SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}1 - личный транспорт | 2 - рабочий транспорт");
		return 1;
	}
	if(type > 2 || type < 1) type = 1;
	new carid;
	if(PI[playerid][PlayerCarID] && type == 1) carid = PI[playerid][PlayerCarID];
	else if(PI[playerid][pVehicleKey] && type == 2) carid = PI[playerid][pVehicleKey];
	else if(type == 2)
	{

	}
	else return SendClientMessage(playerid, COLOR_RED, "У Вас нет авто");
	GetVehiclePos(carid, x, y, z);
	if(!IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z)) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится возле своего транспорта!");
	if(IsLocked[carid] == false)
	{
		PI[playerid][cLock] = 1;
		IsLocked[carid] = true;
		CarDoors(carid, PI[playerid][cLock]);
		GameTextForPlayer(playerid, "~r~LOCK", 2000, 3);
//		PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
	}
	else
	{
		PI[playerid][cLock] = 0;
		IsLocked[carid] = false;
		CarDoors(carid, PI[playerid][cLock]);
		GameTextForPlayer(playerid, "~g~OPEN", 2000, 3);
//		PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
	}
	return 1;
}
CMD:sellcar(playerid)
{
	if(PI[playerid][cModel] != 0)
	{
		ShowPlayerDialog(playerid, D_JOB+22, 0, "{FFCC00}Продажа авто", "{ffffff}Вы уверены что хотите продать транспорт?\nНа Ваш банковский счёт будет начислено\n\nЕсли Вы хотите продать другому игроку,\nиспользуйте команду {FFCC00}/sellmycar", "Да", "Нет");
	}
	else
	{
		SCM(playerid,COLOR_LIME,"Информация: {ffffff}Ваше авто не создано по тех. причинам:");
		SCM(playerid,COLOR_LIME,"Информация: {ffffff}Если Вы купили дом / квартиру ТОЛЬКО ЧТО - то перезайдите");
		SCM(playerid,COLOR_LIME,"Информация: {ffffff}Если У Вас отель или квартира, нужно забрать авто (Меню жильца > Забрать авто)");
		SCM(playerid,COLOR_LIME,"Информация: {ffffff}Если У Вас дом, то перезайдите");
	}
	return 1;
}

/*CMD:mycar(playerid, params[]);
{
	new cares[MAX_PLAYERS] = 0;
	if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится в транспорте!");
	else if(GetPlayerVehicleID(playerid) == PI[playerid][PlayerCarID][0]) cares[playerid]++;
	else if(GetPlayerVehicleID(playerid) == PI[playerid][PlayerCarID][1]) cares[playerid]++;
	else if(cares[playerid] <= 0) return SendClientMessage(playerid,-1,"Вы должны находится в личном транспорте");
	if(sscanf(params, "uii", params[0], params[1], params[2])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/sellmycar [ид игрока] [цена] [1/2]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете продать транспорт себе!");
	else if(params[1] < 1 || params[1] > 3000000) return SendClientMessage(playerid, COLOR_RED, "Стоимость от 1 до 3000000 руб");
	SetPVarInt(params[0], "CarPlayer", playerid);
	SetPVarInt(params[0], "CarPrice", params[1]);
	SetPVarInt(params[0], "KeyCar", 1);
	SetPVarInt(params[0], "NumberCar", params[2]);
	SendMes(playerid, COLOR_BLUE, "Вы предложили купить свой транспорт %s, ожидайте подтверждения игрока", GetName(params[0]));
	SendMes(params[0], COLOR_BLUE, "Игрок %s предлагает Вам купить его транспорт %s за %i рублей", GetName(playerid), VehicleNames[GetVehicleModel(PI[playerid][PlayerCarID])-400], params[1]);
	SendClientMessage(params[0], COLOR_WHITE, "{FFFFFF}Нажмите {03c03c}Y {FFFFFF}для согласия или {ff7518}N {FFFFFF}для отказа");
	return 1;
}
*/
CMD:sellhouse(playerid) return callcmd::sellhome(playerid);
CMD:sellmyhouse(playerid) return callcmd::sellhome(playerid);
CMD:sellhome(playerid)
{
	if(GetPlayerHouse(playerid) == 0) return SendClientMessage(playerid, COLOR_RED, "У Вас нет дома!");

	ShowPlayerDialog
	(
		playerid, D_SELLHOUSE, DIALOG_STYLE_MSGBOX,
		"{FFCC00}Продажа дома",
		"{FFFFFF}Вы уверены что хотите продать свой дом государству?\n\n\
		Вам будет возвращена его стоимость за вычитом 20%",
		"Да", "Нет"
	);

	return 1;
}
//==============================================================================
CMD:sellbiz(playerid, params[]) return callcmd::sellmybiz(playerid, params);
CMD:sellmybiz(playerid, params[])
{
	if(GetPlayerBizz(playerid) == 0)
	    return SendClientMessage(playerid, COLOR_RED, "Вы не владеете бизнесом!");
     else if(sscanf(params, "ii", params[0],params[1]))
	    return SendClientMessage(playerid, COLOR_LIME, "Информация: {FFFFFF}/sellmbiz [id игрока] [цена]");
    if(GetPlayerBizz(params[0]) == 1)
	    return SendClientMessage(playerid, COLOR_RED, "У игрока уже есть бизнес!");
	if(params[1] < 1)
	    return SendClientMessage(playerid, COLOR_RED, "Неверная цена!");
	if(params[1] > 99999999)
	    return SendClientMessage(playerid, COLOR_RED, "Неверная цена!");
	new i = GetPVarInt(playerid, "PlayerBizz");
	SetPVarInt(params[0], "sellbiz",1);
   	SetPVarInt(params[0], "bizzid", i);
	SetPVarInt(params[0], "price_bizz", params[1]);
	SetPVarInt(params[0], "idsellplayerbiz",playerid);
	new string[144];
	format(string, sizeof(string), "Вы предложили {FFCC00}%s {0099FF}купить ваш бизнес за {FFFFFF}%i {0099FF}рублей", PI[params[0]][pName], params[1]);
	SendClientMessage(playerid, COLOR_BLUE, string);
	format(string, sizeof(string), "%s предлагает вам купить его бизнес за %i рублей", PI[playerid][pName], params[1]);
	SendClientMessage(params[0], COLOR_BLUE, string);
	SendClientMessage(params[0], COLOR_WHITE, "{FFFFFF}Нажмите {03c03c}Y {FFFFFF}чтобы согласиться или {ff7518}N {FFFFFF}для отказа");
	return 1;
}
//==============================================================================

CMD:vehnitro(playerid)
{
    if(PI[playerid][pAdmin] < 4) return 1;
	//else if(AdminLogged[playerid] == false) return SCM(playerid, COLOR_DARKORANGE, YouAreNotLoggedInAsAdmin);
	else if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, COLOR_DARKORANGE, "Вы должны находится в транспорте!");
    SCM(playerid,COLOR_BLUE,"Вы установили временное нитро на x10 запусков");
	AddVehicleComponent(GetPlayerVehicleID(playerid),1010);
	return 1;
}
CMD:getmet(playerid,params[])
{
    if(PI[playerid][pMember] == 12)
    {
		if(IsPlayerInRangeOfPoint(playerid, 3, -70.9661,1137.1775,2340.5300))
		{
			Dialog(playerid,1982,DSI,"{FFCC00}Склад Армии | Взять металл","{ffffff}Введите кол-во кг. металла, которое хотите взять .","Взять","Закрыть");
		}
    }
    else
    {
        SCM(playerid,COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    }
	return 1;
}
CMD:re(playerid, params[]) return callcmd::spec(playerid, params);
CMD:sp(playerid, params[]) return callcmd::spec(playerid, params);
CMD:spec(playerid, params[])
{   
	if(PI[playerid][pAdmin] < ADM_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}(/sp)ec [ид игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(playerid == params[0]) return SendClientMessage(playerid, COLOR_RED, "Следить за собой нельзя");
	else if(PI[playerid][pAdmin] < ADM_GRAND && AdminInfo[params[0]][admSpectate]) return SendClientMessage(playerid, COLOR_RED, "Следить за этим администратором запрещено");
 	
 	new Float:xPos[4];
	GetPlayerPos(playerid, xPos[0], xPos[1], xPos[2]);
	GetPlayerFacingAngle(playerid, xPos[3]);
	if(PI[playerid][Spectating][0] == INVALID_PLAYER_ID)
	{
	    SetPVarInt(playerid, "SpecInt", GetPlayerInterior(playerid));
		SetPVarInt(playerid, "SpecVw", GetPlayerVirtualWorld(playerid));
		SetPVarFloat(playerid, "SpecX", xPos[0]);
		SetPVarFloat(playerid, "SpecY", xPos[1]);
		SetPVarFloat(playerid, "SpecZ", xPos[2]);
		SetPVarFloat(playerid, "SpecA", xPos[3]);
		if(PI[playerid][pAdmin] < 7)
		{
			new string[128];
			format(string, sizeof(string), "[A] %s [%d] начал наблюдать за %s [%d]", GetName(playerid), playerid, GetName(params[0]), params[0]);
    		SendAdminMessage(COLOR_GREY, string);
 		}
	}
  	SetPlayerInterior(playerid, GetPlayerInterior(params[0]));
	SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(params[0]));
	TogglePlayerSpectating(playerid, 1);
	if(IsPlayerInAnyVehicle(params[0])) PlayerSpectateVehicle(playerid, GetPlayerVehicleID(params[0]));
	else PlayerSpectatePlayer(playerid, params[0]);
	PI[playerid][Spectating][0] = params[0];
	PI[playerid][Spectating][1] = playerid;
	player_spectate_id = params[0];
	for(new i; i < sizeof pOdmenPanel_TD; i++) TextDrawShowForPlayer(playerid, pOdmenPanel_TD[i]);
    for(new i; i < sizeof pOdminPanel_PTD[]; i++) PlayerTextDrawShow(playerid, pOdminPanel_PTD[playerid][i]);
    SelectTextDraw(playerid, 0xFF9933FF);
	return 1;
}
CMD:spoff(playerid, params[]) return callcmd::specoff(playerid, params);
CMD:specoff(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	
	else if(PI[playerid][Spectating][0] == INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "Вы не наблюдаете за игроком!");
	if(PI[playerid][pAdmin] < 1)
	{
		new string[128];
		
		format(string, sizeof(string), "[A] %s [%d] закончил наблюдение за %s [%i]", GetName(playerid), playerid, GetName(PI[playerid][Spectating][0]), PI[playerid][Spectating][0]);
	    SendAdminMessage(COLOR_GREY, string);
  	}
	
	TogglePlayerSpectating(playerid, 0);
	
	for(new i; i < sizeof pOdmenPanel_TD; i++) TextDrawHideForPlayer(playerid, pOdmenPanel_TD[i]);
    for(new i; i < sizeof pOdminPanel_PTD[]; i++) PlayerTextDrawHide(playerid, pOdminPanel_PTD[playerid][i]);
	
	CancelSelectTextDraw(playerid);
	
	return 1;
}

CMD:calling(playerid, params[])
{
	if(PI[playerid][pJob] != JOB_MECHANIC) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/gomechanic [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!MechanicON[params[0]]) return SendClientMessage(playerid, COLOR_RED, "Этот игрок не вызывал механика либо его вызов уже приняли");
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(PI[i][pJob] == JOB_MECHANIC) SendMes(i, COLOR_YELLOW, "Автомеханик %s принял вызов %s", GetName(playerid), GetName(params[0]));
	}
	SendMes(params[0], COLOR_GREEN, "Автомеханик %s принял ваш вызов, ждите", GetName(playerid));
	SendMes(playerid, COLOR_GREEN, "Игрок %s отмечен на карте", GetName(params[0]));
	new Float:X, Float:Y, Float:Z;
	GetPlayerPos(params[0], X, Y, Z);
	DisablePlayerRaceCheckpoint(playerid);
	SetPlayerRaceCheckpoint(playerid, 1, X, Y, Z, 0.0, 0.0, 0.0, 5);
	UseGPS[playerid] = true;
	MechanicON[params[0]] = false;
	SetPVarInt(params[0], "CallMech", gettime()+600);
	return 1;
}

CMD:gotaxi(playerid, params[])
{
    if(PI[playerid][pJob] != JOB_TAXI) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
    else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/gotaxi [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
    else if(!GetPVarInt(playerid, "PriceTaxi")) return SendClientMessage(playerid, COLOR_RED, "Принять вызов можно только с автомобиля такси с настроеным тарифом!");
	else if(!TaxiON[params[0]]) return SendClientMessage(playerid, COLOR_RED, "Этот игрок не заказывал такси либо его заказ уже приняли");
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(PI[i][pJob] == JOB_TAXI) SendMes(i, COLOR_YELLOW, "Таксист %s принял вызов %s",GetName(playerid), GetName(params[0]));
	}
	SendMes(params[0], COLOR_GREEN, "Таксист %s принял ваш вызов, ждите", GetName(playerid));
	SendMes(playerid, COLOR_GREEN, "Игрок %s отмечен на карте", GetName(params[0]));
	new Float:X, Float:Y, Float:Z;
	GetPlayerPos(params[0], X, Y, Z);
	DisablePlayerRaceCheckpoint(playerid);
	SetPlayerRaceCheckpoint(playerid, 1, X, Y, Z, 0.0, 0.0, 0.0, 5);
	UseGPS[playerid] = true;
	TaxiON[params[0]] = false;
	SetPVarInt(params[0], "CallTaxi", gettime()+600);
	return 1;
}

CMD:gomedhelp(playerid, params[])
{
    if(!IsAMedic(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/gomedhelp [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!MedicON[params[0]]) return SendClientMessage(playerid, COLOR_RED, "Этот игрок не вызывал мед.помощь либо его вызов уже приняли");
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(IsAMedic(i)) SendMes(i, COLOR_YELLOW, "%s %s принял вызов %s", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), GetName(params[0]));
	}
	SendMes(params[0], COLOR_GREEN, "%s %s принял ваш вызов, ждите", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
	SendMes(playerid, COLOR_GREEN, "Игрок %s отмечен на карте", GetName(params[0]));
	new Float:X, Float:Y, Float:Z;
	GetPlayerPos(params[0], X, Y, Z);
	DisablePlayerRaceCheckpoint(playerid);
	SetPlayerRaceCheckpoint(playerid, 1, X, Y, Z, 0.0, 0.0, 0.0, 5);
	UseGPS[playerid] = true;
	MedicON[params[0]] = false;
	SetPVarInt(params[0], "CallMedic", gettime()+600);
	return 1;
}

CMD:gopolice(playerid, params[])
{
    if(!IsACop(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/gopolice [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!PoliceON[params[0]]) return SendClientMessage(playerid, COLOR_RED, "Этот игрок не вызывал полицию либо его вызов уже приняли");
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(IsACop(i)) SendMes(i, COLOR_YELLOW, "%s %s принял вызов %s", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), GetName(params[0]));
	}
	SendMes(params[0], COLOR_GREEN, "%s %s принял ваш вызов, ждите", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
	SendMes(playerid, COLOR_GREEN, "Игрок %s отмечен на карте", GetName(params[0]));
	new Float:X, Float:Y, Float:Z;
	GetPlayerPos(params[0], X, Y, Z);
	DisablePlayerRaceCheckpoint(playerid);
	SetPlayerRaceCheckpoint(playerid, 1, X, Y, Z, 0.0, 0.0, 0.0, 5);
	UseGPS[playerid] = true;
	PoliceON[params[0]] = false;
	SetPVarInt(params[0], "CallPolice", gettime()+600);
	return 1;
}
CMD:gps(playerid, params[])
{
	if(UseGPS[playerid])
	{
		SendClientMessage(playerid, 0x999999AA, "GPS отключен");
		DisablePlayerRaceCheckpoint(playerid);
		UseGPS[playerid] = false;
	}
	if(GetPVarInt(playerid, "GPSWORK") == 1)
	{
		RemovePlayerMapIcon(playerid, 99);
		DeletePVar(playerid, "GPSWORK");
	}
	ShowPlayerDialog(playerid, D_GPS, DIALOG_STYLE_LIST, "{FFCC00}GPS", "\
	{FFCC00}1. {ffffff}Общественные места\n\
	{FFCC00}2. {ffffff}Подработки\n\
	{FFCC00}3. {ffffff}Развлечения\n\
	{FFCC00}4. {ffffff}Организации\n\
	{FFCC00}5. {ffffff}Нелегальные организации\n\
	{FFCC00}6. {ffffff}Бизнесы\n\
	{FFCC00}7. {ffffff}Ближайшие объекты\n\
	{FFCC00}8. {ffffff}Работы\n\
	{FFCC00}9. {ffffff}Районы области", "Выбрать", "Отмена");
	return 1;
}
CMD:gm(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/gm [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(StartGMTest[playerid] == true) return SendClientMessage(playerid, COLOR_RED, "Вы тестируете другого человека, подождите окончания теста!");
	new Float:gmhealth;
	GetPlayerHealth(params[0], gmhealth);
	new Float:boomx, Float:boomy, Float:boomz;
	GetPlayerPos(params[0],boomx, boomy, boomz);
    CreateExplosion(boomx, boomy, boomz+7, 5, 0.5);
  	SetTimerEx("GmTest", 1000, false, "ddf", playerid, params[0], gmhealth);
  	StartGMTest[playerid] = true;
    return 1;
}
CMD:setskill(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "udd", params[0], params[1], params[2]))
	{
		SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/setskill [id игрока] [номер] [количество]");
		SendClientMessage(playerid, COLOR_WHITE, "0 - Silenced 9mm, 1 - Desert Eagle, 2 - Shotgun, 3 - MP5, 4 - AK47, 5 - M4A1, 6 - Pistol, 7 - Micro Uzi");
		return 1;
	}
	else if(params[1] > 7 || params[1] < 0) return SendClientMessage(playerid, COLOR_RED, "Неизвестнео значение");
	else if(params[2] > 100 || params[2] < 0) return SendClientMessage(playerid, COLOR_RED, "Значение владения оружием может быть от 0 до 100");
	else if(!IsPlayerConnected(params[0])) return 1;
	PI[params[0]][pSkill][params[1]] = params[2];
	SendClientMessage(playerid, COLOR_BLUE, "Уровень владения оружием игроку установлен");
	return 1;
}
CMD:gmx(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	for(new x; x < 25; x++) SendClientMessageToAll(COLOR_RED, " ");
	GameTextForAll( "~b~RESTART", 5000, 3);
	SaveAcc();
	SaveWarehouse();
	foreach(new i: Player)
	{
	    if(!PlayerLogged[i]) continue;
		Kick(i);
	}
	
	//gamemode_exit_deday[playerid] = 5;
	
	return 1;
}
//==============================================================================
CMD:givevip(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(sscanf(params, "ui", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/givevip [id игрока] [кол-во дней]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	if(params[1] < 0 || params[1] > 365) return SendClientMessage(playerid, COLOR_RED, "Нельзя выдавать VIP статус более чем на 365 дней");
	new string[128];
	if(params[1] > 0)
	{
	    new year, month, day;
		getdate(year, month, day);
		new current_date = getdate(year, month, day);
	    PI[params[0]][pVip] = 1;
	    PI[params[0]][pVipTime] = current_date + params[1];
	    format(string, sizeof(string), "Вы выдали VIP статус игроку %s [%d] на %i дней", GetName(params[0]), params[0], params[1]);
	    SendClientMessage(playerid, COLOR_YELLOW, string);
	    format(string, sizeof(string), "Администратор %s выдал Вам VIP статус на %i дней", GetName(playerid), params[1]);
	    SendClientMessage(params[0], COLOR_BLUE, string);
	    format(string, sizeof(string), "%s выдал VIP статус %s на %i дней", GetName(playerid), GetName(params[0]), params[1]);
	    SendLog("SetVip", string);
	}
	else if(params[1] == 0)
	{
	    PI[params[0]][pVip] = 0;
	    PI[params[0]][pVipTime] = 0;
	    format(string, sizeof(string), "Вы забрали VIP статус у игрока %s", GetName(params[0]));
	    SendClientMessage(playerid, COLOR_YELLOW, string);
	    format(string, sizeof(string), "Администратор %s забрал У Вас VIP статус", GetName(playerid));
	    SendClientMessage(params[0], COLOR_BLUE, string);
	    format(string, sizeof(string), "%s забрал VIP статус у игрока %s", GetName(playerid), GetName(params[0]));
	    SendLog("SetVip", string);
	}
	return 1;
}
CMD:adown(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_GRAND) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(sscanf(params, "i", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/adown [ид игрока]");
	if(PI[params[0]][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "Этот игрок не является администратором");
	if(PI[params[0]][pAdmin] > 7) return SendClientMessage(playerid, COLOR_RED, "Этот администратор не может быть понижен");
	if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Нельзя изменить свой уровень");
	new string[128];
	if(PI[params[0]][pAdmin] > 1)
	{
		PI[params[0]][pAdmin]--;
		MysqlUpdatePlayerInt(params[0], "admin", PI[params[0]][pAdmin]);
		format(string, sizeof(string), "%s понизил Ваш уровень администратора", GetName(playerid));
		SendClientMessage(params[0], COLOR_YELLOW, string);
		format(string, sizeof(string), "[A] %s [%d] понизил администратора %s [%d] до %d уровня", GetName(playerid), playerid, GetName(params[0]), params[0], PI[params[0]][pAdmin]);
		SendAdminMessageEx(COLOR_RED, string, 5);
		mysql_format(dbHandle, string, sizeof(string), "UPDATE `admins` SET `level` = '%d' WHERE `name` = '%s' LIMIT 1", PI[params[0]][pAdmin], GetName(params[0]));
		mysql_tquery(dbHandle, string, "", "");
		format(string, sizeof(string), "%s понизил администратора %s до %d уровня", GetName(playerid), GetName(params[0]), PI[params[0]][pAdmin]);
		SendLog("EditAdmin", string);
	}
	else if(PI[params[0]][pAdmin] == 1)
	{
	    RemoveAdmin(params[0], GetName(params[0]));
	    format(string, sizeof(string), "%s снял %s с должности администратора", GetName(playerid), GetName(params[0]));
		SendAdminMessageEx(COLOR_RED, string, 5);
		SendLog("DeleteAdmin", string);
	}
	return 1;
}
/*
CMD:y(playerid,params[])
{
	if(PI[playerid][pYouTube] != 1) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/y [текст]");
	else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SendClientMessage(playerid, COLOR_RED, "Не флудите");
	new string[128];
	format(string, sizeof(string), "[Y] %s [%d]: %s", GetName(playerid), playerid, params[0]);
	SendAdminMessage(COLOR_REDD, string);
	SendYouTuberMessage(COLOR_REDD, string);
	SetString(OldMessage[playerid], params[0]);
	TextReset[playerid] = gettime()+3;
	return 1;
}
CMD:hc(playerid,params[])
{
	if(PI[playerid][pSupports] != 1) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/hc [текст]");
	else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SendClientMessage(playerid, COLOR_RED, "Не флудите");
	new string[128];
	format(string, sizeof(string), "[H] %s [%d]: %s", GetName(playerid), playerid, params[0]);
	SendAdminMessage(COLOR_YELLOW, string);
	SendSupportMessage(COLOR_YELLOW, string);
	SetString(OldMessage[playerid], params[0]);
	TextReset[playerid] = gettime()+3;
	return 1;
}
CMD:setyoutube(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_GRAND) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(sscanf(params, "i", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/setyoutube [ид игрока]");
 	if(PI[params[0]][pYouTube] == 0)
    {
        PI[params[0]][pYouTube] = 1;
		new string[128];
		format(string, sizeof(string), "%s %s назначил Вас ютубером проекта", GetAdminRang(playerid), GetName(playerid));
		SendClientMessage(params[0], COLOR_BLUE, string);
		format(string, sizeof(string), "Вы назначили %s[%d] ютубером проекта", GetName(params[0]), params[0]);
		SendClientMessage(playerid, COLOR_LIME, string);
		new Query[128];
		format(Query, sizeof(Query), "UPDATE `accounts` SET youtube='1' WHERE name='%s' LIMIT 1", GetName(params[0]));
		mysql_tquery(dbHandle, Query, "", "");
  	}
    else
    {
    	PI[params[0]][pYouTube] = 0;
		new string[128];
		format(string, sizeof(string), "%s %s снял Вас с поста ютубера проекта", GetAdminRang(playerid), GetName(playerid));
		SendClientMessage(params[0], COLOR_BLUE, string);
		format(string, sizeof(string), "Вы сняли %s[%d] с поста ютубера", GetName(params[0]), params[0]);
		SendClientMessage(playerid, COLOR_LIME, string);
		new Query[128];
		format(Query, sizeof(Query), "UPDATE `accounts` SET youtube='0' WHERE name='%s' LIMIT 1", GetName(params[0]));
		mysql_tquery(dbHandle, Query, "", "");
		return true;
    }
	return 1;
}
*/
CMD:setsupport(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_GRAND) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(sscanf(params, "i", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/setsupport [ид игрока]");
 	if(PI[params[0]][pSupport] == 0)
    {
        PI[params[0]][pSupport] = 1;
		new string[128];
		format(string, sizeof(string), "%s %s назначил Вас Агентом поддержки", GetAdminRang(playerid), GetName(playerid));
		SendClientMessage(params[0], COLOR_BLUE, string);
		format(string, sizeof(string), "Вы назначили %s[%d] Агентом поддержки", GetName(params[0]), params[0]);
		SendClientMessage(playerid, COLOR_LIME, string);
		new Query[128];
		format(Query, sizeof(Query), "UPDATE `accounts` SET support='1' WHERE name='%s' LIMIT 1", GetName(params[0]));
		mysql_tquery(dbHandle, Query, "", "");
  	}
    else
    {
    	PI[params[0]][pSupport] = 0;
		new string[128];
		format(string, sizeof(string), "%s %s снял Вас с поста Агента поддержки", GetAdminRang(playerid), GetName(playerid));
		SendClientMessage(params[0], COLOR_BLUE, string);
		format(string, sizeof(string), "Вы сняли %s[%d] с поста Агента поддержки", GetName(params[0]), params[0]);
		SendClientMessage(playerid, COLOR_LIME, string);
		new Query[128];
		format(Query, sizeof(Query), "UPDATE `accounts` SET support='0' WHERE name='%s' LIMIT 1", GetName(params[0]));
		mysql_tquery(dbHandle, Query, "", "");
		return true;
    }
	return 1;
}
//==============================================================================
CMD:setleader(playerid, params[])
{
    if(PI[playerid][pAdmin] < 6) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    {
		if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, 0x99CC00FF, "Информация: {FFFFFF}/setleader [id игрока]");
		else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрока нет в сети");
		else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не авторизовался");
		else if(IsPlayerInAnyVehicle(params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок не должен находиться в транспорте!");
		else if(PI[params[0]][pTempLeader]) return SendClientMessage(playerid, COLOR_RED, "Сначала снимите с себя права временного состояние в организации!");
		if(PI[params[0]][pLeader])
		{
			LeaveFractionPlayer(params[0]);
			SendMes(playerid, COLOR_BLUE, "Вы сняли %s с должности лидера организации", GetName(params[0]));
			SendMes(params[0], COLOR_RED, "Администратор %s снял Вас с должности лидера организации", GetName(playerid));
		}
		else
		{
			if(PI[params[0]][pLeader] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок лидер другой организации!");
			if(PI[params[0]][pMember] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок находится в другой организации!");
			new str[90], str2[600];
			for(new i = 1; i < MAX_FRACTIONS; i++)
			{
				format(str, sizeof(str), "№%i - %s\n", i, Fraction_Name[i]);
				strcat(str2, str);
			}
			SetPVarInt(playerid, "actplayerid", params[0]);
			ShowPlayerDialog(playerid, D_FRACMENU, 2, "Организации", str2, "Выбрать", "Отмена");
		}
	}
	return 1;
}
/*
//==============================================================================
CMD:tempduty(playerid)
{
    if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	ShowPlayerDialog(playerid, D_TEMPRABOTA, 2, "{ffcc00}Временная работа", "{ffffff}Уволиться\n(1) Водитель маршрутки\n(7) Водитель такси\n(6) Дальнобойщик\n(2) Механик", "Устроиться", "Закрыть");
	return 1;
}
//==============================================================================
CMD:templeader(playerid, params[])
{
    if(IsPlayerGrandAdmin(playerid))
    {
		new id, frac;
		if(sscanf(params, "ud", id, frac))
			return SendClientMessage(playerid, 0x99CC00FF, "Информация: {FFFFFF}/templeader [id игрока] [номер фракции]");
		else if(id == INVALID_PLAYER_ID)
			return SendClientMessage(playerid, COLOR_RED, "Игрок оффлайн");
		else if(!(0 <= frac <= MAX_FRACTIONS))
			return SendClientMessage(playerid, COLOR_RED, "Вы ввели неправильный номер фракции");

		if(PI[id][pMember] > 0)
			SendClientMessage(playerid, COLOR_RED, "Игрок состоит в организации. Сначала нужно его уволить");

		switch(frac)
		{
			case TEAM_PPS,TEAM_DPS,TEAM_FSIN,TEAM_VDV: PI[id][pRank] = 10;
			case TEAM_MZY,TEAM_SPARTAK..TEAM_CSKA,TEAM_DINAMO..TEAM_ZENIT,TEAM_SMI,TEAM_MZA: PI[id][pRank] = 10;
			case TEAM_AO: PI[id][pRank] = 12;
		}
		PI[id][pLeader] = PI[id][pMember] = frac;
		PI[id][pSpawnChange] = 2;
		MysqlUpdatePlayerInt(id, "spawnchange", PI[id][pSpawnChange]);

		STRING_GLOBAL[0] = EOS;
		format(STRING_GLOBAL, sizeof STRING_GLOBAL, "UPDATE accounts SET memberskin=%d, leader=%d, member=%d, rank=%d, job=0 WHERE name='%s'", PI[id][pMemberSkin], PI[id][pLeader], PI[id][pMember], PI[id][pRank], GetName(id));
		mysql_query(dbHandle, STRING_GLOBAL);

		format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "Вы назначили %s временным лидером организации: %s", GetName(id), Fraction_Name[frac]);
		SendClientMessage(playerid, COLOR_LIME, STRING_GLOBAL);
		format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "Администратор %s назначил Вас временным лидером организации: %s", GetName(playerid), Fraction_Name[frac]);
		SendClientMessage(id, COLOR_BLUE, STRING_GLOBAL);
		format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "[A] %s назначил %s временным лидером организации \"%s\"", GetName(playerid), GetName(id), Fraction_Name[frac]);
		SendAdminMessage(COLOR_GREY, STRING_GLOBAL);
		ResetPlayerWeapons(id);
		SetPlayerColorEx(id, TeamColors[GetTeamID(id)]);
	}
	return 1;
}
//==============================================================================
cmd:tpc(playerid,params[])
{
//	if(admin_ban_time[playerid] > 0) return SendErr(playerid, "Ваши админ-действия на сервере заблокированы");
	if(PI[playerid][pAdmin] < 3) return 1;
	else if(AdminLogged[playerid] == false) return SendErr(playerid, "Вы не авторизованы. Используйте {FFCC00}/alogin");
	new Float:px,Float:py,Float:pz,string[128];
	if(sscanf(params,"p<,>fff",px,py,pz)) return SendClientMessage(playerid, 0xFFFFFFAA, "{9ACD32}Введите: {FFFFFF} /rt <x,y,z>");
	SetPlayerPosEx(playerid,px,py,pz);
	format(string, sizeof(string), "Вы были телепортированны на указанные вами координаты: %f, %f, %f",px,py,pz);
	SendClientMessage(playerid, 0xFFFFFFAA, string);
	return 1;
}*/
//==============================================================================
CMD:f(playerid, params[])
{
	if(IsAGang(playerid) || IsAMafia(playerid))
	{
	    if(PI[playerid][pMuted] > 0) return SCM(playerid, COLOR_RED, "У вас затычка. Узнать подробней: /time");
	    else if(isnull(params))return SCM(playerid, COLOR_LIME, "Информация: {ffffff}/r [текст]");
   		else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SCM(playerid,COLOR_RED,"Не флуди");
		else if(IsIpFound(params[0]) || CheckString(params[0])) return PlayerGetsChatBan(playerid, params[0]);
		new string[128];
		format(string, sizeof(string), "[F] %s %s[%d]: %s", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), playerid, params[0]);
		SendFMes(PI[playerid][pMember], 0xFF6600AA, string);
		SetPlayerChatBubble(playerid,"сообщает в рацию",COLOR_PURPLE,30.0,10000);
		SetString(OldMessage[playerid], params[0]);
		TextReset[playerid] = gettime()+3;
	}
	else SCM(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
//==============================================================================
CMD:fb(playerid, params[])
{
	if(IsAGang(playerid) || IsAMafia(playerid))
	{
	    if(PI[playerid][pMuted] > 0) return SCM(playerid, COLOR_RED, "У вас затычка. Узнать подробней: /time");
	    else if(isnull(params))return SCM(playerid, COLOR_LIME, "Информация: {ffffff}/r [текст]");
   		else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SCM(playerid,COLOR_RED,"Не флуди");
		else if(IsIpFound(params[0]) || CheckString(params[0])) return PlayerGetsChatBan(playerid, params[0]);
		new string[128];
		format(string, sizeof(string), "[F] %s %s[%d]: (( %s ))", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), playerid, params[0]);
		SendFMes(PI[playerid][pMember], 0xFF6600AA, string);
		SetPlayerChatBubble(playerid,"сообщает в рацию",COLOR_PURPLE,30.0,10000);
		SetString(OldMessage[playerid], params[0]);
		TextReset[playerid] = gettime()+3;
	}
	else SCM(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
//==============================================================================
CMD:r(playerid, params[])
{
	if(IsAGos(playerid))
	{
		if(PI[playerid][pMuted] > 0) return SCM(playerid, COLOR_RED, "У Вас затычка. Узнать подробней: /time");
		else if(isnull(params)) return SCM(playerid, COLOR_LIME, "Информация: {ffffff}/r [текст]");
		else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SCM(playerid,COLOR_RED,"Не флуди");
		else if(IsIpFound(params[0]) || CheckString(params[0])) return PlayerGetsChatBan(playerid, params[0]);
		new string[128];
		format(string, sizeof(string), "[R] %s %s[%d]: %s", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), playerid, params[0]);
		SendFMes(PI[playerid][pMember], 0x3366FFAA, string);
		SetPlayerChatBubble(playerid,"сообщает в рацию",COLOR_PURPLE,30.0,10000);
		SetString(OldMessage[playerid], params[0]);
		TextReset[playerid] = gettime()+3;
	}
	else SCM(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
//==============================================================================
CMD:rb(playerid, params[])
{
	if(IsAGos(playerid))
	{
		if(PI[playerid][pMuted] > 0) return SCM(playerid, COLOR_RED, "У Вас затычка. Узнать подробней: /time");
		else if(isnull(params)) return SCM(playerid, COLOR_LIME, "Информация: {ffffff}/rb [текст]");
		else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SCM(playerid,COLOR_RED,"Не флуди");
		else if(IsIpFound(params[0]) || CheckString(params[0])) return PlayerGetsChatBan(playerid, params[0]);
		new fmt_msg[150];
		format(fmt_msg, sizeof fmt_msg, "[R] %s %s[%d]: (( %s ))", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), playerid, params[0]);
		SendFMes(PI[playerid][pMember], 0x3366FFAA, fmt_msg);
		SetPlayerChatBubble(playerid, "сообщает в рацию", COLOR_PURPLE, 30.0, 10000);
		SetString(OldMessage[playerid], params[0]);
		TextReset[playerid] = gettime()+3;
	}
	else SCM(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
//==============================================================================
CMD:invite(playerid, params[])
{
	if(IsAbleToInvite(playerid))
	{
		new targetid;
		if(sscanf(params, "u", targetid)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/invite [id игрока]");
		else if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[targetid] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
		else if(PI[targetid][pLeader] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок лидер другой организации!");
		else if(PI[targetid][pMember] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок находится в другой организации!");
		else if(PI[targetid][pWarn] > 0) return SendClientMessage(playerid, COLOR_RED, "У игрока предупреждение!");
		else if(IsPlayerInAnyVehicle(targetid)) return SendClientMessage(playerid, COLOR_RED, "Игрок не должен находится в транспорте!");
		else if(!IsPlayerInRangeOfPlayer(8.0, playerid, targetid)) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
		else if(PI[targetid][pLevel] < 2) return SendClientMessage(playerid, COLOR_RED, "У игрока нету 2 уровня!");
		else if(IsACop(playerid) && !PI[targetid][pVoennik]) return SCM(playerid, COLOR_RED, "У игрока нет военного билета!");
  		SendMes(playerid, COLOR_BLUE, "Вы предложили %s вступить в \"%s\"", GetName(targetid), Fraction_Name[PI[playerid][pMember]]);
		SendMes(targetid, COLOR_BLUE, "%s %s предлагает Вам вступить в \"%s\"", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), Fraction_Name[PI[playerid][pMember]]);
		SCM(targetid, COLOR_WHITE, "{FFFFFF}Нажмите {03c03c}Y {FFFFFF}чтобы согласиться или {ff7518}N {FFFFFF}для отказа");
		SetPVarInt(targetid, "KeyInvite", 1);
		SetPVarInt(targetid, "offerfractionid", PI[playerid][pMember]);
		SetPVarInt(targetid, "offerplayer", playerid);
		SetPVarInt(playerid, "actplayerid", targetid);
	}
	return 1;
}
/*
//==============================================================================
CMD:hi(playerid, params[])
{
 	if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/hi [id игрока]");
 	if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете пожать руку самому себе!");
	if(!IsPlayerInRangeOfPlayer(2.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	new Float:angle, string[64];
	GetPlayerFacingAngle(playerid, angle);
	SetPlayerFacingAngle(params[0], angle + 180);
	format(string, sizeof(string), "пожал(а) руку %s", GetName(params[0]));
	MeAction(playerid, string);
	if(!IsPlayerInAnyVehicle(playerid)) ApplyAnimation(playerid,"GANGS","hndshkfa",4.0,0,0,0,0,0);
	if(!IsPlayerInAnyVehicle(params[0])) ApplyAnimation(params[0],"GANGS","hndshkfa",4.0,0,0,0,0,0);
	return 1;
}
//==============================================================================
CMD:sellgun(playerid, params[])
{
	if(!IsAGang(playerid)) return 1;
	if(PI[playerid][pRank] < 1) return SCM(playerid, COLOR_RED, "Продавать оружие можно только со 2-ого ранга!");

	else if(sscanf(params, "uiii", params[0], params[1], params[2], params[3])) return SCM(playerid, COLOR_LIME, "Информация: {ffffff}/sellgun [id игрока] [id оружия] [кол-во патронов] [цена]");
	else if(!IsPlayerConnected(params[0])) return SCM(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SCM(playerid, COLOR_RED, "Игрок не ввел пароль!");
	if(params[1] == 24 || params[1] == 25 || params[1] == 29 || params[1] == 23 || params[1] == 30 || params[1] == 31 || params[1] == 33)
	{
		if(params[2] < 1 || params[2] > 500) return SCM(playerid, COLOR_RED, "Количество патронов от 1 до 500!");
		if(params[3] < 1 || params[3] > 20000) return SCM(playerid, COLOR_RED, "Цена от 1 до 20000 доллара(ов)!");
		if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SCM(playerid, COLOR_RED, "Игрок слишком далеко!");
		if(PI[playerid][pPatron] < params[2]) return SCM(playerid, COLOR_RED, "У Вас недостаточно материалов!");
		SendMes(playerid, COLOR_BLUE, "Вы предложили %s купить У Вас %s с %i пт. за %i рублей", GetName(params[0]), WeaponNames[params[1]], params[2], params[3]);
		SendMes(params[0], COLOR_WHITE, "%s предложил Вам купить {0099FF}%s(%i патр) {ffffff}за %i рублей.", GetName(playerid), WeaponNames[params[1]], params[2], params[3]);
		SCM(params[0], COLOR_WHITE, "{FFFFFF}Нажмите {03c03c}Y {FFFFFF}чтобы согласиться или {ff7518}N {FFFFFF}для отказа");
		SetPVarInt(params[0], "KeyGun", 1);
		SetPVarInt(params[0], "PlayerGun", playerid);
		SetPVarInt(params[0], "PlayerGun_", params[1]);
		SetPVarInt(params[0], "PlayerGAmmo", params[2]);
		SetPVarInt(params[0], "PlayerGPrice", params[3]);
	} else return SCM(playerid, COLOR_RED, "Неверный ID оружия! ID оружия: 23, 24, 25, 29, 30, 31, 33");

	return 1;
}
//==============================================================================
CMD:d(playerid, params[])
{
	if(IsACop(playerid) || PI[playerid][pMember] == TEAM_VDV || IsAMedic(playerid) || IsAMayor(playerid) || IsANews(playerid))
	{
		if(PI[playerid][pMuted] > 0) return SendClientMessage(playerid, COLOR_RED, "У Вас затычка. Узнать подробней: /time");
		else if(GetPVarInt(playerid,"dep") > gettime()) return SendClientMessage(playerid, COLOR_RED, "Следующее сообщение Вы сможете отправить через 15 секунд!");
		else if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/d [текст]");
		else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SendClientMessage(playerid, COLOR_RED,"Не флудите");
		else if(IsIpFound(params[0]) || CheckString(params[0])) return PlayerGetsChatBan(playerid, params[0]);
		new mesid[128];
		format(mesid, sizeof(mesid), "[D]: %s %s [%d]: %s", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), playerid, params[0]);
		SendDMes(0xff8282AA, mesid);
		SetPlayerChatBubble(playerid,"сообщает в департамент",COLOR_PURPLE,30.0,10000);
		SetPVarInt(playerid,"dep",gettime() + 15);
	}
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
//==============================================================================
CMD:db(playerid, params[])
{
	if(IsACop(playerid) || PI[playerid][pMember] == TEAM_VDV || IsAMedic(playerid) || IsAMayor(playerid) || IsANews(playerid))
	{
		if(PI[playerid][pMuted] > 0) return SendClientMessage(playerid, COLOR_RED, "У Вас затычка. Узнать подробней: /time");
		else if(GetPVarInt(playerid,"dep") > gettime()) return SendClientMessage(playerid, COLOR_RED, "Следующее сообщение Вы сможете отправить через 15 секунд!");
		else if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/db [текст]");
		else if(TextReset[playerid] > gettime() && GetString(OldMessage[playerid], params[0])) return SendClientMessage(playerid, COLOR_RED,"Не флудите");
		else if(IsIpFound(params[0]) || CheckString(params[0])) return PlayerGetsChatBan(playerid, params[0]);
		new mesid[128];
		format(mesid, sizeof(mesid), "(( [D]: %s %s [%d]: %s ))", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), playerid, params[0]);
		SendDMes(0xff8282AA, mesid);
		SetPVarInt(playerid,"dep",gettime() + 15);
	}
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
CMD:find(playerid)
{
	if(PI[playerid][pMember] == 0) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	new full, string[150], string_dialogue[2048], text[20];
    strcat(string_dialogue, "{FFCC00}ID\tУровень\tТелефон\tРанг\tИмя\n\n");
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false || PI[i][pAdmin]) continue;
		if(PI[i][pMember] == PI[playerid][pMember])
		{
		    if(PI[i][pPhoneNumber] <= 1) format(text, sizeof(text), "None\t\t");
			else format(text, sizeof(text), "%i\t\t", PI[i][pPhoneNumber]);
		    format(string, sizeof(string),"{FFFFFF}%i\t%i\t\t%s%i\t%s\n", i, PI[i][pLevel], text, PI[i][pRank], GetName(i));
			strcat(string_dialogue, string);
			full++;
		}
	}
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{FFCC00}Члены организации онлайн", string_dialogue, "Закрыть", "");
	return 1;
}

CMD:leaders(playerid)
{
	new full, str[150], string[2048], text[20];
	strcat(string, "{FFCC00}Организация - Должность - Имя - Телефон\n\n");
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false || PI[i][pAdmin]) continue;
		if(PI[i][pLeader] > 0)
		{
		    if(PI[i][pPhoneNumber] <= 1) format(text, sizeof(text), "None");
			else format(text, sizeof(text), "%i", PI[i][pPhoneNumber]);
			format(str, sizeof(str),"{FFFFFF}%s - %s - %s - %s\n", Fraction_Name[PI[i][pLeader]], Fraction_Rang[PI[i][pMember]][PI[i][pRank]], GetName(i), text);
			strcat(string, str);
			full++;
		}
	}
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{FFCC00}Лидеры онлайн", string, "Закрыть", "");
	return 1;
}
CMD:leaders(playerid)
{
    //if(GetPVarInt(playerid, "logged") == 0) return 1;
	new string[1500];
	new fmt_str[128];

	string = "Организация - Должность - Имя - Телефон\n\n{FFFFFF}";

	foreach(new i: Player)
	{
		if(!IsPlayerConnected(i)) continue;
		else if(PI[i][pLeader] == 0) continue;

		//format(fmt_str, sizeof fmt_str, "%s - %s - %s [%d] - %d", Fraction_Name[ PI[i][pLeader] ], Fraction_Rang[PI[i][pMember]], PI[i][pName], i, PI[i][pPhoneNumber]);
		format(fmt_str, sizeof fmt_str,"%s - %s - %s [%d] - %d", Fraction_Name[PI[i][pLeader]], Fraction_Rang[PI[i][pMember]][PI[i][pRank]], GetName(i));
		strcat(string, fmt_str);

		if(IsPlayerAfk(i))
		{
			new afk[15];

			if((floatround(player_afk_time[i] / 60) % 60) > 0)
				format(afk, sizeof afk, " - [AFK: %d:%02d]", (floatround(player_afk_time[i] / 60) % 60), player_afk_time[i] % 60);
			else
				format(afk, sizeof afk, " - [AFK: 0:%d]", player_afk_time[i] % 60);

			strcat(string, afk);
		}
		strcat(string, "\n");
	}

	ShowPlayerDialog
	(
		playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX,
		"{FFCC00}Лидеры онлайн",
		string,
		"Закрыть", ""
	);
	return 1;
}*/
/*CMD:leaders(playerid)
{
	new str[150], text[20];

	STRING_GLOBAL[0] = EOS;
	strcat(STRING_GLOBAL, "{FFCC00}Организация - Должность - Имя игрока - Телефон\n\n");
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(PI[i][pLeader] > 0 && PI[i][pAdmin] == 0)
		{
		    if(PI[i][pPhoneNumber] <= 1) format(text, sizeof(text), "None");
			else format(text, sizeof(text), "%i", PI[i][pPhoneNumber]);
			format(str, sizeof(str),"{FFFFFF}%s - %s - %s - %s\n", Fraction_Name[PI[i][pLeader]], Fraction_Rang[PI[i][pMember]][PI[i][pRank]], GetName(i), text);
			strcat(STRING_GLOBAL, str);
		}
	}
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{FFCC00}Лидеры организаций в сети", STRING_GLOBAL, "Закрыть", "");
	return 1;
}*/

cmd:leaders(playerid)
{
	new full, str[150], text[20];
	global_string = "";
	strcat(global_string, "{FFFF00}Организация - Должность - Имя игрока - Телефон\n\n");
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(PI[i][pLeader] > 0)
		{
			if(PI[i][pPhoneNumber] <= 1) format(text, sizeof(text), "None");
			else format(text, sizeof(text), "%i", PI[i][pPhoneNumber]);
			if(PI[i][pAFK] >= 3) format(str, sizeof(str), "{FFFFFF}%s - %s - %s - %s {FF0000}[AFK: %s]\n", Fraction_Name[PI[i][pLeader]], Fraction_Rang[PI[i][pMember]][PI[i][pRank]], GetName(i), text, Converts(PI[i][pAFK]));
			else format(str, sizeof(str),"{FFFFFF}%s - %s - %s - %s\n", Fraction_Name[PI[i][pLeader]], Fraction_Rang[PI[i][pMember]][PI[i][pRank]], GetName(i), text);
			strcat(global_string, str);
			full++;
		}
	}
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{FFCC00}Лидеры организаций в сети", global_string, "Закрыть", "");
	return 1;
}

CMD:changeskin(playerid, params[])
{
    if(IsAbleToChangeSkin(playerid))
    {
        new targetid;
		if(sscanf(params, "u", targetid)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/changeskin [id игрока]");
		else if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[targetid] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
		else if(PI[targetid][pMember] == 0) return SendClientMessage(playerid, COLOR_RED, "Игрок не находится в организации!");
		else if(PI[targetid][pMember] != PI[playerid][pMember]) return SendClientMessage(playerid, COLOR_RED, "Игрок находится в другой организации!");
        else if(GetPlayerDistanceToPlayer(playerid,targetid) > 5.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid)) return SendClientMessage(playerid,COLOR_RED,"Вы далеко друг от друга");
        else if(PI[targetid][pRank] > PI[playerid][pRank]) return SendClientMessage(playerid, COLOR_RED, "Ваш ранг недостаточен");
        SetPVarInt(playerid, "actplayerid", targetid);
		new fractionid = PI[playerid][pMember];
        new mes[128];
		for(new i; i < 10; i++)
		{
			new skinid = Fraction_Skin[fractionid][i];
			if(!skinid) break;
			if(!i) format(mes, sizeof(mes), "Скин %d [%d]", i+1, skinid);
			else format(mes, sizeof(mes), "%s\nСкин %d [%d]", mes, i+1, skinid);
		}
		ShowPlayerDialog(playerid, D_FRACMENU+8, 2, "{FFCC00}Выбор скина", mes, "Принять", "");
    }
    else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}

CMD:leave(playerid, params[])
{
	if(PI[playerid][pImprove][1] || PI[playerid][pVip])
	{
		if(PI[playerid][pMember] == 0) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится в организации!");
		else if(PI[playerid][pLeader] > 0) return SendClientMessage(playerid, COLOR_RED, "Вы не должны быть лидером!");
		else if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вы не должны находится в транспорте!");
		new string[256];
		format(string, 256, "{FFFFFF}Вы состоите в организации: \"%s\",\nи Вы хотите покинуть её по собственному желанию.\nПри этом все Ваши достижения в организации останутся позади.\n\nВы уверены что хотите уволится из организации?",Fraction_Name[PI[playerid][pMember]]);
		ShowPlayerDialog(playerid, D_LEAVE, 0, "{FFCC00}Предупреждение", string, "Да", "Нет");
	}
	else SendClientMessage(playerid, COLOR_RED, "У Вас нет VIP");
	return 1;
}

CMD:quitjob(playerid, params[])
{
    if(!PI[playerid][pVip]) return SendClientMessage(playerid, COLOR_RED, "Вы не имеете VIP статус");
    else if(!PI[playerid][pJob]) return SendClientMessage(playerid, COLOR_RED, "Вы нигде не работаете!");
	PI[playerid][pJob] = 0;
	SendClientMessage(playerid, COLOR_WHITE, "Вы уволились с работы");
	return 1;
}
CMD:lwarn(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_GRAND) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    {
		if(PI[playerid][pAdmin] < 1) return 1;
		if(sscanf(params, "us[26]", params[0], params[1])) return SCM(playerid, COLOR_LIME, "Информация: {ffffff}/lwarn [id лидера] [причина]");
		else if(!IsPlayerConnected(params[0])) return SCM(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[params[0]] == false) return SCM(playerid, COLOR_RED, "Игрок не ввел пароль!");
		else if(PI[params[0]][pLeader] == 0) return SCM(playerid, COLOR_RED, "Игрок не является лидером!");
		else if(playerid == params[0] && PI[playerid][pAdmin] < 7) return SCM(playerid, COLOR_RED, "Нельзя выдавать выговоры самому себе!");
		new string[256];
		PI[params[0]][pfWarn] ++;
		if(PI[params[0]][pfWarn] >= 3)
		{
		    format(string, sizeof(string), "[A] %s %s выдал предупреждение [3|3] лидеру %s",GetAdminRang(playerid),PI[playerid][pName],PI[params[0]][pName]);
		    SendMes(params[0],COLOR_RED,"Вы получили лидерское-предупреждение 3 из 3 от %s. Причина: %s",PI[playerid][pName],params[1]);
		    LeaveFractionPlayer(params[0]);
		}
		else
		{
			format(string, sizeof(string), "[A] %s %s выдал предупреждение [%d|3] лидеру %s",GetAdminRang(playerid),PI[playerid][pName],PI[params[0]][pfWarn],PI[params[0]][pName]);
			SendMes(params[0],COLOR_RED,"Вы получили лидерское-предупреждение [%d из 3] от %s. Причина: %s",PI[params[0]][pfWarn],PI[playerid][pName],params[1]);
		}
		SendAdminMessage(COLOR_GREY, string);
	}
	return 1;
}
CMD:awarn(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_GRAND) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    {
		if(PI[playerid][pAdmin] < 1) return 1;
		if(sscanf(params, "us[26]", params[0], params[1])) return SCM(playerid, COLOR_LIME, "Информация: {ffffff}/awarn [id админа] [причина]");
		else if(!IsPlayerConnected(params[0])) return SCM(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[params[0]] == false) return SCM(playerid, COLOR_RED, "Игрок не ввел пароль!");
		if(PI[params[0]][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "Этот игрок не является администратором");
		else if(playerid == params[0] && PI[playerid][pAdmin] < 7) return SCM(playerid, COLOR_RED, "Нельзя выдавать выговоры самому себе!");
		new string[256];
		PI[params[0]][pAWARN] ++;
		if(PI[params[0]][pAWARN] >= 3)
		{
            format(string, sizeof(string), "[A] %s %s выдал предупреждение [3|3] администратору %s",GetAdminRang(playerid),PI[playerid][pName],PI[params[0]][pName]);
		    SendMes(params[0],COLOR_RED,"Вы получили админ-предупреждение 3 из 3 от %s. Причина: %s",PI[playerid][pName],params[1]);
		}
		else
		{
			format(string, sizeof(string), "[A] %s %s выдал предупреждение [%d|3] администратору %s",GetAdminRang(playerid),PI[playerid][pName],PI[params[0]][pAWARN],PI[params[0]][pName]);
			SendMes(params[0],COLOR_RED,"Вы получили админ-предупреждение %d из 3 от %s. Причина: %s",PI[params[0]][pAWARN],PI[playerid][pName],params[1]);
		}
		SendAdminMessage(COLOR_GREY, string);
	}
	return 1;
}
CMD:unlwarn(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_GRAND) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    {
		if(PI[playerid][pAdmin] < 1) return 1;
		if(sscanf(params, "us[26]", params[0], params[1])) return SCM(playerid, COLOR_LIME, "Информация: {ffffff}/unlwarn [id лидера] [причина]");
		else if(!IsPlayerConnected(params[0])) return SCM(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[params[0]] == false) return SCM(playerid, COLOR_RED, "Игрок не ввел пароль!");
		else if(PI[params[0]][pLeader] == 0) return SCM(playerid, COLOR_RED, "Игрок не является лидером!");
		else if(playerid == params[0] && PI[playerid][pAdmin] < 7) return SCM(playerid, COLOR_RED, "Нельзя снимать выговоры самому себе!");
		else if(PI[params[0]][pfWarn] == 0) return SCM(playerid,COLOR_RED,"У лидера нет выговоров!");

		PI[params[0]][pfWarn] --;

		new string[256];
		format(string, sizeof(string), "[A] %s [%d] снял выговор %d/3 лидеру %s [%d]. Причина: %s",PI[playerid][pName],playerid,PI[params[0]][pfWarn],PI[params[0]][pName],params[0],params[1]);
		SendAdminMessage(COLOR_GREY, string);
		SendMes(params[0],COLOR_BLUE,"Администратор %s [%d] снял Вам лидерский выговор %d/3. Причина: %s",PI[playerid][pName],playerid,PI[params[0]][pfWarn],params[1]);
	}
	return 1;
}
CMD:unawarn(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_GRAND) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    {
		if(PI[playerid][pAdmin] < 1) return 1;
		if(sscanf(params, "us[26]", params[0], params[1])) return SCM(playerid, COLOR_LIME, "Информация: {ffffff}/unawarn [id админа] [причина]");
		else if(!IsPlayerConnected(params[0])) return SCM(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[params[0]] == false) return SCM(playerid, COLOR_RED, "Игрок не ввел пароль!");
		if(PI[params[0]][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "Этот игрок не является администратором");
		else if(playerid == params[0] && PI[playerid][pAdmin] < 7) return SCM(playerid, COLOR_RED, "Нельзя снимать выговоры самому себе!");
		else if(PI[params[0]][pAWARN] == 0) return SCM(playerid,COLOR_RED,"У администратора нет выговоров!");

		PI[params[0]][pAWARN] --;

		new string[256];
		format(string, sizeof(string), "[A] Руководитель %s снял предупреждение [%d|3] администратору %s",PI[playerid][pName],PI[params[0]][pAWARN],PI[params[0]][pName]);
		SendAdminMessage(COLOR_GREY, string);
		SendMes(params[0],COLOR_RED,"Руководитель %s снял Вам админ-предупреждение [%d|3]",PI[playerid][pName],PI[params[0]][pAWARN]);
	}
	return 1;
}
CMD:guninvite(playerid, params[])
{
	if(PI[playerid][pMember] != TEAM_AO) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(!IsAMayor(playerid) || PI[playerid][pRank] < 9) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	new targetid, reason[32];
	if(sscanf(params, "us[32]", targetid, reason)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/guninvite [id игрока] [причина]");
	else if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[targetid] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[targetid][pMember] == 0) return SendClientMessage(playerid, COLOR_RED, "Игрок не находится в организации!");
	else if(PI[targetid][pLeader] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок лидер другой организации!");
	SendMes(playerid, COLOR_LIME, "Вы уволили %s из организации. Причина: %s",GetName(targetid),reason);
	SendMes(targetid, COLOR_RED, "%s %s уволил Вас из организации. Причина: %s", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid),reason);
	LeaveFractionPlayer(targetid);
	return 1;
}
CMD:cc(playerid) return callcmd::clearchat(playerid);
CMD:clearchat(playerid)
{
	if(PI[playerid][pAdmin] < ADM_GRAND) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    for(new i = 0; i < 100; i++) SendClientMessageToAll(COLOR_WHITE, "");
    new string[64];
	format(string, sizeof(string),  "[A] Чат был очищен администрацией");
	SendAdminMessage(COLOR_GREY, string);
	return 1;
}
CMD:uninvite(playerid, params[])
{
	if(IsAbleToUninvite(playerid))
	{
		new targetid, reason[32];
		new string[100];
		if(sscanf(params, "us[32]", targetid, reason)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/uninvite [ид игрока] [Причина]");
		else if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[targetid] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
		else if(PI[targetid][pMember] == 0) return SendClientMessage(playerid, COLOR_RED, "Игрок не находится в организации!");
		else if(PI[targetid][pLeader] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок лидер другой организации!");
		else if(PI[targetid][pMember] != PI[playerid][pMember]) return SendClientMessage(playerid, COLOR_RED, "Игрок находится в другой организации!");
		else if(playerid == targetid) return SendClientMessage(playerid, COLOR_RED, "Самого себя нельзя уволить!");
		SendMes(playerid, COLOR_LIME, "Вы уволили из фракции %s. Причина: %s",GetName(targetid),reason);
		SendMes(targetid, COLOR_RED, "%s [%d] уволил Вас из организации \"Безработный\". Причина: %s",GetName(playerid), playerid, reason);
		format(string, sizeof(string), "[A] %s %s уволил игрока из организации %s. Причина: %s", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]],GetName(playerid), GetName(params[0]), reason);
	    SendAdminMessage(COLOR_GREY, string);
		LeaveFractionPlayer(targetid);
	}
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
//==============================================================================
CMD:auninvite(playerid, params[])
{
	if(PI[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	new targetid, reason[32];
	if(sscanf(params, "us[32]", targetid, reason)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/auninvite [id игрока] [причина]");
	else if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[targetid] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[targetid][pMember] == 0) return SendClientMessage(playerid, COLOR_RED, "Игрок не находится в организации!");
	else if(PI[targetid][pLeader] > 0) return SendClientMessage(playerid, COLOR_RED, "Игрок лидер другой организации!");
	SendMes(playerid, COLOR_LIME, "Вы уволили из фракции %s [%d]",GetName(targetid), targetid);
	new string[129];
	format(string, sizeof(string), "[A] %s %s [%d] уволил %s [%d] из организации", GetAdminRang(playerid), GetName(playerid), playerid, GetName(targetid), targetid);
 	SendAdminMessage(COLOR_GREY, string);
	SendMes(targetid, COLOR_RED, "Администратор %s уволил Вас из организации \"Безработный\"",GetName(playerid));
	LeaveFractionPlayer(targetid);
	return 1;
}
//==============================================================================
CMD:rang(playerid, params[])
{
	if(PI[playerid][pRank] < 9) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(sscanf(params, "dc", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/rang [Ид игрока] [+/-]");
	if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы указали свой ID!");
	if(PI[playerid][pMember] != PI[params[0]][pMember]) return SendClientMessage(playerid, COLOR_RED, "Данный игрок не в вашей фракции!");
	if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Вы далеко от игрока");
	new string[133];
	if(params[1] == 43) // Повышение +
	{
		if(PI[params[0]][pRank] >= 9) return SendClientMessage(playerid, COLOR_RED, "Вы не можете повысить игрока более 9 ранга");
		if(PI[params[0]][pRank] == 9 && PI[params[0]][pRank] == 8) return SendClientMessage(playerid, COLOR_RED, "Вы не можете повысить игрока более 7 ранга");
		else if(PI[params[0]][pLeader] > 0) return SendClientMessage(playerid, COLOR_RED, "Данный игрок лидер");
		PI[params[0]][pRank]++;
		format(string,sizeof(string),"Вы повысили %s [%d] до %s(%d)", GetName(params[0]), params[0], Fraction_Rang[PI[params[0]][pMember]][PI[params[0]][pRank]], PI[params[0]][pRank]);
		SendClientMessage(playerid, COLOR_BLUE, string);
		format(string,sizeof(string),"Ваш ранг в организации был повышен до %d (%s)", PI[params[0]][pRank], Fraction_Rang[PI[params[0]][pMember]][PI[params[0]][pRank]]);
		SendClientMessage(params[0], COLOR_BLUE, string);
		if(PI[params[0]][pMember] == TEAM_VDV && PI[params[0]][pRank] == 5)
		{
       	 	PI[params[0]][pVoennik] = 1;
			SendClientMessage(params[0], COLOR_BLUE, "Поздравляем! Вы получили военный билет");
		}
	}
	else if(params[1] == 45) // Понижение -
	{
		if(PI[params[0]][pRank] == 1) return SendClientMessage(playerid, COLOR_RED, "У игрока сейчас 1 ранг, понижение невозможно");
		if(PI[params[0]][pLeader] > 0) return SendClientMessage(playerid, COLOR_RED, "Данный игрок лидер");
		PI[params[0]][pRank]--;
		format(string,sizeof(string),"Вы понизили ранг игроку %s [%d] до %d (%s)", GetName(params[0]), params[0], PI[params[0]][pRank], Fraction_Rang[PI[params[0]][pMember]][PI[params[0]][pRank]]);
		SendClientMessage(playerid, COLOR_BLUE, string);
		format(string,sizeof(string),"Ваш ранг в организации был понижен до %d (%s)", PI[params[0]][pRank], Fraction_Rang[PI[params[0]][pMember]][PI[params[0]][pRank]]);
		SendClientMessage(params[0], COLOR_RED, string);
	}
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
//==============================================================================
CMD:arang(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_GRAND_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	if(sscanf(params, "dc", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/arang [id игрока] [+/-]");
	if(!IsPlayerInRangeOfPlayer(10.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Вы далеко от игрока");
	new string[133];
	if(params[1] == 43) // Повышение +
	{
	    if(PI[params[0]][pRank] >= 12) return SendClientMessage(playerid, COLOR_RED, "Вы не можете повысить игрока выше 13-го ранга");
		if(PI[params[0]][pRank] == 9 && PI[params[0]][pRank] == 8) return SendClientMessage(playerid, COLOR_RED, "Вы не можете повысить игрока более 7 ранга");
		PI[params[0]][pRank]++;
		format(string,sizeof(string),"Вы повысили %s [%d] до %s(%d)", GetName(params[0]), params[0], Fraction_Rang[PI[params[0]][pMember]][PI[params[0]][pRank]], PI[params[0]][pRank]);
		SendClientMessage(playerid, COLOR_BLUE, string);
		format(string,sizeof(string),"Ваш ранг в организации был повышен до %d (%s)", PI[params[0]][pRank], Fraction_Rang[PI[params[0]][pMember]][PI[params[0]][pRank]]);
		SendClientMessage(params[0], COLOR_BLUE, string);
		if(PI[playerid][pMember] == TEAM_VDV && PI[playerid][pRank] == 5)
		{
       	 	PI[playerid][pVoennik] = 1;
			SendClientMessage(playerid, COLOR_BLUE, "Поздравляем! Вы получили военный билет");
		}
	}
	else if(params[1] == 45) // Понижение -
	{
		if(PI[params[0]][pRank] == 1) return SendClientMessage(playerid, COLOR_RED, "У игрока сейчас 1 ранг, понижение невозможно");
		PI[params[0]][pRank]--;
		format(string,sizeof(string),"Вы понизили ранг игроку %s [%d] до %d (%s)", GetName(params[0]), params[0], PI[params[0]][pRank], Fraction_Rang[PI[params[0]][pMember]][PI[params[0]][pRank]]);
		SendClientMessage(playerid, COLOR_BLUE, string);
		format(string,sizeof(string),"Ваш ранг в организации был понижен до %d (%s)", PI[params[0]][pRank], Fraction_Rang[PI[params[0]][pMember]][PI[params[0]][pRank]]);
		SendClientMessage(params[0], COLOR_RED, string);
	}
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
//==============================================================================
CMD:lmenu(playerid)
{
	if(PI[playerid][pLeader] < 1) return 1;
   	ShowPlayerDialog(playerid, D_FRACMENU+7, 2, "{FFCC00}Панель лидера", "{ffffff}Члены организации\t\t{63BD4E}[Online]{ffffff}\nЧлены организации\t\t{F04245}[Offline]{ffffff}\nУволить игрока\t\t{F04245}[Offline]", "Выбрать", "Отмена");
	return 1;
}
//==============================================================================
CMD:selllic(playerid, params[])
{
	if(PI[playerid][pMember] != TEAM_AO) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(!IsAMayor(playerid) || PI[playerid][pRank] < 5) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(sscanf(params, "ud", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/selllic [id игрока] [id лицензии (1-водительские,2-водные,3-воздушные,4-оружие,5-бизнес)]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!IsPlayerInRangeOfPlayer(10.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	new bool:dostup;
	switch(params[1])
	{
		case 1:	if(PI[params[0]][pLic][0]) dostup = true;
		case 2: if(PI[params[0]][pLic][1]) dostup = true;
		case 3: if(PI[params[0]][pLic][2]) dostup = true;
		case 4: if(PI[params[0]][pLic][3]) dostup = true;
		case 5:
		{
		    new i = GetPVarInt(params[0], "PlayerBizz");
			if(BizzInfo[i][bLic]) dostup = true;
		}
	}
	if(params[1] == 5 && !GetPlayerBizz(params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок не имеет бизнеса!");
	if(dostup == true) return SendClientMessage(playerid, COLOR_RED, "У игрока есть данная лицензия");
	new type[24], price;
	switch(params[1])
	{
		case 1: type = "Водительские права", price = 1000;
		case 2: type = "лицензию на судоходство", price = 3000;
		case 3: type = "лицензию на полеты", price = 10000;
		case 4: type = "лицензию на оружие", price = 30000;
		case 5: type = "лицензию на бизнес", price = 1000000;
	}
	new string[144];
	format(string, sizeof(string), "Вы предложили %s купить %s. Цена: %i рублей", GetName(params[0]), type, price);
	SendClientMessage(playerid, COLOR_BLUE, string);
	format(string, sizeof(string), "%s предложил Вам купить %s. Цена: %i рублей", GetName(playerid), type, price);
	SendClientMessage(params[0], COLOR_BLUE, string);
	SendClientMessage(params[0], COLOR_WHITE, "{FFFFFF}Нажмите {03c03c}Y {FFFFFF}чтобы согласиться или {ff7518}N {FFFFFF}для отказа");
	SetPVarInt(params[0], "sellexamlic", 1);
	SetPVarInt(params[0], "changelic", params[1]);
	SetPVarInt(params[0], "idselllic", playerid);
	return 1;
}
CMD:agl(playerid, params[]) return callcmd::agivelic(playerid, params);
CMD:agivelic(playerid, params[])
{
    if(PI[playerid][pAdmin] < 7) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params,"ddd", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/agivelic [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	PI[params[0]][pCarA] = 1;
	PI[params[0]][pCarB] = 1;
	PI[params[0]][pCarC] = 1;
	PI[params[0]][pCarD] = 1;
	SendClientMessage(playerid, COLOR_LIME, "Вы выдали лицензии всех категорий");
	SendMes(params[0], COLOR_BLUE,"Администратор %s [%d] выдал Вам лицензии всех категорий", GetName(playerid), playerid);
	return 1;
}

CMD:givelic(playerid, params[])
{
    if(PI[playerid][pAdmin] < 7) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    else if(sscanf(params,"ddd", params[0],params[1],params[2])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/givelic [id игрока] [1 - A, 2 - B, 3 - C, 4 - D] [значение - 1(Выдать)]");
    else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
    else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	new amount = params[2];
	switch(params[1])
	{
		case 1:
		{
			PI[params[0]][pCarA] = amount;
			SendClientMessage(playerid, COLOR_LIME, "Вы выдали категорию A");
			SendMes(params[0],COLOR_LIME,"Администратор %s [%d] выдал Вам категорию на вождение - A", GetName(playerid), playerid);
		}
		case 2:
		{
			PI[params[0]][pCarB] = amount;
			SendClientMessage(playerid, COLOR_LIME, "Вы выдали категорию B");
			SendMes(params[0],COLOR_LIME,"Администратор %s [%d] выдал Вам категорию на вождение - B", GetName(playerid), playerid);
		}
		case 3:
		{
			PI[params[0]][pCarC] = amount;
			SendClientMessage(playerid, COLOR_LIME, "Вы выдали категорию C");
			SendMes(params[0],COLOR_LIME,"Администратор %s [%d] выдал Вам категорию на вождение - C", GetName(playerid), playerid);
		}
		case 4:
		{
			PI[params[0]][pCarD] = amount;
			SendClientMessage(playerid, COLOR_LIME, "Вы выдали категорию D");
			SendMes(params[0],COLOR_LIME,"Администратор %s [%d] выдал Вам категорию на вождение - D", GetName(playerid), playerid);
		}
	}
	return 1;
}
CMD:takegun(playerid, params[])
{
	if((PI[playerid][pMember] == TEAM_PPS || PI[playerid][pMember] == TEAM_DPS || PI[playerid][pMember] == TEAM_FSIN) && PI[playerid][pRank] >= 6)
	{
		if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/take [id игрока]");
		else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
		else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
      	ResetPlayerWeaponsAC(params[0]);
	  	SendMes(playerid, COLOR_LIME, "Вы забрали оружие у %s",GetName(params[0]));
	  	SendMes(params[0], COLOR_LIME, "%s забрал У Вас оружие",GetName(playerid));
	}
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
CMD:switchskin(playerid, params[])
{
	if(PI[playerid][pMember] < TEAM_FSIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "d", params[0])) return SCM(playerid, COLOR_LIME, "Информация: {ffffff}/switchskin [id внешности]");
	else if(params[0] > 299 || params[0] < 1) { SCM(playerid, COLOR_RED, " ID может быть от 1 до 299"); return true; }
	PI[playerid][pChar][0] = params[0];
	SetPlayerSkin(playerid, PI[playerid][pChar][0]);
	new string[128];
	format(string, sizeof(string), "Вы сменили свою внешность");
	SendClientMessage(playerid, COLOR_BLUE, string);
	MeAction(playerid, "сменил внешность");
	return true;
}

CMD:mwarn(playerid, params[])
{
    if(PI[playerid][pMember] < TEAM_FSIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	new targetid, reason[32];
	if(sscanf(params, "ds[32]", targetid, reason)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/mwarn [id игрока] [причина]");
	else if(targetid == INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(!gPlayerLogged[targetid]) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!PI[targetid][pMember]) return SendClientMessage(playerid, COLOR_RED, "Игрок не состоит в организации!");
	else if(PI[targetid][pLeader]) return SendClientMessage(playerid, COLOR_RED, "Лидеру нельзя выдать выговор!");
	else if(PI[targetid][pMember] != PI[playerid][pMember]) return SendClientMessage(playerid, COLOR_RED, "Игрок не состоит в Вашей организации!");
	else if(playerid == targetid) return SendClientMessage(playerid, COLOR_RED, "Самому себя нельзя выдать выговор!");
	new string[128];
	if(PI[targetid][pMemberWarn] == 3)
	{
	    format(string, sizeof(string), "Вы выдали выговор %s [3/3]. Причина: %s", GetName(targetid), reason);
		SendClientMessage(playerid, COLOR_BLUE, string);
		format(string, sizeof(string), "%s %s выдал%s Вам выговор [3/3]. Причина: %s", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), (PI[playerid][pSex]==1)?(""):("а"), reason);
		SendClientMessage(targetid, COLOR_BLUE, string);
		format(string, sizeof(string), "%s %s выдал%s выговор игроку %s [3/3]. Причина: %s. Игрок уволен", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), (PI[playerid][pSex]==1)?(""):("а"), GetName(targetid), reason);
		SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
		LeaveFractionPlayer(targetid);
		SendClientMessage(targetid, COLOR_RED, "Вы были уволены с организации по причине трёх выговоров!");
	}
	else
	{
	    PI[targetid][pMemberWarn] ++;
        MysqlUpdatePlayerInt(targetid, "memberwarn", PI[targetid][pMemberWarn]);
	    format(string, sizeof(string), "Вы выдали выговор %s [%d/3]. Причина: %s", GetName(targetid), PI[targetid][pMemberWarn], reason);
		SendClientMessage(playerid, COLOR_BLUE, string);
        format(string, sizeof(string), "%s %s выдал%s Вам выговор [%d/3]. Причина: %s", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), (PI[playerid][pSex]==1)?(""):("а"), PI[targetid][pMemberWarn], reason);
		SendClientMessage(targetid, COLOR_BLUE, string);
		format(string, sizeof(string), "%s %s выдал%s выговор игроку %s [%d/3]. Причина: %s", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), (PI[playerid][pSex]==1)?(""):("а"), GetName(targetid), PI[targetid][pMemberWarn], reason);
		SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
	}
	return 1;
}

CMD:unmwarn(playerid, params[])
{
    if(PI[playerid][pMember] < TEAM_FSIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	new targetid, reason[32];
	if(sscanf(params, "ds[32]", targetid, reason)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/unmwarn [ID игрока]");
	else if(targetid == INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(!gPlayerLogged[targetid]) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!PI[targetid][pMember]) return SendClientMessage(playerid, COLOR_RED, "Игрок не состоит в организации!");
	else if(PI[targetid][pLeader]) return SendClientMessage(playerid, COLOR_RED, "Лидеру нельзя снять выговор!");
	else if(PI[targetid][pMember] != PI[playerid][pMember]) return SendClientMessage(playerid, COLOR_RED, "Игрок не состоит в Вашей организации!");
	else if(playerid == targetid) return SendClientMessage(playerid, COLOR_RED, "Самому себя нельзя снять выговор!");
	else if(!PI[targetid][pMemberWarn]) return SendClientMessage(playerid, COLOR_RED, "У игрока нет выговора!");
	new string[128];
	format(string, sizeof(string), "Вы сняли выговор %s. Причина: %s", GetName(targetid), reason);
	SendClientMessage(playerid, COLOR_BLUE, string);
    format(string, sizeof(string), "%s %s снял%s Вам выговор. Причина: %s", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), (PI[playerid][pSex]==1)?(""):("а"), reason);
	SendClientMessage(targetid, COLOR_BLUE, string);
	PI[targetid][pMemberWarn] --;
	MysqlUpdatePlayerInt(targetid, "memberwarn", PI[targetid][pMemberWarn]);
	return 1;
}

CMD:takelic(playerid, params[])
{
	if((PI[playerid][pMember] == TEAM_PPS || PI[playerid][pMember] == TEAM_DPS || PI[playerid][pMember] == TEAM_FSIN) && PI[playerid][pRank] >= 6)
	{
		if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/takelic [id игрока]");
		else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
		else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
		ShowPlayerDialog(playerid, D_LIC+1, 2, "{FFCC00}Отобрать лицензии", "{FFCC00}1. {FFFFFF}Отобрать водительские права\n{FFCC00}2. {FFFFFF}Отобрать лицензию на судоходство\n{FFCC00}3. {FFFFFF}Отобрать лицензию на полеты\n{FFCC00}4. {FFFFFF}Отобрать лицензию на оружие\n{FFCC00}5. {FFFFFF}Отобрать патроны\n{FFCC00}6. {FFFFFF}Отобрать металл\n{FFCC00}7. {FFFFFF}Отобрать наркотики", "Отобрать", "Отмена");
		SetPVarInt(playerid, "LicName", params[0]);
	}
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}

CMD:atake(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_ADMIN) return 1;
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/atake [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	ShowPlayerDialog(playerid, D_LIC+3, 2, "{FFCC00}Отобрать лицензии", "{FFCC00}1. {FFFFFF}Отобрать водительские права\n{FFCC00}2. {FFFFFF}Отобрать лицензию на судоходство\n{FFCC00}3. {FFFFFF}Отобрать лицензию на полеты\n{FFCC00}4. {FFFFFF}Отобрать лицензию на оружие\n{FFCC00}5. {FFFFFF}Отобрать патроны\n{FFCC00}6. {FFFFFF}Отобрать металл\n{FFCC00}7. {FFFFFF}Отобрать наркотики", "Отобрать", "Отмена");
	SetPVarInt(playerid, "LicName", params[0]);
	return 1;
}
CMD:news(playerid, params[])
{
	if(!IsANews(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	NewsPanel(playerid);
	return 1;
}
CMD:edit(playerid)
{
	if(!IsANews(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(PI[playerid][pRank] < 2)
		return SendClientMessage(playerid, COLOR_RED, "Редактирование объявлений доступно со 2-го ранга");

	ShowPlayerDialogEditList(playerid);
	
	return 1;
}
CMD:ad(playerid, params[])
{
    if(PI[playerid][pMuted] > 0) return SendClientMessage(playerid, 0xff6600AA, "У Вас затычка. Узнать подробней: /time");
    else if(PI[playerid][pTime] < 0) return SendClientMessage(playerid, COLOR_RED, "Вы должны играть на сервере более 4 часов!");
    else if(PI[playerid][pPhoneNumber] <= 1) return SendClientMessage(playerid, COLOR_RED, "У Вас нет сим-карты, приобретите её в ближайшем 24/7");
	extract params -> new string:text[128]; else return SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/ad [текст объявления]");

	new fmt_msg[150], count;

	count = strlen ( text );

	format
	(
		fmt_msg,
		sizeof fmt_msg,
		"{ffffff}Содержание: {FFCC00}%s\n\n\
		{ffffff}Цена объявление: {FFCC00}%d рублей\n\
		{ffffff}Вы действительно хотите отправить объявление?",
		text, count*25
	);

	ShowPlayerDialog
	(
		playerid, DIALOG_SEND_EDIT, DIALOG_STYLE_MSGBOX,
		"Объявление",
		fmt_msg,
		"Да", "Нет"
	);

	SetPVarInt(playerid, "pricead", count*25);

	SetPVarString(playerid, "textad", text);
	return 1;
}
//==============================================================================
CMD:npanel(playerid, params[])
{
	if(IsANews(playerid)) ShowPlayerDialog(playerid, D_NMENU+4, 2, "{FFCC00}Панель", "- Установить цену за звонок\n- Установить цену за СМС\n- Установить цену за объявление", "Принять", "Отмена");
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
//==============================================================================
CMD:p(playerid)
{
	if(Mobile[playerid] != -1) return SendClientMessage(playerid, COLOR_RED, "Вы уже разговариваете по телефону!");
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(Mobile[i] == playerid)
		{
			if(Ether[playerid] == true) CallNews[PI[playerid][pNews]-1]++, EtherCalled[i] = true;
			Mobile[playerid] = i;
			SendMes(i, COLOR_RED, "%s поднял трубку мобильного", GetName(playerid));
			PI[i][pPhoneBalance] -= 10;
			MeAction(playerid, "ответил на звонок");
			if(!IsPlayerInAnyVehicle(playerid)) SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
			return 1;
		}
	}
	return 1;
}
//==============================================================================
CMD:sms(playerid, params[])
{
    if(PI[playerid][pPhoneBalance] < 1) return SendClientMessage(playerid, COLOR_RED, "У Вас недостаточно денег!");
    if(PI[playerid][pPhoneNumber] <= 1) return SendClientMessage(playerid, COLOR_RED, "У Вас нет телефона!");
    if(PI[playerid][pMuted] > 0) return SendClientMessage(playerid, 0xff6600AA, "У Вас затычка. Узнать подробней: /time");
	else if(PI[playerid][pJail] > 0) return SendClientMessage(playerid, COLOR_RED, "У Вас изъяли телефон!");
	else if(pCuff[playerid][pCuffee] == playerid) return SendClientMessage(playerid, COLOR_RED, "На Вас надеты наручники!");
   	else if(Mobile[playerid] != -1) return SendClientMessage(playerid, COLOR_RED, "Вы разговариваете по телефону!");
   	else if(!Phone[playerid]) return SendClientMessage(playerid, COLOR_RED, "У Вас выключен телефон!");
    else if(sscanf(params, "ds[100]", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/sms [номер] [текст]");
	else if(!(100 <= params[0] <= 9999999)) return SendClientMessage(playerid, COLOR_RED, "Неверный номер телефона!");
	else if(params[0] == PI[playerid][pPhoneNumber]) return SendClientMessage(playerid, COLOR_RED, "Ты не можешь писать смс самому себе!");
	else if(IsAIP(params[1])) return 0;
	new nidx = -1, plidx = -1;
	foreach(new i: Player)
	{
	    if(!IsPlayerConnected(i) || !PlayerLogged[i]) continue;
	    if(params[0] == 555 || params[0] == 666 || params[0] == 777)
	    {
	    	nidx = i;
	    	break;
    	}
    	else if(params[0] == PI[i][pPhoneNumber])
 	    {
 	        plidx = i;
 	        break;
 	    }
 	}
 	new string[200];
 	if(nidx > -1)
 	{
 	    new select_radio = (params[0] == 555)?(1):(params[0] == 666)?(2):(3);
		if(PI[playerid][pNews] != select_radio) return SendClientMessage(playerid, COLOR_RED, "Вы должны переключиться на волну этой студии!");
 	    else if(!Ether[nidx] && PI[nidx][pMember] == PI[playerid][pNews]+17) return SendClientMessage(playerid, COLOR_RED, "[Ошибка] Радио не принимает СМС!");
 	    new news_name[24];
 	    news_name = (PI[playerid][pNews] == 1)?("ТРК Амазинг Тел.: 555"):(PI[playerid][pNews] == 2)?("ТРК Ритм Тел.: 666"):("Закрыто Тел.: 777");
 	    if(!EtherSms[PI[playerid][pNews]-1]) return SendClientMessage(playerid, COLOR_RED, "Радио не принимает СМС!");
    	if(PI[playerid][pPhoneBalance] < SmsPrice[PI[playerid][pNews]-1]) return SendClientMessage(playerid, COLOR_RED, "На Вашем счету в банке недостаточно денег!");
		PI[playerid][pPhoneBalance] -= SmsPrice[PI[playerid][pNews]-1];
        FracBank[PI[playerid][pNews]+7] += SmsPrice[PI[playerid][pNews]-1];
        PlayerPlaySound(nidx, 1052, 0.0, 0.0, 0.0);
		PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
		format(string, sizeof(string), "SMS: %s | Отправитель: %s [т.%i]", params[1], GetName(playerid), PI[playerid][pPhoneNumber]);
		SendClientMessage(nidx, 0xFFCC00FF, string);
		format(string, sizeof(string), "SMS: %s | Получатель: %s", params[1], news_name);
		SendClientMessage(playerid, 0xFFCC00FF, string);
		SendClientMessage(playerid, COLOR_WHITE, "Ваше сообщение доставлено");
		MeAction(playerid, "достаёт мобильный телефон");
		SetPlayerChatBubble(playerid, (PI[playerid][pSex] == 1)?("Отправил СМС"):("Отправила СМС"), COLOR_YELLOW, 13.0, 10000);
 	}
 	else if(plidx > -1)
 	{
 	    if(!Phone[plidx]) return SendClientMessage(playerid, COLOR_RED, "Игрок выключил телефон!");
	    if(PI[plidx][pJail] > 0) return SendClientMessage(playerid, COLOR_RED, "Абонент временно недоступен!");
		PlayerPlaySound(plidx, 1052, 0.0, 0.0, 0.0);
		PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
		format(string, sizeof(string), "SMS: %s | Отправитель: %s [т.%i]", params[1], GetName(playerid), PI[playerid][pPhoneNumber]);
		SendClientMessage(plidx, 0xFFCC00FF, string);
		format(string, sizeof(string), "SMS: %s | Получатель: %s [т.%i]", params[1], GetName(plidx), PI[plidx][pPhoneNumber]);
		SendClientMessage(playerid, 0xFFCC00FF, string);
		foreach(new x:Player)
		{
			if(AdminInfo[x][admSmsEars])
			{
			    format(string, sizeof(string), "[SMS] %s | Отправил %s [%i] для %s [%i]", params[1], GetName(playerid), playerid, GetName(plidx), plidx);
			    SendClientMessage(x, COLOR_YELLOW, string);
			}
		}
		foreach(new x:Player)
		{
			if(AdminInfo[x][fsbSmsEars])
			{
			    format(string, sizeof(string), "[SMS] %s | Отправил %s [%i] для %s [%i]", params[1], GetName(playerid), playerid, GetName(plidx), plidx);
			    SendClientMessage(x, 0x5da130FF, string);
			}
		}
		PI[playerid][pPhoneBalance] -= 10;
		SendClientMessage(playerid, COLOR_WHITE, "Ваше сообщение доставлено");
		MeAction(playerid, "достаёт мобильный телефон");
		SetPlayerChatBubble(playerid, (PI[playerid][pSex] == 1)?("Отправил СМС"):("Отправила СМС"), COLOR_YELLOW, 13.0, 10000);
 	}
 	else SendClientMessage(playerid, COLOR_RED, "Указанный Вами номер не существует!");
	return 1;
}
//==============================================================================
CMD:h(playerid)
{
	if(Mobile[playerid] == -1) return SendClientMessage(playerid, COLOR_RED, "Вы не разговариваете по телефону!");
	new callerid = Mobile[playerid];
	SendClientMessage(callerid, COLOR_RED, "Собеседник повесил трубку");
	SetPlayerSpecialAction(callerid,SPECIAL_ACTION_STOPUSECELLPHONE);
	CellTime[callerid] = -1;
	CellTime[playerid] = -1;
	Mobile[callerid] = -1;
	if(EtherCalled[playerid] == true) EtherCalled[playerid] = false;
	if(EtherCalled[callerid] == true) EtherCalled[callerid] = false;
	SendClientMessage(playerid,  COLOR_RED, "Вы положили трубку");
	Mobile[playerid] = -1;
	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
	DeletePVar(playerid, "CallTime");
	DeletePVar(callerid, "CallTime");
	return 1;
}
//==============================================================================
CMD:togphone(playerid, params[])
{
    if(PI[playerid][pPhoneNumber] <= 1) return SendClientMessage(playerid, COLOR_RED, "У Вас нет мобильного телефона или SIM-карты!");
    if(Phone[playerid])
    {
        Phone[playerid] = false;
        SendClientMessage(playerid, COLOR_RED, "Вы выключили телефон");
    }
    else
    {
        Phone[playerid] = true;
        SendClientMessage(playerid, COLOR_LIME, "Вы включили телефон");
    }
	return 1;
}
//==============================================================================
CMD:call(playerid, params[])
{
	if(PI[playerid][pPhoneNumber] <= 1) return SendClientMessage(playerid, COLOR_RED, "У Вас нет телефона!");
	if(PI[playerid][pMuted] > 0) return SendClientMessage(playerid, COLOR_RED, "У Вас затычка. Узнать подробней: /time");
	if(Mobile[playerid] != -1) return SendClientMessage(playerid, COLOR_RED, "Вы уже разговариваете по телефону");
	if(Phone[playerid] == false) return SendClientMessage(playerid, COLOR_RED, "У Вас выключен телефон");
	if(Ether[playerid] == true) return SendClientMessage(playerid, COLOR_RED, "Действие невозможно");
	if(sscanf(params, "d", params[0]))
	{
		SendClientMessage(playerid, COLOR_LIME, "• Информация: {ffffff}/call [номер]");
		return 1;
	}
	if(!(1 <= params[0] <= 9999999)) return SendClientMessage(playerid, COLOR_RED, "Неверный номер телефона");
	if(params[0] == PI[playerid][pPhoneNumber]) return SendClientMessage(playerid, COLOR_RED, "Ты не можешь позвонить самому себе");
	if(PI[playerid][pPhoneBalance] < 1) return SendClientMessage(playerid, COLOR_RED, "У Вас недостаточно денег!");
	new fullphone;
	if(params[0] == 911)
	{
		return ShowPlayerDialog(playerid, D_HEAL+3, 2, "{FFCC00}Сервисы", "1. Вызвать механика\n2. Вызвать такси\n3. Вызвать скорую помошь\n4. Вызвать полицию", "Принять", "Назад");
	}
	foreach(new i: Player)
	{
		if(params[0] == PI[i][pPhoneNumber] && PlayerLogged[i] == true)
	{
		if(Phone[i] == false) return SendClientMessage(playerid, COLOR_FADE1, "Абонент вне зоны действия сети");
		if(Ether[i] == true) return SendClientMessage(playerid, COLOR_FADE1, "Действие невозможно");
		if(Mobile[i] != -1) return SendClientMessage(playerid, COLOR_FADE1, "Абонент уже разговаривает по телефону");
		Mobile[playerid] = i;
		SendMes(i, COLOR_BLUE, "Входящий звонок | Номер: {ffffff}%i {0099FF}| Вызывает: {ffffff}%s", PI[playerid][pPhoneNumber], GetName(playerid));
		SendClientMessage(i, COLOR_WHITE, "Используйте {03c03c}/p {ffffff}чтобы ответить или {ff7518}/h {ffffff}чтобы отклонить вызов");
		PlayerPlaySound(i, 23000, 0.0, 0.0, 0.0);
		PlayerPlaySound(playerid, 3600, 0.0, 0.0, 0.0);
		if(!IsPlayerInAnyVehicle(playerid)) SetPlayerSpecialAction(playerid, 11);
		CellTime[playerid] = 0;
		fullphone++;
	}
}
	if(fullphone == 0) return SendClientMessage(playerid, COLOR_RED, "Игрок с этим номером не найден");
	return 1;
}
/*CMD:business(playerid)
{
	if(GetPlayerBizz(playerid) == 0) return SendClientMessage(playerid, COLOR_RED, "Вы не владеете бизнесом!");
	new i = GetPVarInt(playerid, "PlayerBizz");
	BizzStats(playerid, i);
	return 1;
}*/

CMD:business(playerid)
{
	if(GetPlayerBizz(playerid) == 0) return SendClientMessage(playerid, COLOR_RED, "Вы не владеете бизнесом!");
	ShowPlayerDialog(playerid, D_HEAL+10, 2, "Панель управления бизнесом", "{FFCC00}1. {FFFFFF}Информация о бизнесе\n{FFCC00}2. {FFFFFF}Открыть бизнес\n{FFCC00}3. {FFFFFF}Установить цену за товар\n{FFCC00}4. {FFFFFF}Установить цену за вход\n{FFCC00}5. {FFFFFF}Продать бизнес\n{FFCC00}6. {FFFFFF}Заказать продукты", "Принять", "Отмена");
	return 1;
}

CMD:setbizprod(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_GRAND_ADMIN) return 1;
	else if(sscanf(params, "i", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/setbizprod [количество продуктов]");
	for(new idx = 1; idx <= TOTALBIZZ; idx++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 4.0, BizzInfo[idx][bEntrx],BizzInfo[idx][bEntry],BizzInfo[idx][bEntrz]))
		{
			BizzInfo[idx][bProduct] = params[0];
			MysqlUpdateBizzInt(idx, "product", params[0]);
			SendMes(playerid, COLOR_WHITE, "Вы заменили бизнесу {FFCC00}%s {ffffff}продуктов на {FFCC00}%d",BizzInfo[idx][bName], BizzInfo[idx][bProduct]);
		}
	}
	return 1;
}
//==============================================================================
CMD:buybiz(playerid, params[])
{
	if(GetPlayerBizz(playerid) == 1) return SendClientMessage(playerid, COLOR_RED, "Вы уже владеете бизнесом!");
	new full, full_;
	new string[512];
	for(new idx = 1; idx <= TOTALBIZZ; idx++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 5.0, BizzInfo[idx][bEntrx],BizzInfo[idx][bEntry],BizzInfo[idx][bEntrz]))
		{
			full++;
			if(!strcmp(BizzInfo[idx][bOwner],"None",true))
			{
				full_++;
				if(PI[playerid][pCash] < BizzInfo[idx][bPrice]) return SendClientMessage(playerid, COLOR_RED, "У Вас недостаточно денег!");
				else
				{
					PI[playerid][pCash] -= BizzInfo[idx][bPrice];
					BizzInfo[idx][bBuyPrice] = BizzInfo[idx][bPrice] / 2;
					BizzInfo[idx][bProduct] = 100;
					BizzInfo[idx][bMoney] = BizzInfo[idx][bBuyPrice] / 2000;
					BizzInfo[idx][bEnter] = 0;
					BizzInfo[idx][bTill] = 50;
					SendClientMessage(playerid, COLOR_WHITE, "Поздравляем с покупкой бизнеса! Теперь каждый час с вашего счёта будут взимать сумму в размере ДОДЕЛАТЬ р.");
					SendClientMessage(playerid, COLOR_WHITE, "Налоговый счёт вы можете пополнять в одном из банков.");
					SendClientMessage(playerid, COLOR_WHITE, "У вас есть 24 часа, чтобы купить лицензию, иначе ваш бизнес будет продан за гос.стоимость");
					SendClientMessage(playerid, COLOR_WHITE, "Покупка лицензии: /gps >> Государственные организации >> Администрация Области");
					SendClientMessage(playerid, COLOR_WHITE, "Команды: /bmenu - управление бизнесом, /getbizstats - информация о бизнесе.");
					SendMes(playerid, COLOR_WHITE, "Вы купили бизнес {FFCC00}%s {ffffff}за {FFFFFF}%i {ffffff}Рублей. У Вас осталось: {FFCC00}%i {ffffff}рублей", BizzInfo[idx][bName], BizzInfo[idx][bPrice], PI[playerid][pCash]);
					SendMes(playerid, COLOR_LIME, "Подсказка: {FFFFFF}Аренда бизнеса оплачена на 3 час (%i рублей), не забывайте регулярно следить за его балансом.", BizzInfo[idx][bMoney]);
					SendClientMessage(playerid, COLOR_LIME, "Подсказка: {FFFFFF}Приобретите лицензию На Ваш бизнес, если в течении 24 часов этого не будет, он будет продан государству!");
					strmid(BizzInfo[idx][bOwner],GetName(playerid), 0, strlen(GetName(playerid)), MAX_PLAYER_NAME);
					format(string, sizeof(string), "UPDATE `bizz` SET owner = '%s', buyprice = %i , product = %i, money = %i WHERE id = '%d' LIMIT 1", BizzInfo[idx][bOwner], BizzInfo[idx][bBuyPrice], BizzInfo[idx][bProduct],BizzInfo[idx][bMoney], idx);
					mysql_tquery(dbHandle, string, "", "");
					UpdateBizz(idx);
					SaveAcc();
				}
			}
			else full_++;
		}
	}
	if(full == 0) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится рядом с бизнесом!");
	if(full_ == 0) return SendClientMessage(playerid, COLOR_RED, "Бизнес уже имеет владельца!");
	return 1;
}
//==============================================================================
CMD:radio(playerid, params[])
{
	ShowPlayerDialog(playerid, 9345, DIALOG_STYLE_LIST, "{FFCC00}Выберите радиостанцию", "1. Радио Шансон\n2. Наше Радио\n3. Радио Рекорд\n4. Зайцев.FM (Pop)\n5. Зайцев.FM (RnB)\n6. Выключить радио", "Выбор", "Выход");
	return 1;
}
//==============================================================================
CMD:hmenu(playerid)
{
	if(GetPlayerHouse(playerid) == 0) return SendClientMessage(playerid, COLOR_RED, "У Вас нет дома!");
	new i = GetPVarInt(playerid, "PlayerHouse");
	if(strcmp(GetName(playerid), HouseInfo[i][hOwner], true) == 0)
	{
		if((IsPlayerInRangeOfPoint(playerid,60.0,HouseInfo[i][hExitx],HouseInfo[i][hExity],HouseInfo[i][hExitz]) || IsPlayerInRangeOfPoint(playerid,3.0,2934.4077,2967.4949,3176.5769)) && GetPlayerVirtualWorld(playerid) == HouseInfo[i][hVirtual])
		{
		    new string[400];
		    format(string, sizeof(string), "{ffffff}\
			{0099FF}1. {FFFFFF}Открыть / закрыть дом\n\
			{0099FF}2. {FFFFFF}Гардероб\n\
			{0099FF}3. {FFFFFF}Оплачен на: {FFAA44}%d / 10 дней\n{FFFFFF}\
			{0099FF}4. {FFFFFF}Аптечек в доме: {FFAA44}%i шт\n{FFFFFF}\
			{0099FF}5. {FFFFFF}Продать дом", HouseInfo[i][hOplata], HouseInfo[i][hHeal]);
			ShowPlayerDialog(playerid, D_HOME, 2, "{FFCC00}Панель управления домом", string, "Принять", "Отмена");
		}
		else SendClientMessage(playerid, COLOR_RED, "Вы должны находится в вашем доме!");
	}
	return 1;
}
//==============================================================================
CMD:gethouse(playerid, params[])
{
	if(PI[playerid][pAdmin] != 6) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "i",params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/gethouse [Номер Дома]");
	new i = params[0];
	new klass[32];
	new lock[32];
	if(HouseInfo[i][hDiscript] == 'A')
	{
	    klass = "низкий";
	}
	else if(HouseInfo[i][hDiscript] == 'B')
	{
	    klass = "средний";
	}
	else if(HouseInfo[i][hDiscript] == 'C')
	{
	    klass = "Высокий";
	}
	else if(HouseInfo[i][hDiscript] == 'D')
	{
	    klass = "элитный";
	}
	else if(HouseInfo[i][hDiscript] == 'E')
	{
	    klass = "дэлюксовый [VIP]";
	}
	else if(HouseInfo[i][hDiscript] == 'F')
	{
	    klass = "особняк";
	}
	else if(HouseInfo[i][hDiscript] == 'G')
	{
	    klass = "квартира";
	}
	if(HouseInfo[i][hLock] == 1)
	{
	    lock = "{FF0000}закрыт";
	}
	else if(HouseInfo[i][hLock] == 0)
	{
	    lock = "{FFCC00}открыт";
	}
	new string[500];
	format(string, sizeof(string), "{FFFFFF}Дом №{FFCC00}\t\t%d\n\n{FFFFFF}Оплачен на:\t{FFCC00}%d дней\n{FFFFFF}Класс:{FFCC00}\t\t%s\n{FFFFFF}Стоимость:\t{FFCC00}%d рублей\n{ffffff}Состояние:\t%s\n{ffffff}Цена за сутки:{FFCC00}\t%d",i,HouseInfo[i][hOplata],klass,HouseInfo[i][hBuyPrice]*2,lock,GetHomeOplata(i));
	Dialog(playerid,D_HOME+3,DSM,"{FFCC00}Информация о Доме",string,"Назад","");
	return 1;
}
//==============================================================================
CMD:getbizstats(playerid, params[])
{
	new full = 0;
	for(new i = 1; i <= TOTALBIZZ; i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 5.0, BizzInfo[i][bEntrx],BizzInfo[i][bEntry],BizzInfo[i][bEntrz]))
		{
			if(!strcmp(BizzInfo[i][bOwner],"None",true)) return SendClientMessage(playerid, COLOR_RED, "Бизнес не имеет владельца!");
			BizzStats(playerid, i);
			full++;
		}
	}
	if(full == 0) SendClientMessage(playerid, COLOR_RED, "Вы должны находится рядом с бизнесом!");
	return 1;
}
//==============================================================================
CMD:bizlist(playerid, params[])
{
	if(!IsAMafia(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	SendClientMessage(playerid, COLOR_GREEN, "Завоеванные бизнесы:");
	new string[128];
	for(new h = 0; h < 200; h++)
	{
		new mafiapay = BizzPay[h] / 10;
		switch(PI[playerid][pMember])
		{
			case TEAM_CSKA:
			{
				if(BizzInfo[h][bMafia] == TEAM_CSKA)
				{
				    format(string, sizeof(string), "- %s, прибыль: %d", BizzInfo[h][bName], mafiapay);
					SendClientMessage(playerid, COLOR_YELLOW2, string);
				}
			}
			case TEAM_SPARTAK:
			{
				if(BizzInfo[h][bMafia] == TEAM_SPARTAK)
				{
				    format(string, sizeof(string), "- %s, прибыль: %d", BizzInfo[h][bName], mafiapay);
					SendClientMessage(playerid, COLOR_YELLOW2, string);
				}
			}
		}
	}
	return 1;
}
CMD:bizwar(playerid, params[])
{
	new factionm = 0;
	new playerposed;
	if(PI[playerid][pLeader] != 0) factionm = PI[playerid][pLeader];
	else if(PI[playerid][pMember] != 0 && PI[playerid][pLeader] == 0) factionm = PI[playerid][pMember];
	else factionm = 0;
	if(!IsAGang(playerid)) return 1;
	if(startwar == 1) return SendClientMessage(playerid, COLOR_RED, "Война уже начата!");
	if(FrakCDm[factionm] > 0) return SendClientMessage(playerid, COLOR_RED, "Следующий захват возможен через час!");
	for(new h = 0; h < 200; h++)
	{
        if(PI[playerid][pMember] == TEAM_SPARTAK && PI[playerid][pRank] >= 7 || PI[playerid][pMember] == TEAM_CSKA && PI[playerid][pRank] >= 7 || PI[playerid][pMember] == TEAM_DINAMO && PI[playerid][pRank] >= 7 || PI[playerid][pMember] == TEAM_ZENIT && PI[playerid][pRank] >= 7)
		{
			if(IsPlayerInRangeOfPoint(playerid, 6.0, BizzInfo[h][bEntrx],BizzInfo[h][bEntry],BizzInfo[h][bEntrz]))
    		{
    		    new string[64];
    		    playerposed = 1;
    			if(BizzInfo[h][bMafia] == PI[playerid][pMember]) return SendClientMessage(playerid, COLOR_RED, "Бизнес принадлежит Вам!");
				if(war > 0)
				{
					format(string, sizeof(string), "Войну можно начать через %d сек", war);
					SendClientMessage(playerid, COLOR_RED, string);
					return 1;
				}
				if(BizzInfo[h][bMafia] == 0)
				{
					BizzInfo[h][bMafia] = PI[playerid][pMember];
					switch(BizzInfo[h][bMafia])
					{
					   	case TEAM_SPARTAK: MafiaTotalBizz[0]++;
					   	case TEAM_CSKA: MafiaTotalBizz[1]++;
					   	case TEAM_DINAMO: MafiaTotalBizz[2]++;
					   	case TEAM_ZENIT: MafiaTotalBizz[3]++;
					}
					SendFMes(PI[playerid][pMember], COLOR_LIME, "[F] Ваша мафия захватила новый бизнес!");
					MysqlUpdateBizzInt(h, "mafia", BizzInfo[h][bMafia]);
					return 1;
				}
				if(BizzInfo[h][bMafia] > 0)
				{
					startwar = 1;
					format(string,sizeof(string),"[R] %s назначил стрелу за %s мафии %s",GetName(playerid),BizzInfo[h][bName],BizzInfo[h][bMafia]);
					SendFMes(PI[playerid][pMember],COLOR_LIME,string);
					format(string,sizeof(string),"Мафия %s назначила Вам стрелу за бизнес %s",Fraction_Name[PI[playerid][pMember]],BizzInfo[h][bName]);
					SendFMes(BizzInfo[h][bMafia],COLOR_REDD,string);
					SendFMes(BizzInfo[h][bMafia],COLOR_LIME,"Место встречи - Заброшенный аэропорт");
					SendFMes(BizzInfo[h][bMafia],COLOR_LIME,"У Вас есть 10 минут, чтобы отбить бизнес!");
					BizzInfo[h][bZahvat] = 1;
					war = 1200;
					MZSafeTime[0] = 600;
					FrakCDm[factionm]  = 1800;
					MZInfo[0][mNapad] = PI[playerid][pMember];
					MZInfo[0][mFrakVlad] = BizzInfo[h][bMafia];
					ZoneTimerm[0] = 130;
					ZoneOnBattlem[0] = 1;
					zons = GangZoneCreate(446.9828,-215.6673,492.6197,-310.9768);
					GangZoneShowForAll(zons, COLOR_NEWS);
					GangZoneFlashForAll(zons, COLOR_RED);
				}
			}
		}
	}
	if(playerposed == 0) SendClientMessage(playerid, COLOR_RED, "Вы находитесь далеко от бизнеса!");
    return 1;
}
/*CMD:capture(playerid, params[])
{
	if(!IsAMafia(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(PI[playerid][pRank] < 7) return SendClientMessage(playerid,COLOR_RED,"Захват территории доступен с 7 ранга и выше!");
	new h; gettime(h);
	if(h < 12 || h > 21) return SendClientMessage(playerid, COLOR_RED, "Проводить захват можно только с 12:00 до 22:00");
	new faction = PI[playerid][pMember];
	if(FrakCD != 0)
	{
		new fd[128];
		format(fd,sizeof(fd),"Следующий захват территории возможен через %d минут(ы)", FrakCD/60);
		SendClientMessage(playerid,COLOR_RED,fd);
		return 1;
	}
	if(!IsInAllowed(playerid)) return SendClientMessage(playerid, COLOR_RED, "Ваша банда уже участвует в захвате зон!");
	new str[128];
 	for(new i = 0; i < sizeof(GZInfo); i++)
	{
  		if(IsPlayerToSquare(playerid, GZInfo[i][gCoords][0], GZInfo[i][gCoords][1],GZInfo[i][gCoords][2],GZInfo[i][gCoords][3]) && ZoneOnBattle[i] == 0)
		{
			if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Нельзя использовать в машине!");
			{
				if(GZInfo[i][gFrak] == faction) return SendClientMessage(playerid, COLOR_RED, "Вы не можете захватывать зону вашей банды!");
				if(GZInfo[i][gFrak] == 0) return SendClientMessage(playerid, COLOR_RED, "Нельзя захватить эту территорию");
				if(GZInfo[i][gFrak] == 7 && b_Capture{0}) return SendClientMessage(playerid, COLOR_RED, "Доступ данной банды к войне за территории закрыт");
				if(GZInfo[i][gFrak] == 8 && b_Capture{1}) return SendClientMessage(playerid, COLOR_RED, "Доступ данной банды к войне за территории закрыт");
				if(GZInfo[i][gFrak] == 9 && b_Capture{2}) return SendClientMessage(playerid, COLOR_RED, "Доступ данной банды к войне за территории закрыт");
				if(GZInfo[i][gFrak] == 10 && b_Capture{3}) return SendClientMessage(playerid, COLOR_RED, "Доступ данной банды к войне за территории закрыт");
				if(GZInfo[i][gFrak] == 11 && b_Capture{4}) return SendClientMessage(playerid, COLOR_RED, "Доступ данной банды к войне за территории закрыт");
				if(IsCapture == true) return SendClientMessage(playerid, COLOR_RED, "Уже происходит захват одной из зон. Дождитесь окончания!");
				if(IsPlayerInBandOnline(faction) < 5) return SendClientMessage(playerid, COLOR_RED, "В вашей банде мало игроков онлайн, нужно минимум 2!");
				if(IsPlayerInBandOnline(GZInfo[i][gFrak]) < 5)
				{
					format(str, sizeof(str), "У банды \"%s\" мало игроков,нужно минимум 5!", GetGangName(GZInfo[i][gFrak]));
					SendClientMessage(playerid, COLOR_RED, str);
					return 1;
				}
    			format(str, sizeof(str), "На Вашу территорию напала %s, У Вас есть 10 минут, чтобы отстоять её.", Fraction_Name[PI[playerid][pMember]]);
				SendFMes(GZInfo[i][gFrak], COLOR_BLUE, str);
				format(str, sizeof(str), "Если по истечению времени Вас не будет на территории, она перейдет к %s",Fraction_Name[PI[playerid][pMember]]);
				SendFMes(GZInfo[i][gFrak], COLOR_RED, str);
				format(str, sizeof(str), "[R] %s [%d] напал на территорию ОПГ '%s'",GetName(playerid),playerid,GetGangName(GZInfo[i][gFrak]));
				SendFMes(faction, COLOR_LIME, str);
    			GangZoneFlashForAll(GangZone[i],GetGangZoneColor(faction));
				GZSafeTime[i] = 840;
				FrakCD = 7200;
				GZInfo[i][gNapad] = faction;
				ZoneOnBattle[i] = 1;
				GangInfo[faction][capture] = 1;
				GangInfo[GZInfo[i][gFrak]][capture] = 1;
				GangInfo[GZInfo[i][gFrak]][captureid] = faction;
				GangInfo[faction][captureid] = faction;
				GangInfo[faction][gangnumber] = 1;
				GangInfo[GZInfo[i][gFrak]][gangnumber] = 0;
				CaptureStart(faction, GZInfo[i][gFrak]);
		        format(str, sizeof(str), "[A] ОПГ '%s' напала на территорию ОПГ '%s'",GetGangName(faction),GetGangName(GZInfo[i][gFrak]));
		        SendAdminMessage(COLOR_GREY, str);
			}
		}
	}
	return 1;
}*/
CMD:break(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid) == 1) return SendClientMessage(playerid, COLOR_RED, "Вы находитесь в транспорте");
	if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return SendClientMessage(playerid, COLOR_RED, "Вы находитесь в интерьере");

	if(PI[playerid][pMember] != TEAM_PPS)
		return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная возможность");

	if(!strlen(params)) return SendClientMessage(playerid, COLOR_LIME, "Информация:{ffffff}  /break [(1-4)]");
	extract params -> new type;

	if(!(1 <= type <= 4))
		return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/break [(1-4)]");

	if(IsValidDynamicObject(bobject[playerid]))
    {
        DestroyDynamicObject(bobject[playerid]);
        DestroyDynamic3DTextLabel(btext[playerid]);
        bobject[playerid] = 0;
		return 1;
    }

	new Float:px,Float:py,Float:pz;
	GetPlayerPos(playerid, px, py, pz);

	new Float:angle;
	GetPlayerFacingAngle(playerid, angle);

	px += floatsin(-angle, degrees);
	py += floatcos(-angle, degrees);

	new string[15];
	format(string, sizeof string, "(( %d ))", playerid);

	btext[playerid] = CreateDynamic3DTextLabel(string, 0xBB995580, px, py, pz-1.0, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 5.0);

	switch(type)
	{
		case 1: bobject[playerid] = CreateDynamicObject(1228, px, py, pz-0.7, 0.0, 0.0, angle-180.0);
		case 2: bobject[playerid] = CreateDynamicObject(1237, px, py, pz-1.0, 0.0, 0.0, angle-180.0);
		case 3: bobject[playerid] = CreateDynamicObject(1423, px, py, pz-1.0, 0.0, 0.0, angle-180.0);
		case 4: bobject[playerid] = CreateDynamicObject(1422, px, py, pz-0.82, 0.0, 0.0, angle-180.0);
	}
	return 1;
}
CMD:conus(playerid)
{
	if(IsPlayerInAnyVehicle(playerid) == 1) return SendClientMessage(playerid, COLOR_RED, "Вы находитесь в транспорте");
	if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return SendClientMessage(playerid, COLOR_RED, "Вы находитесь в интерьере");

	if(PI[playerid][pMember] != TEAM_PPS)
		return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная возможность");

	if(PI[playerid][pRank] < 3)
		return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная возможность");

	if(totalconus == 100)
		return SendClientMessage(playerid, COLOR_RED, "Конусы закончились");

	if(pdobject[playerid] == 5)
		return SendClientMessage(playerid, COLOR_RED, "Вы установили максимальное количество конусов");

	totalconus ++;
	pdobject[playerid] ++;

	new Float:px,Float:py,Float:pz;
	GetPlayerPos(playerid, px, py, pz);

	new Float:angle;
	GetPlayerFacingAngle(playerid, angle);

	px += floatsin(-angle, degrees);
	py += floatcos(-angle, degrees);

	conus[totalconus] = CreateDynamicObject(1238, px, py, pz-0.69, 0.0, 0.0, angle-180.0);

	return Streamer_Update(playerid, STREAMER_TYPE_OBJECT);
}

CMD:delconus(playerid)
{
	if(IsPlayerInAnyVehicle(playerid) == 1) return SendClientMessage(playerid, COLOR_RED, "Вы не можете использовать функцию в данный момент");
	if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return SendClientMessage(playerid, COLOR_RED, "Вы не должны находится в помещениях");

	if(PI[playerid][pMember] != TEAM_PPS)
		return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная возможность");

	if(PI[playerid][pRank] < 3)
		return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная возможность");

	new Float: cx, Float: cy, Float: cz;

	for(new i = 0; i < 100; i++)
	{
		if(IsValidDynamicObject(conus[i]))
		{
			GetDynamicObjectPos(conus[i], cx, cy, cz);

			if(IsPlayerInRangeOfPoint(playerid, 1.0, cx, cy, cz))
			{
				DestroyDynamicObject(conus[i]);
				conus[i] = -1;
				SendClientMessage(playerid, 0x99CC00FF, "Вы убрали конус");
				totalconus --;
				pdobject[playerid] --;
				return 1;
			}
		}
	}
	return Streamer_Update(playerid, STREAMER_TYPE_OBJECT);
}
CMD:su(playerid, params[]) return callcmd::suspect(playerid, params);
CMD:suspect(playerid, params[])
{
	if(!IsACop(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(sscanf(params, "us", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/su [ид игрока] [Преступление]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pJail] > 0) return SendClientMessage(playerid, COLOR_RED, "Данный игрок уже находится в тюрьме!");
	else if(IsACop(params[0])) return SendClientMessage(playerid, COLOR_RED, "Данный человек законник");
	else if(PI[playerid][pMember] != TEAM_FSIN && PI[params[0]][pWanted] >= 6) return SendClientMessage(playerid, COLOR_RED, "Вы не можете дать более 3-ех звезд!");
	else if(PI[playerid][pMember] == TEAM_FSIN && PI[params[0]][pWanted] >= 6) return SendClientMessage(playerid, COLOR_RED, "Вы не можете дать более 6-ти звезд!");
	PI[params[0]][pWanted]++;
	if(PI[params[0]][pWanted]-1 == 0) PI[params[0]][pWantedTime] = 1800 + random(300);
	SetPlayerWantedLevel(params[0],PI[params[0]][pWanted]);
	SetPlayerCriminal(params[0], GetName(playerid), params[1]);
	return 1;
}

CMD:frisk(playerid, params[])
{
	if(IsACop(playerid) || PI[playerid][pMember] == TEAM_VDV)
	{
		if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация:{ffffff} /frisk [id игрока]");
		else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
		else if(playerid == params[0]) return SendClientMessage(playerid, COLOR_RED, "Вы не можете обыскать себя!");
		else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
		SendMes(playerid, COLOR_WHITE, "Имущество %s", GetName(params[0]));
		SendMes(playerid, COLOR_RED, "- %s", (PI[params[0]][pPatron]) ? ("Патроны") : ("Пусто"));
		SendMes(playerid, COLOR_RED, "- %s", (PI[params[0]][pGunAmount]) ? ("Метал") : ("Пусто"));
		SendMes(playerid, COLOR_RED, "- %s", (PI[params[0]][pDrugs]) ? ("Наркотики") : ("Пусто"));
		new string[100];
		if(PI[playerid][pSex] == 1) format(string, sizeof(string), "достал перчатки и обыскал %s", GetName(params[0]));
		else format(string, sizeof(string), "достала перчатки и обыскала %s", GetName(params[0]));
		MeAction(playerid, string);
	}
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
CMD:ticket(playerid, params[])
{
	if(!IsACop(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(sscanf(params, "iis", params[0], params[1], params[2])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/ticket [id игрока] [сумма] [причина]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	else if(params[1] < 1 || params[1] > 10000) return SendClientMessage(playerid, COLOR_RED, "Сумма штрафа от 1 рублей до 10000 рублей");
	SendMes(playerid, COLOR_BLUE, "Вы выписали штраф в размере %d руб. на имя %s. Причина: %s", params[1], GetName(params[0]), params[2]);
	SendMes(params[0], COLOR_BLUE, "Офицер %s выписал Вам штраф в размере %d рублей. Причина: %s", GetName(playerid), params[1], params[2]);
	SendClientMessage(params[0], COLOR_WHITE, "{FFFFFF}Нажмите {03c03c}Y {FFFFFF}чтобы согласиться или {ff7518}N {FFFFFF}для отказа");
	SetPVarInt(params[0], "TicketPlayer", playerid);
	SetPVarInt(params[0], "TicketSumma", params[1]);
	SetPVarInt(params[0], "KeyTicket", 1);
	return 1;
}
CMD:canceldice(playerid)
{
    if(KostiName[playerid] == INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_DARKORANGE, "Вы не предлагали никому игру!");
	Predlog[playerid] = Predlog[KostiName[playerid]] =
	KostiMoney[playerid] = KostiMoney[KostiName[playerid]] =
	ZapretDice[playerid] = ZapretDice[KostiName[playerid]] = 0;
	SendClientMessage(KostiName[playerid], COLOR_RED, "Игрок отказался от ставки!");
	SendClientMessage(playerid, COLOR_RED, "Вы отказались играть!");
	KostiName[KostiName[playerid]] = KostiName[playerid] = INVALID_PLAYER_ID;
	return true;
}
CMD:dice(playerid, params[])
{
    if(!IsPlayerInRangeOfPoint(playerid,70.0,-925.0152,2863.8723,1043.8800)) return SendClientMessage(playerid, COLOR_GREY, "Вы должны находиться в казино!");
    else if(KostiMoney[playerid] != 0 || ZapretDice[playerid] != 0) return SendClientMessage(playerid, COLOR_DARKORANGE, "Вам уже предложили игру!");
    else if(sscanf(params, "ud", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/dice [ид игрока] [сумма]");
    else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_DARKORANGE, PlayerIsNotOnline);
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_DARKORANGE, PlayerIsNotAuthorized);
    else if(params[1] < 500 || params[1] > 5000000) return SendClientMessage(playerid, COLOR_DARKORANGE, "Минимальная ставка 500 рублей, максимальная 5 000 000 рублей");
    else if(ZapretDice[params[0]] == 1) return SendClientMessage(playerid, COLOR_DARKORANGE, "В данный момент игрок не может играть!");
	else if(!ProxDetectorS(6.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_DARKORANGE, "Игрок не рядом с Вами!");
    else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_DARKORANGE, "Самому себе нельзя предлагать игру");
    new string[128];
    format(string, sizeof(string), "Вы предложили %s бросить кости на %i рублей", GetName(params[0]), params[1]);
    SendClientMessage(playerid, COLOR_BLUE, string);
    format(string, sizeof(string), "%s предлагает Вам бросить кости. Ставка: %i рублей", GetName(playerid), params[1]);
    SendClientMessage(params[0], COLOR_BLUE, string);
    SendClientMessage(params[0], COLOR_WHITE, PlayerAccess);
    ZapretDice[playerid] = ZapretDice[params[0]] = 1;
    KostiName[playerid] = params[0];
    KostiName[params[0]] = playerid;
    KostiMoney[params[0]] = params[1];
    KostiMoney[playerid] = params[1];
    Predlog[playerid] = 1;
    return 1;
}

/*CMD:dice(playerid, params[])
{
    if(!IsPlayerInRangeOfPoint(playerid,30.0,1603.8601,987.0284,1819.0200) && !IsPlayerInRangeOfPoint(playerid,30.0, 503.0951,-25.0348,1907.3684)) return SendClientMessage(playerid, COLOR_RED, "Вы должны находиться в казино!");
    else if(KostiMoney[playerid] != 0 || ZapretDice[playerid] != 0) return SendClientMessage(playerid, COLOR_RED, "Вам уже предложили игру!");
    else if(sscanf(params, "ud", params[0], params[1])) return SendClientMessage(playerid, 0xFFCC00AA, "•[Подсказка] {FFFFFF}Введите: /dice [id игрока] [ставка (в фишках)]");
    else if(!IsPlayerConnected(params[0])) return SendMess(playerid, MSG_PLAYER_OFFLINE);
	else if(PlayerLogged[params[0]] == false) return SendMess(playerid, MSG_PLAYER_NOT_LOGGED);
    else if(params[1] < 1000 || params[1] > 10000000) return SendClientMessage(playerid, COLOR_RED, "Минимальная ставка 1.000 фишек, максимальная 10.000.000 фишек");
    else if(ZapretDice[params[0]] == 1) return SendClientMessage(playerid, COLOR_RED, "В данный момент игрок не может играть!");
	else if(!ProxDetectorS(6.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок не рядом с Вами!");
    else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Самому себе нельзя предлагать игру");
	else if(PhoneNumbers[playerid][0] < params[1]) return SendClientMessage(playerid, COLOR_RED, "У Вас недостаточно фишек. Вы можете купить фишки в обменнике казино");
	SendClientMessage(playerid, COLOR_YELLOW, "Для того чтобы отказатся от своей ставки, введите /canceldice");
    new string[128];
    format(string, sizeof(string), "Вы предложили %s бросить кости. Ставка: %i", GetName(params[0]), params[1]);
    SendClientMessage(playerid, COLOR_BLUE, string);
    format(string, sizeof(string), "%s предлагает бросить кости. Ставка: %i", GetName(playerid), params[1]);
    SendClientMessage(params[0], COLOR_BLUE, string);
    SendMess(params[0], MSG_PLAYER_ACCESS);
    ZapretDice[playerid] = ZapretDice[params[0]] = 1;
    KostiName[playerid] = params[0];
    KostiName[params[0]] = playerid;
    KostiMoney[params[0]] = KostiMoney[playerid] = params[1];
    Predlog[playerid] = 1;
    return 1;
}*/

CMD:history(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_SUPER_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	new nickname[MAX_PLAYER_NAME];
	if(sscanf(params, "s[24]", nickname)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/history [имя игрока]");
	new string[128];
	format(string, sizeof(string), "SELECT `id` FROM `accounts` WHERE `name` = '%s'", nickname);
	mysql_tquery(dbHandle, string, "OnPlayerHistoryName", "d", playerid);
	return 1;
}
/*CMD:need(playerid)
{
	new string[256];
	format(string, sizeof(string), "{FFFFFF}Сытость:	{FFCC00}%d%%\n{FFFFFF}Жажда:		{FFCC00}%d%%\n{FFFFFF}Туалет:		{FFCC00}%d%%\n{FFFFFF}Гигиена:	{FFCC00}%d%%", PI[playerid][pHunger], PI[playerid][pZhazhda], PI[playerid][pTualet], PI[playerid][pGigiena]);
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{FFCC00}Нужды", string, "Закрыть", "");
	return 1;
}*/
//==============================================================================
CMD:stats(playerid)
{
    ShowPlayerStatsDialog(playerid, playerid);
	return 1;
}
//==============================================================================
CMD:mm(playerid) return callcmd::menu(playerid);
CMD:mn(playerid) return callcmd::menu(playerid);
CMD:menu(playerid)
{   
    PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
	ShowPlayerMenuDialog(playerid);
	return 1;
}
//==============================================================================
CMD:astats(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_GRAND) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");

	if(sscanf(params, "i", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/astats [ID администратора]");

	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	if(PI[params[0]][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "Этот игрок не является администратором");

    new stats_text [ 1364 ], str_stats [ 128 ], h, m, s;

	gettime(h, m, s);

	format(str_stats, sizeof str_stats, "{FFFFFF}Статистика администратора:\t\t{FFCC00}%s\n\n", PI[params[0]][pName]), strcat(stats_text, str_stats);
	format(str_stats, sizeof str_stats, "{FFFFFF}Кикнул игроков:\t\t{ffffff}%d раз\n", PI[params[0]][pCKICK]), strcat(stats_text, str_stats);
	format(str_stats, sizeof str_stats, "{FFFFFF}Забанил игроков:\t\t{ffffff}%d раз\n", PI[params[0]][pCBAN]), strcat(stats_text, str_stats);
	format(str_stats, sizeof str_stats, "{FFFFFF}Посадил в JAIL:\t\t{ffffff}%d раз\n", PI[params[0]][pCJAIL]), strcat(stats_text, str_stats);
	format(str_stats, sizeof str_stats, "{FFFFFF}Ответил на репорт:\t\t{ffffff}%d раз\n", PI[params[0]][pCREPORT]), strcat(stats_text, str_stats);
	format(str_stats, sizeof str_stats, "{FFFFFF}Выдал молчанку:\t\t{ffffff}%d раз\n", PI[params[0]][pCMUTE]), strcat(stats_text, str_stats);
	format(str_stats, sizeof str_stats, "{FFFFFF}Слэпнул игроков:\t\t{ffffff}%d раз\n", PI[params[0]][pCSLAP]), strcat(stats_text, str_stats);
	format(str_stats, sizeof str_stats, "{FFFFFF}Создал автомобилей:\t\t{ffffff}%d шт.", PI[params[0]][pCVEH]), strcat(stats_text, str_stats);
	ShowPlayerDialog(playerid, dialog_SHOW_ASTAT, DIALOG_STYLE_MSGBOX, "{FFCC00}Статистика администратора", stats_text, "Закрыть", "");
	return 1;
}
CMD:viphelp(playerid)
{
	if(!PI[playerid][pVip]) return SendClientMessage(playerid, COLOR_RED, "Вы не имеете VIP статус");
	new str[68], string[576];
	new year, month, day;
	new current_date = getdate(year, month, day);
	new time_left = PI[playerid][pVipTime] - current_date;
	//SendClientMessage(playerid, 0xff66ccFF, "Срок действия VIP аккаунта:{FFFFFF} %i дней", time_left);
	format(str, sizeof(str), "{FFCC00}Вы владеете VIP статусом. Осталось дней: %i\n\n", time_left);
	strcat(string, str);
	strcat(string, "{FFFFFF}Ниже приведены ваши преимущества.\n");
	strcat(string, "1) Ускоренное лечение в больнице\n");
	strcat(string, "2) Удаление тюнинга с личного транспорта (/removetuning)\n");
	strcat(string, "3) Возможность покинуть организацию самому (/leave)\n");
	strcat(string, "4) Каждую 4-ую зарплату +1 респект\n");
	strcat(string, "5) Прокачка скиллов в 2 раза быстрей\n");
	strcat(string, "6) /makegun - создание оружие\n");
	strcat(string, "7) Уменьшенное время на отправку вопроса/репорта\n");
	strcat(string, "8) Возможность уволиться с работы не на месте устройства (/quitjob)\n");
	strcat(string, "9) /vsellgun - продажа оружие игроку");
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{FFCC00}VIP статус", string, "Закрыть", "");
	return 1;
}
CMD:apanel(playerid)
{
	if(PI[playerid][pAdmin] < ADM_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
   	ShowPlayerDialog(playerid, D_APANEL, 2, "{FFCC00}Панель администратора", "\
   	{ffffff}VIP игроки\t\t\t{63BD4E}[Online]\n\
 	{ffffff}Список администрации\t{63BD4E}[Online]\n\
 	{ffffff}Весь список администрации\n\
 	{ffffff}Настройки администратора\t{FFCC00}[4LVL+]\n\
  	{ffffff}Управление сервером\
	", "Выбрать", "Отмена");
	return 1;
}
CMD:get(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_SUPER_MODER) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/get [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	new string[64], string_dialogue[512];
	format(string, sizeof(string), "{FFCC00}Номер аккаунта:\t%i\n", PI[params[0]][pID]);
	strcat(string_dialogue, string);
	format(string, sizeof(string), "{FFCC00}Рег.дата:\t%s\n", PI[params[0]][pRegData]);
	strcat(string_dialogue, string);
	format(string, sizeof(string), "{FFCC00}Рег.IP:\t%s\n", PI[params[0]][pRegIP]);
	strcat(string_dialogue, string);
	format(string, sizeof(string), "{FFCC00}Последний IP:\t%s\n", PI[params[0]][pLastIP]);
	strcat(string_dialogue, string);
	format(string, sizeof(string), "{FFCC00}Уровень:\t\t%i\n", PI[params[0]][pLevel]);
	strcat(string_dialogue, string);
	format(string, sizeof(string), "{FFCC00}Наличные:\t\t%i\n", PI[params[0]][pCash]);
	strcat(string_dialogue, string);
	format(string, sizeof(string), "{FFCC00}Банк:\t%i\n", PI[params[0]][pBank]);
	strcat(string_dialogue, string);
	format(string, sizeof(string), "{FFCC00}Донат:\t\t\t%i\n", PI[params[0]][pCredits]);
	strcat(string_dialogue, string);
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, GetName(params[0]), string_dialogue, "Закрыть", "");
	return 1;
}

CMD:offget(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	new playername[MAX_PLAYER_NAME];
	if(sscanf(params, "s[24]", playername)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/offget [имя игрока]");
	else if(GetPlayerID(playername) != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "Игрок в сети, используйте команду /get");
	format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `name`='%s'", playername);
	mysql_tquery(dbHandle, query, "OnPlayerOffget", "is", playerid, playername);
	return 1;
}

/*CMD:amusic(playerid,params[])
{
    if(PI[playerid][pAdmin] < ADM_SUPER_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");
    new radio[256], distance;
	if(MUSICACTIVE == true)
	{
	    foreach(new i: Player)
		{
		    if(!PlayerLogged[i] || activemusic[i] == false) continue;
		    activemusic[i] = false;
			StopAudioStreamForPlayer(i);
		}
		format(radio, sizeof radio, "[A] %s [%d] выключил музыку", GetName(playerid), playerid);
		SendAdminMessage(COLOR_GREY, radio);
		MUSICACTIVE = false;
	    return 1;
	}
	if(sscanf(params, "s[256]d", radio, distance)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/amusic [url] [дистанция]");
	if(strlen(radio) < 10 || strlen(radio) > 256) return SendClientMessage(playerid, COLOR_RED, "Неверное количество символов в URL!");
	if(distance < 2 || distance > 300) return SendClientMessage(playerid, COLOR_RED, "Неверно указана дистанция!");
	new Float:X, Float:Y, Float:Z;
	GetPlayerPos(playerid, X, Y, Z);
	MUSICACTIVE = true;
	MUSICX = X;
	MUSICY = Y;
	MUSICZ = Z;
	MUSICDIST = distance;
	strmid(MUSICURL, radio, 0, strlen(radio), 256);
	activemusic[playerid] = true;
	foreach(new i: Player) { PlayAudioStreamForPlayer(i, radio, X, Y, Z, distance, 1); }
	format(radio, sizeof radio, "[A] %s [%d] поставил музыку (дистанция %d м)", GetName(playerid), playerid, distance);
    SendAdminMessage(COLOR_GREY, radio);
	return true;
}*/

CMD:ears(playerid,params[])
{
    if(PI[playerid][pAdmin] < ADM_SUPER_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");
    if(!AdminInfo[playerid][admSmsEars])
    {
        SendClientMessage(playerid, COLOR_BLUE, "Вы включили прослушку SMS. Информация будет выводиться только Вам");
        AdminInfo[playerid][admSmsEars] = 1;
    }
    else
    {
        SendClientMessage(playerid, COLOR_BLUE, "Вы отключили прослушку SMS сообщений");
        AdminInfo[playerid][admSmsEars] = 0;
    }
    return 1;
}
CMD:rears(playerid,params[])
{
    if(PI[playerid][pAdmin] < ADM_SUPER_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");
    if(!AdminInfo[playerid][admrEars])
    {
        SendClientMessage(playerid, COLOR_BLUE, "Вы включили прослушку рации. Информация будет выводиться только Вам");
        AdminInfo[playerid][admrEars] = 1;
    }
    else
    {
        SendClientMessage(playerid, COLOR_BLUE, "Вы отключили прослушку рациий");
        AdminInfo[playerid][admrEars] = 0;
    }
    return 1;
}
CMD:readsms(playerid,params[])
{
    if(PI[playerid][pMember] < TEAM_FSIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");
    if(!AdminInfo[playerid][fsbSmsEars])
    {
        SendClientMessage(playerid, COLOR_BLUE, "Вы включили прослушку SMS. Входящие/исходящие SMS будут отображаться Вам");
        AdminInfo[playerid][fsbSmsEars] = 1;
    }
    else
    {
        SendClientMessage(playerid, COLOR_BLUE, "Вы отключили прослушку SMS сообщений");
        AdminInfo[playerid][fsbSmsEars] = 0;
    }
    return 1;
}
CMD:unmask(playerid, params[])
{
    if(!IsACop(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна эта команда!");
    if(UnMaskReset[playerid] > 0) return 1;
	UnMaskReset[playerid] = 3;
	foreach(new i: Player)
	{
 		if(!PlayerLogged[i]) continue;
 		if(pCuff[i][pCuffee] == i)
 		{
			if(!PlayerUseMask[i]) continue;
			if(ProxDetectorS(2.0, playerid, i) && GetPlayerFaceToPlayer(playerid, i, 30.0))
			{
				new string[100];
				PlayerUseMask[i] = false;
				format(string, sizeof(string), "Вы сняли маску с игрока %s", GetName(i));
				SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
				format(string, sizeof(string), "%s снял с Вас маску", GetName(playerid));
				SendClientMessage(i, COLOR_RED, string);
				format(string, sizeof(string), "снял маску с игрока %s", GetName(i));
				MeAction(playerid, string);
				break;
			}
	    }
	    else SendClientMessage(playerid, COLOR_RED, "Игрок должен быть в наручниках");
    }
	return 1;
}
//==============================================================================
CMD:tazer(playerid, params[])
{
	if(!IsACop(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/tazer [id игрока]");
 	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!ProxDetectorS(10.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Вы далеко друг от друга");
	else if(playerid == params[0]) return SendClientMessage(playerid, COLOR_RED, "Нельзя себя ударить электрошокером");
	new string[128];
	if(PI[playerid][pSex] == 1) format(string, sizeof(string), "ударил электрошоком %s'a", GetName(params[0]));
	else format(string, sizeof(string), "ударила электрошоком %s'a", GetName(params[0]));
	MeAction(playerid, string);
	ClearAnimations(params[0], 1);
	ApplyAnimation(params[0], "CRACK", "crckdeth2", 4.0, 0, 1, 1, 1, 0, 1);
	
	tazer_off[params[0]] = 15;
	
	SetPVarInt(params[0], "Tazer", 1);
	TogglePlayerControllable(params[0], 0);
	return 1;
}
//==============================================================================
CMD:gotome(playerid, params[])
{
    if(!IsACop(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(GetPlayerState(playerid) == 2) return SendClientMessage(playerid, COLOR_RED, "Вы не должны быть в авто!");
	else if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/gotome [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(IsPlayerInAnyVehicle(params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок не должен находится в транспорте!");
	else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете вести самого себя!");
	if(pCuff[params[0]][pCuffee] == params[0])
	{
		if(ProxDetectorS(10.0, playerid, params[0]))
  			{
     			new Float:xe, Float:ye, Float:ze;
        		GetPlayerPos(playerid,xe,ye,ze);
          		SetPlayerPos(params[0],xe+0.5,ye+0.5,ze);
          		FreezePlayer(params[0], 5000);
      		    SendClientMessage(params[0],COLOR_RED,"Вас насильно тащат за собой!");
      		}
	 	else
	 	{
	  		SendClientMessage(playerid, COLOR_RED, "Вы далеко друг от друга");
	  	}
	}
	else
	{
		SendClientMessage(playerid, COLOR_RED, "Игрок не в наручниках");
 		return 1;
	}
	return 1;
}
CMD:cuff(playerid, params[])
{
	if(!IsACop(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(PlayerTied[playerid] == true) return SendClientMessage(playerid, COLOR_RED, "Вы связаны, Вы не можете одеть наручники!");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/cuff [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!ProxDetectorS(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Вы далеко друг от друга");
	else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете надеть наручники на себя!");
	else if(pCuff[params[0]][pCuffee] == params[0]) return SendClientMessage(playerid, COLOR_RED, "Игрок уже в наручниках!");
	if(GetPVarInt(params[0], "Tazer") > 0)
	{
		SetPVarInt(params[0], "Tazer", 0);
		TogglePlayerControllable(params[0], 1);
		SetPlayerSpecialAction(params[0], SPECIAL_ACTION_NONE);
	}
	SendMes(playerid, COLOR_BLUE, "Вы надели наручники на %s", GetName(params[0]));
	if(PI[playerid][pSex] == 1) SendMes(params[0], COLOR_BLUE, "%s надел на Вас наручники!", GetName(playerid));
	else SendMes(params[0], COLOR_BLUE, "%s надела на Вас наручники!", GetName(playerid));
	SetPlayerSpecialAction(params[0], SPECIAL_ACTION_CUFFED);
	SetPlayerAttachedObject(params[0], 0, 19418, 6, -0.011000, 0.028000, -0.022000, -15.600012, -33.699977, -81.700035, 0.891999, 1.000000, 1.168000);
	pCuff[params[0]][pCuffee] = pCuff[playerid][pCuffee] = params[0];
	pCuff[params[0]][pCuffer] = pCuff[playerid][pCuffer] = playerid;
	GameTextForPlayer(playerid, "~r~cuffed", 5000, 5);
	GameTextForPlayer(params[0], "~r~cuffed", 5000, 5);
	new string[64];
	if(PI[playerid][pSex] == 1) format(string, sizeof(string), "надел наручники на %s", GetName(params[0]));
	else format(string, sizeof(string), "надела наручники на %s", GetName(params[0]));
	MeAction(playerid, string);
	return 1;
}

CMD:uncuff(playerid, params[])
{
	if(!IsACop(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/uncuff [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!ProxDetectorS(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Вы далеко друг от друга");
	else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете снять наручники с себя!");
	else if(pCuff[params[0]][pCuffer] == INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "Игрок не в наручниках!");
	SendMes(playerid, COLOR_BLUE, "Вы сняли наручники с %s", GetName(params[0]));
	if(PI[playerid][pSex] == 1) SendMes(params[0], COLOR_BLUE, "%s снял с Вас наручники", GetName(playerid));
	else SendMes(params[0], COLOR_BLUE, "%s сняла с Вас наручники", GetName(playerid));
	SetPlayerSpecialAction(params[0], SPECIAL_ACTION_NONE);
	RemovePlayerAttachedObject(params[0], 0);
	pCuff[params[0]][pCuffer] = pCuff[params[0]][pCuffee] = pCuff[playerid][pCuffee] = pCuff[playerid][pCuffer] = INVALID_PLAYER_ID;
	GameTextForPlayer(playerid, "~g~uncuffed", 5000, 5);
	GameTextForPlayer(params[0], "~g~uncuffed", 5000, 5);
	TogglePlayerControllable(params[0], 1);
	new string[64];
	if(PI[playerid][pSex] == 1) format(string, sizeof(string), "снял наручники с %s", GetName(params[0]));
	else format(string, sizeof(string), "сняла наручники с %s", GetName(params[0]));
	MeAction(playerid, string);
	return 1;
}

CMD:search(playerid, params[])
{
	if(!IsACop(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/search [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!PI[params[0]][pWanted]) return SendClientMessage(playerid, COLOR_RED, "Игрок не находится в розыске!");
	if(GetPVarInt(playerid, "findplayer") == 1)
	{
		DeletePVar(playerid, "findplayer");
		SendClientMessage(playerid, COLOR_BLUE, "Вы отключили метку на карте");
		DisablePlayerRaceCheckpoint(playerid);
	}
	else
	{
		SetPVarInt(playerid, "findplayer", 1);
		new string[51];
		format(string, sizeof(string), "Подозреваемый %s отмечен У Вас на радаре красной точкой, отправляйтесь туда", GetName(params[0]));
		SendClientMessage(playerid, COLOR_BLUE, string);
		new Float:pos[3];
		GetPlayerPos(params[0], pos[0], pos[1], pos[2]);
		SetPlayerRaceCheckpoint(playerid, 1, pos[0], pos[1], pos[2], 0.0, 0.0, 0.0, 5.0);
	}
	return 1;
}
//==============================================================================
CMD:pos(playerid, params[])
{
    if(PI[playerid][pAdmin] < 6) return 1;
    else if(PI[playerid][pAdmin] < 1) return SCM(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");

	new Float: x, Float: y, Float: z, interior, virtual_world;

	if(sscanf(params, "P<,>fff", x, y, z))
		return SendClientMessage(playerid, COLOR_LIME, "Используйте: {FFFFFF}/pos [x y z]");

	sscanf(params, "P<,>{fff}dd", interior, virtual_world);

	SetPlayerInterior(playerid, interior);
	SetPlayerVirtualWorld(playerid, virtual_world);
	return SetPlayerPos(playerid, x, y, z);
}
CMD:arrest(playerid, params[])
{
	if(!IsACop(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(PI[playerid][pMember] == TEAM_PPS && IsPlayerInRangeOfPoint(playerid, 10.0, 402.2726,749.9173,12.0716))
	{
		if(sscanf(params, "ui", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/arrest [id игрока] [минуты]");
		else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
		else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
		else if(PI[params[0]][pJail] > 0) return SendClientMessage(playerid, COLOR_RED, "Данный игрок уже находится в тюрьме!");
		else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете арестовать самого себя!");
		else if(IsACop(params[0]) || PI[params[0]][pMember] == TEAM_VDV) return SendClientMessage(playerid, COLOR_RED, "Данный игрок полицейский/агент/военный!");
		else if(PI[params[0]][pWanted] == 0) return SendClientMessage(playerid, COLOR_RED, "Игрок должен иметь хотя бы 1 уровень розыска!");
		else if(params[1] < 1 || params[1] > 60) return SendClientMessage(playerid, COLOR_RED, "Количество минут от 1 до 60");
		ResetPlayerWeaponsAC(params[0]);
		PI[params[0]][pJailTime] = params[1];
		PI[params[0]][pWanted] = 0;
		if(pCuff[params[0]][pCuffer] != INVALID_PLAYER_ID)
		{
			new cuffer = pCuff[params[0]][pCuffer];
			SetPlayerSpecialAction(params[0], SPECIAL_ACTION_NONE);
			RemovePlayerAttachedObject(params[0], 0);
			pCuff[params[0]][pCuffer] = INVALID_PLAYER_ID;
			pCuff[params[0]][pCuffee] = INVALID_PLAYER_ID;
			pCuff[cuffer][pCuffee] = INVALID_PLAYER_ID;
			pCuff[cuffer][pCuffer] = INVALID_PLAYER_ID;
		}
		SendMes(playerid, COLOR_LIME, "Вы арестовали %s.", GetName(params[0]));
		SendMes(params[0], COLOR_BLUE, "%s %s [%i] посадил Вас в камеру на %i секунд", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid), playerid, params[1]*60);
		SetPlayerInterior(params[0], 0);
		SetPlayerPos(params[0], 449.9814,1320.2548,1723.5298);
		SetPlayerFacingAngle(params[0], 360.0000);
		PI[params[0]][pJail] = 1;
		//PI[params[0]][pJail] = 1;
		SetPlayerWantedLevel(params[0], 0);
		TogglePlayerControllable(params[0], 1);
	}
	return 1;
}
CMD:m(playerid, params[]) return callcmd::megaphone(playerid, params);
CMD:megaphone(playerid, params[])
{
	if(!IsACop(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	{
		if(isnull(params)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/m [текст]");
		new string[128];
		format(string, sizeof(string), "<< %s %s: %s >>",Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]],GetName(playerid),params[0]);
		ProxDetectorNew(playerid, 45.0, COLOR_YELLOW, string);
	}
	return 1;
}
CMD:clear(playerid, params[])
{
	if(!IsACop(playerid) || PI[playerid][pRank] < 4) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится в транспорте!");
	{
		if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/clear [id игрока]");
		else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
		else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
		else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете снять себе розыск!");
		else if(!PI[params[0]][pWanted]) return SendClientMessage(playerid, COLOR_RED, "Игрок должен находится в розыске!");
		else if(!IsPlayerInVehicle(params[0], GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, COLOR_RED, "Игрок должен находится с Вами в транспорте!");
		SendMes(playerid, COLOR_LIGHTBLUE, "Вы сняли уровни розыска с %s'а", GetName(params[0]));
		SendMes(params[0], COLOR_LIGHTBLUE, "Офицер %s снял с Вас уровни розыска", GetName(playerid));
		new string[128];
		format(string, sizeof(string), "Офицер %s зашел(ла) в базу данных полиции", GetName(playerid));
		ProxDetectorNew(playerid, 13.0, COLOR_PURPLE, string);
		PI[params[0]][pWanted] = 0;
		SetPlayerWantedLevel(params[0], 0);
	}
	return 1;
}
//==============================================================================
CMD:incar(playerid, params[])
{
    if(!IsACop(playerid) || PI[playerid][pRank] < 1) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	else if(GetPlayerState(playerid) != 2) return SendClientMessage(playerid, COLOR_RED, "Вы должны быть в авто!");
	else if(sscanf(params, "ui", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/incar [id игрока] [место(1-3)]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!ProxDetectorS(10.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок не рядом с Вами!");
	else if(IsPlayerInAnyVehicle(params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок не должен находится в транспорте!");
	else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете затащить в автомобиль самого себя!");
	else if(pCuff[params[0]][pCuffer] == INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "Игрок не в наручниках!");
	else if(params[1] > 3 || params[1] < 1) return SendClientMessage(playerid, COLOR_RED, "Количество мест от 1 до 3!");
	new string[90];
	{
		if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете затащить в автомобиль самого себя!");
		PutPlayerInVehicle(params[0], GetPlayerVehicleID(playerid), params[1]);
		TogglePlayerControllable(params[0], 0);
		FreezePlayer[params[0]] = true;
		if(PI[playerid][pSex] == 1) format(string, sizeof(string), "насильно затащил в авто %s", GetName(params[0]));
		else format(string, sizeof(string), "насильно затащила в авто %s", GetName(params[0]));
		MeAction(playerid, string);
	}
	return true;
}
//==============================================================================
CMD:lic(playerid, params[])
{
	if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/lic [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Вы далеко от игрока");
	new string[64];
    SendMes(playerid, COLOR_WHITE, "Вы показали свои лицензии %s [%d]", GetName(params[0]),params[0]);
	format(string, sizeof(string), "___________[ ЛИЦЕНЗИИ ]___________");
	SendClientMessage(params[0],COLOR_WHITE, string);
	SendMes(params[0], COLOR_WHITE, "Имя Фамилия: %s", PI[playerid][pName]);
	SendMes(params[0], COLOR_WHITE, "Лицензия категории A: %s | Лицензия категории B: %s", PI[playerid][pCarA] == 1 ? ("есть") : ("нет"), PI[playerid][pCarB] == 1 ? ("есть") : ("нет"));
	SendMes(params[0], COLOR_WHITE, "Лицензия категории C: %s | Лицензия категории D: %s", PI[playerid][pCarC] == 1 ? ("есть") : ("нет"), PI[playerid][pCarD] == 1 ? ("есть") : ("нет"));
	SendClientMessage(params[0],COLOR_WHITE, "___________[ ЛИЦЕНЗИИ ]___________");
	return 1;
}
//==============================================================================
CMD:paintlist(playerid)
{
    new fmt_str[700] = "Убийств\tСмертей\tНик\n";
    for(new i = 0; i < PaintList; i++)
    {
	    format
		(
			fmt_str, sizeof(fmt_str),
			"%d\t%d\t%s",
   			fmt_str,
			PaintInfo[i][Kills],
			PaintInfo[i][Deaths],
			PaintInfo[i][Player_Name]
		);
	}
    ShowPlayerDialog
	(
		playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX,
		"Список игроков",
		fmt_str,
		"Закрыть", ""
	);
    return true;
}
//==============================================================================
CMD:showpass(playerid, params[])
{
	if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/showpass [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Вы далеко от игрока");
	new sctring[1300], str[150];
	
	format(str,sizeof(str),"{ffffff}Имя Фамилия:\t\t\t%s\n",GetName(params[0]));
	strcat(sctring,str);
	format(str,sizeof(str),"{ffffff}Пол:\t\t\t\t%s\n",(PI[params[0]][pSex]==1)?("Мужской"):("Женский"));
	strcat(sctring,str);
	format(str,sizeof(str),"{ffffff}Лет в области:\t\t\t%d (%d/%d)\n",PI[params[0]][pLevel], PI[params[0]][pExp], (PI[params[0]][pLevel]+0)*4);
	strcat(sctring,str);
	if(PI[params[0]][pMember] != 0) format(str,sizeof(str),"{ffffff}Фракция:\t\t\t%s\n",Fraction_Name[PI[params[0]][pMember]]);
	else format(str,sizeof(str),"{ffffff}Фракция:\t\t\tНет\n");
	strcat(sctring,str);
	format(str,sizeof(str),"{ffffff}Работа:\t\t\t\t%s\n",Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], Job_Names[PI[params[0]][pJob]]);
	strcat(sctring,str);
	ShowPlayerDialog(playerid, 15143, DIALOG_STYLE_MSGBOX, "{FFCC00}Паспорт", sctring, "Закрыть", "");
	return 1;
}
//==============================================================================
CMD:eject(playerid, params[])
{
	if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вы не в транспорте");
	else if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится за рулем транспорта!");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/eject [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(playerid == params[0]) return SendClientMessage(playerid, COLOR_RED, "Ты не можешь выкинуть себя!");
	else if(!IsPlayerInVehicle(params[0],GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, COLOR_RED, "Игрок должен находится в Вашем транспорте!");
	SendMes(playerid, COLOR_BLUE, "Вы выкинули из транспорта %s", GetName(params[0]));
	SendMes(params[0], COLOR_LIGHTBLUE, "%s выкинул Вас из транспорта", GetName(playerid));
	new string[100];
	format(string, sizeof(string), "Выкинул из транспорта %s", GetName(params[0]));
	MeAction(playerid, string);
	RemoveFromVehicle(params[0]);
	return 1;
}
//==============================================================================
CMD:payday(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_GRAND) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");
	PayDay();
	return 1;
}
//==============================================================================
CMD:gcontrol(playerid, params[])
{
    if(PI[playerid][pAdmin] < ADM_GRAND) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    else if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");
	ShowDialogGhetto(playerid);
	return 1;
}
//==============================================================================
CMD:pay(playerid, params[])
{
   	if(GetPVarInt(playerid, "payer") > gettime()) return SendClientMessage(playerid, COLOR_RED, "Не флудите");
	else if(sscanf(params, "ui", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/pay [id игрока] [сумма]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Нельзя передавать деньги самому себе");
	else if(!ProxDetectorS(3.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	else if(params[1] < 1 || GetMoney(playerid) < params[1]) return SendClientMessage(playerid, COLOR_RED, "У Вас недостаточно денег!");
	else if(PI[playerid][pLevel] == 20 && params[1] > 5000) return SendClientMessage(playerid, COLOR_RED, "За раз можно передать не более 5000 рублей");
	else if(PI[playerid][pAdmin] < ADM_SUPER_ADMIN && params[1] > 5000) return SendClientMessage(playerid, COLOR_RED, "Нельзя передавать больше 5000 рублей");
	TransferMoney(playerid, params[0], params[1]);
	new string[128];
	format(string,sizeof(string),"%s достал(-а) кошелёк и передал(-а) деньги %s", GetName(playerid), GetName(params[0]));
	SendLog("PayLog",string);
	SendMes(params[0], COLOR_RED, "Игрок %s передал Вам %d руб", GetName(playerid), params[1]);
	SendMes(playerid, COLOR_RED, "Вы передали %s[%d] %d рублей", GetName(params[0]), params[1]);
	if(PI[playerid][pSex] == 1) format(string, sizeof(string), "%s достал кошелёк и передал деньги %s", GetName(params[0]));
	else format(string, sizeof(string), "достала деньги из кармана и передала их %s", GetName(params[0]));
	MeAction(playerid, string);
	ApplyAnimation(playerid, "DEALER", "shop_pay", 4.1, 0, 1, 1, 0, 0, 1);
	SetPVarInt(playerid, "payer", gettime()+15);
	return 1;
}
//==============================================================================
CMD:heal(playerid, params[])
{
	if(!IsAMedic(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/heal [id игрока]");
	else if(playerid == params[0]) return SendClientMessage(playerid, COLOR_RED, "Вы не можете вылечить себя!");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!IsPlayerInRangeOfPlayer(5.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	else if(GetPVarInt(params[0], "lechenie") > 0) SendClientMessage(playerid, COLOR_RED, "Пациент уже проходит курс лечения!");
	new Float:shealth;
	GetPlayerHealth(params[0], shealth);
	SendMes(playerid, COLOR_BLUE, "Вы предложили %s вылечиться за 500 рублей", GetName(params[0]));
	SendMes(params[0], COLOR_BLUE, "%s %s предлагает Вам пройти курс платного лечения за 500 рублей", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
	SendClientMessage(params[0], COLOR_WHITE, "{FFFFFF}Нажмите {03c03c}Y {FFFFFF}чтобы согласиться или {ff7518}N {FFFFFF}для отказа");
	SetPVarInt(params[0], "PlayerHeal", playerid);
	SetPVarInt(params[0], "MoneyHeal", 500);
	SetPVarInt(params[0], "KeyHeal", 1);
    if(PlayerDied[params[0]] == true)
	{
		SetPVarInt(params[0], "lechenie", 0);
		PlayerDied[params[0]] = false;
	}
	return 1;
}
//==============================================================================
CMD:canceltune(playerid)
{
	if(!GetPVarInt(playerid, "UsedCTO")) return 0;
    new bizzid = GetPVarInt(playerid,"CTObizzid");
	if(GetPlayerState(playerid) != 2) return CheatKick(playerid, 12221);
	new pveh = GetPlayerVehicleID(playerid);
	SetVehiclePos(pveh,BizzInfo[bizzid][bEntrx],BizzInfo[bizzid][bEntry],BizzInfo[bizzid][bEntrz]);
	DeletePVar(playerid,"UsedCTO");
	SetVehicleZAngle(pveh,270.9845);
	SetPlayerInterior(playerid,1);
	SetPlayerVirtualWorld(playerid,0);
	SetVehicleVirtualWorld(pveh,0);
	LinkVehicleToInterior(pveh,0);
	PutPlayerInVehicle(playerid, pveh, 0);
	TogglePlayerControllable(playerid,true);
	SetCameraBehindPlayer(playerid);
	return 1;
}
//==============================================================================
CMD:cancel(playerid)
{
	ShowPlayerDialog(playerid, D_HEAL+132, DIALOG_STYLE_LIST, "text", "text", "Выбрать", "Закрыть");
	return 1;
}
//==============================================================================
CMD:healing(playerid, params[])
{
	new full = 0;
	for(new i = 1; i < TOTALHOUSE; i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 60.0, HouseInfo[i][hExitx], HouseInfo[i][hExity], HouseInfo[i][hExitz]))
		{
			if(HouseInfo[i][hVirtual] == GetPlayerVirtualWorld(playerid))
			{
				if(HouseInfo[i][hHeal] == 0) return SendClientMessage(playerid, COLOR_RED, "В доме нет аптечек!");
				new Float:shealth;
				GetPlayerHealth(playerid, shealth);
				if(shealth >= 100) return SendClientMessage(playerid, COLOR_RED, "Вы не нуждаетесь в лечении!");
				HouseInfo[i][hHeal]--;
				MysqlUpdateHouseInt(i, "hHeal", HouseInfo[i][hHeal]);
				SetHealth(playerid, shealth+25);
				GetPlayerHealth(playerid, shealth);
				if(shealth > 100) SetHealth(playerid, 100);
				SendMes(playerid, COLOR_BLUE, "Вы использовали 1 аптечку. Осталось %i аптечек", HouseInfo[i][hHeal]);
				MeAction(playerid, "использовал аптечку");
				full++;
			}
		}
	}
	if(full == 0) SendClientMessage(playerid, COLOR_RED, "Вы должны находится в доме!");
	return 1;
}
//==============================================================================
CMD:afk(playerid, params[])
{
	if(PI[playerid][pAdmin] < 1) return 1;
	//else if(AdminLogged[playerid] == false) return SendClientMessage(playerid, COLOR_GREY, YouAreNotLoggedInAsAdmin);
	new list,full,str[100],sttr[2000];
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(PI[i][pAFK] >= 3) list++;
	}
	format(str,sizeof(str),"{FF6347}Всего в AFK - %i игрок(ов)\n\n",list);
	strcat(sttr, str);
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(PI[i][pAFK] >= 3)
		{
			format(str,sizeof(str),"{ffffff}%s[%i] - {FF6347}AFK: %s\n",GetName(i), i, Converts(PI[i][pAFK]));
			strcat(sttr, str);
			full++;
		}
	}
	if(full == 0) strcat(sttr, "{ffffff}Информация не найдена");
	ShowPlayerDialog(playerid,D_NULL,DIALOG_STYLE_MSGBOX,"{ffffff}AFK",sttr,"Закрыть","");
	return 1;
}
//==============================================================================
CMD:wanted(playerid, params[])
{
	if(!IsACop(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	new full, str[150], sttr[2000];
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(PI[i][pWanted] > 0)
		{
			format(str,sizeof(str),"{ffffff}%s - {ffffff}Уровень розыска: {FFCC00}%i\n",GetName(i), PI[i][pWanted]);
			strcat(sttr, str);
			full++;
		}
	}
	if(full == 0) strcat(sttr, "Информация не найдена");
	ShowPlayerDialog(playerid,D_NULL,DIALOG_STYLE_MSGBOX,"Разыскиваются:",sttr,"Закрыть","");
	return 1;
}
CMD:wedding(playerid, params[])
{
	if(PI[playerid][pMarried] == 1) return SendClientMessage(playerid, COLOR_RED, "Вы уже связаны узами брака!");
	else if(!IsPlayerInRangeOfPoint(playerid,20.0,2684.1265,-2535.2329,22.5574)) return SendClientMessage(playerid, COLOR_RED, "Вы не в церкви");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/wedding [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(playerid == params[0]) return SendClientMessage(playerid, COLOR_RED, "Ты не можешь заключить брак сам с собой!");
	else if(!IsPlayerInRangeOfPlayer(5.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	else if(PI[params[0]][pMarried] == 1) return SendClientMessage(playerid, COLOR_RED, "Игрок уже связан узами брака!");
	new string[128];
	format(string, sizeof(string), "Вы предложили %s заключить брачный договор", GetName(params[0]));
	SendClientMessage(playerid, COLOR_BLUE, string);
	if(PI[playerid][pSex] == 1)
	{
	    format(string, sizeof(string), "%s предложил Вам заключить брачный договор", GetName(playerid));
		SendClientMessage(params[0], COLOR_BLUE, string);
		format(string, sizeof(string), "{FFFFFF}%s предложил Вам заключить брачный договор\n\nВы согласны?", GetName(playerid));
		ShowPlayerDialog(params[0], D_HEAL+19, 0, "{FF6666}Свадьба", string, "Да", "Нет");
	}
	else
	{
	    format(string, sizeof(string), "%s предложила Вам заключить брачный договор", GetName(playerid));
		SendClientMessage(params[0], COLOR_BLUE, string);
	    format(string, sizeof(string), "{FFFFFF}%s предложила Вам заключить брачный договоре\n\nВы согласны?", GetName(playerid));
		ShowPlayerDialog(params[0], D_HEAL+19, 0, "{FF6666}Свадьба", string, "Да", "Нет");
	}
	SetPVarInt(params[0], "PlayerMarriage", playerid);
	return 1;
}
CMD:divorce(playerid, params[])
{
	if(PI[playerid][pMarried] == 0) return SendClientMessage(playerid, COLOR_RED, "Вы не связаны узами брака!");
	else if(!IsPlayerInRangeOfPoint(playerid, 5.0,2684.1265,-2535.2329,22.5574)) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится у церкви!");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/divorce [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(playerid == params[0]) return SendClientMessage(playerid, COLOR_RED, "Ты не можешь разорвать брак сам с собой!");
	else if(!IsPlayerInRangeOfPlayer(5.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	if(!strcmp(GetName(params[0]), PI[playerid][pWhoMarried], true))
	{
	    new string[128];
	    format(string, sizeof(string), "Вы предложили %s развестисть", GetName(params[0]));
	    SendClientMessage(playerid, COLOR_BLUE, string);
	    if(PI[playerid][pSex] == 1)
	    {
	        format(string, sizeof(string), "%s предложил Вам развестись", GetName(playerid));
	        SendClientMessage(params[0], COLOR_BLUE, string);
	        format(string, sizeof(string), "{FFFFFF}%s предложил Вам развестись\n\nВы согласны?", GetName(playerid));
			ShowPlayerDialog(params[0], D_HEAL+20, 0, "{F04245}Развод", string, "Да", "Нет");
	    }
	    else
	    {
	        format(string, sizeof(string), "%s предложила Вам развестись", GetName(playerid));
	        SendClientMessage(params[0], COLOR_BLUE, string);
	        format(string, sizeof(string), "{FFFFFF}%s предложила Вам развестись\n\nВы согласны?", GetName(playerid));
			ShowPlayerDialog(params[0], D_HEAL+20, 0, "{F04245}Развод", string, "Да", "Нет");
	    }
		SetPVarInt(params[0], "PlayerMarriage", playerid);
	}
	else SendClientMessage(playerid, COLOR_RED, "Игрок не связам узами брака с Вами!");
	return 1;
}
//==============================================================================
CMD:donate(playerid)
{
    ShowPlayerDialogDonateList(playerid);
    return 1;
}
CMD:rlock(playerid)
{
	if(PI[playerid][P_ENTRANCE] == -1 && PI[playerid][P_ROOM] == -1)
		return SendClientMessage(playerid, COLOR_RED, "У Вас нет квартиры");

	new entranceid = PI[playerid][P_ENTRANCE],
		roomid = PI[playerid][P_ROOM];

	if(GetRoomData(entranceid, roomid, ER_LOCK) == true)
	{
		SetRoomData(entranceid, roomid, ER_LOCK, false);

		SendClientMessage(playerid, 0xFF6600FF, "Квартира закрыта");
	}
	else
	{
		SetRoomData(entranceid, roomid, ER_LOCK, true);

		SendClientMessage(playerid, 0x99CC00FF, "Квартира открыта");
	}

	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof STRING_GLOBAL, "UPDATE `rooms` SET `lock` = '%d' WHERE `id` = '%d' ", bool: GetRoomData(entranceid, roomid, ER_LOCK), GetRoomData(entranceid, roomid, ER_SQL_ID));
	mysql_query(dbHandle, STRING_GLOBAL);

	return 1;
}
CMD:entrance_exit(playerid, params[])
{
	if(!IsPlayerGrandAdmin(playerid))
		return 1;

	extract params -> new entranceid; else return SendClientMessage(playerid, 0xFFCC00AA, "•[Подсказка] {ffffff}Введите: /entrance_exit [ид подъезда]");

	if(!(0 <= entranceid <= MAX_ENTRANCES-1))
		return SendClientMessage(playerid, COLOR_RED, "Такого подъезда не существует");

	GetPlayerPos(playerid, g_entrance[entranceid][EXIT_POS_X], g_entrance[entranceid][EXIT_POS_Y], g_entrance[entranceid][EXIT_POS_Z]);
	GetPlayerFacingAngle(playerid, g_entrance[entranceid][EXIT_ANGLE]);

	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof STRING_GLOBAL, "UPDATE entrances SET exit_x='%f', exit_y='%f', exit_z='%f', exit_a='%f' WHERE id=%d", g_entrance[entranceid][EXIT_POS_X], g_entrance[entranceid][EXIT_POS_Y], g_entrance[entranceid][EXIT_POS_Z], g_entrance[entranceid][EXIT_ANGLE], entranceid);
	mysql_query(dbHandle, STRING_GLOBAL);

	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof STRING_GLOBAL, "Вы успешно изменили координаты выхода в подъезде %d", entranceid);
	SendClientMessage(playerid, COLOR_BLUE, STRING_GLOBAL);

	return 1;
}

CMD:adivorce(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_ADMIN) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	else if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");
	else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/adivorce [id игрока]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(PI[params[0]][pMarried] == 0) return SendClientMessage(playerid, COLOR_RED, "Игрок не связан узами брака!");
	new targetid;
	sscanf(PI[params[0]][pWhoMarried], "u", targetid);
	if(IsPlayerConnected(targetid))
	{
		SendMes(targetid, COLOR_GREEN, "Администратор %s развел тебя с %s", GetName(playerid), PI[targetid][pWhoMarried]);
		strmid(PI[targetid][pWhoMarried], "None", 0, strlen("None"), MAX_PLAYER_NAME);
		PI[targetid][pMarried] = 0;
	}
	else
	{
		format(query,sizeof(query), "SELECT * FROM `accounts` WHERE name = '%s'",PI[params[0]][pWhoMarried]);
		mysql_tquery(dbHandle, query, "OnPlayerDivorce", "i", params[0]);
	}
	SendMes(playerid, COLOR_LIME, "Вы развели игрока %s и %s", GetName(params[0]), PI[params[0]][pWhoMarried]);
	SendMes(params[0], COLOR_GREEN, "Администратор %s развел тебя с %s", GetName(playerid), PI[targetid][pWhoMarried]);
	strmid(PI[params[0]][pWhoMarried], "None", 0, strlen("None"), MAX_PLAYER_NAME);
	PI[params[0]][pMarried] = 0;
	return 1;
}

forward OnPlayerDivorce(targetid);
public OnPlayerDivorce(targetid)
{
    new rows, fields;
    cache_get_data(rows, fields);
	if(rows)
	{
		format(query,sizeof(query), "UPDATE `accounts` SET married = 0, whomarried = None WHERE name = '%s'",PI[targetid][pWhoMarried]);
		mysql_tquery(dbHandle, query, "", "");
	}
	return 1;
}
CMD:removetuning(playerid, params[])
{
	if(!PI[playerid][pVip]) return SCM(playerid, COLOR_RED, "Вы не имеете VIP статус");
	else if(GetPlayerHouse(playerid) == 0) return SendClientMessage(playerid, COLOR_RED, "Вы не владеете домом!");
	else if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится в транспорте!");
	else if(GetPlayerVehicleID(playerid) != PI[playerid][PlayerCarID]) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится в вашем личном транспорте!");
	for(new i = 0; i < 14; i++) PI[playerid][cVehcoms][i] = 0;
	PI[playerid][cPaintjob] = 3;
	SetPVarInt(playerid, "removetuning", 1);
	format(PI[playerid][cVehcom], 64, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
	PI[playerid][cVehcoms][0],PI[playerid][cVehcoms][1],PI[playerid][cVehcoms][2],
	PI[playerid][cVehcoms][3],PI[playerid][cVehcoms][4],PI[playerid][cVehcoms][5],
	PI[playerid][cVehcoms][6],PI[playerid][cVehcoms][7],PI[playerid][cVehcoms][8],
	PI[playerid][cVehcoms][9],PI[playerid][cVehcoms][10],PI[playerid][cVehcoms][11],
	PI[playerid][cVehcoms][12],PI[playerid][cVehcoms][13]);
	SendClientMessage(playerid, COLOR_RED, "Тюнинг успешно удален!");
	SetVehicleToRespawn(PI[playerid][PlayerCarID]);
	return 1;
}

CMD:nbank(playerid, params[])
{
	if(IsANews(playerid) && PI[playerid][pLeader]) BankFracEnter(playerid);
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}

CMD:anim(playerid, params[]) return callcmd::animlist(playerid, params);
CMD:animlist(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "В данный момент нельзя использовать анимации");
	new animid;
	if(sscanf(params, "i", animid))
	{
		new anims[][] =
		{
			{"1. Руки вверх\n2. Справлять нужду\n3. Танец (1)\n4. Танец (2)\n5. Танец (3)\n6. Танец (4)\n7. Танец (5)\n8. Танец (6)\n9. Танец (7)\n10. Танец (8)\n11. Танец (9)\n12. Танец(10)\n13. Курить\n14. Возмущение\n15. Присесть (1)\n16. Присесть (2)\n17. Присесть (3)\n18. Присесть (4)\n19. Лежать (1)\n20. Лежать (2)\n21. Жест рукой (1)\n22. Жест рукой (2)\n"},
			{"23. Читать рэп\n24. Зивать\n25. Диллер (1)\n26. Диллер (2)\n27. Диллер (3)\n28. Диллер (4)\n29. Пьяная походка\n30. Рука лицо\n31. Спать на боку\n32. Сесть на корточки"}
		};
		STRING_GLOBAL[0] = EOS;
		format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "%s%s", anims[0], anims[1]);
		ShowPlayerDialog(playerid,D_JOB+136,DIALOG_STYLE_LIST, "Анимации", STRING_GLOBAL, "Выбрать", "Отмена");
	}
	switch(animid)
	{
	    case 0:
	    {
		    new animss[][] =
			{
				{"1. Руки вверх\n2. Справлять нужду\n3. Танец (1)\n4. Танец (2)\n5. Танец (3)\n6. Танец (4)\n7. Танец (5)\n8. Танец (6)\n9. Танец (7)\n10. Танец (8)\n11. Танец (9)\n12. Танец(10)\n13. Курить\n14. Возмущение\n15. Присесть (1)\n16. Присесть (2)\n17. Присесть (3)\n18. Присесть (4)\n19. Лежать (1)\n20. Лежать (2)\n21. Жест рукой (1)\n22. Жест рукой (2)\n"},
				{"23. Читать рэп\n24. Зивать\n25. Диллер (1)\n26. Диллер (2)\n27. Диллер (3)\n28. Диллер (4)\n29. Пьяная походка\n30. Рука лицо\n31. Спать на боку\n32. Сесть на корточки"}
			};
			STRING_GLOBAL[0] = EOS;
			format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "%s%s", animss[0], animss[1]);
			ShowPlayerDialog(playerid,D_JOB+136,DIALOG_STYLE_LIST, "Анимации", STRING_GLOBAL, "Выбрать", "Отмена");
			return 1;
		}
		case 1: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_HANDSUP);
		case 2: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_PISS);
	    case 3: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
	    case 4: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
	    case 5: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
	    case 6: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE4);
	    case 7: ApplyAnimation(playerid,"DANCING","dnce_M_b",4.1,1,0,0,0,0,1);
		case 8: ApplyAnimation(playerid,"DANCING","dnce_M_a",4.1,1,0,0,0,0,1);
		case 9: ApplyAnimation(playerid,"DANCING","dnce_M_b",4.1,1,0,0,0,0,1);
		case 10: ApplyAnimation(playerid,"DANCING","DAN_Down_A",4.1,1,0,0,0,0,1);
		case 11: ApplyAnimation(playerid,"DANCING","DAN_Left_A",4.1,1,0,0,0,0,1);
		case 12: ApplyAnimation(playerid,"DANCING","DAN_Loop_A",4.1,1,0,0,0,0,1);
		case 13: ApplyAnimation(playerid,"SMOKING","M_smklean_loop",4.1,1,0,0,0,0,1);
		case 14: ApplyAnimation(playerid,"PED","fucku",4.1,0,0,0,0,0,1);
		case 15: ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Crash",4.1,0,0,0,1,0,1);
		case 16: ApplyAnimation(playerid,"BEACH","ParkSit_W_Loop",4.1,1,0,0,1,0,1);
		case 17: ApplyAnimation(playerid,"PED","SEAT_down",4.1,0,0,0,1,0,1);
		case 18: ApplyAnimation(playerid,"BEACH","ParkSit_M_loop",4.1,1,0,0,1,0,1);
		case 19: ApplyAnimation(playerid,"BEACH","SitnWait_loop_W",4.1,1,0,0,1,0,1);
		case 20: ApplyAnimation(playerid,"BEACH","Lay_Bac_Loop",4.1,1,0,0,1,0,1);
		case 21: ApplyAnimation(playerid,"GANGS","hndshkba",4.1,0,0,0,0,0,1);
		case 22: ApplyAnimation(playerid,"ON_LOOKERS","WAVE_LOOP",4.1,1,1,1,0,0,1);
		case 23: ApplyAnimation(playerid,"BENCHPRESS","GYM_BP_CELEBRATE",4.1,1,1,1,0,0,1);
		case 24: ApplyAnimation(playerid,"GANGS","smkcig_prtl",4.1,0,0,0,0,0,1);
		case 25: ApplyAnimation(playerid,"DEALER","DEALER_DEAL",4.1,0,0,0,0,0,1);
		case 26: ApplyAnimation(playerid,"DEALER","DEALER_IDLE_01",4.1,0,0,0,0,0,1);
		case 27: ApplyAnimation(playerid,"DEALER","DEALER_IDLE_03",4.1,0,0,0,0,0,1);
		case 28: ApplyAnimation(playerid,"DEALER","DRUGS_BUY",4.1,0,0,0,0,0,1);
		case 29: ApplyAnimation(playerid,"RYDER","RYD_Die_PT1",4.1,1,1,0,0,0,1);
		case 30: ApplyAnimation(playerid,"MISC","plyr_shkhead",4.1,0,0,0,0,0,1);
		case 31: ApplyAnimation(playerid,"CRACK","Crckidle2",4.1,1,0,0,0,0,0);
		case 32: ApplyAnimation(playerid,"PED","cower",3.0,1,0,0,0,0);
	}
	SetPVarInt(playerid, "Animation", 1);
	TextDrawShowForPlayer(playerid, AnimDraw);
	return 1;
}

CMD:fstyle(playerid, params[])
{
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/fstyle [стиль от 1 до 3]");
	switch(params[0])
	{
	    case 1:
	    {
	        if(PI[playerid][pSportExp] >= 1000)
			{
			    PI[playerid][pFightStyle] = 5;
				SetPlayerFightingStyle(playerid, FIGHT_STYLE_BOXING);
				SendClientMessage(playerid, COLOR_GREEN, "Вы изменили свой стиль боя на {FFFFFF}бокс");
			}
			else SendClientMessage(playerid, COLOR_RED, "Вы еще не выучили этот стиль боя!");
	    }
	    case 2:
	    {
	        if(PI[playerid][pSportExp] >= 3000)
			{
			    PI[playerid][pFightStyle] = 6;
				SetPlayerFightingStyle(playerid, FIGHT_STYLE_KUNGFU);
				SendClientMessage(playerid, COLOR_GREEN, "Вы изменили свой стиль боя на {FFFFFF}кунг-фу");
			}
			else SendClientMessage(playerid, COLOR_RED, "Вы еще не выучили этот стиль боя!");
	    }
	    case 3:
	    {
	        if(PI[playerid][pSportExp] >= 6000)
			{
			    PI[playerid][pFightStyle] = 7;
				SetPlayerFightingStyle(playerid, FIGHT_STYLE_KNEEHEAD);
				SendClientMessage(playerid, COLOR_GREEN, "Вы изменили свой стиль боя на {FFFFFF}кикбокс");
			}
			else SendClientMessage(playerid, COLOR_RED, "Вы еще не выучили этот стиль боя!");
	    }
	}
	return 1;
}
CMD:tempzone(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_GRAND_ADMIN) return 1;
	else if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");
	else if(sscanf(params, "i", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/tempzone [id банды]");
	for(new i = 0; i < sizeof(GZInfo); i++)
	{
		if(IsPlayerToSquare(playerid,GZInfo[i][gCoords][0], GZInfo[i][gCoords][1],GZInfo[i][gCoords][2],GZInfo[i][gCoords][3]))
		{
			GZInfo[i][gFrak] = params[0];
			GangZoneStopFlashForAll(GangZone[i]);
			GangZoneHideForAll(GangZone[i]);
			GangZoneShowForAll(GangZone[i],GetGangZoneColor(i));
			SaveGZ(i);
			break;
		}
	}
	return 1;
}
CMD:close(playerid, params[])
{
	if((IsAGang(playerid) || IsAMafia(playerid)) && PI[playerid][pRank] >= 9)
	{
	    new string[128];
		switch(PI[playerid][pMember])
		{
		    case 7:
		    {
				if(b_Sklad{0})
				{
				    b_Sklad{0} = 0;
				    MysqlUpdateGangInt("bskl_g",b_Sklad{0});
				    format(string, sizeof(string), "%s %s открыл доступ к складу банды", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
				else
				{
				    b_Sklad{0} = 1;
				    MysqlUpdateGangInt("bskl_g",b_Sklad{0});
				    format(string, sizeof(string), "%s %s временно закрыл доступ к складу банды", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
		    }
		    case 8:
		    {
		        if(b_Sklad{1})
				{
				    b_Sklad{1} = 0;
				    MysqlUpdateGangInt("bskl_b",b_Sklad{1});
				    format(string, sizeof(string), "%s %s открыл доступ к складу банды", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
				else
				{
				    b_Sklad{1} = 1;
				    MysqlUpdateGangInt("bskl_b",b_Sklad{1});
				    format(string, sizeof(string), "%s %s временно закрыл доступ к складу банды", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
		    }
		    case 9:
		    {
		        if(b_Sklad{2})
				{
				    b_Sklad{2} = 0;
				    MysqlUpdateGangInt("bskl_r",b_Sklad{2});
				    format(string, sizeof(string), "%s %s открыл доступ к складу банды", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
				else
				{
				    b_Sklad{2} = 1;
				    MysqlUpdateGangInt("bskl_r",b_Sklad{2});
				    format(string, sizeof(string), "%s %s временно закрыл доступ к складу банды", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
		    }
		    case 10:
		    {
		        if(b_Sklad{3})
				{
				    b_Sklad{3} = 0;
				    MysqlUpdateGangInt("bskl_a",b_Sklad{3});
				    format(string, sizeof(string), "%s %s открыл доступ к складу банды", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
				else
				{
				    b_Sklad{3} = 1;
				    MysqlUpdateGangInt("bskl_a",b_Sklad{3});
				    format(string, sizeof(string), "%s %s временно закрыл доступ к складу банды", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
		    }
		    case 11:
		    {
		        if(b_Sklad{4})
				{
				    b_Sklad{4} = 0;
				    MysqlUpdateGangInt("bskl_v",b_Sklad{4});
				    format(string, sizeof(string), "%s %s открыл доступ к складу банды", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
				else
				{
				    b_Sklad{4} = 1;
				    MysqlUpdateGangInt("bskl_v",b_Sklad{4});
				    format(string, sizeof(string), "%s %s временно закрыл доступ к складу банды", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
		    }
		    case 15:
		    {
		        if(b_Sklad{5})
				{
				    b_Sklad{5} = 0;
				    MysqlUpdateMafiaInt("bskl_l",b_Sklad{5});
				    format(string, sizeof(string), "%s %s открыл доступ к складу мафии", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
				else
				{
				    b_Sklad{5} = 1;
				    MysqlUpdateMafiaInt("bskl_l",b_Sklad{5});
				    format(string, sizeof(string), "%s %s временно закрыл доступ к складу мафии", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
		    }
		    case 16:
		    {
		        if(b_Sklad{6})
				{
				    b_Sklad{6} = 0;
				    MysqlUpdateMafiaInt("bskl_y",b_Sklad{6});
				    format(string, sizeof(string), "%s %s открыл доступ к складу мафии", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
				else
				{
				    b_Sklad{6} = 1;
				    MysqlUpdateMafiaInt("bskl_y",b_Sklad{6});
				    format(string, sizeof(string), "%s %s временно закрыл доступ к складу мафии", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
		    }
		    case 17:
		    {
		        if(b_Sklad{7})
				{
				    b_Sklad{7} = 0;
				    MysqlUpdateMafiaInt("bskl_r",b_Sklad{7});
				    format(string, sizeof(string), "%s %s открыл доступ к складу мафии", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
				else
				{
				    b_Sklad{7} = 1;
				    MysqlUpdateMafiaInt("bskl_r",b_Sklad{7});
				    format(string, sizeof(string), "%s %s временно закрыл доступ к складу мафии", Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], GetName(playerid));
					SendFMes(PI[playerid][pMember], COLOR_YELLOW, string);
				}
		    }
		}
	}
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
//==============================================================================
CMD:usedrugs(playerid, params[])
{
    if(IsPlayerInRangeOfPoint(playerid,100.0,-1519.6149,1342.5447,1523.7000)) return SendClientMessage(playerid,-1,"В больнице опасно принимать наркотики!");
	if(PI[playerid][pDrugs] <= 0) return SendClientMessage(playerid, COLOR_RED, "У Вас нет наркотиков!");
	if(GetPVarInt(playerid, "DrugsTime") > gettime()) return SendClientMessage(playerid, COLOR_RED, "Употреблять наркотики можно раз в 2 минуты!");
	if(sscanf(params, "i", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/drugs [кол-во грамма]");
	new string[128];
	if(params[0] > 3)
	{
	    format(string, sizeof(string), "Кол-во наркотиков от 1 до 3, сейчас У Вас %i грамм", PI[playerid][pDrugs]);
		SendClientMessage(playerid, COLOR_RED, string);
		return 1;
	}
	new Float:health;
	GetPlayerHealth(playerid, health);
	SetHealth(playerid, health+params[0]*20);
	GetPlayerHealth(playerid, health);
	if(health > 120) return SendClientMessage(playerid, COLOR_BLUE, "Вам плохо от наркотиков, пожалуйста подождите");
	PI[playerid][pDrugs] -= params[0];
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) ApplyAnimation(playerid,"SMOKING","M_smk_drag",4.1,0,0,0,0,0,1);
	format(string, sizeof(string), "Вы употребили %i гр. наркотиков. Ваше здоровье: %3.1f", params[0], PI[playerid][pHeal]);
	SendClientMessage(playerid, COLOR_LIME, string);
	
	//drug_effect_gone_timer[playerid] = 6;
	
	SetPVarInt(playerid, "DrugsTime", gettime()+60);
	if(PI[playerid][pSex] == 1) MeAction(playerid, "употребил наркотики");
	else MeAction(playerid, "употребила наркотики");
	SetPlayerTime(playerid,17,0);
	SetPlayerDrunkLevel(playerid, 3000);
	SetPlayerWeather(playerid, -68);
	
	return 1;
}
//==============================================================================
CMD:dropdrugs(playerid, params[])
{
	if(PI[playerid][pDrugs] == 0) return SendClientMessage(playerid, COLOR_RED, "У Вас нет наркотиков!");
	PI[playerid][pDrugs] = 0;
	if(PI[playerid][pSex] == 1) MeAction(playerid, "скинул пакетик с неизвестным содержимым");
	else MeAction(playerid, "скинула пакетик с неизвестным содержимым");
	return 1;
}
//==============================================================================
CMD:selldrugs(playerid, params[])
{
	if(!IsAGang(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(PI[playerid][pRank] < 1) return SendClientMessage(playerid, COLOR_RED, "Продажа наркотиков доступна со 2 ранга!");
	new full = 0;
	for(new i = 0; i < sizeof(GZInfo); i++)
	{
		if(IsPlayerToSquare(playerid,GZInfo[i][gCoords][0], GZInfo[i][gCoords][1],GZInfo[i][gCoords][2],GZInfo[i][gCoords][3]) && ZoneOnBattle[i] == 0)
		{
			if(sscanf(params, "uii", params[0], params[1], params[2])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/selldrugs [id игрока] [грамм] [цена]");
			else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
			else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
			else if(params[1] < 1 || params[1] > 100) return SendClientMessage(playerid, COLOR_RED, "Количество грамм от 1 до 100!");
			else if(params[2] < 1 || params[2] > 10000) return SendClientMessage(playerid, COLOR_RED, "Цена от 1 до 10000 рублей!");
            else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
			else if(PI[playerid][pDrugs] < params[1]) return SendClientMessage(playerid, COLOR_RED, "У Вас нет столько наркотиков!");
			SendMes(playerid, COLOR_BLUE, "Вы предложили %s купить наркотики (Грамм: %i). Цена: %i рублей", GetName(params[0]), params[1], params[2]);
			SendMes(params[0], COLOR_BLUE, "%s предложил Вам купить наркотики (Грамм: %i). Цена: %i рублей", GetName(playerid), params[1], params[2]);
			SendClientMessage(params[0], COLOR_WHITE, "{FFFFFF}Нажмите {03c03c}Y {FFFFFF}чтобы согласиться или {ff7518}N {FFFFFF}для отказа");
			SetPVarInt(params[0], "KeyDrugs", 1);
			SetPVarInt(params[0], "PlayerDrugs", playerid);
			SetPVarInt(params[0], "PlayerDrugsKG", params[1]);
			SetPVarInt(params[0], "DrugsPrice", params[2]);
			full++;
			break;
		}
	}
	return 1;
}
//==============================================================================
CMD:fstats(playerid)
{
	if(PI[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	{
	new adm_region, patrol_service, roadpost_service, fsb, emergency_A, OPG1, OPG2, OPG3, ch_mafia, mass_media, army;
	foreach(new i: Player)
	{
		switch(PI[i][pMember])
		{
			case 1: adm_region++;
			case 2: patrol_service++;
			case 3: roadpost_service++;
			case 4: fsb++;
			case 5: emergency_A++;
			case 6: OPG1++;
			case 7: OPG2++;
			case 8: OPG3++;
			case 9: ch_mafia++;
			case 11: mass_media++;
			case 12: army++;
			default: continue;
		}
	}
	new str[400];
	format(str,sizeof(str),"{FFFFFF}Администрация области: %d чел.\nПатрульно-постовая служба: %d чел.\nДорожно-постовая служба: %d чел.\nФедеральная Служба Безопаности: %d чел.\nСкорая Медицинская Помощь г. Арзамас: %d чел.\nОПГ Южная: %d чел.\nОПГ Ореховская: %d чел.\nОПГ Солнцевская: %d чел.\nЧеченская Мафия: %d чел.\nСредство Массовой Информации г. Южный: %d чел.\nВоинская часть: %d чел.",
	adm_region, patrol_service, roadpost_service, fsb, emergency_A, OPG1, OPG2, OPG3, ch_mafia, mass_media, army);
	ShowPlayerDialog(playerid, D_NULL, 0, "{FFCC00}Cписок игроков", str, "Закрыть","");
	}
	return 1;
}
//==============================================================================
CMD:vsellgun(playerid, params[])
{
	if(!PI[playerid][pVip]) return SendClientMessage(playerid, COLOR_RED, "Вы не имеете VIP статус");

	else if(sscanf(params, "uiii", params[0], params[1], params[2], params[3])) return SCM(playerid, COLOR_LIME, "Информация: {ffffff}/vsellgun [id игрока] [id оружия] [патроны] [цена]");
	else if(!IsPlayerConnected(params[0])) return SCM(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SCM(playerid, COLOR_RED, "Игрок не ввел пароль!");
	if(params[1] == 24 || params[1] == 25 || params[1] == 29 || params[1] == 23 || params[1] == 30 || params[1] == 31 || params[1] == 33)
	{
		if(params[2] < 1 || params[2] > 500) return SCM(playerid, COLOR_RED, "Количество патронов от 1 до 500!");
		if(params[3] < 1 || params[3] > 100000) return SCM(playerid, COLOR_RED, "Цена от 1 до 100000 рублей");
		if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SCM(playerid, COLOR_RED, "Игрок слишком далеко!");
		if(PI[playerid][pPatron] < params[2]) return SCM(playerid, COLOR_RED, "У Вас недостаточно материалов!");
		SendMes(playerid, COLOR_BLUE, "Вы предложили %s купить У Вас %s с %i пт. за %i рублей", GetName(params[0]), WeaponNames[params[1]], params[2], params[3]);
		SendMes(params[0], COLOR_BLUE, "Игрок %s предложил Вам купить %s (%i) с %i пт. за %i рублей", GetName(playerid), WeaponNames[params[1]], params[1], params[2], params[3]);
		SCM(params[0], COLOR_WHITE, "{FFFFFF}Нажмите {03c03c}Y {FFFFFF}чтобы согласиться или {ff7518}N {FFFFFF}для отказа");
		SetPVarInt(params[0], "KeyGun", 1);
		SetPVarInt(params[0], "PlayerGun", playerid);
		SetPVarInt(params[0], "PlayerGun_", params[1]);
		SetPVarInt(params[0], "PlayerGAmmo", params[2]);
		SetPVarInt(params[0], "PlayerGPrice", params[3]);
	} else return SCM(playerid, COLOR_RED, "Неверный ID оружия! ID оружия: 23, 24, 25, 29, 30, 31, 33");

	return 1;
}
//==============================================================================
CMD:showall(playerid)
{
    if(GetPVarInt(playerid, "logged") == 0) return 1;

    if(PI[playerid][pRank] < 9)
		return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная возможность");

	ShowPlayerDialog
	(
		playerid, DIALOG_SHOWALL, DIALOG_STYLE_LIST,
		"{FFCC00}Сортирование",
		"{FFFFFF}1. По возврастанию ранга\n\
		2. По убыванию ранга\n\
		3. По возврастанию даты входа\n\
		4. По убыванию даты входа\n\
		5. По возврастанию уровня\n\
		6. По убыванию уровня\n\
		7. По алфавиту",
		"Далее", "Отмена"
	);
    return 1;
}
//==============================================================================
CMD:makegun(playerid)
{
	if(!IsAGang(playerid) && !IsAArmy(playerid) && !IsAMafia(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	ShowPlayerDialogCreateGun(playerid);
	return 1;
}
//==============================================================================
/*CMD:loadgun(playerid)
{
	if(!IsAArmy(playerid) && !IsAMafia(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if(gVehicleGun[vehicleid][vGunLoading] || gVehicleGun[vehicleid][vGunUnloading]) return SendClientMessage(playerid, COLOR_RED, "Авто уже стоит на загрузке / разгрузке");
		gVehicleGun[vehicleid][vGunLoading] = true;
		RemovePlayerFromVehicle(playerid);
		new Float:x, Float:y, Float:z, Float:a;
		GetVehiclePos(vehicleid, x, y, z);
		GetVehicleZAngle(vehicleid, a);
		switch(GetVehicleModel(vehicleid))
		{
		    case 433:
		    {
		        x = x - (-6.0*floatsin(a, degrees));
				y = y - 5.5*floatcos(a, degrees);
				gVehicleGun[vehicleid][vGunPickup] = CreateDynamicPickup(1318, 1, x, y, z-0.5); //Пикап грузовиков
		    }
		    case 470,500,482,526,467,587,550,489,580,491:
		    {
		        x = x - (-3.0*floatsin(a, degrees));
				y = y - 3.5*floatcos(a, degrees);
				gVehicleGun[vehicleid][vGunPickup] = CreateDynamicPickup(1318, 1, x, y, z-0.2); //Пикап для легковых авто
		    }
		    default: SendClientMessage(playerid, COLOR_RED, "Вы должны быть в машине предназначенной для загрузки!");
		}
		new string[128];
		format(string, sizeof(string), "Метал: {63BD4E}%d\n{FFFFFF}Патронов: {63BD4E}%d", gVehicleGun[vehicleid][vGunGunAmount], gVehicleGun[vehicleid][vGunAmmo]);
		gVehicleGun[vehicleid][vGunText] = CreateDynamic3DTextLabel(string, 0xFFFFFFFF, x, y, z+0.5, 20.0);
		gVehicleGun[vehicleid][vGunArea] = CreateDynamicSphere(x, y, z, 1.0);
		print("Iter_Add(VehicleGun, vehicleid);");
		Iter_Add(VehicleGun, vehicleid);
		SendClientMessage(playerid, COLOR_GREEN, "Загрузка началась");
	}
	return 1;
}*/

cmd:load(playerid)
{
	if(!IsAArmy(playerid) && !IsAMafia(playerid)) return SendErr(playerid, "Вам недоступна данная функция");
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if(gVehicleGun[vehicleid][vGunLoading] || gVehicleGun[vehicleid][vGunUnloading]) return SendErr(playerid, "Авто уже стоит на загрузке / разгрузке");
		gVehicleGun[vehicleid][vGunLoading] = true;
		RemovePlayerFromVehicle(playerid);
		new Float:x, Float:y, Float:z, Float:a;
		GetVehiclePos(vehicleid, x, y, z);
		GetVehicleZAngle(vehicleid, a);
		switch(GetVehicleModel(vehicleid))
		{
			case 433:
			{
				x = x - (-4.5*floatsin(a, degrees));
				y = y - 5.5*floatcos(a, degrees);
				gVehicleGun[vehicleid][vGunPickup] = CreateDynamicPickup(3013, 1, x, y, z-0.5, -1); //Пикап грузовиков
			}
			case 400,404,436,466,475,489,492,579,482:
			{
				x = x - (-3.0*floatsin(a, degrees));
				y = y - 3.5*floatcos(a, degrees);
				gVehicleGun[vehicleid][vGunPickup] = CreateDynamicPickup(3013, 1, x, y, z-0.2, -1); //Пикап для легковых авто
			}
			default: SendErr(playerid, "Вы должны быть в машине предназначенной для загрузки");
		}
		new string[160];
		if(IsAMafia(playerid))
		{
			format(string, sizeof(string),"{f0f0f0}Загрузка: \n"cBLUE"%d{f0f0f0} из "cBLUE" 20{f0f0f0} ящиков\n"cBLUE"%d{f0f0f0} из "cBLUE" 20{f0f0f0} пакетов", gVehicleGun[vehicleid][vGunAmmo], gVehicleGun[vehicleid][vGunNarko]);
		}
		else
		{
			format(string, sizeof(string),"{f0f0f0}Загрузка: \n"cBLUE"%d{f0f0f0} из "cBLUE" 20{f0f0f0} ящиков", gVehicleGun[vehicleid][vGunAmmo]);
		}
		gVehicleGun[vehicleid][vGunText] = CreateDynamic3DTextLabel(string, 0xFFFFFFFF, x, y, z+0.8, 20.0);
		gVehicleGun[vehicleid][vGunArea] = CreateDynamicSphere(x, y, z, 1.0);
		Iter_Add(VehicleGun, vehicleid);
		SendClientMessage(playerid, COLOR_GREEN, "Загрузка началась");
	}
	return 1;
}

/*CMD:unloadgun(playerid)
{
	if(!IsAArmy(playerid) && !IsAMafia(playerid)) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if(gVehicleGun[vehicleid][vGunLoading] || gVehicleGun[vehicleid][vGunUnloading]) return SendClientMessage(playerid, COLOR_RED, "Авто уже стоит на загрузке / разгрузке");
		gVehicleGun[vehicleid][vGunUnloading] = true;
		RemovePlayerFromVehicle(playerid);
		new Float:x, Float:y, Float:z, Float:a;
		GetVehiclePos(vehicleid, x, y, z);
		GetVehicleZAngle(vehicleid, a);
    	switch(GetVehicleModel(vehicleid))
		{
		    case 433:
		    {
		        x = x - (-6.0*floatsin(a, degrees));
				y = y - 5.5*floatcos(a, degrees);
				gVehicleGun[vehicleid][vGunPickup] = CreateDynamicPickup(1318, 1, x, y, z-0.5); //Пикап грузовиков
		    }
		    case 470,500,482,526,467,587,550,489,580,491:
		    {
		        x = x - (-3.0*floatsin(a, degrees));
				y = y - 3.5*floatcos(a, degrees);
				gVehicleGun[vehicleid][vGunPickup] = CreateDynamicPickup(1318, 1, x, y, z-0.2); //Пикап для легковых авто
		    }
		    default: SendClientMessage(playerid, COLOR_RED, "Вы должны быть в машине предназначенной для загрузки!");
		}
		new string[128];
		format(string, sizeof(string), "Метал: {63BD4E}%d\n{FFFFFF}Патронов: {63BD4E}%d", gVehicleGun[vehicleid][vGunGunAmount], gVehicleGun[vehicleid][vGunAmmo]);
		gVehicleGun[vehicleid][vGunText] = CreateDynamic3DTextLabel(string, 0xFFFFFFFF, x, y, z+0.5, 20.0);
		gVehicleGun[vehicleid][vGunArea] = CreateDynamicSphere(x, y, z, 1.0);
		print("Iter_Add(VehicleGun, vehicleid);");
		Iter_Add(VehicleGun, vehicleid);
		SendClientMessage(playerid, COLOR_GREEN, "Разгрузка началась");
	}
	return 1;
}*/

cmd:unload(playerid)
{
	if(!IsAArmy(playerid) && !IsAMafia(playerid)) return SendErr(playerid, "Вам недоступна данная функция");
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if(gVehicleGun[vehicleid][vGunLoading] || gVehicleGun[vehicleid][vGunUnloading]) return SendErr(playerid, "Авто уже стоит на загрузке / разгрузке");
		gVehicleGun[vehicleid][vGunUnloading] = true;
		RemovePlayerFromVehicle(playerid);
		new Float:x, Float:y, Float:z, Float:a;
		GetVehiclePos(vehicleid, x, y, z);
		GetVehicleZAngle(vehicleid, a);
		switch(GetVehicleModel(vehicleid))
		{
			case 433:
			{
				x = x - (-6.0*floatsin(a, degrees));
				y = y - 5.5*floatcos(a, degrees);
				gVehicleGun[vehicleid][vGunPickup] = CreateDynamicPickup(1318, 1, x, y, z-0.5, -1); //Пикап грузовиков
			}
			case 400,404,436,466,475,489,492,579,482:
			{
				x = x - (-3.0*floatsin(a, degrees));
				y = y - 3.5*floatcos(a, degrees);
				gVehicleGun[vehicleid][vGunPickup] = CreateDynamicPickup(1318, 1, x, y, z-0.2, -1); //Пикап для легковых авто
			}
			default: SendErr(playerid, "Вы должны быть в машине предназначенной для загрузки!");
		}
		new string[160];
		if(IsAMafia(playerid))
		{
			format(string, sizeof(string),"{f0f0f0}Загрузка: \n"cBLUE"%d{f0f0f0} из "cBLUE" 20{f0f0f0} ящиков\n"cBLUE"%d{f0f0f0} из "cBLUE" 20{f0f0f0} пакетов", gVehicleGun[vehicleid][vGunAmmo], gVehicleGun[vehicleid][vGunNarko]);
		}
		else
		{
			format(string, sizeof(string),"{f0f0f0}Загрузка: \n"cBLUE"%d{f0f0f0} из "cBLUE" 20{f0f0f0} ящиков", gVehicleGun[vehicleid][vGunAmmo]);
		}
		gVehicleGun[vehicleid][vGunText] = CreateDynamic3DTextLabel(string, 0xFFFFFFFF, x, y, z+0.8, 20.0);
		gVehicleGun[vehicleid][vGunArea] = CreateDynamicSphere(x, y, z, 1.0);
		Iter_Add(VehicleGun, vehicleid);
		SendClientMessage(playerid, COLOR_GREEN, "Разгрузка началась");
	}
	return 1;
}

CMD:givemetal(playerid, params[])
{
	if(sscanf(params, "ui", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/giveguns [id игрока] [количество]");
	else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(params[1] < 0) return SendClientMessage(playerid, COLOR_RED, "Неверное количество!");
	else if(PI[playerid][pGunAmount] < params[1]) return SendClientMessage(playerid, COLOR_RED, "У Вас недостаточно металла");
	else if(PI[params[0]][pGunAmount]+params[1] > 500 && !PI[playerid][pImprove][2]) return SendClientMessage(playerid, COLOR_RED, "Игрок не может взять Метал!");
	else if(PI[params[0]][pGunAmount]+params[1] > 1000 && PI[playerid][pImprove][2]) return SendClientMessage(playerid, COLOR_RED, "Игрок не может взять Метал!");
	PI[playerid][pGunAmount] -= params[1];
	PI[params[0]][pGunAmount] += params[1];
	new string[128];
	format(string, sizeof(string), "UPDATE `accounts` SET gunamount=%i,gunamount=%i WHERE id=%i LIMIT 1", PI[playerid][pGunAmount], PI[params[0]][pGunAmount], PI[playerid][pID]);
	mysql_tquery(dbHandle, string, "", "");
	string = "\0";
	format(string, sizeof(string), "передал единицы оружия %s", GetName(params[0]));
	MeAction(playerid, string);
	format(string, sizeof(string), "Вы передали %s %d Метал", GetName(params[0]), params[1]);
	SendClientMessage(playerid, COLOR_WHITE, string);
	format(string, sizeof(string), "%s передал Вам %d Метал", GetName(playerid), params[1]);
	SendClientMessage(params[0], COLOR_WHITE, string);
	return 1;
}

CMD:givepatr(playerid, params[])
{
	if(sscanf(params, "ui", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/givepatr [id игрока] [количество]");
	else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(params[1] < 0) return SendClientMessage(playerid, COLOR_RED, "Неверное количество!");
	else if(PI[playerid][pPatron] < params[1]) return SendClientMessage(playerid, COLOR_RED, "У Вас нет столько патрон!");
	else if(PI[params[0]][pPatron]+params[1] > 500 && !PI[playerid][pImprove][2]) return SendClientMessage(playerid, COLOR_RED, "Игрок не может взять столько патрон!");
	else if(PI[params[0]][pPatron]+params[1] > 1000 && PI[playerid][pImprove][2]) return SendClientMessage(playerid, COLOR_RED, "Игрок не может взять столько патрон!");
	PI[playerid][pPatron] -= params[1];
	PI[params[0]][pPatron] += params[1];
	new string[128];
	format(string, sizeof(string), "UPDATE `accounts` SET patron=%i,patron=%i WHERE id=%i LIMIT 1", PI[playerid][pPatron], PI[params[0]][pPatron], PI[playerid][pID]);
	mysql_tquery(dbHandle, string, "", "");
	string = "\0";
	format(string, sizeof(string), "передал патроны %s", GetName(params[0]));
	MeAction(playerid, string);
	format(string, sizeof(string), "Вы передали %s %d пт", GetName(params[0]), params[1]);
	SendClientMessage(playerid, COLOR_WHITE, string);
	format(string, sizeof(string), "%s передал Вам %d пт", GetName(playerid), params[1]);
	SendClientMessage(params[0], COLOR_WHITE, string);
	return 1;
}

CMD:flower(playerid, params[])
{
    if(!HaveWeapon(playerid, 14)) return SendClientMessage(playerid, COLOR_RED, "У Вас нет цветов!");
    else if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/flower [id игрока]");
	else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Самому себе нельзя передавать!");
	else if(HaveWeapon(params[0], 14)) return SendClientMessage(playerid, COLOR_RED, "У игрока уже есть цветы!");
	RemovePlayerWeapon(playerid, 14);
	GivePlayerWeaponAC(params[0], 14, 1);
	new string[128];
	format(string, sizeof(string), "передал цветы %s", GetName(params[0]));
	MeAction(playerid, string);
	format(string, sizeof(string), "Вы передали %s цветы", GetName(params[0]), params[1]);
	SendClientMessage(playerid, COLOR_WHITE, string);
	format(string, sizeof(string), "%s передал Вам цветы", GetName(playerid), params[1]);
	SendClientMessage(params[0], COLOR_WHITE, string);
	return 1;
}

CMD:sellsim(playerid, params[])
{
	if(PI[playerid][pPhoneNumber] <= 1) return SendClientMessage(playerid, COLOR_RED, "У Вас нет SIM-карты!");
	else if(sscanf(params, "ui", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/sellsim [id игрока] [цена]");
	else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
	else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
	else if(playerid == params[0]) return SendClientMessage(playerid, COLOR_RED, "Самому себе нельзя продавать SIM-карту!");
	else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
	else if(params[1] < 1 || params[1] > 1000000) return SendClientMessage(playerid, COLOR_RED, "Цена должна быть от 1 до 1.000.000 рублей");
	new string[144];
	format(string, sizeof(string), "Вы предложили %s купить SIM-карту. Цена: %i рублей", GetName(params[0]), params[1]);
	SendClientMessage(playerid, COLOR_BLUE, string);
	format(string, sizeof(string), "%s предложил Вам купить SIM-карту. Цена: %i рублей", GetName(playerid), params[1]);
	SendClientMessage(params[0], COLOR_BLUE, string);
	SendClientMessage(params[0], COLOR_WHITE, "{FFFFFF}Нажмите {03c03c}Y {FFFFFF}чтобы согласиться или {ff7518}N {FFFFFF}для отказа");
	SetPVarInt(params[0], "KeySim", 1);
	SetPVarInt(params[0], "PlayerSim", playerid);
	SetPVarInt(params[0], "SimPrice", params[1]);
	return 1;
}

CMD:sellzone(playerid, params[])
{
	if(PI[playerid][pLeader] && IsAGang(playerid))
	{
		new full = 0;
		for(new i = 0; i < sizeof(GZInfo); i++)
		{
			if(IsPlayerToSquare(playerid,GZInfo[i][gCoords][0], GZInfo[i][gCoords][1],GZInfo[i][gCoords][2],GZInfo[i][gCoords][3]) && ZoneOnBattle[i] == 0)
			{
				if(GZInfo[i][gFrak] != PI[playerid][pMember]) return SendClientMessage(playerid, COLOR_RED, "Вы не можете продать чужую зону!");
				else if(sscanf(params, "ui", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/sellzone [id игрока] [цена]");
				else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
				else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
				else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вы не можете продать зону себе!");
				else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
				else if(!IsAGang(params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок должен состоять в какой-нибудь банде!");
				else if(!PI[params[0]][pLeader]) return SendClientMessage(playerid, COLOR_RED, "Игрок не руководитель банды!");
				else if(params[1] < 1 || params[1] > 100000) return SendClientMessage(playerid, COLOR_RED, "Цена от 1 до 100000 доллара(ов)!");
				SendMes(playerid, COLOR_BLUE, "Вы предложили %s купить зону. Цена: %i  рублей", GetName(params[0]), params[1]);
				SendMes(params[0], COLOR_BLUE, "%s предложил Вам купить зону. Цена: %i  рублей", GetName(playerid), params[1]);
				SendClientMessage(params[0], COLOR_WHITE, "{FFFFFF}Нажмите {03c03c}Y {FFFFFF}чтобы согласиться или {ff7518}N {FFFFFF}для отказа");
				SetPVarInt(params[0], "KeyZone", 1);
				SetPVarInt(params[0], "PlayerZone", playerid);
				SetPVarInt(params[0], "ZonePrice", params[1]);
				SetPVarInt(params[0], "ZoneID", i);
				full++;
			}
		}
		if(full == 0) SendClientMessage(playerid, COLOR_RED, "Вы должны находится в своей зоне!!");
	}
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}
CMD:repair(playerid, params[])
{
	if(PI[playerid][pJob] == JOB_MECHANIC)
	{
		if(GetPlayerState(playerid) != 2) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится за рулем эвакуатора!");
		new carid = GetPlayerVehicleID(playerid);
		if(carid >= mechanic[0] && carid <= mechanic[1] || GetVehicleModel(carid) == 525)
		{
			if(sscanf(params, "ui", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/repair [ид игрока] [цена]");
			else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
			else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
			else if(params[1] < 1 || params[1] > 1000) return SendClientMessage(playerid, COLOR_RED, "Цена от 1 до 1000 рублей!");
			else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
			else if(GetPlayerState(params[0]) != 2) return SendClientMessage(playerid, COLOR_RED, "Игрок должен находится за рулем транспорта!");
			else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Вs не можете починить машину себе!");
			SendMes(playerid, COLOR_BLUE, "Вы предложили %s отремонтировать его транспорт за %i рублей", GetName(params[0]), params[1]);
			SendMes(params[0], COLOR_BLUE, "%s предложил Вам отремонтировать транспорт за {FFFFFF}%i рублей", GetName(playerid), params[1]);
			new string[100];
			format(string, sizeof(string), "Механик %s предлагает Вам отремонтировать транспорт за %i рублейй\n\nВы согласны?", GetName(playerid), params[1]);
			ShowPlayerDialog(params[0], D_JOB+67, 0, "Автомеханик", string, "Да", "Нет");
			SetPVarInt(playerid, "MechVehID", GetPlayerVehicleID(params[0]));
			SetPVarInt(params[0], "PlayerMech", playerid);
			SetPVarInt(params[0], "MechanicPrice", params[1]);
		}
		else SendClientMessage(playerid, COLOR_RED, "Вы должны находится в эвакуаторе!");
	}
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}

CMD:refill(playerid, params[])
{
	if(PI[playerid][pJob] == JOB_MECHANIC)
	{
		if(GetPlayerState(playerid) != 2) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится за рулем эвакуатора!");
		new carid = GetPlayerVehicleID(playerid);
		if(carid >= mechanic[0] && carid <= mechanic[1] || GetVehicleModel(carid) == 525)
		{
			if(sscanf(params, "ui", params[0], params[1])) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/refill [id игрока] [цена]");
			else if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "Такого игрока нет");
			else if(PlayerLogged[params[0]] == false) return SendClientMessage(playerid, COLOR_RED, "Игрок не ввел пароль!");
			else if(params[1] < 1 || params[1] > 5000) return SendClientMessage(playerid, COLOR_RED, "Цена от 1 до 5000 рублей!");
			else if(!IsPlayerInRangeOfPlayer(8.0, playerid, params[0])) return SendClientMessage(playerid, COLOR_RED, "Игрок слишком далеко!");
			else if(GetPlayerState(params[0]) != 2) return SendClientMessage(playerid, COLOR_RED, "Игрок должен находится за рулем транспорта!");
			else if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Ты не можешь заправить себе машин!");
			SendMes(playerid, COLOR_LIGHTBLUE, "Вы предложили %s заправить его транспорт за %i рублей", GetName(params[0]), params[1]);
			SendMes(params[0], COLOR_LIGHTBLUE, "%s преложил Вам заправить ваш транспорт за {FFFFFF}%i рублей", GetName(playerid), params[1]);
			new string[100];
			format(string, sizeof(string), "%s преложил Вам заправить ваш транспорт за %i рублей\n\nВы согласны?", GetName(playerid), params[1]);
			ShowPlayerDialog(params[0], D_JOB+130, 0, "Автомеханик", string, "Да", "Нет");
			SetPVarInt(params[0], "MechanicPlayer", playerid);
			SetPVarInt(params[0], "MechanicPrice", params[1]);
		}
		else SendClientMessage(playerid, COLOR_RED, "Вы должны находится в эвакуаторе!");
	}
	else SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	return 1;
}

CMD:fill(playerid, params[])
{
	if(GetPlayerState(playerid) != 2) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится за рулем!");
	if(Fuel[GetPlayerVehicleID(playerid)] >= 100) return SendClientMessage(playerid, COLOR_RED, "Ваш бак полон!");
	if(GetPVarInt(playerid, "Refueling") > 0) return SendClientMessage(playerid, COLOR_RED, "Вы уже заправляетесь!");
	new full;
	for(new i = 1; i <= TOTALBIZZ; i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 5.0, BizzInfo[i][bEntrx], BizzInfo[i][bEntry], BizzInfo[i][bEntrz])
				&& BizzInfo[i][bType] == 2)
		{
			ShowPlayerDialog(playerid, D_JOB+128, 1,"{FFCC00}Заправка", "{ffffff}Введите количество литров для заправки транспорта.", "Далее", "Отмена");
			full++;
			SetPVarInt(playerid, "FuelBizzID", i);
		}
	}
	if(full == 0) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится у заправки!");
	return true;
}
//==============================================================================
/*CMD:end(playerid, params[])
{
	if(PI[playerid][pJob] != JOB_BUS) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(GetPlayerState(playerid) != 2) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится за рулем автобуса!");
	new carid = GetPlayerVehicleID(playerid);
	if(carid >= buscar[0] && carid <= buscar[1])
	{
		if(GetPVarInt(playerid, "PriceBus") > 0)
		{
		    new CB[16];
		    TimeConverter(PI[playerid][pBusTime], CB);
			SendMes(playerid, COLOR_BLUE, "Рабочий день завершен. Вами заработано: %i рублей. Время рейса: %s", GetPVarInt(playerid, "BusMoney"), CB);
			SendClientMessage(playerid, COLOR_WHITE, "Деньги будут перечислены на счет во время зарплаты (PayDay)");
			PI[playerid][pPayCheck] += GetPVarInt(playerid, "BusMoney");
			DeletePVar(playerid, "BusTime");
			DeletePVar(playerid, "TypeBus");
			DeletePVar(playerid, "PriceBus");
			DeletePVar(playerid, "BusStop");
			DeletePVar(playerid, "BusMoney");
			PI[playerid][pBusTime] = 0;
			pPressed[playerid] = 0;
			if(IsValidDynamic3DTextLabel(BusText3D[playerid])) DestroyDynamic3DTextLabel(BusText3D[playerid]);
			SetVehicleToRespawn(GetPlayerVehicleID(playerid));
			DisablePlayerRaceCheckpoint(playerid);
			return 1;
		}
	}
	else SendClientMessage(playerid, COLOR_RED, "Вы должны находится в автобусе!");
	return 1;
}*/

CMD:fare(playerid, params[])
{
	if(PI[playerid][pJob] != JOB_TAXI) return SendClientMessage(playerid, COLOR_RED, "Вам недоступна данная функция");
	if(GetPlayerState(playerid) != 2) return SendClientMessage(playerid, COLOR_RED, "Вы должны находится за рулем такси!");
	new carid = GetPlayerVehicleID(playerid);
	if(carid >= taxicar[0] && carid <= taxicar[1])
	{
		if(GetPVarInt(playerid, "PriceTaxi") > 0)
		{
			SendMes(playerid, COLOR_BLUE, "Рабочий день завершен. Вами заработано: %i рублей", GetPVarInt(playerid, "TaxiMoney"));
			SendClientMessage(playerid, COLOR_WHITE, "Деньги будут перечислены на счет во время зарплаты");
			DeletePVar(playerid, "PriceTaxi");
			DeletePVar(playerid, "TaxiMoney");
			if(IsValidDynamic3DTextLabel(TaxiText3D[playerid])) DestroyDynamic3DTextLabel(TaxiText3D[playerid]);
			return 1;
		}
		ShowPlayerDialog(playerid, D_JOB+57, 1, "{FFCC00}Тариф", "{ffffff}Введите стоимость проезда:", "Принять", "Отмена");
	}
	else SendClientMessage(playerid, COLOR_RED, "Вы должны находится в такси!");
	return 1;
}
CMD:nitro(playerid)
{
    if(PI[playerid][pAdmin] < 4) return 1;
	else if(PI[playerid][pAdmin] < 1) return SCM(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");
	else if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, COLOR_RED, "Вы должны находится в транспорте!");
    SCM(playerid,COLOR_BLUE,"Вы установили временное нитро на x10 запусков");
	AddVehicleComponent(GetPlayerVehicleID(playerid),1010);
	return 1;
}
CMD:rt(playerid,params[])
{
    if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
    else if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");
    new Float:px,Float:py,Float:pz,string[128];
    if(sscanf(params,"p<,>fff",px,py,pz)) return SendClientMessage(playerid, COLOR_LIME, "Информация: {ffffff}/rt <x, y, z>");
    SetPlayerPos(playerid,px,py,pz);
    format(string, sizeof(string), "Вы были телепортированны на указанные Вами координаты: %f, %f, %f",px,py,pz);
    SendClientMessage(playerid, 0xFFFFFFFF, string);
    return 1;
}
