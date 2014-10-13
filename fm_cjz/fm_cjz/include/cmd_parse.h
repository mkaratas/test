#ifndef __CMD_PARSE_H__
#define __CMD_PARSE_H__

typedef enum {
	FM_PROVIDER_LOGIN,
	FM_PROVIDER_LOGOUT,
	FM_PROVIDER_SET_LOGIN_INFO,
	FM_PROVIDER_PLAY,
	FM_PROVIDER_STOP,
	FM_PROVIDER_PAUSE,
	FM_PROVIDER_NEXT,
	FM_PROVIDER_RATE,
	FM_PROVIDER_UNRATE,
	FM_PROVIDER_ERROR = 0xff,
} FM_CMD;


typedef struct fm_cmd_table {
	char *cmdstr;
	FM_CMD cmd;
} fm_cmd_table_t;


#endif /*__CMD_PARSE_H__*/
