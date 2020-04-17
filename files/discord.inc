// DISCROD BOT PERFOMANCE ROLE PLAY


#include <../../files/discord-connector.inc>
#include <../../files/strlib.inc>

new DCC_Channel:p_Main;
new DCC_Channel:p_Admins;

#define D_Message(%0)	DCC_SendChannelMessage(%0)


stock FindSpecifiersInString(message[], array_size = sizeof(message))
{
    new message_length = strlen(message);
    for(new i; i < message_length; i++)
    {
        if(message[i] == '%')
        {
            if(message_length < array_size) strins(message, "%", i++, message_length++);
            else message[i] = '#';
        }
    }
} 


public OnGameModeInit()
{

	p_Admins = DCC_FindChannelById("647060066461286400");
	p_Main = DCC_FindChannelById("637650059445534720");
	
	switch(random(3)) {
		case 0: DCC_SetBotActivity("Playing on Brilliant Role Play");
		case 1: DCC_SetBotActivity("Plays CRMP");
		case 2: DCC_SetBotActivity("I Love Brilliants");
	}


    #if defined discord_OnGameModeInit
        return discord_OnGameModeInit();
    #else
        return 1;
    #endif
}
#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit discord_OnGameModeInit
#if defined discord_OnGameModeInit
    forward discord_OnGameModeInit();
#endif 

stock SendDiscordMessage(message[], DCC_Channel:Channel) {
	new newc[256];
	utf8encode(newc, message);
	D_Message(Channel, newc);
	return 1;
}

forward OnChannelMessage(DCC_Channel:Channel, DCC_User:Author, message[]);
public OnChannelMessage(DCC_Channel:Channel, DCC_User:Author, message[]) {
	return 1;
}

forward OnChannelCommand(DCC_Channel:Channel, DCC_User:Author, cmd[]);
public OnChannelCommand(DCC_Channel:Channel, DCC_User:Author, cmd[]) {

	new cmd_args[3][128];
	
	if(!sscanf(cmd, "'/toserver' s[127]", cmd_args[0])) {
		if(Channel == p_Admins) {
			new message[256];
			format(message, 256, "%s", cmd_args);
			new username[32];
			DCC_GetUserName(Author, username);
			new tmp_message[256];
			format(tmp_message, 256, "%s", message);
			
			format(message, sizeof(message), "%s: %s", username, tmp_message);
			SendClientMessageToAll(-1, message);
			return 1;
		}
	} 
	return 0;
}


public OnPlayerConnect(playerid)
{
    
	new string[126], name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, MAX_PLAYER_NAME);
	format(string, 126, "Player %s joined to the server!", name);
	D_Message(p_Admins, string);

    #if defined discord_OnPlayerConnect
        return discord_OnPlayerConnect(playerid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect discord_OnPlayerConnect
#if defined discord_OnPlayerConnect
    forward discord_OnPlayerConnect(playerid);
#endif 

public DCC_OnMessageCreate(DCC_Message:message) {

	new DCC_Channel:channel;
	DCC_GetMessageChannel(message, channel);
	new DCC_User:Author;
	DCC_GetMessageAuthor(message, Author);
	new content[256];
	DCC_GetMessageContent(message, content);
	FindSpecifiersInString(content);

	if(strfind(content, "/") != -1) OnChannelMessage(channel, Author, content);
	else if(strfind(content, "/") < 1) OnChannelCommand(channel, Author, content);
	else OnChannelMessage(channel, Author, content);

	// if(channel == p_Admins) {
	// 	new dcc_pos = strfind(content, "toserver", true);
	// 	if(dcc_pos != -1) {
	// 		new DCC_User:author;
	// 		DCC_GetMessageAuthor(DCC_Message:message, author);
	// 		new _message[256];
	// 		format(_message, 256, "%s", content);
	// 		strdel(_message, dcc_pos, dcc_pos+8);
	// 		new username[32];
	// 		DCC_GetUserName(author, username);
	// 		new tmp_message[256];
	// 		format(tmp_message, 256, "%s", _message);
			
	// 		format(_message, sizeof(_message), "%s: %s", username, tmp_message);
	// 		SendClientMessageToAll(-1, _message);
	// 		return 1;
	// 	}
	// }
	return 0;

}

// public DCC_OnChannelMessage(DCC_Channel:channel, DCC_User:author, const message[]) {
// 	if(channel == pAdmins) {
// 		new dcc_pos = strfind(message, "toserver", true);
// 		if(dcc_pos != -1) {
// 			new _message[sizeof(message) + 27] = message;
// 			strdel(_message, dcc_pos, dcc_pos+8);
// 			new username[32];
// 			DCC_GetUserName(author, username);
// 			new tmp_message[sizeof(_message)] = _message;
// 			format(_message, sizeof(_message), "{FFCC00}%s:{FFFFFF} %s", username, tmp_message);
// 			SendClientMessageToAll(-1, _message);
// 			return 1;
// 		}
// 	}
// }