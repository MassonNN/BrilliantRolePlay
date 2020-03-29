

enum 
{
	DIALOG_REG,
	DIALOG_LOG,
	DIALOG_SEX
}

public OnPlayerConnect(playerid)
{
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, sizeof(name));
    if(!IsRPNick(name))
    {
        SendClientMessage(playerid, 0xFFFFFFFF, !"Придумайте RolePlay никнейм");
        return Kick(playerid);
    }
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
        SetPlayerColor(playerid, 0xFFFFFFFF);
   	GetPlayerName(playerid, PI[playerid][PLAYER_Name], MAX_PLAYER_NAME);
	TogglePlayerSpectating(playerid, 1);
	if(PI[playerid][PLAYER_Logged] == 0)
	{
 		GetPlayerIp(playerid, PI[playerid][PLAYER_IP], 17);
	        new qString[120];
	        format(qString, sizeof(qString), "SELECT * FROM `accounts` WHERE `name` = '%s'", PI[playerid][PLAYER_Name]);
	        mysql_tquery(dbHandle, qString, "CheckAcc", "d", playerid);
	}
	return 1;
}

// IsRPNick(const name[])  // Я уже говорил о том, что не могу работать с новым компилятором
// {
//     static num_underscores, ptr;
//     emit
//     {
//         load.s.pri name
//         load.i
//         const.alt 'A'
//         jsless ret_false
//         const.alt 'Z'
//         jsgrtr ret_false
//         load.s.pri name
//         add.c (cellbits / charbits)
//         load.i
//         const.alt 'a'
//         jsless ret_false
//         const.alt 'z'
//         jsgrtr ret_false
//         zero num_underscores
//         load.s.pri name
//         add.c (cellbits / charbits * 2)
//         jump loop_entry
//     	loop:
//         load.pri ptr
//         add.c (cellbits / charbits)
//     	loop_entry:
//         stor.pri ptr
//         load.i
//         const.alt 'a'
//         jsless is_underscore
//         const.alt 'z'
//         jsleq loop
//     	is_underscore:
//         const.alt '_'
//         jneq is_term
//         inc num_underscores
//         load.pri ptr
//         add.c (cellbits / charbits)
//         load.i
//         const.alt 'A'
//         jsless ret_false
//         const.alt 'Z'
//         jsgrtr ret_false
//         load.pri ptr
//         add.c (cellbits / charbits * 2)
//         stor.pri ptr
//         load.i
//         const.alt 'a'
//         jsless ret_false
//         const.alt 'z'
//         jsleq loop
//         jump ret_false
//     	is_term:
//         jnz ret_false
//         load.pri ptr
//         load.s.alt name
//         sub
//         const.alt (cellbits / charbits * 4)
//         jsless ret_false
//         load.pri num_underscores
//         const.alt 1
//         eq
//         retn
//     	ret_false:
//     }
//     return false;
// }

forward CheckAcc(playerid);
public CheckAcc(playerid)
{
    	new rows;
	cache_get_row_count(rows);
    	if(!rows)
    	{
		SendClientMessage(playerid, 0xFFFFFFFF, !"Аккаунт есть!!");
        	ShowPlayerDialog(playerid, DIALOG_REG, DIALOG_STYLE_INPUT, !"Регистрация", !"{FFFFFF}Придумайте свой будущий пароль для аккаунта", !"Далее", !"Отмена");
    	}
    	else
    	{
		SendClientMessage(playerid, 0xFFFFFFFF, !"Аккаунта нету!!!");
     	    	ShowPlayerDialog(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"Авторизация", !"{FFFFFF}Введите пароль от аккаунта", !"Ок", "");
    	    	cache_get_value_name_int(0, "password", PI[playerid][PLAYER_Password]);
    	}
    	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
	    case DIALOG_REG:
	    {
	        if(!response) return ShowPlayerDialog(playerid, DIALOG_REG, DIALOG_STYLE_INPUT, !"Регистрация", !"Введите новый пароль для регистрации", !"Ок", "");
	        if(strlen(inputtext) < 6 || strlen(inputtext) > 32) return ShowPlayerDialog(playerid, DIALOG_REG, DIALOG_STYLE_INPUT, !"Регистрация", !"Введите новый пароль для регистрации", !"Ок", ""), SendClientMessage(playerid, 0xFFFFFFFF, !"Пароль должен состоять от 6-ти до 32-ух символов");
	        for(new i; i < strlen(inputtext); i++)
	        {
	            switch(inputtext[i])
	            {
	                case '0'..'9', 'a'..'z', 'A'..'Z': continue;
	                default: return ShowPlayerDialog(playerid, DIALOG_REG, DIALOG_STYLE_INPUT, !"Регистрация", !"Введите новый пароль для регистрации", !"Ок", ""), SendClientMessage(playerid, 0xFFFFFFFF, !"Пароль может содержать только латинские буквы и цифры");
	            }
	        }
	        format(PI[playerid][PLAYER_Password], 32, "%s", inputtext);
	        ShowPlayerDialog(playerid, DIALOG_SEX, DIALOG_STYLE_MSGBOX, !"Регистрация", !"Выберите пол персонажа", !"Мужской", "Женский");
		}
		case DIALOG_SEX:
		{
		    	if(response) PI[playerid][PLAYER_Sex] = 1;
		    	else PI[playerid][PLAYER_Sex] = 2;
		    	CreateAcc(playerid, PI[playerid][PLAYER_Password]);
		}
	    	case DIALOG_LOG:
	    	{
	        	if(!response) return ShowPlayerDialog(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"{FFFFFF}Авторизация", !"{FFFFFF}Введите свой пароль", !"Ок", "");
	        	if(strlen(inputtext) < 6 || strlen(inputtext) > 32) return ShowPlayerDialog(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"{FFFFFF}Авторизация", !"{FFFFFF}Пароль может состоять только от 6-ти до 32-ух латинских букв и цифр", !"Ок", "");
            		for(new i; i < strlen(inputtext); i++)
	        	{
	            		switch(inputtext[i])
	            		{
	               			case '0'..'9', 'a'..'z', 'A'..'Z': continue;
	               			default: return ShowPlayerDialog(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"{FFFFFF}Авторизация", !"{FFFFFF}Пароль может содержать только английские буквы или цифры", !"Ок", "");
	            		}
	        	}
	       		if(!strcmp(PI[playerid][PLAYER_Password], inputtext))
	       		{
				new qString[90];
            			format(qString, sizeof(qString), "SELECT * FROM `accounts` WHERE `name` = '%s'", PI[playerid][PLAYER_Name]);	            			
				mysql_tquery(dbHandle, qString, "LoadAcc", "d", playerid);
	        	}
	        	else
	        	{
				if(GetPVarInt(playerid, "BadAttempt") >= 3) return ShowPlayerDialog(playerid, 228, DIALOG_STYLE_MSGBOX, !"Кикнут", !"{FFFFFF}Вы ввели неверно пароль 3 раза и были кикнуты, {EC4646}/q {FFFFFF}для выхода", !"Далее", ""), Kick(playerid);
	            		new string[55];
	            		format(string, sizeof(string), "Вы ввели неверный пароль! У Вас осталось %d попытки", 3 - GetPVarInt(playerid, "BadAttempt"));
             			if(GetPVarInt(playerid, "BadAttempt") == 2)
             			{
             	    			ShowPlayerDialog(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"Авторизация", !"Введите свой пароль", !"Ок", ""), SCM(playerid, 0xFFFFFFFF, !"Вы ввели неверный пароль! У Вас осталась 1 попытка");
				}
				else
				{
                    			ShowPlayerDialog(playerid, DIALOG_LOG, DIALOG_STYLE_PASSWORD, !"Авторизация", !"Введите свой пароль", !"Ок", ""), SCM(playerid, 0xFFFFFFFF, string);
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


forward OnPlayerLogin(playerid);
public OnPlayerLogin(playerid)
{
    	PI[playerid][PLAYER_Logged] = true;
    	DeletePVar(playerid, "BadAttempt");
    	TogglePlayerSpectating(playerid, 0);
    	SpawnPlayer(playerid);
	return 1;
}

CreateAcc(playerid, password[])
{
	new qString[200], skin;
	if(PI[playerid][PLAYER_Sex] == 0)
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
	return 1;
}

forward LoadAccID(playerid);
hook LoadAccID(playerid) return cache_get_value_name_int(0, "id", PI[playerid][PLAYER_ID]);
