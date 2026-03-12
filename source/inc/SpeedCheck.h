/* SpeedCheck.h - Speed check details definition */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history ------------------
02mar26, Updated coding standards
*/

#ifndef __INCSPEED_CHECK_H_ 
#define __INCSPEED_CHECK_H_

/* includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "SpeedCheck.h"
#include "MessageQueue.h"

/* defines */
#define MAX_BREACH_COUNT    (5)

/* function declarations */
void* SpeedCheckThread(void* arg);
bool SpeedCheckMessageQueueCreate();
bool SpeedCheckMessageQueueSend(uint32_t *pucMsgQSpeedData, size_t lMsgQSize);
bool SpeedCheckMessageQueueReceive(uint32_t *pucMsgQSpeedData, size_t lMsgQSize);
bool SpeedCheckForThresholds(uint32_t *pucMsgQSpeedData, 
                            uint8_t *psucThresholdBreachCount);
#endif //__INCSPEED_CHECK_H_
//EOF