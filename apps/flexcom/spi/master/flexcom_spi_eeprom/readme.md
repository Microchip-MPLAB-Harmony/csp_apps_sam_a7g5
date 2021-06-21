---
parent: Harmony 3 peripheral library application examples for SAMA5D2 family
title: FLEXCOM SPI EEPROM read write 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# FLEXCOM SPI EEPROM read write

This example application shows how to use the flexcom module in SPI mode.

## Description

This application configures the flexcom peripheral in SPI mode to read and write data from an external EEPROM memory chip. Data is written to the EEPROM and then read back and compared. Successful comparison is indicated by turning on an LED.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/flexcom/spi/master/flexcom_spi_eeprom/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_a5d2_xult.X | MPLABX project for [SAMA7G5 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails) |


## Setting up AT91Bootstrap loader

To load the application binary onto the target device, we need to use at91bootstrap loader. Refer to the [at91bootstrap loader documentation](../../../../docs/readme_bootstrap.md) for details on how to configure, build and run bootstrap loader project and use it to bootstrap the application binaries.

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a5d2_xult.X | [SAMA7G5 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails) |


### Setting up [SAMA7G5 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails)

#### Addtional hardware required

- [EEPROM 4 Click board](https://www.mikroe.com/eeprom-4-click)

#### Setting up the board

- Connect the Debug USB port on the board to the computer using a micro USB cable
- Connect [EEPROM 4 Click board](https://www.mikroe.com/eeprom-4-click) to MikroBus1 connector

## Running the Application

1. Build and program the application using its IDE
5. LED indicates the success or failure:

| Board      | LED Details                                    |
| ----------------- | ---------------------------------------------- |
| [SAMA7G5 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails) | RGB_LED(Color changes from Green to Blue indicating success) |

