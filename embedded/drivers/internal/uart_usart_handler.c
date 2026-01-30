#include "uart_usart_handler.h"

/* Handles.  */
#ifdef DEBUG_MODE
UART_HandleTypeDef huart2;
#endif

/* 

Using UART1 for debugging purposes.
Setting up UART for debugging like arduino serial port. 

*/
void MX_USART2_UART_Init(void) {
    #ifdef DEBUG_MODE 
    __HAL_RCC_USART2_CLK_ENABLE();

    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    #endif
}
