/* main.c - main function */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history --------------------
02mar26, Updated coding standards
*/
/*
DESCRIPTION
This module is the includes main function of the system. The function uses the 
following functions defined in Thread.h:
INCLUDE FILES: Thread.h
*/
/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include "Thread.h"

/* defines */
#define FAILURE             (1)
#define SUCCESS             (0)

/*******************************************************************************
*
* main - This function evaluates engine speed data against thresholds and 
* boundaries
*
* DESCRIPTION
* The function [main] will create threads to read engine speed to check the 
* range within [SPEED_THRESHOLD_MIN] and [SPEED_THRESHOLD_MAX] and to alarm
* If violation is found return the error status
*
* PARAMETERS
* \is
* \i N/A
* \ie
*
* GLOBALS:
* \is
*
* \i N/A
* \ie
*
* RETURNS:
* \is
* \i <FAILURE>
* when CreateThreads fails
*
* \i <SUCCESS>
* when CreateThreads success
*
* \ie
* 
* ERRNO:
* \is
* \i N/A
*
* \i N/A
* \ie
*
* SEE ALSO:
* Thread.c
*
* \INTERNAL
* The function [main] will create threads to read engine speed to check the 
* range within [SPEED_THRESHOLD_MIN] and [SPEED_THRESHOLD_MAX] and to alarm
* If violation is found return the error status
*/

int main(void)
{
    int lRet = FAILURE;
    
    if(CreateThreads())
    {
        lRet = SUCCESS;
    }
    else
    {
        printf("CreateThreads Failed\n");
    }
    
    return lRet;
}
//EOF
