from machine import Pin, RTC
from utime import sleep
from _thread import start_new_thread

GP12 = 12
GP13 = 13
GP14 = 14
GP15 = 15
GP16 = 16
GP25 = 25

ON = 1
OFF = 0

LDELAY = 5
MDELAY = 2
SDELAY = 0.2

rtc = RTC()

led_red = Pin(GP15, Pin.OUT)
led_yellow = Pin(GP14, Pin.OUT)
led_green = Pin(GP13, Pin.OUT)
led_walk = Pin(GP25, Pin.OUT)

button = Pin(GP16, Pin.OUT, Pin.PULL_DOWN)
buzzer = Pin(GP12, Pin.OUT)


global button_pressed
button_pressed = False


def light_cycle():
    led_red.value(ON)
    sleep(MDELAY)
    led_red.value(OFF)
    led_yellow.value(ON)
    sleep(MDELAY)
    led_yellow.value(OFF)
    led_green.value(ON)
    sleep(LDELAY)
    led_green.value(OFF)
    led_yellow.value(ON)
    sleep(MDELAY)
    led_yellow.value(OFF)


def button_reader_thread():
    global button_pressed

    while True:
        if button.value() == ON:
            button_pressed = True
            print(rtc.datetime())
        sleep(SDELAY)


start_new_thread(button_reader_thread, ())


while True:

    if button_pressed == True:
        led_red.value(ON)
        led_walk.value(ON)

        for i in range(10):
            buzzer.value(ON)
            sleep(SDELAY)
            buzzer.value(OFF)
            sleep(SDELAY)
        led_walk.value(OFF)
        global button_pressed
        button_pressed = False

    light_cycle()
