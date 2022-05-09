/*
 * UART.c
 *
 *  Created on: May 9, 2022
 *      Author: wardo
 */
#include "fsl_uart.h"
#include "board.h"
#include "UART.h"
#include "pin_mux.h"


static uint8_t data;//[6];
static uint8_t volatile flag;

void DEMO_UART_IRQHandler(void) // ISR UART
{
    /* If new data arrived. */
    if ((kUART_RxDataRegFullFlag | kUART_RxOverrunFlag) & UART_GetStatusFlags(DEMO_UART))
    {
        data = UART_ReadByte(DEMO_UART);
        flag = true;
    }
    SDK_ISR_EXIT_BARRIER;
}

uint8_t UART_intr_get_status(void){
	return(flag);
}
void UART_intr_reset_status(void){
	flag = false;
}
uint8_t UART_Get_Data(void){
	return(data);
}

void UART_mensaje_error_caracteres(void){
	uint8_t g_error_num[] = "\r\nERROR: Solo puedes ingresar numeros!! \r\n vuelve a intentarlo:\r\n";
	UART_WriteBlocking(UART0, g_error_num, TAM_MSG_ERROR_NUM);
}
void UART_mensaje_error_numerico(void){
	uint8_t g_error_msg[] = "\r\nERROR: Solo puedes ingresar un valor entero y tres decimales!! \r\n vuelve a intentarlo:\r\n";
	UART_WriteBlocking(UART0, g_error_msg, TAM_MSG_ERROR_MSG);
}
void UART_mensaje_welcome(void){
	uint8_t g_welcome[] = "\r\nIntroducir voltaje de 0 a 3.3v expresado con 3 decimales:\r\n";
	UART_WriteBlocking(DEMO_UART, g_welcome,TAM_MSG_WELCOME);
}

void UART_mensaje_completaod(void){
	uint8_t g_succeess[]  = "\r\nCorrecto, enviando a DAC...\r\n";
	UART_WriteBlocking(UART0, g_succeess, TAM_MSG_SUCEESS);
}
void UART_mensaje_espejo(void){
	UART_WriteByte(UART0, UART_Get_Data());
}

void UART_Init_user(void){


    BOARD_InitBootPins();
    BOARD_InitBootClocks();


	uart_config_t config;

    UART_GetDefaultConfig(&config);
    config.baudRate_Bps = BOARD_DEBUG_UART_BAUDRATE;
    config.enableTx     = true;
    config.enableRx     = true;

    UART_Init(DEMO_UART, &config, DEMO_UART_CLK_FREQ);
    /* Enable RX interrupt. */
    UART_EnableInterrupts(DEMO_UART, kUART_RxDataRegFullInterruptEnable | kUART_RxOverrunInterruptEnable);
    EnableIRQ(DEMO_UART_IRQn);
}
