/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
extern void app_initialize (void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IO_D10_Pin GPIO_PIN_2
#define IO_D10_GPIO_Port GPIOA
#define ISM43362_RESET_Pin GPIO_PIN_8
#define ISM43362_RESET_GPIO_Port GPIOE
#define ISM43362_WAKEUP_Pin GPIO_PIN_13
#define ISM43362_WAKEUP_GPIO_Port GPIOB
#define IO_D9_Pin GPIO_PIN_15
#define IO_D9_GPIO_Port GPIOA
#define ISM43362_SPI3_NSS_Pin GPIO_PIN_0
#define ISM43362_SPI3_NSS_GPIO_Port GPIOE
#define ISM43362_DATARDY_Pin GPIO_PIN_1
#define ISM43362_DATARDY_GPIO_Port GPIOE
#define ISM43362_DATARDY_EXTI_IRQn EXTI1_IRQn

/* USER CODE BEGIN Private defines */
extern RNG_HandleTypeDef hrng;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
