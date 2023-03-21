#include "i2c_device.h"

namespace {
  bool positive(int n) {
    return n > 0;
  }
}

namespace i2c_device {

int I2C_DEVICE::reg_read(uint8_t reg, uint8_t *dst, size_t nbytes) {
  if (!positive(nbytes)) {
    return 0;
  }

  this->write_addr(reg);
  int bytes_read =
      i2c_read_blocking(this->i2c, this->i2c_addr, dst, nbytes, false);
  return bytes_read;
}

int I2C_DEVICE::reg_write(uint8_t reg, const uint8_t *src, size_t nbytes) {
  if (positive(nbytes)) {
    return 0;
  }

  this->write_addr(reg);
  int bytes_written =
      i2c_write_blocking(this->i2c, this->i2c_addr, src, nbytes, false);
  return bytes_written;
}

bool I2C_DEVICE::write_addr(uint8_t reg) {
  return i2c_write_blocking(this->i2c, this->i2c_addr, &reg, 1, true);
}

} // namespace i2c_device
