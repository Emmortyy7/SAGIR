#pragma once

/*

    All config libs and extra configs gathered in one lib. 

*/

/* DEBUGGING FLAGS  */
#define DEBUG_MODE

/* BOARD FLAGS */
#define F446_MCU

/* pinmap.h is at the bottom because F446_MCU flag needs to be defined first.  */
#include "pinmap.h"
