#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "blink.pio.h"


#ifndef PIO_BLINK_LED_GPIO
#define PIO_BLINK_LED_GPIO PICO_DEFAULT_LED_PIN
#endif


int main() {
    // On RP2040 this is `25`, RP2035 it's on the Wireless chip
    assert(PIO_BLINK_LED_GPIO < 31);

    PIO pio;
    uint sm;
    uint offset;
    uint SLEEP_DELAY_MS = 1000;
    float SM_CLK_FREQ = 2500; // hz

    setup_default_uart();

    // Find an open PIO and state machine on that PIO, add our PIO Assembly Program to it, and specify the GPIO pins
    // which should be mapped/available to the PIO and State Machine
    bool success = pio_claim_free_sm_and_add_program_for_gpio_range(&blink_program, &pio, &sm, &offset, PIO_BLINK_LED_GPIO, 1, true);
    // If the previous statement is not `true`, fail catastrophically.
    hard_assert(success);

    // Some text to STDOUT so we can see something via the Serial Console
    printf("Using gpio %d\n", PIO_BLINK_LED_GPIO);

    // Initialize the state machine and tell it to run our assembly program
    blink_program_init(pio, sm, offset, PIO_BLINK_LED_GPIO, SM_CLK_FREQ);

    // Infinite loop with no break-out condition: DO NOT DO THIS IN PROD!
    while (true) {
        sleep_ms(SLEEP_DELAY_MS);
    }

    // If we do somehow break out of the infinite loop, clean up our PIO
    pio_remove_program_and_unclaim_sm(&blink_program, pio, sm, offset);
}
