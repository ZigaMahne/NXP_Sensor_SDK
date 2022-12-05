/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _RTE_DEVICE_H
#define _RTE_DEVICE_H

extern void I2C4_InitPins();
extern void I2C4_DeinitPins();
extern void I2C5_InitPins();
extern void I2C5_DeinitPins();
extern void SPI5_InitPins();
extern void SPI5_DeinitPins();
extern void USART0_InitPins();
extern void USART0_DeinitPins();
extern void SPI5_InitPins();
extern void SPI5_DeinitPins();
extern void USART0_InitPins();
extern void USART0_DeinitPins();

/*Driver name mapping*/
/* User needs to provide the implementation of I2CX_GetFreq/I2CX_InitPins/I2CX_DeinitPins for the enabled I2C instance.
 */
#define RTE_I2C4            1
#define RTE_I2C4_PIN_INIT   I2C4_InitPins
#define RTE_I2C4_PIN_DEINIT I2C4_DeinitPins
#define RTE_I2C4_DMA_EN     0
#define RTE_I2C5            1
#define RTE_I2C5_PIN_INIT   I2C5_InitPins
#define RTE_I2C5_PIN_DEINIT I2C5_DeinitPins
#define RTE_I2C5_DMA_EN     0

/* User needs to provide the implementation of SPIX_GetFreq/SPIX_InitPins/SPIX_DeinitPins for the enabled SPI instance.
 */
#define RTE_SPI5            1
#define RTE_SPI5_PIN_INIT   SPI5_InitPins
#define RTE_SPI5_PIN_DEINIT SPI5_DeinitPins
#define RTE_SPI5_DMA_EN     0

/* User needs to provide the implementation of USARTX_GetFreq/USARTX_InitPins/USARTX_DeinitPins for the enabled USART
 * instance. */
#define RTE_USART0            1
#define RTE_USART0_PIN_INIT   USART0_InitPins
#define RTE_USART0_PIN_DEINIT USART0_DeinitPins
#define RTE_USART0_DMA_EN     0

/* UART configuration. */
#define USART_RX_BUFFER_LEN     64
#define USART0_RX_BUFFER_ENABLE 1

/* I2C configuration */
#define RTE_I2C4_Master_DMA_BASE DMA0
#define RTE_I2C4_Master_DMA_CH   9

#define RTE_I2C5_Master_DMA_BASE DMA0
#define RTE_I2C5_Master_DMA_CH   11

/* SPI configuration. */

#define RTE_SPI5_SSEL_NUM        kSPI_Ssel2
#define RTE_SPI5_PIN_INIT        SPI5_InitPins
#define RTE_SPI5_PIN_DEINIT      SPI5_DeinitPins
#define RTE_SPI5_DMA_TX_CH       11
#define RTE_SPI5_DMA_TX_DMA_BASE DMA0
#define RTE_SPI5_DMA_RX_CH       10
#define RTE_SPI5_DMA_RX_DMA_BASE DMA0

/* USART configuration. */
#define RTE_USART0_PIN_INIT        USART0_InitPins
#define RTE_USART0_PIN_DEINIT      USART0_DeinitPins
#define RTE_USART0_DMA_TX_CH       1
#define RTE_USART0_DMA_TX_DMA_BASE DMA0
#define RTE_USART0_DMA_RX_CH       0
#define RTE_USART0_DMA_RX_DMA_BASE DMA0

#endif /* _RTE_DEVICE_H */
