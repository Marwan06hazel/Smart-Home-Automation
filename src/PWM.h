/*
 * PWM.h
 *
 * Created on: Oct 20, 2026
 *
 */

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

#define F_CPU					16000000UL

#define PWM_TIMER0_PORT_ID		DDRB		/* OC0  (PB3) */
#define PWM_TIMER0_PIN_ID		3

#define PWM_TIMER1_PORT_ID		DDRD		/* OC1A (PD5) */
#define PWM_TIMER1_PIN_ID		5

#define PWM_TIMER2_PORT_ID		DDRD		/* OC2  (PD7) */
#define PWM_TIMER2_PIN_ID		7

typedef enum{
	TIMER0, TIMER1, TIMER2
}Timer_ID_Type;

typedef enum{
	NO_CLOCK,
	F_CPU_CLOCK,
	F_CPU_8,
	F_CPU_64,
	F_CPU_256,
	F_CPU_1024,
	F_CPU_32,
	F_CPU_128
}Timer_ClockType;

typedef enum{
	PWM_NON_INVERTING,
	PWM_INVERTING
}PWM_Polarity;

typedef struct{
	Timer_ID_Type 	timerType;
	Timer_ClockType ClockType;
	PWM_Polarity 	Polarity;
	uint16			Timer1Freq;
}PWM_Config;

static uint16 getFreq(Timer_ClockType clk);
static uint8 getTimersBits(Timer_ID_Type timer, Timer_ClockType clk);

void PWM_init(const PWM_Config *cfg);
void PWM_Start(uint8 duty_cycle);
void PWM_deinit(const PWM_Config *cfg);

#endif /* PWM_H_ */
