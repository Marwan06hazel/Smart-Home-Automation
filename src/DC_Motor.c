/*
 *  DC_Motor.c
 *
 *  Created on: Oct 24, 2026
 *
 */

#include "DC_Motor.h"

void DcMotor_init(void){
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_INPUT1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_INPUT2_PIN_ID, PIN_OUTPUT);

	GPIO_setupPinDirection(DC_MOTOR_EN_PORT_ID, DC_MOTOR_EN_PIN, PIN_OUTPUT);

	PWM_Config dc_motor_pwm_config = {
		.timerType  = DC_MOTOR_DEFAULT_TIMER,
		.ClockType  = DC_MOTOR_DEFAULT_CLOCK,
		.Polarity   = DC_MOTOR_DEFAULT_POLARITY
	};

	DcMotor_Rotate(DC_MOTOR_STOP, 0, dc_motor_pwm_config);
}

void DcMotor_Rotate(DCMotor_State state, uint8 speed, PWM_Config DcMotor_PWM_config){
	switch(state){
	case DC_MOTOR_STOP:
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_INPUT1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_INPUT2_PIN_ID, LOGIC_LOW);
		break;

	case DC_MOTOR_CW:
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_INPUT1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_INPUT2_PIN_ID, LOGIC_LOW);
		break;
	case DC_MOTOR_A_CW:
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_INPUT1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_INPUT2_PIN_ID, LOGIC_HIGH);
		break;
	}

	PWM_init(&DcMotor_PWM_config);
	PWM_Start(speed);
}
