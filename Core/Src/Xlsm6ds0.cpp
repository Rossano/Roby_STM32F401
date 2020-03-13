/**
  * LSM6DS0.cpp
  *
  *  Created on: Feb 27, 2020
  *  Author: Ross
  */

//#include "stm32f4xx_hal.h"
//#include <LSM6DS0_ACC_GYRO_driver_HL.h>
//#include <board.h>
#include <Xlsm6ds0.h>

extern ACCELERO_Data_t ACCELERO_Data;
extern uint8_t AccGyro_Sensor_IO_IT_Config(void);
//extern uint8_t I2C_EXPBD_Init(void);

X_lsm6ds0::X_lsm6ds0(DrvContextTypeDef &ctx):
	Accelerometer(ctx){
	// TODO Auto-generated constructor stub

	//ACCELERO_Drv_t *driver = NULL;

	  if (Sensor_IO_Init() == COMPONENT_ERROR)
	  {
	    //return COMPONENT_ERROR;
		  while(1);
	  }

//	  /* Setup sensor handle. */
//	  ctx.who_am_i 		= LSM6DS0_ACC_GYRO_WHO_AM_I;
//	  ctx.ifType 		= 0; /* I2C interface */
//	  ctx.address 		= LSM6DS0_ACC_GYRO_I2C_ADDRESS_HIGH;
//	  ctx.instance 		= LSM6DS0_X_0;
//	  ctx.isInitialized = 0;
//	  ctx.isEnabled     = 0;
//	  ctx.isCombo       = 1;
	  ctx.pData         = &ACCELERO_Data; //(void *)&ACCELERO_Data[ LSM6DS0_X_0 ];
//	  ctx.pVTable       = (void *)&(this->ctx); //LSM6DS0_X_Drv;
//	  ctx.pExtVTable    = (void *)&LSM6DS0_X_ExtDrv;
//
	  LSM6DS0_X_0_Data.comboData = &(this->LSM6DS0_Combo_Data);
	  ACCELERO_Data.pComponentData = (void *)&(this->LSM6DS0_X_0_Data);
//	  ACCELERO_Data.pExtData = 0;

//	  *handle = (void *)&(this->ctx);

//	  driver = (ACCELERO_Drv_t *)((DrvContextTypeDef *)(*handle))->pVTable;

//	  if (driver->Init == NULL)
//	  {
//	    memset((*handle), 0, sizeof(DrvContextTypeDef));
//	    *handle = NULL;
//	    return COMPONENT_ERROR;
//	  }
//
//	  if (driver->Init((DrvContextTypeDef *)(*handle)) == COMPONENT_ERROR)
//	  {
//	    memset((*handle), 0, sizeof(DrvContextTypeDef));
//	    *handle = NULL;
//	    return COMPONENT_ERROR;
//	  }

	  if(this->Init(ctx) == COMPONENT_ERROR)
	  {
		  while (1);
	  }

	  /* Configure interrupt lines for LSM6DS0 */
	  LSM6DS0_Sensor_IO_ITConfig();

//	  return COMPONENT_OK;
}

X_lsm6ds0::~X_lsm6ds0() {
	// TODO Auto-generated destructor stub
}

DrvStatusTypeDef X_lsm6ds0::Init (DrvContextTypeDef &ctx)
{
	//DrvContextTypeDef *foo;
	//foo = &ctx;
	//return LSM6DS0_X_Init(foo);
	return LSM6DS0_X_Init(&ctx);
}

DrvStatusTypeDef X_lsm6ds0::DeInit (DrvContextTypeDef &ctx)
{
	return LSM6DS0_X_DeInit(&ctx);
}

DrvStatusTypeDef X_lsm6ds0::Sensor_Enable (DrvContextTypeDef &ctx)
{
	return LSM6DS0_X_Sensor_Enable(&ctx);
}

DrvStatusTypeDef X_lsm6ds0::Sensor_Disable (DrvContextTypeDef &ctx)
{
	return LSM6DS0_X_Sensor_Disable(&ctx);
}

DrvStatusTypeDef X_lsm6ds0::Get_WhoAmI (DrvContextTypeDef &ctx, uint8_t &who)
{
	return LSM6DS0_X_Get_WhoAmI(&ctx, &who);
}

DrvStatusTypeDef X_lsm6ds0::Check_WhoAmI (DrvContextTypeDef &ctx)
{
	return LSM6DS0_X_Check_WhoAmI(&ctx);
}

DrvStatusTypeDef X_lsm6ds0::Get_Axes (DrvContextTypeDef &ctx, SensorAxes_t &axis)
{
	return LSM6DS0_X_Get_Axes(&ctx, &axis);
}

DrvStatusTypeDef X_lsm6ds0::Get_AxesRaw (DrvContextTypeDef &ctx, SensorAxesRaw_t &axis)
{
	return LSM6DS0_X_Get_AxesRaw(&ctx, &axis);
}

DrvStatusTypeDef X_lsm6ds0::Get_Sensitivity (DrvContextTypeDef &ctx, float &val)
{
	return LSM6DS0_X_Get_Sensitivity(&ctx, &val);
}

DrvStatusTypeDef X_lsm6ds0::Get_ODR (DrvContextTypeDef &ctx, float &odr)
{
	return LSM6DS0_X_Get_ODR(&ctx, &odr);
}

DrvStatusTypeDef X_lsm6ds0::Set_ODR (DrvContextTypeDef &ctx, SensorOdr_t odr)
{
	return LSM6DS0_X_Set_ODR(&ctx, odr);
}

DrvStatusTypeDef X_lsm6ds0::Set_ODR_Value (DrvContextTypeDef &ctx, float val)
{
	return LSM6DS0_X_Set_ODR_Value(&ctx, val);
}

DrvStatusTypeDef X_lsm6ds0::Get_FS (DrvContextTypeDef &ctx, float &val)
{
	return LSM6DS0_X_Get_FS(&ctx, &val);
}

DrvStatusTypeDef X_lsm6ds0::Set_FS (DrvContextTypeDef &ctx, SensorFs_t val)
{
	return LSM6DS0_X_Set_FS(&ctx, val);
}

DrvStatusTypeDef X_lsm6ds0::Set_FS_Value (DrvContextTypeDef &ctx, float val)
{
	return LSM6DS0_X_Set_FS_Value(&ctx, val);
}

//DrvStatusTypeDef LSM6DS0::Get_Axes_Status (DrvContextTypeDef &ctx, uint8_t &status)
//{
//	return LSM6DS0_X_Get_Axes_Status(&ctx, &status);
//}
//
//DrvStatusTypeDef LSM6DS0::Set_Axes_Status (DrvContextTypeDef &ctx, uint8_t &status)
//{
//	return LSM6DS0_X_Set_Axes_Status(&ctx, &status);
//}

DrvStatusTypeDef X_lsm6ds0::Read_Reg (DrvContextTypeDef &ctx, uint8_t addr, uint8_t &val)
{
	return LSM6DS0_X_Read_Reg(&ctx, addr, &val);
}

DrvStatusTypeDef X_lsm6ds0::Write_Reg (DrvContextTypeDef &ctx, uint8_t addr, uint8_t val)
{
	return LSM6DS0_X_Write_Reg(&ctx, addr, val);
}

DrvStatusTypeDef X_lsm6ds0::Get_DRDY_Status (DrvContextTypeDef &ctx, uint8_t &status)
{
	return LSM6DS0_X_Get_DRDY_Status(&ctx, &status);
}

/**
 * @brief  Configures sensor interrupts interface for LSM6DS0 sensor).
 * @param  None
 * @retval COMPONENT_OK in case of success
 * @retval COMPONENT_ERROR in case of failure
 */
DrvStatusTypeDef X_lsm6ds0::LSM6DS0_Sensor_IO_ITConfig(void)
{
//  GPIO_InitTypeDef GPIO_InitStructureInt1;
//
//  /* Enable INT1 GPIO clock */
//  LSM6DS0_INT1_GPIO_CLK_ENABLE();
//
//  /* Configure GPIO PINs to detect Interrupts */
//  GPIO_InitStructureInt1.Pin = LSM6DS0_INT1_PIN;
//  GPIO_InitStructureInt1.Mode = GPIO_MODE_IT_RISING;
//  GPIO_InitStructureInt1.Speed = GPIO_SPEED_FREQ_HIGH;
//  GPIO_InitStructureInt1.Pull  = GPIO_NOPULL;
//  HAL_GPIO_Init(LSM6DS0_INT1_GPIO_PORT, &GPIO_InitStructureInt1);
//
//  /* Enable and set EXTI Interrupt priority */
//  HAL_NVIC_SetPriority(LSM6DS0_INT1_EXTI_IRQn, 0x00, 0x00);
//  HAL_NVIC_EnableIRQ(LSM6DS0_INT1_EXTI_IRQn);
//
//  return COMPONENT_OK;
	if(AccGyro_Sensor_IO_IT_Config())
	{
		return COMPONENT_OK;
	}
	else {
		return COMPONENT_ERROR;
	}
}

/**
 * @brief  Configures sensor I2C interface.
 * @param  None
 * @retval COMPONENT_OK in case of success
 * @retval COMPONENT_ERROR in case of failure
 */
DrvStatusTypeDef X_lsm6ds0::Sensor_IO_Init(void)
{

  if ((uint8_t)I2C_EXPBD_Init())
  {
    return COMPONENT_ERROR;
  }
  else
  {
    return COMPONENT_OK;
  }
}

