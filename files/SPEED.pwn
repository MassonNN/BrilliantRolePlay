//==============================================================================

SPEED0 = TextDrawCreate(531.303600, 305.083400, "speed:speed");              // - Основной спидометр
TextDrawLetterSize(SPEED0, 0.000000, 0.000000);
TextDrawTextSize(SPEED0, 114.399711, 138.250030);
TextDrawAlignment(SPEED0, 1);
TextDrawColor(SPEED0, -1);
TextDrawSetShadow(SPEED0, 0);
TextDrawSetOutline(SPEED0, 0);
TextDrawFont(SPEED0, 4);

//==========================[ ВКЛЮЧЁННЫЕ TEXTDRAW ]=============================
SPEED1 = TextDrawCreate(531.303600, 305.083400, "speed:left1");              // - Поворотник в лево ВКЛ
TextDrawLetterSize(SPEED1, 0.000000, 0.000000);
TextDrawTextSize(SPEED1, 114.399711, 138.250030);
TextDrawAlignment(SPEED1, 1);
TextDrawColor(SPEED1, -1);
TextDrawSetShadow(SPEED1, 0);
TextDrawSetOutline(SPEED1, 0);
TextDrawFont(SPEED1, 4);

SPEED2 = TextDrawCreate(531.303600, 305.083400, "speed:right1");             // - Поворотник в право ВКЛ
TextDrawLetterSize(SPEED2, 0.000000, 0.000000);
TextDrawTextSize(SPEED2, 114.399711, 138.250030);
TextDrawAlignment(SPEED2, 1);
TextDrawColor(SPEED2, -1);
TextDrawSetShadow(SPEED2, 0);
TextDrawSetOutline(SPEED2, 0);
TextDrawFont(SPEED2, 4);

SPEED3 = TextDrawCreate(531.303600, 305.083400, "speed:engine1");            // - Иконка двигателя ВКЛ
TextDrawLetterSize(SPEED3, 0.000000, 0.000000);
TextDrawTextSize(SPEED3, 114.399711, 138.250030);
TextDrawAlignment(SPEED3, 1);
TextDrawColor(SPEED3, -1);
TextDrawSetShadow(SPEED3, 0);
TextDrawSetOutline(SPEED3, 0);
TextDrawFont(SPEED3, 4);

SPEED4 = TextDrawCreate(531.303600, 305.083400, "speed:limit1");             // - Иконка лимита скорости ВКЛ
TextDrawLetterSize(SPEED4, 0.000000, 0.000000);
TextDrawTextSize(SPEED4, 114.399711, 138.250030);
TextDrawAlignment(SPEED4, 1);
TextDrawColor(SPEED4, -1);
TextDrawSetShadow(SPEED4, 0);
TextDrawSetOutline(SPEED4, 0);
TextDrawFont(SPEED4, 4);

SPEED5 = TextDrawCreate(531.303600, 305.083400, "speed:door1");              // - Иконка дверей ВКЛ
TextDrawLetterSize(SPEED5, 0.000000, 0.000000);
TextDrawTextSize(SPEED5, 114.399711, 138.250030);
TextDrawAlignment(SPEED5, 1);
TextDrawColor(SPEED5, -1);
TextDrawSetShadow(SPEED5, 0);
TextDrawSetOutline(SPEED5, 0);
TextDrawFont(SPEED5, 4);

SPEED6 = TextDrawCreate(531.303600, 305.083400, "speed:light1");             // - Иконка фар ВКЛ
TextDrawLetterSize(SPEED6, 0.000000, 0.000000);
TextDrawTextSize(SPEED6, 114.399711, 138.250030);
TextDrawAlignment(SPEED6, 1);
TextDrawColor(SPEED6, -1);
TextDrawSetShadow(SPEED6, 0);
TextDrawSetOutline(SPEED6, 0);
TextDrawFont(SPEED6, 4);

SPEED7 = TextDrawCreate(531.303600, 305.083400, "speed:middle1");            // - Аварийка ВКЛ
TextDrawLetterSize(SPEED7, 0.000000, 0.000000);
TextDrawTextSize(SPEED7, 114.399711, 138.250030);
TextDrawAlignment(SPEED7, 1);
TextDrawColor(SPEED7, -1);
TextDrawSetShadow(SPEED7, 0);
TextDrawSetOutline(SPEED7, 0);
TextDrawFont(SPEED7, 4);

//=========================[ ВЫКЛЮЧЁННЫЕ TEXTDRAW ]=============================

SPEED8 = TextDrawCreate(531.303600, 305.083400, "speed:left2");              // - Поворотник в лево ВЫКЛ
TextDrawLetterSize(SPEED8, 0.000000, 0.000000);
TextDrawTextSize(SPEED8, 114.399711, 138.250030);
TextDrawAlignment(SPEED8, 1);
TextDrawColor(SPEED8, -1);
TextDrawSetShadow(SPEED8, 0);
TextDrawSetOutline(SPEED8, 0);
TextDrawFont(SPEED8, 4);

SPEED9 = TextDrawCreate(531.303600, 305.083400, "speed:right2");             // - Поворотник в право ВЫКЛ
TextDrawLetterSize(SPEED9, 0.000000, 0.000000);
TextDrawTextSize(SPEED9, 114.399711, 138.250030);
TextDrawAlignment(SPEED9, 1);
TextDrawColor(SPEED9, -1);
TextDrawSetShadow(SPEED9, 0);
TextDrawSetOutline(SPEED9, 0);
TextDrawFont(SPEED9, 4);

SPEED10 = TextDrawCreate(531.303600, 305.083400, "speed:engine2");            // - Иконка двигателя ВЫКЛ
TextDrawLetterSize(SPEED10, 0.000000, 0.000000);
TextDrawTextSize(SPEED10, 114.399711, 138.250030);
TextDrawAlignment(SPEED10, 1);
TextDrawColor(SPEED10, -1);
TextDrawSetShadow(SPEED10, 0);
TextDrawSetOutline(SPEED10, 0);
TextDrawFont(SPEED10, 4);

SPEED11 = TextDrawCreate(531.303600, 305.083400, "speed:limit2");             // - Иконка лимита скорости ВЫКЛ
TextDrawLetterSize(SPEED11, 0.000000, 0.000000);
TextDrawTextSize(SPEED11, 114.399711, 138.250030);
TextDrawAlignment(SPEED11, 1);
TextDrawColor(SPEED11, -1);
TextDrawSetShadow(SPEED11, 0);
TextDrawSetOutline(SPEED11, 0);
TextDrawFont(SPEED11, 4);

SPEED12 = TextDrawCreate(531.303600, 305.083400, "speed:door2");              // - Иконка дверей ВЫКЛ
TextDrawLetterSize(SPEED12, 0.000000, 0.000000);
TextDrawTextSize(SPEED12, 114.399711, 138.250030);
TextDrawAlignment(SPEED12, 1);
TextDrawColor(SPEED12, -1);
TextDrawSetShadow(SPEED12, 0);
TextDrawSetOutline(SPEED12, 0);
TextDrawFont(SPEED12, 4);

SPEED13 = TextDrawCreate(531.303600, 305.083400, "speed:light2");             // - Иконка фар ВЫКЛ
TextDrawLetterSize(SPEED13, 0.000000, 0.000000);
TextDrawTextSize(SPEED13, 114.399711, 138.250030);
TextDrawAlignment(SPEED13, 1);
TextDrawColor(SPEED13, -1);
TextDrawSetShadow(SPEED13, 0);
TextDrawSetOutline(SPEED13, 0);
TextDrawFont(SPEED13, 4);

SPEED14 = TextDrawCreate(531.303600, 305.083400, "speed:middle2");            // - Аварийка ВЫКЛ
TextDrawLetterSize(SPEED14, 0.000000, 0.000000);
TextDrawTextSize(SPEED14, 114.399711, 138.250030);
TextDrawAlignment(SPEED14, 1);
TextDrawColor(SPEED14, -1);
TextDrawSetShadow(SPEED14, 0);
TextDrawSetOutline(SPEED14, 0);
TextDrawFont(SPEED14, 4);

//==============================================================================

