/**
  ******************************************************************************
  * @file    otp_interface.c
  * @author  MCD Application Team
  * @brief   Contains One-time programmable access functions
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

/* Includes ------------------------------------------------------------------*/
#include "platform.h"
#include "openbl_mem.h"
#include "app_openbootloader.h"
#include "common_interface.h"
#include "otp_interface.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define OTP_PROG_STEP_SIZE                ((uint8_t)0x8U)

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void OPENBL_OTP_Program(uint32_t Address, uint64_t Data);

/* Exported variables --------------------------------------------------------*/
OPENBL_MemoryTypeDef OTP_Descriptor =
{
  OTP_START_ADDRESS,
  OTP_END_ADDRESS,
  OTP_BL_SIZE,
  OTP_AREA,
  OPENBL_OTP_Read,
  OPENBL_OTP_Write,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};

/* Exported functions --------------------------------------------------------*/

/**
  * @brief  This function is used to read data from a given address.
  * @param  Address The address to be read.
  * @retval Returns the read value.
  */
uint8_t OPENBL_OTP_Read(uint32_t Address)
{
  return (*(uint8_t *)(Address));
}

/**
  * @brief  This function is used to write data in OTP.
  * @param  Address The address where that data will be written.
  * @param  pData The data to be written.
  * @param  DataLength The length of the data to be written.
  * @retval None.
  */
void OPENBL_OTP_Write(uint32_t Address, uint8_t *pData, uint32_t DataLength)
{
  uint32_t index;
  uint8_t remaining_data[OTP_PROG_STEP_SIZE] = {0x0};
  uint8_t remaining;

  if ((pData != NULL) && (DataLength != 0U))
  {
    /* Unlock the flash memory for write operation */
    HAL_FLASH_Unlock();

    /* Program double-word by double-word (8 bytes) */
    while ((DataLength >> 3U) > 0U)
    {
      OPENBL_OTP_Program(Address, (uint64_t)(*((uint64_t *)((uint32_t)pData))));

      Address    += OTP_PROG_STEP_SIZE;
      pData      += OTP_PROG_STEP_SIZE;
      DataLength -= OTP_PROG_STEP_SIZE;
    }

    /* If remaining count, go back to fill the rest with 0xFF */
    if (DataLength > 0U)
    {
      remaining = OTP_PROG_STEP_SIZE - DataLength;

      /* copy the remaining bytes */
      for (index = 0U; index < DataLength; index++)
      {
        remaining_data[index] = *(pData + index);
      }

      /* Fill the upper bytes with 0xFF */
      for (index = 0U; index < remaining; index++)
      {
        remaining_data[index + DataLength] = 0xFFU;
      }

      /* FLASH word program */
      OPENBL_OTP_Program(Address, (uint64_t)(*((uint64_t *)((uint32_t)remaining_data))));
    }

    /* Lock the Flash to disable the flash control register access */
    HAL_FLASH_Lock();
  }

  /* Lock the Flash to disable the flash control register access */
  HAL_FLASH_Lock();
}

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Program double word at a specified FLASH address.
  * @param  Address specifies the address to be programmed.
  * @param  Data specifies the data to be programmed.
  * @retval None.
  */
static void OPENBL_OTP_Program(uint32_t Address, uint64_t Data)
{
  /* Clear all FLASH errors flags before starting write operation */
  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);

  HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, Address, Data);
}
