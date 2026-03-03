/* Sleep.c - millisecond delay function */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history --------------------
02mar26, Updated coding standards
*/
/*
DESCRIPTION
This module create a sleep function in milliseconds. 
INCLUDE FILES: Sleep.h
*/
/* includes */
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include "Sleep.h"

/*******************************************************************************
*
* msleep - This function is a sleep function in milliseconds
*
* DESCRIPTION
* This function is a sleep function in milliseconds 
*
* PARAMETERS
* \is
* \i [ucTimeInMilliSeconds]
* [in] An interger which represents time in milliseconds
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
* when the milliseconds delay creation using usleep is success
*
* \i <false>
* when the milliseconds delay creation using usleep failed
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
* This function is a sleep function in milliseconds  
*/
bool msleep(uint32_t ucTimeInMilliSeconds) 
{ 
    bool blRet = false;
    if(usleep(ucTimeInMilliSeconds * MILLISECONDS) == 0)
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