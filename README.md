# ROTARY-ENCODER-INTERFACE-WITH-DISPLAY
A system that uses a rotary encoder to navigate and modify settings in a menu-driven display interface.
# Rotary Encoder Interface with Display

##  Overview
This project implements a menu-driven user interface using a rotary encoder and an ESP32 microcontroller. The system allows users to navigate menus, view parameters, and adjust system settings using rotation and button press actions.

---

## Objective
To design and implement an embedded system that replaces traditional button input with a rotary encoder for:
- Menu navigation
- Parameter adjustment
- User interaction via a display

---

##  Hardware Components
- ESP32 Microcontroller
- Rotary Encoder (with push button)
- OLED Display (I2C / SPI)
- Breadboard & Connecting Wires

---

## System Features

###  Navigation
- Clockwise rotation → Move DOWN
- Counterclockwise rotation → Move UP
- Button press → SELECT / ENTER

---

###  Menu Structure

#### Main Menu
- View Parameters
- Temperature Settings
- Humidity Settings
- Voltage Settings

---

### View Parameters Page
Displays:
- Temperature
- Humidity
- Voltage

---

###  Settings Pages
Each parameter allows:
- Set Low Limit
- Set High Limit

---

## System Logic
- Encoder signals (A & B) detect direction of rotation
- Button press confirms selections
- Values are adjusted using rotation input
- Display updates in real-time

---

##  Project Structure (Git Workflow)
