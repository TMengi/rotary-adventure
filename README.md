# Rotary Adventure

Driver code for a homemade quadcopter powered by a Raspberry Pi Pico.

Or at least it will be one day. Just a skeleton right now while I design
hardware and get the dev environment set up.

## Install
- If you have not already, install the Raspberry Pi Pico C/C++ SDK using the
  instructions in [Getting started with Raspberry Pi
  Pico](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).
- Clone the repo and run the build script:
  ```bash
  git clone https://github.com/TMengi/rotary-adventure.git
  cd rotary-adventure
  ./build.sh
  ```
  - If the first run prints out a warning about not being able to find
    `compile_commands.json`, try running it one more time. This is necessary
    due to some caching behavior when running CMake using Unix Makefiles.
  - If the script continues to display the same warnings, you can still
    proceed, but your editor may not be able to recognize imports from the Pico
    libaries.

## Uploading to hardware
- Obtain a Raspberry Pi Pico.
- Hold the `BOOTSEL` button and plug the Pico into a computer. The board should
  be recognized as a mass storage device.
- Copy the `build/copter.uf2` to the root directory of the Pico. The board
  should automatically restart and begin executing the main loop.
