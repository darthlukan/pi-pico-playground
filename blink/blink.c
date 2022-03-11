#include "pico/stdlib.h"

void led_on(uint pin) {
        gpio_put(pin, true);
}

void led_off(uint pin) {
        gpio_put(pin, false);
}

int main() {
    const uint onboard_led_pin = 25;
    const uint offboard_led_pin = 16;
    gpio_init(onboard_led_pin);
    gpio_init(offboard_led_pin);
    gpio_set_dir(onboard_led_pin, GPIO_OUT);
    gpio_set_dir(offboard_led_pin, GPIO_OUT);

    while(true) {
        led_on(onboard_led_pin);
        sleep_ms(1000);
        led_off(onboard_led_pin);
        led_on(offboard_led_pin);
        sleep_ms(1000);
        led_off(offboard_led_pin);
    }
    return 0;
}
