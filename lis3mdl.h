#ifndef LIS3MDL_H
#define LIS3MDL_H

#include "i2c_device.h"

namespace lis3mdl {

enum reg : uint8_t {
  I2C_ADDR = 0x1C,
  WHO_AM_I = 0x0F,
};

const uint8_t DEFAULT_MODEL_ID{0x3D};

class LIS3MDL : i2c_device::I2C_DEVICE {
public:
  LIS3MDL(i2c_inst_t *i2c) : i2c_device::I2C_DEVICE(i2c, reg::I2C_ADDR){};
  uint8_t read_model_id();
  bool init();
};

} // namespace lis3mdl

#endif
