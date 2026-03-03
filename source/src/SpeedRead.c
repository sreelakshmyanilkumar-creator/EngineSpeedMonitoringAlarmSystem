/* SpeedRead.c - speed read thread function and sensor read wrapper function */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history --------------------
02mar26, Updated coding standards
*/
/*
DESCRIPTION
This module contains the thread function to read engine speed data and send it 
to SpeedCheckThread() via message queue. 
INCLUDE FILES: Thread.h, SpeedRead.h, SpeedCheck.h, Alarm.h
*/
/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include "SpeedRead.h"
#include "SpeedCheck.h"
#include "Sensor.h"
#include "MessageQueue.h"
#include "Sleep.h"

/*******************************************************************************
*
* SpeedReadThread -This function continously read the engine speed data and send
it to SpeedCheckThread() via message queue.
*
* DESCRIPTION
* The function [SpeedReadThread] will continously read engine speed and send via
* message queue
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
* Sensor.c
*
* \INTERNAL
* The function [SpeedReadThread] will continously read engine speed and send via
* message queue
*/
void* SpeedReadThread(void *pArg)
{
    uint32_t ucSpeedValue = 0;
    (void)pArg;

    while(1)
    {
        if(ReadSpeed(&ucSpeedValue) != false)
        {
            if(SpeedCheckMessageQueueSend(&ucSpeedValue, MSG_QUEUE_MAX_MSG_SIZE) 
                                        != false)
            {
                printf("Message send successfully, Data = %d\n", ucSpeedValue);
            }
        }

        msleep(20);
    }

    return NULL;
}

/*******************************************************************************
*
* ReadSpeed - This function is a wrapper for engine speed read from sensor
*
* DESCRIPTION
* The function [ReadSpeed] read engine speed
*
* PARAMETERS
* \is
* \i <*pucSpeedValue>
* [in] A pointer to an integer representing the engine speed value to be 
* evaluated.
* \ie
*
* GLOBALS:
* \is
* \i N/A
* \ie
*
* RETURNS:
* \is
* \i <false>
* when sensor read fails
*
* \i <SUCCESS>
* when sensor read success
* \ie
* 
* ERRNO:
* \is
* \i N/A
* \ie
*
* SEE ALSO:
*
* \INTERNAL
* The function [ReadSpeed] will read the speed value to pucSpeedValue pointer
*/
bool ReadSpeed(uint32_t *pucSpeedValue)
{
    bool blRet = false;

    if(pucSpeedValue != NULL)
    {
        blRet = SensorRead(pucSpeedValue);
    }

    return blRet;
}
//EOF