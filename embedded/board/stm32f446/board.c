/*

Preparing hardwares for running our program.

*/


#include "board.h"

/* 

Setting up the mcu for the things we gonna do.
This function is for setting up the mcu and its peripherals. 

*/
void board_init(void) {
    
    /* Init things. */
    HAL_Init();    
}
