/* Thread.c - Thread creation function */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history --------------------
02mar26, Updated coding standards
*/
/*
DESCRIPTION
The module will create threads and evaluate the engine speed data against 
predefined thresholds and boundaries. It checks if the engine speed is within 
the acceptable range and logs any violations accordingly.
INCLUDE FILES: Thread.h, SpeedRead.h, SpeedCheck.h, Alarm.h
*/
/* includes */
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include "Thread.h"
#include "SpeedRead.h"
#include "SpeedCheck.h"
#include "Alarm.h"

/* Local variables */
THREAD_HANDLER ThreadHandler[] = {{0, SpeedReadThread},
                                  {0, SpeedCheckThread},
                                  {0, AlarmThread}
                                 };

/*******************************************************************************
*
* CreateThreads - This function evaluates engine speed data against thresholds 
* and boundaries
*
* DESCRIPTION
* The function [CreateThreads] will create threads and join them
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
* \i <FAILURE>
* when any of the 3 threads create/join fails
*
* \i <SUCCESS>
* when all the 3 threads create and join success
* \ie
* 
* ERRNO:
* \is
* \i N/A
* \ie
*
* SEE ALSO:
* Thread.c, SpeedRead.c, SpeedCheck.c, Alarm.c
*
* \INTERNAL
* The function [CreateThreads] will create threads and join them
*/
bool CreateThreads()
{
    bool blRet = true;
    uint8_t ucMaxThreadCount = 0;
    ucMaxThreadCount = sizeof(ThreadHandler)/sizeof(ThreadHandler[0]);

    //To create threads
    for (uint8_t ucindex = 0; ucindex < ucMaxThreadCount; ucindex++)
    {
        if(pthread_create(&ThreadHandler[ucindex].lThreadId, NULL, 
                            ThreadHandler[ucindex].func, NULL) != 0)
        {
            blRet = false;
            return blRet;
        }
    }

    //To join threads
    for (uint8_t ucindex = 0; ucindex < ucMaxThreadCount; ucindex++) 
    {
        if(pthread_join(ThreadHandler[ucindex].lThreadId, NULL) != 0)
        {
            blRet = false;
            return blRet;
        }
    }

    return blRet;
}
//EOF