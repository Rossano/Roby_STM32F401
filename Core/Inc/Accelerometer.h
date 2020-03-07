/*
 * accelero.h
 *
 *  Created on: Feb 27, 2020
 *      Author: Ross
 */

#ifndef SRC_ACCELERO_H_
#define SRC_ACCELERO_H_

#ifdef __cplusplus
extern "C" {
#endif

//#include <stdint.h>
#include "sensor.h"

class Accelerometer {

public:
	DrvContextTypeDef *ctx;
#if 0
	  /* Identity */
	  uint8_t who_am_i;

	  /* Configuration */
	  uint8_t ifType;        /* 0 means I2C, 1 means SPI, etc. */
	  uint8_t address;       /* Sensor I2C address (NOTE: Not a unique sensor ID). */
	  uint8_t spiDevice;     /* Sensor Chip Select for SPI Bus */
	  uint8_t instance;      /* Sensor instance (NOTE: Sensor ID unique only within its class). */
	  uint8_t isInitialized; /* Sensor setup done. */
	  uint8_t isEnabled;     /* Sensor ON. */
	  uint8_t isCombo;       /* Combo sensor (component consists of more sensors). */

	  /* Pointer to the Data */
	  void *pData;

	  /* Pointer to the Virtual Table */
	  void *pVTable;
	  /* Pointer to the Extended Virtual Table */
	  void *pExtVTable;
#endif
public:
	Accelerometer(DrvContextTypeDef &);
	virtual ~Accelerometer();
#if 1
public:
	virtual DrvStatusTypeDef Init (DrvContextTypeDef &);
	virtual DrvStatusTypeDef DeInit (DrvContextTypeDef &);
	virtual DrvStatusTypeDef Sensor_Enable (DrvContextTypeDef &);
	virtual DrvStatusTypeDef Sensor_Disable (DrvContextTypeDef &);
	virtual DrvStatusTypeDef Get_WhoAmI (DrvContextTypeDef &, uint8_t &);
	virtual DrvStatusTypeDef Check_WhoAmI (DrvContextTypeDef &);
	virtual DrvStatusTypeDef Get_Axes (DrvContextTypeDef &, SensorAxes_t &);
	virtual DrvStatusTypeDef Get_AxesRaw (DrvContextTypeDef &, SensorAxesRaw_t &);
	virtual DrvStatusTypeDef Get_Sensitivity (DrvContextTypeDef &, float &);
	virtual DrvStatusTypeDef Get_ODR (DrvContextTypeDef &, float &);
	virtual DrvStatusTypeDef Set_ODR (DrvContextTypeDef &, SensorOdr_t);
	virtual DrvStatusTypeDef Set_ODR_Value (DrvContextTypeDef &, float);
	virtual DrvStatusTypeDef Get_FS (DrvContextTypeDef &, float &);
	virtual DrvStatusTypeDef Set_FS (DrvContextTypeDef &, SensorFs_t);
	virtual DrvStatusTypeDef Set_FS_Value (DrvContextTypeDef &, float);
	virtual DrvStatusTypeDef Get_Axes_Status (DrvContextTypeDef &, uint8_t &);
	virtual DrvStatusTypeDef Set_Axes_Status (DrvContextTypeDef &, uint8_t &);
	virtual DrvStatusTypeDef Read_Reg (DrvContextTypeDef &, uint8_t, uint8_t &);
	virtual DrvStatusTypeDef Write_Reg (DrvContextTypeDef &, uint8_t, uint8_t);
	virtual DrvStatusTypeDef Get_DRDY_Status (DrvContextTypeDef &, uint8_t &);
#endif
};

#ifdef __cplusplus
}
#endif

#endif /* SRC_ACCELERO_H_ */
