/*
 * DAC.h
 *
 *  Created on: May 9, 2022
 *      Author: wardo
 */

#ifndef DAC_H_
#define DAC_H_

#define DAC_BASEADDR    	  DAC0     //DAC a utilizar

void DAC_Init_user(void);
void DAC_Write_user(float valor);

#endif /* DAC_H_ */
