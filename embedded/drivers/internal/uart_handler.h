/*

Handling all the uart things in here.

*/
#pragma once 

#include "board.h"

/* UART for transmitting debug output.  */
extern UART_HandleTypeDef huart1;
void MX_USART1_UART_Init(void);
