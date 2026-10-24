/******************************************************************************
 *
 * File Name: ADC.h
 *
 * Description: Commonly used bit-manipulation macros for 8-bit registers
 *
 * Author: Marwan Alaa
 *
 * Created on: Oct 10, 2026
 *
 *******************************************************************************/
#include <avr/interrupt.h> /* For ADC ISR */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

volatile uint16 g_adcResult = 0;

void ADC_init(void){
	ADMUX = 0;
#if(ADC_MODE == POLLING)
	ADCSRA = ADC_ENABLE | ADC_128_PRESCALER;
#elif(ADC_MODE == INTERRUPT)
	ADCSRA = ADC_ENABLE | ADC_INTERRUPT_ENABLE | ADC_128_PRESCALER;
#endif
}

#if(ADC_MODE == INTERRUPT)
ISR(ADC_vect){
	g_adcResult = ADC;
}
#endif

#if(ADC_MODE == POLLING)
uint16 ADC_readChannel(uint8 channel_num){
	channel_num = 0x07; 	/* To know which pin to read 0 --> 7 MUX0..4 */
	ADMUX &= 0xE0;			/* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX |= channel_num;	/* Choose the correct channel by setting the channel number in MUX4:0 bits */
	while(!ADC_INTERRUPT_FLAG);
	ADCSRA |= ADC_INTERRUPT_FLAG;
	return ADC;
}

#elif(ADC_MODE == INTERRUPT)
uint16 ADC_readChannel(uint8 channel_num){
	channel_num = 0x07; 	/* To know which pin to read 0 --> 7 MUX0..4 */
	ADMUX &= 0xE0;			/* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX |= channel_num;	/* Choose the correct channel by setting the channel number in MUX4:0 bits */
	ADCSRA |= ADC_START_CONVERSION;
}
#endif
