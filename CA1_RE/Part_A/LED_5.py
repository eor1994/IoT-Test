#!/usr/bin/python

import Adafruit_BBIO.GPIO as GPIO
import time

led = "P9_15"

GPIO.setup(led, GPIO.OUT)

while True:
	GPIO.output(led, GPIO.HIGH)
	time.sleep(1)
	GPIO.output(led, GPIO.LOW)
	time.sleep(1)

