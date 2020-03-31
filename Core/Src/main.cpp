/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <board.h>
#include <Mems.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#define MAX_BUF_SIZE		128
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart2;

Mems *mems;

/* USER CODE BEGIN PV */

typedef struct displayFloatToInt_s
{
  int8_t sign; /* 0 means positive, 1 means negative */
  uint32_t out_int;
  uint32_t out_dec;
} displayFloatToInt_t;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

void print_accelero(SensorAxes_t &, bool);
void print_gyro(SensorAxes_t &, bool);
void FloatToInt(float in, displayFloatToInt_t *out_value, int32_t dec_prec);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

SensorAxes_t  acc, gyro;
static char dataOut[MAX_BUF_SIZE];        /*!< DataOut Frame */
SensorAxes_t accRead, gyroRead;

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

  mems = new Mems();

  mems->Initialize_Sensors();
  mems->Enalble_Sensors();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

	  accRead = mems->ReadAccelero();
	  gyroRead = mems->ReadGyro();

	  print_accelero(accRead, false);
	  print_gyro(gyroRead, false);

	  HAL_Delay(1000);

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PB4 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void print_accelero(SensorAxes_t &acceleration, bool verbose)
{
	uint8_t who_am_i;
	float odr;
	float fullScale;

	snprintf(dataOut, MAX_BUF_SIZE, "\r\nACC_X: %d, ACC_Y: %d, ACC_Z: %d\r\n",
			(int)acceleration.AXIS_X, (int)acceleration.AXIS_Y, (int)acceleration.AXIS_Z);

	HAL_UART_Transmit(&UartHandle, (uint8_t *)dataOut, strlen(dataOut), 5000);

	if (verbose == 1)
	{
		if (mems->accel->Get_WhoAmI(*mems->accel->ctx, who_am_i) == COMPONENT_ERROR) //BSP_ACCELERO_Get_WhoAmI(handle, &who_am_i) == COMPONENT_ERROR)
		{
			snprintf(dataOut, MAX_BUF_SIZE, "WHO AM I : ERROR\r\n");
		}
		else
		{
			snprintf(dataOut, MAX_BUF_SIZE, "WHO AM I address: 0x%02X\r\n", who_am_i);
		}

		HAL_UART_Transmit(&UartHandle, (uint8_t *)dataOut, strlen(dataOut), 5000);

		if (mems->accel->Get_ODR(*mems->accel->ctx, odr) == COMPONENT_ERROR)
		{
			snprintf(dataOut, MAX_BUF_SIZE, "ODR: ERROR\r\n");
		}
		else
		{
			displayFloatToInt_t out_value;
			FloatToInt(odr, &out_value, 3);
			snprintf(dataOut, MAX_BUF_SIZE, "ODR: %c%d.%03d Hz\r\n", ((out_value.sign) ? '-' : '+'),
					(int)out_value.out_int, (int)out_value.out_dec);
		}

		HAL_UART_Transmit(&UartHandle, (uint8_t *)dataOut, strlen(dataOut), 5000);

		if (mems->accel->Get_FS(*mems->accel->ctx, fullScale) == COMPONENT_ERROR)
		{
			snprintf(dataOut, MAX_BUF_SIZE, "FS: ERROR\r\n");
		}
		else
		{
			displayFloatToInt_t out_value;
			FloatToInt(fullScale, &out_value, 3);
			snprintf(dataOut, MAX_BUF_SIZE, "FS: %c%d.%03d g\r\n", ((out_value.sign) ? '-' : '+'),
					(int)out_value.out_int, (int)out_value.out_dec);
		}

		HAL_UART_Transmit(&UartHandle, (uint8_t *)dataOut, strlen(dataOut), 5000);
	}
}

void print_gyro(SensorAxes_t &gyro, bool verbose)
{
	uint8_t who_am_i;
	float odr;
	float fullScale;
	SensorAxes_t angular_velocity;

	uint8_t status;


	snprintf(dataOut, MAX_BUF_SIZE, "\r\nGYR_X: %d, GYR_Y: %d, GYR_Z: %d\r\n",
			(int)angular_velocity.AXIS_X, (int)angular_velocity.AXIS_Y, (int)angular_velocity.AXIS_Z);

	HAL_UART_Transmit(&UartHandle, (uint8_t *)dataOut, strlen(dataOut), 5000);

	if (verbose == 1)
	{
		if (mems->gyro->Get_WhoAmI(*mems->gyro->ctx, who_am_i) == COMPONENT_ERROR)//BSP_GYRO_Get_WhoAmI(handle, &who_am_i) == COMPONENT_ERROR)
		{
			snprintf(dataOut, MAX_BUF_SIZE, "WHO AM I address: ERROR\r\n");
		}
		else
		{
			snprintf(dataOut, MAX_BUF_SIZE, "WHO AM I address: 0x%02X\r\n", who_am_i);
		}

		HAL_UART_Transmit(&UartHandle, (uint8_t *)dataOut, strlen(dataOut), 5000);

		if (mems->gyro->Get_ODR(*mems->gyro->ctx, odr) == COMPONENT_ERROR)//BSP_GYRO_Get_ODR(handle, &odr) == COMPONENT_ERROR)
		{
			snprintf(dataOut, MAX_BUF_SIZE, "ODR: ERROR\r\n");
		}
		else
		{
			displayFloatToInt_t out_value;
			FloatToInt(odr, &out_value, 3);
			snprintf(dataOut, MAX_BUF_SIZE, "ODR: %c%d.%03d Hz\r\n", ((out_value.sign) ? '-' : '+'),
					(int)out_value.out_int, (int)out_value.out_dec);
		}

		HAL_UART_Transmit(&UartHandle, (uint8_t *)dataOut, strlen(dataOut), 5000);

		if (mems->gyro->Get_FS(*mems->gyro->ctx, fullScale) == COMPONENT_ERROR) //BSP_GYRO_Get_FS(handle, &fullScale) == COMPONENT_ERROR)
		{
			snprintf(dataOut, MAX_BUF_SIZE, "FS: ERROR\r\n");
		}
		else
		{
			displayFloatToInt_t out_value;
			FloatToInt(fullScale, &out_value, 3);
			snprintf(dataOut, MAX_BUF_SIZE, "FS: %c%d.%03d g\r\n", ((out_value.sign) ? '-' : '+'),
					(int)out_value.out_int, (int)out_value.out_dec);
		}

		HAL_UART_Transmit(&UartHandle, (uint8_t *)dataOut, strlen(dataOut), 5000);
	}
}

/**
 * @brief  Splits a float into two integer values.
 * @param  in the float value as input
 * @param  out_value the pointer to the sign, integer and decimal parts as output
 * @param  dec_prec the decimal precision to be used
 * @retval None
 */
void FloatToInt(float in, displayFloatToInt_t *out_value, int32_t dec_prec)
{
  if (in >= 0.0f)
  {
    out_value->sign = 0;
  }
  else
  {
    out_value->sign = 1;
    in = -in;
  }

  out_value->out_int = (int32_t)in;
  in = in - (float)(out_value->out_int);
  out_value->out_dec = (int32_t)trunc(in * pow(10, dec_prec));
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
