# TimerAVR
In AVR microcontrollers, timers are essential hardware components used for various timing and control purposes. AVR microcontrollers typically include several timer modules, such as Timer/Counter 0 (T0), Timer/Counter 1 (T1), and Timer/Counter 2 (T2), which can be configured to perform different tasks like generating delays, measuring time intervals, and generating PWM signals. Here's an overview of timers in AVR microcontrollers:

1. **Timer/Counter Modes:**
   AVR timers can operate in various modes, including:
   - Normal Mode: Counts up to a maximum value and then overflows.
   - CTC (Clear Timer on Compare Match) Mode: Generates an interrupt or toggles an output pin when the timer matches a predefined value.
   - PWM (Pulse-Width Modulation) Mode: Used to generate PWM signals for applications like motor control and LED dimming.

2. **Prescaler:**
   AVR timers often have a prescaler that divides the clock frequency. This feature is useful for achieving lower time resolution or for power-saving.

3. **Interrupts:**
   Timers can trigger interrupts when they overflow or reach a specific value in CTC mode. These interrupts are useful for creating accurate time-based actions in your code.

4. **Input Capture:**
   Some timers allow capturing external events like pulses or frequency measurements.

5. **Output Compare Unit (OCU):**
   Timers may include output compare units that can be configured to perform actions when specific timer values are reached, such as generating PWM waveforms.

6. **16-Bit vs. 8-Bit Timers:**
   AVR microcontrollers often include both 8-bit and 16-bit timers. 16-bit timers have a larger counting range and are suitable for longer timing intervals.

7. **Timer/Counter Registers:**
   To use timers, you need to configure various registers associated with each timer. These registers control the timer's mode, prescaler, output compare values, and more.

8. **Clock Sources:**
   Timers can use various clock sources, such as the system clock or an external clock source. You can configure these sources based on your requirements.

Here's a simple example of setting up and using an 8-bit timer (Timer/Counter 0) in CTC mode on an AVR microcontroller:

```c
#include <avr/io.h>
#include <avr/interrupt.h>

void timer0_init() {
    // Set CTC mode with OCR0 as the top value
    TCCR0 |= (1 << WGM01);

    // Set prescaler to 64
    TCCR0 |= (1 << CS01) | (1 << CS00);

    // Set the value to compare against (e.g., 250 for 1 ms at 8 MHz clock)
    OCR0 = 250;

    // Enable Timer/Counter 0 Compare Match A interrupt
    TIMSK |= (1 << OCIE0);
}

ISR(TIMER0_COMPA_vect) {
    // This function will be called when Timer 0 reaches the set value (1 ms delay).
}

int main() {
    // Initialize timer
    timer0_init();

    // Enable global interrupts
    sei();

    while (1) {
        // Your main code here
    }

    return 0;
}
```

This code sets up Timer 0 in CTC mode to generate a 1 ms interrupt and illustrates the fundamental steps involved in configuring and using timers on AVR microcontrollers. The specific registers and settings may vary depending on the microcontroller model you are working with.
