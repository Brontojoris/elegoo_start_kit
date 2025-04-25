# Realtime Clock module

## Elegoo Lesson 19

[Uno Starter Kit.pdf > Page 136](../../docs/UNO%20Starter%20Kit.pdf)

### Overview

In this lesson, you will learn how to use the RTC module, The DS1307 real-time clock is a low-power chip.

Address and data are transferred serially through an I2C, which can be used unless being connected to UNO with only three data cables.

DS1307 provides seconds, minutes, hours, day, date, month, and year
information. Timekeeping operation continues while the part operates from the backup supply.

**Components Required:**

* (1) x Elegoo Uno R3
* (1) x DS1307 RTC module
* (4) x F-M wires (Female to Male DuPont wires)

![real time clock module](clock_1.png)

### Wiring Diagram

Set up according to the following image.

Ignore the 32K and SQW pins; you will not need them. Plug the SCL pin into your UNO R3 board SCL port, and the SDA pin into the SDA port.

The VCC pin plugs into the 5V port, and the GND plugs into the GND port.

![Wiring diagram](clock_2.png)

### Updating the DS3231 header

1. When trying to run the provided sample files, I got a number of errors about `ISO C++ forbids converting a string constant to 'char*'`
2. Update the file to match current coding practices using the CLion suggested fixes. See the git history for a summary of the changes.

## Result

![proof](clock.mp4)
