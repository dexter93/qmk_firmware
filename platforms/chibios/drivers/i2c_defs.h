#pragma once

#include "quantum.h"
#include <string.h>
#include <ch.h>
#include <hal.h>
#include <math.h>

#ifndef I2C1_SCL_PIN
#    define I2C1_SCL_PIN B6
#endif
#ifndef I2C1_SDA_PIN
#    define I2C1_SDA_PIN B7
#endif

#ifdef SN32_I2C_USE_I2C0
// The default timing values below configures the I2C clock to 400khz assuming a 48Mhz clock
// For more info refer to the sn32 docs.
#    ifndef I2C1_SCLHT
#        define I2C1_SCLHT 28U
#    endif
#    ifndef I2C1_SCLLT
#        define I2C1_SCLLT 90U
#    endif
#    ifndef I2C1_TIMEOUT
#        define I2C1_TIMEOUT 0U /* hardware timeout control disabled */
#    endif
#	 ifndef I2C_DRIVER
#    define I2C_DRIVER I2CD0
#	 endif
#endif

#ifdef USE_I2CV1
#    ifndef I2C1_OPMODE
#        define I2C1_OPMODE OPMODE_I2C
#    endif
#    ifndef I2C1_CLOCK_SPEED
#        define I2C1_CLOCK_SPEED 100000 /* 400000 */
#    endif
#    ifndef I2C1_DUTY_CYCLE
#        define I2C1_DUTY_CYCLE STD_DUTY_CYCLE /* FAST_DUTY_CYCLE_2 */
#    endif
#else
// The default timing values below configures the I2C clock to 400khz assuming a 72Mhz clock
// For more info : https://www.st.com/en/embedded-software/stsw-stm32126.html
#    ifndef I2C1_TIMINGR_PRESC
#        define I2C1_TIMINGR_PRESC 0U
#    endif
#    ifndef I2C1_TIMINGR_SCLDEL
#        define I2C1_TIMINGR_SCLDEL 7U
#    endif
#    ifndef I2C1_TIMINGR_SDADEL
#        define I2C1_TIMINGR_SDADEL 0U
#    endif
#    ifndef I2C1_TIMINGR_SCLH
#        define I2C1_TIMINGR_SCLH 38U
#    endif
#    ifndef I2C1_TIMINGR_SCLL
#        define I2C1_TIMINGR_SCLL 129U
#    endif
#endif

#ifndef I2C_DRIVER
#    define I2C_DRIVER I2CD1
#endif

#ifdef USE_GPIOV1
#    ifndef I2C1_SCL_PAL_MODE
#        define I2C1_SCL_PAL_MODE PAL_MODE_ALTERNATE_OPENDRAIN
#    endif
#    ifndef I2C1_SDA_PAL_MODE
#        define I2C1_SDA_PAL_MODE PAL_MODE_ALTERNATE_OPENDRAIN
#    endif
#else
// The default PAL alternate modes are used to signal that the pins are used for I2C
#    ifndef I2C1_SCL_PAL_MODE
#        define I2C1_SCL_PAL_MODE 4
#    endif
#    ifndef I2C1_SDA_PAL_MODE
#        define I2C1_SDA_PAL_MODE 4
#    endif
#endif

#ifdef SW_I2C_USE_I2C1
#    ifndef I2C1_SCL_PAL_MODE
#        define I2C1_SCL_PAL_MODE PAL_MODE_OUTPUT_PUSHPULL
#    endif
#    ifndef I2C1_SDA_PAL_MODE
#        define I2C1_SDA_PAL_MODE PAL_MODE_OUTPUT_PUSHPULL
#    endif
#   ifndef I2C_CLOCK_FREQUENCY
#       define I2C_CLOCK_FREQUENCY 100000
#   endif
#   ifndef SW_I2C_DELAY
#      define SW_I2C_DELAY ceil((CH_CFG_ST_FREQUENCY / I2C_CLOCK_FREQUENCY) / 2)
#   endif
#	ifndef SW_I2C_USE_OSAL_DELAY
#		define SW_I2C_USE_OSAL_DELAY TRUE
#	endif
#endif

#if (SW_I2C_USE_OSAL_DELAY == FALSE)
__attribute__((weak)) void i2c_sw_delay(void) {}
#endif

static const I2CConfig i2cconfig = {
#if defined(SW_I2C_USE_I2C1)
    0,
    I2C1_SCL_PIN,
    I2C1_SDA_PIN,
#if (SW_I2C_USE_OSAL_DELAY == FALSE)
    &i2c_sw_delay,
#else
    SW_I2C_DELAY,
#endif
#elif defined(SN32_I2C_USE_I2C0)
    I2C1_SCLHT,
    I2C1_SCLLT,
    I2C1_TIMEOUT,
#elif defined(USE_I2CV1_CONTRIB)
    I2C1_CLOCK_SPEED,
#elif defined(USE_I2CV1)
    I2C1_OPMODE,
    I2C1_CLOCK_SPEED,
    I2C1_DUTY_CYCLE,
#elif defined(WB32F3G71xx) || defined(WB32FQ95xx)
    I2C1_OPMODE,
    I2C1_CLOCK_SPEED,
#else
    // This configures the I2C clock to 400khz assuming a 72Mhz clock
    // For more info : https://www.st.com/en/embedded-software/stsw-stm32126.html
    STM32_TIMINGR_PRESC(I2C1_TIMINGR_PRESC) | STM32_TIMINGR_SCLDEL(I2C1_TIMINGR_SCLDEL) | STM32_TIMINGR_SDADEL(I2C1_TIMINGR_SDADEL) | STM32_TIMINGR_SCLH(I2C1_TIMINGR_SCLH) | STM32_TIMINGR_SCLL(I2C1_TIMINGR_SCLL), 0, 0
#endif
};
