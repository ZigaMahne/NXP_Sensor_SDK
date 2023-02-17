/*---------------------------------------------------------------------------
 * Copyright (c) 2023 Arm Limited (or its affiliates). 
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *---------------------------------------------------------------------------*/

#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#ifdef RTE_Compiler_EventRecorder
#include "EventRecorder.h"
#endif

#include "clock_config.h"
#include "board.h"
#include "pin_mux.h"
#include "peripherals.h"
#include "main.h"
#include "systick_utils.h"
#include "lpc54114.h"

int main (void) {

  /*! Initialize the MCU hardware. */
  BOARD_InitPins();
  BOARD_BootClockRUN();
  BOARD_SystickEnable();
  BOARD_InitDebugConsole();

  NVIC_SetPriority(FLEXCOMM0_IRQn,  8U); // UART0
  NVIC_SetPriority(FLEXCOMM5_IRQn,  8U); // SPI5
  NVIC_SetPriority(FLEXCOMM4_IRQn,  8U); // I2C4

  SystemCoreClockUpdate();

#if defined(RTE_Compiler_EventRecorder) && \
    (defined(__MICROLIB) || \
    !(defined(RTE_CMSIS_RTOS2_RTX5) || defined(RTE_CMSIS_RTOS2_FreeRTOS)))
  EventRecorderInitialize(EventRecordAll, 1U);
#endif

  osKernelInitialize();                 // Initialize CMSIS-RTOS2
  app_initialize();                     // Initialize application
  osKernelStart();                      // Start thread execution

  for (;;) {}
}
