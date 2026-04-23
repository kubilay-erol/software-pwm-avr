# Bare-Metal Software PWM on Arduino Uno

This project demonstrates **Software Pulse Width Modulation (PWM)** by directly accessing the ATmega328P registers. 

### How it Works
Instead of using the built-in `analogWrite()`, this code manually toggles **Digital Pin 11 (PB3)** and uses a `volatile` delay loop to control the duty cycle, creating a "breathing" LED effect.

### Hardware Setup
- **Board:** Arduino Uno (ATmega328P)
- **Component:** LED connected to **Digital Pin 11** (with a 220Ω resistor).

### Register Map Used
| Register | Address | Purpose |
|----------|---------|---------|
| DDRB     | 0x24    | Data Direction (Sets Pin 11 as Output) |
| PORTB    | 0x25    | Data Register (Toggles Pin HIGH/LOW) |
