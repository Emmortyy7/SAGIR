/*

    All printing funcs gathered in one lib.  

*/

#pragma once

/* Included board.h directly instead of just hal libs because i need an acces to huart1 variable. */
#include "board.h"

void __print_Str(const char* str, uint32_t len);
void __print_uint(const uint64_t num);
void __print_int(const int64_t num);
void __putc(const char ch);
void __putuc(const unsigned char ch); // unsigned char.
