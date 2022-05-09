

#include "clock_config.h"
#include "DAC.h"
#include "UART.h"


#define TAMANO_DATO_FLOAT    (5u)      //Tamano de elementos ASCII del dato
#define LAST_INF_NUM_ASCCI   (47u)	   //Valor decimal que reprecenta simbolo ASCII antes del 0
#define LAST_SUP_NUM_ASCCI   (57u)	   //Valor decimal que reprecenta simbolo ASCII despues del 9
#define PUNTO_DECIMAL_ASCII  (46u)	   //Simbolo de punto en ASCII valor Decimal
#define TECLA_ENTER_ASCII    (13u)     //Simbolo de retorno de carro en ASCII valor Decimal
#define MAX_RESOLUTION_DAC   (4095u)
#define MAX_VOLTAGE_OP       (3.3)
#define RESET                (0)
#define MAX_ELEMNTOS_UART_RX (5u)
#define FIRST				 (1u)

int main(void)
{

    float valor_flotante = 0;                 //variable flotante para almacenamiento y envio por DAC
	float decimal[TAMANO_DATO_FLOAT];		  //variable arreglo para almacenar conversion de CARACTERES ASCII a DECIMAL
	uint8_t dato_arreglo[TAMANO_DATO_FLOAT];  //variable arreglo para almacenamiento de caracteres ASCII introducidos por usuario
	uint8_t index = 0;
	uint8_t bandera = true;

    UART_Init_user();
    DAC_Init_user();
    UART_mensaje_welcome();

while (1)
    {
	  uint8_t flag = UART_intr_get_status();
      if (flag)
        {
          dato_arreglo[index] = UART_Get_Data();
          if (FIRST == index){
        	  bandera = false; // posicion de punto decimal.
          }
          if (TECLA_ENTER_ASCII != dato_arreglo[index]){ // si no se ha presionado enter
        	  if((true == bandera) && (LAST_INF_NUM_ASCCI < dato_arreglo[index]) && (LAST_SUP_NUM_ASCCI > dato_arreglo[index]))// filtro, que solo se recivan numeros
        	         	  // bandera = pos 0 2 3 4
        	           {
        		  	  	  UART_mensaje_espejo();
						  index++;
        	           }
        	  else if(false == bandera && PUNTO_DECIMAL_ASCII == dato_arreglo[index]){
        		   UART_mensaje_espejo();
                   index++;
                   bandera = true;
        	  }
        	  else if(false == bandera && ((LAST_INF_NUM_ASCCI < dato_arreglo[index]) && (LAST_SUP_NUM_ASCCI > dato_arreglo[index]))){
        		  // error por ingresar un numero en la posicion del punto decimal
        		  UART_mensaje_error_numerico();
        		  index = RESET; // reinicio de index
        		  bandera = true;
        	  }
        	   else{//error solo puedes agregar numeros con un solo entero
        		  UART_mensaje_error_caracteres();
        		  index = RESET; // reinicio de index
        		  bandera = true;
        	  }
          }
          else{ // si se presiona enter, mandamos dato por DAC

        	  for (uint8_t i = 0;i<sizeof(dato_arreglo);i++){
        		  	 decimal[i] = dato_arreglo[i] - 0x30;
        	      }
        	  valor_flotante = (decimal[0])+(decimal[2]/10)+(decimal[3]/100)+(decimal[4]/1000);
        	  index = 0; // reiniciamos index
        	  valor_flotante = valor_flotante*(MAX_RESOLUTION_DAC / MAX_VOLTAGE_OP);
        	  //DAC_SetBufferValue(DAC_BASEADDR, 0U, valor_flotante); // dacValue solo puede tomar valores de entre 0 y 4095 (uint16_t)
        	  DAC_Write_user(valor_flotante);
        	  UART_mensaje_completaod();
        	  UART_mensaje_welcome();
        }
     UART_intr_reset_status();
    }
  if(MAX_ELEMNTOS_UART_RX < index){
	  //error por sobrepasar cantidad de datos
	UART_mensaje_error_numerico();
    index = RESET; // reinicio de index
  }
 }
}


