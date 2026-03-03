/* Alarm.c - Alarm thread function and semaphore wrapper library */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history --------------------
02mar26, Updated coding standards
*/
/*
DESCRIPTION
This module has thread functions for alarm and semaphore wrapper APIs
INCLUDE FILES: Alarm.h Semaphore.h
*/
/* includes */
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include "Alarm.h"
#include "Semaphore.h"

/*******************************************************************************
*
* AlarmThread - This thread function waits for signal from SpeedCheckThread() 
* and print "ALARM TRIGGERED" when get signal
*
* DESCRIPTION
* This thread function waits for signal from SpeedCheckThread() 
* and print "ALARM TRIGGERED" when get signal
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
* \i N/A
* \ie
* 
* ERRNO:
* \is
* \i N/A
* \ie
*
* SEE ALSO:
* Semaphore.c SpeedCheckThread.c
*
* \INTERNAL
* This thread function waits for signal from SpeedCheckThread() 
* and print "ALARM TRIGGERED" when get signal   
*/
void* AlarmThread(void *pArg)
{
    (void)pArg;
    if(AlarmSemaphoreInitialize())
    {
        while(1)
        {
            if(AlarmSemaphoreWait())
            {
                printf("Alarm Triggered\n");
            }
            else
            {
                printf("Semwait failed\n");
            }
        }
    }
    else
    {
        printf("Alarm semaphore initialize failed\n");
    }

    return NULL;
}

/*******************************************************************************
*
* AlarmSemaphoreInitialize - This function is a wrapper for semaphore init
*
* DESCRIPTION
* This function is a wrapper for semaphore init
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
* when the semaphore initialize is successfull
*
* \i <false>
* when the semaphore initialize is not successfull
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
* This function is a wrapper for semaphore init
*/
bool AlarmSemaphoreInitialize()
{
    bool blRet = false;

    if(SemaphoreInit() != false)
    {
        blRet = true;
    }

    return blRet;
}

/*******************************************************************************
*
* AlarmSemaphoreWait - This function is a wrapper for semaphore wait
*
* DESCRIPTION
* This function is a wrapper for semaphore wait 
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
* when the semaphore wait is successfull
*
* \i <false>
* when the semaphore wait failed
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
* This function is a wrapper for semaphore wait 
*/
bool AlarmSemaphoreWait()
{
    bool blRet = false;

    if(SemaphoreWait() == 0)
    {
        blRet = true;
    }

    return blRet;
}

/*******************************************************************************
*
* AlarmSemaphorePost - This function is a wrapper for semaphore post
*
* DESCRIPTION
* This function is a wrapper for semaphore post 
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
* when the semaphore post is successfull
*
* \i <false>
* when the semaphore post failed
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
* This function is a wrapper for semaphore post
*/
bool AlarmSemaphorePost()
{
    bool blRet = false;

    if(SemaphorePost() == 0)
    {
        blRet = true;
    }

    return blRet;
}
//EOF

