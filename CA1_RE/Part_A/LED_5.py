#!/usr/bin/python

import Adafruit_BBIO.GPIO as GPIO
import time
import sys

led = "P9_15"

GPIO.setup(led, GPIO.OUT)
count = 0

while count < 5:

	GPIO.output(led, GPIO.HIGH)
	time.sleep(0.1)
	GPIO.output(led, GPIO.LOW)
	time.sleep(0.1)

count += 1

sys.exit()
