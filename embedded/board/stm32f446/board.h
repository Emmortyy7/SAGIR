/*

   All includes and some settings gathered in one file for app/main.c so it's gonna be easier for writing main logic.     

*/


#pragma once

/* Critical files -> needs to be included first. */
#include "config.h"

/* Hal libs. */
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"
#include "stm32f446xx.h"
#include "stm32f4xx.h"

/* include/ */
#include "__printf.h"

/* drivers/ */
#include "internal/adc_handler.h"
#include "internal/gpio_handler.h"
#include "internal/uart_handler.h"
#include "internal/system_clock_handler.h"

void board_init(void);
