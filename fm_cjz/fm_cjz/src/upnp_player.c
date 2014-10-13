/*
 * upnpPlayer.c
 *
 *  Created on: 2014-3-25
 *      Author: chentao
 */

#include <stdio.h>
#include <upnp_player.h>
#include <string.h>
#include <debug.h>
#include <upnp_util.h>


/*!
 * Mutex for protecting the global device list in a multi-threaded,
 * asynchronous environment. All functions should lock this mutex before
 * reading or writing the device list. 
 */
ithread_mutex_t DeviceListMutex;

UpnpClient_Handle g_handle=-1;

#define RK_SERVICE_SERVCOUNT    3
#define RK_SERVICE_AV           0  

#define RK_MAXVARS              5

#define RK_SUCCESS      0
#define RK_ERROR        (-1)
#define RK_WARNING      1

#define RK_AV_VARCOUNT  4
#define RK_CM_VARCOUNT  0
#define RK_RC_VARCOUNT  0

#define RK_MAX_VAL_LEN      5

extern char RKVarCount[];

char RKVarCount[RK_SERVICE_SERVCOUNT] =
    { RK_AV_VARCOUNT, RK_CM_VARCOUNT, RK_RC_VARCOUNT };

/*!
   Global arrays for storing variable names and counts for 
   TvControl and TvPicture services 
 */
const char *RKVarName[RK_SERVICE_SERVCOUNT][RK_MAXVARS] = {
    {"AVTransportURI", "NextAVTransportURI", "NextAVTransportURIMetaData", "LastChange"}
};

/*! Service names.*/
const char *RKServiceName[] = { "AVTransport", "ConnectionManager", "RenderingControl" };

/*!
   Timeout to request during subscriptions 
 */
int default_timeout = 1801;

struct rk_service {
    char ServiceId[NAME_SIZE];
    char ServiceType[NAME_SIZE];
    char *VariableStrVal[RK_MAXVARS];
    char EventURL[NAME_SIZE];
    char ControlURL[NAME_SIZE];
    char SID[NAME_SIZE];
};

extern struct RKDeviceNode *GlobalDeviceList;

struct RKDevice {
    char UDN[250];
    char DescDocURL[250];
    char FriendlyName[250];
    char PresURL[250];
    int  AdvrTimeOut;
    struct rk_service RKService[RK_SERVICE_SERVCOUNT];
};

struct RKDeviceNode {
    struct RKDevice device;
    struct RKDeviceNode *next;
};


/*! Device type for rk device. */
const char RKDeviceType[] = "urn:schemas-upnp-org:device:MediaRenderer:1";

/*!
   The first node in the global device list, or NULL if empty 
 */
struct RKDeviceNode *GlobalDeviceList = NULL;

/********************************************************************************
 * RKCtrlPointPrintList
 *
 * Description: 
 *       Print the universal device names for each device in the global device list
 *
 * Parameters:
 *   None
 *
 ********************************************************************************/
int RKCtrlPointPrintList()
{
    struct RKDeviceNode *tmpdevnode;
    int i = 0;

    ithread_mutex_lock(&DeviceListMutex);

    tmpdevnode = GlobalDeviceList;
    while (tmpdevnode) {
        SampleUtil_Print(" %3d -- %s\n", ++i, tmpdevnode->device.FriendlyName);
        tmpdevnode = tmpdevnode->next;
    }
    // SampleUtil_Print("\n");
    ithread_mutex_unlock(&DeviceListMutex);

    return RK_SUCCESS;
}


void RKStateUpdate(char *UDN, int Service, IXML_Document *ChangedVariables,
           char **State)
{
    IXML_NodeList *properties;
    IXML_NodeList *variables;
    IXML_Element *property;
    IXML_Element *variable;
    long unsigned int length;
    long unsigned int length1;
    long unsigned int i;
    int j;
    char *tmpstate = NULL;

    SampleUtil_Print("RK State Update (service %d):\n", Service);
    /* Find all of the e:property tags in the document */
    properties = ixmlDocument_getElementsByTagName(ChangedVariables,
        "e:property");
    if (properties) {
        length = ixmlNodeList_length(properties);
        for (i = 0; i < length; i++) {
            /* Loop through each property change found */
            property = (IXML_Element *)ixmlNodeList_item(
                properties, i);
            /* For each variable name in the state table,
             * check if this is a corresponding property change */
            for (j = 0; j < RKVarCount[Service]; j++) {

                SampleUtil_Print("RKVarName[Service][j]:%s\n", RKVarName[Service][j]);

		
//		printf("property:\n%s\n",ixmlNode_getNodeValue(property->n));

                variables = ixmlElement_getElementsByTagName(
                    property, RKVarName[Service][j]);
                /* If a match is found, extract 
                 * the value, and update the state table */
                if (variables) {
                    length1 = ixmlNodeList_length(variables);
                    if (length1) {
                        variable = (IXML_Element *)
                            ixmlNodeList_item(variables, 0);


			IXML_NodeList *_parameters= ixmlNode_getChildNodes(
						variable);	
			if (_parameters) {
				printf("parameters parsed\n");
				int _parameters_len = ixmlNodeList_length(_parameters);
				int _i = 0;
				for (_i;_i<_parameters_len;_i++) {
					printf("the p:%d\n", _i);

					IXML_Node * _theNode = ixmlNodeList_item(_parameters, _i);
					if (eINVALID_NODE == ixmlNode_getNodeType(_theNode))
					{
						printf("theNode is invalid\n");
					}else{
						int _type = ixmlNode_getNodeType(_theNode);
						if (_type == eTEXT_NODE) {
							DOMString *_theValue = ixmlNode_getNodeValue(_theNode);
							printf("the value:%s\n", _theValue);
							
							if(strcasestr(_theValue, "<TransportState val=\"STOPPED\"/>")) {
								// if(strcasestr(_theValue, "<CurrentTransportActions val=\"Play,Stop\"/>"))
                                {
									printf("kkkkkkkkkkkkkkkk\n");
									//to_play_next_song();
									printf("good!\n");
								}
							}

//							IXML_NodeList *_instances= ixmlElement_getElementsByTagName(
//									_theNode, "Event");
//							int _nodeLength = ixmlNodeList_length(_instances);
//							printf("_nodeLength:%d\n", _nodeLength);
//							if (_instances) ixmlNodeList_free(_instances);
							
						}else
							printf("theType:%d\n",_type);
						_theNode = NULL;	
					}
				}

				ixmlNodeList_free(_parameters);
				_parameters= NULL;
			}else printf("parameters false\n");




                    }
                    ixmlNodeList_free(variables);
                    variables = NULL;
                }
            }
        }
        ixmlNodeList_free(properties);
    }
    return;
    UDN = UDN;
}

/********************************************************************************
 * RKCtrlPointHandleEvent
 *
 * Description: 
 *       Handle a UPnP event that was received.  Process the event and update
 *       the appropriate service state table.
 *
 * Parameters:
 *   sid -- The subscription id for the event
 *   eventkey -- The eventkey number for the event
 *   changes -- The DOM document representing the changes
 *
 ********************************************************************************/
void RKCtrlPointHandleEvent(
    const char *sid,
    int evntkey,
    IXML_Document *changes)
{
    struct RKDeviceNode *tmpdevnode;
    int service;

    SampleUtil_Print("RKCtrlPointHandleEvent recved\n evntkey is:%d\n sid:%s\n", evntkey,sid);

    tmpdevnode = GlobalDeviceList;
    while (tmpdevnode) {
        for (service = 0; service < RK_SERVICE_SERVCOUNT; ++service) {
            if (strcmp(tmpdevnode->device.RKService[service].SID, sid) ==  0) {
                SampleUtil_Print("Received RK %s Event: %d for SID %s\n",
                    RKServiceName[service],
                    evntkey,
                    sid);
                RKStateUpdate(
                    tmpdevnode->device.UDN,
                    service,
                    changes,
                    (char **)&tmpdevnode->device.RKService[service].VariableStrVal);
                break;
            }
        }
        tmpdevnode = tmpdevnode->next;
    }
}


/********************************************************************************
 * RKCtrlPointCallbackEventHandler
 *
 * Description: 
 *       The callback handler registered with the SDK while registering
 *       the control point.  Detects the type of callback, and passes the 
 *       request on to the appropriate function.
 *
 * Parameters:
 *   EventType -- The type of callback event
 *   Event -- Data structure containing event data
 *   Cookie -- Optional data specified during callback registration
 *
 ********************************************************************************/
int RKCtrlPointCallbackEventHandler(Upnp_EventType EventType, void *Event, void *Cookie)
{
    /*int errCode = 0;*/

    switch ( EventType ) {
    /* SSDP Stuff */
    case UPNP_DISCOVERY_ADVERTISEMENT_ALIVE:
    case UPNP_DISCOVERY_SEARCH_RESULT: {
        SampleUtil_Print("UPNP_DISCOVERY_SEARCH_RESULT\n");
        struct Upnp_Discovery *d_event = (struct Upnp_Discovery *)Event;
        IXML_Document *DescDoc = NULL;
        int ret;

        if (d_event->ErrCode != UPNP_E_SUCCESS) {
            SampleUtil_Print("Error in Discovery Callback -- %d\n",
                d_event->ErrCode);
        }
        ret = UpnpDownloadXmlDoc(d_event->Location, &DescDoc);
        if (ret != UPNP_E_SUCCESS) {
            SampleUtil_Print("Error obtaining device description from %s -- error = %d\n",
                d_event->Location, ret);
        } else {
            SampleUtil_Print("found device ,add it.\n");
            RKCtrlPointAddDevice(
                DescDoc, d_event->Location, d_event->Expires);
        }
        if (DescDoc) {
            ixmlDocument_free(DescDoc);
        }
        RKCtrlPointPrintList();
        break;
    }
    case UPNP_DISCOVERY_SEARCH_TIMEOUT:
        /* Nothing to do here... */
        break;
    case UPNP_DISCOVERY_ADVERTISEMENT_BYEBYE: {
        struct Upnp_Discovery *d_event = (struct Upnp_Discovery *)Event;

        if (d_event->ErrCode != UPNP_E_SUCCESS) {
            SampleUtil_Print("Error in Discovery ByeBye Callback -- %d\n",
                    d_event->ErrCode);
        }
        SampleUtil_Print("Received ByeBye for Device: %s\n", d_event->DeviceId);
        // RKCtrlPointRemoveDevice(d_event->DeviceId);
        SampleUtil_Print("After byebye:\n");
        // RKCtrlPointPrintList();
        break;
    }
    /* SOAP Stuff */
    case UPNP_CONTROL_ACTION_COMPLETE: {
        struct Upnp_Action_Complete *a_event = (struct Upnp_Action_Complete *)Event;

        if (a_event->ErrCode != UPNP_E_SUCCESS) {
            SampleUtil_Print("Error in  Action Complete Callback -- %d\n",
                    a_event->ErrCode);
        }
        /* No need for any processing here, just print out results.
         * Service state table updates are handled by events. */
        break;
    }
    case UPNP_CONTROL_GET_VAR_COMPLETE: {
        struct Upnp_State_Var_Complete *sv_event = (struct Upnp_State_Var_Complete *)Event;

        if (sv_event->ErrCode != UPNP_E_SUCCESS) {
            SampleUtil_Print("Error in Get Var Complete Callback -- %d\n",
                    sv_event->ErrCode);
        } else {
            // RKCtrlPointHandleGetVar(
            //     sv_event->CtrlUrl,
            //     sv_event->StateVarName,
            //     sv_event->CurrentVal);
        }
        break;
    }
    /* GENA Stuff */
    case UPNP_EVENT_RECEIVED: {
        SampleUtil_PrintEvent(EventType, Event);

        struct Upnp_Event *e_event = (struct Upnp_Event *)Event;

        RKCtrlPointHandleEvent(
            e_event->Sid,
            e_event->EventKey,
            e_event->ChangedVariables);
        break;
    }
    case UPNP_EVENT_SUBSCRIBE_COMPLETE:
    case UPNP_EVENT_UNSUBSCRIBE_COMPLETE:
    case UPNP_EVENT_RENEWAL_COMPLETE: {
        struct Upnp_Event_Subscribe *es_event = (struct Upnp_Event_Subscribe *)Event;

        if (es_event->ErrCode != UPNP_E_SUCCESS) {
            SampleUtil_Print("Error in Event Subscribe Callback -- %d\n",
                    es_event->ErrCode);
        } else {
            // TvCtrlPointHandleSubscribeUpdate(
            //     es_event->PublisherUrl,
            //     es_event->Sid,
            //     es_event->TimeOut);
        }
        break;
    }
    case UPNP_EVENT_AUTORENEWAL_FAILED:
    case UPNP_EVENT_SUBSCRIPTION_EXPIRED: {
        struct Upnp_Event_Subscribe *es_event = (struct Upnp_Event_Subscribe *)Event;
        int TimeOut = default_timeout;
        Upnp_SID newSID;
        int ret;

        ret = UpnpSubscribe(
            g_handle,
            es_event->PublisherUrl,
            &TimeOut,
            newSID);
        if (ret == UPNP_E_SUCCESS) {
            SampleUtil_Print("Subscribed to EventURL with SID=%s\n", newSID);
            // TvCtrlPointHandleSubscribeUpdate(
            //     es_event->PublisherUrl,
            //     newSID,
            //     TimeOut);
        } else {
            SampleUtil_Print("Error Subscribing to EventURL -- %d\n", ret);
        }
        break;
    }
    /* ignore these cases, since this is not a device */
    case UPNP_EVENT_SUBSCRIPTION_REQUEST:
    case UPNP_CONTROL_GET_VAR_REQUEST:
    case UPNP_CONTROL_ACTION_REQUEST:
        break;
    }

    return 0;
    Cookie = Cookie;
}

/********************************************************************************
 * RKCtrlPointAddDevice
 *
 * Description: 
 *       If the device is not already included in the global device list,
 *       add it.  Otherwise, update its advertisement expiration timeout.
 *
 * Parameters:
 *   DescDoc -- The description document for the device
 *   location -- The location of the description document URL
 *   expires -- The expiration time for this advertisement
 *
 ********************************************************************************/
void RKCtrlPointAddDevice(
    IXML_Document *DescDoc,
    const char *location,
    int expires)
{
    char *deviceType = NULL;
    char *friendlyName = NULL;
    char presURL[200];
    char *baseURL = NULL;
    char *relURL = NULL;
    char *UDN = NULL;
    char *serviceId[RK_SERVICE_SERVCOUNT] = { NULL, NULL };
    char *eventURL[RK_SERVICE_SERVCOUNT] = { NULL, NULL };
    char *controlURL[RK_SERVICE_SERVCOUNT] = { NULL, NULL };
    Upnp_SID eventSID[RK_SERVICE_SERVCOUNT];
    int TimeOut[RK_SERVICE_SERVCOUNT] = {
        default_timeout,
        default_timeout
    };
    struct RKDeviceNode *deviceNode;
    struct RKDeviceNode *tmpdevnode;
    int ret = 1;
    int found = 0;
    int service;
    int var;

    ithread_mutex_lock(&DeviceListMutex);

    /* Read key elements from description document */
    UDN = SampleUtil_GetFirstDocumentItem(DescDoc, "UDN");
    deviceType = SampleUtil_GetFirstDocumentItem(DescDoc, "deviceType");
    friendlyName = SampleUtil_GetFirstDocumentItem(DescDoc, "friendlyName");
    baseURL = SampleUtil_GetFirstDocumentItem(DescDoc, "URLBase");
    relURL = SampleUtil_GetFirstDocumentItem(DescDoc, "presentationURL");

    ret = UpnpResolveURL((baseURL ? baseURL : location), relURL, presURL);

    if (UPNP_E_SUCCESS != ret)
        SampleUtil_Print("Error generating presURL from %s + %s\n",
                 baseURL, relURL);

    if (strcmp(deviceType, RKDeviceType) == 0) {
        SampleUtil_Print("Found RK device\n");

        /* Check if this device is already in the list */
        tmpdevnode = GlobalDeviceList;
        while (tmpdevnode) {
            if (strcmp(tmpdevnode->device.UDN, UDN) == 0) {
                found = 1;
                break;
            }
            tmpdevnode = tmpdevnode->next;
        }

        if (found) {
            /* The device is already there, so just update  */
            /* the advertisement timeout field */
            tmpdevnode->device.AdvrTimeOut = expires;
        } else {
            for (service = 0; service < RK_SERVICE_SERVCOUNT;
                 service++) {
                if (SampleUtil_FindAndParseService
                    (DescDoc, location, RKServiceType[service],
                     &serviceId[service], &eventURL[service],
                     &controlURL[service])) {
                    SampleUtil_Print
                        ("Subscribing to EventURL %s...\n",
                         eventURL[service]);
                    ret =
                        UpnpSubscribe(g_handle,
                              eventURL[service],
                              &TimeOut[service],
                              eventSID[service]);
                    if (ret == UPNP_E_SUCCESS) {
                        SampleUtil_Print
                            ("Subscribed to EventURL with SID=%s\n",
                             eventSID[service]);
                    } else {
                        SampleUtil_Print
                            ("Error Subscribing to EventURL -- %d\n",
                             ret);
                        strcpy(eventSID[service], "");
                    }
                } else {
                    SampleUtil_Print
                        ("Error: Could not find Service: %s\n",
                         RKServiceType[service]);
                }
            }
            /* Create a new device node */
            deviceNode =
                (struct RKDeviceNode *)
                malloc(sizeof(struct RKDeviceNode));
            strcpy(deviceNode->device.UDN, UDN);
            strcpy(deviceNode->device.DescDocURL, location);
            strcpy(deviceNode->device.FriendlyName, friendlyName);
            strcpy(deviceNode->device.PresURL, presURL);
            deviceNode->device.AdvrTimeOut = expires;
            for (service = 0; service < RK_SERVICE_SERVCOUNT;
                 service++) {
                if (serviceId[service] == NULL) {
                    /* not found */
                    continue;
                }
                strcpy(deviceNode->device.RKService[service].
                       ServiceId, serviceId[service]);
                strcpy(deviceNode->device.RKService[service].
                       ServiceType, RKServiceType[service]);
                strcpy(deviceNode->device.RKService[service].
                       ControlURL, controlURL[service]);
                strcpy(deviceNode->device.RKService[service].
                       EventURL, eventURL[service]);
                strcpy(deviceNode->device.RKService[service].
                       SID, eventSID[service]);
                for (var = 0; var < RKVarCount[service]; var++) {
                    deviceNode->device.
                        RKService[service].VariableStrVal
                        [var] =
                        (char *)malloc(RK_MAX_VAL_LEN);
                    strcpy(deviceNode->device.
                           RKService[service].VariableStrVal
                           [var], "");
                }
            }
            deviceNode->next = NULL;
            /* Insert the new device node in the list */
            if ((tmpdevnode = GlobalDeviceList)) {
                while (tmpdevnode) {
                    if (tmpdevnode->next) {
                        tmpdevnode = tmpdevnode->next;
                    } else {
                        tmpdevnode->next = deviceNode;
                        break;
                    }
                }
            } else {
                GlobalDeviceList = deviceNode;
            }
            /*Notify New Device Added */
            SampleUtil_StateUpdate(NULL, NULL,
                           deviceNode->device.UDN,
                           DEVICE_ADDED);
        }
    }

    ithread_mutex_unlock(&DeviceListMutex);

    if (deviceType)
        free(deviceType);
    if (friendlyName)
        free(friendlyName);
    if (UDN)
        free(UDN);
    if (baseURL)
        free(baseURL);
    if (relURL)
        free(relURL);
    for (service = 0; service < RK_SERVICE_SERVCOUNT; service++) {
        if (serviceId[service])
            free(serviceId[service]);
        if (controlURL[service])
            free(controlURL[service]);
        if (eventURL[service])
            free(eventURL[service]);
    }
}


/********************************************************************************
 * RKCtrlPointGetDevice
 *
 * Description: 
 *       Given a list number, returns the pointer to the device
 *       node at that position in the global device list.  Note
 *       that this function is not thread safe.  It must be called 
 *       from a function that has locked the global device list.
 *
 * Parameters:
 *   devnum -- The number of the device (order in the list,
 *             starting with 1)
 *   devnode -- The output device node pointer
 *
 ********************************************************************************/
int RKCtrlPointGetDevice(int devnum, struct RKDeviceNode **devnode)
{
    int count = devnum;
    struct RKDeviceNode *tmpdevnode = NULL;

    if (count)
        tmpdevnode = GlobalDeviceList;
    while (--count && tmpdevnode) {
        tmpdevnode = tmpdevnode->next;
    }
    if (!tmpdevnode) {
        SampleUtil_Print("Error finding RKDevice number -- %d\n",
                 devnum);
        return RK_ERROR;
    }
    *devnode = tmpdevnode;

    SampleUtil_Print("RKCtrlPointGetDevice finished.\n");

    return RK_SUCCESS;
}

/********************************************************************************
 * RKCtrlPointSendAction
 *
 * Description: 
 *       Send an Action request to the specified service of a device.
 *
 * Parameters:
 *   service -- The service
 *   devnum -- The number of the device (order in the list,
 *             starting with 1)
 *   actionname -- The name of the action.
 *   param_name -- An array of parameter names
 *   param_val -- The corresponding parameter values
 *   param_count -- The number of parameters
 *
 ********************************************************************************/
int RKCtrlPointSendAction(
    int service,
    int devnum,
    const char *actionname,
    const char **param_name,
    char **param_val,
    int param_count)
{
    struct RKDeviceNode *devnode;
    IXML_Document *actionNode = NULL;
    int rc = RK_SUCCESS;
    int param;


    SampleUtil_Print("RKServiceType[service] is: %s\n devnum: %d\n", RKServiceType[service], devnum);

    rc = RKCtrlPointGetDevice(devnum, &devnode);
    if (RK_SUCCESS == rc) {
        if (0 == param_count) {
            actionNode =
                UpnpMakeAction(actionname, RKServiceType[service],
                       0, NULL);
        } else {
            SampleUtil_Print("actionname: %s, RKServiceType[service]:%s\n", actionname,RKServiceType[service]);            
            for (param = 0; param < param_count; param++) {
                SampleUtil_Print("param_count:%d, param_name[param]: %s, param_val[param]:%s\n", param_count,param_name[param],param_val[param]);            
                if (UpnpAddToAction(&actionNode, actionname,
                     RKServiceType[service], param_name[param],
                     param_val[param]) != UPNP_E_SUCCESS) {
                        SampleUtil_Print("ERROR: RKCtrlPointSendAction: Trying to add action param\n");
                    /*return -1; // TBD - BAD! leaves mutex locked */
                }
            }
        }

        rc = UpnpSendActionAsync(g_handle,
                     devnode->device.
                     RKService[service].ControlURL,
                     RKServiceType[service], NULL,
                     actionNode,
                     RKCtrlPointCallbackEventHandler, NULL);

        if (rc != UPNP_E_SUCCESS) {
            SampleUtil_Print("Error in UpnpSendActionAsync -- %d\n",
                     rc);
            rc = RK_ERROR;
        }else{
            SampleUtil_Print("good\n");
        }
    }


    if (actionNode)
        ixmlDocument_free(actionNode);

    return rc;
}

void play_next_function(fm_player_t *player)
{
// 	while(TRUE)
// 	{
// 		sleep(5);
// 		if(player->status == FM_PLAYER_PLAY)
// 		{
// 			array_list* devices = getYuePodDevice(player, &player->controlPoint);
// 			int i;
// 			for (i=0; i<devices->length; i++)
// 			{
// 				CgUpnpDevice *device = array_list_get_idx(devices, i);
// 				CgUpnpAction *getTransportInfo = cg_upnp_device_getactionbyname(device, "GetTransportInfo");
// 				CgUpnpArgument *instanceID = cg_upnp_action_getargumentbyname(getTransportInfo, "InstanceID");
// 				cg_upnp_argument_setintvalue(instanceID, 0);
// 				cg_upnp_action_post(getTransportInfo);
// 				CgUpnpArgument *currentTransportState = cg_upnp_action_getargumentbyname(getTransportInfo, "CurrentTransportState");
// 				if(strcasecmp("STOPPED", currentTransportState->value))
// 				{
// 					to_play_next_song();
// 				}
// 			}
// 		}
// 	}
}


int fm_player_open(fm_player_t *pl)
{
	LOGV("fm_player_open\n");
	pl->status = FM_PLAYER_STOP;
	return 0;
}


BOOL fm_player_set_url(fm_player_t *player, const char *url)
{
	LOGV("Player set url: %s\n", url);

    char *paramName[3] = {
        "InstanceID",
        "CurrentURI",
        "CurrentURIMetaData"
    };

    char *paramValue[3] = {
        "0",
        url,
        ""
    };

    struct RKDeviceNode *tmpdevnode;

    ithread_mutex_lock(&DeviceListMutex);

    tmpdevnode = GlobalDeviceList;
    BOOL ret = TRUE;

    while (tmpdevnode) {
        if (RK_SUCCESS != RKCtrlPointSendAction(
                RK_SERVICE_AV, 1, "SetAVTransportURI", &paramName,
                &paramValue, 3))
            ret = FALSE;

        tmpdevnode = tmpdevnode->next;
    }

    ithread_mutex_unlock(&DeviceListMutex);
    return ret;
}

BOOL fm_player_set_next_url(fm_player_t *player, const char *url)
{
	LOGV("Player set url: %s\n", url);

    char *paramName[3] = {
        "InstanceID",
        "CurrentURI",
        "CurrentURIMetaData"
    };

    char *paramValue[3] = {
        0,
        url,
        0
    };

    // sprintf(param_val_a, "%d", paramValue);
    return RKCtrlPointSendAction(
        RK_SERVICE_AV, 1, "SetAVTransportURI", &paramName,
        &paramValue, 3);


	// int i;
	// array_list* devices = getYuePodDevice(player, &player->controlPoint);
	// for (i=0; i<devices->length; i++)
	// {
	// 	CgUpnpDevice *device = array_list_get_idx(devices, i);
	// 	CgUpnpAction *setNextAVTransportURI = cg_upnp_device_getactionbyname(
	// 			device, "SetAVTransportURI");
	// 	CgUpnpArgument *instanceID = cg_upnp_action_getargumentbyname(
	// 			setNextAVTransportURI, "InstanceID");
	// 	cg_upnp_argument_setintvalue(instanceID, 0);
	// 	CgUpnpArgument *currentURI = cg_upnp_action_getargumentbyname(
	// 			setNextAVTransportURI, "NextURI");
	// 	cg_upnp_argument_setvalue(currentURI, url);
	// 	CgUpnpArgument *currentURIMetaData = cg_upnp_action_getargumentbyname(
	// 			setNextAVTransportURI, "NextURIMetaData");
	// 	cg_upnp_argument_setintvalue(currentURIMetaData, 0);
	// 	cg_upnp_action_post(setNextAVTransportURI);
	// }
	return TRUE;
}

void fm_player_play(fm_player_t *player)
{
	LOGV("Player play\n");
    
    char *paramName[2] = {
        "InstanceID",
        "Speed"
    };

    char *paramValue[2] = {
        "0",
        "1"
    };

    struct RKDeviceNode *tmpdevnode;
    ithread_mutex_lock(&DeviceListMutex);

    tmpdevnode = GlobalDeviceList;
    while (tmpdevnode) {
        RKCtrlPointSendAction(RK_SERVICE_AV, 1, "Play", &paramName,
                                &paramValue, 2);
        tmpdevnode = tmpdevnode->next;
    }

    ithread_mutex_unlock(&DeviceListMutex);

	player->status = FM_PLAYER_PLAY;

}

void fm_player_pause(fm_player_t *player)
{
	LOGV("Player pause\n");

    char *paramName[1] = {
        "InstanceID"
    };

    char *paramValue[2] = {
        "0"
    };

    // sprintf(param_val_a, "%d", paramValue);

    struct RKDeviceNode *tmpdevnode;
    ithread_mutex_lock(&DeviceListMutex);

    tmpdevnode = GlobalDeviceList;
    while (tmpdevnode) {
        RKCtrlPointSendAction(RK_SERVICE_AV, 1, "Pause", &paramName,
            &paramValue, 1);

        tmpdevnode = tmpdevnode->next;
    }

    ithread_mutex_unlock(&DeviceListMutex);

	player->status = FM_PLAYER_PAUSE;
}

void fm_player_stop(fm_player_t *player)
{
    LOGV("Player stop\n");

    char *paramName[1] = {
        "InstanceID"
    };

    char *paramValue[2] = {
        "0"
    };


    RKCtrlPointSendAction(
        RK_SERVICE_AV, 1, "Stop", &paramName,
        &paramValue, 1);
	player->status = FM_PLAYER_STOP;
}

int fm_player_init(fm_player_t *player)
{
	int ret=0;
	int timeout=0;
	Upnp_SID sid;
	// IXML_Document *action=NULL;
	char actionxml[250];

    ithread_mutex_init(&DeviceListMutex, 0);

    SampleUtil_Initialize(linux_print);

  /* First, initialize the UPnP Library. */
	ret = UpnpInit(NULL, 0);
	if(ret != UPNP_E_SUCCESS) {
		printf("UpnpInit failed\n");
		return ret;
	}

  /* Next, register yourself as a Client. */
    SampleUtil_Print("Registering Control Point\n");
	ret = UpnpRegisterClient(RKCtrlPointCallbackEventHandler, &g_handle, &g_handle);
	if(ret != UPNP_E_SUCCESS) {
		printf("UpnpRegisterClient failed\n");
		return ret;
	}

  /* Send out a search request for your device. */
	ret = UpnpSearchAsync(g_handle, 5, 
		"urn:schemas-upnp-org:device:MediaRenderer:1", NULL);
	if(ret != UPNP_E_SUCCESS) {
		printf("upnpSearchAsync returned ret: %d\n", ret);
		return ret;
	}
}

void fm_player_exit()
{
  /* Unregister yourself with the library. */
	int ret = UpnpUnRegisterClient(g_handle);
	if(ret != UPNP_E_SUCCESS) {
		printf("UpnpUnRegisterClient failed\n");
	}

  /* Clean up the library. */
	// ixmlDocument_free(action);
	UpnpFinish();
}


// void DeviceNotifyReceived(CgUpnpSSDPPacket *ssdpPkt)
// {
// 	char *uuid = cg_upnp_ssdp_packet_getusn( ssdpPkt);
// 	char *target = cg_upnp_ssdp_packet_getnt( ssdpPkt);
// 	char *subType = cg_upnp_ssdp_packet_getnts( ssdpPkt);
// 	char *where = cg_upnp_ssdp_packet_getlocation( ssdpPkt);
// }

// void DeviceSearchResponseReceived(CgUpnpSSDPPacket *ssdpPkt)
// {
// 	char *uuid = cg_upnp_ssdp_packet_getusn( ssdpPkt);
// 	char *target = cg_upnp_ssdp_packet_getnt(ssdpPkt);
// 	char *subType = cg_upnp_ssdp_packet_getnts( ssdpPkt);
// 	char *where = cg_upnp_ssdp_packet_getlocation( ssdpPkt);
// }

// array_list* getYuePodDevice(fm_player_t* player, CgUpnpControlPoint* ctrlPoint)
// {
// 	array_list* yuepods = (struct array_list*)calloc(1, sizeof(struct array_list));

// 	CgUpnpDevice* dev;
// 	int devCnt = 0;
// 	LOGV("Device Num = %d\n", cg_upnp_controlpoint_getndevices(ctrlPoint));
// 	for (dev = cg_upnp_controlpoint_getdevices(ctrlPoint); dev != NULL; dev =
// 			cg_upnp_device_next(dev)) {
// 		if(strcmp(cg_upnp_device_getmanufacturer(dev), MANUFACTURER) == 0)
// 		{
// 			CgUpnpService *playService = cg_upnp_device_getservicebytype(dev, "urn:schemas-upnp-org:service:AVTransport:1");
// 			if (cg_upnp_controlpoint_subscribe(ctrlPoint, playService, 6000) == TRUE)
// 			{
// 				strcpy(m_sid, cg_upnp_service_getsubscriptionsid(playService));
// 			}
// 			array_list_add(yuepods, dev);
// 		}
// 		LOGV("[%d] = %s\n", ++devCnt, cg_upnp_device_getfriendlyname(dev));
// 	}

// 	return yuepods;
// }
