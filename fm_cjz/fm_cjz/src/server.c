#include <stdio.h>
#include <fm_rcs.h>
#include <service_provider.h>
#include <cmd_parse.h>

#define RECV_BUF_SIZE 10 

void cmd_parse(service_provider *sp, char *cmdstr)
{
	song_entry *song = NULL;
	//server* sver = sp->get_server_by_name(sp, "lapsule");
	server* sver = sp->get_server_by_name(sp, "douban");
	proxy *pxy = sp->pxy;
	sp->cur_server = sver;

	FM_CMD cmd = get_cmd_from_str(cmdstr);
	//LOGD("cmd = %d\n", cmd);
	switch (cmd) {
		case FM_PROVIDER_LOGIN:
			if (!sver) {
				printf("no available server\n");
			} else {
				sp->get_current_server(sp)->login(sver, pxy, "cjzswust@gmail.com", "cjz5023091");
			}
			break;
		case FM_PROVIDER_STOP:
			if (!sver) {
				printf("no available provider\n");
			} else {
				sver->logout(sver);
			}
			break;	
		case FM_PROVIDER_SET_LOGIN_INFO:
	
			//fm_provider_set_login_info();
			break;
		case FM_PROVIDER_NEXT:
			song = sver->next_song(sver, pxy);
			if (!song) {
				LOGE("don't have songs\n");
			} else {
				if (song->name && song->id && song->url && song->album && song->picture) {
					LOGV("current song is:\n");
					LOGI("name  : %s\n", song->name);
					LOGI("ID    : %d\n", song->id);
					LOGI("URL   : %s\n", song->url);
					LOGI("album : %s\n", song->album);
					LOGI("cover : %s\n", song->picture);
				} else {
					LOGE("server returned a invalid song struct\n");
				}
			} 
			break;
		default:
			break;
	}
}

/**
 * brief: once a remote controller connected, 
 *        a fm_rcs_callback thread will be created to response commands
 * param: a pointer which point to a connected socket you can communicate 
 *        with remote controller
 */
void *fm_rcs_callback(void *args)
{
	int nread = 0;;
	fm_rcs_t *prcs = (fm_rcs_t*)args;
	int confd = prcs->consfd;
	service_provider *sp = (service_provider*)prcs->data;
	char recv_buf[RECV_BUF_SIZE] = {0};

	char client_ip[INET6_ADDRSTRLEN] = {0};
	int cli_port;
	fm_rcs_get_peer_info(confd, client_ip, sizeof(client_ip), &cli_port);
	LOGV("cli_ip: %s, port: %d [\033[32mconnected\033[0m]\n", client_ip, cli_port);
	
	//LOGI("connected fd = %d\n", confd);

	while(1) {
		bzero(recv_buf, sizeof(recv_buf));
		if( (nread = read(confd, recv_buf, sizeof(recv_buf) -1)) <= 0 ) {
			if (nread == 0) {
				break;
			} else {
				LOGE("read(): %s\n", strerror(errno));	
			}
		} else {
			LOGI("%d characters received from %s\n", nread, client_ip);
			LOGV("%s", recv_buf);
			cmd_parse(sp, recv_buf);
		}
	}
	LOGV("cli_ip: %s, port: %d [\033[31mclosed\033[0m]\n", client_ip, cli_port);
	//raise(SIGUSR2);
	return NULL;
}

extern server *douban_server_register(void);

void servers_load_callback(service_provider *sp)
{
	LOGV("register cb\n");
	sp->add_servers(sp, douban_server_register());
	sp->add_servers(sp, lapsule_server_register());
}

int main(int argc, char **argv)
{
	service_provider *sp = new_service_provider(servers_load_callback);
	sp->servers_load(sp);
	
	fm_rcs_start(fm_rcs_callback, sp);
	
	fm_rcs_end();
	

	return 0;
}
