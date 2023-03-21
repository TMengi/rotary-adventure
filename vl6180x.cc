#include "vl6180x.h"
#include "stdio.h"

namespace vl6180x {

uint8_t VL6180X::read_model_id() {
  uint8_t model_id{0};
  this->reg_read(reg::MODEL_ID, &model_id, 1);
  return model_id;
}

bool VL6180X::init() {
  uint8_t model_id = this->read_model_id();
  if (model_id != DEFAULT_MODEL_ID) {
    printf("Failed to initialized VL6180X: got model ID %d, expected %d\n",
           model_id, DEFAULT_MODEL_ID);
    return false;
  }
  return true;
}

} // namespace vl6180x
