/**
  * lsm6dso.cpp
  *
  *  Created on: Feb 27, 2020
  *  Author: Ross
  */

#include <Glsm6dso.h>

G_lsm6dso::G_lsm6dso(DrvContextTypeDef &ctx):
	Gyroscope(ctx){
	// TODO Auto-generated constructor stub
	ctx.who_am_i = IKS01A1_LSM6DS0_WHO_AM_I;
}

G_lsm6dso::~G_lsm6dso() {
	// TODO Auto-generated destructor stub
}

DrvStatusTypeDef G_lsm6dso::Init (DrvContextTypeDef &ctx)
{
	DrvContextTypeDef *foo;
	foo = &ctx;
	return LSM6DSO_G_Init(foo);
}

DrvStatusTypeDef G_lsm6dso::DeInit (DrvContextTypeDef &ctx)
{
	return LSM6DSO_G_DeInit(&ctx);
}

DrvStatusTypeDef G_lsm6dso::Sensor_Enable (DrvContextTypeDef &ctx)
{
	return LSM6DSO_G_Sensor_Enable(&ctx);
}

DrvStatusTypeDef G_lsm6dso::Sensor_Disable (DrvContextTypeDef &ctx)
{
	return LSM6DSO_G_Sensor_Disable(&ctx);
}

DrvStatusTypeDef G_lsm6dso::Get_WhoAmI (DrvContextTypeDef &ctx, uint8_t &who)
{
	return LSM6DSO_G_Get_WhoAmI(&ctx, &who);
}

DrvStatusTypeDef G_lsm6dso::Check_WhoAmI (DrvContextTypeDef &ctx)
{
	return LSM6DSO_G_Check_WhoAmI(&ctx);
}

DrvStatusTypeDef G_lsm6dso::Get_Axes (DrvContextTypeDef &ctx, SensorAxes_t &axis)
{
	return LSM6DSO_G_Get_Axes(&ctx, &axis);
}

DrvStatusTypeDef G_lsm6dso::Get_AxesRaw (DrvContextTypeDef &ctx, SensorAxesRaw_t &axis)
{
	return LSM6DSO_G_Get_AxesRaw(&ctx, &axis);
}

DrvStatusTypeDef G_lsm6dso::Get_Sensitivity (DrvContextTypeDef &ctx, float &val)
{
	return LSM6DSO_G_Get_Sensitivity(&ctx, &val);
}

DrvStatusTypeDef G_lsm6dso::Get_ODR (DrvContextTypeDef &ctx, float &odr)
{
	return LSM6DSO_G_Get_ODR(&ctx, &odr);
}

DrvStatusTypeDef G_lsm6dso::Set_ODR (DrvContextTypeDef &ctx, SensorOdr_t odr)
{
	return LSM6DSO_G_Set_ODR(&ctx, odr);
}

DrvStatusTypeDef G_lsm6dso::Set_ODR_Value (DrvContextTypeDef &ctx, float val)
{
	return LSM6DSO_G_Set_ODR_Value(&ctx, val);
}

DrvStatusTypeDef G_lsm6dso::Get_FS (DrvContextTypeDef &ctx, float &val)
{
	return LSM6DSO_G_Get_FS(&ctx, &val);
}

DrvStatusTypeDef G_lsm6dso::Set_FS (DrvContextTypeDef &ctx, SensorFs_t val)
{
	return LSM6DSO_G_Set_FS(&ctx, val);
}

DrvStatusTypeDef G_lsm6dso::Set_FS_Value (DrvContextTypeDef &ctx, float val)
{
	return LSM6DSO_G_Set_FS_Value(&ctx, val);
}

//DrvStatusTypeDef lsm6dso::Get_Axes_Status (DrvContextTypeDef &ctx, uint8_t &status)
//{
//	return LSM6DSO_X_Get_Axes_Status(&ctx, &status);
//}
//
//DrvStatusTypeDef lsm6dso::Set_Axes_Status (DrvContextTypeDef &ctx, uint8_t &status)
//{
//	return LSM6DSO_X_Set_Axes_Status(&ctx, &status);
//}

DrvStatusTypeDef G_lsm6dso::Read_Reg (DrvContextTypeDef &ctx, uint8_t addr, uint8_t &val)
{
	return LSM6DSO_G_Read_Reg(&ctx, addr, &val);
}

DrvStatusTypeDef G_lsm6dso::Write_Reg (DrvContextTypeDef &ctx, uint8_t addr, uint8_t val)
{
	return LSM6DSO_G_Write_Reg(&ctx, addr, val);
}

DrvStatusTypeDef G_lsm6dso::Get_DRDY_Status (DrvContextTypeDef &ctx, uint8_t &status)
{
	return LSM6DSO_G_Get_DRDY_Status(&ctx, &status);
}
