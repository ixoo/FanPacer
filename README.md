# Fan Pacer

This project provides a solution to regulate fan speed by sending a PWM signal, allowing you to throttle the fans down to a desired speed, reducing noise and improving usability.

## Overview

I own a Dell C410x GPU enclosure with a faulty fan board that incorrectly detects operational fans as non-operational. As a result, it triggers a fault that forces all eight fans to run at 100%, creating excessive noise. Since the enclosure otherwise works perfectly, I built this solution to throttle the fans down to 50% by using an interceptor board.

Temperature safety is maintained via GPU temperature monitoring, which handles throttling the GPU itself, so there's no risk of overheating.

## Hardware

The hardware folder contains the KiCad schematics and PCB design for a compact board that connects to the fans' 12V power supply and generates a PWM signal to control the fan speed. The PCB is designed to be small enough to fit within the fan structure, without requiring modifications to the enclosure.

## Software

In the software folder, you'll find the AVR C code designed to run on an ATtiny25/45/85 microcontroller. The code generates the necessary PWM signal. At startup, the system waits for 10 seconds before sending the signal, ensuring the fan reaches its full spin before reducing its speed.

## Cost Breakdown

- **12 PCBs** (delivered): $3.50 (via OSHPark)
- **12 ATtiny85**: $10
- **Zener diodes and pull-up resistors**: ~$1
- **Total cost for 12 completed boards**: ~$15
