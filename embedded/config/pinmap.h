#pragma once

#include "board.h"

#ifdef F446_MCU

/* Serial Port pin.  */
#define UART_CMD_PIN__UART1       GPIO_PIN_9
#define UART_CMD_PIN_GROUP__UART1 GPIOA

#define ADC_PIN__ADC1       GPIO_PIN_0
#define ADC_PIN_GROUP__ADC1 GPIOA

#endif
