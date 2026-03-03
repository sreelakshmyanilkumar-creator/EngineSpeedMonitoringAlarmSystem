/* Semaphore.h - Semaphore details definition */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history ------------------
02mar26, Updated coding standards
*/

#ifndef __INCSEMAPHORE_H_ 
#define __INCSEMAPHORE_H_

/* includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* function declarations */
bool SemaphoreInit();
bool SemaphorePost();
bool SemaphoreWait();
#endif //__INCSEMAPHORE_H_
//EOF