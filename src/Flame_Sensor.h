/*
 * Flame_Sensor.h
 *
 *  Created on: Oct 24, 2026
 *
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "std_types.h"
#include "GPIO.h"

#define FLAME_SENSOR_PORT_ID 				PORTD_ID
#define FLAME_SENSOR_PIN_ID 				PIN3_ID

void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);
void FlameSensor_deinit(void);

#endif /* FLAME_SENSOR_H_ */
