new TempPlayerPassword[MAX_PLAYERS][33];

enum 
{
	DIALOG_REG,
	DIALOG_LOG,
	DIALOG_SEX
}

public OnPlayerDisconnect(playerid, reason)
{
	TempPlayerPassword[playerid][0] = EOS;
	return 1;
}

public OnPlayerConnect(playerid)
{
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, sizeof(name));
    if(!IsRPNick(name))
    {
        SendClientMessage(playerid, 0xFFFFFFFF, !"Придумайте RP никнейм");
        return Kick(playerid);
    }
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
    SetPlayerColor(playerid, 0xFFFFFFFF);
   	GetPlayerName(playerid, PI[playerid][PLAYER_Name], MAX_PLAYER_NAME);
	TogglePlayerSpectating(playerid, 1);
	new string[120];
	if(PI[playerid][PLAYER_Logged] == 0)
	{
 		GetPlayerIp(playerid, PI[playerid][PLAYER_IP], 17);
	    format(string, sizeof(string), "SELECT * FROM `accounts` WHERE `name` = '%s'", PI[playerid][PLAYER_Name]);
	    mysql_tquery(dbHandle, string, "CheckAcc", "d", playerid);
	}
	return 1;
}

forward CheckAcc(playerid);
public CheckAcc(playerid)
{
    	new rows = cache_num_rows();
    	if(!rows)
    	{
        	ShowPlayerDialog(playerid, DIALOG_REG, DIALOG_STYLE_INPUT, !"Регистрация", !"{FFFFFF}Введите новый пароль для своего игрового аккаунта\nВыбирайте пароль тщательно, дабы Вас не взломали\n\
       		Примечание: Пароль может быть от 6 до 32-х символов либого регистра на английском языке включая цифры", !"Далее", !"Отмена");
    	}
    	else
    	{
    		cache_get_value_name(0, "password", TempPlayerPassword[playerid]);
     	    ShowPlayerDialog(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"Авторизация", !"{FFFFFF}Введите пароль от своего аккаунта", !"Далее", !"Отмена");
    	}
    	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
	    case DIALOG_REG:
	    {
	    	if(!response) return Kick(playerid);
	        if(strlen(inputtext) < 6 || strlen(inputtext) > 32) return ShowPlayerDialog(playerid, DIALOG_REG, DIALOG_STYLE_INPUT, !"Регистрация", !"{FFFFFF}Введите новый пароль для своего игрового аккаунта\nВыбирайте пароль тщательно, дабы Вас не взломали\n\
       		Примечание: Пароль может быть от 6 до 32-х символов либого регистра на английском языке включая цифры", !"Далее", !"Отмена");
	        for(new i; i < strlen(inputtext); i++)
	        {
	            switch(inputtext[i])
	            {
	                case '0'..'9', 'a'..'z', 'A'..'Z': continue;
	                default: return ShowPlayerDialog(playerid, DIALOG_REG, DIALOG_STYLE_INPUT, !"Регистрация", !"{FFFFFF}Введите новый пароль для своего игрового аккаунта\nВыбирайте пароль тщательно, дабы Вас не взломали\n\
       				Примечание: Пароль может быть от 6 до 32-х символов либого регистра на английском языке включая цифры", !"Далее", !"Отмена");
	            }
	        }
	        format(TempPlayerPassword[playerid], 32, "%s", inputtext);
	        ShowPlayerDialog(playerid, DIALOG_SEX, DIALOG_STYLE_MSGBOX, !"Регистрация", !"Выберите пол для Вашего игрового персонажа", !"Мужской", !"Женский");
		}
		case DIALOG_SEX:
		{
		    	if(response) PI[playerid][PLAYER_Sex] = 1;
		    	else PI[playerid][PLAYER_Sex] = 2;
		    	CreateAcc(playerid, TempPlayerPassword[playerid]);
		}
    	case DIALOG_LOG:
    	{
        	if(!response) return Kick(playerid);
        	if(strlen(inputtext) < 6 || strlen(inputtext) > 32) return ShowPlayerDialog(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"Авторизация", !"{FFFFFF}Введите пароль от своего аккаунта", !"Далее", !"Отмена");
        	for(new i; i < strlen(inputtext); i++)
        	{
        		switch(inputtext[i])
        		{
           			case '0'..'9', 'a'..'z', 'A'..'Z': continue;
           			default: return ShowPlayerDialog(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"Авторизация", !"{FFFFFF}Введите пароль от своего аккаунта", !"Далее", !"Отмена");
        		}
        	}
       		if(!strcmp(TempPlayerPassword[playerid], inputtext))
       		{
				new qString[90];
        		format(qString, sizeof(qString), "SELECT * FROM `accounts` WHERE `name` = '%s'", PI[playerid][PLAYER_Name]);	            			
				mysql_tquery(dbHandle, qString, "LoadAcc", "d", playerid);
        	}
        	else
        	{
				if(GetPVarInt(playerid, "BadAttempt") >= 3) return ShowPlayerDialog(playerid, 228, DIALOG_STYLE_MSGBOX, !"Отключен", !"{FFFFFF}Вы были отключны от сервера из-за неоднократного ввода неправильного пароля\
				", !"Окей", ""), GKick(playerid);
        		new string[55];
        		format(string, sizeof(string), "Неверный пароль! Осталось %d попытки", 3 - GetPVarInt(playerid, "BadAttempt"));
     			if(GetPVarInt(playerid, "BadAttempt") == 2)
         		{
         	    	ShowPlayerDialog(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"Авторизация", !"{FFFFFF}Введите пароль от своего аккаунта", !"Далее", !"Отмена");
         	    	SendClientMessage(playerid, 0xFF0000FF, !"Неверный пароль! Осталась последняя попытка");

				}
				else
				{
                	ShowPlayerDialog(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"Авторизация", !"{FFFFFF}Введите пароль от своего аккаунта", !"Далее", !"Отмена"); 
                	SendClientMessage(playerid, 0xFF0000FF, string);
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
	cache_get_value_name_int(0, "id", PI[playerid][PLAYER_ID]);
	cache_get_value_name_int(0, "admin", PI[playerid][PLAYER_Admin]);
	cache_get_value_name_int(0, "money", PI[playerid][PLAYER_Money]);
	cache_get_value_name_int(0, "skin", PI[playerid][PLAYER_Skin]);
	cache_get_value_name_int(0, "sex", PI[playerid][PLAYER_Sex]);
	new qString[110];
	format(qString, sizeof(qString), "SELECT * FROM `accounts` WHERE `name` = '%s'", PI[playerid][PLAYER_Name]);
	mysql_tquery(dbHandle, qString, "OnPlayerLogin", "d", playerid);
 	return 1;
}


static const TesterssNames[][] = {

	{"Marshall_Mathers"},
	{"Bogdan_Swarovski"},
	{"Sergey_Sanchez"},
	{"Rich_Anderson"},
	{"Denis_Zona"},
	{"Igor_Belov"}
};

forward OnPlayerLogin(playerid);
public OnPlayerLogin(playerid)
{
    PI[playerid][PLAYER_Logged] = true;
    DeletePVar(playerid, "BadAttempt");
    TogglePlayerSpectating(playerid, 0);
    SpawnPlayer(playerid);
    for(new i; i < sizeof(TesterssNames); i++)
	{
		if(strcmp(PI[playerid][PLAYER_Name], TesterssNames[i])) continue;
		new string[125];
		format(string, sizeof(string), "Добро пожаловать на сервер, %s, Вы авторизовались как тестер", PI[playerid][PLAYER_Name]);
		SendClientMessage(playerid, COLOR_GREEN_L, string);
		break;
	}
	return 1;
}

stock CreateAcc(playerid, const password[])
{
	new qString[200], skin;
	if(PI[playerid][PLAYER_Sex] == 1)
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
	PI[playerid][PLAYER_Skin] = skin;
	format(qString, sizeof(qString), "INSERT INTO `accounts` (`name`, `password`, `skin`, `money`, `sex`, `regip`) VALUES ('%s', '%s', '%d', '%d', '%d', '%s')", PI[playerid][PLAYER_Name], password, PI[playerid][PLAYER_Skin], 100, PI[playerid][PLAYER_Sex], PI[playerid][PLAYER_IP]);
	mysql_tquery(dbHandle, qString, "LoadAccID", "d", playerid);
	TogglePlayerSpectating(playerid, 0);
	PI[playerid][PLAYER_Logged] = 1;
	SpawnPlayer(playerid);
	TempPlayerPassword[playerid][0] = EOS;
	for(new i; i < sizeof(TesterssNames); i++)
	{
		if(strcmp(PI[playerid][PLAYER_Name], TesterssNames[i])) continue;
		new string[125];
		format(string, sizeof(string), "Добро пожаловать на сервер, %s, Вы авторизовались как тестер", PI[playerid][PLAYER_Name]);
		SendClientMessage(playerid, COLOR_GREEN_L, string);
		break;
	}
	return 1;
}

forward LoadAccID(playerid);
public LoadAccID(playerid) return cache_get_value_name_int(0, "id", PI[playerid][PLAYER_ID]);

stock IsRPNick(const name[])
{
    static i, n;
    if('A' <= name[0] <= 'Z' && 'a' <= name[1] <= 'z')
    {
        for(i = 1, n = 0;;)
        {
            switch(name[++i])
            {
                case 'a'..'z': continue;
                case '_':
				{
                    if (n++, 'A' <= name[++i] <= 'Z' && 'a' <= name[++i] <= 'z') continue;
                    else break;
				}
                case '\0': return (i >= 4 && n == 1);
                default: return false;
            }
        }
    }
    return false;
}