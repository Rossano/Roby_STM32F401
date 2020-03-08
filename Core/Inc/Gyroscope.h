/*
 * gyroscope.h
 *
 *  Created on: Feb 28, 2020
 *      Author: Ross
 */

#ifndef INC_GYROSCOPE_H_
#define INC_GYROSCOPE_H_

//#include <stdint.h>
#include "sensor.h"

class Gyroscope {
public:
	DrvContextTypeDef *ctx;
	Gyroscope(DrvContextTypeDef &);
	virtual ~Gyroscope();
	virtual DrvStatusTypeDef Init (DrvContextTypeDef &);
	virtual DrvStatusTypeDef DeInit(DrvContextTypeDef &);
	virtual DrvStatusTypeDef Sensor_Enable(DrvContextTypeDef &);
	virtual DrvStatusTypeDef Sensor_Disable(DrvContextTypeDef &);
	virtual DrvStatusTypeDef Get_WhoAmI(DrvContextTypeDef &, uint8_t &);
	virtual DrvStatusTypeDef Check_WhoAmI(DrvContextTypeDef &);
	virtual DrvStatusTypeDef Get_Axes(DrvContextTypeDef &, SensorAxes_t &);
	virtual DrvStatusTypeDef Get_AxesRaw(DrvContextTypeDef &, SensorAxesRaw_t &);
	virtual DrvStatusTypeDef Get_Sensitivity(DrvContextTypeDef &, float &);
	virtual DrvStatusTypeDef Get_ODR(DrvContextTypeDef &, float &);
	virtual DrvStatusTypeDef Set_ODR(DrvContextTypeDef &, SensorOdr_t);
	virtual DrvStatusTypeDef Set_ODR_Value(DrvContextTypeDef &, float);
	virtual DrvStatusTypeDef Get_FS(DrvContextTypeDef &, float &);
	virtual DrvStatusTypeDef Set_FS(DrvContextTypeDef &, SensorFs_t);
	virtual DrvStatusTypeDef Set_FS_Value(DrvContextTypeDef &, float);
	virtual DrvStatusTypeDef Get_Axes_Status(DrvContextTypeDef &, uint8_t &);
	virtual DrvStatusTypeDef Set_Axes_Status(DrvContextTypeDef &, uint8_t &);
	virtual DrvStatusTypeDef Read_Reg(DrvContextTypeDef &, uint8_t, uint8_t &);
	virtual DrvStatusTypeDef Write_Reg(DrvContextTypeDef &, uint8_t, uint8_t);
	DrvStatusTypeDef Get_DRDY_Status(DrvContextTypeDef &, uint8_t &);
};

#endif /* INC_GYROSCOPE_H_ */
