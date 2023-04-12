#pragma once

#ifndef I2C1_SCL_PIN
#    define I2C1_SCL_PIN B6
#endif
#ifndef I2C1_SDA_PIN
#    define I2C1_SDA_PIN B7
#endif

#ifdef SN32
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

#ifdef USE_HAL_I2C_FALLBACK
#   ifndef I2C_CLOCK_FREQUENCY
#       define I2C_CLOCK_FREQUENCY 400000
#   endif
#   ifndef SW_I2C_DELAY
#      define SW_I2C_DELAY ceiling(CH_CFG_ST_FREQUENCY / I2C_CLOCK_FREQUENCY / 2)
#   endif
#   ifndef MY_I2C_ADDRESS
#       define MY_I2C_ADDRESS (0x18 << 1)
#endif