#include "hardware/i2c.h"
#include "vl6180x.h"
#include "stdio.h"

namespace vl6180x {

int reg_write(i2c_inst_t *i2c, uint8_t reg, const uint8_t *buf, size_t nbytes) {
  if (nbytes < 1) {
    return 0;
  }

  printf("writing to register %d\n", reg);
  i2c_write_blocking(i2c, I2C_ADDR, &reg, 1, true);
  int bytes_written = i2c_write_blocking(i2c, I2C_ADDR, buf, nbytes, false);
  printf("write complete\n");
  return bytes_written;
}

int reg_read(i2c_inst_t *i2c, uint8_t reg, uint8_t *buf, size_t nbytes) {
  i2c_write_blocking(i2c, I2C_ADDR, &reg, 1, true);
  int bytes_read = i2c_read_blocking(i2c, I2C_ADDR, buf, nbytes, false);
  return bytes_read;
}

uint8_t read_model_id(i2c_inst_t *i2c) {
  const uint8_t ADDR_MODEL_ID{0x00};
  uint8_t buf[1] = {0x88};
  int bytes_read = reg_read(i2c, ADDR_MODEL_ID, buf, 1);
  printf("read %d bytes\n", bytes_read);
  uint8_t model_id = buf[0];
  printf("got model ID 0x%X (%d)\n", model_id, model_id);
  return model_id;
}

} // namespace vl6180x
