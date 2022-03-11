from machine import Pin
from utime import sleep

GP15 = 15
GP14 = 14

DELAY = 2
PRESSED = 1
ON = 1
OFF = 0

led_external = Pin(GP15, Pin.OUT)
button = Pin(GP14, Pin.IN, Pin.PULL_DOWN)

while True:
    if button.value() == PRESSED:
        led_external.value(ON if led_external.value() is OFF else OFF)
        sleep(DELAY)
