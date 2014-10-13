/*
 * upnpPlayer.h
 *
 *  Created on: 2014-3-25
 *      Author: chentao
 */

#ifndef DOUBANAGENT_H_
#define DOUBANAGENT_H_
 
#include <upnp_util.h>
#include <json-c/json.h>


typedef void (*play_next)();

enum fm_player_status {
    FM_PLAYER_PLAY,
    FM_PLAYER_PAUSE,
    FM_PLAYER_STOP
};

typedef struct fm_player {
    enum fm_player_status status;
    int sig_ack;
    // CgUpnpControlPoint controlPoint;
} fm_player_t;

extern ithread_mutex_t DeviceListMutex;

int fm_player_open(fm_player_t *pl);
BOOL fm_player_set_url(fm_player_t *pl, const char *url);
BOOL fm_player_set_next_url(fm_player_t *player, const char *url);
void fm_player_play(fm_player_t *pl);
void fm_player_pause(fm_player_t *pl);
void fm_player_toggle(fm_player_t *pl);
void fm_player_stop(fm_player_t *pl);

int fm_player_init(fm_player_t *player);
void fm_player_exit();

// array_list* getYuePodDevice(fm_player_t* player, CgUpnpControlPoint* ctrlPoint);
// void DeviceNotifyReceived(CgUpnpSSDPPacket *ssdpPkt);
// void DeviceSearchResponseReceived(CgUpnpSSDPPacket *ssdpPkt);

void RKCtrlPointAddDevice(IXML_Document *, const char *, int); 

void to_play_next_song();

#endif /* DOUBANAGENT_H_ */
