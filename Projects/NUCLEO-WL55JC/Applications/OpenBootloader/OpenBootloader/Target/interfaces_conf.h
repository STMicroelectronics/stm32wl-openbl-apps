/**
  ******************************************************************************
  * @file    interfaces_conf.h
  * @author  MCD Application Team
  * @brief   Contains Interfaces configuration
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INTERFACES_CONF_H
#define INTERFACES_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32wlxx_ll_usart.h"
#include "stm32wlxx_ll_spi.h"

#define MEMORIES_SUPPORTED                6U

/* ------------------------- Definitions for USART -------------------------- */
#define USARTx                            USART1
#define USARTx_CLK_ENABLE()               __HAL_RCC_USART1_CLK_ENABLE()
#define USARTx_CLK_DISABLE()              __HAL_RCC_USART1_CLK_DISABLE()
#define USARTx_GPIO_CLK_TX_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define USARTx_GPIO_CLK_RX_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define USARTx_DeInit()                   LL_USART_DeInit(USARTx)

#define USARTx_TX_PIN                     GPIO_PIN_9
#define USARTx_TX_GPIO_PORT               GPIOA
#define USARTx_RX_PIN                     GPIO_PIN_10
#define USARTx_RX_GPIO_PORT               GPIOA
#define USARTx_ALTERNATE                  GPIO_AF7_USART1

/* -------------------------- Definitions for SPI --------------------------- */
#define SPIx                              SPI1
#define SPIx_CLK_ENABLE()                 __HAL_RCC_SPI1_CLK_ENABLE()
#define SPIx_CLK_DISABLE()                __HAL_RCC_SPI1_CLK_DISABLE()
#define SPIx_GPIO_CLK_SCK_ENABLE()        __HAL_RCC_GPIOA_CLK_ENABLE()
#define SPIx_GPIO_CLK_MISO_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define SPIx_GPIO_CLK_MOSI_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define SPIx_GPIO_CLK_NSS_ENABLE()        __HAL_RCC_GPIOA_CLK_ENABLE()
#define SPIx_DeInit()                     LL_SPI_DeInit(SPIx)
#define SPIx_IRQn                         SPI1_IRQn

#define SPIx_MOSI_PIN                     GPIO_PIN_7
#define SPIx_MOSI_PIN_PORT                GPIOA
#define SPIx_MISO_PIN                     GPIO_PIN_6
#define SPIx_MISO_PIN_PORT                GPIOA
#define SPIx_SCK_PIN                      GPIO_PIN_5
#define SPIx_SCK_PIN_PORT                 GPIOA
#define SPIx_NSS_PIN                      GPIO_PIN_4
#define SPIx_NSS_PIN_PORT                 GPIOA
#define SPIx_ALTERNATE                    GPIO_AF5_SPI1

#endif /* INTERFACES_CONF_H */
