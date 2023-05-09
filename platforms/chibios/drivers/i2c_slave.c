#include "i2c_slave.h"

#ifndef I2C_SLAVE_TIMEOUT
  #define I2C_SLAVE_TIMEOUT 500
#endif

volatile uint8_t i2c_slave_reg[I2C_SLAVE_REG_COUNT];

uint8_t slave_incoming_body= 0;
uint8_t slave_outgoing_body= 0;

void slave_catch_error(I2CDriver *i2cp) {
  dprintf("i2c slave error:%d\n", i2cp->errors);
}

void slave_clear_after_send(I2CDriver *i2cp) {
  slave_outgoing_body = 0; // Clear outgoing message
}

void slave_incoming_message_process(I2CDriver * i2cp) {

  size_t len = i2c_lld_get_rxbytes(i2cp);
  uint8_t buffer_address = slave_incoming_body;
  if((len == 0) || (buffer_address >= I2C_SLAVE_REG_COUNT)) {
    return;
  }

  dprintf("i2c slave addr:%d len:%d\n", buffer_address, len);

  bool isWrite = len > 1;
  if (isWrite) {
    uint8_t * addr =  (uint8_t*) &i2c_slave_reg[buffer_address];
    uint8_t * data =  (uint8_t*) &slave_incoming_body;
    uint16_t length = len - 1;

    memcpy(addr, data, length);
  } else {
    slave_outgoing_body =  i2c_slave_reg[buffer_address];

    // TODO: somehow get request size instead of the following hacks

    // Hack v1 - sniff the requested offset and bodge a mapping to expected size
    //           this incorrectly couples i2c_slave to split transport
    // uint16_t length = 0;
    // if(buffer_address == 0) {
    //   #define ROWS_PER_HAND (MATRIX_ROWS / 2)
    //   //matrix_row_t smatrix[ROWS_PER_HAND];
    //   //length = sizeof(smatrix);
    //   length = sizeof(matrix_row_t) * ROWS_PER_HAND;
    // }

    // Hack v2 - very inefficiently just return the rest of the buffer
    //           ARM i2c_master seems to be happy enough getting extra data...
    uint16_t length = sizeof(i2c_slave_reg) - (buffer_address * sizeof(i2c_slave_reg[0]));

    dprintf("i2c slave read len:%d\n", length);

    //memcpy(slave_outgoing_body, data, length);
    //slave_outgoing_body.size = length;

    i2cSlaveTransmitTimeout(i2cp, &slave_outgoing_body, length, TIME_MS2I(I2C_SLAVE_TIMEOUT));
    slave_catch_error(i2cp);
    slave_clear_after_send(i2cp);
  }
}

void i2c_slave_init(uint8_t address) {
  // Try releasing special pins for a short time
  palSetLineMode(I2C1_SCL_PIN, PAL_MODE_INPUT);
  palSetLineMode(I2C1_SDA_PIN, PAL_MODE_INPUT);

  chThdSleepMilliseconds(10);

#ifdef USE_I2CV1
  palSetLineMode(I2C1_SCL_PIN, PAL_MODE_STM32_ALTERNATE_OPENDRAIN);
  palSetLineMode(I2C1_SDA_PIN, PAL_MODE_STM32_ALTERNATE_OPENDRAIN);
#elif defined(SW_I2C_USE_I2C1)
  palSetLineMode(I2C1_SCL_PIN, PAL_MODE_OUTPUT_PUSHPULL);
  palSetLineMode(I2C1_SDA_PIN, PAL_MODE_OUTPUT_PUSHPULL);
#elif !defined(SN32F2xx)
  palSetLineMode(I2C1_SCL_PIN, PAL_MODE_ALTERNATE(I2C1_SCL_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN);
  palSetLineMode(I2C1_SDA_PIN, PAL_MODE_ALTERNATE(I2C1_SDA_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN);
#endif

  i2cStart(&I2C_DRIVER, &slaveI2Cconfig);

  i2cSlaveReceiveTimeout(&I2C_DRIVER, &slave_incoming_body, I2C_SLAVE_REG_COUNT, TIME_MS2I(I2C_SLAVE_TIMEOUT));
  slave_catch_error(&I2C_DRIVER);
  slave_incoming_message_process(&I2C_DRIVER);
  i2cSlaveMatchAddress(&I2C_DRIVER, (address >> 1));
}

void i2c_slave_stop(void){
  i2cStop(&I2C_DRIVER);
}