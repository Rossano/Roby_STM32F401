/**
 ******************************************************************************
 * @file    LSM6DSO_ACC_GYRO_driver_HL.h
 * @author  MEMS Application Team
 * @brief   This file contains definitions for the LSM6DSO_ACC_GYRO_driver_HL.c firmware driver
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2018 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LSM6DSO_ACC_GYRO_DRIVER_HL_H
#define __LSM6DSO_ACC_GYRO_DRIVER_HL_H

#ifdef __cplusplus
extern "C" {
#endif



/* Includes ------------------------------------------------------------------*/

//#include "accelerometer.h"
//#include "gyroscope.h"

//#include <Accelerometer.h>
#include <sensor.h>

/* Include accelero sensor component drivers. */
#include "LSM6DSO_ACC_GYRO_driver.h"



/** @addtogroup BSP BSP
 * @{
 */

/** @addtogroup COMPONENTS COMPONENTS
 * @{
 */

/** @addtogroup LSM6DSO LSM6DSO
 * @{
 */

/** @addtogroup LSM6DSO_Public_Constants Public constants
 * @{
 */

#define LSM6DSO_SENSORS_MAX_NUM  1     /**< LSM6DSO max number of instances */

/** @addtogroup LSM6DSO_ACC_SENSITIVITY Accelero sensitivity values based on selected full scale
 * @{
 */

#define LSM6DSO_ACC_SENSITIVITY_FOR_FS_2G   0.061  /**< Sensitivity value for 2 g full scale [mg/LSB] */
#define LSM6DSO_ACC_SENSITIVITY_FOR_FS_4G   0.122  /**< Sensitivity value for 4 g full scale [mg/LSB] */
#define LSM6DSO_ACC_SENSITIVITY_FOR_FS_8G   0.244  /**< Sensitivity value for 8 g full scale [mg/LSB] */
#define LSM6DSO_ACC_SENSITIVITY_FOR_FS_16G  0.488  /**< Sensitivity value for 16 g full scale [mg/LSB] */

/**
 * @}
 */

/** @addtogroup LSM6DSO_GYRO_SENSITIVITY Gyro sensitivity values based on selected full scale
 * @{
 */

#define LSM6DSO_GYRO_SENSITIVITY_FOR_FS_125DPS   04.375  /**< Sensitivity value for 125 dps full scale [mdps/LSB] */
#define LSM6DSO_GYRO_SENSITIVITY_FOR_FS_250DPS   08.750  /**< Sensitivity value for 250 dps full scale [mdps/LSB] */
#define LSM6DSO_GYRO_SENSITIVITY_FOR_FS_500DPS   17.500  /**< Sensitivity value for 500 dps full scale [mdps/LSB] */
#define LSM6DSO_GYRO_SENSITIVITY_FOR_FS_1000DPS  35.000  /**< Sensitivity value for 1000 dps full scale [mdps/LSB] */
#define LSM6DSO_GYRO_SENSITIVITY_FOR_FS_2000DPS  70.000  /**< Sensitivity value for 2000 dps full scale [mdps/LSB] */

/**
 * @}
 */

/**
 * @}
 */

/** @addtogroup LSM6DSO_Public_Types LSM6DSO Public Types
 * @{
 */

/**
 * @brief LSM6DSO combo specific data internal structure definition
 */
typedef struct
{
  uint8_t isAccInitialized;
  uint8_t isGyroInitialized;
} LSM6DSO_Combo_Data_t;

/**
 * @brief LSM6DSO accelero specific data internal structure definition
 */
typedef struct
{
  LSM6DSO_Combo_Data_t *comboData; /* Combo data to manage in software SPI 3-Wire initialization of the combo sensors */
  float Previous_ODR;
} LSM6DSO_X_Data_t;

/**
 * @brief LSM6DSO gyro specific data internal structure definition
 */
typedef struct
{
  LSM6DSO_Combo_Data_t *comboData; /* Combo data to manage in software SPI 3-Wire initialization of the combo sensors */
  float Previous_ODR;
} LSM6DSO_G_Data_t;

/**
 * @}
 */

/** @addtogroup LSM6DSO_Public_Variables Public variables
 * @{
 */

//extern ACCELERO_Drv_t LSM6DSO_X_Drv;
//extern GYRO_Drv_t LSM6DSO_G_Drv;
extern LSM6DSO_Combo_Data_t LSM6DSO_Combo_Data[LSM6DSO_SENSORS_MAX_NUM];

/**
 * @}
 */
/** @addtogroup LSM6DSO_Callable_Private_Function_Prototypes Callable private function prototypes
 * @{
 */

static DrvStatusTypeDef LSM6DSO_X_Init(DrvContextTypeDef *handle);
static DrvStatusTypeDef LSM6DSO_X_DeInit(DrvContextTypeDef *handle);
static DrvStatusTypeDef LSM6DSO_X_Sensor_Enable(DrvContextTypeDef *handle);
static DrvStatusTypeDef LSM6DSO_X_Sensor_Disable(DrvContextTypeDef *handle);
static DrvStatusTypeDef LSM6DSO_X_Get_WhoAmI(DrvContextTypeDef *handle, uint8_t *who_am_i);
static DrvStatusTypeDef LSM6DSO_X_Check_WhoAmI(DrvContextTypeDef *handle);
static DrvStatusTypeDef LSM6DSO_X_Get_Axes(DrvContextTypeDef *handle, SensorAxes_t *acceleration);
static DrvStatusTypeDef LSM6DSO_X_Get_AxesRaw(DrvContextTypeDef *handle, SensorAxesRaw_t *value);
static DrvStatusTypeDef LSM6DSO_X_Get_Sensitivity(DrvContextTypeDef *handle, float *sensitivity);
static DrvStatusTypeDef LSM6DSO_X_Get_ODR(DrvContextTypeDef *handle, float *odr);
static DrvStatusTypeDef LSM6DSO_X_Set_ODR(DrvContextTypeDef *handle, SensorOdr_t odr);
static DrvStatusTypeDef LSM6DSO_X_Set_ODR_Value(DrvContextTypeDef *handle, float odr);
static DrvStatusTypeDef LSM6DSO_X_Get_FS(DrvContextTypeDef *handle, float *fullScale);
static DrvStatusTypeDef LSM6DSO_X_Set_FS(DrvContextTypeDef *handle, SensorFs_t fs);
static DrvStatusTypeDef LSM6DSO_X_Set_FS_Value(DrvContextTypeDef *handle, float fullScale);
static DrvStatusTypeDef LSM6DSO_X_Read_Reg(DrvContextTypeDef *handle, uint8_t reg, uint8_t *data);
static DrvStatusTypeDef LSM6DSO_X_Write_Reg(DrvContextTypeDef *handle, uint8_t reg, uint8_t data);
static DrvStatusTypeDef LSM6DSO_X_Get_DRDY_Status(DrvContextTypeDef *handle, uint8_t *status);

static DrvStatusTypeDef LSM6DSO_G_Init(DrvContextTypeDef *handle);
static DrvStatusTypeDef LSM6DSO_G_DeInit(DrvContextTypeDef *handle);
static DrvStatusTypeDef LSM6DSO_G_Sensor_Enable(DrvContextTypeDef *handle);
static DrvStatusTypeDef LSM6DSO_G_Sensor_Disable(DrvContextTypeDef *handle);
static DrvStatusTypeDef LSM6DSO_G_Get_WhoAmI(DrvContextTypeDef *handle, uint8_t *who_am_i);
static DrvStatusTypeDef LSM6DSO_G_Check_WhoAmI(DrvContextTypeDef *handle);
static DrvStatusTypeDef LSM6DSO_G_Get_Axes(DrvContextTypeDef *handle, SensorAxes_t *angular_velocity);
static DrvStatusTypeDef LSM6DSO_G_Get_AxesRaw(DrvContextTypeDef *handle, SensorAxesRaw_t *value);
static DrvStatusTypeDef LSM6DSO_G_Get_Sensitivity(DrvContextTypeDef *handle, float *sensitivity);
static DrvStatusTypeDef LSM6DSO_G_Get_ODR(DrvContextTypeDef *handle, float *odr);
static DrvStatusTypeDef LSM6DSO_G_Set_ODR(DrvContextTypeDef *handle, SensorOdr_t odr);
static DrvStatusTypeDef LSM6DSO_G_Set_ODR_Value(DrvContextTypeDef *handle, float odr);
static DrvStatusTypeDef LSM6DSO_G_Get_FS(DrvContextTypeDef *handle, float *fullScale);
static DrvStatusTypeDef LSM6DSO_G_Set_FS(DrvContextTypeDef *handle, SensorFs_t fullScale);
static DrvStatusTypeDef LSM6DSO_G_Set_FS_Value(DrvContextTypeDef *handle, float fullScale);
static DrvStatusTypeDef LSM6DSO_G_Read_Reg(DrvContextTypeDef *handle, uint8_t reg, uint8_t *data);
static DrvStatusTypeDef LSM6DSO_G_Write_Reg(DrvContextTypeDef *handle, uint8_t reg, uint8_t data);
static DrvStatusTypeDef LSM6DSO_G_Get_DRDY_Status(DrvContextTypeDef *handle, uint8_t *status);

/**
 * @}
 */
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __LSM6DSO_ACC_GYRO_DRIVER_HL_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
