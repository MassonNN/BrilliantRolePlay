/*
    Fly Camera (flycam.inc)
    * This is a modified version of SAMP flymode filterscript. Much better, fast, bug free and with few options.
	Author: (creator)
 	* Gammix
	Contributors:
 	* Scott - Original flymode filterscript
 	* Incognito - Streamer plugin
	(c) Copyright 2015
 	* This file is provided as is (no warranties).
*/
/*
STOCKS:
native SetPlayerCamera(playerid, type = 1);
native SetPlayerCameraSpeed(playerid, Float:speed);
native Float: GetPlayerCameraSpeed(playerid);
CALLBACKS:
public OnPlayerCameraUpdate(playerid, Float:oldx, Float:oldy, Float:oldz, olddir, Float:newx, Float:newy, Float:newz, newdir)
*/

#include <streamer>
#include <YSI_Coding/y_hooks>

#define MOVE_FORWARD    		(1)
#define MOVE_BACK       		(2)
#define MOVE_LEFT       		(3)
#define MOVE_RIGHT      		(4)
#define MOVE_FORWARD_LEFT       (5)
#define MOVE_FORWARD_RIGHT      (6)
#define MOVE_BACK_LEFT          (7)
#define MOVE_BACK_RIGHT         (8)

enum {
	DIALOG_NNN = 20000,
}

new Float:SP[3];

enum e_PLAYER_FLY_MODE {
				flyType,
				flyObject,
				flyDirection,
				flyKeys[2],
				flyTick,
				ReturnAttempt,
	Float:		flyMovementSpeed
};
static
	g_FlyMode[MAX_PLAYERS][e_PLAYER_FLY_MODE]
;

public OnPlayerConnect(playerid) {
    g_FlyMode[playerid][flyType] = 0;
    g_FlyMode[playerid][flyObject] = INVALID_OBJECT_ID;
    g_FlyMode[playerid][flyDirection] = 0;
    g_FlyMode[playerid][flyKeys][0] = 0;
    g_FlyMode[playerid][flyKeys][1] = 0;
    g_FlyMode[playerid][flyTick] = 0;
    g_FlyMode[playerid][flyMovementSpeed] = 10.0;
    g_FlyMode[playerid][ReturnAttempt] = 0;

	#if defined Cam_OnPlayerConnect
		return Cam_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Cam_OnPlayerConnect
#if defined Cam_OnPlayerConnect
	forward Cam_OnPlayerConnect(playerid);
#endif

stock MovePlayerCamera(playerid, const Float:CP[3], const Float:FV[3]) {
	new
	    Float:NP[3]
	;
	
	#define OFFSET_X (FV[0]*1000.0)
	#define OFFSET_Y (FV[1]*1000.0)
	#define OFFSET_Z (FV[2]*1000.0)
	switch(g_FlyMode[playerid][flyDirection]) {
		case MOVE_FORWARD: {
			NP[0] = CP[0]+OFFSET_X;
			NP[1] = CP[1]+OFFSET_Y;
			NP[2] = CP[2]+OFFSET_Z;
		}
		case MOVE_BACK: {
			NP[0] = CP[0]-OFFSET_X;
			NP[1] = CP[1]-OFFSET_Y;
			NP[2] = CP[2]-OFFSET_Z;
		}
		case MOVE_LEFT: {
			NP[0] = CP[0]-OFFSET_Y;
			NP[1] = CP[1]+OFFSET_X;
			NP[2] = CP[2];
		}
		case MOVE_RIGHT: {
			NP[0] = CP[0]+OFFSET_Y;
			NP[1] = CP[1]-OFFSET_X;
			NP[2] = CP[2];
		}
		case MOVE_BACK_LEFT: {
			NP[0] = CP[0]+(-OFFSET_X - OFFSET_Y);
 			NP[1] = CP[1]+(-OFFSET_Y + OFFSET_X);
		 	NP[2] = CP[2]-OFFSET_Z;
		}
		case MOVE_BACK_RIGHT: {
			NP[0] = CP[0]+(-OFFSET_X + OFFSET_Y);
 			NP[1] = CP[1]+(-OFFSET_Y - OFFSET_X);
		 	NP[2] = CP[2]-OFFSET_Z;
		}
		case MOVE_FORWARD_LEFT: {
			NP[0] = CP[0]+(OFFSET_X  - OFFSET_Y);
			NP[1] = CP[1]+(OFFSET_Y  + OFFSET_X);
			NP[2] = CP[2]+OFFSET_Z;
		}
		case MOVE_FORWARD_RIGHT: {
			NP[0] = CP[0]+(OFFSET_X  + OFFSET_Y);
			NP[1] = CP[1]+(OFFSET_Y  - OFFSET_X);
			NP[2] = CP[2]+OFFSET_Z;
		}
	}

	MoveDynamicObject(g_FlyMode[playerid][flyObject], NP[0], NP[1], NP[2], g_FlyMode[playerid][flyMovementSpeed]);

	g_FlyMode[playerid][flyTick] = GetTickCount();
}

public OnPlayerUpdate(playerid) {
	if (g_FlyMode[playerid][flyType] == 1) {
		new
			keys,
			ud,
			lr
		;
		GetPlayerKeys(playerid, keys, ud, lr);

		new
			Float:CP[3],
			Float:FV[3],
			olddir = g_FlyMode[playerid][flyDirection]
		;
		GetPlayerCameraPos(playerid, CP[0], CP[1], CP[2]);
		GetPlayerCameraFrontVector(playerid, FV[0], FV[1], FV[2]);

		if (g_FlyMode[playerid][flyKeys][0] != ud || g_FlyMode[playerid][flyKeys][1] != lr) {
		    if ((g_FlyMode[playerid][flyKeys][0] != 0 || g_FlyMode[playerid][flyKeys][1] != 0) && ud == 0 && lr == 0) {
		        StopDynamicObject(g_FlyMode[playerid][flyObject]);

                g_FlyMode[playerid][flyDirection] = 0;
		    }
		    else {
			    if(lr < 0) {
					if(ud < 0) {
						g_FlyMode[playerid][flyDirection] = MOVE_FORWARD_LEFT;
					}
					else if(ud > 0) {
						g_FlyMode[playerid][flyDirection] = MOVE_BACK_LEFT;
					}
					else {
						g_FlyMode[playerid][flyDirection] = MOVE_LEFT;
					}

					MovePlayerCamera(playerid, CP, FV);
				}
				else if(lr > 0) {
					if(ud < 0) {
						g_FlyMode[playerid][flyDirection] = MOVE_FORWARD_RIGHT;
					}
					else if(ud > 0) {
						g_FlyMode[playerid][flyDirection] = MOVE_BACK_RIGHT;
					}
					else {
						g_FlyMode[playerid][flyDirection] = MOVE_RIGHT;
					}

					MovePlayerCamera(playerid, CP, FV);
				}
				else if(ud < 0) {
					g_FlyMode[playerid][flyDirection] = MOVE_FORWARD;

					MovePlayerCamera(playerid, CP, FV);
				}
				else if(ud > 0) {
					g_FlyMode[playerid][flyDirection] = MOVE_BACK;

					MovePlayerCamera(playerid, CP, FV);
				}
				else {
                    g_FlyMode[playerid][flyDirection] = -1;
				}
		    }

		    g_FlyMode[playerid][flyKeys][0] = ud;
			g_FlyMode[playerid][flyKeys][1] = lr;
		}
		else if (g_FlyMode[playerid][flyDirection] && (GetTickCount() - g_FlyMode[playerid][flyTick] > 100)) {
		    if ((g_FlyMode[playerid][flyKeys][0] != 0 || g_FlyMode[playerid][flyKeys][1] != 0) && ud == 0 && lr == 0) {
                StopDynamicObject(g_FlyMode[playerid][flyObject]);

                g_FlyMode[playerid][flyDirection] = 0;
			}
			else {
				MovePlayerCamera(playerid, CP, FV);
			}
		}

		if (funcidx("OnPlayerCameraUpdate") != -1) {
		    new
				Float:NP[3]
			;
			GetPlayerCameraPos(playerid, NP[0], NP[1], NP[2]);
			
			CallLocalFunction("OnPlayerCameraUpdate", "ifffifffi", playerid, CP[0], CP[1], CP[2], olddir, NP[0], NP[1], NP[2], g_FlyMode[playerid][flyDirection]);
		}
	}

	#if defined Cam_OnPlayerUpdate
		return Cam_OnPlayerUpdate(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate Cam_OnPlayerUpdate
#if defined Cam_OnPlayerUpdate
	forward Cam_OnPlayerUpdate(playerid);
#endif

stock SetPlayerCamera(playerid, type = 1) {
	switch (type) {
		case 1,2: {
			TogglePlayerSpectating(playerid, true);
			GetPlayerPos(playerid, SP[0], SP[1], SP[2]);
			g_FlyMode[playerid][flyObject] = CreateDynamicObject(19300, SP[0], SP[1], SP[2], 0.0, 0.0, 0.0, .playerid = playerid);
			AttachCameraToDynamicObject(playerid, g_FlyMode[playerid][flyObject]);

			g_FlyMode[playerid][flyType] = type;

		    g_FlyMode[playerid][flyDirection] = 0;
		    g_FlyMode[playerid][flyKeys][0] = 0;
		    g_FlyMode[playerid][flyKeys][1] = 0;
		    g_FlyMode[playerid][flyTick] = 0;

		    SetTimerEx("OnFlySpeedUpdate", 250, false, "d", playerid);
		}

	    default: {

			ShowPlayerDialog(playerid, DIALOG_NNN, DIALOG_STYLE_MSGBOX, !"Полёт", !"{FFFFFF}Где хотите появится относительно полёта?", !"В начале", !"В конце");

			DestroyDynamicObject(g_FlyMode[playerid][flyObject]);
		    g_FlyMode[playerid][flyObject] = INVALID_OBJECT_ID;

			g_FlyMode[playerid][flyType] = 0;
		}
	}
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_NNN:
		{
			TogglePlayerSpectating(playerid, false);
			if(response)
			{
				SetTimerEx("Possss", 300, false, "dd", playerid, 0);
			}
			else
			{
				SetTimerEx("Possss", 300, false, "dd", playerid, 1);
			}
		}
	}
	return 1;
}

callback:Possss(playerid, type)
{
	if(type == 1) 
	{
		new Float:CP[3];
		GetPlayerCameraPos(playerid, CP[0], CP[1], CP[2]);
		SetPlayerPos(playerid, CP[0], CP[1], CP[2]);
	}
	else SetPlayerPos(playerid, SP[0], SP[1], SP[2]);
}

stock SetPlayerCameraSpeed(playerid, Float:speed) {
    g_FlyMode[playerid][flyMovementSpeed] = speed;

	return true;
}

stock Float:GetPlayerCameraSpeed(playerid) {
    return g_FlyMode[playerid][flyMovementSpeed];
}

stock Cam_SetPlayerCameraPos(playerid, Float:x, Float:y, Float:z) {
	if (g_FlyMode[playerid][flyType] != 0) {
	    new
	        iFlyType = g_FlyMode[playerid][flyType]
		;
		g_FlyMode[playerid][flyType] = 0;

		StopDynamicObject(g_FlyMode[playerid][flyObject]);	
		SetDynamicObjectPos(g_FlyMode[playerid][flyObject], x, y, z);
		
		g_FlyMode[playerid][flyType] = iFlyType;
		
		return true;
	}
	else {
		return SetPlayerCameraPos(playerid, x, y, z);
	}
}
#if defined _ALS_SetPlayerCameraPos
	#undef SetPlayerCameraPos
#else
	#define _ALS_SetPlayerCameraPos
#endif
#define SetPlayerCameraPos Cam_SetPlayerCameraPos

stock Cam_SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z) {
	if (g_FlyMode[playerid][flyType] != 0) {
	    new
	        iFlyType = g_FlyMode[playerid][flyType]
		;
		g_FlyMode[playerid][flyType] = 0;

		SetPlayerCameraLookAt(playerid, x, y, z);
		
		g_FlyMode[playerid][flyType] = iFlyType;
		
		return 1;
	}
	return SetPlayerCameraLookAt(playerid, x, y, z);
}
#if defined _ALS_SetPlayerCameraLookAt
	#undef SetPlayerCameraLookAt
#else
	#define _ALS_SetPlayerCameraLookAt
#endif
#define SetPlayerCameraLookAt Cam_SetPlayerCameraLookAt

forward OnPlayerCameraUpdate(playerid, Float:oldx, Float:oldy, Float:oldz, olddir, Float:newx, Float:newy, Float:newz, newdir);

callback:OnFlySpeedUpdate(playerid) {
	if(g_FlyMode[playerid][flyType] != 0) 
	{
		new UpDown, Keys, LeftRight;
		GetPlayerKeys(playerid, Keys, UpDown, LeftRight);
		if(UpDown == KEY_UP || UpDown == KEY_DOWN || LeftRight == KEY_RIGHT|| LeftRight == KEY_LEFT)
		{
			g_FlyMode[playerid][ReturnAttempt] = 0;
			if(g_FlyMode[playerid][flyMovementSpeed] < 50.0) g_FlyMode[playerid][flyMovementSpeed] *= 1.08;
		}
		else 
		{
			if(g_FlyMode[playerid][ReturnAttempt] == 0)
			{
				callcmd::fly(playerid);
				g_FlyMode[playerid][ReturnAttempt]++;
			}
			else
			{
				g_FlyMode[playerid][flyMovementSpeed] = 10.0;
			}
		}
		SetTimerEx("OnFlySpeedUpdate", 250, false, "d", playerid);
	}
	return 1;
}