#ifndef VL6180X_H
#define VL6180X_H

#include "hardware/i2c.h"
#include "pico/stdlib.h"

namespace vl6180x {

const uint8_t I2C_ADDR{0x29};

int reg_write(i2c_inst_t *i2c, uint8_t reg, const uint8_t *buf, size_t nbytes);

int reg_read(i2c_inst_t *i2c, uint8_t reg, uint8_t *buf, size_t nbytes);

uint8_t read_model_id(i2c_inst_t *i2c);

} // namespace vl6180x

#endif
