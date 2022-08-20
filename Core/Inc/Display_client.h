/*
 * Display_client.h
 *
 *  Created on: 20 Ağu 2022
 *      Author: ibrhm
 */

#ifndef INC_DISPLAY_CLIENT_H_
#define INC_DISPLAY_CLIENT_H_
#include "env_sensor.h"
#include "environmental_data.h"

typedef struct display_client{
	environmental_data_e data;
	callback_fn fn_handler;
}display_client_t;

void display_client_init(display_client_t *const me);
display_client_t * display_client_create(void);
void display_client_handlenewdata(void *client,environmental_data_e data);
void display_client_subscribe(display_client_t *const me,env_sensor_t *const server);
void display_client_unsubscribe(display_client_t *const me,env_sensor_t *const server);
void display_client_destroy(display_client_t *const me);
void logspecifieddata();

#endif /* INC_DISPLAY_CLIENT_H_ */
