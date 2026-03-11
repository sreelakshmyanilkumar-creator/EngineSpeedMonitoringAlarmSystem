/* HltcMock.c - test function library */ 
/* 
* Copyright (c) 2026 Trenser Technologies Ltd. 
* 
*/
/* includes */
#include <stdio.h>
#include <mqueue.h>
#include <stdint.h>

#define FLAG_RESET  (0)
#define FLAG_SET    (1)
#define MQ_SUCCESS  ()
#define MQ_FAIL     (-1)

mqd_t mock_mq_open();
void SetForSuccessTest();
void ResetForSuccessTest();