// Система объектов

#define MAX_DYN_OBJECTS 100

enum dynObject {
	Float:dyn_X,
	Float:dyn_Y,
	Float:dyn_Z,
	dyn_Creator
};

new dynObjectInfo[MAX_DYN_OBJECTS][dynObject];
new totalDynObjects;

cmd:create(playerid, params[]) {

	if(CheckAdmin(playerid, 7)) return 0;
	new modelid;
	if(sscanf(params, "dd", modelid)) return SendErr(playerid, "Использование: /create [id модели] (0 - обычный объект, 1 - объект игрока, 2 - объект машины)");
	//CreateDynamicObject(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, \
	interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_OBJECT_SD, Float:drawdistance = STREAMER_OBJECT_DD, \
	STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1)
	

	return 1;
}