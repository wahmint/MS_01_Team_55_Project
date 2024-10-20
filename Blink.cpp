#include <stdio.h>
#include "pico/stdlib.h"
#include "led.h"

int main() {
    // Define pin numbers
    const uint red_led_pin = 6;    // Red LED in positive logic
    const uint green_led_pin = 7; // Green LED in positive logic
    const uint blue_led_pin = 8;  // Blue LED in negative logic

    // Initialize standard I/O (for debugging purposes)
    stdio_init_all();

    // Initialize the LEDs
    init_leds(red_led_pin, green_led_pin, blue_led_pin);

    // Main loop
    while (true) {
        // Step 1: Turn off all LEDs for the first 5 seconds
        led_off(red_led_pin, false);   // Red LED off (active-high)
        led_off(green_led_pin, false); // Green LED off (active-high)
        led_off(blue_led_pin, true);   // Blue LED off (active-low)
        sleep_ms(5000);

        // Step 2: Sequentially turn on the LEDs
        // Red LED on for 1 second
        led_on(red_led_pin, false);
        sleep_ms(1000);
        led_off(red_led_pin, false);

        // Green LED on for 1 second
        led_on(green_led_pin, false);
        sleep_ms(1000);
        led_off(green_led_pin, false);

        // Blue LED on for 1 second (active-low logic)
        led_on(blue_led_pin, true);
        sleep_ms(1000);
        led_off(blue_led_pin, true);

        // Step 3: Turn on all LEDs for 2 seconds
        led_on(red_led_pin, false);    // Red LED on
        led_on(green_led_pin, false);  // Green LED on
        led_on(blue_led_pin, true);    // Blue LED on (active-low)
        sleep_ms(2000);

        // Turn off all LEDs
        led_off(red_led_pin, false);
        led_off(green_led_pin, false);
        led_off(blue_led_pin, true);

        // Repeat cycle
    }
}
