#include "lis3mdl.h"
#include <stdio.h>

namespace lis3mdl {

uint8_t LIS3MDL::read_model_id() {
  uint8_t model_id{0};
  this->reg_read(reg::WHO_AM_I, &model_id, 1);
  return model_id;
}

bool LIS3MDL::init() {
  uint8_t model_id = this->read_model_id();
  if (model_id != DEFAULT_MODEL_ID) {
    printf("Failed to initialize LIS3MDL: got model ID 0x%X, expected 0x%X\n",
           model_id, DEFAULT_MODEL_ID);
    return false;
  }
  return true;
}

} // namespace lis3mdl
