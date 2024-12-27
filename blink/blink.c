#include "pico/stdlib.h"

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 250
#endif

void pico_led_init(void) {
#ifdef PICO_DEFAULT_LED_PIN
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
#endif
}

void pico_led_toggle(bool led_on) {
        gpio_put(PICO_DEFAULT_LED_PIN, led_on);
}

int main() {
    pico_led_init();
    while(true) {
        pico_led_toggle(true);
        sleep_ms(1000);
        pico_led_toggle(false);
    }
    return 0;
}
