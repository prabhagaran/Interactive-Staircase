# Interactive-Staircase
# 🪜 Interactive Motivational Staircase

A fun, sensor-driven, sound-and-light staircase project designed to encourage people to choose stairs over elevators by adding engaging light and audio effects.

## 🎯 Project Objective

This project creates an interactive staircase that responds to user movement with light and sound to:
- Motivate people to climb stairs
- Make the experience engaging and rewarding
- Deliver positive audio feedback at key points

## 🧠 How It Works

The system uses 3 IR sensors positioned at:
- **Entrance**: Detects someone approaching the stairs.
- **Midway**: Detects when a person reaches the middle steps.
- **Top**: Detects the person finishing the climb.

Each detection triggers:
- A **motivational sound** played using a DFPlayer Mini MP3 module.
- A **dedicated LED** for visual feedback.
- A **chaser animation** on the LEDs when no sensors are triggered, keeping the installation dynamic and alive.

## 🎬 Demo Sequence

| Location | Trigger | Action |
|----------|---------|--------|
| Entrance | IR Sensor 1 | LED turns on and sound plays: `"Let's move!"` |
| Midway | IR Sensor 2 | LED turns on and sound plays: `"Your heart is thanking you!"` |
| Top | IR Sensor 3 | LED turns on and sound plays: `"You did it!"` |
| Idle | No sensors triggered | LEDs run a smooth chaser effect continuously |

## 🧩 Hardware Components

- ✅ 1x Arduino Uno / Nano
- ✅ 3x IR Sensors (Digital Output)
- ✅ 3x LEDs (standard or high-brightness)
- ✅ 1x DFPlayer Mini MP3 Module
- ✅ 1x MicroSD card (formatted FAT32)
- ✅ 1x 8Ω Speaker (small, suitable for DFPlayer)
- ✅ Jumper wires, breadboard or PCB
- ✅ Stable 5V Power Supply

## 🗂 Audio Files

Your microSD card should contain:

| File Name | Trigger Location | Message |
|-----------|------------------|---------|
| `0001.mp3` | Entrance | "Let's move!" |
| `0002.mp3` | Midway | "Your heart is thanking you already!" |
| `0003.mp3` | Top | "You did it!" |

Ensure filenames are exact (`0001.mp3`, `0002.mp3`, `0003.mp3`), and the card is FAT32 formatted.

## 🧪 Wiring Summary

| Component | Arduino Pin |
|----------:|:------------|
| IR Sensor 1 | D2 |
| IR Sensor 2 | D3 |
| IR Sensor 3 | D4 |
| LED 1 (Entrance) | D5 |
| LED 2 (Midway) | D6 |
| LED 3 (Top) | D7 |
| DFPlayer RX | D10 |
| DFPlayer TX | D11 |
| DFPlayer VCC | 5V |
| DFPlayer GND | GND |
| Speaker | DFPlayer SPK1 + SPK2 |

## 🧠 Behavior Logic

```plaintext
IF no sensor is triggered:
    LOOP LEDs in chase effect

IF Entrance IR is triggered:
    STOP chase
    PLAY sound 1
    FLASH LED 1
    RESUME chase

IF Midway IR is triggered:
    STOP chase
    PLAY sound 2
    FLASH LED 2
    RESUME chase

IF Top IR is triggered:
    STOP chase
    PLAY sound 3
    FLASH LED 3
    RESUME chase
