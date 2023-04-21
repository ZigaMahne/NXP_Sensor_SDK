/*
 * Copyright 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file evkmimxrt1060.h
 * @brief The evkmimxrt1060.h file defines GPIO pin mappings for evkmimxrt1060 board
 */

#ifndef EVKBIMX1050_H_
#define EVKBIMX1050_H_

#include "pin_mux.h"
#include "RTE_Device.h"
#include "GPIO_iMXRT1060.h"
#include "MIMXRT1062.h"
#include "Driver_I2C.h"
#include "Driver_SPI.h"
#include "Driver_USART.h"

// i.MXRT1060 EVK Arduino Connector Pin Defintion
#define ARDUINO_UNO_D0  GPIO_PORT1(23U) /* LPUART3: RX */
#define ARDUINO_UNO_D1  GPIO_PORT1(22U) /* LPUART3: TX */
#define ARDUINO_UNO_D2  GPIO_PORT1(11U)
#define ARDUINO_UNO_D3  GPIO_PORT1(24U)
#define ARDUINO_UNO_D4  GPIO_PORT1(9U)
#define ARDUINO_UNO_D5  GPIO_PORT1(10U)
#define ARDUINO_UNO_D6  GPIO_PORT1(18U)
#define ARDUINO_UNO_D7  GPIO_PORT1(19U)
#define ARDUINO_UNO_D8  GPIO_PORT1(3U)
#define ARDUINO_UNO_D9  GPIO_PORT1(2U)

#define ARDUINO_UNO_D10  GPIO_PORT3(13U)
#define ARDUINO_UNO_D11  GPIO_PORT3(14U)
#define ARDUINO_UNO_D12  GPIO_PORT3(15U)
#define ARDUINO_UNO_D13  GPIO_PORT3(12U)

#define ARDUINO_UNO_D14 GPIO_PORT1(17U) /* LPI2C1:  SDA  */
#define ARDUINO_UNO_D15 GPIO_PORT1(16U) /* LPI2C1:  SCL  */
#define ARDUINO_UNO_D16 GPIO_PORT1(8U)
#define ARDUINO_UNO_D17 GPIO_PORT1(10U)
#define ARDUINO_UNO_D18 GPIO_PORT1(17U) /* LPI2C1:  SDA  */
#define ARDUINO_UNO_D19 GPIO_PORT1(16U) /* LPI2C1:  SCL  */

#define A5 ARDUINO_UNO_D19
#define A4 ARDUINO_UNO_D18

// i.MXRT1060 EVK Arduino CMSIS Driver instances
#define ARDUINO_UNO_I2C     1
//#define ARDUINO_UNO_SPI     5
#define ARDUINO_UNO_UART    3

// i.MXRT1060 EVK Internal Peripheral Pin Definitions
#define RED_LED         GPIO_PORT1(9U)
#define GREEN_LED       GPIO_PORT1(9U)
#define BLUE_LED        GPIO_PORT1(9U)
#define INT1            GPIO_PORT1(10U)
#define INT2            GPIO_PORT1(11U)

// i.MXRT1060 EVK Arduino CMSIS Driver instances
#define ARDUINO_UNO_I2C     1
#define ARDUINO_UNO_SPI     1
#define ARDUINO_UNO_UART    3

// CMSIS Drivers
extern ARM_DRIVER_I2C   Driver_I2C1;
extern ARM_DRIVER_SPI   Driver_SPI1;
extern ARM_DRIVER_USART Driver_USART1;
extern ARM_DRIVER_USART Driver_USART3;

// I2C_S1: Pin mapping and driver information for default I2C brought to shield
#define I2C_S1_SCL_PIN      A5
#define I2C_S1_SDA_PIN      A4
#define I2C_S1_DRIVER       Driver_I2C1
#define I2C_S1_DEVICE_INDEX I2C1_INDEX
#define I2C_S1_SIGNAL_EVENT I2C1_SignalEvent_t

// I2C_S2: Pin mapping and driver information for alternate I2C bus on shield
#define I2C_S2_SCL_PIN      D15
#define I2C_S2_SDA_PIN      D14
#define I2C_S2_DRIVER       Driver_I2C0
#define I2C_S2_DEVICE_INDEX I2C0_INDEX
#define I2C_S2_SIGNAL_EVENT I2C0_SignalEvent_t

// I2C_B: Pin mapping and driver information for I2C routed on base board
#define I2C_BB_SCL_PIN      A5
#define I2C_BB_SDA_PIN      A4
#define I2C_BB_DRIVER       Driver_I2C3
#define I2C_BB_DEVICE_INDEX I2C3_INDEX
#define I2C_BB_SIGNAL_EVENT I2C3_SignalEvent_t

// SPIS: Pin mapping and driver information default SPI brought to shield
#define SPI_S_SCLK         D13
#define SPI_S_MISO         D12
#define SPI_S_MOSI         D11
#define SPI_S_DRIVER       Driver_SPI1
#define SPI_S_BAUDRATE     500000U ///< Transfer baudrate - 500k
#define SPI_S_DEVICE_INDEX SPI1_INDEX
#define SPI_S_SIGNAL_EVENT SPI1_SignalEvent_t

// UART: Driver information for default UART to communicate with HOST PC.
#define HOST_S_DRIVER       Driver_USART1
#define HOST_S_SIGNAL_EVENT HOST_SignalEvent_t

// On-Board FXOS8700 Sensor Information
#define FXOS8700_BB_I2C_ADDR 0x1E
#define FXOS8700_BB_INT1     INT1
#define FXOS8700_BB_INT2     INT2

/* Compatability definitions for evkmimxrt1060 */
#define I2C1          LPI2C1
#define I2C_Type      LPI2C_Type
#define I2C_BASE_PTRS LPI2C_BASE_PTRS
#define SPI1          LPSPI1
#define SPI_Type      LPSPI_Type
#define SPI_BASE_PTRS LPSPI_BASE_PTRS

/* @brief dummy arguement to Power Mode Wait Wrapper. */
#define SMC NULL

// I2C/SPI Communication Idle Task and Argument
#define COMM_IDLE_TASK      NULL //SMC_SetPowerModeVlpr
#define COMM_IDLE_ARG       NULL

// Enter Sleep (Power Down)
#define ENTER_SLEEP()       NULL//SMC_SetPowerModeWait(SMC)

///* @brief Kinetis style Wrapper API for Power Mode Wait (Wait for Interrupt). */
//status_t SMC_SetPowerModeWait(void *arg);
///* @brief Kinetis style Wrapper API for Power Mode VLPR (Wait for Interrupt). */
//status_t SMC_SetPowerModeVlpr(void *arg);

#endif /* EVKBIMX1050_H_ */
