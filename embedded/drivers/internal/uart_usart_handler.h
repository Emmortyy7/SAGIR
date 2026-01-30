/*

Handling all the uart things in here.

*/
#pragma once 

#include "board.h"

extern UART_HandleTypeDef huart2;

/* USART for transmitting debug output.  */
void MX_USART2_UART_Init(void);
