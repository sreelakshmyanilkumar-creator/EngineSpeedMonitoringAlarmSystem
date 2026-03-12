/* LltcMock.c - test function library */ 
/* 
* Copyright (c) 2026 Trenser Technologies Ltd. 
* 
*/
/* includes */
#include <stdio.h>
#include <mqueue.h>
#include <stdbool.h>
#include "LltcMock.h"

#define MOCK_MQ_SUCCESS ((mqd_t)42)
#define MOCK_MQ_FAILURE ((mqd_t)-1)

static bool MQ_Flag = FLAG_RESET;

mqd_t mock_mq_open()
{
    if(MQ_Flag == FLAG_SET)
    {
        return MOCK_MQ_SUCCESS;
    }
    else
    {
        return MOCK_MQ_FAILURE;
    }

}

void SetForSuccessTest()
{
    MQ_Flag = FLAG_SET;
}

void ResetForSuccessTest()
{
    MQ_Flag = FLAG_RESET;
}

