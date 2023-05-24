---
parent: Harmony 3 peripheral library application examples for SAMA7G5 family
title: Octal SPI flash read write using OctaFlash protocol
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Octal SPI flash read write using OctaFlash protocol

This example application shows how to use the QSPI Peripheral library to perform erase, write and read operation with the Octal SPI Flash memory using OctaFlash protocol.

## Description

This example uses the QSPI peripheral library to erase and write an array of values to the Octal SPI Flash memory. It verifies the value written by reading the values back and comparing it to the value written.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_sam_a7g5) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/qspi/octal_spi_read_write/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_a7g5_ek.X | MPLABX project for [SAMA7G5 Evaluation Kit]() |
|||

## Setting up AT91Bootstrap loader

To load the application binary onto the target device, we need to use at91bootstrap loader. Refer to the [at91bootstrap loader documentation](../../docs/readme_bootstrap.md) for details on how to configure, build and run bootstrap loader project and use it to bootstrap the application binaries.

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a7g5_ek.X | [SAMA7G5 Evaluation Kit]() |
|||

### Setting up [SAMA7G5 Evaluation Kit]()

#### Setting up the board

- Connect the USB port J7 on board to the computer using a micro USB cable (to power the board)
- Connect the USB port J24 on board to the computer using a micro USB cable (to enable debug com port)
- Open jumper J21 (DISABLE_BOOT)

## Running the Application

1. Build the application using its IDE
2. LED indicates success or failure:
    - The LED is toggled when the value read from the Octal SPI Flash memory matched with the written value
    - The LED is turned ON when the value read from the Octal SPI Flash did not match with the written value

Refer to the following table for LED name:

| Board             | LED Name                |
| ----------------- | ----------------------- |
| [SAMA7G5 Evaluation Kit]() | RGB_LED(Green) |
