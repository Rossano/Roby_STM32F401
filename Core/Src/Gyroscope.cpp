/*
 * gyroscope.cpp
 *
 *  Created on: Feb 28, 2020
 *      Author: Ross
 */

#include <Gyroscope.h>

Gyroscope::Gyroscope(DrvContextTypeDef &ctx) {
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

Gyroscope::~Gyroscope() {
	// TODO Auto-generated destructor stub
}
#if 0
DrvStatusTypeDef Gyroscope::Init (DrvContextTypeDef &ctx)
{

}
DrvStatusTypeDef Gyroscope::DeInit(DrvContextTypeDef &ctx)
{

}

DrvStatusTypeDef Gyroscope::Sensor_Enable(DrvContextTypeDef &ctx)
{

}

DrvStatusTypeDef Gyroscope::Sensor_Disable(DrvContextTypeDef &ctx)
{

}

DrvStatusTypeDef Gyroscope::Get_WhoAmI(DrvContextTypeDef &ctx, uint8_t &who)
{

}

DrvStatusTypeDef Gyroscope::Check_WhoAmI(DrvContextTypeDef &ctx)
{

}

DrvStatusTypeDef Gyroscope::Get_Axes(DrvContextTypeDef &ctx, SensorAxes_t &axis)
{

}

DrvStatusTypeDef Gyroscope::Get_AxesRaw(DrvContextTypeDef &ctx, SensorAxesRaw_t &axis)
{

}

DrvStatusTypeDef Gyroscope::Get_Sensitivity(DrvContextTypeDef &ctx, float &val)
{

}

DrvStatusTypeDef Gyroscope::Get_ODR(DrvContextTypeDef &ctx, float &val)
{

}

DrvStatusTypeDef Gyroscope::Set_ODR(DrvContextTypeDef &ctx, SensorOdr_t ods)
{

}

DrvStatusTypeDef Gyroscope::Set_ODR_Value(DrvContextTypeDef &ctx, float val)
{

}

DrvStatusTypeDef Gyroscope::Get_FS(DrvContextTypeDef &ctx, float &fs)
{

}

DrvStatusTypeDef Gyroscope::Set_FS(DrvContextTypeDef &ctx, SensorFs_t sen)
{

}

DrvStatusTypeDef Gyroscope::Set_FS_Value(DrvContextTypeDef &ctx, float val)
{

}

DrvStatusTypeDef Gyroscope::Get_Axes_Status(DrvContextTypeDef &ctx, uint8_t &status)
{

}

DrvStatusTypeDef Gyroscope::Set_Axes_Status(DrvContextTypeDef &ctx, uint8_t &status)
{

}

DrvStatusTypeDef Gyroscope::Read_Reg(DrvContextTypeDef &ctx, uint8_t adr, uint8_t &val)
{

}

DrvStatusTypeDef Gyroscope::Write_Reg(DrvContextTypeDef &ctx, uint8_t adr, uint8_t val)
{

}

DrvStatusTypeDef Gyroscope::Get_DRDY_Status(DrvContextTypeDef &ctx, uint8_t &status)
{

}
#endif
