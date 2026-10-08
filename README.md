# AVR ATmega32 Drivers

A layered driver library in C for the ATmega32 microcontroller, built with Microchip Studio.

## Layers

| Layer | Modules |
| --- | --- |
| **MCAL** (microcontroller abstraction) | DIO (digital I/O), ADC, EXTI (external interrupts), GIE (global interrupt enable), UART |
| **HAL** (hardware abstraction) | 7-segment display, keypad, character LCD, LDR light sensor, multiplexer |
| **Services** | Standard types, bit-manipulation macros, register memory map |

Each driver is split the same way:

- `*_int.h`: the public interface
- `*_prog.c`: the implementation
- `*_cfg.h`: compile-time configuration (pins, modes)
- `*_private.h`: internal definitions

HAL drivers only call MCAL interfaces, never registers directly, so a component can move to other
pins by changing its configuration file.

## Layout

```
AVR-Atmega32/AVR-Atmega32/
  MCAL/      ADC, COMMUNCATION (UART), DIO, EXTI, GIE
  HAL/       7Segement, Keybad, LCD_Charcter, LDR, MUX
  SERVICES/  STDTypes.h, Math.h, MemMap.h
  main.c
```

## Building

Open the project in Microchip Studio and build it for the ATmega32. The circuits can be simulated in
Proteus.
