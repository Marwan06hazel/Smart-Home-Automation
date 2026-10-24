/*
- Buzzer.c
 *
- Created on:
Oct 20, 2026
 *
 */

/* Include the corresponding header file for the buzzer driver */
#include "Buzzer.h"

/* Static helper function to determine the logic level needed to turn the buzzer ON based on transistor type */
static uint8 BuzzerOn(const Buzzer_Config* cfg){
	/* NPN transistor requires LOGIC_HIGH to turn on, while PNP requires LOGIC_LOW */
	return (cfg->type == BUZZER_NPN) ? LOGIC_HIGH : LOGIC_LOW;
}

/* Static helper function to determine the logic level needed to turn the buzzer OFF based on transistor type */
static uint8 BuzzerOff(const Buzzer_Config* cfg){
	/* NPN transistor requires LOGIC_LOW to turn off, while PNP requires LOGIC_HIGH */
	return (cfg->type == BUZZER_NPN) ? LOGIC_LOW : LOGIC_HIGH;
}

/* Initialize the buzzer pin configuration and set its initial state to off */
void Buzzer_init(const Buzzer_Config *cfg){
	/* Guard clause to prevent null pointer dereference */
	if(cfg == 0) return;

	/* Ensure the buzzer starts in the off state before configuring pin direction */
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, BuzzerOff(cfg));

	/* Configure the buzzer pin direction as an output pin */
	GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);
}

/* Turn the buzzer on */
void Buzzer_on(const Buzzer_Config *cfg){
	/* Guard clause to prevent null pointer dereference */
	if(cfg == 0) return;

	/* Write the appropriate active logic level to the buzzer pin */
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, BuzzerOn(cfg));
}

/* Turn the buzzer off */
void Buzzer_off(const Buzzer_Config *cfg){
	/* Guard clause to prevent null pointer dereference */
	if(cfg == 0) return;

	/* Write the appropriate inactive logic level to the buzzer pin */
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, BuzzerOff(cfg));
}

/* Deinitialize the buzzer peripheral to a safe default state */
void Buzzer_deinit(const Buzzer_Config *cfg){
	/* Guard clause to prevent null pointer dereference */
	if(cfg == 0) return;

	/* Turn off the buzzer output before changing pin direction */
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, BuzzerOff(cfg));

	/* Reset the buzzer pin direction back to input to save power/release the pin */
	GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_INPUT);
}
