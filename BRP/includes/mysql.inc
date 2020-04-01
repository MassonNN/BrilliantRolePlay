#include <YSI_Coding/y_hooks>

new MySQL:dbHandle;

hook OnGameModeInit()
{
	dbHandle = mysql_connect("193.109.78.92", "gs30197", "intell", "gs30197");
	switch(mysql_errno())
	{
	    case 0: print(!"Подключен к базе!!");
	    default: printf("Подключение неудачно. Код ошибки: %d", mysql_errno());
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}