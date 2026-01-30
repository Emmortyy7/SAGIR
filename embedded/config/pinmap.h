/*

Defining pins that will be used in this project.

*/

#pragma once

/* Serial Port pin.  */
#define USART_CMD_PIN__USART2       GPIO_PIN_2
#define USART_CMD_PIN_GROUP__USART2 GPIOA

/* Using ADC1 for our audio.  */
#define ADC_PIN__ADC1       GPIO_PIN_0
#define ADC_PIN_GROUP__ADC1 GPIOA
#define ADC_CHANNEL__ADC1   ADC_CHANNEL_0

/* sx126x LoRa pins. SPI1 */
#define SX126X_SPI_SCK_PIN__SPI1        GPIO_PIN_5
#define SX126X_SPI_SCK_PIN_GROUP__SPI1  GPIOA
#define SX126X_SPI_MISO_PIN__SPI1       GPIO_PIN_6
#define SX126X_SPI_MISO_PIN_GROUP__SPI1 GPIOA
#define SX126X_SPI_MOSI_PIN__SPI1       GPIO_PIN_7
#define SX126X_SPI_MOSI_PIN_GROUP__SPI1 GPIOA
#define SX126X_NSS_PIN                  GPIO_PIN_4
#define SX126X_NSS_PIN_GROUP            GPIOA
#define SX126X_BUSY_PIN                 GPIO_PIN_1
#define SX126X_BUSY_PIN_GROUP           GPIOA
#define SX126X_RESET_PIN                GPIO_PIN_3
#define SX126X_RESET_PIN_GROUP          GPIOA
#define SX126X_DIO1_PIN                 GPIO_PIN_8
#define SX126X_DIO1_PIN_GROUP           GPIOA
