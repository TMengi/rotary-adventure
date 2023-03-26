#include "devices/lis3mdl.h"
#include "devices/lsm6ds33.h"
#include "hardware/i2c.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include <stdlib.h>

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
const uint8_t SDA_PIN{14};
const uint8_t SCL_PIN{15};
i2c_inst_t *i2c = i2c1;

void setup_i2c() {
  uint32_t real_baud = i2c_init(i2c, I2C_SPEED);
  if (real_baud != I2C_SPEED) {
    printf("Could not initialize I2C with baud %d\n", I2C_SPEED);
    exit(-1);
  }
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

  uint8_t model_id{0};
  lsm6ds33::LSM6DS33 lsm = lsm6ds33::LSM6DS33(i2c);
  lis3mdl::LIS3MDL lis = lis3mdl::LIS3MDL(i2c);

  bool success{true};
  success &= lsm.init();
  success &= lis.init();
  auto msg = success ? "success\n" : "failure\n";
  printf(msg);

  while (true) {
    model_id = lsm.read_model_id();
    printf("got model id for lsm: 0x%X (%d)\n", model_id, model_id);

    model_id = lis.read_model_id();
    printf("got model id for lis: 0x%X (%d)\n", model_id, model_id);

    sleep_ms(5000);
  }

  return 0;
}
