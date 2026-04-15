# MEMBER 1: ROTARY ENCODER CORE
# Branch: feature/encoder-core

from machine import Pin
import time

# GPIO pins
CLK = Pin(32, Pin.IN)
DT = Pin(33, Pin.IN)
SW = Pin(25, Pin.IN, Pin.PULL_UP)

# Variables
last_clk = CLK.value()
encoder_value = 0
button_pressed = False


# Detect rotation direction
def handle_encoder():
    global last_clk, encoder_value

    current_clk = CLK.value()

    if current_clk != last_clk:

        if DT.value() != current_clk:
            encoder_value += 1   # clockwise
            print("UP")
        else:
            encoder_value -= 1   # counterclockwise
            print("DOWN")

        print("Value:", encoder_value)

    last_clk = current_clk


# Detect button press (with debounce)
def handle_button():
    global button_pressed

    if SW.value() == 0:
        time.sleep_ms(200)  # debounce
        button_pressed = True
        print("BUTTON PRESSED")
    else:
        button_pressed = False


# Main loop
def main():
    global last_clk

    print("Encoder starting...")

    while True:
        handle_encoder()
        handle_button()
        time.sleep_ms(5)


# Run program
main()
