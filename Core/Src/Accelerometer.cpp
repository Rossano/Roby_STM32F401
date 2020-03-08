/*
 * accelero.cpp
 *
 *  Created on: Feb 27, 2020
 *      Author: Ross
 */

#include <Accelerometer.h>

ACCELERO_Data_t ACCELERO_Data;

Accelerometer::Accelerometer(DrvContextTypeDef &ctx) {
	// TODO Auto-generated constructor stub
	this->ctx = new DrvContextTypeDef();

	this->ctx->who_am_i = 0;
	this->ctx->ifType = ctx.ifType;
	this->ctx->address = ctx.address;
	this->ctx->spiDevice = ctx.spiDevice;
	this->ctx->instance = ctx.instance;
	this->ctx->isCombo = ctx.isCombo;
	this->ctx->pData = NULL;
	this->ctx->pExtVTable = NULL;
	this->ctx->pVTable = NULL;
	this->ctx->isInitialized = 0;
	this->ctx->isEnabled = 0;
}

Accelerometer::~Accelerometer() {
	// TODO Auto-generated destructor stub
}

DrvStatusTypeDef Accelerometer::Init (DrvContextTypeDef &ctx)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::DeInit (DrvContextTypeDef &ctx)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Sensor_Enable (DrvContextTypeDef &ctx)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Sensor_Disable (DrvContextTypeDef &ctx)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Get_WhoAmI (DrvContextTypeDef &ctx, uint8_t &who)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Check_WhoAmI (DrvContextTypeDef &ctx)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Get_Axes (DrvContextTypeDef &ctx, SensorAxes_t &axis)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Get_AxesRaw (DrvContextTypeDef &ctx, SensorAxesRaw_t &axis)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Get_Sensitivity (DrvContextTypeDef &ctx, float &val)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Get_ODR (DrvContextTypeDef &ctx, float &val)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Set_ODR (DrvContextTypeDef &ctx, SensorOdr_t odr)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Set_ODR_Value (DrvContextTypeDef &ctx, float val)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Get_FS (DrvContextTypeDef &ctx, float &val)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Set_FS (DrvContextTypeDef &ctx, SensorFs_t fs)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Set_FS_Value (DrvContextTypeDef &ctx, float val)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Get_Axes_Status (DrvContextTypeDef &ctx, uint8_t &status)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Set_Axes_Status (DrvContextTypeDef &ctx, uint8_t &status)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Read_Reg (DrvContextTypeDef &ctx, uint8_t addr, uint8_t &val)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Write_Reg (DrvContextTypeDef &ctx, uint8_t addr, uint8_t val)
{
	return COMPONENT_NOT_IMPLEMENTED;
}

DrvStatusTypeDef Accelerometer::Get_DRDY_Status (DrvContextTypeDef &ctx, uint8_t &status)
{
	return COMPONENT_NOT_IMPLEMENTED;
}


