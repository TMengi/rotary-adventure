#ifndef VL6180X_H
#define VL6180X_H

#include "i2c_device.h"

namespace vl6180x {

enum reg: uint8_t {
  I2C_ADDR = 0x29,
  MODEL_ID = 0x00,
};

const uint8_t DEFAULT_MODEL_ID{0xB4};

class VL6180X : i2c_device::I2C_DEVICE {
public:
  VL6180X(i2c_inst_t *i2c) : I2C_DEVICE(i2c, reg::I2C_ADDR){};
  uint8_t read_model_id();
  bool init();
};

} // namespace vl6180x

#endif
