// Textdraws Perfomance Role Play


//==============================================================================
stock LoadTextDraws()
{    
    HungerBackground[0] = TextDrawCreate(547.500000, 58.000000, "_");
	TextDrawBackgroundColor(HungerBackground[0], 255);
	TextDrawFont(HungerBackground[0], 1);
	TextDrawLetterSize(HungerBackground[0], 0.500000, 0.399999);
	TextDrawColor(HungerBackground[0], -1);
	TextDrawSetOutline(HungerBackground[0], 0);
	TextDrawSetProportional(HungerBackground[0], 1);
	TextDrawSetShadow(HungerBackground[0], 1);
	TextDrawUseBox(HungerBackground[0], 1);
	TextDrawBoxColor(HungerBackground[0], 255);
	TextDrawTextSize(HungerBackground[0], 606.000000, 40.000000);
	TextDrawSetSelectable(HungerBackground[0], 0);

	HungerBackground[1] = TextDrawCreate(549.500000, 60.000000, "_");
	TextDrawBackgroundColor(HungerBackground[1], 255);
	TextDrawFont(HungerBackground[1], 1);
	TextDrawLetterSize(HungerBackground[1], 0.490000, -0.000000);
	TextDrawColor(HungerBackground[1], -1);
	TextDrawSetOutline(HungerBackground[1], 0);
	TextDrawSetProportional(HungerBackground[1], 1);
	TextDrawSetShadow(HungerBackground[1], 1);
	TextDrawUseBox(HungerBackground[1], 1);
	TextDrawBoxColor(HungerBackground[1], 1787344480);
	TextDrawTextSize(HungerBackground[1], 604.000000, 40.000000);
	TextDrawSetSelectable(HungerBackground[1], 0);
	//
	new playerid;
	enable_animation_TD = TextDrawCreate(401.00, 419.00, !"~w~ ~g~LSHIFT~w~ TO STOP THE ANIMATION");
	TextDrawBackgroundColor(enable_animation_TD, 0x000000FF);
	TextDrawFont(enable_animation_TD, 2);
	TextDrawSetOutline(enable_animation_TD, 1);
	TextDrawLetterSize(enable_animation_TD, 0.300000, 1.250000);
	TextDrawColor(enable_animation_TD, 0xFFCC00FF);
	TextDrawSetProportional(enable_animation_TD, 1);
	//
	TDBizwar[playerid][0] = CreatePlayerTextDraw(playerid, 184.399993, 187.419998, "usebox");
	PlayerTextDrawLetterSize(playerid, TDBizwar[playerid][0], 0.000000, 3.250741);
	PlayerTextDrawTextSize(playerid, TDBizwar[playerid][0], 6.800000, 0.000000);
	PlayerTextDrawAlignment(playerid, TDBizwar[playerid][0], 1);
	PlayerTextDrawColor(playerid, TDBizwar[playerid][0], 0);
	PlayerTextDrawUseBox(playerid, TDBizwar[playerid][0], true);
	PlayerTextDrawBoxColor(playerid, TDBizwar[playerid][0], 102);
	PlayerTextDrawSetShadow(playerid, TDBizwar[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, TDBizwar[playerid][0], 0);
	PlayerTextDrawFont(playerid, TDBizwar[playerid][0], 0);

	TDBizwar[playerid][1] = CreatePlayerTextDraw(playerid, 15.200009, 188.160049, "Œœ√");
	PlayerTextDrawLetterSize(playerid, TDBizwar[playerid][1], 0.304399, 1.249065);
	PlayerTextDrawAlignment(playerid, TDBizwar[playerid][1], 1);
	PlayerTextDrawColor(playerid, TDBizwar[playerid][1], -5963521);
	PlayerTextDrawSetShadow(playerid, TDBizwar[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, TDBizwar[playerid][1], 1);
	PlayerTextDrawBackgroundColor(playerid, TDBizwar[playerid][1], 51);
	PlayerTextDrawFont(playerid, TDBizwar[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, TDBizwar[playerid][1], 1);

	TDBizwar[playerid][2] = CreatePlayerTextDraw(playerid, 42.400016, 188.159988, "_");
	PlayerTextDrawLetterSize(playerid, TDBizwar[playerid][2], 0.250797, 1.383466);
	PlayerTextDrawAlignment(playerid, TDBizwar[playerid][2], 1);
	PlayerTextDrawColor(playerid, TDBizwar[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, TDBizwar[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, TDBizwar[playerid][2], 1);
	PlayerTextDrawBackgroundColor(playerid, TDBizwar[playerid][2], 51);
	PlayerTextDrawFont(playerid, TDBizwar[playerid][2], 2);
	PlayerTextDrawSetProportional(playerid, TDBizwar[playerid][2], 1);

	TDBizwar[playerid][3] = CreatePlayerTextDraw(playerid, 169.599990, 187.413406, "0");
	PlayerTextDrawLetterSize(playerid, TDBizwar[playerid][3], 0.412400, 1.450664);
	PlayerTextDrawAlignment(playerid, TDBizwar[playerid][3], 1);
	PlayerTextDrawColor(playerid, TDBizwar[playerid][3], -2147483393);
	PlayerTextDrawSetShadow(playerid, TDBizwar[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, TDBizwar[playerid][3], 1);
	PlayerTextDrawBackgroundColor(playerid, TDBizwar[playerid][3], 51);
	PlayerTextDrawFont(playerid, TDBizwar[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, TDBizwar[playerid][3], 1);

	TDBizwar[playerid][4] = CreatePlayerTextDraw(playerid, 169.599975, 205.333328, "0");
	PlayerTextDrawLetterSize(playerid, TDBizwar[playerid][4], 0.415598, 1.420799);
	PlayerTextDrawAlignment(playerid, TDBizwar[playerid][4], 1);
	PlayerTextDrawColor(playerid, TDBizwar[playerid][4], -2147483393);
	PlayerTextDrawSetShadow(playerid, TDBizwar[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, TDBizwar[playerid][4], 1);
	PlayerTextDrawBackgroundColor(playerid, TDBizwar[playerid][4], 51);
	PlayerTextDrawFont(playerid, TDBizwar[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, TDBizwar[playerid][4], 1);

	TDBizwar[playerid][5] = CreatePlayerTextDraw(playerid, 43.200019, 205.333328, "_");
	PlayerTextDrawLetterSize(playerid, TDBizwar[playerid][5], 0.257198, 1.256531);
	PlayerTextDrawAlignment(playerid, TDBizwar[playerid][5], 1);
	PlayerTextDrawColor(playerid, TDBizwar[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, TDBizwar[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, TDBizwar[playerid][5], 1);
	PlayerTextDrawBackgroundColor(playerid, TDBizwar[playerid][5], 51);
	PlayerTextDrawFont(playerid, TDBizwar[playerid][5], 2);
	PlayerTextDrawSetProportional(playerid, TDBizwar[playerid][5], 1);

	TDBizwar[playerid][6] = CreatePlayerTextDraw(playerid, 15.199992, 205.333389, "Œœ√");
	PlayerTextDrawLetterSize(playerid, TDBizwar[playerid][6], 0.278798, 1.241598);
	PlayerTextDrawAlignment(playerid, TDBizwar[playerid][6], 1);
	PlayerTextDrawColor(playerid, TDBizwar[playerid][6], -5963521);
	PlayerTextDrawSetShadow(playerid, TDBizwar[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, TDBizwar[playerid][6], 1);
	PlayerTextDrawBackgroundColor(playerid, TDBizwar[playerid][6], 51);
	PlayerTextDrawFont(playerid, TDBizwar[playerid][6], 2);
	PlayerTextDrawSetProportional(playerid, TDBizwar[playerid][6], 1);

    SetTimer("vsysted",1000,true);
    Vrijeme = TextDrawCreate(553.7777, 23.3955, "__"); // ?????
    TextDrawLetterSize(Vrijeme, 0.5113, 2.0727);
    TextDrawTextSize(Vrijeme, 1280.0000, 1280.0000);
    TextDrawAlignment(Vrijeme, 1);
    TextDrawColor(Vrijeme, -1);
    TextDrawSetOutline(Vrijeme, 1);
    TextDrawBackgroundColor(Vrijeme, 255);
    TextDrawFont(Vrijeme, 3);
    TextDrawSetProportional(Vrijeme, 1);
    TextDrawSetShadow(Vrijeme, 0);

    SetTimer("vsystem",1000,true);
    Datum = TextDrawCreate(565.3336, 15.9288, "__"); // ????? ????
    TextDrawLetterSize(Datum, 0.2148, 0.9527);
    TextDrawTextSize(Datum, 1280.0000, 1280.0000);
    TextDrawAlignment(Datum, 1);
    TextDrawColor(Datum, -4587265);
    TextDrawUseBox(Datum, 1);
    TextDrawBoxColor(Datum, 0);
    TextDrawFont(Datum, 1);
    TextDrawSetProportional(Datum, 1);
    TextDrawSetShadow(Datum, 0);

	Button[0] = TextDrawCreate(50.0, 200.0, "<<");
	TextDrawAlignment(Button[0], 2);
	TextDrawTextSize(Button[0], 15.000000, 68.000000);
	TextDrawSetProportional(Button[0], 1);
	TextDrawLetterSize(Button[0], 0.679999, 1.900000);
	TextDrawSetShadow(Button[0], 1);
	TextDrawSetSelectable(Button[0], 1);
	TextDrawColor(Button[0], 0x63BD4EFF);
	TextDrawFont(Button[0], 3);
	TextDrawSetOutline(Button[0], 0);
	TextDrawBackgroundColor(Button[0], 255);

    Button[1] = TextDrawCreate(530.0, 200.0, ">>");
	TextDrawFont(Button[1], 3);
	TextDrawLetterSize(Button[1], 0.679999, 1.900000);
	TextDrawSetOutline(Button[1], 0);
	TextDrawAlignment(Button[1], 2);
	TextDrawTextSize(Button[1], 15.000000, 68.000000);
	TextDrawSetProportional(Button[1], 1);
	TextDrawSetShadow(Button[1], 1);
	TextDrawSetSelectable(Button[1], 1);
	TextDrawColor(Button[1], 0x63BD4EFF);
	TextDrawBackgroundColor(Button[1], 255);

	Button[2] = TextDrawCreate(240.000000, 371.000000, "Cancel");
	TextDrawAlignment(Button[2], 2);
	TextDrawTextSize(Button[2], 15.000000, 68.000000);
	TextDrawBackgroundColor(Button[2], 255);
	TextDrawFont(Button[2], 3);
	TextDrawLetterSize(Button[2], 0.679999, 1.900000);
	TextDrawColor(Button[2], 0x63BD4EFF);
	TextDrawSetOutline(Button[2], 0);
	TextDrawSetProportional(Button[2], 1);
	TextDrawSetShadow(Button[2], 1);
	TextDrawSetSelectable(Button[2], 1);

	Button[3] = TextDrawCreate(382.000000, 371.000000, "Select");
	TextDrawAlignment(Button[3], 2);
	TextDrawTextSize(Button[3], 15.000000, 68.000000);
	TextDrawBackgroundColor(Button[3], 255);
	TextDrawFont(Button[3], 3);
	TextDrawLetterSize(Button[3], 0.679999, 1.900000);
	TextDrawColor(Button[3], 0x63BD4EFF);
	TextDrawSetOutline(Button[3], 0);
	TextDrawSetProportional(Button[3], 1);
	TextDrawSetShadow(Button[3], 1);
	TextDrawSetSelectable(Button[3], 1);
}
//==============================================================================

stock CreateTextDraws(playerid)
{
    SecurityCode[playerid][0] = CreatePlayerTextDraw(playerid,  513.333374, 287.066650, "1");
	PlayerTextDrawLetterSize(playerid, SecurityCode[playerid][0], 0.760999, 2.894222);
	PlayerTextDrawTextSize(playerid, SecurityCode[playerid][0], 528.666748, 18.000000);
	PlayerTextDrawAlignment(playerid, SecurityCode[playerid][0], 1);
	PlayerTextDrawColor(playerid, SecurityCode[playerid][0], -1);
	PlayerTextDrawUseBox(playerid, SecurityCode[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, SecurityCode[playerid][0], -5963521);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, SecurityCode[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, SecurityCode[playerid][0], 255);
	PlayerTextDrawFont(playerid, SecurityCode[playerid][0], 3);
	PlayerTextDrawSetProportional(playerid, SecurityCode[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][0], 0);
	PlayerTextDrawSetSelectable(playerid, SecurityCode[playerid][0], true);

	SecurityCode[playerid][5] = CreatePlayerTextDraw(playerid,  533.228515, 287.066650, "6");
	PlayerTextDrawLetterSize(playerid, SecurityCode[playerid][5], 0.760999, 2.894222);
	PlayerTextDrawTextSize(playerid, SecurityCode[playerid][5], 548.561889, 18.000000);
	PlayerTextDrawAlignment(playerid, SecurityCode[playerid][5], 1);
	PlayerTextDrawColor(playerid, SecurityCode[playerid][5], -1);
	PlayerTextDrawUseBox(playerid, SecurityCode[playerid][5], 1);
	PlayerTextDrawBoxColor(playerid, SecurityCode[playerid][5], -5963521);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, SecurityCode[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, SecurityCode[playerid][5], 255);
	PlayerTextDrawFont(playerid, SecurityCode[playerid][5], 3);
	PlayerTextDrawSetProportional(playerid, SecurityCode[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][5], 0);
	PlayerTextDrawSetSelectable(playerid, SecurityCode[playerid][5], true);

	SecurityCode[playerid][2] = CreatePlayerTextDraw(playerid,  553.523559, 287.066650, "3");
	PlayerTextDrawLetterSize(playerid, SecurityCode[playerid][2], 0.760999, 2.894222);
	PlayerTextDrawTextSize(playerid, SecurityCode[playerid][2], 568.856933, 18.000000);
	PlayerTextDrawAlignment(playerid, SecurityCode[playerid][2], 1);
	PlayerTextDrawColor(playerid, SecurityCode[playerid][2], -1);
	PlayerTextDrawUseBox(playerid, SecurityCode[playerid][2], 1);
	PlayerTextDrawBoxColor(playerid, SecurityCode[playerid][2], -5963521);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, SecurityCode[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, SecurityCode[playerid][2], 255);
	PlayerTextDrawFont(playerid, SecurityCode[playerid][2], 3);
	PlayerTextDrawSetProportional(playerid, SecurityCode[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][2], 0);
	PlayerTextDrawSetSelectable(playerid, SecurityCode[playerid][2], true);

	SecurityCode[playerid][4] = CreatePlayerTextDraw(playerid,  553.523559, 318.868591, "5");
	PlayerTextDrawLetterSize(playerid, SecurityCode[playerid][4], 0.760999, 2.894222);
	PlayerTextDrawTextSize(playerid, SecurityCode[playerid][4], 568.856933, 18.000000);
	PlayerTextDrawAlignment(playerid, SecurityCode[playerid][4], 1);
	PlayerTextDrawColor(playerid, SecurityCode[playerid][4], -1);
	PlayerTextDrawUseBox(playerid, SecurityCode[playerid][4], 1);
	PlayerTextDrawBoxColor(playerid, SecurityCode[playerid][4], -5963521);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, SecurityCode[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, SecurityCode[playerid][4], 255);
	PlayerTextDrawFont(playerid, SecurityCode[playerid][4], 3);
	PlayerTextDrawSetProportional(playerid, SecurityCode[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][4], 0);
	PlayerTextDrawSetSelectable(playerid, SecurityCode[playerid][4], true);

	SecurityCode[playerid][7] = CreatePlayerTextDraw(playerid,  533.228515, 318.868591, "8");
	PlayerTextDrawLetterSize(playerid, SecurityCode[playerid][7], 0.760999, 2.894222);
	PlayerTextDrawTextSize(playerid, SecurityCode[playerid][7], 548.561889, 18.000000);
	PlayerTextDrawAlignment(playerid, SecurityCode[playerid][7], 1);
	PlayerTextDrawColor(playerid, SecurityCode[playerid][7], -1);
	PlayerTextDrawUseBox(playerid, SecurityCode[playerid][7], 1);
	PlayerTextDrawBoxColor(playerid, SecurityCode[playerid][7], -5963521);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, SecurityCode[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, SecurityCode[playerid][7], 255);
	PlayerTextDrawFont(playerid, SecurityCode[playerid][7], 3);
	PlayerTextDrawSetProportional(playerid, SecurityCode[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][7], 0);
	PlayerTextDrawSetSelectable(playerid, SecurityCode[playerid][7], true);

	SecurityCode[playerid][6] = CreatePlayerTextDraw(playerid,  513.233398, 318.868591, "7");
	PlayerTextDrawLetterSize(playerid, SecurityCode[playerid][6], 0.760999, 2.894222);
	PlayerTextDrawTextSize(playerid, SecurityCode[playerid][6], 528.566772, 18.000000);
	PlayerTextDrawAlignment(playerid, SecurityCode[playerid][6], 1);
	PlayerTextDrawColor(playerid, SecurityCode[playerid][6], -1);
	PlayerTextDrawUseBox(playerid, SecurityCode[playerid][6], 1);
	PlayerTextDrawBoxColor(playerid, SecurityCode[playerid][6], -5963521);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, SecurityCode[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, SecurityCode[playerid][6], 255);
	PlayerTextDrawFont(playerid, SecurityCode[playerid][6], 3);
	PlayerTextDrawSetProportional(playerid, SecurityCode[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][6], 0);
	PlayerTextDrawSetSelectable(playerid, SecurityCode[playerid][6], true);

	SecurityCode[playerid][1] = CreatePlayerTextDraw(playerid,  513.233398, 350.770538, "2");
	PlayerTextDrawLetterSize(playerid, SecurityCode[playerid][1], 0.760999, 2.894222);
	PlayerTextDrawTextSize(playerid, SecurityCode[playerid][1], 528.566772, 18.000000);
	PlayerTextDrawAlignment(playerid, SecurityCode[playerid][1], 1);
	PlayerTextDrawColor(playerid, SecurityCode[playerid][1], -1);
	PlayerTextDrawUseBox(playerid, SecurityCode[playerid][1], 1);
	PlayerTextDrawBoxColor(playerid, SecurityCode[playerid][1], -5963521);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, SecurityCode[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, SecurityCode[playerid][1], 255);
	PlayerTextDrawFont(playerid, SecurityCode[playerid][1], 3);
	PlayerTextDrawSetProportional(playerid, SecurityCode[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][1], 0);
	PlayerTextDrawSetSelectable(playerid, SecurityCode[playerid][1], true);

	SecurityCode[playerid][3] = CreatePlayerTextDraw(playerid,  533.328491, 350.770538, "4");
	PlayerTextDrawLetterSize(playerid, SecurityCode[playerid][3], 0.760999, 2.894222);
	PlayerTextDrawTextSize(playerid, SecurityCode[playerid][3], 548.661865, 18.000000);
	PlayerTextDrawAlignment(playerid, SecurityCode[playerid][3], 1);
	PlayerTextDrawColor(playerid, SecurityCode[playerid][3], -1);
	PlayerTextDrawUseBox(playerid, SecurityCode[playerid][3], 1);
	PlayerTextDrawBoxColor(playerid, SecurityCode[playerid][3], -5963521);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, SecurityCode[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, SecurityCode[playerid][3], 255);
	PlayerTextDrawFont(playerid, SecurityCode[playerid][3], 3);
	PlayerTextDrawSetProportional(playerid, SecurityCode[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][3], 0);
	PlayerTextDrawSetSelectable(playerid, SecurityCode[playerid][3], true);

	SecurityCode[playerid][8] = CreatePlayerTextDraw(playerid,  553.523559, 350.770538, "9");
	PlayerTextDrawLetterSize(playerid, SecurityCode[playerid][8], 0.760999, 2.894222);
	PlayerTextDrawTextSize(playerid, SecurityCode[playerid][8], 568.856933, 18.000000);
	PlayerTextDrawAlignment(playerid, SecurityCode[playerid][8], 1);
	PlayerTextDrawColor(playerid, SecurityCode[playerid][8], -1);
	PlayerTextDrawUseBox(playerid, SecurityCode[playerid][8], 1);
	PlayerTextDrawBoxColor(playerid, SecurityCode[playerid][8], -5963521);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, SecurityCode[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, SecurityCode[playerid][8], 255);
	PlayerTextDrawFont(playerid, SecurityCode[playerid][8], 3);
	PlayerTextDrawSetProportional(playerid, SecurityCode[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, SecurityCode[playerid][8], 0);
	PlayerTextDrawSetSelectable(playerid, SecurityCode[playerid][8], true);

/*	StatusWork[playerid][0] = CreatePlayerTextDraw(playerid,  609.500000, 143.687500, " ");
	PlayerTextDrawLetterSize(playerid, GreenZoneText[playerid][0], 0.000000, 0.016666);
	PlayerTextDrawTextSize(playerid, GreenZoneText[playerid][0], 0.500000, 0.000000);
	PlayerTextDrawAlignment(playerid, GreenZoneText[playerid][0], 0);
	PlayerTextDrawColor(playerid, GreenZoneText[playerid][0], 0);
	PlayerTextDrawUseBox(playerid, GreenZoneText[playerid][0], true);
	PlayerTextDrawBoxColor(playerid, GreenZoneText[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, GreenZoneText[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, GreenZoneText[playerid][0], 0);
	PlayerTextDrawFont(playerid, GreenZoneText[playerid][0], 0);
*/
	StatusWork[playerid][1] = CreatePlayerTextDraw(playerid,  478.000000, 187.419998, "usebox");
	PlayerTextDrawLetterSize(playerid, StatusWork[playerid][1], 0.000000, 9.638891);
	PlayerTextDrawTextSize(playerid, StatusWork[playerid][1], 618.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, StatusWork[playerid][1], 1);
	PlayerTextDrawColor(playerid, StatusWork[playerid][1], 0);
	PlayerTextDrawUseBox(playerid, StatusWork[playerid][1], true);
	PlayerTextDrawBoxColor(playerid, StatusWork[playerid][1], 102);
	PlayerTextDrawSetShadow(playerid, StatusWork[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, StatusWork[playerid][1], 0);
	PlayerTextDrawFont(playerid, StatusWork[playerid][1], 0);

	StatusWork[playerid][2] = CreatePlayerTextDraw(playerid,  619.439941, 191.899978, "usebox");
	PlayerTextDrawLetterSize(playerid, StatusWork[playerid][2], -0.006399, 8.520547);
	PlayerTextDrawTextSize(playerid, StatusWork[playerid][2], 476.399993, 0.000000);
	PlayerTextDrawAlignment(playerid, StatusWork[playerid][2], 1);
	PlayerTextDrawColor(playerid, StatusWork[playerid][2], 0);
	PlayerTextDrawUseBox(playerid, StatusWork[playerid][2], true);
	PlayerTextDrawBoxColor(playerid, StatusWork[playerid][2], -5963521);
	PlayerTextDrawSetShadow(playerid, StatusWork[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, StatusWork[playerid][2], 0);
	PlayerTextDrawFont(playerid, StatusWork[playerid][2], 0);

	StatusWork[playerid][3] = CreatePlayerTextDraw(playerid,  495.999908, 191.893264, "»Õ‘Œ–Ã¿÷»ﬂ");
	PlayerTextDrawLetterSize(playerid, StatusWork[playerid][3], 0.383599, 1.652266);
	PlayerTextDrawAlignment(playerid, StatusWork[playerid][3], 1);
	PlayerTextDrawColor(playerid, StatusWork[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, StatusWork[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, StatusWork[playerid][3], 1);
	PlayerTextDrawBackgroundColor(playerid, StatusWork[playerid][3], 51);
	PlayerTextDrawFont(playerid, StatusWork[playerid][3], 2);
	PlayerTextDrawSetProportional(playerid, StatusWork[playerid][3], 1);

	StatusWork[playerid][4] = CreatePlayerTextDraw(playerid,  485.239898, 217.458587, "œP»ÕE—EÕŒ: 0");
	PlayerTextDrawLetterSize(playerid, StatusWork[playerid][4], 0.383599, 1.652266);
	PlayerTextDrawAlignment(playerid, StatusWork[playerid][4], 1);
	PlayerTextDrawColor(playerid, StatusWork[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, StatusWork[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, StatusWork[playerid][4], 1);
	PlayerTextDrawBackgroundColor(playerid, StatusWork[playerid][4], 51);
	PlayerTextDrawFont(playerid, StatusWork[playerid][4], 2);
	PlayerTextDrawSetProportional(playerid, StatusWork[playerid][4], 1);

	StatusWork[playerid][5] = CreatePlayerTextDraw(playerid,  486.000000, 241.530441, "œ–O÷EÕ“: 0 %");
	PlayerTextDrawLetterSize(playerid, StatusWork[playerid][5], 0.416878, 1.632107);
	PlayerTextDrawAlignment(playerid, StatusWork[playerid][5], 1);
	PlayerTextDrawColor(playerid, StatusWork[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, StatusWork[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, StatusWork[playerid][5], 1);
	PlayerTextDrawBackgroundColor(playerid, StatusWork[playerid][5], 51);
	PlayerTextDrawFont(playerid, StatusWork[playerid][5], 2);
	PlayerTextDrawSetProportional(playerid, StatusWork[playerid][5], 1);

//==============================================================================
/*	GreenZoneText[playerid][0] = CreatePlayerTextDraw(playerid, 18.666662, 270.044372, "LD_SPAC:white");//
	PlayerTextDrawLetterSize(playerid, GreenZoneText[playerid][0], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, GreenZoneText[playerid][0], 85.666664, 12.029632);
	PlayerTextDrawAlignment(playerid, GreenZoneText[playerid][0], 1);
	PlayerTextDrawColor(playerid, GreenZoneText[playerid][0], -491053057);
	PlayerTextDrawSetShadow(playerid, GreenZoneText[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, GreenZoneText[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, GreenZoneText[playerid][0], -305712641);
	PlayerTextDrawFont(playerid, GreenZoneText[playerid][0], 4);

	GreenZoneText[playerid][1] = CreatePlayerTextDraw(playerid, 10.333336, 266.725860, "LD_BEAT:chit");//
	PlayerTextDrawLetterSize(playerid, GreenZoneText[playerid][1], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, GreenZoneText[playerid][1], 18.333328, 18.666656);
	PlayerTextDrawAlignment(playerid, GreenZoneText[playerid][1], 1);
	PlayerTextDrawColor(playerid, GreenZoneText[playerid][1], -491053057);
	PlayerTextDrawSetShadow(playerid, GreenZoneText[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, GreenZoneText[playerid][1], 0);
	PlayerTextDrawFont(playerid, GreenZoneText[playerid][1], 4);

	GreenZoneText[playerid][2] = CreatePlayerTextDraw(playerid, 93.666664, 266.896301, "LD_BEAT:chit");//
	PlayerTextDrawLetterSize(playerid, GreenZoneText[playerid][2], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, GreenZoneText[playerid][2], 18.666660, 18.251846);
	PlayerTextDrawAlignment(playerid, GreenZoneText[playerid][2], 1);
	PlayerTextDrawColor(playerid, GreenZoneText[playerid][2], -491053057);
	PlayerTextDrawSetShadow(playerid, GreenZoneText[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, GreenZoneText[playerid][2], 0);
	PlayerTextDrawFont(playerid, GreenZoneText[playerid][2], 4);

	GreenZoneText[playerid][3] = CreatePlayerTextDraw(playerid, 93.666671, 254.866531, "LD_BEAT:chit");//
	PlayerTextDrawLetterSize(playerid, GreenZoneText[playerid][3], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, GreenZoneText[playerid][3], 13.666660, 14.103694);
	PlayerTextDrawAlignment(playerid, GreenZoneText[playerid][3], 1);
	PlayerTextDrawColor(playerid, GreenZoneText[playerid][3], -491053057);
	PlayerTextDrawSetShadow(playerid, GreenZoneText[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, GreenZoneText[playerid][3], 0);
	PlayerTextDrawFont(playerid, GreenZoneText[playerid][3], 4);

	GreenZoneText[playerid][4] = CreatePlayerTextDraw(playerid, 104.666687, 265.407287, "LD_BEAT:chit");//
	PlayerTextDrawLetterSize(playerid, GreenZoneText[playerid][4], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, GreenZoneText[playerid][4], 3.999993, 3.733323);
	PlayerTextDrawAlignment(playerid, GreenZoneText[playerid][4], 1);
	PlayerTextDrawColor(playerid, GreenZoneText[playerid][4], -491053057);
	PlayerTextDrawSetShadow(playerid, GreenZoneText[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, GreenZoneText[playerid][4], 0);
	PlayerTextDrawFont(playerid, GreenZoneText[playerid][4], 4);

	GreenZoneText[playerid][5] = CreatePlayerTextDraw(playerid, 108.666671, 269.311004, "LD_BEAT:chit");//
	PlayerTextDrawLetterSize(playerid, GreenZoneText[playerid][5], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, GreenZoneText[playerid][5], 2.333326, 1.659250);
	PlayerTextDrawAlignment(playerid, GreenZoneText[playerid][5], 1);
	PlayerTextDrawColor(playerid, GreenZoneText[playerid][5], -491053057);
	PlayerTextDrawSetShadow(playerid, GreenZoneText[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, GreenZoneText[playerid][5], 0);
	PlayerTextDrawFont(playerid, GreenZoneText[playerid][5], 4);

	GreenZoneText[playerid][6] = CreatePlayerTextDraw(playerid, 31.666656, 270.459320, "àEáEHAï_àOHA");//
	PlayerTextDrawLetterSize(playerid, GreenZoneText[playerid][6], 0.210999, 1.127111);
	PlayerTextDrawAlignment(playerid, GreenZoneText[playerid][6], 1);
	PlayerTextDrawColor(playerid, GreenZoneText[playerid][6], 993737215);
	PlayerTextDrawSetShadow(playerid, GreenZoneText[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, GreenZoneText[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, GreenZoneText[playerid][6], 51);
	PlayerTextDrawFont(playerid, GreenZoneText[playerid][6], 2);
	PlayerTextDrawSetProportional(playerid, GreenZoneText[playerid][6], 1);

	GreenZoneText[playerid][7] = CreatePlayerTextDraw(playerid, 99.333351, 255.940719, "!");//
	PlayerTextDrawLetterSize(playerid, GreenZoneText[playerid][7], 0.297333, 1.131258);
	PlayerTextDrawAlignment(playerid, GreenZoneText[playerid][7], 1);
	PlayerTextDrawColor(playerid, GreenZoneText[playerid][7], 993737215);
	PlayerTextDrawSetShadow(playerid, GreenZoneText[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, GreenZoneText[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, GreenZoneText[playerid][7], 51);
	PlayerTextDrawFont(playerid, GreenZoneText[playerid][7], 0);
	PlayerTextDrawSetProportional(playerid, GreenZoneText[playerid][7], 1);
*/
//==============================================================================

	CaptureTD[playerid][0] = CreatePlayerTextDraw(playerid, 156.399993, 220.273345, "usebox");
	PlayerTextDrawLetterSize(playerid, CaptureTD[playerid][0], 0.000000, 5.822591);
	PlayerTextDrawTextSize(playerid, CaptureTD[playerid][0], 23.599998, 0.000000);
	PlayerTextDrawAlignment(playerid, CaptureTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, CaptureTD[playerid][0], 0);
	PlayerTextDrawUseBox(playerid, CaptureTD[playerid][0], true);
	PlayerTextDrawBoxColor(playerid, CaptureTD[playerid][0], 102);
	PlayerTextDrawSetShadow(playerid, CaptureTD[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, CaptureTD[playerid][0], 0);
	PlayerTextDrawFont(playerid, CaptureTD[playerid][0], 0);

	CaptureTD[playerid][1] = CreatePlayerTextDraw(playerid, 49.600002, 221.013366, "«¿’¬¿“ “≈––»“Œ–»»");
	PlayerTextDrawLetterSize(playerid, CaptureTD[playerid][1], 0.174796, 1.316264);
	PlayerTextDrawAlignment(playerid, CaptureTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, CaptureTD[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, CaptureTD[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, CaptureTD[playerid][1], 1);
	PlayerTextDrawBackgroundColor(playerid, CaptureTD[playerid][1], 51);
	PlayerTextDrawFont(playerid, CaptureTD[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, CaptureTD[playerid][1], 1);

	CaptureTD[playerid][2] = CreatePlayerTextDraw(playerid, 150.800003, 235.206695, "usebox");
	PlayerTextDrawLetterSize(playerid, CaptureTD[playerid][2], 0.000000, -0.565556);
	PlayerTextDrawTextSize(playerid, CaptureTD[playerid][2], 23.599998, 0.000000);
	PlayerTextDrawAlignment(playerid, CaptureTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, CaptureTD[playerid][2], 0);
	PlayerTextDrawUseBox(playerid, CaptureTD[playerid][2], true);
	PlayerTextDrawBoxColor(playerid, CaptureTD[playerid][2], 102);
	PlayerTextDrawSetShadow(playerid, CaptureTD[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, CaptureTD[playerid][2], 0);
	PlayerTextDrawFont(playerid, CaptureTD[playerid][2], 0);

	CaptureTD[playerid][3] = CreatePlayerTextDraw(playerid, 30.399995, 237.440017, "¬–≈Ãﬂ:");
	PlayerTextDrawLetterSize(playerid, CaptureTD[playerid][3], 0.156395, 1.398398);
	PlayerTextDrawAlignment(playerid, CaptureTD[playerid][3], 1);
	PlayerTextDrawColor(playerid, CaptureTD[playerid][3], -5963521);
	PlayerTextDrawSetShadow(playerid, CaptureTD[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, CaptureTD[playerid][3], 1);
	PlayerTextDrawBackgroundColor(playerid, CaptureTD[playerid][3], 51);
	PlayerTextDrawFont(playerid, CaptureTD[playerid][3], 2);
	PlayerTextDrawSetProportional(playerid, CaptureTD[playerid][3], 1);

	CaptureTD[playerid][4] = CreatePlayerTextDraw(playerid, 56.000015, 238.933349, "12:00");
	PlayerTextDrawLetterSize(playerid, CaptureTD[playerid][4], 0.205999, 1.114665);
	PlayerTextDrawAlignment(playerid, CaptureTD[playerid][4], 1);
	PlayerTextDrawColor(playerid, CaptureTD[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, CaptureTD[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, CaptureTD[playerid][4], 1);
	PlayerTextDrawBackgroundColor(playerid, CaptureTD[playerid][4], 51);
	PlayerTextDrawFont(playerid, CaptureTD[playerid][4], 2);
	PlayerTextDrawSetProportional(playerid, CaptureTD[playerid][4], 1);

	CaptureTD[playerid][5] = CreatePlayerTextDraw(playerid, 36.000000, 250.133255, "Œœ√");
	PlayerTextDrawLetterSize(playerid, CaptureTD[playerid][5], 0.165797, 1.501198);
	PlayerTextDrawAlignment(playerid, CaptureTD[playerid][5], 2);
	PlayerTextDrawColor(playerid, CaptureTD[playerid][5], -5963521);
	PlayerTextDrawSetShadow(playerid, CaptureTD[playerid][5], 1);
	PlayerTextDrawSetOutline(playerid, CaptureTD[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, CaptureTD[playerid][5], 51);
	PlayerTextDrawFont(playerid, CaptureTD[playerid][5], 2);
	PlayerTextDrawSetProportional(playerid, CaptureTD[playerid][5], 1);

	CaptureTD[playerid][6] = CreatePlayerTextDraw(playerid, 30.135000, 261.333312, "Œœ√");
	PlayerTextDrawLetterSize(playerid, CaptureTD[playerid][6], 0.165000, 1.501000);
	PlayerTextDrawAlignment(playerid, CaptureTD[playerid][6], 1);
	PlayerTextDrawColor(playerid, CaptureTD[playerid][6], -5963521);
	PlayerTextDrawSetShadow(playerid, CaptureTD[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, CaptureTD[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, CaptureTD[playerid][6], 51);
	PlayerTextDrawFont(playerid, CaptureTD[playerid][6], 2);
	PlayerTextDrawSetProportional(playerid, CaptureTD[playerid][6], 1);

	CaptureTD[playerid][7] = CreatePlayerTextDraw(playerid, 68.478988, 250.133331, "_");
	PlayerTextDrawLetterSize(playerid, CaptureTD[playerid][7], 0.168997, 1.434599);
	PlayerTextDrawAlignment(playerid, CaptureTD[playerid][7], 2);
	PlayerTextDrawColor(playerid, CaptureTD[playerid][7], -1);
	PlayerTextDrawSetShadow(playerid, CaptureTD[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, CaptureTD[playerid][7], 1);
	PlayerTextDrawBackgroundColor(playerid, CaptureTD[playerid][7], 51);
	PlayerTextDrawFont(playerid, CaptureTD[playerid][7], 2);
	PlayerTextDrawSetProportional(playerid, CaptureTD[playerid][7], 1);

	CaptureTD[playerid][8] = CreatePlayerTextDraw(playerid, 45.599979, 262.079956, "_");
	PlayerTextDrawLetterSize(playerid, CaptureTD[playerid][8], 0.153797, 1.367400);
	PlayerTextDrawAlignment(playerid, CaptureTD[playerid][8], 1);
	PlayerTextDrawColor(playerid, CaptureTD[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, CaptureTD[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, CaptureTD[playerid][8], 1);
	PlayerTextDrawBackgroundColor(playerid, CaptureTD[playerid][8], 51);
	PlayerTextDrawFont(playerid, CaptureTD[playerid][8], 2);
	PlayerTextDrawSetProportional(playerid, CaptureTD[playerid][8], 1);

	CaptureTD[playerid][9] = CreatePlayerTextDraw(playerid, 140.000000, 250.880020, "0");
	PlayerTextDrawLetterSize(playerid, CaptureTD[playerid][9], 0.180399, 1.219197);
	PlayerTextDrawAlignment(playerid, CaptureTD[playerid][9], 1);
	PlayerTextDrawColor(playerid, CaptureTD[playerid][9], -5963521);
	PlayerTextDrawSetShadow(playerid, CaptureTD[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, CaptureTD[playerid][9], 1);
	PlayerTextDrawBackgroundColor(playerid, CaptureTD[playerid][9], 51);
	PlayerTextDrawFont(playerid, CaptureTD[playerid][9], 2);
	PlayerTextDrawSetProportional(playerid, CaptureTD[playerid][9], 1);

	CaptureTD[playerid][10] = CreatePlayerTextDraw(playerid, 140.599975, 262.208312, "0");
	PlayerTextDrawLetterSize(playerid, CaptureTD[playerid][10], 0.158600, 1.174198);
	PlayerTextDrawAlignment(playerid, CaptureTD[playerid][10], 1);
	PlayerTextDrawColor(playerid, CaptureTD[playerid][10], -5963521);
	PlayerTextDrawSetShadow(playerid, CaptureTD[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, CaptureTD[playerid][10], 1);
	PlayerTextDrawBackgroundColor(playerid, CaptureTD[playerid][10], 51);
	PlayerTextDrawFont(playerid, CaptureTD[playerid][10], 2);
	PlayerTextDrawSetProportional(playerid, CaptureTD[playerid][10], 1);


	//ÃÂÌ˛¯Í‡
	MenuTD[0][playerid] = CreatePlayerTextDraw(playerid, 554.666687, 1.500000, "usebox");
	PlayerTextDrawLetterSize(playerid, MenuTD[0][playerid], 0.000000, 2.909670);
	PlayerTextDrawTextSize(playerid, MenuTD[0][playerid], 168.666671, 0.000000);
	PlayerTextDrawAlignment(playerid, MenuTD[0][playerid], 1);
	PlayerTextDrawColor(playerid, MenuTD[0][playerid], 255);
	PlayerTextDrawUseBox(playerid, MenuTD[0][playerid], true);
	PlayerTextDrawBoxColor(playerid, MenuTD[0][playerid], 255);
	PlayerTextDrawSetShadow(playerid, MenuTD[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MenuTD[0][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, MenuTD[0][playerid], 255);
	PlayerTextDrawFont(playerid, MenuTD[0][playerid], 0);

	MenuTD[1][playerid] = CreatePlayerTextDraw(playerid, 179.666610, 5.392592, "œÂÒÓÌ‡Ê");
	PlayerTextDrawLetterSize(playerid, MenuTD[1][playerid], 0.381333, 1.284740);
	PlayerTextDrawTextSize(playerid, MenuTD[1][playerid], -63.333332, -15.348149);
	PlayerTextDrawAlignment(playerid, MenuTD[1][playerid], 1);
	PlayerTextDrawColor(playerid, MenuTD[1][playerid], -1);
	PlayerTextDrawSetShadow(playerid, MenuTD[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MenuTD[1][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, MenuTD[1][playerid], 51);
	PlayerTextDrawFont(playerid, MenuTD[1][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MenuTD[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MenuTD[1][playerid], true);

	MenuTD[2][playerid] = CreatePlayerTextDraw(playerid, 251.666717, 6.637040, "—ÓÓ·˘ÂÌËˇ");
	PlayerTextDrawLetterSize(playerid, MenuTD[2][playerid], 0.438666, 1.247407);
	PlayerTextDrawAlignment(playerid, MenuTD[2][playerid], 1);
	PlayerTextDrawColor(playerid, MenuTD[2][playerid], -1);
	PlayerTextDrawSetShadow(playerid, MenuTD[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MenuTD[2][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, MenuTD[2][playerid], 51);
	PlayerTextDrawFont(playerid, MenuTD[2][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MenuTD[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MenuTD[2][playerid], true);

	MenuTD[3][playerid] = CreatePlayerTextDraw(playerid, 311.333526, 7.051864, "“‡ÌÒÔÓÚ");
	PlayerTextDrawLetterSize(playerid, MenuTD[3][playerid], 0.400666, 1.239111);
	PlayerTextDrawAlignment(playerid, MenuTD[3][playerid], 1);
	PlayerTextDrawColor(playerid, MenuTD[3][playerid], -1);
	PlayerTextDrawSetShadow(playerid, MenuTD[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MenuTD[3][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, MenuTD[3][playerid], 51);
	PlayerTextDrawFont(playerid, MenuTD[3][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MenuTD[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MenuTD[3][playerid], true);

	MenuTD[4][playerid] = CreatePlayerTextDraw(playerid, 384.999969, 7.051851, "Õ‡ÒÚÓÈÍË");
	PlayerTextDrawLetterSize(playerid, MenuTD[4][playerid], 0.425666, 1.293036);
	PlayerTextDrawAlignment(playerid, MenuTD[4][playerid], 1);
	PlayerTextDrawColor(playerid, MenuTD[4][playerid], -1);
	PlayerTextDrawSetShadow(playerid, MenuTD[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MenuTD[4][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, MenuTD[4][playerid], 51);
	PlayerTextDrawFont(playerid, MenuTD[4][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MenuTD[4][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MenuTD[4][playerid], true);

	MenuTD[5][playerid] = CreatePlayerTextDraw(playerid, 452.333312, 6.637037, "¡‡ÌÍ");
	PlayerTextDrawLetterSize(playerid, MenuTD[5][playerid], 0.418000, 1.454815);
	PlayerTextDrawAlignment(playerid, MenuTD[5][playerid], 1);
	PlayerTextDrawColor(playerid, MenuTD[5][playerid], -1);
	PlayerTextDrawSetShadow(playerid, MenuTD[5][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MenuTD[5][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, MenuTD[5][playerid], 51);
	PlayerTextDrawFont(playerid, MenuTD[5][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MenuTD[5][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MenuTD[5][playerid], true);

	MenuTD[6][playerid] = CreatePlayerTextDraw(playerid, 497.666748, 7.466665, "¡ËÁÌÂÒ");
	PlayerTextDrawLetterSize(playerid, MenuTD[6][playerid], 0.383666, 1.450667);
	PlayerTextDrawAlignment(playerid, MenuTD[6][playerid], 1);
	PlayerTextDrawColor(playerid, MenuTD[6][playerid], -1);
	PlayerTextDrawSetShadow(playerid, MenuTD[6][playerid], 0);
	PlayerTextDrawSetOutline(playerid, MenuTD[6][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, MenuTD[6][playerid], 51);
	PlayerTextDrawFont(playerid, MenuTD[6][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MenuTD[6][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MenuTD[6][playerid], true);
	//ÕÓ‚˚È ‡‚ÚÓÒ‡ÎÓÌ
    /*choicecars[playerid][0] = CreatePlayerTextDraw(playerid, 436.800048, 368.362213, "usebox");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][0], 0.000000, 7.260617);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][0], 200.400024, 0.000000);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][0], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][0], 0);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][0], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][0], 102);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][0], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][0], 0);

	choicecars[playerid][10] = CreatePlayerTextDraw(playerid, 202.399993, 351.928894, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][10], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][10], 232.800018, 15.431091);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][10], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][10], -65281);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][10], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][10], 4);

	choicecars[playerid][2] = CreatePlayerTextDraw(playerid, 206.000000, 372.835571, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][2], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][2], 30.800003, 43.804443);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][2], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][2], -5963521);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][2], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][2], 4);

	choicecars[playerid][3] = CreatePlayerTextDraw(playerid, 399.600006, 371.839996, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][3], 0.001600, 0.154311);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][3], 31.200042, 44.799983);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][3], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][3], -5963521);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][3], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][3], 4);

	choicecars[playerid][11] = CreatePlayerTextDraw(playerid, 206.000000, 419.626678, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][11], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][11], 52.399993, 13.937774);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][11], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][11], -5963521);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][11], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][11], 4);

	choicecars[playerid][15] = CreatePlayerTextDraw(playerid, 431.199951, 420.124450, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][15], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][15], -53.999969, 12.942230);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][15], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][15], -5963521);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][15], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][15], 4);

	choicecars[playerid][6] = CreatePlayerTextDraw(playerid, 315.600006, 411.662200, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][6], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][6], -52.000000, -19.413299);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][6], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][6], -83289343);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][6], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][6], 4);

	choicecars[playerid][16] = CreatePlayerTextDraw(playerid, 320.000000, 392.248901, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][16], 0.001199, 0.099555);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][16], 51.200000, 19.413347);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][16], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][16], 586875440);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][16], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][16], 4);

	choicecars[playerid][8] = CreatePlayerTextDraw(playerid, 264.000000, 414.648864, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][8], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][8], 107.600006, 17.920013);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][8], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][8], 16777215);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][8], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][8], 4);

	choicecars[playerid][17] = CreatePlayerTextDraw(playerid, 258.799957, 369.351165, "—“Œ»ÃŒ—“‹:");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][17], 0.257599, 1.784177);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][17], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][17], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][17], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][17], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][17], 1);

	choicecars[playerid][1] = CreatePlayerTextDraw(playerid, 325.600067, 369.848937, "1000000");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][1], 0.270000, 1.873776);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][1], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][1], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][1], 1);

	choicecars[playerid][12] = CreatePlayerTextDraw(playerid, 250.000091, 351.928894, "BMX");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][12], 0.415999, 1.510399);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][12], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][12], 255);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][12], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][12], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][12], 1);

	choicecars[playerid][4] = CreatePlayerTextDraw(playerid, 207.200088, 375.324249, "<");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][4], 0.930000, 4.287998);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][4], 235.199890, 4.977777);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][4], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][4], 255);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][4], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][4], -5963521);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][4], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, choicecars[playerid][4], true);

	choicecars[playerid][5] = CreatePlayerTextDraw(playerid, 402.800323, 372.337768, ">");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][5], 0.993999, 4.263109);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][5], 429.200103, 14.933334);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][5], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][5], 255);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][5], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][5], 0);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][5], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, choicecars[playerid][5], true);

	choicecars[playerid][13] = CreatePlayerTextDraw(playerid, 266.800079, 393.244445, "OTMEHA");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][13], 0.284799, 1.595022);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][13], 313.199981, 4.480000);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][13], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][13], -1);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][13], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][13], 1258818305);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][13], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][13], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][13], 1);
	PlayerTextDrawSetSelectable(playerid, choicecars[playerid][13], true);

	choicecars[playerid][14] = CreatePlayerTextDraw(playerid, 322.399993, 393.244506, " ”œ»“‹");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][14], 0.293199, 1.674666);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][14], 368.399841, 10.453332);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][14], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][14], -1);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][14], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][14], -83731711);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][14], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][14], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][14], 1);
	PlayerTextDrawSetSelectable(playerid, choicecars[playerid][14], true);

	choicecars[playerid][7] = CreatePlayerTextDraw(playerid, 209.200027, 419.128967, "<<<");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][7], 0.449200, 1.520355);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][7], 248.800064, 9.457778);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][7], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][7], 255);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][7], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][7], 0);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][7], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, choicecars[playerid][7], true);

	choicecars[playerid][9] = CreatePlayerTextDraw(playerid, 401.199920, 418.631103, ">>>");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][9], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][9], 432.399871, 0.995555);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][9], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][9], 255);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][9], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][9], 0);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][9], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][9], 1);
	PlayerTextDrawSetSelectable(playerid, choicecars[playerid][9], true);

	choicecars[playerid][18] = CreatePlayerTextDraw(playerid, 265.999969, 413.155639, "œ–Œ…“» “≈—“-ƒ–¿…¬");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][18], 0.250599, 2.092800);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][18], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][18], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][18], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][18], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][18], 1);*/
	
	// ÌÓ‚˚È
    /*choicecars[playerid][0] = CreatePlayerTextDraw(playerid, 226.000076, 360.888641, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][0], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][0], 189.599990, 83.128906);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][0], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][0], 471802624);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][0], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][0], 4);

	choicecars[playerid][1] = CreatePlayerTextDraw(playerid, 225.999984, 358.399932, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][1], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][1], 189.600006, 14.933341);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][1], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][1], -238809344);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][1], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][1], 4);

	choicecars[playerid][2] = CreatePlayerTextDraw(playerid, 266.799987, 359.395660, "UNREALSUPERCAR");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][2], 0.276396, 1.480530);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][2], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][2], 337058303);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][2], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][2], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][2], 1);

	choicecars[playerid][3] = CreatePlayerTextDraw(playerid, 231.200057, 378.311004, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][3], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][3], 22.399982, 40.319992);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][3], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][3], -238809344);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][3], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][3], 4);

	choicecars[playerid][4] = CreatePlayerTextDraw(playerid, 387.399810, 378.315429, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][4], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][4], 22.399982, 40.319992);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][4], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][4], -238809344);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][4], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][4], 4);

	choicecars[playerid][5] = CreatePlayerTextDraw(playerid, 231.199996, 425.102233, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][5], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][5], 32.399990, 15.431091);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][5], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][5], -238809344);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][5], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][5], 4);

	choicecars[playerid][6] = CreatePlayerTextDraw(playerid, 376.999908, 425.106658, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][6], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][6], 32.399990, 15.431091);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][6], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][6], -238809344);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][6], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][6], 4);

	choicecars[playerid][7] = CreatePlayerTextDraw(playerid, 272.399993, 441.031219, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][7], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][7], 95.199996, -15.431077);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][7], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][7], 882432768);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][7], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][7], 4);

	choicecars[playerid][8] = CreatePlayerTextDraw(playerid, 272.799804, 403.697723, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][8], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][8], 43.999980, 15.928874);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][8], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][8], -414434304);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][8], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][8], 4);

	choicecars[playerid][9] = CreatePlayerTextDraw(playerid, 322.999969, 403.204040, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][9], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][9], 43.999980, 15.928874);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][9], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][9], 785150208);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][9], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][9], 4);

	choicecars[playerid][10] = CreatePlayerTextDraw(playerid, 272.400024, 381.297821, "—“Œ»ÃŒ—“‹: 7000000 –”¡");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][10], 0.179995, 1.669687);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][10], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][10], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][10], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][10], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][10], 1);

	choicecars[playerid][11] = CreatePlayerTextDraw(playerid, 277.599914, 404.195587, "OTMEHA");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][11], 0.207194, 1.430755);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][11], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][11], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][11], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][11], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][11], 1);

	choicecars[playerid][12] = CreatePlayerTextDraw(playerid, 276.599975, 426.102325, "œ–Œ…“» “≈—“-ƒ–¿…¬");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][12], 0.207194, 1.430755);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][12], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][12], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][12], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][12], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][12], 1);

	choicecars[playerid][13] = CreatePlayerTextDraw(playerid, 235.999938, 423.608703, "< < <");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][13], 0.277999, 1.833953);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][13], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][13], 337058303);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][13], -247369313);
	PlayerTextDrawFont(playerid, choicecars[playerid][13], 3);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][13], 1);

	choicecars[playerid][14] = CreatePlayerTextDraw(playerid, 382.999938, 423.613281, "> > >");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][14], 0.277999, 1.833953);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][14], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][14], 337058303);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][14], -247369313);
	PlayerTextDrawFont(playerid, choicecars[playerid][14], 3);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][14], 1);

	choicecars[playerid][15] = CreatePlayerTextDraw(playerid, 395.999938, 375.333282, ">");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][15], 0.398799, 5.079462);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][15], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][15], 337058303);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][15], -247369313);
	PlayerTextDrawFont(playerid, choicecars[playerid][15], 0);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][15], 1);

	choicecars[playerid][16] = CreatePlayerTextDraw(playerid, 235.800018, 375.337646, "<");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][16], 0.398799, 5.079462);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][16], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][16], 337058303);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][16], -247369313);
	PlayerTextDrawFont(playerid, choicecars[playerid][16], 0);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][16], 1);

	choicecars[playerid][17] = CreatePlayerTextDraw(playerid, 328.600036, 404.200042, " ”œ»“‹");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][17], 0.207194, 1.430755);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][17], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][17], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][17], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][17], 2);*/
	
	choicecars[playerid][0] = CreatePlayerTextDraw(playerid, 637.314941, 250.583297, "usebox");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][0], 0.000000, 16.838151);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][0], 513.373657, 0.000000);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][0], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][0], 0);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][0], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][0], -8388353);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][0], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][0], 0);

	choicecars[playerid][1] = CreatePlayerTextDraw(playerid, 636.377746, 251.750000, "usebox");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][1], 0.000000, 16.600002);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][1], 514.310424, 0.000000);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][1], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][1], 0);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][1], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][1], 471604479);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][1], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][1], 1);

	choicecars[playerid][2] = CreatePlayerTextDraw(playerid, 543.953369, 250.833328, "¿¬“Œ—¿ÀŒÕ");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][2], 0.250409, 1.086666);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][2], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][2], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][2], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][2], 1);

	choicecars[playerid][3] = CreatePlayerTextDraw(playerid, 621.853576, 266.916687, "usebox");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][3], 0.000000, -0.586854);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][3], 526.960449, 0.000000);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][3], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][3], 0);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][3], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][3], -8388353);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][3], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][3], 0);

	choicecars[playerid][4] = CreatePlayerTextDraw(playerid, 519.590332, 249.666671, "hud:radar_impound");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][4], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][4], 11.713043, 11.666687);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][4], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][4], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][4], 4);

	choicecars[playerid][5] = CreatePlayerTextDraw(playerid, 616.169067, 250.666625, "hud:radar_truck");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][5], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][5], 11.713043, 11.666687);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][5], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][5], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][5], 4);

	choicecars[playerid][6] = CreatePlayerTextDraw(playerid, 523.806640, 267.749786, "BMW");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][6], 0.172166, 1.220833);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][6], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][6], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][6], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][6], 1);

	choicecars[playerid][7] = CreatePlayerTextDraw(playerid, 617.511108, 286.999938, "LD_BEAT:right");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][7], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][7], 12.650054, 12.250000);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][7], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][7], -8388353);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][7], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][7], 4);
	PlayerTextDrawSetSelectable(playerid, choicecars[playerid][7], true);

	choicecars[playerid][8] = CreatePlayerTextDraw(playerid, 520.590209, 286.833221, "LD_BEAT:left");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][8], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][8], 12.181537, 12.833334);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][8], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][8], -8388353);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][8], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][8], 4);
	PlayerTextDrawSetSelectable(playerid, choicecars[playerid][8], true);

	choicecars[playerid][9] = CreatePlayerTextDraw(playerid, 543.953430, 286.416534, "¬€¡Œ– ¿¬“Œ");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][9], 0.249941, 1.214999);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][9], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][9], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][9], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][9], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][9], 1);

	choicecars[playerid][10] = CreatePlayerTextDraw(playerid, 523.806518, 306.249908, "—“Œ»ÃŒ—“‹:");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][10], 0.213865, 1.337499);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][10], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][10], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][10], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][10], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][10], 1);

	choicecars[playerid][11] = CreatePlayerTextDraw(playerid, 580.092102, 306.666503, "15000000");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][11], 0.216676, 1.290833);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][11], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][11], -8388353);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][11], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][11], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][11], 1);

	choicecars[playerid][12] = CreatePlayerTextDraw(playerid, 628.881164, 326.416625, "usebox");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][12], 0.000000, -0.575930);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][12], 519.932678, 0.000000);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][12], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][12], 0);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][12], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][12], -8388353);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][12], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][12], 0);

	choicecars[playerid][13] = CreatePlayerTextDraw(playerid, 524.744079, 342.999969, "≈—À» ¬€ Œœ–≈ƒ≈À»À»—‹");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][13], 0.205431, 1.185832);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][13], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][13], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][13], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][13], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][13], 1);

	choicecars[playerid][14] = CreatePlayerTextDraw(playerid, 539.331237, 353.333312, "— ¬€¡Œ–ŒÃ ¿¬“Œ");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][14], 0.205431, 1.185832);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][14], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][14], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][14], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][14], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][14], 1);

	choicecars[playerid][15] = CreatePlayerTextDraw(playerid, 520.653259, 364.249938, "Õ¿∆Ã»“≈  ÕŒœ ”");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][15], 0.179194, 1.150832);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][15], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][15], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][15], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][15], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][15], 1);

	choicecars[playerid][16] = CreatePlayerTextDraw(playerid, 587.246276, 364.083374, " ”œ»“‹");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][16], 0.212459, 1.174166);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][16], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][16], 8388863);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][16], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][16], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][16], 1);

	choicecars[playerid][17] = CreatePlayerTextDraw(playerid, 523.338256, 385.000091, " ”œ»“‹");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][17], 0.280863, 1.308332);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][17], 567.847656, 13.416663);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][17], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][17], -1);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][17], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][17], 741092607);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][17], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][17], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][17], 1);
	PlayerTextDrawSetSelectable(playerid, choicecars[playerid][17], true);

	choicecars[playerid][18] = CreatePlayerTextDraw(playerid, 544.016235, 328.250030, "¬€¡–¿“‹ ÷¬≈“");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][18], 0.192313, 1.343333);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][18], 602.518798, -23.333341);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][18], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][18], -1);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][18], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][18], 741092607);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][18], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][18], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][18], 1);
	PlayerTextDrawSetSelectable(playerid, choicecars[playerid][18], true);

	choicecars[playerid][19] = CreatePlayerTextDraw(playerid, 527.212707, 327.500000, "hud:radar_spray");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][19], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][19], 11.713043, 11.666687);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][19], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][19], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][19], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][19], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][19], 4);

	choicecars[playerid][20] = CreatePlayerTextDraw(playerid, 608.329956, 327.916717, "hud:radar_spray");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][20], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][20], 11.713043, 11.666687);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][20], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][20], -1);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][20], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][20], 0);
	PlayerTextDrawFont(playerid, choicecars[playerid][20], 4);

	choicecars[playerid][21] = CreatePlayerTextDraw(playerid, 582.435241, 384.833312, "OTMEHA");
	PlayerTextDrawLetterSize(playerid, choicecars[playerid][21], 0.283674, 1.343333);
	PlayerTextDrawTextSize(playerid, choicecars[playerid][21], 628.755371, 26.833330);
	PlayerTextDrawAlignment(playerid, choicecars[playerid][21], 1);
	PlayerTextDrawColor(playerid, choicecars[playerid][21], -1);
	PlayerTextDrawUseBox(playerid, choicecars[playerid][21], true);
	PlayerTextDrawBoxColor(playerid, choicecars[playerid][21], 741092607);
	PlayerTextDrawSetShadow(playerid, choicecars[playerid][21], 0);
	PlayerTextDrawSetOutline(playerid, choicecars[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, choicecars[playerid][21], 51);
	PlayerTextDrawFont(playerid, choicecars[playerid][21], 2);
	PlayerTextDrawSetProportional(playerid, choicecars[playerid][21], 1);
	PlayerTextDrawSetSelectable(playerid, choicecars[playerid][21], true);
}
//==============================================================================


//=================================[ —ÔË‰ÓÏÂÚ ]================================
stock Speedometr(playerid)
{
	//‰ÓÔ.Í ÒÔË‰ÓÏÂÚÛ
	speed_textpa[playerid][0] = CreatePlayerTextDraw(playerid, 560.000000, 375.625000, "");
	PlayerTextDrawLetterSize(playerid, speed_textpa[playerid][0], 0.208997, 0.773123);
	PlayerTextDrawAlignment(playerid, speed_textpa[playerid][0], 2);
	PlayerTextDrawColor(playerid, speed_textpa[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, speed_textpa[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, speed_textpa[playerid][0], 26);
	PlayerTextDrawFont(playerid, speed_textpa[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, speed_textpa[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][0], 0);

	speed_textpa[playerid][1] = CreatePlayerTextDraw(playerid, 517.500000, 397.112457, "0");
	PlayerTextDrawLetterSize(playerid, speed_textpa[playerid][1], 0.341998, 1.232499);
	PlayerTextDrawAlignment(playerid, speed_textpa[playerid][1], 2);
	PlayerTextDrawColor(playerid, speed_textpa[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, speed_textpa[playerid][1], 1);
	PlayerTextDrawBackgroundColor(playerid, speed_textpa[playerid][1], 255);
	PlayerTextDrawFont(playerid, speed_textpa[playerid][1], 3);
	PlayerTextDrawSetProportional(playerid, speed_textpa[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][1], 0);

	speed_textpa[playerid][2] = CreatePlayerTextDraw(playerid, 517.899963, 408.787475, "000000 KM");
	PlayerTextDrawLetterSize(playerid, speed_textpa[playerid][2], 0.164000, 0.589375);
	PlayerTextDrawAlignment(playerid, speed_textpa[playerid][2], 2);
	PlayerTextDrawColor(playerid, speed_textpa[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, speed_textpa[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, speed_textpa[playerid][2], 255);
	PlayerTextDrawFont(playerid, speed_textpa[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, speed_textpa[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][2], 0);

	speed_textpa[playerid][3] = CreatePlayerTextDraw(playerid, 553.500000, 406.725036, "IIIIIIIIIIIIIIIIIIIIIIIIIIIIII");
	PlayerTextDrawLetterSize(playerid, speed_textpa[playerid][3], 0.211500, 0.943750);
	PlayerTextDrawAlignment(playerid, speed_textpa[playerid][3], 1);
	PlayerTextDrawColor(playerid, speed_textpa[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, speed_textpa[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, speed_textpa[playerid][3], 255);
	PlayerTextDrawFont(playerid, speed_textpa[playerid][3], 2);
	PlayerTextDrawSetProportional(playerid, speed_textpa[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][3], 0);

	speed_textpa[playerid][4] = CreatePlayerTextDraw(playerid, 554.500000, 391.687500, "?¡≈Õ«»Õ:~Y~_100L");
	PlayerTextDrawLetterSize(playerid, speed_textpa[playerid][4], 0.120498, 0.659375);
	PlayerTextDrawAlignment(playerid, speed_textpa[playerid][4], 1);
	PlayerTextDrawColor(playerid, speed_textpa[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, speed_textpa[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, speed_textpa[playerid][4], 255);
	PlayerTextDrawFont(playerid, speed_textpa[playerid][4], 2);
	PlayerTextDrawSetProportional(playerid, speed_textpa[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][4], 0);

	speed_textpa[playerid][5] = CreatePlayerTextDraw(playerid, 554.500000, 400.288024, "—Œ—“ŒﬂÕ»≈:_~g~100 hp");
	PlayerTextDrawLetterSize(playerid, speed_textpa[playerid][5], 0.120498, 0.659375);
	PlayerTextDrawAlignment(playerid, speed_textpa[playerid][5], 1);
	PlayerTextDrawColor(playerid, speed_textpa[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, speed_textpa[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, speed_textpa[playerid][5], 255);
	PlayerTextDrawFont(playerid, speed_textpa[playerid][5], 2);
	PlayerTextDrawSetProportional(playerid, speed_textpa[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][5], 0);

	speed_textpa[playerid][6] = CreatePlayerTextDraw(playerid, 507.699920, 426.324951, "LD_BEAT:chit");
	PlayerTextDrawLetterSize(playerid, speed_textpa[playerid][6], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, speed_textpa[playerid][6], 4.000000, 3.119997);
	PlayerTextDrawAlignment(playerid, speed_textpa[playerid][6], 1);
	PlayerTextDrawColor(playerid, speed_textpa[playerid][6], 2090745855);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, speed_textpa[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, speed_textpa[playerid][6], 255);
	PlayerTextDrawFont(playerid, speed_textpa[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, speed_textpa[playerid][6], 0);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][6], 0);

	speed_textpa[playerid][7] = CreatePlayerTextDraw(playerid, 542.002014, 426.324951, "LD_BEAT:chit");
	PlayerTextDrawLetterSize(playerid, speed_textpa[playerid][7], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, speed_textpa[playerid][7], 4.000000, 3.119997);
	PlayerTextDrawAlignment(playerid, speed_textpa[playerid][7], 1);
	PlayerTextDrawColor(playerid, speed_textpa[playerid][7], 2090745855);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, speed_textpa[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, speed_textpa[playerid][7], 255);
	PlayerTextDrawFont(playerid, speed_textpa[playerid][7], 4);
	PlayerTextDrawSetProportional(playerid, speed_textpa[playerid][7], 0);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][7], 0);

	speed_textpa[playerid][8] = CreatePlayerTextDraw(playerid, 587.101806, 426.324951, "LD_BEAT:chit");
	PlayerTextDrawLetterSize(playerid, speed_textpa[playerid][8], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, speed_textpa[playerid][8], 4.000000, 3.119997);
	PlayerTextDrawAlignment(playerid, speed_textpa[playerid][8], 1);
	PlayerTextDrawColor(playerid, speed_textpa[playerid][8], -1523963137);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, speed_textpa[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, speed_textpa[playerid][8], 255);
	PlayerTextDrawFont(playerid, speed_textpa[playerid][8], 4);
	PlayerTextDrawSetProportional(playerid, speed_textpa[playerid][8], 0);
	PlayerTextDrawSetShadow(playerid, speed_textpa[playerid][8], 0);
}
//==============================================================================
/*stock CreateSpeedometrTextdraws(playerid)
{
	pSpeed_PTD[playerid][0] = CreatePlayerTextDraw(playerid, 598.0000, 416.4889, "100%"); // ÔÛÒÚÓ
	PlayerTextDrawLetterSize(playerid, pSpeed_PTD[playerid][0], 0.2009, 1.1022);
	PlayerTextDrawAlignment(playerid, pSpeed_PTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, pSpeed_PTD[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, pSpeed_PTD[playerid][0], 255);
	PlayerTextDrawFont(playerid, pSpeed_PTD[playerid][0], 2);
	PlayerTextDrawSetProportional(playerid, pSpeed_PTD[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, pSpeed_PTD[playerid][0], 0);

	pSpeed_PTD[playerid][1] = CreatePlayerTextDraw(playerid, 493.5000, 376.0445, "HP~n~åPOÄEÇ~n~çÖå"); // ÔÛÒÚÓ
	PlayerTextDrawLetterSize(playerid, pSpeed_PTD[playerid][1], 0.2054, 1.1831);
	PlayerTextDrawAlignment(playerid, pSpeed_PTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, pSpeed_PTD[playerid][1], -1);
	PlayerTextDrawBackgroundColor(playerid, pSpeed_PTD[playerid][1], 255);
	PlayerTextDrawFont(playerid, pSpeed_PTD[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, pSpeed_PTD[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, pSpeed_PTD[playerid][1], 0);

	pSpeed_PTD[playerid][2] = CreatePlayerTextDraw(playerid, 528.4984, 375.9223, "100%~n~1.200_KM~n~ECèí"); // ÔÛÒÚÓ
	PlayerTextDrawLetterSize(playerid, pSpeed_PTD[playerid][2], 0.2054, 1.1831);
	PlayerTextDrawAlignment(playerid, pSpeed_PTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, pSpeed_PTD[playerid][2], -19909889);
	PlayerTextDrawBackgroundColor(playerid, pSpeed_PTD[playerid][2], 255);
	PlayerTextDrawFont(playerid, pSpeed_PTD[playerid][2], 2);
	PlayerTextDrawSetProportional(playerid, pSpeed_PTD[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, pSpeed_PTD[playerid][2], 0);

	pSpeed_PTD[playerid][3] = CreatePlayerTextDraw(playerid, 569.0000, 375.4223, "ÉBÖÇ.~n~ÉBEPÖ~n~ÅAPë"); // ÔÛÒÚÓ
	PlayerTextDrawLetterSize(playerid, pSpeed_PTD[playerid][3], 0.2054, 1.1831);
	PlayerTextDrawAlignment(playerid, pSpeed_PTD[playerid][3], 1);
	PlayerTextDrawColor(playerid, pSpeed_PTD[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, pSpeed_PTD[playerid][3], 255);
	PlayerTextDrawFont(playerid, pSpeed_PTD[playerid][3], 2);
	PlayerTextDrawSetProportional(playerid, pSpeed_PTD[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, pSpeed_PTD[playerid][3], 0);

	pSpeed_PTD[playerid][4] = CreatePlayerTextDraw(playerid, 607.5996, 375.2445, "LD_BEAT:Chit"); // ÔÛÒÚÓ
	PlayerTextDrawTextSize(playerid, pSpeed_PTD[playerid][4], 10.0000, 12.0000);
	PlayerTextDrawAlignment(playerid, pSpeed_PTD[playerid][4], 1);
	PlayerTextDrawColor(playerid, pSpeed_PTD[playerid][4], -19909889);
	PlayerTextDrawBackgroundColor(playerid, pSpeed_PTD[playerid][4], 255);
	PlayerTextDrawFont(playerid, pSpeed_PTD[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, pSpeed_PTD[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, pSpeed_PTD[playerid][4], 0);

	pSpeed_PTD[playerid][5] = CreatePlayerTextDraw(playerid, 607.5996, 385.6451, "LD_BEAT:Chit"); // ÔÛÒÚÓ
	PlayerTextDrawTextSize(playerid, pSpeed_PTD[playerid][5], 10.0000, 12.0000);
	PlayerTextDrawAlignment(playerid, pSpeed_PTD[playerid][5], 1);
	PlayerTextDrawColor(playerid, pSpeed_PTD[playerid][5], -1523963137);
	PlayerTextDrawBackgroundColor(playerid, pSpeed_PTD[playerid][5], 255);
	PlayerTextDrawFont(playerid, pSpeed_PTD[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, pSpeed_PTD[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, pSpeed_PTD[playerid][5], 0);

	pSpeed_PTD[playerid][6] = CreatePlayerTextDraw(playerid, 607.5996, 396.3458, "LD_BEAT:Chit"); // ÔÛÒÚÓ
	PlayerTextDrawTextSize(playerid, pSpeed_PTD[playerid][6], 10.0000, 12.0000);
	PlayerTextDrawAlignment(playerid, pSpeed_PTD[playerid][6], 1);
	PlayerTextDrawColor(playerid, pSpeed_PTD[playerid][6], 8388863);
	PlayerTextDrawBackgroundColor(playerid, pSpeed_PTD[playerid][6], 255);
	PlayerTextDrawFont(playerid, pSpeed_PTD[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, pSpeed_PTD[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, pSpeed_PTD[playerid][6], 0);

	pSpeed_PTD[playerid][7] = CreatePlayerTextDraw(playerid, 460.5000, 382.8889, "120"); // ÔÛÒÚÓ
	PlayerTextDrawLetterSize(playerid, pSpeed_PTD[playerid][7], 0.5965, 2.9751);
	PlayerTextDrawAlignment(playerid, pSpeed_PTD[playerid][7], 2);
	PlayerTextDrawColor(playerid, pSpeed_PTD[playerid][7], -1);
	PlayerTextDrawBackgroundColor(playerid, pSpeed_PTD[playerid][7], 255);
	PlayerTextDrawFont(playerid, pSpeed_PTD[playerid][7], 2);
	PlayerTextDrawSetProportional(playerid, pSpeed_PTD[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, pSpeed_PTD[playerid][7], 1);
}
*/
CreateReconTextDraws(playerid)
{
	pOdminPanel_PTD[playerid][0] = CreatePlayerTextDraw(playerid, 213.0000, 308.8445, "MARK_RICHARDS_(500)_FPS:_100_I_PING:_110"); // ÔÛÒÚÓ
	PlayerTextDrawLetterSize(playerid, pOdminPanel_PTD[playerid][0], 0.1824, 1.1457);
	PlayerTextDrawTextSize(playerid, pOdminPanel_PTD[playerid][0], 475.0000, 0.0000);
	PlayerTextDrawAlignment(playerid, pOdminPanel_PTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, pOdminPanel_PTD[playerid][0], 589505535);
	PlayerTextDrawUseBox(playerid, pOdminPanel_PTD[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, pOdminPanel_PTD[playerid][0], -19909889);
	PlayerTextDrawBackgroundColor(playerid, pOdminPanel_PTD[playerid][0], 255);
	PlayerTextDrawFont(playerid, pOdminPanel_PTD[playerid][0], 2);
	PlayerTextDrawSetProportional(playerid, pOdminPanel_PTD[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, pOdminPanel_PTD[playerid][0], 0);

	pOdminPanel_PTD[playerid][1] = CreatePlayerTextDraw(playerid, 428.7999, 326.4667, "CKOPOCèí:_100_KM/ç"); // ÔÛÒÚÓ
	PlayerTextDrawLetterSize(playerid, pOdminPanel_PTD[playerid][1], 0.2004, 1.0337);
	PlayerTextDrawTextSize(playerid, pOdminPanel_PTD[playerid][1], 5.0000, 92.0000);
	PlayerTextDrawAlignment(playerid, pOdminPanel_PTD[playerid][1], 2);
	PlayerTextDrawColor(playerid, pOdminPanel_PTD[playerid][1], -1);
	PlayerTextDrawUseBox(playerid, pOdminPanel_PTD[playerid][1], 1);
	PlayerTextDrawBoxColor(playerid, pOdminPanel_PTD[playerid][1], 589505535);
	PlayerTextDrawBackgroundColor(playerid, pOdminPanel_PTD[playerid][1], -1523963137);
	PlayerTextDrawFont(playerid, pOdminPanel_PTD[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, pOdminPanel_PTD[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, pOdminPanel_PTD[playerid][1], 0);
	PlayerTextDrawSetSelectable(playerid, pOdminPanel_PTD[playerid][1], true);

	pOdminPanel_PTD[playerid][2] = CreatePlayerTextDraw(playerid, 429.2999, 342.2448, "MAKC:_147_KM/ç"); // ÔÛÒÚÓ
	PlayerTextDrawLetterSize(playerid, pOdminPanel_PTD[playerid][2], 0.2004, 1.0337);
	PlayerTextDrawTextSize(playerid, pOdminPanel_PTD[playerid][2], 5.0000, 92.0000);
	PlayerTextDrawAlignment(playerid, pOdminPanel_PTD[playerid][2], 2);
	PlayerTextDrawColor(playerid, pOdminPanel_PTD[playerid][2], -1);
	PlayerTextDrawUseBox(playerid, pOdminPanel_PTD[playerid][2], 1);
	PlayerTextDrawBoxColor(playerid, pOdminPanel_PTD[playerid][2], -1523963137);
	PlayerTextDrawBackgroundColor(playerid, pOdminPanel_PTD[playerid][2], -1523963137);
	PlayerTextDrawFont(playerid, pOdminPanel_PTD[playerid][2], 2);
	PlayerTextDrawSetProportional(playerid, pOdminPanel_PTD[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, pOdminPanel_PTD[playerid][2], 0);
	PlayerTextDrawSetSelectable(playerid, pOdminPanel_PTD[playerid][2], true);

	pOdminPanel_PTD[playerid][3] = CreatePlayerTextDraw(playerid, 429.2999, 358.4226, "çÖå:_HEè"); // ÔÛÒÚÓ
	PlayerTextDrawLetterSize(playerid, pOdminPanel_PTD[playerid][3], 0.2004, 1.0337);
	PlayerTextDrawTextSize(playerid, pOdminPanel_PTD[playerid][3], 5.0000, 92.0000);
	PlayerTextDrawAlignment(playerid, pOdminPanel_PTD[playerid][3], 2);
	PlayerTextDrawColor(playerid, pOdminPanel_PTD[playerid][3], -1);
	PlayerTextDrawUseBox(playerid, pOdminPanel_PTD[playerid][3], 1);
	PlayerTextDrawBoxColor(playerid, pOdminPanel_PTD[playerid][3], -1523963137);
	PlayerTextDrawBackgroundColor(playerid, pOdminPanel_PTD[playerid][3], -1523963137);
	PlayerTextDrawFont(playerid, pOdminPanel_PTD[playerid][3], 2);
	PlayerTextDrawSetProportional(playerid, pOdminPanel_PTD[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, pOdminPanel_PTD[playerid][3], 0);
	PlayerTextDrawSetSelectable(playerid, pOdminPanel_PTD[playerid][3], true);

	pOdminPanel_PTD[playerid][4] = CreatePlayerTextDraw(playerid, 428.7999, 374.6004, "HP:_1000"); // ÔÛÒÚÓ
	PlayerTextDrawLetterSize(playerid, pOdminPanel_PTD[playerid][4], 0.2004, 1.0337);
	PlayerTextDrawTextSize(playerid, pOdminPanel_PTD[playerid][4], 5.0000, 92.0000);
	PlayerTextDrawAlignment(playerid, pOdminPanel_PTD[playerid][4], 2);
	PlayerTextDrawColor(playerid, pOdminPanel_PTD[playerid][4], -1);
	PlayerTextDrawUseBox(playerid, pOdminPanel_PTD[playerid][4], 1);
	PlayerTextDrawBoxColor(playerid, pOdminPanel_PTD[playerid][4], 589505535);
	PlayerTextDrawBackgroundColor(playerid, pOdminPanel_PTD[playerid][4], -1523963137);
	PlayerTextDrawFont(playerid, pOdminPanel_PTD[playerid][4], 2);
	PlayerTextDrawSetProportional(playerid, pOdminPanel_PTD[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, pOdminPanel_PTD[playerid][4], 0);
}