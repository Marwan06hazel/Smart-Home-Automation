/******************************************************************************
 *
 * File Name: ADC.h
 *
 * Description: Commonly used bit-manipulation macros for 8-bit registers
 *
 * Author: Marwan Alaa
 *
 * Created on: Oct 7, 2026
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include <avr/io.h>

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

#define ADC_MODE 						POLLING

/* ADMUX REGISTER */
#define AVCC                    		(1 << REFS0)		         /* 0x40 */
#define INTERNAL_2_56_VOLTAGE   		(1 << REFS1) | (1 << REFS0) /* 0xC0 */
#define EXTERNAL_AREF           		0x00

#define RIGHT_ADJUSTED          		0x00
#define LEFT_ADJUSTED           		(1 << ADLAR)          /* 0x20 */

#define ADC0                    		0x00
#define ADC1                    		0x01
#define ADC2                    		0x02
#define ADC3                    		0x03
#define ADC4                    		0x04
#define ADC5                    		0x05
#define ADC6                    		0x06
#define ADC7                    		0x07

/* ADCSRA REGISTER */
#define ADC_ENABLE              		(1 << ADEN)           /* 0x80 */
#define ADC_START_CONVERSION    		(1 << ADSC)           /* 0x40 */
#define ADC_AUTO_TRIGGER_ENABLE 		(1 << ADATE)          /* 0x20 */
#define ADC_INTERRUPT_FLAG      		(1 << ADIF)           /* 0x10 */
#define ADC_INTERRUPT_ENABLE    		(1 << ADIE)           /* 0x08 */

#define ADC_2_PRESCALER_1       		0x01
#define ADC_4_PRESCALER         		0x02
#define ADC_8_PRESCALER         		0x03
#define ADC_16_PRESCALER        		0x04
#define ADC_32_PRESCALER        		0x05
#define ADC_64_PRESCALER        		0x06
#define ADC_128_PRESCALER       		0x07

/* SFIOR REGISTER (Auto Trigger Sources) */
#define FREE_RUNNING_MODE               (0 << ADTS0)
#define ANALOG_COMPARATOR               (1 << ADTS0)
#define EXTERNAL_INTERRUPT_REQUEST_0    (1 << ADTS1)
#define TIMER_COUNTER_0_COMPARE_MATCH   ((1 << ADTS1) | (1 << ADTS0))
#define TIMER_COUNTER_0_OVERFLOW        (1 << ADTS2)
#define TIMER_COUNTER_1_COMPARE_MATCH_B ((1 << ADTS2) | (1 << ADTS0))
#define TIMER_COUNTER_1_OVERFLOW        ((1 << ADTS2) | (1 << ADTS1))
#define TIMER_COUNTER_1_CAPTURE_EVENT   ((1 << ADTS2) | (1 << ADTS1) | (1 << ADTS0))


extern volatile uint16 g_adcResult;

void ADC_init(void);
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
