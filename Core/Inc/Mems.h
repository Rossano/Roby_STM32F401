/*
 * Mems.h
 *
 *  Created on: 5 mars 2020
 *      Author: Ross
 */

#ifndef SRC_MEMS_H_
#define SRC_MEMS_H_

#include <stdint.h>
#include <board.h>
#include <Xlsm6ds0.h>
#include <Glsm6ds0.h>

/* Includes ------------------------------------------------------------------*/

#if (defined(USE_STM32F4XX_NUCLEO) || defined(STM32F401xE))
#include "stm32f4xx_hal.h"
#endif

//#ifdef USE_STM32L0XX_NUCLEO
//#include "stm32l0xx_hal.h"
//#endif
//
//#ifdef USE_STM32L1XX_NUCLEO
//#include "stm32l1xx_hal.h"
//#endif
//
//#ifdef USE_STM32L4XX_NUCLEO
//#include "stm32l4xx_hal.h"
//#endif

//#include "accelerometer.h"
//#include "gyroscope.h"
//#include "magnetometer.h"
//#include "humidity.h"
//#include "temperature.h"
//#include "pressure.h"

/** @addtogroup BSP BSP
 * @{
 */

/** @addtogroup X_NUCLEO_IKS01A1 X_NUCLEO_IKS01A1
 * @{
 */

/** @addtogroup X_NUCLEO_IKS01A1_IO IO
 * @{
 */

/** @addtogroup X_NUCLEO_IKS01A1_IO_Public_Constants Public constants
 * @{
 */

//#define IKS01A1_HTS221_WHO_AM_I        (uint8_t)0xBC
//#define IKS01A1_LPS25HB_WHO_AM_I       (uint8_t)0xBD
//#define IKS01A1_LPS22HB_WHO_AM_I       (uint8_t)0xB1
#define IKS01A1_LSM6DS0_WHO_AM_I       (uint8_t)0x68
//#define IKS01A1_LSM6DS3_WHO_AM_I       (uint8_t)0x69
//#define IKS01A1_LIS3MDL_WHO_AM_I       (uint8_t)0x3D
//#define IKS01A1_LSM6DSL_WHO_AM_I       (uint8_t)0x6A
//#define IKS01A1_LSM303AGR_ACC_WHO_AM_I (uint8_t)0x33 /* Same value as IKS01A1_LIS2DH12_WHO_AM_I */
//#define IKS01A1_LSM303AGR_MAG_WHO_AM_I (uint8_t)0x40 /* Same value as IKS01A1_LIS2MDL_WHO_AM_I */
//#define IKS01A1_H3LIS331DL_WHO_AM_I    (uint8_t)0x32
//#define IKS01A1_LIS2DH12_WHO_AM_I      (uint8_t)0x33 /* Same value as IKS01A1_LSM303AGR_ACC_WHO_AM_I */
//#define IKS01A1_LIS2MDL_WHO_AM_I       (uint8_t)0x40 /* Same value as IKS01A1_LSM303AGR_MAG_WHO_AM_I */
//#define IKS01A1_LIS2DW12_WHO_AM_I      (uint8_t)0x44

/**
 * Mems CLass
 */
class Mems {
public:
	X_lsm6ds0 * accel;
	G_lsm6ds0 * gyro;
public:
	Mems();
	virtual ~Mems();
	DrvStatusTypeDef Initialize_Sensors();
	DrvStatusTypeDef Enalble_Sensors();
	DrvStatusTypeDef Disable_Sensors();
	SensorAxes_t ReadAccelero();
	SensorAxes_t ReadGyro();

//	DrvStatusTypeDef Sensor_IO_Init(void);
//	DrvStatusTypeDef LSM6DS0_Sensor_IO_ITConfig(void);
private:
	DrvContextTypeDef xctx;
	DrvContextTypeDef gctx;
	/* Link function for sensor peripheral */
//	uint8_t Sensor_IO_Write(void *handle, uint8_t WriteAddr, uint8_t *pBuffer, uint16_t nBytesToWrite);
//	uint8_t Sensor_IO_Read(void *handle, uint8_t ReadAddr, uint8_t *pBuffer, uint16_t nBytesToRead);

//	uint8_t I2C_EXPBD_Init(void);
//	void I2C_EXPBD_MspInit(void);
	void I2C_EXPBD_Error(uint8_t Addr);
	uint8_t I2C_EXPBD_ReadData(uint8_t Addr, uint8_t Reg, uint8_t *pBuffer, uint16_t Size);
	uint8_t I2C_EXPBD_WriteData(uint8_t Addr, uint8_t Reg, uint8_t *pBuffer, uint16_t Size);
};

#endif /* SRC_MEMS_H_ */
