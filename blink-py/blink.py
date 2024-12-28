from machine import Pin
from utime import sleep


GP25 = 25 # AKA: "LED"
DELAY = 1


led_internal = Pin(GP25, Pin.OUT)


while True:
    sleep(DELAY)
    led_internal.toggle()