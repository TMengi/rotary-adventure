#include "lsm6ds33.h"
#include "stdio.h"

namespace lsm6ds33 {

uint8_t LSM6DS33::read_model_id() {
  uint8_t model_id{0};
  this->reg_read(reg::WHO_AM_I, &model_id, 1);
  return model_id;
}

bool LSM6DS33::init() {
  uint8_t model_id = this->read_model_id();
  if (model_id != DEFAULT_MODEL_ID) {
    printf("Failed to initialize LSM6DS33: got model ID 0x%X, expected 0x%X\n",
           model_id, DEFAULT_MODEL_ID);
    return false;
  }
  return true;
}

} // namespace lsm6ds33
