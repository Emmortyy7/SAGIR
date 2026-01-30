#include "sx126x_spi_handler.h"

SPI_HandleTypeDef hspi1;

void MX_SPI1_Init(void) {
    __HAL_RCC_SPI1_CLK_ENABLE();
    
    hspi1.Instance = SPI1;
    hspi1.Init.Mode = SPI_MODE_MASTER;
    hspi1.Init.Direction = SPI_DIRECTION_2LINES;
    hspi1.Init.DataSize = SPI_DATASIZE_8BIT;

    /* SX126x SPI Mode 0 */
    hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
    hspi1.Init.CLKPhase    = SPI_PHASE_1EDGE;

    /* NSS software (CS GPIO ile yönetilecek) */
    hspi1.Init.NSS = SPI_NSS_SOFT;

    /* APB2 = 84 MHz, 10.5 MHz CHANGE LATER !!! */
    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;

    hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
    hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi1.Init.CRCPolynomial = 7;
}
