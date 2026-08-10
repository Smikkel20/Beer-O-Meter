# Beer-O-Meter

A fun ATTiny-powered device that measures how quickly you can down a pint. Place a glass on the pressure plate, press the button, drink, and release — the 7-segment display shows your elapsed time in centiseconds.

## Features

- **Pressure plate / button trigger** — starts timing when pressed, stops when released.
- **TM1637 4-digit 7-segment display** — shows elapsed time live.
- **Auto-reset** — after a short cooldown, the meter is ready for the next round.
- **KiCad PCB** — custom PCB design included.

## Hardware

| Component | Description |
|-----------|-------------|
| ATTiny85 | 8-bit AVR MCU |
| TM1637 4-digit 7-segment display | Clock & data interface |
| Momentary push button / pressure plate | Input on PB2 (physical pin 7) |
| Wires / custom PCB | Connections as per KiCad design |

### Wiring

| Display / Button Pin | ATTiny85 Pin |
|----------------------|--------------|
| TM1637 CLK | PB4 (physical pin 3) |
| TM1637 DIO | PB3 (physical pin 2) |
| Button (pressure plate) | PB2 (physical pin 7) |

## Usage

1. Power the PCB.
2. Place your glass on the pressure plate.
3. Pick up the glass and start drinking!
4. Put down the glass on the pressure plate when its empty.
5. The display shows your time!

## Building & Flashing

Install the ATTiny85 core (e.g. via [ATTinyCore](https://github.com/SpenceKonde/ATTinyCore)) and flash with your programmer (USBasp, AVRISP mkII, Arduino-as-ISP, etc.):

```bash
arduino-cli compile --fqbn attiny:avr:attiny85 Beer-O-Meter/
arduino-cli upload -p /dev/ttyUSB0 --fqbn attiny:avr:attiny85 Beer-O-Meter/
```

Or open `Beer-O-Meter/Beer-O-Meter.ino` in the Arduino IDE with the ATTiny85 board selected and upload.

## PCB Design

The `PCB-Design/` folder contains the KiCad project files:

- `Beer-Timer.kicad_sch` — schematic
- `Beer-Timer.kicad_pcb` — PCB layout
- `Beer-Timer.kicad_pro` — project settings
- `Beer-Timer.step` / `Beer-Timer.stl` — 3D models

Open the `.kicad_pro` file in KiCad 7+ to view or modify the design.

## License

This project is licensed under the GNU General Public License v3.0 — see [LICENSE](LICENSE).
