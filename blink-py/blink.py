from machine import Pin
from utime import sleep

GP15 = 15
GP25 = 25
DELAY = 1

led_external = Pin(GP15, Pin.OUT)
led_internal = Pin(GP25, Pin.OUT)

while True:
    led_external.toggle()
    sleep(DELAY)
    led_internal.toggle()
    sleep(DELAY)
