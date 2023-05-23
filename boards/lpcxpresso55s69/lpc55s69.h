/*
 * Copyright 2018 NXP
 *
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file lpc55s69.h
 * @brief The lpc55s69.h file defines GPIO pin mappings for LPCXpresso55S69 board
*/

#ifndef LPC55S69_H_
#define LPC55S69_H_

#include "pin_mux.h"
#include "fsl_power.h"
#include "RTE_Device.h"
#include "GPIO_LPC55S69.h"
//#include "gpio_driver.h"
#include "Driver_I2C.h" // Added by dando-dev I2C is detailed by PACK
#include "Driver_SPI.h" // Added by dando-dev SPI is detailed by PACK
#include "Driver_USART.h"  // Added by dando-dev USART is detailed by PACK

// LPCXpresso55S69 Arduino Connector Pin Defintion
// Grabbed ports/pins from from old lpc55s69.c file gpioHandleKSDK calls
#define ARDUINO_UNO_D0  GPIO_PORT0(29U)     /* UART0: RX PIO0 Pin 29*/
#define ARDUINO_UNO_D1  GPIO_PORT0(30U)     /* UART0: TX PIO0 Pin 30*/
#define ARDUINO_UNO_D2  GPIO_PORT0(15U)
// #define ARDUINO_UNO_D3  GPIO_PORT1(6U)   /* PIO1 Pin 6 - LEDR Conflict */
// #define ARDUINO_UNO_D4  GPIO_PORT1(7U)   /* PIO1 Pin 7 - LEDG Conflict */
// #define ARDUINO_UNO_D5  GPIO_PORT1(4U)   /* PIO1 Pin 4 - LEDB Conflict */
#define ARDUINO_UNO_D6  GPIO_PORT1(10U)
#define ARDUINO_UNO_D7  GPIO_PORT1(9U)
#define ARDUINO_UNO_D8  GPIO_PORT1(8U)
#define ARDUINO_UNO_D9  GPIO_PORT1(5U)
#define ARDUINO_UNO_D10 GPIO_PORT1(1U)   /* SPI8:  CS   PIO0 Pin 20*/
#define ARDUINO_UNO_D11 GPIO_PORT0(26U)  /* SPI8:  MOSI PIO0 Pin 20*/
#define ARDUINO_UNO_D12 GPIO_PORT1(3U)  /* SPI8:  MISO PIO0 Pin 19*/
#define ARDUINO_UNO_D13 GPIO_PORT1(2U)  /* SPI8:  SCK  PIO0 Pin 21*/
#define ARDUINO_UNO_D14 GPIO_PORT0(16U)
#define ARDUINO_UNO_D15 GPIO_PORT0(23U)
#define ARDUINO_UNO_D16 GPIO_PORT0(0U)
#define ARDUINO_UNO_D17 GPIO_PORT1(31U)
#define ARDUINO_UNO_D18 GPIO_PORT0(13U)
#define ARDUINO_UNO_D19 GPIO_PORT0(14U)
#define ARDUINO_UNO_D20 GPIO_PORT1(21U)  /* I2C4:  SDA  PIO1 Pin 21*/
#define ARDUINO_UNO_D21 GPIO_PORT1(20U)  /* I2C4:  SCL  PIO1 Pin 20*/

// LPCXpresso55S69 Arduino CMSIS Driver instances
#define ARDUINO_UNO_I2C     4
#define ARDUINO_UNO_SPI     8
#define ARDUINO_UNO_UART    0

// LPCXpresso55S69 Internal Peripheral Pin Definitions
#define RED_LED         GPIO_PORT1(4U) /* PIO1 Pin 4 */
#define GREEN_LED       GPIO_PORT1(7U) /* PIO1 Pin 7 */
#define BLUE_LED        GPIO_PORT1(6U)  /* PIO1 Pin 6 */

// CMSIS Drivers
extern ARM_DRIVER_I2C   Driver_I2C4;      // Added by dando-dev to declare i2c4
extern ARM_DRIVER_SPI   Driver_SPI8;      // Added by dando-dev to declare SPI8 listed in prior file below
extern ARM_DRIVER_USART Driver_USART0;  // Added by dando-dev to declare USART0
extern ARM_DRIVER_USART Driver_USART1;  // Added by dando-dev to declare USART1

// // I2C_S1: Pin mapping and driver information for default I2C brought to shield
// #define I2C_S1_SCL_PIN D15
// #define I2C_S1_SDA_PIN D14
// #define I2C_S1_DRIVER Driver_I2C4
// #define I2C_S1_DEVICE_INDEX I2C4_INDEX
// #define I2C_S1_SIGNAL_EVENT I2C4_SignalEvent_t

// // SPI_S: Pin mapping and driver information default SPI brought to shield
// #define SPI_S_DRIVER       Driver_SPI8
 #define SPI_S_BAUDRATE     500000U///< Transfer baudrate - 500k
 #define SPI_S_DEVICE_INDEX SPI8_INDEX
 #define SPI_S_SIGNAL_EVENT SPI8_SignalEvent_t

// UART: Driver information for default UART to communicate with HOST PC.
#define HOST_S_DRIVER           Driver_USART0
#define HOST_S_SIGNAL_EVENT     HOST_SignalEvent_t
#define HOST_B_DRIVER           Driver_USART1
#define HOST_B_SIGNAL_EVENT     HOST_SignalEvent_t

#define WIRED_USART            USART0
#define WIRED_USART_CLK_SRC    kCLOCK_Flexcomm0
#define WIRED_USART_CLK_FREQ   CLOCK_GetFlexCommClkFreq(0)
#define WIRED_USART_IRQHandler FLEXCOMM0_IRQHandler
#define WIRED_USART_IRQn       FLEXCOMM0_IRQn

#define WIRELESS_USART USART1

// ADS_FLASH: The next to last sector of flash.
#define ADS_NVM_ADDR (FSL_FEATURE_SYSCON_FLASH_SIZE_BYTES - (2 * FSL_FEATURE_SYSCON_FLASH_SECTOR_SIZE_BYTES))

/* @brief  Override Kinetis style Wrapper for handling all Clock related configurations. */
#ifdef BOARD_BootClockRUN
#undef BOARD_BootClockRUN
#define BOARD_BootClockRUN()                             \
    /* attach 12 MHz clock to FLEXCOMM0 (debug/UART0) */ \
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM0);               \
    /* attach 12 MHz clock to FLEXCOMM4 (I2C4) */        \
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM4);               \
    /* attach 12 MHz clock to FLEXCOMM7 (SPI7) */        \
    CLOCK_AttachClk(kFRO12M_to_HSLSPI);               \
    /* Configure FROHF96M Clock */                       \
    BOARD_BootClockFROHF96M()
#endif

// Sensor Communication Idle Task and Argument
#define SENSOR_IDLE_TASK    SMC_SetPowerModeVlpr
#define SENSOR_IDLE_ARG     NULL

/* @brief dummy arguement to Power Mode Wait Wrapper. */
#define SMC NULL

/* @brief Kinetis style Wrapper API for Power Mode Wait (Wait for Interrupt). */
status_t SMC_SetPowerModeWait(void *);
/* @brief Kinetis style Wrapper API for Power Mode VLPR (Wait for Interrupt). */
status_t SMC_SetPowerModeVlpr(void *);

///@name Miscellaneous Hardware Configuration Parameters
///@{
#define THIS_BOARD           16         ///< LPC54114
#define CORE_SYSTICK_HZ      48000000   ///< core and systick clock rate (Hz)
#define CALIBRATION_NVM_ADDR 0x0003FF00 ///< start of final 256 bytes of 256K flash memory (LPC54114)
#define NVM_SECTOR_NUMBER    7          ///< Sector number in flash where we will store parameters
#define NVM_PAGE_NUMBER      1023       ///< Page number in flash where we will store parameters

// offsets from start of NVM block for calibration coefficients
#define MAG_NVM_OFFSET   0   // 68 bytes used
#define GYRO_NVM_OFFSET  100 // 16 bytes used
#define ACCEL_NVM_OFFSET 140 // 88 bytes used
///@}

#endif /* LPC55S69_CM4_H_ */