/*
 * LM35_Temperature_Sensor.c
 *
 *  Created on: Oct 24, 2026
 *
 */

#include "LM35_Temperature_Sensor.h"
#include "ADC.h"

void LM35_init(void){
	ADC_init();
}

uint8 LM35_getTemperature(void){
	uint16 adc_value  = ADC_readChannel(LDR_LM35_CHANNEL_ID);
	uint8 adc_voltage =	(uint8)((uint16)(adc_value*ADC_REF_VOLT_VALUE) / ADC_MAXIMUM_VALUE);
	return adc_voltage*100;
}
