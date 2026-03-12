/* Sensor.h - Sensor read definition */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history ------------------
02mar26, Updated coding standards
*/

#ifndef __INCSENSOR_H_ 
#define __INCSENSOR_H_

/* includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* defines */
#define SPEED_THRESHOLD_MAX     (2500)
#define SPEED_THRESHOLD_MIN     (600)
#define RANGE_ADJUST            (1)
#define SPEED_SENSOR_MAX        (2800) 
#define SPEED_SENSOR_MIN        (400)

/* function declarations */
bool SensorRead(uint32_t *pucSpeedValue);
#endif //_SENSOR_H_
//EOF