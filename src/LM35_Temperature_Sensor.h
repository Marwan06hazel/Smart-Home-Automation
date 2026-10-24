/*
 * LM35_Temperature_Sensor.h
 *
 *  Created on: Oct 24, 2026
 *
 */

#ifndef LM35_TEMPERATURE_SENSOR_H_
#define LM35_TEMPERATURE_SENSOR_H_

#include "std_types.h"

#define LDR_LM35_CHANNEL_ID	1

void LM35_init(void);
uint8 LM35_getTemperature(void);

#endif /* LM35_TEMPERATURE_SENSOR_H_ */
