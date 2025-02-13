#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN_1 = 26;
const int BTN_PIN_2 = 7;

bool debounce(int pin) {
    if (!gpio_get(pin)) {  
        sleep_ms(50);      
        if (!gpio_get(pin)) {  
            return true;   
        }
    }
    return false;
}

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN_1);
    gpio_set_dir(BTN_PIN_1, GPIO_IN);
    gpio_pull_up(BTN_PIN_1);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);
    int cnt_1 = 0;
    int cnt_2 = 0;

    while (true) {
        if (debounce(BTN_PIN_1)) {
            printf("Botao 1: %d\n", cnt_1);
            ++cnt_1;  
            while (!gpio_get(BTN_PIN_1));  
        }

        if (debounce(BTN_PIN_2)) {
            printf("Botao 2: %d\n", cnt_2);
            ++cnt_2;
            while (!gpio_get(BTN_PIN_2));
        }
    }
}
