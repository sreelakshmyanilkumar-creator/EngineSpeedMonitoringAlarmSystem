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

TEST(SensorRead_HLTC_1, SensorRead_HLTC_ZeroValue)
{
    uint32_t ucSpeedValue = 0;
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), false);
}

TEST(SensorRead_HLTC_1, SensorRead_HLTC_MinValue)
{
    uint32_t ucSpeedValue = SPEED_SENSOR_MIN;
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), true);
}

TEST(SensorRead_HLTC_1, SensorRead_HLTC_MinNoBreachValue)
{
    uint32_t ucSpeedValue = (SPEED_SENSOR_MIN + TEST_VALUE);
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), true);
}

TEST(SensorRead_HLTC_1, SensorRead_HLTC_MaxNoBreachValue)
{
    uint32_t ucSpeedValue = (SPEED_SENSOR_MAX - TEST_VALUE);
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), true);
}

TEST(SensorRead_HLTC_1, SensorRead_HLTC_MaxValue)
{
    uint32_t ucSpeedValue = SPEED_SENSOR_MAX;
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), true);
}

TEST(SensorRead_HLTC_1, SensorRead_HLTC_MaxBreachValue)
{
    uint32_t ucSpeedValue = (SPEED_SENSOR_MAX + TEST_VALUE);
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), false);
}

TEST(SensorRead_HLTC_1, SensorRead_HLTC_MiddleValue)
{
    uint32_t ucSpeedValue = ((SPEED_SENSOR_MAX + SPEED_SENSOR_MIN)/DIVIDE_TWO);
    uint32_t *pucSpeedValue = &ucSpeedValue;
    printf("pucSpeedValue = %d\n",*pucSpeedValue);
    EXPECT_EQ(SensorRead(pucSpeedValue), true);
}

TEST(SensorRead_HLTC_2, SensorRead_HLTC_NullCheck)
{
    uint32_t *pucSpeedValue = nullptr;
    EXPECT_EQ(SensorRead(pucSpeedValue), false);
}


TEST(MessageQueueCreate_HLTC_1, MessageQueueCreate_HLTC_Success)
{
    SetForSuccessTest();
    EXPECT_EQ(MessageQueueCreate(), true);
    ResetForSuccessTest();
}

TEST(MessageQueueCreate_HLTC_2, MessageQueueCreate_HLTC_Fail)
{
    ResetForSuccessTest();
    EXPECT_EQ(MessageQueueCreate(), false);
}