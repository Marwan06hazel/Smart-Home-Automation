/*
 * Flame_Sensor.c
 *
 *  Created on: Oct 24, 2026
 *
 */

#include "Flame_Sensor.h"
#include "GPIO.h"

void FlameSensor_init(void){
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, PIN_INPUT);
}
uint8 FlameSensor_getValue(void){
	GPIO_readPin(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID);
}
void FlameSensor_deinit(void){
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, PIN_OUTPUT);
}


