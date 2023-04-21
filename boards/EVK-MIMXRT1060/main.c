/*---------------------------------------------------------------------------
 * Copyright (c) 2023 Arm Limited (or its affiliates). All rights reserved.
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


#include "clock_config.h"
#include "board.h"
#include "pin_mux.h"
#include "fsl_iomuxc.h"
#include "main.h"

// Callbacks for LPUART1 Driver
uint32_t LPUART1_GetFreq   (void) { return BOARD_BOOTCLOCKRUN_UART_CLK_ROOT; }
void     LPUART1_InitPins  (void) { /* Done in BOARD_InitDEBUG_UART function */ }
void     LPUART1_DeinitPins(void) { /* Not implemented */ }

// Callbacks for LPUART3 Driver
uint32_t LPUART3_GetFreq   (void) { return BOARD_BOOTCLOCKRUN_UART_CLK_ROOT; }
void     LPUART3_InitPins  (void) { /* Done in BOARD_InitDEBUG_UART function */ }
void     LPUART3_DeinitPins(void) { /* Not implemented */ }

// Callbacks for LPI2C1 Driver
uint32_t LPI2C1_GetFreq   (void) { return BOARD_BOOTCLOCKRUN_LPI2C_CLK_ROOT; }
void     LPI2C1_InitPins  (void) { /* Done in BOARD_InitDEBUG_UART function */ }
void     LPI2C1_DeinitPins(void) { /* Not implemented */ }

#ifdef   CMSIS_shield_header
#include CMSIS_shield_header
__WEAK int32_t shield_setup (void) {
  return 0;
}
#endif

int main (void) {

  /*! Initialize the MCU hardware. */
  BOARD_InitBootPins();
  BOARD_InitBootClocks();
  BOARD_InitDebugConsole();

  SystemCoreClockUpdate();

#ifdef CMSIS_shield_header
  shield_setup();
#endif

  return (app_main());
}