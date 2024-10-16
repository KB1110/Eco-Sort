/**
 ******************************************************************************
 * @file    main.c
 * @author  MCD Application Team
 * @brief   This is the main program for the application running on Cortex-M7
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32h7xx_hal_tim.h"

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void CPU_CACHE_Enable(void);
static void MPU_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM8_Init(void);
static void MX_TIM13_Init(void);

TIM_HandleTypeDef htim8;
TIM_HandleTypeDef htim13;
uint8_t waste;

/**
* @brief  Application entry point
* @param  None
* @retval None
*/
int main(void)
{
  /* System Init, System clock, voltage scaling and L1-Cache configuration are done by CPU1 (Cortex-M7)
  in the meantime Domain D2 is put in STOP mode(Cortex-M4 in deep-sleep) */
  
  /* Configure the MPU attributes */
  MPU_Config();
  
  /* Enable the CPU Cache */
  CPU_CACHE_Enable();
  
  HAL_Init();
  
  /* Configure the system clock to 400 MHz */
  SystemClock_Config();
  
  /*Enable CRC HW IP block*/
  __HAL_RCC_CRC_CLK_ENABLE();
  
  MX_GPIO_Init();
  MX_TIM8_Init();
  MX_TIM13_Init();

  HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim13, TIM_CHANNEL_1);

  /*APP init*/
  APP_Init(&App_Context);
  
  /*TEST init*/
  TEST_Init(App_Context.Test_ContextPtr);
  
  /*UTILS init */
  UTILS_Init(App_Context.Utils_ContextPtr);
  
  /*DISPLAY init*/
  DISPLAY_Init(App_Context.Display_ContextPtr);
  
  /*AI init*/
  AI_Init(App_Context.Ai_ContextPtr);
  
  /*Display Welcome Screen*/
  int is_menu = DISPLAY_WelcomeScreen(App_Context.Display_ContextPtr);
  
//  if(HAL_GPIO_ReadPin(GPIOJ, GPIO_PIN_0) == GPIO_PIN_RESET) {
//  		  HAL_GPIO_WritePin(GPIOJ, GPIO_PIN_3, GPIO_PIN_SET);
//
//  		  while(HAL_GPIO_ReadPin(GPIOJ, GPIO_PIN_5) == GPIO_PIN_SET);
//
//  		  HAL_Delay(500);
//
//  		  HAL_GPIO_WritePin(GPIOJ, GPIO_PIN_3, GPIO_PIN_RESET);
//
//  		  HAL_Delay(5000);
//
//  		  for (int i = 0; i < 500; i++) {
//  			  if ((is_menu != 0) || (App_Context.Test_ContextPtr->UartContext.uart_cmd_ongoing == 1))
//				  {
//					/* Run main menu */
//					TEST_MainMenu(App_Context.Test_ContextPtr);
//				  }
//
//				  if(App_Context.Operating_Mode == NOMINAL || App_Context.Operating_Mode == CAPTURE || (App_Context.Operating_Mode == DUMP && App_Context.Test_ContextPtr->DumpContext.Dump_FrameSource == CAMERA_LIVE))
//				  {
//					/*CAMERA init*/
//					CAMERA_Init(App_Context.Camera_ContextPtr);
//				  }
//
//				  while(App_Context.run_loop)
//				  {
//					/* Check joystick input to adjust camera's brightness / contrast */
//					UTILS_Joystick_Check(App_Context.Utils_ContextPtr);
//
//					/*Check UART status for any received command from Host PC*/
//					TEST_CmdIf_Check(App_Context.Test_ContextPtr);
//
//				#if MEMORY_SCHEME == FULL_INTERNAL_MEM_OPT
//					/*****************************************************************************/
//					/**************Launch the camera acquisition of the subsequent frame *********/
//					/*****************************************************************************/
//					APP_StartNewFrameAcquisition(&App_Context);
//
//					/****************************************************************************/
//					/**************Wait for the next frame to be ready for processing************/
//					/****************************************************************************/
//					APP_GetNextReadyFrame(&App_Context);
//				#endif
//
//				#if MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
//					/**************************************************************************/
//					/**************Wait for the next frame to be ready for processing**********/
//					/**************************************************************************/
//					APP_GetNextReadyFrame(&App_Context);
//
//					/**************************************************************************************************************************/
//					/**************Launch the camera acquisition of the subsequent frame in parallel of the current frame processing***********/
//					/**************************************************************************************************************************/
//					APP_StartNewFrameAcquisition(&App_Context);
//				#endif
//
//					/**********************************************************************/
//					/************************Run Frame Preprocessing***********************/
//					/**********************************************************************/
//					APP_FramePreprocess(&App_Context);
//
//					/********************************************************************/
//					/*************************Run NN Inference***************************/
//					/********************************************************************/
//					APP_NetworkInference(&App_Context);
//
//					/*****************************************************/
//					/**************Run post process operations************/
//					/*****************************************************/
//					waste = APP_Postprocess(&App_Context);
//				  }
//
//					AI_Deinit();
//					App_Context.run_loop = 1;
//					UTIL_LCD_SetFont(&Font24);
//					goto RESTART;
//  		  }
//  		RESTART:
//  			  if ((is_menu != 0) || (App_Context.Test_ContextPtr->UartContext.uart_cmd_ongoing == 1))
//  			  {
//  				/* Run main menu */
//  				TEST_MainMenu(App_Context.Test_ContextPtr);
//  			  }
//
//  			  if(App_Context.Operating_Mode == NOMINAL || App_Context.Operating_Mode == CAPTURE || (App_Context.Operating_Mode == DUMP && App_Context.Test_ContextPtr->DumpContext.Dump_FrameSource == CAMERA_LIVE))
//  			  {
//  				/*CAMERA init*/
//  				CAMERA_Init(App_Context.Camera_ContextPtr);
//  			  }
//
//  			  while(App_Context.run_loop)
//  			  {
//  				/* Check joystick input to adjust camera's brightness / contrast */
//  				UTILS_Joystick_Check(App_Context.Utils_ContextPtr);
//
//  				/*Check UART status for any received command from Host PC*/
//  				TEST_CmdIf_Check(App_Context.Test_ContextPtr);
//
//  			#if MEMORY_SCHEME == FULL_INTERNAL_MEM_OPT
//  				/*****************************************************************************/
//  				/**************Launch the camera acquisition of the subsequent frame *********/
//  				/*****************************************************************************/
//  				APP_StartNewFrameAcquisition(&App_Context);
//
//  				/****************************************************************************/
//  				/**************Wait for the next frame to be ready for processing************/
//  				/****************************************************************************/
//  				APP_GetNextReadyFrame(&App_Context);
//  			#endif
//
//  			#if MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
//  				/**************************************************************************/
//  				/**************Wait for the next frame to be ready for processing**********/
//  				/**************************************************************************/
//  				APP_GetNextReadyFrame(&App_Context);
//
//  				/**************************************************************************************************************************/
//  				/**************Launch the camera acquisition of the subsequent frame in parallel of the current frame processing***********/
//  				/**************************************************************************************************************************/
//  				APP_StartNewFrameAcquisition(&App_Context);
//  			#endif
//
//  				/**********************************************************************/
//  				/************************Run Frame Preprocessing***********************/
//  				/**********************************************************************/
//  				APP_FramePreprocess(&App_Context);
//
//  				/********************************************************************/
//  				/*************************Run NN Inference***************************/
//  				/********************************************************************/
//  				APP_NetworkInference(&App_Context);
//
//  				/*****************************************************/
//  				/**************Run post process operations************/
//  				/*****************************************************/
//  				waste = APP_Postprocess(&App_Context);
//
//  			  }
//
//  			  if(1)
//  			  {
//  				AI_Deinit();
//  				App_Context.run_loop = 1;
//  				UTIL_LCD_SetFont(&Font24);
//  				goto RESTART;
//  			  }
//  			  else
//  			  {
//  				;
//  			  }

//  			HAL_GPIO_WritePin(GPIOJ, GPIO_PIN_3, GPIO_PIN_SET);
//
//  //		  1 - E-Waste
//  //		  2 - Metal
//  //		  3 - Paper
//  //		  4 - Plastic
//
//  //		  E-Waste
//  		  if (waste == 1) {
//  			  TIM8->CCR2 = 500;
//  			  TIM13->CCR1 = 2500;
//  			  while(HAL_GPIO_ReadPin(GPIOJ, GPIO_PIN_4) == GPIO_PIN_SET);
//
//  			  HAL_Delay(500);
//
//  			  TIM8->CCR2 = 2500;
//  		  }
//
//  //		  Metal
//  		  else if (waste == 2) {
//  			  TIM8->CCR2 = 2500;
//  			  TIM13->CCR1 = 2500;
//  			  while(HAL_GPIO_ReadPin(IR3_ARD_D4_GPIO_Port, IR3_ARD_D4_Pin) == GPIO_PIN_SET);
//
//  			  HAL_Delay(1000);
//
//  			  TIM8->CCR2 = 500;
//  		  }
//
//  //		  Paper
//  		  else if (waste == 3) {
//  			  TIM8->CCR2 = 2500;
//  			  TIM13->CCR1 = 2500;
//  			  while(HAL_GPIO_ReadPin(IR4_ARD_D5_GPIO_Port, IR4_ARD_D5_Pin) == GPIO_PIN_SET);
//
//  			  HAL_Delay(1000);
//
//  			  TIM13->CCR1 = 500;
//  		  }
//
//  //		  Plastic
//  		  else if (waste == 4) {
//  			  TIM8->CCR2 = 2500;
//  			  TIM13->CCR1 = 500;
//  			  while(HAL_GPIO_ReadPin(IR4_ARD_D5_GPIO_Port, IR4_ARD_D5_Pin) == GPIO_PIN_SET);
//
//  			  HAL_Delay(1000);
//
//  			  TIM13->CCR1 = 2500;
//  		  }

RESTART:
	  if ((is_menu != 0) || (App_Context.Test_ContextPtr->UartContext.uart_cmd_ongoing == 1))
	  {
		/* Run main menu */
		TEST_MainMenu(App_Context.Test_ContextPtr);
	  }

	  if(App_Context.Operating_Mode == NOMINAL || App_Context.Operating_Mode == CAPTURE || (App_Context.Operating_Mode == DUMP && App_Context.Test_ContextPtr->DumpContext.Dump_FrameSource == CAMERA_LIVE))
	  {
		/*CAMERA init*/
		CAMERA_Init(App_Context.Camera_ContextPtr);
	  }

	  while(App_Context.run_loop)
	  {
		/* Check joystick input to adjust camera's brightness / contrast */
		UTILS_Joystick_Check(App_Context.Utils_ContextPtr);

		/*Check UART status for any received command from Host PC*/
		TEST_CmdIf_Check(App_Context.Test_ContextPtr);

	#if MEMORY_SCHEME == FULL_INTERNAL_MEM_OPT
		/*****************************************************************************/
		/**************Launch the camera acquisition of the subsequent frame *********/
		/*****************************************************************************/
		APP_StartNewFrameAcquisition(&App_Context);

		/****************************************************************************/
		/**************Wait for the next frame to be ready for processing************/
		/****************************************************************************/
		APP_GetNextReadyFrame(&App_Context);
	#endif

	#if MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
		/**************************************************************************/
		/**************Wait for the next frame to be ready for processing**********/
		/**************************************************************************/
		APP_GetNextReadyFrame(&App_Context);

		/**************************************************************************************************************************/
		/**************Launch the camera acquisition of the subsequent frame in parallel of the current frame processing***********/
		/**************************************************************************************************************************/
		APP_StartNewFrameAcquisition(&App_Context);
	#endif

		/**********************************************************************/
		/************************Run Frame Preprocessing***********************/
		/**********************************************************************/
		APP_FramePreprocess(&App_Context);

		/********************************************************************/
		/*************************Run NN Inference***************************/
		/********************************************************************/
		APP_NetworkInference(&App_Context);

		/*****************************************************/
		/**************Run post process operations************/
		/*****************************************************/
		waste = APP_Postprocess(&App_Context);

	  }

	  if(1)
	  {
		AI_Deinit();
		App_Context.run_loop = 1;
		UTIL_LCD_SetFont(&Font24);
		goto RESTART;
	  }
	  else
	  {
		;
	  }
  
  /* End of program */
}

/* Private functions ---------------------------------------------------------*/
/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 400000000 (Cortex-M7 CPU Clock)
 *            HCLK(Hz)                       = 200000000 (Cortex-M4 CPU, Bus matrix Clocks)
 *            AHB Prescaler                  = 2
 *            D1 APB3 Prescaler              = 2 (APB3 Clock  100MHz)
 *            D2 APB1 Prescaler              = 2 (APB1 Clock  100MHz)
 *            D2 APB2 Prescaler              = 2 (APB2 Clock  100MHz)
 *            D3 APB4 Prescaler              = 2 (APB4 Clock  100MHz)
 *            HSE Frequency(Hz)              = 25000000
 *            PLL_M                          = 5
 *            PLL_N                          = 160
 *            PLL_P                          = 2
 *            PLL_Q                          = 4
 *            PLL_R                          = 2
 *            VDD(V)                         = 3.3
 *            Flash Latency(WS)              = 4
 * @param  None
 * @retval None
 */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  HAL_StatusTypeDef ret = HAL_OK;

  /*!< Supply configuration update enable */
  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

  /* The voltage scaling allows optimizing the power consumption when the device is
  clocked below the maximum system frequency, to update the voltage scaling value
  regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY))
  {
  }

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.CSIState = RCC_CSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;

  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 160;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;

  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if (ret != HAL_OK)
  {
    Error_Handler();
  }

  /* Select PLL as system clock source and configure  bus clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_D1PCLK1 |
                                 RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_D3PCLK1);

  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;
  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);
  if (ret != HAL_OK)
  {
    Error_Handler();
  }

  /*
  Note : The activation of the I/O Compensation Cell is recommended with communication  interfaces
  (GPIO, SPI, FMC, QSPI ...)  when  operating at  high frequencies(please refer to product datasheet)
  The I/O Compensation Cell activation  procedure requires :
  - The activation of the CSI clock
  - The activation of the SYSCFG clock
  - Enabling the I/O Compensation Cell : setting bit[0] of register SYSCFG_CCCSR
  */

  /*activate CSI clock mandatory for I/O Compensation Cell*/
  __HAL_RCC_CSI_ENABLE();

  /* Enable SYSCFG clock mandatory for I/O Compensation Cell */
  __HAL_RCC_SYSCFG_CLK_ENABLE();

  /* Enables the I/O Compensation Cell */
  HAL_EnableCompensationCell();
}

/**
 * @brief  CPU L1-Cache enable.
 * @param  None
 * @retval None
 */
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

/**
 * @brief  Configure the MPU attributes for the device's memories.
 * @param  None
 * @retval None
 */
static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;

  /* Disable the MPU */
  HAL_MPU_Disable();

#if EXT_SDRAM_CACHE_ENABLED == 0
  /*
  To make the memory region non cacheable and avoid any cache coherency maintenance:
  - either: MPU_ACCESS_NOT_BUFFERABLE + MPU_ACCESS_NOT_CACHEABLE
  - or: MPU_ACCESS_SHAREABLE => the S field is equivalent to non-cacheable memory
  */
  /* External SDRAM memory: LCD Frame buffer => non-cacheable */
  /*TEX=001, C=0, B=0*/
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0xD0000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_32MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
#elif EXT_SDRAM_CACHE_ENABLED == 1
  /* External SDRAM memory: all as WBWA */
  /*TEX=001, C=1, B=1*/
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0xD0000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_32MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1; 
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE; 
#elif EXT_SDRAM_CACHE_ENABLED == 2
  /*External SDRAM memory: all as Write Thru:*/
  /*TEX=000, C=1, B=0*/
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0xD0000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_32MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0; 
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
#else
#error Please check definition of EXT_SDRAM_CACHE_ENABLED define
#endif

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /*Internal SRAM memory: cache policies are WBWA (Write Back and Write Allocate) by default */

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

static void MX_TIM8_Init(void)
{

  /* USER CODE BEGIN TIM8_Init 0 */

  /* USER CODE END TIM8_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM8_Init 1 */

  /* USER CODE END TIM8_Init 1 */
  htim8.Instance = TIM8;
  htim8.Init.Prescaler = 200 - 1;
  htim8.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim8.Init.Period = 4000 - 1;
  htim8.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim8.Init.RepetitionCounter = 0;
  htim8.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim8) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim8, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
  sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
  sBreakDeadTimeConfig.Break2Filter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim8, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM8_Init 2 */

  /* USER CODE END TIM8_Init 2 */
  HAL_TIM_MspPostInit(&htim8);

}

/**
  * @brief TIM13 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM13_Init(void)
{

  /* USER CODE BEGIN TIM13_Init 0 */

  /* USER CODE END TIM13_Init 0 */

  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM13_Init 1 */

  /* USER CODE END TIM13_Init 1 */
  htim13.Instance = TIM13;
  htim13.Init.Prescaler = 200 - 1;
  htim13.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim13.Init.Period = 4000 - 1;
  htim13.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim13.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim13) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim13) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim13, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM13_Init 2 */

  /* USER CODE END TIM13_Init 2 */
  HAL_TIM_MspPostInit(&htim13);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOJ_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(RELAY_ARD_D2_GPIO_Port, RELAY_ARD_D2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : CEC_CK_MCO1_Pin */
  GPIO_InitStruct.Pin = CEC_CK_MCO1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
  HAL_GPIO_Init(CEC_CK_MCO1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED1_Pin */
  GPIO_InitStruct.Pin = LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : IR1_ARD_D7_Pin */
  GPIO_InitStruct.Pin = IR1_ARD_D7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(IR1_ARD_D7_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : IR4_ARD_D5_Pin */
  GPIO_InitStruct.Pin = IR4_ARD_D5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(IR4_ARD_D5_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : IR2_ARD_D8_Pin IR3_ARD_D4_Pin */
  GPIO_InitStruct.Pin = IR2_ARD_D8_Pin|IR3_ARD_D4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

  /*Configure GPIO pin : RELAY_ARD_D2_Pin */
  GPIO_InitStruct.Pin = RELAY_ARD_D2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(RELAY_ARD_D2_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}



/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
void Error_Handler(void)
{
  BSP_LED_Off(LED_GREEN);
  BSP_LED_Off(LED_ORANGE);
  BSP_LED_Off(LED_RED);
  BSP_LED_Off(LED_BLUE);

  /* Turn LED RED on */
  BSP_LED_On(LED_RED);
  while (1)
  {
  }
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
  ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */

