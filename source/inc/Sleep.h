/* Sleep.h - Sleep definition */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history ------------------
02mar26, Updated coding standards
*/

#ifndef __INCSLEEP_H_ 
#define __INCSLEEP_H_

/* includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* defines */
#define MILLISECONDS    (1000)

/* function declarations */
bool msleep(uint32_t ucTimeInMilliSeconds);
#endif //__INCSLEEP_H_ 
//EOF