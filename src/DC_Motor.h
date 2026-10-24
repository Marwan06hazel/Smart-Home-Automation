/*
 * DC_Motor.h
 *
 * Created on: Oct 24, 2026
 *
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
#include "GPIO.h"
#include "PWM.h"

#define DC_MOTOR_DEFAULT_TIMER    	TIMER0
#define DC_MOTOR_DEFAULT_CLOCK    	F_CPU_256
#define DC_MOTOR_DEFAULT_POLARITY 	PWM_NON_INVERTING

#define DC_MOTOR_PORT_ID			PORTB_ID
#define DC_MOTOR_INPUT1_PIN_ID		PIN0_ID
#define DC_MOTOR_INPUT2_PIN_ID		PIN1_ID

#define DC_MOTOR_EN_PORT_ID  		PORTB_ID
#define DC_MOTOR_EN_PIN      		PIN3_ID

typedef enum {
    DC_MOTOR_STOP,
    DC_MOTOR_CW,
    DC_MOTOR_A_CW
} DCMotor_State;

void DcMotor_init(void);
void DcMotor_Rotate(DCMotor_State state, uint8 speed, PWM_Config DcMotor_PWM_config);

#endif /* DC_MOTOR_H_ */
