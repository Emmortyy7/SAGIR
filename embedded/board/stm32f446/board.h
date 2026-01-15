/*

   All includes and some settings gathered in one file for app/main.c so it's gonna be easier for writing main logic.     

*/


#pragma once

#include "config.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"
#include "stm32f446xx.h"
#include "stm32f4xx.h"
#include "__printf.h"

extern UART_HandleTypeDef huart1;

void SystemClock_Config(void);
void Error_Handler(void);
void MX_USART1_UART_Init(void);
void MX_GPIO_Init(void);
void board_init();
