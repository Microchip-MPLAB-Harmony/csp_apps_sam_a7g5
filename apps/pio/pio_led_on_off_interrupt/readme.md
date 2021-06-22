---
parent: Harmony 3 peripheral library application examples for SAMA7G5 family
title: PIO interrupt 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# PIO interrupt

This example application shows how to generate GPIO interrupt on switch press and release, and indicate the switch status using the LED.

## Description

This application uses the PIO Peripheral library to generate callback on switch press and release, and drives the GPIO pin connected to the LED to indicate the switch status. The LED is turned ON when the switch is pressed and turned OFF when the switch is released.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_sam_a7g5) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/pio/pio_led_on_off_interrupt/firmware** .

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

- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Build and run the application using its IDE
2. LED is turned ON when the switch is pressed and turned OFF when the switch is released

Following table provides details of switch and LED:

| Board      | Switch Name |  LED Name |
| ---------- | ----------- | --------- |
| [SAMA7G5 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails) |USER BUTTON |RGB_LED(Blue) |
