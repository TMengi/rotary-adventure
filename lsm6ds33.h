#ifndef LSM6DS33_H
#define LSM6DS33_H

#include "i2c_device.h"

namespace lsm6ds33 {

const uint8_t I2C_ADDR{0x6A};
const uint8_t DEFAULT_MODEL_ID{0x69};

enum reg : uint8_t {
  WHO_AM_I = 0x0F,
};

class LSM6DS33 : i2c_device::I2C_DEVICE {
public:
  LSM6DS33(i2c_inst_t *i2c) : i2c_device::I2C_DEVICE(i2c, I2C_ADDR){};
  uint8_t read_model_id();
  bool init();
};

} // namespace lsm6ds33

#endif
