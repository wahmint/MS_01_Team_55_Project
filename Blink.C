#include <stdio.h>
#include "pico/stdlib.h"

// Define GPIO pins for the LEDs
#define RED_LED_PIN 6    // GPIO pin for the Red LED (positive logic)
#define GREEN_LED_PIN 7  // GPIO pin for the Green LED (positive logic)
#define BLUE_LED_PIN 8   // GPIO pin for the Blue LED (negative logic)

// Function to initialize the LED GPIO pins
void led_init() {
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);   // Set Red LED as output
    
    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT); // Set Green LED as output
    
    gpio_init(BLUE_LED_PIN);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);  // Set Blue LED as output (negative logic)
}

// Functions to control the Red LED
void led_red_on() {
    gpio_put(RED_LED_PIN, 1); // Turn on Red LED
}
void led_red_off() {
    gpio_put(RED_LED_PIN, 0); // Turn off Red LED
}

// Functions to control the Green LED
void led_green_on() {
    gpio_put(GREEN_LED_PIN, 1); // Turn on Green LED
}
void led_green_off() {
    gpio_put(GREEN_LED_PIN, 0); // Turn off Green LED
}

// Functions to control the Blue LED (negative logic)
void led_blue_on() {
    gpio_put(BLUE_LED_PIN, 0);  // Turn on Blue LED (negative logic)
}
void led_blue_off() {
    gpio_put(BLUE_LED_PIN, 1);  // Turn off Blue LED (negative logic)
}

// Functions to control all LEDs together
void led_all_on() {
    led_red_on();
    led_green_on();
    led_blue_on();
}
void led_all_off() {
    led_red_off();
    led_green_off();
    led_blue_off();
}

// Delay function for milliseconds
void delay_ms(int milliseconds) {
    sleep_ms(milliseconds);  // Sleep for the given number of milliseconds
}

int main() {
    stdio_init_all();  // Initialize standard I/O
    led_init();        // Initialize LED GPIO pins

    // Turn off all LEDs for the first 5 seconds
    led_all_off();
    delay_ms(5000);

    // Continuous 10-second cycle
    while (true) {
        // Turn on Red LED for 1 second, then off
        led_red_on();
        delay_ms(1000);
        led_red_off();
        
        // Turn on Green LED for 1 second, then off
        led_green_on();
        delay_ms(1000);
        led_green_off();
        
        // Turn on Blue LED for 1 second, then off
        led_blue_on();
        delay_ms(1000);
        led_blue_off();
        
        // After all LEDs are off, turn on all LEDs for 2 seconds
        led_all_on();
        delay_ms(2000);
        led_all_off();
        
        // Add a small delay before restarting the cycle
        delay_ms(500);
    }

    return 0;
}
