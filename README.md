IoT Smart Incubator Module <a name="TOP"></a>
===================

## Table of Contents
* [Introduction](#Introduction)
* [Features](#Features)
* [Tools Used](#Tools-Used)
  * [Arduino IDE](#Arduino-IDE)
  * [Fritzing](#Fritzing)
  * [Blynk IoT](#Blynk_IoT)
* [Hardware Components Used](#Hardware-Components-Used)
* [Microcontroller Specifications](#Microcontroller-Specifications)
* [Schematic](#Schematic)
* [Completed Hardware Assembly](#Completed-Hardware-Assembly)
* [Blynk IoT Mobile Dashboard (Mobile Application)](#Blynk-IoT-Mobile-Dashboard-(Mobile-Application))
* [References](#References)

## Introduction
#### What is an Infant Incubator and why is it required?
An infant incubator is a medical device that provides a controlled environment for premature or ill newborns. It is required to regulate temperature, humidity, and oxygen levels, mimicking the conditions of the mother's womb. This controlled setting supports the development of underdeveloped organs and reduces the risks associated with premature birth, improving the chances of survival and healthy growth for vulnerable newborns.

#### Objective of the Project
The primary objective of this project is to develop a smart module for incubators, empowered with the capability to transmit comprehensive health and environmental data concerning the infant inside the incubator through the Internet of Things (IoT). This innovative module aims to enhance the monitoring and management of vital parameters related to the infant's well-being and surroundings, providing real-time insights for efficient healthcare.

#### Motivation
Mostly all existing warmers/incubators are manually operated, i.e., all readings have to be manually collected and stored for numerous infants. Our project aims to eliminate such tedious tasks as all readings will be collected automatically and sent to the respective parents/guardians on their mobile phones. Similarly, any sudden drop or rise in any parameters will automatically alert the respective contact.

## Features
The IoT Module is equipped with the following features:
* Heart Rate monitoring
* SpO2 monitoring
* Body Temperature monitoring
* Room Temperature monitoring
* Room Humidity monitoring
* Fever or high body temperature detection

## Unique Features
* Works on the Internet of Things, and hence health parameters of the infant can be monitored from anywhere in the world with the help of an Internet connection.
* Parameter monitoring using the Blynk Mobile App
* All health-related data is forwarded to the application in real-time using the Blynk IoT Server.
* Equipped with a 2000mAh rechargeable lithium-ion backup battery which serves as a backup in case of power outages.

## Tools Used
#### Arduino IDE 
Arduino Integrated Development Environment or Arduino Software (IDE) contains a text editor for writing code, a message area, a text console, a toolbar with buttons for common functions and a series of menus. It connects to the Arduino hardware to upload programs and communicate with them. 
* For more details refer: <https://www.arduino.cc/en/software>

#### Fritzing
Fritzing is an open-source hardware initiative that makes electronics accessible as creative material for anyone. We offer a software tool, a community website and services in the spirit of Processing and Arduino, fostering a creative ecosystem that allows users to document their prototypes, share them with others, teach electronics in a classroom, and layout and manufacture professional PCBs. 
* For more details refer: <https://fritzing.org/>

#### Blynk IoT
Blynk is an IoT platform that simplifies the development of IoT projects. It provides a mobile app and cloud service, allowing users to design interfaces for controlling and monitoring connected devices easily. Blynk supports various hardware platforms and offers a user-friendly drag-and-drop interface for creating IoT applications.
* For more details refer: <https://blynk.io/>

## Hardware Components Used
1. Nodemcu ESP8266 microcontroller
2. MAX30102 Heart rate and SpO2 sensor
3. MQ2 Air Quality sensor
4. DS18B20 Digital temperature sensor
5. DHT11 Temperature and Humidity sensor
6. 16x2 I2C LCD Display
7. LM2596 DC-DC Buck Converter
8. 5V Piezo Buzzer
9. DC 5V 1A Power Bank Module
10. 18650 2000mAh Li-Ion Battery

## Microcontroller Specifications
Espressif System's ESP8266 microcontroller has the following specifications:
* Tensilica 32-bit RISC CPU Xtensa LX106
* Operating Voltage: 3.3V
* Input Voltage: 7-12V
* Digital I/O Pins: 16
* Analog Input Pins (ADC): 1
* Peripherals Interfaces: 1 - UART, 1 - SPI, and 1 - I2C
* Flash Memory: 4 MB, SRAM: 64KB
* Clock Speed: 80 MHz
* 802.11 n support (2.4 GHz ~ 2.5 GHz), up to 72.2 Mbps 
* USB-TTL based on CP2102 is included onboard, Enabling Plug-n-Play
* Onboard PCB Antenna

## Microcontroller Interfacing
* Used I2C protocol to interface the microcontroller to:
  1. MAX30100 Heart rate and Pulse Oximeter sensor for Heart rate and SpO2 monitoring.
  3. 16x2 LCD Display for displaying all the measured parameters.
* Used WiFi (2.4GHz) for Connectivity with the Blynk Mobile Application.
* Used the OneWire protocol to interface the DS18B20 Digital temperature sensor to monitor the body temperature.
* Used the ESP8266's digital I/O pin to read the DHT11 Temperature and Humidity sensor data for monitoring the room temperature and humidity.
* Used the ESP8266's digital I/O pin to turn ON/OFF the piezo buzzers.

## Schematic
![image](https://github.com/Nirvan007/IoT_Smart_Incubator_Module/assets/127144315/b0921243-ba35-40d0-89d7-f3b712425e40)

## Completed Hardware Assembly
![image](https://github.com/Nirvan007/IoT_Smart_Incubator_Module/assets/127144315/193a112a-81e4-4900-9889-9efb57aa9d6a)

## Blynk IoT Mobile Dashboard (Mobile Application)
#### Parameter Display
![image](https://github.com/Nirvan007/IoT_Smart_Incubator_Module/assets/127144315/54f7a057-8d4b-40f1-ba87-77b2ba2793dc)
![image](https://github.com/Nirvan007/IoT_Smart_Incubator_Module/assets/127144315/4ce4663c-3381-437e-a28e-37d6e91ef1ee)

## References
 - [1] https://www.analog.com/en/products/max30100.html
 - [2] https://ieeexplore.ieee.org/document/8540606
 - [3] https://www.analog.com/media/en/technical-documentation/data-sheets/ds18b20.pdf
 - [4] https://ieeexplore.ieee.org/document/9153994
