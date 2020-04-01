// v.01.02


#define MAX_BANK_ACCOUNTS 	10
#define MAX_PLAYER_VEHICLES	3
#define MAX_BUSINESSES		3
#define MAX_FRACS	10


// SEX
#define MAN					1
#define WOMAN				2
#define NOT_SET				0

enum PLAYER_Stats {

	PLAYER_ID,
	PLAYER_Name[MAX_PLAYER_NAME],
	PLAYER_IP[17], 
	PLAYER_Sex, 	
	PLAYER_Skin,					
	PLAYER_Money, 					
	PLAYER_BankMoney[MAX_BANK_ACCOUNTS], 
	PLAYER_Level, 					
	PLAYER_Exp, 					
	PLAYER_MuteTime, 				
	PLAYER_BanTime, 				
	PLAYER_Warns, 					
	PLAYER_Reputation, 				
	PLAYER_Age, 					
	PLAYER_Admin,					
	PLAYER_Logged,					
	PLAYER_Language,				

}; 

new PI[MAX_PLAYERS][PLAYER_Stats];

enum PLAYER_Licenses {

	PLAYER_LIC_CAR_EXP_TIME, 		
	PLAYER_LIC_FLY_EXP_TIME, 		
	PLAYER_LIC_WATER_EXP_TIME, 		
	PLAYER_LIC_GUN_EXP_TIME 		
};

new PL[MAX_PLAYERS][PLAYER_Licenses];


enum PLAYER_Property { 

	PLAYER_House,					
	PLAYER_Vehicle[MAX_PLAYER_VEHICLES],
	PLAYER_Model,					
	PLAYER_Business[MAX_BUSINESSES] 
}; 

new PP[MAX_PLAYERS][PLAYER_Property];



enum PLAYER_Organization { 

	PLAYER_Fraction,				
	PLAYER_Rank,					
	PLAYER_FracWarns,				
	PLAYER_TimeInFrac[MAX_FRACS],	
	PLAYER_FracModel				
};

new PO[MAX_PLAYERS][PLAYER_Organization]; 

//Прочее

new AVeh[MAX_PLAYERS];

new VehicleName[][] ={
    "Landstalker", "Bravura", "Buffalo", "Linerunner", "Perrenial", "Sentinel",
    "Dumper", "Firetruck", "Trashmaster", "Stretch", "Manana", "Infernus",
    "Voodoo", "Pony", "Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam",
    "Esperanto", "Taxi", "Washington", "Bobcat", "Whoopee", "BF Injection",
    "Hunter", "Premier", "Enforcer", "Securicar", "Banshee", "Predator", "Bus",
    "Rhino", "Barracks", "Hotknife", "Trailer", "Previon", "Coach", "Cabbie",
    "Stallion", "Rumpo", "RC Bandit", "Romero", "Packer", "Monster", "Admiral",
    "Squalo", "Seasparrow", "Pizzaboy", "Tram", "Trailer", "Turismo", "Speeder",
    "Reefer", "Tropic", "Flatbed", "Yankee", "Caddy", "Solair", "Berkley's RC Van",
    "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider", "Glendale",
    "Oceanic","Sanchez", "Sparrow", "Patriot", "Quad", "Coastguard", "Dinghy",
    "Hermes", "Sabre", "Rustler", "ZR-350", "Walton", "Regina", "Comet", "BMX",
    "Burrito", "Camper", "Marquis", "Baggage", "Dozer", "Maverick", "News Chopper",
    "Rancher", "FBI Rancher", "Virgo", "Greenwood", "Jetmax", "Hotring", "Sandking",
    "Blista Compact", "Police Maverick", "Boxvillde", "Benson", "Mesa", "RC Goblin",
    "Hotring RacerA", "Hotring RacerB", "Bloodring Banger", "Rancher", "Super GT",
    "Elegant", "Journey", "Bike", "Mountain Bike", "Beagle", "Cropduster", "Stunt",
    "Tanker", "Roadtrain", "Nebula", "Majestic", "Buccaneer", "Shamal", "Hydra",
    "FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck", "Fortune",
    "Cadrona", "FBI Truck", "Willard", "Forklift", "Tractor", "Combine", "Feltzer",
    "Remington", "Slamvan", "Blade", "Freight", "Streak", "Vortex", "Vincent",
    "Bullet", "Clover", "Sadler", "Firetruck", "Hustler", "Intruder", "Primo",
    "Cargobob", "Tampa", "Sunrise", "Merit", "Utility", "Nevada", "Yosemite",
    "Windsor", "Monster", "Monster", "Uranus", "Jester", "Sultan", "Stratium",
    "Elegy", "Raindance", "RC Tiger", "Flash", "Tahoma", "Savanna", "Bandito",
    "Freight Flat", "Streak Carriage", "Kart", "Mower", "Dune", "Sweeper",
    "Broadway", "Tornado", "AT-400", "DFT-30", "Huntley", "Stafford", "BF-400",
    "News Van", "Tug", "Trailer", "Emperor", "Wayfarer", "Euros", "Hotdog", "Club",
    "Freight Box", "Trailer", "Andromada", "Dodo", "RCCam", "Launch", "Police Car",
    "Police Car", "Police Car", "Police Ranger", "Picador", "S.W.A.T", "Alpha",
    "Phoenix", "Glendale", "Sadler", "Luggage", "Luggage", "Stairs", "Boxville",
    "Tiller", "Utility Trailer"
};

SSCANF:vehiclemodel(model_name[])
{
    if ('0' <= model_name[0] <= '9')
    {
        new model;
    #if !defined sscanf
        for(new i = strlen(model_name)-1; i != -1; i--)
        {
            switch(model_name[i])
            {
                case '0'..'9':
                {
                    continue;
                }
                default:
                {
                    model = -1;
                    break;
                }
            }
        }
        if(model != -1)
        {
            model = strval(model_name);
        }
    #else
        sscanf(model_name, "i", model);
    #endif
        if(400 <= model <= 611)
        {
            return model;
        }
    }
    static const sVehicleModelName[212][] =
    {
        {!"Landstalker"}, {!"Bravura"}, {!"Buffalo"}, {!"Linerunner"}, {!"Perennial"},
        {!"Sentinel"}, {!"Dumper"}, {!"Fire Truck"}, {!"Trashmaster"}, {!"Stretch"},
        {!"Manana"}, {!"Infernus"}, {!"Voodoo"}, {!"Pony"}, {!"Mule"}, {!"Cheetah"},
        {!"Ambulance"}, {!"Leviathan"}, {!"Moonbeam"}, {!"Esperanto"}, {!"Taxi"},
        {!"Washington"}, {!"Bobcat"}, {!"Mr.Whoopee"}, {!"BF Injection"}, {!"Hunter"},
        {!"Premier"}, {!"Enforcer"}, {!"Securicar"}, {!"Banshee"}, {!"Predator"}, {!"Bus"},
        {!"Rhino"}, {!"Barracks"}, {!"Hotknife"}, {!"Article Trailer 1"}, {!"Previon"},
        {!"Coach"}, {!"Cabbie"}, {!"Stallion"}, {!"Rumpo"}, {!"RC Bandit"}, {!"Romero"},
        {!"Packer"}, {!"Monster"}, {!"Admiral"}, {!"Squalo"}, {!"Seasparrow"}, {!"Pizzaboy"},
        {!"Tram"}, {!"Article Trailer 2"}, {!"Turismo"}, {!"Speeder"}, {!"Reefer"},
        {!"Tropic"}, {!"Flatbed"}, {!"Yankee"}, {!"Caddy"}, {!"Solair"}, {!"Berkleys RC Van"},
        {!"Skimmer"}, {!"PCJ-600"}, {!"Faggio"}, {!"Freeway"}, {!"RC Baron"}, {!"RC Raider"},
        {!"Glendale"}, {!"Oceanic"}, {!"Sanchez"}, {!"Sparrow"}, {!"Patriot"}, {!"Quadbike"},
        {!"Coastguard"}, {!"Dinghy"}, {!"Hermes"}, {!"Sabre"}, {!"Rustler"}, {!"ZR-350"},
        {!"Walton"}, {!"Regina"}, {!"Comet"}, {!"BMX"}, {!"Burrito"}, {!"Camper"},
        {!"Marquis"}, {!"Baggage"}, {!"Dozer"}, {!"Maverick"}, {!"News Chopper"},
        {!"Rancher"}, {!"FBI Rancher"}, {!"Virgo"}, {!"Greenwood"}, {!"Jetmax"},
        {!"Hotring Racer"}, {!"Sandking"}, {!"Blista Compact"}, {!"Police Maverick"},
        {!"Boxville"}, {!"Benson"}, {!"Mesa"}, {!"RC Goblin"}, {!"Hotring Racer (A)"},
        {!"Hotring Racer (B)"}, {!"Bloodring Banger"}, {!"Rancher 2"},
        {!"Super GT"}, {!"Elegant"}, {!"Journey"}, {!"Bike"}, {!"Mountain Bike"},
        {!"Beagle"}, {!"Cropduster"}, {!"Stuntplane"}, {!"Tanker"}, {!"Roadtrain"},
        {!"Nebula"}, {!"Majestic"}, {!"Buccaneer"}, {!"Shamal"}, {!"Hydra"}, {!"FCR-900"},
        {!"NRG-500"}, {!"HPV1000"}, {!"Cement Truck"}, {!"Towtruck"}, {!"Fortune"}, {!"Cardona"},
        {!"FBI Truck"}, {!"Willard"}, {!"Forklift"}, {!"Tractor"}, {!"Combine Harvester"},
        {!"Feltzer"}, {!"Remington"}, {!"Slamvan"}, {!"Blade"}, {!"Freight"}, {!"Brown Streak"},
        {!"Vortex"}, {!"Vincent"}, {!"Bullet"}, {!"Clover"}, {!"Sadler"}, {!"Fire Truck 2"},
        {!"Hustler"}, {!"Intruder"}, {!"Primo"}, {!"Cargobob"}, {!"Tampa"}, {!"Sunrise"},
        {!"Merit"}, {!"Utility Van"}, {!"Nevada"}, {!"Yosemite"}, {!"Windsor"}, {!"Monster (A)"},
        {!"Monster (B)"}, {!"Uranus"}, {!"Jester"}, {!"Sultan"}, {!"Stratum"}, {!"Elegy"},
        {!"Raindance"}, {!"RC Tiger"}, {!"Flash"}, {!"Tahoma"}, {!"Savanna"}, {!"Bandito"},
        {!"Freight"}, {!"Brown Streak"}, {!"Kart"}, {!"Mower"}, {!"Dune"}, {!"Sweeper"},
        {!"Broadway"}, {!"Tornado"}, {!"AT-400"}, {!"DFT-30"}, {!"Huntley"}, {!"Stafford"},
        {!"BF-400"}, {!"Newsvan"}, {!"Tug"}, {!"Petrol Truck"}, {!"Emperor"}, {!"Wayfarer"},
        {!"Euros"}, {!"Hotdog"}, {!"Club"}, {!"Freight Box"}, {!"Article Trailer 3"}, {!"Andromada"},
        {!"Dodo"}, {!"RC Cam"}, {!"Launch"}, {!"Police (LSPD)"}, {!"Police (SFPD)"}, {!"Police (LVPD)"},
        {!"Ranger"}, {!"Picador"}, {!"S.W.A.T."}, {!"Alpha"}, {!"Phoenix"}, {!"Glendale 2"},
        {!"Sadler 2"}, {!"Baggage Box A"}, {!"Baggage Box B"}, {!"Stairs Trailer"}, {!"Boxville 2"},
        {!"Farm Trailer"}, {!"Utility Trailer"}
    };
    for(new i = 0; i < sizeof(sVehicleModelName); i++)
    {
        if(!strcmp(sVehicleModelName[i], model_name, true))
            return i+400;
    }

    for(new i = 0; i < sizeof(sVehicleModelName); i++)
    {
        if(strfind(sVehicleModelName[i], model_name, true) != -1)
            return i+400;
    }
    return INVALID_VEHICLE_ID;
}