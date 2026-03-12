/* LltcEngineSpeedMonitoringSystem.cpp - test function library */ 
/* 
* Copyright (c) 2026 Trenser Technologies Ltd. 
* 
*/
/* includes */
#include <gtest/gtest.h>
#include <stdio.h>

extern "C" {
    #include "Sensor.h"
    #include "MessageQueue.h"
    #include "LltcMock.h"
}

#define TEST_VALUE      (1)
#define DIVIDE_TWO      (2)

/* Test Functions Definitions */

TEST(MessageQueueCreate_LLTC_1, MessageQueueCreate_LLTC_Success)
{
    SetForSuccessTest();
    EXPECT_EQ(MessageQueueCreate(), true);
    ResetForSuccessTest();
}

TEST(MessageQueueCreate_LLTC_2, MessageQueueCreate_LLTC_Fail)
{
    ResetForSuccessTest();
    EXPECT_EQ(MessageQueueCreate(), false);
}

TEST(SensorRead_LLTC_3, SensorRead_LLTC_NullCheck)
{
    uint32_t *pucSpeedValue = nullptr;
    EXPECT_EQ(SensorRead(pucSpeedValue), false);
}

TEST(SensorRead_LLTC_4, SensorRead_LLTC_ZeroValue)
{
    uint32_t ucSpeedValue = 0;
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), false);
}

TEST(SensorRead_LLTC_11, SensorRead_LLTC_MinBreachValue)
{
    uint32_t ucSpeedValue = (SPEED_SENSOR_MIN - TEST_VALUE);
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), false);
}

TEST(SensorRead_LLTC_5, SensorRead_LLTC_MinValue)
{
    uint32_t ucSpeedValue = SPEED_SENSOR_MIN;
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), true);
}

TEST(SensorRead_LLTC_6, SensorRead_LLTC_MinNoBreachValue)
{
    uint32_t ucSpeedValue = (SPEED_SENSOR_MIN + TEST_VALUE);
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), true);
}

TEST(SensorRead_LLTC_7, SensorRead_LLTC_MaxNoBreachValue)
{
    uint32_t ucSpeedValue = (SPEED_SENSOR_MAX - TEST_VALUE);
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), true);
}

TEST(SensorRead_LLTC_8, SensorRead_LLTC_MaxValue)
{
    uint32_t ucSpeedValue = SPEED_SENSOR_MAX;
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), true);
}

TEST(SensorRead_LLTC_9, SensorRead_LLTC_MaxBreachValue)
{
    uint32_t ucSpeedValue = (SPEED_SENSOR_MAX + TEST_VALUE);
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), false);
}

TEST(SensorRead_LLTC_10, SensorRead_LLTC_MiddleValue)
{
    uint32_t ucSpeedValue = ((SPEED_SENSOR_MAX + SPEED_SENSOR_MIN)/DIVIDE_TWO);
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), true);
}


