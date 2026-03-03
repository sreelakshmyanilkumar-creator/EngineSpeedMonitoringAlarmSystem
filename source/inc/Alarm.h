/* Alarm.h - Alarm details definition */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history ------------------
02mar26, Updated coding standards
*/

#ifndef __INCALARM
#define __INCALARM

/* includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

/* global */
extern sem_t AlarmFlag;

/* function declarations */
void* AlarmThread(void *arg);
bool AlarmSemaphoreInitialize();
bool AlarmSemaphoreWait();
bool AlarmSemaphorePost();
#endif //__INCALARM
//EOF