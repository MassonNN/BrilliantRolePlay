#define WIDTH_TD 1920.0//ширина td
#define HEIGHT_TD 1080.0//высота td

#define TD_CLARITY_MAX 0
#define TD_CLARITY_MIN 255

#define BACKGROUND_HIDDEN 0//background скрыт
#define BACKGROUND_HIDE 1//background скрывается
#define BACKGROUND_SHOWN 2//background показан
#define BACKGROUND_SHOW 3//background показывается

forward ShowBackgroundForPlayer(playerid, backid);//функция показа td
forward HideBackgroundForPlayer(playerid, backid);//функция скрытия td

forward SmoothlyShowBackground(playerid, backid);//скрипт плавного показа background
forward SmoothlyHideBackground(playerid, backid);//скрипт плавного скрытия background

forward OnPlayerBackgroundShown(playerid, backid);//callback когда background показан полностью
forward OnPlayerBackgroundHidden(playerid, backid);//callback когда background скрыт полностью
forward OnPlayerBackgroundShow(playerid, backid);//callback когда background начал показываться
forward OnPlayerBackgroundHide(playerid, backid);//callback когда background начал скрываться

const TIMER_INTERVAL = 5;//интенсивность показа/скрытия background
const GRADATION_COLOR = 1;//шаг смены цвета (чем меньше, тем плавнее). Минимум 1, максимум 255 (мгновенно)

enum PLAYER_BACKGROUND
{
    PlayerText:bg_td,

    bg_status,
    bg_color,

    bg_timer,
}
new pBG[MAX_PLAYERS][PLAYER_BACKGROUND];

public ShowBackgroundForPlayer(playerid, backid)
{
    if(pBG[playerid][bg_status] != BACKGROUND_HIDDEN) return 0;

    CreateBackgroundForPlayer(playerid, pBG[playerid][bg_td]);

    pBG[playerid][bg_status] = BACKGROUND_SHOW;
    pBG[playerid][bg_timer] = SetTimerEx("SmoothlyShowBackground", TIMER_INTERVAL, true, "ii", playerid, backid);

    return CallLocalFunction("OnPlayerBackgroundShow", "ii", playerid, backid);
}

public HideBackgroundForPlayer(playerid, backid)
{
    if(pBG[playerid][bg_status] != BACKGROUND_SHOWN) return 0;

    pBG[playerid][bg_status] = BACKGROUND_HIDE;
    pBG[playerid][bg_timer] = SetTimerEx("SmoothlyHideBackground", TIMER_INTERVAL, true, "ii", playerid, backid);

    return CallLocalFunction("OnPlayerBackgroundHide", "ii", playerid, backid);
}

public SmoothlyShowBackground(playerid, backid)
{
    if(pBG[playerid][bg_color] != TD_CLARITY_MIN)
    {
        pBG[playerid][bg_color] += GRADATION_COLOR;

        if(pBG[playerid][bg_color] > TD_CLARITY_MIN) pBG[playerid][bg_color] = TD_CLARITY_MIN;

        PlayerTextDrawColor(playerid, pBG[playerid][bg_td], pBG[playerid][bg_color]);
        return PlayerTextDrawShow(playerid, pBG[playerid][bg_td]);
    }
    else
    {
        pBG[playerid][bg_status] = BACKGROUND_SHOWN;
        KillTimer(pBG[playerid][bg_timer]);

        return CallLocalFunction("OnPlayerBackgroundShown", "ii", playerid, backid);
    }
}

public SmoothlyHideBackground(playerid, backid)
{
    if(pBG[playerid][bg_color] != TD_CLARITY_MAX)
    {
        pBG[playerid][bg_color] -= GRADATION_COLOR;

        if(pBG[playerid][bg_color] < TD_CLARITY_MAX) pBG[playerid][bg_color] = TD_CLARITY_MAX;

        PlayerTextDrawColor(playerid, pBG[playerid][bg_td], pBG[playerid][bg_color]);
        return PlayerTextDrawShow(playerid, pBG[playerid][bg_td]);
    }
    else
    {
        PlayerTextDrawDestroy(playerid, pBG[playerid][bg_td]);

        pBG[playerid][bg_status] = BACKGROUND_HIDDEN;
        KillTimer(pBG[playerid][bg_timer]);

        return CallLocalFunction("OnPlayerBackgroundHidden", "ii", playerid, backid);
    }
}

stock CreateBackgroundForPlayer(playerid, PlayerText:textdraw)
{
    pBG[playerid][bg_color] = 0x00000000;

    textdraw = CreatePlayerTextDraw(playerid, -WIDTH_TD/2, -HEIGHT_TD/2, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, textdraw, WIDTH_TD, HEIGHT_TD);
    PlayerTextDrawAlignment(playerid, textdraw, 1);
    PlayerTextDrawColor(playerid, textdraw, 0x00000000);
    PlayerTextDrawFont(playerid, textdraw, 4);
    PlayerTextDrawSetProportional(playerid, textdraw, 0);
    PlayerTextDrawSetShadow(playerid, textdraw, 0);

    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	PlayerTextDrawDestroy(playerid, pBG[playerid][bg_td]);

    pBG[playerid][bg_status] = 0;
    pBG[playerid][bg_color] = 0;

    KillTimer(pBG[playerid][bg_timer]);

    #if defined BCKGRND_OnPlayerDisconnect
        return BCKGRND_OnPlayerDisconnect(playerid, reason);
    #else
        return 1;
    #endif
}

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect BCKGRND_OnPlayerDisconnect
#if defined BCKGRND_OnPlayerDisconnect
forward BCKGRND_OnPlayerDisconnect(playerid, reason);
#endif