static const TestersNames[][] = {

	{"Folinq_Weard"},
	{"Marshall_Mathers"},
	{"Roma_Omegov"},
	{"Bogdan_Swarovski"},
	{"Sergey_Sanchez"},
	{"Rich_Anderson"}
};

/*hook OnPlayerConnect(playerid) {
	new pname[25];
	GetPlayerName(playerid, pname, sizeof(pname));
	for(new __i; __i < sizeof(TestersNames); __i++) 
	{
		if(!strcmp(pname, TestersNames[i]))
		{
			return 1;
		}
		continue;
	}
	Kick(playerid);
	return 1;
}/*