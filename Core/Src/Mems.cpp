/*
 * Mems.cpp
 *
 *  Created on: 5 mars 2020
 *      Author: Ross
 */

#include <board.h>
#include <sensor.h>
#include <Mems.h>
#include <LSM6DS0_ACC_GYRO_driver.h>
#include <LSM6DS0_ACC_GYRO_driver_HL.h>

//#include <stm32f4xx_hal_def.h>
//#include <stm32f4xx_hal_i2c.h>
//#include <sys/_stdint.h>

extern ACCELERO_Data_t ACCELERO_Data;
extern GYRO_Data_t GYRO_Data;

Mems::Mems()
{
	// TODO Auto-generated constructor stub

	I2C_EXPBD_Timeout = NUCLEO_I2C_EXPBD_TIMEOUT_MAX;

	/* Setup sensor handle. */
	xctx.who_am_i 		= LSM6DS0_ACC_GYRO_WHO_AM_I;
	xctx.ifType 		= 0; /* I2C interface */
	xctx.address 		= LSM6DS0_ACC_GYRO_I2C_ADDRESS_LOW; //HIGH;
	xctx.instance 		= LSM6DS0_X_0;
	xctx.isInitialized = 0;
	xctx.isEnabled     = 0;
	xctx.isCombo       = 1;
	xctx.pData         = &ACCELERO_Data; //(void *)&ACCELERO_Data[ LSM6DS0_X_0 ];
//	xctx.pVTable       = (void *)&(this->ctx); //LSM6DS0_X_Drv;
	xctx.pExtVTable    = (void *)&LSM6DS0_X_ExtDrv;

//	LSM6DS0_X_0_Data.comboData = &(this->LSM6DS0_Combo_Data);
//	ACCELERO_Data.pComponentData = (void *)&(this->LSM6DS0_X_0_Data);
	ACCELERO_Data.pExtData = 0;

	/* Setup sensor handle. */
	gctx.who_am_i 		= LSM6DS0_ACC_GYRO_WHO_AM_I;
	gctx.ifType 		= 0; /* I2C interface */
	gctx.address 		= LSM6DS0_ACC_GYRO_I2C_ADDRESS_LOW; //HIGH;
	gctx.instance 		= LSM6DS0_G_0;
	gctx.isInitialized = 0;
	gctx.isEnabled     = 0;
	gctx.isCombo       = 1;
	gctx.pData         = &GYRO_Data; //(void *)&ACCELERO_Data[ LSM6DS0_X_0 ];
//	gctx.pVTable       = (void *)&(this->ctx); //LSM6DS0_X_Drv;
	gctx.pExtVTable    = 0;

//	LSM6DS0_G_0_Data.comboData = &(this->LSM6DS0_Combo_Data);
//	GYRO_Data.pComponentData = (void *)&(this->LSM6DS0_G_0_Data);
	GYRO_Data.pExtData = 0;

	accel = new X_lsm6ds0(xctx);
	gyro = new G_lsm6ds0(gctx);
}

Mems::~Mems() {
	// TODO Auto-generated destructor stub
}

DrvStatusTypeDef Mems::Initialize_Sensors()
{
	DrvContextTypeDef Xfoo;
	DrvContextTypeDef Gfoo;

	if(accel == NULL || gyro == NULL) return COMPONENT_ERROR;

	//accel->ctx->isInitialized = 1;
	//gyro->ctx->isInitialized = 1;

	//Xfoo = *accel->ctx;
	//Gfoo = *gyro->ctx;

	//if( this->accel->Init(Xfoo) == COMPONENT_OK)
	if( this->accel->Init(*accel->ctx) == COMPONENT_OK)
	{
		//return this->gyro->Init(Gfoo);
		return this->gyro->Init(*gyro->ctx);
	}
	else return COMPONENT_ERROR;
}

DrvStatusTypeDef Mems::Enalble_Sensors()
{
	DrvContextTypeDef Xfoo;
	DrvContextTypeDef Gfoo;
	if( this->accel->Sensor_Enable(Xfoo) == COMPONENT_OK)
	{
		return this->gyro->Sensor_Enable(Gfoo);
	}
	else return COMPONENT_ERROR;
}

DrvStatusTypeDef Mems::Disable_Sensors()
{
	return COMPONENT_NOT_IMPLEMENTED;
}

SensorAxes_t Mems::ReadAccelero()
{
	uint8_t id;
	SensorAxes_t acceleration;
	uint8_t status;

	//	  BSP_ACCELERO_Get_Instance(handle, &id);

	//	  BSP_ACCELERO_IsInitialized(handle, &status);

	if (true) //this->IsAcceleroInitialized())// status == 1)
	{
		if (this->accel->Get_Axes(xctx, acceleration) == COMPONENT_ERROR) //BSP_ACCELERO_Get_Axes(handle, &acceleration) == COMPONENT_ERROR)
		{
			acceleration.AXIS_X = 0;
			acceleration.AXIS_Y = 0;
			acceleration.AXIS_Z = 0;
		}
	}
	return acceleration;
}

SensorAxes_t Mems::ReadGyro()
{
	//uint8_t id;
	SensorAxes_t angular_velocity;
	//uint8_t status;


	//BSP_GYRO_Get_Instance(handle, &id);

	//BSP_GYRO_IsInitialized(handle, &status);

	if (this->IsGyroInitialized()) //status == 1)
	{
		if (this->gyro->Get_Axes(gctx, angular_velocity) == COMPONENT_ERROR)//BSP_GYRO_Get_Axes(handle, &angular_velocity) == COMPONENT_ERROR)
		{
			angular_velocity.AXIS_X = 0;
			angular_velocity.AXIS_Y = 0;
			angular_velocity.AXIS_Z = 0;
		}
	}
	return angular_velocity;
}

bool Mems::IsAcceleroInitialized()
{
	return (bool)this->accel->ctx->isInitialized;
}

bool Mems::IsGyroInitialized()
{
	return (bool)this->gyro->ctx->isInitialized;
}

//
//DrvStatusTypeDef Mems::Sensor_IO_Init(void)
//{
//	if (HAL_I2C_GetState(&I2C_EXPBD_Handle) == HAL_I2C_STATE_RESET)
//	{
//
//		/* I2C_EXPBD peripheral configuration */
//
//#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || defined(STM32F401xE))
//		I2C_EXPBD_Handle.Init.ClockSpeed = NUCLEO_I2C_EXPBD_SPEED;
//		I2C_EXPBD_Handle.Init.DutyCycle = I2C_DUTYCYCLE_2;
//#endif
//
//#if (defined (USE_STM32L0XX_NUCLEO) || defined (USE_STM32L4XX_NUCLEO))
//		I2C_EXPBD_Handle.Init.Timing = NUCLEO_I2C_EXPBD_TIMING_400KHZ;    /* 400KHz */
//#endif
//
//		I2C_EXPBD_Handle.Init.OwnAddress1    = 0x33;
//		I2C_EXPBD_Handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
//		I2C_EXPBD_Handle.Instance            = NUCLEO_I2C_EXPBD;
//
//		/* Init the I2C */
//		I2C_EXPBD_MspInit();
//		HAL_I2C_Init(&I2C_EXPBD_Handle);
//	}
//
//	if (HAL_I2C_GetState(&I2C_EXPBD_Handle) == HAL_I2C_STATE_READY)
//	{
//		return COMPONENT_ERROR;
//	}
//	else
//	{
//		return COMPONENT_OK;
//	}
//}
//
///**
// * @brief  Configures sensor interrupts interface for LSM6DS0 sensor).
// * @param  None
// * @retval COMPONENT_OK in case of success
// * @retval COMPONENT_ERROR in case of failure
// */
//DrvStatusTypeDef Mems::LSM6DS0_Sensor_IO_ITConfig(void)
//{
//	GPIO_InitTypeDef GPIO_InitStructureInt1;
//
//	/* Enable INT1 GPIO clock */
//	LSM6DS0_INT1_GPIO_CLK_ENABLE();
//
//	/* Configure GPIO PINs to detect Interrupts */
//	GPIO_InitStructureInt1.Pin = LSM6DS0_INT1_PIN;
//	GPIO_InitStructureInt1.Mode = GPIO_MODE_IT_RISING;
//	GPIO_InitStructureInt1.Speed = GPIO_SPEED_FREQ_HIGH;
//	GPIO_InitStructureInt1.Pull  = GPIO_NOPULL;
//	HAL_GPIO_Init(LSM6DS0_INT1_GPIO_PORT, &GPIO_InitStructureInt1);
//
//	/* Enable and set EXTI Interrupt priority */
//	HAL_NVIC_SetPriority(LSM6DS0_INT1_EXTI_IRQn, 0x00, 0x00);
//	HAL_NVIC_EnableIRQ(LSM6DS0_INT1_EXTI_IRQn);
//
//	return COMPONENT_OK;
//}

///**
// * @brief  Writes a buffer to the sensor
// * @param  handle instance handle
// * @param  WriteAddr specifies the internal sensor address register to be written to
// * @param  pBuffer pointer to data buffer
// * @param  nBytesToWrite number of bytes to be written
// * @retval 0 in case of success
// * @retval 1 in case of failure
// */
//uint8_t Mems::Sensor_IO_Write(void *handle, uint8_t WriteAddr, uint8_t *pBuffer,
//		uint16_t nBytesToWrite)
//{
//	DrvContextTypeDef *ctx = (DrvContextTypeDef *)handle;
//
//	/* call I2C_EXPBD Write data bus function */
//	if (I2C_EXPBD_WriteData(ctx->address, WriteAddr, pBuffer, nBytesToWrite))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
///**
// * @brief  Reads a from the sensor to buffer
// * @param  handle instance handle
// * @param  ReadAddr specifies the internal sensor address register to be read from
// * @param  pBuffer pointer to data buffer
// * @param  nBytesToRead number of bytes to be read
// * @retval 0 in case of success
// * @retval 1 in case of failure
// */
//uint8_t Mems::Sensor_IO_Read(void *handle, uint8_t ReadAddr, uint8_t *pBuffer,
//		uint16_t nBytesToRead)
//{
//	DrvContextTypeDef *ctx = (DrvContextTypeDef *)handle;
//
//	/* call I2C_EXPBD Read data bus function */
//	if (I2C_EXPBD_ReadData(ctx->address, ReadAddr, pBuffer, nBytesToRead))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}

///**
// * @brief  Configures I2C interface.
// * @param  None
// * @retval 0 in case of success
// * @retval 1 in case of failure
// */
//uint8_t Mems::I2C_EXPBD_Init(void)
//{
//  if (HAL_I2C_GetState(&I2C_EXPBD_Handle) == HAL_I2C_STATE_RESET)
//  {
//
//    /* I2C_EXPBD peripheral configuration */
//
//#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || defined(STM32F401xE))
//    I2C_EXPBD_Handle.Init.ClockSpeed = NUCLEO_I2C_EXPBD_SPEED;
//    I2C_EXPBD_Handle.Init.DutyCycle = I2C_DUTYCYCLE_2;
//#endif
//
//#if (defined (USE_STM32L0XX_NUCLEO) || defined (USE_STM32L4XX_NUCLEO))
//    I2C_EXPBD_Handle.Init.Timing = NUCLEO_I2C_EXPBD_TIMING_400KHZ;    /* 400KHz */
//#endif
//
//    I2C_EXPBD_Handle.Init.OwnAddress1    = 0x33;
//    I2C_EXPBD_Handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
//    I2C_EXPBD_Handle.Instance            = NUCLEO_I2C_EXPBD;
//
//    /* Init the I2C */
//    I2C_EXPBD_MspInit();
//    HAL_I2C_Init(&I2C_EXPBD_Handle);
//  }
//
//  if (HAL_I2C_GetState(&I2C_EXPBD_Handle) == HAL_I2C_STATE_READY)
//  {
//    return 0;
//  }
//  else
//  {
//    return 1;
//  }
//}
///**
// * @brief I2C MSP Initialization
// * @param None
// * @retval None
// */
//void Mems::I2C_EXPBD_MspInit(void)
//{
//	GPIO_InitTypeDef  GPIO_InitStruct;
//
//	/* Enable I2C GPIO clocks */
//	NUCLEO_I2C_EXPBD_SCL_SDA_GPIO_CLK_ENABLE();
//
//	/* I2C_EXPBD SCL and SDA pins configuration -------------------------------------*/
//	GPIO_InitStruct.Pin        = NUCLEO_I2C_EXPBD_SCL_PIN | NUCLEO_I2C_EXPBD_SDA_PIN;
//	GPIO_InitStruct.Mode       = GPIO_MODE_AF_OD;
//	GPIO_InitStruct.Speed      = GPIO_SPEED_FREQ_HIGH;
//	GPIO_InitStruct.Pull       = GPIO_NOPULL;
//	GPIO_InitStruct.Alternate  = NUCLEO_I2C_EXPBD_SCL_SDA_AF;
//
//	HAL_GPIO_Init(NUCLEO_I2C_EXPBD_SCL_SDA_GPIO_PORT, &GPIO_InitStruct);
//
//	/* Enable the I2C_EXPBD peripheral clock */
//	NUCLEO_I2C_EXPBD_CLK_ENABLE();
//
//	/* Force the I2C peripheral clock reset */
//	NUCLEO_I2C_EXPBD_FORCE_RESET();
//
//	/* Release the I2C peripheral clock reset */
//	NUCLEO_I2C_EXPBD_RELEASE_RESET();
//
//	/* Enable and set I2C_EXPBD Interrupt to the highest priority */
//	HAL_NVIC_SetPriority(NUCLEO_I2C_EXPBD_EV_IRQn, 0, 0);
//	HAL_NVIC_EnableIRQ(NUCLEO_I2C_EXPBD_EV_IRQn);
//
//#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
//	/* Enable and set I2C_EXPBD Interrupt to the highest priority */
//	HAL_NVIC_SetPriority(NUCLEO_I2C_EXPBD_ER_IRQn, 0, 0);
//	HAL_NVIC_EnableIRQ(NUCLEO_I2C_EXPBD_ER_IRQn);
//#endif
//
//}

/**
 * @brief  Manages error callback by re-initializing I2C
 * @param  Addr I2C Address
 * @retval None
 */
void Mems::I2C_EXPBD_Error(uint8_t Addr)
{

	/* De-initialize the I2C comunication bus */
	HAL_I2C_DeInit(&I2C_EXPBD_Handle);

	/* Re-Initiaize the I2C comunication bus */
	I2C_EXPBD_Init();
}

///**
// * @brief  Read a register of the device through BUS
// * @param  Addr Device address on BUS
// * @param  Reg The target register address to read
// * @param  pBuffer The data to be read
// * @param  Size Number of bytes to be read
// * @retval 0 in case of success
// * @retval 1 in case of failure
// */
//uint8_t Mems::I2C_EXPBD_ReadData(uint8_t Addr, uint8_t Reg, uint8_t *pBuffer,
//		uint16_t Size)
//{
//	HAL_StatusTypeDef status = HAL_OK;
//
//	status = HAL_I2C_Mem_Read(&I2C_EXPBD_Handle, Addr, (uint16_t)Reg, I2C_MEMADD_SIZE_8BIT, pBuffer, Size, I2C_EXPBD_Timeout);
//
//	/* Check the communication status */
//	if (status != HAL_OK)
//	{
//
//		/* Execute user timeout callback */
//		I2C_EXPBD_Error(Addr);
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
///**
// * @brief  Write data to the register of the device through BUS
// * @param  Addr Device address on BUS
// * @param  Reg The target register address to be written
// * @param  pBuffer The data to be written
// * @param  Size Number of bytes to be written
// * @retval 0 in case of success
// * @retval 1 in case of failure
// */
//uint8_t Mems::I2C_EXPBD_WriteData(uint8_t Addr, uint8_t Reg, uint8_t *pBuffer,
//		uint16_t Size)
//{
//	HAL_StatusTypeDef status = HAL_OK;
//
//	status = HAL_I2C_Mem_Write(&I2C_EXPBD_Handle, Addr, (uint16_t)Reg, I2C_MEMADD_SIZE_8BIT, pBuffer, Size, I2C_EXPBD_Timeout);
//
//	/* Check the communication status */
//	if (status != HAL_OK)
//	{
//
//		/* Execute user timeout callback */
//		I2C_EXPBD_Error(Addr);
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
