---
parent: Harmony 3 peripheral library application examples for SAM9X60 family
title: PIT64B periodic interrupt 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# PIT64B periodic interrupt

This application shows how to use PIT64B counter in interrupt mode.

## Description

This application toggles an LED based off the PIT64B interrupt. Every time the PIT64B counter expires the LED toggles.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_sam_a7g5) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/pit64b/led_toggle_interrupt/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_a7g5_ek.X | MPLABX project for [SAMA7G5 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails) |


## Setting up AT91Bootstrap loader

To load the application binary onto the target device, we need to use at91bootstrap loader. Refer to the [at91bootstrap loader documentation](../../docs/readme_bootstrap.md) for details on how to configure, build and run bootstrap loader project and use it to bootstrap the application binaries.

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a7g5_ek.X | [SAMA7G5 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails) |

### Setting up [SAMA7G5 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails)

#### Setting up the board

- Connect an oscilloscope to clock output pin
- Connect a 5V power supply to the board. This can be either of the following:
    - A USB cable connected between "USBA" (J7) connector on the board and USB host port on PC 
    - A 5V DC adapter connected to "5V DC IN" (J1) connector on board 
- Connect the Debug USB port (J24) on the board to the computer using a micro USB cable

## Running the Application

1. Build and run the application using its IDE
2. Press PB_USER1 switch to start/stop timer
3. LED toggles at a fixed rate when timer is on and stops toggling when timer is off 
4. Timer period can be monitored on clock output pin
5. Press PB_USER2 switch to change the timer period
6. When timer period is changed LED toggle rate is changed
7. Exact period can be measured on the clock output pin
8. Timer period cycles between 250ms, 500ms, 750ms and 1000ms

Following table provides details of switch and LED:

| Board | PB_USER1 |  PBUSER_2 | LED | clock output pin | 
|:----------|:---------|:---------|:----------|:--------|
| [SAMA7G5 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails) |USER BUTTON | SW4 | RGB_LED(Blue) | PD20 (PWM pin on Mikrobus2 connector) |