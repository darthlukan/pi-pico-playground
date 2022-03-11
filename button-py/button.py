from machine import Pin
from utime import sleep

GP14 = 14
DELAY = 2
PRESSED = 1

button = Pin(GP14, Pin.IN, Pin.PULL_DOWN)

while True:
    if button.value() == PRESSED:
        print("Pressed!")
        sleep(DELAY)
