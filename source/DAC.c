/*
 * DAC.c
 *
 *  Created on: May 9, 2022
 *      Author: wardo
 */
#include "DAC.h"
#include "fsl_dac.h"

void DAC_Write_user(float valor){
	DAC_SetBufferValue(DAC_BASEADDR, 0U, valor); // dacValue solo puede tomar valores de entre 0 y 4095 (uint16_t)
}
void DAC_Init_user(void){
	dac_config_t dacConfigStruct;
    DAC_GetDefaultConfig(&dacConfigStruct);
	DAC_Init(DAC_BASEADDR, &dacConfigStruct);
    DAC_Enable(DAC_BASEADDR, true);
    DAC_SetBufferReadPointer(DAC_BASEADDR, 0U);
}
