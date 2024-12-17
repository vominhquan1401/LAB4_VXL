/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IN1_SEG1_Pin GPIO_PIN_1
#define IN1_SEG1_GPIO_Port GPIOA
#define IN2_SEG1_Pin GPIO_PIN_2
#define IN2_SEG1_GPIO_Port GPIOA
#define IN3_SEG1_Pin GPIO_PIN_3
#define IN3_SEG1_GPIO_Port GPIOA
#define IN4_SEG1_Pin GPIO_PIN_4
#define IN4_SEG1_GPIO_Port GPIOA
#define IN1_SEG2_Pin GPIO_PIN_6
#define IN1_SEG2_GPIO_Port GPIOA
#define IN2_SEG2_Pin GPIO_PIN_7
#define IN2_SEG2_GPIO_Port GPIOA
#define LED_RED_ABOVE_Pin GPIO_PIN_0
#define LED_RED_ABOVE_GPIO_Port GPIOB
#define LED_YELLOW_ABOVE_Pin GPIO_PIN_1
#define LED_YELLOW_ABOVE_GPIO_Port GPIOB
#define LED_GREEN_ABOVE_Pin GPIO_PIN_2
#define LED_GREEN_ABOVE_GPIO_Port GPIOB
#define BTN1_Pin GPIO_PIN_13
#define BTN1_GPIO_Port GPIOB
#define BTN2_Pin GPIO_PIN_14
#define BTN2_GPIO_Port GPIOB
#define BTN3_Pin GPIO_PIN_15
#define BTN3_GPIO_Port GPIOB
#define IN3_SEG2_Pin GPIO_PIN_8
#define IN3_SEG2_GPIO_Port GPIOA
#define IN4_SEG2_Pin GPIO_PIN_9
#define IN4_SEG2_GPIO_Port GPIOA
#define IN1_SEG3_Pin GPIO_PIN_10
#define IN1_SEG3_GPIO_Port GPIOA
#define IN2_SEG3_Pin GPIO_PIN_11
#define IN2_SEG3_GPIO_Port GPIOA
#define IN3_SEG3_Pin GPIO_PIN_12
#define IN3_SEG3_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define IN4_SEG3_Pin GPIO_PIN_15
#define IN4_SEG3_GPIO_Port GPIOA
#define LED_RED_RIGHT_Pin GPIO_PIN_3
#define LED_RED_RIGHT_GPIO_Port GPIOB
#define LED_YELLOW_RIGHT_Pin GPIO_PIN_4
#define LED_YELLOW_RIGHT_GPIO_Port GPIOB
#define LED_GREEN_RIGHT_Pin GPIO_PIN_5
#define LED_GREEN_RIGHT_GPIO_Port GPIOB
#define IN1_SEG4_Pin GPIO_PIN_6
#define IN1_SEG4_GPIO_Port GPIOB
#define IN2_SEG4_Pin GPIO_PIN_7
#define IN2_SEG4_GPIO_Port GPIOB
#define IN3_SEG4_Pin GPIO_PIN_8
#define IN3_SEG4_GPIO_Port GPIOB
#define IN4_SEG4_Pin GPIO_PIN_9
#define IN4_SEG4_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
