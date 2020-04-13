/* 
	GeoInfo v1.0
	(c) Copyright 2011, Makar
	
	Функции:
	GetPlayerCountry(playerid,country[]) - Страна
	GetPlayerCity(playerid,city[]) - Город
	GetPlayerProvider(playerid,provider[]) - Провайдер
	GetPlayerLongitude(playerid) - Долгота
	GetPlayerLatitude(playerid) - Широта
*/
#include a_http
#include a_samp


forward GeoResponse(index, response_code, data[]);
forward Geo_OnPlayerConnect(playerid);

public Geo_OnPlayerConnect(playerid)
{
	new string[128],ip[16];
	GetPlayerIp(playerid,ip,sizeof(ip));
	format(string,128,"ip-whois.net/ip_geo.php?ip=%s",ip);
	HTTP(playerid,HTTP_GET,string,"","GeoResponse");
}	

public GeoResponse(index, response_code, data[])
{
	if(response_code == 200)
	{
	    new ep = 0, sp = ep, stringNum = 0;
	    do
		{
		    ep = strfind(data, "\n", false, sp);
			if(-1 < ep < strlen(data))
			{
			    stringNum++;
			    if(stringNum == 27)
			    {
			        new temp[128],PlayerCountry[64];
			        strmid(temp,data,sp,ep);
			        strmid(PlayerCountry,temp,20,strfind(temp,"<br>",true)-4);
			        SetPVarString(index,"Country",PlayerCountry);
			    }
			    if(stringNum == 28)
			    {
			        new temp[128],PlayerCity[64];
			        strmid(temp,data,sp,ep);
			        strmid(PlayerCity,temp,62,strfind(temp,"\";",true)-2);
			        SetPVarString(index,"City",PlayerCity);
			    }
			}
		    sp = ep+1;
	    }
	    while(-1 < ep < strlen(data));
	}
	return;
}
stock GetPlayerCountry(playerid, country[64])
{
	GetPVarString(playerid, "Country", country, 64);
	return country;
}

stock GetPlayerCity(playerid, city[64])
{
	GetPVarString(playerid, "City", city, 64);
	return city;
}	