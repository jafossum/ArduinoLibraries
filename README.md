# ArduinoLibraries
Collection of ArduinoLibraries developed with VisualMicro.

Collection of different .cpp and .h libraries for different Arduino use.

For the functionality of the different Libraries, look in the subfolders.

## JAF_FrequencyScheduler

This library chedules appended tasks (methods) at a given tickCount based on the set frequence.

This works repetitive, so there is no need to re-append task after it has been performed.

Methods and frequenceies are provided at startup.

## JAF_MavLink

[MavLink](http://www.qgroundcontrol.org/mavlink/start) based library containing my own implementation 
of the MavLink protocoll using the MavLink [mavgenerate](https://github.com/mavlink/mavlink) for C++ 
projects.

This will be an ongoing project with MavLink methods added as they are needed into my own MavLink definition 
files.

## JAF_EscController

Library with inheritance from built in Arduino Library [Servo](https://www.arduino.cc/en/Reference/Servo).

This will be used together with **JAF_FrequencyScheduler** in a set frequency to set PWM signals to ESCs connected
to defined pins.

## JAF_Watchdog

Library that wraps the default *<avr/wdt.h>* Watchdog lib for Arduino. This is for easyer extension on Watchdog functionality later. 