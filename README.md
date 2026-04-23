# Software PWM LED Fader (Bare-Metal AVR)

A low-level implementation of **Pulse Width Modulation (PWM)** for the ATmega328P (Arduino Uno). This project demonstrates how to create a "breathing" LED effect by bypassing standard Arduino libraries and interacting directly with hardware registers using memory-mapped I/O.

---

## 🚀 Overview

While most Arduino sketches use `analogWrite()`, this project takes a **bare-metal** approach. It manually toggles a digital pin and manages timing via `volatile` delay loops to control the LED's duty cycle.

### Key Technical Concepts
* **Direct Register Manipulation:** Accesses hardware via specific memory addresses (`0x24` for DDRB, `0x25` for PORTB).
* **Software PWM:** Toggles the pin state faster than the human eye can perceive to simulate variable voltage.
* **Compiler Optimization Guard:** Uses the `volatile` keyword to ensure delay loops are not optimized away by the compiler.

---

## 🛠 Hardware Configuration

To see the fading effect, connect an LED to the following pin:

| Component | Arduino Pin | AVR Port/Bit | Register Address |
| :--- | :--- | :--- | :--- |
| **LED (+) Anode** | Digital Pin 11 | **PB3** (Port B, Bit 3) | `0x25` (PORTB) |
| **Resistor** | 220Ω | N/A | N/A |
| **LED (-) Cathode** | GND | Ground | N/A |

---

## 💻 How It Works

The code simulates PWM by dividing time into a **period** (1000 units):

1.  **Initialization:** The Data Direction Register (**MY_DDRB**) is configured to set Pin 11 (PB3) as an output using bitwise OR (`|= 0x08`).
2.  **The Duty Cycle:** The `brightness` variable determines how long the LED stays HIGH vs. LOW within the fixed period.
3.  **Fading Logic:** * The code increments the `brightness` until it reaches 1000.
    * It then decrements it back to 0.
    * This creates a smooth "breathing" pulse.
4.  **Delays:** The `tiny_delay` function uses a `volatile` counter to prevent the compiler from optimizing out the "empty" timing loops.

---
