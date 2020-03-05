/*
 * Mems.h
 *
 *  Created on: 5 mars 2020
 *      Author: Ross
 */

#ifndef SRC_MEMS_H_
#define SRC_MEMS_H_

#include <Xlsm6dso.h>
#include <Glsm6dso.h>


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

/* I2C clock speed configuration (in Hz) */
#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)))
#define NUCLEO_I2C_EXPBD_SPEED                         400000
#endif /* USE_STM32F4XX_NUCLEO or USE_STM32L1XX_NUCLEO */

#define NUCLEO_I2C_EXPBD_SPEED		400000

/* Timing samples for L0 with SYSCLK 32MHz set in SystemClock_Config() */
#if (defined (USE_STM32L0XX_NUCLEO))
#define NUCLEO_I2C_EXPBD_TIMING_100KHZ       0x10A13E56 /* Analog Filter ON, Rise Time 400ns, Fall Time 100ns */
#define NUCLEO_I2C_EXPBD_TIMING_400KHZ       0x00B1112E /* Analog Filter ON, Rise Time 250ns, Fall Time 100ns */
#endif /* USE_STM32L0XX_NUCLEO */

/* Timing samples for L4 with SYSCLK 80MHz set in SystemClock_Config() */
#if (defined (USE_STM32L4XX_NUCLEO))
#define NUCLEO_I2C_EXPBD_TIMING_400KHZ       0x10D1143A /* Analog Filter ON, Rise time 250ns, Fall Time 100ns */
#define NUCLEO_I2C_EXPBD_TIMING_1000KHZ      0x00D00E28 /* Analog Filter ON, Rise time 120ns, Fall time 25ns */
#endif /* USE_STM32L4XX_NUCLEO */

/* I2C peripheral configuration defines */
#define NUCLEO_I2C_EXPBD                            I2C1
#define NUCLEO_I2C_EXPBD_CLK_ENABLE()               __I2C1_CLK_ENABLE()
#define NUCLEO_I2C_EXPBD_SCL_SDA_GPIO_CLK_ENABLE()  __GPIOB_CLK_ENABLE()
#define NUCLEO_I2C_EXPBD_SCL_SDA_AF                 GPIO_AF4_I2C1
#define NUCLEO_I2C_EXPBD_SCL_SDA_GPIO_PORT          GPIOB
#define NUCLEO_I2C_EXPBD_SCL_PIN                    GPIO_PIN_8
#define NUCLEO_I2C_EXPBD_SDA_PIN                    GPIO_PIN_9

#define NUCLEO_I2C_EXPBD_FORCE_RESET()              __I2C1_FORCE_RESET()
#define NUCLEO_I2C_EXPBD_RELEASE_RESET()            __I2C1_RELEASE_RESET()

/* I2C interrupt requests */
#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
#define NUCLEO_I2C_EXPBD_EV_IRQn                    I2C1_EV_IRQn
#define NUCLEO_I2C_EXPBD_ER_IRQn                    I2C1_ER_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define NUCLEO_I2C_EXPBD_EV_IRQn                    I2C1_IRQn
#endif

/* Maximum Timeout values for flags waiting loops. These timeouts are not based
   on accurate values, they just guarantee that the application will not remain
   stuck if the I2C communication is corrupted.
   You may modify these timeout values depending on CPU frequency and application
   conditions (interrupts routines ...). */
#define NUCLEO_I2C_EXPBD_TIMEOUT_MAX    0x1000 /*<! The value of the maximal timeout for BUS waiting loops */

/* Definition for interrupt Pins */
#define HTS221_DRDY_GPIO_PORT           GPIOB
#define HTS221_DRDY_GPIO_CLK_ENABLE()   __GPIOB_CLK_ENABLE()
#define HTS221_DRDY_GPIO_CLK_DISABLE()  __GPIOB_CLK_DISABLE()
#define HTS221_DRDY_PIN                 GPIO_PIN_10

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
#define HTS221_DRDY_EXTI_IRQn           EXTI15_10_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define HTS221_DRDY_EXTI_IRQn           EXTI4_15_IRQn
#endif

#define LSM6DS0_INT1_GPIO_PORT           GPIOB
#define LSM6DS0_INT1_GPIO_CLK_ENABLE()   __GPIOB_CLK_ENABLE()
#define LSM6DS0_INT1_GPIO_CLK_DISABLE()  __GPIOB_CLK_DISABLE()
#define LSM6DS0_INT1_PIN                 GPIO_PIN_5

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)) || defined(STM32F401xE))
#define LSM6DS0_INT1_EXTI_IRQn           EXTI9_5_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define LSM6DS0_INT1_EXTI_IRQn           EXTI4_15_IRQn
#endif

//#define LIS3MDL_DRDY_GPIO_PORT           GPIOC
//#define LIS3MDL_DRDY_GPIO_CLK_ENABLE()   __GPIOC_CLK_ENABLE()
//#define LIS3MDL_DRDY_GPIO_CLK_DISABLE()  __GPIOC_CLK_DISABLE()
//#define LIS3MDL_DRDY_PIN                 GPIO_PIN_0

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
#define LIS3MDL_DRDY_EXTI_IRQn           EXTI0_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define LIS3MDL_DRDY_EXTI_IRQn           EXTI0_1_IRQn
#endif

#define LIS3MDL_INT1_GPIO_PORT           GPIOC
#define LIS3MDL_INT1_GPIO_CLK_ENABLE()   __GPIOC_CLK_ENABLE()
#define LIS3MDL_INT1_GPIO_CLK_DISABLE()  __GPIOC_CLK_DISABLE()
#define LIS3MDL_INT1_PIN                 GPIO_PIN_1

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
#define LIS3MDL_INT1_EXTI_IRQn           EXTI1_IRQn
#endif

//#if (defined (USE_STM32L0XX_NUCLEO))
//#define LIS3MDL_INT1_EXTI_IRQn           EXTI0_1_IRQn
//#endif

//#define LPS25HB_INT1_GPIO_PORT           GPIOB
//#define LPS25HB_INT1_GPIO_CLK_ENABLE()   __GPIOB_CLK_ENABLE()
//#define LPS25HB_INT1_GPIO_CLK_DISABLE()  __GPIOB_CLK_DISABLE()
//#define LPS25HB_INT1_PIN                 GPIO_PIN_4

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
#define LPS25HB_INT1_EXTI_IRQn           EXTI4_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define LPS25HB_INT1_EXTI_IRQn           EXTI4_15_IRQn
#endif

// ready for use
#define USER_INT_GPIO_PORT           GPIOA
#define USER_INT_GPIO_CLK_ENABLE()   __GPIOA_CLK_ENABLE()
#define USER_INT_GPIO_CLK_DISABLE()  __GPIOA_CLK_DISABLE()
#define USER_INT_PIN                 GPIO_PIN_10

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)) || defined(STM32F401xE))
#define USER_INT_EXTI_IRQn           EXTI15_10_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define USER_INT_EXTI_IRQn           EXTI4_15_IRQn
#endif

// ready for use
#define M_INT1_GPIO_PORT           GPIOA
#define M_INT1_GPIO_CLK_ENABLE()   __GPIOA_CLK_ENABLE()
#define M_INT1_GPIO_CLK_DISABLE()  __GPIOA_CLK_DISABLE()
#define M_INT1_PIN                 GPIO_PIN_4

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
#define M_INT1_EXTI_IRQn           EXTI4_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define M_INT1_EXTI_IRQn           EXTI4_15_IRQn
#endif

// ready for use
#define M_INT2_GPIO_PORT           GPIOB
#define M_INT2_GPIO_CLK_ENABLE()   __GPIOB_CLK_ENABLE()
#define M_INT2_GPIO_CLK_DISABLE()  __GPIOB_CLK_DISABLE()
#define M_INT2_PIN                 GPIO_PIN_0

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
#define M_INT2_EXTI_IRQn           EXTI0_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define M_INT2_EXTI_IRQn           EXTI0_1_IRQn
#endif

class Mems {
public:
	X_lsm6dso * accel;
	G_lsm6dso * gyro;
public:
	Mems();
	virtual ~Mems();
	DrvStatusTypeDef Sensor_IO_Init(void);
	DrvStatusTypeDef LSM6DS0_Sensor_IO_ITConfig(void);
private:
	/* Link function for sensor peripheral */
	uint8_t Sensor_IO_Write(void *handle, uint8_t WriteAddr, uint8_t *pBuffer, uint16_t nBytesToWrite);
	uint8_t Sensor_IO_Read(void *handle, uint8_t ReadAddr, uint8_t *pBuffer, uint16_t nBytesToRead);

	void I2C_EXPBD_MspInit(void);
	void I2C_EXPBD_Error(uint8_t Addr);
	uint8_t I2C_EXPBD_ReadData(uint8_t Addr, uint8_t Reg, uint8_t *pBuffer, uint16_t Size);
	uint8_t I2C_EXPBD_WriteData(uint8_t Addr, uint8_t Reg, uint8_t *pBuffer, uint16_t Size);
};

#endif /* SRC_MEMS_H_ */
