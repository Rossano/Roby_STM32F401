/*
 * board.c
 *
 *  Created on: 8 mars 2020
 *      Author: Ross
 */

#include <board.h>

/**
 * @brief I2C MSP Initialization
 * @param None
 * @retval None
 */
void I2C_EXPBD_MspInit(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  /* Enable I2C GPIO clocks */
  NUCLEO_I2C_EXPBD_SCL_SDA_GPIO_CLK_ENABLE();

  /* I2C_EXPBD SCL and SDA pins configuration -------------------------------------*/
  GPIO_InitStruct.Pin        = NUCLEO_I2C_EXPBD_SCL_PIN | NUCLEO_I2C_EXPBD_SDA_PIN;
  GPIO_InitStruct.Mode       = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Speed      = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pull       = GPIO_NOPULL;
  GPIO_InitStruct.Alternate  = NUCLEO_I2C_EXPBD_SCL_SDA_AF;

  HAL_GPIO_Init(NUCLEO_I2C_EXPBD_SCL_SDA_GPIO_PORT, &GPIO_InitStruct);

  /* Enable the I2C_EXPBD peripheral clock */
  NUCLEO_I2C_EXPBD_CLK_ENABLE();

  /* Force the I2C peripheral clock reset */
  NUCLEO_I2C_EXPBD_FORCE_RESET();

  /* Release the I2C peripheral clock reset */
  NUCLEO_I2C_EXPBD_RELEASE_RESET();

  /* Enable and set I2C_EXPBD Interrupt to the highest priority */
  HAL_NVIC_SetPriority(NUCLEO_I2C_EXPBD_EV_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(NUCLEO_I2C_EXPBD_EV_IRQn);

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
  /* Enable and set I2C_EXPBD Interrupt to the highest priority */
  HAL_NVIC_SetPriority(NUCLEO_I2C_EXPBD_ER_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(NUCLEO_I2C_EXPBD_ER_IRQn);
#endif

}

/**
 * @brief  Configures I2C interface.
 * @param  None
 * @retval 0 in case of success
 * @retval 1 in case of failure
 */
uint8_t I2C_EXPBD_Init(void)
{
  if (HAL_I2C_GetState(&I2C_EXPBD_Handle) == HAL_I2C_STATE_RESET)
  {

    /* I2C_EXPBD peripheral configuration */

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || defined(STM32F401xE))
    I2C_EXPBD_Handle.Init.ClockSpeed = NUCLEO_I2C_EXPBD_SPEED;
    I2C_EXPBD_Handle.Init.DutyCycle = I2C_DUTYCYCLE_2;
#endif

#if (defined (USE_STM32L0XX_NUCLEO) || defined (USE_STM32L4XX_NUCLEO))
    I2C_EXPBD_Handle.Init.Timing = NUCLEO_I2C_EXPBD_TIMING_400KHZ;    /* 400KHz */
#endif

    I2C_EXPBD_Handle.Init.OwnAddress1    = 0x33;
    I2C_EXPBD_Handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    I2C_EXPBD_Handle.Instance            = NUCLEO_I2C_EXPBD;

    /* Init the I2C */
    I2C_EXPBD_MspInit();
    HAL_I2C_Init(&I2C_EXPBD_Handle);
  }

  if (HAL_I2C_GetState(&I2C_EXPBD_Handle) == HAL_I2C_STATE_READY)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

/**
 * @brief  Configures sensor interrupts interface for LSM6DS0 sensor).
 * @param  None
 * @retval COMPONENT_OK in case of success
 * @retval COMPONENT_ERROR in case of failure
 */
uint8_t AccGyro_Sensor_IO_ITConfig(void)
{
  GPIO_InitTypeDef GPIO_InitStructureInt1;

  /* Enable INT1 GPIO clock */
  LSM6DS0_INT1_GPIO_CLK_ENABLE();

  /* Configure GPIO PINs to detect Interrupts */
  GPIO_InitStructureInt1.Pin = LSM6DS0_INT1_PIN;
  GPIO_InitStructureInt1.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStructureInt1.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStructureInt1.Pull  = GPIO_NOPULL;
  HAL_GPIO_Init(LSM6DS0_INT1_GPIO_PORT, &GPIO_InitStructureInt1);

  /* Enable and set EXTI Interrupt priority */
  HAL_NVIC_SetPriority(LSM6DS0_INT1_EXTI_IRQn, 0x00, 0x00);
  HAL_NVIC_EnableIRQ(LSM6DS0_INT1_EXTI_IRQn);

  return 0;
}


