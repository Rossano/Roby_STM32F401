/*
 * lsm6dso.h
 *
 *  Created on: Feb 27, 2020
 *      Author: Ross
 */

#ifndef X_LSM6DS0_H_
#define X_LSM6DS0_H_

#include <sensor.h>
#include <board.h>
#include <Accelerometer.h>
#include <LSM6DS0_ACC_GYRO_driver.h>
#include <LSM6DS0_ACC_GYRO_driver_HL.h>

#define IKS01A1_LSM6DS0_WHO_AM_I       (uint8_t)0x68

class X_lsm6ds0: public Accelerometer {
private:
	//ACCELERO_Drv_t	*driver;
	LSM6DS0_X_Data_t LSM6DS0_X_0_Data;
	LSM6DS0_Combo_Data_t LSM6DS0_Combo_Data;
	uint8_t I2C_EXPBD_Init(void);
public:
	X_lsm6ds0(DrvContextTypeDef &);
	~X_lsm6ds0();

	DrvStatusTypeDef Init (DrvContextTypeDef &);
	DrvStatusTypeDef DeInit (DrvContextTypeDef &);
	DrvStatusTypeDef Sensor_Enable (DrvContextTypeDef &);
	DrvStatusTypeDef Sensor_Disable (DrvContextTypeDef &);
	DrvStatusTypeDef Get_WhoAmI (DrvContextTypeDef &, uint8_t &);
	DrvStatusTypeDef Check_WhoAmI (DrvContextTypeDef &);
	DrvStatusTypeDef Get_Axes (DrvContextTypeDef &, SensorAxes_t &);
	DrvStatusTypeDef Get_AxesRaw (DrvContextTypeDef &, SensorAxesRaw_t &);
	DrvStatusTypeDef Get_Sensitivity (DrvContextTypeDef &, float &);
	DrvStatusTypeDef Get_ODR (DrvContextTypeDef &, float &);
	DrvStatusTypeDef Set_ODR (DrvContextTypeDef &, SensorOdr_t);
	DrvStatusTypeDef Set_ODR_Value (DrvContextTypeDef &, float);
	DrvStatusTypeDef Get_FS (DrvContextTypeDef &, float &);
	DrvStatusTypeDef Set_FS (DrvContextTypeDef &, SensorFs_t);
	DrvStatusTypeDef Set_FS_Value (DrvContextTypeDef &, float);
	//	 DrvStatusTypeDef Get_Axes_Status (DrvContextTypeDef &, uint8_t &);
	//	 DrvStatusTypeDef Set_Axes_Status (DrvContextTypeDef &, uint8_t &);
	DrvStatusTypeDef Read_Reg (DrvContextTypeDef &, uint8_t, uint8_t &);
	DrvStatusTypeDef Write_Reg (DrvContextTypeDef &, uint8_t, uint8_t);
	DrvStatusTypeDef Get_DRDY_Status (DrvContextTypeDef &, uint8_t &);
	DrvStatusTypeDef Sensor_IO_Init(void);
	DrvStatusTypeDef LSM6DS0_Sensor_IO_ITConfig(void);
};

#endif /* X_LSM6DS0_H_ */
