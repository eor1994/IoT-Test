#!/bin/bash

echo out >/sys/class/gpio/gpio30/direction #output on pin 30

for i in {1..5} #loop 10000 times

do

echo 1 > /sys/class/gpio/gpio30/value #gpio pin 30 on
sleep 1

echo 0 > /sys/class/gpio/gpio30/value #gpio pin 30 off
sleep 1

done #finish and repeat

