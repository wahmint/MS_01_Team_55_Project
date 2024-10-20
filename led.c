#include "led.h"
#include "pico/stdlib.h"

// Pin Definitions
#define RED_PIN 6
#define GREEN_PIN 7
#define BLUE_PIN 8

// Function to initialize the LEDs
void led_init() {
    gpio_init(RED_PIN);
    gpio_set_dir(RED_PIN, GPIO_OUT);
    
    gpio_init(GREEN_PIN);
    gpio_set_dir(GREEN_PIN, GPIO_OUT);
    
    gpio_init(BLUE_PIN);
    gpio_set_dir(BLUE_PIN, GPIO_IN); // Set blue pin as input to pull-up
}

// Turn on the Red LED
void led_on_red() {
    gpio_put(RED_PIN, 1);
}

// Turn off the Red LED
void led_off_red() {
    gpio_put(RED_PIN, 0);
}

// Turn on the Green LED
void led_on_green() {
    gpio_put(GREEN_PIN, 1);
}

// Turn off the Green LED
void led_off_green() {
    gpio_put(GREEN_PIN, 0);
}

// Turn on the Blue LED
void led_on_blue() {
    gpio_put(BLUE_PIN, 0); // Active low
}

// Turn off the Blue LED
void led_off_blue() {
    gpio_put(BLUE_PIN, 1); // Active low
}

// Turn on all LEDs
void led_on_all() {
    led_on_red();
    led_on_green();
    led_on_blue();
}

// Turn off all LEDs
void led_off_all() {
    led_off_red();
    led_off_green();
    led_off_blue();
}
