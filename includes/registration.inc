#define GKick(%1) 				SetTimerEx("PKick", 50, false, "i", %1)
enum Player_Info
{
	ID,
	Name[MAX_PLAYER_NAME],
	Password[32],
	Admin,
	bool:Logged,
	Money,
	Skin,
	Sex,
	IP[17],
};
//////////////////////////////////////////
//////////////////////////////////////////
enum
{
	DIALOG_REG,
	DIALOG_SEX,
	DIALOG_LOG,
};
//////////////////////////////////////////
new pInfo[MAX_PLAYERS][Player_Info];
//////////////////////////////////////////
forward PKick(playerid);
public PKick(playerid)
{
	Kick(playerid);
	return 1;
}

public OnPlayerConnect(playerid)
{
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, sizeof(name));
    if(!IsRPNick(name))
    {
        SCM(playerid, COLOR_NEWS, !"Придумайте RolePlay никнейм");
        return GKick(playerid);
    }
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
    SetPlayerColor(playerid, 0xFFFFFFFF);
   	new name[25];
	GetPlayerName(playerid, name, 25);
	TogglePlayerSpectating(playerid, 1);
	if(!pInfo[playerid][Logged])
	{
 		GetPlayerName(playerid, pInfo[playerid][Name], MAX_PLAYER_NAME);
 		GetPlayerIp(playerid, pInfo[playerid][IP], 17);
	    new qString[120];
	    format(qString, sizeof(qString), "SELECT * FROM `accounts` WHERE `name` = '%s'", pInfo[playerid][Name]);
	    mysql_tquery(MySQL, qString, "CheckAcc", "d", playerid);
	}
	return 1;
}

stock IsRPNick(const name[])
{
    static num_underscores, ptr;
    emit
    {
        load.s.pri name
        load.i
        const.alt 'A'
        jsless ret_false
        const.alt 'Z'
        jsgrtr ret_false
        load.s.pri name
        add.c (cellbits / charbits)
        load.i
        const.alt 'a'
        jsless ret_false
        const.alt 'z'
        jsgrtr ret_false
        zero num_underscores
        load.s.pri name
        add.c (cellbits / charbits * 2)
        jump loop_entry
    	loop:
        load.pri ptr
        add.c (cellbits / charbits)
    	loop_entry:
        stor.pri ptr
        load.i
        const.alt 'a'
        jsless is_underscore
        const.alt 'z'
        jsleq loop
    	is_underscore:
        const.alt '_'
        jneq is_term
        inc num_underscores
        load.pri ptr
        add.c (cellbits / charbits)
        load.i
        const.alt 'A'
        jsless ret_false
        const.alt 'Z'
        jsgrtr ret_false
        load.pri ptr
        add.c (cellbits / charbits * 2)
        stor.pri ptr
        load.i
        const.alt 'a'
        jsless ret_false
        const.alt 'z'
        jsleq loop
        jump ret_false
    	is_term:
        jnz ret_false
        load.pri ptr
        load.s.alt name
        sub
        const.alt (cellbits / charbits * 4)
        jsless ret_false
        load.pri num_underscores
        const.alt 1
        eq
        retn
    	ret_false:
    }
    return false;
}

public OnPlayerDisconnect(playerid, reason)
{
	ClearVars(playerid);
	return 1;
}

enum e_RandomSpawn
{
	Float:rX,
	Float:rY,
	Float:rZ,
	Float:rA
}

new RandomSpawn[][e_RandomSpawn] = {
	{ 2507.06, -2120.7, 23.46, 175.000 },
	{ 2507.19, -2123.03, 23.46, 183.18 },
	{ 2506.94, -2129.11, 23.46, 1.6288 },
	{ 2512.48, -2130.23, 23.46, 3.1328 },
	{ 2511.64, -2120.85, 23.46, 181.32 },
	{ 2511.58, -2123.76, 23.46, 178.80 }
};

public OnPlayerSpawn(playerid)
{
	new r = random(6);
	SetPlayerPos(playerid, RandomSpawn[r][rX], RandomSpawn[r][rY], RandomSpawn[r][rZ]);
	SetPlayerFacingAngle(playerid, RandomSpawn[r][rA]);
	SetPlayerSkin(playerid, pInfo[playerid][Skin]);
	SetCameraBehindPlayer(playerid);
	return 1;
}

forward CheckAcc(playerid);
public CheckAcc(playerid)
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(!rows)
    {
        SPD(playerid, DIALOG_REG, DIALOG_STYLE_INPUT, !"Регистрация", !"{FFFFFF}Придумайте свой будущий пароль для аккаунта", !"Далее", !"Отмена");
    }
    else
    {
        SPD(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"Авторизация", !"{FFFFFF}Введите пароль от аккаунта", !"Ок", "");
        cache_get_field_content(0, "password", pInfo[playerid][Password], MySQL, 33);
    }
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
	    case DIALOG_REG:
	    {
	        if(!response) return SPD(playerid, DIALOG_REG, DIALOG_STYLE_INPUT, !"Регистрация", !"Введите новый пароль для регистрации", !"Ок", "");
	        if(strlen(inputtext) < 6 || strlen(inputtext) > 32) return SPD(playerid, DIALOG_REG, DIALOG_STYLE_INPUT, !"Регистрация", !"Введите новый пароль для регистрации", !"Ок", ""), SCM(playerid, COLOR_ADM, !"Пароль должен состоять от 6-ти до 32-ух символов");
	        for(new i; i < strlen(inputtext); i++)
	        {
	            switch(inputtext[i])
	            {
	                case '0'..'9', 'a'..'z', 'A'..'Z': continue;
	                default: return SPD(playerid, DIALOG_REG, DIALOG_STYLE_INPUT, !"Регистрация", !"Введите новый пароль для регистрации", !"Ок", ""), SCM(playerid, COLOR_ADM, !"Пароль может содержать только латинские буквы и цифры");
	            }
	        }
	        format(pInfo[playerid][Password], 32, "%s", inputtext);
	        SPD(playerid, DIALOG_SEX, DIALOG_STYLE_MSGBOX, !"Регистрация", !"Выберите пол персонажа", !"Мужской", "Женский");
		}
		case DIALOG_SEX:
		{
		    if(response) pInfo[playerid][Sex] = 0;
		    else pInfo[playerid][Sex] = 1;
		    CreateAcc(playerid, pInfo[playerid][Password]);
		}
	    case DIALOG_LOG:
	    {
	        if(!response) return SPD(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"{FFFFFF}Авторизация", !"{FFFFFF}Введите свой пароль", !"Ок", "");
	        if(strlen(inputtext) < 6 || strlen(inputtext) > 32) return SPD(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"{FFFFFF}Авторизация", !"{FFFFFF}Пароль может состоять только от 6-ти до 32-ух латинских букв и цифр", !"Ок", "");
            for(new i; i < strlen(inputtext); i++)
	        {
	            switch(inputtext[i])
	            {
	                case '0'..'9', 'a'..'z', 'A'..'Z': continue;
	                default: return SPD(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"{FFFFFF}Авторизация", !"{FFFFFF}Пароль может содержать только английские буквы или цифры", !"Ок", "");
	            }
	        }
	        if(!strcmp(pInfo[playerid][Password], inputtext))
	        {
				new qString[42 + MAX_PLAYER_NAME];
	            format(qString, sizeof(qString), "SELECT * FROM `accounts` WHERE `name` = '%s'", pInfo[playerid][Name]);
	            mysql_function_query(MySQL, qString, true, "LoadAcc", "d", playerid);
	        }
	        else
	        {
				if(GetPVarInt(playerid, "BadAttempt") >= 3) return SPD(playerid, 228, DIALOG_STYLE_MSGBOX, !"Кикнут", !"{FFFFFF}Вы ввели неверно пароль 3 раза и были кикнуты, {EC4646}/q {FFFFFF}для выхода", !"Далее", ""), GKick(playerid);
	            new string[55];
	            format(string, sizeof(string), "Вы ввели неверный пароль! У Вас осталось %d попытки", 3 - GetPVarInt(playerid, "BadAttempt"));
             	if(GetPVarInt(playerid, "BadAttempt") == 2)
             	{
             	    SPD(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"Авторизация", !"Введите свой пароль", !"Ок", ""), SCM(playerid, COLOR_ADM, !"Вы ввели неверный пароль! У Вас осталась 1 попытка");
			 	}
			 	else
			 	{
                    SPD(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"Авторизация", !"Введите свой пароль", !"Ок", ""), SCM(playerid, COLOR_ADM, string);
				}
	            SetPVarInt(playerid, "BadAttempt", GetPVarInt(playerid, "BadAttempt") + 1);
   			}
  		}
	}
 	return 1;
}

forward LoadAcc(playerid);
public LoadAcc(playerid)
{
    pInfo[playerid][ID] = cache_get_field_content_int(0, "id", MySQL);
    pInfo[playerid][Admin] = cache_get_field_content_int(0, "admin", MySQL);
    pInfo[playerid][Money] = cache_get_field_content_int(0, "money", MySQL);
    pInfo[playerid][Skin] = cache_get_field_content_int(0, "skin", MySQL);
    pInfo[playerid][Sex] = cache_get_field_content_int(0, "sex", MySQL);
    new qString[110];
    format(qString, sizeof(qString), "SELECT * FROM `accounts` WHERE `name` = '%s'", pInfo[playerid][Name]);
	mysql_tquery(MySQL, qString, "OnPlayerLogin", "d", playerid);
 	return 1;
}


forward OnPlayerLogin(playerid);
public OnPlayerLogin(playerid)
{
    pInfo[playerid][Logged] = true;
    DeletePVar(playerid, "BadAttempt");
    TogglePlayerSpectating(playerid, 0);
    SpawnPlayer(playerid);
	return 1;
}

stock CreateAcc(playerid, password[])
{
	new qString[200], skin;
	if(pInfo[playerid][Sex] == 0)
	{
		switch(random(3))
		{
			case 0: skin = 30;
			case 1: skin = 48;
			case 2: skin = 180;
		}
	}
	else
	{
		switch(random(3))
		{
			case 0: skin = 169;
			case 1: skin = 226;
			case 2: skin = 193;
		}
	}
	pInfo[playerid][Skin] = skin;
	format(qString, sizeof(qString), "INSERT INTO `accounts` (`name`, `password`, `skin`, `money`, `sex`, `regip`) VALUES ('%s', '%s', '%d', '%d', '%d', '%s')", pInfo[playerid][Name], password, pInfo[playerid][Skin], 100, pInfo[playerid][Sex], pInfo[playerid][IP]);
	mysql_tquery(MySQL, qString, "LoadAccID", "d", playerid);
	TogglePlayerSpectating(playerid, 0);
	pInfo[playerid][Logged] = true;
	SpawnPlayer(playerid);
	return 1;
}

forward LoadAccID(playerid);
public LoadAccID(playerid) return pInfo[playerid][ID] = cache_get_field_content_int(0, "id", MySQL);

stock ClearVars(playerid)
{
    pInfo[playerid][ID] = 0;
    pInfo[playerid][Name] = EOS;
    pInfo[playerid][Password] = EOS;
    pInfo[playerid][Admin] = 0;
    pInfo[playerid][Logged] = false;
    pInfo[playerid][Skin] = 0;
    pInfo[playerid][Money] = 0;
    pInfo[playerid][Sex] = 0;
    pInfo[playerid][IP] = EOS;
}
