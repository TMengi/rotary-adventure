#ifndef I2C_DEVICE_H
#define I2C_DEVICE_H

#include "hardware/i2c.h"

namespace i2c_device {

class I2C_DEVICE {
protected:
  // Static I2C hardware instance and slave address
  i2c_inst_t *i2c;
  const uint8_t i2c_addr;

  // Virtual constructor meant to be overloaded
  //
  // Inherited classes should take an i2c_inst_t object and pass their
  // predefined address.
  I2C_DEVICE(i2c_inst_t *i2c, uint8_t addr) : i2c{i2c}, i2c_addr{addr} {};

  // Base methods for reading and writing to various addresses
  //
  // These wrappers first check that the number of bytes to be read/written is
  // at least 1, then write the starting address, and finally read/write
  // to/from the data buffer, returning the number of bytes transmitted.
  virtual int reg_read(uint8_t reg, uint8_t *dst, size_t nbytes);
  virtual int reg_write(uint8_t reg, const uint8_t *src, size_t nbytes);

private:
  // Address a register for reading/writing
  //
  // Assumes more communication will follow (does not terminate the I2C
  // communication).
  //
  // Returns:
  //   Boolean describing if the write was successful.
  bool write_addr(uint8_t reg);
};

} // namespace i2c_device

#endif
