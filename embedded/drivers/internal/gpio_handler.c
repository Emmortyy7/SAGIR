#include "gpio_handler.h"

/* 

All GPIO settings will be done in here. 

*/
void MX_GPIO_Init(void) {

    #ifdef DEBUG_MODE
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /* UART1 for debugging. */
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = UART_CMD_PIN__UART1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;      
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(UART_CMD_PIN_GROUP__UART1, &GPIO_InitStruct);
    #endif
    
}
