/*
 *
 * (c) Copyright 2016-2017, LLC CSR COMMUNITY
 *
 *
 * Основные функции для значения INT(без точки)
 * GetBalanceCSRInt("Andrew_Nest"); - возвращает кол-во донат очков - (-1) - акк несуществует
 * SetBalanceCSRInt("Andrew_Nest",0); - оннулирует донат очки у игрока - (-1) - акк несуществует (вместо 0 - можно поставить 100, в этом случае донат очки примут значение 100)
 * GiveBalanceCSRInt("Andrew_Nest",-100); - изымает с баланса 100 донат очков - (-1) - акк несуществует
 * SetNameCSR("Andrew_Nest","Lena_Nest"); - изменяет ник в базе данных доната, если это не сделать, то донат очки вайпнутся (старый ник, новый ник)
 *
 * Основные функции для значения Float(с плавающей точкой)
 * GetBalanceCSRFloat("Andrew_Nest"); - возвращает кол-во донат очков - (-1) - акк несуществует
 * SetBalanceCSRFloat("Andrew_Nest",0.00); - оннулирует донат очки у игрока - (-1) - акк несуществует(вместо 0.00 - можно поставить 100.00, в этом случае донат очки примут значение 100.00)
 * GiveBalanceCSRFloat("Andrew_Nest",-100.00); - изымает с баланса 100 донат очков - (-1) - акк несуществует
 * SetNameCSR("Andrew_Nest","Lena_Nest"); - изменяет ник в базе данных доната, если это не сделать, то донат очки вайпнутся (старый ник, новый ник)
 */
stock GetBalanceCSRInt(nicknamecsr[])//--------------------------------------------получение баланса игрока
{
	new type_data_csr;
	new idscsr[64];
	format(idscsr,sizeof(idscsr),"csr/conf.ini");
	new iniOpencsr;
	iniOpencsr = csr_openFile(idscsr);
	if(iniOpencsr == -1 || iniOpencsr == -2){iniOpencsr = csr_createFile(idscsr);csr_setInteger(iniOpencsr, "TypeCredits",1);}
    csr_getInteger(iniOpencsr, "TypeCredits",type_data_csr);
	csr_closeFile(iniOpencsr);
	//--------------------------------------------------------------------------
	new CreditsInt;
	format(idscsr,sizeof(idscsr),"csr/%s.ini",nicknamecsr);//---проверка существования пользователя
	iniOpencsr = csr_openFile(idscsr);
	if(iniOpencsr == -1 || iniOpencsr == -2) {csr_closeFile(iniOpencsr);return -1;}
	csr_getInteger(iniOpencsr, "CreditsINT",CreditsInt);
	csr_closeFile(iniOpencsr);
	if(type_data_csr == 1){
        return CreditsInt;
	}
	if(type_data_csr == 2){
		return -1;
	}
	return -1;
}
stock GetBalanceCSRFloat(nicknamecsr[])//--------------------------------------------получение баланса игрока
{
	new type_data_csr;
	new idscsr[64];
	format(idscsr,sizeof(idscsr),"csr/conf.ini");
	new iniOpencsr;
	iniOpencsr = csr_openFile(idscsr);
	if(iniOpencsr == -1 || iniOpencsr == -2){iniOpencsr = csr_createFile(idscsr);csr_setInteger(iniOpencsr, "TypeCredits",1);}
    csr_getInteger(iniOpencsr, "TypeCredits",type_data_csr);
	csr_closeFile(iniOpencsr);
	//--------------------------------------------------------------------------
	new Float:CreditsFloat;
	format(idscsr,sizeof(idscsr),"csr/%s.ini",nicknamecsr);//---проверка существования пользователя
	iniOpencsr = csr_openFile(idscsr);
	if(iniOpencsr == -1 || iniOpencsr == -2) {csr_closeFile(iniOpencsr);return -1;}
	csr_getFloat(iniOpencsr, "CreditsFLOAT",CreditsFloat);
	csr_closeFile(iniOpencsr);
	if(type_data_csr == 1){
        return -1;
	}
	if(type_data_csr == 2){
		return CreditsFloat;
	}
	return -1;
}
//------------------------------------------------------------------------------
stock SetBalanceCSRInt(nicknamecsr[],newbalancecsr)//---------------------------изменение баланса CSR на конкретное значение Int
{
    new iniOpencsr;
    new idscsr[64],balncesusercsr;
	format(idscsr,sizeof(idscsr),"csr/%s.ini",nicknamecsr);//---проверка существования пользователя
	iniOpencsr = csr_openFile(idscsr);
	if(iniOpencsr == -1 || iniOpencsr == -2) {csr_closeFile(iniOpencsr);return -1;}
	csr_setFloat(iniOpencsr, "CreditsINT",balncesusercsr);
	csr_setInteger(iniOpencsr, "CreditsINT",newbalancecsr);
	csr_closeFile(iniOpencsr);
 	balncesusercsr = newbalancecsr-balncesusercsr;
	new textforlogcsr[256];
	if(balncesusercsr > 0)
	{
		format(textforlogcsr,256,"Donate:%s:+%d",nicknamecsr,balncesusercsr);
	}else{
        format(textforlogcsr,256,"Donate:%s:%d",nicknamecsr,balncesusercsr);
	}
	InputLogsCSR(textforlogcsr);
	return 1;
}
stock SetBalanceCSRFloat(nicknamecsr[],Float:newbalancecsr)//-------------------изменение баланса CSR на конкретное значение Float
{
    new idscsr[64],Float:balncesusercsr;
	format(idscsr,sizeof(idscsr),"csr/%s.ini",nicknamecsr);//---проверка существования пользователя
	iniOpencsr = csr_openFile(idscsr);
	if(iniOpencsr == -1 || iniOpencsr == -2) {csr_closeFile(iniOpencsr);return -1;}
	csr_getFloat(iniOpencsr, "CreditsFLOAT",balncesusercsr);
	csr_setFloat(iniOpencsr, "CreditsFLOAT",newbalancecsr);
	csr_closeFile(iniOpencsr);
 	balncesusercsr = newbalancecsr-balncesusercsr;
	new textforlogcsr[256];
	if(balncesusercsr > 0)
	{
		format(textforlogcsr,256,"Donate:%s:+%d",nicknamecsr,balncesusercsr);
	}else{
        format(textforlogcsr,256,"Donate:%s:%d",nicknamecsr,balncesusercsr);
	}
	InputLogsCSR(textforlogcsr);
	return 1;
}
//------------------------------------------------------------------------------
stock GiveBalanceCSRInt(nicknamecsr[],setbalancecsr)//--------------------------изменение баланса CSR Int
{
    new idscsr[64],balncesusercsr;
	format(idscsr,sizeof(idscsr),"csr/%s.ini",nicknamecsr);//---проверка существования пользователя
	iniOpencsr = csr_openFile(idscsr);
	if(iniOpencsr == -1 || iniOpencsr == -2) {csr_closeFile(iniOpencsr);return -1;}
	csr_getInteger(iniOpencsr, "CreditsINT",balncesusercsr);
	csr_setInteger(iniOpencsr, "CreditsINT",balncesusercsr+setbalancecsr);
	csr_closeFile(iniOpencsr);
	new textforlogcsr[256];
	if(setbalancecsr > 0)
	{
		format(textforlogcsr,256,"Donate:%s:+%d",nicknamecsr,setbalancecsr);
	}else{
        format(textforlogcsr,256,"Donate:%s:%d",nicknamecsr,setbalancecsr);
	}
	InputLogsCSR(textforlogcsr);
	return 1;
}
stock GiveBalanceCSRFloat(nicknamecsr[],Float:setbalancecsr)//------------------изменение баланса CSR Float
{
    new idscsr[64],FLoat:balncesusercsr;
	format(idscsr,sizeof(idscsr),"csr/%s.ini",nicknamecsr);//---проверка существования пользователя
	iniOpencsr = csr_openFile(idscsr);
	if(iniOpencsr == -1 || iniOpencsr == -2) {csr_closeFile(iniOpencsr);return -1;}
	csr_getFloat(iniOpencsr, "CreditsFLOAT",balncesusercsr);
	csr_setFloat(iniOpencsr, "CreditsFLOAT",balncesusercsr+setbalancecsr);
	csr_closeFile(iniOpencsr);
	new textforlogcsr[256];
	if(setbalancecsr > 0)
	{
		format(textforlogcsr,256,"Donate:%s:+%.2f",nicknamecsr,setbalancecsr);
	}else{
        format(textforlogcsr,256,"Donate:%s:%.2f",nicknamecsr,setbalancecsr);
	}
	InputLogsCSR(textforlogcsr);
	return 1;
}
//------------------------------------------------------------------------------
stock InputLogsCSR(logtext[])
{
	new hourcsr,minutecsr,secondcsr,yearcsr,monthcsr,daycsr;
	gettime(hourcsr, minutecsr, secondcsr);
	getdate(yearcsr, monthcsr, daycsr);
	new stringcsr[255], stringcsr2[128], File: logs_csr;
	format(stringcsr2, sizeof(stringcsr2), "csr/logs2.txt");//------------------логирование транзакции
	logs_csr = fopen(stringcsr2, io_append);
	format(stringcsr, sizeof(stringcsr), "%s(%d:%d:%d|%d.%d.%d)\n",logtext,hourcsr,minutecsr,secondcsr,daycsr,monthcsr,yearcsr);
	fwrite(logs_csr, stringcsr);
	fclose(logs_csr);
	return 1;
}
stock SetNameCSR(nicknamecsrold,nicknamecsrnew)
{
    new idscsr[64];
	format(idscsr,sizeof(idscsr),"csr/%s.ini",nicknamecsrold);//---проверка существования пользователя
	iniOpencsr = csr_openFile(idscsr);
	if(iniOpencsr == -1 || iniOpencsr == -2) {csr_closeFile(iniOpencsr);return -1;}
    format(idscsr,sizeof(idscsr),"csr/%s.ini",nicknamecsrnew);
	csr_rename_file (iniOpencsr,idscsr,1);
	csr_closeFile(iniOpencsr);
}
//########################СНИЗУ MX_INI##########################################



#if defined _mxCSR_included
    #endinput
#endif
#define _mxCSR_included





const

    // настройки

    // РЕКОМЕНДУЕТСЯ ИЗМЕНИТЬ ПОД СЕБЯ
    CSR_MAX_OPENED_FILES    = 2,        // максимум, открытых одновременно, файлов
    CSR_MAX_FILE_SIZE       = 65536,    // байт,        макс. размер файла
    CSR_MAX_FILENAME_SIZE   = 128,      // символов,    макс. размер пути к файлу
    CSR_MAX_KEYS_IN_FILE    = 2048,     // максимум ключей в открытом файле

    // в ОЗУ будет выделено для временного хранения файлов примерно вот столько байт:
    // CSR_MAX_OPENED_FILES * ( CSR_MAX_FILE_SIZE + CSR_MAX_FILENAME_SIZE*4 + CSR_MAX_KEYS_IN_FILE*4 )


    // НЕЛЬЗЯ МЕНЯТЬ
    CSR_INTEGER_SIZE        = 12,       // размер строки с целочисленным значением
    CSR_FLOAT_SIZE          = 40,       // размер строки с дробным числовым значением

    CSR_STRING_DELIMITER    = '\n',     // разделитель строк
    CSR_DELIMITER           = '=',      // разделитель ключа и значения


    // коды ошибок, возвращаемые функциями

    // РЕКОМЕНДУЕТСЯ НЕ ИЗМЕНЯТЬ
    CSR_OK                  =  0,       // функция успешно выполнена

        // проверять на ошибку можно так:
        // if ( возвращаемое_значение_функции < 0 ) ...

    CSR_FILE_NOT_FOUND      = -1,       // файл не найден по указанному пути
    CSR_FILE_ALREADY_EXIST  = -2,       // файл не найден по указанному пути
    CSR_TOO_LARGE_FILE      = -3,       // размер файла превысил допустимый лимит
    CSR_WRONG_PATH_SIZE     = -4,       // неправильный размер пути к файлу
    CSR_READ_ERROR          = -5,       // ошибка чтения файла
    CSR_WRITE_ERROR         = -6,       // ошибка при записи в файл
    CSR_NO_FREE_SLOT        = -7,       // нет свободного слота для открытия файла
    CSR_WRONG_SLOT          = -8,       // указан неверный слот открытого файла
    CSR_KEY_NOT_FOUND       = -9,       // ключ в открытом файле не найден
    CSR_WRONG_RETURN_SIZE   = -10,      // размер строки, в которую будет помещено значение ключа - указан неверно (<= 0)


    // другие вспомогательные константы

    // НЕЛЬЗЯ МЕНЯТЬ
    cellbytes = cellbits / charbits;    // кол-во байт в одной ячейке





// списки разных символов для оператора case в одной из функций

// РЕКОМЕНДУЕТСЯ НЕ ИЗМЕНЯТЬ
#define CSR_SPACE_CHAR  ' ', '\t'                       // строковые пробельные символы
#define CSR_KEY_STARTS  ' ', '\t', '\r', '\n', '\0'     // символы, перед началом ключа
#define CSR_STRING_ENDS '\r', '\n', '\0'                // символы, завершающие значение
#define CSR_NUMBER_ENDS ' ', '\t', '\r', '\n', '\0'     // символы, завершающие численное значение





static stock

    // временное хранилище открытых файлов

    _csr_nSlotUsed      [ CSR_MAX_OPENED_FILES ],                               // флаг: занят ли слот
    _csr_nFileChanged   [ CSR_MAX_OPENED_FILES ],                               // флаг: был ли изменен файл
    _csr_nFileBusy      [ CSR_MAX_OPENED_FILES ],                               // флаг: изменяется ли в данный момент содержимое файла
    _csr_nFileSize      [ CSR_MAX_OPENED_FILES ],                               // размер открытого файла
    _csr_nDelimPos      [ CSR_MAX_OPENED_FILES ] [ CSR_MAX_KEYS_IN_FILE ],      // список позиций CSR_DELIMITER
    _csr_nKeysCount     [ CSR_MAX_OPENED_FILES ],                               // кол-во ключей открытого файла
    _csr_szFilePath     [ CSR_MAX_OPENED_FILES ] [ CSR_MAX_FILENAME_SIZE ],     // путь к файлу
    _csr_szFileContent  [ CSR_MAX_OPENED_FILES ] [ CSR_MAX_FILE_SIZE char ];    // контент файла





















/*
    Создает и сразу открывает INI файл для чтения/записи.
    ПОДРОБНЕЕ
        Файл создается только в ОЗУ, и в него записывается строка szDefaultContent.
        В szDefaultContent могут быть и ключи, которые потом парсер также будет видеть.
        Только при закрытии файла, его содержимое будет записано на диск
        по указанному пути к файлу.
    ПАРАМЕТРЫ:
        szFilePath[]        путь к файлу
        szDefaultContent    контент файла по умолчанию, обычно, можно не указывать
    ВЕРНЕТ:
        код ошибки < 0 или ИД_открытого_файла
*/
stock csr_rename_file ( file_id, new_file_name[], delete_old_file = 1 )
{
    // если указан неверный слот
    if ( file_id < 0 || file_id >= MAX_OPENED_FILES || fUsed == 0 )
        return INI_WRONG_FILE_ID;

    // если нужно удалить старый файл
    if ( delete_old_file )
    {
        // узнаем имя файла
        new fName[MAX_FILENAME_SIZE];
        getproperty( STORE_MACHINE, _, file_id, fName );
        strunpack( fName, fName );

        // удалим старый файл
        fremove(fName);
    }

    // сохраним новое имя файла в propety массиве
    setproperty( STORE_MACHINE, _, file_id, new_file_name );

    // выставим настройки файла
    fChanged = 1;

    return CSR_OK;
}
stock csr_createFile ( szFilePath[], szDefaultContent[] = "" )
{
    //
    //  несколько блоков с проверками
    //

    // ------------
    new nFileNameSize = strlen( szFilePath ); // узнаем размер пути

    // если размер пути неправильный
    if ( nFileNameSize <= 0 || nFileNameSize >= CSR_MAX_FILENAME_SIZE )
        return CSR_WRONG_PATH_SIZE; // вернем код ошибки
    // ------------


    // ------------
    if ( fexist( szFilePath ) ) // если файл уже существует
        return CSR_FILE_ALREADY_EXIST; // вернем код ошибки - файл уже существует

    for ( new slot = 0; slot < CSR_MAX_OPENED_FILES; slot++ ) // перебор всех слотов ОЗУ
        if // если уже есть такой открытый файл
        (
                _csr_nSlotUsed[slot] != 0
            &&  strcmp( szFilePath, _csr_szFilePath[slot], false ) == 0
        )
            return CSR_FILE_ALREADY_EXIST; // вернем код ошибки - файл уже существует
    // ------------



    // ------------
    new nFileSize = strlen( szDefaultContent ); // узнаем размер контентa файла по умолчанию

    // если размер неправильный
    if ( nFileSize < 0 || nFileSize >= CSR_MAX_FILE_SIZE )
        return CSR_TOO_LARGE_FILE; // вернем код ошибки
    // ------------




    //
    //  поиск свободного слота для записи в ОЗУ
    //

    for ( new slot = 0; slot < CSR_MAX_OPENED_FILES; slot++ ) // перебор всех слотов ОЗУ
    {
        if ( _csr_nSlotUsed[slot] != 1 ) // если слот найден
        {
            // ------------
            _csr_nSlotUsed[slot]        = 1; // застолбим найденное место
            _csr_nFileChanged[slot]     = 0; // файл не был изменен
            _csr_nFileSize[slot]        = nFileSize; // скопируем размер файла в слот
            _csr_nKeysCount[slot]       = 0; // кол-во ключей выставим 0
            // ------------


            // ------------
            // скопируем в ОЗУ весь файл,
            // запомнив все позиции CSR_DELIMITER и их кол-во
            for ( new i = 0;  i < nFileSize && i < CSR_MAX_FILE_SIZE;  i++ )
            {
                if (
                        szDefaultContent[i] == CSR_DELIMITER // если символ это CSR_DELIMITER
                    &&  _csr_nKeysCount[slot] < CSR_MAX_KEYS_IN_FILE // и лимит ключей еще не исчерпан
                ) {
                    _csr_nDelimPos[slot][ _csr_nKeysCount[slot] ] = i; // добавим еще одну позицию CSR_DELIMITER
                    _csr_nKeysCount[slot]++; // увеличим кол-во найденных ключей
                }

                _csr_szFileContent[slot]{i} = szDefaultContent[i];
            }

            _csr_szFileContent[slot]{nFileSize} = 0; // символ конца строки для контента
            // ------------


            // ------------
            // скопируем в озу путь к файлу
            memcpy( _csr_szFilePath[slot], szFilePath, 0, nFileNameSize * cellbytes );

            _csr_szFilePath[slot][nFileNameSize] = 0; // символ конца строки для пути
            // ------------


            return slot; // вернем ИД слота
        }
    }




    //
    //  если свободный слот в памяти не найден
    //

    return CSR_NO_FREE_SLOT; // вернем код ошибки
    // ------------
}




/*
    Открывает INI файл для чтения/записи, если он существует.
    ПОДРОБНЕЕ
        Копирует в ОЗУ с диска всё содержимое файла, если его размер не превышает
        допустимый. Если кол-во ключей в файле больше допустимого, ошибки никакой не будет,
        просто при чтении/записи значений, парсер не будет видеть лишние ключи.
    ПАРАМЕТРЫ:
        szFilePath[]    путь к файлу
    ВЕРНЕТ:
        код ошибки < 0 или ИД_открытого_файла
*/

stock csr_openFile ( szFilePath[] )
{
    //
    //  несколько блоков с проверками
    //

    // ------------
    new nFileNameSize = strlen( szFilePath ); // узнаем размер пути

    // если размер пути неправильный
    if ( nFileNameSize <= 0 || nFileNameSize >= CSR_MAX_FILENAME_SIZE )
        return CSR_WRONG_PATH_SIZE; // вернем код ошибки
    // ------------


    if ( ! fexist( szFilePath ) ) // если файл не найден
        return CSR_FILE_NOT_FOUND; // вернем код ошибки


    // ------------
    // проверка - открыт ли уже файл с таким именем
    for ( new slot = 0; slot < CSR_MAX_OPENED_FILES; slot++ ) // перебор всех слотов ОЗУ
        if // если уже есть такой открытый файл
        (
                _csr_nSlotUsed[slot] != 0
            &&  strcmp( szFilePath, _csr_szFilePath[slot], false ) == 0
        )
            return slot; // просто вернем его слот
    // ------------


    // ------------
    new File: pFile = fopen( szFilePath, io_read ); // пытаемся открыть файл для чтения

    if ( ! pFile ) // если файл не открылся
        return CSR_READ_ERROR; // вернем код ошибки
    // ------------


    // ------------
    new nFileSize = flength( pFile ); // узнаем размер файла

    if ( nFileSize >= CSR_MAX_FILE_SIZE ) // если размер файла слишком большой
    {
        fclose(pFile); // закроем файл
        return CSR_TOO_LARGE_FILE; // вернем код ошибки
    }
    // ------------




    //
    //  поиск свободного слота для записи в ОЗУ
    //

    // ------------
    for ( new slot = 0; slot < CSR_MAX_OPENED_FILES; slot++ ) // перебор всех слотов ОЗУ
    {
        if ( _csr_nSlotUsed[slot] != 1 ) // если слот найден
        {
            // ------------
            _csr_nSlotUsed[slot]        = 1; // застолбим найденное место
            _csr_nFileChanged[slot]     = 0; // файл не был изменен
            _csr_nFileSize[slot]        = nFileSize; // скопируем размер файла в слот
            _csr_nKeysCount[slot]       = 0; // кол-во ключей выставим 0
            // ------------


            // ------------
            // скопируем в ОЗУ весь файл,
            // запомнив все позиции CSR_DELIMITER и их кол-во
            for ( new i = 0, symbol, nextstr = 1; i < nFileSize && i < CSR_MAX_FILE_SIZE; i++ )
            {
                symbol = fgetchar( pFile, 0, false ); // читаем из файла следующий символ

                if ( symbol == CSR_STRING_DELIMITER ) // если начинается новая строка
                    nextstr = 1;

                if (
                        nextstr // если обрабатывается следующая строка
                    &&  symbol == CSR_DELIMITER // если символ это CSR_DELIMITER
                    &&  _csr_nKeysCount[slot] < CSR_MAX_KEYS_IN_FILE // и лимит ключей еще не исчерпан
                ) {
                    _csr_nDelimPos[slot][ _csr_nKeysCount[slot] ] = i; // добавим еще одну позицию CSR_DELIMITER
                    _csr_nKeysCount[slot]++; // увеличим кол-во найденных ключей
                    nextstr = 0; // сбрасываем информацию о новой строке
                }

                _csr_szFileContent[slot]{i} = symbol;
            }

            _csr_szFileContent[slot]{nFileSize} = 0; // символ конца строки для контента

            fclose(pFile); // закроем файл
            // ------------


            // ------------
            // скопируем в озу путь к файлу
            memcpy( _csr_szFilePath[slot], szFilePath, 0, nFileNameSize * cellbytes );

            _csr_szFilePath[slot][nFileNameSize] = 0; // символ конца строки для пути
            // ------------


            return slot; // вернем ИД слота
        }
    }
    // ------------




    //
    //  если свободный слот в памяти не найден
    //

    // ------------
    fclose(pFile); // закроем файл

    return CSR_NO_FREE_SLOT; // вернем код ошибки
    // ------------
}




/*
    Закрывает INI файл, если он был открыт.
    ПОДРОБНЕЕ
        Если файл не был изменен - освободит слот для хранения файла в ОЗУ.
        Если файл был изменен - полностью перезапишет файл на диске.
    ПАРАМЕТРЫ:
        nFilePointer    ИД_открытого_файла, полученный от csr_openFile / csr_createFile
    ВЕРНЕТ:
        код ошибки < 0 или 0 при успехе
*/

stock csr_closeFile ( nFilePointer )
{
    if
    (   // если ИД открытого файла указан верно
            nFilePointer >= 0
        &&  nFilePointer < CSR_MAX_OPENED_FILES
        &&  _csr_nSlotUsed[nFilePointer] != 0
    )
    {
        if ( _csr_nFileChanged[nFilePointer] != 0 ) // если файл был изменен
        {
            new File: pFile = fopen( _csr_szFilePath[nFilePointer], io_write ); // пытаемся открыть файл для записи

            if ( ! pFile ) // если файл не открылся
                return CSR_WRITE_ERROR; // вернем код ошибки

            // запишем контент файла из ОЗУ на диск
            for ( new i = 0;  i < _csr_nFileSize[nFilePointer];  i++ )
                fputchar( pFile, _csr_szFileContent[nFilePointer]{i}, false );

            fclose(pFile); // закроем файл
        }

        _csr_nSlotUsed[nFilePointer] = 0; // освободить слот открытого файла

        return CSR_OK; // вернуть код об успешном выполнении функции
    }

    return CSR_WRONG_SLOT; // вернуть код: неверный указатель на открытый файл
}











/*
    Получает из открытого INI файла значение указанного ключа.
    ПОДРОБНЕЕ
        Парсер ищет в ОЗУ в контенте файла указанный ключ и помещает в
        szReturnValue его строковое значение. szReturnValue нужно создать заранее.
        nSizeOfReturn можно не указывать, если только не нужно точное кол-во
        возвращаемых символов в строке (в описании этого параметра ниже даны
        дополнительные указания).
        Как ключ так и значение в файле, могут быть любой длины и
        могут содержать любые символы, кроме 2 символов конца строки \r и \n.
        Парсер не видит пробелы и знаки табуляции вокруг имени ключа и
        перед значением, он считает их отступами.
    ПАРАМЕТРЫ:
        nFilePointer        ИД_открытого_файла, полученный от csr_openFile / csr_createFile
        szKeyName[]         имя ключа
        szReturnValue[]     сюда будет помещено значение ключа в виде строки
        nSizeOfReturn       макс. размер возвращаемой строки, обычно, это размер szReturnValue.
                            если ваша строка szReturnValue является частью массива, который был создан с помощью enum,
                            этот параметр нужно обязательно указывать как число
    ВЕРНЕТ:
        код ошибки < 0 или 0 при успехе
*/

stock csr_getString ( nFilePointer, szKeyName[], szReturnValue[], nSizeOfReturn = sizeof(szReturnValue) )
{
    // ----------------
    if // если ИД открытого файла указан неверно
    (
            nFilePointer < 0
        ||  nFilePointer >= CSR_MAX_OPENED_FILES
        ||  _csr_nSlotUsed[nFilePointer] != 1
    )
        return CSR_WRONG_SLOT; // вернуть код: неверный указатель на открытый файл
    // ----------------


    if ( nSizeOfReturn <= 0 ) // если по какой-то причине размер возвращаемого значения указан/рассчитан как 0
        return CSR_WRONG_RETURN_SIZE;


    // ----------------
    new nKeyLen = strlen(szKeyName); // узнаем длину имени указанного ключа

    if ( nKeyLen <= 0 ) // если указан пустой ключ
        return CSR_KEY_NOT_FOUND;
    // ----------------


    // ----------------
    for // перебор и сравнение всех ключей файла с указанным ключом
    (
        new kPos = 0, curFilePos, found = 0;
        kPos < _csr_nKeysCount[nFilePointer];
        kPos++
    )
    {
        // ----------------
        found = 0; // флаг, найдена ли позиция конца ключа = 0

        for // ищем позицию конца ключа
        (
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] - 1; // текущ. поз. файла = поз. текущ. CSR_DELIMITER - 1
            curFilePos >= 0; // продолжать пока поз. файла >= 0
            curFilePos-- // после каждого повтора текущ. поз. файла -= 1
        )
        {
            switch ( _csr_szFileContent[nFilePointer]{curFilePos} ) // узнаем что за символ в текущ. поз. файла
            {
                case CSR_SPACE_CHAR :           continue; // если это пробельный символ, перейдем к пред. символу файла
                case CSR_STRING_DELIMITER :     break; // если это конец строки
                default : // если это другой символ
                {
                    found = 1; // позиция конца ключа найдена
                    break; // конец цикла
                }
            }
        }

        // если позиция конца ключа не найдена, переход к след. позиции CSR_DELIMITER
        if ( found != 1 ) continue;
        // ----------------


        // сравниваем посимвольно текущий ключ файла и указанный ключ
        for ( new curKeyPos = nKeyLen - 1;  curKeyPos >= 0;  curFilePos--, curKeyPos-- )
        {
            if
            (
                    curFilePos < 0 // если поз файла стала < 0
                ||  _csr_szFileContent[nFilePointer]{curFilePos} != szKeyName[curKeyPos] // если символы из ключей не равны
                ||  _csr_szFileContent[nFilePointer]{curFilePos} == CSR_STRING_DELIMITER // если символ из ключа это CSR_STRING_DELIMITER
            )
            {
                found = 0; // флаг, ключ не найден
                break; // конец сравнения
            }
        }


        // ----------------
        if ( found != 0 ) // если указанный ключ найден в файле
        {
            // если найдено совпадение не целого ключа файла, а его окончания с указанным ключом
            if ( curFilePos >= 0 )
            {
                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_KEY_STARTS : {}
                    default: continue;
                }
            }


            // ----------------
            // текущая позиция в файле будет на 1 больше текущей позиции CSR_DELIMITER
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] + 1;

            // ищем позицию начала значения, она будет помещена в curFilePos
            for ( ; ; curFilePos++ )
            {
                if ( curFilePos >= _csr_nFileSize[nFilePointer] ) break;

                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_SPACE_CHAR :   continue; // если это пробельный символ, перейдем к след. символу
                    default :               break; // если это другой символ
                }
            }
            // ----------------


            // ----------------
            // скопируем посимвольно в szReturnValue значение ключа из файла
            // воспользуемся созданной переменной found как позицией в возвращаемом значении
            for ( found = 0;  found < nSizeOfReturn;  found++, curFilePos++ )
            {
                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_STRING_ENDS : // если это символ конца значения
                    {
                        szReturnValue[found] = 0; // запишем символ конца строки
                        break; // конец копирования
                    }
                    default :
                        // копируем символ из файла в szReturnValue
                        szReturnValue[found] = _csr_szFileContent[nFilePointer]{curFilePos};
                }
            }

            szReturnValue[nSizeOfReturn - 1] = 0; // на всякий случай обрежем правильно строку

            return CSR_OK;
            // ----------------
        }
        // ----------------
    }
    // ----------------


    // ----------------
    return CSR_KEY_NOT_FOUND;
    // ----------------
}




/*
    Получает из открытого INI файла целочисленное значение указанного ключа.
    ПОДРОБНЕЕ
        Парсер ищет в ОЗУ в контенте файла указанный ключ и помещает в
        nReturnValue его целочисленное значение. nReturnValue нужно создать заранее.
        Имя ключа в файле может быть любой длины, а также может содержать
        любые символы, кроме 2 символов конца строки \r и \n.
        Значение может быть только фиксированной длины, которая равна CSR_INTEGER_SIZE - 1.
        Парсер не видит пробелы и знаки табуляции вокруг имени ключа/значения,
        он считает их отступами.
    ПАРАМЕТРЫ:
        nFilePointer        ИД_открытого_файла, полученный от csr_openFile / csr_createFile
        szKeyName[]         имя ключа
        nReturnValue        сюда будет помещено значение ключа в виде целого числа
    ВЕРНЕТ:
        код ошибки < 0 или 0 при успехе
*/

stock csr_getInteger ( nFilePointer, szKeyName[], & nReturnValue )
{
    // ----------------
    if // если ИД открытого файла указан неверно
    (
            nFilePointer < 0
        ||  nFilePointer >= CSR_MAX_OPENED_FILES
        ||  _csr_nSlotUsed[nFilePointer] != 1
    )
        return CSR_WRONG_SLOT; // вернуть код: неверный указатель на открытый файл
    // ----------------


    // ----------------
    new nKeyLen = strlen(szKeyName); // узнаем длину имени указанного ключа

    if ( nKeyLen <= 0 ) // если указан пустой ключ
        return CSR_KEY_NOT_FOUND;
    // ----------------


    // ----------------
    for // перебор и сравнение всех ключей файла с указанным ключом
    (
        new kPos = 0, curFilePos, found = 0;
        kPos < _csr_nKeysCount[nFilePointer];
        kPos++
    )
    {
        // ----------------
        found = 0; // флаг, найдена ли позиция конца ключа = 0

        for // ищем позицию конца ключа
        (
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] - 1; // текущ. поз. файла = поз. текущ. CSR_DELIMITER - 1
            curFilePos >= 0; // продолжать пока поз. файла >= 0
            curFilePos-- // после каждого повтора текущ. поз. файла -= 1
        )
        {
            switch ( _csr_szFileContent[nFilePointer]{curFilePos} ) // узнаем что за символ в текущ. поз. файла
            {
                case CSR_SPACE_CHAR :           continue; // если это пробельный символ, перейдем к пред. символу файла
                case CSR_STRING_DELIMITER :     break; // если это конец строки
                default : // если это другой символ
                {
                    found = 1; // позиция конца ключа найдена
                    break; // конец цикла
                }
            }
        }

        // если позиция конца ключа не найдена, переход к след. позиции CSR_DELIMITER
        if ( found != 1 ) continue;
        // ----------------


        // сравниваем посимвольно текущий ключ файла и указанный ключ
        for ( new curKeyPos = nKeyLen - 1;  curKeyPos >= 0;  curFilePos--, curKeyPos-- )
        {
            if
            (
                    curFilePos < 0 // если поз файла стала < 0
                ||  _csr_szFileContent[nFilePointer]{curFilePos} != szKeyName[curKeyPos] // если символы из ключей не равны
                ||  _csr_szFileContent[nFilePointer]{curFilePos} == CSR_STRING_DELIMITER // если символ из ключа это CSR_STRING_DELIMITER
            )
            {
                found = 0; // флаг, ключ не найден
                break; // конец сравнения
            }
        }


        // ----------------
        if ( found != 0 ) // если указанный ключ найден в файле
        {
            // если найдено совпадение не целого ключа файла, а его окончания с указанным ключом
            if ( curFilePos >= 0 )
            {
                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_KEY_STARTS : {}
                    default: continue;
                }
            }


            // ----------------
            // текущая позиция в файле будет на 1 больше текущей позиции CSR_DELIMITER
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] + 1;

            // ищем позицию начала значения, она будет помещена в curFilePos
            for ( ; ; curFilePos++ )
            {
                if ( curFilePos >= _csr_nFileSize[nFilePointer] ) break;

                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_SPACE_CHAR :   continue; // если это пробельный символ, перейдем к след. символу
                    default :               break; // если это другой символ
                }
            }
            // ----------------


            // ----------------
            new strValue[CSR_INTEGER_SIZE]; // временная строка для численного значения

            // скопируем посимвольно в strValue значение ключа из файла
            // воспользуемся созданной переменной found как позицией в возвращаемом значении
            for ( found = 0;  found < CSR_INTEGER_SIZE;  found++, curFilePos++ )
            {
                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_NUMBER_ENDS : // если это символ конца численного значения
                    {
                        strValue[found] = 0; // запишем символ конца строки
                        break; // конец копирования
                    }
                    default :
                        // копируем символ из файла в strValue
                        strValue[found] = _csr_szFileContent[nFilePointer]{curFilePos};
                }
            }

            strValue[CSR_INTEGER_SIZE - 1] = 0; // на всякий случай обрежем правильно строку

            nReturnValue = strval(strValue); // запишем в nReturnValue численное значение ключа

            return CSR_OK;
            // ----------------
        }
        // ----------------
    }
    // ----------------


    // ----------------
    return CSR_KEY_NOT_FOUND;
    // ----------------
}




/*
    Получает из открытого INI файла дробное численное значение указанного ключа.
    ПОДРОБНЕЕ
        Парсер ищет в ОЗУ в контенте файла указанный ключ и помещает в
        fReturnValue его дробное значение. fReturnValue нужно создать заранее.
        Имя ключа в файле может быть любой длины, а также может содержать
        любые символы, кроме 2 символов конца строки \r и \n.
        Значение может быть только фиксированной длины, которая равна CSR_FLOAT_SIZE - 1.
        Парсер не видит пробелы и знаки табуляции вокруг имени ключа/значения,
        он считает их отступами.
    ПАРАМЕТРЫ:
        nFilePointer        ИД_открытого_файла, полученный от csr_openFile / csr_createFile
        szKeyName[]         имя ключа
        fReturnValue        сюда будет помещено значение ключа в виде дробного числа
    ВЕРНЕТ:
        код ошибки < 0 или 0 при успехе
*/

stock csr_getFloat ( nFilePointer, szKeyName[], & Float: fReturnValue )
{
    // ----------------
    if // если ИД открытого файла указан неверно
    (
            nFilePointer < 0
        ||  nFilePointer >= CSR_MAX_OPENED_FILES
        ||  _csr_nSlotUsed[nFilePointer] != 1
    )
        return CSR_WRONG_SLOT; // вернуть код: неверный указатель на открытый файл
    // ----------------


    // ----------------
    new nKeyLen = strlen(szKeyName); // узнаем длину имени указанного ключа

    if ( nKeyLen <= 0 ) // если указан пустой ключ
        return CSR_KEY_NOT_FOUND;
    // ----------------


    // ----------------
    for // перебор и сравнение всех ключей файла с указанным ключом
    (
        new kPos = 0, curFilePos, found = 0;
        kPos < _csr_nKeysCount[nFilePointer];
        kPos++
    )
    {
        // ----------------
        found = 0; // флаг, найдена ли позиция конца ключа = 0

        for // ищем позицию конца ключа
        (
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] - 1; // текущ. поз. файла = поз. текущ. CSR_DELIMITER - 1
            curFilePos >= 0; // продолжать пока поз. файла >= 0
            curFilePos-- // после каждого повтора текущ. поз. файла -= 1
        )
        {
            switch ( _csr_szFileContent[nFilePointer]{curFilePos} ) // узнаем что за символ в текущ. поз. файла
            {
                case CSR_SPACE_CHAR :           continue; // если это пробельный символ, перейдем к пред. символу файла
                case CSR_STRING_DELIMITER :     break; // если это конец строки
                default : // если это другой символ
                {
                    found = 1; // позиция конца ключа найдена
                    break; // конец цикла
                }
            }
        }

        // если позиция конца ключа не найдена, переход к след. позиции CSR_DELIMITER
        if ( found != 1 ) continue;
        // ----------------


        // сравниваем посимвольно текущий ключ файла и указанный ключ
        for ( new curKeyPos = nKeyLen - 1;  curKeyPos >= 0;  curFilePos--, curKeyPos-- )
        {
            if
            (
                    curFilePos < 0 // если поз файла стала < 0
                ||  _csr_szFileContent[nFilePointer]{curFilePos} != szKeyName[curKeyPos] // если символы из ключей не равны
                ||  _csr_szFileContent[nFilePointer]{curFilePos} == CSR_STRING_DELIMITER // если символ из ключа это CSR_STRING_DELIMITER
            )
            {
                found = 0; // флаг, ключ не найден
                break; // конец сравнения
            }
        }


        // ----------------
        if ( found != 0 ) // если указанный ключ найден в файле
        {
            // если найдено совпадение не целого ключа файла, а его окончания с указанным ключом
            if ( curFilePos >= 0 )
            {
                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_KEY_STARTS : {}
                    default: continue;
                }
            }


            // ----------------
            // текущая позиция в файле будет на 1 больше текущей позиции CSR_DELIMITER
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] + 1;

            // ищем позицию начала значения, она будет помещена в curFilePos
            for ( ; ; curFilePos++ )
            {
                if ( curFilePos >= _csr_nFileSize[nFilePointer] ) break;

                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_SPACE_CHAR :   continue; // если это пробельный символ, перейдем к след. символу
                    default :               break; // если это другой символ
                }
            }
            // ----------------


            // ----------------
            new strValue[CSR_FLOAT_SIZE]; // временная строка для дробного значения

            // скопируем посимвольно в strValue значение ключа из файла
            // воспользуемся созданной переменной found как позицией в возвращаемом значении
            for ( found = 0;  found < CSR_INTEGER_SIZE;  found++, curFilePos++ )
            {
                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_NUMBER_ENDS : // если это символ конца численного значения
                    {
                        strValue[found] = 0; // запишем символ конца строки
                        break; // конец копирования
                    }
                    default :
                        // копируем символ из файла в strValue
                        strValue[found] = _csr_szFileContent[nFilePointer]{curFilePos};
                }
            }

            strValue[CSR_FLOAT_SIZE - 1] = 0; // на всякий случай обрежем правильно строку

            fReturnValue = floatstr(strValue); // запишем в fReturnValue дробное значение ключа

            return CSR_OK;
            // ----------------
        }
        // ----------------
    }
    // ----------------


    // ----------------
    return CSR_KEY_NOT_FOUND;
    // ----------------
}











/*
    Изменяет/добавляет в открытый INI файл указанный ключ и его значение.
    ПОДРОБНЕЕ
        Парсер ищет в ОЗУ в контенте файла указанный ключ и изменяет его
        строковое значение на szKeyValue.
        Форматирование файла не меняется. Если только указанное имя ключа
        не было найдено, тогда ключ и значение будут добавлены в конец файла.
        Имя ключа/значение в файле может быть любой длины, а также может содержать
        любые символы, кроме 2 символов конца строки \r и \n. Если эти символы есть
        в имени ключа или в значении, вы должны должны хорошо знать и осознавать
        последствия.
    ПАРАМЕТРЫ:
        nFilePointer        ИД_открытого_файла, полученный от csr_openFile / csr_createFile
        szKeyName[]         имя ключа
        szKeyValue[]        строка со значением ключа
    ВЕРНЕТ:
        код ошибки < 0 или 0 при успехе
*/

stock csr_setString ( nFilePointer, szKeyName[], szKeyValue[] )
{
    // ----------------
    if // если ИД открытого файла указан неверно
    (
            nFilePointer < 0
        ||  nFilePointer >= CSR_MAX_OPENED_FILES
        ||  _csr_nSlotUsed[nFilePointer] != 1
    )
        return CSR_WRONG_SLOT; // вернуть код: неверный указатель на открытый файл
    // ----------------


    // ----------------
    new nKeyLen = strlen(szKeyName); // узнаем длину имени указанного ключа

    if ( nKeyLen <= 0 ) // если указан пустой ключ
        return CSR_KEY_NOT_FOUND;
    // ----------------


    // ----------------
    for // перебор и сравнение всех ключей файла с указанным ключом
    (
        new kPos = 0, curFilePos, found;
        kPos < _csr_nKeysCount[nFilePointer];
        kPos++
    )
    {
        // ----------------
        found = 0; // флаг, найдена ли позиция конца ключа = 0

        for // ищем позицию конца ключа
        (
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] - 1; // текущ. поз. файла = поз. текущ. CSR_DELIMITER - 1
            curFilePos >= 0; // продолжать пока поз. файла >= 0
            curFilePos-- // после каждого повтора текущ. поз. файла -= 1
        )
        {
            switch ( _csr_szFileContent[nFilePointer]{curFilePos} ) // узнаем что за символ в текущ. поз. файла
            {
                case CSR_SPACE_CHAR :           continue; // если это пробельный символ, перейдем к пред. символу файла
                case CSR_STRING_DELIMITER :     break; // если это конец строки
                default : // если это другой символ
                {
                    found = 1; // позиция конца ключа найдена
                    break; // конец цикла
                }
            }
        }

        // если позиция конца ключа не найдена, переход к след. позиции CSR_DELIMITER
        if ( found != 1 ) continue;
        // ----------------


        // сравниваем посимвольно текущий ключ файла и указанный ключ
        for ( new curKeyPos = nKeyLen - 1;  curKeyPos >= 0;  curFilePos--, curKeyPos-- )
        {
            if
            (
                    curFilePos < 0 // если поз файла стала < 0
                ||  _csr_szFileContent[nFilePointer]{curFilePos} != szKeyName[curKeyPos] // если символы из ключей не равны
                ||  _csr_szFileContent[nFilePointer]{curFilePos} == CSR_STRING_DELIMITER // если символ из ключа это CSR_STRING_DELIMITER
            )
            {
                found = 0; // флаг, ключ не найден
                break; // конец сравнения
            }
        }


        if ( found != 0 ) // если указанный ключ НАЙДЕН в файле
        {
            // если найдено совпадение не целого ключа файла, а его окончания с указанным ключом
            if ( curFilePos >= 0 )
            {
                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_KEY_STARTS : {}
                    default: continue;
                }
            }


            // ----------------
            // текущая позиция в файле будет на 1 больше текущей позиции CSR_DELIMITER
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] + 1;

            // ищем позицию начала значения, она будет помещена в curFilePos
            for ( ; ; curFilePos++ )
            {
                if ( curFilePos >= _csr_nFileSize[nFilePointer] ) break;

                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_SPACE_CHAR :   continue; // если это пробельный символ, перейдем к след. символу
                    default :               break; // если это другой символ
                }
            }
            // ----------------


            // ----------------
            new nValueLen = strlen(szKeyValue); // узнаем размер значения указанного ключа

            // если будущий размер файла превышает лимит
            if ( ( curFilePos + nValueLen ) >= CSR_MAX_FILE_SIZE )
                return CSR_TOO_LARGE_FILE; // вернем код ошибки о переполнении файла
            // ----------------


            // ----------------
            new fileValueStartPos = curFilePos; // сохраним позицию начала значения

            // ищем позицию конца значения, она будет помещена в curFilePos
            for ( ; ; curFilePos++ )
            {
                if ( curFilePos >= _csr_nFileSize[nFilePointer] ) break;

                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_STRING_ENDS :  break; // если это конец строки - стоп
                    default :               continue; // если это другой символ, перейдем к след. символу
                }
            }

            // вычислим смещение оставшихся позиций для CSR_DELIMITER после изменения значения
            new filePosOffset = nValueLen - ( /*текущ длина значения*/ curFilePos - fileValueStartPos );
            // ----------------


            if ( _csr_nFileBusy[nFilePointer] != 0 ) // если прямо сейчас файл изменяется другой функцией
                return CSR_WRITE_ERROR; // вернем код ошибки при записи в файл


            // ----------------
            _csr_nFileBusy[nFilePointer] = 1; // флаг: файл изменяется = 1

            if ( filePosOffset != 0 ) // если длины старого и нового значений разные
            {
                if ( filePosOffset < 0 ) // если длина нового значения меньше
                {
                    for // копируем символы, стоящие после текущего значения на их новые места,
                    ( // которые теперь будут ближе к началу файла
                        ;
                        curFilePos < _csr_nFileSize[nFilePointer];
                        curFilePos++
                    )
                        _csr_szFileContent[nFilePointer]{ curFilePos + filePosOffset } =
                            _csr_szFileContent[nFilePointer]{curFilePos};
                }
                else if ( filePosOffset > 0 ) // если длина нового значения больше
                {
                    new fileValueEndPos = curFilePos;

                    for // копируем символы, стоящие после текущего значения на их новые места,
                    ( // начиная с конца файла
                        curFilePos = _csr_nFileSize[nFilePointer] - 1;
                        curFilePos >= fileValueEndPos;
                        curFilePos--
                    )
                        _csr_szFileContent[nFilePointer]{ curFilePos + filePosOffset } =
                            _csr_szFileContent[nFilePointer]{curFilePos};
                }

                // изменим позиции всех CSR_DELIMITER, которые находились после текущего CSR_DELIMITER
                for ( kPos++;  kPos < _csr_nKeysCount[nFilePointer];  kPos++ )
                    _csr_nDelimPos[nFilePointer][kPos] += filePosOffset;

                _csr_nFileSize[nFilePointer] += filePosOffset; // изменим размер файла
                _csr_szFileContent[nFilePointer]{ _csr_nFileSize[nFilePointer] } = 0; // конец строки для конца файла
            }

            curFilePos = fileValueStartPos; // текущ поз файла = поз начала старого значения
            for // запишем новое значение поверх старого
            (
                new valuePos = 0;
                valuePos < nValueLen;
                curFilePos++, valuePos++
            )
                _csr_szFileContent[nFilePointer]{curFilePos} = szKeyValue[valuePos];

            _csr_nFileChanged[nFilePointer]     = 1; // флаг: файл изменен = 1
            _csr_nFileBusy[nFilePointer]        = 0; // флаг: файл изменяется = 0

            return CSR_OK;
            // ----------------
        }
    }
    // ----------------


    //
    // если указанный ключ НЕ НАЙДЕН в файле
    //

    // ----------------
    new nValueLen = strlen(szKeyValue); // узнаем размер значения ключа

    // если будущий размер файла превышает лимит
    if ( ( _csr_nFileSize[nFilePointer] + 5 + nKeyLen + nValueLen ) >= CSR_MAX_FILE_SIZE )
        return CSR_TOO_LARGE_FILE; // вернем код ошибки о переполнении файла
    // ----------------


    // ----------------
    if ( _csr_nFileBusy[nFilePointer] != 0 ) // если прямо сейчас файл изменяется другой функцией
        return CSR_WRITE_ERROR; // вернем код ошибки при записи в файл

    _csr_nFileBusy[nFilePointer] = 1; // флаг: файл изменяется = 1
    // ----------------


    // ----------------
    if // если последний символ файла не является разделителем строк
    (
            _csr_nFileSize[nFilePointer] > 0
        &&  _csr_szFileContent[nFilePointer]{ _csr_nFileSize[nFilePointer] - 1 } != CSR_STRING_DELIMITER
    )
    {
        // вставим в конец файла перевод каретки и разделитель строк
        _csr_szFileContent[nFilePointer]{ _csr_nFileSize[nFilePointer] }        = '\r';
        _csr_szFileContent[nFilePointer]{ _csr_nFileSize[nFilePointer] + 1 }    = CSR_STRING_DELIMITER;

        _csr_nFileSize[nFilePointer] += 2; // увеличим размер файла на 2
    }

    new curFilePos, strPos; // будут временным хранилищами позиций в файле/ключе/значении

    for // добавим посимвольно имя ключа в файл
    (
        curFilePos = _csr_nFileSize[nFilePointer], strPos = 0;
        strPos < nKeyLen;
        curFilePos++, strPos++
    )
        _csr_szFileContent[nFilePointer]{curFilePos} = szKeyName[strPos];

    _csr_szFileContent[nFilePointer]{ curFilePos++ }                = ' '; // после ключа добавим пробел

    _csr_nDelimPos[nFilePointer][ _csr_nKeysCount[nFilePointer] ]   = curFilePos; // добавим новую позицию CSR_DELIMITER
    _csr_nKeysCount[nFilePointer]++; // кол-во ключей в файле +1

    _csr_szFileContent[nFilePointer]{ curFilePos++ }                = CSR_DELIMITER; // после пробела выше добавим CSR_DELIMITER
    _csr_szFileContent[nFilePointer]{ curFilePos++ }                = ' '; // после CSR_DELIMITER добавим пробел

    // добавим посимвольно значение ключа в файл
    for ( strPos = 0;  strPos < nValueLen;  curFilePos++, strPos++ )
        _csr_szFileContent[nFilePointer]{curFilePos} = szKeyValue[strPos];

    _csr_szFileContent[nFilePointer]{curFilePos}    = 0; // добавим символ конца строки
    _csr_nFileSize[nFilePointer]                    = curFilePos; // изменим размер файла
    _csr_nFileChanged[nFilePointer]                 = 1; // флаг: файл изменен = 1
    _csr_nFileBusy[nFilePointer]                    = 0; // флаг: файл изменяется = 0

    return CSR_OK;
    // ----------------
}




/*
    Изменяет/добавляет в открытый INI файл указанный ключ и его целочисленное значение.
    ПОДРОБНЕЕ
        Парсер ищет в ОЗУ в контенте файла указанный ключ и изменяет его
        целочисленное значение на nKeyValue.
        Форматирование файла не меняется, если только указанное имя ключа
        не было найдено, тогда ключ и значение будут добавлены в конец файла.
        Имя ключа в файле может быть любой длины, а также может содержать
        любые символы, кроме 2 символов конца строки \r и \n. Если вы в качестве
        значения указываете число больше, чем cellmax или меньше, чем cellmin,
        вы должны должны хорошо знать и осознавать последствия.
    ПАРАМЕТРЫ:
        nFilePointer        ИД_открытого_файла, полученный от csr_openFile / csr_createFile
        szKeyName[]         имя ключа
        nKeyValue           целочисленное значение ключа
    ВЕРНЕТ:
        код ошибки < 0 или 0 при успехе
*/

stock csr_setInteger ( nFilePointer, szKeyName[], nKeyValue )
{
    // ----------------
    if // если ИД открытого файла указан неверно
    (
            nFilePointer < 0
        ||  nFilePointer >= CSR_MAX_OPENED_FILES
        ||  _csr_nSlotUsed[nFilePointer] != 1
    )
        return CSR_WRONG_SLOT; // вернуть код: неверный указатель на открытый файл
    // ----------------


    // ----------------
    new nKeyLen = strlen(szKeyName); // узнаем длину имени указанного ключа

    if ( nKeyLen <= 0 ) // если указан пустой ключ
        return CSR_KEY_NOT_FOUND;
    // ----------------


    // ----------------
    for // перебор и сравнение всех ключей файла с указанным ключом
    (
        new kPos = 0, curFilePos, found;
        kPos < _csr_nKeysCount[nFilePointer];
        kPos++
    )
    {
        // ----------------
        found = 0; // флаг, найдена ли позиция конца ключа = 0

        for // ищем позицию конца ключа
        (
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] - 1; // текущ. поз. файла = поз. текущ. CSR_DELIMITER - 1
            curFilePos >= 0; // продолжать пока поз. файла >= 0
            curFilePos-- // после каждого повтора текущ. поз. файла -= 1
        )
        {
            switch ( _csr_szFileContent[nFilePointer]{curFilePos} ) // узнаем что за символ в текущ. поз. файла
            {
                case CSR_SPACE_CHAR :           continue; // если это пробельный символ, перейдем к пред. символу файла
                case CSR_STRING_DELIMITER :     break; // если это конец строки
                default : // если это другой символ
                {
                    found = 1; // позиция конца ключа найдена
                    break; // конец цикла
                }
            }
        }

        // если позиция конца ключа не найдена, переход к след. позиции CSR_DELIMITER
        if ( found != 1 ) continue;
        // ----------------


        // сравниваем посимвольно текущий ключ файла и указанный ключ
        for ( new curKeyPos = nKeyLen - 1;  curKeyPos >= 0;  curFilePos--, curKeyPos-- )
        {
            if
            (
                    curFilePos < 0 // если поз файла стала < 0
                ||  _csr_szFileContent[nFilePointer]{curFilePos} != szKeyName[curKeyPos] // если символы из ключей не равны
                ||  _csr_szFileContent[nFilePointer]{curFilePos} == CSR_STRING_DELIMITER // если символ из ключа это CSR_STRING_DELIMITER
            )
            {
                found = 0; // флаг, ключ не найден
                break; // конец сравнения
            }
        }


        if ( found != 0 ) // если указанный ключ НАЙДЕН в файле
        {
            // если найдено совпадение не целого ключа файла, а его окончания с указанным ключом
            if ( curFilePos >= 0 )
            {
                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_KEY_STARTS : {}
                    default: continue;
                }
            }


            // ----------------
            // текущая позиция в файле будет на 1 больше текущей позиции CSR_DELIMITER
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] + 1;

            // ищем позицию начала значения, она будет помещена в curFilePos
            for ( ; ; curFilePos++ )
            {
                if ( curFilePos >= _csr_nFileSize[nFilePointer] ) break;

                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_SPACE_CHAR :   continue; // если это пробельный символ, перейдем к след. символу
                    default :               break; // если это другой символ
                }
            }
            // ----------------


            // ----------------
            new szKeyValue[CSR_INTEGER_SIZE]; // создадим строку для хранения целочисленного значения
            format( szKeyValue, CSR_INTEGER_SIZE, "%i", nKeyValue );
            // ----------------


            // ----------------
            new nValueLen = strlen(szKeyValue); // узнаем размер значения указанного ключа

            // если будущий размер файла превышает лимит
            if ( ( curFilePos + nValueLen ) >= CSR_MAX_FILE_SIZE )
                return CSR_TOO_LARGE_FILE; // вернем код ошибки о переполнении файла
            // ----------------


            // ----------------
            new fileValueStartPos = curFilePos; // сохраним позицию начала значения

            // ищем позицию конца значения, она будет помещена в curFilePos
            for ( ; ; curFilePos++ )
            {
                if ( curFilePos >= _csr_nFileSize[nFilePointer] ) break;

                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_NUMBER_ENDS :  break; // если это конец числа - стоп
                    default :               continue; // если это другой символ, перейдем к след. символу
                }
            }

            // вычислим смещение оставшихся позиций для CSR_DELIMITER после изменения значения
            new filePosOffset = nValueLen - ( /*текущ длина значения*/ curFilePos - fileValueStartPos );
            // ----------------


            if ( _csr_nFileBusy[nFilePointer] != 0 ) // если прямо сейчас файл изменяется другой функцией
                return CSR_WRITE_ERROR; // вернем код ошибки при записи в файл


            // ----------------
            _csr_nFileBusy[nFilePointer] = 1; // флаг: файл изменяется = 1

            if ( filePosOffset != 0 ) // если длины старого и нового значений разные
            {
                if ( filePosOffset < 0 ) // если длина нового значения меньше
                {
                    for // копируем символы, стоящие после текущего значения на их новые места,
                    ( // которые теперь будут ближе к началу файла
                        ;
                        curFilePos < _csr_nFileSize[nFilePointer];
                        curFilePos++
                    )
                        _csr_szFileContent[nFilePointer]{ curFilePos + filePosOffset } =
                            _csr_szFileContent[nFilePointer]{curFilePos};
                }
                else if ( filePosOffset > 0 ) // если длина нового значения больше
                {
                    new fileValueEndPos = curFilePos;

                    for // копируем символы, стоящие после текущего значения на их новые места,
                    ( // начиная с конца файла
                        curFilePos = _csr_nFileSize[nFilePointer] - 1;
                        curFilePos >= fileValueEndPos;
                        curFilePos--
                    )
                        _csr_szFileContent[nFilePointer]{ curFilePos + filePosOffset } =
                            _csr_szFileContent[nFilePointer]{curFilePos};
                }

                // изменим позиции всех CSR_DELIMITER, которые находились после текущего CSR_DELIMITER
                for ( kPos++;  kPos < _csr_nKeysCount[nFilePointer];  kPos++ )
                    _csr_nDelimPos[nFilePointer][kPos] += filePosOffset;

                _csr_nFileSize[nFilePointer] += filePosOffset; // изменим размер файла
                _csr_szFileContent[nFilePointer]{ _csr_nFileSize[nFilePointer] } = 0; // конец строки для конца файла
            }

            curFilePos = fileValueStartPos; // текущ поз файла = поз начала старого значения
            for // запишем новое значение поверх старого
            (
                new valuePos = 0;
                valuePos < nValueLen;
                curFilePos++, valuePos++
            )
                _csr_szFileContent[nFilePointer]{curFilePos} = szKeyValue[valuePos];

            _csr_nFileChanged[nFilePointer]     = 1; // флаг: файл изменен = 1
            _csr_nFileBusy[nFilePointer]        = 0; // флаг: файл изменяется = 0

            return CSR_OK;
            // ----------------
        }
    }
    // ----------------


    //
    // если указанный ключ НЕ НАЙДЕН в файле
    //

    // ----------------
    new szKeyValue[CSR_INTEGER_SIZE]; // создадим строку для хранения целочисленного значения
    format( szKeyValue, CSR_INTEGER_SIZE, "%i", nKeyValue );
    // ----------------


    // ----------------
    new nValueLen = strlen(szKeyValue); // узнаем размер значения ключа

    // если будущий размер файла превышает лимит
    if ( ( _csr_nFileSize[nFilePointer] + 5 + nKeyLen + nValueLen ) >= CSR_MAX_FILE_SIZE )
        return CSR_TOO_LARGE_FILE; // вернем код ошибки о переполнении файла
    // ----------------


    // ----------------
    if ( _csr_nFileBusy[nFilePointer] != 0 ) // если прямо сейчас файл изменяется другой функцией
        return CSR_WRITE_ERROR; // вернем код ошибки при записи в файл

    _csr_nFileBusy[nFilePointer] = 1; // флаг: файл изменяется = 1
    // ----------------


    // ----------------
    if // если последний символ файла не является разделителем строк
    (
            _csr_nFileSize[nFilePointer] > 0
        &&  _csr_szFileContent[nFilePointer]{ _csr_nFileSize[nFilePointer] - 1 } != CSR_STRING_DELIMITER
    )
    {
        // вставим в конец файла перевод каретки и разделитель строк
        _csr_szFileContent[nFilePointer]{ _csr_nFileSize[nFilePointer] }        = '\r';
        _csr_szFileContent[nFilePointer]{ _csr_nFileSize[nFilePointer] + 1 }    = CSR_STRING_DELIMITER;

        _csr_nFileSize[nFilePointer] += 2; // увеличим размер файла на 2
    }

    new curFilePos, strPos; // будут временным хранилищами позиций в файле/ключе/значении

    for // добавим посимвольно имя ключа в файл
    (
        curFilePos = _csr_nFileSize[nFilePointer], strPos = 0;
        strPos < nKeyLen;
        curFilePos++, strPos++
    )
        _csr_szFileContent[nFilePointer]{curFilePos} = szKeyName[strPos];

    _csr_szFileContent[nFilePointer]{ curFilePos++ }                = ' '; // после ключа добавим пробел

    _csr_nDelimPos[nFilePointer][ _csr_nKeysCount[nFilePointer] ]   = curFilePos; // добавим новую позицию CSR_DELIMITER
    _csr_nKeysCount[nFilePointer]++; // кол-во ключей в файле +1

    _csr_szFileContent[nFilePointer]{ curFilePos++ }                = CSR_DELIMITER; // после пробела выше добавим CSR_DELIMITER
    _csr_szFileContent[nFilePointer]{ curFilePos++ }                = ' '; // после CSR_DELIMITER добавим пробел

    // добавим посимвольно значение ключа в файл
    for ( strPos = 0;  strPos < nValueLen;  curFilePos++, strPos++ )
        _csr_szFileContent[nFilePointer]{curFilePos} = szKeyValue[strPos];

    _csr_szFileContent[nFilePointer]{curFilePos}    = 0; // добавим символ конца строки
    _csr_nFileSize[nFilePointer]                    = curFilePos; // изменим размер файла
    _csr_nFileChanged[nFilePointer]                 = 1; // флаг: файл изменен = 1
    _csr_nFileBusy[nFilePointer]                    = 0; // флаг: файл изменяется = 0

    return CSR_OK;
    // ----------------
}




/*
    Изменяет/добавляет в открытый INI файл указанный ключ и его дробное численное значение.
    ПОДРОБНЕЕ
        Парсер ищет в ОЗУ в контенте файла указанный ключ и изменяет его
        дробное значение на fKeyValue.
        Форматирование файла не меняется, если только указанное имя ключа
        не было найдено, тогда ключ и значение будут добавлены в конец файла.
        Имя ключа в файле может быть любой длины, а также может содержать
        любые символы, кроме 2 символов конца строки \r и \n. Если вы в качестве
        значения указываете очень большое/маленькое дробное число, вы должны
        хорошо знать и осознавать последствия.
    ПАРАМЕТРЫ:
        nFilePointer        ИД_открытого_файла, полученный от csr_openFile / csr_createFile
        szKeyName[]         имя ключа
        fKeyValue           дробное численное значение ключа
    ВЕРНЕТ:
        код ошибки < 0 или 0 при успехе
*/

stock csr_setFloat ( nFilePointer, szKeyName[], Float: fKeyValue )
{
    // ----------------
    if // если ИД открытого файла указан неверно
    (
            nFilePointer < 0
        ||  nFilePointer >= CSR_MAX_OPENED_FILES
        ||  _csr_nSlotUsed[nFilePointer] != 1
    )
        return CSR_WRONG_SLOT; // вернуть код: неверный указатель на открытый файл
    // ----------------


    // ----------------
    new nKeyLen = strlen(szKeyName); // узнаем длину имени указанного ключа

    if ( nKeyLen <= 0 ) // если указан пустой ключ
        return CSR_KEY_NOT_FOUND;
    // ----------------


    // ----------------
    for // перебор и сравнение всех ключей файла с указанным ключом
    (
        new kPos = 0, curFilePos, found;
        kPos < _csr_nKeysCount[nFilePointer];
        kPos++
    )
    {
        // ----------------
        found = 0; // флаг, найдена ли позиция конца ключа = 0

        for // ищем позицию конца ключа
        (
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] - 1; // текущ. поз. файла = поз. текущ. CSR_DELIMITER - 1
            curFilePos >= 0; // продолжать пока поз. файла >= 0
            curFilePos-- // после каждого повтора текущ. поз. файла -= 1
        )
        {
            switch ( _csr_szFileContent[nFilePointer]{curFilePos} ) // узнаем что за символ в текущ. поз. файла
            {
                case CSR_SPACE_CHAR :           continue; // если это пробельный символ, перейдем к пред. символу файла
                case CSR_STRING_DELIMITER :     break; // если это конец строки
                default : // если это другой символ
                {
                    found = 1; // позиция конца ключа найдена
                    break; // конец цикла
                }
            }
        }

        // если позиция конца ключа не найдена, переход к след. позиции CSR_DELIMITER
        if ( found != 1 ) continue;
        // ----------------


        // сравниваем посимвольно текущий ключ файла и указанный ключ
        for ( new curKeyPos = nKeyLen - 1;  curKeyPos >= 0;  curFilePos--, curKeyPos-- )
        {
            if
            (
                    curFilePos < 0 // если поз файла стала < 0
                ||  _csr_szFileContent[nFilePointer]{curFilePos} != szKeyName[curKeyPos] // если символы из ключей не равны
                ||  _csr_szFileContent[nFilePointer]{curFilePos} == CSR_STRING_DELIMITER // если символ из ключа это CSR_STRING_DELIMITER
            )
            {
                found = 0; // флаг, ключ не найден
                break; // конец сравнения
            }
        }


        if ( found != 0 ) // если указанный ключ НАЙДЕН в файле
        {
            // если найдено совпадение не целого ключа файла, а его окончания с указанным ключом
            if ( curFilePos >= 0 )
            {
                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_KEY_STARTS : {}
                    default: continue;
                }
            }


            // ----------------
            // текущая позиция в файле будет на 1 больше текущей позиции CSR_DELIMITER
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] + 1;

            // ищем позицию начала значения, она будет помещена в curFilePos
            for ( ; ; curFilePos++ )
            {
                if ( curFilePos >= _csr_nFileSize[nFilePointer] ) break;

                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_SPACE_CHAR :   continue; // если это пробельный символ, перейдем к след. символу
                    default :               break; // если это другой символ
                }
            }
            // ----------------


            // ----------------
            new szKeyValue[CSR_FLOAT_SIZE]; // создадим строку для хранения дробного значения
            format( szKeyValue, CSR_FLOAT_SIZE, "%f", fKeyValue ); // поместим строковое значение fKeyValue в szKeyValue
            // ----------------


            // ----------------
            new nValueLen = strlen(szKeyValue); // узнаем размер значения указанного ключа

            // если будущий размер файла превышает лимит
            if ( ( curFilePos + nValueLen ) >= CSR_MAX_FILE_SIZE )
                return CSR_TOO_LARGE_FILE; // вернем код ошибки о переполнении файла
            // ----------------


            // ----------------
            new fileValueStartPos = curFilePos; // сохраним позицию начала значения

            // ищем позицию конца значения, она будет помещена в curFilePos
            for ( ; ; curFilePos++ )
            {
                if ( curFilePos >= _csr_nFileSize[nFilePointer] ) break;

                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_NUMBER_ENDS :  break; // если это конец числа - стоп
                    default :               continue; // если это другой символ, перейдем к след. символу
                }
            }

            // вычислим смещение оставшихся позиций для CSR_DELIMITER после изменения значения
            new filePosOffset = nValueLen - ( /*текущ длина значения*/ curFilePos - fileValueStartPos );
            // ----------------


            if ( _csr_nFileBusy[nFilePointer] != 0 ) // если прямо сейчас файл изменяется другой функцией
                return CSR_WRITE_ERROR; // вернем код ошибки при записи в файл


            // ----------------
            _csr_nFileBusy[nFilePointer] = 1; // флаг: файл изменяется = 1

            if ( filePosOffset != 0 ) // если длины старого и нового значений разные
            {
                if ( filePosOffset < 0 ) // если длина нового значения меньше
                {
                    for // копируем символы, стоящие после текущего значения на их новые места,
                    ( // которые теперь будут ближе к началу файла
                        ;
                        curFilePos < _csr_nFileSize[nFilePointer];
                        curFilePos++
                    )
                        _csr_szFileContent[nFilePointer]{ curFilePos + filePosOffset } =
                            _csr_szFileContent[nFilePointer]{curFilePos};
                }
                else if ( filePosOffset > 0 ) // если длина нового значения больше
                {
                    new fileValueEndPos = curFilePos;

                    for // копируем символы, стоящие после текущего значения на их новые места,
                    ( // начиная с конца файла
                        curFilePos = _csr_nFileSize[nFilePointer] - 1;
                        curFilePos >= fileValueEndPos;
                        curFilePos--
                    )
                        _csr_szFileContent[nFilePointer]{ curFilePos + filePosOffset } =
                            _csr_szFileContent[nFilePointer]{curFilePos};
                }

                // изменим позиции всех CSR_DELIMITER, которые находились после текущего CSR_DELIMITER
                for ( kPos++;  kPos < _csr_nKeysCount[nFilePointer];  kPos++ )
                    _csr_nDelimPos[nFilePointer][kPos] += filePosOffset;

                _csr_nFileSize[nFilePointer] += filePosOffset; // изменим размер файла
                _csr_szFileContent[nFilePointer]{ _csr_nFileSize[nFilePointer] } = 0; // конец строки для конца файла
            }

            curFilePos = fileValueStartPos; // текущ поз файла = поз начала старого значения
            for // запишем новое значение поверх старого
            (
                new valuePos = 0;
                valuePos < nValueLen;
                curFilePos++, valuePos++
            )
                _csr_szFileContent[nFilePointer]{curFilePos} = szKeyValue[valuePos];

            _csr_nFileChanged[nFilePointer]     = 1; // флаг: файл изменен = 1
            _csr_nFileBusy[nFilePointer]        = 0; // флаг: файл изменяется = 0

            return CSR_OK;
            // ----------------
        }
    }
    // ----------------


    //
    // если указанный ключ НЕ НАЙДЕН в файле
    //

    // ----------------
    new szKeyValue[CSR_FLOAT_SIZE]; // создадим строку для хранения дробного значения
    format( szKeyValue, CSR_FLOAT_SIZE, "%f", fKeyValue ); // поместим строковое значение fKeyValue в szKeyValue
    // ----------------


    // ----------------
    new nValueLen = strlen(szKeyValue); // узнаем размер значения ключа

    // если будущий размер файла превышает лимит
    if ( ( _csr_nFileSize[nFilePointer] + 5 + nKeyLen + nValueLen ) >= CSR_MAX_FILE_SIZE )
        return CSR_TOO_LARGE_FILE; // вернем код ошибки о переполнении файла
    // ----------------


    // ----------------
    if ( _csr_nFileBusy[nFilePointer] != 0 ) // если прямо сейчас файл изменяется другой функцией
        return CSR_WRITE_ERROR; // вернем код ошибки при записи в файл

    _csr_nFileBusy[nFilePointer] = 1; // флаг: файл изменяется = 1
    // ----------------


    // ----------------
    if // если последний символ файла не является разделителем строк
    (
            _csr_nFileSize[nFilePointer] > 0
        &&  _csr_szFileContent[nFilePointer]{ _csr_nFileSize[nFilePointer] - 1 } != CSR_STRING_DELIMITER
    )
    {
        // вставим в конец файла перевод каретки и разделитель строк
        _csr_szFileContent[nFilePointer]{ _csr_nFileSize[nFilePointer] }        = '\r';
        _csr_szFileContent[nFilePointer]{ _csr_nFileSize[nFilePointer] + 1 }    = CSR_STRING_DELIMITER;

        _csr_nFileSize[nFilePointer] += 2; // увеличим размер файла на 2
    }

    new curFilePos, strPos; // будут временным хранилищами позиций в файле/ключе/значении

    for // добавим посимвольно имя ключа в файл
    (
        curFilePos = _csr_nFileSize[nFilePointer], strPos = 0;
        strPos < nKeyLen;
        curFilePos++, strPos++
    )
        _csr_szFileContent[nFilePointer]{curFilePos} = szKeyName[strPos];

    _csr_szFileContent[nFilePointer]{ curFilePos++ }                = ' '; // после ключа добавим пробел

    _csr_nDelimPos[nFilePointer][ _csr_nKeysCount[nFilePointer] ]   = curFilePos; // добавим новую позицию CSR_DELIMITER
    _csr_nKeysCount[nFilePointer]++; // кол-во ключей в файле +1

    _csr_szFileContent[nFilePointer]{ curFilePos++ }                = CSR_DELIMITER; // после пробела выше добавим CSR_DELIMITER
    _csr_szFileContent[nFilePointer]{ curFilePos++ }                = ' '; // после CSR_DELIMITER добавим пробел

    // добавим посимвольно значение ключа в файл
    for ( strPos = 0;  strPos < nValueLen;  curFilePos++, strPos++ )
        _csr_szFileContent[nFilePointer]{curFilePos} = szKeyValue[strPos];

    _csr_szFileContent[nFilePointer]{curFilePos}    = 0; // добавим символ конца строки
    _csr_nFileSize[nFilePointer]                    = curFilePos; // изменим размер файла
    _csr_nFileChanged[nFilePointer]                 = 1; // флаг: файл изменен = 1
    _csr_nFileBusy[nFilePointer]                    = 0; // флаг: файл изменяется = 0

    return CSR_OK;
    // ----------------
}




/*
    Удаляет из открытого INI файла указанный ключ и его значение.
    ПОДРОБНЕЕ
        Парсер ищет в ОЗУ в контенте файла указанный ключ и удаляет найденную
        пару ключ/значение.
        Имя ключа/значение в файле может быть любой длины,
        а также может содержать любые символы, кроме 2 символов конца строки \r и \n.
        Если эти символы есть в имени ключа или в значении,
        вы должны должны хорошо знать и осознавать последствия.
    ПАРАМЕТРЫ:
        nFilePointer        ИД_открытого_файла, полученный от csr_openFile / csr_createFile
        szKeyName[]         имя ключа
    ВЕРНЕТ:
        код ошибки < 0 или 0 при успехе
*/

stock csr_removeKey ( nFilePointer, szKeyName[] )
{
    // ----------------
    if // если ИД открытого файла указан неверно
    (
            nFilePointer < 0
        ||  nFilePointer >= CSR_MAX_OPENED_FILES
        ||  _csr_nSlotUsed[nFilePointer] != 1
    )
        return CSR_WRONG_SLOT; // вернуть код: неверный указатель на открытый файл
    // ----------------


    // ----------------
    new nKeyLen = strlen(szKeyName); // узнаем длину имени указанного ключа

    if ( nKeyLen <= 0 ) // если указан пустой ключ
        return CSR_KEY_NOT_FOUND;
    // ----------------


    // ----------------
    for // перебор и сравнение всех ключей файла с указанным ключом
    (
        new kPos = 0, curFilePos, found;
        kPos < _csr_nKeysCount[nFilePointer];
        kPos++
    )
    {
        // ----------------
        found = 0; // флаг, найдена ли позиция конца ключа = 0

        for // ищем позицию конца ключа
        (
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] - 1; // текущ. поз. файла = поз. текущ. CSR_DELIMITER - 1
            curFilePos >= 0; // продолжать пока поз. файла >= 0
            curFilePos-- // после каждого повтора текущ. поз. файла -= 1
        )
        {
            switch ( _csr_szFileContent[nFilePointer]{curFilePos} ) // узнаем что за символ в текущ. поз. файла
            {
                case CSR_SPACE_CHAR :           continue; // если это пробельный символ, перейдем к пред. символу файла
                case CSR_STRING_DELIMITER :     break; // если это конец строки
                default : // если это другой символ
                {
                    found = 1; // позиция конца ключа найдена
                    break; // конец цикла
                }
            }
        }

        // если позиция конца ключа не найдена, переход к след. позиции CSR_DELIMITER
        if ( found != 1 ) continue;
        // ----------------


        // сравниваем посимвольно текущий ключ файла и указанный ключ
        for ( new curKeyPos = nKeyLen - 1;  curKeyPos >= 0;  curFilePos--, curKeyPos-- )
        {
            if
            (
                    curFilePos < 0 // если поз файла стала < 0
                ||  _csr_szFileContent[nFilePointer]{curFilePos} != szKeyName[curKeyPos] // если символы из ключей не равны
                ||  _csr_szFileContent[nFilePointer]{curFilePos} == CSR_STRING_DELIMITER // если символ из ключа это CSR_STRING_DELIMITER
            )
            {
                found = 0; // флаг, ключ не найден
                break; // конец сравнения
            }
        }


        if ( found != 0 ) // если указанный ключ НАЙДЕН в файле
        {
            // если найдено совпадение не целого ключа файла, а его окончания с указанным ключом
            if ( curFilePos >= 0 )
            {
                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_KEY_STARTS : {}
                    default: continue;
                }
            }


            // сохраним позицию начала ключа
            new keyStartPos = ( curFilePos <= 0 ) ? 0 : curFilePos + 1;


            // ----------------
            // текущая позиция в файле будет на 1 больше текущей позиции CSR_DELIMITER
            curFilePos = _csr_nDelimPos[nFilePointer][kPos] + 1;

            // ищем позицию начала значения, она будет помещена в curFilePos
            for ( ; ; curFilePos++ )
            {
                if ( curFilePos >= _csr_nFileSize[nFilePointer] ) break;

                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_SPACE_CHAR :   continue; // если это пробельный символ, перейдем к след. символу
                    default :               break; // если это другой символ
                }
            }
            // ----------------


            // ----------------
            // ищем позицию конца значения, она будет помещена в curFilePos
            for ( ; ; curFilePos++ )
            {
                if ( curFilePos >= _csr_nFileSize[nFilePointer] ) break;

                switch ( _csr_szFileContent[nFilePointer]{curFilePos} )
                {
                    case CSR_STRING_ENDS :  break; // если это конец строки - стоп
                    default :               continue; // если это другой символ, перейдем к след. символу
                }
            }

            // вычислим смещение оставшихся позиций для CSR_DELIMITER после изменения значения
            new filePosOffset = keyStartPos - curFilePos;
            // ----------------


            if ( _csr_nFileBusy[nFilePointer] != 0 ) // если прямо сейчас файл изменяется другой функцией
                return CSR_WRITE_ERROR; // вернем код ошибки при записи в файл


            // ----------------
            _csr_nFileBusy[nFilePointer] = 1; // флаг: файл изменяется = 1

            // затираем контент ключа, следующими за ним данными файла
            for ( ; curFilePos <= _csr_nFileSize[nFilePointer]; curFilePos++ )
                _csr_szFileContent[nFilePointer]{ curFilePos + filePosOffset } =
                    _csr_szFileContent[nFilePointer]{curFilePos};

            // затираем текущий CSR_DELIMITER, и меняем позиции последующих CSR_DELIMITER
            for ( ;  kPos < _csr_nKeysCount[nFilePointer];  kPos++ )
                _csr_nDelimPos[nFilePointer][kPos] = _csr_nDelimPos[nFilePointer][kPos + 1] + filePosOffset;

            _csr_nKeysCount[nFilePointer]--;
            _csr_nFileSize[nFilePointer] += filePosOffset; // изменим размер файла
            _csr_szFileContent[nFilePointer]{ _csr_nFileSize[nFilePointer] } = 0; // конец строки для конца файла

            _csr_nFileChanged[nFilePointer]     = 1; // флаг: файл изменен = 1
            _csr_nFileBusy[nFilePointer]        = 0; // флаг: файл изменяется = 0

            return CSR_OK;
            // ----------------
        }
    }
    // ----------------


    //
    // если указанный ключ НЕ НАЙДЕН в файле
    //

    // ----------------
    return CSR_KEY_NOT_FOUND;
    // ----------------
}




/*
    Возвращает строку с описанием указанного кода ошибки на русском языке.
    ПОДРОБНЕЕ
        Если какая-то функция вам вернула не 0 (всё в порядке), а отрицательное
        значение, значит, имела место ошибка. Если вы хотите вывести в любой лог или
        в диалог человеческое описание этой ошибки, то передайте этой функции код
        ошибки и она вам вернет описание этой ошибки на русском языке.
        Описание ошибок довольно длинные и превышают размер в 128 символов,
        поэтому выводить эти описания в чате не рекомендуется!
    ПАРАМЕТРЫ:
        nErrorCode      код ошибки, полученный от любой функции
    ВЕРНЕТ:
        строку с человеческим описанием ошибки, под указанным кодом
    ПРИМЕР:
        new ini = csr_openFile("несуществующий файл"); // пытаемся открыть несуществующий файл
        if ( ini < 0 ) print( csr_getErrorInfo(ini) );
        else
        {
            new number, result = csr_getInteger( ini, "несуществующий ключ", number ); // пробуем получить значение несуществующего ключа
            if ( result < 0 ) print( csr_getErrorInfo(result) );
            csr_closeFile(ini);
        }
*/

stock csr_getErrorInfo ( nErrorCode )
{
    new error_ms[200] = "Ошибок нет";

    if ( nErrorCode >= 0 ) return error_ms;

    switch ( nErrorCode )
    {
        case CSR_FILE_NOT_FOUND :     error_ms = "INI файл, указанный в `csr_openFile`, не существует, возможно, указан неверный путь к нему";
        case CSR_FILE_ALREADY_EXIST : error_ms = "INI файл, указанный в `csr_createFile`, уже существует, укажите другое имя/путь к файлу";
        case CSR_TOO_LARGE_FILE :     error_ms = "Невозможно добавить новый ключ в INI файл, т.к. размер INI файла превысит допустимый лимит в " #CSR_MAX_FILE_SIZE " символ(ов), или будет превышен лимит в " #CSR_MAX_KEYS_IN_FILE " ключей";
        case CSR_WRONG_PATH_SIZE :    error_ms = "Длина пути к INI файлу, указанного в `csr_openFile` / `csr_createFile`, превышает лимит в " #CSR_MAX_FILENAME_SIZE " символ(ов)";
        case CSR_READ_ERROR :         error_ms = "Ошибка при чтении INI файла с диска, возможно, файл занят другим процессом";
        case CSR_WRITE_ERROR :        error_ms = "Ошибка при записи содержимого INI файла на диск, возможно, файл занят другим процессом";
        case CSR_NO_FREE_SLOT :       error_ms = "Лимит в " #CSR_MAX_OPENED_FILES " одновременно открытых INI файлов исчерпан, поэтому открыть/создать еще 1 файл нельзя, пока не закрыт хоть 1 из открытых файлов";
        case CSR_WRONG_SLOT :         error_ms = "Указан неверный ID открытого INI файла, возможно, при открытии INI файла произошла ошибка, поэтому вместо ID файла вы получили код ошибки";
        case CSR_KEY_NOT_FOUND :      error_ms = "Указанный ключ не найден в открытом INI файле";
        case CSR_WRONG_RETURN_SIZE :  error_ms = "При попытке чтения строкового значения из INI файла, последний параметр `nSizeOfReturn` в `csr_getString` оказался <= 0, укажите вручную значение > 0 для него";

        default:                      error_ms = "Неизвестная ошибка";
    }

    return error_ms;
}
