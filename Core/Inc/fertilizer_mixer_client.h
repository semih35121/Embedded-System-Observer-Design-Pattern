/*
 * fertilizer_mixer_client.h
 *
 *  Created on: 9 Ağu 2022
 *      Author: ibrhm
 */

#ifndef INC_FERTILIZER_MIXER_CLIENT_H_
#define INC_FERTILIZER_MIXER_CLIENT_H_
#include "env_sensor.h"
#include "environmental_data.h"

typedef struct fertilizer_mixer_client{
	environmental_data_e data;
	callback_fn fn_handler;
}fertilizer_mixer_client_t;

void fertilizer_mixer_client_init(fertilizer_mixer_client_t *const me);
fertilizer_mixer_client_t * fertilizer_mixer_client_create(void);
void fertilizer_mixer_client_handlenewdata(void *client,environmental_data_e data);
void fertilizer_mixer_client_subscribe(fertilizer_mixer_client_t *const me,env_sensor_t *const server);
void fertilizer_mixer_client_unsubscribe(fertilizer_mixer_client_t *const me,env_sensor_t *const server);


#endif /* INC_FERTILIZER_MIXER_CLIENT_H_ */
