/* Semaphore.c - Semaphore wrapper function library */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history --------------------
02mar26, Updated coding standards
*/
/*
DESCRIPTION
This module has wrapper functions  for creates, wait , post alarm semaphore
INCLUDE FILES: Semaphore.h
*/
/* includes */
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <semaphore.h>

/* globals */
sem_t lAlarmSemFlag;

/*******************************************************************************
*
* SemaphoreInit - This function is a wrapper for sem_init()
*
* DESCRIPTION
* This function is a wrapper for sem_init()
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
* when the sem_init() is successfull
*
* \i <false>
* when the sem_init() is not successfull
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
* This function is a wrapper for sem_init()   
*/
bool SemaphoreInit()
{
    bool blRet = false;

    if(sem_init(&lAlarmSemFlag, 0, 0) == 0)
    {
        blRet = true;
    }
    else
    {
        blRet = false;
    }

    return blRet;
}

/*******************************************************************************
*
* SemaphoreWait - This function is a wrapper for sem_wait()
*
* DESCRIPTION
* This function is a wrapper for sem_wait()
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
* when the sem_wait is successfull
*
* \i <false>
* when the sem_wait is not successfull
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
* This function is a wrapper for sem_wait()  
*/
bool SemaphoreWait()
{
    bool blRet = false;

    if(sem_wait(&lAlarmSemFlag) == 0)
    {
        blRet = true;
    }
    else
    {
        blRet = false;
    }

    return blRet;
}

/*******************************************************************************
*
* SemaphorePost - This function is a wrapper for sem_post()
*
* DESCRIPTION
* This function is a wrapper for sem_post()
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
* when the sem_post() is successfull
*
* \i <false>
* when the sem_post() is not successfull
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
* This function is a wrapper for sem_post()
*/
bool SemaphorePost()
{
    bool blRet = false;

    if(sem_post(&lAlarmSemFlag) == 0)
    {
        blRet = true;
    }
    else
    {
        blRet = false;
    }

    return blRet;
}
//EOF