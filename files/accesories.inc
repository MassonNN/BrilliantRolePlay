/* Система акссесуаров 
	Версия: 0.1 ALPHA
	Разработка ведется с 3 января 2020 года
	Senior Gamemode Developer: Folinq Weard
	CEO: Roma Omegov
	
	
	
    ----------- Todo list
	- Сделать инвентарь
	- Сделать добавление/убирание акссесуара
	- Сделать возможность продавать/покупать акссесуары
	- Сделать настройку акссесуаров

	
*/



// acc - префикс для системы акссесуаров

// #define acc_NUM 3 // сколько сейчас создано акссесуаров
// #define acc_MaxName 32 // Максимальное количество символов в названии акссесуара


// // -------- [РЕДКОСТЬ АКССЕСУАРА] --------------

// #define COMMON 		1 // обычный
// #define RARE		2 // редкий
// #define SUPER_RARE	3 // сверхредкий
// #define EXCLUSIVE	4 // эксклюзивный


/* -------- [ВНУТРЕННИЕ ID АКССЕСУАРОВ] --------



*/
// ---------------------------------------------

// enum acc_Inform { // информация об акссесуаре
// 	acc_id, // id аксессуара для внутренних перехватов и мапинуляций
// 	acc_name[acc_MaxName], // имя акссесуара
// 	acc_cost, // гос.стоимость акссесуара
// 	acc_game_id, // игровой id объекта акссесуара
// 	acc_bone, // кость, к которой крепится акссесуар по умолчанию
// 	acc_rarity // редкость предмета
// };

// new const static acc_Info[acc_NUM][acc_Inform] = {
// 	{0, "Катана", 			5000, 	18644, 	5, COMMON}, 
// 	{1, "Красная шапка", 	2000, 	18950, 	2, COMMON}, 
// 	{2, "Желтая шапка", 	2000, 	18951,	2, COMMON} 
// };

// #define GetAccName(%1)		acc_Info[%1][acc_name]
// #define GetAccCost(%1)		acc_Info[%1][acc_cost]
// #define GetAccRarity(%1)	acc_Info[%1][acc_rarity]
// #define GetAccBone(%1)		acc_Info[%1][acc_bone]
// #define GetAccModel(%1)		acc_Info[%1][acc_game_id]

// #define IsValidAcc(%1)		(0 < %1 < acc_NUM)



 
// ------------------------------------------


// enum acc_PlayerInfo { // Информация об игроке по системе акссесуаров
// 	bool:acc_bone_used[18], // Занятость слотов (всего 18)
// 	bool:acc_is_wear[18], // Занятость слотов (всего 18)
// 	bool:acc_is_have_acc[acc_NUM], // есть ли у игрока акссесуар (по макс кол-ву)
// 	bool:acc_banned[acc_NUM] // заблокирован ли акссесуар к перепродаже у игрока
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

// 		if(IsPlayerHaveAcc(playerid, acces_id)) { // Добавление уже имеющегося акссесуара на тело
// 			if(FindFreeSlot(playerid) > 9) { 
// 				SendErr(playerid, "Достигнуто максимальное количество акссесуаров");
// 				if(!PI[playerid][pVip]) SendTimeMessage(playerid, "Для того, чтобы установить более трех акссесуаров одновременно, приобретите VIP", 1000, POND_TYPE);
// 				return 0;
// 			}
			
// 			SetPlayerAttachedObject(playerid, \
// 			FindFreeSlot(playerid), \
// 			GetAccModel(acces_id), \
// 			GetAccBone(acces_id));
// 		}
// 		else  { // Добавление нового акссесуара
// 			if (IsBoneUsed(playerid, GetAccBone(acces_id)) || FindFreeSlot(playerid) > 9) SendErr(playerid, "Место под новый акссесуар занято, он добавлен к Вам в инвентарь.");
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
// 			(IsPlayerWearAcc(playerid, i)) ? ("{63BD4E}Надет") : ("{FFFF00}Снят"), \
// 			IsAccBanned(playerid, id) ? ("{FF0000}Заблокирован") : ("Не заблокирован"));
// 			strcat(string, tmp);
// 		} else continue;
// 	}
// 	if(!strlen(string)) string = "{FFFFFF}У игрока нет акссесуаров.";
// 	ShowPlayerDialog(playerid, ACCESLIST, \
// 	(PI[playerid][pAdmin] > 6) ? DIALOG_STYLE_LIST : DIALOG_STYLE_INPUT, \
// 	GetName(id), string, "Далее", "Закрыть");
// 	return 1;
// }

