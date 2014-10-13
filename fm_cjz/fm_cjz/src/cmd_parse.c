/**
 * Author: Jianzhong Cui
 * 
 * Copyright: Can not be used in commercial product
 */

#include <stdio.h>
#include <cmd_parse.h>
#include <debug.h>

fm_cmd_table_t ctable[] = {
	{"login\n",		FM_PROVIDER_LOGIN},
	{"logout\n",	FM_PROVIDER_LOGOUT},
	{"play\n", 		FM_PROVIDER_PLAY},
	{"PLAY\n", 		FM_PROVIDER_PLAY},
	{"stop\n", 		FM_PROVIDER_STOP},
	{"pause\n", 	FM_PROVIDER_PAUSE},
	{"next\n", 		FM_PROVIDER_NEXT},
	{"rate\n", 		FM_PROVIDER_RATE},
	{"unrate\n", 	FM_PROVIDER_UNRATE}
};

FM_CMD get_cmd_from_str(char *cmdstr)
{
	int i;
	//LOGI("cmdstr = %s\n", cmdstr);
	for (i = 0; i < ARRAY_SIZE(ctable); i++) {
		if (strncmp(cmdstr, ctable[i].cmdstr, sizeof(cmdstr)) == 0) {
			//LOGI("i = %d match\n", i);
			return ctable[i].cmd;
		}
	}
	if (i == ARRAY_SIZE(ctable)) {
		return FM_PROVIDER_ERROR;
	}
}
