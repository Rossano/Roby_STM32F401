/**
  * LSM6DS0.cpp
  *
  *  Created on: Feb 27, 2020
  *  Author: Ross
  */

#include <LSM6DS0_ACC_GYRO_driver_HL.h>
#include <Glsm6ds0.h>

G_lsm6ds0::G_lsm6ds0(DrvContextTypeDef &ctx):
	Gyroscope(ctx){
	// TODO Auto-generated constructor stub
	ctx.who_am_i = IKS01A1_LSM6DS0_WHO_AM_I;
}

G_lsm6ds0::~G_lsm6ds0() {
	// TODO Auto-generated destructor stub
}

DrvStatusTypeDef G_lsm6ds0::Init (DrvContextTypeDef &ctx)
{
	DrvContextTypeDef *foo;
	foo = &ctx;
	return LSM6DS0_G_Init(foo);
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
