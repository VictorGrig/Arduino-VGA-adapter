##Arduino Mega 2560 R3 VGA adapter

Original project: [Marcelo Rodrigues](http://garagelab.com/profiles/blogs/arduino-generated-vga-color-signal-complete)

You can find there:
- AD 14.3 PCB project
- C source code for AVR MCU

---
Bill of materials:

Value        |Description|Designator|Quantity
:------------|:----------|:---------|:-------
1N4148       |Diode      |D1..D3    |3
470 Ohm 1/4W |Resistor   |R1..R3    |3
75 Ohm 1/2W  |Resistor   |R4..R4    |3
1kOhm 1/4W   |Resistor   |R7, R8    |2
PLS-7        |Pin header |XP1       |1
D-SUB DHR-15F|VGA adapter|XS1       |1

---
You can easily modify source code for getting compability with yours MCU. It doesn't matter what kind of Arduino you have. Go to [Atmel's website](http://www.atmel.com/products/microcontrollers/avr/default.aspx), find appropriate MCU, find your board's pinout and find register references for digital ports **12** - **8**. Table for **Arduino Mega 2560 R3** is below.

Board|Register|Title   |PCB
:----|:-------|:-------|:--
GND  |GND     |GND     |GND
13   |PB7     |Not used|GND
12   |PB6     |R       |R
11   |PB5     |G       |G
10   |PB4     |B       |B
9    |PH6     |HSYNC   |H
8    |PH5     |VSYNC   |V