#pragma once
/* Master to Slave I2C Connection */
//#define I2C1_SCL_PIN C13
//#define I2C1_SDA_PIN C12

/* RGB Drivers I2C Connection */
#define I2C1_SCL_PIN C9
#define I2C1_SDA_PIN C10

/* RGB Matrix Driver Configuration */
#define DRIVER_COUNT 2
#define DRIVER_ADDR_1 0b1110100
#define DRIVER_ADDR_2 0b1110111

#define DRIVER_1_LED_TOTAL (41 + 4)
#define DRIVER_2_LED_TOTAL 48
#define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

// Connects each switch in the dip switch to the GPIO pin of the MCU
#define DIP_SWITCH_PINS { B13, B14, C8 }
#define MATRIX_ROWS 7