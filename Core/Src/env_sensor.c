/*
 * env_sensor.c
 *
 *  Created on: Aug 6, 2022
 *      Author: ibrhm
 */
#include "env_sensor.h"
#include <stdlib.h>
#include <stdio.h>
#include <stm32f4xx_hal.h>
#include <stm32f4xx.h>
extern UART_HandleTypeDef huart2;


void env_sensor_init(env_sensor_t *const me) {
	for (int i = 0; i < MAX_CLIENT; i++) {
		me->clients[i].fn_handler = NULL;
		me->clients[i].pobject = NULL;
	}

}
env_sensor_t* env_sensor_create(void) {

	env_sensor_t *newclient = (env_sensor_t*) malloc(sizeof(env_sensor_t));
	if (newclient != NULL) {
		env_sensor_init(newclient);
	}
	return newclient;

}
void env_sensor_get_data(env_sensor_t *const me) {
	me->data.temperature = (rand() % 10);
	me->data.humudity = (rand() % 200);
	me->data.sprayed = true;
	//Notify Client
	env_sensor_notify(me);
}
void env_sensor_notify(env_sensor_t *const me) {
	for (int i = 0; i < MAX_CLIENT; i++) {
		if (me->clients[i].pobject != NULL && me->clients[i].fn_handler != NULL) {
			me->clients[i].fn_handler(me->clients[i].pobject, me->data);
		}
	}

}
void env_sensor_dumplist(env_sensor_t *const me) {
	printf("Dumplist :  \t number of Clients: %d\n\r", me->n_client);

	for (int i = 0; i < MAX_CLIENT; i++) {
		if (me->clients[i].fn_handler != NULL && me->clients[i].pobject != NULL) {
			printf("\T POBJECT :%p \t fn_handler: %p\n\r",
					me->clients[i].pobject, me->clients[i].fn_handler);
		}
	}

}
void env_sensor_destroy(env_sensor_t *const me) {
	//Do something
	free(me);

}

