#include "__printf.h"

UART_HandleTypeDef huart2;

void __print_Str(UART_HandleTypeDef *huartx, const char* str, uint32_t len) {
    #ifdef DEBUG_MODE 
    HAL_UART_Transmit(huartx, (uint8_t*)str, len, HAL_MAX_DELAY);
    #endif
}

void __print_uint(UART_HandleTypeDef *huartx, const uint64_t num) {
    #ifdef DEBUG_MODE
    uint8_t buf[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    
    buf[0] = (uint8_t)((num >> 0)  & 0xFF);
    buf[1] = (uint8_t)((num >> 8)  & 0xFF);
    buf[2] = (uint8_t)((num >> 16) & 0xFF);
    buf[3] = (uint8_t)((num >> 24) & 0xFF);
    buf[4] = (uint8_t)((num >> 32) & 0xFF);
    buf[5] = (uint8_t)((num >> 40) & 0xFF);
    buf[6] = (uint8_t)((num >> 48) & 0xFF);
    buf[7] = (uint8_t)((num >> 56) & 0xFF);
    
    HAL_UART_Transmit(huartx, buf, sizeof(buf), HAL_MAX_DELAY);
    #endif
}

/* This will probably wont work because function takes uint8_t buf as parameter but i dont usually use int's so it doesnt matter. */
void __print_int(UART_HandleTypeDef *huartx, const int64_t num) {
    #ifdef DEBUG_MODE
    int8_t buf[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    
    buf[0] = (int8_t)((num >> 0)  & 0xFF);
    buf[1] = (int8_t)((num >> 8)  & 0xFF);
    buf[2] = (int8_t)((num >> 16) & 0xFF);
    buf[3] = (int8_t)((num >> 24) & 0xFF);
    buf[4] = (int8_t)((num >> 32) & 0xFF);
    buf[5] = (int8_t)((num >> 40) & 0xFF);
    buf[6] = (int8_t)((num >> 48) & 0xFF);
    buf[7] = (int8_t)((num >> 56) & 0xFF);
    
    HAL_UART_Transmit(huartx, buf, sizeof(buf), HAL_MAX_DELAY);
    #endif
}
void __putc(UART_HandleTypeDef *huartx, const char ch) {
    #ifdef DEBUG_MODE
    HAL_UART_Transmit(huartx, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
    #endif
}

void __putuc(UART_HandleTypeDef *huartx, const unsigned char ch) {
    #ifdef DEBUG_MODE
    HAL_UART_Transmit(huartx, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
    #endif
}
