/* SpeedRead.h - Speed Read details definition */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history ------------------
02mar26, Updated coding standards
*/

#ifndef __INCSPEED_READ_H_ 
#define __INCSPEED_READ_H_

/* includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

/* function declarations */
void* SpeedReadThread(void* arg);
bool ReadSpeed(uint32_t *pucSpeedValue);
#endif //__INCSPEED_READ_H_
//EOF