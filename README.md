# Rotary Adventure

Driver code for a homemade quadcopter powered by a Raspberry Pi Pico.

Or at least it will be one day. Just a skeleton right now while I design
hardware and get the dev environment set up.

## Install
- Clone this repository into `~/devel/`
- Run `bootstrap.sh` to install the Raspberry Pi Pico C/C++ SDK
- Run `build.sh` to finish building the code
  - If the first run prints out a warning about not being able to find
    `compile_commands.json`, try running it one more time. This is necessary
    due to some caching behavior when running CMake using Unix Makefiles.
  - If the script continues to display the same warnings, you can still
    proceed, but your editor may not be able to recognize imports from the Pico
    libaries.

## Building the code
For changes that add new source files and libraries, rerun `build.sh`.

For normal code changes and updates, navigate to the `build/` directory and run
the `make` command.

## Uploading to hardware
- Obtain a Raspberry Pi Pico.
- Hold the `BOOTSEL` button and plug the Pico into a computer. The board should
  be recognized as a mass storage device.
- Run `make_and_flash.sh` to build the code and flash it to the Pico in one
  step. The board should automatically restart and begin executing the main
  loop. If you do not want to rebuild the code, simply copy the existing
  `build/copter.uf2` to the root directory of the Pico.

## Serial monitoring
When connected with the `BOOTSEL` pin not depressed, the Pico should show up as
a USB ACM device. This can be verified with `sudo dmesg | tail`. Once the
device is connected, a session can be opened to monitor the serial port with
`sudo screen /dev/ttyACM0 115200` (your port may be slightly different, just
use what is shown in `dmesg`).

To avoid repeatedly calling `screen`, you can leave `serial_monitoring.sh`
running in a separate terminal to automatically open a serial monitor every
time a device becomes available.
