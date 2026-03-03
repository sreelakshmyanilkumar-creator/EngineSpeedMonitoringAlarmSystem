/* Sensor.c - Speed Sensor read function */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history --------------------
02mar26, Updated coding standards
*/
/*
DESCRIPTION
This module directly read from speed sensor
INCLUDE FILES: Sensor.h
*/
/* includes */
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include "Sensor.h"

/*******************************************************************************
*
* SensorRead - The function [SensorRead] will read the engine speed values from
* a sensor.
*
* DESCRIPTION
* The function [SensorRead] will read the engine speed values from a sensor.
*
* PARAMETERS
* \is
* \i [pucSpeedValue]
* [in] An interger pointer to which the sensor read
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
* if the speed sensor data is read successfully.
*
* \i <false>
* if the speed sensor data read fails
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
* The function [SensorRead] will read the engine speed values from a sensor.  
*/
bool SensorRead(uint32_t *pucSpeedValue)
{
    bool blRet = false;
    
    *pucSpeedValue = (rand() % (SPEED_THRESHOLD_MAX - (SPEED_THRESHOLD_MIN) + 
                    RANGE_ADJUST)) + (SPEED_THRESHOLD_MIN);

    //Comparing with assumed sensor max and min values
    if(*pucSpeedValue > SPEED_SENSOR_MIN || *pucSpeedValue < SPEED_SENSOR_MAX)
    {
        blRet = true;
    }

    return blRet;
}
//EOF