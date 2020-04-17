// СИСТЕМА АВТОШКОЛЫ




forward autoschool_DestroyTeoriya(playerid);
public autoschool_DestroyTeoriya(playerid) {

	TextDrawDestroy(autoschool_Interact[playerid]);
	for(new i; i < 7; i++) {
			TextDrawDestroy(autoschool_vopros[playerid][i]);
			for(new d; d < 3; d++) TextDrawDestroy(autoschool_otvet[playerid][i][d]);
	}
	return 1;
}


forward autoschool_AnswerTeoriya(playerid);
public autoschool_AnswerTeoriya(playerid) {

	autoschool_DestroyTeoriya(playerid);


	switch (GetPVarInt(playerid, "autoschool_Progress")) {

		case 1: { // первый вопрос

			autoschool_vopros[playerid][0] = TextDrawCreate(203.464141, 134.999984, "autoschool:vopros_01"); 
			TextDrawLetterSize(autoschool_vopros[playerid][0], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_vopros[playerid][0], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_vopros[playerid][0], 1); 
			TextDrawColor(autoschool_vopros[playerid][0], -1); 
			TextDrawSetShadow(autoschool_vopros[playerid][0], 0); 
			TextDrawSetOutline(autoschool_vopros[playerid][0], 0); 
			TextDrawFont(autoschool_vopros[playerid][0], 4);
			TextDrawSetSelectable(autoschool_vopros[playerid][0], 1);

			autoschool_otvet[playerid][0][0] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet1_01"); 
			TextDrawLetterSize(autoschool_otvet[playerid][0][0], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][0][0], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][0][0], 1); 
			TextDrawColor(autoschool_otvet[playerid][0][0], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][0][0], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][0][0], 0); 
			TextDrawFont(autoschool_otvet[playerid][0][0], 4); 
			TextDrawSetSelectable(autoschool_otvet[playerid][0][0], 1); 

			autoschool_otvet[playerid][0][1] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet1_02"); 
			TextDrawLetterSize(autoschool_otvet[playerid][0][1], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][0][1], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][0][1], 1); 
			TextDrawColor(autoschool_otvet[playerid][0][1], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][0][1], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][0][1], 0); 
			TextDrawFont(autoschool_otvet[playerid][0][1], 4); 

			autoschool_otvet[playerid][0][2] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet1_03"); 
			TextDrawLetterSize(autoschool_otvet[playerid][0][2], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][0][2], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][0][2], 1); 
			TextDrawColor(autoschool_otvet[playerid][0][2], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][0][2], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][0][2], 0); 
			TextDrawFont(autoschool_otvet[playerid][0][2], 4); 
		}
		case 2: { // 2ой вопрос


			autoschool_vopros[playerid][1] = TextDrawCreate(203.464141, 134.999984, "autoschool:vopros_02"); 
			TextDrawLetterSize(autoschool_vopros[playerid][1], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_vopros[playerid][1], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_vopros[playerid][1], 1); 
			TextDrawColor(autoschool_vopros[playerid][1], -1); 
			TextDrawSetShadow(autoschool_vopros[playerid][1], 0); 
			TextDrawSetOutline(autoschool_vopros[playerid][1], 0); 
			TextDrawFont(autoschool_vopros[playerid][1], 4);
			TextDrawSetSelectable(autoschool_vopros[playerid][1], 1);

			autoschool_otvet[playerid][1][0] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet2_01"); 
			TextDrawLetterSize(autoschool_otvet[playerid][1][0], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][1][0], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][1][0], 1); 
			TextDrawColor(autoschool_otvet[playerid][1][0], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][1][0], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][1][0], 0); 
			TextDrawFont(autoschool_otvet[playerid][1][0], 4); 
			TextDrawSetSelectable(autoschool_otvet[playerid][1][0], 1); 

			autoschool_otvet[playerid][1][1] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet2_02"); 
			TextDrawLetterSize(autoschool_otvet[playerid][1][1], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][1][1], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][1][1], 1); 
			TextDrawColor(autoschool_otvet[playerid][1][1], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][1][1], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][1][1], 0); 
			TextDrawFont(autoschool_otvet[playerid][1][1], 4); 

			autoschool_otvet[playerid][1][2] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet2_03"); 
			TextDrawLetterSize(autoschool_otvet[playerid][1][2], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][1][2], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][1][2], 1); 
			TextDrawColor(autoschool_otvet[playerid][1][2], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][1][2], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][1][2], 0); 
			TextDrawFont(autoschool_otvet[playerid][1][2], 4); 

		}

		case 3: { // 3ий вопрос


			autoschool_vopros[playerid][2] = TextDrawCreate(203.464141, 134.999984, "autoschool:vopros_03"); 
			TextDrawLetterSize(autoschool_vopros[playerid][2], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_vopros[playerid][2], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_vopros[playerid][2], 1); 
			TextDrawColor(autoschool_vopros[playerid][2], -1); 
			TextDrawSetShadow(autoschool_vopros[playerid][2], 0); 
			TextDrawSetOutline(autoschool_vopros[playerid][2], 0); 
			TextDrawFont(autoschool_vopros[playerid][2], 4);
			TextDrawSetSelectable(autoschool_vopros[playerid][2], 1);

			autoschool_otvet[playerid][2][0] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet3_01"); 
			TextDrawLetterSize(autoschool_otvet[playerid][2][0], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][2][0], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][2][0], 1); 
			TextDrawColor(autoschool_otvet[playerid][2][0], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][2][0], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][2][0], 0); 
			TextDrawFont(autoschool_otvet[playerid][2][0], 4); 
			TextDrawSetSelectable(autoschool_otvet[playerid][2][0], 1); 

			autoschool_otvet[playerid][2][1] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet3_02"); 
			TextDrawLetterSize(autoschool_otvet[playerid][2][1], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][2][1], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][2][1], 1); 
			TextDrawColor(autoschool_otvet[playerid][2][1], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][2][1], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][2][1], 0); 
			TextDrawFont(autoschool_otvet[playerid][2][1], 4); 

			autoschool_otvet[playerid][2][2] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet3_03"); 
			TextDrawLetterSize(autoschool_otvet[playerid][2][2], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][2][2], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][2][2], 1); 
			TextDrawColor(autoschool_otvet[playerid][2][2], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][2][2], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][2][2], 0); 
			TextDrawFont(autoschool_otvet[playerid][2][2], 4); 


		}
		case 4: { // 4ый вопрос


			autoschool_vopros[playerid][3] = TextDrawCreate(203.464141, 134.999984, "autoschool:vopros_04"); 
			TextDrawLetterSize(autoschool_vopros[playerid][3], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_vopros[playerid][3], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_vopros[playerid][3], 1); 
			TextDrawColor(autoschool_vopros[playerid][3], -1); 
			TextDrawSetShadow(autoschool_vopros[playerid][3], 0); 
			TextDrawSetOutline(autoschool_vopros[playerid][3], 0); 
			TextDrawFont(autoschool_vopros[playerid][3], 4);
			TextDrawSetSelectable(autoschool_vopros[playerid][3], 1);

			autoschool_otvet[playerid][3][0] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet4_01"); 
			TextDrawLetterSize(autoschool_otvet[playerid][3][0], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][3][0], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][3][0], 1); 
			TextDrawColor(autoschool_otvet[playerid][3][0], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][3][0], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][3][0], 0); 
			TextDrawFont(autoschool_otvet[playerid][3][0], 4); 
			TextDrawSetSelectable(autoschool_otvet[playerid][3][0], 1); 

			autoschool_otvet[playerid][3][1] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet4_02"); 
			TextDrawLetterSize(autoschool_otvet[playerid][3][1], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][3][1], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][3][1], 1); 
			TextDrawColor(autoschool_otvet[playerid][3][1], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][3][1], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][3][1], 0); 
			TextDrawFont(autoschool_otvet[playerid][3][1], 4); 

			autoschool_otvet[playerid][3][2] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet4_03"); 
			TextDrawLetterSize(autoschool_otvet[playerid][3][2], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][3][2], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][3][2], 1); 
			TextDrawColor(autoschool_otvet[playerid][3][2], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][3][2], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][3][2], 0); 
			TextDrawFont(autoschool_otvet[playerid][3][2], 4); 



		} 
		case 5: { // 5ый вопрос


			autoschool_vopros[playerid][4] = TextDrawCreate(203.464141, 134.999984, "autoschool:vopros_05"); 
			TextDrawLetterSize(autoschool_vopros[playerid][4], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_vopros[playerid][4], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_vopros[playerid][4], 1); 
			TextDrawColor(autoschool_vopros[playerid][4], -1); 
			TextDrawSetShadow(autoschool_vopros[playerid][4], 0); 
			TextDrawSetOutline(autoschool_vopros[playerid][4], 0); 
			TextDrawFont(autoschool_vopros[playerid][4], 4);
			TextDrawSetSelectable(autoschool_vopros[playerid][4], 1);

			autoschool_otvet[playerid][4][0] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet5_01"); 
			TextDrawLetterSize(autoschool_otvet[playerid][4][0], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][4][0], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][4][0], 1); 
			TextDrawColor(autoschool_otvet[playerid][4][0], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][4][0], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][4][0], 0); 
			TextDrawFont(autoschool_otvet[playerid][4][0], 4); 
			TextDrawSetSelectable(autoschool_otvet[playerid][4][0], 1); 

			autoschool_otvet[playerid][4][1] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet5_02"); 
			TextDrawLetterSize(autoschool_otvet[playerid][4][1], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][4][1], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][4][1], 1); 
			TextDrawColor(autoschool_otvet[playerid][4][1], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][4][1], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][4][1], 0); 
			TextDrawFont(autoschool_otvet[playerid][4][1], 4); 

			autoschool_otvet[playerid][4][2] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet5_03"); 
			TextDrawLetterSize(autoschool_otvet[playerid][4][2], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][4][2], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][4][2], 1); 
			TextDrawColor(autoschool_otvet[playerid][4][2], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][4][2], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][4][2], 0); 
			TextDrawFont(autoschool_otvet[playerid][4][2], 4); 



		}
		case 6: { // 6ой вопрос


			autoschool_vopros[playerid][5] = TextDrawCreate(203.464141, 134.999984, "autoschool:vopros_06"); 
			TextDrawLetterSize(autoschool_vopros[playerid][5], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_vopros[playerid][5], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_vopros[playerid][5], 1); 
			TextDrawColor(autoschool_vopros[playerid][5], -1); 
			TextDrawSetShadow(autoschool_vopros[playerid][5], 0); 
			TextDrawSetOutline(autoschool_vopros[playerid][5], 0); 
			TextDrawFont(autoschool_vopros[playerid][5], 4);
			TextDrawSetSelectable(autoschool_vopros[playerid][5], 1);

			autoschool_otvet[playerid][5][0] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet6_01"); 
			TextDrawLetterSize(autoschool_otvet[playerid][5][0], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][5][0], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][5][0], 1); 
			TextDrawColor(autoschool_otvet[playerid][5][0], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][5][0], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][5][0], 0); 
			TextDrawFont(autoschool_otvet[playerid][5][0], 4); 
			TextDrawSetSelectable(autoschool_otvet[playerid][5][0], 1); 

			autoschool_otvet[playerid][5][1] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet6_02"); 
			TextDrawLetterSize(autoschool_otvet[playerid][5][1], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][5][1], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][5][1], 1); 
			TextDrawColor(autoschool_otvet[playerid][5][1], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][5][1], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][5][1], 0); 
			TextDrawFont(autoschool_otvet[playerid][5][1], 4); 


		} 
		case 7: { // 7ой вопрос


			autoschool_vopros[playerid][6] = TextDrawCreate(203.464141, 134.999984, "autoschool:vopros_07"); 
			TextDrawLetterSize(autoschool_vopros[playerid][6], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_vopros[playerid][6], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_vopros[playerid][6], 1); 
			TextDrawColor(autoschool_vopros[playerid][6], -1); 
			TextDrawSetShadow(autoschool_vopros[playerid][6], 0); 
			TextDrawSetOutline(autoschool_vopros[playerid][6], 0); 
			TextDrawFont(autoschool_vopros[playerid][6], 4);
			TextDrawSetSelectable(autoschool_vopros[playerid][6], 1);

			autoschool_otvet[playerid][6][0] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet7_01"); 
			TextDrawLetterSize(autoschool_otvet[playerid][6][0], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][6][0], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][6][0], 1); 
			TextDrawColor(autoschool_otvet[playerid][6][0], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][6][0], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][6][0], 0); 
			TextDrawFont(autoschool_otvet[playerid][6][0], 4); 
			TextDrawSetSelectable(autoschool_otvet[playerid][6][0], 1); 

			autoschool_otvet[playerid][6][1] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet7_02"); 
			TextDrawLetterSize(autoschool_otvet[playerid][6][1], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][6][1], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][6][1], 1); 
			TextDrawColor(autoschool_otvet[playerid][6][1], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][6][1], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][6][1], 0); 
			TextDrawFont(autoschool_otvet[playerid][6][1], 4); 

			autoschool_otvet[playerid][5][2] = TextDrawCreate(203.806747, 134.749969, "autoschool:otvet7_03"); 
			TextDrawLetterSize(autoschool_otvet[playerid][5][2], 0.000000, 0.000000); 
			TextDrawTextSize(autoschool_otvet[playerid][5][2], 236.603210, 221.083251); 
			TextDrawAlignment(autoschool_otvet[playerid][5][2], 1); 
			TextDrawColor(autoschool_otvet[playerid][5][2], -1); 
			TextDrawSetShadow(autoschool_otvet[playerid][5][2], 0); 
			TextDrawSetOutline(autoschool_otvet[playerid][5][2], 0); 
			TextDrawFont(autoschool_otvet[playerid][5][2], 4); 

		} 
	}

	autoschool_Interact[playerid] = TextDrawCreate(352.922363, 315.333007, "usebox"); 
	TextDrawLetterSize(autoschool_Interact[playerid], 0.000000, 1.951853); 
	TextDrawTextSize(autoschool_Interact[playerid], 288.483123, 0.000000); 
	TextDrawAlignment(autoschool_Interact[playerid], 1); 
	TextDrawColor(autoschool_Interact[playerid], 0); 
	TextDrawUseBox(autoschool_Interact[playerid], true); 
	TextDrawBoxColor(autoschool_Interact[playerid], 102); 
	TextDrawSetShadow(autoschool_Interact[playerid], 0); 
	TextDrawSetOutline(autoschool_Interact[playerid], 0); 
	TextDrawFont(autoschool_Interact[playerid], 0); 

	SelectTextDraw(playerid, -1);


	return 1;
}




forward as_OnPlayerClickTextDraw(playerid, Text:clickedid);
public as_OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	new atp = GetPVarInt(playerid, "autoschool_Progress");
	if(atp) {
		if(clickedid == autoschool_Interact[playerid]) {
			if(!selectedOtvet[playerid]) SendErr(playerid, "Сначала выберите вариант ответа!");
			switch(atp){
				case 1: {
					if(selectedOtvet[playerid] == 2) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						autoschool_AnswerTeoriya(playerid);
						selectedOtvet[playerid] = 0;
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
				case 2: {
					if(selectedOtvet[playerid] == 2) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						autoschool_AnswerTeoriya(playerid);
						selectedOtvet[playerid] = 0;
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
				case 3: {
					if(selectedOtvet[playerid] == 1) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						autoschool_AnswerTeoriya(playerid);
						selectedOtvet[playerid] = 0;
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
				case 4: {
					if(selectedOtvet[playerid] == 2) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						autoschool_AnswerTeoriya(playerid);
						selectedOtvet[playerid] = 0;
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
				case 5: {
					if(selectedOtvet[playerid] == 2) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						autoschool_AnswerTeoriya(playerid);
						selectedOtvet[playerid] = 0;
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
				case 6: {
					if(selectedOtvet[playerid] == 2) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						autoschool_AnswerTeoriya(playerid);
						selectedOtvet[playerid] = 0;
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
				case 7: {
					if(selectedOtvet[playerid] == 3) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						SendSucces(playerid, "Вы прошли теоритический тест, теперь подойдите к менеджеру за практикой!");
						SendAttention(playerid, "Практику лучше пройти прямо сейчас, так как теоритический аттестат обнуляется через время!");
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
			}
		}
		
		if(clickedid == autoschool_otvet[playerid][atp][0]) selectedOtvet[playerid] = 1;
		else if(clickedid == autoschool_otvet[playerid][atp][1]) selectedOtvet[playerid] = 2;
		else if(clickedid == autoschool_otvet[playerid][atp][2]) selectedOtvet[playerid] = 3;
		SendPond(playerid, "Вы выбрали этот вариант ответа, чтобы продолжить нажмите {FFCC00}ОК");
	}
        
        // #if defined test_OnPlayerClickTextDraw 
        //         test_OnPlayerClickTextDraw(playerid, Text:clickedid); 
        // #endif 
        //  return 1;
}

// #if defined _ALS_OnPlayerClickTextDraw 
//     #undef OnPlayerClickTextDraw
// #else 
//     #define _ALS_OnPlayerClickTextDraw 
// #endif 
// #define OnPlayerClickTextDraw test_OnPlayerClickTextDraw 
// #if defined test_OnPlayerClickTextDraw 
// forward test_OnPlayerClickTextDraw(playerid, Text:clickedid); 
// #endif 


/*public OnPlayerClickTextDraw(playerid, Text:clickedid)
{ 

	new atp = GetPVarInt(playerid, "autoschool_Progress");
	if(atp) {
		if(clickedid == autoschool_Interact[playerid]) {
			if(!selectedOtvet[playerid]) SendErr(playerid, "Сначала выберите вариант ответа!");
			switch(atp){
				case 1: {
					if(selectedOtvet[playerid] == 2) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						autoschool_AnswerTeoriya(playerid);
						selectedOtvet[playerid] = 0;
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
				case 2: {
					if(selectedOtvet[playerid] == 2) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						autoschool_AnswerTeoriya(playerid);
						selectedOtvet[playerid] = 0;
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
				case 3: {
					if(selectedOtvet[playerid] == 1) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						autoschool_AnswerTeoriya(playerid);
						selectedOtvet[playerid] = 0;
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
				case 4: {
					if(selectedOtvet[playerid] == 2) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						autoschool_AnswerTeoriya(playerid);
						selectedOtvet[playerid] = 0;
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
				case 5: {
					if(selectedOtvet[playerid] == 2) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						autoschool_AnswerTeoriya(playerid);
						selectedOtvet[playerid] = 0;
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
				case 6: {
					if(selectedOtvet[playerid] == 2) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						autoschool_AnswerTeoriya(playerid);
						selectedOtvet[playerid] = 0;
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
				case 7: {
					if(selectedOtvet[playerid] == 3) {
						SetPVarInt(playerid, "autoschool_Progress", atp+1);
						SendSucces(playerid, "Вы прошли теоритический тест, теперь подойдите к менеджеру за практикой!");
						SendAttention(playerid, "Практику лучше пройти прямо сейчас, так как теоритический аттестат обнуляется через время!");
					} else { 
						if(autoschool_errors[playerid] == 3) {
							SendErr(playerid, "Вы ответили неверно 3 раза, тест провален. Следующий тест можно пройти в следующем часу (после PayDay)!");
							autoschool_DestroyTeoriya(playerid);
						}
						SendErr(playerid, "Это неверный вариант ответа!");
						autoschool_errors[playerid]++;
					}
				}
			}
		}
		
		if(clickedid == autoschool_otvet[playerid][atp][0]) selectedOtvet[playerid] = 1;
		else if(clickedid == autoschool_otvet[playerid][atp][1]) selectedOtvet[playerid] = 2;
		else if(clickedid == autoschool_otvet[playerid][atp][2]) selectedOtvet[playerid] = 3;
		SendPond(playerid, "Вы выбрали этот вариант ответа, чтобы продолжить нажмите {FFCC00}ОК");
	}



    #if defined as_OnPlayerClickTextDraw 
        return as_OnPlayerClickTextDraw(playerid, Text:clickedid); 
    #else 
        return 1; 
    #endif 
} 

#if defined _ALS_OnPlayerClickTextDraw 
    #undef OnPlayerClickTextDraw 
#else 
    #define _ALS_OnPlayerClickTextDraw 
#endif 
#define OnPlayerClickTextDraw as_OnPlayerClickTextDraw 
#if defined as_OnPlayerClickTextDraw 
    forward as_OnPlayerClickTextDraw(playerid, Text:clickedid); 
#endif 

*/


