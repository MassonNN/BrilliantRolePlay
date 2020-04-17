// Functions Perfomance Role Play

//==============================================================================
/*stock LoadCars()
{
    // Автомобили Чеченской Мафии в пгт. Батырево
 	chechen_mafia[0] = AddStaticVehicleEx(579,1938.4396,2162.3931,15.8537,338.2932,1,1, 900); // Автомобиль Чеченская Мафия пгт. Батырево
	AddStaticVehicleEx(579,1933.2781,2162.4089,15.7729,338.3034,1,1, 900); // Автомобиль Чеченская Мафия пгт. Батырево
	AddStaticVehicleEx(579,1927.7268,2162.4390,15.7724,338.7794,1,1, 900); // Автомобиль Чеченская Мафия пгт. Батырево
	AddStaticVehicleEx(540,1922.1433,2161.5642,15.4714,338.4219,1,1, 900); // Автомобиль Чеченская Мафия пгт. Батырево
	AddStaticVehicleEx(540,1930.1125,2171.3899,15.4715,265.7278,1,1, 900); // Автомобиль Чеченская Мафия пгт. Батырево
	AddStaticVehicleEx(482,1939.0087,2186.1685,15.5935,271.1104,1,1, 900); // Автомобиль Чеченская Мафия пгт. Батырево
	AddStaticVehicleEx(482,1939.1074,2188.7380,15.6467,273.4596,1,1, 900); // Автомобиль Чеченская Мафия пгт. Батырево
	chechen_mafia[1] = AddStaticVehicleEx(540,1951.6643,2206.7141,15.5248,180.0455,1,1, 900); // Автомобиль Чеченская Мафия пгт. Батырево
 	// Автомобили Русской Мафии в пгт. Арзамас
 	russian_mafia[0] = AddStaticVehicleEx(579,384.9605,1034.0248,12.2951,353.0691,0,0, 900); // Автомобиль Русская Мафия пгт. Батырево
	AddStaticVehicleEx(579,380.9216,1034.3499,12.2998,352.6057,0,0, 900); // Автомобиль Русская Мафия пгт. Батырево
	AddStaticVehicleEx(579,377.0201,1034.9999,12.2777,351.9909,0,0, 900); // Автомобиль Русская Мафия пгт. Батырево
	AddStaticVehicleEx(500,366.8302,1043.5325,12.0552,261.1548,0,0, 900); // Автомобиль Русская Мафия пгт. Батырево
	AddStaticVehicleEx(500,367.3383,1047.6759,12.0543,260.1719,0,0, 900); // Автомобиль Русская Мафия пгт. Батырево
	AddStaticVehicleEx(500,391.0331,1045.1917,12.0528,260.9227,0,0, 900); // Автомобиль Русская Мафия пгт. Батырево
	AddStaticVehicleEx(482,383.2562,1058.8158,12.0861,170.8264,0,0, 900); // Автомобиль Русская Мафия пгт. Батырево
	russian_mafia[1] = AddStaticVehicleEx(482,379.3456,1059.3954,12.0921,170.8241,0,0, 900); // Автомобиль Русская Мафия пгт. Батырево
	return 1;
}*/
//==============================================================================
stock UpdateBizz(idx)
{
	new string[200],fee[64],text[20];
	if(BizzInfo[idx][bEnter] == 0) fee = "бесплатно";
	else format(fee, sizeof(fee), "%d рублей", BizzInfo[idx][bEnter]);
	switch(BizzInfo[idx][bMafia])
	{
	    case TEAM_SPARTAK: text = "ОПГ Ореховское";
	    case TEAM_CSKA: text = "ОПГ Солнце";
	    case TEAM_DINAMO: text = "ОПГ Южная";
		case 0: text = "отсутствует";
	}
	if(BizzInfo[idx][bType] == 1)
	{
		if(!strcmp(BizzInfo[idx][bOwner],"None",true))
		{
			format(string, sizeof(string), "{FFCC00}Магазин 24/7\n{FFFFFF}Владелец: {FFCC00}государство\n{FFFFFF}Контролирует: {3497FF}%s\n{FFFFFF}Цена: {FFCC00}%d {FFFFFF}рублей\n{FFFFFF}Вход: {FFCC00}бесплатный",text,BizzInfo[idx][bPrice]);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
		else
		{
			format(string, sizeof(string), "{0099FF}Магазин 24/7\n{FFFFFF}Владелец: {0099FF}%s\n{FFFFFF}Контролирует: {3497FF}%s\n{FFFFFF}Вход: {FFCC00}%s",BizzInfo[idx][bOwner], text, fee);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
	}
	if(BizzInfo[idx][bType] == 10)
	{
		if(!strcmp(BizzInfo[idx][bOwner],"None",true))
		{
			format(string, sizeof(string), "{3497FF}Магазин Игрушек\n{FFFFFF}Владелец: {FFCC00}государство\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена: {FFCC00}%d {FFFFFF}рублей\n{FFFFFF}Цена за вход: {FFCC00}бесплатный",text,BizzInfo[idx][bPrice]);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
		else
		{
			format(string, sizeof(string), "{3497FF}Магазин Игрушек\n{FFFFFF}Владелец: {0099FF}%s\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена за вход: {FFCC00}%s",BizzInfo[idx][bOwner],text, fee);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
	}
	else if(BizzInfo[idx][bType] == 9)
	{
		if(!strcmp(BizzInfo[idx][bOwner],"None",true))
		{
			format(string, sizeof(string), "{3497FF}Казино\n{FFFFFF}Владелец: {FFCC00}государство\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена: {FFCC00}%d {FFFFFF}рублей\n{FFFFFF}Цена за вход: {FFCC00}бесплатный",text,BizzInfo[idx][bPrice]);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
		else
		{
			format(string, sizeof(string), "{3497FF}Казино\n{FFFFFF}Владелец: {0099FF}%s\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена за вход: {FFCC00}%s",BizzInfo[idx][bOwner],text, fee);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
	}
	else if(BizzInfo[idx][bType] == 2)
	{
		if(!strcmp(BizzInfo[idx][bOwner],"None",true))
		{
			format(string, sizeof(string), "{FFCC00}Заправка\n{FFCC00}Заправка продаётся\n{FFFFFF}Цена: {FFCC00}%d рублей\n{ffffff}Цена за 1 литр - {FFCC00}%i рублей\n{FFCC00}Используйте /fill",BizzInfo[idx][bPrice], BizzInfo[idx][bTill]);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
		else
		{
			format(string, sizeof(string), "{FFCC00}/buyk - купить канистру\n/fill - заправить транспорт\n{FFFFFF}Владелец: {FFCC00}%s\n{FFFFFF}Цена за 1 литр бензина: {FFCC00}%i рублей",BizzInfo[idx][bOwner], BizzInfo[idx][bTill]);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
	}
	else if(BizzInfo[idx][bType] == 7)
	{
		if(!strcmp(BizzInfo[idx][bOwner],"None",true))
		{
			format(string, sizeof(string), "{3497FF}СТО\n{FFFFFF}Владелец: {FFCC00}государство\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена: {FFCC00}%d {FFFFFF}руб.",text,BizzInfo[idx][bPrice]);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
		else
		{
			format(string, sizeof(string), "{3497FF}СТО\n{FFFFFF}Владелец: {FFCC00}%s\n{FFFFFF}Крышует: {3497FF}%s",BizzInfo[idx][bOwner],text);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
	}
	else if(BizzInfo[idx][bType] == 8)
	{
   		if(!strcmp(BizzInfo[idx][bOwner],"None",true))
		{
			format(string, sizeof(string), "{3497FF}Магазин Одежды\n{FFFFFF}Владелец: {FFCC00}государство\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена: {FFCC00}%d {FFFFFF}рублей\n{FFFFFF}Цена за вход: {FFCC00}бесплатный",text,BizzInfo[idx][bPrice]);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
		else
		{
			format(string, sizeof(string), "{3497FF}Магазин Одежды\n{FFFFFF}Владелец: {FFCC00}%s\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена за вход: {FFCC00}%s",BizzInfo[idx][bOwner],text,fee);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
	}
	else if(BizzInfo[idx][bType] == 14)
	{
		if(!strcmp(BizzInfo[idx][bOwner],"None",true))
		{
			format(string, sizeof(string), "{3497FF}Аптека\n{FFFFFF}Владелец: {FFCC00}государство\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена: {FFCC00}%d {FFFFFF}рублей\n{FFFFFF}Цена за вход: {FFCC00}бесплатный", text,BizzInfo[idx][bPrice]);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
		else
		{
			format(string, sizeof(string), "{3497FF}Аптека\n{FFFFFF}Владелец: {FFCC00}%s\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена за вход: {FFCC00}%s",BizzInfo[idx][bOwner],text,fee);
			UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
		}
	}
	return 1;
}

stock UpdateHouse(idx)
{
	DestroyDynamicMapIcon(HouseInfo[idx][hMIcon]);
	DestroyDynamicPickup(HouseInfo[idx][hPickup]);
	if(!strcmp(HouseInfo[idx][hOwner],"None",true))
	{
		HouseInfo[idx][hMIcon] = CreateDynamicMapIcon(HouseInfo[idx][hEntrx], HouseInfo[idx][hEntry], HouseInfo[idx][hEntrz], 31, 0,-1,-1,-1,150.0);
		HouseInfo[idx][hPickup] = CreateDynamicPickup(1273, 1, HouseInfo[idx][hEntrx], HouseInfo[idx][hEntry], HouseInfo[idx][hEntrz]);
	}
	else
	{
		HouseInfo[idx][hMIcon] = CreateDynamicMapIcon(HouseInfo[idx][hEntrx], HouseInfo[idx][hEntry], HouseInfo[idx][hEntrz], 32, 0,-1,-1,-1,150.0);
		HouseInfo[idx][hPickup] = CreateDynamicPickup(1272, 1, HouseInfo[idx][hEntrx], HouseInfo[idx][hEntry], HouseInfo[idx][hEntrz]);
	}
	return 1;
}
stock BuyCar(playerid)
{
	//if(GetPlayerHouse(playerid) == 1 || GetPlayerPorchHouse(playerid))
	if(GetPlayerHouse(playerid) == 1)
	{
		new Float:x, Float:y, Float:z, Float:fa,cost[MAX_PLAYERS],model[MAX_PLAYERS];
		switch(InShop[playerid])
		{
			case 1: cost[playerid] = carsC[pPressed[playerid]][1], model[playerid] = carsC[pPressed[playerid]][0], x=2640.9773, y=-1909.2632, z=2328.1699, fa=270.6537;
			case 2: cost[playerid] = carsB[pPressed[playerid]][1], model[playerid] = carsB[pPressed[playerid]][0], x=2640.9773, y=-1909.2632, z=2328.1699, fa=270.6537;
			case 3: cost[playerid] = carsA[pPressed[playerid]][1], model[playerid] = carsA[pPressed[playerid]][0], x=2640.9773, y=-1909.2632, z=2328.1699, fa=270.6537;
			case 4: cost[playerid] = carsBike[pPressed[playerid]][1], model[playerid] = carsBike[pPressed[playerid]][0], x=2640.9773, y=-1909.2632, z=2328.1699, fa=270.6537;
		}
		switch(InShop[playerid])
		{
			case 1: PI[playerid][cClass] = 1;
			case 2: PI[playerid][cClass] = 2;
			case 3: PI[playerid][cClass] = 3;
			case 4: PI[playerid][cClass] = 4;
		}
		if(PI[playerid][pCash] < cost[playerid]) return SendClientMessage(playerid, COLOR_RED, "У Вас недостаточно денег");
		InShop[playerid] = 0;
		TogglePlayerControllable(playerid,true);
		PI[playerid][pCash] -= cost[playerid];
		for(new i; i < 19; i++) PlayerTextDrawHide(playerid,choicecars[playerid][i]);
		FreezePlayer(playerid, 2000);
		SetPlayerPos(playerid,x,y,z);
		SetPlayerFacingAngle(playerid,fa);
		SetPlayerInterior(playerid,1);
		SetPlayerVirtualWorld(playerid,0);
		SetCameraBehindPlayer(playerid);

		for(new i = 0; i < 14; i++) PI[playerid][cVehcoms][i] = 0;
		format(PI[playerid][cVehcom], 64, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
		PI[playerid][cVehcoms][0],PI[playerid][cVehcoms][1],PI[playerid][cVehcoms][2],
		PI[playerid][cVehcoms][3],PI[playerid][cVehcoms][4],PI[playerid][cVehcoms][5],
		PI[playerid][cVehcoms][6],PI[playerid][cVehcoms][7],PI[playerid][cVehcoms][8],
		PI[playerid][cVehcoms][9],PI[playerid][cVehcoms][10],PI[playerid][cVehcoms][11],
		PI[playerid][cVehcoms][12],PI[playerid][cVehcoms][13]);

		PI[playerid][cModel] = model[playerid];
		PI[playerid][cCost] = cost[playerid];
		PI[playerid][cLock] = 1;
		PI[playerid][cFuel] = 100;
		PI[playerid][cColor][0] = colors[playerid][0];
		PI[playerid][cColor][1] = colors[playerid][1];
		PI[playerid][cPaintjob] = 3;

		SendClientMessage(playerid, COLOR_BLUE, "Поздравляем Вас с успешной покупкой автомобиля!");
		SendClientMessage(playerid, COLOR_BLUE, "Он появится у Вашего дома/квартиры (заберите его в подъезде)");
		//SendClientMessage(playerid, COLOR_BLUE, "Получить номер на Т/С Вы можете {FFCC00}у сотрудника{0099FF} в здании ДПС");
		SendClientMessage(playerid, COLOR_BLUE, "Получить номер на Т/С Вы можете командой{FFCC00} /mynumber{0099FF} в здании ДПС");
		SendClientMessage(playerid, COLOR_BLUE, "Найти отделение ДПС Вы можете в {FFCC00}(/gps -> 3. Организации -> 2. ДПС)");
		CancelSelectTextDraw(playerid);
		
		LoadMyCar(playerid);

		if(PI[playerid][SalonCarID] != INVALID_VEHICLE_ID) DestroyVehicle(PI[playerid][SalonCarID]);
		PI[playerid][SalonCarID] = INVALID_VEHICLE_ID;
		
		SaveAccount(playerid);

		pPressed[playerid] = 0;
		new string[128];
		format(string, sizeof(string), "Игрок %s купил транспорт %s [%i] за %d рублей", GetName(playerid), VehicleNames[GetVehicleModel(PI[playerid][PlayerCarID])-400], GetPlayerVehicleID(playerid), cost[playerid]);
		SendLog("BuyCar", string);
	}
	return 1;
}
stock BuyCloseCar(playerid)
{
	new Float:x, Float:y, Float:z, Float:fa;
	switch(InShop[playerid])
	{
 		case 1: x=2640.9773, y=-1909.2632, z=2328.1699, fa=270.6537;
  		case 2: x=2640.9773, y=-1909.2632, z=2328.1699, fa=270.6537;
		case 3: x=2640.9773, y=-1909.2632, z=2328.1699, fa=270.6537;
		case 4: x=2640.9773, y=-1909.2632, z=2328.1699, fa=270.6537;
	}
	if(PI[playerid][SalonCarID] != INVALID_VEHICLE_ID) DestroyVehicle(PI[playerid][SalonCarID]);
	PI[playerid][SalonCarID] = INVALID_VEHICLE_ID;
	InShop[playerid] = 0;
	TogglePlayerControllable(playerid,true);
	FreezePlayer(playerid, 2000);
	for(new i; i < 19; i++) PlayerTextDrawHide(playerid,choicecars[playerid][i]);
	SetPlayerPos(playerid,x,y,z);
	SetPlayerFacingAngle(playerid,fa);
	SetPlayerInterior(playerid,1);
	SetPlayerVirtualWorld(playerid,0);
	SetCameraBehindPlayer(playerid);
	pPressed[playerid] = 0;
	return 1;
}
stock LoadMyCar(playerid)
{
	if(GetPlayerHouse(playerid) != 0)
	{
		new h = GetPVarInt(playerid, "PlayerHouse");
		new carid;
		if(PI[playerid][cModel] == 0 || PI[playerid][cModel] < 400 || PI[playerid][cModel] > 611) return 1;
		if(PI[playerid][cPaintjob] > 3 || PI[playerid][cPaintjob] < 0) PI[playerid][cPaintjob] = 3;
		if(PI[playerid][PlayerCarID] != INVALID_VEHICLE_ID)
		{
			if(GetPlayerVehicleID(playerid) == PI[playerid][PlayerCarID]) RemovePlayerFromVehicle(playerid);
			DestroyVehicle(PI[playerid][PlayerCarID]);
			PI[playerid][PlayerCarID] = INVALID_VEHICLE_ID;
		}
		carid = CreateVehicle(PI[playerid][cModel], HouseInfo[h][hCarx], HouseInfo[h][hCary], HouseInfo[h][hCarz], HouseInfo[h][hCarfa], PI[playerid][cColor][0], PI[playerid][cColor][1], 90000);
		SetVehicleVirtualWorld(PI[playerid][PlayerCarID], 0);
		LinkVehicleToInterior(PI[playerid][PlayerCarID], 0);
		PI[playerid][PlayerCarID] = carid;
		CarDoors(carid, PI[playerid][cLock]);
		Fuel[carid] = PI[playerid][cFuel];
		SetVehicleHealth(carid, 1000);
		Engine[carid] = Lights[PI[playerid][PlayerCarID]] = false;
		//IsLocked[carid] = (!PI[playerid][cLock]) ? (false) : (true);
		IsLocked[PI[playerid][PlayerCarID]] = true;
		for(new i; i < 14; i++)
		{
			if(PI[playerid][cVehcoms][i]) AddVehicleComponent(PI[playerid][PlayerCarID], PI[playerid][cVehcoms][i]);
		}
		if(PI[playerid][cPaintjob] != 3) ChangeVehiclePaintjob(PI[playerid][PlayerCarID], PI[playerid][cPaintjob]);
		new labeltext[60];
		format(labeltext, sizeof(labeltext), "%s", PI[playerid][pNumberVehicle]);
		VehicleLabel[carid] = Create3DTextLabel(labeltext, 0xFFFFFFFF, 0, 0, 0, 10.0, 0);
		Attach3DTextLabelToVehicle(VehicleLabel[carid], carid, 0, 0, 0.2);
		SetVehicleNumberPlate(carid, PI[playerid][pNumberVehicle]);
	}
	/*else if(GetPlayerPorchHouse(playerid) != 0)
	{
		new h = GetPlayerPorchHouse(playerid);
		new porch = floatround(h / 9, floatround_floor) + 1;
		new carid;
		if(PI[playerid][cModel] == 0 || PI[playerid][cModel] < 400 || PI[playerid][cModel] > 611) return 1;
		if(PI[playerid][cPaintjob] > 3 || PI[playerid][cPaintjob] < 0) PI[playerid][cPaintjob] = 3;
		if(PI[playerid][PlayerCarID] != INVALID_VEHICLE_ID)
		{
			DestroyVehicle(PI[playerid][PlayerCarID]);
			PI[playerid][PlayerCarID] = INVALID_VEHICLE_ID;
		}
		carid = CreateVehicle(PI[playerid][cModel], PorchInfo[porch][pCarX], PorchInfo[porch][pCarY], PorchInfo[porch][pCarZ], PorchInfo[porch][pCarA], PI[playerid][cColor][0], PI[playerid][cColor][1], 90000);
		SetVehicleVirtualWorld(PI[playerid][PlayerCarID], 0);
		LinkVehicleToInterior(PI[playerid][PlayerCarID], 0);
		PI[playerid][PlayerCarID] = carid;
		CarDoors(carid, PI[playerid][cLock]);
		Fuel[carid] = PI[playerid][cFuel];
		SetVehicleHealth(carid, 1000);
		Engine[carid] = Lights[PI[playerid][PlayerCarID]] = false;
		//IsLocked[carid] = (!PI[playerid][cLock]) ? (false) : (true);
		IsLocked[PI[playerid][PlayerCarID]] = true;
		for(new i; i < 14; i++)
		{
			if(PI[playerid][cVehcoms][i]) AddVehicleComponent(PI[playerid][PlayerCarID], PI[playerid][cVehcoms][i]);
		}
		if(PI[playerid][cPaintjob] != 3) ChangeVehiclePaintjob(PI[playerid][PlayerCarID], PI[playerid][cPaintjob]);
		new labeltext[60];
		format(labeltext, sizeof(labeltext), "%s", PI[playerid][pNumberVehicle]);
		VehicleLabel[carid] = Create3DTextLabel(labeltext, 0xFFFFFFFF, 0, 0, 0, 10.0, 0);
		Attach3DTextLabelToVehicle(VehicleLabel[carid], carid, 0, 0, 0.2);
		SetVehicleNumberPlate(carid, PI[playerid][pNumberVehicle]);
	}*/
	return 1;
}
stock SendVipMessage(color, str[])
{
	foreach(new i: Player)
	{
		if(!PlayerLogged[i]) continue;
		if(PI[i][pVip] > 0) SendClientMessage(i, color, str);
	}
	return 1;
}
stock SendAdminMessage(color, str[])
{
	foreach(new i: Player)
	{
		if(!PlayerLogged[i]) continue;
		if(PI[i][pAdmin] > ADM_NONE) SendClientMessage(i, color, str);
	}
	return 1;
}

stock SendYouTuberMessage(color, str[], alogs = -1)
{
	foreach(new playerid: YouTubers)
	{
		if(alogs == -1)
		{
			if(PlayerLogged[playerid]) if(PI[playerid][pYouTuber] > 0) SendClientMessage(playerid, color, str);
		}
		else
		{
			if(AdminInfo[playerid][admAlog] == 1)
			{
				if(PI[playerid][pYouTuber] > 0) SendClientMessage(playerid, color, str);
			}
			else continue;
		}
	}
	return 1;
}
/*stock family_message(family, color, string[])
{
	foreach(new i : Player)
	{
		if(IsPlayerConnected(i))
		{
			if(PI[i][pFamily] == family)
			{
				SendClientMessage(i, color, string);
			}
		}
	}
}*/
/*stock SendYouTuberMessage(color, str[])
{
	foreach(new i: Player)
	{
		if(!PlayerLogged[i]) continue;
		if(PI[i][pYouTube] == 1) SendClientMessage(i, color, str);
	}
	return 1;
}
stock SendSupportMessage(color, str[])
{
	foreach(new i: Player)
	{
		if(!PlayerLogged[i]) continue;
		if(PI[i][pSupports] == 1) SendClientMessage(i, color, str);
	}
	return 1;
}*/
stock SendAdminMessageEx(color, str[], admin_level)
{
	foreach(new i: Player)
	{
		if(!PlayerLogged[i]) continue;
		if(PI[i][pAdmin] >= admin_level) SendClientMessage(i, color, str);
	}
	return 1;
}
stock SendAdminMessageToAll(color, const message[])
{
	foreach(new i: Player)
	{
		if(!PlayerLogged[i]) continue;
		SendClientMessage(i, color, message);
	}
}
stock SendDMes(color, str[])
{
	foreach(new i: Player)
	{
		if(!PlayerLogged[i]) continue;
		if(PI[i][pMember] == TEAM_VDV || IsAMedic(i) || IsAMayor(i) || IsACop(i) || IsANews(i)) SendClientMessage(i, color, str);
	}
	return 1;
}

stock SendNMes(news, color, str[])
{
	foreach(new i: Player)
	{
		if(!PlayerLogged[i]) continue;
		if(PI[i][pNews] == news) SendClientMessage(i, color, str);
	}
	return 1;
}

stock ProxDetectorNew(playerid, Float:Radi = 10.0, color, text[])
{
	new Float:posx, Float:posy, Float:posz;
	GetPlayerPos(playerid, posx, posy, posz);
	foreach(new i: Player)
	{
		if(GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid)
 		&& GetPlayerInterior(playerid) == GetPlayerInterior(i)
 		&& IsPlayerInRangeOfPoint(i, Radi, posx, posy, posz)) SendClientMessage(i, color, text);
	}
	return 1;
}

stock ProxDetector(Float:radi, playerid, str[],col1,col2,col3,col4,col5)
{
	new Float:posx, Float:posy, Float:posz, Float:oldposx, Float:oldposy,
	Float:oldposz, Float:tempposx, Float:tempposy, Float:tempposz;
	GetPlayerPos(playerid, oldposx, oldposy, oldposz);
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		GetPlayerPos(i, posx, posy, posz);
		tempposx = (oldposx -posx);
		tempposy = (oldposy -posy);
		tempposz = (oldposz -posz);
		if (((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16))) SendClientMessage(i, col1, str);
		else if (((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8))) SendClientMessage(i, col2, str);
		else if (((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4))) SendClientMessage(i, col3, str);
		else if (((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2))) SendClientMessage(i, col4, str);
		else if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi))) SendClientMessage(i, col5, str);
	}
	return 1;
}

stock IsPlayerInRangeOfPlayer(Float:radi, playerid, targetid)
{
	if(IsPlayerConnected(playerid) && IsPlayerConnected(targetid) && !IsPlayerNPC(playerid) && !IsPlayerNPC(targetid))
	{
		new Float:posx, Float:posy, Float:posz;
		GetPlayerPos(targetid, posx, posy, posz);
		if(IsPlayerInRangeOfPoint(playerid, radi, posx, posy, posz)) return 1;
	}
	return 0;
}

stock IsVehicleInRangeOfPoint(vehicleid, Float:distance, Float:x, Float:y, Float:z)
{
	new Float:oldposx, Float:oldposy, Float:oldposz;
	new Float:tempposx, Float:tempposy, Float:tempposz;
	GetVehiclePos(vehicleid, oldposx, oldposy, oldposz);
	tempposx = (oldposx - x);
	tempposy = (oldposy - y);
	tempposz = (oldposz - z);
	if (((tempposx < distance) && (tempposx > -distance)) && ((tempposy < distance) && (tempposy > -distance)) && ((tempposz < distance) && (tempposz > -distance)))return true;
	return false;
}

stock SpeedVehicle(playerid)
{
	new Float:ST[4];
	if(IsPlayerInAnyVehicle(playerid)) GetVehicleVelocity(GetPlayerVehicleID(playerid),ST[0],ST[1],ST[2]);
	else GetPlayerVelocity(playerid,ST[0],ST[1],ST[2]);
	ST[3] = floatsqroot(floatpower(floatabs(ST[0]), 2.0) + floatpower(floatabs(ST[1]), 2.0) + floatpower(floatabs(ST[2]), 2.0)) * 213.3;
	return floatround(ST[3]);
}


stock RemoveBuild(playerid)
{
    if(!GetPVarInt(playerid, "BuildingsRemoved"))
	{

		SetPVarInt(playerid, "BuildingsRemoved", true);
	}
	return 1;
}
//==============================================================================
forward check_banlist(playerid);
public check_banlist(playerid)
{
	new unbandate, vas[32], bool:ban, rows, fields, dialog[500], str[150];
    cache_get_data(rows, fields);
	if(rows)
	{
	    cache_get_field_content(0, "unbandate", vas); unbandate = strval(vas);
		if(unbandate - gettime() > 0) ban = true;
	}
	if(ban == true)
	{
		new data[15], whobanned[MAX_PLAYER_NAME], reason[32], timeban;
		cache_get_field_content(0, "bandate", data);
		cache_get_field_content(0, "unbandate", vas); unbandate = strval(vas);
		cache_get_field_content(0, "whobanned", whobanned);
		cache_get_field_content(0, "reason", reason);
		timeban = cache_get_field_content_int(0, "time");
       	
       	strcat(dialog, "{F04245}");
		format(str, sizeof(str), "{ffffff}Этот аккаунт заблокирован на {FF6347}%d дней\n", timeban);
		strcat(dialog, str);
		format(str, sizeof(str), "{ffffff}Ник администратора: %s\n", whobanned);
		strcat(dialog, str);
		format(str, sizeof(str), "{ffffff}Причина блокировки: %s\n", reason);
	 	strcat(dialog, str);
  		format(str, sizeof(str), "{ffffff}Дата и время: {FFCC00}%s\n\n", data);
		strcat(dialog, str);
		format(str, sizeof(str), "{ffffff}Введите {FFCC00}/q(/quit) {ffffff}для выхода из игры", data);
		strcat(dialog, str);
		
       	
		ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{FFCC00}"SERVER_NAME"", dialog, "Закрыть", "");
		SKick(playerid, 28183);
	}
	return 1;
}
//==============================================================================
stock SetPlayerDataToDefault(playerid)
{
    SetPVarInt(playerid, "USEDIALOGID", -1);

    PI[playerid][pCity]                         	=
    //iPlayerAmmo[playerid]                           =
	//iNewPlayerAmmo[playerid]						=
	//Shot[playerid]                                  =
    PI[playerid][pBusTime]                          =
    PI[playerid][pWorkSalary]                       =
	//PI[playerid][pFamilySozd]                       =
	//PI[playerid][pFamilyZam]                        =
    //PI[playerid][pAFK]                              =
    AdminInfo[playerid][admAlog]                    =
    AdminInfo[playerid][admGoto]                    =
    AdminInfo[playerid][admGethere]                 =
    AdminInfo[playerid][admSpectate]                =
    AdminInfo[playerid][admSmsEars]                 =
    Ujahhs[playerid] 								=
    Medicines[playerid]								=
    UnMaskReset[playerid] 							=
    UseWork[playerid] 								=
	pickupentered[playerid] 						=
	PI[playerid][pSportExp] 						=
	PI[playerid][pMask] 							=
	PI[playerid][pBed] 								=
	PI[playerid][pTruckSkill] 						=
	PI[playerid][pTruckLevel] 						=
	PI[playerid][pZakon] 							=
	PI[playerid][pCheckCode] 						=
	PI[playerid][pWatch] 							=
	PI[playerid][pCiggare] 							=
	PI[playerid][pSprunk] 							=
	PI[playerid][pCHIPS] 							=
	PI[playerid][pRepairCar] 						=
	ChosenSkin[playerid] 							=
	SelectCharPlace[playerid] 						=
	PI[playerid][pPhoneBalance] 					=
	PlayerLogTries[playerid] 						=
	PlayerStats[playerid] 							=
	ClothesRound[playerid]							=
	HousePrice[playerid] 							=
	InShop[playerid] 								=
	InShopSkin[playerid] 							=
	DrivingTestTime[playerid]						=
	FlyTestTime[playerid]							=
	WaterTestTime[playerid]							=
	Oldskin2[playerid] 								=
	PI[playerid][pAdmin] 							=
	PI[playerid][pYouTuber] 						=
	PI[playerid][pLeader] 							=
	PI[playerid][pTempLeader]                       =
	PI[playerid][pMember] 							=
	PI[playerid][pRank] 							=
	PI[playerid][pModel] 							=
	PI[playerid][pMemberSkin] 						=
	//PI[playerid][pFamily] 							=
	PI[playerid][pSex] 								=
	PI[playerid][pID] 								=
	PI[playerid][pWarn] 							=
	PI[playerid][pCash] 							=
	PI[playerid][pExp] 								=
    PI[playerid][pMuted] 							=
	PI[playerid][pAge] 								=
	PI[playerid][pBank] 							=
	PI[playerid][pNews] 							=
	PI[playerid][pJail] 							=
	PI[playerid][pJailTime] 						=
	PI[playerid][pWanted] 							=
	PI[playerid][pWantedTime] 						=
	PI[playerid][pDrugs] 							=
	PI[playerid][pPatron] 							=
	PI[playerid][pGunAmount] 						=
	PI[playerid][pCarA] 				     		=
	PI[playerid][pCarB] 				     		=
	PI[playerid][pCarC] 				     		=
	PI[playerid][pCarD] 				     		=
	PI[playerid][pCheckTime] 						=
	PI[playerid][pPick] 							=
	PI[playerid][pJob] 								=
	PI[playerid][pMarried] 							=
	PI[playerid][pPayCheck] 						=
	PI[playerid][pCharity] 							=
	PI[playerid][pVip] 								=
	PI[playerid][pVipTime]							=
	PI[playerid][pTime] 							=
	PI[playerid][pFightStyle] 						=
	PI[playerid][pCredits] 							=
	PI[playerid][pTotalCredits] 					=
	PI[playerid][pSkin][0] 							=
	PI[playerid][pSkin][1] 							=
	PI[playerid][pSkin][2] 							=
	PI[playerid][pZakon] 							=
	PI[playerid][pCheckCode] 						=
	PI[playerid][pVehicleKey]                       =
	PI[playerid][pMailConfirmed]                    =
	PI[playerid][pPhoneNumber]                      =
	PI[playerid][pVoennik]                          =
	PassInfo[playerid][psDateBirth][0] 				=
 	PassInfo[playerid][psDateBirth][1] 				=
 	PassInfo[playerid][psDateBirth][2] 				=
 	PassInfo[playerid][psDate][0] 					=
 	PassInfo[playerid][psDate][1] 					=
 	PassInfo[playerid][psDate][2] 					=
 	PassInfo[playerid][psCity] 						=
 	PassRegSex[playerid] 							=
 	PI[playerid][pRegVehicle] 						=
 	PI[playerid][pSpawnChange]						=
 	PI[playerid][ACCheck] 							=
 	Predlog[playerid]								=
    ZapretDice[playerid] 							=
    KostiMoney[playerid]							= 0;
    //player_afk_time[playerid] 						= 0;
    PI[playerid][P_ENTRANCE] 						=
	PI[playerid][P_ROOM] 							= -1;

    PI[playerid][pInputCode]						=
    HouseOffer[playerid] 							=
    Mobile[playerid] 								=
	CellTime[playerid] 								=
	PlayerStats[playerid] 							=
	PassInfo[playerid][mcState] 					= -1;
	
	/*PI[playerid][pFamily] 							=
	PI[playerid][pFamilySozd]                   	=
	PI[playerid][pFamilyZam]                    	=*/

    //activemusic[playerid]                           =
    //PlayerMusic[playerid]                           =
    StartGMTest[playerid]                           =
    PlayerDied[playerid]                    		=
    CheckOutMoney[playerid]							=
    UseGPS[playerid] 								=
	FreezePlayer[playerid]							=
	PlayerTied[playerid] 							=
	PlayerLogged[playerid] 							=
	AdminLogged[playerid] 							=
	TaxiON[playerid]                                =
	MedicON[playerid]                               =
	MechanicON[playerid]                            =
	PoliceON[playerid]                              =
	Ether[playerid] 								=
	EtherCall[0] 									=
	EtherCall[1] 									=
	EtherSms[0] 									=
	EtherSms[1] 									=
	EtherLive[playerid] 							=
	EtherCalled[playerid] 							= false;

	times[playerid] 								=
	Phone[playerid] 								= true;

	NameStats[playerid]                             =
	pCuff[playerid][pCuffer] 						=
	pCuff[playerid][pCuffee] 						=
    PI[playerid][Spectating][0] 					=
	PI[playerid][Spectating][1] 					=
	KostiName[playerid] 							= INVALID_PLAYER_ID;

	VehTest[playerid]                               =
	PI[playerid][TaxiCarID]                         =
	PI[playerid][BusCarID]                          =
	PI[playerid][MechanicCarID]                     =
	PI[playerid][GruzCarID] 						=
	PI[playerid][TruckerCarID]                      =
	PI[playerid][SalonCarID]                        =
	PI[playerid][PlayerCarID][0]                    =
	PI[playerid][PlayerCarID][1]                    =
	EnterVehicle[playerid] 							= INVALID_VEHICLE_ID;

	PI[playerid][pColor]							= NONE_COLOR;
	PI[playerid][pSettings]                    		= 65535;
	PlayerArmour[playerid] 							= 0.0;
	PlayerLastTick[playerid] 						= GetTickCount();
	PI[playerid][pLevel] 							= 1;
	PI[playerid][pHealthS] 							= 100.0;
	PI[playerid][pHunger] 							= 50;

	new i;
	for(i = 0; i < 4; i++)
	{
    	PI[playerid][pLic][i] = 0;
 	    PI[playerid][pImprove][i] = 0;
 	    PI[playerid][pText][i] = 0;
	}
	for(i = 0; i < 8; i++)
	{
	    PI[playerid][pGunSkill][i] = 0;
	    PhoneNumbers[playerid][i] = 0;
	}
	for(i = 0; i < 12; i++)
 	{
        PI[playerid][pGun][i] = 0;
		PI[playerid][pAmmo][i] = 0;
	}
	/* Транспорт */
	for(i = 0; i < 13; i++)
	{
		PI[playerid][cVehcoms][i] = 0;
	}
	PI[playerid][cModel] 							=
	PI[playerid][cFuel] 							=
	PI[playerid][cColor][0] 						=
	PI[playerid][cColor][1] 						=
	PI[playerid][cLock] 							=
	PI[playerid][cCost] 							=
	PI[playerid][cPaintjob] 						= 0;
	/* Конец */

	strmid(PlayerName[playerid], "None", 0, strlen("None"), MAX_PLAYER_NAME);
	strmid(PI[playerid][pPassword], "", 0, strlen(PI[playerid][pPassword]), 32);
	strmid(PI[playerid][pMail], "", 0, strlen(PI[playerid][pMail]), 64);

	SetSpawnInfoEx(playerid, 0, 0.0, 0.0, 0.0, 0.0);
	ResetPlayerWeaponsAC(playerid);
	return 1;
}

stock SetHealth(playerid, Float: Heal)
{
	PlayerUseHeal[playerid] = 1;
	PI[playerid][pHeal] = Heal;
	SetPlayerHealth(playerid, Heal);
	PlayerUseHeal[playerid] = 0;
	return 1;
}

stock SetArmour(playerid, Float: Arm)
{
	PlayerArmour[playerid] = Arm;
	SetPlayerArmour(playerid, Arm);
	return 1;
}

stock CarDoors(vehicleid, status)
{
	if(vehicleid == INVALID_VEHICLE_ID) return 0;
	new eengine, elights, ealarm, edoors, ebonnet, eboot, eobjective;
	GetVehicleParamsEx(vehicleid, eengine, elights, ealarm, edoors, ebonnet, eboot, eobjective);
	SetVehicleParamsEx(vehicleid, eengine, elights, ealarm, status, ebonnet, eboot, eobjective);
	if(vehicleid < lastveh) SetVehicleParamsEx(vehicleid, eengine, elights, ealarm, false, ebonnet, eboot, eobjective);
	return 1;
}

stock CarDoorsEx(vehicleid, status)
{
	if(vehicleid == INVALID_VEHICLE_ID) return 0;
	new eengine, elights, ealarm, edoors, ebonnet, eboot, eobjective;
	GetVehicleParamsEx(vehicleid, eengine, elights, ealarm, edoors, ebonnet, eboot, eobjective);
	SetVehicleParamsEx(vehicleid, eengine, elights, ealarm, status, ebonnet, eboot, eobjective);
	return 1;
}
stock GetPlayerHouse(playerid)
{
	new house = 0;
	for(new i = 1; i <= TOTALHOUSE;i++)
	{
		if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), true))
		{
			SetPVarInt(playerid, "PlayerHouse", i);
			house ++;
			break;
		}
	}
	return house;
}

/*stock GetPlayerPorchHouse(playerid)
{
	new house = 0;
	for(new i = 1; i <= TOTALPORCHHOUSE;i++)
	{
		if(PorchHouseInfo[i][hOwnerID] == PI[playerid][pID])
		{
	 		SetPVarInt(playerid, "PlayerPorchHouse", i);
			house = i;
			break;
		}
	}
	return house;
}*/
stock GetPlayerBizz(playerid)
{
	new bizz = 0;
	for(new i = 1; i <= TOTALBIZZ;i++)
	{
		if(!strcmp(BizzInfo[i][bOwner], GetName(playerid), true)) bizz++, SetPVarInt(playerid, "PlayerBizz", i);
	}
	return bizz;
}

stock IsTheMember(member)
{
	switch(member)
	{
		case TEAM_AO,TEAM_PPS,TEAM_DPS,TEAM_FSIN,TEAM_MZY,TEAM_VDV,TEAM_SMI,TEAM_MZA: return 1;
		default: return 0;
	}
	return 0;
}
stock IsThePayDayMembers(member)
{
	switch(member)
	{
		case TEAM_AO,TEAM_PPS,TEAM_DPS,TEAM_FSIN,TEAM_MZY,TEAM_VDV,TEAM_SPARTAK,TEAM_CSKA,TEAM_SMI,TEAM_MZA: return 1;
		default: return 0;
	}
	return 0;
}
stock IsAbleToGosNewsRank(playerid)
{
	switch(PI[playerid][pMember])
	{
		case TEAM_AO: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_PPS,TEAM_DPS: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_FSIN: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_VDV: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_MZY: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_SMI,TEAM_MZA: if(PI[playerid][pRank] >= 9) return 1;
		default: return 0;
	}
	return 0;
}
stock IsAbleToInvite(playerid)
{
	switch(PI[playerid][pMember])
	{
	    case TEAM_AO: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_PPS,TEAM_DPS: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_FSIN: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_VDV: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_MZY: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_SPARTAK,TEAM_CSKA, TEAM_DINAMO, TEAM_ZENIT: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_SMI,TEAM_MZA: if(PI[playerid][pRank] >= 9) return 1;
	}
	return 0;
}
stock IsAbleToChangeSkin(playerid)
{
	switch(PI[playerid][pMember])
	{
	    case TEAM_AO: if(PI[playerid][pRank] >= 8) return 1;
		case TEAM_PPS,TEAM_DPS: if(PI[playerid][pRank] >= 8) return 1;
		case TEAM_FSIN: if(PI[playerid][pRank] >= 8) return 1;
		case TEAM_VDV: if(PI[playerid][pRank] >= 8) return 1;
		case TEAM_MZY: if(PI[playerid][pRank] >= 8) return 1;
		case TEAM_SPARTAK,TEAM_CSKA, TEAM_DINAMO, TEAM_ZENIT: if(PI[playerid][pRank] >= 8) return 1;
		case TEAM_SMI,TEAM_MZA: if(PI[playerid][pRank] >= 8) return 1;
	}
	return 0;
}
stock IsAbleToUninvite(playerid)
{
    switch(PI[playerid][pMember])
	{
	    case TEAM_AO: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_PPS,TEAM_DPS: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_FSIN: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_VDV: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_MZY: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_SPARTAK,TEAM_CSKA,TEAM_DINAMO, TEAM_ZENIT: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_SMI,TEAM_MZA: if(PI[playerid][pRank] >= 9) return 1;
	}
	return 0;
}
stock IsAbleToGiverank(playerid)
{
    switch(PI[playerid][pMember])
	{
	    case TEAM_AO: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_PPS,TEAM_DPS: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_FSIN: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_VDV: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_MZY: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_SPARTAK,TEAM_CSKA,TEAM_DINAMO,TEAM_ZENIT: if(PI[playerid][pRank] >= 9) return 1;
		case TEAM_SMI,TEAM_MZA: if(PI[playerid][pRank] >= 9) return 1;
	}
	return 0;
}
stock SelectCar(playerid)
{
	new string[128];
	new Keys,ud,lr;
	GetPlayerKeys(playerid,Keys,ud,lr);
	if((GetTickCount() - PlayerLastTick[playerid]) < 500) return 1;
	if(lr < 0)
	{
		pPressed[playerid]++;
		if(PI[playerid][SalonCarID] != INVALID_VEHICLE_ID) DestroyVehicle(PI[playerid][SalonCarID]);
		if(InShop[playerid] == 1)
		{
			if(pPressed[playerid]>sizeof(carsC))pPressed[playerid] = 0;
			PI[playerid][SalonCarID] = CreateVehicle(carsC[pPressed[playerid]][0],2641.2471,-1920.3633,2325.8000,270.0000,colors[playerid][0]=random(10),colors[playerid][1]=random(10),10000);
			format(string,sizeof(string),"~w~%s",VehicleNames[carsC[pPressed[playerid]][0]-400]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][6],string);
			format(string,64,"%d",carsC[pPressed[playerid]][1]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][11],string);
		}
		if(InShop[playerid] == 2)
		{
			if(pPressed[playerid]>sizeof(carsB))pPressed[playerid] = 0;
			PI[playerid][SalonCarID] = CreateVehicle(carsC[pPressed[playerid]][0],2641.2471,-1920.3633,2325.8000,270.0000,colors[playerid][0]=random(10),colors[playerid][1]=random(10),10000);
			format(string,sizeof(string),"~w~%s",VehicleNames[carsB[pPressed[playerid]][0]-400]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][6],string);
			format(string,sizeof(string),"~w~%d",carsB[pPressed[playerid]][1]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][11],string);
		}
		if(InShop[playerid] == 3)
		{
			if(pPressed[playerid]>sizeof(carsA))pPressed[playerid] = 0;
			PI[playerid][SalonCarID] = CreateVehicle(carsC[pPressed[playerid]][0],2641.2471,-1920.3633,2325.8000,270.0000,colors[playerid][0]=random(10),colors[playerid][1]=random(10),10000);
			format(string,sizeof(string),"~w~%s",VehicleNames[carsA[pPressed[playerid]][0]-400]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][6],string);
			format(string,sizeof(string),"~w~%d",carsA[pPressed[playerid]][1]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][11],string);
		}
		if(InShop[playerid] == 4)
		{
			if(pPressed[playerid]>sizeof(carsBike))pPressed[playerid] = 0;
			PI[playerid][SalonCarID] = CreateVehicle(carsC[pPressed[playerid]][0],2641.2471,-1920.3633,2325.8000,270.0000,colors[playerid][0]=random(10),colors[playerid][1]=random(10),10000);
			format(string,sizeof(string),"~w~%s",VehicleNames[carsBike[pPressed[playerid]][0]-400]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][6],string);
			format(string,sizeof(string),"~w~%d",carsBike[pPressed[playerid]][1]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][11],string);
		}
		PlayerLastTick[playerid] = GetTickCount();
		LinkVehicleToInterior(PI[playerid][SalonCarID],3);
		SetVehicleVirtualWorld(PI[playerid][SalonCarID],playerid);
		PutPlayerInVehicle(playerid,PI[playerid][SalonCarID],0);
		SetPlayerCameraPos(playerid, 2650.4348, -1924.8947, 2326.8867);
		SetPlayerCameraLookAt(playerid, 2649.5349, -1924.4620, 2326.7051);
	}
	if(lr > 0)
	{
		pPressed[playerid]--;
		if(PI[playerid][SalonCarID] != INVALID_VEHICLE_ID) DestroyVehicle(PI[playerid][SalonCarID]);
		if(InShop[playerid] == 1)
		{
			if(pPressed[playerid] < 0) pPressed[playerid] = sizeof(carsC)-1;
			PI[playerid][SalonCarID] = CreateVehicle(carsC[pPressed[playerid]][0],2641.2471,-1920.3633,2325.8000,270.0000,colors[playerid][0]=random(10),colors[playerid][1]=random(10),10000);
			format(string,sizeof(string),"~w~%s",VehicleNames[carsC[pPressed[playerid]][0]-400]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][6],string);
			format(string,sizeof(string),"~w~%d",carsC[pPressed[playerid]][1]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][11],string);
		}
		if(InShop[playerid] == 2)
		{
			if(pPressed[playerid] < 0) pPressed[playerid] = sizeof(carsB)-1;
			PI[playerid][SalonCarID] = CreateVehicle(carsC[pPressed[playerid]][0],2641.2471,-1920.3633,2325.8000,270.0000,colors[playerid][0]=random(10),colors[playerid][1]=random(10),10000);
			format(string,sizeof(string),"~w~%s",VehicleNames[carsB[pPressed[playerid]][0]-400]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][6],string);
			format(string,sizeof(string),"~w~%i",carsB[pPressed[playerid]][1]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][11],string);
		}
		if(InShop[playerid] == 3)
		{
			if(pPressed[playerid] < 0) pPressed[playerid] = sizeof(carsA)-1;
			PI[playerid][SalonCarID] = CreateVehicle(carsA[pPressed[playerid]][0],2641.2471,-1920.3633,2325.8000,270.0000,colors[playerid][0]=random(10),colors[playerid][1]=random(10),10000);
			format(string,sizeof(string),"~w~%s",VehicleNames[carsA[pPressed[playerid]][0]-400]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][6],string);
			format(string,sizeof(string),"~w~%d",carsA[pPressed[playerid]][1]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][11],string);
		}
		if(InShop[playerid] == 4)
		{
			if(pPressed[playerid] < 0) pPressed[playerid] = sizeof(carsBike)-1;
			PI[playerid][SalonCarID] = CreateVehicle(carsC[pPressed[playerid]][0],2641.2471,-1920.3633,2325.8000,270.0000,colors[playerid][0]=random(10),colors[playerid][1]=random(10),10000);
			format(string,sizeof(string),"~w~%s",VehicleNames[carsBike[pPressed[playerid]][0]-400]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][6],string);
			format(string,sizeof(string),"~w~%d",carsBike[pPressed[playerid]][1]);
			PlayerTextDrawSetString(playerid,choicecars[playerid][11],string);
		}
		/*PlayerLastTick[playerid] = GetTickCount();
		LinkVehicleToInterior(PI[playerid][SalonCarID],0);
		PutPlayerInVehicle(playerid,PI[playerid][SalonCarID],0);
		SetPlayerCameraPos(playerid, 2650.4348, -1924.8947, 2326.8867);
		SetPlayerCameraLookAt(playerid, 2649.5349, -1924.4620, 2326.7051);*/
		PlayerLastTick[playerid] = GetTickCount();
		LinkVehicleToInterior(PI[playerid][SalonCarID],3);
		SetVehicleVirtualWorld(PI[playerid][SalonCarID],playerid);
		PutPlayerInVehicle(playerid,PI[playerid][SalonCarID],0);
		SetPlayerCameraPos(playerid, 2650.4348, -1924.8947, 2326.8867);
		SetPlayerCameraLookAt(playerid, 2649.5349, -1924.4620, 2326.7051);
	}
	return 1;
}
stock Convert(seconds, stringTo[], size = sizeof(stringTo))
{
	stringTo[0] = 0x0;
	new result[4];
	result[0] = floatround(seconds / (3600 * 24));
	result[1] = floatround(seconds / 3600);
	result[2] = floatround((seconds / 60) - (result[1] * 60));
	result[3] = floatround(seconds - ((result[1] * 3600) + (result[2] * 60)));
	switch(result[0])
	{
	case 0:
		{
			switch(result[1])
			{
			case 0: format(stringTo,size,"%02d:%02d",result[2],result[3]);
			default: format(stringTo,size,"%d:%02d:%02d",result[1],result[2],result[3]);
			}
		}
	}
	return 1;
}
stock TimeConverter(seconds)
{
	new strings[64];
	new minutes = floatround(seconds/60);
	seconds -= minutes*60;
	format(strings, 64, "%02d:%02d", minutes, seconds);
	return strings;
}
stock GetXYInBackOfPlayer(const playerid, &Float:x, &Float:y, const Float:distance)
{
	new Float:a; GetPlayerPos(playerid, x, y, a); GetPlayerFacingAngle(playerid, a);
	if(IsPlayerInAnyVehicle(playerid))
	{
		new vid = GetPlayerVehicleID(playerid);
		if(vid > 0 && vid <= MAX_VEHICLES) GetVehicleZAngle(vid, a);
	}
	x -= (distance * floatsin(-a, degrees)); y -= (distance * floatcos(-a, degrees));
}
stock IsPlayerInInvalidNosVehicle(playerid)
{
    #define MAX_INVALID_NOS_VEHICLES 52
    static const InvalidNosVehicles[MAX_INVALID_NOS_VEHICLES] =
    {
		581,523,462,521,463,522,461,448,468,586,417,425,469,487,512,520,563,593,
		509,481,510,472,473,493,520,595,484,430,453,432,476,497,513,533,577,
		452,446,447,454,590,569,537,538,570,449,519,460,488,511,519,548,592
	};
	if(IsPlayerInAnyVehicle(playerid))
	{
		for(new i = 0; i < MAX_INVALID_NOS_VEHICLES; i++)
        {
			if(GetVehicleModel(GetPlayerVehicleID(playerid)) == InvalidNosVehicles[i]) return 1;
		}
	}
	return 0;
}
stock IsComponentidCompatible(modelid, componentid)
{
    if(componentid == 1025 || componentid == 1073 || componentid == 1074 || componentid == 1075 || componentid == 1076 ||
         componentid == 1077 || componentid == 1078 || componentid == 1079 || componentid == 1080 || componentid == 1081 ||
         componentid == 1082 || componentid == 1083 || componentid == 1084 || componentid == 1085 || componentid == 1096 ||
         componentid == 1097 || componentid == 1098 || componentid == 1087 || componentid == 1086)
         return 1;

    switch (modelid)
    {
        case 400: return (componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 401: return (componentid == 1005 || componentid == 1004 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 114 || componentid == 1020 || componentid == 1019 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1003 || componentid == 1017 || componentid == 1007);
        case 402: return (componentid == 1009 || componentid == 1009 || componentid == 1010);
        case 404: return (componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1002 || componentid == 1016 || componentid == 1000 || componentid == 1017 || componentid == 1007);
        case 405: return (componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1014 || componentid == 1023 || componentid == 1000);
        case 409: return (componentid == 1009);
        case 410: return (componentid == 1019 || componentid == 1021 || componentid == 1020 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007);
        case 411: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 412: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 415: return (componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007);
        case 418: return (componentid == 1020 || componentid == 1021 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1002 || componentid == 1016);
        case 419: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 420: return (componentid == 1005 || componentid == 1004 || componentid == 1021 || componentid == 1019 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1003);
        case 421: return (componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1014 || componentid == 1023 || componentid == 1016 || componentid == 1000);
        case 422: return (componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1017 || componentid == 1007);
        case 426: return (componentid == 1005 || componentid == 1004 || componentid == 1021 || componentid == 1019 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1003);
        case 429: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 436: return (componentid == 1020 || componentid == 1021 || componentid == 1022 || componentid == 1019 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1003 || componentid == 1017 || componentid == 1007);
        case 438: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 439: return (componentid == 1003 || componentid == 1023 || componentid == 1001 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1017 || componentid == 1007 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1013);
        case 442: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 445: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 451: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 458: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 466: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 467: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 474: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 475: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 477: return (componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1017 || componentid == 1007);
        case 478: return (componentid == 1005 || componentid == 1004 || componentid == 1012 || componentid == 1020 || componentid == 1021 || componentid == 1022 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 479: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 480: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 489: return (componentid == 1005 || componentid == 1004 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1002 || componentid == 1016 || componentid == 1000);
        case 491: return (componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1014 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007);
        case 492: return (componentid == 1005 || componentid == 1004 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1016 || componentid == 1000);
        case 496: return (componentid == 1006 || componentid == 1017 || componentid == 1007 || componentid == 1011 || componentid == 1019 || componentid == 1023 || componentid == 1001 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1003 || componentid == 1002 || componentid == 1142 || componentid == 1143 || componentid == 1020);
        case 500: return (componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 506: return (componentid == 1009);
        case 507: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 516: return (componentid == 1004 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1002 || componentid == 1015 || componentid == 1016 || componentid == 1000 || componentid == 1017 || componentid == 1007);
        case 517: return (componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1002 || componentid == 1023 || componentid == 1016 || componentid == 1003 || componentid == 1017 || componentid == 1007);
        case 518: return (componentid == 1005 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1018 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007);
        case 526: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 527: return (componentid == 1021 || componentid == 1020 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1014 || componentid == 1015 || componentid == 1017 || componentid == 1007);
        case 529: return (componentid == 1012 || componentid == 1011 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007);
        case 533: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 534: return (componentid == 1126 || componentid == 1127 || componentid == 1179 || componentid == 1185 || componentid == 1100 || componentid == 1123 || componentid == 1125 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1180 || componentid == 1178 || componentid == 1101 || componentid == 1122 || componentid == 1124 || componentid == 1106);
        case 535: return (componentid == 1109 || componentid == 1110 || componentid == 1113 || componentid == 1114 || componentid == 1115 || componentid == 1116 || componentid == 1117 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1120 || componentid == 1118 || componentid == 1121 || componentid == 1119);
        case 536: return (componentid == 1104 || componentid == 1105 || componentid == 1182 || componentid == 1181 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1184 || componentid == 1183 || componentid == 1128 || componentid == 1103 || componentid == 1107 || componentid == 1108);
        case 540: return (componentid == 1004 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1017 || componentid == 1007);
        case 541: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 542: return (componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1014 || componentid == 1015);
        case 545: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 546: return (componentid == 1004 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1019 || componentid == 1018 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1002 || componentid == 1001 || componentid == 1023 || componentid == 1017 || componentid == 1007);
        case 547: return (componentid == 1142 || componentid == 1143 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1016 || componentid == 1003 || componentid == 1000);
        case 549: return (componentid == 1012 || componentid == 1011 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007);
        case 550: return (componentid == 1005 || componentid == 1004 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1003);
        case 551: return (componentid == 1005 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1002 || componentid == 1023 || componentid == 1016 || componentid == 1003);
        case 555: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 558: return (componentid == 1092 || componentid == 1089 || componentid == 1166 || componentid == 1165 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1168 || componentid == 1167 || componentid == 1088 || componentid == 1091 || componentid == 1164 || componentid == 1163 || componentid == 1094 || componentid == 1090 || componentid == 1095 || componentid == 1093);
        case 559: return (componentid == 1065 || componentid == 1066 || componentid == 1160 || componentid == 1173 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1159 || componentid == 1161 || componentid == 1162 || componentid == 1158 || componentid == 1067 || componentid == 1068 || componentid == 1071 || componentid == 1069 || componentid == 1072 || componentid == 1070 || componentid == 1009);
        case 560: return (componentid == 1028 || componentid == 1029 || componentid == 1169 || componentid == 1170 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1141 || componentid == 1140 || componentid == 1032 || componentid == 1033 || componentid == 1138 || componentid == 1139 || componentid == 1027 || componentid == 1026 || componentid == 1030 || componentid == 1031);
        case 561: return (componentid == 1064 || componentid == 1059 || componentid == 1155 || componentid == 1157 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1154 || componentid == 1156 || componentid == 1055 || componentid == 1061 || componentid == 1058 || componentid == 1060 || componentid == 1062 || componentid == 1056 || componentid == 1063 || componentid == 1057);
        case 562: return (componentid == 1034 || componentid == 1037 || componentid == 1171 || componentid == 1172 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1149 || componentid == 1148 || componentid == 1038 || componentid == 1035 || componentid == 1147 || componentid == 1146 || componentid == 1040 || componentid == 1036 || componentid == 1041 || componentid == 1039);
        case 565: return (componentid == 1046 || componentid == 1045 || componentid == 1153 || componentid == 1152 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1150 || componentid == 1151 || componentid == 1054 || componentid == 1053 || componentid == 1049 || componentid == 1050 || componentid == 1051 || componentid == 1047 || componentid == 1052 || componentid == 1048);
        case 566: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 567: return (componentid == 1129 || componentid == 1132 || componentid == 1189 || componentid == 1188 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1187 || componentid == 1186 || componentid == 1130 || componentid == 1131 || componentid == 1102 || componentid == 1133);
        case 575: return (componentid == 1044 || componentid == 1043 || componentid == 1174 || componentid == 1175 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1176 || componentid == 1177 || componentid == 1099 || componentid == 1042);
        case 576: return (componentid == 1136 || componentid == 1135 || componentid == 1191 || componentid == 1190 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1192 || componentid == 1193 || componentid == 1137 || componentid == 1134);
        case 579: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 580: return (componentid == 1020 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1017 || componentid == 1007);
        case 585: return (componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007);
        case 587: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 589: return (componentid == 1005 || componentid == 1004 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1024 || componentid == 1013 || componentid == 1006 || componentid == 1016 || componentid == 1000 || componentid == 1017 || componentid == 1007);
        case 600: return (componentid == 1005 || componentid == 1004 || componentid == 1020 || componentid == 1022 || componentid == 1018 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1017 || componentid == 1007);
        case 602: return (componentid == 1008 || componentid == 1009 || componentid == 1010);
        case 603: return (componentid == 1144 || componentid == 1145 || componentid == 1142 || componentid == 1143 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1017 || componentid == 1007);
    }
    return 0;
}
stock GiveWeapon(playerid,weaponid,ammo)
{
    SetPVarInt(playerid, "GunCheckTime", 2);
    new ammow = 0;
    if(weaponid >= 1 && weaponid <= 9) GetPlayerWeaponData(playerid, 1, ammow, ammow);
    if(weaponid >= 10 && weaponid <= 15) GetPlayerWeaponData(playerid, 10, ammow, ammow);
    if(weaponid >= 16 && weaponid <= 19) GetPlayerWeaponData(playerid, 8, ammow, ammow);
    if(weaponid >= 22 && weaponid <= 24) GetPlayerWeaponData(playerid, 2, ammow, ammow);
    if(weaponid >= 25 && weaponid <= 27) GetPlayerWeaponData(playerid, 3, ammow, ammow);
    if(weaponid >= 28 && weaponid <= 29 || weaponid == 32) GetPlayerWeaponData(playerid, 4, ammow, ammow);
    if(weaponid >= 30 && weaponid <= 31) GetPlayerWeaponData(playerid, 5, ammow, ammow);
    if(weaponid >= 33 && weaponid <= 34) GetPlayerWeaponData(playerid, 6, ammow, ammow);
    if(weaponid >= 35 && weaponid <= 38) GetPlayerWeaponData(playerid, 7, ammow, ammow);
    if(weaponid >= 41 && weaponid <= 43) GetPlayerWeaponData(playerid, 9, ammow, ammow);
    Weapons[playerid][weaponid] += (ammo+ammow);
	GivePlayerWeapon(playerid,weaponid,ammo);
	return true;
}
stock GetGangZoneColor(fractionid)
	return
		(GZInfo[fractionid][gFrak] == TEAM_SPARTAK) ? (0x009900AA) :
		(GZInfo[fractionid][gFrak] == TEAM_CSKA) ? (0xffa500AA) :
		(GZInfo[fractionid][gFrak] == TEAM_DINAMO) ? (0x00CCFFAA) : (0xFFFFFF65);

stock GetGangName(fractionid)
{
	new string[20];
	switch(fractionid)
	{
		case 7: format(string, sizeof(string), "Южная");
		case 8: format(string, sizeof(string), "Ореховская");
		case 9: format(string, sizeof(string), "Солнцевская");
	}
	return string;
}

stock IsInAllowed(playerid)
{
	for(new i = 0; i < sizeof(allowedfactions); i++)
	{
		if(PI[playerid][pMember] == allowedfactions[i]||PI[playerid][pLeader] == allowedfactions[i]) return 1;
	}
	return 0;
}

stock IsInAllowedF(fractionid)
{
	for(new i = 0; i < sizeof(allowedfactions); i++)
	{
		if(fractionid == allowedfactions[i]) return 1;
	}
	return 0;
}

stock IsPlayerInBandOnline(fractionid)
{
	new np;
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(PI[i][pMember] == fractionid || PI[i][pLeader] == fractionid) np++;
	}
	return np;
}

stock IsPlayerToSquare(playerid,Float:min_x,Float:min_y,Float:max_x,Float:max_y)
{
	new Float:xxp,Float:yyp,Float:zzp;
	GetPlayerPos(playerid, xxp, yyp, zzp);
	if((xxp <= max_x && xxp >= min_x) && (yyp <= max_y && yyp >= min_y)) return 1;
	return 0;
}
stock GivePlayerWeaponAC(playerid, weaponid, ammo)
{
    new slot = GetWeaponSlotEx(weaponid);
	if(slot == -1) return 0;
	PI[playerid][pGun][slot] = weaponid;
    if(ammo > 0) PI[playerid][pAmmo][slot] += ammo;
    else PI[playerid][pAmmo][slot] -= ammo;
	GivePlayerWeapon(playerid, weaponid, ammo);
	return 1;
}
stock RemovePlayerWeapon(playerid, weaponid)
{
	if(!IsPlayerConnected(playerid) || weaponid < 0 || weaponid > 50) return;
	for(new i = 0; i < 12; i++) GetPlayerWeaponData(playerid, i, PI[playerid][pGun][i], PI[playerid][pAmmo][i]);
	ResetPlayerWeaponsAC(playerid);
	for(new i = 0; i < 12; i++)
	{
		if(PI[playerid][pGun][i] == weaponid || PI[playerid][pAmmo][i] == 0) continue;
		GivePlayerWeaponAC(playerid, PI[playerid][pGun][i], PI[playerid][pAmmo][i]);
	}
	GivePlayerWeaponAC(playerid, 0, 1);
}
stock ResetPlayerWeaponsAC(playerid)
{
	for(new i = 0; i < 12; i++)
    {
        PI[playerid][pGun][i] = 0;
		PI[playerid][pAmmo][i] = 0;
	}
	ResetPlayerWeapons(playerid);
	return 1;
}
stock GetWeaponSlotEx(weaponid)
{
	switch(weaponid)
	{
		case 0,1:			return 0;
		case 2..9:			return 1;
		case 22..24:		return 2;
		case 25..27:		return 3;
		case 28,29,32:		return 4;
		case 30,31:			return 5;
		case 33,34:			return 6;
		case 35..38:		return 7;
		case 16..18,39:		return 8;
		case 41..43:		return 9;
		case 10..15:		return 10;
		case 44..46:		return 11;
		case 40:			return 12;
	}
	return -1;
}
stock GzCheck()
{
	new string[256], SCORE[128];
	for(new i = 0; i < sizeof(GZInfo); i++)
	{
		if(ZoneOnBattle[i] == 1 && IsCapture == true)
		{
   			foreach(new x: Player)
			{
				if(PlayerLogged[x] == false && drawcapt[x] == true) continue;
				if(PI[x][pMember] == GZInfo[i][gNapad] || PI[x][pMember] == GZInfo[i][gFrak])
				{
				    for(new s; s < 10; s++) PlayerTextDrawShow(x, CaptureTD[x][s]);
					format(SCORE, sizeof(SCORE), "%s", GetGangName(GZInfo[i][gNapad]));
					PlayerTextDrawSetString(x, CaptureTD[x][7], SCORE);
					format(SCORE, sizeof(SCORE), "%s", GetGangName(GZInfo[i][gFrak]));
					PlayerTextDrawSetString(x, CaptureTD[x][8], SCORE);
					format(SCORE, sizeof(SCORE), "%d", GangInfo[GZInfo[i][gNapad]][score]);
					PlayerTextDrawSetString(x, CaptureTD[x][9], SCORE);
					format(SCORE, sizeof(SCORE), "%d", GangInfo[GZInfo[i][gFrak]][score]);
					PlayerTextDrawSetString(x, CaptureTD[x][10], SCORE);
					GangZoneFlashForPlayer(x,GangZone[i],GetGangZoneColor(GZInfo[i][gNapad]));
					drawcapt[x] = true;
				}
			}
		}
		if(ZoneOnBattle[i] == 1 && GZSafeTime[i] == 0)
		{
			if(GangInfo[GZInfo[i][gNapad]][score] == GangInfo[GZInfo[i][gFrak]][score])
			{
				new zh = GZInfo[i][gNapad];
				new zj = i;
				new zg = GZInfo[i][gFrak];
				format(string, 128, "Вы захватили новую территорию, которая находилась под контролем банды %s",GetGangName(zg));
				SendFMes(GZInfo[i][gNapad],COLOR_GREEN, string);
				format(string, 128, "Вам не удалось отстоять свою территорию, теперь эта территория под контролем банды %s",GetGangName(zh));
				SendFMes(GZInfo[i][gFrak],COLOR_RED, string);
				ZoneOnBattle[i] = 0;
				IsCapture = false;
				CaptureEnd(GZInfo[i][gNapad], GZInfo[i][gFrak]);
				GangInfo[GZInfo[i][gNapad]][captureid] =
				GangInfo[GZInfo[i][gNapad]][capture] =
				GangInfo[GZInfo[i][gNapad]][score] =
				GangInfo[GZInfo[i][gFrak]][captureid] =
				GangInfo[GZInfo[i][gFrak]][capture] =
				GangInfo[GZInfo[i][gFrak]][score] =
				GangInfo[GZInfo[i][gNapad]][gangnumber] =
				GangInfo[GZInfo[i][gFrak]][gangnumber] = 0;
				GZInfo[zj][gFrak] = zh;
				GZInfo[zj][gNapad] = 0;
				GangZoneStopFlashForAll(GangZone[zj]);
				GangZoneHideForAll(GangZone[zj]);
				GangZoneShowForAll(GangZone[zj],GetGangZoneColor(zj));
				SaveGZ(zj);

			}
			else if(GangInfo[GZInfo[i][gNapad]][score] > GangInfo[GZInfo[i][gFrak]][score])
			{
				new zx = GZInfo[i][gNapad];
				new zl = i;
				format(string, 128, "Вы захватили новую территорию, которая находилась под контролем банды %s", GetGangName(GZInfo[i][gFrak]));
				SendFMes(GZInfo[i][gNapad],COLOR_GREEN, string);
				format(string, 128, "Вам не удалось отстоять свою территорию, теперь эта территория под контролем банды %s",GetGangName(zx));
				SendFMes(GZInfo[i][gFrak],COLOR_RED, string);
				ZoneOnBattle[zl] = 0;
				CaptureEnd(GZInfo[zl][gNapad], GZInfo[zl][gFrak]);
				GangInfo[GZInfo[zl][gNapad]][captureid] =
				GangInfo[GZInfo[zl][gNapad]][capture] =
				GangInfo[GZInfo[zl][gNapad]][score] =
				GangInfo[GZInfo[zl][gFrak]][captureid] =
				GangInfo[GZInfo[zl][gFrak]][capture] =
				GangInfo[GZInfo[zl][gFrak]][score] =
				GangInfo[GZInfo[i][gNapad]][gangnumber] =
				GangInfo[GZInfo[i][gFrak]][gangnumber] = 0;
				GZInfo[zl][gFrak] = zx;
				GZInfo[zl][gNapad] = 0;
				IsCapture = false;
				GangZoneStopFlashForAll(GangZone[zl]);
				GangZoneHideForAll(GangZone[zl]);
				GangZoneShowForAll(GangZone[zl],GetGangZoneColor(zl));
				SaveGZ(zl);

			}
			else if(GangInfo[GZInfo[i][gNapad]][score] < GangInfo[GZInfo[i][gFrak]][score])
			{
				new zx = GZInfo[i][gFrak];
				new zl = i;
				SendFMes(GZInfo[i][gNapad],COLOR_RED, "Вам не удалось захватить новую территорию");
				SendFMes(GZInfo[i][gFrak],COLOR_GREEN,"Вы отстояли свою территорию");
				ZoneOnBattle[zl] = 0;
				CaptureEnd(GZInfo[zl][gNapad], GZInfo[zl][gFrak]);
				GangInfo[GZInfo[zl][gNapad]][captureid] =
				GangInfo[GZInfo[zl][gNapad]][capture] =
				GangInfo[GZInfo[zl][gNapad]][score] =
				GangInfo[GZInfo[zl][gFrak]][captureid] =
				GangInfo[GZInfo[zl][gFrak]][capture] =
				GangInfo[GZInfo[zl][gFrak]][score] =
				GangInfo[GZInfo[i][gNapad]][gangnumber] =
				GangInfo[GZInfo[i][gFrak]][gangnumber] = 0;
				IsCapture = false;
				GZInfo[zl][gFrak] = zx;
				GZInfo[zl][gNapad] = 0;
				GangZoneStopFlashForAll(GangZone[zl]);
				GangZoneHideForAll(GangZone[zl]);
				GangZoneShowForAll(GangZone[zl],GetGangZoneColor(zl));
				SaveGZ(zl);

			}
		}
	}
	for(new i = 0; i < sizeof(GZInfo); i++)
	{
		for(new z = 0; z < 20; z++)
		{
			OnZONE[i][z] = 0;
		}
	}
	for(new i = 0; i < sizeof(MZInfo); i++)
	{
		if(ZoneOnBattlem[i] == 1 && MZSafeTime[i] == 0)
		{
			ZoneTimerm[i] -= 10;
			if(ZoneTimerm[i] <= 0)
			{
				for(new h = 0; h < sizeof(BizzInfo); h++)
				{
					if(BizzInfo[h][bZahvat] == 1)
					{
						SendFMes(BizzInfo[h][bMafia],COLOR_GREEN,"Вам удалось отстоять свой бизнес");
						BizzInfo[h][bZahvat] = 0;
					}
				}
				SendFMes(MZInfo[i][mNapad],COLOR_RED,"Вам не удалось взять под контроль новый бизнес");
				startwar = 0;
				ZoneOnBattlem[i] = 0;
				GangZoneStopFlashForAll(zons);
			}
			foreach(new x: Player)
			{
				if(IsPlayerToSquare(x,328.755706, 2412.644531, 448.755706, 2564.644531))
				{
					new factionm;
					if(PI[x][pLeader] != 0) factionm = PI[x][pLeader];
					else factionm = PI[x][pMember];
					OnmZONE[i][factionm]++;
				}
			}
			new asd;
			for(new x = 0; x < 20; x++)
			{
				if(OnmZONE[i][x] > 0 && IsInAllowedM(x)) asd++;
			}
			if(asd == 1)
			{
				for(new x = 0; x < 20; x++)
				{
					if(OnmZONE[i][x] > 0)
					{
						new zx = x;
						new zl = i;
						if(MZInfo[i][mFrakVlad] == x)
						{
							for(new h = 0; h < sizeof(BizzInfo); h++)
							{
								if(BizzInfo[h][bZahvat] == 1)
								{
									BizzInfo[h][bMafia] = BizzInfo[h][bMafia];
									switch(BizzInfo[h][bMafia])
									{
									   	case TEAM_SPARTAK: MafiaTotalBizz[0]++;
									   	case TEAM_CSKA: MafiaTotalBizz[1]++;
									   	case TEAM_DINAMO: MafiaTotalBizz[2]++;
									}
									SendFMes(BizzInfo[h][bMafia],COLOR_GREEN,"Вы отстояли свой бизнес");
									BizzInfo[h][bZahvat] = 0;
									MysqlUpdateBizzInt(h, "mafia", BizzInfo[h][bMafia]);
								}
							}
							startwar = 0;
							SendFMes(MZInfo[i][mNapad],COLOR_RED,"Вам не удалось завоевать ещё один бизнес");
						}
						else
						{
							startwar = 0;
							SendFMes(MZInfo[i][mNapad],COLOR_GREEN,"Вы завоевали новый бизнес");
							for(new h = 0; h < sizeof(BizzInfo); h++)
							{
								if(BizzInfo[h][bZahvat] == 1)
								{
									SendFMes(BizzInfo[h][bMafia],COLOR_RED,"Вы потеряли контроль над одним из своих бизнесов");
									BizzInfo[h][bMafia] = MZInfo[i][mNapad];
									switch(BizzInfo[h][bMafia])
									{
									   	case TEAM_SPARTAK: MafiaTotalBizz[0]--;
									   	case TEAM_CSKA: MafiaTotalBizz[1]--;
									   	case TEAM_DINAMO: MafiaTotalBizz[2]--;
									}
									BizzInfo[h][bZahvat] = 0;
									MysqlUpdateBizzInt(h, "mafia", BizzInfo[h][bMafia]);
								}
							}
						}
						ZoneOnBattlem[zl] = 0;
						MZInfo[zl][mFrakVlad] = 0;
						MZInfo[zl][mFrakVlad] = zx;
						GangZoneStopFlashForAll(zons);
						GangZoneHideForAll(zons);
						GangZoneShowForAll(zons,COLOR_NEWS);
						break;
					}
				}
			}
		}
	}
	for(new mz = 0; mz < 20; mz++)
	{
		OnmZONE[0][mz] = 0;
	}
	return 1;
}

stock LeaveFractionPlayer(playerid)
{
	if(IsAGang(playerid))
	{
		for(new i; i < 11; i++) PlayerTextDrawHide(playerid, CaptureTD[playerid][i]);
	}
	PI[playerid][pMemberSkin] = PI[playerid][pMember] = PI[playerid][pRank] = 0;
	if(PI[playerid][pLeader]) PI[playerid][pLeader] = 0;
	ResetPlayerWeaponsAC(playerid);
	SetPlayerSkin(playerid,PI[playerid][pModel]);
	PI[playerid][pSpawnChange] = 0;
	return 1;
}

stock NewsPanel(playerid)
{
	new full = 0;
	full = (PI[playerid][pMember] == TEAM_SMI) ? (0) : (PI[playerid][pMember] == TEAM_MZA) ? (1) : (2);
	new string[210];
	format(string, sizeof(string), "%s\n{FFFFFF}- Пригласить в эфир\n{FFFFFF}- Выпроводить из эфира\n%s\n%s\n{FFCC00}- Объявления [Новых %i]",
	!Ether[playerid] ? ("{63BD4E}- Войти в эфир") : ("{F04245}- Выйти из эфира"),
	!EtherCall[full] ? ("{63BD4E}- Включить прием звонков в эфир") : ("{F04245}- Выключить прием звонков в эфир"),
	!EtherSms[full] ? ("{63BD4E}- Включить прием смс в эфир") : ("{F04245}- Выключить прием смс в эфир"),
	TOTALADVERT[full]);
	ShowPlayerDialog(playerid, D_NMENU, 2,
	(PI[playerid][pMember] == TEAM_SMI) ? ("{FFCC00}ТРК Амазинг {FFFFFF}(т. 555)") :
	(PI[playerid][pMember] == TEAM_MZA) ? ("{FFCC00}ТРК Ритм {FFFFFF}(т. 666)") : ("{FFCC00}Закрыто {FFFFFF}(т. 777)"),
	string, "Принять", "Отмена");
	return 1;
}

stock MobileCrash(playerid)
{
	SendClientMessage(Mobile[playerid], COLOR_RED, "Абонент положил трубку");
	SetPlayerSpecialAction(Mobile[playerid], SPECIAL_ACTION_STOPUSECELLPHONE);
	CellTime[Mobile[playerid]] = CellTime[playerid] = Mobile[Mobile[playerid]] = -1;
	if(EtherCalled[playerid] == true) EtherCalled[playerid] = false;
	if(EtherCalled[Mobile[playerid]] == true) EtherCalled[Mobile[playerid]] = false;
	Mobile[playerid] = -1;
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
	DeletePVar(playerid, "CallTime");
	DeletePVar(Mobile[playerid], "CallTime");
	return 1;
}

stock ClearBizz(i)
{
	new playerid = GetPlayerID(BizzInfo[i][bOwner]);
	if(playerid != INVALID_PLAYER_ID)
	{
		if(IsPlayerConnected(playerid) && PlayerLogged[playerid])
		{
			PI[playerid][pBank] += BizzInfo[i][bBuyPrice];
			PI[playerid][pBank] += BizzInfo[i][bMoney];
			SendClientMessage(playerid, COLOR_YELLOW,"[Налоговая служба] Ваш бизнес закрыли в связи с нехваткой ресурсов");
			SendClientMessage(playerid, COLOR_YELLOW,"[Налоговая служба] Половина стоимости бизнеса и его бюджет зачислены На Ваш банковский счет");
		}
	}
	else
	{
		format(query, sizeof(query), "SELECT `bank`,`text` FROM `accounts` WHERE name = '%s'", BizzInfo[i][bOwner]);
		mysql_tquery(dbHandle, query, "OfflineClearBizz", "i", i);
	}
	BizzPay[i] = BizzInfo[i][bLock] = BizzInfo[i][bLockTime] = BizzInfo[i][bMafia] = BizzInfo[i][bBuyPrice] = BizzInfo[i][bMoney] = BizzInfo[i][bLic] = BizzInfo[i][bEnter] = 0;
	BizzInfo[i][bTill] = 50;
	switch(BizzInfo[i][bType])
	{
	    case 1: BizzInfo[i][bProduct] = 5000;
	    case 2: BizzInfo[i][bProduct] = 20000;
	    case 3: BizzInfo[i][bProduct] = 3000;
	    case 4: BizzInfo[i][bProduct] = 7000;
	    case 5: BizzInfo[i][bProduct] = 7000;
	    case 6: BizzInfo[i][bProduct] = 20000;
	    case 7: BizzInfo[i][bProduct] = 100000;
	    case 8: BizzInfo[i][bProduct] = 50000;
	    case 9: BizzInfo[i][bProduct] = 50000;
	}
	strmid(BizzInfo[i][bOwner], "None", 0, strlen("None"), MAX_PLAYER_NAME);
	format(query, sizeof(query), "UPDATE `bizz` SET owner='%s', block=%d, locktime=%d, money=%d, lic=%d, penter=%d, till=%d,buyprice=%d,product=%d,mafia=%d WHERE id = %d",
	BizzInfo[i][bOwner], BizzInfo[i][bLock], BizzInfo[i][bLockTime], BizzInfo[i][bMoney], BizzInfo[i][bLic], BizzInfo[i][bEnter], BizzInfo[i][bTill],BizzInfo[i][bBuyPrice],BizzInfo[i][bProduct],BizzInfo[i][bMafia],i);
	mysql_tquery(dbHandle, query, "", "");
	UpdateBizz(i);
	return 1;
}

forward OfflineClearBizz(bizzid);
public OfflineClearBizz(bizzid)
{
    new rows, fields, bank, texts[20], text[4];
    cache_get_data(rows, fields);
	if(rows)
	{
		bank = cache_get_row_int(0, 0, dbHandle); // bank
		cache_get_row(0, 1, texts, dbHandle); // text
	}
	sscanf(texts, "p<,>a<i>[4]", text);
	format(texts, sizeof(texts), "%i, 1, %i, %i", text[0], text[2], text[3]);
	bank += BizzInfo[bizzid][bBuyPrice];
	bank += BizzInfo[bizzid][bMoney];
	format(query, sizeof(query), "UPDATE `accounts` SET text = '%s', bank = %i WHERE name = '%s'", texts, bank, BizzInfo[bizzid][bOwner]);
	mysql_tquery(dbHandle, query, "", "");
	return 1;
}

stock GetHomeOplata(idx)
{
	new htax;
    if(!strcmp("A",HouseInfo[idx][hDiscript],true)) htax = 1000;
	if(!strcmp("B",HouseInfo[idx][hDiscript],true)) htax = 2000;
	if(!strcmp("C",HouseInfo[idx][hDiscript],true)) htax = 4000;
	if(!strcmp("D",HouseInfo[idx][hDiscript],true)) htax = 8000;
	if(!strcmp("E",HouseInfo[idx][hDiscript],true)) htax = 16000;
	if(!strcmp("F",HouseInfo[idx][hDiscript],true)) htax = 32000;
	if(!strcmp("G",HouseInfo[idx][hDiscript],true)) htax = 1000;
	return htax;
}
stock GetBizOplata(idx)
{
	new htax;
    if(!strcmp("24/7",BizzInfo[idx][hDiscript],true)) htax = 1000;
	if(!strcmp("Казино",BizzInfo[idx][hDiscript],true)) htax = 1000;
	if(!strcmp("Магазин одежды",BizzInfo[idx][hDiscript],true)) htax = 1000;
	if(!strcmp("АЗС",BizzInfo[idx][hDiscript],true)) htax = 1000;
	if(!strcmp("СТО",BizzInfo[idx][hDiscript],true)) htax = 1000;
	return htax;
}

forward OfflineClearHouse(houseid);
public OfflineClearHouse(houseid)
{
    new rows, fields, texts[16], text[4];
    cache_get_data(rows, fields);
	if(rows) cache_get_field_content(0, "text", texts);
	sscanf(texts, "p<,>a<i>[4]", text);
	format(texts, sizeof(texts), "%i, %i, %i, %i", houseid, text[1], text[2], text[3]);
	format(query, sizeof(query), "UPDATE `accounts`  SET text = '%s' WHERE name = '%s'", texts, HouseInfo[houseid][hOwner]);
	mysql_tquery(dbHandle, query, "", "");
	return 1;
}

stock GunShopList(playerid)
{
	if(PI[playerid][pLic][3] == 0) return SendClientMessage(playerid, COLOR_RED, "У Вас нет лицензии на оружие!");
	new string[700], str[80];
	strcat(string, "{FFCC00}Наименование\t\t{FFCC00}Цена\n");
	for(new i; i < 10-8; i++)
	{
	    format(str, sizeof(str), "{FFFFFF}%s\t\t{63BD4E}%d рублей\n", gGunNames[i], gGunCosts[i]);
	    strcat(string, str);
	}
	for(new i = 2; i < 10; i++)
	{
	    format(str, sizeof(str), "{FFFFFF}%s\t\t{63BD4E}%d рублей {AFAFAF}за 1 пт.\n", gGunNames[i], gGunCosts[i]);
	    strcat(string, str);
	}
	ShowPlayerDialog(playerid, 1374, DIALOG_STYLE_LIST, "{FFCC00}Магазин оружия", string, "Купить", "Отмена");
	return 1;
}

stock SkinShopList(playerid)
{
	ShowPlayerDialog(playerid, D_JOB+31, DIALOG_STYLE_MSGBOX, "{FFCC00}Покупка одежды", "{FFFFFF}Вы хотите перейти к выбору одежды?", "Да", "Нет");
	return 1;
}
stock MagazineList(playerid)
{
	ShowPlayerDialog(playerid, D_HEAL+13, DIALOG_STYLE_LIST, "{FFCC00}Магазин 24/7","\
	\n1. Мобильный телефон  \t\t{FFCC00}450 рублей\
	\n2. SIM-карта     		\t\t{FFCC00}300 рублей\
	\n3. Фотоаппарат		\t\t{FFCC00}300 рублей\
	\n4. Аптечки для дома	\t\t{FFCC00}550 рублей\
	\n5. Цветы				{FFCC00}100 рублей\
	\n6. Рюкзак				{FFCC00}150 рублей\
	\n7. Маска				{FFCC00}300 рублей\
	\n8. Сигарета			\t{FFCC00}70 рублей\
	\n9. Газировка			\t{FFCC00}70 рублей\
	\n10. Набор инструментов	\t{FFCC00}200 рублей","Купить", "Отмена");
	return 1;
}
stock EatList(playerid, idx)
{
	new string[512], str[64];
	strcat(string, "{FFCC00}Наименование\t\t{FFCC00}Цена\n");
	for(new i; i < 4; i++)
	{
	    if(GetPlayerInterior(playerid) == 5)
	    {
			format(str, sizeof(str), "{FFFFFF}%s\t\t{63BD4E}%d рублей\n", gEateryNames1[i], BizzInfo[idx][bTill] * gEateryCosts[i]);
			strcat(string, str);
		}
	    else if(GetPlayerInterior(playerid) == 10)
	    {
			format(str, sizeof(str), "{FFFFFF}%s\t\t{63BD4E}%d рублей\n", gEateryNames2[i], BizzInfo[idx][bTill] * gEateryCosts[i]);
			strcat(string, str);
		}
	    else if(GetPlayerInterior(playerid) == 9)
	    {
			format(str, sizeof(str), "{FFFFFF}%s\t\t{63BD4E}%d рублей\n", gEateryNames3[i], BizzInfo[idx][bTill] * gEateryCosts[i]);
			strcat(string, str);
		}
	}
	ShowPlayerDialog(playerid, D_HEAL+14, DIALOG_STYLE_LIST, "{FFCC00}Закусочная", string, "Купить", "Отмена");
	return 1;
}

stock BarList(playerid)
{
	ShowPlayerDialog(playerid, D_HEAL+15, DIALOG_STYLE_LIST, "{FFCC00}Бар","\
	\n{FFCC00}1.{FFFFFF} Минеральная вода (50 рублей)\
	\n{FFCC00}2.{FFFFFF} Обычная газировка (80 рублей)\
	\n{FFCC00}3.{FFFFFF} Кока-Кола (85 рублей)\
	\n{FFCC00}4.{FFFFFF} Пиво (60 рублей)\
	\n{FFCC00}5.{FFFFFF} Вино (200 рублей)\
	\n{FFCC00}6.{FFFFFF} Водка (100 рублей)\
	\n{FFCC00}7.{FFFFFF} Виски (300 рублей)\
	\n{FFCC00}8.{FFFFFF} Абсент (250 рублей)", "Купить", "Отмена");
	return 1;
}

/*stock BizzStats(playerid, idx)
{
	new string[800], text[20];
	switch(BizzInfo[idx][bMafia])
	{
	    case TEAM_SPARTAK: text = "ОПГ Южная";
	    case TEAM_CSKA: text = "ОПГ Ореховская";
	    case TEAM_DINAMO: text = "ОПГ Солнцевская";
		case 0: text = "отсутствует";
	}
	if(BizzInfo[idx][bProduct] < 1) SendClientMessage(playerid, COLOR_LIME, "{DC4747}[ Информация ] {ffffff}Бизнес не приносит прибыли по причине отсутствия продуктов");
	if(BizzInfo[idx][bType] == 1)
	{
		format(string, sizeof(string), "{ffffff}Название: \t\t\t{FFCC00}Магазин 24/7\n{ffffff}Тип предприятия:\t\t24/7\n{FFFFFF}Владелец: \t\t\t{0099FF}%s\n{ffffff}Стоимость: \t\t\t\t{0099FF}%d рублей\n{ffffff}Баланс: \t\t\t%d рублей\nПрибыль: \t\t\t%d рублей\nОплачен на \t\t\t\t30 из 30 дней\nЦена за вход: \t\t\t%d рублей",
		BizzInfo[idx][bOwner], BizzInfo[idx][bPrice], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[TOTALBIZZ][bEnter]);
	}
	else if(BizzInfo[idx][bType] == 2)
	{
		format(string, sizeof(string), "{ffffff}Название: \t\t\tАЗС\nТип предприятия: \t\t\tАЗС\n{FFFFFF}Владелец: \t\t\t{0099FF}%s\n{ffffff}Стоимость: \t\t\t{0099FF}%d рублей\n{ffffff}Баланс: \t\t\t%d рублей\nПрибыль за день: \t\t\t%d рублей\nОплачен на \t\t\t30 из 30 дней\nЦена за 1 литр: \t\t\t%d рублей",
		BizzInfo[idx][bOwner], BizzInfo[idx][bPrice], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[idx][bTill] / 3);
	}
	else if(BizzInfo[idx][bType] == 3)
	{
		format(string, sizeof(string), "{FFFFFF}Закусочная:\t\t\t%s\n{FFFFFF}Владелец:\t\t\t%s\n\nНа счету бизнеса:\t\t%i рублей\nВ этом часу заработано:\t%i рублей\nСтоимость бизнеса:\t\t%i рублей\nЦена за товар:\t\t%i рублей\n\nПродуктов:\t\t\t%i / 3000\n\nСтатус:\t\t\t\t%s\nЛицензия на бизнес:\t\t%s\nВремя простоя:\t\t%i час(-а/ов)\nКрыша:\t\t\t%s",
		BizzInfo[idx][bName], BizzInfo[idx][bOwner], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[idx][bPrice], BizzInfo[idx][bTill], BizzInfo[idx][bProduct]
		,(!BizzInfo[idx][bLock])?("{63BD4E}Открыт{ffffff}") : ("{F04245}Закрыт{ffffff}"),(!BizzInfo[idx][bLic])?("{F04245}Нет{ffffff}"):("{63BD4E}Да{ffffff}"), BizzInfo[idx][bLockTime], text);
	}
	else if(BizzInfo[idx][bType] == 4 || BizzInfo[idx][bType] == 5)
	{
		format(string, sizeof(string), "{FFFFFF}Клуб:\t\t\t%s\n{FFFFFF}Владелец:\t\t\t%s\n\nНа счету бизнеса:\t\t%i рублей\nВ этом часу заработано:\t%i рублей\nСтоимость бизнеса:\t\t%i рублей\nЦена за товар:\t\t%i рублей\n\nПродуктов:\t\t\t%i / 7000\n\nСтатус:\t\t\t\t%s\nЛицензия на бизнес:\t\t%s\nВремя простоя:\t\t%i час(-а/ов)\nКрыша:\t\t\t%s",
		BizzInfo[idx][bName], BizzInfo[idx][bOwner], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[idx][bPrice], BizzInfo[idx][bTill], BizzInfo[idx][bProduct]
		,(!BizzInfo[idx][bLock])?("{63BD4E}Открыт{ffffff}") : ("{F04245}Закрыт{ffffff}"),(!BizzInfo[idx][bLic])?("{F04245}Нет{ffffff}"):("{63BD4E}Да{ffffff}"), BizzInfo[idx][bLockTime], text);
	}
	else if(BizzInfo[idx][bType] == 6)
	{
		format(string, sizeof(string), "{FFFFFF}Аммуниция:\t\t\t%s\n{FFFFFF}Владелец:\t\t\t%s\n\nНа счету бизнеса:\t\t%i рублей\nВ этом часу заработано:\t%i рублей\nСтоимость бизнеса:\t\t%i рублей\n\nБоеприпасов на складе:\t%i / 20000\n\nСтатус:\t\t\t\t%s\nЛицензия на бизнес:\t\t%s\nВремя простоя:\t\t%i час(-а/ов)\nКрыша:\t\t\t%s",
		BizzInfo[idx][bOwner], BizzInfo[idx][bPrice], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[TOTALBIZZ][bEnter]);
	}
	else if(BizzInfo[idx][bType] == 7)
	{
		format(string, sizeof(string), "{FFFFFF}CTO:\t\t\t\t%s\n{FFFFFF}Владелец:\t\t\t%s\n\nНа счету бизнеса:\t\t%i рублей\nВ этом часу заработано:\t%i рублей\nСтоимость бизнеса:\t\t%i рублей\nЦена за 1 запчасть:\t\t%i рублей\n\nЗапчастей на складе:\t\t%i / 100000\n\nСтатус:\t\t\t\t%s\nЛицензия на бизнес:\t\t%s\nВремя простоя:\t\t%i час(-а/ов)\nКрыша:\t\t\t%s",
		BizzInfo[idx][bOwner], BizzInfo[idx][bPrice], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[TOTALBIZZ][bEnter]);
	}
	else if(BizzInfo[idx][bType] == 8)
	{
		format(string, sizeof(string), "{FFFFFF}Название: \t\t\t{FFCC00}Магазин Одежды\n{ffffff}Тип предприятия:\t\tМагазин одежды\n{FFFFFF}Владелец: \t\t\t{0099FF}%s\n{ffffff}Стоимость: \t\t\t\t{0099FF}%d рублей\n{ffffff}Баланс: \t\t\t%d рублей\nПрибыль: \t\t\t%d рублей\nОплачен на \t\t\t\t30 из 30 дней\nЦена за вход: \t\t\t%d рублей",
		BizzInfo[idx][bOwner], BizzInfo[idx][bPrice], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[TOTALBIZZ][bEnter]);
	}
	else if(BizzInfo[idx][bType] == 9)
	{
	   	format(string, sizeof(string), "{ffffff}Название: \t\t\t{FFCC00}Казино\n{ffffff}Тип предприятия:\t\t\tКазино\n{FFFFFF}Владелец: \t\t\t{0099FF}%s\n{ffffff}Стоимость: \t\t\t\t{0099FF}%d рублей\n{ffffff}Баланс: \t\t\t%d рублей\nПрибыль: \t\t\t%d рублей\nОплачен на \t\t\t30 из 30 дней\nЦена за вход: \t\t\t%d рублей",
		BizzInfo[idx][bOwner], BizzInfo[idx][bPrice], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[TOTALBIZZ][bEnter]);
	}
	ShowPlayerDialog(playerid, D_BIZPANEL, 0, "{FFCC00}Информация о бизнесе", string, "Изменить", "Отмена");
	return 1;
}*/

stock BizzStats(playerid, idx)
{
	new string[800], text[20];
	switch(BizzInfo[idx][bMafia])
	{
	    case TEAM_SPARTAK: text = "ОПГ Южная";
	    case TEAM_CSKA: text = "ОПГ Ореховская";
	    case TEAM_DINAMO: text = "ОПГ Солнцевская";
		case 0: text = "Отсутствует";
	}
	if(BizzInfo[idx][bProduct] < 1) SendClientMessage(playerid, COLOR_YELLOW, "Бизнес не приносит прибыли по причине отсутствия продуктов");
	if(BizzInfo[idx][bType] == 1)
	{
		format(string, sizeof(string), "{FFFFFF}Магазин 24/7:\t\t\t%s\n{FFFFFF}Владелец:\t\t\t%s\nОплачен:\t\t\t%d из 30 дней\n\nНа счету бизнеса:\t\t%iр\nВ этом часу заработано:\t%iр\nСтоимость бизнеса:\t\t%iр\n\nПродуктов:\t\t\t%i / 5000\n\nСтатус:\t\t\t\t%s\nЛицензия на бизнес:\t\t%s\nВремя простоя:\t\t%i час(-а/ов)\nКрыша:\t\t\t\t%s",
		BizzInfo[idx][bName], BizzInfo[idx][bOwner], BizzInfo[idx][bOplata], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[idx][bPrice], BizzInfo[idx][bProduct]
		,(!BizzInfo[idx][bLock])?("{63BD4E}Открыт{ffffff}") : ("{F04245}Закрыт{ffffff}"),(!BizzInfo[idx][bLic])?("{F04245}Нет{ffffff}"):("{63BD4E}Есть{ffffff}"), BizzInfo[idx][bLockTime], text);
	}
	else if(BizzInfo[idx][bType] == 2)
	{
		format(string, sizeof(string), "{FFFFFF}Заправка:\t\t\t%s\n{FFFFFF}Владелец:\t\t\t%s\nОплачен:\t\t\t%d из 30 дней\n\nНа счету бизнеса:\t\t%iр\nВ этом часу заработано:\t%iр\nСтоимость бизнеса:\t\t%iр\nЦена за 1 литр:\t\t%iр\n\nТоплива:\t\t\t%i / 20000\n\nСтатус:\t\t\t\t%s\nЛицензия на бизнес:\t\t%s\nВремя простоя:\t\t%i час(-а/ов)\nКрыша:\t\t\t%s",
		BizzInfo[idx][bName], BizzInfo[idx][bOwner], BizzInfo[idx][bOplata], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[idx][bPrice], BizzInfo[idx][bTill], BizzInfo[idx][bProduct]
		,(!BizzInfo[idx][bLock])?("{63BD4E}Открыт{ffffff}") : ("{F04245}Закрыт{ffffff}"),(!BizzInfo[idx][bLic])?("{F04245}Нет{ffffff}"):("{63BD4E}Да{ffffff}"), BizzInfo[idx][bLockTime], text);
	}
	else if(BizzInfo[idx][bType] == 3)
	{
		format(string, sizeof(string), "{FFFFFF}Закусочная:\t\t\t%s\n{FFFFFF}Владелец:\t\t\t%s\nОплачен:\t\t\t%d из 30 дней\n\nНа счету бизнеса:\t\t%iр\nВ этом часу заработано:\t%iр\nСтоимость бизнеса:\t\t%iр\nЦена за товар:\t\t%iр\n\nПродуктов:\t\t\t%i / 3000\n\nСтатус:\t\t\t\t%s\nЛицензия на бизнес:\t\t%s\nВремя простоя:\t\t%i час(-а/ов)\nКрыша:\t\t\t%s",
		BizzInfo[idx][bName], BizzInfo[idx][bOwner], BizzInfo[idx][bOplata], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[idx][bPrice], BizzInfo[idx][bTill], BizzInfo[idx][bProduct]
		,(!BizzInfo[idx][bLock])?("{63BD4E}Открыт{ffffff}") : ("{F04245}Закрыт{ffffff}"),(!BizzInfo[idx][bLic])?("{F04245}Нет{ffffff}"):("{63BD4E}Да{ffffff}"), BizzInfo[idx][bLockTime], text);
	}
	else if(BizzInfo[idx][bType] == 4 || BizzInfo[idx][bType] == 5)
	{
		format(string, sizeof(string), "{FFFFFF}Клуб:\t\t\t%s\n{FFFFFF}Владелец:\t\t\t%s\nОплачен:\t\t\t%d из 30 дней\n\nНа счету бизнеса:\t\t%iр\nВ этом часу заработано:\t%iр\nСтоимость бизнеса:\t\t%iр\nЦена за товар:\t\t%iр\n\nПродуктов:\t\t\t%i / 7000\n\nСтатус:\t\t\t\t%s\nЛицензия на бизнес:\t\t%s\nВремя простоя:\t\t%i час(-а/ов)\nКрыша:\t\t\t%s",
		BizzInfo[idx][bName], BizzInfo[idx][bOwner], BizzInfo[idx][bOplata], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[idx][bPrice], BizzInfo[idx][bTill], BizzInfo[idx][bProduct]
		,(!BizzInfo[idx][bLock])?("{63BD4E}Открыт{ffffff}") : ("{F04245}Закрыт{ffffff}"),(!BizzInfo[idx][bLic])?("{F04245}Нет{ffffff}"):("{63BD4E}Да{ffffff}"), BizzInfo[idx][bLockTime], text);
	}
	else if(BizzInfo[idx][bType] == 6)
	{
		format(string, sizeof(string), "{FFFFFF}Аммуниция:\t\t\t%s\n{FFFFFF}Владелец:\t\t\t%s\nОплачен:\t\t\t%d из 30 дней\n\nНа счету бизнеса:\t\t%iр\nВ этом часу заработано:\t%iр\nСтоимость бизнеса:\t\t%iр\n\nБоеприпасов на складе:\t%i / 20000\n\nСтатус:\t\t\t\t%s\nЛицензия на бизнес:\t\t%s\nВремя простоя:\t\t%i час(-а/ов)\nКрыша:\t\t\t%s",
		BizzInfo[idx][bName], BizzInfo[idx][bOwner], BizzInfo[idx][bOplata], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[idx][bPrice], BizzInfo[idx][bProduct]
		,(!BizzInfo[idx][bLock])?("{63BD4E}Открыт{ffffff}") : ("{F04245}Закрыт{ffffff}"),(!BizzInfo[idx][bLic])?("{F04245}Нет{ffffff}"):("{63BD4E}Да{ffffff}"), BizzInfo[idx][bLockTime], text);
	}
	else if(BizzInfo[idx][bType] == 7)
	{
		format(string, sizeof(string), "{FFFFFF}CTO:\t\t\t\t%s\n{FFFFFF}Владелец:\t\t\t%s\nОплачен:\t\t\t%d из 30 дней\n\nНа счету бизнеса:\t\t%iр\nВ этом часу заработано:\t%iр\nСтоимость бизнеса:\t\t%iр\nЦена за 1 запчасть:\t\t%iр\n\nЗапчастей на складе:\t\t%i / 100000\n\nСтатус:\t\t\t\t%s\nЛицензия на бизнес:\t\t%s\nВремя простоя:\t\t%i час(-а/ов)\nКрыша:\t\t\t%s",
		BizzInfo[idx][bName], BizzInfo[idx][bOwner], BizzInfo[idx][bOplata], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[idx][bPrice], BizzInfo[idx][bTill], BizzInfo[idx][bProduct]
		,(!BizzInfo[idx][bLock])?("{63BD4E}Открыт{ffffff}") : ("{F04245}Закрыт{ffffff}"),(!BizzInfo[idx][bLic])?("{F04245}Нет{ffffff}"):("{63BD4E}Да{ffffff}"), BizzInfo[idx][bLockTime], text);
	}
	else if(BizzInfo[idx][bType] == 8)
	{
		format(string, sizeof(string), "{FFFFFF}Магазин одежды:\t\t%s\n{FFFFFF}Владелец:\t\t\t%s\nОплачен:\t\t\t%d из 30 дней\n\nНа счету бизнеса:\t\t%iр\nВ этом часу заработано:\t%iр\nСтоимость бизнеса:\t\t%iр\n\nТовар:\t\t\t\t%i / 50000\n\nСтатус:\t\t\t\t%s\nЛицензия на бизнес:\t\t%s\nВремя простоя:\t\t%i час(-а/ов)\nКрыша:\t\t\t%s",
		BizzInfo[idx][bName], BizzInfo[idx][bOwner], BizzInfo[idx][bOplata], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[idx][bPrice], BizzInfo[idx][bProduct]
		,(!BizzInfo[idx][bLock])?("{63BD4E}Открыт{ffffff}") : ("{F04245}Закрыт{ffffff}"),(!BizzInfo[idx][bLic])?("{F04245}Нет{ffffff}"):("{63BD4E}Да{ffffff}"), BizzInfo[idx][bLockTime], text);
	}
	else if(BizzInfo[idx][bType] == 9)
	{
	    format(string, sizeof(string), "{FFFFFF}Казино:\t\t\t%s\n{FFFFFF}Владелец:\t\t\t%s\nОплачен:\t\t\t%d из 30 дней\n\nНа счету бизнеса:\t\t%iр\nВ этом часу заработано:\t%iр\nСтоимость бизнеса:\t\t%iр\n\nТовар:\t\t\t\t%i / 50000\n\nСтатус:\t\t\t\t%s\nЛицензия на бизнес:\t\t%s\nВремя простоя:\t\t%i час(-а/ов)\nКрыша:\t\t\t%s",
		BizzInfo[idx][bName], BizzInfo[idx][bOwner], BizzInfo[idx][bOplata], BizzInfo[idx][bMoney], BizzPay[idx], BizzInfo[idx][bPrice], BizzInfo[idx][bProduct]
		,(!BizzInfo[idx][bLock])?("{63BD4E}Открыт{ffffff}") : ("{F04245}Закрыт{ffffff}"),(!BizzInfo[idx][bLic])?("{F04245}Нет{ffffff}"):("{63BD4E}Да{ffffff}"), BizzInfo[idx][bLockTime], text);
	}
	ShowPlayerDialog(playerid, D_NULL, 0, "{FFCC00}Статистика бизнеса", string, "Закрыть", "");
	return 1;
}

stock AdvertList(playerid)
{
	new full = 0;
	full = (PI[playerid][pMember] == TEAM_SMI) ? (0) : (PI[playerid][pMember] == TEAM_MZA) ? (1) : (2);
	new str[42], str2[630];
	for(new i = 1; i <= TOTALADVERT[full]; i++)
	{
		format(str, sizeof(str), "№%i - Прислал: %s\n",i, AdvertInfo[i][full][aName]);
		strcat(str2, str);
	}
	if(TOTALADVERT[full] == 0) return ShowPlayerDialog(playerid, D_NULL, 0, "{FFCC00}Объявления", "{FFFFFF}Новых объявлений нет", "Назад", "");
	ShowPlayerDialog(playerid, D_NMENU+5, 2, "{FFCC00}Объявления", str2, "Принять", "Отмена");
	return 1;
}

stock BankFracEnter(playerid)
{
	new bank, string[256];
	if(PI[playerid][pMember] == TEAM_SMI) bank = FracBank[8];
	if(PI[playerid][pMember] == TEAM_MZA) bank = FracBank[9];
	//if(PI[playerid][pMember] == TEAM_LVNEWS) bank = FracBank[10];
	format(string, sizeof(string), "Ввод средств в банк организации\nВывод средств из банка организации\nВ банке организации: %i рублей", bank);
	ShowPlayerDialog(playerid, D_JOB+131, 2, "{FFCC00}Банк", string, "Принять", "Отмена");
	return 1;
}

stock SavePos(playerid)
{
    new Float:X;
    new Float:Y;
    new Float:Z;
    GetPlayerPos(playerid,X,Y,Z);
    PI[playerid][PosX] = X;
    PI[playerid][PosY] = Y;
    PI[playerid][PosZ] = Z;
    PI[playerid][pInt] = GetPlayerInterior(playerid);
    PI[playerid][pWorld] = GetPlayerVirtualWorld(playerid);
    SaveAcc();
    return true;
}

stock SetPos(playerid)
{
    SetPlayerInterior(playerid, PI[playerid][pInt]);
    SetPlayerVirtualWorld(playerid, PI[playerid][pWorld]);
    SetPlayerPos(playerid, PI[playerid][PosX],PI[playerid][PosY],PI[playerid][PosZ]);
    return true;
}

stock SetPosInShop(playerid)
{
	SetPlayerPos(playerid,2641.2471,-1920.3633,2325.8000);
	SetPlayerFacingAngle(playerid,270.0000);
	SetPlayerInterior(playerid,3);
	SetPlayerVirtualWorld(playerid,playerid);
	TogglePlayerControllable(playerid,false);
	pPressed[playerid] = 0;
	LinkVehicleToInterior(PI[playerid][SalonCarID],3);
	SetVehicleVirtualWorld(PI[playerid][SalonCarID],playerid);
	for(new i; i < 19; i++) PlayerTextDrawShow(playerid,choicecars[playerid][i]);
	PutPlayerInVehicle(playerid,PI[playerid][SalonCarID],0);
}

/*stock SetPosInShop(playerid)
{
	SetPlayerPos(playerid,2641.2471,-1920.3633,2325.8000);
	SetPlayerFacingAngle(playerid,270.0000);
	TogglePlayerControllable(playerid,false);
	pPressed[playerid] = 0;
	SetPlayerVirtualWorld(playerid, 1);
	SetVehicleVirtualWorld(PI[playerid][SalonCarID],playerid);
	for(new i; i < 19; i++) PlayerTextDrawShow(playerid,choicecars[playerid][i]);
	PutPlayerInVehicle(playerid,PI[playerid][SalonCarID],0);
}*/

forward OfflineSetReferalMoney(playerid);
public OfflineSetReferalMoney(playerid)
{
    new rows, fields, texts[12], text[4];
    cache_get_data(rows, fields);
	if(rows) cache_get_field_content(0, "text", texts);
    sscanf(texts, "p<,>a<i>[4]", text);
   	format(texts, sizeof(texts), "%i, %i, %i, %i", text[0], text[1], 1, text[3]);
    format(query, sizeof(query), "UPDATE `accounts`  SET text = '%s' WHERE name = '%s'", texts, PI[playerid][pReferal]);
	mysql_tquery(dbHandle, query, "", "");
	return 1;
}
stock GetVehicleIdxByKey(key)
{
	for(new i = 0; i < MAX_VEHICLES; i++)
	{
		if(!PI[i][aKey]) continue;
		if(PI[i][aKey] == key) return i;
	}
	return -1;
}
//==============================================================================
stock PayDay()
{
    new string[128];
    new hour;
    gettime(hour);
    foreach(new i: Player)
	{
	    if(!IsPlayerConnected(i)) continue;
	    if(PlayerLogged[i])
	    {
			if(PI[i][pCheckTime] >= 0 && IsThePayDayMembers(PI[i][pMember]))
			{
				PI[i][pPayCheck] += Fraction_Pay[GetTeamID(i)][PI[i][pRank]-1];
			}
			else if(PI[i][pCheckTime] >= 0 && IsAGang(i))
			{
				if(PI[i][pLeader] == TEAM_SPARTAK) PI[i][pPayCheck] += 40 * GangTotalGz[3];
				else if(PI[i][pMember] == TEAM_SPARTAK) PI[i][pPayCheck] += 100 * GangTotalGz[3];
				if(PI[i][pLeader] == TEAM_CSKA) PI[i][pPayCheck] += 40 * GangTotalGz[2];
				else if(PI[i][pMember] == TEAM_CSKA) PI[i][pPayCheck] += 100 * GangTotalGz[2];
				if(PI[i][pLeader] == TEAM_DINAMO) PI[i][pPayCheck] += 40 * GangTotalGz[0];
				else if(PI[i][pMember] == TEAM_DINAMO) PI[i][pPayCheck] += 100 * GangTotalGz[0];
    			if(PI[i][pLeader] == TEAM_ZENIT) PI[i][pPayCheck] += 40 * GangTotalGz[0];
				else if(PI[i][pMember] == TEAM_ZENIT) PI[i][pPayCheck] += 100 * GangTotalGz[0];
			}
			format(string, sizeof(string), "Текущее время: {0099FF}%d:00", hour);
			SendClientMessage(i, 0xFFFFFFFF, string);
			SendClientMessage(i,0xFFFFFFFF, "БАНКОВСКИЙ ЧЕК");
			SendClientMessage(i,0xFFFFFFFF, "______________________________________");
			SendClientMessage(i,0xFFFFFFFF, "");
			if(PI[i][pAdmin])
			{
			    new AdminSalary = 5000*(PI[i][pAdmin]+1);
			    GiveBankMoney(i, AdminSalary, "AdminSalary");
			    format(string, sizeof(string), "Админ-зарплата: {FFCC00}%d руб", AdminSalary);
			    SendClientMessage(i, 0xFFFFFFFF, string);
			}
	  		format(string, sizeof(string), "Ваша зарплата: {FFCC00}%d рублей", PI[i][pPayCheck]);
		    SendClientMessage(i, 0xFFFFFFFF, string);
			GiveBankMoney(i, PI[i][pPayCheck], "PayDay");
			format(string, sizeof(string), "Текущий баланс счёта: {FFCC00}%d рублей", PI[i][pBank]);
			SendClientMessage(i, 0xFFFFFFFF, string);
			SendClientMessage(i,0xFFFFFFFF, "______________________________________");
//			SendClientMessage(i,0xDA70D6FF, "Вы отыграли 5 часов без AFK на нашем сервере.");
//			SendClientMessage(i,0xDA70D6FF, "Теперь вы можете бесплатно прокрутить рулетку на нашем сайте! (perfomance-rp.ru/roulette)");
			PI[i][pPayCheck] = 0;
			if(PI[i][pZakon] < 100) PI[i][pZakon]+=10;
			{
				PI[i][pCheckTime] = 0;
				PI[i][pTime]++;
				PI[i][pExp]++;
				if(doubling_exp) PI[i][pExp]++;
			    if(PI[i][pVip] && !(PI[i][pTime] % 2)) PI[i][pExp]++;
			    if(PI[i][pExp] >= (PI[i][pLevel]+0)*4)
			    {
			        SendClientMessage(i, COLOR_BLUE, "Ваш игровой уровень повысился, теперь Вы перешли на следующий уровень!");
				    PI[i][pLevel]++;
				    PI[i][pExp] = 0;
				    SetPlayerScore(i, PI[i][pLevel]);
			    }
//=======================[ Реферальная система ]================================
			    if(PI[i][pLevel] == 5 && PI[i][pExp] == 0)
			    {
			        if(!strcmp(PI[i][pReferal], "None", true)) { }
			        else
			        {
			        	new targetid = GetPlayerID(PI[i][pReferal]);
						if(targetid != INVALID_PLAYER_ID)
						{
							TransferMoney(-1, targetid, 100000);
						    SendClientMessage(targetid, COLOR_YELLOW, "Вы получили {ffffff}100000 рублей{FFCC00} за приглашенного игрока");
						}
						else
						{
						  	format(query, sizeof(query), "SELECT * FROM `accounts` WHERE name = '%s'", PI[i][pReferal]);
						  	mysql_tquery(dbHandle, query, "OfflineSetReferalMoney", "i", i);
						}
			   		}
			    }
			}
			SaveAccount(i);
			PlayerPlaySound(i,5203,0.0,0.0,0.0);
		}
		else SendClientMessage(i, COLOR_RED, "Вы не авторизированы для получения зарплаты");
	}
//==============================================================================
/*	if(hour == 4)
	{
		new Query[128],
			targetid;
		for(new idx = 1; idx <= TOTALPORCHHOUSE; idx++)
		{
			if(PorchHouseInfo[idx][hOwnerID] == 0) continue;
			PorchHouseInfo[idx][hDays]--;
			if(PorchHouseInfo[idx][hDays] <= 0)
			{
				targetid = GetPlayerID(PorchHouseInfo[idx][hOwner]);
				if(targetid != INVALID_PLAYER_ID)
				{
					PI[targetid][pSpawnChange] = 0;
					SendClientMessage(targetid, COLOR_RED, "Вы были выселены из квартиры за неуплату");
					if(PI[targetid][PlayerCarID] != INVALID_VEHICLE_ID)
					{
						DestroyVehicle(PI[targetid][PlayerCarID]);
						PI[targetid][PlayerCarID] = INVALID_VEHICLE_ID;
					}
					MysqlUpdatePlayerInt(targetid, "spawnchange", PI[targetid][pSpawnChange]);
				}
				else
				{
					mysql_format(dbHandle, Query,sizeof Query, "UPDATE `accounts` SET `spawnchange` = '0'WHERE `id` = '%d'", PorchHouseInfo[idx][hOwnerID]);
					mysql_tquery(dbHandle, Query, "", "");
				}
				strmid(PorchHouseInfo[idx][hOwner], "None", 0, strlen("None"), MAX_PLAYER_NAME);
				PorchHouseInfo[idx][hDays] = 0;
				PorchHouseInfo[idx][hOwnerID] = 0;
				mysql_format(dbHandle, Query,sizeof Query, "UPDATE `porch_house` SET `hOwner` = 'none', `hOwnerID` = '0', `hDays` = `0' WHERE `id` = '%d'", idx);
				mysql_tquery(dbHandle, Query, "", "");
				DestroyDynamicMapIcon(PorchHouseInfo[idx][hMIcon]);
				DestroyDynamicPickup(PorchHouseInfo[idx][hPickup]);
				PorchHouseInfo[idx][hMIcon] = CreateDynamicMapIcon(PorchHouseInfo[idx][hEntrx], PorchHouseInfo[idx][hEntry], PorchHouseInfo[idx][hEntrz], 32, 0,idx + 100,9,-1,150.0);
				PorchHouseInfo[idx][hPickup] = CreateDynamicPickup(1272, 1, PorchHouseInfo[idx][hEntrx], PorchHouseInfo[idx][hEntry], PorchHouseInfo[idx][hEntrz]);
			}
			else
			{
				mysql_format(dbHandle, Query,sizeof Query, "UPDATE `porch_house` SET `hDays` = `%d' WHERE `id` = '%d'", PorchHouseInfo[idx][hDays], idx);
				mysql_tquery(dbHandle, Query, "", "");
			}
		}
	}*/
//==============================================================================
	if(hour == 23)
	{
		for(new houseid = 1; houseid <= TOTALHOUSE; houseid++)
		{
			if(!strcmp("None", HouseInfo[houseid][hOwner], true)) continue;
			if(HouseInfo[houseid][hOplata] < 1)
			{
				new targetid = GetPlayerID(HouseInfo[houseid][hOwner]);
				if(targetid != INVALID_PLAYER_ID)
				{
					PI[targetid][pBank] += HouseInfo[houseid][hBuyPrice];
					PI[targetid][pSpawnChange] = 0;
					SendClientMessage(targetid, COLOR_YELLOW, "Вы были выселены из дома за неуплату");
					SendClientMessage(targetid, COLOR_YELLOW, "На Ваш банковский счет возвращена стоимость дома по гос-ву");
					if(PI[targetid][PlayerCarID] != INVALID_VEHICLE_ID)
					{
						DestroyVehicle(PI[targetid][PlayerCarID]);
						PI[targetid][PlayerCarID] = INVALID_VEHICLE_ID;
					}
				}
				else
				{
					strmid(HouseInfo[houseid][hOwner], "None", 0, strlen("None"), MAX_PLAYER_NAME);
					format(query, sizeof(query), "UPDATE `house` SET hOwner='%s',hOplata=%d,buyprice=%d,hLock=%d WHERE id=%d",
					HouseInfo[houseid][hOwner],HouseInfo[houseid][hOplata],HouseInfo[houseid][hBuyPrice],HouseInfo[houseid][hLock],houseid);
					mysql_tquery(dbHandle, query, "", "");
					UpdateHouse(houseid);
				}
				MysqlUpdatePlayerInt(targetid, "spawnchange", PI[targetid][pSpawnChange]);
				strmid(HouseInfo[houseid][hOwner], "None", 0, strlen("None"), MAX_PLAYER_NAME);
				format(query, sizeof(query), "UPDATE `house` SET hOwner='%s',hOplata=%d,buyprice=%d,hLock=%d WHERE id=%d",
				HouseInfo[houseid][hOwner],HouseInfo[houseid][hOplata],HouseInfo[houseid][hBuyPrice],HouseInfo[houseid][hLock],houseid);
				mysql_tquery(dbHandle, query, "", "");
				UpdateHouse(houseid);
			}
			else
			{
				HouseInfo[houseid][hOplata] -= 1;
				MysqlUpdateHouseInt(houseid, "hOplata", HouseInfo[houseid][hOplata]);
			}
		}
	}
//==============================================================================
	for(new bizzid = 1; bizzid <= TOTALBIZZ; bizzid++)
	{
	    if(!strcmp(BizzInfo[bizzid][bOwner], "None", true)) continue;
	    if(BizzInfo[bizzid][bMoney] < BizzInfo[bizzid][bBuyPrice] / 2000 || BizzInfo[bizzid][bLock] == 1 && BizzInfo[bizzid][bLockTime] >= 12) ClearBizz(bizzid);
	    else
	    {
	       	BizzPay[bizzid] = 0;
	       	new playerid = GetPlayerID(BizzInfo[bizzid][bOwner]);
	        if(BizzInfo[bizzid][bProduct] <= 0)
			{
				if(playerid != INVALID_PLAYER_ID && IsPlayerConnected(playerid))
				{
					if(BizzInfo[bizzid][bLockTime] == 0)
					{
					    if(GetPlayerBizz(playerid))
						{
							SendClientMessage(playerid, COLOR_YELLOW, "[Налоговая служба] Ваш бизнес был закрыт по причине: отсутствие продуктов или отсутствие лицензии");
							SendClientMessage(playerid, COLOR_YELLOW, "[Налоговая служба] Если по истечению {ffffff}12 {FFCC00}часов бизнес будет закрыт, он будет продан гос-ву");
						}
					}
					BizzInfo[bizzid][bLock] = 1;
					MysqlUpdateBizzInt(bizzid, "block", BizzInfo[bizzid][bLock]);
				}
			}
			if(BizzInfo[bizzid][bLock] == 1)
			{
				BizzInfo[bizzid][bLockTime]++;
				MysqlUpdateBizzInt(bizzid, "locktime", BizzInfo[bizzid][bLockTime]);
			}
			if(BizzInfo[bizzid][bLockTime] > 1 && BizzInfo[bizzid][bLockTime] < 12)
			{
				if(IsPlayerConnected(playerid) && playerid != INVALID_PLAYER_ID)
				{
					if(GetPlayerBizz(playerid))
					{
						SendMes(playerid, COLOR_YELLOW, "[Напоминание] Ваш бизнес закрыт уже {ffffff}%i {FFCC00}час(а)", BizzInfo[GetPVarInt(playerid, "PlayerBizz")][bLockTime]);
						SendClientMessage(playerid, COLOR_YELLOW, "[Напоминание] Если по истечению {ffffff}12 {FFCC00}часов бизнес будет закрыт, он будет продан гос-ву");
					}
				}
			}
  			BizzInfo[bizzid][bMoney] -= BizzInfo[bizzid][bBuyPrice] / 2000;
			MysqlUpdateBizzInt(bizzid, "money", BizzInfo[bizzid][bMoney]);
	    }
	   	switch(BizzInfo[bizzid][bMafia])
    	{
    		case TEAM_SPARTAK:
			{
				FracBank[6] += BizzPay[bizzid] / 10;
				MysqlUpdateMafiaInt("yakuzabank", FracBank[5]);
			}
	    	case TEAM_CSKA:
			{
				FracBank[5] += BizzPay[bizzid] / 10;
				MysqlUpdateMafiaInt("lcnbank", FracBank[6]); 
			}
			case TEAM_DINAMO:
			{
				FracBank[5] += BizzPay[bizzid] / 10;
				MysqlUpdateMafiaInt("rmbank", FracBank[7]);
			}
		}
	}
	return 1;
}
//=============================[ Спидометр ]====================================
stock HideSpeedometer(playerid)
{
    for(new i; i < 9; i++) PlayerTextDrawHide(playerid, speed_textpa[playerid][i]);
    for(new i; i < 24; i++) TextDrawHideForPlayer(playerid, speed_text[i]);
}
stock ShowSpeedometer(playerid)
{
    for(new i; i < 9; i++) PlayerTextDrawShow(playerid, speed_textpa[playerid][i]);
    for(new i; i < 24; i++) TextDrawShowForPlayer(playerid, speed_text[i]);
}
//==============================================================================
stock Menu()
{
	specmenu = CreateMenu("Spec", 1, 40.0, 220.0, 100.0);
	AddMenuItem(specmenu, 0, "Обновить");
	AddMenuItem(specmenu, 0, "Следующий");
	AddMenuItem(specmenu, 0, "Преведущий");
	AddMenuItem(specmenu, 0, "Слап");
	AddMenuItem(specmenu, 0, "GM info");
	AddMenuItem(specmenu, 0, "Статистика");
	AddMenuItem(specmenu, 0, "Выход");

	skinmenu = CreateMenu("СКИНЫ", 1, 50.0, 160.0, 90.0);
	AddMenuItem(skinmenu ,0,">> ДАЛЕЕ");
	AddMenuItem(skinmenu ,0,"<< НАЗАД");
	AddMenuItem(skinmenu ,0,"ВЫБРАТЬ");
}
//==============================================================================
public OnPlayerSelectedMenuRow(playerid, row)
{
    if(GetPlayerMenu(playerid) == Menu:INVALID_MENU) return SKick(playerid, 7436);
    if(GetPlayerMenu(playerid) == specmenu)
    {
        switch(row)
        {
            case 0:
            {
	            SetPlayerInterior(playerid,GetPlayerInterior(PI[playerid][Spectating][0]));
	            SetPlayerVirtualWorld(playerid,GetPlayerVirtualWorld(PI[playerid][Spectating][0]));
	            TogglePlayerSpectating(playerid, 1);
	            if(IsPlayerInAnyVehicle(PI[playerid][Spectating][0]))
	            {
		           new carid = GetPlayerVehicleID(PI[playerid][Spectating][0]);
		           PlayerSpectateVehicle(playerid, carid);
             	}
	            else PlayerSpectatePlayer(playerid, PI[playerid][Spectating][0]);
                ShowMenuForPlayer(specmenu, playerid);
            }
            case 1:
			{
			    new maxplayers = GetMaxPlayers();
				for(new id = PI[playerid][Spectating][0]+1, bool:secondloop; id < maxplayers; id++)
				{
				    if(id == maxplayers && !secondloop)
					{
						secondloop = true, id = 0;
						continue;
					}
					if(PlayerLogged[id] == false) continue;
					switch(GetPlayerState(id))
					{
						case 1..3: {}
						default: continue;
					}
					new param_str[4];
					format(param_str, sizeof param_str, "%i", id);
					callcmd::spec(playerid, param_str);
					break;
				}
				ShowMenuForPlayer(specmenu, playerid);
			}
            case 2:
			{
			    new maxplayers = GetMaxPlayers();
				for(new id = PI[playerid][Spectating][0]-1, bool:secondloop; id >= 0; id--)
				{
				    if(id <= 0 && !secondloop)
					{
						secondloop = true, id = maxplayers;
						continue;
					}
					if(PlayerLogged[id] == false) continue;
					switch(GetPlayerState(id))
					{
						case 1..3: {}
						default: continue;
					}
					new param_str[4];
					format(param_str, sizeof param_str, "%i", id);
					callcmd::spec(playerid, param_str);
					break;
				}
				ShowMenuForPlayer(specmenu, playerid);
			}
            case 3:
            {
                new param_str[11];
                format(param_str, sizeof(param_str), "%i", PI[playerid][Spectating][0]);
                callcmd::slap(playerid, param_str);
                ShowMenuForPlayer(specmenu, playerid);
            }
            case 4:
            {
                new param_str[11];
                format(param_str, sizeof(param_str), "%i", PI[playerid][Spectating][0]);
                callcmd::gm(playerid, param_str);
                ShowMenuForPlayer(specmenu, playerid);
            }
            case 5:
			{
				ShowPlayerStatsDialog(playerid, PI[playerid][Spectating][0]);
				ShowMenuForPlayer(specmenu, playerid);
			}
            case 6: callcmd::specoff(playerid, "");
		}
    }
    if(GetPlayerMenu(playerid) == skinmenu)
	{
		switch(row)
		{
		    case 0:
			{
			    if(PI[playerid][pSex] == 1)
				{
					if(SelectCharPlace[playerid] == 0) SelectCharPlace[playerid] = sizeof(JoinRegM)-1;
					else SelectCharPlace[playerid]--;
					SetPlayerSkin(playerid, JoinRegM[SelectCharPlace[playerid]]);
					ChosenSkin[playerid] = JoinRegM[SelectCharPlace[playerid]];
				}
			    else
			    {
					if(SelectCharPlace[playerid] == 0) SelectCharPlace[playerid] = sizeof(JoinRegF)-1;
					else SelectCharPlace[playerid]--;
					SetPlayerSkin(playerid, JoinRegF[SelectCharPlace[playerid]]);
					ChosenSkin[playerid] = JoinRegF[SelectCharPlace[playerid]];
			    }
			    {
			        ShowMenuForPlayer(skinmenu,playerid);
			    }
		    }
		    case 1:
		    {
			    if(PI[playerid][pSex] == 1)
				{
					if(SelectCharPlace[playerid] == sizeof(JoinRegM)-1) SelectCharPlace[playerid] = 0;
					else SelectCharPlace[playerid]++;
					SetPlayerSkin(playerid, JoinRegM[SelectCharPlace[playerid]]);
					ChosenSkin[playerid] = JoinRegM[SelectCharPlace[playerid]];
				}
				else
				{
					if(SelectCharPlace[playerid] == sizeof(JoinRegF)-1) SelectCharPlace[playerid] = 0;
					else SelectCharPlace[playerid]++;
					SetPlayerSkin(playerid, JoinRegF[SelectCharPlace[playerid]]);
					ChosenSkin[playerid] = JoinRegF[SelectCharPlace[playerid]];
				}
				{
					ShowMenuForPlayer(skinmenu,playerid);
				}
			}
			case 2:
			{
				PI[playerid][pModel] = ChosenSkin[playerid];
				ChosenSkin[playerid] = 0;
				SelectCharPlace[playerid] = 0;
				ClothesRound[playerid] = 0;
				TogglePlayerControllable(playerid, 1);
				CreateAccount(playerid, PI[playerid][pPassword]);
				HideMenuForPlayer(specmenu, playerid);
			}
		}
	}
    return 1;
}
//==============================================================================
/*public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
    if(!IsPlayerConnected(playerid)) return 0;
	if(PI[playerid][pAFK] >= 3) return 0;

	if(!IsACop(playerid) || !IsAArmy(playerid) || !IsAMayor(playerid) || !PI[playerid][pAdmin])
	{
		for(new i; i < sizeof(AreaInfo[arGreenZone]); i++)
	    {
	        if(IsPlayerInDynamicArea(playerid, AreaInfo[arGreenZone][i]))
	        {
				ApplyAnimation(playerid,"PED","handscower",4.1,1,0,0,0,1000);
			 	SetPlayerArmedWeapon(playerid, 0);
			 	return 0;
			}
		}
	}
    return 1;
}*/
//==============================================================================
stock SKick(playerid, reason)
{
    new string[128];
    format(string, sizeof(string), "%s [%d] был кикнут с причиной: %i", GetName(playerid), playerid, reason);
	SendLog("ServerSkick",string);
	return Kick(playerid);
}

stock SetHunger(playerid, amount)
{
	if(amount > 100) PI[playerid][pHunger] = 100;
	else if(amount < 0) PI[playerid][pHunger] = 0;
	else PI[playerid][pHunger] = amount;
	Hunger(playerid, 0);
	return 1;
}

stock Hunger(playerid, type)
{
    if(PI[playerid][pSettings] & setHungerInfo)
    {
		switch(type)
		{
		    case 0:
			{
/*				TextDrawShowForPlayer(playerid, HungerBackground[0]);
				TextDrawShowForPlayer(playerid, HungerBackground[1]);
				PlayerTextDrawTextSize(playerid, HungerProgress[playerid], 549.5 + PI[playerid][pHunger] / 100.0 * 54.5, 40.000000);*/
				switch(PI[playerid][pHunger])
				{
/*				    case 81..100: PlayerTextDrawBoxColor(playerid, HungerProgress[playerid], 0x63BD4EFF);
				    case 51..80: PlayerTextDrawBoxColor(playerid, HungerProgress[playerid], 0xCCFF00FF);
				    case 31..50: PlayerTextDrawBoxColor(playerid, HungerProgress[playerid], 0xFDE910FF);
				    case 16..30: PlayerTextDrawBoxColor(playerid, HungerProgress[playerid], 0xFF8800FF);
				    case 0..15: PlayerTextDrawBoxColor(playerid, HungerProgress[playerid], 0xFF0600FF);*/
				}
			//	PlayerTextDrawShow(playerid, HungerProgress[playerid]);
			}
			case 1:
			{
/*				PlayerTextDrawHide(playerid, HungerProgress[playerid]);
				TextDrawHideForPlayer(playerid, HungerBackground[0]);
				TextDrawHideForPlayer(playerid, HungerBackground[1]);*/
			}
		}
	}
}

stock TunningGarages(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid,20.0,2065.3801,-1832.5280,13.68)||IsPlayerInRangeOfPoint(playerid,20.0,-99.7154,1117.5011,19.88)||IsPlayerInRangeOfPoint(playerid,20.0,719.8336,-456.7990,16.47)||IsPlayerInRangeOfPoint(playerid,20.0,-1420.4562,2583.2180,55.98)||IsPlayerInRangeOfPoint(playerid,20.0,-2424.8093,1021.1127,50.53)||IsPlayerInRangeOfPoint(playerid,20.0,1975.0587,2161.9456,11.21)||
    IsPlayerInRangeOfPoint(playerid,20.0,487.9699,-1741.5265,11.28)||IsPlayerInRangeOfPoint(playerid,20.0,1025.7683,-1023.8249,32.24)||IsPlayerInRangeOfPoint(playerid,20.0,-1904.9709,285.8506,41.18)||IsPlayerInRangeOfPoint(playerid,20.0,615.2845,-124.2390,997.7112)||IsPlayerInRangeOfPoint(playerid,20.0,616.7787,-74.8150,997.6274)||IsPlayerInRangeOfPoint(playerid,20.0,617.5302,-1.9900,1001.06))return 1;
    return 0;
}
stock ShowDialogGhetto(playerid)
{
	new string[400];
	format(string, sizeof(string), "{FFFFFF}Закрыто\t\t\t| %s\nЗакрыто\t\t\t| %s\nЗакрыто\t\t\t| %s\nЗакрыто\t\t| %s\nЗакрыто\t\t| %s",
	(b_Capture{0} ? ("{F04245}Запрет включен{FFFFFF}") : ("{63BD4E}Запрет выключен{FFFFFF}")),
	(b_Capture{1} ? ("{F04245}Запрет включен{FFFFFF}") : ("{63BD4E}Запрет выключен{FFFFFF}")),
	(b_Capture{2} ? ("{F04245}Запрет включен{FFFFFF}") : ("{63BD4E}Запрет выключен{FFFFFF}")),
	(b_Capture{3} ? ("{F04245}Запрет включен{FFFFFF}") : ("{63BD4E}Запрет выключен{FFFFFF}")),
	(b_Capture{4} ? ("{F04245}Запрет включен{FFFFFF}") : ("{63BD4E}Запрет выключен{FFFFFF}")));
	ShowPlayerDialog(playerid, 969, DIALOG_STYLE_LIST, "{FFCC00}Управление каптами", string, "Изменить", "Отмена");
	return 1;
}

stock isNumeric(const string[])
{
	if(strlen(string) <= 0) return 0;
  	for(new i = 0; i < strlen(string); i++)
    {
		if((string[i] > '9' || string[i] < '0' && string[i] != '-' && string[i] != '+')
		|| (string[i] == '-' && i != 0) || (string[i] == '+' && i != 0)) return 0;
	}
  	if(strlen(string) == 1 && (string[0] == '-' || string[0] == '+')) return 0;
  	return 1;
}

forward OnPlayerChangeName(playerid, nickname[]);
public OnPlayerChangeName(playerid, nickname[])
{
    new rows, fields;
    cache_get_data(rows, fields);
	if(rows)
	{
		SendClientMessage(playerid, COLOR_RED, "Этот никнейм уже используется");
		return ShowPlayerDialog(playerid, D_JOB+20, 1, "{FFCC00}Смена нонРП ника", "{FFFFFF}Введите будущий ник\n\n{F04245}Возможно сменить только если У Вас нонРП ник!", "Принять", "Назад");
	}
	new full = 0;
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(PI[i][pAdmin] > ADM_ADMIN) full++;
	}
	if(full == 0) return SendClientMessage(playerid, COLOR_RED, "Модераторы игровых логинов сейчас находятся оффлайн!");
	set_name = playerid;
	strmid(PlayerName[playerid], nickname, 0, strlen(nickname), MAX_PLAYER_NAME);
	SendClientMessage(playerid, COLOR_YELLOW, "Вы успешно отправили заявку на смену игрового ника");
	new string[128];
	format(string, sizeof(string), "[A] %s [%i] просит сменить ник на %s", GetName(playerid), playerid, nickname);
	SendAdminMessage(COLOR_GREY, string);
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(PI[i][pAdmin] > ADM_ADMIN)
		{
			SendClientMessage(i, COLOR_RED, "Введите /okay, чтобы принять заявку");
		}
	}
	return 1;
}
forward OnPlayerChangeDonateName(playerid, nickname[]);
public OnPlayerChangeDonateName(playerid, nickname[])
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
		SendErr(playerid, "Этот никнейм уже используется");
		return ShowPlayerDialogEx(playerid, D_JOB+179, 1, "{3498db}>> Смена ника", "{FFFFFF}Введите будущий ник:", "Принять", "Назад");
	}
	if(GetPlayerHouse(playerid) > 0)
	{
		new i = GetPVarInt(playerid, "PlayerHouse");
		format(HouseInfo[i][hOwner], MAX_PLAYER_NAME, nickname);
		MysqlUpdateHouseStr(i, "hOwner", nickname);
	}
	if(GetPlayerBizz(playerid) > 0)
	{
		new i = GetPVarInt(playerid, "PlayerBizz");
		format(BizzInfo[i][bOwner], MAX_PLAYER_NAME, nickname);
		MysqlUpdateBizzStr(i, "owner", nickname);
		UpdateBizz(i);
	}

	new rowss;
	new string[128];
	new Cache: result;

	format(string, sizeof string, "SELECT * FROM ownable_cars WHERE owner_name='%s'", GetName(playerid));
	result = mysql_query(dbHandle, string);
	rowss = cache_num_rows();

	if(rowss)
	{
		format(string, sizeof string, "UPDATE ownable_cars SET owner_name='%s' WHERE owner_name='%s'", nickname, GetName(playerid));
		mysql_query(dbHandle, string);
		cache_delete(result);
	}

	cache_delete(result);

	format(string, sizeof(string), "%s сменил(а) ник на %s", GetName(playerid), nickname);
	SendClientMessageToAll(COLOR_ORANGE, string);
	PI[playerid][pCredits] -= 150;

	//new query[128];
	format(query, sizeof(query), "SELECT `referal` FROM `accounts` WHERE `name`='%s'", PI[playerid][pName]);
	mysql_tquery(dbHandle, query, "MysqlPayAZCheck", "dd", playerid, 15);

	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_ACCOUNTS" SET name='%s',credits=%i WHERE name='%s' LIMIT 1", nickname, PI[playerid][pCredits], GetName(playerid));
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
	if(PI[playerid][pAdmin])
	{
		STRING_GLOBAL[0] = EOS;
		format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_ADMIN" SET name='%s' WHERE name='%s' LIMIT 1", nickname, GetName(playerid));
		mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
	}
	if(PI[playerid][pSupport])
	{
		STRING_GLOBAL[0] = EOS;
		format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_SUPPORT" SET name='%s' WHERE name='%s' LIMIT 1", nickname, GetName(playerid));
		mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
	}
	if(PI[playerid][pYouTuber])
	{
		STRING_GLOBAL[0] = EOS;
		format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_YOUTUBER" SET name='%s' WHERE name='%s' LIMIT 1", nickname, GetName(playerid));
		mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
	}

	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_ACCOUNTS" SET referal='%s' WHERE referal='%s' LIMIT 1", nickname, GetName(playerid));
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");

	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "INSERT INTO `historyname` (`idacca`, `Name`, `lastname`) VALUE ('%d', '%s', '%s')", PI[playerid][pID], nickname, GetName(playerid));
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
	format(GetName(playerid), MAX_PLAYER_NAME, nickname);
	SetPlayerName(playerid, nickname);
	SCMF(playerid, COLOR_GREEN, "Ваше новое имя: {ffffff}%s", nickname);
	SendClientMessage(playerid, COLOR_GREEN, "Обязательно нужно сделать скриншот. Клавиша: {ffffff}F8");
	SendClientMessage(playerid, COLOR_GREEN, "Пропишите свой новый ник в окне {ffffff}CR:MP");
	Kick(playerid);
	return 1;
}

forward OnPlayerSetName(playerid, nickname[]);
public OnPlayerSetName(playerid, nickname[])
{
	new string[128];
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
		format(string, sizeof(string), "{FFFFFF}Введите будущий ник для игрока: %s", GetName(NameStats[playerid]));
		ShowPlayerDialogEx(playerid, D_UCPADMIN2, DIALOG_STYLE_INPUT, "{3498db}>> Имя игрока", string, "Принять", "Отмена");
		return SendErr(playerid, "Этот никнейм уже используется");
	}
	if(GetPlayerHouse(NameStats[playerid]))
	{
		new i = GetPVarInt(NameStats[playerid], "PlayerHouse");
		strmid(HouseInfo[i][hOwner], nickname, 0, strlen(nickname), MAX_PLAYER_NAME);
		MysqlUpdateHouseStr(i, "hOwner", nickname);
	}
	if(GetPlayerBizz(NameStats[playerid]))
	{
		new i = GetPVarInt(NameStats[playerid], "PlayerBizz");
		strmid(BizzInfo[i][bOwner], nickname, 0, strlen(nickname), MAX_PLAYER_NAME);
		MysqlUpdateBizzStr(i, "owner", nickname);
		UpdateBizz(i);
	}
	format(string, sizeof(string), "Вы сменили имя игрока %s на %s", GetName(NameStats[playerid]), nickname);
	SendClientMessage(playerid, COLOR_LIME, string);

	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_ACCOUNTS" SET name = '%s' WHERE name = '%s' LIMIT 1", nickname, GetName(NameStats[playerid]));
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
	if(PI[NameStats[playerid]][pAdmin])
	{
		STRING_GLOBAL[0] = EOS;
		format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_ADMIN" SET name='%s' WHERE name='%s' LIMIT 1", nickname, GetName(NameStats[playerid]));
		mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
	}
	if(PI[NameStats[playerid]][pSupport])
	{
		STRING_GLOBAL[0] = EOS;
		format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_SUPPORT" SET name='%s' WHERE name='%s' LIMIT 1", nickname, GetName(NameStats[playerid]));
		mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
	}
	if(PI[NameStats[playerid]][pYouTuber])
	{
		STRING_GLOBAL[0] = EOS;
		format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_YOUTUBER" SET name='%s' WHERE name='%s' LIMIT 1", nickname, GetName(NameStats[playerid]));
		mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
	}

	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_ACCOUNTS" SET referal='%s' WHERE referal='%s' LIMIT 1", nickname, GetName(NameStats[playerid]));
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");

	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "INSERT INTO `historyname` (`idacca`, `Name`, `lastname`) VALUE ('%d', '%s', '%s')", PI[NameStats[playerid]][pID], nickname, GetName(NameStats[playerid]));
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
	format(GetName(NameStats[playerid]), MAX_PLAYER_NAME, nickname);
	SetPlayerName(NameStats[playerid], nickname);
	format(string, sizeof(string), "Администратор %s сменил Вам никнейм", GetName(playerid));
	SendClientMessage(NameStats[playerid], COLOR_WHITE, string);
	format(string, sizeof(string), "Ваш новый никнейм: {ffffff}%s", nickname);
	SendClientMessage(NameStats[playerid], COLOR_GREEN, string);
	SendClientMessage(NameStats[playerid], COLOR_GREEN, "Обязательно нужно сделать скриншот. Клавиша: {ffffff}F8");
	SendClientMessage(NameStats[playerid], COLOR_GREEN, "Пропишите свой новый ник в окне {ffffff}SA:MP");
	Kick(NameStats[playerid]);
	return 1;
}

forward OnPlayerSetPhoneNumber(playerid);
public OnPlayerSetPhoneNumber(playerid)
{
    new rows, fields;
	cache_get_data(rows, fields);
    if(rows)
    {
		SendClientMessage(playerid, COLOR_RED, "Такой номер уже используется");
		ShowPlayerDialog(playerid, D_BUYSIM, DIALOG_STYLE_INPUT, "{FFCC00}Изменение номера", "{FFFFFF}Введите новый номер в поле ниже\n\n{FFCC00}Примечания:\n\
		{FFCC00}- Номер должен быть шестизначным,\nнапример: 123456\n- Номер не должен начинаться с 0", "Далее", "Отмена");
		return 1;
	}
    new price = gShopCosts[1];
    new i = GetPVarInt(playerid, "PlayerBizz");
    PI[playerid][pPhoneNumber] = GetPVarInt(playerid, "CheckNumber");
    TransferMoney(playerid, -1, price);
    if(BizzInfo[i][bProduct] > 0)
	{
		BizzInfo[i][bMoney] += price;
		BizzPay[i] += price;
		BizzInfo[i][bProduct] -= gShopProd[1];
		MysqlUpdateBizzInt(i, "money", BizzInfo[i][bMoney]);
		MysqlUpdateBizzInt(i, "product", BizzInfo[i][bProduct]);
	}
	new string[128];
	format(string, sizeof(string), "{ffffff}Вы изменили номер телефона\nТеперь с Вами можно связаться по номеру {0099FF}%i", PI[playerid][pPhoneNumber]);
	ShowPlayerDialog(playerid, D_NULL, 0, "{FFCC00}Изменение номера", string, "Закрыть", "");
	MysqlUpdatePlayerInt(playerid, "phonenumber", PI[playerid][pPhoneNumber]);
	DeletePVar(playerid, "CheckNumber");
	return 1;
}
forward MysqlCheckPhoneNumber(playerid, telephone);
public MysqlCheckPhoneNumber(playerid, telephone)
{
	if(cache_get_row_count(dbHandle) > 0) return SendClientMessage(playerid, COLOR_RED, "Произошла ошибка при покупке SIM-карты, попробуйте еще раз!");
	new num;
	foreach(new i: Player)
	{
 		if((PI[i][pPhoneNumber] == telephone) && (i != playerid))
		{
	 		SendClientMessage(playerid, COLOR_RED, "Произошла ошибка при покупке SIM-карты, попробуйте еще раз!");
	 		num++;
	 		break;
		}
	}
    if(num == 0)
	{
	    PI[playerid][pPhoneNumber] = telephone;
		SendClientMessage(playerid, COLOR_BLUE, "Вы купили мобильный телефон");
		MysqlUpdatePlayerInt(playerid, "phonenumber", PI[playerid][pPhoneNumber]);
		new price = gShopCosts[0];
		new i = GetPVarInt(playerid, "PlayerBizz");
	    TransferMoney(playerid, -1, price);
	    if(BizzInfo[i][bProduct] > 0)
	    {
			BizzInfo[i][bMoney] += price;
			BizzPay[i] += price;
			BizzInfo[i][bProduct] -= gShopProd[0];
		    MysqlUpdateBizzInt(i, "money", BizzInfo[i][bMoney]);
			MysqlUpdateBizzInt(i, "product", BizzInfo[i][bProduct]);
		}
	    MagazineList(playerid);
	}
	return 1;
}
forward OfflineMembersOnFraction(playerid);
public OfflineMembersOnFraction(playerid)
{
	new rows, fields;
	cache_get_data(rows, fields);
	new string[84], string_dialogue[1681], mname[MAX_PLAYER_NAME], mdata[15], mrank;
	strcat(string_dialogue, "{FFCC00}Посл. вход\tДолжность\t\tНик\n");
	if(rows)
	{
	for(new i = 0; i < rows; i++)
	{
	cache_get_field_content(i, "name", mname, dbHandle, MAX_PLAYER_NAME);
	cache_get_field_content(i, "datavhod", mdata, dbHandle, 15);
	mrank = cache_get_field_content_int(i, "rank", dbHandle);
	format(string, sizeof(string), "{FFFFFF}%s\t%s (%i)\t\t%s\n", mdata, Fraction_Rang[PI[playerid][pMember]][mrank], mrank, mname);
	strcat(string_dialogue, string);
	}
	}
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_LIST, "{FFCC00}Все члены организации", string_dialogue, "Закрыть", "");
	return 1;
}
forward OfflineUninviteOnFraction(playerid);
public OfflineUninviteOnFraction(playerid)
{
	new rows, fields, Names[MAX_PLAYER_NAME];
    cache_get_data(rows, fields);
    if(!rows) return SendClientMessage(playerid, COLOR_RED, "Не найдено совпадений!");
    cache_get_field_content(0, "name", Names, dbHandle, 32);
    format(query, 256, "UPDATE `accounts` SET leader = '0', member = '0', rank = '0', memberskin = '0' WHERE name = '%s' LIMIT 1",Names);
	mysql_tquery(dbHandle, query, "", "");
	new string[63];
	format(string, sizeof(string), "Вы уволили игрока %s", Names);
	SendClientMessage(playerid, COLOR_RED, string);
	return 1;
}
forward AllAdmins(playerid);
public AllAdmins(playerid)
{
   	new rows, fields;
    cache_get_data(rows, fields);
	new string[72], string_dialogue[1440], aname[MAX_PLAYER_NAME], alevel, alastcon[15], adata[15];
	strcat(string_dialogue, "{FFCC00}Ник {FFCC00}Уровень админа {FFCC00}Последний вход {FFCC00}Поставлен\n");
	if(rows)
	{
	    for(new i = 0; i < rows; i++)
	    {
	        cache_get_field_content(i, "name", aname, dbHandle, MAX_PLAYER_NAME);
			alevel = cache_get_field_content_int(i, "level", dbHandle);
			cache_get_field_content(i, "last_connect", alastcon, dbHandle, 15);
			cache_get_field_content(i, "data", adata, dbHandle, 15);
			if(alevel == 6) continue;
	    	format(string, sizeof(string), "{FFFFFF}%s\t%d\t%s\t%s\n", aname, alevel, alastcon, adata);
	    	strcat(string_dialogue, string);
    	}
	}
	ShowPlayerDialog(playerid, D_APANEL+1, DIALOG_STYLE_LIST, "{FFCC00}Весь список администрации", string_dialogue, "Закрыть", "");
	return 1;
}
//==============================================================================
forward OnPlayerReferal(playerid);
public OnPlayerReferal(playerid)
{
    new rows, fields;
    cache_get_data(rows, fields);
	if(!rows)
	{
		ShowPlayerDialog(playerid, D_JOB+30, 1, "{FFCC00}Реферал",\
		"{FFFFFF}{ffffff}Введите имя игрока, пригласившего Вас на сервер\n\
		Если Вас никто не приглашал, то нажмите \"Пропустить\"\n\n\
		{FFCC00}Если Вы достигните 5 уровня, то Ваш реферал получит 50 000 рублей", "Ок", "Пропустить");
		return SendClientMessage(playerid, COLOR_RED, "Игрок с таким логином не играет на сервере!");
	}
	new name[MAX_PLAYER_NAME];
	GetPVarString(playerid, "Drug", name, sizeof(name));
	strmid(PI[playerid][pReferal], name, 0, strlen(name), MAX_PLAYER_NAME);
	ClothesRound[playerid] = 1;
	PlayerRegistered[playerid] = 1;
	SetHealth(playerid, 100);
	SetHunger(playerid, 100);
	PlayerLogged[playerid] = true;
	SpawnPlayer(playerid);
	return 1;
}
//==============================================================================
stock Float:GetAngleToPoint(Float:X, Float:Y, Float:A, Float:x, Float:y)
{
	new Float:angle = 185.0 - atan2(X-x, Y-y);
	A -= (angle - 5.0);
	return A;
}
//==============================================================================
forward GetPlayerAngleToPoint(playerid, Float:x, Float:y);
stock GetPlayerAngleToPoint(playerid, Float:x, Float:y)
{
	new Float:ix, Float:iy, Float:iz, Float:a;
	GetPlayerFacingAngle(playerid, a);
	GetPlayerPos(playerid, ix, iy, iz);
	return floatround(GetAngleToPoint(ix, iy, a, x, y));
}
//==============================================================================
stock Float:GetPlayerAngleToPlayer(playerid, facingtoid)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(facingtoid, x, y, z);
	return float(GetPlayerAngleToPoint(playerid, x, y));
}
//==============================================================================
stock GetPlayerFaceToPlayer(playerid, targetid, Float:facing)
{
	new Float:radius = GetPlayerAngleToPlayer(playerid, targetid);
	return (radius > -facing && radius < facing);
}
//==============================================================================
stock PlayerSecurity(playerid)
{
    new string[350];
	format(string, sizeof(string), "Сменить пароль\nПотверждение почты\nУстановить защитный код\t\t| %s\n{FFCC00}Настройки графического пароля", (!PI[playerid][pCheckCode]) ? ("{F04245}Отсутствует") : ("{63BD4E}Активирован"));
	ShowPlayerDialog(playerid, D_JOB+201, 2, "{FFCC00}Защита аккаунта", string, "Выбрать", "Назад");
	return 1;
}
//==============================================================================
stock GPSPlayer_(playerid, Float:X, Float:Y, Float:Z, locname[])
{
	if(X == 0.0) return SendClientMessage(playerid, COLOR_RED, "Критическая ошибка! Обратитесь к администрации!");
 	new Float:VPos[3];
    GetPlayerPos(playerid, VPos[0], VPos[1], VPos[2]);
    UseGPS[playerid] = true;
    DisablePlayerRaceCheckpoint(playerid);
	SetPlayerRaceCheckpoint(playerid, 1, X, Y, Z, 0, 0, 0, 5.0);
	new string[128];
	format(string, sizeof(string), "Вы отметили на карте: %s. {FFCC00}Расстояние: %.1f м", locname, GetDistanceBetweenPoints(VPos[0], VPos[1], VPos[2], X, Y, Z));
	SendClientMessage(playerid, COLOR_WHITE, string);
	return 1;
}
//==============================================================================
stock MeAction(playerid, action[], Float:distance = 13.0)
{
	new string[128];
	format(string, sizeof(string), "%s %s", GetName(playerid), action);
	foreach(new i: Player)
	{
		if(!IsPlayerConnected(i) || GetPlayerDistanceToPlayer(playerid,i) > distance || GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid)) continue;
		SendClientMessage(i, COLOR_PURPLE, string);
	}
	return 1;
}
//==============================================================================
stock DoAction(playerid, action[], Float:distance = 13.0)
{
	new string[128];
	format(string, sizeof(string), "%s (( %s ))", action, GetName(playerid));
	foreach(new i: Player)
	{
		if(!IsPlayerConnected(i) ||  GetPlayerDistanceToPlayer(playerid,i) > distance || GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid)) continue;
		SendClientMessage(i, COLOR_PURPLE, string);
	}
	return 1;
}
//==============================================================================
stock TryAction(playerid, action[], Float:distance = 13.0)
{
	new string[128];
	if(random(2) == 1) format(string, sizeof(string), "%s %s | {FFCC00}Удачно", GetName(playerid), action);
	else format(string, sizeof(string), "%s %s | {FF0000}Неудачно", GetName(playerid), action);
	foreach(new i: Player)
	{
		if(!IsPlayerConnected(i) || GetPlayerDistanceToPlayer(playerid,i) > distance || GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid)) continue;
		SendClientMessage(i, COLOR_PURPLE, string);
	}
	return 1;
}
//===============================================================================
stock AutoStationBusInfo(playerid, text[]) ProxDetectorNew(playerid, 30.0, COLOR_BLUE, text);

forward OnPlayerOffMute(playerid, name[], time, reason[]);
public OnPlayerOffMute(playerid, name[], time, reason[])
{
	if(cache_get_row_count(dbHandle) > 0)
    {
		new string[144];
  		mysql_tquery(dbHandle, "SET NAMES 'cp1251'", "", "");
		mysql_tquery(dbHandle, "SET CHARACTER SET 'cp1251'", "", "");
		format(string, sizeof(string), "[A] Администратор %s поставил затычку %s в оффлайне на %d мин. Причина: %s", GetName(playerid), name, time, reason);
		SendAdminMessage(COLOR_BLUE, string);
		format(query, sizeof(query), "UPDATE `accounts` SET `mute` = '%d', `offmes_mute` = 'Администратор %s выдал Вам затычку в оффлайне на %d минут. Причина: %s' WHERE name='%s'", time*60, GetName(playerid), time, reason, name);
		mysql_tquery(dbHandle, query, "", "");

	}
	else SendClientMessage(playerid, COLOR_RED, "Игрок не найден!");
    return 1;
}
forward OnPlayerOffJail(playerid, name[], time, reason[]);
public OnPlayerOffJail(playerid, name[], time, reason[])
{
	if(cache_get_row_count(dbHandle) > 0)
    {
		new string[144];
  		mysql_tquery(dbHandle, "SET NAMES 'cp1251'", "", "");
		mysql_tquery(dbHandle, "SET CHARACTER SET 'cp1251'", "", "");
		format(string, sizeof(string), "[A] Администратор %s посадил в деморган %s в оффлайне на %d минут(ы). Причина: %s", GetName(playerid), name, time, reason);
		SendAdminMessage(COLOR_BLUE, string);
		format(query, sizeof(query), "UPDATE `accounts` SET `jail` = '3', `jailtime` = '%d', `offmes_jail` = 'Администратор %s посадил Вас в деморган в оффлайне на %d минут. Причина: %s' WHERE name='%s'", time*60, GetName(playerid), time, reason, name);
		mysql_tquery(dbHandle, query, "", "");

	}
	else SendClientMessage(playerid, COLOR_RED, "Игрок не найден!");
    return 1;
}

forward OnPlayerOffban(playerid, name[], day, reason[]);
public OnPlayerOffban(playerid, name[], day, reason[])
{
	if(cache_get_row_count(dbHandle) > 0)
    {
		new string[144];
		format(string, sizeof(string), "Администратор %s забанил игрока %s в оффлайне на %i дней. Причина: %s", GetName(playerid), name, day, reason);
		SendClientMessageToAll(COLOR_RED, string);
		SendLog("OffBan", string);
		getdate(years, months, days);
		new unbandate = gettime() + day*86400;
		new data[15];
        mysql_tquery(dbHandle, "SET NAMES 'cp1251'", "", "");
		mysql_tquery(dbHandle, "SET CHARACTER SET 'cp1251'", "", "");
		format(data, sizeof(data), "%02d.%02d.%04d", days, months, years);
		format(query, sizeof(query), "INSERT INTO bans (name, whobanned, ip, bandate, time, unbandate, reason) VALUES ('%s', '%s', '%s', '%s', '%d', '%d', '%s')", name, GetName(playerid), cache_get_row_int(0, 3, dbHandle), data, day, unbandate, reason);
		mysql_tquery(dbHandle, query, "", "");
		format(query, sizeof(query), "UPDATE `accounts` SET warn=0,member=0,leader=0,templeader=0,rank=0,job=0,spawnchange=0 WHERE name='%s'", name);
		mysql_tquery(dbHandle, query, "", "");
	}
	else SendClientMessage(playerid, COLOR_RED, "Игрок не найден!");
	return 1;
}
forward OnPlayerOffwarn(playerid, name[], reason[]);
public OnPlayerOffwarn(playerid, name[], reason[])
{
	if(cache_get_row_count(dbHandle) > 0)
	{
	    new string[144];
		if(cache_get_row_int(0, 20, dbHandle) < 3)
		{
			format(string, sizeof(string), "Администратор %s выдал предупреждение в оффлайне игроку %s. Причина: %s", GetName(playerid), name, reason);
			format(query, sizeof(query), "UPDATE `accounts` SET warn=warn+1,member=0,leader=0,templeader=0,rank=0,job=0,spawnchange=0 WHERE name='%s'", name);
			mysql_tquery(dbHandle, query, "", "");
		}
		else
		{
		    new data[15], unbandate;
			format(string, sizeof(string), "Игрок %s получил оффлайн бан на 7 дней от администратора %s. Причина: %s", name, GetName(playerid), reason);
			getdate(years, months, days);
			unbandate = gettime() + 7*86400;
			format(data, sizeof(data), "%02d.%02d.%04d", days, months, years);
			format(query, sizeof(query), "INSERT INTO bans (name, whobanned, ip, bandate, time, unbandate, reason) VALUES ('%s', '%s', '%s', '%s', 7, %d, '%s')", name, GetName(playerid), cache_get_row_int(0, 3, dbHandle), data, unbandate, reason);
			mysql_tquery(dbHandle, query, "", "");
			format(query, sizeof(query), "UPDATE `accounts` SET warn=0,member=0,leader=0,templeader=0,rank=0,job=0,spawnchange=0 WHERE name='%s'", name);
			mysql_tquery(dbHandle, query, "", "");
		}
		SendClientMessageToAll(COLOR_RED, string);
	    SendLog("WarnLog", string);
	}
	else SendClientMessage(playerid, COLOR_RED, "Игрок не найден!");
	return 1;
}

forward OnPlayerOffawarn(playerid, name[], reason[]);
public OnPlayerOffawarn(playerid, name[], reason[])
{
	if(cache_get_row_count(dbHandle) > 0)
	{
	    new string[144];
		if(cache_get_row_int(0, 20, dbHandle) < 3)
		{
			format(string, sizeof(string), "Руководитель %s выдал оффлайн выговор администратору %s. Причина: %s", GetName(playerid), name, reason);
			format(query, sizeof(query), "UPDATE `accounts` SET warn=warn+1,member=0,leader=0,templeader=0,rank=0,job=0,spawnchange=0 WHERE name='%s'", name);
			mysql_tquery(dbHandle, query, "", "");
		}
		else
		{
		    new data[15], unbandate;
			format(string, sizeof(string), "Администратор %s был снят оффлайн Руководителем %s. Причина: %s", name, GetName(playerid), reason);
			getdate(years, months, days);
			unbandate = gettime() + 7*86400;
			format(data, sizeof(data), "%02d.%02d.%04d", days, months, years);
			format(query, sizeof(query), "INSERT INTO bans (name, whobanned, ip, bandate, time, unbandate, reason) VALUES ('%s', '%s', '%s', '%s', 7, %d, '%s')", name, GetName(playerid), cache_get_row_int(0, 3, dbHandle), data, unbandate, reason);
			mysql_tquery(dbHandle, query, "", "");
			format(query, sizeof(query), "UPDATE `accounts` SET warn=0,member=0,leader=0,templeader=0,rank=0,job=0,spawnchange=0 WHERE name='%s'", name);
			mysql_tquery(dbHandle, query, "", "");
		}
		SendClientMessageToAll(COLOR_RED, string);
	    SendLog("WarnLog", string);
	}
	else SendClientMessage(playerid, COLOR_RED, "Игрок не найден!");
	return 1;
}
forward OnPlayerUnban(playerid, name[]);
public OnPlayerUnban(playerid, name[])
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(!rows) return SendClientMessage(playerid, COLOR_RED, "Данный игрок не забанен!");
    else
    {
		format(query, sizeof(query), "DELETE FROM bans WHERE name = '%s'", name);
	    mysql_tquery(dbHandle, query, "", "");
		new string[76];
		format(string, sizeof(string), "[A] %s разбанил игрока %s", GetName(playerid), name);
		SendAdminMessage(COLOR_BLUE, string);
	}
	return 1;
}
forward OnPlayerDeleteAccount1(playerid, name[]);
public OnPlayerDeleteAccount1(playerid, name[])
{
	if(cache_get_row_count(dbHandle) > 0)
    {
        new idacca, level;
        idacca = cache_get_row_int(0, 0, dbHandle);
        level = cache_get_row_int(0, 1, dbHandle);
        if(!GetPVarInt(playerid, "deleting_account"))
        {
            new string[80];
            SetPVarInt(playerid, "deleting_account", 1);
			format(string, sizeof(string), "Ник: %s, аккаунт №%i, уровень: %i. Деактивировать аккаунт??", name, idacca, level);
			SendClientMessage(playerid, COLOR_RED, string);
			SendClientMessage(playerid, COLOR_YELLOW, "Чтобы ОТМЕНИТЬ удаление аккаунта, повторите /nb без ника");
			SendClientMessage(playerid, COLOR_YELLOW, "Чтобы ПОТВЕРДИТЬ удаление аккаунта, повторите /nb [ник игрока]");
		}
		else if(GetPVarInt(playerid, "deleting_account"))
		{
		    new string[87];
	    	format(string, sizeof(string), "Аккаунт №%i деактивирован", idacca);
	    	SendClientMessage(playerid, COLOR_LIME, string);
	    	format(string, sizeof(string), "[Внимание] Руководитель %s [%i] деактивировал аккаунт %s", GetName(playerid), playerid, name);
	    	SendAdminMessage(COLOR_REDD, string);
	    	SendLog("DeleteAccount", string);
	    	if(GetPlayerID(name) != -1)
	    	{
	    	    SendClientMessage(GetPlayerID(name), COLOR_REDD, "Ваш аккаунт деактивирован");
				Kick(GetPlayerID(name));
	    	}
			format(string, sizeof(string), "DELETE FROM `accounts` WHERE `name` = '%s'", name);
			mysql_tquery(dbHandle, string, "", "");
			SetPVarInt(playerid, "deleting_account", 0);
		}
    }
    else
    {
        DeletePVar(playerid, "deleting_account");
    	SendClientMessage(playerid, COLOR_RED, "Игрок не найден!");
    }
	return 1;
}
forward OnPlayerDeleteAccount(playerid, name[]);
public OnPlayerDeleteAccount(playerid, name[])
{
	if(cache_get_row_count(dbHandle) > 0)
    {
        new idacca, level;
        idacca = cache_get_row_int(0, 0, dbHandle);
        level = cache_get_row_int(0, 1, dbHandle);
        if(!GetPVarInt(playerid, "deleting_account"))
        {
            new string[80];
            SetPVarInt(playerid, "deleting_account", 1);
			format(string, sizeof(string), "Ник: %s, аккаунт №%i, уровень: %i. Удалить аккаунт?", name, idacca, level);
			SendClientMessage(playerid, COLOR_RED, string);
			SendClientMessage(playerid, COLOR_LIME, "Чтобы {FFCC00}ОТМЕНИТЬ{FFCC00} удаление аккаунта, повторите /delacc без ника");
			SendClientMessage(playerid, COLOR_LIME, "Чтобы {FFCC00}ПОДТВЕРДИТЬ{FFCC00} удаление аккаунта, повторите /delacc [ник игрока]");
		}
		else if(GetPVarInt(playerid, "deleting_account"))
		{
		    new string[87];
	    	format(string, sizeof(string), "Аккаунт №%i удалён", idacca);
	    	SendClientMessage(playerid, COLOR_LIME, string);
	    	format(string, sizeof(string), "[Внимание] Руководитель %s [%i] удалил аккаунт %s", GetName(playerid), playerid, name);
	    	SendAdminMessage(COLOR_REDD, string);
	    	SendLog("DeleteAccount", string);
	    	if(GetPlayerID(name) != -1)
	    	{
	    	    SendClientMessage(GetPlayerID(name), COLOR_REDD, "Ваш аккаунт был удалён за нарушение правил сервера");
				Kick(GetPlayerID(name));
	    	}
			format(string, sizeof(string), "DELETE FROM `accounts` WHERE `name` = '%s'", name);
			mysql_tquery(dbHandle, string, "", "");
			SetPVarInt(playerid, "deleting_account", 0);
		}
    }
    else
    {
        DeletePVar(playerid, "deleting_account");
    	SendClientMessage(playerid, COLOR_RED, "Игрок не найден!");
    }
	return 1;
}

forward OnPlayerOffget(playerid, name[]);
public OnPlayerOffget(playerid, name[])
{
	if(cache_get_row_count(dbHandle) > 0)
	{
	    new string[64], string_dialogue[512], idacca, cash, bank, level, regip[16], lastip[16], datareg[15], donate;
	    idacca = cache_get_row_int(0, 0, dbHandle);
	    cash = cache_get_row_int(0, 11, dbHandle);
	    bank = cache_get_row_int(0, 12, dbHandle);
	    level = cache_get_row_int(0, 10, dbHandle);
	    cache_get_row(0, 14, regip, dbHandle, 16);
	    cache_get_row(0, 3, lastip, dbHandle, 16);
	    cache_get_row(0, 15, datareg, dbHandle, 15);
	    donate = cache_get_row_int(0, 58, dbHandle);
		format(string, sizeof(string), "{FFCC00}Номер аккаунта:\t%i\n", idacca);
		strcat(string_dialogue, string);
		format(string, sizeof(string), "{FFCC00}Наличные:\t\t%i\n", cash);
		strcat(string_dialogue, string);
		format(string, sizeof(string), "{FFCC00}Банковский счёт:\t%i\n", bank);
		strcat(string_dialogue, string);
		format(string, sizeof(string), "Уровень:\t\t%i\n", level);
		strcat(string_dialogue, string);
		format(string, sizeof(string), "{FFCC00}IP адрес (регис.):\t%s\n", regip);
		strcat(string_dialogue, string);
		format(string, sizeof(string), "{FFCC00}IP адрес (последн.):\t%s\n", lastip);
		strcat(string_dialogue, string);
		format(string, sizeof(string), "{FFCC00}Дата регистрации:\t%s\n", datareg);
		strcat(string_dialogue, string);
		format(string, sizeof(string), "{FFCC00}Донат:\t\t\t%i\n", donate);
		strcat(string_dialogue, string);
		ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, name, string_dialogue, "Закрыть", "");
	}
	else SendClientMessage(playerid, COLOR_RED, "Игрок не найден!");
	return 1;
}

stock SetString(param_1[], param_2[], size = 300)
{
    return strmid(param_1, param_2, 0, strlen(param_2), size);
}

stock GetString(param1[],param2[])
{
	return !strcmp(param1, param2, false);
}
forward GmTest(playerid, targetid, Float:oldhealth);
public GmTest(playerid, targetid, Float:oldhealth)
{
    new Float: newhealth;
	GetPlayerHealth(targetid, newhealth);
	new mes[256], string[60];
	if(oldhealth == newhealth) string = "{FF0000}Возможно игрок использует God Mode(GM)";
	if(oldhealth != newhealth) string = "{05E900}Вероятно игрок чист, показатель его HP уменьшился";
    format(mes, sizeof(mes), "{FFFFFF}Было: {FF9900}%.0f.0 (HP)\n{FFFFFF}Стало: {FF9900}%.0f.0 (HP)\n{FFFFFF}Уменьшилось на: {FF9900}%.0f.0 (HP)\n\n%s", oldhealth, newhealth, oldhealth-newhealth, string);
    ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, GetName(targetid), mes, "Закрыть", "");
	SetHealth(targetid, oldhealth);
	StartGMTest[playerid] = false;
	return 1;
}
forward StealMats(playerid);
public StealMats(playerid)
{
	new guns = random(5) + 1;
	new ammo = random(5) + 1;
	if(PI[playerid][pGunAmount] + guns > 500) guns = 500 - PI[playerid][pGunAmount];
	if(PI[playerid][pPatron] + ammo > 500) ammo = 500 - PI[playerid][pPatron];
	if(500 < ammo + PI[playerid][pPatron] && !PI[playerid][pImprove][2]) return 0;
	else if(1000 < ammo + PI[playerid][pPatron] && PI[playerid][pImprove][2]) return 0;
	if(500 < guns + PI[playerid][pGunAmount] && !PI[playerid][pImprove][2]) return 0;
	else if(1000 < guns + PI[playerid][pGunAmount] && PI[playerid][pImprove][2]) return 0;
	if(gArmyWarehouse[0] < guns || gArmyWarehouse[1] < ammo) return 0;
	gArmyWarehouse[1] -= ammo;
	new string[35];
	format(string, sizeof(string), "~b~+%d~n~~y~TOTAL: %d", ammo, PI[playerid][pPatron]);
	GameTextForPlayer(playerid, string, 1500, 6);
	PI[playerid][pPatron] += ammo;
	MysqlUpdatePlayerInt(playerid, "patron", PI[playerid][pPatron]);
	return 1;
}
/*stock SendFMes(family, color, str[])
{
	foreach(new i: Player)
	{
		if(!PlayerLogged[i]) continue;
		if(PI[i][pMember] == family) SendClientMessage(i, color, str);
	}
	return 1;
}*/
stock WHDataUpdate()
{
	new string[500];

	format(string,sizeof(string),"{FFCC00}Склад\n{FFFFFF}Патроны: {FFCC00}%d {FFFFFF}шт.\n{FFFFFF}Металл: {FFCC00}%d {FFFFFF}кг.\n{FFCC00}/getmet - взять металл\n/putmet - положить металл", gArmyWarehouse[1], gArmyWarehouse[0]);
	UpdateDynamic3DTextLabelText(gArmyWarehouseText,0xFFFFFFFF,string);

	format(string,sizeof(string),"{F3FF02}Склад\n\n{FFFFFF}Патроны: {FFAF00}%d\n{FFFFFF}Металл: {FFAF00}%d\n{FFFFFF}Деньги: {FFAF00}%d", MafiaPatr[0], MafiaEd[0], FracBank[5]);
	UpdateDynamic3DTextLabelText(Mafia3d[0],0xFFFFFFFF,string);

	format(string,sizeof(string),"{F3FF02}Склад\n\n{FFFFFF}Патроны: {FFAF00}%d\n{FFFFFF}Металл: {FFAF00}%d\n{FFFFFF}Деньги: {FFAF00}%d", MafiaPatr[1], MafiaEd[1], FracBank[6]);
	UpdateDynamic3DTextLabelText(Mafia3d[1],0xFFFFFFFF,string);

	format(string,sizeof(string),"{F3FF02}Склад\n\n{FFFFFF}Патроны: {FFAF00}%d\n{FFFFFF}Металл: {FFAF00}%d\n{FFFFFF}Деньги: {FFAF00}%d", MafiaPatr[2], MafiaEd[2], FracBank[7]);
	UpdateDynamic3DTextLabelText(Mafia3d[2],0xFFFFFFFF,string);
}

stock GetPlayerTruckLevel(playerid)
{
	if(PI[playerid][pTruckSkill] >= 30000) return 2;
	else return 1;
}

stock BadFloat(Float:x)
{
    if(x >= 10.0 || x <= -10.0) return 1;
    return 0;
}

stock IsIpFound(const string[])
{
	if(!CheckIPs) CheckIPs = regex_build("([0-9]{1,3})[^[:digit:]^[:cntrl:]]{1,3}([0-9]{1,3})[^[:digit:]^[:cntrl:]]{1,3}([0-9]{1,3})[^[:digit:]^[:cntrl:]]{1,3}([0-9]{1,3})");
	return regex_search_exid(string, CheckIPs);
}
//==============================================================================
stock CheckString(string[])
{
	static const WebSites[][] = {
		"риверс","р и в е р с","rivers","р и в е р с","слив","sliv","IP "};
	for(new i = 0; i < sizeof(WebSites); i++)
	{
		if(strfind(string, WebSites[i], true) != -1) return 1;
	}
	return 0;
}
//==============================================================================
stock PlayerGetsChatBan(playerid, text[])
{
	new string[90];
	format(string, sizeof(string), "[Внимание] %s[%i] получил бан чата за отправку: %s", GetName(playerid), playerid, text);
	SendAdminMessage(COLOR_RED, string);
	SendLog("PlayerAdvertise",string);
	return 1;
}
//==============================================================================
stock AdminAntisliv(playerid, text[])
{
	RemoveAdmin(playerid, GetName(playerid));
	new string[88];
	format(string, sizeof(string), "[Внимание] %s [%i] подозревается во взломе [IP:%s]", GetName(playerid), playerid, PI[playerid][pIP]);
	SendAdminMessage(COLOR_REDD, string);
	format(string, sizeof(string), "[Внимание] Текст: %s", text);
	SendAdminMessage(COLOR_REDD, string);
	SendLog("AdminAntisliv",string);
	new data[15], unbandate;
	getdate(years, months, days);
	unbandate = gettime() + 30*86400;
	format(data, sizeof(data), "%02d.%02d.%04d", days, months, years);
	format(query, sizeof(query), "INSERT INTO bans (name, whobanned, ip, bandate, time, unbandate, reason) VALUES ('%s', 'System', '%s', '%s', '30', '%d', 'Слив админки')", GetName(playerid), PI[playerid][pIP], data, unbandate);
	mysql_tquery(dbHandle, query, "", "");
	Kick(playerid);
	return 1;
}
//==============================================================================
stock AttemptRemoveChiefAdmin(playerid)
{
	RemoveAdmin(playerid, GetName(playerid));
    new data[15], unbandate;
	getdate(years, months, days);
	unbandate = gettime() + 30*86400;
	format(data, sizeof(data), "%02d.%02d.%04d", days, months, years);
	format(query, sizeof(query), "INSERT INTO bans (name, whobanned, ip, bandate, time, unbandate, reason) VALUES ('%s', 'System', '%s', '%s', '30', '%d', 'Слив админки')", GetName(playerid), PI[playerid][pIP], data, unbandate);
	mysql_tquery(dbHandle, query, "", "");
    new string[98];
    format(string, sizeof(string), "[Внимание] %s был снят за попытку выдать наказание главному администратору", GetName(playerid));
    SendAdminMessageEx(COLOR_REDD, string, 5);
    SendLog("AttemptRemoveChiefAdmin", string);
    Kick(playerid);
	return 1;
}
//==============================================================================
stock AttemptRemoveAdmin(playerid)
{
    SendClientMessage(playerid, COLOR_RED, "Администратор выше Вас рангом, или равен Вам");
    new string[97];
    format(string, sizeof(string), "[Внимание] %s попытался выдать наказание администратору выше его по рангу", GetName(playerid));
    SendAdminMessageEx(COLOR_REDD, string, 5);
    SendLog("AttemptRemoveAdmin", string);
	return 1;
}
//==============================================================================
stock RemoveAdmin(targetid, name[])
{
	PI[targetid][pAdmin] = ADM_NONE;
	new string[128];
	mysql_format(dbHandle, string, sizeof(string), "DELETE FROM `admins` WHERE `name`='%s'", name);
	mysql_tquery(dbHandle, string, "", "");
	MysqlUpdatePlayerInt(targetid, "admin", PI[targetid][pAdmin]);
	return 1;
}

stock SetSpawnInfoEx(playerid, skin, Float:x, Float:y, Float:z, Float:a)
    return SetSpawnInfo(playerid, 255, skin, x, y, z-0.2, a, 0, 0, 0, 0, 0, 0);

stock HaveWeapon(playerid, weaponid)
{
	new weapons[13][2];
	for(new i = 0; i <= 12; i++)
	{
		GetPlayerWeaponData(playerid, i, weapons[i][0], weapons[i][1]);
		if((weapons[i][0] == weaponid) && weapons[i][1]) return 1;
	}
	return 0;
}

stock split(const strsrc[], strdest[][], delimiter)
{
	new i, li, aNum, len;
	while(i <= strlen(strsrc))
	{
		if(strsrc[i]==delimiter || i==strlen(strsrc))
		{
			len = strmid(strdest[aNum], strsrc, li, i, 128);
			strdest[aNum][len] = 0;
			li = i+1;
			aNum++;
		}
		i++;
	}
	return 1;
}

stock GetNameWithNumber(number)
{
	new str[MAX_PLAYER_NAME] = {"Offline/None"};
	foreach(new i: Player)
	{
		if(!PlayerLogged[i]) continue;
		if(PI[i][pPhoneNumber] == number)
		{
			format(str, sizeof(str), "%s", GetName(i));
			break;
		}
	}
	return str;
}

forward SetAdmin(playerid, name[], level);
public SetAdmin(playerid, name[], level)
{
	new rows, fields, string[256];
	cache_get_data(rows, fields);
	if(rows)
	{
		if(!level)
		{
			if(GetPlayerID(name) != INVALID_PLAYER_ID) PI[GetPlayerID(name)][pAdmin] = 0, AdminLogged[GetPlayerID(name)] = false;
			mysql_format(dbHandle, string, sizeof(string), "DELETE FROM "T_ADMIN" WHERE `name`='%s'", name);
			mysql_tquery(dbHandle, string, "", "");
			mysql_format(dbHandle, string, sizeof(string), "UPDATE "T_ACCOUNTS" SET `admin` = '0' WHERE `name` = '%s'", name);
			mysql_tquery(dbHandle, string, "", "");
			format(string, sizeof(string), "Вы сняли %s с должности администратора", name);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), "[A] %s снял %s с должности администратора", GetName(playerid), name);
			SendAdminMessage(COLOR_GREY, string);
		}
		else
		{
			if(GetPlayerID(name) != INVALID_PLAYER_ID) PI[GetPlayerID(name)][pAdmin] = level;
			mysql_format(dbHandle, string, sizeof(string), "UPDATE "T_ADMIN" SET `level` = '%d' WHERE `name` = '%s' LIMIT 1", level, name);
			mysql_tquery(dbHandle, string, "", "");
			format(string, sizeof(string), "Вы установили уровень администратора %s на %i", name, level);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), "[A] %s установил уровень администратора %s на %i", GetName(playerid), name, level);
			SendAdminMessage(COLOR_GREY, string);
		}
	}
	else
	{
		if(!level) return SendClientMessage(playerid, COLOR_GREY, "Игрок не администратор");
		new data[15];
		getdate(years, months, days);
		format(data, sizeof(data), "%02d.%02d.%04d", days, months, years);
		mysql_format(dbHandle, string, sizeof(string), "INSERT INTO "T_ADMIN" (`name`, `level`, `last_connect`, `put_admin`, `data`) VALUES ('%s', %d, '%s', '%s', '%s')", name, level, data, GetName(playerid), data);
		mysql_tquery(dbHandle, string, "", "");
		format(string, sizeof(string), "%s добавлен в список администрации. Уровень полномочий %i", name, level);
		SendClientMessage(playerid, COLOR_GREEN, string);
		format(string, sizeof(string), "[A] %s добавил в список администрации %s (%i уровень)", GetName(playerid), name, level);
		SendAdminMessage(COLOR_GREY, string);
		if(GetPlayerID(name) != INVALID_PLAYER_ID)
		{
			format(string, sizeof(string), "%s назначил Вас администратором {FFFFFF}/alogin", GetName(playerid));
			SendClientMessage(GetPlayerID(name), COLOR_LIME, string);
		}
	}
	return 1;
}

forward Alogin(playerid, name[]);
public Alogin(playerid, name[])
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(!rows)
	{
		if(PI[playerid][pAdmin] > 0) PI[playerid][pAdmin] = 0;
		return 1;
	}
	new Password[16];
	cache_get_field_content(0, "password", Password, dbHandle);
	if(!strcmp(Password, "qwerty", true))
	{
		SetPVarInt(playerid, "aLogin", 1);
		ShowPlayerDialog(playerid, D_ALOGIN, DIALOG_STYLE_INPUT, "{FFCC00}Регистрация администратора", "\
		{FFFFFF}Введите пароль, который будет от панели администратора\n\n\
		{FFCC00}Примечание:\n\
		\t- Пароль должен состоять из латинских букв и цифр\n\
		\t- Размер пароля от 6 до 15 символов", "Принять", "Отмена");
	}
	else
	{
		SetPVarInt(playerid, "aLogin", 0);
		ShowPlayerDialog(playerid, D_ALOGIN, DIALOG_STYLE_INPUT, "{FFCC00}Доступ администратора", "\
		{FFFFFF}Пароль должен состоять из латинских букв и цифры\n\
		размером от 6 до 15 символов\n\n\
		Введите пароль:", "Войти", "Отмена");
	}
	return 1;
}
//==============================================================================
forward AloginReg(playerid, name[]);
public AloginReg(playerid, name[])
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(!rows) return 1;
	new inputtext[16], string[144], ipplayer[256];
	GetPVarString(playerid, "inputtext", inputtext, sizeof(inputtext));
	mysql_format(dbHandle, string, sizeof(string), "UPDATE "T_ADMIN" SET `password` = '%s' WHERE `name` = '%s' LIMIT 1", inputtext, GetName(playerid));
	mysql_tquery(dbHandle, string, "", "");
	PI[playerid][pAdmin] = cache_get_field_content_int(0, "level");
	GetPlayerIp(playerid,ipplayer,sizeof(ipplayer));
	MysqlUpdatePlayerInt(playerid, "admin", PI[playerid][pAdmin]);
	if(PI[playerid][pSex] == 1) format(string, sizeof(string), "<ALogin> вошёл %s[%i]", GetName(playerid), playerid);
	else format(string, sizeof(string), "<ALogin> вошла %s[%i]", GetName(playerid), playerid);
	SendAdminMessage(COLOR_SERVER, string);
	AdminLogged[playerid] = true;
	new day, month, year;
	getdate(year, month, day);
	mysql_format(dbHandle, string, sizeof(string), "UPDATE "T_ADMIN" SET `last_connect` = '%d.%d.%d' WHERE `name` = '%s' LIMIT 1", day, month, year, GetName(playerid));
	mysql_tquery(dbHandle, string, "", "");

	global_string = "";
	mysql_format(dbHandle, global_string, 128, "SELECT * FROM "T_ADMIN" WHERE `name` = '%s'",GetName(playerid));
	mysql_tquery(dbHandle, global_string, "LoadAstats", "d", playerid);
	return 1;
}
//==============================================================================
forward AloginAuth(playerid, inputtext[]);
public AloginAuth(playerid, inputtext[])
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(!rows)
	{
		SendErr(playerid, "Неверный пароль");
		SetPVarInt(playerid, "attempt_pass", GetPVarInt(playerid, "attempt_pass") + 1);
		if(GetPVarInt(playerid, "attempt_pass") > 3)
		{
			DeletePVar(playerid, "attempt_pass");
            Kick(playerid);
		}
	}
	else
	{
		new string[144];
		AdminLogged[playerid] = true;
		PI[playerid][pAdmin] = cache_get_row_int(0, 1, dbHandle);
		AdminInfo[playerid][admGoto] = cache_get_row_int(0, 6, dbHandle);
		AdminInfo[playerid][admGethere] = cache_get_row_int(0, 7, dbHandle);
		AdminInfo[playerid][admSpectate] = cache_get_row_int(0, 8, dbHandle);
		AdminInfo[playerid][admTimeMin] = cache_get_row_int(0, 9, dbHandle);
		AdminInfo[playerid][admAlog] = cache_get_row_int(0, 10, dbHandle);

		if(PI[playerid][pAdmin] != 7)
		{
			if(PI[playerid][pSex] == 1) format(string, sizeof(string), "<ALogin> вошёл %s[%i]", GetName(playerid), playerid);
			else format(string, sizeof(string), "<ALogin> вошла %s[%i]", GetName(playerid), playerid);
			SendAdminMessage(COLOR_SERVER, string);
		}

		Iter_Add(Admins, playerid);

		new day, month, year;
		getdate(year, month, day);
		mysql_format(dbHandle, string, 144, "UPDATE "T_ADMIN" SET `last_connect` = '%d.%d.%d' WHERE `name` = '%s' LIMIT 1", day, month, year, GetName(playerid));
		mysql_tquery(dbHandle, string, "", "");
	}
	return 1;
}
//==============================================================================
forward SupportAuth(playerid);
public SupportAuth(playerid)
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(!rows)
	{
		return 1;
	}
	else
	{
		new string[144];
		AdminLogged[playerid] = true;
		PI[playerid][pSupport] = cache_get_row_int(0, 1, dbHandle);
		SupportInfo[playerid][admTimeMin] = cache_get_row_int(0, 9, dbHandle);

		if(PI[playerid][pSex] == 1) format(string, sizeof(string), "Хелпер %s[%i] авторизовался.", GetName(playerid), playerid);
		else format(string, sizeof(string), "Хелпер %s[%i] авторизовалась.", GetName(playerid), playerid);
		SendAdminMessage(COLOR_BLUE, string);

		Itter_Add(Supports, playerid);

		new day, month, year;
		getdate(year, month, day);
		mysql_format(dbHandle, string, 144, "UPDATE "T_SUPPORT" SET `last_connect` = '%d.%d.%d' WHERE `name` = '%s' LIMIT 1", day, month, year, GetName(playerid));
		mysql_tquery(dbHandle, string, "", "");
	}
	return 1;
}

forward YouTuberAuth(playerid);
public YouTuberAuth(playerid)
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(!rows)
	{
		return 1;
	}
	else
	{
		new string[144];
		//AdminLogged[playerid] = true;
		PI[playerid][pYouTuber] = cache_get_row_int(0, 1, dbHandle);
		YouTubersInfo[playerid][admTimeMin] = cache_get_row_int(0, 9, dbHandle);

		if(PI[playerid][pSex] == 1) format(string, sizeof(string), "Ютубер %s[%i] авторизовался.", GetName(playerid), playerid);
		else format(string, sizeof(string), "Ютубер %s[%i] авторизовалась.", GetName(playerid), playerid);
		SendAdminMessage(COLOR_BLUE, string);

		Itter_Add(YouTubers, playerid);

		new day, month, year;
		getdate(year, month, day);
		mysql_format(dbHandle, string, 144, "UPDATE "T_YOUTUBER" SET `last_connect` = '%d.%d.%d' WHERE `name` = '%s' LIMIT 1", day, month, year, GetName(playerid));
		mysql_tquery(dbHandle, string, "", "");
	}
	return 1;
}

stock GetMonthDays(year, month)
{
	switch(month)
	{
	    case 0:     return 31;
	    case 1: 	return 31;
	    case 2: 	return februarydays(year);
	    case 3: 	return 31;
	    case 4: 	return 30;
	    case 5: 	return 31;
	    case 6: 	return 30;
	    case 7: 	return 31;
	    case 8: 	return 31;
	    case 9: 	return 30;
	    case 10: 	return 31;
	    case 11: 	return 30;
	    case 12: 	return 31;
	    default: 	return -1;
	}
	return -1;
}

stock februarydays(year)
{
	if(!(year % 4)) return 29;
	else return 28;
}

stock GetArendCarID(vehicleid, &arend_id = INVALID_PLAYER_ID)
{
    arend_id = INVALID_PLAYER_ID;
	for(new i = 0; i < sizeof(ArendInfo); i++)
	{
	    if(vehicleid == ArendInfo[i][aID])
		{
      		if(IsPlayerConnected(ArendInfo[i][aPlayerID])) arend_id = ArendInfo[i][aPlayerID];
			return i;
		}
 	}
	return -1;
}

stock GetVehicleArendID(vehicleid)
{
	new playerid = INVALID_PLAYER_ID, get_rent = GetArendCarID(vehicleid, playerid);
    if(get_rent != (-1))
	{
	    if(playerid == INVALID_PLAYER_ID || !IsPlayerConnected(playerid))
	    {
	        ArendInfo[get_rent][aPlayerID] = INVALID_PLAYER_ID;
	        return INVALID_PLAYER_ID;
	    }
	    return ArendInfo[get_rent][aPlayerID];
	}
	return INVALID_PLAYER_ID;
}

stock TranslateText(string[])
{
    new result[128];
    for (new i = 0; i < sizeof(result); i++)
    {
        switch (string[i])
        {
            case 'а': result[i] = 'a';
            case 'А': result[i] = 'A';
            case 'б': result[i] = '—';
            case 'Б': result[i] = 'Ђ';
            case 'в': result[i] = 'ў';
            case 'В': result[i] = '‹';
            case 'г': result[i] = '™';
            case 'Г': result[i] = '‚';
            case 'д': result[i] = 'љ';
            case 'Д': result[i] = 'ѓ';
            case 'е': result[i] = 'e';
            case 'Е': result[i] = 'E';
            case 'ё': result[i] = 'e';
            case 'Ё': result[i] = 'E';
            case 'ж': result[i] = '›';
            case 'Ж': result[i] = '„';
            case 'з': result[i] = 'џ';
            case 'З': result[i] = '€';
            case 'и': result[i] = 'њ';
            case 'И': result[i] = '…';
            case 'й': result[i] = 'ќ';
            case 'Й': result[i] = '…';
            case 'к': result[i] = 'k';
            case 'К': result[i] = 'K';
            case 'л': result[i] = 'ћ';
            case 'Л': result[i] = '‡';
            case 'м': result[i] = 'Ї';
            case 'М': result[i] = 'M';
            case 'н': result[i] = '®';
            case 'Н': result[i] = ' ';
            case 'о': result[i] = 'o';
            case 'О': result[i] = 'O';
            case 'п': result[i] = 'Ј';
            case 'П': result[i] = 'Њ';
            case 'р': result[i] = 'p';
            case 'Р': result[i] = 'P';
            case 'с': result[i] = 'c';
            case 'С': result[i] = 'C';
            case 'т': result[i] = '¦';
            case 'Т': result[i] = 'Џ';
            case 'у': result[i] = 'y';
            case 'У': result[i] = 'Y';
            case 'ф': result[i] = '~';
            case 'Ф': result[i] = 'Ѓ';
            case 'х': result[i] = 'x';
            case 'Х': result[i] = 'X';
            case 'ц': result[i] = '*';
            case 'Ц': result[i] = '‰';
            case 'ч': result[i] = '¤';
            case 'Ч': result[i] = 'Ќ';
            case 'ш': result[i] = 'Ґ';
            case 'Ш': result[i] = 'Ћ';
            case 'щ': result[i] = 'Ў';
            case 'Щ': result[i] = 'Љ';
            case 'ь': result[i] = '©';
            case 'Ь': result[i] = '’';
            case 'ъ': result[i] = 'ђ';
            case 'Ъ': result[i] = '§';
            case 'ы': result[i] = 'Ё';
            case 'Ы': result[i] = '‘';
            case 'э': result[i] = 'Є';
            case 'Э': result[i] = '“';
            case 'ю': result[i] = '«';
            case 'Ю': result[i] = '”';
            case 'я': result[i] = '¬';
            case 'Я': result[i] = '•';
            default: result[i] = string[i];
        }
    }
    return result;
}
forward TopCharity(playerid);
public TopCharity(playerid)
{
    new rows, fields, name[MAX_PLAYER_NAME], string[59], string_dialogue[945];
    cache_get_data(rows, fields);
    strcat(string_dialogue, "{FFCC00}Ник игрока\t\t{FFCC00}Пожертвовано\n");
    if(rows < 1) return 1;
    for(new i; i < rows; i++)
    {
        if(cache_get_row_int(i, 52, dbHandle) < 1 || cache_get_row_int(i, 6, dbHandle) >= 1) continue;
        cache_get_row(i, 1, name, dbHandle, MAX_PLAYER_NAME);
        format(string, sizeof(string), "{FFFFFF}%s\t\t{63BD4E}%d рублей\n", name, cache_get_row_int(i, 52, dbHandle));
        strcat(string_dialogue, string);
    }
    ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_LIST, "{FFCC00}Самые щедрые игроки", string_dialogue, "Закрыть", "");
	return 1;
}

stock GetMaxSeat(modelid)
{
	switch(modelid)
	{
		case 596..598, 427, 490: return 4;
		case 599, 497, 528: return 2;
	}
	return -1;
}

stock CategoryVeh(carid)
{
    if(carid >= Category[0] && carid <= Category[1]) return true;
	return false;
}

forward OnPlayerHistoryName(playerid);
public OnPlayerHistoryName(playerid)
{
    if(cache_get_row_count(dbHandle) > 0)
    {
		new string[128];
		new idacca = cache_get_row_int(0, 0, dbHandle);
		format(string, sizeof(string), "SELECT * FROM `historyname` WHERE `idacca` = '%d' ORDER BY `id` DESC LIMIT 10", idacca);
		mysql_tquery(dbHandle, string, "OnPlayerHistoryName2", "d", playerid);
    }
    else SendClientMessage(playerid, COLOR_RED, "Игрок с таким именем не найден");
	return 1;
}

forward OnPlayerHistoryName2(playerid);
public OnPlayerHistoryName2(playerid)
{
	new rows, fields;
    cache_get_data(rows, fields);
	if(rows)
	{
	    new nickname[MAX_PLAYER_NAME], string[350], str[35];
	    for(new i = 0; i < rows; i++)
	    {
			cache_get_row(i, 2, nickname, dbHandle);
	        format(str, sizeof(str), "{FFFFFF}%s\n", nickname);
			strcat(string, str);
	    }
	    ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_LIST, "{FFCC00}История ников", string, "Закрыть", "");
	}
	else SendClientMessage(playerid, COLOR_RED, "Данный игрок ещё не менял имя");
	return 1;
}

/*forward TimeMine(playerid);
public TimeMine(playerid)
{
    if(startjob2[playerid]==true)
    {
  		if(IsPlayerAttachedObjectSlotUsed(playerid,2)) RemovePlayerAttachedObject(playerid,2);
		if(IsPlayerAttachedObjectSlotUsed(playerid,3)) RemovePlayerAttachedObject(playerid,3);
		SetPlayerAttachedObject(playerid,2, 1458, 1, -1.034844, 1.116571, -0.065124, 76.480148, 75.781570, 280.952545, 0.575599, 0.604554, 0.624122);
		SetPlayerAttachedObject(playerid,3, 905, 1, -0.275758, 1.305280, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);
		SetPlayerCheckpoint(playerid,-25.5943,1054.8018,-84.0819-1,2.0);
    }
    return true;
}*/
stock GiveMoney(playerid, amount, bool:game_text=true)
{
	if(playerid == INVALID_PLAYER_ID) return 1;

	PI[playerid][pCash] += amount;
	GivePlayerMoney(playerid, amount);
	MysqlUpdatePlayerInt(playerid, "cash", PI[playerid][pCash]);

	STRING_GLOBAL[0] = EOS;
	/*mysql_format(dbHandle, STRING_GLOBAL, sizeof STRING_GLOBAL, "INSERT INTO money_log (uid,uip,time,money,description) VALUES (%d,'%s',%d,%d,'%s')", PI[playerid][pID], PI[playerid][pIP], gettime(), amount, description);
	mysql_query(dbHandle, STRING_GLOBAL);*/

	if(game_text && amount != 0)
	{
		STRING_GLOBAL[0] = EOS;
		format(STRING_GLOBAL, sizeof STRING_GLOBAL, "%s%d rub", amount < 0 ? ("~r~") : ("~g~+"), amount);
		GameTextForPlayer(playerid, STRING_GLOBAL, 4000, 1);
	}

	return 1;
}
stock IsPlayerUseForbiddenSoftware(playerid)
{
	static const forbidden_soft_keys[][43 + 1] =
	{
		"5E1C1837D2C54B24EAAED18C3F96D9EA51A2A481003", // RakSAMP v0.5-0.3c
		"381356A6B4349449E8F818B06B405A4FBBE9F8DDDAB", // RakSAMP v0.5-0.3d
		"354A1F8D95B8384F9C365E2D7418C7EC06CD6EE2928", // RakSAMP v0.5-0.3eR2
		"38E4952825700FE3B8476C3F72D976E7447905BA45D", // BabaShura 2.6/2.7 (0.3e)
		"45525544533450414336385A4E335637584B4F49", // ALEXDRIFT
		"4D374F3753315753544D4E5450354A59414F4746", // SERGEENKO
		"9ED058AA448CD9C4EACD949800A0DC8CFDA4DF99" // MAKAREVICH
	};

	new player_key[64 + 1];

	gpci(playerid, player_key, sizeof(player_key));

	for(new i = 0; i < sizeof(forbidden_soft_keys); i++)
	{
		if(strcmp(player_key, forbidden_soft_keys[i]) == 0)
		{
			return BanEx(playerid,"Cheat");
		}
	}

	return 0;
}
/*CMD:intporch(playerid)
{
	SetPlayerInterior(playerid, 9);
	return SetPlayerPos(playerid, -379.4313,1127.5590,2712.7734);
}*/
/*CMD:addpod(playerid)
{
	 if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	 {
	 	if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");
	 	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,  COLOR_RED, !"Вы не должны находится в машине");
	 	new Float:x, Float:y, Float:z;
	 	GetPlayerPos(playerid, x, y, z);
	 	new Cache:temp = mysql_query(dbHandle, "SELECT max(id) FROM `porch_house`", true);
	 	new flat[10];
		cache_get_row(0, 0, flat);
		new last_flat = strval(flat) + 1;
		cache_delete(temp, dbHandle);
		new Query[200];
		mysql_format(dbHandle, Query, sizeof Query, "INSERT INTO `porch` (`pEnterX`, `pEnterY`,`pEnterZ`, `pCarX`, `pCarY`, `pCarZ`, `first_flat`) VALUES ('%f','%f','%f','%f','%f','%f','%d')", x, y, z, x, y, z, last_flat);
		temp = mysql_query(dbHandle, Query, true);
		new id = cache_insert_id(dbHandle);
		cache_delete(temp, dbHandle); 
		for(new idx = 1; idx < sizeof(PorchFlatsCoord); idx++)
		{
			mysql_format(dbHandle, Query, sizeof Query, "INSERT INTO `porch_house` (`hEntrx`, `hEntry`,`hEntrz`,`hPrice`) VALUES ('%f','%f','%f','%d')", PorchFlatsCoord[idx][0],PorchFlatsCoord[idx][1],PorchFlatsCoord[idx][2], 3000);
			mysql_tquery(dbHandle, Query, "", "");
		}
		format(Query, sizeof Query, "{FFCC00}Создан подъезд № %d\n{FFFFFF}*Изменения вступят в силу после перезагрузки сервера\n{FFFFFF}Не забудьте установить координаты для спавна авто ({FFCC00}/podsetcarpos{FFFFFF})", id);
		ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFFF}Создание подъезда", Query, "Ок", "");
	 }
	 return 1;
}
CMD:podsetcarpos(playerid, params[])
{
	if(PI[playerid][pAdmin] < ADM_TOP) return SendClientMessage(playerid, COLOR_WHITE, "Данной команды не существует. Используйте /mm для просмотра списка команд.");
	{
	 	if(PI[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_RED, "[MySQL] Впишите себя в таблице admin");
	 	if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,  COLOR_RED, !"Вы должны находится в машине");
	 	new porch;
	 	if(sscanf(params, "d", porch)) return SendClientMessage(playerid,  COLOR_LIME, !"Информация: {ffffff}/podsetcarpos [Номер подъезда]");
	 	if(porch < 1 || porch > TOTALPORCH) return SendClientMessage(playerid,  COLOR_RED, !"Такого подъезда не существует");
	 	new Float:x, Float:y, Float:z, Float:a;
	 	GetVehiclePos(GetPlayerVehicleID(playerid), x, y, z);
	 	GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
	 	PorchInfo[porch][pCarX] = x;
	 	PorchInfo[porch][pCarY] = y;
	 	PorchInfo[porch][pCarZ] = z;
	 	PorchInfo[porch][pCarA] = a;
	 	new Query[144];
	 	format(Query, sizeof Query, "UPDATE `porch` SET `pCarX` = '%f', `pCarY` = '%f',`pCarZ` = '%f',`pCarA` = '%f' WHERE `id` = '%d'", x, y, z, a, porch);
	 	mysql_tquery(dbHandle, Query, "", "");
	 	SendClientMessage(playerid, COLOR_GREEN, "Координаты спавна авто установлены");
 	}
 	return 1;
}*/
forward gdonat_callback(playerid);
public gdonat_callback(playerid)
{
	new rows, fields;
    cache_get_data(rows, fields);
	new sum = cache_get_row_int(0, 0, dbHandle);
	new status = cache_get_row_int(0, 1, dbHandle);
	new did = cache_get_row_int(0, 2, dbHandle);
	new string[128];
    if(status == 1)
    {
        PI[playerid][pCredits] += sum;
        PI[playerid][pTotalCredits] += sum;
        format(string, sizeof(string), "На Ваш счёт зачислено %i кредитов. Спасибо за помощь серверу!", sum);
		SendClientMessage(playerid, COLOR_GREEN, string);
		format(string, sizeof(string), "%s /donate to %d", GetName(playerid), sum);
		SendLog("GiveCredits", string);
		format(string, sizeof(string), "UPDATE `accounts` SET credits=%d,totalcredits=%d WHERE id=%d", PI[playerid][pCredits], PI[playerid][pTotalCredits], PI[playerid][pID]);
		mysql_tquery(dbHandle, string, "", "");
		format(string, sizeof(string), "DELETE FROM `gdonate_payments` WHERE `id` = '%d'", did);
		mysql_tquery(dbHandle, string, "", "");
    }
	return 1;
}
#define BYTES_PER_CELL (cellbits / 8)

stock SendMesToAll(color, fstring[], {Float, _}:...)
{
	static const
	STATIC_ARGS = 2;
	new
	n = (numargs() - STATIC_ARGS) * BYTES_PER_CELL;
	if (n)
	{
		new
		message[145],
		arg_start,
		arg_end;
		#emit CONST.alt        fstring
		#emit LCTRL          5
		#emit ADD
		#emit STOR.S.pri        arg_start

		#emit LOAD.S.alt        n
		#emit ADD
		#emit STOR.S.pri        arg_end
		do
		{
			#emit LOAD.I
			#emit PUSH.pri
			arg_end -= BYTES_PER_CELL;
			#emit LOAD.S.pri      arg_end
		}
		while (arg_end > arg_start);

		// Push the static format parameters.
		#emit PUSH.S          fstring
		#emit PUSH.C          145
		#emit PUSH.ADR         message

		n += BYTES_PER_CELL * 3;
		#emit PUSH.S          n
		#emit SYSREQ.C         format

		n += BYTES_PER_CELL;
		#emit LCTRL          4
		#emit LOAD.S.alt        n
		#emit ADD
		#emit SCTRL          4

		return SendClientMessageToAll(color, message);
	}
	else
	{
		return SendClientMessageToAll(color, fstring);
	}
}
/**************************************************************************/
stock GetPlayerCar(playerid)
{
	new car;
	if(PI[playerid][cModel] > 0) car = PI[playerid][cModel];
	else car = 0;
	return car;
}
stock DestroyVehicleOP(vehicleid)
{
	if(!IsValidVehicle(vehicleid)) return 0;
	return (DestroyVehicle(vehicleid));
}
stock SendDalnoboyMessage(color, str[])
{
	foreach(new i: Player)
	{
		if(!PlayerLogged[i]) continue;
		if(PI[i][pJob] == 6) SCM(i, color, str);
	}
	return 1;
}
stock GetAdminRang(playerid)
{
	new text[29];
	switch(PI[playerid][pAdmin])
	{
		case 1: text = "Мл.администратор";
		case 2: text = "Мл.администратор";
		case 3: text = "Администратор";
		case 4: text = "Администратор";
		case 5: text = "Зам гл.администратора";
		case 6: text = "Главный администратор";
		case 7: text = "Руководитель";
	}
	return text;
}
stock GetRang(playerid)
{
	new text[29];
	switch(PI[playerid][pLeader])
	{
		case 1: text = "1";
		case 2: text = "2";
		case 3: text = "3";
		case 4: text = "4";
		case 5: text = "5";
		case 6: text = "6";
		case 7: text = "7";
		case 8: text = "8";
		case 9: text = "9";
		case 10: text = "10";
		case 11: text = "11";
		case 12: text = "12";
		case 13: text = "13";
		case 14: text = "14";
		case 15: text = "15";
		case 16: text = "16";
		case 17: text = "17";
		case 18: text = "18";
		case 19: text = "19";
		case 20: text = "20";
		case 21: text = "21";
		case 22: text = "22";
		case 23: text = "23";
		case 24: text = "24";
		case 25: text = "25";
		
	}
	return text;
}
stock ToolsList(playerid)
{
	ShowPlayerDialog(playerid,1456,DIALOG_STYLE_LIST,"{FFCC00}Покупка игрушек","{FFCC00}1. {ffffff}Машинка   {FFCC00}1000 рублей\n{FFCC00}2. {ffffff}Самолётик   {FFCC00}2800 рублей\n{FFCC00}3. {ffffff}Вертолётик   {FFCC00}2500 рублей\n{FFCC00}4. {ffffff}Вертолётик   {FFCC00}2600 рублей\n{FFCC00}5. {ffffff}Танчик   {FFCC00}6200 рублей\n{FFCC00}6. {ffffff}Горшок   {FFCC00}800 рублей","Купить","Отмена");
	return 1;
}
stock AptekaList(playerid)
{
	ShowPlayerDialog(playerid,1458,DIALOG_STYLE_LIST,"{FFCC00}Аптека","{FFCC00}1. {ffffff}Аптечка\t{FFCC00}1000 рублей\n{FFCC00}2. {ffffff}Маска\t{FFCC00}2000 руб.","Купить","Отмена");
	return 1;
}
stock IsAIP(text[])
{
	new numbers;
	for(new i = 0; i < strlen(text); i++) if('0' <= text[i] <= '9') if(!('0' <= text[i+1] <= '9')) numbers ++;
	if(numbers >= 4) return 1;
	return 0;
}
stock ReplaceText(text[])
{
	for(new i; i < strlen(text); i ++)
	{
	    if('0' <= text[i] <= '9') text[i] = '*';
	}
	return 1;
}
/*stock SetZhazhda(playerid, amount)
{
	if(amount > 100) PI[playerid][pZhazhda] = 100;
	else if(amount < 0) PI[playerid][pZhazhda] = 0;
	else PI[playerid][pZhazhda] = amount;
	return 1;
}
stock GiveZhazhda(playerid, amount)
{
	SetZhazhda(playerid,PI[playerid][pZhazhda] + amount);
	if(PI[playerid][pZhazhda] + amount > 100) PI[playerid][pZhazhda] = 100;
}*/
stock GiveHunger(playerid, amount)
{
	SetHunger(playerid,PI[playerid][pHunger] + amount);
	if(PI[playerid][pHunger] + amount > 100) PI[playerid][pHunger] = 100;
	Hunger(playerid, 0);
}
stock SendMuteMessage(playerid, ret = 1)
{
	new string[128];
	format(string, sizeof(string), "У Вас затычка. Узнать подробней: /time");
	SendClientMessage(playerid, COLOR_RED, string);
	return ret;
}

stock FixText(string[])
{
	new result[256];
	for(new i=0; i < 256; i++)
	{
		switch(string[i])
		{
			case 'a':result[i] = 'a';
			case 'A':result[i] = 'A';
			case 'a':result[i] = '—';
			case 'A':result[i] = '€';
			case 'a':result[i] = '?';
			case 'A':result[i] = '‹';
			case 'a':result[i] = '™';
			case 'A':result[i] = '‚';
			case 'a':result[i] = 's';
			case 'A':result[i] = '?';
			case 'a':result[i] = 'e';
			case 'A':result[i] = 'E';
			case '?':result[i] = 'e';
			case '?':result[i] = 'E';
			case '?':result[i] = '›';
			case '?':result[i] = '„';
			case 'c':result[i] = 'Y';
			case 'C':result[i] = '?';
			case 'e':result[i] = '?';
			case 'E':result[i] = '…';
			case 'e':result[i] = '?';
			case 'E':result[i] = '…';
			case 'e':result[i] = 'k';
			case 'E':result[i] = 'K';
			case 'e':result[i] = 'z';
			case 'E':result[i] = '‡';
			case 'i':result[i] = '?';
			case 'I':result[i] = 'M';
			case 'i':result[i] = '®';
			case 'I':result[i] = '*';
			case 'i':result[i] = 'o';
			case 'I':result[i] = 'O';
			case 'i':result[i] = '?';
			case 'I':result[i] = '?';
			case '?':result[i] = 'p';
			case '?':result[i] = 'P';
			case 'n':result[i] = 'c';
			case 'N':result[i] = 'C';
			case 'o':result[i] = '¦';
			case 'O':result[i] = '?';
			case 'o':result[i] = 'y';
			case 'O':result[i] = 'Y';
			case 'o':result[i] = '?';
			case 'O':result[i] = '?';
			case 'o':result[i] = 'x';
			case 'O':result[i] = 'X';
			case 'o':result[i] = '*';
			case 'O':result[i] = '‰';
			case '?':result[i] = '¤';
			case '?':result[i] = '?';
			case 'o':result[i] = '?';
			case 'O':result[i] = 'Z';
			case 'u':result[i] = '?';
			case 'U':result[i] = 'S';
			case 'u':result[i] = '©';
			case 'U':result[i] = '’';
			case 'u':result[i] = '?';
			case 'U':result[i] = '§';
			case 'u':result[i] = '?';
			case 'U':result[i] = '‘';
			case 'y':result[i] = '?';
			case 'Y':result[i] = '“';
			case '?':result[i] = '«';
			case '?':result[i] = '”';
			case 'y':result[i] = '¬';
			case '?':result[i] = '•';
			default:result[i]=string[i];
		}
	}
	return result;
}
//==============================================================================
stock ShowPlayerDialogTeleportList(playerid)
{
	new list_text[30 * (sizeof teleport_list)];
	new dest[30];

	for(new i; i < sizeof teleport_list; i ++)
	{
		format(dest, sizeof dest, "%s\n", teleport_list[i][t_name]);
		strcat(list_text, dest);
	}


	return
		ShowPlayerDialog
		(
			playerid, DIALOG_TELEPORT_LIST, DIALOG_STYLE_LIST,
			"{FFCC00}Телепорт",
			list_text,
			"Выбрать", "Закрыть"
		);
}
//==============================================================================
stock ShowPlayerMenuDialog(playerid)
{
	ShowPlayerDialog
	(
		playerid, DIALOG_MENU, DIALOG_STYLE_LIST,
		"{FFCC00}Меню игрока",
		"{FFCC00}1. {ffffff}Статистика\n\
		{FFCC00}2. {ffffff}Команды сервера\n\
		{FFCC00}3. {ffffff}Защита аккаунта\n\
		{FFCC00}4. {ffffff}Вопросы/жалобы на игроков\n\
		{FFCC00}5. {ffffff}Правила сервера\n\
		{FFCC00}6. {ffffff}Изменение ника\n\
		{FFCC00}7. {ffffff}Персональные настройки\n\
		{FFCC00}8. {ffffff}GPS (важные места)\n\
		{FFCC00}9. {ffffff}Радио\n\
		{FFCC00}10. {ffffff}Дополнительные возможности",
		"Выбрать", "Закрыть"
	);

	return 1;
}
//==============================================================================
stock ShowPlayerDialogOrgList(playerid)
{
	return
		ShowPlayerDialog
		(
			playerid, DIALOG_CMDS_ORGANIZATIONS_LIST, DIALOG_STYLE_LIST,
			"{FFCC00}Команды огранизаций",
			"{FFCC00}1. {ffffff}Правительство\n\
			{FFCC00}2. {ffffff}Патрульно-постовая служба (ППС)\n\
			{FFCC00}3. {ffffff}Центральная Больница\n\
			{FFCC00}4. {ffffff}Армия\n\
			{FFCC00}5. {ffffff}Средства массовой информации (СМИ)\n\
			{FFCC00}6. {ffffff}Организованная преступная группа\n\
			{FFCC00}7. {ffffff}Дорожно-патрульная служба (ДПС)\n\
			{FFCC00}8. {ffffff}Федеральная служба безопасности (ФСБ)\n\
			{FFCC00}9. {ffffff}Общие команды организаций\n\
			{FFCC00}7. {ffffff}Команды лидеров/заместителей организаций\n\
			{FFCC00}8. {ffffff}Команды мафий",
			"Выбрать", "Назад"
		);
}

stock ShowPlayerDialogWorksCmds(playerid)
{
	return
		ShowPlayerDialog
		(
			playerid, DIALOG_CMDS_WORKS, DIALOG_STYLE_MSGBOX,
			"{FFCC00}Команды для работы",
			"\n{ffffff}Команды: {FFCC00}Работ{ffffff}\n\n\
			/calling - посмотреть список вызовов (Механик)\n\
			/repair [id игрока] [стоимость] - починить авто игроку (Механик)\n\
			/jskill - посмотреть свои рабочие навыки (Дальнобойщик)\n\
			/end - окончить работу (Уборщик улиц)\n\
			",
			"Назад", "Закрыть"
		);
}

stock ShowPlayerDialogFamilyCmds(playerid)
{
	return
		ShowPlayerDialog
		(
			playerid, DIALOG_CMDS_PROPERTY, DIALOG_STYLE_MSGBOX,
			"{FFCC00}Команды семьи",
			"\n{FFFFFF}Команды: {FFCC00}Семья{FFFFFF}\n\n\
			/fmenu - информация о семье\n\
			/fo - посмотреть список онлайн семьи\n\
			/fhlock - закрыть или открыть особняк\n\
			/sellfhouse - продать особняк государству\n\
			/buyfbiz - купить семейный бизнес\n\
			/foff - посмотреть полный список членов семьи\n\
			/frang [id] [1/2] - изменить игроку ранг в семье\n\
			/funinvite [id] [причина] - уволить игрока из семьи\n\
			/funinviteoff [никнейм] - уволить игрока из семьи оффлайн\n\
			/fleave - покинуть семью по СЖ\n\
			/finvite [id] - принять игрока в семью \n\
			/use - управление шкафом дома\n\
			/rlock - закрыть/открыть номер в отеле\n\
			/klock - закрыть/открыть квартиру",
			"Назад", "Закрыть"
		);
}
//==============================================================================
stock ShowPlayerDialogPropertyCmds(playerid)
{
	return
		ShowPlayerDialog
		(
			playerid, DIALOG_CMDS_PROPERTY, DIALOG_STYLE_MSGBOX,
			"{FFCC00}Команды недвижимости",
			"\n{ffffff}Команды недвижимости: {FFCC00}Транспорт, дом, бизнес{ffffff}\n\n\
			/rshower - починить душ\n\
			/lock [1] - открыть/закрыть личный транспорт\n\
			/gpsveh - поиск личного транспорта\n\
			/sellcar - продать транспорт государству\n\
			/sellmycar [id] [цена] - продать транспорт игроку\n\
			/buybiz - купить бизнес\n\
			/business - управление бизнесом\n\
			/sellmybusiness [id] [цена] - продать бизнес игроку\n\
			/sellhouse [id] [цена] - продать дом государству/игроку\n\
			/sellmyhouse [id] [цена] - продать дом игроку\n\
			/changehouse [id] [цена] - обменяться домами\n\
			/hlock - закрыть/открыть дом\n\
			/home - управление домом\n\
			/hupg - улучшение дома\n\
			/use - управление сейфом дома\n\
			/gpsbiz - Отметить свой бизнес на карте",
			"Назад", "Закрыть"
		);
}

stock ShowPlayerDialogCommunCmds(playerid)
{
	return
		ShowPlayerDialog
		(
			playerid, DIALOG_CMDS_COMMYNUCATION, DIALOG_STYLE_MSGBOX,
			"{FFCC00}Команды общения",
			"\n{ffffff}Команды: {FFCC00}Общение{ffffff}\n\n\
			/rb [текст] - написать в ООС чат организации\n\
			/r [текст] - написать в РП чат организации\n\
			/db [текст] - написать в ООС чат департамента\n\
			/d [текст] - написать в РП чат департамента\n\
			/gov [текст] - написать в гос новости\n\
			/ad [текст] - подать объявление\n\
			/me [текст] - действие игрока от 1 лица\n\
			/try [текст] - действие игрока на удачу\n\
			/do [текст] - действие игрока от 3 лица\n\
			/b [текст] - написать в ООС чат\n\
			/s [текст] - крикнуть в чат\n\
			/call [номер телефона] - позвонить\n\
			/p - взять трубку\n\
			/h - положить трубку\n\
			/sms [номер телефона] [текст] - написать смс игроку\n\
			/togphone - выключить телефон",
			"Назад", "Закрыть"
		);
}

stock ShowPlayerDialogRadio(playerid)
{
	return
		ShowPlayerDialog
		(
			playerid, DIALOG_RADIO, DIALOG_STYLE_LIST,
			"{FFCC00}Radio",
			"{FFCC00}1.{FFFFFF} Подключиться к радио\n\
			{FFCC00}2.{FFFFFF} Информация о радио",
			"Назад", "Закрыть"
		);
}
stock ShowPlayerDialogCommands(playerid)
{
	return
		ShowPlayerDialog
		(
			playerid, DIALOG_MENU_CMD, DIALOG_STYLE_LIST,
			"{FFCC00}Команды сервера",
			"{FFCC00}1. {ffffff}Команды организаций\n\
			{FFCC00}2. {ffffff}Команды работ\n\
			{FFCC00}3. {ffffff}Команды семьи\n\
			{FFCC00}4. {ffffff}Команды недвижимости\n\
			{FFCC00}5. {ffffff}Команды общения\n\
			{FFCC00}6. {ffffff}Команды остальные",
			"Выбрать", "Назад"
		);
}
stock ShowPlayerDialogSecurity(playerid)
{
	/*ShowPlayerDialog
	(
		playerid, DIALOG_MENU_SECURITY, DIALOG_STYLE_LIST,
		"{FFCC00}Настройки безопасности",
		"{FFCC00}1.{ffffff} Сменить пароль\n\
		{FFCC00}2.{ffffff} Установить защитный код\n\
		{FFCC00}3.{ffffff} Двухэтапная авторизация",
		"Далее", "Отмена"
	);
	return 1;*/
	return PlayerSecurity(playerid);
}

stock ShowPlayerDialogOtherCmds(playerid)
{
	return
		ShowPlayerDialog
		(
			playerid, DIALOG_CMDS_OTHER, DIALOG_STYLE_MSGBOX,
			"{FFCC00}Команды остальные",
			"\n{ffffff}Команды: {FFCC00}Остальные{ffffff}\n\n\
			/guncolor - взять скин оружия\n\
			/myrefs - посмотреть список рефералов\n\
			/pack - заказать наркотики\n\
			/blow - запустить перотехнические изделия\n\
			/mn - меню сервера\n\
			/paintlist - посмотреть список участников матча по пейнтболу\n\
			/drugs [количество (1-2)] - использовать наркотики\n\
			/pepsi - выпить баночку напитка\n\
			/drink - выпить бутылку пива\n\
			/en - запустить двигатель в транспорте\n\
			/smoke - начать курить сигарету\n\
			/eat - съесть пачку чипсов\n\
			/id [никнейм] - посмотреть id игрока по никнейму\n\
			/radio - открыть меню радио сервера\n\
			/need - посмотреть свои нужды\n\
			/fstyle - использовать изученные стили боя\n\
			/fight [id] [сумма] - предложить бой игроку\n\
			/skill [id] - предложить посмотреть свои навыки оружия\n\
			/gotomp - телепортироваться на мероприятие\n\
			/time - посмотреть время\n\
			/pass [id] - показать паспорт\n\
			/lic [id] - показать лицензии\n\
			/leaders - список лидеров онлайн\n\
			/eject [id] - выкинуть игрока из транспорта\n\
			/fill - заправить транспорт на АЗС\n\
			/carpass [id] - показать документы на транспортное средство\n\
			/tune - поставить тюнинг на транспорт в СТО\n\
			/gps - навигатор по серверу\n\
			/pay [id] - передать деньги игроку\n\
			/dice [id] [сумма] - предложить игроку игру в кости\n\
			/anim [номер анимации] - анимация\n\
			/mask - надеть маску\n\
			/healme - использовать аптечку\n\
			/tickets - посмотреть список неоплаченных штрафов\n\
			/buyk - купить канистру на АЗС\n\
			/donate - посмотреть донат\n\
			/hi - пожать руку, если человек находится рядом. Помахать рукой,\n\
			если человек находится чуть дальше (~5-7 метров от Вас)\n\
			/flowers - передать цветы, если человек находится рядом. Помахать рукой,\n\
			если человек находится чуть дальше (~5-7 метров от Вас)\n\
			/selfie - сделать селфи\n\
			/huninvite - выселить игрока\n\
			/car - открыть меню выбора транспорта\n\
			/gpsavto - найти свой транспорт\n\
			/mytk - посмотреть свою трудовую книжку\n\
			/showtk [id] - показать трудовую книжку\n\
			/sellsim [id] [сумма] - продать SIM-карту игроку\n\
			/fish - рыбалка\n\
			/craftfood - приготовить еду\n\
			/eatfish - съесть готовую рыбу\n\
			/rshower - починить душ\n\
			/pov - включить вид от 1-го лица\n\
			/trunk - открыть капот/багажник\n\
			/tmenu - меню багажника\n\
			/doc - показать удостоверение игроку\n\
			/recipes - посмтреть свои рецепты\n\
			/drugsoff - избавиться от наркотиков",
			"Назад", "Закрыть"
		);
}

stock ShowPlayerConnectToRadio(playerid)
{
	SCM(playerid, COLOR_BLUE, "В разработке");
	return 1;
}

stock ShowPlayerRadioInfo(playerid)
{
	ShowPlayerDialog
	(
		playerid, DIALOG_MENU_SECURITY, DIALOG_STYLE_MSGBOX,
		"{FFCC00}Информация",
		"{FFFFFF}Слушателей сейчас: 6 чел\n\
		ВКонтакте: "VKONTAKTE_RADIO"",
		"Закрыть", ""
	);
	return 1;
}

stock ShowPlayerDialogHelpAdm(playerid)
{
	ShowPlayerDialog
	(
		playerid, DIALOG_MENU_HELP_ADM, DIALOG_STYLE_LIST,
		"{FFCC00}Связь с администрацией",
		"{FFCC00}1. {ffffff}Вопрос\n\
		{FFCC00}2. {ffffff}Жалоба",
		"Выбрать", "Назад"
	);
	return 1;
}
stock ShowPlayerDialogRuleServer(playerid)
{
	ShowDialogRules_GAME_1(playerid);
	return 1;
}
stock ShowPlayerDialogSettings(playerid)
{
	new fmt_dialog[40];

	format
	(
		fmt_dialog, sizeof fmt_dialog,
		"1. %s ники\n\
		2. Очистить чат",
		(player_show_name_tags[playerid] == true) ? ("Выключить") : ("Включить")
	);

	ShowPlayerDialog
	(
		playerid, DIALOG_MENU_SETTINGS, DIALOG_STYLE_LIST,
		"{FFCC00}Личные настройки",
		fmt_dialog,
		"Далее", "Назад"
	);
	return 1;
}
stock ShowPlayerDialogChangeNonRpName(playerid)
{
	ShowPlayerDialog
	(
		playerid, DIALOG_MENU_CHANGE_NAME, DIALOG_STYLE_INPUT,
		"{FFCC00}Изменение имени",
		"{FFFFFF}Вы можете изменить имя своего персонажа, если оно не соответствует RP правилам\n"\
		"Во всех остальных случаях смена имени осуществляется в /menu > Дополнительные средства\n\n"\
		"RP ник имеет формат Имя_Фамилия. Например: Andrey_Ivanov, Maria_Petrova, Steve_Jobs, Amanda_Flores и т.п\n"\
		"Введите новое имя в поле ниже. Допустимы только латинские символы:",
		"Изменить", "Закрыть"
	);

	return 1;
}
stock ShowPlayerDialogEditList(playerid)
{
	new fmt_msg[400], fmt_msg1[10+3+MAX_PLAYER_NAME+40], status[40];

	for(new i = 0; i < 15; i++)
	{
		switch(edit_list[i][aStatus])
		{
			case 0: status = "";
			case 1: status = "{ffffff}[{FFCC00}Проверяется{ffffff}]";
			case 2: status = "{ffffff}[{FFCC00}Проверено{ffffff}]";
		}
		format(fmt_msg1, sizeof fmt_msg1, "%d. %s %s\n", i+1, edit_list[i][aName], status);
		strcat(fmt_msg, fmt_msg1);
	}

	ShowPlayerDialog
	(
		playerid, DIALOG_SHOW_EDIT, DIALOG_STYLE_LIST,
		"Объявляния",
		fmt_msg,
		"Ок", "Отмена"
	);

	return 1;
}
forward minuteupdate();
public minuteupdate()
{
	new hour, minute, second;
	gettime(hour, minute, second);
	
	foreach(new playerid: Player)
	for(new i = 0; i < 15; i++)
	{
		if(edit_list[i][aStatus] == 2)
		{
		    new string[128];
			format(string, sizeof(string), "%s | Отправил: %s (тел. %i)", edit_list[i][aText], edit_list[i][aName], PI[playerid][pPhoneNumber]);
			SendClientMessageToAll(0x99CC00AA, string);
			format(string, sizeof(string), "   Объявление проверил %s %s.",Fraction_Rang[PI[playerid][pMember]][PI[playerid][pRank]], edit_list[i][aEditName], playerid);
			SendClientMessageToAll(0x339900AA, string);

			edit_list[i][aEditName] = EOS;
			edit_list[i][aName] = EOS;
			edit_list[i][aPhone] = EOS;
			edit_list[i][aStatus] = 0;
			edit_list[i][aText] = EOS;
		}

	}
	
	/*if(minute == 5 || minute == 15 || minute == 30 || minute == 45 || minute == 59)
	{
        foreach(new playerid: Player)
        {
 			if(PI[playerid][pHunger] -5 > 0)
			{
                PI[playerid][pHunger] -= 5;
			}
		    if(PI[playerid][pHunger] <= 30)
			{
			    SendClientMessage(playerid, 0xff7963FF, "Вы проголодались! Посетите столовую или купите чипсы в 24/7. Узнать состояние персонажа: /need");
			    PlayerPlaySound(playerid, 40403, 0.0, 0.0, 0.0);
			}
 			if(PI[playerid][pZhazhda] -3 > 0)
			{
                PI[playerid][pZhazhda] -= 3;
			}
			if(PI[playerid][pZhazhda] <= 30)
			{
			    SendClientMessage(playerid, 0xff7963FF, "Вы хотите пить! Посетите столовую или купите пепси в 24/7. Узнать состояние персонажа: /need");
			}
			if(PI[playerid][pHYGIENE] -1 > 0)
			{
                PI[playerid][pHYGIENE] --;
			}
			if(PI[playerid][pHYGIENE] <= 30)
			{
				new fmt_str[128];
				SetPlayerChatBubble(playerid, "Плохо пахнет", COLOR_PURPLE, 25.0, 5000);

				format(fmt_str, sizeof fmt_str, "Плохо пахнет (( %s ))", PI[playerid][pName]);
			}
			UpdateNeeds(playerid);
		}
	}*/
	if(hour == 00 && minute == 00)
	{
		for(new houseid = 1; houseid <= TOTALHOUSE; houseid++)
		{
			if(!strcmp("None", HouseInfo[houseid][hOwner], true)) continue;
			if(HouseInfo[houseid][hOplata] < 1)
			{
				new targetid = GetPlayerID(HouseInfo[houseid][hOwner]);
				if(targetid != INVALID_PLAYER_ID)
				{
					PI[targetid][pBank] += HouseInfo[houseid][hBuyPrice];
					PI[targetid][pSpawnChange] = 0;
					SendClientMessage(targetid, COLOR_RED, "Вы были выселены из дома за неуплату");
					SendClientMessage(targetid, COLOR_RED, "На Ваш банковский счет возвращена стоимость дома по гос-ву");
					if(PI[targetid][PlayerCarID] != INVALID_VEHICLE_ID)
					{
						DestroyVehicle(PI[targetid][PlayerCarID]);
						PI[targetid][PlayerCarID] = INVALID_VEHICLE_ID;
					}
				}
				else
				{
					strmid(HouseInfo[houseid][hOwner], "None", 0, strlen("None"), MAX_PLAYER_NAME);
					format(query, sizeof(query), "UPDATE `house` SET hOwner='%s',hOplata=%d,buyprice=%d,hLock=%d WHERE id=%d",
					HouseInfo[houseid][hOwner],HouseInfo[houseid][hOplata],HouseInfo[houseid][hBuyPrice],HouseInfo[houseid][hLock],houseid);
					mysql_tquery(dbHandle, query, "", "");
					UpdateHouse(houseid);
				}
				MysqlUpdatePlayerInt(targetid, "spawnchange", PI[targetid][pSpawnChange]);
				strmid(HouseInfo[houseid][hOwner], "None", 0, strlen("None"), MAX_PLAYER_NAME);
				format(query, sizeof(query), "UPDATE `house` SET hOwner='%s',hOplata=%d,buyprice=%d,hLock=%d WHERE id=%d",
				HouseInfo[houseid][hOwner],HouseInfo[houseid][hOplata],HouseInfo[houseid][hBuyPrice],HouseInfo[houseid][hLock],houseid);
				mysql_tquery(dbHandle, query, "", "");
				UpdateHouse(houseid);
			}
			else
			{
				HouseInfo[houseid][hOplata] -= 1;
				MysqlUpdateHouseInt(houseid, "hOplata", HouseInfo[houseid][hOplata]);
			}
		}
		for(new entranceid = TOTALENTRANCE; entranceid > 0; entranceid --)
		{
			for(new roomid = 22; roomid > 0; roomid --)
			{
				if(!strcmp("None", g_rooms[entranceid][roomid][ER_OWNER], true)) continue;

				if(GetRoomData(entranceid, roomid, ER_PAY) < 1)
				{
					new targetid = GetPlayerID(g_rooms[entranceid][roomid][ER_OWNER]);
					if(targetid != INVALID_PLAYER_ID)
					{
						SendClientMessage(targetid, COLOR_YELLOW, "Ваша квартира была продана за неуплату");

						PI[targetid][P_ENTRANCE] =
						PI[targetid][P_ROOM] = -1;

						MysqlUpdatePlayerInt(targetid, "entrance", PI[targetid][P_ENTRANCE]);
						MysqlUpdatePlayerInt(targetid, "room", PI[targetid][P_ROOM]);
					}

					STRING_GLOBAL[0] = EOS;
					format(STRING_GLOBAL, sizeof STRING_GLOBAL, "UPDATE accounts SET entrance=-1, room=-1 WHERE name='%s'", g_rooms[entranceid][roomid][ER_OWNER]);
					mysql_query(dbHandle, STRING_GLOBAL);

					g_rooms[entranceid][roomid][ER_PAY] = 1;

					g_rooms[entranceid][roomid][ER_OWNER] = EOS;
					strcat(g_rooms[entranceid][roomid][ER_OWNER], "None");
				}
				else
				{
					g_rooms[entranceid][roomid][ER_PAY] --;
				}

				STRING_GLOBAL[0] = EOS;
				format(STRING_GLOBAL, sizeof STRING_GLOBAL, "UPDATE rooms SET owner='%s', pay=%d WHERE id=%d", g_rooms[entranceid][roomid][ER_OWNER], g_rooms[entranceid][roomid][ER_PAY], g_rooms[entranceid][roomid][ER_SQL_ID]);
				mysql_query(dbHandle, STRING_GLOBAL);
			}

			UpdateEntrance(entranceid);
		}
	}
	return 1;
}
/*stock UpdateNeeds(playerid)
{
	static const fmt_query[] = "UPDATE `accounts` SET `needs` = '%d, %d, %d, %d' WHERE `id` = '%d'";
	format
	(
	    query, sizeof(query), fmt_query,
		PI[playerid][pHunger],
		PI[playerid][pZhazhda],
		PI[playerid][pTualet],
		PI[playerid][pHYGIENE]
	);
	mysql_query(dbHandle, query);
    return 1;
}*/
/*stock GetPlayerRankName(playerid)
{
	new rang = PI[playerid][pRank];

	if(!(1 <= rang <= 15))
		rang = 1;

	return ranknames[ PI[playerid][pMember] ][ rang ];
}*/
stock ShowPlayerDialogDonateList(playerid)
{
	new count;
	new fmt_str[80];
	new text[(sizeof fmt_str) * 10];
	
	for(new i; i < 10; i++)
	{
		dialog_listitem_values[playerid][count] = i;
		count ++;
		
		format(fmt_str, sizeof fmt_str, "{FFCC00}%d. {ffffff}%s\n", i+1, donate_list[i][donate_name]);
		strcat(text, fmt_str);
	}
	
	ShowPlayerDialog
	(
		playerid, DIALOG_MENU_DONATE, DIALOG_STYLE_LIST,
		"{FFCC00}Донат меню",
		text,
		"Выбрать", "Отмена"
	);
	
	return 1;
}
stock SetPlayerSkillss(playerid)
{
    SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL_SILENCED, PI[playerid][pSkill]*10);
    SetPlayerSkillLevel(playerid, WEAPONSKILL_DESERT_EAGLE, PI[playerid][pSkill][1]*10);
    SetPlayerSkillLevel(playerid, WEAPONSKILL_SHOTGUN, PI[playerid][pSkill][2]*10);
    SetPlayerSkillLevel(playerid, WEAPONSKILL_MP5, PI[playerid][pSkill][3]*10);
    SetPlayerSkillLevel(playerid, WEAPONSKILL_AK47, PI[playerid][pSkill][4]*10);
    SetPlayerSkillLevel(playerid, WEAPONSKILL_M4, PI[playerid][pSkill][5]*10);
    return 1;
}
stock SetPlayerSkills(playerid)
{
	SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL_SILENCED, 		PI[playerid][pGunSkill]*10);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_DESERT_EAGLE, 		PI[playerid][pGunSkill][1]*10);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SHOTGUN, 				PI[playerid][pGunSkill][2]*10);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_MP5, 					PI[playerid][pGunSkill][3]*10);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_AK47, 				PI[playerid][pGunSkill][4]*10);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_M4, 					PI[playerid][pGunSkill][5]*10);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 				PI[playerid][pGunSkill][6]*10);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_MICRO_UZI, 			PI[playerid][pGunSkill][7]*10);
	return 1;
}

stock GetPlayerJobkName(playerid)
{
	return Job_Names[ PI[playerid][pJob] ];
}
stock SendMessageToJob(to_job, message[], color = -1)
{
	foreach(new i: Player)
	{
		if(PI[i][pJob] == to_job) SendClientMessage(i, color, message);
	}
	return 1;
}
stock ApplyAnimationEx(playerid, animlib[], animname[], Float:fDelta, loop, lockx, locky, freeze, time, forcesync, anim_type=USE_ANIM_TYPE_NONE)
{
	PI[playerid][pP_USE_ANIM_TYPE] = anim_type;
	ApplyAnimationEx(playerid, animlib, animname, fDelta, loop, lockx, locky, freeze, time, forcesync);

	return 0;
}
forward ClearPlayerChatAnim(playerid);
public ClearPlayerChatAnim(playerid)
{
//	ClearPlayerAnim(playerid);
	PI[playerid][pP_USE_ANIM_TYPE] = USE_ANIM_TYPE_NONE;
	return 0;
}
stock GetNearestVehicleID(playerid, Float:dist = 5.0)
{
	new Float: x, Float: y, Float: z;

	GetPlayerPos(playerid, x, y, z);
	for(new i = 1; i < MAX_VEHICLES; i ++)
	{
		if(!IsValidVehicle(i)) continue;
		else if(!IsVehicleStreamedIn(i, playerid)) continue;
		else if(GetVehicleDistanceFromPoint(i, x, y, z) > dist) continue;

		return i;
	}

	return -1;
}
stock ShowDialogSelectRecipe(playerid)
{
	ShowPlayerDialog
	(
		playerid, DIALOG_SELECT_RECIPE, DIALOG_STYLE_LIST,
		"{FFCC00}Рецепты",
		"{FFCC00}1. {FFFFFF}Пистолеты\n"\
		"{FFCC00}2. {FFFFFF}Пистолеты-пулемёты\n"\
		"{FFCC00}3. {FFFFFF}Дробовики\n"\
		"{FFCC00}4. {FFFFFF}Штурмовые винтовки\n"\
		"{FFCC00}5. {FFFFFF}Снайперские винтовки\n"\
		"{FFCC00}6. {FFFFFF}Гранаты",
		"Выбрать", "Отмена"
    );
    return 1;
}

stock ShowDialogBuyRecipeGuns(playerid)
{
	ShowPlayerDialog
	(
		playerid, DIALOG_BUY_RECIPE_GUNS, DIALOG_STYLE_LIST,
		"{FFCC00}Пистолеты\n",\
		"{FFCC00}1. {FFFFFF}9mm - 20 000 рублей\n"\
		"{FFCC00}2. {FFFFFF}SDPistol - 40 000 рублей\n"\
		"{FFCC00}3. {FFFFFF}Дигл - 100 000 рублей",
		"Выбрать", "Назад"
    );
	return 1;
}

stock ShowDialogBuyRecipeGuns_2(playerid)
{
	ShowPlayerDialog
	(
		playerid, DIALOG_BUY_RECIPE_GUNS_2, DIALOG_STYLE_LIST,
		"{FFCC00}Пистолеты-пулемёты\n",\
		"{FFCC00}1. {FFFFFF}ТЕК-9 - 50 000 рублей\n"\
		"{FFCC00}2. {FFFFFF}УЗИ - 75 000 рублей\n"\
		"{FFCC00}3. {FFFFFF}МП5 - 120 000 рублей",
		"Выбрать", "Назад"
    );
    return 1;
}

stock ShowDialogBuyRecipeGuns_3(playerid)
{
	ShowPlayerDialog
	(
		playerid, DIALOG_BUY_RECIPE_GUNS_3, DIALOG_STYLE_LIST,
		"{FFCC00}Дробовики\n",\
		"{FFCC00}1. {FFFFFF}Шотган - 120 000 рублей\n"\
		"{FFCC00}2. {FFFFFF}Обрез - 150 000 рублей\n"\
		"{FFCC00}3. {FFFFFF}Боевой дробовик - 200 000 рублей",
		"Выбрать", "Назад"
    );
    return 1;
}

stock ShowDialogBuyRecipeGuns_4(playerid)
{
	ShowPlayerDialog
	(
		playerid, DIALOG_BUY_RECIPE_GUNS_5, DIALOG_STYLE_LIST,
		"{FFCC00}Штурмовые винтовки\n",\
		"{FFCC00}1. {FFFFFF}АК-47 - 200 000 рублей\n"\
		"{FFCC00}2. {FFFFFF}М4 - 300 000 рублей",
		"Выбрать", "Назад"
    );
    return 1;
}

stock ShowDialogBuyRecipeGuns_5(playerid)
{
	ShowPlayerDialog
	(
		playerid, DIALOG_BUY_RECIPE_GUNS_5, DIALOG_STYLE_LIST,
		"{FFCC00}Снайперские винтовки\n",\
		"{FFCC00}1. {FFFFFF}Contry Rifle - 150 000 рублей\n"\
		"{FFCC00}2. {FFFFFF}Sniper Rifle - 300 000 рублей",
		"Выбрать", "Назад"
    );
    return 1;
}
stock ShowDialogBuyRecipeGuns_6(playerid)
{
	ShowPlayerDialog
	(
		playerid, DIALOG_BUY_RECIPE_GUNS_6, DIALOG_STYLE_LIST,
		"{FFCC00}Гранаты\n",\
		"{FFCC00}1. {FFFFFF}Дымовая граната - 150 000 рублей\n"\
		"{FFCC00}2. {FFFFFF}Коктейль молотова - 300 000 рублей\n"\
		"{FFCC00}3. {FFFFFF}Взрывчатая граната - 600 000 рублей",
		"Выбрать", "Назад"
    );
    return 1;
}
stock PlayerCheckRecipe(playerid, listitem)
{
	switch(listitem)
	{
		case 0:
		{
			if(PI[playerid][pRECIPE_9MM] > 0)
			{
				return SendClientMessage(playerid, COLOR_RED, "У Вас нет этого рецепта");
			}
		}
		case 1:
		{
			if(PI[playerid][pRECIPE_SDPISTOL] > 0)
			{
                return SendClientMessage(playerid, COLOR_RED, "У Вас нет этого рецепта");
			}
		}
		case 2:
		{
			if(PI[playerid][pRECIPE_DEAGLE] > 0)
			{
                return SendClientMessage(playerid, COLOR_RED, "У Вас нет этого рецепта");
			}
		}
		case 3:
		{
			if(PI[playerid][pRECIPE_TEK9] > 0)
			{
                return SendClientMessage(playerid, COLOR_RED, "У Вас нет этого рецепта");
			}
		}
		case 4:
		{
			if(PI[playerid][pRECIPE_UZY] > 0)
			{
                return SendClientMessage(playerid, COLOR_RED, "У Вас нет этого рецепта");
			}
		}
		case 5:
		{
			if(PI[playerid][pRECIPE_MP5] > 0)
			{
                return SendClientMessage(playerid, COLOR_RED, "У Вас нет этого рецепта");
			}
		}
		case 6:
		{
			if(PI[playerid][pRECIPE_SHOTGUN] > 0)
			{
                return SendClientMessage(playerid, COLOR_RED, "У Вас нет этого рецепта");
			}
		}
		case 7:
		{
			if(PI[playerid][pRECIPE_SHOTGUN] > 0)
			{
                return SendClientMessage(playerid, COLOR_RED, "У Вас нет этого рецепта");
			}
		}
		case 8:
		{
			if(PI[playerid][pRECIPE_COMBAT_SHOTGUN] == 0)
			{
                return SendClientMessage(playerid, COLOR_RED, "У Вас нет этого рецепта");
			}
		}
		case 9:
		{
			if(PI[playerid][pRECIPE_AK47] > 0)
			{
                return SendClientMessage(playerid, COLOR_RED, "У Вас нет этого рецепта");
			}
		}
		case 10:
		{
			if(PI[playerid][pRECIPE_M4] > 0)
			{
                return SendClientMessage(playerid, COLOR_RED, "У Вас нет этого рецепта");
			}
		}
		case 11:
		{
			if(PI[playerid][pRECIPE_COUNTRY_RIFLE] > 0)
			{
                return SendClientMessage(playerid, COLOR_RED, "У Вас нет этого рецепта");
			}
		}
		case 12:
		{
			if(PI[playerid][pRECIPE_SNIPER_RIFLE] > 0)
			{
                return SendClientMessage(playerid, COLOR_RED, "У Вас нет этого рецепта");
			}
		}
		default: return 1;
	}

	return 1;
}
stock ShowPlayerDialogCreateGun(playerid)
{
	new old_gun;
	new count;
	new fmt_str[80];
	new text[(sizeof fmt_str) * 10];

	for(new i; i < 12; i++)
	{
		if(old_gun == gunlist[i][gun_id]) continue;

		dialog_listitem_values[playerid][count] = i;
		count ++;

		old_gun = gunlist[i][gun_id];

		format(fmt_str, sizeof fmt_str, "{FFCC00}%d. {ffffff}%s{0099ff}(%d металла)\n", i+1, gunlist[i][gun_name], gunlist[i][gun_metal]);
		strcat(text, fmt_str);
	}

	ShowPlayerDialog
	(
		playerid, DIALOG_CREATE_GUN, DIALOG_STYLE_LIST,
		"{FFCC00}Создание оружия",
		text,
		"Создать", "Отмена"
	);
	return 1;
}
stock ResultCheat(p, r)
{
    new fmt_dialog[300], result[5];

    switch(r)
    {
        case 1: result = "G001"; // - Оружие
        case 2: result = "G002"; // - Патроны
        case 3: result = "G002"; // - Бексконечные патроны
    }

	new Year, Month, Day;
	getdate(Year, Month, Day);

	new Hour, Minute;
	gettime(Hour, Minute);

	format
	(
		fmt_dialog, sizeof fmt_dialog,
		"{FFFFFF}Внимание! Вы были кикнуты по подозрению в читерстве!\n"\
		"Код: {FFCC00}%s\n"\
		"{FFFFFF}Дата: {FFCC00}%d-%02d-%02d %d:%02d\n"\
		"{FFFFFF}Ваш пинг: {FFCC00}%d\n\n"\
		"{FFFFFF}Форум: {FFCC00}http://{FFCC00}"PROJECT_FORUM"\n"\
		"{FFFFFF}Предложения по улучшению античита\n"\
		"можно оставить на форуме.",
        result, Day, Month, Year, Hour, Minute, GetPlayerPing(p)
	);

	ShowPlayerDialog
	(
		p, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX,
		"{FFCC00}Античит",
		fmt_dialog,
		"Закрыть", ""
	);

    if(PI[p][pAdmin] == 0)
	{
	    Kick(p);
	}
    return true;
}
stock ShowDialogRules_1(playerid)
{
	new string[] = !"\
	{99CC00}Игровой процесс\n\n\
	{FF3300}Запрещено:{FFFFFF}\n\
	• Причинение ущерба здоровью персонажа без весомой на то игровой причины (DM);{FFFFFF}\n\
	• Смешивание игровой и внеигровой информации (MG);\n\
	• Причинение ущерба здоровью персонажа без весомой игровой причины на территории базы организации, где они появляются при входе в игру (SK);\n\
	• Причинение ущерба здоровью члену своей фракции без весомой на то игровой причины (TK);\n\
	• Бег с постоянным использованием прыжков (BH);\n\
	• Причинение ущерба здоровью с машины игровому персонажу без весомой на то игровой причины (DB);\n\
	• Преувеличение возможностей своего персонажа (PG);\n\
	• Причинение ущерба здоровью персонажа в отместку, который ранее Вас убил (RVK);\n\
	• Намеренное повторное убийство одного и того же игрока, которого Вы уже убили ранее (RPK);\
   ";
    return ShowPlayerDialog(playerid, D_RULES_1, DIALOG_STYLE_MSGBOX, !"{FFCC00}Правила сервера", string, !"Далее", "");
}

stock ShowDialogRules_2(playerid)
{
	new string[] = !"\
    {99CC00}Общение (чат)\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
    • Любые оскорбления во внеигровом чате: оскорбления религии, расы, половой принадлежности, оскорбляющие вопросы и прочее;\n\
    • Затрагивание любых членов семьи, а также оскорбляющие их фразы;\n\
    • Реклама каких-либо сторонних ресурсов/программ/серверов/групп и прочего;\n\
    • Использование флуда и написание сообщений верхним регистром (CAPS LOCK);\n\
    • Смешивать игровую и внеигровую информацию (MG);\n\
    • Писать и посылать сообщения не по теме в связь с администрацией сервера, а также во внеигровые чаты фракций и работ (Оффтоп);\n\
    • Обманывать администрацию сервера и игроков;\n\
    • Отправлять непонятные и бредовые объявления;\n\
	• Угрожать людям во внеигровом чате (блокировкой, затычкой, увольнением, расправой и так далее);\n\n\n\
	{99CC00}Правила дорожного движения\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
	• Езда на красный свет;\n\
	• Езда по встречной полосе;\n\
	• Езда по полям (исключение: боевая техника (танк), автомобиль \"Монстр\");\n\
	• Подрезать других игроков;\n\
	• Разворачиваться в неположенном для этого месте;\n\
	• Парковаться в неположенном месте (на тротуаре, на проезжей части и так далее);\n\
	• Игнорировать шлагбаумы, другие преграды и ограждения;\n\
	• Парковаться и вставать на проезжей части\
   ";
    return ShowPlayerDialog(playerid, D_RULES_2, DIALOG_STYLE_MSGBOX, !"{FFCC00}Правила сервера", string, !"Далее", "");
}

stock ShowDialogRules_3(playerid)
{
	new string[] = !"\
    {99CC00}Вдали от клавиатуры (AFK)\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
    • Вставать в AFK на дороге;\n\
    • Вставать в AFK на месте появления;\n\
    • Вставать в AFK на входах/выходах;\n\
    • Вставать в AFK у банкоматов;\n\
    • Вставать в AFK на складе воинской части;\n\
    • Вставать в AFK на пикапах (пикап - маркер, с которым можно взаимодействовать. Например, метка бизнеса);\n\n\n\
	{99CC00}Игровые ситуации:\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
	• Игнорировать отыгровки других людей, не обращать внимание на их взаимодействие с Вами;\n\
    • Доставать/менять/убирать оружие без какой-либо отыгровки;\n\
    • Продавать оружие и похищать людей в людных местах (зеленых зонах);\n\n\n\
	{99CC00}Игровой ник\n\n\
	{FFFFFF}Пример ролевого ника, где имя и фамилия написаны с заглавных букв\n\
	через нижнее подчеркивание по форме \"Имя_Фамилия\"):\n\
	Alexander_Kostylev, Tom_Eastwood, Vladlena_Ivanova и т.д.\n\
	Только игрок с ролевым (RP) ником имеет право состоять во фракции.\n\n\n\
	{FF3300}Запрещено:\n\
	{FFFFFF}• Фальсифицировать с помощью ника администраторов или лидеров;\n\
	• Использовать неадекватные имена и фамилии (например, мусорка, насморк, сопля);\n\
   ";
    return ShowPlayerDialog(playerid, D_RULES_3, DIALOG_STYLE_MSGBOX, !"{FFCC00}Правила сервера", string, !"Далее", "");
}

stock ShowDialogRules_4(playerid)
{
	new string[] = !"\
	{99CC00}Фракции\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
	• Продавать/покупать ранги внеигровым (ООС) путем за любые игровые, либо реальные вещи (средства);\n\
	• Использовав внеигровую (ООС) связь, повышать игроков и прощать им их нарушения из-за\n\
	непосредственных отношений с ними (блат);\n\
	• Использовать фракционные системы в личных целях (просто так использовать\n\
	электрошокер, давать розыск, выписывать штрафы и так далее);\n\
	• Использование склада/общака в личных для себя целях (воровство патрон и металла);\n\
	• Для правоохранительных органов в одиночку запрещено проверять документы у игроков, проводить обыск,\n\
	задержание преступника, стоять на посту (не считая поста на территории фракции);\n\
	• Надевать наручники/связывать/использовать шокер через стены/автомобиль, а также прочие преграды;\n\
	• Сотрудникам государственных фракций производить бандитизм на воинской части, а также воровать\n\
	патроны со склада воинской части в форме фракции и без маски;\n\n\n\
	{99CC00}Казино\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
	• Стоять и сидеть на столах;\n\
	• Приседать, включать просто так неподходящие анимации и прыгать в момент ставки;\
   ";
    return ShowPlayerDialog(playerid, D_RULES_4, DIALOG_STYLE_MSGBOX, !"{FFCC00}Правила сервера", string, !"Далее", "");
}

stock ShowDialogRules_5(playerid)
{
	new string[] = !"\
    {99CC00}Действия с аккаунтом и имуществом\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
	• Передавать/покупать/обменивать/продавать доступ к игровому аккаунту;\n\
	• Взламывать, а также путем махинаций получать доступ к другому игровому аккаунту;\n\
	• Передавать имущество и деньги с одного своего аккаунта на другой;\n\
	• Покупать/продавать игровое имущество и игровые деньги за реальные средства у других игроков;\n\
	• Иметь более одного аккаунта с имуществом (имущество: бизнес, дом);\n\
	• Недонесение о критических недоработках сервера, которые способствуют получению игровой валюты,\n\
	либо отрицательно влияют на работу самого сервера; недонесение о игроке, совершающем запрещенные\n\
	действия по получению, передаче или продаже игровой валюты/аккаунтов;\n\n\n\
	{99CC00}Нечестное получение преимущества\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
	• Использование сторонних программ (читы; скрипты/моды/программы,\n\
	дающие преимущества перед другими людьми);\n\
	• Использование недоработок (багов) игрового сервера и мода (+С, отводы пистолета,\n\
	Scroll, \"застревание\" в текстурах с помощью анимации и так далее);\
   ";
    return ShowPlayerDialog(playerid, D_JOB+30, DIALOG_STYLE_MSGBOX, !"{FFCC00}Правила сервера", string, !"Далее", "");
}
//==============================================================================
stock ShowDialogRules_GAME_1(playerid)
{
	new string[] = !"\
	{99CC00}Игровой процесс\n\n\
	{FF3300}Запрещено:{FFFFFF}\n\
	• Причинение ущерба здоровью персонажа без весомой на то игровой причины (DM);{FFFFFF}\n\
	• Смешивание игровой и внеигровой информации (MG);\n\
	• Причинение ущерба здоровью персонажа без весомой игровой причины на территории базы организации, где они появляются при входе в игру (SK);\n\
	• Причинение ущерба здоровью члену своей фракции без весомой на то игровой причины (TK);\n\
	• Бег с постоянным использованием прыжков (BH);\n\
	• Причинение ущерба здоровью с машины игровому персонажу без весомой на то игровой причины (DB);\n\
	• Преувеличение возможностей своего персонажа (PG);\n\
	• Причинение ущерба здоровью персонажа в отместку, который ранее Вас убил (RVK);\n\
	• Намеренное повторное убийство одного и того же игрока, которого Вы уже убили ранее (RPK);\
   ";
    return ShowPlayerDialog(playerid, D_RULES_GAME_1, DIALOG_STYLE_MSGBOX, !"{FFCC00}Правила сервера", string, !"Далее", "");
}
//==============================================================================
stock ShowDialogRules_GAME_2(playerid)
{
	new string[] = !"\
    {99CC00}Общение (чат)\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
    • Любые оскорбления во внеигровом чате: оскорбления религии, расы, половой принадлежности, оскорбляющие вопросы и прочее;\n\
    • Затрагивание любых членов семьи, а также оскорбляющие их фразы;\n\
    • Реклама каких-либо сторонних ресурсов/программ/серверов/групп и прочего;\n\
    • Использование флуда и написание сообщений верхним регистром (CAPS LOCK);\n\
    • Смешивать игровую и внеигровую информацию (MG);\n\
    • Писать и посылать сообщения не по теме в связь с администрацией сервера, а также во внеигровые чаты фракций и работ (Оффтоп);\n\
    • Обманывать администрацию сервера и игроков;\n\
    • Отправлять непонятные и бредовые объявления;\n\
	• Угрожать людям во внеигровом чате (блокировкой, затычкой, увольнением, расправой и так далее);\n\n\n\
	{99CC00}Правила дорожного движения\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
	• Езда на красный свет;\n\
	• Езда по встречной полосе;\n\
	• Езда по полям (исключение: боевая техника (танк), автомобиль \"Монстр\");\n\
	• Подрезать других игроков;\n\
	• Разворачиваться в неположенном для этого месте;\n\
	• Парковаться в неположенном месте (на тротуаре, на проезжей части и так далее);\n\
	• Игнорировать шлагбаумы, другие преграды и ограждения;\n\
	• Парковаться и вставать на проезжей части\
   ";
    return ShowPlayerDialog(playerid, D_RULES_GAME_2, DIALOG_STYLE_MSGBOX, !"{FFCC00}Правила сервера", string, !"Далее", "");
}
//==============================================================================
stock ShowDialogRules_GAME_3(playerid)
{
	new string[] = !"\
    {99CC00}Вдали от клавиатуры (AFK)\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
    • Вставать в AFK на дороге;\n\
    • Вставать в AFK на месте появления;\n\
    • Вставать в AFK на входах/выходах;\n\
    • Вставать в AFK у банкоматов;\n\
    • Вставать в AFK на складе воинской части;\n\
    • Вставать в AFK на пикапах (пикап - маркер, с которым можно взаимодействовать. Например, метка бизнеса);\n\n\n\
	{99CC00}Игровые ситуации:\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
	• Игнорировать отыгровки других людей, не обращать внимание на их взаимодействие с Вами;\n\
    • Доставать/менять/убирать оружие без какой-либо отыгровки;\n\
    • Продавать оружие и похищать людей в людных местах (зеленых зонах);\n\n\n\
	{99CC00}Игровой ник\n\n\
	{FFFFFF}Пример ролевого ника, где имя и фамилия написаны с заглавных букв\n\
	через нижнее подчеркивание по форме \"Имя_Фамилия\"):\n\
	Alexander_Kostylev, Tom_Eastwood, Vladlena_Ivanova и т.д.\n\
	Только игрок с ролевым (RP) ником имеет право состоять во фракции.\n\n\n\
	{FF3300}Запрещено:\n\
	{FFFFFF}• Фальсифицировать с помощью ника администраторов или лидеров;\n\
	• Использовать неадекватные имена и фамилии (например, мусорка, насморк, сопля);\n\
   ";
    return ShowPlayerDialog(playerid, D_RULES_GAME_3, DIALOG_STYLE_MSGBOX, !"{FFCC00}Правила сервера", string, !"Далее", "");
}
//==============================================================================
stock ShowDialogRules_GAME_4(playerid)
{
	new string[] = !"\
	{99CC00}Фракции\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
	• Продавать/покупать ранги внеигровым (ООС) путем за любые игровые, либо реальные вещи (средства);\n\
	• Использовав внеигровую (ООС) связь, повышать игроков и прощать им их нарушения из-за\n\
	непосредственных отношений с ними (блат);\n\
	• Использовать фракционные системы в личных целях (просто так использовать\n\
	электрошокер, давать розыск, выписывать штрафы и так далее);\n\
	• Использование склада/общака в личных для себя целях (воровство патрон и металла);\n\
	• Для правоохранительных органов в одиночку запрещено проверять документы у игроков, проводить обыск,\n\
	задержание преступника, стоять на посту (не считая поста на территории фракции);\n\
	• Надевать наручники/связывать/использовать шокер через стены/автомобиль, а также прочие преграды;\n\
	• Сотрудникам государственных фракций производить бандитизм на воинской части, а также воровать\n\
	патроны со склада воинской части в форме фракции и без маски;\n\n\n\
	{99CC00}Казино\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
	• Стоять и сидеть на столах;\n\
	• Приседать, включать просто так неподходящие анимации и прыгать в момент ставки;\
   ";
    return ShowPlayerDialog(playerid, D_RULES_GAME_4, DIALOG_STYLE_MSGBOX, !"{FFCC00}Правила сервера", string, !"Далее", "");
}
//==============================================================================
stock ShowDialogRules_GAME_5(playerid)
{
	new string[] = !"\
    {99CC00}Действия с аккаунтом и имуществом\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
	• Передавать/покупать/обменивать/продавать доступ к игровому аккаунту;\n\
	• Взламывать, а также путем махинаций получать доступ к другому игровому аккаунту;\n\
	• Передавать имущество и деньги с одного своего аккаунта на другой;\n\
	• Покупать/продавать игровое имущество и игровые деньги за реальные средства у других игроков;\n\
	• Иметь более одного аккаунта с имуществом (имущество: бизнес, дом);\n\
	• Недонесение о критических недоработках сервера, которые способствуют получению игровой валюты,\n\
	либо отрицательно влияют на работу самого сервера; недонесение о игроке, совершающем запрещенные\n\
	действия по получению, передаче или продаже игровой валюты/аккаунтов;\n\n\n\
	{99CC00}Нечестное получение преимущества\n\n\
    {FF3300}Запрещено:{FFFFFF}\n\
	• Использование сторонних программ (читы; скрипты/моды/программы,\n\
	дающие преимущества перед другими людьми);\n\
	• Использование недоработок (багов) игрового сервера и мода (+С, отводы пистолета,\n\
	Scroll, \"застревание\" в текстурах с помощью анимации и так далее);\
   ";
    return ShowPlayerDialog(playerid, D_RULES_GAME_5, DIALOG_STYLE_MSGBOX, !"{FFCC00}Правила сервера", string, !"Закрыть", "");
}
//==============================================================================
forward IsPlayerInZone(playerid, Float:minX, Float:minY, Float:maxX, Float:maxY); 
public IsPlayerInZone(playerid, Float:minX, Float:minY, Float:maxX, Float:maxY) 
{ 
    new Float:FXF_ZoneX, Float:FXF_ZoneY, Float:FXF_ZoneZ; 
    GetPlayerPos(playerid, FXF_ZoneX, FXF_ZoneY, FXF_ZoneZ); 
    if((FXF_ZoneX >= minX && FXF_ZoneX <= maxX) && (FXF_ZoneY >= minY && FXF_ZoneY <= maxY) && FXF_ZoneZ <= 500) 
    { 
        return 1; 
    } 
    return 0; 
}  
//==============================================================================
stock LoadMySQLSettings()
{
	new FileID = ini_openFile("mysql_settings.ini"),errCode;
	if(FileID < 0)
	{
		printf("Error while opening MySQL settings file. Error code: %d",FileID);
		return 0;
	}
	errCode = ini_getString(FileID,"host",MySQLSettings[SERVER_HOST]);
	if(errCode < 0) printf("Error while reading MySQL settings file (host). Error code: %d",errCode);
	errCode = ini_getString(FileID,"username",MySQLSettings[SERVER_USERNAME]);
	if(errCode < 0) printf("Error while reading MySQL settings file (username). Error code: %d",errCode);
	errCode = ini_getString(FileID,"password",MySQLSettings[SERVER_PASSWORD]);
	if(errCode < 0) printf("Error while reading MySQL settings file (password). Error code: %d",errCode);
	errCode = ini_getString(FileID,"database",MySQLSettings[SERVER_DATABASE]);
	if(errCode < 0) printf("Error while reading MySQL settings file (database). Error code: %d",errCode);
	ini_closeFile(FileID);
	return 1;
}
LimitVehicleSpeed_ts(const playerid, const speed)
{
    new	Float: speed_x,
        Float: speed_y,
        Float: speed_z,
        vehicle = GetPlayerVehicleID(playerid);
		
    GetVehicleVelocity(vehicle, speed_x, speed_y, speed_z);
    return (floatround(floatsqroot((speed_x * speed_x) + (speed_y * speed_y) + (speed_z * speed_z)) * 195) > speed)
    ? SetVehicleVelocity(vehicle, speed_x * 0.98, speed_y * 0.98, speed_z * 0.98)
    : 0;
}

/*publics UpdateZonaPlayer(playerid)
{
	new Float: x, Float: y, Float: z;
	
	GetPlayerPos(playerid, x, y, z);

//	for(new i = 0; i != sizeof ZoneName; i ++)
	{
//		if((x <= ZoneName[i][zMax_x] && x >= ZoneName[i][zMin_x]) && (y <= ZoneName[i][zMax_y] && y >= ZoneName[i][zMin_y]))
		{
//			TextDrawSetString(arzp_PTD[playerid], ZoneName[i][zName]);
//			break;
		}
		
//		else
		{
			TextDrawSetString(arzp_PTD[playerid], "Hњ›E™OPOљCKA¬ O—ћ.");
		}
	}
	
	return 1;
}
*/
stock SendFMes(family, color, str[])
{
	foreach(new i: Player)
	{
		if(!PlayerLogged[i]) continue;
		if(PI[i][pMember] == family) SendClientMessage(i, color, str);
	}
	
	return 1;
}

stock AC_Vehicle_Time(model)
{
    new value = 500;
    switch(model)
    {
        //-------------------[Скутеры/мотоциклы/велосипеды/без дверей]----------
        case 424: value = 250;
        case 448: value = 250;
        case 461..463: value = 250;
        case 468: value = 250;
        case 471: value = 250;
        case 481: value = 250;
        case 509..510: value = 250;
        case 521..523: value = 250;
        case 530..531: value = 250;
        case 571..572: value = 250;
        case 581: value = 250;
        case 586: value = 250;
        case 457: value = 250;
        case 485: value = 250;
        case 486: value = 250;
        case 568: value = 250;
        //----------------------------[Лодки/Поезда]----------------------------
        case 430: value = 0;
        case 446: value = 0;
        case 452..454: value = 0;
        case 472..473: value = 0;
        case 484: value = 0;
        case 493: value = 0;
        case 539: value = 0;
        case 595: value = 0;
        case 449: value = 0;
        case 537..538: value = 0;
        case 570: value = 0;
    }
    return value;
}
stock GetWeaponModel(weaponid)
{
    switch(weaponid)
    {
        case 1:
            return 331;

        case 2..8:
            return weaponid+331;

        case 9:
            return 341;

        case 10..15:
            return weaponid+311;

        case 16..18:
            return weaponid+326;

        case 22..29:
            return weaponid+324;

        case 30,31:
            return weaponid+325;

        case 32:
            return 372;

        case 33..45:
            return weaponid+324;

        case 46:
            return 371;
    }
    return 0;
}

stock ChangeView(playerid, oldstate, newstate)
{
    new Float: X[3], Float: Y[3], Float: Z[3];
	
    if(GetPlayerVehicleID(playerid) > 0)
    {
        GetVehicleModelInfo(GetVehicleModel(GetPlayerVehicleID(playerid)), 1, X[0], Y[0], Z[0]);
        GetVehicleModelInfo(GetVehicleModel(GetPlayerVehicleID(playerid)), 2, X[1], Y[1], Z[1]);
        GetVehicleModelInfo(GetVehicleModel(GetPlayerVehicleID(playerid)), 3, X[2], Y[2], Z[2]);
    }
	
    if(oldstate == newstate) AttachCameraToObject(playerid, FirstPerson[playerid]);
	
    switch(newstate)
    {
        case 1: AttachObjectToPlayer(FirstPerson[playerid], playerid, 0.0, 0.13, 0.65, 0, 0, 0), AttachCameraToObject(playerid, FirstPerson[playerid]);
        case 2, 3:
        {
            switch(GetPlayerVehicleSeat(playerid))
            {
                case 0: { X[1] -= (X[0] / 2.43), Y[1] -= 0.1, Z[1] += 0.6; AttachObjectToVehicle(FirstPerson[playerid], GetPlayerVehicleID(playerid), X[1], Y[1], Z[1], 0, 0, 0); }
                case 1: { X[1] += 0.0, Y[1] -= 0.1, Z[1] += 0.55; AttachObjectToVehicle(FirstPerson[playerid], GetPlayerVehicleID(playerid), X[1], Y[1], Z[1], 0, 0, 0); }
                case 2: { X[2] -= (X[0] / 2.43), Y[2] += 0.0, Z[2] += 0.6; AttachObjectToVehicle(FirstPerson[playerid], GetPlayerVehicleID(playerid), X[2], Y[2], Z[2], 0, 0, 0); }
                case 3: { X[2] += 0.0, Y[2] += 0.0, Z[2] += 0.55; AttachObjectToVehicle(FirstPerson[playerid], GetPlayerVehicleID(playerid), X[2], Y[2], Z[2], 0, 0, 0); }
                default:
                {
                    switch(GetPlayerVehicleSeat(playerid))
                    {
                        case 0: AttachObjectToVehicle(FirstPerson[playerid], GetPlayerVehicleID(playerid), X[1], Y[1] + 0.45, Z[1] + 0.6, 0, 0, 0);
                        case 1: AttachObjectToVehicle(FirstPerson[playerid], GetPlayerVehicleID(playerid), X[2], Y[2] + 0.4, Z[2] + 0.5, 0, 0, 0);
                    }
                }
            }
            AttachCameraToObject(playerid, FirstPerson[playerid]);
        }
    }
	
    return 0;
}
//==============================================================================
publics SecondTimer(playerid)
{
	new fmt_str[90];
		/*hours,
		minutes, 
		seconds,
		gettime(hours, minutes, seconds);*/
		//vehicleid = GetPlayerVehicleID(playerid);
		
//    UpdateZonaPlayer(playerid);
	tazer_off[playerid] --;

	if(tazer_off[playerid] == 0)
	{
		SetPVarInt(playerid, "Tazer", 0);
		ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 0);
		TogglePlayerControllable(playerid, 1);
	}
	PI[playerid][pAFK]++;
	if(PI[playerid][pAFK] >= 3)
	{
		new temp[64];
		format(temp, sizeof(temp), "На паузе: %s", Converts(PI[playerid][pAFK]));
		SetPlayerChatBubble(playerid, temp, COLOR_AFK, 10.0, 1600);
	}
	
    /*format(fmt_str, sizeof fmt_str, "%s%d:%s%d", (hours < 10) ? ("0") : (""), hours, (minutes < 10) ? ("0") : (""), minutes);
    TextDrawSetString(Vrijeme, fmt_str);
    
	getdate(year, month, day);
	
	format(fmt_str, sizeof fmt_str, "ФЕВРАЛЬ %d", day, ((month < 10) ? ("0") : ("")));
	TextDrawSetString(Datum, fmt_str);*/
	
	/*timer_show_use_alt_td[playerid] --;
	
	if(timer_show_use_alt_td[playerid] == 1)
	{
		for(new i = 0; i != sizeof USE_ALT; i ++)
		{
			PlayerTextDrawHide(playerid, USE_ALT[i]);
		}		
	}
	if(minutes == 00 && seconds == 00)
	{
		new weather;
		
		weather = random(20);
		
		SetWeather(weather);
		
		switch(weather)
		{
			case 1: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается солнечная погода! (28°С)");
			case 2: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидаются сильные дожди!");
			case 3: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается солнечная погода! (28°С)");
			case 4: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается туманная погода!");
			case 5: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается дождевая погода!");
			case 6: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается дождевая погода!");
			case 7: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается облачная погода!");
			case 8: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается пасмурная погода!");
			case 9: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается туманная погода!");
			case 10: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается солнечная погода! (28°С)");
			case 11: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается солнечная погода! (28°С)");
			case 12: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается облачная погода!");
			case 13: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается солнечная погода! (28°С)");
			case 14: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается солнечная погода! (28°С)");
			case 15: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается облачная погода!");
			case 16: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается дождевая погода!");
			case 17: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается жаркая погода! (32°С)");
			case 18: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается жаркая погода! (32°С)");
			case 19: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидаются сильные дожди!");
			case 20: SendClientMessageToAll(COLOR_OMEGOV,"В области ожидается облачная погода!");
		}
	}*/
	
	for(new i; i < 6; i++) if(gGunWorkTime[i]) gGunWorkTime[i] --;
	
	WHDataUpdate();
	GzCheck();
	SaveAcc();
	Probeg();
	SaveWarehouse();
	
	/*for(new i = 0; i < sizeof GZInfo; i ++)
	{
		if(GZSafeTime[i] > 0)
		{
			GZSafeTime[i] --;
			
			foreach(new x: Player)
			{
				if(PI[x][pMember] == GZInfo[i][gNapad] || PI[x][pMember] == GZInfo[i][gFrak])
				{
					TimeConverter(GZSafeTime[i], fmt_str);
					PlayerTextDrawSetString(x, CaptureTD[x][4], fmt_str);
				}
			}
		}
	}*/
	
	PlayerTimer();
	
	/*if(FrakCD > 0 && IsCapture == false) FrakCD --;
	
	for(new f = 0; f < 3; f++)
	{
		if(MZSafeTime[f]>0)
		{
			MZSafeTime[f] --;
			if(MZSafeTime[f] == 200 || MZSafeTime[f] == 450)
			{
				format(fmt_str, sizeof fmt_str, "У Вас осталось %d секунд. Место встречи: Поле", MZSafeTime[f]);
				
				SendFMes(MZInfo[f][mNapad],COLOR_RED, fmt_str);
				
				for(new h = 0; h < 200; h++)
				{
					if(BizzInfo[h][bZahvat] == 1) SendFMes(BizzInfo[h][bMafia],COLOR_RED,fmt_str);
				}
			}
		}
	}*/
	
	fuelcheck ++;
	
	if(fuelcheck == 25)
	{
		fuelcheck = 0;
		for(new v = 1, j = MAX_VEHICLES; v <= j; v++)
		{
			if(GetVehicleModel(v) == 0) continue;
			if(IsAPlane(v) == 1 || IsABoat(v) == 1 || IsAVel(v) == 1) continue; // и мопед
			if(Engine[v] == true && Fuel[v] > 0)
			{
				Fuel[v]--;
				if(Fuel[v] < 1)
				{
					Engine[v] = false;
					PlayerFuelMes[v] = true;
					GetVehicleParamsEx(v,engine,lights,alarm,doors,bonnet,boot,objective);
					SetVehicleParamsEx(v,false,lights,alarm,doors,bonnet,boot,objective);
					Fuel[v] = 0;
				}
			}
		}
	}

	/*if(minutes == 0 && seconds >= 11 && seconds <= 16) PAYDAY = 0;
	
   	if(minutes == 0 && seconds >= 0 && seconds <= 10 && PAYDAY == 0)
   	{
   	    PAYDAY = 1;
   	    SetWorldTime(hours);
   	    PayDay();
		
		mask_off_timer[playerid] --;
	
		if(mask_off_timer[playerid] == 0)
		{
			SetPlayerColorEx(playerid,TeamColors[GetTeamID(playerid)]);
			PlayerUseMask[playerid] = false;
			PI[playerid][pMask]--;
			SetPlayerChatBubble(playerid, "снимает маску", COLOR_PURPLE, 13.0, 10000);
			GameTextForPlayer(playerid, "~y~INVISABLE OFF", 800, 4);
			PlayerPlaySound(playerid, 21001, 0.0, 0.0, 0.0);
  		}
   	}*/
   	
    new h,m,s;
	gettime(h,m,s);

   	if(m == 2 && PAYDAY == 1) PAYDAY = 0;
	if(m == 1 && PAYDAY == 0)
	{
		PAYDAY = 1;
		SetWorldTime(h);
		PayDay();
		//ServerBonus();
	}
	
	foreach(new i: Player)
	{
		if(!IsPlayerConnected(i)) continue;
		
		if(GetPVarInt(i, "arendkey") == -1) continue;
		
		new rc = GetPVarInt(i, "arendkey");
		
		if(ArendInfo[rc][aPlayerID] != i)
		{
		    SetPVarInt(i, "arendkey", -1);
		    continue;
		}
		
		if(!IsPlayerInVehicle(i, ArendInfo[rc][aID]))
		{
		    new Float: x, 
				Float: y, 
				Float: z;
			
		    GetVehiclePos(ArendInfo[rc][aID], x, y, z);
			
			/*if(!IsPlayerInRangeOfPoint(i, 2000.0, x, y, z) && GetPlayerVirtualWorld(i) == 0 && GetPlayerInterior(i) == 0)
			{
			    SendClientMessage(i, COLOR_RED, "Вы отошли слишком далеко от арендованного транспорта");
				
			    ArendInfo[rc][aPlayerID] = INVALID_PLAYER_ID;
            	SetVehicleToRespawn(ArendInfo[rc][aID]);
				CarDoorsEx(ArendInfo[rc][aID], 0);
            	SetPVarInt(i, "arendkey", -1);
				
            	continue;
			}*/
		}
	}
	
	/*if(paintt[1] == 0)
    {
        if(hours == 16 && minutes == 10  || hours == 13 && minutes == 10  || hours == 14 && minutes == 10  || hours == 22 && minutes == 10 || hours == 01 && minutes == 30 || hours == 03 && minutes == 15 )
        {
            SendClientMessageToAll(0xFFCC00FF, "[МП] Внимание! Начало пейнтбола через 5 минут!");

            paintt[0] = 300;
            paintt[1] = 1;

			foreach(new i: Player)
			{
                if(GetPVarInt(i, "paintball") == 1)
                {
                    DeletePVar(i, "paintball");
				}
			}
        }
    }
    if(paintt[0] > 0)
    {
        paintt[0]--;
        if(paintt[1] == 1 && paintt[0] == 120)
		{
		    SendClientMessageToAll(0xFFCC00FF, "[МП] Внимание! Начало пейнтбола через 5 минут!");
		}
        if(paintt[1] == 1 && paintt[0] == 1)
        {
            if(paintt[2] > 1) // 1
            {
                for(new i = 0; i < PaintList; i ++)
                {
                    strmid(PaintInfo[i][Player_Name],"None", 0, strlen("None"), MAX_PLAYER_NAME);
                    PaintInfo[i][Kills] = 0;
                    PaintInfo[i][Deaths] = 0;
                }

                PaintList = 0;

                SendClientMessageToAll(0xFFCC00FF,"[МП] Внимание! Матч по Пейнтболу начался");

                paintt[1] = 2;
			    paintt[0] = 300;
        		
				foreach(new i: Player)
				{
                    if(GetPVarInt(i, "paintball") == 1)
					{
					    SetPVarInt(i, "paintball", 2);
					    FreezePlayer(i, 2000);
						PI[i][pHeal] = 100;
						SetPlayerHealth(i, PI[i][pHeal]);
  						GivePlayerWeaponAC(i, PaintGun[random(sizeof(PaintGun))], 600);
        				SetPlayerPos(i, 2234.7456,1391.6573,11.5700);
					}
                }
            }
            else
			{
			    SendClientMessageToAll(0xFFCC00FF, "Матч по пейнтболу отменен из-за недостаточного количества участников");
				paintt[1] = 0;
				paintt[0] = 0;
			}
        }
        if(paintt[1] == 2 && paintt[0] == 1)
        {
            SendClientMessageToAll(0xFFCC00FF, "Матч по пейнтболу завершен. Список участников: /paintlist");

            paintt[1] = paintt[0] = 0;

            foreach(new i: Player)
            {
                if(GetPVarInt(i, "paintball") == 2)
                {
                    PaintInfo[PaintList][Kills] = GetPVarInt(i,"paintkills");
                    PaintInfo[PaintList][Deaths] = GetPVarInt(i,"paintdeaths");

                    strmid(PaintInfo[PaintList][Player_Name], PI[i][pName], 0, strlen(PI[i][pName]), MAX_PLAYER_NAME);

                    PaintList++;
                    ResetPlayerWeaponsAC(i);

                    SetPlayerPos(i, 2233.7534,1374.7618,11.5700);
                    SetPlayerFacingAngle(i, 189.2908);
                }
            }
        }
    }
	
   	if(MUSICACTIVE == true && activemusic[playerid] == false && IsPlayerInRangeOfPoint(playerid, MUSICDIST, MUSICX, MUSICY, MUSICZ))
    {
		if(PlayerMusic[playerid] == true)
		{
           PlayAudioStreamForPlayer(playerid, MUSICURL, MUSICX, MUSICY, MUSICZ,MUSICDIST, 1);
    	   activemusic[playerid] = true;
 		   SendClientMessage(playerid, COLOR_GREEN, "Вы попали в зону проигрывания музыки");
 		   SendClientMessage(playerid, COLOR_GREEN, "Во избежании недоразумений, сделайте пожалуйста громкость колонок тише");
 		   SendClientMessage(playerid, COLOR_GREEN, "В песне, возможно, будет использована нецензурная брань");
 		}
    }
	
    if(MUSICACTIVE == true && activemusic[playerid] == true && !IsPlayerInRangeOfPoint(playerid, MUSICDIST, MUSICX, MUSICY, MUSICZ))
    {
        if(PlayerMusic[playerid] == true)
		{
    	   activemusic[playerid] = false;
     	   StopAudioStreamForPlayer(playerid);
     	   SendClientMessage(playerid, COLOR_RED, "Вы покинули зону прослушивания музыки!");
		}
    }
	
	clear_anim_text[playerid] --;
	
	if(clear_anim_text[playerid] == 0)
	{
		ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
	}*/
	
	/*check_rent_car[playerid] --;
	
	if(check_rent_car[playerid] == 0)
	{
		if(GetPlayerState(playerid) != 2) return 1;
		
		EnterVehicle[playerid] = vehicleid;
		
		if(!ispassenger_timer)
		{
			if(PI[playerid][TaxiCarID] == vehicleid
			|| PI[playerid][BusCarID] == vehicleid
			|| PI[playerid][MechanicCarID] == vehicleid
			|| PI[playerid][TruckerCarID] == vehicleid) return 1;
			
			else
			{
				SendClientMessage(playerid, COLOR_RED, "У Вас нет ключей от этого транспорта");
				ClearAnimations(playerid, true);
				
				return 1;
			}
		}
	}*/
	
	/*hand_timer[playerid] --;
	
	if(hand_timer[playerid] == 0)
	{
		if(startjob2[playerid] == true)
		{
			ApplyAnimation(playerid,"PED","IDLE_chat",4.1,0,0,0,1,5150);
			
			if(IsPlayerAttachedObjectSlotUsed(playerid,1)) RemovePlayerAttachedObject(playerid,1);
			
			SetPlayerAttachedObject(playerid,2, 905, 5, 0.020944, 0.039285, -0.035010, 0.000000, 0.000000, 0.000000, 0.301603, 0.125763, 0.233199);
			SetPlayerAttachedObject(playerid,3, 906, 6, -0.032336, 0.111448, 0.001745, 0.000000, 0.000000, 0.000000, 0.026124, 0.048238, 0.048593);
			
			timemine[playerid] = mine_timer[playerid] = 6;
		}		
	}
	
	mine_timer[playerid] --;
	
	if(mine_timer[playerid] == 0)
	{
		if(startjob2[playerid] == true)
		{
			if(IsPlayerAttachedObjectSlotUsed(playerid,2)) RemovePlayerAttachedObject(playerid,2);
			if(IsPlayerAttachedObjectSlotUsed(playerid,3)) RemovePlayerAttachedObject(playerid,3);
			SetPlayerAttachedObject(playerid,2, 1458, 1, -1.034844, 1.116571, -0.065124, 76.480148, 75.781570, 280.952545, 0.575599, 0.604554, 0.624122);
			SetPlayerAttachedObject(playerid,3, 905, 1, -0.275758, 1.305280, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);
			SetPlayerCheckpoint(playerid,-25.5943, 1054.8018, -84.0819-1, 2.0);
		}
	}
	
	reset_antiflood_pick_timer[playerid] --;
	
	if(reset_antiflood_pick_timer[playerid] == 0)
	{
		SetPVarInt(playerid, "PickupID", -1);
	}
	
	unfreeze_two_timer[playerid] --;
	
	if(unfreeze_two_timer[playerid] == 0)
	{
		TogglePlayerControllable(playerid, 1);
		ClearAnimations(playerid);
	}
	
	clear_animations_delay[playerid] --;
	
	if(clear_animations_delay[playerid] == 0)
	{
		ApplyAnimation(playerid, "PED", "IDLE_chat", 4.1, 1, 0, 0, 0, 1, 1);
	}
	
	warning_green_zone_timer[playerid] --;
	
	if(warning_green_zone_timer[playerid] == 0)
	{
		PlayerTextDrawShow(playerid, GreenZoneText[playerid][0]);
		PlayerTextDrawShow(playerid, GreenZoneText[playerid][1]);
		
		DeletePVar(playerid, "SwitchingTextdraw");		
	}
	
	pickup_back_timer[playerid] --;
	
	if(pickup_back_timer[playerid] == 0)
	{
		pickupentered[playerid] = 0;
	}
	
	gamemode_exit_deday[playerid] --;
	
	if(gamemode_exit_deday[playerid] == 0)
	{
		GameModeExit();
	}
	
	drug_effect_gone_timer[playerid] --;
	
	if(drug_effect_gone_timer[playerid] == 0)
	{
		SetPlayerTime(playerid, hours, minutes);
		SetPlayerWeather(playerid, 7);
		SetPlayerDrunkLevel(playerid, 0);
	}*/
 
	// Спектатор

	format(fmt_str, sizeof fmt_str, "%s_(%d)_FPS:_100_I_PING:_%d", GetName(player_spectate_id), player_spectate_id, GetPlayerPing(player_spectate_id));
	PlayerTextDrawSetString(playerid, pOdminPanel_PTD[playerid][0], fmt_str);
	
	if(IsPlayerInAnyVehicle(player_spectate_id))
	{
		format(fmt_str, sizeof fmt_str, "СКОРОСТЬ:_%d_KM/Ч", SpeedVehicle(player_spectate_id));
		PlayerTextDrawSetString(playerid, pOdminPanel_PTD[playerid][1], fmt_str);
	}
	
	else
	{
		format(fmt_str, sizeof fmt_str, "НЕ В МАШИНЕ", SpeedVehicle(player_spectate_id));
		PlayerTextDrawSetString(playerid, pOdminPanel_PTD[playerid][1], fmt_str);
	}
	
	format(fmt_str, sizeof fmt_str, "ЧИП:_НЕТ", SpeedVehicle(player_spectate_id));
	PlayerTextDrawSetString(playerid, pOdminPanel_PTD[playerid][3], fmt_str);
	
	new Float: player_spectate_health;
	
	GetPlayerHealth(player_spectate_id, player_spectate_health);
	
	format(fmt_str, sizeof fmt_str, "HP:_%d", player_spectate_health * 100 / 1000);
	PlayerTextDrawSetString(playerid, pOdminPanel_PTD[playerid][4], fmt_str);
	
	if(GetPlayerMoney(playerid) < 999999)
	{
		RemovePlayerAttachedObject(playerid,3);
	}
	if(GetPlayerMoney(playerid) > 1000000)
    {
		SetPlayerAttachedObject(playerid,3,1210,5,0.299999,0.099999,0.000000,0.000000,-83.000000,0.000000,1.000000,1.000000,1.000000);
    }
	return 1;
}

stock IsPlayerGrandAdmin(playerid)
{
    if(PI[playerid][pAdmin] < 0) return 0;

	new fmt_query[70];
	new rows;
	new Cache: result;

	format(fmt_query, sizeof fmt_query, "SELECT * FROM fullaccess WHERE name='%s'", GetName(playerid));
	result = mysql_query(dbHandle, fmt_query);

	rows = cache_num_rows();

	if(rows)
	{
		cache_delete(result);
		return 1;
	}
	else
	{
		cache_delete(result);
		return 0;
	}
}

/*
forward AdvertiseTimer();
public AdvertiseTimer()
{
	SendClientMessageToAll(0xFFCC00FF,"_______________________________________________________________________________________________");
	SendClientMessageToAll(0xFFCC00FF,"                                                                                               ");
	SendClientMessageToAll(0xFFFFFFFF,"Модпак для сервера (не обязательно): {FFCC00}"PROJECT_SITE"/modpack {FFFFFF}(если У Вас с ним лагает - удалите его)");
	SendClientMessageToAll(0xFFFFFFFF,"Наш форум (сайт для общения): {FFCC00}"PROJECT_FORUM"");
	SendClientMessageToAll(0xFFFFFFFF,"Мы ВКонтакте: {FFCC00}"VKONTAKTE_COMMUNITY" {FFFFFF}(конкурсы и важная информация)");
	SendClientMessageToAll(0xFFFFFFFF,"Продажа и покупка игровой валюты/имущества/аккаунтов за реальные деньги запрещена правилами сервера");
	SendClientMessageToAll(0xFFFFFFFF,"За нарушение данного правила: удаление аккаунт(а/ов) (деактивация)");
	SendClientMessageToAll(0xFFCC00FF,"_______________________________________________________________________________________________");
}

forward AdvertiseTimer1();
public AdvertiseTimer1()
{
	SendClientMessageToAll(0xFFCC00FF,"_______________________________________________________________________________________________");
	SendClientMessageToAll(0xFFCC00FF,"                                                                                               ");
	SendClientMessageToAll(0xFFFFFFFF,"Хотите получить 50 000 рублей? Тогда {FFCC00}пригласите друга на сервер и пусть он укажет Ваш ник");
	SendClientMessageToAll(0xFFFFFFFF,"(на 5-ом уровне и Вы и Ваш друг получите по 50 000 рублей)");
	SendClientMessageToAll(0xFFFFFFFF,"Также Вы можете получить 10 000 рублей просто так на сайте {FFCC00}"PROJECT_SITE"");
	SendClientMessageToAll(0xFFFFFFFF,"В личном кабинете нажмите на {FFCC00}синий баннер \"VK\"");
	SendClientMessageToAll(0xFFCC00FF,"_______________________________________________________________________________________________");
}

forward AdvertiseTimer2();
public AdvertiseTimer2()
{
	SendClientMessageToAll(0xFFCC00FF,"_______________________________________________________________________________________________");
	SendClientMessageToAll(0xFFCC00FF,"                                                                                               ");
	SendClientMessageToAll(0xFFFFFFFF,"Поддержи область! Пожертвуй рубли в экономику области - {FFCC00}/drop [сумма]");
	SendClientMessageToAll(0xFFFFFFFF,"Продажа и покупка игровой валюты/имущества/аккаунтов за реальные деньги запрещена правилами сервера");
	SendClientMessageToAll(0xFFFFFFFF,"За нарушение данного правила: удаление всех аккаунт(а/ов) на всех серверах (деактивация)");
	SendClientMessageToAll(0xFFCC00FF,"_______________________________________________________________________________________________");
}

forward AdvertiseTimer3();
public AdvertiseTimer3()
{
	SendClientMessageToAll(0xFFCC00FF,"_______________________________________________________________________________________________");
	SendClientMessageToAll(0xFFCC00FF,"                                                                                               ");
	SendClientMessageToAll(0xFFFFFFFF,"Получение дополнительных средств: {FFCC00}"ACCOUNT_REPLENISHMENT"");
	SendClientMessageToAll(0xFFFFFFFF,"При возникновении вопросов/жалоб, введите: {FFCC00}/menu{FFFFFF}, далее выберите: \"Вопросы/жалобы на игроков\"");
	SendClientMessageToAll(0xFFFFFFFF,"Всю полезную информацию Вы можете найти в {FFCC00}/gps{FFFFFF}, {FFCC00}/help {FFFFFF}или на нашем форуме: {FFCC00}"PROJECT_FORUM"");
	SendClientMessageToAll(0xFFCC00FF,"_______________________________________________________________________________________________");
}

forward AdvertiseTimer4();
public AdvertiseTimer4()
{
	SendClientMessageToAll(0xFFCC00FF,"_______________________________________________________________________________________________");
	SendClientMessageToAll(0xFFCC00FF,"                                                                                               ");
	SendClientMessageToAll(0xFFFFFFFF,"Версия данного мода:{FFCC00} Обновление "UPDATE" от "UPDATE_DATA"");
	SendClientMessageToAll(0x99CC00FF,"Скачайте последнюю версию мода:{FFFFFF} youtube.com/MarkRichardsMR");
	SendClientMessageToAll(0xFFFFFFFF,"Разработчик мода ВКонтакте:{FFCC00} vk.com/mark_richards");
	SendClientMessageToAll(0xFFCC00FF,"_______________________________________________________________________________________________");
}

forward AdvertiseTimer5();
public AdvertiseTimer5()
{
	SendClientMessageToAll(0xFFCC00FF,"_______________________________________________________________________________________________");
	SendClientMessageToAll(0xFFCC00FF,"                                                                                               ");
	SendClientMessageToAll(0xFFFFFFFF,"Уважаемые игроки, большая просьба: задавайте вопросы только в /вопрос, а жалобы на игроков - /жалоба (/rep)");
	SendClientMessageToAll(0xFFFFFFFF,"Мы стараемся ответить на все Ваши жалобы и вопросы. Ваше обращение не останется без ответа");
	SendClientMessageToAll(0xFFCC00FF,"_______________________________________________________________________________________________");
}
*/
/*new ID_TRAILER_SYNC = 114;
new ID_UNOCCUPIED_SYNC = 110;
public OnPlayerReceivedPacket(player_id, packet_id, BitStream:bs)
{
    if(packet_id == ID_UNOCCUPIED_SYNC)
    {
        new vehID, seatID, Float:Roll[3];
        BS_IgnoreBits(bs,8);
        BS_ReadValue(bs, RNM_INT16, vehID,
                         RNM_UINT8, seatID,
                         RNM_FLOAT, Roll[0],
                         RNM_FLOAT, Roll[1],
                         RNM_FLOAT, Roll[2]);
        new buff[255];
        if(floatcmp(floatabs(Roll[0]), 30000.0) == 1 ||
           floatcmp(floatabs(Roll[1]), 30000.0) == 1 ||
           floatcmp(floatabs(Roll[2]), 30000.0) == 1)
           {
           	Kick(player_id);
			return false;
           }
	}
    if(packet_id == ID_TRAILER_SYNC)
    {
        new trailerid;
        BS_IgnoreBits(bs,8);
        BS_ReadValue(bs, RNM_UINT16, trailerid); 								// - узнаем ид авто, которое синхронят
        if(GetPlayerState(player_id) != PLAYER_STATE_DRIVER) return false;

        new vehicle_id = GetPlayerVehicleID(player_id); 						// - узнаем ид авто, в котором игрок
        if(!IsTrailerAttachedToVehicle(vehicle_id)) return false; 				// - если у игрока ничего не прицеплено то не принимаем

        new model_car = GetVehicleModel(vehicle_id); 							// - узнаем модель авто игрока
        new model_trailer = GetVehicleModel(trailerid); 						// - узнаем модель того, что синхронят
        if(model_car == 403 || model_car == 514 || model_car == 515 || model_car == 572)
        {
            if(model_trailer == 584 || model_trailer == 435 || model_trailer == 450 || model_trailer == 610 || model_trailer == 611)
            return true;
        }
        if(model_car == 525) return true;
        return false;
    }
    if(packet_id == ID_UNOCCUPIED_SYNC)
    {
        new sVehicleID, seat;
        BS_IgnoreBits(bs, 8);
        BS_ReadValue(bs, RNM_UINT16, sVehicleID, RNM_UINT8, seat);

        if(seat >= 1)
            if(GetPlayerVehicleID(player_id) != sVehicleID) Kick(player_id);
    }
    return true;
}*/

stock GetSpeedKM(playerid)
{
	new Float:PosX, Float:PosY, Float:PosZ, Float:PlayerSpeedDistance;
 	GetVehicleVelocity(GetPlayerVehicleID(playerid), PosX, PosY, PosZ);
	PlayerSpeedDistance = floatmul(floatsqroot(floatadd(floatadd(floatpower(PosX, 2), floatpower(PosY, 2)), floatpower(PosZ, 2))), 170.0);
	new spe = floatround(PlayerSpeedDistance * 1);
	return spe;
}
forward vsystem(playerid);
forward vsysted(playerid);
public vsystem(playerid)
{
    new string[150],months1[12],year,month,day;
    getdate(year, month, day);
    switch(month)
    {
        case 1: months1 = "•HBAP’";
		case 2: months1 = "ЃEBPA‡’";
		case 3: months1 = "MAPT";
		case 4: months1 = "AЊPE‡’";
		case 5: months1 = "MA†";
		case 6: months1 = "…”H’";
		case 7: months1 = "…”‡’";
		case 8: months1 = "AB‚YCT";
		case 9: months1 = "CEHT•ЂP’";
		case 10: months1 = "OKT•ЂP’";
		case 11: months1 = "HO•ЂP’";
		case 12: months1 = "ѓEKAЂP’";

    }
    format(string, sizeof string, "%s %d",months1, day);
    TextDrawSetString(Datum, string);

}
public vsysted(playerid)
{
    new string[150],hours,minutes,seconds;
    gettime(hours, minutes, seconds);
    format(string, sizeof string, "%s%d:%s%d", (hours < 10) ? ("0") : (""), hours, (minutes < 10) ? ("0") : (""), minutes);
    TextDrawSetString(Vrijeme, string);
}
/*stock IsPlayerAfk(playerid)
{
	return player_afk_time[playerid] >= 5 ? (true) : (false);
}*/

forward HideNoticeTextDraw(playerid);
public  HideNoticeTextDraw(playerid) //return TextDrawHideForPlayer(playerid, USE_ALT[i]);
{
    for(new i; i < sizeof USE_ALT; i++) PlayerTextDrawHide(playerid, USE_ALT[i]);
	return 1;
}
//const PLAYER_SYNC = 207;
new VehicleDestroyed = 136;
new ID_UNOCCUPIED_SYNC = 110;
new ID_TRAILER_SYNC = 114;
IRPC:VehicleDestroyed(playerid, BitStream:bs)
{
    new vehicleid;
    BS_ReadUint16(bs, vehicleid);
    if (GetVehicleModel(vehicleid) < 400) return 0;
    return OnVehicleDeathRequest(vehicleid, playerid);
}

forward OnVehicleDeathRequest(vehicleid, killerid);
public OnVehicleDeathRequest(vehicleid, killerid)
{
    new Float:vhealth;
    GetVehicleHealth(vehicleid, vhealth);
    if (vhealth > 300.0) return 0;
    return 1;
}
public OnIncomingPacket(playerid, packetid, BitStream:bs){
    switch(packetid) {
    case VEHICLE_SYNC:{
            new inCarData[PR_InCarSync];
            BS_IgnoreBits(bs, eight);
            BS_ReadInCarSync(bs, inCarData);
            if inCarData[PR_position][two] == BulletCrasher *then {
                new string[MAX_CHATBUBBLE_LENGTH];
                format(string,sizeof(string),"[AC]: {FFCC00}%s {999999}|ID:%d| {00FF00}auto-kick {ff3838}[Motiv: BulletCrasher]",GetName(playerid),playerid);
                SendAdminMessage(red,string);
                Kick(playerid);
                return false;
            }
        }
    case PLAYER_SYNC:{
            new onFootData[PR_OnFootSync];
            BS_IgnoreBits(bs,eight);
            BS_ReadOnFootSync(bs, onFootData);
            if onFootData[PR_position][two] == BulletCrasher *then {
                new string[MAX_CHATBUBBLE_LENGTH];
                format(string,sizeof(string),"[AC]: {FFCC00}%s {999999}|ID:%d| {00FF00}auto-kick {ff3838}[Motiv: BulletCrasher]",GetName(playerid),playerid);
                SendAdminMessage(red,string);
                Kick(playerid);
                return false;
            }
        }
    case PASSENGER_SYNC:{
            new passengerData[PR_PassengerSync];
            BS_IgnoreBits(bs, eight);
            BS_ReadPassengerSync(bs, passengerData);
            if GetPlayerVehicleSeat(playerid) == NULL *then {
                new string[MAX_CHATBUBBLE_LENGTH];
                format(string,sizeof(string),"[AC]: {FFCC00}%s {999999}|ID:%d| {00FF00}auto-kick {ff3838}[Motiv: BadVehicleCrasher]",GetName(playerid),playerid);
                SendAdminMessage(red,string);
                Kick(playerid);
                return false;
            }
            if passengerData[PR_position][two] == BulletCrasher *then {
                new string[MAX_CHATBUBBLE_LENGTH];
                format(string,sizeof(string),"[AC]: {FFCC00}%s {999999}|ID:%d| {00FF00}auto-kick {ff3838}[Motiv: BulletCrasher]",GetName(playerid),playerid);
                SendAdminMessage(red,string);
                Kick(playerid);
                return false;
            }
        }

    }
    /*if(packetid == ID_UNOCCUPIED_SYNC)
    {
        new vehID, seatID, Float:Roll[3];
        BS_IgnoreBits(bs,8);
        BS_ReadValue(bs, PR_INT16, vehID,
                         PR_UINT8, seatID,
                         PR_FLOAT, Roll[0],
                         PR_FLOAT, Roll[1],
                         PR_FLOAT, Roll[2]);
        new buff[255];
        if(floatcmp(floatabs(Roll[0]), 30000.0) == 1 ||
           floatcmp(floatabs(Roll[1]), 30000.0) == 1 ||
           floatcmp(floatabs(Roll[2]), 30000.0) == 1)
            {
             Kick(playerid);
             return false;
            }
	}*/
    if(packetid == ID_TRAILER_SYNC)
    {
        new trailerid;
        BS_IgnoreBits(bs,8);
        BS_ReadValue(bs, PR_UINT16, trailerid);									// - узнаем ид авто, которое синхронят
        if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return false;

        new vehicleid = GetPlayerVehicleID(playerid);							// - узнаем ид авто, в котором игрок
        if(!IsTrailerAttachedToVehicle(vehicleid)) return false;				// - если у игрока ничего не прицеплено то не принимаем

        new model_car = GetVehicleModel(vehicleid); 							// - узнаем модель авто игрока
        new model_trailer = GetVehicleModel(trailerid); 						// - узнаем модель того, что синхронят
        if(model_car == 403 || model_car == 514 || model_car == 515 || model_car == 572)
        {
            if(model_trailer == 584 || model_trailer == 435 || model_trailer == 450 || model_trailer == 610 || model_trailer == 611)
            return true;
        }
        if(model_car == 525) return true;
        return false;
    }
    if(packetid == ID_UNOCCUPIED_SYNC)
    {
        new sVehicleID, seat;
        BS_IgnoreBits(bs, 8);
        BS_ReadValue(bs, PR_UINT16, sVehicleID, PR_UINT8, seat);

        if(seat >= 1)
            if(GetPlayerVehicleID(playerid) != sVehicleID) Kick(playerid);
    }
    if(packetid == PLAYER_SYNC)
    {
        new
            onFootData[PR_OnFootSync];

        BS_IgnoreBits(bs, 8);
        BS_ReadOnFootSync(bs, onFootData);

        if(onFootData[PR_specialAction] == SPECIAL_ACTION_ENTER_VEHICLE)
        {
            if(onFootData[PR_keys] & KEY_SPRINT || onFootData[PR_keys] & KEY_JUMP)
            {
                onFootData[PR_keys] = onFootData[PR_keys] & ~KEY_SPRINT;
				onFootData[PR_keys] = onFootData[PR_keys] & ~KEY_JUMP;

                BS_SetWriteOffset(bs, 8);
                BS_WriteOnFootSync(bs, onFootData);
            }
        }
    }
    if (packetid == PLAYER_SYNC)
    {
        new onFootData[PR_OnFootSync];

        BS_IgnoreBits(bs, 8); // ignore packetid (byte)
        BS_ReadOnFootSync(bs, onFootData);

        if (onFootData[PR_surfingVehicleId] != 0 &&
            onFootData[PR_surfingVehicleId] != INVALID_VEHICLE_ID
        ) {
			if ((floatcmp(floatabs(onFootData[PR_surfingOffsets][0]), 10.0) != -1) ||
				(floatcmp(floatabs(onFootData[PR_surfingOffsets][1]), 10.0) != -1) ||
				(floatcmp(floatabs(onFootData[PR_surfingOffsets][2]), 10.0) != -1))
			{
                onFootData[PR_surfingOffsets][0] = onFootData[PR_surfingOffsets][1] = onFootData[PR_surfingOffsets][2] = 0.0;

                BS_SetWriteOffset(bs, 8);
                BS_WriteOnFootSync(bs, onFootData); // rewrite
            }
        }
    }
    return 1;
}

public: LoadEntrances()
{
	new time = GetTickCount();

	new rows, fields;
	cache_get_data(rows, fields);

	if(rows)
	{
		for(new idx; idx < rows; idx ++)
		{
			SetEntranceData(idx, E_SQL_ID, cache_get_row_int(idx, 0, dbHandle));
			SetEntranceData(idx, POS_X, cache_get_row_float(idx, 1, dbHandle));
			SetEntranceData(idx, POS_Y, cache_get_row_float(idx, 2, dbHandle));
			SetEntranceData(idx, POS_Z, cache_get_row_float(idx, 3, dbHandle));
			SetEntranceData(idx, EXIT_POS_X, cache_get_row_float(idx, 4, dbHandle));
			SetEntranceData(idx, EXIT_POS_Y, cache_get_row_float(idx, 5, dbHandle));
			SetEntranceData(idx, EXIT_POS_Z, cache_get_row_float(idx, 6, dbHandle));
			SetEntranceData(idx, EXIT_ANGLE, cache_get_row_float(idx, 7, dbHandle));
			SetEntranceData(idx, E_PRICE_ROOM, cache_get_row_int(idx, 8, dbHandle));

			SetEntranceData(idx, E_PICKUP, CreateDynamicPickup(1318, 23, GetEntranceData(idx, POS_X), GetEntranceData(idx, POS_Y), GetEntranceData(idx, POS_Z), -1, -1));
			SetEntranceData(idx, E_AREA_ENTER, CreateDynamicSphere(GetEntranceData(idx, POS_X), GetEntranceData(idx, POS_Y), GetEntranceData(idx, POS_Z), 1.0));

			TOTALENTRANCE ++;
		}
	}

	for(new i; i < sizeof coord_rooms; i ++)
	{
		g_area_rooms[i] = CreateDynamicSphere(coord_rooms[i][0], coord_rooms[i][1], coord_rooms[i][2], 1.0);

		CreatePickup(19197, 23, coord_rooms[i][0], coord_rooms[i][1], coord_rooms[i][2], -1);
	
		CreatePickup(19197, 23, -379.4767,1127.6851,2712.7734, -1);
        CreatePickup(1239, 23, -378.0949,1128.7030,2712.7734, -1);
        CreatePickup(19197, 23, -691.0283,-460.0852,3147.0801, -1);

		STRING_GLOBAL[0] = EOS;
		format(STRING_GLOBAL, sizeof STRING_GLOBAL, "- Квартира №%d -", i + 1);
		CreateDynamic3DTextLabel(STRING_GLOBAL, 0x3399FFFF, coord_rooms[i][0], coord_rooms[i][1], coord_rooms[i][2] + 1.0, 5.0);
	}

	printf("[Загружено подъездов]: <%d>. Потрачено: <%i ms>.", rows, GetTickCount() - time);
	return 1;
}

stock UpdateEntrance(idx)
{
	new icon = 32;

	for(new i; i < MAX_ROOMS; i ++)
	{
		if(strcmp(g_rooms[idx][i][ER_OWNER], "None"))
			continue;

		icon = 31;

		break;
	}

	if(IsValidDynamicMapIcon(g_entrance[idx][E_MAP_ICON]))
	{
		DestroyDynamicMapIcon(g_entrance[idx][E_MAP_ICON]);
		SetEntranceData(idx, E_MAP_ICON, CreateDynamicMapIcon(GetEntranceData(idx, POS_X), GetEntranceData(idx, POS_Y), GetEntranceData(idx, POS_Z), icon, 0, 0, 0, -1, STREAMER_MAP_ICON_SD, MAPICON_LOCAL));
	}
	else SetEntranceData(idx, E_MAP_ICON, CreateDynamicMapIcon(GetEntranceData(idx, POS_X), GetEntranceData(idx, POS_Y), GetEntranceData(idx, POS_Z), icon, 0, 0, 0, -1, STREAMER_MAP_ICON_SD, MAPICON_LOCAL));

	return 1;
}

public: LoadRooms()
{
	new time = GetTickCount();
	new rows, fields;
	cache_get_data(rows, fields);

	new room_id,
		entranceid,
		text_buffer = -1;

	if(rows)
	{
		for(new idx; idx < rows; idx ++)
		{
			entranceid = cache_get_row_int(idx, 1, dbHandle);

			if(entranceid != text_buffer)
			{
				room_id = 0;
				UpdateEntrance(entranceid);
			}

			if(room_id > 22) continue;

			SetRoomData(entranceid, room_id, ER_SQL_ID, cache_get_row_int(idx, 0, dbHandle));
			SetRoomData(entranceid, room_id, ER_PAY, cache_get_row_int(idx, 3, dbHandle));
			cache_get_field_content(idx, "owner", g_rooms[entranceid][room_id][ER_OWNER], dbHandle, MAX_PLAYER_NAME);
			SetRoomData(entranceid, room_id, ER_LOCK, bool: cache_get_row_int(idx, 4, dbHandle));

			text_buffer = entranceid;
			room_id ++;

			TOTALROOMS ++;

			//printf("sql: %d roomid: %d entranceid: %d pay: %d owner: %s lock: %d", GetRoomData(entranceid, room_id, ER_SQL_ID), room_id, entranceid, GetRoomData(entranceid, room_id, ER_PAY), GetRoomData(entranceid, room_id, ER_OWNER), GetRoomData(entranceid, room_id, ER_LOCK));
		}
	}

	printf("[Загружено квартир]: <%d>. Потрачено: <%i ms>.", TOTALROOMS, GetTickCount() - time);

	return 1;
}

stock ShowPlayerEntraceMenu(playerid)
{
	ShowPlayerDialog
	(
		playerid, DIALOG_ENTRACE_MENU, DIALOG_STYLE_LIST,
		"{FFCC00}Меню подъезда",
		"{FFCC00}1. {FFFFFF}Список жильцов\n"\
		"{FFCC00}2. {FFFFFF}Регистрация\n"\
		"{FFCC00}3. {FFFFFF}Меню жильца",
		"Далее", "Закрыть"
	);
	return 1;
}

stock ShowPlayerFreeRomm(playerid, entranceid)
{
	if(0 <= entranceid <= MAX_ENTRANCES-1)
	{
		STRING_GLOBAL = "Квартира\t\tСтоимость\t\tОплачено\t\tВладелец\n\n{FFFFFF}";

		new fmt_str[144],
			owner[MAX_PLAYER_NAME];

		for(new idx; idx < MAX_ROOMS; idx ++)
		{
			owner = "{FFCC00}Отсутствует";

			if(strcmp(g_rooms[entranceid][idx][ER_OWNER], "None")) format(owner, sizeof owner, "{ff614a}%s", GetRoomData(entranceid, idx, ER_OWNER));

			format(fmt_str, sizeof fmt_str, "{FFCC00}№%d\t\t\t{FFFFFF}%d\t\t%d из 30\t\t\t%s\n", idx + 1, GetEntranceData(entranceid, E_PRICE_ROOM),  GetRoomData(entranceid, idx, ER_PAY), owner);
			strcat(STRING_GLOBAL, fmt_str);
		}

		ShowPlayerDialog
		(
			playerid, 0, DIALOG_STYLE_MSGBOX,
			"{FFCC00}Список жильцов",
			STRING_GLOBAL,
			"Закрыть", ""
		);

	}
	return 1;
}
//==============================================================================
stock GetFreeEntranceRoom(entranceid)
{
	new free_room = -1;

	if(0 <= entranceid <= MAX_ENTRANCES-1)
	{
		for(new idx; idx < MAX_ROOMS; idx ++)
		{
			if(strcmp(g_rooms[entranceid][idx][ER_OWNER], "None"))
				continue;

			free_room = idx;

			break;
		}
	}

	return free_room;
}
//==============================================================================
stock SetPlayerPosInRoom(playerid, entranceid = -1, roomid = -1)
{
	if(entranceid == -1 || roomid== -1)
		return 1;

	FreezePlayer(playerid, 2000);
	SetPlayerPos(playerid, -691.0530,-456.7366,3147.0801);
	SetPlayerFacingAngle(playerid, 360);
	SetPlayerInterior(playerid, 1);
	SetPlayerVirtualWorld(playerid, ((entranceid + 1) * 400) + (roomid + 2000));

	PI[playerid][P_IN_ROOM] = roomid;
	PI[playerid][P_IN_ENTRANCE] = entranceid;

	return 1;
}
//==============================================================================
stock ShowPlayerRoomInfo(playerid, entranceid = -1, roomid = -1)
{
	if(entranceid == -1 || roomid== -1)
		return 1;

	new owner[MAX_PLAYER_NAME] = "Отсутствует";

	if(strcmp(g_rooms[entranceid][roomid][ER_OWNER], "None")) format(owner, sizeof owner, "%s", GetRoomData(entranceid, roomid, ER_OWNER));

	STRING_GLOBAL[0] = EOS;

	format
	(
		STRING_GLOBAL, sizeof STRING_GLOBAL,
		"{FFFFFF}Квартира №{FFCC00}%d\n"\
		"{FFFFFF}Владелец: {FFCC00}%s\n"\
		"{FFFFFF}Оплата в сутки: %d рублей\n"\
		"{FFFFFF}Статус: %s\n\n"\
		"{FFFFFF}Вы хотите войти в эту квартиру?",
		(roomid % 22) + 1,
		owner,
		GetEntranceData(entranceid, E_PRICE_ROOM),
		GetRoomData(entranceid, roomid, ER_LOCK) == true ? "{99CC00}Открыта" : "{ff614a}Закрыта"
	);

	ShowPlayerDialog
	(
		playerid, DIALOG_ROOM_ENTER, DIALOG_STYLE_MSGBOX,
		"{FFCC00}Квартира",
		STRING_GLOBAL,
		"Войти", "Отмена"
	);

	g_player_listitem_use[playerid] = roomid;

	return 1;
}
//==============================================================================
stock ShowPlayerDialogPayRoom(playerid, entranceid = -1, roomid = -1)
{
	if(entranceid == -1 || roomid== -1)
		return 1;

	new fmt_dialog[170];

	format
	(
		fmt_dialog, sizeof fmt_dialog,
		"{ffffff}Квартира:\t\t\t\t\t№%d\n"\
		"Оплаченных дней:\t\t\t\t%d из 30\n"\
		"Ежедневная плата:\t\t\t\t%d руб\n"\
		"На сколько дней Вы хотите оплатить квартиру?",
		(roomid % 22) + 1,
		GetRoomData(entranceid, roomid, ER_PAY),
		GetEntranceData(entranceid, E_PRICE_ROOM)
	);

	return ShowPlayerDialog(playerid, DIALOG_PAY_ROOM, DIALOG_STYLE_INPUT, "{ffcc00}Оплата квартиры", fmt_dialog, "Оплатить", "Назад");
}
//==============================================================================
stock CheckServerProperty()
{
	for(new entranceid = TOTALENTRANCE; entranceid > 0; entranceid --)
	{
		for(new roomid = 22; roomid > 0; roomid --)
		{
			if(!strcmp("None", g_rooms[entranceid][roomid][ER_OWNER], true)) continue;

			if(GetRoomData(entranceid, roomid, ER_PAY) < 1)
			{
				new targetid = GetPlayerID(g_rooms[entranceid][roomid][ER_OWNER]);
				if(targetid != INVALID_PLAYER_ID)
				{
					SendClientMessage(targetid, COLOR_YELLOW, "Ваша квартира была продана за неуплату");

					PI[targetid][P_ENTRANCE] =
					PI[targetid][P_ROOM] = -1;

					MysqlUpdatePlayerInt(targetid, "entrance", PI[targetid][P_ENTRANCE]);
					MysqlUpdatePlayerInt(targetid, "room", PI[targetid][P_ROOM]);
				}

				STRING_GLOBAL[0] = EOS;
				format(STRING_GLOBAL, sizeof STRING_GLOBAL, "UPDATE accounts SET entrance=-1, room=-1 WHERE name='%s'", g_rooms[entranceid][roomid][ER_OWNER]);
				mysql_query(dbHandle, STRING_GLOBAL);

				g_rooms[entranceid][roomid][ER_PAY] = 1;

				g_rooms[entranceid][roomid][ER_OWNER] = EOS;
				strcat(g_rooms[entranceid][roomid][ER_OWNER], "None");
			}
			else
			{
				g_rooms[entranceid][roomid][ER_PAY] --;
			}

			STRING_GLOBAL[0] = EOS;
			format(STRING_GLOBAL, sizeof STRING_GLOBAL, "UPDATE rooms SET owner='%s', pay=%d WHERE id=%d", g_rooms[entranceid][roomid][ER_OWNER], g_rooms[entranceid][roomid][ER_PAY], g_rooms[entranceid][roomid][ER_SQL_ID]);
			mysql_query(dbHandle, STRING_GLOBAL);
		}

		UpdateEntrance(entranceid);
	}
	return 1;
}
//==============================================================================
stock SendMess(playerid, E_MSG_CMD_NAME:messageid)
{
	if(!IsPlayerConnected(playerid))
		return false;

	for(new id = sizeof(MSG_CMD_STRUCT)-1; id != -1; --id)
	{
		if(MSG_CMD_STRUCT[id][msgID] != messageid)
			continue;
		SendClientMessage(playerid, MSG_CMD_STRUCT[id][msgColor], MSG_CMD_STRUCT[id][msgText]);
		break;
	}
	return true;
}
//==============================================================================
/*stock AC_KICK(USERID, const SAC_NAME[], SAC_CODE)
{

	if(!AC_STRUCT[SAC_CODE - 1][RAC_STATUS]) return 1;

	if(GetTickCount()-GetPVarInt(USERID, "-Cheater") < 3000) return 1;
	SetPVarInt(USERID, "-Cheater", GetTickCount());

	//if(PI[USERID][pAdmin] > 0 && AdminLogged[USERID] == true && !PG_DATA[USERID][USE_CRASHER]) return 1;

	new ipstr[16];
	GetPlayerIp(USERID, ipstr, 16);

	new frmt_str[144];
	format(frmt_str, 144, "{F66917}[R-AC] {A3A3A3}%s[%d] был кикнут по подозрению в читерстве (%s) <#0%i> ", GetName(USERID), USERID, SAC_NAME, SAC_CODE);

	foreach(new playerid: Admins)
	{
		if(AdminInfo[playerid][admAclog] == 0)
			continue;

		SendClientMessage(playerid, 0xEB7208FF, frmt_str);
	}

	add_server_log(frmt_str, 39);

    new fmt_str[128];

	new y, m, d;
	getdate(y, m, d);

	new hh, mm, ss;
	gettime(hh, mm, ss);

	SendClientMessage(USERID, 0xF66917FF, "{F66917}[AC] {FCD736} Вы были кикнуты системой защиты по подозрению в использовании запрещенного ПО");
	format(fmt_str, 128, "{F66917}[AC] {FCD736} Дата и время: %02d-%02d-%04d / %02d:%02d:%02d | Код анти-чита: %d(%s)", d, m, y, hh, mm, ss, SAC_CODE, SAC_NAME);
	SendClientMessage(USERID, 0xF66917FF, fmt_str);
	SendClientMessage(USERID, 0xF66917FF, "{F66917}[AC] {FCD736} Если Вы считаете, что наказание было выдано ложно - обратитесь к старшей администрации");

	SetTimerEx("DisconnectPlayer",100,0,"i", USERID);

    AC_STRUCT[SAC_CODE - 1][RAC_COUNT] ++;

	return true;
}*/

/*stock ResetPlayerWeaponAC (playerid)
{

    for(new i = 0; i < 47; i++)
    {
        WeaponInfo[playerid][i] = false;
        AmmoInfo[playerid][i] = 0;
    }
    for(new i = 0; i < 13; i++) AmmoSlot[playerid][i] = 0;

    for(new i = 0; i < 12; i++)
 	{
        PI[playerid][pGun][i] = 0;
		PI[playerid][pAmmo][i] = 0;
	}

    ResetPlayerWeapons (playerid);

    return 1;
}*/
//==============================================================================
stock GetAdminsOnline()
{
	new Online;
	foreach(new i : Admins)
	{
		if(PlayerLogged[i]) if(PI[i][pAdmin] && PI[i][pAdmin] != ADM_NONE) Online ++;
	}
	return Online;
}
//==============================================================================
stock GetSupportsOnline()
{
	new Online;
	foreach(new i : Supports)
	{
		if(PlayerLogged[i]) if(PI[i][pSupport] && PI[i][pSupport] != 0) Online ++;
	}
	return Online;
}
//==============================================================================
stock GetYouTubersOnline()
{
	new Online;
	foreach(new i : YouTubers)
	{
		if(PlayerLogged[i]) if(PI[i][pYouTuber] && PI[i][pYouTuber] != 0) Online ++;
	}
	return Online;
}
//==============================================================================
//DestroyPlayerMapDraws(playerid) //на дисконект
//{
//	for(new i; i < sizeof gps_support_td; i++) TextDrawHideForPlayer(playerid, gps_support_td[i]);
//	for(new i; i < sizeof arzp_PTD; i++) TextDrawHideForPlayer(playerid, arzp_PTD[i]);
//	return true;
//}
//==============================================================================
//CreatePlayerMapDraws(playerid)
//{
//	for(new i; i < sizeof gps_support_td; i++) TextDrawShowForPlayer(playerid, gps_support_td[i]);
//	for(new i; i < sizeof arzp_PTD; i++) TextDrawShowForPlayer(playerid, arzp_PTD[i]);
//	return true;
//}
//==============================================================================
stock AC_SetVehicleToRespawn(vehicleid)
{
   	SetVehicleToRespawn(vehicleid);

    new Float:x, Float:y, Float:z, Float:a;
    GetVehiclePos(vehicleid, x, y, z);
	GetVehicleZAngle(vehicleid, a);
	return 1;
}
const UPDATE_SCORES_PINGSIPS = 105;

new rpc_105_used[MAX_PLAYERS] = 0;

public OnIncomingRPC(playerid, rpcid, BitStream:bs)

{
switch(rpcid)
{
	case UPDATE_SCORES_PINGSIPS:
	{
		if(!rpc_105_used[playerid])
		{
			SetPVarInt(playerid, "ac_trainer", GetTickCount());

			rpc_105_used[playerid] = 1;

		}
		else
		{
			new ac_time_value = GetTickCount() - GetPVarInt(playerid, "ac_trainer");

			if(ac_time_value > 4900 && ac_time_value < 5100) Kick(playerid);

			rpc_105_used[playerid] = 0;

		}

	}

}
return true;
}
//==============================================================================



//========================[ Система вдыхания/выдыхания ]========================
stock GetPlayerSpeedPar(playerid)
{
    new Float:ST[4];
    if(IsPlayerInAnyVehicle(playerid))
    GetVehicleVelocity(GetPlayerVehicleID(playerid),ST[0],ST[1],ST[2]);
    else GetPlayerVelocity(playerid,ST[0],ST[1],ST[2]);
    ST[3] = floatsqroot(floatpower(floatabs(ST[0]), 2.0) + floatpower(floatabs(ST[1]), 2.0) + floatpower(floatabs(ST[2]), 2.0)) * 179.28625;
    return floatround(ST[3]);
}
//==============================================================================
stock ProxDetectorS(Float:radi, playerid, targetid)
{
    new Float:p[3];
    if(!IsPlayerConnected(playerid)) return 0;
    if(!IsPlayerConnected(targetid)) return 0;
    if(!GetPlayerPos(targetid, p[0], p[1], p[2])) return 0;
	if(!IsPlayerInRangeOfPoint(playerid, radi, p[0], p[1], p[2])) return 0;
	return 1;
}

stock GetNearestVehicle(playerid)
{
	for(new i = 0; i < MAX_VEHICLES; i++)
	{
		if(GetVehicleModel(i))
		{
			new Float:Xx, Float:Yy, Float:Zz;
			GetVehiclePos(i, Xx, Yy, Zz);
			if(PlayerToPoint(8.0, playerid, Xx, Yy, Zz)) return i;
		}
	}
	return 1;
}
stock PlayerToPoint(Float:radi, playerid, Float:x, Float:y, Float:z)
{
	if(IsPlayerConnected(playerid))
	{
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		tempposx = (oldposx -x);
		tempposy = (oldposy -y);
		tempposz = (oldposz -z);
		//printf("DEBUG: X:%f Y:%f Z:%f",posx,posy,posz);
		if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
		{
			return 1;
		}
	}
	return 0;
}
public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	if(PI[playerid][pAdmin] && AdminLogged[playerid] == true)
	{
	    SetPlayerPosFindZ(playerid, fX, fY, fZ);
	}
	return 1;
}
stock SelectAnimation(const playerid, const animation)
{
        switch(animation)
        {
        case 0: SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE1);
        case 1: SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE2);
        case 2: SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE3);
        case 3: SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE4);
        case 4: ApplyAnimation(playerid, !"DANCING", !"DAN_Left_A" ,4.1,1,0,0,0,0,0);
        case 5: ApplyAnimation(playerid, !"DANCING", !"dnce_M_a" ,4.1,1,0,0,0,0,0);
        case 6: ApplyAnimation(playerid, !"ON_LOOKERS", !"wave_loop" ,4.1,1,0,0,0,0,0);
        case 7: ApplyAnimation(playerid, !"BEACH", !"bather" ,4.1,1,0,0,0,0,0);
        case 8: ApplyAnimation(playerid, !"ped", !"WALK_drunk" ,4.1,1,1,1,0,0,0);
        case 9: ApplyAnimation(playerid, !"ped", !"Crouch_Roll_L" , 4.1,1,1,1,0,0,0);
        case 10: ApplyAnimation(playerid, !"ped", !"endchat_03" ,4.1,1,0,0,0,0,0);
        case 11: ApplyAnimation(playerid, !"benchpress", !"gym_bp_celebrate" ,4.1,1,0,0,0,0,0);
        case 12: ApplyAnimation(playerid, !"ped", !"cower" ,4.1,1,0,0,0,0,0);
        case 13: ApplyAnimation(playerid, !"BOMBER", !"BOM_Plant" ,4.1,0,0,0,0,0,0);
        case 14: ApplyAnimation(playerid, !"SHOP", !"ROB_Shifty" ,4.1,0,0,0,0,0,0);
        case 15: ApplyAnimation(playerid, !"SHOP", !"ROB_Loop_Threat" ,4.1,1,0,0,0,0,0);
        case 16: ApplyAnimation(playerid, !"COP_AMBIENT", !"Coplook_loop" ,4.1,1,0,0,0,0,0);
        case 17: ApplyAnimation(playerid, !"FOOD", !"EAT_Vomit_P" ,4.1,0,0,0,0,0,0);
        case 18: ApplyAnimation(playerid, !"FOOD", !"EAT_Burger" ,4.1,0,0,0,0,0,0);
        case 19: ApplyAnimation(playerid, !"SWEET", !"sweet_ass_slap" ,4.1,0,0,0,0,0,0);
        case 20: ApplyAnimation(playerid, !"DEALER", !"DEALER_DEAL" ,4.1,0,0,0,0,0,0);
        case 21: ApplyAnimation(playerid, !"CRACK", !"crckdeth2" ,4.1,1,0,0,0,0,0);
        case 22: ApplyAnimation(playerid, !"LOWRIDER", !"M_smklean_loop" ,4.1,1,0,0,0,0,0);
        case 23: ApplyAnimation(playerid, !"LOWRIDER", !"F_smklean_loop" ,4.1,1,0,0,0,0,0);
        case 24: ApplyAnimation(playerid, !"BEACH", !"ParkSit_M_loop" ,4.1,1,0,0,0,0,0);
        case 25: ApplyAnimation(playerid, !"PARK", !"Tai_Chi_Loop" ,4.1,1,0,0,0,0,0);
        case 26: ApplyAnimation(playerid, !"BAR", !"dnk_stndF_loop" ,4.1,1,0,0,0,0,0);
        case 27: ApplyAnimation(playerid, !"DANCING", !"DAN_Right_A" ,4.1,1,0,0,0,0,0);
        case 28: ApplyAnimation(playerid, !"BSKTBALL", !"BBALL_def_loop" ,4.1,1,0,0,0,0,0);
        case 29: ApplyAnimation(playerid, !"MISC", !"plyr_shkhead" ,4.1,0,0,0,0,0,0);
        case 30: ApplyAnimation(playerid, !"BSKTBALL", !"BBALL_idle" ,4.1,0,0,0,0,0,0);
        case 31: ApplyAnimation(playerid, !"CAMERA", !"camstnd_cmon" ,4.1,1,0,0,0,0,0);
        case 32: ApplyAnimation(playerid, !"SHOP", !"SHP_Rob_HandsUP" ,4.1,1,0,0,0,0,0);
        case 33: ApplyAnimation(playerid, !"CRACK", !"crckidle2" ,4.1,1,0,0,0,0,0);
        case 34: ApplyAnimation(playerid, !"CRACK", !"crckidle4" ,4.1,1,0,0,0,0,0);
        case 35: ApplyAnimation(playerid, !"DEALER", !"DEALER_IDLE" ,4.1,1,0,0,0,0,0);
        case 36: ApplyAnimation(playerid, !"GANGS", !"leanIDLE" ,4.1,1,0,0,0,0,0);
        case 37: ApplyAnimation(playerid, !"GANGS", !"shake_carSH" ,4.1,0,0,0,0,0,0);
        case 38: ApplyAnimation(playerid, !"GANGS", !"smkcig_prtl" ,4.1,0,0,0,0,0,0);
        case 39: ApplyAnimation(playerid, !"BEACH", !"ParkSit_W_loop" ,4.1,1,0,0,0,0,0);
        case 40: ApplyAnimation(playerid, !"INT_HOUSE", !"LOU_Loop" ,4.1,1,0,0,0,0,0);
        case 41: ApplyAnimation(playerid, !"INT_OFFICE", !"OFF_Sit_Bored_Loop" ,4.1,1,0,0,0,0,0);
        case 42: ApplyAnimation(playerid, !"INT_OFFICE", !"OFF_Sit_Idle_Loop" ,4.1,1,0,0,0,0,0);
        case 43: ApplyAnimation(playerid, !"INT_OFFICE", !"OFF_Sit_Type_Loop" ,4.1,1,0,0,0,0,0);
        case 44: ApplyAnimation(playerid, !"INT_SHOP", !"shop_shelf" ,4.1,1,0,0,0,0,0);
        case 45: ApplyAnimation(playerid, !"JST_BUISNESS", !"girl_02" ,4.1,1,0,0,0,0,0);
        case 46: ApplyAnimation(playerid, !"KISSING", !"GF_StreetArgue_02" ,4.1,0,0,0,0,0,0);
        case 47: ApplyAnimation(playerid, !"KISSING", !"Grlfrd_Kiss_01" ,4.1,0,0,0,0,0,0);
        case 48: ApplyAnimation(playerid, !"KISSING", !"Grlfrd_Kiss_02" ,4.1,0,0,0,0,0,0);
        case 49: ApplyAnimation(playerid, !"KISSING", !"Grlfrd_Kiss_03" ,4.1,0,0,0,0,0,0);
        case 50: ApplyAnimation(playerid, !"LOWRIDER", !"RAP_B_Loop" ,4.1,1,0,0,0,0,0);
        case 51: ApplyAnimation(playerid, !"MEDIC", !"CPR" ,4.1,1,0,0,0,0,0);
        case 52: ApplyAnimation(playerid, !"MISC", !"bitchslap" ,4.1,1,0,0,0,0,0);
        case 53: ApplyAnimation(playerid, !"MISC", !"bng_wndw" ,4.1,1,0,0,0,0,0);
        case 54: ApplyAnimation(playerid, !"MISC", !"KAT_Throw_K" ,4.1,0,0,0,0,0,0);
        case 55: ApplyAnimation(playerid, !"MISC", !"SEAT_LR" ,4.1,1,0,0,0,0,0);
        case 56: ApplyAnimation(playerid, !"ped", !"SEAT_idle" ,4.1,1,0,0,0,0,0);
        case 57: ApplyAnimation(playerid, !"ON_LOOKERS", !"lkup_loop" ,4.1,1,0,0,0,0,0);
        case 58: ApplyAnimation(playerid, !"ON_LOOKERS", !"Pointup_loop" ,4.1,1,0,0,0,0,0);
        case 59: ApplyAnimation(playerid, !"ON_LOOKERS", !"panic_loop" ,4.1,1,0,0,0,0,0);
        case 60: ApplyAnimation(playerid, !"ON_LOOKERS", !"shout_02" ,4.1,1,0,0,0,0,0);
        case 61: ApplyAnimation(playerid, !"PAULNMAC", !"Piss_loop" ,4.1,1,0,0,0,0,0);
        case 62: ApplyAnimation(playerid, !"GHANDS", !"gsign1LH" ,4.1,1,0,0,0,0,0);
        case 63: ApplyAnimation(playerid, !"ped", !"IDLE_taxi" ,4.1,1,0,0,0,0,0);
        case 64: ApplyAnimation(playerid, !"POLICE", !"Door_Kick" ,4.1,0,0,0,0,0,0);
        case 65: ApplyAnimation(playerid, !"POLICE", !"CopTraf_Stop" ,4.1,1,0,0,0,0,0);
        case 66: ApplyAnimation(playerid, !"RIOT", !"RIOT_ANGRY_B" ,4.1,1,0,0,0,0,0);
        case 67: ApplyAnimation(playerid, !"LOWRIDER", !"RAP_C_Loop" ,4.1,1,0,0,0,0,0);
        case 68: ApplyAnimation(playerid, !"SWAT", !"gnstwall_injurd" ,4.1,1,0,0,0,0,0);
        case 69: ApplyAnimation(playerid, !"SWEET", !"Sweet_injuredloop" ,4.1,1,0,0,0,0,0);
        case 70: ApplyAnimation(playerid, !"RIOT", !"RIOT_ANGRY" ,4.1,1,0,0,0,0,0);
        case 71: ApplyAnimation(playerid, !"GHANDS", !"gsign2" ,4.1,1,0,0,0,0,0);
        case 72: ApplyAnimation(playerid, !"GHANDS", !"gsign4" ,4.1,1,0,0,0,0,0);
        case 73: ApplyAnimation(playerid, !"GHANDS", !"gsign5" ,4.1,1,0,0,0,0,0);
        default:
                {
                        ShowPlayerDialog(playerid, 000, DIALOG_STYLE_MSGBOX
                        ,
                        !"{FFCD00}Информация", !"{FFFFFF}Для быстрого запуска нужной анимации \
                                можно использовать {66CC33}/anim(list) [номер анимации из списка]", !"Закрыть", ""
                        );
                }
        }
        if(3 < animation < 74)
        TextDrawShowForPlayer(playerid, enable_animation_TD);

        return true;
}
stock HospitalHealth(playerid)
{
    if(GetPVarInt(playerid, "lechenie") == 1)
    {
       if(PI[playerid][pHeal] < 99.00)
       {
			if(PI[playerid][pVip])
			{
			    PI[playerid][pHeal] += 3;
			    GameTextForPlayer(playerid,"~g~+3 HP",300,4);
				SetHealth(playerid,PI[playerid][pHeal]);
			}
			else
			{
			    PI[playerid][pHeal] += 1;
			    GameTextForPlayer(playerid,"~g~+1 HP",300,4);
			    SetHealth(playerid,PI[playerid][pHeal]);
			}
			PlayerPlaySound(playerid, 17803, 0.0, 0.0, 0.0);
       }
       else
	   {
           SetPVarInt(playerid, "lechenie", 0);
           PlayerDied[playerid] = false;
           SendClientMessage(playerid, COLOR_LIME, "Курс лечения пройден!");
           SendClientMessage(playerid, COLOR_WHITE, "Вы выписаны из больницы");
	   }
	}
	return 1;
}
//==============================================================================
stock strtok(const strin[], &index)
{
	new length = strlen(strin);
	while ((index < length) && (strin[index] <= ' '))
	{
		index++;
	}

	new offset = index;
	new result[20];
	while ((index < length) && (strin[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = strin[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

stock IsInAllowedM(mnumbers)
{
	for(new i =0;i<sizeof(allowedmfactions);i++)
	{
		if(mnumbers == allowedmfactions[i]) return 1;
	}
	return 0;
}

/*stock Converts(number)
{
	new hours = 0, mins = 0, secs = 0, string[30];
	hours = floatround(number / 3600);
	mins = floatround((number / 60) - (hours * 60));
	secs = floatround(number - ((hours * 3600) + (mins * 60)));
	if(hours > 0)
	{
		format(string, 30, "%d:%02d:%02d", hours, mins, secs);
	}
	else
	{
		format(string, 30, "%d:%02d", mins, secs);
	}
	return string;
}*/

/*stock Converts(number)
{
	new hours = 0, mins = 0, secs = 0, string[30];
	hours = floatround(number / 3600);
	mins = floatround((number / 60) - (hours * 60));
	secs = floatround(number - ((hours * 3600) + (mins * 60)));
	if(hours > 0) format(string, 30, "%d:%02d:%02d", hours, mins, secs);
	else format(string, 30, "%d:%02d", mins, secs);
	return string;
}*/

stock Converts(number)
{
	new hours = 0, mins = 0, secs = 0, string[30];
	hours = floatround(number / 3600);
	mins = floatround((number / 60) - (hours * 60));
	secs = floatround(number - ((hours * 3600) + (mins * 60)));
	if(hours > 0) format(string, 30, "%d:%02d:%02d", hours, mins, secs);
	else format(string, 30, "%d:%02d", mins, secs);
	return string;
}

stock ConvertSendClientMessagedTime(number)
{
	new hours = 0, mins = 0, string[30];
	hours = number / 3600;
	mins = (number - hours * 3600) / 60;
	format(string, 30, "%d ч %d мин", hours, mins);
	return string;
}

stock emptyMessage(string[])
{
    for(new i; string[i] != 0x0; i++)
    {
        switch(string[i])
        {
            case 0x20: continue;
            default: return 0;
        }
    }
    return 1;
}
stock OnPlayerAmmoChange(playerid, newammo, oldammo)
{
    if(newammo < oldammo)
	{
		Shot[playerid]++;
		switch(GetPlayerWeapon(playerid))
		{
		    case 22:
			{
				if(Shot[playerid] >= 20 && PI[playerid][pGunSkill][6] < 100 && !PI[playerid][pVip]) PI[playerid][pGunSkill][6]++, Shot[playerid] = 0;
				else if(Shot[playerid] >= 10 && PI[playerid][pGunSkill][6] < 100 && PI[playerid][pVip]) PI[playerid][pGunSkill][6]++, Shot[playerid] = 0;
			}
		    case 23:
			{
				if(Shot[playerid] >= 20 && PI[playerid][pSkill] < 100 && !PI[playerid][pVip]) PI[playerid][pSkill]++, Shot[playerid] = 0;
				else if(Shot[playerid] >= 10 && PI[playerid][pSkill] < 100 && PI[playerid][pVip]) PI[playerid][pSkill]++, Shot[playerid] = 0;
			}
			case 24:
			{
				if(Shot[playerid] >= 28 && PI[playerid][pSkill][1] < 100 && !PI[playerid][pVip]) PI[playerid][pSkill][1]++, Shot[playerid] = 0;
				else if(Shot[playerid] >= 14 && PI[playerid][pSkill][1] < 100 && PI[playerid][pVip]) PI[playerid][pSkill][1]++, Shot[playerid] = 0;
			}
			case 25:
			{
				if(Shot[playerid] >= 40 && PI[playerid][pSkill][2] < 100 && !PI[playerid][pVip]) PI[playerid][pSkill][2]++, Shot[playerid] = 0;
				else if(Shot[playerid] >= 20 && PI[playerid][pSkill][2] < 100 && PI[playerid][pVip]) PI[playerid][pSkill][2]++, Shot[playerid] = 0;
			}
			case 28:
			{
				if(Shot[playerid] >= 100 && PI[playerid][pGunSkill][7] < 100 && !PI[playerid][pVip]) PI[playerid][pGunSkill][7]++, Shot[playerid] = 0;
				else if(Shot[playerid] >= 50 && PI[playerid][pGunSkill][7] < 100 && PI[playerid][pVip]) PI[playerid][pGunSkill][7]++, Shot[playerid] = 0;
			}
			case 29:
			{
				if(Shot[playerid] >= 100 && PI[playerid][pSkill][3] < 100 && !PI[playerid][pVip]) PI[playerid][pSkill][3]++, Shot[playerid] = 0;
				else if(Shot[playerid] >= 50 && PI[playerid][pSkill][3] < 100 && PI[playerid][pVip]) PI[playerid][pSkill][3]++, Shot[playerid] = 0;
			}
			case 30:
			{
				if(Shot[playerid] >= 90 && PI[playerid][pSkill][4] < 100 && !PI[playerid][pVip]) PI[playerid][pSkill][4]++, Shot[playerid] = 0;
				else if(Shot[playerid] >= 45 && PI[playerid][pSkill][4] < 100 && PI[playerid][pVip]) PI[playerid][pSkill][4]++, Shot[playerid] = 0;
			}
			case 31:
			{
				if(Shot[playerid] >= 90 && PI[playerid][pSkill][5] < 100 && !PI[playerid][pVip]) PI[playerid][pSkill][5]++, Shot[playerid] = 0;
				else if(Shot[playerid] >= 45 && PI[playerid][pSkill][5] < 100 && PI[playerid][pVip]) PI[playerid][pSkill][5]++, Shot[playerid] = 0;
			}
		}
	}
	SetPlayerSkillss(playerid);
	return 1;
}

stock SendLog(namelog[],string[])
{
	new hour, minn, sec, year, month, day, text[256], log[50], File:LogFile, i;
	gettime(hour, minn, sec);
	getdate(year, month, day);
	format(text, sizeof(text), "[%02d.%02d.%02d|%02d:%02d:%02d]%s\r\n", year, month, day, hour, minn, sec, string);
	format(log,sizeof(log),"[Logs]/%s.log", namelog);
	LogFile = fopen(log, io_append);
	while (text[i] != EOS)
	{
		fputchar(LogFile, text[i], false);
		i++;
	}
	fclose(LogFile);
}

stock PhoneMenu(playerid)
{
	ShowPlayerDialog(playerid, D_PHONE, 2, "{FFCC00}Телефон", "1. Контакты\n2. Позвонить\n3. Отправить СМС\n4. Сервисы", "Принять", "Выход");
	return 1;
}

stock RemoveFromVehicle(playerid)
{
	return RemovePlayerFromVehicle(playerid);
}

stock iswheelmodel(modelid) {

	new wheelmodels[17] = {1025,1073,1074,1075,1076,1077,1078,1079,1080,1081,1082,1083,1084,1085,1096,1097,1098};
	for(new i = 0; i < 17; i++)
	{
		if(modelid == wheelmodels[i])
		return 1;
	}
	return 0;
}

stock IllegalCarNitroIde(carmodel) {

	new illegalvehs[29] = {581,523,462,521,463,522,461,448,468,586,509,481,510,472,473,493,595,484,430,453,452,446,454,590,569,537,538,570,449};
	for(new i = 0; i < 29; i++)
	{
		if(carmodel == illegalvehs[i])
		return 1;
	}
	return 0;
}

stock illegal_nos_vehicle(playerid)
{
	new carid = GetPlayerVehicleID(playerid);
	new playercarmodel = GetVehicleModel(carid);
	return IllegalCarNitroIde(playercarmodel);
}

stock islegalcarmod(vehicleide, componentid)
{
	new modok = false;
	if((iswheelmodel(componentid)) || (componentid == 1086) || (componentid == 1087) || ((componentid >= 1008) && (componentid <= 1010)))
	{
		new nosblocker = IllegalCarNitroIde(vehicleide);
		if(!nosblocker) modok = true;
	}
	else
	{
		for(new i = 0; i < 48; i++)
		{
			if(legalmods[i][0] == vehicleide)
			{
				for(new j = 1; j < 22; j++)
				{
					if(legalmods[i][j] == componentid) modok = true;
				}
			}
		}
	}
	return modok;
}

stock GetPlayerID(name[])
{
	foreach(new i: Player)
	{
		if(strcmp(GetName(i), name, true, strlen(name)) == 0) return i;
	}
	return INVALID_PLAYER_ID;
}

stock CaptureUpd(bandkiller)
{
	new SCORE[64];
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(PI[i][pMember] > sizeof(GangInfo)) continue;
		if(GangInfo[PI[i][pMember]][capture] > 0)
		{
			if(GangInfo[bandkiller][gangnumber] == 1)
			{
				format(SCORE, sizeof(SCORE), "%d", GangInfo[bandkiller][score]);
				PlayerTextDrawSetString(i, CaptureTD[i][9], SCORE);
			}
			else
			{
				format(SCORE, sizeof(SCORE), "%d", GangInfo[bandkiller][score]);
				PlayerTextDrawSetString(i, CaptureTD[i][10], SCORE);
			}
		}
	}
}

stock CaptureStart(familyone, familytwo)
{
	new SCORE[64];
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(PI[i][pMember] == familyone || PI[i][pMember] == familytwo)
		{
		    for(new s; s < 11; s++) PlayerTextDrawShow(i, CaptureTD[i][s]);
			format(SCORE, sizeof(SCORE), "%s", GetGangName(familyone));
			PlayerTextDrawSetString(i, CaptureTD[i][7], SCORE);
			format(SCORE, sizeof(SCORE), "%s", GetGangName(familytwo));
			PlayerTextDrawSetString(i, CaptureTD[i][8], SCORE);
			PlayerTextDrawSetString(i, CaptureTD[i][9], "0");
			PlayerTextDrawSetString(i, CaptureTD[i][10], "0");
			drawcapt[i] = true;
			IsCapture = true;
		}
	}
}

stock CaptureEnd(familyone, familytwo)
{
	foreach(new i: Player)
	{
		if(PI[i][pMember] == familyone || PI[i][pMember] == familytwo)
		{
		    for(new s; s < 11; s++) PlayerTextDrawHide(i, CaptureTD[i][s]);
			drawcapt[i] = false;
		}
	}
}

stock IsAPlane(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 592,577,511,512,593,520,553,476,519,460,513,548,417,487,488,497,563,447,469: return 1;
		default: return 0;
	}
	return 0;
}

stock IsAVel(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 481,509,510,514: return 1;
		default: return 0;
	}
	return 0;
}

stock IsAMoped(vehicleid)
{
    new model = GetVehicleModel(vehicleid);
	if(model == 461 || model == 463  || model == 468  || model == 471  || model == 521  || model == 522  || model == 523  || model == 581  || model == 586)
	{
		return true;
	}
	return false;
}


stock KamazVeh(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 403 || model == 406 || model == 408 || model == 433 || model == 443 || model == 499 || model == 514 || model == 515 || model == 544)
	{
	    return true;
	}
	return false;
}

stock BusVeh2(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 498 || model == 588 || model == 413 || model == 414 || model == 431 || model == 437 || model == 483 || model == 418)
	{
	    return true;
	}
	return false;
}

stock IsABoat(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 472,473,493,595,484,430,452..454,446: return 1;
		default: return 0;
	}
	return 0;
}

stock IsLoginInvalid(text[])
{
	if(strfind(text, "none", false) != -1) return 1;
	if(strfind(text, "'", true) != -1) return 1;
	if(strfind(text, "/", true) != -1) return 1;
	if(strfind(text, "%", true) != -1) return 1;
	if(strfind(text, "&", true) != -1) return 1;
	if(strfind(text, "*", true) != -1) return 1;
	if(strfind(text, "(", true) != -1) return 1;
	if(strfind(text, ")", true) != -1) return 1;
	if(strfind(text, "2", true) != -1) return 1;
	if(strfind(text, "3", true) != -1) return 1;
	if(strfind(text, "4", true) != -1) return 1;
	if(strfind(text, "5", true) != -1) return 1;
	if(strfind(text, "6", true) != -1) return 1;
	if(strfind(text, "7", true) != -1) return 1;
	if(strfind(text, "8", true) != -1) return 1;
	if(strfind(text, "9", true) != -1) return 1;
	return 0;
}

stock IsTextInvalid(text[])
{
	if(strfind(text, "'", true) != -1) return 1;
	if(strfind(text, "%", true) != -1) return 1;
	if(strfind(text, "&", true) != -1) return 1;
	if(strfind(text, "*", true) != -1) return 1;
	if(strfind(text, "(", true) != -1) return 1;
	if(strfind(text, ")", true) != -1) return 1;
	return 0;
}

stock IsTextRussian(text[])
{
	if(strfind(text, "а", true) != -1) return 1;
	if(strfind(text, "б", true) != -1) return 1;
	if(strfind(text, "В", true) != -1) return 1;
	if(strfind(text, "г", true) != -1) return 1;
	if(strfind(text, "д", true) != -1) return 1;
	if(strfind(text, "е", true) != -1) return 1;
	if(strfind(text, "ё", true) != -1) return 1;
	if(strfind(text, "ж", true) != -1) return 1;
	if(strfind(text, "з", true) != -1) return 1;
	if(strfind(text, "и", true) != -1) return 1;
	if(strfind(text, "й", true) != -1) return 1;
	if(strfind(text, "к", true) != -1) return 1;
	if(strfind(text, "л", true) != -1) return 1;
	if(strfind(text, "м", true) != -1) return 1;
	if(strfind(text, "н", true) != -1) return 1;
	if(strfind(text, "о", true) != -1) return 1;
	if(strfind(text, "п", true) != -1) return 1;
	if(strfind(text, "р", true) != -1) return 1;
	if(strfind(text, "с", true) != -1) return 1;
	if(strfind(text, "т", true) != -1) return 1;
	if(strfind(text, "у", true) != -1) return 1;
	if(strfind(text, "ф", true) != -1) return 1;
	if(strfind(text, "х", true) != -1) return 1;
	if(strfind(text, "ц", true) != -1) return 1;
	if(strfind(text, "ч", true) != -1) return 1;
	if(strfind(text, "ш", true) != -1) return 1;
	if(strfind(text, "щ", true) != -1) return 1;
	if(strfind(text, "ъ", true) != -1) return 1;
	if(strfind(text, "ы", true) != -1) return 1;
	if(strfind(text, "ь", true) != -1) return 1;
	if(strfind(text, "э", true) != -1) return 1;
	if(strfind(text, "ю", true) != -1) return 1;
	if(strfind(text, "я", true) != -1) return 1;
	return 0;
}

stock GetVehicleType(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
	    case 483,534,535,536,558,559,560,561,562,565,567,575,576: return 1;
	    default: return 0;
	}
	return 0;
}
//==============================================================================
stock IsAGos(playerid)
{
	switch(GetTeamID(playerid))
	{
	    case TEAM_AO,TEAM_DPS,TEAM_PPS,TEAM_FSIN,TEAM_MZY,TEAM_MZA,TEAM_SMI,TEAM_VDV: return 1;
	    default: return 0;
	}
	return 0;
}
//==============================================================================
stock IsACop(playerid)
{
	switch(GetTeamID(playerid))
	{
	    case TEAM_PPS,TEAM_DPS,TEAM_FSIN: return 1;
	    default: return 0;
	}
	return 0;
}
//==============================================================================
stock IsAArmy(playerid)
{
	switch(GetTeamID(playerid))
	{
	    case TEAM_VDV: return 1;
	    default: return 0;
	}
	return 0;
}
//==============================================================================
stock IsAGang(playerid)
{
	switch(GetTeamID(playerid))
	{
	    case TEAM_SPARTAK,TEAM_CSKA,TEAM_DINAMO,TEAM_ZENIT: return 1;
	    default: return 0;
	}
	return 0;
}
//==============================================================================
stock IsAMafia(playerid)
{
	switch(GetTeamID(playerid))
	{
	    case TEAM_SPARTAK,TEAM_CSKA,TEAM_DINAMO,TEAM_ZENIT: return 1;
	    default: return 0;
	}
	return 0;
}
//==============================================================================
stock IsANews(playerid)
{
	switch(GetTeamID(playerid))
	{
	    case TEAM_SMI: return 1;
	    default: return 0;
	}
	return 0;
}
//==============================================================================
stock IsAMedic(playerid)
{
	switch(GetTeamID(playerid))
	{
	    case TEAM_MZY,TEAM_MZA: return 1;
	    default: return 0;
	}
	return 0;
}
//==============================================================================
stock IsAMayor(playerid)
{
	switch(GetTeamID(playerid))
	{
	    case TEAM_AO: return 1;
	    default: return 0;
	}
	return 0;
}
//==============================================================================
stock SaveGZ(idx)
{
	format(query, 100, "UPDATE `gangzone` SET fraction = %i WHERE id = %i", GZInfo[idx][gFrak], idx);
	mysql_tquery(dbHandle, query, "", "");
	return 1;
}
//==============================================================================
stock SetPlayerCriminal(playerid, killerid[], reason[])
{
	PI[playerid][pCrimes]++;
	strmid(PI[playerid][pWantedWho], killerid, 0, strlen(killerid), MAX_PLAYER_NAME);
	strmid(PI[playerid][pWantedReason], reason, 0, strlen(reason), 32);
	SendMes(playerid, COLOR_RED, "%s объявил Вас в розыск. Причина: %s", killerid, reason);
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		if(IsACop(i)) SendMes(i, 0x3399FFFF, "[Внимание] %s [%i] объявил в розыск %s [%i]. Причина: %s.", killerid, playerid, GetName(playerid), playerid, reason);
	}
	PI[playerid][pZakon]--;
	return 1;
}
//==============================================================================
stock NotFlyingHack(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid,20.0,1968.3948,-1198.0753,17.4500)||IsPlayerInRangeOfPoint(playerid,20.0,2310.9861,-1412.8881,21.6151)||
	IsPlayerInRangeOfPoint(playerid,20.0,1241.1094,-2379.7263,8.3145)||IsPlayerInRangeOfPoint(playerid,20.0,225.6394,-1187.0551,73.4500)||
	IsPlayerInRangeOfPoint(playerid,20.0,193.2040,-1224.7693,76.5034)||IsPlayerInRangeOfPoint(playerid,20.0,196.0067,-1232.3684,76.5034)||
    IsPlayerInRangeOfPoint(playerid,20.0,512.7349,-1104.1942,78.8238)||IsPlayerInRangeOfPoint(playerid,20.0,1283.7939,-806.5845,86.1230)||
	IsPlayerInRangeOfPoint(playerid,20.0,2531.6001,1568.4032,8.4171)||IsPlayerInRangeOfPoint(playerid,60.0,2105.2651,1916.6781,9.5989)||
	IsPlayerInRangeOfPoint(playerid,150.0,-792.4582,2173.0356,40.0821)||IsPlayerInRangeOfPoint(playerid,150.0,1993.5868,1601.2623,9.2979))return 1;
    return 0;
}
//==============================================================================
stock AntiCarHack(playerid)
{
    SetPVarInt(playerid, "CarHackUsing", 0);
    return 1;
}

stock PlayerSpeed(playerid)
{
    new Float:X, Float:Y, Float:Z;
    if(!IsPlayerInAnyVehicle(playerid)) GetPlayerVelocity(playerid,X,Y,Z);
    return floatround( floatsqroot( X * X + Y * Y + Z * Z ) * 170.0 );
}

stock GetPlayerSpeed(playerid)
{
    new Float:Coord[4];
    if(IsPlayerInAnyVehicle(playerid)) return 0;
	GetPlayerVelocity(playerid,Coord[0], Coord[1], Coord[2]);
    Coord[3] = floatsqroot(floatpower(floatabs(Coord[0]), 2.0) + floatpower(floatabs(Coord[1]), 2.0) + floatpower(floatabs(Coord[2]), 2.0)) * 214.3;
    return floatround(Coord[3]);
}

stock GetVehicleSpeed(vehicleid)
{
    new Float:ST[3];
    GetVehicleVelocity(vehicleid, ST[0], ST[1], ST[2]);
    return floatround(floatsqroot(ST[0]*ST[0] + ST[1]*ST[1] + ST[2]*ST[2])*110.3);
}

forward Float:GetPlayerSpeed1(playerid);
public Float:GetPlayerSpeed1(playerid)
{
	new Float:X, Float:Y, Float:Z, Float:PlayerToPoints;
	GetVehicleVelocity(GetPlayerVehicleID(playerid), X, Y, Z);
	PlayerToPoints = floatsqroot(floatpower(X, 2) + floatpower(Y, 2) + floatpower(Z, 2))*100;
	return PlayerToPoints;
}

stock PlayerTimer()
{
    foreach(new i: Player)
	{
		if(PlayerLogged[i] == true)
		{

		    // MONEY CHECK
		    if(CheckOutMoney[i] == false)
			{
				if(PI[i][pCash] < GetPlayerMoney(i))
				{
				    ResetPlayerMoney(i);
				    GivePlayerMoney(i,PI[i][pCash]);
				}
			}
			else CheckOutMoney[i] = false;
			
			new Float: FloatParam;
			if(PlayerUseHeal[i] == 0)
			{
				GetPlayerHealth(i, FloatParam);
				if(PI[i][pHeal] < FloatParam) SetPlayerHealth(i, PI[i][pHeal]);
				else PI[i][pHeal] = FloatParam;
			}
			if(PlayerDied[i] == true)
			{
				HospitalHealth(i);
			}
            
            /*PI[i][pAFK]++;
			if(PI[i][pAFK] >= 3)
			{
				new temp[64];
				format(temp, sizeof(temp), "AFK: %s", Converts(PI[i][pAFK]));
				SetPlayerChatBubble(i, temp, COLOR_AFK, 10.0, 1600);
			}*/
			/*if(PI[playerid][pAFK] == 2400 && !PI[playerid][pAdmin])
			{
				SendClientMessage(playerid, COLOR_RED, "Вы были кикнуты т.к были долгое время в АФК");
				KickEx(playerid, 1828);
			}*/
			
			if(PI[i][Spectating][1] != INVALID_PLAYER_ID)
			{
				new str[300];
				new Float:values[3];
				GetPlayerHealth(PI[i][Spectating][0], values[0]);
				GetPlayerArmour(PI[i][Spectating][0], values[1]);
				GetVehicleHealth(GetPlayerVehicleID(PI[i][Spectating][0]), values[2]);
				format(str, sizeof(str), "%s~n~ID: %d~n~Пинг: %d~n~HP: %.1f~n~Броня: %.1f~n~Скорость: %d~n~CarHP: %.1f~n~Патрон: %i:%i~n~Варнов: %d~n~Денег: %d",
				GetName(PI[i][Spectating][0]), PI[i][Spectating][0], GetPlayerPing(PI[i][Spectating][0]),
				values[0], values[1], SpeedVehicle(PI[i][Spectating][0]) / 2, values[2],
				GetPlayerWeapon(PI[i][Spectating][0]), GetPlayerAmmo(PI[i][Spectating][0]),
				PI[PI[i][Spectating][0]][pWarn], PI[PI[i][Spectating][0]][pCash]);
				PlayerTextDrawSetString(PI[i][Spectating][1], PI[PI[i][Spectating][1]][SpecTxt], str);
			}
		}
		/*if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
		{
			new vehicleid = GetPlayerVehicleID(i);
			if(Fuel[vehicleid] < 1 && PlayerFuelMes[vehicleid] == true && GetVehicleModel(vehicleid) != 462)
			{
				SendClientMessage(i, COLOR_RED, "В транспорте закончился бензин, необходима заправка!");
				Engine[vehicleid] = false;
				GetVehicleParamsEx(vehicleid,engine,lights,alarm,doors,bonnet,boot,objective);
				SetVehicleParamsEx(vehicleid,false,lights,alarm,doors,bonnet,boot,objective);
				PlayerFuelMes[vehicleid] = false;
			}
		}*/
		
	    PI[i][pCheckTime]++;
	    if(PI[i][pAdmin]) AdminInfo[i][admTimeMin]++;
	    if(Ether[i] == true) SetPVarInt(i, "InEther", GetPVarInt(i, "InEther") + 1);
	    if(GetPVarInt(i, "TypeBus")) PI[i][pBusTime]++;
		
		if(IsPlayerInRangeOfPoint(i,1.0,-70.9644,1137.3872,2340.5300))
		{
			if(IsAArmy(i) || IsAGang(i))
			{
				StealMats(i);
			}
		}
		if(Mobile[i] != -1 && EtherCalled[i] == false)
		{
			SetPVarInt(i, "CallTime", GetPVarInt(i, "CallTime") + 1);
			if(GetPVarInt(i, "CallTime") >= 10)
			{
				if(PI[i][pBank] > 100)
				{
					PI[i][pBank] -= 100;
					SetPVarInt(i, "CallTime", 0);
				}
				else
				{
					new callerid = Mobile[i];
					SendClientMessage(callerid, COLOR_RED, "Собеседник повесил трубку");
					SetPlayerSpecialAction(callerid,SPECIAL_ACTION_STOPUSECELLPHONE);
					CellTime[callerid] = -1;
					CellTime[i] = -1;
					SendClientMessage(i, COLOR_RED, "Недостаточно средств на счету");
					Mobile[i] = -1;
					SetPlayerSpecialAction(i,SPECIAL_ACTION_STOPUSECELLPHONE);
					DeletePVar(i, "CallTime");
					DeletePVar(callerid, "CallTime");
				}
			}
		}
		if(GetPVarInt(i, "TimeTaxi") > 0)
		{
			SetPVarInt(i, "TimeTaxi", GetPVarInt(i, "TimeTaxi") - 1);
			if(GetPVarInt(i, "TimeTaxi") == 0)
			{
				if(GetMoney(i) > GetPVarInt(i, "TaxiPrice"))
				{
				    new string[32];
					format(string, sizeof(string), "~r~-%i рублей", GetPVarInt(i, "TaxiPrice"));
					GameTextForPlayer(i, string, 5000, 1);
					format(string, sizeof(string), "~b~+%i рублей", GetPVarInt(i, "TaxiPrice"));
					GameTextForPlayer(GetPVarInt(i, "PlayerTaxi"), string, 5000, 1);
					TransferMoney(i, -1, GetPVarInt(i, "TaxiPrice"));
					PI[GetPVarInt(i, "PlayerTaxi")][pPayCheck] += GetPVarInt(i, "TaxiPrice");
					SetPVarInt(i, "TimeTaxi", 30);
					SetPVarInt(GetPVarInt(i, "PlayerTaxi"), "TaxiMoney", GetPVarInt(GetPVarInt(i, "PlayerTaxi"), "TaxiMoney") + GetPVarInt(i, "TaxiPrice"));
				}
				else
				{
					SendClientMessage(i, COLOR_RED, "У Вас недостаточно денег!");
					RemoveFromVehicle(i);
				}
			}
		}
		if(GetPVarInt(i, "TimeBus") > 0)
		{
		    SetPVarInt(i, "TimeBus", GetPVarInt(i, "TimeBus") - 1);
		    new string[32];
			format(string, sizeof(string), "~r~%i", GetPVarInt(i, "TimeBus"));
			GameTextForPlayer(i, string, 2000, 6);
			if(GetPVarInt(i, "TimeBus") == 0)
			{
				DeletePVar(i, "TimeBus");
				new p = pPressed[i];
				SetPVarInt(i, "BusStop", 1);
				SetPlayerRaceCheckpoint(i,0,arzamas_batirevo[p][0],arzamas_batirevo[p][1],arzamas_batirevo[p][2],arzamas_batirevo[p][3],arzamas_batirevo[p][4],arzamas_batirevo[p][5],5.0);
			}
		}
		if(EtherCalled[i] == true)
		{
			if(PI[i][pPhoneBalance] > CallPrice[PI[i][pNews]-1])
			{
				PI[i][pPhoneBalance] -= CallPrice[PI[i][pNews]-1];
				if(PI[i][pNews]-1 == 0)
				{
					FracBank[8] += CallPrice[PI[i][pNews]-1];
					MysqlUpdateOtherInt("lsnbank", FracBank[8]);
				}
				if(PI[i][pNews]-1 == 1)
				{
					FracBank[9] += CallPrice[PI[i][pNews]-1];
					MysqlUpdateOtherInt("sfnbank", FracBank[9]);
				}
				if(PI[i][pNews]-1 == 2)
				{
					FracBank[10] += CallPrice[PI[i][pNews]-1];
					MysqlUpdateOtherInt("lvnbank", FracBank[10]);
				}
			}
			else
			{
				new callerid = Mobile[i];
				SendClientMessage(callerid, COLOR_RED, "Абонент положил трубку");
				SetPlayerSpecialAction(callerid,SPECIAL_ACTION_STOPUSECELLPHONE);
				CellTime[callerid] = -1;
				CellTime[i] = -1;
				Mobile[callerid] = -1;
				if(EtherCalled[i] == true) EtherCalled[i] = false;
				if(EtherCalled[callerid] == true) EtherCalled[callerid] = false;
				SendClientMessage(i, COLOR_RED, "Недостаточно средств на счету");
				Mobile[i] = -1;
				SetPlayerSpecialAction(i,SPECIAL_ACTION_STOPUSECELLPHONE);
			}
		}
		if(PI[i][pJail] > 0)
		{
			PI[i][pJailTime]--;
			if(PI[i][pJailTime] == 0)
			{
				if(PI[i][pJail] == 1)
				{
				    SendClientMessage(i, COLOR_LIME,"Время заключения в тюрьме истекло, теперь Вы свободны");
					SetPlayerPos(i, 404.3761,755.9924,12.0700);
					SetPlayerFacingAngle(i, 160.0000);
				}
				if(PI[i][pJail] == 2)
				{
				    SendClientMessage(i, COLOR_LIME,"Время заключения в тюрьме истекло, теперь Вы свободны");
					SetPlayerPos(i, 1916.7854,2183.6296,15.7060);
					SetPlayerFacingAngle(i, 90.2275);
				}
				if(PI[i][pJail] == 3)
				{
				    SendClientMessage(i, COLOR_LIME,"Время заключения в деморгане истекло, теперь Вы свободны");
					SpawnPlayer(i);
				}
				PI[i][pJail] = PI[i][pJailTime] = 0;
				SetPlayerInterior(i, 0);
				SetPlayerVirtualWorld(i, 0);
			}
		}
		if(PI[i][pMuted] > 0)
		{
			PI[i][pMuted]--;
			if(PI[i][pMuted] == 0)
			{
               SendClientMessage(i, COLOR_LIME, "Доступ в чат разблокирован");
			}
		}
		if(PI[i][pWanted] > 0)
		{
			PI[i][pWantedTime]--;
			if(PI[i][pWantedTime] <= 0)
			{
				PI[i][pWanted]--;
				SetPlayerWantedLevel(i, PI[i][pWanted]);
				if(PI[i][pWanted] > 0) PI[i][pWantedTime] = 1800 + random(300);
			}
		}
		/*if(!PI[i][pAdmin])
		{
		    new speed = PlayerSpeed(i);
		    if(!speed) SetPVarInt(i, "HungerTime", GetPVarInt(i, "HungerTime") + 1);
		    else SetPVarInt(i, "HungerTime", GetPVarInt(i, "HungerTime") + speed/4);
			if(GetPVarInt(i, "HungerTime") == 250 && !PI[i][pVip])
			{
				SetPVarInt(i, "HungerTime", 0);
				if(PI[i][pVip]) PI[i][pHunger] -= 2;
				else PI[i][pHunger]--;
				SetHunger(i, PI[i][pHunger]);
				if(PI[i][pHunger] == 1 || PI[i][pHunger] == 5 || PI[i][pHunger] == 10 || PI[i][pHunger] == 15)
					SendClientMessage(i, COLOR_YELLOW,"Вы проголодались! Сходите в закусочную!");
			}
			SetPVarInt(i, "HealthTime", GetPVarInt(i, "HealthTime") + 1);
			if(GetPVarInt(i, "HealthTime") == 60)
			{
				SetPVarInt(i, "HealthTime", 0);
				if(PI[i][pHunger] <= 0)
				{
				    new Float:shealth;
				    GetPlayerHealth(i, shealth);
				    SetHealth(i, (PI[i][pImprove][0] == 1) ? (shealth-1.0) : (shealth-2.0));
				}
			}
			if(PI[i][pHeal] < 20)
			{
				SetPVarInt(i, "HealthTime_", GetPVarInt(i, "HealthTime_") + 1);
				if(GetPVarInt(i, "HealthTime_") == 600)
				{
					SetPVarInt(i, "HealthTime_", 0);
					SendClientMessage(i, COLOR_YELLOW, "У Вас сильно ухудшилось здоровье, вылечитесь у медика!");
				}
			}
		}
		if(GetPlayerDrunkLevel(i) > 0)
		{
			SetPVarInt(i, "DrunkTime", GetPVarInt(i, "DrunkTime") + 1);
			if(GetPVarInt(i, "DrunkTime") >= 100)
			{
				SetPlayerDrunkLevel(i, GetPlayerDrunkLevel(i) - 1000);
				SetPVarInt(i, "DrunkTime", 0);
			}
		}*/
		if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
     	{
     	    new Float:vehhealth;
        	GetVehicleHealth(GetPlayerVehicleID(i), vehhealth);
	    	if(vehhealth <= 400)
	    	{
	    	    if(Engine[GetPlayerVehicleID(i)] == true) SendClientMessage(i, COLOR_RED, "Транспорт заглох. Вы можете вызвать механика: /call");
      			Engine[GetPlayerVehicleID(i)] = false;
            	GetVehicleParamsEx(GetPlayerVehicleID(i),engine,lights,alarm,doors,bonnet,boot,objective);
            	SetVehicleParamsEx(GetPlayerVehicleID(i),false,lights,alarm,doors,bonnet,boot,objective);
	    	}
	    }
		/*if(GetPVarInt(i, "BusTime") > 0)
		{
			if(GetPlayerState(i) != 2 || GetPlayerVehicleID(i) != PI[i][BusCarID])
			{
				new string[32];
				SetPVarInt(i, "BusTime", GetPVarInt(i, "BusTime") - 1);
				format(string, sizeof(string), "~r~%d",GetPVarInt(i, "BusTime"));
				GameTextForPlayer(i, string, 2000, 6);
				new CB[16];
		    	TimeConverter(PI[i][pBusTime], CB);
				if(GetPVarInt(i, "BusTime") == 0)
				{
				    if(IsValidDynamic3DTextLabel(BusText3D[i])) DestroyDynamic3DTextLabel(BusText3D[i]);
					SendMes(i, COLOR_BLUE, "Рабочий день завершен. Вами заработано: %i рублей. Время рейса: %s", GetPVarInt(i, "BusMoney"), CB);
					SendClientMessage(i, COLOR_WHITE, "Деньги будут перечислены на счет во время зарплаты");
					PI[i][pPayCheck] += GetPVarInt(i, "BusMoney");
					SetVehicleToRespawn(PI[i][BusCarID]);
					PI[i][BusCarID] = INVALID_VEHICLE_ID;
					DeletePVar(i, "BusTime");
					DeletePVar(i, "TypeBus");
					DeletePVar(i, "PriceBus");
					DeletePVar(i, "BusStop");
					DeletePVar(i, "BusMoney");
					PI[i][pBusTime] = 0;
					pPressed[i] = 0;
				}
			}
		}*/
		if(GetPVarInt(i, "TruckerJobTime") > 0)//дальнобойщик
		{
			if(GetPlayerState(i) != 2)
			{
				SetPVarInt(i, "TruckerJobTime", GetPVarInt(i, "TruckerJobTime") - 1);
				if(GetPVarInt(i, "TruckerJobTime") == 0)
				{
                    DestroyVehicleEx(TruckerCar[i]);
                    PI[i][TruckerCarID] = INVALID_VEHICLE_ID;
                    TruckerCar[i] = 0;
					SendClientMessage(i, COLOR_BLUE, "К сожалению, Вы не успели сесть в грузовик");
					DisablePlayerRaceCheckpoint(i);
					DeletePVar(i, "TruckerJobTime");
					DeletePVar(i, "TruckerJob");
					DeletePVar(i, "TruckerJobRazgruzka");
					pPressed[i] = 0;
				}
			}
		}
		if(GetPVarInt(i, "TruckerJobTimeGoToCar") > 0)//дальнобойщик
		{
			if(GetPlayerState(i) != 2)
			{
				SetPVarInt(i, "TruckerJobTimeGoToCar", GetPVarInt(i, "TruckerJobTimeGoToCar") - 1);
				if(GetPVarInt(i, "TruckerJobTimeGoToCar") == 0)
				{
                    DestroyVehicleEx(TruckerCar[i]);
                    TruckerCar[i] = 0;
                    DisablePlayerRaceCheckpoint(i);
					SendClientMessage(i, COLOR_RED, "К сожалению, Вы не успели сесть в грузовик");
					DeletePVar(i, "TruckerJobTime");
					DeletePVar(i, "TruckerJob");
					DeletePVar(i, "TruckerJobRazgruzka");
					DisablePlayerCheckpoint(i);
				}
			}
		}
		if(CellTime[i] > -1)
		{
			CellTime[i]++;
			if(Mobile[Mobile[i]] == -1 && CellTime[i] == 5)
			{
				CellTime[i] = 0;
				new string[64];
				format(string, sizeof(string), "У %s звонит мобильный телефон", GetName(Mobile[i]));
				ProxDetectorNew(Mobile[i], 13.0, COLOR_PURPLE, string);
			}
		}
		if(TransferReset[i] > 0) TransferReset[i]--;
		if(UnMaskReset[i] > 0) UnMaskReset[i]--;
	}
	return 1;
}

stock GiveBankMoney(playerid, money, reason[] = "None")
{
    new string[100];
	PI[playerid][pBank] += (money);
	format(string,sizeof(string),"[%s] [%s]: [%d рублей] [%d рублей] [%s]",PI[playerid][pIP],GetName(playerid),money,PI[playerid][pCash],reason);
	SendLog("BankMoneyLog",string);
	return 1;
}

stock TransferMoney(playerid, toplayerid, money)
{
    if(GetPlayerMoney(playerid) < 0) ResetPlayerMoney(playerid);
	if(GetPlayerMoney(toplayerid) < 0) ResetPlayerMoney(toplayerid);
	if(toplayerid >= 0)
	{
	    GivePlayerMoney(toplayerid, money);
		PI[toplayerid][pCash] = PI[toplayerid][pCash] + money;
		CheckOutMoney[toplayerid] = true;
	}
	if(playerid >= 0)
	{
		GivePlayerMoney(playerid, -money);
		PI[playerid][pCash] = PI[playerid][pCash] - money;
		CheckOutMoney[playerid] = true;
	}
}

stock ResetMoney(playerid)
{
	PI[playerid][pCash] = 0;
	ResetPlayerMoney(playerid);
}

stock GetMoney(playerid)
{
	return PI[playerid][pCash];
}

stock HealthCheck()
{
	new Float: Heal;
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		GetPlayerHealth(i, Heal);
		if(PI[i][pHeal] < Heal) SetPlayerHealth(i, PI[i][pHeal]);
		else PI[i][pHeal] = Heal;
	}
}

stock ArmourCheck()
{
	new Float: Arm;
	foreach(new i: Player)
	{
		if(PlayerLogged[i] == false) continue;
		GetPlayerArmour(i, Arm);
		if(PlayerArmour[i] < Arm) SetPlayerArmour(i, PlayerArmour[i]);
		else PlayerArmour[i] = Arm;
	}
}
stock PreloadAnimLib(playerid, animlib[])
{
	ApplyAnimation(playerid,animlib,"null",0.0,0,0,0,0,0);
	return 0;
}
stock CheatKick(playerid,errorcode)
{
	if(playerid == INVALID_PLAYER_ID) return 1;
	new string[128];
	if(PI[playerid][pAdmin] != ADM_NONE)
	{
	    format(string, sizeof(string), "{f39c12}["SERVER_NAME_RP" AntiCheat] {3498db}Античит попытался Вас кикнуть {2ecc71}(ac-code %d)", errorcode);
		SendClientMessage(playerid, COLOR_RED, string);
		return 1;
	}
	if(errorcode != 0)
	{
	    format(string, sizeof(string), "{f39c12}["SERVER_NAME_RP" AntiCheat] {3498db}Обнаружено использование чит-программ {2ecc71}(ac-code %d)", errorcode);
		SendClientMessage(playerid, COLOR_RED, string);
		Kick(playerid);
	}
	else Kick(playerid);
	return 1;
}
stock SaveVehicleTuning(playerid)
{
	PI[playerid][cVehcoms][0] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_SPOILER);
	PI[playerid][cVehcoms][1] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_HOOD);
	PI[playerid][cVehcoms][2] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_ROOF);
	PI[playerid][cVehcoms][3] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_SIDESKIRT);
	PI[playerid][cVehcoms][4] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_LAMPS);
	PI[playerid][cVehcoms][5] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_NITRO);
	PI[playerid][cVehcoms][6] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_EXHAUST);
	PI[playerid][cVehcoms][7] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_WHEELS);
	PI[playerid][cVehcoms][8] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_STEREO);
	PI[playerid][cVehcoms][9] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_HYDRAULICS);
	PI[playerid][cVehcoms][10] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_FRONT_BUMPER);
	PI[playerid][cVehcoms][11] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_REAR_BUMPER);
	PI[playerid][cVehcoms][12] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_VENT_RIGHT);
	PI[playerid][cVehcoms][13] = GetVehicleComponentInSlot(PI[playerid][PlayerCarID], CARMODTYPE_VENT_LEFT);
	format(PI[playerid][cVehcom], 64, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
	PI[playerid][cVehcoms][0], PI[playerid][cVehcoms][1], PI[playerid][cVehcoms][2],
	PI[playerid][cVehcoms][3], PI[playerid][cVehcoms][4], PI[playerid][cVehcoms][5],
	PI[playerid][cVehcoms][6], PI[playerid][cVehcoms][7], PI[playerid][cVehcoms][8],
	PI[playerid][cVehcoms][9], PI[playerid][cVehcoms][10], PI[playerid][cVehcoms][11],
	PI[playerid][cVehcoms][12], PI[playerid][cVehcoms][13]);
	return 1;
}
stock ShowSTODialog(playerid)
{
	ShowPlayerDialog(playerid,D_CTO+1,DIALOG_STYLE_LIST,"{FFCC00}Тюнинг меню","1. Покраска\n2. Гидравлика\n3. Закись азота\n4. Диски\n5. Починить транспорт","Выбрать","Выход");
	return 1;
}
//==============================================================================
stock CreateAccount(playerid, password[])
{
    if(PlayerRegistered[playerid] == 0) return CheatKick(playerid, 2112);
    new pass[50];
    mysql_escape_string(password, pass, dbHandle);
	if(IsTextInvalid(pass))
	{
		SendClientMessage(playerid, COLOR_RED, "В пароле должны быть только буквы и цифры");
		return Kick(playerid);
	}
	new data[15];
	format(data, sizeof(data), "%s", date("%dd.%mm.%yyyy",gettime()));
	new Query[500];
	new Info[300];
	strcat(Query, "INSERT INTO `accounts` ");
	strcat(Query, "(`name`, `password`, `regip`, `datareg`, `sex`, `age`, `model`, `mail`, `referal`) ");
	strcat(Query, "VALUES ");
	format(Info, sizeof(Info), "('%s', '%s', '%s', '%s', '%i', '%i', '%i', '%s', '%s')",
	GetName(playerid), pass, PI[playerid][pIP], data, PI[playerid][pSex], PI[playerid][pAge], PI[playerid][pModel], PI[playerid][pMail], PI[playerid][pReferal]);
	strcat(Query, Info);
	mysql_tquery(dbHandle, Query, "", "");
//	for(new i = 0; i != 10; ++i) SendClientMessage(playerid, -1, " ");
	PlayerLogged[playerid] = true;
	PlayerRegistered[playerid] = 0;

	PI[playerid][pCash] = BONUS_CASH; 											// - Система бонуса, выдача денег при регистрации.
	PI[playerid][pBank] = 0;                                                    // - Система бонуса, выдача денег на банке при регистрации.
	PI[playerid][pLevel] = BONUS_LVL;                                           // - Система бонуса, выдача уровня при регистрации.
	PI[playerid][pCredits] = BONUS_COIN;                                        // - Система бонуса, выдача Perfomance Coins при регистрации.
	PI[playerid][pZakon] = BONUS_ZAKON;                                         // -
	
	PI[playerid][pBanya] = 0;
	SetHunger(playerid, PI[playerid][pHunger]);
	Hunger(playerid, 0);
	PI[playerid][pSpawnChange] = 0;
	SpawnPlayer(playerid);
	return 1;
}
//==============================================================================
forward OnPlayerLogin(playerid, tmp[]);
public OnPlayerLogin(playerid, tmp[])
{
	mysql_format(dbHandle, query, sizeof(query), "SELECT * FROM bans WHERE name = '%e'", GetName(playerid));
	mysql_tquery(dbHandle, query, "check_banlist", "i", playerid);

	if(!GetPVarInt(playerid, "Logged")) return 1;
	new rows, fields;
	new posx[3];
    new posy[3];
    new posz[3];
    new pint[3];
    new pworld[3];
    cache_get_data(rows, fields);
	if(!rows)
	{
		PlayerLogTries[playerid]++;
//		if(PlayerLogTries[playerid] == 4)
		if(PlayerLogTries[playerid] == 3)
		{
			SendClientMessage(playerid, COLOR_RED, "Вы несколько раз ввели неверный пароль! Для выхода из игры введите: {ffffff}/q(uit)");
			return Kick(playerid);
		}
        new string[100];
		format(string, sizeof(string), "{FF6600}Неправильный пароль!\nУ Вас осталось{FFFFFF} %d попыток", 3 - PlayerLogTries[playerid]);
		ShowPlayerDialog(playerid, D_ERRORPAS, DIALOG_STYLE_MSGBOX, "{FF6600}Ошибка", string, "Повтор", "Выйти");
		return 1;
	}

	PI[playerid][pID] = cache_get_row_int(0, 0, dbHandle); // id
	//cache_get_row(0, 2, PI[playerid][pPassword], dbHandle, 32); // password
	cache_get_row(0, 3, PI[playerid][pLastIP], dbHandle, 16); // ip
	cache_get_row(0, 4, PI[playerid][pNumberVehicle], dbHandle, 20); // veh_number
	PI[playerid][pRegVehicle] = cache_get_row_int(0, 5, dbHandle); // veh_reg
	PI[playerid][pAdmin] = cache_get_row_int(0, 6, dbHandle); // admin
	PI[playerid][pSecurityCode] = cache_get_row_int(0, 7, dbHandle); // securitycode
	PI[playerid][pCheckCode] = cache_get_row_int(0, 8, dbHandle); // checkcode
	cache_get_row(0, 9, PI[playerid][pMail], dbHandle, 64); // mail
	PI[playerid][pLevel] = cache_get_row_int(0, 10, dbHandle); // level
	PI[playerid][pCash] = cache_get_row_int(0, 11, dbHandle); // cash
	PI[playerid][pBank] = cache_get_row_int(0, 12, dbHandle); // bank
	PI[playerid][pExp] = cache_get_row_int(0, 13, dbHandle); // exp
	cache_get_row(0, 14, PI[playerid][pRegIP], dbHandle, 16); // regip
	cache_get_row(0, 15, PI[playerid][pRegData], dbHandle, 15); // datareg
	PI[playerid][pLeader] = cache_get_row_int(0, 16, dbHandle); // leader
	PI[playerid][pTempLeader] = cache_get_row_int(0, 17, dbHandle); // templeader
	PI[playerid][pMember] = cache_get_row_int(0, 18, dbHandle); // member
	PI[playerid][pRank] = cache_get_row_int(0, 19, dbHandle); // rank
	PI[playerid][pWarn] = cache_get_row_int(0, 20, dbHandle); // warn
	PI[playerid][pSex] = cache_get_row_int(0, 21, dbHandle); // sex
	PI[playerid][pAge] = cache_get_row_int(0, 22, dbHandle); // age
	PI[playerid][pModel] = cache_get_row_int(0, 23, dbHandle); // model
	PI[playerid][pMemberSkin] = cache_get_row_int(0, 24, dbHandle); // memberskin
	cache_get_row(0, 25, PI[playerid][pLics], dbHandle, 16); // lic
	PI[playerid][pMuted] = cache_get_row_int(0, 28, dbHandle); // mute
	PI[playerid][pPick] = cache_get_row_int(0, 29, dbHandle); // pick
	PI[playerid][pCheckTime] = cache_get_row_int(0, 30, dbHandle); //checktime
	PI[playerid][pNews] = cache_get_row_int(0, 31, dbHandle); // news
	//PI[playerid][pPhone] = cache_get_row_int(0, 32, dbHandle); // phone
	PI[playerid][pPhoneNumber] = cache_get_row_int(0, 33, dbHandle); // phonenumber
	cache_get_row(0, 34, PI[playerid][pTexts], dbHandle, 20); // text
	PI[playerid][pJail] = cache_get_row_int(0, 35, dbHandle); // jail
	PI[playerid][pJailTime] = cache_get_row_int(0, 36, dbHandle); // jailtime
	PI[playerid][pWanted] = cache_get_row_int(0, 37, dbHandle); // wanted
	PI[playerid][pWantedTime] = cache_get_row_int(0, 38, dbHandle); // wantedtime
	cache_get_row(0, 39, PI[playerid][pWantedWho], dbHandle, MAX_PLAYER_NAME); // wantedwho
	cache_get_row(0, 40, PI[playerid][pWantedReason], dbHandle, 32); // wantedreason
	PI[playerid][pHeal] = cache_get_row_float(0, 41, dbHandle); // heal
	PI[playerid][pDrugs] = cache_get_row_int(0, 42, dbHandle); // drugs
	PI[playerid][pPatron] = cache_get_row_int(0, 43, dbHandle); // patron
	PI[playerid][pGunAmount] = cache_get_row_int(0, 44, dbHandle); // gunamount
	PI[playerid][pCrimes] = cache_get_row_int(0, 45, dbHandle); // crimes
	PI[playerid][pJob] = cache_get_row_int(0, 46, dbHandle); // job
	PI[playerid][pMarried] = cache_get_row_int(0, 47, dbHandle); // married
	cache_get_row(0, 48, PI[playerid][pWhoMarried], dbHandle, MAX_PLAYER_NAME); // whomarried
	cache_get_row(0, 49, PI[playerid][pReferal], dbHandle, MAX_PLAYER_NAME); // referal
	PI[playerid][pRefMoney] = cache_get_row_int(0, 50, dbHandle); // refmoney
	PI[playerid][pPayCheck] = cache_get_row_int(0, 51, dbHandle); // paycheck
	PI[playerid][pCharity] = cache_get_row_int(0, 52, dbHandle); // charity
	PI[playerid][pVip] = cache_get_row_int(0, 53, dbHandle); // vip
	PI[playerid][pVipTime] = cache_get_row_int(0, 54, dbHandle); // viptime
	PI[playerid][pTime] = cache_get_row_int(0, 55, dbHandle); // time
	PI[playerid][pFightStyle] = cache_get_row_int(0, 56, dbHandle); // fstyle
	PI[playerid][pCredits] = cache_get_row_int(0, 57, dbHandle); // credits
	PI[playerid][pTotalCredits] = cache_get_row_int(0, 58, dbHandle); // totalcredits
	PI[playerid][pSkin][0] = cache_get_row_int(0, 59, dbHandle); // skin1
	PI[playerid][pSkin][1] = cache_get_row_int(0, 60, dbHandle); // skin2
	PI[playerid][pSkin][2] = cache_get_row_int(0, 61, dbHandle); // skin3
	PI[playerid][pSpawnChange] = cache_get_row_int(0, 62, dbHandle); // spawnchange
	PI[playerid][pSkill] = cache_get_row_int(0, 63, dbHandle); // sdpistol
	PI[playerid][pSkill][1] = cache_get_row_int(0, 64, dbHandle); // deserteagle
	PI[playerid][pSkill][2] = cache_get_row_int(0, 65, dbHandle); // shotgun
	PI[playerid][pSkill][3] = cache_get_row_int(0, 66, dbHandle); // mp5
	PI[playerid][pSkill][4] = cache_get_row_int(0, 67, dbHandle); // ak47
	PI[playerid][pSkill][5] = cache_get_row_int(0, 68, dbHandle); // m4
	PI[playerid][pGunSkill][6] = cache_get_row_int(0, 69, dbHandle); // pistol
	PI[playerid][pGunSkill][7] = cache_get_row_int(0, 70, dbHandle); // microuzi
	PI[playerid][pHunger] = cache_get_row_int(0, 71, dbHandle); // hunger
	PI[playerid][pHealthS] = cache_get_row_int(0, 72, dbHandle); // healths
	PI[playerid][pSportExp] = cache_get_row_int(0, 73, dbHandle); // sportexp
	PI[playerid][pOnline] = cache_get_row_int(0, 74, dbHandle); // online
	PI[playerid][pZakon] = cache_get_row_int(0, 75, dbHandle); // zakon
	PI[playerid][pCity] = cache_get_row_int(0, 76, dbHandle); // city
	cache_get_row(0, 77, PI[playerid][pRepcars], dbHandle, 16); // repcar
	PI[playerid][pBed] = cache_get_row_int(0, 78, dbHandle); // bed
	PI[playerid][pWatch] = cache_get_row_int(0, 79, dbHandle); // watch
	PI[playerid][pCiggare] = cache_get_row_int(0, 80, dbHandle); // ciggare
	PI[playerid][pSprunk] = cache_get_row_int(0, 81, dbHandle); // sprunk
	PI[playerid][pMask] = cache_get_row_int(0, 82, dbHandle); // mask
	PI[playerid][pPhoneBalance] = cache_get_row_int(0, 83, dbHandle); // phonebalance
	PI[playerid][pTruckSkill] = cache_get_row_int(0, 84, dbHandle); // truckskill
	PI[playerid][cModel][0] = cache_get_row_int(0, 85, dbHandle); // cModel
	PI[playerid][cClass][0] = cache_get_row_int(0, 86, dbHandle); // cClass
	PI[playerid][cFuel][0] = cache_get_row_int(0, 87, dbHandle); // cFuel
	PI[playerid][cColor][0] = cache_get_row_int(0, 88, dbHandle); // cColor1
	PI[playerid][cColor][1] = cache_get_row_int(0, 89, dbHandle); // cColor2
	PI[playerid][cLock][0] = cache_get_row_int(0, 90, dbHandle); // cLock
	PI[playerid][cCost][0] = cache_get_row_int(0, 91, dbHandle); // cCost
	cache_get_row(0, 92, PI[playerid][cVehcom], dbHandle, 64); // cVehcom
	PI[playerid][cPaintjob] = cache_get_row_int(0, 93, dbHandle); // cPaintjob
	PI[playerid][cProbeg] = cache_get_row_int(0, 94, dbHandle); // cPaintjob
	PI[playerid][pAptechka] = cache_get_row_int(0, 95, dbHandle); // aptechka
	PI[playerid][pVoennik] = cache_get_row_int(0, 96, dbHandle); // Voennik
	PI[playerid][pMusic] = cache_get_row_int(0, 97, dbHandle); // music
	cache_get_row(0, 98, PI[playerid][pImproves], dbHandle, 32); // improves
	PI[playerid][pSettings] = cache_get_row_int(0, 99, dbHandle); // settings
	PhoneNumbers[playerid][0] = cache_get_row_int(0, 101, dbHandle); // phnumber1
	PhoneNumbers[playerid][1] = cache_get_row_int(0, 102, dbHandle); // phnumber2
	PhoneNumbers[playerid][2] = cache_get_row_int(0, 103, dbHandle); // phnumber3
	PhoneNumbers[playerid][3] = cache_get_row_int(0, 104, dbHandle); // phnumber4
	PhoneNumbers[playerid][4] = cache_get_row_int(0, 105, dbHandle); // phnumber5
	PhoneNumbers[playerid][5] = cache_get_row_int(0, 106, dbHandle); // phnumber6
	PhoneNumbers[playerid][6] = cache_get_row_int(0, 107, dbHandle); // phnumber7
	PhoneNumbers[playerid][7] = cache_get_row_int(0, 108, dbHandle); // phnumber8
	PI[playerid][pVehicleKey][0] = cache_get_row_int(0, 108, dbHandle); // mailconf
	PI[playerid][pVehicleKey][1] = cache_get_row_int(0, 109, dbHandle); // mailconf
	PI[playerid][pMailConfirmed] = cache_get_row_int(0, 109, dbHandle); // mailconf
	PI[playerid][pCarA] = cache_get_row_int(0, 112, dbHandle); // cash
	PI[playerid][pCarB] = cache_get_row_int(0, 113, dbHandle); // cash
	PI[playerid][pCarC] = cache_get_row_int(0, 114, dbHandle); // cash
	PI[playerid][pCarD] = cache_get_row_int(0, 115, dbHandle); // cash
    cache_get_field_content(0,"pInt",pint), PI[playerid][pInt] = strval(pint);
    cache_get_field_content(0,"pWorld",pworld), PI[playerid][pWorld] = strval(pworld);
    cache_get_field_content(0,"PosX",posx), PI[playerid][PosX] = floatstr(posx);
    cache_get_field_content(0,"PosY",posy), PI[playerid][PosY] = floatstr(posy);
    cache_get_field_content(0,"PosZ",posz), PI[playerid][PosZ] = floatstr(posz);
    PI[playerid][pTruckLevel] = cache_get_row_int(0, 121, dbHandle); // truckskill
    PI[playerid][P_ENTRANCE] = cache_get_row_int(0, 122, dbHandle);
	PI[playerid][P_ROOM] = cache_get_row_int(0, 123, dbHandle);
    /*PI[playerid][pFamily] = cache_get_row_int(0, 122, dbHandle); // fama
	PI[playerid][pFamilySozd] = cache_get_row_int(0, 123, dbHandle); // sozd
	PI[playerid][pFamilyZam] = cache_get_row_int(0, 124, dbHandle); //zam
	*/


	new l_guns[56], l_ammo[56];
	
	cache_get_row(0, 26, l_guns, dbHandle, 64); // guns
	cache_get_row(0, 27, l_ammo, dbHandle, 64); // ammos

	new g_data[13], a_data[13];
	sscanf(l_guns, "p<,>a<i>[13]", g_data);
	sscanf(l_ammo, "p<,>a<i>[13]", a_data);
	for(new i; i < 13; i++)
	{
	    PI[playerid][pGun][i] = g_data[i];
	    PI[playerid][pAmmo][i] = a_data[i];
	}
	SetPVarInt(playerid, "Connected", 1);
		
    sscanf(PI[playerid][cVehcom], "p<,>a<i>[14]",PI[playerid][cVehcoms]);
	sscanf(PI[playerid][pTexts], "p<,>a<i>[4]", PI[playerid][pText]);
	sscanf(PI[playerid][pRepcars], "p<,>a<i>[2]", PI[playerid][pRepcar]);
	sscanf(PI[playerid][pImproves], "p<,>a<i>[4]", PI[playerid][pImprove]);
	sscanf(PI[playerid][pLics], "p<,>a<i>[4]",PI[playerid][pLic]);


	//if(PI[playerid][cModel][0] > 0 && GetPlayerPorchHouse(playerid) == 0) LoadMyCar(playerid);
	DeletePVar(playerid, "Logged");
	DeletePVar(playerid, "avttimer");

    GetPlayerIp(playerid, PI[playerid][pIP], 16);
	format(query, 256, "UPDATE `accounts` SET ip = '%s', online = '1' WHERE id = '%i' LIMIT 1", PI[playerid][pIP], PI[playerid][pID]);
	mysql_tquery(dbHandle, query, "", "");
	
	new string[128];
    mysql_format(dbHandle, string, sizeof(string), "SELECT * FROM "T_SUPPORT" WHERE `name` = '%s' LIMIT 1", GetName(playerid));
	mysql_tquery(dbHandle, string, "SupportAuth", "i", playerid);

	mysql_format(dbHandle, string, sizeof(string), "SELECT * FROM "T_YOUTUBER" WHERE `name` = '%s' LIMIT 1", GetName(playerid));
	mysql_tquery(dbHandle, string, "YouTuberAuth", "i", playerid);
	
	PlayerTimerID[playerid] = SetTimerEx("PlayerUpdate", 1000, 1, "d", playerid);
	
	if(PI[playerid][pCheckCode] == 1)
	{
	    new texter_pas[5];
		new digitsd[9] = {1,2,3,4,5,6,7,8,9};
		for(new i, rand, old_digit; i < 9; i++)
		{
			while((rand = random(9)) == i) {}
			old_digit = digitsd[i];
			digitsd[i] = digitsd[rand];
			digitsd[rand] = old_digit;
		}
    	for(new f = 0; f < 10; f++)
		{
		    if(f < 9)
		    {
		        mass_pass[playerid][f] = digitsd[f];
				format(texter_pas,sizeof(texter_pas),"%i",mass_pass[playerid][f]);
				PlayerTextDrawSetString(playerid,SecurityCode[playerid][f],texter_pas);
		    }
			PlayerTextDrawShow(playerid,SecurityCode[playerid][f]);
		}
		SendClientMessage(playerid, COLOR_LIME, "Система безопасности запрашивает ввод Вашего графического пароля");
		PI[playerid][pInputCode] = 0;
		Ujahhs[playerid] = 1;
		SelectTextDraw(playerid, -264092161);
	}
	else if(PI[playerid][pCheckCode] == 2)
	{
	    if(!strcmp(PI[playerid][pLastIP],PI[playerid][pIP],true))
		{
		    PlayerLogged[playerid] = true;
		    Hunger(playerid, 0);
   			SpawnPlayer(playerid);
		}
		else
		{
		    new texter_pas[5];
			new digitsd[9] = {1,2,3,4,5,6,7,8,9};
			for(new i, rand, old_digit; i < 9; i++)
			{
				while((rand = random(9)) == i) {}
				old_digit = digitsd[i];
				digitsd[i] = digitsd[rand];
				digitsd[rand] = old_digit;
			}
	    	for(new f = 0; f < 10; f++)
			{
			    if(f < 9)
			    {
			        mass_pass[playerid][f] = digitsd[f];
					format(texter_pas,sizeof(texter_pas),"%i",mass_pass[playerid][f]);
					PlayerTextDrawSetString(playerid,SecurityCode[playerid][f],texter_pas);
			    }
				PlayerTextDrawShow(playerid,SecurityCode[playerid][f]);
			}
			SendClientMessage(playerid, COLOR_LIME, "Система безопасности запрашивает ввод Вашего графического пароля");
			PI[playerid][pInputCode] = 0;
			Ujahhs[playerid] = 1;
			SelectTextDraw(playerid,-264092161);
		}
	}
	else if(PI[playerid][pCheckCode] == 3)
	{
	    new strv[26], strvv[26], splitt[4][4], spli[4][4];
	    split(PI[playerid][pLastIP], splitt, '.');
		format(strv, sizeof(strv), "%s.%s", splitt[0], splitt[1]);
	    split(PI[playerid][pIP], spli, '.');
		format(strvv, sizeof(strvv), "%s.%s", spli[0], spli[1]);
	    if(strcmp(strv,strvv,true))
		{
		    new texter_pas[5];
			new digitsd[9] = {1,2,3,4,5,6,7,8,9};
			for(new i, rand, old_digit; i < 9; i++)
			{
				while((rand = random(9)) == i) {}
				old_digit = digitsd[i];
				digitsd[i] = digitsd[rand];
				digitsd[rand] = old_digit;
			}
	    	for(new f = 0; f < 10; f++)
			{
			    if(f < 9)
			    {
			        mass_pass[playerid][f] = digitsd[f];
					format(texter_pas,sizeof(texter_pas),"%i",mass_pass[playerid][f]);
					PlayerTextDrawSetString(playerid,SecurityCode[playerid][f],texter_pas);
			    }
				PlayerTextDrawShow(playerid,SecurityCode[playerid][f]);
			}
			SendClientMessage(playerid, COLOR_LIME, "Система безопасности запрашивает ввод Вашего графического пароля");
			PI[playerid][pInputCode] = 0;
			Ujahhs[playerid] = 1;
			SelectTextDraw(playerid,-264092161);
		}
		else
		{
            ShowPlayerDialog(playerid, SelectSpawn, DIALOG_STYLE_LIST, "{FFCC00}Выберите спавн:", "- Вокзал\n- Дом\n- Квартира\n- База организации", "Выбрать", "Отмена");
		    PlayerLogged[playerid] = true;
		    Hunger(playerid, 0);
            if(GetPVarInt(playerid, "check_adm") > gettime()) return 1;
  			else if(AdminLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Вы уже авторизовались как администратор!");
			format(string, sizeof(string), "SELECT * FROM `admins` WHERE `name` = '%s'", GetName(playerid));
			mysql_tquery(dbHandle, string, "admAuth", "is", playerid, GetName(playerid));
 			SetPVarInt(playerid, "check_adm", gettime()+5);
		}
	}
	else
	{
        ShowPlayerDialog(playerid, SelectSpawn, DIALOG_STYLE_LIST, "{FFCC00}Выберите спавн:", "- Вокзал\n- Дом\n- Квартира\n- База организации", "Выбрать", "Отмена");
	    PlayerLogged[playerid] = true;
	    Hunger(playerid, 0);
     	if(GetPVarInt(playerid, "check_adm") > gettime()) return 1;
  		else if(AdminLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Вы уже авторизовались как администратор!");
		format(string, sizeof(string), "SELECT * FROM `admins` WHERE `name` = '%s'", GetName(playerid));
		mysql_tquery(dbHandle, string, "admAuth", "is", playerid, GetName(playerid));
		SetPVarInt(playerid, "check_adm", gettime()+5);
	}
	if(PI[playerid][pVip] == 1)
	{
		new fmt_msg[128];

		{
// 			new year, month, day;
//			new current_date = getdate(year, month, day);
//			new time_left = PI[playerid][pVipTime] - current_date;
			format(fmt_msg, sizeof fmt_msg, "Здраствуйте, VIP игрок!");
			SendClientMessage(playerid, 0x99FF66AA, fmt_msg);
		}

	}
	switch(PI[playerid][pAdmin])
    {
		case 1: SendClientMessage(playerid, 0x99CCFFFF, "Вы вошли как администратор первого уровня");
		case 2: SendClientMessage(playerid, 0x99CCFFFF, "Вы вошли как администратор второго уровня");
		case 3: SendClientMessage(playerid, 0x99CCFFFF, "Вы вошли как администратор третьего уровня");
		case 4: SendClientMessage(playerid, 0x99CCFFFF, "Вы вошли как администратор четвёртого уровня");
		case 5: SendClientMessage(playerid, 0x99CCFFFF, "Вы вошли как администратор пятого уровня");
		case 6: SendClientMessage(playerid, 0x99CCFFFF, "Вы вошли как главный администратор");
		case 7: SendClientMessage(playerid, 0x99CCFFFF, "Вы вошли как руководитель проекта");
    }
	if(Pick == 1)
	{
		SendClientMessageToAll(COLOR_WHITE, "Сегодня проходят выборы Мэра!");
		SendClientMessageToAll(COLOR_WHITE, "Голосование проходит в администрации области пгт. Батырево на первом этаже. Сделайте свой выбор");
	}
	if(PI[playerid][pText][0] == 1)
	{
		new i = PI[playerid][pText][0];
		PI[playerid][pBank] += HouseInfo[i][hPrice];
		SendMes(playerid, COLOR_YELLOW, "[Квитанция] Вы были выселены за неуплату! Вам было возвращено {FFCC00}%d рублей", HouseInfo[i][hPrice]);
		SendClientMessage(playerid, COLOR_YELLOW, "[Квитанция] Деньги были переведены На Ваш банковский счет");
		format(PI[playerid][pTexts], 20,  "0, %i, %i, %i", PI[playerid][pText][1], PI[playerid][pText][2], PI[playerid][pText][3]);
		format(query, 256, "UPDATE `accounts` SET text = '%s' WHERE name = '%s'", PI[playerid][pTexts], GetName(playerid));
		mysql_tquery(dbHandle, query, "", "");
	}
	if(PI[playerid][pText][1] == 1)
	{
		SendClientMessage(playerid, COLOR_YELLOW, "[Налоговая служба] Ваш бизнес закрыли в связи с нехваткой ресурсов");
		SendClientMessage(playerid, COLOR_YELLOW, "[Налоговая служба] Бюджет бизнеса зачислен На Ваш банковский счет");
		format(PI[playerid][pTexts], 20, "%i, 0, %i, %i", PI[playerid][pText][0], PI[playerid][pText][2], PI[playerid][pText][3]);
		format(query, 256, "UPDATE `accounts` SET text = '%s' WHERE name = '%s'", PI[playerid][pTexts], GetName(playerid));
		mysql_tquery(dbHandle, query, "", "");
	}
	if(PI[playerid][pText][2] == 1)
	{
		TransferMoney(-1, playerid, 100000);
		SendClientMessage(playerid, COLOR_ORANGE, "Вы получили 100 000 рублей на банковский счет, приглашённого друга");
		PI[playerid][pRefMoney] = 0;
		format(PI[playerid][pTexts], 20, "%i, %i, 0, %i", PI[playerid][pText][0], PI[playerid][pText][1], PI[playerid][pText][3]);
		format(query, 256, "UPDATE `accounts` SET text = '%s', refmoney = %d WHERE name = '%s'", PI[playerid][pTexts], PI[playerid][pRefMoney], GetName(playerid));
		mysql_tquery(dbHandle, query, "", "");
	}
	if(PI[playerid][pText][3] == 1)
	{
		SendClientMessage(playerid, COLOR_LIME, "{DC4747}[Информация] {ffffff}На Ваш счёт поступил донат платёж (/donate - Проверить зачисления)");
		format(PI[playerid][pTexts], 20, "%i, %i, %i, 0", PI[playerid][pText][0], PI[playerid][pText][1], PI[playerid][pText][2]);
		format(query, 256, "UPDATE `accounts` SET text = '%s' WHERE name = '%s'", PI[playerid][pTexts], GetName(playerid));
		mysql_tquery(dbHandle, query, "", "");
	}
	StopAudioStreamForPlayer(playerid);
	if(PI[playerid][pVipTime] > 0)
	{
	    new year, month, day;
		new current_date = getdate(year, month, day);
		new time_left = PI[playerid][pVipTime] - current_date;
		if(time_left <= 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "Срок действия вашего VIP аккаунта истек!");
			PI[playerid][pVip] = PI[playerid][pVipTime] = 0;
		}
	}
	/*new string[256];
 	format(string, sizeof(string), "SELECT * FROM `admins` WHERE `name` = '%s'", GetName(playerid));
	mysql_tquery(dbHandle, string, "admAuth", "is", playerid, GetName(playerid));
	SetPVarInt(playerid, "check_adm", gettime()+5);*/
	TextDrawShowForPlayer(playerid, logo);
	return 1;
}
//==============================================================================
stock SaveAccount(playerid)
{
	if(PlayerLogged[playerid] == false || IsPlayerConnected(playerid) == 0) return 1;
	new src[90], year, month, day;
	getdate(year, month, day);
	format(global_string,sizeof(global_string),"UPDATE "T_ACCOUNTS" SET ");
	format(src,sizeof(src),"ip='%s',",PI[playerid][pIP]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"level=%d,",PI[playerid][pLevel]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"admin=%d,",PI[playerid][pAdmin]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"sex=%d,",PI[playerid][pSex]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"age=%d,",PI[playerid][pAge]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"securitycode='%i',",PI[playerid][pSecurityCode]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"model=%d,",PI[playerid][pModel]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"memberskin=%d,",PI[playerid][pMemberSkin]);
	strcat(global_string,src,sizeof(global_string));
	if(PI[playerid][pCash] < -1000000) PI[playerid][pCash] = BONUS_CASH;
	format(src,sizeof(src),"cash=%d,",PI[playerid][pCash]);
	strcat(global_string,src,sizeof(global_string));
	if(PI[playerid][pBank] < -1000000) PI[playerid][pBank] = 0;
	format(src,sizeof(src),"bank=%d,",PI[playerid][pBank]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"mute=%d,",PI[playerid][pMuted]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"warn=%d,",PI[playerid][pWarn]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"leader=%d,",PI[playerid][pLeader]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"templeader=%d,",PI[playerid][pTempLeader]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"member=%d,",PI[playerid][pMember]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"rank=%d,",PI[playerid][pRank]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"exp=%d,",PI[playerid][pExp]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"news=%d,",PI[playerid][pNews]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"crimes=%d,",PI[playerid][pCrimes]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"wanted=%d,",PI[playerid][pWanted]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"wantedtime=%d,",PI[playerid][pWantedTime]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"wantedwho='%s',",PI[playerid][pWantedWho]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"wantedreason='%s',",PI[playerid][pWantedReason]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"jail=%d,",PI[playerid][pJail]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"job=%d,",PI[playerid][pJob]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"jailtime=%d,",PI[playerid][pJailTime]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"checktime=%d,",PI[playerid][pCheckTime]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"drugs=%d,",PI[playerid][pDrugs]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"married=%d,",PI[playerid][pMarried]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"whomarried='%s',",PI[playerid][pWhoMarried]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"paycheck='%i',",PI[playerid][pPayCheck]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"charity='%i',",PI[playerid][pCharity]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"vip='%i',",PI[playerid][pVip]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"viptime='%i',",PI[playerid][pVipTime]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"time='%i',",PI[playerid][pTime]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"fstyle='%i',",PI[playerid][pFightStyle]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"skin1='%i',",PI[playerid][pSkin][0]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"skin2='%i',",PI[playerid][pSkin][1]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"skin3='%i',",PI[playerid][pSkin][2]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"spawnchange='%i',",PI[playerid][pSpawnChange]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"sdpistol='%i',",PI[playerid][pGunSkill][0]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"deserteagle='%i',",PI[playerid][pGunSkill][1]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"shotgun='%i',",PI[playerid][pGunSkill][2]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"mp5='%i',",PI[playerid][pGunSkill][3]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"ak47='%i',",PI[playerid][pGunSkill][4]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"m4='%i',",PI[playerid][pGunSkill][5]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"pistol='%i',",PI[playerid][pGunSkill][6]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"microuzi='%i',",PI[playerid][pGunSkill][7]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"sportexp='%i',",PI[playerid][pSportExp]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"zakon='%i',",PI[playerid][pZakon]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"checkcode='%i',",PI[playerid][pCheckCode]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"city='%i',",PI[playerid][pCity]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"bed='%i',",PI[playerid][pBed]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"watch='%i',",PI[playerid][pWatch]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"ciggare='%i',",PI[playerid][pCiggare]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"sprunk='%i',",PI[playerid][pSprunk]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"mask='%i',",PI[playerid][pMask]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"phonebalance='%i',",PI[playerid][pPhoneBalance]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"cModel='%i',",PI[playerid][cModel]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"cFuel='%i',",PI[playerid][cFuel]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"cClass='%i',",PI[playerid][cClass]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"cColor1='%i',",PI[playerid][cColor][0]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"cColor2='%i',",PI[playerid][cColor][1]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"cLock='%i',",PI[playerid][cLock]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"cCost='%i',",PI[playerid][cCost]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"cVehcom='%i',",PI[playerid][cVehcom]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"cPaintjob='%i',",PI[playerid][cPaintjob]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"cProbeg='%i',",PI[playerid][cProbeg]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"aptechka='%i',",PI[playerid][pAptechka]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"Voennik='%i',",PI[playerid][pVoennik]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"music='%i',",PI[playerid][pMusic]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"datavhod='%d.%d.%d',",day, month, year);
	strcat(global_string,src,sizeof(global_string));
	/*format(PI[playerid][pPhones],16,"%i, %i",PI[playerid][pPhone][0],PI[playerid][pPhone][1]);
	format(src,sizeof(src),"phone='%s',",PI[playerid][pPhones]);
	strcat(global_string,src,sizeof(global_string));*/
	format(PI[playerid][pRepcars],16,"%i, %i",PI[playerid][pRepcar][0],PI[playerid][pRepcar][1]);
	format(src,sizeof(src),"repcar='%s',",PI[playerid][pRepcars]);
	strcat(global_string,src,sizeof(global_string));
	format(PI[playerid][pImproves],32,"%i, %i, %i, %i",PI[playerid][pImprove][0],PI[playerid][pImprove][1],PI[playerid][pImprove][2],PI[playerid][pImprove][3]);
	format(src,sizeof(src),"improves='%s',",PI[playerid][pImproves]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"veh_reg='%i',",PI[playerid][pRegVehicle]);
	strcat(global_string,src,sizeof(query));
	format(src,sizeof(src),"pcara='%i',",PI[playerid][pCarA]);
	strcat(global_string,src,sizeof(query));
	format(src,sizeof(src),"pcarb='%i',",PI[playerid][pCarB]);
	strcat(global_string,src,sizeof(query));
	format(src,sizeof(src),"pcarc='%i',",PI[playerid][pCarC]);
	strcat(global_string,src,sizeof(query));
	format(src,sizeof(src),"pcard='%i',",PI[playerid][pCarD]);
	strcat(global_string,src,sizeof(query));
	format(src,sizeof(src),"phonenumber='%i',",PI[playerid][pPhoneNumber]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"phnumber1='%i',",PhoneNumbers[playerid][0]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"phnumber2='%i',",PhoneNumbers[playerid][1]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"phnumber3='%i',",PhoneNumbers[playerid][2]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"phnumber4='%i',",PhoneNumbers[playerid][3]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"phnumber5='%i',",PhoneNumbers[playerid][4]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"phnumber6='%i',",PhoneNumbers[playerid][5]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"phnumber7='%i',",PhoneNumbers[playerid][6]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"phnumber8='%i',",PhoneNumbers[playerid][7]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"trucklevel='%i',",PI[playerid][pTruckLevel]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src),"entrance='%s',",PI[playerid][P_ENTRANCE]);
 	format(src,sizeof(src),"room='%s',",PI[playerid][P_ROOM]);
	strcat(global_string,src,sizeof(global_string));

	format(PI[playerid][pLics],16,"%i, %i, %i, %i",PI[playerid][pLic][0],PI[playerid][pLic][1],PI[playerid][pLic][2],PI[playerid][pLic][3]);
	format(src,sizeof(src),"lic='%s'",PI[playerid][pLics]);
	strcat(global_string,src,sizeof(global_string));
	format(src,sizeof(src)," WHERE name='%s' LIMIT 1",GetName(playerid));
	strcat(global_string,src,sizeof(global_string));
	mysql_tquery(dbHandle, global_string, "", "");
	return 1;
}
//==============================================================================
stock MysqlUpdatePlayerStr(playerid, field[], data[])
{
	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_ACCOUNTS" SET %s = '%s' WHERE name = '%s'", field, data, GetName(playerid));
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
}
//==============================================================================
stock MysqlUpdatePlayerInt(playerid, field[], data[])
{
	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_ACCOUNTS" SET %s = '%i' WHERE name = '%s'", field, data, GetName(playerid));
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
}
//==============================================================================
stock MysqlUpdateHouseStr(idx, field[], data[])
{
	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_HOUSE" SET %s = '%s' WHERE id = '%d' LIMIT 1", field, data, idx);
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
}
//==============================================================================
stock MysqlUpdateHouseInt(idx, field[], data)
{
	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_HOUSE" SET %s = '%d' WHERE id = '%d' LIMIT 1", field, data, idx);
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
}
//==============================================================================
stock MysqlUpdateBizzStr(idx, field[], data[])
{
	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_BIZZ" SET %s = '%s' WHERE id = '%d' LIMIT 1", field, data, idx);
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
}
//==============================================================================
stock MysqlUpdateBizzInt(idx, field[], data)
{
	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_BIZZ" SET %s = '%d' WHERE id = '%d' LIMIT 1", field, data, idx);
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
}
//==============================================================================
stock MysqlUpdateOtherStr(field[], data[])
{
	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_OTHER" SET %s = '%s' LIMIT 1", field, data);
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
}
//==============================================================================
stock MysqlUpdateOtherInt(field[], data)
{
	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_OTHER" SET %s = '%d' LIMIT 1", field, data);
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
}

stock MysqlUpdateGangInt(field[], data)
{
	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_GANG" SET %s = '%d' LIMIT 1", field, data);
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
}

stock MysqlUpdateMafiaInt(field[], data)
{
	STRING_GLOBAL[0] = EOS;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "UPDATE "T_MAFIA" SET %s = '%d' LIMIT 1", field, data);
	mysql_tquery(dbHandle, STRING_GLOBAL, "", "");
}

/*forward LoadFamily();
public LoadFamily ()
{
	new time = GetTickCount(), rows, fields, temp [32];
    cache_get_data(rows,fields);
    if(rows)
    {
		for(new f = 1; f <= rows; f++)
  		{
            cache_get_field_content(f-1, "fam_name", temp) ,sscanf(temp, "s[64]", family_info[f][f_name]);
            cache_get_field_content(f-1, "fam_creator", temp) , sscanf(temp, "s[64]", family_info[f][f_creator]) ;
            cache_get_field_content(f-1, "fam_zamcreator", temp) , sscanf(temp, "s[64]", family_info[f][f_creator_zam]) ;
            cache_get_field_content(f-1, "fam_data", temp ) , sscanf(temp, "s[32]", family_info[f][f_creating_data]);
            family_info[f][f_chat_color] = cache_get_field_content_int(f-1, "fam_chat_color");
            family_info[f][f_members_amount] = cache_get_field_content_int(f-1, "fam_members_amount");
            family_info[f][f_narko] = cache_get_field_content_int(f-1, "f_narko");
            family_info[f][f_pt] = cache_get_field_content_int(f-1, "f_pt");
            family_info[f][f_money] = cache_get_field_content_int(f-1, "f_money");

			family_count++;
		}
        printf("[Загружено семей]: <%d>. Потрачено: <%i ms>.", family_count, GetTickCount() - time);
    }
    else return print("[Загружено семей]: <0>. Потрачено: <->");
    return true;
}*/

/*public: LoadFamily()
{
	new time = GetTickCount();
	new rows, fields;
	cache_get_data(rows, fields);

	if(rows)
	{
		new sub[16];

		for(new idx = 1; idx <= rows; idx ++)
		{
			cache_get_row(idx-1, 1, g_family_info[idx][F_NAME], dbHandle, 64);
			SetFamilyData(idx, F_OWNED, cache_get_row_int(idx-1, 2, dbHandle));
			cache_get_row(idx-1, 3, g_family_info[idx][F_OWNER], dbHandle, 64);
			cache_get_row(idx-1, 4, sub, dbHandle, 16);
			sscanf(sub, "p<,>ddd", g_family_info[idx][F_SUB][0], g_family_info[idx][F_SUB][1], g_family_info[idx][F_SUB][2]);

			SetFamilyData(idx, F_HOUSE, cache_get_row_int(idx-1, 6, dbHandle));
			SetFamilyData(idx, F_DRUGS, cache_get_row_int(idx-1, 7, dbHandle));
			SetFamilyData(idx, F_PATRON, cache_get_row_int(idx-1, 8, dbHandle));
			SetFamilyData(idx, F_MONEY, cache_get_row_int(idx-1, 9, dbHandle));
			SetFamilyData(idx, F_PROD, cache_get_row_int(idx-1, 10, dbHandle));
			SetFamilyData(idx, F_SPAWN, bool: cache_get_row_int(idx-1, 11, dbHandle));

			if(GetFamilyData(idx, F_HOUSE) != -1)
			{
				SetFamilyData(idx, F_STORE_LABEL, CreateDynamic3DTextLabel("Склад", 0xFFFF00FF, 498.0487,-2.2444,1904.9518+1.0, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, HouseInfo[GetFamilyData(idx, F_HOUSE)][hVirtual], HouseInfo[GetFamilyData(idx, F_HOUSE)][hInt]));
				UpdateHouseFamilyLabel(idx);
			}

			for(new i; i < 10; i ++)
			{
				g_family_info[idx][F_CARS][i] = INVALID_VEHICLE_ID;
			}

			TOTALFAMILY ++;

		}
	}
	printf("[Загружено семей]: <%d>. Потрачено: <%i ms>.", rows, GetTickCount() - time);
	return 1;
}*/

/*forward LoadFamily();
public LoadFamily()
{
	new time = GetTickCount(), rows, fields, temp [88];
	cache_get_data(rows,fields);
	if(rows)
	{
		for(new f = 1; f <= rows; f++)
		{
			cache_get_field_content(f-1, "fam_name", temp) ,sscanf(temp, "s[64]", family_info[f][f_name]);
			cache_get_field_content(f-1, "fam_creator", temp) , sscanf(temp, "s[64]", family_info[f][f_creator]) ;
			cache_get_field_content(f-1, "fam_zamcreator", temp) , sscanf(temp, "s[64]", family_info[f][f_creator_zam]) ;
			cache_get_field_content(f-1, "fam_data", temp ) , sscanf(temp, "s[32]", family_info[f][f_creating_data]);
			family_info[f][f_chat_color] = cache_get_field_content_int(f-1, "fam_chat_color");
			family_info[f][f_members_amount] = cache_get_field_content_int(f-1, "fam_members_amount");

			cache_get_field_content ( f-1, "f_spawn", temp ), sscanf ( temp, "p<,>ffffdd",
			family_info [ f ] [ f_spawn ] [ 0 ], family_info [ f ] [ f_spawn ] [ 1 ], family_info [ f ] [ f_spawn ] [ 2 ], family_info [ f ] [ f_spawn ] [ 3 ],
			family_info [ f ] [ f_spawn_int ], family_info [ f ] [ f_spawn_virt ] ) ;

			family_info [ f ] [ f_patron ] = cache_get_field_content_int(f-1, "frac_patron");
			family_info [ f ] [ f_metall ] = cache_get_field_content_int(f-1, "frac_metall");
			family_info [ f ] [ f_money ] = cache_get_field_content_int(f-1, "frac_money");
			family_info [ f ] [ f_drugs ] = cache_get_field_content_int(f-1, "frac_drugs");

			family_count++;
		}
		printf("[Загружено семей]: <%d>. Потрачено: <%i ms>.", family_count, GetTickCount() - time);
	}
	else return print("[Загружено семей]: <0>. Потрачено: <->");
	return 1;
}*/
//==============================================================================
forward LoadVeh();
public LoadVeh()
{
	new time = GetTickCount(), rows, fields;
    cache_get_data(rows, fields);
	if(rows)
	{
		for(new idx = 1; idx <= rows; idx++)
		{
		    VehInfo[idx][vVehicle] = INVALID_VEHICLE_ID;
        	VehInfo[idx][vID] = cache_get_row_int(idx-1, 0, dbHandle); // id
			VehInfo[idx][vModel] = cache_get_row_int(idx-1, 1, dbHandle); // model
        	VehInfo[idx][vPos_X] = cache_get_row_float(idx-1, 2, dbHandle); // x
        	VehInfo[idx][vPos_Y] = cache_get_row_float(idx-1, 3, dbHandle); // y
        	VehInfo[idx][vPos_Z] = cache_get_row_float(idx-1, 4, dbHandle); // z
        	VehInfo[idx][vPos_FA] = cache_get_row_float(idx-1, 5, dbHandle); // fa
        	VehInfo[idx][vInt] = cache_get_row_int(idx-1, 6, dbHandle); // vint
        	VehInfo[idx][vWorld] = cache_get_row_int(idx-1, 7, dbHandle); // world
        	cache_get_row(idx-1, 8, VehInfo[idx][vColors], dbHandle, 16); // colors
        	VehInfo[idx][vFraction] = cache_get_row_int(idx-1, 9, dbHandle); // fraction
			VehInfo[idx][vStatus] = cache_get_row_int(idx-1, 10, dbHandle); // status
			VehInfo[idx][vCost] = cache_get_row_int(idx-1, 11, dbHandle); // cost
            sscanf(VehInfo[idx][vColors], "p<,>a<i>[2]", VehInfo[idx][vColor]);
            if(VehInfo[idx][vStatus] == 0 || VehInfo[idx][vStatus] == 2)
            {
	        	VehInfo[idx][vVehicle] = CreateVehicle(VehInfo[idx][vModel], VehInfo[idx][vPos_X], VehInfo[idx][vPos_Y], VehInfo[idx][vPos_Z], VehInfo[idx][vPos_FA], VehInfo[idx][vColor][0], VehInfo[idx][vColor][1], 300);
	            LinkVehicleToInterior(VehInfo[idx][vVehicle], VehInfo[idx][vInt]);
	            SetVehicleVirtualWorld(VehInfo[idx][vVehicle], VehInfo[idx][vWorld]);
	            Fuel[VehInfo[idx][vVehicle]] = 200;
	           	Engine[VehInfo[idx][vVehicle]] = false;
				Lights[VehInfo[idx][vVehicle]] = false;
			}
			TOTALVEH++;
		}
	}
	printf("[Загружено орг/раб. автомобилей]: <%i>. Потрачено: <%i ms>.", TOTALVEH, GetTickCount() - time);
	return 1;
}
//==============================================================================
forward LoadATM();
public LoadATM()
{
	new time = GetTickCount(), rows, fields;
    cache_get_data(rows, fields);
	if(rows)
	{
		for(new idx = 1; idx <= rows; idx++)
		{
			ATMInfo[idx][aID] = cache_get_row_int(idx-1, 0, dbHandle); // ID
			ATMInfo[idx][aX] = cache_get_row_float(idx-1, 1, dbHandle); // aX
			ATMInfo[idx][aY] = cache_get_row_float(idx-1, 2, dbHandle); // aY
			ATMInfo[idx][aZ] = cache_get_row_float(idx-1, 3, dbHandle); // aZ
			ATMInfo[idx][arX] = cache_get_row_float(idx-1, 4, dbHandle); // arX
			ATMInfo[idx][arY] = cache_get_row_float(idx-1, 5, dbHandle); // arY
			ATMInfo[idx][arZ] = cache_get_row_float(idx-1, 6, dbHandle); // arZ
        	TOTALATM++;
			ATM[idx] = CreateObject(2942, ATMInfo[idx][aX], ATMInfo[idx][aY], ATMInfo[idx][aZ], ATMInfo[idx][arX], ATMInfo[idx][arY], ATMInfo[idx][arZ]);
			LABELATM[idx] = CreateDynamic3DTextLabel("Использовать\n{99CC00}Нажмите\"H\"", 0xBBBBBBFF, ATMInfo[idx][aX],ATMInfo[idx][aY],ATMInfo[idx][aZ]+1.1,10.0);
//			ATM[idx] = CreateDynamicMapIcon(ATMInfo[idx][aX], ATMInfo[idx][aY], ATMInfo[idx][aZ], 52, 0, -1, -1, -1, 2000.0);
        }
    }
	printf("[Загружено банкоматов]: <%i>. Потрачено: <%i ms>.", TOTALATM, GetTickCount() - time);
	return 1;
}
//==============================================================================
forward LoadBizz();
public LoadBizz()
{
	new time = GetTickCount(), rows, fields;
    cache_get_data(rows, fields);
	for(new i; i < TOTALBIZZ; i++) strmid(BizzInfo[i][bOwner],"None",0,strlen("None"),MAX_PLAYER_NAME);
	if(rows)
	{
		for(new idx = 1; idx <= rows; idx++)
		{
		    BizzInfo[idx][bID] = cache_get_row_int(idx-1, 0, dbHandle); // id
			cache_get_row(idx-1, 1, BizzInfo[idx][bOwner], dbHandle, MAX_PLAYER_NAME); // owner
			BizzInfo[idx][bType] = cache_get_row_int(idx-1, 2, dbHandle); // type
			BizzInfo[idx][bPrice] = cache_get_row_int(idx-1, 3, dbHandle); // price
			BizzInfo[idx][bBuyPrice] = cache_get_row_int(idx-1, 4, dbHandle); // buyprice
			BizzInfo[idx][bMoney] = cache_get_row_int(idx-1, 5, dbHandle); // money
			BizzInfo[idx][bLic] = cache_get_row_int(idx-1, 6, dbHandle); // lic
			BizzInfo[idx][bEntrx] = cache_get_row_float(idx-1, 7, dbHandle); // x
			BizzInfo[idx][bEntry] = cache_get_row_float(idx-1, 8, dbHandle); // y
			BizzInfo[idx][bEntrz] = cache_get_row_float(idx-1, 9, dbHandle); // z
			BizzInfo[idx][bExitx] = cache_get_row_float(idx-1, 10, dbHandle); // xt
			BizzInfo[idx][bExity] = cache_get_row_float(idx-1, 11, dbHandle); // yt
			BizzInfo[idx][bExitz] = cache_get_row_float(idx-1, 12, dbHandle); // zt
			BizzInfo[idx][bMenux] = cache_get_row_float(idx-1, 13, dbHandle); // menux
			BizzInfo[idx][bMenuy] = cache_get_row_float(idx-1, 14, dbHandle); // menuy
			BizzInfo[idx][bMenuz] = cache_get_row_float(idx-1, 15, dbHandle); // menuz
			BizzInfo[idx][bInt] = cache_get_row_int(idx-1, 16, dbHandle); // vint
			BizzInfo[idx][bVirtual] = cache_get_row_int(idx-1, 17, dbHandle); // virt
			BizzInfo[idx][bMIcon] = cache_get_row_int(idx-1, 18, dbHandle); // icon
			cache_get_row(idx-1, 19, BizzInfo[idx][bName], dbHandle, 32); // name
			BizzInfo[idx][bEnter] = cache_get_row_int(idx-1, 20, dbHandle); // penter
			BizzInfo[idx][bLock] = cache_get_row_int(idx-1, 21, dbHandle); // block
			BizzInfo[idx][bProduct] = cache_get_row_int(idx-1, 22, dbHandle); // product
			BizzInfo[idx][bTill] = cache_get_row_int(idx-1, 23, dbHandle); // till
			BizzInfo[idx][bLockTime] = cache_get_row_int(idx-1, 24, dbHandle); // locktime
			BizzInfo[idx][bMafia] = cache_get_row_int(idx-1, 25, dbHandle); // mafia
			switch(BizzInfo[idx][bMafia])
			{
			   	case TEAM_SPARTAK: MafiaTotalBizz[0]++;
			   	case TEAM_CSKA: MafiaTotalBizz[1]++;
			   	case TEAM_DINAMO: MafiaTotalBizz[2]++;
			   	case TEAM_ZENIT: MafiaTotalBizz[3]++;
			}
			new fee[64], string[200];
			if(BizzInfo[idx][bEnter] == 0) fee = "бесплатно";
			else format(fee, sizeof(fee), "%d рублей", BizzInfo[idx][bEnter]);
			new text[20];
			switch(BizzInfo[idx][bMafia])
			{
			    case TEAM_SPARTAK: text = "ОПГ Ореховское";
			    case TEAM_CSKA: text = "ОПГ Солцне";
			    case TEAM_DINAMO: text = "ОПГ Южная";
			    case TEAM_ZENIT: text = "Чеченская Мафия";
				case 0: text = "отсутствует";
			}
			if(BizzInfo[idx][bType] == 1)
			{
				BizzInfo[idx][bPickup] = CreateDynamicPickup(19132,1, BizzInfo[idx][bEntrx],BizzInfo[idx][bEntry],BizzInfo[idx][bEntrz]);
				BizzInfo[idx][bPickupExit] = CreateDynamicPickup(19132,1,BizzInfo[idx][bExitx], BizzInfo[idx][bExity], BizzInfo[idx][bExitz],BizzInfo[idx][bVirtual]);
				BizzInfo[idx][bMenu] = CreateDynamicSphere(BizzInfo[idx][bMenux],BizzInfo[idx][bMenuy],BizzInfo[idx][bMenuz],1.0,BizzInfo[idx][bVirtual],BizzInfo[idx][bInt]);
				if(BizzInfo[idx][bType] == 8) CreateDynamicPickup(1275,1,BizzInfo[idx][bMenux],BizzInfo[idx][bMenuy],BizzInfo[idx][bMenuz],BizzInfo[idx][bVirtual],BizzInfo[idx][bInt]);
				else CreateDynamicPickup(1514,1,BizzInfo[idx][bMenux],BizzInfo[idx][bMenuy],BizzInfo[idx][bMenuz],BizzInfo[idx][bVirtual],BizzInfo[idx][bInt]);
				if(!strcmp(BizzInfo[idx][bOwner],"None",true))
				{
					format(string, sizeof(string), "{FFCC00}Магазин 24/7\n{FFFFFF}Владелец: {0099FF}государство\n{FFFFFF}Контролирует: {3497FF}%s\n{FFFFFF}Цена: {FFCC00}%d {FFFFFF}рублей\n{FFFFFF}Вход: {FFCC00}бесплатный", text,BizzInfo[idx][bPrice]);
					LABELBIZZ[idx] = CreateDynamic3DTextLabel(string,-1,BizzInfo[idx][bEntrx], BizzInfo[idx][bEntry], BizzInfo[idx][bEntrz]+0.5,20.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1);
				}
				else
				{
					format(string, sizeof(string), "{0099FF}Магазин 24/7 '%s'\n{FFFFFF}Владелец: {0099FF}%s\n{FFFFFF}Контролирует: {3497FF}%s\n{FFFFFF}Вход: {FFCC00}%s", BizzInfo[TOTALBIZZ][bOwner], fee);
//					format(string, sizeof(string), "{0099FF}Магазин 24/7 \n{FFFFFF}Владелец: {0099FF}%s\n{FFFFFF}Контролирует: {3497FF}%s\n{FFFFFF}Вход: {FFCC00}%s",BizzInfo[idx][bOwner],text,fee);
					LABELBIZZ[idx] = CreateDynamic3DTextLabel(string,-1,BizzInfo[idx][bEntrx], BizzInfo[idx][bEntry], BizzInfo[idx][bEntrz]+0.5,20.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1);
				}
			}
			else if(BizzInfo[idx][bType] == 9)
			{
				BizzInfo[idx][bPickup] = CreateDynamicPickup(19132,1, BizzInfo[idx][bEntrx],BizzInfo[idx][bEntry],BizzInfo[idx][bEntrz]);
				BizzInfo[idx][bPickupExit] = CreateDynamicPickup(19132,1,BizzInfo[idx][bExitx], BizzInfo[idx][bExity], BizzInfo[idx][bExitz],BizzInfo[idx][bVirtual]);
				if(!strcmp(BizzInfo[idx][bOwner],"None",true))
				{
					format(string, sizeof(string), "{3497FF}Казино\n{FFFFFF}Владелец: {FFCC00}государство\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена: {FFCC00}%d {FFFFFF}рублей\n{FFFFFF}Цена за вход: {FFCC00}бесплатный",text,BizzInfo[idx][bPrice]);
					LABELBIZZ[idx] = CreateDynamic3DTextLabel(string,-1,BizzInfo[idx][bEntrx], BizzInfo[idx][bEntry], BizzInfo[idx][bEntrz]+0.5,20.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID);
				}
				else
				{
					format(string, sizeof(string), "{3497FF}Казино\n{FFFFFF}Владелец: {0099FF}%s\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена за вход: {FFCC00}%s",BizzInfo[idx][bOwner],text,fee);
					LABELBIZZ[idx] = CreateDynamic3DTextLabel(string,-1,BizzInfo[idx][bEntrx], BizzInfo[idx][bEntry], BizzInfo[idx][bEntrz]+0.5,20.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID);
				}
			}
			else if(BizzInfo[idx][bType] == 2)
			{
			    BizzInfo[idx][bPickup] = CreateDynamicPickup(1650,1,BizzInfo[idx][bEntrx],BizzInfo[idx][bEntry],BizzInfo[idx][bEntrz]);
				if(!strcmp(BizzInfo[idx][bOwner],"None",true))
				{
					format(string, sizeof(string), "{FFCC00}Заправка\n{FFCC00}Заправка продаётся\n{FFFFFF}Цена: {FFCC00}%d рублей\n{ffffff}Цена за 1 литр - {FFCC00}%i рублей\n{FFCC00}Используйте /fill",BizzInfo[idx][bPrice], BizzInfo[idx][bTill]);
					LABELBIZZ[idx] = CreateDynamic3DTextLabel(string,-1,BizzInfo[idx][bEntrx], BizzInfo[idx][bEntry], BizzInfo[idx][bEntrz]+1.5,20.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID);
				}
				else
				{
					format(string, sizeof(string), "{FFCC00}/buyk - купить канистру\n/fill - заправить транспорт\n{FFFFFF}Владелец: {FFCC00}%s\n{FFFFFF}Цена за 1 литр бензина: {FFCC00}%i рублей",BizzInfo[idx][bOwner], BizzInfo[idx][bTill]);
					LABELBIZZ[idx] = CreateDynamic3DTextLabel(string,-1,BizzInfo[idx][bEntrx], BizzInfo[idx][bEntry], BizzInfo[idx][bEntrz]+1.5,20.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID);
				}
			}
			else if(BizzInfo[idx][bType] == 10)
			{
				BizzInfo[idx][bPickup] = CreateDynamicPickup(19132,1, BizzInfo[idx][bEntrx],BizzInfo[idx][bEntry],BizzInfo[idx][bEntrz]);
				BizzInfo[idx][bPickupExit] = CreateDynamicPickup(19132,1,BizzInfo[idx][bExitx], BizzInfo[idx][bExity], BizzInfo[idx][bExitz],BizzInfo[idx][bVirtual]);
				BizzInfo[idx][bMenu] = CreateDynamicSphere(BizzInfo[idx][bMenux],BizzInfo[idx][bMenuy],BizzInfo[idx][bMenuz],1.0,BizzInfo[idx][bVirtual],BizzInfo[idx][bInt]);
				if(BizzInfo[idx][bType] == 8) CreateDynamicPickup(1275,1,BizzInfo[idx][bMenux],BizzInfo[idx][bMenuy],BizzInfo[idx][bMenuz],BizzInfo[idx][bVirtual],BizzInfo[idx][bInt]);
				else CreateDynamicPickup(1274,1,BizzInfo[idx][bMenux],BizzInfo[idx][bMenuy],BizzInfo[idx][bMenuz],BizzInfo[idx][bVirtual],BizzInfo[idx][bInt]);
				if(!strcmp(BizzInfo[idx][bOwner],"None",true))
				{
					format(string, sizeof(string), "{3497FF}Магазин Игрушек\n{FFFFFF}Владелец: {FFCC00}государство\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена: {FFCC00}%d {FFFFFF}рублей\n{FFFFFF}Цена за вход: {FFCC00}бесплатный", text,BizzInfo[idx][bPrice]);
					LABELBIZZ[idx] = CreateDynamic3DTextLabel(string,-1,BizzInfo[idx][bEntrx], BizzInfo[idx][bEntry], BizzInfo[idx][bEntrz]+0.5,20.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1);
				}
				else
				{
					format(string, sizeof(string), "{3497FF}Магазин Игрушек\n{FFFFFF}Владелец: {0099FF}%s\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена за вход: {FFCC00}%s",BizzInfo[idx][bOwner],text,fee);
					LABELBIZZ[idx] = CreateDynamic3DTextLabel(string,-1,BizzInfo[idx][bEntrx], BizzInfo[idx][bEntry], BizzInfo[idx][bEntrz]+0.5,20.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1);
				}
			}
			else if(BizzInfo[TOTALBIZZ][bType] == 8)
			{
				BizzInfo[idx][bPickup] = CreateDynamicPickup(19132,1, BizzInfo[idx][bEntrx],BizzInfo[idx][bEntry],BizzInfo[idx][bEntrz]);
				BizzInfo[idx][bPickupExit] = CreateDynamicPickup(19132,1,BizzInfo[idx][bExitx], BizzInfo[idx][bExity], BizzInfo[idx][bExitz],BizzInfo[idx][bVirtual]);
				BizzInfo[idx][bMenu] = CreateDynamicSphere(BizzInfo[idx][bMenux],BizzInfo[idx][bMenuy],BizzInfo[idx][bMenuz],1.0,BizzInfo[idx][bVirtual],BizzInfo[idx][bInt]);
				if(BizzInfo[idx][bType] == 8) CreateDynamicPickup(1275,1,BizzInfo[idx][bMenux],BizzInfo[idx][bMenuy],BizzInfo[idx][bMenuz],BizzInfo[idx][bVirtual],BizzInfo[idx][bInt]);
				else CreateDynamicPickup(1274,1,BizzInfo[idx][bMenux],BizzInfo[idx][bMenuy],BizzInfo[idx][bMenuz],BizzInfo[idx][bVirtual],BizzInfo[idx][bInt]);
		   		if(!strcmp(BizzInfo[idx][bOwner],"None",true))
				{
    				format(string, sizeof(string), "{3497FF}Магазин Одежды\n{FFFFFF}Владелец: {FFCC00}государство\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена: {FFCC00}%d {FFFFFF}рублей\n{FFFFFF}Цена за вход: {FFCC00}бесплатный", text,BizzInfo[idx][bPrice]);
					LABELBIZZ[idx] = CreateDynamic3DTextLabel(string,-1,BizzInfo[idx][bEntrx], BizzInfo[idx][bEntry], BizzInfo[idx][bEntrz]+0.5,20.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1);
				}
				else
				{
					format(string, sizeof(string), "{3497FF}Магазин Одежды\n{FFFFFF}Владелец: {0099FF}%s\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена за вход: {FFCC00}%s",BizzInfo[idx][bOwner],text,fee);
					UpdateDynamic3DTextLabelText(LABELBIZZ[idx],-1,string);
				}
			}
			else if(BizzInfo[idx][bType] == 14)
			{
				BizzInfo[idx][bPickup] = CreateDynamicPickup(19132,1, BizzInfo[idx][bEntrx],BizzInfo[idx][bEntry],BizzInfo[idx][bEntrz]);
				BizzInfo[idx][bPickupExit] = CreateDynamicPickup(19132,1,BizzInfo[idx][bExitx], BizzInfo[idx][bExity], BizzInfo[idx][bExitz],BizzInfo[idx][bVirtual]);
				BizzInfo[idx][bMenu] = CreateDynamicSphere(BizzInfo[idx][bMenux],BizzInfo[idx][bMenuy],BizzInfo[idx][bMenuz],1.0,BizzInfo[idx][bVirtual],BizzInfo[idx][bInt]);
				if(BizzInfo[idx][bType] == 8) CreateDynamicPickup(1275,1,BizzInfo[idx][bMenux],BizzInfo[idx][bMenuy],BizzInfo[idx][bMenuz],BizzInfo[idx][bVirtual],BizzInfo[idx][bInt]);
				else CreateDynamicPickup(1274,1,BizzInfo[idx][bMenux],BizzInfo[idx][bMenuy],BizzInfo[idx][bMenuz],BizzInfo[idx][bVirtual],BizzInfo[idx][bInt]);
				if(!strcmp(BizzInfo[idx][bOwner],"None",true))
				{
					format(string, sizeof(string), "{3497FF}Аптека\n{FFFFFF}Владелец: {FFCC00}государство\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена: {FFCC00}%d {FFFFFF}рублей\n{FFFFFF}Цена за вход: {FFCC00}бесплатный", text,BizzInfo[idx][bPrice]);
					LABELBIZZ[idx] = CreateDynamic3DTextLabel(string,-1,BizzInfo[idx][bEntrx], BizzInfo[idx][bEntry], BizzInfo[idx][bEntrz]+0.5,20.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1);
				}
				else
				{
					format(string, sizeof(string), "{3497FF}Аптека\n{FFFFFF}Владелец: {FFCC00}%s\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена за вход: {FFCC00}%s",BizzInfo[idx][bOwner],text,fee);
					LABELBIZZ[idx] = CreateDynamic3DTextLabel(string,-1,BizzInfo[idx][bEntrx], BizzInfo[idx][bEntry], BizzInfo[idx][bEntrz]+0.5,20.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1);
				}
			}
			else if(BizzInfo[idx][bType] == 7)
			{
				if(!strcmp(BizzInfo[idx][bOwner],"None",true))
				{
					format(string, sizeof(string), "{3497FF}СТО\n{FFFFFF}Владелец: {FFCC00}государство\n{FFFFFF}Крышует: {3497FF}%s\n{FFFFFF}Цена: {FFCC00}%d {FFFFFF}руб.", text,BizzInfo[idx][bPrice]);
					LABELBIZZ[idx] = CreateDynamic3DTextLabel(string,-1,BizzInfo[idx][bEntrx], BizzInfo[idx][bEntry], BizzInfo[idx][bEntrz]+1.5,20.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1);
				}
				else
				{
					format(string, sizeof(string), "{3497FF}СТО\n{FFFFFF}Владелец: {FFCC00}%s\n{FFFFFF}Крышует: {3497FF}%s",BizzInfo[idx][bOwner],text);
					LABELBIZZ[idx] = CreateDynamic3DTextLabel(string,-1,BizzInfo[idx][bEntrx], BizzInfo[idx][bEntry], BizzInfo[idx][bEntrz]+1.5,20.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1);
				}
			}
			TOTALBIZZ++;
        }
    }
	printf("[Загружено бизнесов]: <%i>. Потрачено: <%i ms>.", TOTALBIZZ,GetTickCount() - time);
	return 1;
}
//==============================================================================
forward LoadHouse();
public LoadHouse()
{
	new time = GetTickCount(), rows, fields;
    cache_get_data(rows, fields);
	for(new i; i < TOTALHOUSE; i++) strmid(HouseInfo[i][hOwner],"None",0,strlen("None"),MAX_PLAYER_NAME);
	if(rows)
	{
		for(new idx = 1; idx <= rows; idx++)
		{
			HouseInfo[idx][hID] = cache_get_row_int(idx-1, 0, dbHandle); // id
			HouseInfo[idx][hEntrx] = cache_get_row_float(idx-1, 1, dbHandle); // hEntrx
			HouseInfo[idx][hEntry] = cache_get_row_float(idx-1, 2, dbHandle); // hEntry
			HouseInfo[idx][hEntrz] = cache_get_row_float(idx-1, 3, dbHandle); // hEntrz
			HouseInfo[idx][hExitx] = cache_get_row_float(idx-1, 4, dbHandle); // hExitx
			HouseInfo[idx][hExity] = cache_get_row_float(idx-1, 5, dbHandle); // hExity
			HouseInfo[idx][hExitz] = cache_get_row_float(idx-1, 6, dbHandle); // hExitz
			HouseInfo[idx][hCarx] = cache_get_row_float(idx-1, 7, dbHandle); // carx
			HouseInfo[idx][hCary] = cache_get_row_float(idx-1, 8, dbHandle); // cary
			HouseInfo[idx][hCarz] = cache_get_row_float(idx-1, 9, dbHandle); // carz
			HouseInfo[idx][hCarfa] = cache_get_row_float(idx-1, 10, dbHandle); // carfa
			cache_get_row(idx-1, 11, HouseInfo[idx][hOwner], dbHandle, MAX_PLAYER_NAME); // hOwner
			cache_get_row(idx-1, 12, HouseInfo[idx][hDiscript], dbHandle, 16); // hDiscript
			HouseInfo[idx][hPrice] = cache_get_row_int(idx-1, 13, dbHandle); // hPrice
			HouseInfo[idx][hBuyPrice] = cache_get_row_int(idx-1, 14, dbHandle); // buyprice
			HouseInfo[idx][hInt] = cache_get_row_int(idx-1, 15, dbHandle); // hInt
			HouseInfo[idx][hVirtual] = cache_get_row_int(idx-1, 16, dbHandle); // hVirtual
			HouseInfo[idx][hLock] = cache_get_row_int(idx-1, 17, dbHandle); // hLock
			HouseInfo[idx][hOplata] = cache_get_row_int(idx-1, 18, dbHandle); // hOplata
			HouseInfo[idx][hHeal] = cache_get_row_int(idx-1, 19, dbHandle); // hHeal
           	if(!strcmp(HouseInfo[idx][hOwner],"None",true))
			{
				HouseInfo[idx][hMIcon] = CreateDynamicMapIcon(HouseInfo[idx][hEntrx], HouseInfo[idx][hEntry], HouseInfo[idx][hEntrz], 31, 0,-1,-1,-1,150.0);
				HouseInfo[idx][hPickup] = CreateDynamicPickup(1273, 23, HouseInfo[idx][hEntrx], HouseInfo[idx][hEntry], HouseInfo[idx][hEntrz]);
			}
			else
			{
				HouseInfo[idx][hMIcon] = CreateDynamicMapIcon(HouseInfo[idx][hEntrx], HouseInfo[idx][hEntry], HouseInfo[idx][hEntrz], 32, 0,-1,-1,-1,150.0);
				HouseInfo[idx][hPickup] = CreateDynamicPickup(1272, 23, HouseInfo[idx][hEntrx], HouseInfo[idx][hEntry], HouseInfo[idx][hEntrz]);
			}
			TOTALHOUSE++;
		}
	}
	printf("[Загружено домов]: <%i>. Потрачено: <%i ms>.", TOTALHOUSE, GetTickCount() - time);
	for(new idx = 1; idx <= TOTALHOUSE; idx++)
	{
		if(HouseInfo[idx][hOwner] == 0) TotalFreeHouses ++;
	}
	return 1;
}
//==============================================================================
forward LoadMafia();
public LoadMafia()
{
	new time = GetTickCount(), rows, fields;
    cache_get_data(rows, fields);
	if(rows)
	{
	    FracBank[5] = cache_get_row_int(0, 0, dbHandle); // yakuzabank
		FracBank[6] = cache_get_row_int(0, 1, dbHandle); // lcnbank
		FracBank[7] = cache_get_row_int(0, 2, dbHandle); // rmbank
		DrugsBank[TEAM_CSKA] = cache_get_row_int(0, 3, dbHandle); // yakuzadrugs
		DrugsBank[TEAM_SPARTAK] = cache_get_row_int(0, 4, dbHandle); // lcndrugs
		DrugsBank[TEAM_DINAMO] = cache_get_row_int(0, 5, dbHandle); // rmdrugs
		DrugsBank[TEAM_ZENIT] = cache_get_row_int(0, 7, dbHandle); // rmdrugs
	    MafiaPatr[0] = cache_get_row_int(0, 8, dbHandle); // lcnpat
		MafiaPatr[1] = cache_get_row_int(0, 9, dbHandle); // yakpat
		MafiaPatr[2] = cache_get_row_int(0, 10, dbHandle); // rmpat
		MafiaEd[0] = cache_get_row_int(0, 11, dbHandle); // lcned
		MafiaEd[1] = cache_get_row_int(0, 12, dbHandle); // yaked
		MafiaEd[2] = cache_get_row_int(0, 13, dbHandle); // rmed
		b_Sklad{5} = cache_get_row_int(0, 14, dbHandle); // bskl_l
		b_Sklad{6} = cache_get_row_int(0, 15, dbHandle); // bskl_y
		b_Sklad{7} = cache_get_row_int(0, 16, dbHandle); // bskl_r
    }
	printf("[Загружены склады мафий]: Потрачено: <%i ms>.", GetTickCount() - time);
	return 1;
}
//==============================================================================
forward LoadGang();
public LoadGang()
{
	new time = GetTickCount(), rows, fields;
    cache_get_data(rows, fields);
	if(rows)
	{
	    FracBank[0] = cache_get_row_int(0, 0, dbHandle); // grovebank
		FracBank[1] = cache_get_row_int(0, 1, dbHandle); // ballasbank
		FracBank[2] = cache_get_row_int(0, 2, dbHandle); // rifabank
		FracBank[3] = cache_get_row_int(0, 3, dbHandle); // aztecbank
		FracBank[4] = cache_get_row_int(0, 4, dbHandle); // vagosbank
		DrugsBank[TEAM_SPARTAK] = cache_get_row_int(0, 5, dbHandle); // grovedrugs
		DrugsBank[TEAM_SPARTAK] = cache_get_row_int(0, 6, dbHandle); // ballasdrugs
		DrugsBank[TEAM_DINAMO] = cache_get_row_int(0, 7, dbHandle); // rifadrugs
		//DrugsBank[TEAM_OPGTEST2] = cache_get_row_int(0, 8, dbHandle); // aztecdrugs
		//DrugsBank[TEAM_VAGOS] = cache_get_row_int(0, 9, dbHandle); // vagosdrugs
	    GangPatr[0] = cache_get_row_int(0, 10, dbHandle); // grovepat
		GangPatr[1] = cache_get_row_int(0, 11, dbHandle); // ballaspat
		GangPatr[2] = cache_get_row_int(0, 12, dbHandle); // rifapat
		GangPatr[3] = cache_get_row_int(0, 13, dbHandle); // aztecpat
		GangPatr[4] = cache_get_row_int(0, 14, dbHandle); // vagospat
		GangEd[0] = cache_get_row_int(0, 15, dbHandle); // groveed
		GangEd[1] = cache_get_row_int(0, 16, dbHandle); // ballased
		GangEd[2] = cache_get_row_int(0, 17, dbHandle); // rifaed
		GangEd[3] = cache_get_row_int(0, 18, dbHandle); // azteced
		GangEd[4] = cache_get_row_int(0, 19, dbHandle); // vagosed
		b_Capture{0} = cache_get_row_int(0, 20, dbHandle); // bcapt_g
		b_Capture{1} = cache_get_row_int(0, 21, dbHandle); // bcapt_b
		b_Capture{2} = cache_get_row_int(0, 22, dbHandle); // bcapt_r
		b_Capture{3} = cache_get_row_int(0, 23, dbHandle); // bcapt_a
		b_Capture{4} = cache_get_row_int(0, 24, dbHandle); // bcapt_v
		b_Sklad{0} = cache_get_row_int(0, 25, dbHandle); // bskl_g
		b_Sklad{1} = cache_get_row_int(0, 26, dbHandle); // bskl_b
		b_Sklad{2} = cache_get_row_int(0, 27, dbHandle); // bskl_r
		b_Sklad{3} = cache_get_row_int(0, 28, dbHandle); // bskl_a
		b_Sklad{4} = cache_get_row_int(0, 29, dbHandle); // bskl_v
    }
	printf("[Загружены склады банд]: Потрачено: <%i ms>.", GetTickCount() - time);
	return 1;
}
//==============================================================================
forward LoadGZ();
public LoadGZ()
{
	new time = GetTickCount(), rows, fields;
    cache_get_data(rows, fields);
	if(rows)
	{
		for(new idx = 0; idx < rows; idx++)
		{
		    GZInfo[idx][gID] = cache_get_row_int(idx, 0, dbHandle); // id
			GZInfo[idx][gCoords][0] = cache_get_row_float(idx, 1, dbHandle); // ginfo1
            GZInfo[idx][gCoords][1] = cache_get_row_float(idx, 2, dbHandle); // ginfo2
            GZInfo[idx][gCoords][2] = cache_get_row_float(idx, 3, dbHandle); // ginfo3
            GZInfo[idx][gCoords][3] = cache_get_row_float(idx, 4, dbHandle); // ginfo4
            GZInfo[idx][gFrak] = cache_get_row_int(idx, 5, dbHandle); // fraction
        	TOTALGZ++;
	        GangZone[idx] = GangZoneCreate(GZInfo[idx][gCoords][0],GZInfo[idx][gCoords][1],GZInfo[idx][gCoords][2],GZInfo[idx][gCoords][3]);
			ZoneOnBattle[idx] = 0;
			GZSafeTime[idx] = 0;
        }
    }
	printf("[Загружено гангзон]: <%i>. Потрачено: <%i ms>.", TOTALGZ, GetTickCount() - time);
	return 1;
}
//==============================================================================
forward LoadOther();
public LoadOther()
{
	new time = GetTickCount(), rows, fields;
    cache_get_data(rows, fields);
	if(rows)
	{
		FracBank[8] = cache_get_row_int(0, 0, dbHandle); // lsnbank
		FracBank[9] = cache_get_row_int(0, 1, dbHandle); // sfnbank
		FracBank[10] = cache_get_row_int(0, 2, dbHandle); // lvnbank
		cache_get_row(0, 3, NewsPrice, dbHandle, 40); // newsprice
		sscanf(NewsPrice, "p<,>iiiiii", SmsPrice[0], SmsPrice[1], CallPrice[0], CallPrice[1], AdvertPrice[0], AdvertPrice[1]);
		Mineral = cache_get_row_int(0, 4, dbHandle); // mineral
		gGunWorkWH[0] = cache_get_row_int(0, 5, dbHandle); // guncoal
		gGunWorkWH[1] = cache_get_row_int(0, 6, dbHandle); // gunwood
		gGunWorkWH[2] = cache_get_row_int(0, 7, dbHandle); // gun
		Lessdrov = cache_get_row_int(0, 8, dbHandle); // drova
		gArmyWarehouse[0] = cache_get_row_int(0, 9, dbHandle); // armygun
		gArmyWarehouse[1] = cache_get_row_int(0, 10, dbHandle); // armyammo
		doubling_exp = cache_get_row_int(0, 11, dbHandle); // d_exp
		doubling_donate = cache_get_row_int(0, 12, dbHandle); // d_donate
    }
	printf("[Загружено остальное]: Потрачено: <%i ms>.",GetTickCount() - time);
	return 1;
}
//==============================================================================
stock SaveWarehouse()
{
    new Query[150];
	format(Query, sizeof(Query), "UPDATE `other` SET armygun=%d,armyammo=%d,mineral=%d,guncoal=%d,gunwood=%d,gun=%d,drova=%d", gArmyWarehouse[0], gArmyWarehouse[1], Mineral, gGunWorkWH[0], gGunWorkWH[1], gGunWorkWH[2], Lessdrov);
	mysql_tquery(dbHandle, Query, "", "");
	return 1;
}
