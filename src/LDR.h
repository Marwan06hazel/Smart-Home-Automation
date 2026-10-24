/*
 * LDR.h
 *
 *  Created on: Oct 20, 2026
 *
 */

#ifndef LDR_H_
#define LDR_H_

#include "std_types.h"

#define LDR_SENSOR_CHANNEL_ID 				0
#define LDR_SENSOR_MAX_VOLT_VALUE 			2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY 		100
#define LDR_SENSOR_Least_LIGHT_INTENSITY 	0

void LDR_init(void);
uint8 LDR_getLightIntensity(void);

#endif /* LDR_H_ */
