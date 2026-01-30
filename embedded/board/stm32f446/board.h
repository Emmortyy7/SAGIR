/*

   All includes and some settings gathered in one file for app/main.c so it's gonna be easier for writing main logic.     

*/


#pragma once

/* Critical files and configs-> needs to be included first. */
#include "config.h"

/* Hal libs. */
#include "stm32f4xx_hal.h"
#include "stm32f446xx.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_tim.h"
#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_adc.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_hal_uart.h"
#include "stm32f4xx_hal_usart.h"

/* include/ */
#include "__printf.h"

/* drivers/ */
#include "internal/hydrophone_input_stream_handler__adc1_dma2_tim2.h"
#include "internal/gpio_handler.h"
#include "internal/uart_usart_handler.h"
#include "internal/system_clock_handler.h"
#include "internal/sx126x_spi_handler.h"
#include "external/sx126x_semtech_driver/sx126x.h"
#include "external/sx126x_semtech_driver/sx126x_regs.h"
#include "external/sx126x_semtech_driver/sx126x_hal.h"
#include "external/sx126x_semtech_driver/sx126x_status.h"
#include "external/sx126x_semtech_driver/sx126x_driver_version.h"

void board_init(void);
