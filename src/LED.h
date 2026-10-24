/*
 * LED.h
 *
 *  Created on: Oct 20, 2026
 *
 */

#ifndef LED_H_
#define LED_H_

#include "GPIO.h"
#include "std_types.h"

#define NUMBER_OF_LEDs  3
#define LED_PORT_ID		PORTB_ID
#define LED_PIN_ID		PIN5_ID

typedef enum{
	Negative_Logic,
	Postivie_Logic
}LED_connections;

typedef enum{
	RED,
	GREEN,
	BLUE
}LED_ID;

typedef struct{
	LED_connections type;
}LED_Config;

static uint8 LED_on_config(const LED_Config* cfg);
static uint8 LED_off_config(const LED_Config* cfg);

void LEDS_init(const LED_Config* cfg);
void LED_on(const LED_Config* cfg, LED_ID id);
void LED_off(const LED_Config* cfg, LED_ID id);
void LEDS_deinit(const LED_Config* cfg);

#endif /* LED_H_ */
