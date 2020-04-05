#include <YSI_Coding/y_hooks>

static const TestersNames[][] = {

	{"Folinq_Weard"},
	{"Marshall_Mathers"},
	{"Roma_Omegov"},
	{"Bogdan_Swarovski"},
	{"Sergey_Sanchez"},
	{"Rich_Anderson"},
	{"Denis_Zona"},
	{"Igor_Belov"}
};

hook OnPlayerConnect(playerid) {
	new pname[25];
	GetPlayerName(playerid, pname, sizeof(pname));
	for(new __i; __i < sizeof(TestersNames); __i++) 
	{
		if(!strcmp(pname, TestersNames[__i]))
		{
			return 1;
		}
		continue;
	}
	return Kick(playerid);
}