/*
 * env_sensor.h
 *
 *  Created on: Aug 6, 2022
 *      Author: ibrhm
 */

#ifndef INC_ENV_SENSOR_H_
#define INC_ENV_SENSOR_H_
#include "environmental_data.h"
#define  MAX_CLIENT 10
//Callback Function for notification

typedef void (*callback_fn)(void * pobject,environmental_data_e data);
typedef struct notify_handler{
	void *pobject;//Pointer to Client Object
	callback_fn fn_handler;//Callback fn;
}notify_handler_t;

typedef struct env_sensor{
	environmental_data_e data;
	uint32_t n_client;
	notify_handler_t clients[MAX_CLIENT];
}env_sensor_t;


env_sensor_t * env_sensor_create(void);
void env_sensor_get_data(env_sensor_t * const me);
void env_sensor_notify(env_sensor_t * const me);
void env_sensor_dumplist(env_sensor_t * const me);
void env_sensor_destroy(env_sensor_t * const me);











#endif /* INC_ENV_SENSOR_H_ */
