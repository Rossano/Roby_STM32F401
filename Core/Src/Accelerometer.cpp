/*
 * accelero.cpp
 *
 *  Created on: Feb 27, 2020
 *      Author: Ross
 */

#include <Accelerometer.h>

#if 1
Accelerometer::Accelerometer(DrvContextTypeDef &ctx) {
	// TODO Auto-generated constructor stub
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

DrvStatusTypeDef Init (DrvContextTypeDef &ctx)
{

}

DrvStatusTypeDef DeInit (DrvContextTypeDef &ctx)
{

}

DrvStatusTypeDef Sensor_Enable (DrvContextTypeDef &ctx)
{

}

DrvStatusTypeDef Sensor_Disable (DrvContextTypeDef &ctx);
DrvStatusTypeDef Get_WhoAmI (DrvContextTypeDef &ctx, uint8_t who);
DrvStatusTypeDef Check_WhoAmI (DrvContextTypeDef &ctx);
DrvStatusTypeDef Get_Axes (DrvContextTypeDef &ctx, SensorAxes_t &axis);
DrvStatusTypeDef Get_AxesRaw (DrvContextTypeDef &ctx, SensorAxesRaw_t axis);
DrvStatusTypeDef Get_Sensitivity (DrvContextTypeDef &ctx, float val);
DrvStatusTypeDef Get_ODR (DrvContextTypeDef &ctx, float &val);
DrvStatusTypeDef Set_ODR (DrvContextTypeDef &ctx, SensorOdr_t odr);
DrvStatusTypeDef Set_ODR_Value (DrvContextTypeDef &ctx, float val);
DrvStatusTypeDef Get_FS (DrvContextTypeDef &ctx, float &val);
DrvStatusTypeDef Set_FS (DrvContextTypeDef &ctx, SensorFs_t fs);
DrvStatusTypeDef Set_FS_Value (DrvContextTypeDef &ctx, float val);
DrvStatusTypeDef Get_Axes_Status (DrvContextTypeDef &ctx, uint8_t &status);
DrvStatusTypeDef Set_Axes_Status (DrvContextTypeDef &ctx, uint8_t &status);
DrvStatusTypeDef Read_Reg (DrvContextTypeDef &ctx, uint8_t addr, uint8_t &val);
DrvStatusTypeDef Write_Reg (DrvContextTypeDef &ctx, uint8_t addr, uint8_t val);
DrvStatusTypeDef Get_DRDY_Status (DrvContextTypeDef &ctx, uint8_t &status);
#endif
