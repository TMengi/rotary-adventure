#include "pico/stdlib.h"
#include <stdio.h>

const uint8_t VL6180X_I2C_ADDR = 0x29;

void blink() {
  const uint LED_PIN = PICO_DEFAULT_LED_PIN;
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  while (true) {
    gpio_put(LED_PIN, 1);
    sleep_ms(250);
    gpio_put(LED_PIN, 0);
    sleep_ms(250);
  }
}

void print_things() {
  stdio_init_all();
  while (true) {
    printf("what the fuck printf\n");
    sleep_ms(1000);
  }
}

int main() { print_things(); }
