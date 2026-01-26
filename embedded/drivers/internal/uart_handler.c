#include "uart_handler.h"

/* Handles.  */
UART_HandleTypeDef huart1;

/* 

Using UART1 for debugging purposes.
Setting up UART for debugging like arduino serial port. 

*/
void MX_USART1_UART_Init(void) {    

    #ifdef DEBUG_MODE
    __HAL_RCC_USART1_CLK_ENABLE();

    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX; // sadece gönderme
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    HAL_UART_Init(&huart1);
    #endif
    
}
