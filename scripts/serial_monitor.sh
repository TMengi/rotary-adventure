#!/usr/bin/bash
set -e

while true; do
  if [[ -e "/dev/ttyACM0" ]]; then
    sudo screen /dev/ttyACM0 115200
  fi
  sleep 1
done
