/* MessageQueue.c - Message queue wrapper function library */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history --------------------
02mar26, Updated coding standards
*/
/*
DESCRIPTION
This module has wrapper functions for messagw queue creation, send, receive
INCLUDE FILES: MessageQueue.h
*/
/* includes */
#include <stdbool.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "MessageQueue.h"

#ifndef UNIT_TEST
#include "HltcMock.h"
#endif

/* locals */
static mqd_t lSpeedMsgQueue = (mqd_t)MQ_ERROR;

/*******************************************************************************
*
* MessageQueueCreate - The function [MessageQueueCreate] will create a message 
* queue to send speed data from [SpeedReadThread] to [SpeedCheckThread]
*
* DESCRIPTION
* The function [MessageQueueCreate] will create a message queue to send speed 
* data from [SpeedReadThread] to [SpeedCheckThread]
*
* PARAMETERS:
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
* if mq_open() is successfull
*
* \i <false>
* if mq_open() fails
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
* The function [MessageQueueCreate] will create a message queue to send speed 
* data from [SpeedReadThread] to [SpeedCheckThread]
*/
bool MessageQueueCreate()
{
    bool blRet = false;

    /*Message queue Configuration*/
    struct mq_attr stMsgQueueAttr = {0};
    stMsgQueueAttr.mq_flags = 0;
    stMsgQueueAttr.mq_maxmsg = MSG_QUEUE_MAX_MESSAGES;
    stMsgQueueAttr.mq_msgsize = MSG_QUEUE_MAX_MSG_SIZE;
    stMsgQueueAttr.mq_curmsgs = 0;

#ifndef UNIT_TEST
    lSpeedMsgQueue = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, PERMISSION_MASK, 
                            &stMsgQueueAttr);
#else
    lSpeedMsgQueue = (mqd_t)mock_mq_open();
#endif
    if(lSpeedMsgQueue != (mqd_t)MQ_ERROR)
    {
        blRet = true;                                 //MessageQueueCreate_LLR_1
    }
    else
    {
        blRet = false;                                //MessageQueueCreate_LLR_2
    }

    return blRet;
}

/*******************************************************************************
*
* SemaphoreInit - This function is a wrapper for mq_send()
*
* DESCRIPTION
* This function is a wrapper for mq_send()
*
* PARAMETERS
* \is
* \i [pucMessageQueueData]
* [in] A pointer to an integer which contains data to be send via message queue
* \i [lMsgQSize]
* [in] An Interger which contains the size of the data 
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
* when the mq_send() is successfull
*
* \i <false>
* when the mq_send() is not successfull
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
* This function is a wrapper for mq_send()   
*/
bool MessageQueueSend(uint32_t *pucMessageQueueData, size_t lMsgQSize)
{
    bool blRet = true;

    if(pucMessageQueueData == NULL)
    {
        blRet = false;
    }
    else
    {
        if (mq_send(lSpeedMsgQueue, (const char*)pucMessageQueueData, 
                    lMsgQSize, 0) == MQ_ERROR) 
        { 
            blRet = false;
        }
        else
        {
            blRet = true;
        }
    }

    return blRet;
}

/*******************************************************************************
*
* MessageQueueReceive - This function is a wrapper for mq_receive()
*
* DESCRIPTION
* This function is a wrapper for mq_receive()
*
* PARAMETERS:
* \is
* \i [pucMessageQueueData]
* [in] A pointer to an integer to which data is received
* \i [lMsgQSize]
* [in] An Interger which contains the size of the data 
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
* when the mq_receive() is successfull
*
* \i <false>
* when the mq_receive() is not successfull
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
* This function is a wrapper for mq_receive()   
*/
bool MessageQueueReceive(uint32_t *pucMessageQueueData, size_t lMsgQSize)
{
    bool blRet = true;

    if(pucMessageQueueData == NULL)
    {
        blRet = false;
    }
    else
    {
        if (mq_receive(lSpeedMsgQueue, (char*)pucMessageQueueData, lMsgQSize, 
            NULL) == MQ_ERROR)
        {
            blRet = false;
        } 
        else 
        { 
            blRet = true;
        }
    }

    return blRet;
}
//EOF