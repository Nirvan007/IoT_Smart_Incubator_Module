IoT Smart Incubator Module <a name="TOP"></a>
===================

## Table of Contents
* [Introduction](#Introduction)
* [Features](#Features)
* [Tools Used](#Tools-Used)
  * [Arduino IDE](#Arduino-IDE)
  * [Fritzing](#Fritzing)
  * [Blynk IoT](#)
* [Hardware Components Used](#Hardware-Components-Used)
* [Microcontroller Specifications](#Microcontroller-Specifications)
* [Schematic](#Schematic)
* [Completed Hardware Assembly](#Completed-Hardware-Assembly)
* [SEMACS Application UI](#SEMACS-Application-UI)
* [References](#References)

## Introduction
#### What is an Infant Incubator and why is it required?
An infant incubator is a medical device that provides a controlled environment for premature or ill newborns. It is required to regulate temperature, humidity, and oxygen levels, mimicking the conditions of the mother's womb. This controlled setting supports the development of underdeveloped organs and reduces the risks associated with premature birth, improving the chances of survival and healthy growth for vulnerable newborns.

#### Objective of the Project
The primary objective of this project is to develop a smart module for incubators, empowered with the capability to transmit comprehensive health and environmental data concerning the infant inside the incubator through the Internet of Things (IoT). This innovative module aims to enhance the monitoring and management of vital parameters related to the infant's well-being and its surroundings, providing real-time insights for efficient healthcare.

#### Motivation
Mostly all existing warmers/incubators are manually operated, i.e., all readings have to be manually collected and stored for numerous infants. Our project aims at eliminating all such tedious tasks as all readings will be collected automatically and will be sent to the respective parents/guardians on their mobile phones. Similarly, any sudden drop or rise in any of the parameters will automatically alert the respective contact.

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
* Parameter monitoring using Blynk Mobile App
* All health related data is forwarded to the application in real-time using the Blynk IoT Server.
* Equipped with a 2000mAh rechargeable lithium-ion backup-battery which serves as a back-up in case of power outages.

## Tools Used
#### Arduino IDE 
Arduino Integrated Development Environment or Arduino Software (IDE) contains a text editor for writing code, a message area, a text console, a toolbar with buttons for common functions and a series of menus. It connects to the Arduino hardware to upload programs and communicate with them. 
* For more details refer: <https://www.arduino.cc/en/software>

#### Fritzing
Fritzing is an open-source hardware initiative that makes electronics accessible as creative material for anyone. We offer a software tool, a community website and services in the spirit of Processing and Arduino, fostering a creative ecosystem that allows users to document their prototypes, share them with others, teach electronics in a classroom, and layout and manufacture professional PCBs. 
* For more details refer: <https://fritzing.org/>

#### Blynk IoT
Blynk is an IoT platform that simplifies the development of IoT projects. It provides a mobile app and cloud service, allowing users to easily design interfaces for controlling and monitoring connected devices. Blynk supports various hardware platforms and offers a user-friendly drag-and-drop interface for creating IoT applications.
* For more details refer: <https://blynk.io/>

## Hardware Components Used
1. Nodemcu ESP8266 microcontroller
2. MAX30102 Heart rate and SpO2 sensor
3. MQ2 Air Quality sensor
4. DS18B20 Digital temperature sensor
5. DHT11 Temperature and Humidity sensor
6. 16x2 I2C LCD Display
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
  1. MAX30102 Heart rate and Pulse Oximeter sensor for Heart rate and SpO2 monitoring.
  2. MPU6050 Gyroscope and Accelerometer for sleep detection and fall detection.
  3. 16x2 LCD Display for displaying all the measured parameters.
* Used WiFi (2.4GHz) for Connectivity with the Blynk Mobile Application.
* Interfaced the DS18B20 Digital temperature sensor to monitor the body temperature.
* Interfaced the DHT11 Temperature and Humidity sensor to monitor the room temperature and humidity.
* Push Button for switching screens on the OLED display and for sending an emergency call notification.

## Schematic
![image](https://user-images.githubusercontent.com/127144315/223844096-c96638e7-28e1-4cd9-b39b-7ca7b42ead74.png)

## Completed Hardware Assembly
![image](https://github.com/Nirvan007/Real-time-health-monitoring-system-using-Internet-of-Things/assets/127144315/49bc9b4f-90aa-49cb-be2e-77df2ca451d8)

## Google Firebase (Back-end Real-Time Database)
#### Projects interface
![image](https://user-images.githubusercontent.com/127144315/223844498-3c206e85-dd1c-41f6-998f-936464151265.png)

#### SEMACS Project Overview
![image](https://user-images.githubusercontent.com/127144315/223844840-717feab1-2709-4f5d-92d9-6bd8a7ac7aec.png)

#### SEMACS Real-Time Database
![WhatsApp Image 2023-03-09 at 2 23 30 AM](https://user-images.githubusercontent.com/127144315/223847460-ce3c80cb-12b4-41f8-a68a-bc4bb17bbfea.jpeg)

#### Parameter Display
![WhatsApp Image 2023-03-09 at 2 23 30 AM (1)](https://user-images.githubusercontent.com/127144315/223847522-d2eddc7b-c720-4bbe-ab90-4611382727a1.jpeg)

## SEMACS Application UI
#### Main Dashboard
![WhatsApp Image 2023-03-09 at 1 21 38 AM](https://user-images.githubusercontent.com/127144315/223833541-a061c01b-c190-46f0-ba09-0a1ba1cc4de5.jpeg)

## References
 - [1] https://www.analog.com/en/products/max30102.html#product-overview
 - [2] https://ieeexplore.ieee.org/document/8540606
 - [3] https://lastminuteengineers.com/max30102-pulse-oximeter-heart-rate-sensor-arduino-tutorial/#:~:text=MAX30102%20Module%20Pinout,-The%20MAX30102%20module&text=You%20can%20connect%20it%20to,an%20interrupt%20for%20each%20pulse.
 - [4] https://ieeexplore.ieee.org/document/9153994
