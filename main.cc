#include "hardware/i2c.h"
#include "pico/stdlib.h"
#include "vl6180x.h"
#include <stdio.h>

void blink() {
  const uint8_t LED_PIN = PICO_DEFAULT_LED_PIN;
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  while (true) {
    gpio_put(LED_PIN, 1);
    sleep_ms(250);
    gpio_put(LED_PIN, 0);
    sleep_ms(250);
  }
}

const uint32_t I2C_SPEED{100'000};
const uint8_t SDA_PIN{16};
const uint8_t SCL_PIN{17};
i2c_inst_t *i2c{i2c0};

void setup_i2c() {
  printf("initializing i2c with %d baud\n", I2C_SPEED);
  i2c_init(i2c, I2C_SPEED);
  gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
  gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
  gpio_pull_up(SDA_PIN);
  gpio_pull_up(SCL_PIN);
}

int main() {
  stdio_init_all();
  sleep_ms(3000);
  setup_i2c();

  const uint8_t led_pin = PICO_DEFAULT_LED_PIN;
  gpio_init(led_pin);
  gpio_set_dir(led_pin, GPIO_OUT);
  gpio_put(led_pin, 1);

  printf("trying to write register\n");
  int model_id{0};
  uint8_t data[] = {0xB4};
  printf("data is 0x%X\n", data[0]);
  int bytes_written = vl6180x::reg_write(i2c, 0x00, data, 1);
  printf("wrote %d bytes\n", bytes_written);
  while (true) {
    model_id = vl6180x::read_model_id(i2c);
    sleep_ms(1000);
  }

  return 0;
}
