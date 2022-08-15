/*
 * environmental_data.h
 *
 *  Created on: Aug 6, 2022
 *      Author: ibrhm
 */

#ifndef INC_ENVIRONMENTAL_DATA_H_
#define INC_ENVIRONMENTAL_DATA_H_
#include <stdint.h>
#include <stdbool.h>
typedef struct environmental_data{
	uint32_t temperature;
	uint32_t humudity;
	bool sprayed;
}environmental_data_e;










#endif /* INC_ENVIRONMENTAL_DATA_H_ */
