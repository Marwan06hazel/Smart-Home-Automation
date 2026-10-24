/*
 * LDR.c
 *
 *  Created on: Oct 20, 2026
 *
 */
#include "LDR.h"
#include "ADC.h"

void LDR_init(void){
	ADC_init();
}

uint8 LDR_getLightIntensity(void){
    uint16 adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

    uint8 adc_voltage_percentage = (uint8)(((uint32)adc_value * 100) / ADC_MAXIMUM_VALUE);

    return (100 - adc_voltage_percentage);
}

