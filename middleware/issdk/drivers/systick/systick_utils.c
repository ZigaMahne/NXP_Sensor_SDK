/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file  systick_utils.c
 * @brief Encapsulates the ARM sysTick counter, which is used for computing delays.
 *         ARM-core specific function that enables the ARM systick timer on Kinetis uCs.
 *         the timer is 24 bit so allows measurement of intervals up to 2^24/CORE_SYSTICK_HZ secs=0.35s for a 48MHz uC.
*/

#include "issdk_hal.h"
#include "cmsis_os2.h"

// ARM-core specific function to enable systicks.
void BOARD_SystickEnable(void)
{
}

// ARM-core specific function to store the current systick timer ticks.
void BOARD_SystickStart(int32_t *pStart)
{
    // Store the 32 bit systick timer.
    pStart = (int32_t *)osKernelGetSysTimerCount();
}

// ARM-core specific function to compute the elapsed systick timer ticks.
int32_t BOARD_SystickElapsedTicks(int32_t *pStart)
{
    uint32_t elapsed;

    // Subtract the stored start ticks.
    elapsed = osKernelGetSysTimerCount() - *(uint32_t *)pStart;

    return (int32_t)elapsed;
}

// ARM-core specific function to compute the elapsed time in micro seconds.
uint32_t BOARD_SystickElapsedTime_us(int32_t *pStart)
{
    uint32_t time_us, elapsed;
    uint32_t systemCoreClock;

    elapsed = BOARD_SystickElapsedTicks(pStart);
    systemCoreClock = CLOCK_GetFreq(kCLOCK_CoreSysClk);

    time_us = COUNT_TO_USEC(elapsed, systemCoreClock);

    return time_us;
}

// ARM-core specific function to insert delays in milli seconds.
void BOARD_DELAY_ms(uint32_t delay_ms)
{
    osDelay (delay_ms);
}
