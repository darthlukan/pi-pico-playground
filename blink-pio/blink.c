#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "blink.pio.h"

void blink_pin_forever(PIO pio, uint sm, uint offset, uint pin, uint freq);

#ifndef PIO_BLINK_LED_GPIO
#define PIO_BLINK_LED_GPIO PICO_DEFAULT_LED_PIN
#endif

int main() {
    assert(PIO_BLINK_LED_GPIO < 31);

    PIO pio;
    uint sm;
    uint offset;

    setup_default_uart();

    bool success = pio_claim_free_sm_and_add_program_for_gpio_range(&blink_program, &pio, &sm, &offset, PIO_BLINK_LED_GPIO, 1, true);
    hard_assert(success);

    printf("Using gpio %d\n", PIO_BLINK_LED_GPIO);
    blink_program_init(pio, sm, offset, PIO_BLINK_LED_GPIO);

    while (true) {
        pio_sm_put_blocking(pio, sm, 1);
        printf("GPIO %d is on\n", PIO_BLINK_LED_GPIO);
        sleep_ms(1000);
        pio_sm_put_blocking(pio, sm, 0);
        printf("GPIO %d is off", PIO_BLINK_LED_GPIO);
        sleep_ms(1000);
    }

    pio_remove_program_and_unclaim_sm(&blink_program, pio, sm, offset);
}
