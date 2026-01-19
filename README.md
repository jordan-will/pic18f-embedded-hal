# Embedded PIC18F HAL

This repository provides a reusable **Hardware Abstraction Layer (HAL)** for
**PIC18F microcontrollers**, focusing on clean separation between hardware
details and application logic.

The primary goal of this project is to prevent common embedded firmware issues such as:
- Confusion between active-high and active-low logic
- Mechanical bouncing of buttons
- Tight coupling between hardware and application code

The library is designed to be simple, explicit, and easily extensible.

---

## Provided Drivers

The HAL currently includes four core drivers:

### bit_ops

Low-level bit manipulation utilities.

This module provides `static inline` helper functions for common bit operations:
- `set_bit()`
- `clear_bit()`
- `toggle_bit()`
- `read_bit()`

These functions improve code readability when working with hardware registers
while remaining fully optimized by the compiler. They are intended for use with
LAT, PORT, and TRIS registers.

---

### button

Button abstraction driver.

This module separates:
1. Electrical level (raw pin state)
2. Hardware logic (active-high or active-low)
3. Application behavior

The driver allows application code to work with logical button states instead
of raw electrical signals. Features include:
- Support for active-high or active-low buttons
- Configurable button pins
- Designed to work seamlessly with debounce logic

---

### debounce

Button debounce driver.

This module implements a simple, deterministic debounce mechanism that converts
unstable button signals into reliable press events.

Key features:
- Filters mechanical bouncing
- Generates a single press event per physical action
- Independent from button hardware logic
- Reusable for any digital input

---

### led

LED abstraction driver.

This module provides a high-level API for controlling LEDs without worrying
about whether they are wired as active-high or active-low.

Features include:
- Support for active-high or active-low LEDs
- Centralized LED initialization
- Simple and readable API (`led_on()`, `led_off()`, `led_toggle()`)

---

## Project Structure
```
embedded-pic18f-hal/
├── include/ # Public headers (API)
├── src/ # Driver implementations
├── examples/ # Example applications
└── README.md
```

---

## Design Principles

- Clear separation between hardware and application logic
- Explicit configuration using macros
- Deterministic and predictable behavior
- Simple C code suitable for small microcontrollers
- Easily extendable to additional drivers (timers, UART, I2C, etc.)

---

## Target Platform

- Microcontroller: PIC18F family
- Compiler: XC8
- IDE: MPLAB X

---

## Author

**Jordan Willian Marques Pereira**  
Embedded Systems & Firmware Development
