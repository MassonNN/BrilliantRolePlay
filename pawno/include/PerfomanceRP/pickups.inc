// Pickups and Auto Perfomance Role Play

stock LoadPickups()
{  
	// Арзамас спавн
    AreaInfo[arServerHelp] = CreateDynamicSphere(412.57, 1559.40, 12.03,1.0);
    CreateDynamicPickup(1239,1,412.57, 1559.40, 12.03);
    CreateDynamic3DTextLabel("Помощь новичкам",0xFFCC00FF, 412.57, 1559.40, 12.03+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	// Батырево спавн
	AreaInfo[arServerHelpBat] = CreateDynamicSphere(1928.35, 2086.62, 16.45,1.0);
    CreateDynamicPickup(1239,1,1928.35, 2086.62, 16.45);
    CreateDynamic3DTextLabel("Помощь новичкам",0xFFCC00FF, 1928.35, 2086.62, 16.45+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
    // Южный спавн
    AreaInfo[arServerHelpYg] = CreateDynamicSphere(2510.78, -2131.35, 23.46,1.0);
    CreateDynamicPickup(1239,1,2510.78, -2131.35, 23.46);
    CreateDynamic3DTextLabel("Помощь новичкам",0xFFCC00FF, 2510.78, -2131.35, 23.46+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	//
    CreateDynamicPickup(1239,1,1005.3982,2814.5190,1279.5000); // пикап для дома класса "особняк", р-н элитный, особняк
    //=========================
    CreateDynamicPickup(1239,1,-1426.1396,-1125.5704,1521.9399); // пикап для устройства на работу
    CreateDynamicPickup(1239,1,-1419.7555,-1126.8522,1521.9399); // пикап для создания семьи
    
	//==========================================================================
	AreaInfo[arBankMenu] = CreateDynamicSphere(502.20, 707.67, 2713.18,1.0);
	CreateDynamicPickup(1274,1,502.20, 707.67, 2713.18,55);
	CreateDynamic3DTextLabel("Нажмите {FFCC00}л. ALT",0xFFFFFFFF, 502.20, 707.67, 2713.18,5.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Нажмите {FFCC00}л. ALT",0xFFFFFFFF, 833.1951,239.9840,1014.2498,5.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	///
	AreaInfo[arBankMenuArz] = CreateDynamicSphere(497.92, 707.67, 2713.18,1.0);
	CreateDynamicPickup(1274,1,497.92, 707.67, 2713.18,55);
	//
	CreateDynamic3DTextLabel("Нажмите {FFCC00}л. ALT",0xFFFFFFFF, 497.92, 707.67, 2713.18,5.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamicPickup(1239,1,502.20, 707.67, 2713.18); // пикап для arBankMenu
	CreateDynamicPickup(1239,1,497.92, 707.67, 2713.18); // пикап для arBankMenuArz
	//==========================================================================
	
	AreaInfo[arHotdogHP] = CreateDynamicSphere(438.5016,1537.0320,12.0150,1.0);
	CreateDynamicPickup(1582,1,438.5016,1537.0320,12.0150);
	
	CreateDynamicPickup(1239,1,438.6825,1538.8860,12.0150);
	//CreateDynamicPickup(2044,-1,833.1951,239.9840,1014.2498,177); // боекомплект военной части (ВДВ, в г. Батырево)
	
	CreateDynamicPickup(1239,1,-924.7971,879.5367,2512.9500,0);
	CreateDynamicPickup(1239,1,359.1528,184.3584,1008.3828,2);
	CreateDynamicPickup(1239,1,359.1528,184.3584,1008.3828,3);
	CreateDynamicPickup(19131,1,1268.9554,762.7606,1002.5400,3);
	CreateDynamic3DTextLabel("{ffffff}Нажмите {FFCC00}\"L.ALT\"{ffffff} для сдачи на права",-1,131.3677,1368.7531,1002.9600,5.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,-1,-1);
	CreateDynamic3DTextLabel("{FFFFFF}Выдача номеров (для сотрудников ДПС)\n{FFFFFF}Введите команду {FFCC00}/givenumber",-1,-98.9492,737.3321,1620.9200,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,-1,-1);
	CreateDynamic3DTextLabel("{ffffff}Нажмите {FFCC00}\"L.ALT\"{ffffff}для устройства на работу.",-1,-926.1721,857.7138,2512.9500,5.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,-1,-1);
	Mafia3d[2] = CreateDynamic3DTextLabel("_",0xFFFFFFFF,1386.6923,1705.2456,3.5854+1,10.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0); //Склад Армии

	AreaInfo[arGreenZone][0] = CreateDynamicSphere(458.3384, 1559.7034, 12.0150, 200.0, -1, -1); // Спавн арзамас
	AreaInfo[arGreenZone][1] = CreateDynamicSphere(1064.9117, 95.1939, 1049.7869, 60.0, -1, -1); 	// - Автошкола (Интерьер)
	AreaInfo[arGreenZone][2] = CreateDynamicSphere(2324.9849,1759.6368,1.0326,50.0,-1,-1); // Казино ул
	AreaInfo[arGreenZone][3] = CreateDynamicSphere(1904.9236,2227.4309,15.7172,40.0,-1,-1); // Автошкола (улица)
	AreaInfo[arGreenZone][4] = CreateDynamicSphere(2524.2122,-2133.0950,21.9800,60.0,-1,-1); // Спавн южный
	AreaInfo[arGreenZone][5] = CreateDynamicSphere(-932.7878,860.4482,2512.9500,30.0,1,-1); // Мэрия бт (интерьер)
	AreaInfo[arGreenZone][6] = CreateDynamicSphere(2112.7495,-2387.3110,21.9430,100.0,-1,-1); // Центральная Больница (улица)
	AreaInfo[arGreenZone][7] = CreateDynamicSphere(1829.0959,2095.6973,16.1003,60.0,-1,-1); // Площадь мэрии бт
	AreaInfo[arGreenZone][8] = CreateDynamicSphere(1908.8931,2183.4102,15.7060,100.0,-1,-1); // дпс
	AreaInfo[arGreenZone][9] = CreateDynamicSphere(1363.1006,-1279.8647,13.5469,30.0,-1,-1); // Аммо ЛС (улица)
	AreaInfo[arGreenZone][10] = CreateDynamicSphere(312.4500,-137.7774,999.6016,30.0,-1,-1); // Аммо ЛС (интерьер)
	AreaInfo[arGreenZone][11] = CreateDynamicSphere(2008.9309,1897.0229,15.5582,60.0,-1,-1); // Автосолон
	AreaInfo[arGreenZone][13] = CreateDynamicSphere(2346.3521,2006.0250,15.9900,80.0,-1,-1); // Шахта (улица)
	AreaInfo[arGreenZone][14] = CreateDynamicSphere(-246.5507,1053.8990,-84.1475,350.0,-1,-1); // Шахта (интерьер)
	AreaInfo[arGreenZone][17] = CreateDynamicSphere(-1518.4171,1342.6370,1523.7000,100.0,-1,-1); // Центральная Больница (интерьер)
	AreaInfo[arGreenZone][18] = CreateDynamicSphere(1860.2601,2266.2112,15.2729,30.0,-1,-1); // Аммо ЛВ (улица)****************
	AreaInfo[arGreenZone][19] = CreateDynamicSphere(-1494.1315,-297.2617,1762.7900,30.0,-1,-1); // Аммо СФ (улица)
	AreaInfo[arGreenZone][20] = CreateDynamicSphere(1784.6024,2029.1846,-2.3341,20.0,-1,-1); // Гонки: Пустыня LV
	AreaInfo[arGreenZone][21] = CreateDynamicSphere(-1376.6124,1076.3242,2585.4460,20.0,-1,-1); // Церковь
	AreaInfo[arGreenZone][22] = CreateDynamicSphere(-2662.0498,630.9210,14.4531,35.0,-1,-1); // Больница СФ (улица)
	AreaInfo[arGreenZone][23] = CreateDynamicSphere(1607.5980,1835.7625,10.9375,30.0,-1,-1); // Больница ЛВ (улица)
	AreaInfo[arGreenZone][24] = CreateDynamicSphere(-2756.6982,375.8630,4.3340,25.0,-1,-1); // Мэрия СФ (улица)
	AreaInfo[arGreenZone][25] = CreateDynamicSphere(2384.5845,2465.9084,10.8203,25.0,-1,-1); // Мэрия ЛВ (улица)
	AreaInfo[arGreenZone][26] = CreateDynamicSphere(1933.9478,2086.0088,16.4534,70.0,-1,-1); // спавн батырево

    AreaInfo[arArmyAmmo] = CreateDynamicSphere(-70.9644,1137.3872,2340.5300,2,0);//Загрузка
	AreaInfo[arLoadAmmo] = CreateDynamicSphere(1452.8972,1761.7125,-7.4797,2.0);

	AreaInfo[arBuyFishki] = CreateDynamicSphere(-928.7511,858.8748,2518.3899,1.0);
	CreateDynamicPickup(1239,1,-928.7511,858.8748,2518.3899);

	AreaInfo[arBuyNarko][0] = CreateDynamicSphere(2919.2363,989.6827,3.8847,1.0);
	AreaInfo[arBuyNarko][1] = CreateDynamicSphere(2919.2363,989.6827,3.8847,1.0);
	
	AreaInfo[recipe_weapon]  =  CreateDynamicSphere(2003.3171,1339.8420,26.1513, 0.5); // Покупка рецептов
	
	CreateDynamicPickup(1277,1,2003.3171,1339.8420,26.1513);
	
	CreateDynamicPickup(1578,1,2919.2363,989.6827,3.8847);
	CreateDynamicPickup(1578,1,1981.2021,1893.3627,15.5280);

	//AreaInfo[arLoadPatr] = CreateDynamicSphere(-1299.9468,450.0263,7.1875,2.0);
	//AreaInfo[arLoadGun] = CreateDynamicSphere(-1284.9690,449.3527,7.1875,2.0);
	CreateDynamicPickup(2358,1,-1299.9468,450.0263,7.1875);
	CreateDynamicPickup(2358,1,-1284.9690,449.3527,7.1875);

	//AreaInfo[arArmyAmmo] = CreateDynamicSphere(290.2321,-109.3437,1001.5156,1.0,1,6);

	//CreateDynamic3DTextLabel("Боекомплект ВЧ\nНажмите {FFCC00}л. ALT",COLOR_WHITE,1616.9537,1980.6918,1281.8175,15.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,3);

	gGunWorkWHText[0] = CreateDynamic3DTextLabel("_",0xFFCC00FF,132.3752,1857.3159,-18.3955,25);
	gGunWorkWHText[1] = CreateDynamic3DTextLabel("_",0xFFCC00FF,-1050.5100, 2208.5642, 38.4603,25);
	tPickup[4] = CreateDynamic3DTextLabel("_",0xFFFFFFFF,2637.5366,-1414.3035,27.7800,50.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,1,1);
	tPickup[6] = CreateDynamic3DTextLabel("_",0xFFFFFFFF,-940.6257,1221.7030,10.8205,50.0);
	
    sklad = CreateDynamicPickup(3014,23,-70.9644,1137.3872,2340.5300,0);//Склад Армии
	CreateDynamic3DTextLabel("{FFCC00}Склад\n{FFFFFF}Оружия: {0099FF}30064 ед.", 0xFFCC00FF, 457.4512,1311.9478,1723.5336,5.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,-1,-1); // ппс
	CreateDynamic3DTextLabel("{FFCC00}Склад\n{FFFFFF}Оружия: {0099FF}30064 ед.", 0xFFCC00FF, -107.2018,752.5746,1620.9399,5.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,-1,-1); // дпс
	CreateDynamic3DTextLabel("{FFCC00}Склад\n{FFFFFF}Оружия: {0099FF}30064 ед.", 0xFFCC00FF, 180.4792,461.7243,1583.6801,5.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,-1,-1); // фсб
	CreateDynamic3DTextLabel("Нажмите {FFCC00}\"L.ALT/", 0xFFFFFFFF, 1139.6180,1556.2518,1002.5400,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1);
	CreateDynamic3DTextLabel("Нажмите {FFCC00}\"L.ALT/", 0xFFFFFFFF, 875.6308,2095.4758,2721.8101,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1);
	CreateDynamic3DTextLabel("Нажмите {FFCC00}\"L.ALT/", 0xFFFFFFFF, 1697.8187,1321.6997,19.7922,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1);
    CreateDynamic3DTextLabel("Нажмите {FFCC00}\"L.ALT\", {ffffff}для того, чтобы подняться по лестнице.", 0xFFFFFFFF, 1400.6551,1758.0157,-5.7434,5.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1);
    CreateDynamic3DTextLabel("Нажмите {FFCC00}\"L.ALT\", {ffffff}для того, чтобы спуститься по лестнице.", 0xFFFFFFFF, 1400.6990,1757.2811,3.6469,5.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1);

	Pickup[2] = CreateDynamicPickup(353, 23, 457.4017,1313.5282,1723.5200, 0);
	Pickup[3] = CreateDynamicPickup(353, 23, -105.8641,752.5945,1620.9200, 0);
	Pickup[5] = CreateDynamicPickup(1239, 23, 781.0366,751.7977,12.9307,0); //пикап для дальнобойщиков
	Pickup[11] = CreateDynamicPickup(1239, 23, 2142.9124,-2206.4788,23.1784,0); //пикап для машинок мелких, которые мусор убирают
	Pickup[10] = CreateDynamicPickup(1239, 23, 1431.9617,1808.1072,2233.6499, -1);
	Pickup[12] = CreateDynamicPickup(1239, 23, 2189.9546,-343.9691,2332.1599, -1);
	Pickup[1] = CreateDynamicPickup(19134, 23, 1139.6180,1556.2518,1002.5400, 0);
	Pickup[19] = CreateDynamicPickup(19134, 23, 2051.3486,1903.4749,-77.2241, -1);
	//Pickup[20] = CreateDynamicPickup(19134, 23, 1697.8187,1321.6997,19.7922, -1); // висит над входом в шахту
	Pickup[6] = CreateDynamicPickup(2894, 23, 1062.5918, 112.9620, 1049.7478, 0); // ПДД
	Pickup[21] = CreateDynamicPickup(19134, 23, 2326.9878,405.3324,2824.9500, 0);
	gunsklad[1] = CreateDynamicCP(2102.6133,-1614.1257,2056.6399,1.0,1,1); // MERIA GUN
	gunsklad[2] = CreateDynamicCP(2102.6133,-1614.1257,2056.6399,1.0,2,2); // Rifa ган
	gunsklad[3] = CreateDynamicCP(2102.6133,-1614.1257,2056.6399,1.0,3,3); // Aztecas ган
	gunsklad[4] = CreateDynamicCP(2102.6133,-1614.1257,2056.6399,1.0,4,4); // Vagos ган
	gunsklad[6] = CreateDynamicCP(2102.6133,-1614.1257,2056.6399,1.0,5,0); // Yakuza ган
	gunsklad[7] = CreateDynamicCP(2102.6133,-1614.1257,2056.6399,1.0,6,5); // RM ган
	AO_PICK[0] = CreateDynamicPickup(1318,23,1818.2972,2095.7300,16.1631,0);// на улице
	AO_PICK[1] = CreateDynamicPickup(1318,23,-1432.77, -1126.02, 1521.94,-1);// внутри
	Pickup[20] = CreateDynamicPickup(1238, 23, 1646.49, 1409.40, 12.00, -1);
	skladvdv[0] = CreateDynamicPickup(1243, 23, 833.1951,239.9840,1014.2498,177, -1);
	// шахта и тексты
	shahtapick[0] = CreateDynamicPickup(1318,23,1701.37, 1283.27, 12.21,-1);//вход в шахту
	shahtapick[1] = CreateDynamicPickup(1318,23,-258.23, 1052.75, -84.15,-1);//выход с шахты
	CreateDynamic3DTextLabel("Шахта",0xFFFFFFFF,1701.37, 1283.27, 12.21+5,5.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	vodolazmeshok[0] = CreateDynamicPickup(1279,23,2936.9954,-1390.9380,-25.5680,-1);
	vodolazmeshok[1] = CreateDynamicPickup(1279,23,2879.3025,-1310.3881,-15.5581,-1);
	CreateDynamicPickup(1275,23,-246.62, 1051.08, -84.15,-1);
 	CreateDynamicPickup(1275,23,1692.3312,1399.5203,12.0001,-1);
	
	bilet[0] = CreateDynamicPickup(19131, 23, 661.4047,2323.4417,1504.3500,0);
	//Водолазы
	CreateDynamicPickup(1275,23,2816.5166,-1412.9590,4.2203,0);
	CreateDynamic3DTextLabel("Работа водолаза",0xFFFFFFFF,2816.5166,-1412.9590,4.2203+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	//Магазин
	//magaz[0] = CreateDynamicPickup(1318, 23, 2067.1851,1884.0758,15.9428,0);
	//magaz[1] = CreateDynamicPickup(1318, 23, 576.9781,2121.6814,1551.4600,0);
	//Грузчики
	CreateDynamicPickup(1275,23,2355.0908,-261.2916,2.7890,0);
	CreateDynamic3DTextLabel("Работа грузчика",0xFFFFFFFF,2355.0908,-261.2916,2.7890+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamicPickup(2969,23,2341.0645,1391.8145,12.6226,0);//Склад ОПГ"Ореховское"
	CreateDynamicPickup(2969,23,2402.9424,-1711.9265,29.6341,0);//Склад ОПГ"Южное"
	
	Mafia3d[0] = CreateDynamic3DTextLabel("_",0xFFFFFFFF,2610.9749,1767.7500,10.2175,10.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,5,-1);
	Mafia3d[1] = CreateDynamic3DTextLabel("_",0xFFFFFFFF,1705.8579,1337.9902,26.0344,10.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,5,-1);
	Mafia3d[2] = CreateDynamic3DTextLabel("_",0xFFFFFFFF,2402.8911,-1711.8951,29.6341,10.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,5,-1);
	
	armyammo = CreateDynamicCP(-70.9644,1137.3872,2340.5300,1,6); // ammo
	
	gArmyWarehouseText = CreateDynamic3DTextLabel("_",0xFFFFFFFF,-70.9644,1137.3872,2340.5300,10.5,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	
	lvpdpick[2] = CreateDynamicPickup(1318,23,2337.1335,2459.3105,14.9742);//Центральный вход
	lvpdpick[3] = CreateDynamicPickup(1318,23,288.8456,166.9235,1007.1719,122);//Центральный выход
	sfpdpick[0] = CreateDynamicPickup(1318,23,-1605.544799,710.272033,13.867186);//
	sfpdpick[1] = CreateDynamicPickup(1318,23,246.409820,107.299217,1003.218750);//
	sfpdpick[2] = CreateDynamicPickup(1318,23,-1594.212158,716.225036,-4.906250);//
	sfpdpick[3] = CreateDynamicPickup(1318,23,215.550186,126.734489,1003.218750);//
	sfpdpick[4] = CreateDynamicPickup(1318,23,1524.484619,-1677.879516,6.218750);//
	sfpdpick[5] = CreateDynamicPickup(1318,23,296.821960,-112.070549,1001.515625,5);//
	armypick[0] = CreateDynamicPickup(1318, 23, 177.0429,1843.9115,17.6406, -1); // вход в казарму
	armypick[1] = CreateDynamicPickup(1318, 23, 1071.1465,-346.2553,2127.4299, 1); // выход из казармы
	armypick[2] = CreateDynamicPickup(1318, 23, 340.5745,1949.1871,22.0172, -1); // оружейка вход
	armypick[3] = CreateDynamicPickup(1318, 23, 296.8533,-112.0710,1001.5156, 1); // оружейка выход
	armshield = CreateDynamicPickup(1242, 23, 837.6909,239.9840,1014.2498, -1); // щит
	//armgun = CreateDynamicPickup(2044, 23, 1616.8907,1981.2440,1281.8175, -1); // оружие в военной части (ВДВ, г. Батырево)
	armystol = CreateDynamicPickup(1582, 23, 836.6945,250.6147,1014.2498, 0); // Еда
	
	//=============================  Спортзалы  ================================
	sportpickup = CreateDynamicPickup(1275,23,-339.6125,445.4721,2513.6201);
	//===============================  Пикапы  =================================
	paintjob[0] = CreateDynamicPickup(353, 23, 2436.5645,-1904.2631,22.0043, 0);
	CreateDynamicPickup(1239,23,-1157.4618,351.0251,1767.3571);
	// АШ
	ashpick[0] = CreateDynamicPickup(1318, 23, 2172.1340, -2197.8716, 23.1784, 0); // +
	ashpick[1] = CreateDynamicPickup(1318, 23, 1060.3450, 93.5735, 1049.7830, 0);
	//Полиция
	PPS_PICK[0] = CreateDynamicPickup(1318, 23, 405.6946,759.5942,12.6125,0); //+
	PPS_PICK[1] = CreateDynamicPickup(1318, 23, 472.7328,1334.1376,1723.5200,0);
	CreateDynamic3DTextLabel("ППС г. Арзамас",0xFFFFFFFF,405.6946,759.5942,12.6125+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,1915.8481,2184.8945,2.4664+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	DPS_PICK[0] = CreateDynamicPickup(1318, 23, -360.2326, 1025.4321, 13.2432,0);
	DPS_PICK[1] = CreateDynamicPickup(1318, 23, -103.2590,735.9590,1620.9200,0);
	CreateDynamic3DTextLabel("ДПС г. Южный",0xFFFFFFFF,2576.07, -2416.09, 22.50+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,-102.6062, 736.1812, 1622.4000+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
//===========================[ ФСИН ]===========================================
	FSIN_PICK[0] = CreateDynamicPickup(1318, 23, 814.10, 2432.35, 12.21,0);
	FSIN_PICK[1] = CreateDynamicPickup(1318, 23, 166.26, 443.15, 1583.68,0);
	FSIN_PICK[2] = CreateDynamicPickup(1275, 23, 178.90, 455.93, 1583.68,0);
	FSIN_PICK[3] = CreateDynamicPickup(353, 23, 180.4894,460.2450,1583.6801,0);
	CreateDynamic3DTextLabel("Федеральная Служба Безопасности",0xFFFFFFFF,814.10, 2432.35, 12.21+1,5.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,166.26, 443.15, 1583.68+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
//====================================[ ЦГБ-А ]=================================
	BOLA_PICK[0] = CreateDynamicPickup(1318, 23, 436.8893, 1559.8527, 12.9474, 0);
	BOLA_PICK[1] = CreateDynamicPickup(1318, 23, -1510.5693,1342.5870,1523.7000,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,-1510.5693,1342.5870,1523.7000+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	bolnicamedpick[0] = CreateDynamicPickup(1239, 23, -1526.43, 1337.45, 1523.68,0);
	bolnicamedpick[1] = CreateDynamicPickup(1241, 23, -1511.69, 1361.89, 1523.68,0);
	//Покупка металла
	pickmetll = CreateDynamicPickup(1239,2,1646.49, 1409.40, 12.00);
	//Туннель
	tunnel[0] = CreateDynamicPickup(1318, 23, 1539.1289,1762.2802,-7.5291,0);
	tunnel[1] = CreateDynamicPickup(1318, 23, 2494.9148,1869.4111,-7.5524,0);
	//СМИ
	SMI_PICK[0] = CreateDynamicPickup(1318, 23, 2126.5911, -1962.3794, 20.3229, 0); //+
	SMI_PICK[1] = CreateDynamicPickup(1318, 23, 1937.4807, 2922.3198, 1672.9299, 0);
 	//СМИ
	SMI_PICK2[0] = CreateDynamicPickup(1318, 23, -317.8667,816.5047,13.0635, 0); //+
	SMI_PICK2[1] = CreateDynamicPickup(1318, 23, 1937.4807, 2922.3198, 1672.9299, 1);
	// Армия
	kazarmapick[0] = CreateDynamicPickup(1318, 23, 1736.8804,1772.8250,16.2109,0); //+
	kazarmapick[1] = CreateDynamicPickup(1318, 23, 841.3560,244.2667,1014.2498,0);
	//Интерьер склада армии
	army_warehouse[0] = CreateDynamicPickup(1318, 23, 1449.8497,1672.8899,15.3435,0); // Вход
	army_warehouse[1] = CreateDynamicPickup(1318, 23, -70.5206,1144.7675,2340.5300,0); // Выход
	CreateDynamic3DTextLabel("Склад армии",0xFFFFFFFF,1449.8497,1672.8899,15.3435+1,5.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,-70.5206,1144.7675,2340.5300+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	//ОПГ Южная
	opgpick1[0] = CreateDynamicPickup(1318, 23, 2061.2151,-2595.1128,10.8200,0); // ОПГ в Южном
	opgpick1[1] = CreateDynamicPickup(1318, 23, 2097.0193,-1645.3972,2056.6399,1); // ОПГ в Южном
	CreateDynamic3DTextLabel("ОПГ Южная",0xFFFFFFFF,2061.2151,-2595.1128,10.8200,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,2097.0193,-1645.3972,2056.6399,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,0);
 	//ОПГ Ореховская
	opgpick2[0] = CreateDynamicPickup(1318, 23, 2616.2402,1763.3225,3.0097,0); // ОПГ при въезде в Батырево
	opgpick2[1] = CreateDynamicPickup(1318, 23, 2097.0193,-1645.3972,2056.6399,2); // ОПГ при въезде в Батырево
	CreateDynamic3DTextLabel("ОПГ Ореховская",0xFFFFFFFF,2616.3569,1763.3018,3.0097,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,2097.0193,-1645.3972,2056.6399,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,2,0);
  	//ОПГ Солнцевская
	opgpick3[0] = CreateDynamicPickup(1318, 23, -46.4520,1518.4667,14.5622,0); // ОПГ в Арзамасе
	opgpick3[1] = CreateDynamicPickup(1318, 23, 2097.0193,-1645.3972,2056.6399,3); // ОПГ в Арзамасе
	CreateDynamic3DTextLabel("ОПГ Солнцевская",0xFFFFFFFF,-46.4520,1518.4667,14.5622,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,2097.0193,-1645.3972,2056.6399,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,3,0);
   	//Чеченская мафия
	chechenpick[0] = CreateDynamicPickup(1318, 23, 1942.0944,2181.0398,15.7100,0); // Мафия в Батырево
	chechenpick[1] = CreateDynamicPickup(1318, 23, 61.1161,1103.5089,1912.9700,4); // Мафия в Арзамасе
	CreateDynamic3DTextLabel("Чеченская Мафия",0xFFFFFFFF,1942.0944,2181.0398,15.7100,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,61.1161,1103.5089,1912.9700,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,3,0);
	//Баня
	banyavhod[0] = CreateDynamicPickup(1318, 23, 2193.0615,-341.1890,2332.1599, 0);
	banyavhod[1] = CreateDynamicPickup(1318, 23, 2191.9714,-317.7786,2332.1599, 0);
    banyapick[0] = CreateDynamicPickup(1318, 23, 2257.6770,-2187.7087,22.4104, 0); // пикап для входа
    banyapick[1] = CreateDynamicPickup(1318, 23, 2185.7266,-344.7455,2332.1599, 0); // пикап для выхода
    // Интерьер казино в пгт. Батырево, который нельзя купить
	casino_nostalgia[0] = CreateDynamicPickup(19132, 23, 345.5335,2955.6504,1.7500,0); //+
	casino_nostalgia[1] = CreateDynamicPickup(19132, 23, 341.6794,2959.5242,1.7659,0);
	CreateDynamic3DTextLabel("Казино \"Ностальгия\"",0xFFCC00FF,345.5335,2955.6504,1.7500,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFCC00FF,341.6794,2959.5242,1.7659,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	// Столовая армия
	stolovkapick[0] = CreateDynamicPickup(1318, 23, 345.5335,2955.6504,1.7500,0); //+
	stolovkapick[1] = CreateDynamicPickup(1318, 23, 341.6794,2959.5242,1.7659,0);
	CreateDynamic3DTextLabel("Столовая",0xFFFFFFFF,345.5335,2955.6504,1.7500+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,341.6794,2959.5242,1.7659+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	// Автосалон 2
	carshowroom[0] = CreateDynamicPickup(1318, 23, 658.5319, 981.9087, 12.0617, -1);
	carshowroom[1] = CreateDynamicPickup(1318, 23, 2657.5286,-1920.4762,2324.9900, -1);
	CreateDynamic3DTextLabel("Автосалон г. Арзамаса",0xFFFFFFFF,658.5319, 981.9087, 12.0617+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,2657.0837, -1920.3422, 2324.9944+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	// Автосалон 1
	avtosalonpick[0] = CreateDynamicPickup(1239, 23, 2639.02, -1909.31, 2328.15,-1);
	avtosalonpick[1] = CreateDynamicPickup(1318, 23, 1126.6505,1559.8279,2316.2300,-1);
	// банк
	bankpick[0] = CreateDynamicPickup(1318,23,1853.59, 2035.03, 16.97);
	bankpick[1] = CreateDynamicPickup(1318,23,500.00, 721.60, 2713.17, 1);
	CreateDynamic3DTextLabel("Банк",0xFFFFFFFF,1853.59, 2035.03, 16.97+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,500.00, 721.60, 2713.17+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
 	bankpickarz[0] = CreateDynamicPickup(1318, 23, 445.4992, 595.0807, 12.9819);
	bankpickarz[1] = CreateDynamicPickup(1318,23,500.00, 721.60, 2713.17, 2);
	CreateDynamic3DTextLabel("Банк",0xFFFFFFFF,1853.59, 2035.03, 16.97+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,500.00, 721.60, 2713.17+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
 	sudpick[0] = CreateDynamicPickup(1318,23,-139.2102,596.4312,12.1367);
	sudpick[1] = CreateDynamicPickup(1318,23,605.1932,2310.5132,1944.3199, 1);
	CreateDynamic3DTextLabel("Суд",0xFFFFFFFF,-139.2102,596.4312,12.1367+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,605.0511,2310.5183,1944.3199+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	// Военкомат
	voenkomat_arzamas[0] = CreateDynamicPickup(1318,23,-399.64, 596.29, 12.52);
	voenkomat_arzamas[1] = CreateDynamicPickup(1318, 23,-1809.29, -1384.49, 1597.91, 0);
	CreateDynamic3DTextLabel("Военкомат",0xFFFFFFFF,-399.64, 596.29, 12.52+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,-1809.29, -1384.49, 1597.91+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	//
 	voenkomat_bat[0] = CreateDynamicPickup(1318,23,1919.1627,2303.8408,15.5697);
	voenkomat_bat[1] = CreateDynamicPickup(1318, 23,-1809.29, -1384.49, 1597.91, 1);
	CreateDynamic3DTextLabel("Военкомат",0xFFFFFFFF,1919.1627,2303.8408,15.5697+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	CreateDynamic3DTextLabel("Выход",0xFFFFFFFF,-1809.29, -1384.49, 1597.91+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	// Водолазы
	vodolazipick[0] = CreateDynamicPickup(1318,23,2813.44, -2545.23, 11.33);
	vodolazipick[1] = CreateDynamicPickup(1318,23,2819.49, -2559.20, 1.42);
	//Штрафстоянка
	parking_fine[0] = CreateDynamicPickup(1239, 23, 542.99, 1109.92, 12.04);
	CreateDynamic3DTextLabel("Штрафстоянка",0xFFFFFFFF,542.99, 1109.92, 12.04+1,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0);
	// Устройство на работу
	merpicls[4] = CreateDynamicPickup(19134,23,817.6002,806.5474,-72.9915,-1);
	// Автомобили для работы "инкассаторы"
	AddStaticVehicle(428,406.1130,600.7966,11.9440,69.4790,46,46); // sberbank сбербанк 1
	AddStaticVehicle(428,404.5695,596.8455,11.9764,69.4814,46,46); // sberbank сбербанк 2
	AddStaticVehicle(428,402.9841,592.6554,11.9796,69.4812,46,46); // sberbank сбербанк 3
	AddStaticVehicle(428,401.3524,588.3935,11.9799,69.4813,46,46); // sberbank сбербанк 4
	AddStaticVehicle(428,399.8365,584.3559,11.9803,69.4811,46,46); // sberbank сбербанк 5
	//=============================== Автобусы ======================================
	buscar[0] = AddStaticVehicle(413,1932.7802,2102.5276,15.9580,143.4882,6,6); // Автобус
    AddStaticVehicle(413,1927.4086,2102.5386,15.9580,144.6574,6,6); //
	AddStaticVehicle(413,1921.6343,2102.6057,15.9580,147.3934,6,6); //
	AddStaticVehicle(413,1916.2898,2102.7493,15.9580,149.0438,6,6); //
	AddStaticVehicle(413,1910.3177,2102.2048,15.9722,149.3760,6,6); // Автобус, конец батырево, и снизу начало Арзамас
	AddStaticVehicle(418,426.4592,1486.8130,12.2442,17.5464,6,6); // 1 автобус
	AddStaticVehicle(418,422.1686,1487.2878,12.2431,15.8439,6,6); // 2 автобус
	AddStaticVehicle(418,418.0194,1487.6489,12.2015,23.4816,6,6); // 3 автобус
	AddStaticVehicle(418,414.0494,1488.2810,12.2034,25.9706,6,6); // 4 автобус, конец Арзамас
	//
	AddStaticVehicle(418,2726.9709,-2460.3518,21.9175,359.8459,6,6); // avtobus
	AddStaticVehicle(418,2722.4705,-2460.3311,21.8890,359.9806,6,6); // avtobus
	AddStaticVehicle(418,2717.4707,-2460.3342,21.9032,359.9762,6,6); // avtobus
	AddStaticVehicle(418,2712.9749,-2460.3811,21.9263,359.9688,6,6); // avtobus
	AddStaticVehicle(418,2708.4739,-2460.3955,21.9207,359.9810,6,6); // avtobus
	//
	AddStaticVehicle(414,2143.6973,-1809.5884,19.6158,0.1388,6,6); // avto bus
	AddStaticVehicle(414,2150.7708,-1809.5533,19.7218,359.6292,6,6); // avto bus
	AddStaticVehicle(414,2157.6008,-1809.5859,19.6243,2.3207,6,6); // avto bus
	buscar[1] = AddStaticVehicle(414,2164.2212,-1809.5369,19.7072,0.9052,6,6); // avto bus
	for(new i = 0; i < sizeof(ArendInfo); i ++)
	{
	    ArendInfo[i][aID] = AddStaticVehicleEx(ArendInfo[i][aModel], ArendInfo[i][aPos_X], ArendInfo[i][aPos_Y], ArendInfo[i][aPos_Z], ArendInfo[i][aPos_A], ArendInfo[i][aColor_1], ArendInfo[i][aColor_2], 100000);
        SetVehicleParamsEx(ArendInfo[i][aID], false, false, false, false, false, false, false);
	}
	// Автомобили такси в пгт. Батырево
	taxicar[0] = AddStaticVehicle(529,1855.0732,2238.0837,14.9728,359.6179,6,6); // авто 1
	AddStaticVehicle(529,1859.2092,2238.0952,15.0989,359.5284,6,6); // авто 2
	AddStaticVehicle(529,1863.2811,2238.1460,15.1045,0.2573,6,6); // авто 3
	AddStaticVehicle(529,1867.5088,2238.0039,15.0194,359.9849,6,6); // авто 4
	AddStaticVehicle(529,1871.6801,2238.1365,15.0193,0.0257,6,6); // авто 5
	// автомобили вип такси в пгт. Батырево
	AddStaticVehicle(402,1873.2227,2273.9958,14.9852,180.3008,162,1); // такси
	AddStaticVehicle(402,1869.7649,2274.0432,14.9837,179.2382,162,1); // такси
	AddStaticVehicle(402,1866.5858,2274.0027,14.9837,180.3508,162,1); // такси
	AddStaticVehicle(402,1863.3268,2273.8884,14.9833,179.9957,162,1); // такси
	// автомобили южный вип
	AddStaticVehicle(445,2338.3459,-1930.8883,21.5437,90.0081,162,162); // такси машина
	AddStaticVehicle(445,2338.4187,-1927.0847,21.6251,90.0077,162,162); // такси машина 2
	AddStaticVehicle(445,2338.6064,-1923.0378,21.6223,90.0107,162,162); // такси машина 3
	AddStaticVehicle(445,2338.5195,-1919.0688,21.5624,90.0084,162,162); // такси машина 4
	taxicar[1] = AddStaticVehicle(445,2338.5559,-1915.2631,21.5358,90.0084,162,162); // такси машина 5
	//taxicar[1] = AddStaticVehicle(420,-239.8852,946.6199,11.8927,0.1534,6,6); // taxi 5
	// Автомобили такси в г. Арзамас
	/*AddStaticVehicle(420,313.3510,1569.1132,11.6393,264.1472,6,6); // taxicar
	AddStaticVehicle(420,313.0554,1565.1464,11.6374,264.9767,6,6); // taxicar 2
	AddStaticVehicle(420,312.9571,1561.2059,11.6382,264.7987,6,6); // taxicar 3
	AddStaticVehicle(420,312.6860,1557.3655,11.6385,264.7854,6,6); // taxicar 4
	AddStaticVehicle(420,312.3911,1553.6853,11.6393,264.0666,6,6); // taxicar 5
	*/
	//Автомобили в г. Рыжевск
	/*AddStaticVehicle(420,1233.0090,-349.7422,3.7116,359.4035,6,6); // ryzhevsk taxicar
	AddStaticVehicle(420,1236.6566,-349.7705,3.7122,359.3721,6,6); // ryzhevsk taxicar
	AddStaticVehicle(420,1240.1260,-349.8205,3.7125,1.1614,6,6); // ryzhevsk taxicar
	AddStaticVehicle(420,1243.4492,-349.7922,3.7116,359.7032,6,6); // ryzhevsk taxicar
	AddStaticVehicle(420,1246.8367,-349.7544,3.7116,0.1164,6,6); // ryzhevsk taxicar
	*/
	// Автомобили такси в г. Арзамас около казино в центре, на омозинге рядом с агенством недвижимости
	/*AddStaticVehicle(420,-225.8156,946.4365,11.9168,358.5434,6,6); // taxi 1
	AddStaticVehicle(420,-222.4937,946.3608,11.9167,359.5855,6,6); // taxi 2
	AddStaticVehicle(420,-219.1070,946.3252,11.9382,359.5771,6,6); // taxi 3
	AddStaticVehicle(420,-236.3275,946.6731,11.9070,0.2825,6,6); // taxi 4
	AddStaticVehicle(420,-239.8852,946.6199,11.8927,0.1534,6,6); // taxi 5
	*/
	// Стоянка мусоровозов (тестирование)
	/*AddStaticVehicle(408,354.1330,225.4218,12.5403,68.2787,138,138); // musor 1
	AddStaticVehicle(408,355.8802,229.9194,12.5389,68.2799,138,138); // musor 2
	AddStaticVehicle(408,357.6722,234.4869,12.5392,68.0865,138,138); // musor 3
	AddStaticVehicle(408,359.3584,238.7650,12.5396,68.2769,138,138); // musor 4
	AddStaticVehicle(408,361.0227,242.8872,12.5398,68.1756,138,138); // musor 5
	*/
	// Работа МЧС (тестирование)
	AddStaticVehicle(544,1802.9791,2503.4873,15.7904,306.8735,3,1); // МЧС 1
	AddStaticVehicle(544,1799.6654,2507.9414,15.7921,307.7742,3,1); // МЧС 2
	AddStaticVehicle(544,1809.7411,2531.3201,15.7649,126.1764,3,1); // МЧС 3
	AddStaticVehicle(407,1806.2109,2523.2371,15.9891,127.4473,3,1); // МЧС 4
	AddStaticVehicle(407,1810.4530,2517.2664,16.0049,127.0819,3,1); // МЧС 5
	AddStaticVehicle(407,1815.1030,2511.2083,15.9908,127.2189,3,1); // МЧС 6
	AddStaticVehicle(407,1819.3639,2505.4111,16.0077,126.6697,3,1); // МЧС 7
	AddStaticVehicle(544,1830.3553,2503.1099,15.7908,126.2279,3,1); // МЧС 8
	// Автомобили с работы "Механики"
    mechanic[0] = AddStaticVehicleEx(525,2031.3655,1707.2809,15.9178,90.0713,1,2,900);
	AddStaticVehicleEx(525,2031.3267,1702.6316,15.9138,88.9265,3,4,900);
	AddStaticVehicleEx(525,2031.1920,1699.0636,15.9156,89.7137,5,6,900);
	// механики южный
	AddStaticVehicleEx(525,2162.7866,-1820.3979,18.7759,142.0622,17,20,900); // mexanik
	AddStaticVehicleEx(525,2152.9368,-1820.5636,18.7913,146.2906,22,30,900); // mexanik
	AddStaticVehicleEx(525,2148.0430,-1820.7268,18.7399,148.9429,36,43,900); // mexanik
	AddStaticVehicleEx(525,2143.2068,-1820.8278,18.7487,148.9099,44,51,900);// mexanik
    mechanic[1] = AddStaticVehicleEx(525,2031.1490,1694.5487,15.9107,89.5214,7,8,900);
	// Автомобили фракции "Автошкола"
//	CategoryA[0] = AddStaticVehicleEx(420,1941.1428,2246.8303,15.3706,89.6899,3,3,900);
//	CategoryA[1] = AddStaticVehicleEx(420,1941.0850,2248.6548,15.3704,89.1513,3,3,900);
	Category[0] = AddStaticVehicleEx(420,1924.0864,2227.9304,15.2336,359.4565,3,3,900);
	AddStaticVehicleEx(516,1928.9388,2227.6060,15.2354,359.3778,3,3,900);
	Category[1] = AddStaticVehicleEx(516,1934.4419,2227.0940,15.1667,358.6336,3,3,900);
//	CategoryC[0] = AddStaticVehicleEx(515,1921.9586,2250.0825,16.3481,90.4846,3,3,900);
//	CategoryC[1] = AddStaticVehicleEx(515,1929.4639,2250.2246,16.3500,91.0711,3,3,900);
//	CategoryD = AddStaticVehicleEx(483,1909.7322,2236.1389,15.9741,359.3188,3,3,900);
	// Автомобили фракции "Администрация Президента (АП)"
	CAR_AO[0] = AddStaticVehicleEx(540,1796.9641,2082.0020,15.6048,0.0015,1,1,900); // Мэрия кар 1
	AddStaticVehicleEx(540,1793.3883,2082.0022,15.5990,359.9931,1,1,900); //
	AddStaticVehicleEx(540,1789.6044,2082.0022,15.6048,359.9877,1,1,900); //
	AddStaticVehicleEx(540,1785.9757,2081.9902,15.5966,0.0013,1,1,900); //
	AddStaticVehicleEx(426,1797.5665,2102.1089,15.5093,359.3752,1,1,900); //
	AddStaticVehicleEx(490,1803.5847,2124.5081,16.0811,269.9979,1,1,900); //
	CAR_AO[1] = AddStaticVehicleEx(490,1812.5842,2124.5078,16.0795,269.9982,1,1,900); // Мэрия кар 8
	// Автомобили ОПГ Южная
	opg1car[0] = AddStaticVehicleEx(507,2026.5026,-2580.7295,10.7117,179.3000,111,111, 900); // ОПГ Южная
	AddStaticVehicleEx(507,2023.0520,-2580.7390,10.7230,179.3155,111,111, 900); // Автомобиль ОПГ Южная
	AddStaticVehicleEx(421,2019.5947,-2580.6721,10.6596,180.0230,111,111, 900); // Автомобиль ОПГ Южная
	AddStaticVehicleEx(421,2016.1703,-2580.6731,10.6244,180.1323,111,111, 900); // Автомобиль ОПГ Южная
	AddStaticVehicleEx(421,2012.8068,-2580.6721,10.6375,180.1385,111,111, 900); // АвтомобильОПГ Южная
	AddStaticVehicleEx(482,2005.8901,-2580.7607,10.7625,180.0061,111,111, 900); // Автомобиль ОПГ Южная
	opg1car[1] = AddStaticVehicleEx(482,2009.3351,-2580.7610,10.7598,180.0036,111,111, 900); // ОПГ Южная
	// Автомобили ОПГ Ореховская
	opg2car[0] = AddStaticVehicleEx(507,2631.8508,1781.0085,2.4905,90.5519,36,36, 900); // Автомобиль ОПГ Ореховская
	AddStaticVehicleEx(421,2631.7061,1776.9401,2.4331,89.9958,36,36, 900); // Автомобиль ОПГ Ореховская
	AddStaticVehicleEx(421,2631.7058,1772.9398,2.4355,89.9959,36,36, 900); // Автомобиль ОПГ Ореховская
	AddStaticVehicleEx(421,2631.7056,1768.9401,2.4353,89.9962,36,36, 900); // Автомобиль ОПГ Ореховская
	AddStaticVehicleEx(507,2631.8928,1764.4552,2.4893,90.5711,36,36, 900); // Автомобиль ОПГ Ореховская
	AddStaticVehicleEx(482,2632.3816,1760.5900,2.4628,90.0129,36,36, 900); // Автомобиль ОПГ Ореховская
	opg2car[1] = AddStaticVehicleEx(482,2632.3821,1756.3837,2.4622,90.0131,36,36, 900); // Автомобиль ОПГ Ореховская
 	// Автомобили ОПГ Солнцевская
	opg3car[0] = AddStaticVehicleEx(507,-39.4067,1512.4049,13.6869,228.7540,4,4, 900); // ОПГ Солнцевская
	AddStaticVehicleEx(507,-32.9963,1506.7858,13.6888,228.7548,4,4, 900); // Автомобиль ОПГ Солнцевская
	AddStaticVehicleEx(421,-39.8838,1497.6405,13.6200,316.7976,4,4, 900); // Автомобиль ОПГ Солнцевская
	AddStaticVehicleEx(421,-42.5136,1500.1576,13.6177,316.8034,4,4, 900); // Автомобиль ОПГ Солнцевская
	AddStaticVehicleEx(421,-45.0692,1502.6223,13.6680,317.5969,4,4, 900); // Автомобиль ОПГ Солнцевская
	AddStaticVehicleEx(482,-48.4232,1505.2977,13.7863,316.8062,4,4, 900); // Автомобиль ОПГ Солнцевская
	opg3car[1] = AddStaticVehicleEx(482,-51.5649,1508.2843,13.7843,316.8043,4,4, 900); // ОПГ Солнцевская
	// Автомобили ППС
	CAR_PPS[0] = AddStaticVehicleEx(599,376.4598,768.8971,12.0526,249.8389,1,53, 900); // PPS 1
	AddStaticVehicleEx(599,377.6797,772.1161,12.0529,249.8394,1,53, 900); // PPS 2
	AddStaticVehicleEx(599,378.9763,775.7301,12.0452,249.8387,1,53, 900); // pps 3
	AddStaticVehicleEx(599,380.2528,779.1198,12.0452,249.8382,1,53, 900); // pps 4
	AddStaticVehicleEx(599,381.5045,782.4541,12.0452,249.8376,1,53, 900); // pps 5
	AddStaticVehicleEx(599,382.7576,785.7905,11.9570,249.8428,1,53, 900); // pps 6
	AddStaticVehicleEx(599,384.0130,789.1714,11.9565,249.8378,1,53, 900); // pps 7
	AddStaticVehicleEx(599,385.3292,792.6943,11.9556,249.8426,1,53, 900); // pps 8
	AddStaticVehicleEx(427,388.5816,801.7225,12.2036,159.4187,1,53, 900); // pps 9
	AddStaticVehicleEx(427,394.6111,799.4541,12.2037,159.4189,1,53, 900); // pps 10
	AddStaticVehicleEx(427,400.5367,797.3150,12.2036,159.4187,1,53, 900); // pps 11
	AddStaticVehicleEx(427,406.5450,795.0972,12.2038,159.4190,1,53, 900); // pps 12
	AddStaticVehicleEx(427,412.4911,792.9493,12.2039,159.4187,1,53, 900); // pps 13
	AddStaticVehicleEx(427,418.5275,790.7332,12.2039,159.4191,1,53, 900); // pps 14
	AddStaticVehicleEx(427,424.5405,788.5045,12.2037,159.4188,1,53, 900); // pps 15
	CAR_PPS[1] = AddStaticVehicleEx(437,394.7358,769.4554,12.4492,159.4872,1,53, 900); // pps 16
	// Автомобили ДПС
	CAR_DPS[0] = AddStaticVehicleEx(597,2574.7166,-2446.3669,21.7943,0.0046,1,53, 900); // DPS 1
	AddStaticVehicleEx(597,2571.0764,-2446.3667,21.7925,0.0059,1,53, 900); // DPS 2
	AddStaticVehicleEx(597,2567.4507,-2446.3596,21.8654,359.9834,1,53, 900); // DPS 3
	AddStaticVehicleEx(598,2563.7085,-2446.4412,21.6659,359.9956,1,53, 900); // DPS 4
	AddStaticVehicleEx(598,2560.1436,-2446.4375,21.7090,359.9851,1,53, 900); // DPS 5
	AddStaticVehicleEx(598,2556.6165,-2446.4380,21.7091,359.9871,1,53, 900); // DPS 6
	AddStaticVehicleEx(598,2552.9143,-2446.4395,21.7088,0.0079,1,53, 900); // DPS 7
	AddStaticVehicleEx(522,2542.3503,-2446.8250,21.5322,270.0000,79,79, 900); // DPS 8
	AddStaticVehicleEx(522,2542.3503,-2440.4800,21.5322,270.0000,79,79, 900); // DPS 9
	AddStaticVehicleEx(522,2542.3503,-2434.1250,21.5322,270.0000,79,79, 900); // DPS 10
	AddStaticVehicleEx(522,2542.3503,-2427.7700,21.5322,270.0000,79,79, 900); // DPS 11
	AddStaticVehicleEx(522,2542.3503,-2421.4150,21.5322,270.0000,79,79, 900); // DPS 12
	AddStaticVehicleEx(522,2542.3503,-2415.0601,21.5322,270.0000,79,79, 900); // DPS 13
	AddStaticVehicleEx(525,2558.6475,-2408.7432,21.9582,90.0083,1,1, 900); // DPS 14
	AddStaticVehicleEx(525,2558.6475,-2414.9429,21.9582,90.0085,1,1, 900); // DPS 15
	AddStaticVehicleEx(525,2558.6477,-2421.1428,21.9670,90.0093,1,1, 900); // DPS 16
	CAR_DPS[1] = AddStaticVehicleEx(437,2569.0061,-2429.7146,22.4901,269.9933,1,53, 900); // DPS 17
	// Автомобили ФСБ
	CAR_FSIN[0] = AddStaticVehicleEx(490,774.1239,2409.7231,12.3955,356.7602,0,0,900); // ФСБ авто
	AddStaticVehicleEx(490,780.0402,2413.1140,12.4095,356.7593,0,0,900); // ФСБ авто
	AddStaticVehicleEx(490,850.9260,2454.9673,12.4114,61.5028,0,0,900); // ФСБ авто
	AddStaticVehicleEx(490,856.1657,2458.4216,12.4204,61.5604,0,0,900); // ФСБ авто
	AddStaticVehicleEx(601,831.9336,2477.2158,11.8352,120.3691,0,0,900); // ФСБ авто
	AddStaticVehicleEx(601,829.0453,2482.0920,11.8349,120.3661,0,0,900); // ФСБ авто
	AddStaticVehicleEx(402,776.7853,2436.2603,11.7078,300.6672,0,0,900); // ФСБ авто
	AddStaticVehicleEx(579,773.4520,2442.9231,12.1284,300.5613,0,0,900);// ФСБ авто
	AddStaticVehicleEx(440,769.2122,2449.1333,12.1183,300.5846,0,0,900); // ФСБ авто
	CAR_FSIN[1] = AddStaticVehicleEx(440,767.3372,2452.2500,12.1189,301.3601,0,0,900); // ФСБ авто
	// Автомобили СМИ
	CAR_SMI[0] = AddStaticVehicleEx(436,2074.1272,-1929.4330,18.6866,269.9941,130,130,900); // TRK омозинг
	AddStaticVehicleEx(582,2074.9893,-1925.0684,18.9301,269.9958,130,130,900); // TRK омозинг
	AddStaticVehicleEx(582,2074.9873,-1918.8993,18.9268,269.9973,130,130,900); // TRK омозинг
	AddStaticVehicleEx(582,2074.9858,-1912.8334,18.9236,269.9944,130,130,900); // TRK омозинг
	AddStaticVehicleEx(582,2074.9893,-1906.7212,18.9193,269.9958,130,130,900); // TRK омозинг
	AddStaticVehicleEx(582,2074.9893,-1900.5544,18.9193,269.9958,130,130,900); // TRK омозинг
	AddStaticVehicleEx(573,2074.4854,-1894.3937,19.4883,270.0000,130,130,900); // TRK омозинг
	CAR_SMI[1] = AddStaticVehicleEx(573,2074.4854,-1888.2797,19.4883,270.0000,130,130,900); // TRK омозинг
	// Автомобили СМИ
	CAR_MZA[0] = AddStaticVehicleEx(436,-336.0109,839.8407,12.8348,179.4213,101,101,900); // 1
	AddStaticVehicleEx(582,-330.8186,839.3773,13.1553,180.0019,101,101,900); // 2
	AddStaticVehicleEx(582,-324.6631,839.3999,13.1009,180.0026,101,101,900); // 3
	AddStaticVehicleEx(582,-318.4974,839.4010,13.0944,180.0072,101,101,900); // 4
	AddStaticVehicleEx(582,-312.0304,839.3937,13.0945,180.0063,101,101,900); // 5
	AddStaticVehicleEx(582,-305.8983,839.4434,13.1021,179.9128,101,101,900); // 6
	AddStaticVehicleEx(573,-343.1002,768.5734,13.6293,269.9275,101,101,900); // 7
	AddStaticVehicleEx(573,-343.1013,761.9091,13.6331,270.0002,101,101,900); // 8
	CAR_MZA[1] = AddStaticVehicleEx(488,-302.7507,767.2524,13.2219,87.2344,101,101,900); // 9
	//Авто Воинская Часть (армия, вдв)
	CAR_VDV[0] = AddStaticVehicleEx(432,1833.2367,1761.5898,15.4402,180.0000,44,44,900); //
	AddStaticVehicleEx(432,1822.1857,1761.5933,15.4330,180.0000,44,44,900); //
	AddStaticVehicleEx(533,1799.2971,1767.8876,15.2290,180.0001,44,44,900); //
	AddStaticVehicleEx(578,1792.9227,1757.1378,15.4064,179.7775,44,44,900); //
	AddStaticVehicleEx(578,1788.0098,1757.1633,15.4002,179.4015,44,44,900); //
	AddStaticVehicleEx(578,1783.3992,1757.1772,15.4013,179.7767,44,44,900); //
	AddStaticVehicleEx(548,1837.5206,1679.9342,15.8534,0.0499,44,44,900); //
	AddStaticVehicleEx(548,1811.2991,1679.8020,15.8333,359.9967,44,44,900); //
	AddStaticVehicleEx(601,1768.0675,1688.7559,15.0357,38.7621,44,44,900); //
	AddStaticVehicleEx(601,1768.0651,1682.8456,15.0344,38.7601,44,44,900); //
	AddStaticVehicleEx(601,1768.0646,1676.9349,15.0379,38.7594,44,44,900); //
	AddStaticVehicleEx(425,1739.0603,1681.8359,16.1220,359.9631,44,44,900); //
	AddStaticVehicleEx(425,1713.3500,1682.3885,16.1453,359.9830,44,44,900);//
	AddStaticVehicleEx(470,1435.4492,1710.1388,15.2243,179.9498,44,44,900); // тачка армия
	AddStaticVehicleEx(470,1441.8712,1710.1370,15.2913,179.9999,44,44,900); // тачка армия
	AddStaticVehicleEx(470,1448.0392,1710.1370,15.2913,180.0001,44,44,900); // тачка армия
	AddStaticVehicleEx(470,1454.4642,1710.1370,15.2913,180.0000,44,44,900); // тачка армия
	AddStaticVehicleEx(470,1460.6322,1710.1370,15.2913,180.0000,44,44,900); // тачка армия
	AddStaticVehicleEx(470,1467.3142,1710.1370,15.2913,180.0001,44,44,900); // тачка армия
	AddStaticVehicleEx(578,1444.7944,1678.2589,15.4021,0.6173,44,44,900); // тачка армия
	AddStaticVehicleEx(520,1925.9208,1559.4929,15.9056,89.8627,44,44,900);//
	CAR_VDV[1] = AddStaticVehicleEx(520,1943.1287,1541.0121,15.9056,90.0000,44,44,900); //
	
 	CAR_MZY[0] = AddStaticVehicleEx(416, 2098.536, -2467.671, 22.140, 89.9683, 1, 1, 900);
	AddStaticVehicleEx(416, 2104.559, -2467.671, 22.140, 89.8958, 1, 1, 900);
	AddStaticVehicleEx(416, 2110.656, -2467.671, 22.140, 89.9879, 1, 1, 900);
	AddStaticVehicleEx(416, 2116.442, -2467.671, 22.140, 89.7818, 1, 1, 900);
	CAR_MZY[1] = AddStaticVehicleEx(416, 2122.124, -2467.671, 22.140, 270.0019, 6, 6, 900);
	return 1;
}
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