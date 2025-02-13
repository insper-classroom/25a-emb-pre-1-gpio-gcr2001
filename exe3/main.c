#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN1 = 28;
const int BTN_PIN2 = 26;

const int LED_PIN_1 = 4;
const int LED_PIN_2 = 6;

int main() {
  stdio_init_all();

  // botao
  gpio_init(BTN_PIN1);
  gpio_set_dir(BTN_PIN1, GPIO_IN);
  gpio_pull_up(BTN_PIN1);

  gpio_init(BTN_PIN2);
  gpio_set_dir(BTN_PIN2, GPIO_IN);
  gpio_pull_up(BTN_PIN2);

  // Led
  gpio_init(LED_PIN_1);
  gpio_set_dir(LED_PIN_1, GPIO_OUT);

  gpio_init(LED_PIN_2);
  gpio_set_dir(LED_PIN_2, GPIO_OUT);

  bool LED1 = false;
  bool LED2 = false;

  while (true) {
    if (!gpio_get(BTN_PIN1)) { 
      LED1 = !LED1; // inverte led1
      gpio_put(LED_PIN_1, LED1); 

      while (!gpio_get(BTN_PIN1)); 
      sleep_ms(10); 
    }

    if (!gpio_get(BTN_PIN2)) {
      LED2 = !LED2; // inverte led2
      gpio_put(LED_PIN_2, LED2);

      while (!gpio_get(BTN_PIN2));
      sleep_ms(10);
    }
  }
}
