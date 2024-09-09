#include <avr/io.h>
#include <util/delay.h>
#include <avr/sleep.h>

void setupPWM() {
    // Set PB0 as output
    DDRB |= (1 << PB0);

    // Set Timer0 to Fast PWM mode with non-inverting output on OC0A (PB0)
    // WGM01 and WGM00 set to 1 for Fast PWM, COM0A1 set to 1 for non-inverting
    TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1);

    // Set prescaler to 8 (CS01 bit set to 1)
    TCCR0B |= (1 << CS01);  // CS01 = 1 sets the prescaler to 8

    // Set duty cycle to 50% (OCR0A = 127 for 50% of 255)
    OCR0A = 127;
}

int main() {
    // Let the fan start at 100% for 10s
    _delay_ms(10000);

    // Set the fan speed to 50%
    setupPWM();

    // Set sleep mode to power down
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);

    // Main loop
    while (1) {
        // Enter sleep mode
        sleep_mode();

        // Do nothing, PWM is handled by hardware
    }

    return 0;
}
