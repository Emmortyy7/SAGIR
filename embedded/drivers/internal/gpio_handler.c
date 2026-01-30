#include "gpio_handler.h"

/* 

All GPIO settings will be done in here. 

*/
void MX_GPIO_Init(void) {
    
    usart2_init();
    sx126x_gpio_init();
    
}

void usart2_init(void) {
    
    /* DEBUG USART2 */
    #ifdef DEBUG_MODE
    GPIO_InitTypeDef GPIO_InitStruct = {0};    
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /* PA2 -> USART2_TX
       PA3 -> USART2_RX (not used) */
    GPIO_InitStruct.Pin = USART_CMD_PIN__USART2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;

    HAL_GPIO_Init(USART_CMD_PIN_GROUP__USART2, &GPIO_InitStruct);
    #endif

}

void sx126x_gpio_init(void) {
    
    /* LORA SX126X */
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /* SCK, MISO, MOSI */
    GPIO_InitStruct.Pin =
        SX126X_SPI_SCK_PIN__SPI1  |
        SX126X_SPI_MISO_PIN__SPI1 |
        SX126X_SPI_MOSI_PIN__SPI1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(SX126X_SPI_SCK_PIN_GROUP__SPI1, &GPIO_InitStruct);

    /* NSS */
    GPIO_InitStruct.Pin = SX126X_NSS_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(SX126X_NSS_PIN_GROUP, &GPIO_InitStruct);
    HAL_GPIO_WritePin(SX126X_NSS_PIN_GROUP, SX126X_NSS_PIN, GPIO_PIN_SET);

    /* BUSY */
    GPIO_InitStruct.Pin = SX126X_BUSY_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(SX126X_BUSY_PIN_GROUP, &GPIO_InitStruct);

    /* RESET */
    GPIO_InitStruct.Pin = SX126X_RESET_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(SX126X_RESET_PIN_GROUP, &GPIO_InitStruct);
    HAL_GPIO_WritePin(SX126X_RESET_PIN_GROUP, SX126X_RESET_PIN, GPIO_PIN_SET);

    /* DIO1 (IRQ) */
    GPIO_InitStruct.Pin = SX126X_DIO1_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(SX126X_DIO1_PIN_GROUP, &GPIO_InitStruct);

    /* EXTI interrupt enable */
    HAL_NVIC_SetPriority(EXTI9_5_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}
