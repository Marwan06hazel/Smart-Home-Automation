/*
 * PWM.c
 *
 *  Created on: Oct 20, 2026
 *
 */
#include <avr/io.h>
#include "PWM.h"
#include "common_macros.h"

static PWM_Config g_cfg[4];
static Timer_ID_Type g_activeTimer = TIMER0;
static uint16 PWM_g_Timer1_TOP = 1;

static uint16 getFreq(Timer_ClockType clk){
	switch(clk){
	case F_CPU_CLOCK: return 1;		break;
	case F_CPU_8:     return 8;		break;
	case F_CPU_64:    return 64;	break;
	case F_CPU_256:   return 256;	break;
	case F_CPU_1024:  return 1024;	break;
	}
}

static uint8 getTimersBits(Timer_ID_Type timer, Timer_ClockType clk){
	if((timer == TIMER0) || (timer == TIMER1)){
		switch(clk){
		case F_CPU_32: 		return F_CPU_CLOCK; break;
		case F_CPU_128: 	return F_CPU_CLOCK; break;
		}
	}else{
		switch(clk){
		case NO_CLOCK: 		return 0; break;
		case F_CPU_CLOCK: 	return 1; break;
		case F_CPU_8:     	return 2; break;
		case F_CPU_32:		return 3; break;
		case F_CPU_64:    	return 4; break;
		case F_CPU_128: 	return 5; break;
		case F_CPU_256:   	return 6; break;
		case F_CPU_1024:  	return 7; break;
		}
	}

	return (uint8) clk;
}

void PWM_init(const PWM_Config *cfg){
	if(cfg==NULL) return;

	g_cfg[cfg->timerType] = *cfg;
	g_activeTimer = cfg->timerType;

	switch(g_activeTimer){
	case TIMER0:
		SET_BIT(PWM_TIMER0_PORT_ID, PWM_TIMER0_PIN_ID);
		CLEAR_ALL_REGISTER(TCCR0);
		SET_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);

		if(cfg->Polarity == PWM_NON_INVERTING){
			SET_BIT(TCCR0, COM01);
			CLEAR_BIT(TCCR0, COM00);
		}else{
			SET_BIT(TCCR0, COM00);
			SET_BIT(TCCR0, COM01);
		}

		CLEAR_ALL_REGISTER(OCR0);
		CLEAR_ALL_REGISTER(TCNT0);

		TCCR0 |= getTimersBits(cfg->timerType, cfg->ClockType);
		break;

	case TIMER1:
		PWM_g_Timer1_TOP = (F_CPU / ((uint32)cfg->Timer1Freq * getFreq(cfg->ClockType))) - 1;

		SET_BIT(PWM_TIMER1_PORT_ID, PWM_TIMER1_PIN_ID);
		CLEAR_ALL_REGISTER(TCCR1A);
		CLEAR_ALL_REGISTER(TCCR1B);
		SET_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1B, WGM13);

		if(cfg->Polarity == PWM_NON_INVERTING){
			CLEAR_BIT(TCCR1A, COM1A0);
			SET_BIT(TCCR1A, COM1A1);
		}else{
			SET_BIT(TCCR1A, COM1A0);
			SET_BIT(TCCR1A, COM1A1);
		}

		ICR1 = PWM_g_Timer1_TOP;
		CLEAR_ALL_REGISTER(OCR1A);
		CLEAR_ALL_REGISTER(TCNT1);

		TCCR1B |= getTimersBits(cfg->timerType, cfg->ClockType);
		break;

	case TIMER2:
		SET_BIT(PWM_TIMER2_PORT_ID, PWM_TIMER2_PIN_ID);
		CLEAR_ALL_REGISTER(TCCR2);
		SET_BIT(TCCR2, WGM20);
		SET_BIT(TCCR2, WGM21);

		if(cfg->Polarity == PWM_NON_INVERTING){
			SET_BIT(TCCR2, COM21);
			CLEAR_BIT(TCCR2, COM20);
		}else{
			SET_BIT(TCCR2, COM20);
			SET_BIT(TCCR2, COM21);
		}

		CLEAR_ALL_REGISTER(OCR2);
		CLEAR_ALL_REGISTER(TCNT2);

		TCCR2 |= getTimersBits(cfg->timerType, cfg->ClockType);
		break;
	}
}

void PWM_Start(uint8 duty_cycle){
	if(duty_cycle > 100) duty_cycle = 100;

	switch(g_activeTimer){
	case TIMER0:
		OCR0 = (uint8)((uint16)(duty_cycle*255) / 100);
		break;

	case TIMER1:
		OCR1A = (uint16)(((uint32)duty_cycle * PWM_g_Timer1_TOP) / 100);
		break;

	case TIMER2:
		OCR2 = (uint8)((uint16)(duty_cycle*255) / 100);
		break;
	}
}

void PWM_deinit(const PWM_Config *cfg){
	if(cfg==NULL) return;

	switch(cfg->timerType){
	case TIMER0:
		CLEAR_ALL_REGISTER(TCCR0);
		CLEAR_ALL_REGISTER(OCR0);
		CLEAR_ALL_REGISTER(TCNT0);
		CLEAR_BIT(PWM_TIMER0_PORT_ID, PWM_TIMER0_PIN_ID);
		break;

	case TIMER1:
		CLEAR_ALL_REGISTER(TCCR1A);
		CLEAR_ALL_REGISTER(TCCR1B);
		ICR1  = 0;
		OCR1A = 0;
		TCNT1 = 0;
		CLEAR_BIT(PWM_TIMER1_PORT_ID, PWM_TIMER1_PIN_ID);
		break;

	case TIMER2:
		CLEAR_ALL_REGISTER(TCCR2);
		CLEAR_ALL_REGISTER(OCR2);
		CLEAR_ALL_REGISTER(TCNT2);
		CLEAR_BIT(PWM_TIMER2_PORT_ID, PWM_TIMER2_PIN_ID);
		break;
	}
}
