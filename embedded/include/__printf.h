/*

    All printing funcs gathered in one lib.  

*/

#pragma once

/* Included board.h directly instead of just hal libs because i need an acces to huart1 variable. */
#include "board.h"

void __print_Str(UART_HandleTypeDef *huartx, const char* str, uint32_t len);
void __print_uint(UART_HandleTypeDef *huartx, const uint64_t num);
void __print_int(UART_HandleTypeDef *huartx, const int64_t num);
void __putc(UART_HandleTypeDef *huartx, const char ch);
void __putuc(UART_HandleTypeDef *huartx, const unsigned char ch); // unsigned char.
