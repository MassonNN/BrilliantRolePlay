// система каршеринга


#define MAX_CARSHARING	56


new const Float:carsharingCoords[MAX_CARSHARING][4] = {
	{2772.8926,-2489.1787,21.6145,0.9628},
	{2769.2517,-2489.1194,21.5674,359.1768},
	{2570.0273,-2173.4773,21.8364,179.0573},
	{2551.9016,-2173.7322,21.8374,179.9833},
	{2529.8831,-2173.2493,21.8401,178.9718},
	{2245.8848,-1939.2888,18.5230,89.6874},
	{2245.7759,-1934.4556,18.5254,91.5690},
	{2228.1846,-1681.6764,21.4081,269.2088},
	{2303.6438,-1802.2639,22.4438,269.6266},
	{2303.2402,-1831.2872,22.4425,270.6335},
	{2303.2766,-1814.5203,22.4434,272.1964},
	{2519.9900,-709.4296,12.0117,90.0271},
	{2527.4302,-697.6531,12.0043,89.8938},
	{2527.2947,-682.2180,12.0118,89.9545},
	{2520.4248,-666.5202,12.0128,89.6154},
	{2325.9492,-270.2679,1.3030,270.7396},
	{1729.9032,1334.4204,12.2088,90.3976},
	{2138.8245,1817.3492,11.7550,90.1485},
	{2138.8779,1820.1802,11.7550,91.6926},
	{2216.9167,1662.7512,11.9913,228.2961},
	{2218.8931,1662.6405,11.7791,173.3538},
	{1836.3875,2039.6154,15.4622,359.4529},
	{1713.3060,2468.6538,15.1812,212.0745},
	{1716.1985,2470.4839,15.1805,211.2154},
	{-2498.1343,2858.1167,37.2124,178.6636},
	{-2495.1060,2858.0171,37.2117,177.6381},
	{-2458.0771,2791.1963,37.1970,267.7509},
	{-2391.8655,1617.9097,52.9427,107.5659},
	{-2554.4050,1709.6304,52.9423,250.2509},
	{-2553.0164,1712.5560,52.9423,252.5567},
	{-2348.7048,257.7598,23.4393,167.4556},
	{-2250.1118,297.6448,24.3232,349.5201},
	{-2253.2156,298.3192,24.3079,346.5878},
	{-2243.1687,-167.3489,24.2612,169.3394},
	{-506.0312,-1626.0348,40.6550,237.6172},
	{-505.7034,-1624.4171,40.8533,239.3363},
	{-166.6664,-1061.7101,41.0128,211.8664},
	{-169.0004,-1063.2637,41.0145,212.8236},
	{-352.9635,542.6313,12.2710,83.7877},
	{-371.9643,515.9272,12.2620,82.4358},
	{-375.0414,487.5662,12.2620,83.9583},
	{-213.1756,-147.6619,11.5162,173.0485},
	{-215.8007,-147.4051,11.5129,171.2321},
	{-283.3495,137.9865,10.7587,295.2552},
	{-40.2843,538.1546,11.7584,256.8611},
	{-40.7764,535.3333,11.7584,260.5514},
	{802.8746,806.4058,11.9606,246.7857},
	{-477.7249,908.0112,11.5303,271.6378},
	{-477.8856,921.2452,11.5308,270.4127},
	{302.3677,1634.4301,11.5787,354.5378},
	{301.7729,1628.4681,11.5770,355.6412},
	{411.9145,1617.3191,11.5818,359.1309},
	{409.5309,1617.1996,11.5814,0.5841},
	{406.9338,1617.0914,11.5806,1.1328},
	{553.0500,1557.6624,11.7476,54.9530},
	{403.2282,1963.8649,7.8513,263.6827}
};

// статус
#define CI_STATUS_WORK		1
#define CI_STATUS_ARENDED	2
#define CI_STATUS_ERROR		3


enum carsharingInfo {
	carShareID, // системный id
	Float:carShareX, // координата X
	Float:carShareY, // координата Y
	Float:carShareZ, // координата Z
	Float:carShareAngle,
	Text3D:carsharingText,
	carShareClass, // класс
	carShareFuel, // топливо
	carShareStatus, // статус
	bool:carShareUse
};

#define CI_CLASS_ECONOM		1
#define CI_CLASS_MIDDLE		2
#define CI_CLASS_BUSINESS	3

enum businessCarshare {
	costEconom = 100,
	costMiddle = 200,
	costBusiness = 300
};

new costCarshare[businessCarshare];

enum playerCarshare {
	arendCarID, // системный id
	arendTime
};

new playerArend[MAX_PLAYERS][playerCarshare];

new carsharingINFO[MAX_CARSHARING][carsharingInfo];
#define cI carsharingINFO

publics carsharing_OnGameModeInit() {
	for(new i; i < MAX_CARSHARING; i++) {
		cI[i][carShareID] = CreateVehicle(504, carsharingCoords[i][0], carsharingCoords[i][1], carsharingCoords[i][2], carsharingCoords[i][3], 6, 1, 1000);
		cI[i][carsharingText] = Create3DTextLabel("{FFCC00}Каршеринг\n\n{ADFF2F}Готово к аренде", -1, 0.0, 0.0, 0.0, 20.0, -1);
		cI[i][carShareStatus] = CI_STATUS_WORK;
		Attach3DTextLabelToVehicle(cI[i][carsharingText], cI[i][carShareID], 0.0, 0.0, 1.5);
	}
	SetTimer("CarsharingUpdate", 1000*60, true);
	return 1;
}

getCostCarShare(carID) {
	switch(cI[carID][carShareClass]) {
		case CI_CLASS_ECONOM: return costCarshare[costEconom];
		case CI_CLASS_MIDDLE: return costCarshare[costMiddle];
		case CI_CLASS_BUSINESS: return costCarshare[costBusiness];
		default: return 100;
	}
	return 0;
}

hook OnPlayerExitVehicle(playerid, vehicleid) {
	for(new i; i < MAX_CARSHARING; i++) {
		if(vehicleid == cI[i][carShareID] && playerArend[playerid][arendCarID]) {
			SendPond(playerid, "Чтобы отказаться от аренды, введите: /stopcarshare");
		}
	}
}

publics CarsharingUpdate() {
	new tmp[128];
	foreach(new i : Player) {
		if(playerArend[i][arendCarID] > 0) {
			new cost = getCostCarShare(FindCarshareIdById(playerArend[i][arendCarID]));
			if (PI[i][pCash] < cost) {
				RemovePlayerFromVehicle(i);
				SendInfo(i, "У Вас недостаточно средств для дальнейшей аренды");
				StopCarshareArend(i);
			}
			playerArend[i][arendTime]++;
			GiveMoney(i, -cost);
			format(tmp, sizeof tmp, "%d minutes ~n~%d rubles to order", playerArend[i][arendTime], playerArend[i][arendTime]*cost);
			GameTextForPlayer(i, tmp, 1000*30, 1);
		}
	}
	for(new i; i < MAX_CARSHARING; i++) {

		if(!IsValidVehicle(cI[i][carShareID])) SetVehicleToRespawn(cI[i][carShareID]);
		if(GetVehicleHealthR(cI[i][carShareID]) < 400.0) cI[i][carShareStatus] = CI_STATUS_ERROR;
		else if(cI[i][carShareUse] == false) cI[i][carShareStatus] = CI_STATUS_WORK;
		// switch(cI[i][carShareStatus]) {
		// 	case CI_STATUS_WORK: format(tmp, 128, "{FFCC00}Каршеринг\n\n{ADFF2F}Готово к аренде");
		// 	case CI_STATUS_ARENDED: format(tmp, 128, "{FFCC00}Каршеринг\n\n{FFCC00}Арендовано");
		// 	case CI_STATUS_ERROR: format(tmp, 128, "{FFCC00}Каршеринг\n\n{FF0000}Поломано");
		// }
		switch(cI[i][carShareStatus]) {
			case CI_STATUS_WORK: Update3DTextLabelText(cI[i][carsharingText], -1, "{FFCC00}Каршеринг\n\n{ADFF2F}Готово к аренде");
			case CI_STATUS_ARENDED: Update3DTextLabelText(cI[i][carsharingText], -1, "{FFCC00}Каршеринг\n\n{FFCC00}Арендовано");
			case CI_STATUS_ERROR: Update3DTextLabelText(cI[i][carsharingText], -1, "{FFCC00}Каршеринг\n\n{FF0000}Поломано");
		}

		GetVehiclePos(cI[i][carShareID], cI[i][carShareX], cI[i][carShareY], cI[i][carShareZ]);

		if(cI[i][carShareStatus] == CI_STATUS_ERROR) {
			foreach(new d : Player) {
				if(playerArend[d][arendCarID] != i) continue;
				else {
					SendErr(d, "Аренда закончилась из-за поломки автомобиля.");
					SendErr(d, "Следующий раз с Вас будет взят штраф за поломку!");
					StopCarshareArend(d);
				}
			}
			// добавление машины в список необходимых к ремонту
		}


	}
	return 1;
}

cmd:stopcarshare(playerid) {
	if(playerArend[playerid][arendCarID]) {
		StopCarshareArend(playerid);
		SendSucces(playerid, "Спасибо за пользование нашими услугами!");
	} else return SendErr(playerid, "В данный момент Вы не арендуете машину");
	return 1;
}

StopCarshareArend(playerid) {
	new cost = getCostCarShare(playerArend[playerid][arendCarID]);
	RemovePlayerFromVehicle(playerid);
	TogglePlayerControllable(playerid, 1);

	if(GetVehicleHealthR(cI[playerArend[playerid][arendCarID]][carShareID]) < 400.0)  cI[playerArend[playerid][arendCarID]][carShareStatus] = CI_STATUS_ERROR;
	else cI[playerArend[playerid][arendCarID]][carShareStatus] = CI_STATUS_WORK;
	cI[playerArend[playerid][arendCarID]][carShareUse] = false;

	new tmp[128];
	format(tmp, 128, "Аренда завершена, время аренды %d минут(ы/а) и %d рублей к оплате", playerArend[playerid][arendTime], playerArend[playerid][arendTime]*cost);
	SendInfo(playerid, tmp);
	
	playerArend[playerid][arendCarID] = 0;
	playerArend[playerid][arendTime] = 0;

	CarsharingUpdate();
	return 1;
}

carsharing_OnPlayerStateChange(playerid, newstate, oldstate) {
	if(newstate == PLAYER_STATE_DRIVER) {
		new vehicleid = GetPlayerVehicleID(playerid);
		for(new i; i < MAX_CARSHARING; i++)
		{
			if(vehicleid == cI[i][carShareID]) {
				if(playerArend[i][arendCarID] == cI[i][carShareID]) return 1;
				if(cI[i][carShareStatus] == CI_STATUS_ERROR) {
					SendErr(playerid, "Эта машина каршеринга поломана и не готова к аренде");
					RemovePlayerFromVehicle(playerid);
					return 1;
				}
				if(cI[i][carShareStatus] != CI_STATUS_WORK && playerArend[playerid][arendCarID] != i) {
					RemovePlayerFromVehicle(playerid);
					SendErr(playerid, "Эта машина каршеринга уже арендуется другим игроком");
					return 1;
				}

				TogglePlayerControllable(playerid, 0);
				new tmp[128];
				format(tmp, 128, "\\c{FFFFFF}Каршеринг\n\n\n\
				{FFCC00}Стоимость аренды машины каршеринга: {FFCC00}{FFFFFF}%d рублей / минута", getCostCarShare(i));
				Dialog_Open(playerid, "carsharingDialog", DIALOG_STYLE_MSGBOX, "{FFCC00}Каршеринг", tmp, "Арендовать", "Отказаться");
				
			} 
		}
	}
	return 1;
}
DialogResponse:carsharingDialog(playerid, response, listitem) {
	if(!response) {
		TogglePlayerControllable(playerid, 1);
		RemovePlayerFromVehicle(playerid);
		return 1;
	}
	else {
		if(PI[playerid][pCash] < 100) {
			SendErr(playerid, "Недостаточно средств и для одной минуты аренды");
			RemovePlayerFromVehicle(playerid);
			TogglePlayerControllable(playerid, 1);
			return 1;
		} else if(!PI[playerid][pAutoLic]) {
			SendErr(playerid, "У Вас нет водительских прав");
			RemovePlayerFromVehicle(playerid);
			TogglePlayerControllable(playerid, 1);
			return 1;
		} else {
			new vehid = FindCarshareIdById(GetPlayerVehicleID(playerid));
			playerArend[playerid][arendCarID] = vehid;
			cI[vehid][carShareUse] = true;
			cI[vehid][carShareStatus] = CI_STATUS_ARENDED;
			CarsharingUpdate();
			SendSucces(playerid, "Вы арендовали каршеринг. Чтобы закончить аренду, пропишите команду /stopcarshare.");
			TogglePlayerControllable(playerid, 1);
		}
	}
	return 1;
}

FindCarshareIdById(vehid) {
	for(new i; i < MAX_CARSHARING; i++) {
		if(vehid != cI[i][carShareID]) continue;
		else return i;
	}
	return 0;
}

