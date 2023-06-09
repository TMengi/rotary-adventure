#!/usr/bin/bash

# Based on instructions from
# https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf

set -e

print_header() {
  echo
  echo "====================================================================="
  echo "$1"
  echo "====================================================================="
}

cwd="$(pwd)"
root="$(git rev-parse --show-toplevel)"
devel="/home/$(whoami)/devel/"

if [[ ! -e "$devel" ]]; then
  mkdir "$devel"
fi
cd "$devel"

# Install toolchain
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential

# Setup pico-sdk
if [[ ! -e pico ]]; then
  mkdir pico
fi
cd pico
if [[ ! -e pico-sdk ]]; then
  print_header "Cloning Pico SDK"
  git clone https://github.com/raspberrypi/pico-sdk.git --branch master
  cd pico-sdk
  git submodule update --init
  export PICO_SDK_PATH="$devel/pico/pico-sdk"
else
  print_header "Updating Pico SDK"
  cd pico-sdk
  git pull
  git submodule update
fi

# Run initial build
cd "$root/scripts"
print_header "Building project"
./build.sh

echo -e "\n\e[32mBootstrap done\e[0m"

cd "$cwd"
