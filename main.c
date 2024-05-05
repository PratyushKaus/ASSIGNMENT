#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"

#define LED_PIN 9
#define TOGGLE_BUTTON 1

int toggle = 0;

void blinkLed(int count, int delay_ms) {
    for (int i = 0; i < count; i++) {
        gpio_put(LED_PIN, 1);
        sleep_ms(delay_ms);
        gpio_put(LED_PIN, 0);
        sleep_ms(delay_ms);
    }
}

int main() {
#ifndef PICO_DEFAULT_LED_PIN

#else
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_init(TOGGLE_BUTTON);
    gpio_set_dir(TOGGLE_BUTTON, GPIO_IN);
    gpio_pull_up(TOGGLE_BUTTON);

    while (true) {
        
        if (!gpio_get(TOGGLE_BUTTON)) {
            toggle = !toggle;
            sleep_ms(100); 
        }

        
        if (toggle == 0) {
            blinkLed(10, 3000);
            blinkLed(20, 1500);
            blinkLed(30, 1000);
        } else {
            blinkLed(30, 1000);
            blinkLed(20, 1500);
            blinkLed(10, 3000);
        }
    }
#endif
}

