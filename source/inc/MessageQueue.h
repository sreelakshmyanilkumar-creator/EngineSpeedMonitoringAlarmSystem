/* MessageQueue.h - Message queue details definition */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history ------------------
02mar26, Updated coding standards
*/

#ifndef __INCMESSAGE_QUEUE_H_ 
#define __INCMESSAGE_QUEUE_H_

/* includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* global */
#define PERMISSION_MASK         (0666)
#define MSG_QUEUE_MAX_MESSAGES  (10)
#define MSG_QUEUE_MAX_MSG_SIZE  (sizeof(uint32_t))
#define QUEUE_NAME              "/speedqueue"
#define MQ_ERROR            (-1)

/* function declarations */
bool MessageQueueCreate();
bool MessageQueueSend(uint32_t *pucMessageQueueData, size_t lMsgQSize);
bool MessageQueueReceive(uint32_t *pucMessageQueueData, size_t lMsgQSize);
#endif //__INCMESSAGE_QUEUE_H_
//EOF