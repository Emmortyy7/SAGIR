/*

   All includes and some settings gathered in one file for app/main.c so it's gonna be easier for writing main logic.     

*/


#pragma once

#include "stm32f446xx.h"

void SystemClock_Config(void);
void Error_Handler(void);
void board_init(void);
void set_GPIO(void);
