/* Thread.h - Thread details definition */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history ------------------
02mar26, Updated coding standards
*/

#ifndef __INCTHREAD_H_ 
#define __INCTHREAD_H_

/* includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* defines */
typedef struct _THREAD_HANDLER_
{
    pthread_t lThreadId;
    void* (*func) (void*);
}THREAD_HANDLER;

/* function declarations */
bool CreateThreads();
#endif //__INCTHREAD_H_
//EOF