cmake_minimum_required(VERSION 3.12)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(copter C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

# Define the main executable and include our source files
add_subdirectory(src/devices)
add_executable(${PROJECT_NAME} src/main.cc)

# Include our first-party libraries
target_link_libraries(${PROJECT_NAME}
  lsm6ds33
  lis3mdl
)
target_include_directories(${PROJECT_NAME} PUBLIC
  ${PROJECT_BINARY_DIR}
  ${PROJECT_SOURCE_DIR}/src/devices
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(${PROJECT_NAME} 
  pico_stdlib
  hardware_i2c
)

# Enable USB serial output, disable UART output
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# For some reason this option needs to be cached when using Unix Makefiles.
# Also means this cmake needs to be run twice before the compile_commands.json
# properly takes effect.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
