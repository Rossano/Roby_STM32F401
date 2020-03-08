/*
 * sensor.h
 *
 *  Created on: Feb 28, 2020
 *      Author: Ross
 */

#ifndef INC_SENSOR_H_
#define INC_SENSOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/** @addtogroup COMPONENT_Public_Types COMPONENT Public Types
 * @{
 */

/**
 * @brief  NULL pointer definition
 */
#ifndef NULL
#define NULL ( void * )0
#endif

#define LSM6DS0_X_0				0
#define LSM6DS0_G_0				0

/**
 * @}
 */

/**
 * @brief  Component's Status enumerator definition.
 */
typedef enum
{
  COMPONENT_OK = 0,
  COMPONENT_ERROR,
  COMPONENT_TIMEOUT,
  COMPONENT_NOT_IMPLEMENTED
} DrvStatusTypeDef;

/**
 * @brief  ACCELEROMETER data structure definition
 */
typedef struct
{
  void *pComponentData; /* Component specific data. */
  void *pExtData;       /* Other data. */
} ACCELERO_Data_t;

typedef enum
{
  X_AXIS = 0,
  Y_AXIS,
  Z_AXIS,
  ALL_ACTIVE
} ACTIVE_AXIS_t;

typedef enum
{
  NORMAL_MODE,
  HIGH_RES_MODE,
  LOW_PWR_MODE
} OP_MODE_t;

typedef enum
{
  INT1_DRDY_DISABLED,
  INT1_DRDY_ENABLED
} INT1_DRDY_CONFIG_t;

typedef enum
{
  DRDY_PULSED,
  DRDY_LATCHED
} DRDY_MODE_t;


/**
 * @brief  ACCELEROMETER hardware features status data structure definition
 */
typedef struct
{
  unsigned int FreeFallStatus : 1;
  unsigned int TapStatus : 1;
  unsigned int DoubleTapStatus : 1;
  unsigned int WakeUpStatus : 1;
  unsigned int StepStatus : 1;
  unsigned int TiltStatus : 1;
  unsigned int D6DOrientationStatus : 1;
} ACCELERO_Event_Status_t;

typedef struct
{
  int16_t AXIS_X;
  int16_t AXIS_Y;
  int16_t AXIS_Z;
} SensorAxesRaw_t;

/**
 * @brief  Sensor axes data structure definition
 */
typedef struct
{
  int32_t AXIS_X;
  int32_t AXIS_Y;
  int32_t AXIS_Z;
} SensorAxes_t;

/**
 * @brief  Sensor output data rate enumerator definition
 */
typedef enum
{
  ODR_LOW,
  ODR_MID_LOW,
  ODR_MID,
  ODR_MID_HIGH,
  ODR_HIGH
} SensorOdr_t;

/**
 * @brief  Sensor full scale enumerator definition
 */
typedef enum
{
  FS_LOW,
  FS_MID_LOW,
  FS_MID,
  FS_MID_HIGH,
  FS_HIGH
} SensorFs_t;

/**
 * @brief  Sensor interrupt pin enumerator definition
 */
typedef enum
{
  INT1_PIN,
  INT2_PIN
} SensorIntPin_t;

/**
 * @brief  Component's Context structure definition.
 */
typedef struct
{

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
} DrvContextTypeDef;


/**
 * @brief  GYROSCOPE data structure definition
 */
typedef struct
{
  void *pComponentData; /* Component specific data. */
  void *pExtData;       /* Other data. */
} GYRO_Data_t;

#ifdef __cplusplus
}
#endif

#endif /* INC_SENSOR_H_ */
