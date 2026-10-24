/*
 * LED.c
 *
 *  Created on: Oct 20, 2026
 *
 */
#include "LED.h"

static uint8 LED_on_config(const LED_Config* cfg){
	return (cfg->type == Postivie_Logic) ? LOGIC_HIGH : LOGIC_LOW;
}

static uint8 LED_off_config(const LED_Config* cfg){
	return (cfg->type == Postivie_Logic) ? LOGIC_LOW : LOGIC_HIGH;
}

void LEDS_init(const LED_Config* cfg){
	uint8 i;

	for(i = 0; i<NUMBER_OF_LEDs; i++){
		GPIO_setupPinDirection(LED_PORT_ID, LED_PIN_ID+i, PIN_OUTPUT);
		GPIO_writePin(LED_PORT_ID, LED_PIN_ID+i, LED_off_config(cfg));
	}
}

void LED_on(const LED_Config* cfg, LED_ID id){
	switch(id){
	case RED:
		GPIO_writePin(LED_PORT_ID, LED_PIN_ID, LED_on_config(cfg));
		break;
	case GREEN:
		GPIO_writePin(LED_PORT_ID, LED_PIN_ID+1, LED_on_config(cfg));
		break;
	case BLUE:
		GPIO_writePin(LED_PORT_ID, LED_PIN_ID+2, LED_on_config(cfg));
		break;
	}
}

void LED_off(const LED_Config* cfg, LED_ID id){
	switch(id){
	case RED:
		GPIO_writePin(LED_PORT_ID, LED_PIN_ID, LED_off_config(cfg));
		break;
	case GREEN:
		GPIO_writePin(LED_PORT_ID, LED_PIN_ID+1, LED_off_config(cfg));
		break;
	case BLUE:
		GPIO_writePin(LED_PORT_ID, LED_PIN_ID+2, LED_off_config(cfg));
		break;
	}
}

void LEDS_deinit(const LED_Config* cfg){
	uint8 i;

	for(i = 0; i<NUMBER_OF_LEDs; i++){
		GPIO_setupPinDirection(LED_PORT_ID, LED_PIN_ID+i, PIN_INPUT);
		GPIO_writePin(LED_PORT_ID, LED_PIN_ID+i, LED_off_config(cfg));
	}
}
