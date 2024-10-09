/**
 ******************************************************************************
 * @file    main.h
 * @author  MCD Application Team
 * @brief   Header for main.c module for Cortex-M7.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>

#include "fp_vision_display.h"
#include "fp_vision_app.h"

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);


/*Defines related to cache settings*/
#define EXT_SDRAM_CACHE_ENABLED 1
#define OSC32_OUT_Pin GPIO_PIN_15
#define OSC32_OUT_GPIO_Port GPIOC
#define OSC32_IN_Pin GPIO_PIN_14
#define OSC32_IN_GPIO_Port GPIOC
#define CEC_CK_MCO1_Pin GPIO_PIN_8
#define CEC_CK_MCO1_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_12
#define LED1_GPIO_Port GPIOI
#define OSC_OUT_Pin GPIO_PIN_1
#define OSC_OUT_GPIO_Port GPIOH
#define OSC_IN_Pin GPIO_PIN_0
#define OSC_IN_GPIO_Port GPIOH
#define PMOD_14_ARD_D3_Pin GPIO_PIN_8
#define PMOD_14_ARD_D3_GPIO_Port GPIOF
#define IR1_ARD_D7_Pin GPIO_PIN_0
#define IR1_ARD_D7_GPIO_Port GPIOJ
#define ARD_D6_Pin GPIO_PIN_7
#define ARD_D6_GPIO_Port GPIOJ
#define ARD_D9_Pin GPIO_PIN_6
#define ARD_D9_GPIO_Port GPIOJ
#define IR4_ARD_D5_Pin GPIO_PIN_6
#define IR4_ARD_D5_GPIO_Port GPIOA
#define IR2_ARD_D8_Pin GPIO_PIN_5
#define IR2_ARD_D8_GPIO_Port GPIOJ
#define RELAY_ARD_D2_Pin GPIO_PIN_3
#define RELAY_ARD_D2_GPIO_Port GPIOJ
#define IR3_ARD_D4_Pin GPIO_PIN_4
#define IR3_ARD_D4_GPIO_Port GPIOJ


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

