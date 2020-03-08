/*
 * board.h
 *
 *  Created on: 7 mars 2020
 *      Author: Ross
 */

#ifndef INC_BOARD_H_
#define INC_BOARD_H_

#include "stm32f4xx_hal.h"
#include "main.h"


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


/**
 * 	BOARD
 */
#define NUCLEO_I2C_EXPBD_SPEED                         400000
#define NUCLEO_I2C_EXPBD_TIMEOUT_MAX    0x1000 /*<! The value of the maximal timeout for BUS waiting loops */

extern I2C_HandleTypeDef	hi2c1;
#define I2C_EXPBD_Handle	hi2c1

#define NUCLEO_I2C_EXPBD_EV_IRQn                    I2C1_EV_IRQn
#define NUCLEO_I2C_EXPBD_ER_IRQn                    I2C1_ER_IRQn

extern uint32_t I2C_EXPBD_Timeout;

extern I2C_HandleTypeDef I2C_EXPBD_Handle;

/**
 * @brief I2C MSP Initialization
 * @param None
 * @retval None
 */
void I2C_EXPBD_MspInit(void);

/**
 * @brief  Configures I2C interface.
 * @param  None
 * @retval 0 in case of success
 * @retval 1 in case of failure
 */
uint8_t I2C_EXPBD_Init(void);

/**
 * @brief  Configures sensor interrupts interface for LSM6DS0 sensor).
 * @param  None
 * @retval COMPONENT_OK in case of success
 * @retval COMPONENT_ERROR in case of failure
 */
uint8_t AccGyro_Sensor_IO_ITConfig(void);

#endif /* INC_BOARD_H_ */
