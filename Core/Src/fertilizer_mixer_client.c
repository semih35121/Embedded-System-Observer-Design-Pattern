/*
 * fertilizer_mixer_client.c
 *
 *  Created on: 9 Ağu 2022
 *      Author: ibrhm
 *
 */

#include "fertilizer_mixer_client.h"
#include <stdlib.h>
#include <main.h>
#include <string.h>
#include <stdio.h>
#include <stm32f4xx_hal.h>
#include <stm32f4xx.h>
extern UART_HandleTypeDef huart2;
char * fertilizer_loghandle="";
void fertilizer_mixer_client_init(fertilizer_mixer_client_t *const me) {
	me->fn_handler = fertilizer_mixer_client_handlenewdata;
}
fertilizer_mixer_client_t* fertilizer_mixer_client_create(void) {
	fertilizer_mixer_client_t *me = (fertilizer_mixer_client_t*) malloc(
			sizeof(fertilizer_mixer_client_t));
	if (me == NULL) {
		printf("Yetersiz bellek alani\r\n");
		return NULL;
	}
	fertilizer_mixer_client_init(me);
	return me;
}
void fertilizer_mixer_client_handlenewdata(void *fertilizerclient,
		environmental_data_e data) {
int a=12;
int b=14;
int c=15;
	((fertilizer_mixer_client_t*) fertilizerclient)->data = data;


		printf(" Humudity:%d\r\n  Temperature :%d\r\n  Sprayed:%d\r\n",((fertilizer_mixer_client_t*) fertilizerclient)->data.humudity,
			     ((fertilizer_mixer_client_t*) fertilizerclient)->data.temperature,
				 ((fertilizer_mixer_client_t*) fertilizerclient)->data.sprayed);
	//fertilizer_mixer_clientlog_handle(((fertilizer_mixer_client_t*) fertilizerclient)->data);
	//Process Data
		//Do something


}
void fertilizer_mixer_client_subscribe(fertilizer_mixer_client_t *const me,
		env_sensor_t *const server) {
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
void fertilizer_mixer_client_unsubscribe(fertilizer_mixer_client_t *const me,
		env_sensor_t *const server) {
	for (int i = 0; i < MAX_CLIENT; i++) {
		if (server->clients[i].pobject == (void*) me) {
			server->clients[i].pobject = NULL;
			server->n_client--;
			server->clients[i].fn_handler = NULL;
		}
	}

}
void fertilizer_mixer_client_destroy(fertilizer_mixer_client_t *const me) {
	printf("fertilizer client has destroyed\r\n");
	free(me);
}

