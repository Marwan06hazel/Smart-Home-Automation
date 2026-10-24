/*
- Buzzer.h
 *
- Created on:
Oct 20, 2026
 *
 */

#ifndef BUZZER_H_
#define BUZZER_H_

/* Include the underlying GPIO driver dependency */
#include "GPIO.h"

/* Define the hardware port and pin mapping for the buzzer connection on the microcontroller */
#define BUZZER_PORT_ID	PORTD_ID
#define BUZZER_PIN_ID	PIN3_ID

/* Enum defining the transistor type used in the buzzer driver circuit */
typedef enum{
	BUZZER_NPN, /* NPN transistor configuration */
	BUZZER_PNP  /* PNP transistor configuration */
}Buzzer_Transistor;

/* Configuration structure containing parameters needed to initialize the buzzer */
typedef struct{
	Buzzer_Transistor type; /* Stores the selected transistor configuration type */
}Buzzer_Config;

/* Static internal function declaration to turn the buzzer on */
static uint8 BuzzerOn(const Buzzer_Config* cfg);

/* Static internal function declaration to turn the buzzer off */
static uint8 BuzzerOff(const Buzzer_Config* cfg);

/* Public function declaration to initialize the buzzer peripheral */
void Buzzer_init(const Buzzer_Config *cfg);

/* Public function declaration to turn the buzzer on */
void Buzzer_on(const Buzzer_Config *cfg);

/* Public function declaration to turn the buzzer off */
void Buzzer_off(const Buzzer_Config *cfg);

/* Public function declaration to deinitialize the buzzer peripheral */
void Buzzer_deinit(const Buzzer_Config *cfg);

#endif /* BUZZER_H_ */
