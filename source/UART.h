/*
 * UART.h
 *
 *  Created on: May 9, 2022
 *      Author: wardo
 */

#ifndef UART_H_
#define UART_H_

#define DEMO_UART                 UART0
#define DEMO_UART_CLKSRC          UART0_CLK_SRC
#define DEMO_UART_CLK_FREQ        CLOCK_GetFreq(UART0_CLK_SRC)
#define DEMO_UART_IRQn            UART0_RX_TX_IRQn
#define DEMO_UART_IRQHandler      UART0_RX_TX_IRQHandler
#define TAM_MSG_SUCEESS      (33u)     //Tamanos de los mensajes STRING
#define TAM_MSG_ERROR_NUM    (66u)
#define TAM_MSG_WELCOME      (62u)
#define TAM_MSG_ERROR_MSG    (91u)

static uint16_t volatile txIndex; /* Index of the data to send out. */
static uint16_t volatile rxIndex; /* Index of the memory to save new arrived data. */

void UART_Init_user(void);
uint8_t UART_intr_get_status(void);
void UART_intr_reset_status(void);
uint8_t UART_Get_Data(void);

void UART_mensaje_welcome(void);
void UART_mensaje_error_caracteres(void);
void UART_mensaje_error_numerico(void);
void UART_mensaje_completaod(void);
void UART_mensaje_espejo(void);

#endif /* UART_H_ */
