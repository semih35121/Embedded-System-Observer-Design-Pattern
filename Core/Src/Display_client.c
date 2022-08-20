/*
 * Display_client.c
 *
 *  Created on: 20 Ağu 2022
 *      Author: ibrhm
 */
#include "fertilizer_mixer_client.h"
#include <stdlib.h>
#include <main.h>
#include <string.h>
#include <stdio.h>
#include <stm32f4xx_hal.h>
#include <stm32f4xx.h>
#include "Display_client.h"
extern UART_HandleTypeDef huart2;
void display_client_init(display_client_t *const me) {
	me->fn_handler = display_client_handlenewdata;
}
display_client_t * display_client_create(void)
 {
	display_client_t *me = (display_client_t*) malloc(
			sizeof(display_client_t));
	if (me == NULL) {
		printf("Yetersiz bellek alani\r\n");
		return NULL;
	}
	display_client_init(me);
	return me;
}
void logspecifieddata(){
	char *log500data="";
	sprintf(log500data,"gllog500");
	printf("%s",log500data);
}

void display_client_handlenewdata(void *mydisplayclient,environmental_data_e data)
 {

	((display_client_t*) mydisplayclient)->data = data;
	logspecifieddata();
	/*printf(" Display Humudity:%d\r\n Display Temperature :%d\r\n Display  Sprayed:%d\r\n",((display_client_t*) mydisplayclient)->data.humudity,
				     ((display_client_t*) mydisplayclient)->data.temperature,
					 ((display_client_t*) mydisplayclient)->data.sprayed);*/
	//fertilizer_mixer_clientlog_handle(((fertilizer_mixer_client_t*) fertilizerclient)->data);
	//Process Data
		//Do something


}
void display_client_subscribe(display_client_t *const me,env_sensor_t *const server)
 {
	for (int i = 0; i < MAX_CLIENT; i++) {
		if (server->clients[i].pobject == (void*) me) {
			return;
		}
		if (server->clients[i].pobject == NULL) {
			server->n_client++;
			server->clients[i].pobject = (void*) me;
			server->clients[i].fn_handler = me->fn_handler;
			for (int j = i + 1; j < MAX_CLIENT; j++) {
				if ((server->clients[j].pobject) == me) {
					server->clients[j].pobject = NULL;
					server->clients[j].fn_handler = NULL;
					server->n_client--;

				}
			}
			return;
		}

	}

}
void display_client_unsubscribe(display_client_t *const me,env_sensor_t *const server)
 {
	for (int i = 0; i < MAX_CLIENT; i++) {
		if (server->clients[i].pobject == (void*) me) {
			server->clients[i].pobject = NULL;
			server->n_client--;
			server->clients[i].fn_handler = NULL;
		}
	}

}
void display_client_destroy(display_client_t *const me)
 {
	printf("display client has destroyed\r\n");
	free(me);
}

