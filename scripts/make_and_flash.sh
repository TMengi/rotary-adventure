#!/usr/bin/bash
set -e

if [[ ! -e "/media/tyler/RPI-RP2/" ]]; then
  echo "RPI-RP2 not detected"
  exit
fi

cwd="$(pwd)"
root="$(git rev-parse --show-toplevel)"
build="$root/build"

cd "$build"
make
sudo cp copter.uf2 /media/tyler/RPI-RP2/

cd "$cwd"
