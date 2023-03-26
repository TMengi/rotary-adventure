set(LSM6DS33_NAME lsm6ds33)
add_library(${LSM6DS33_NAME}
  lsm6ds33.cc
  i2c_device.cc
)
target_link_libraries(${LSM6DS33_NAME}
  pico_stdlib
  hardware_i2c
)

set(LIS3MDL_NAME lis3mdl)
add_library(${LIS3MDL_NAME}
  lis3mdl.cc
  i2c_device.cc
)
target_link_libraries(${LIS3MDL_NAME}
  pico_stdlib
  hardware_i2c
)
