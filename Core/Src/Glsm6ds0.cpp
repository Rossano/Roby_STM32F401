/**
 * LSM6DS0.cpp
 *
 *  Created on: Feb 27, 2020
 *  Author: Ross
 */

//#include <LSM6DS0_ACC_GYRO_driver_HL.h>
#include <Glsm6ds0.h>

GYRO_Data_t GYRO_Data;

G_lsm6ds0::G_lsm6ds0(DrvContextTypeDef &ctx):
			Gyroscope(ctx){
	// TODO Auto-generated constructor stub
	ctx.who_am_i = IKS01A1_LSM6DS0_WHO_AM_I;

	if (Sensor_IO_Init() == COMPONENT_ERROR)
	{
		//return COMPONENT_ERROR;
//		while(1);
	}

//	/* Setup sensor handle. */
//	ctx.who_am_i 		= LSM6DS0_ACC_GYRO_WHO_AM_I;
//	ctx.ifType 		= 0; /* I2C interface */
//	ctx.address 		= LSM6DS0_ACC_GYRO_I2C_ADDRESS_HIGH;
//	ctx.instance 		= LSM6DS0_G_0;
//	ctx.isInitialized = 0;
//	ctx.isEnabled     = 0;
//	ctx.isCombo       = 1;
//	ctx.pData         = &GYRO_Data; //(void *)&ACCELERO_Data[ LSM6DS0_X_0 ];
	ctx.pVTable       = (void *)&(this->ctx); //LSM6DS0_X_Drv;
//	ctx.pExtVTable    = 0;
//
	LSM6DS0_G_0_Data.comboData = &(this->LSM6DS0_Combo_Data);
	GYRO_Data.pComponentData = (void *)&(this->LSM6DS0_G_0_Data);
//	GYRO_Data.pExtData = 0;

	if(this->Init(ctx) == COMPONENT_ERROR)
	{
//		while (1);
	}
}

G_lsm6ds0::~G_lsm6ds0() {
	// TODO Auto-generated destructor stub
}

DrvStatusTypeDef G_lsm6ds0::Init (DrvContextTypeDef &ctx)
{
	//	DrvContextTypeDef *foo;
	//	foo = &ctx;
	return LSM6DS0_G_Init(&ctx);
}

DrvStatusTypeDef G_lsm6ds0::DeInit (DrvContextTypeDef &ctx)
{
	return LSM6DS0_G_DeInit(&ctx);
}

DrvStatusTypeDef G_lsm6ds0::Sensor_Enable (DrvContextTypeDef &ctx)
{
	return LSM6DS0_G_Sensor_Enable(&ctx);
}

DrvStatusTypeDef G_lsm6ds0::Sensor_Disable (DrvContextTypeDef &ctx)
{
	return LSM6DS0_G_Sensor_Disable(&ctx);
}

DrvStatusTypeDef G_lsm6ds0::Get_WhoAmI (DrvContextTypeDef &ctx, uint8_t &who)
{
	return LSM6DS0_G_Get_WhoAmI(&ctx, &who);
}

DrvStatusTypeDef G_lsm6ds0::Check_WhoAmI (DrvContextTypeDef &ctx)
{
	return LSM6DS0_G_Check_WhoAmI(&ctx);
}

DrvStatusTypeDef G_lsm6ds0::Get_Axes (DrvContextTypeDef &ctx, SensorAxes_t &axis)
{
	return LSM6DS0_G_Get_Axes(&ctx, &axis);
}

DrvStatusTypeDef G_lsm6ds0::Get_AxesRaw (DrvContextTypeDef &ctx, SensorAxesRaw_t &axis)
{
	return LSM6DS0_G_Get_AxesRaw(&ctx, &axis);
}

DrvStatusTypeDef G_lsm6ds0::Get_Sensitivity (DrvContextTypeDef &ctx, float &val)
{
	return LSM6DS0_G_Get_Sensitivity(&ctx, &val);
}

DrvStatusTypeDef G_lsm6ds0::Get_ODR (DrvContextTypeDef &ctx, float &odr)
{
	return LSM6DS0_G_Get_ODR(&ctx, &odr);
}

DrvStatusTypeDef G_lsm6ds0::Set_ODR (DrvContextTypeDef &ctx, SensorOdr_t odr)
{
	return LSM6DS0_G_Set_ODR(&ctx, odr);
}

DrvStatusTypeDef G_lsm6ds0::Set_ODR_Value (DrvContextTypeDef &ctx, float val)
{
	return LSM6DS0_G_Set_ODR_Value(&ctx, val);
}

DrvStatusTypeDef G_lsm6ds0::Get_FS (DrvContextTypeDef &ctx, float &val)
{
	return LSM6DS0_G_Get_FS(&ctx, &val);
}

DrvStatusTypeDef G_lsm6ds0::Set_FS (DrvContextTypeDef &ctx, SensorFs_t val)
{
	return LSM6DS0_G_Set_FS(&ctx, val);
}

DrvStatusTypeDef G_lsm6ds0::Set_FS_Value (DrvContextTypeDef &ctx, float val)
{
	return LSM6DS0_G_Set_FS_Value(&ctx, val);
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

DrvStatusTypeDef G_lsm6ds0::Read_Reg (DrvContextTypeDef &ctx, uint8_t addr, uint8_t &val)
{
	return LSM6DS0_G_Read_Reg(&ctx, addr, &val);
}

DrvStatusTypeDef G_lsm6ds0::Write_Reg (DrvContextTypeDef &ctx, uint8_t addr, uint8_t val)
{
	return LSM6DS0_G_Write_Reg(&ctx, addr, val);
}

DrvStatusTypeDef G_lsm6ds0::Get_DRDY_Status (DrvContextTypeDef &ctx, uint8_t &status)
{
	return LSM6DS0_G_Get_DRDY_Status(&ctx, &status);
}

/**
 * @brief  Configures sensor I2C interface.
 * @param  None
 * @retval COMPONENT_OK in case of success
 * @retval COMPONENT_ERROR in case of failure
 */
DrvStatusTypeDef G_lsm6ds0::Sensor_IO_Init(void)
{
	if (I2C_EXPBD_Init())
	{
		return COMPONENT_ERROR;
	}
	else
	{
		return COMPONENT_OK;
	}
}

DrvStatusTypeDef G_lsm6ds0::LSM6DS0_Sensor_IO_ITConfig(void)
{
	if(AccGyro_Sensor_IO_IT_Config())
	{
		return COMPONENT_OK;
	}
	else {
		return COMPONENT_ERROR;
	}
}
