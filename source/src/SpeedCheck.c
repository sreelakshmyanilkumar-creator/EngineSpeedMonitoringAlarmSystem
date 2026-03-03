/* SpeedCheck.c - Speed check thread function and msg queue wrapper library */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history --------------------
02mar26, Updated coding standards
*/
/*
DESCRIPTION
This module contains the thread function to receive the sensor data from 
SpeedReadThread() and check it with threasholds. 
INCLUDE FILES: SpeedCheck.h, Alarm.h, MessageQueue.h, Sensor.h, Semaphore.h
*/
/* includes */
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include "MessageQueue.h"
#include "SpeedCheck.h"
#include "Sensor.h"
#include "Alarm.h"
#include "Semaphore.h"

/*******************************************************************************
*
* SpeedCheckThread - This thread function continously check for the breach in 
* engine speed threshold against [SPEED_THRESHOLD_MIN] and [SPEED_THRESHOLD_MAX].
* If the breach count goes beyond 5, it will signal alarm semaphore
*
* DESCRIPTION
* This function check for the breach in engine speed threshold against 
* [SPEED_THRESHOLD_MIN] and [SPEED_THRESHOLD_MAX]. If the breach count goes 
* beyond 5, it will signal alarm semaphore
*
* PARAMETERS
* \is
* \i N/A
* \ie
*
* GLOBALS:
* \is
* \i N/A
* \ie
*
* RETURNS:
* \is
* \i 
* \ie
* 
* ERRNO:
* \is
* \i N/A
* \ie
*
* SEE ALSO:
* Alarm.c, Semaphore.c, MessageQueue.c
*
* \INTERNAL
* Thread function to receive the sensor data from SpeedReadThread() and check it
* with threasholds.
*/
void* SpeedCheckThread(void *pArg)
{
    uint16_t ucSpeedValue = 0;
    static uint8_t sucThresholdBreachCount = 0;
    (void)pArg;

    SpeedCheckMessageQueueCreate();

    while(1)
    {
        if(SpeedCheckMessageQueueReceive(&ucSpeedValue, 
                                        MSG_QUEUE_MAX_MSG_SIZE) != false)
        {
            printf("Message Received successfully, Data = %d\n",ucSpeedValue);

            if(SpeedCheckForThresholds(&ucSpeedValue, &sucThresholdBreachCount) 
                                        != false)
            {
                AlarmSemaphorePost();
            }
        }
    }

    return NULL;
}

/*******************************************************************************
*
* SpeedCheckMessageQueueCreate - This function is a wrapper function for 
* MessageQueueCreate()
*
* DESCRIPTION
* This function is a wrapper function for MessageQueueCreate() 
*
* PARAMETERS
* \is
* \i N/A
* \ie
*
* GLOBALS:
* \is
* \i N/A
* \ie
*
* RETURNS:
* \is
* \i <true>
* when the MessageQueue create is success
*
* \i <false>
* when the MessageQueue create fails
* \ie
* 
* ERRNO:
* \is
* \i N/A
* \ie
*
* SEE ALSO:
* MessageQueue.c
*
* \INTERNAL
* This function is a wrapper function for MessageQueueCreate() 
*/
bool SpeedCheckMessageQueueCreate()
{
    bool blRet = false;

    if(MessageQueueCreate() != false)
    {
        blRet = true;
    }

    return blRet;
}

/*******************************************************************************
*
* SpeedCheckMessageQueueSend - This function is a wrapper function for 
* MessageQueueSend()
*
* DESCRIPTION
* This function is a wrapper function for MessageQueueSend() 
*
* PARAMETERS
* \is
* \i N/A
* \ie
*
* GLOBALS:
* \is
* \i N/A
* \ie
*
* RETURNS:
* \is
* \i <true>
* when the MessageQueue Send is success
*
* \i <false>
* when the MessageQueue Send fails
* \ie
* 
* ERRNO:
* \is
* \i N/A
* \ie
*
* SEE ALSO:
* MessageQueue.c
*
* \INTERNAL
* This function is a wrapper function for MessageQueueSend() 
*/
bool SpeedCheckMessageQueueSend(uint32_t *pucMsgQSpeedData, size_t lMsgQSize)
{
    bool blRet = false;

    if(pucMsgQSpeedData != NULL)
    {
        if(MessageQueueSend(pucMsgQSpeedData, lMsgQSize) != false)
        {
            blRet = true;
        }
    }

    return blRet;
}

/*******************************************************************************
*
* SpeedCheckMessageQueueReceive - This function is a wrapper function for 
* MessageQueueReceive()
*
* DESCRIPTION
* This function is a wrapper function for MessageQueueReceive() 
*
* PARAMETERS
* \is
* \i N/A
* \ie
*
* GLOBALS:
* \is
* \i N/A
* \ie
*
* RETURNS:
* \is
* \i <true>
* when the MessageQueue receive is success
*
* \i <false>
* when the MessageQueue receive fails
* \ie
* 
* ERRNO:
* \is
* \i N/A
* \ie
*
* SEE ALSO:
* MessageQueue.c
*
* \INTERNAL
* This function is a wrapper function for MessageQueueReceive() 
*/
bool SpeedCheckMessageQueueReceive(uint32_t *pucMsgQSpeedData, size_t lMsgQSize)
{
    bool blRet = false;

    if(MessageQueueReceive(pucMsgQSpeedData , lMsgQSize) != false)
    {
        blRet = true;
    }

    return blRet;
}

/*******************************************************************************
*
* SpeedCheckForThresholds - This function check for the breach in engine speed 
* threshold against [SPEED_THRESHOLD_MIN] and [SPEED_THRESHOLD_MAX]. If the breach
* count goes beyond 5, signals alarm using semaphore
*
* DESCRIPTION
* This function check for the breach in engine speed 
* threshold against [SPEED_THRESHOLD_MIN] and [SPEED_THRESHOLD_MAX]. If the breach
* count goes beyond 5, signals alarm using semaphore
*
* PARAMETERS:
* \is
* \i [pucMsgQSpeedData]
* [in] A pointer to an integer representing the engine speed
* \i [psucThresholdBreachCount]
* [in] A pointer to an integer representing the breach count
* \ie
*
* GLOBALS:
* \is
* \i N/A
* \ie
*
* RETURNS:
* \is
* \i <true>
* when the SpeedCheckForThresholds when engine speed breaches threasholds more 
* than 5 times
*
* \i <false>
* when the SpeedCheckForThresholds doesn't breach the thresholds
* \ie
* 
* ERRNO:
* \is
* \i N/A
* \ie
*
* SEE ALSO:
* MessageQueue.c
*
* \INTERNAL
* This function is a wrapper function for MessageQueueReceive() 
*/
bool SpeedCheckForThresholds(uint32_t *pucMsgQSpeedData, 
                            uint8_t *psucThresholdBreachCount)
{
    bool blRet = false;

    if(*pucMsgQSpeedData < SPEED_THRESHOLD_MIN || 
        *pucMsgQSpeedData > SPEED_THRESHOLD_MAX)
    {
        (*psucThresholdBreachCount)++;
    }
    else
    {
        *psucThresholdBreachCount = 0;
    }

    if(*psucThresholdBreachCount > MAX_BREACH_COUNT)
    {
        blRet = true;
    }

    return blRet;
}
//EOF