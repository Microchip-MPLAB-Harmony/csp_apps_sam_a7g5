---
parent: Harmony 3 peripheral library application examples for SAMA7G5 family
title: ADC user sequence 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# ADC user sequence

This example application shows how to sample three analog inputs using the user sequencer in external trigger mode (TC peripheral) and send the converted data to the console.

## Description

Conversion of the three analog inputs is triggered by TC peripheral at every 500 ms. The user sequencer is used to define the order of conversion:

| Board | Sequence of conversion |
| ----- | ---------------------- |
| [SAMA7G5 Evaluation Kit]() |  AD6 --> AD7 --> AD5 |
|||

Analog input voltage in the range of 0 V to 3.3 V is fed to the ADC input channel AD6, AD7 and AD5. ADC conversion result is displayed on the console.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_sam_a7g5) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/adc/adc_user_sequence/firmware** .

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

#### Addtional hardware required

- SD Card with FAT32 file system

#### Setting up the SD Card

- Download harmony MPU bootstrap loader from this [location](firmware/at91bootstrap_sam_a7g5_ek.X/binaries/boot.bin)
- Copy the downloaded boot loader binary( boot.bin) onto the SD card

#### Setting up the board

- SDMMC slot used for bootloading the application is SDMMC1 (J4)
- Connect the USB port J7 on board to the computer using a micro USB cable (to power the board)
- Connect the USB port J24 on board to the computer using a micro USB cable (to enable debug com port)
- Use a jumper wire to connect Pin 11 of mikroBUS 2 connector (AD5 is mapped to Port Pin PC18) to 3.3 V or GND
- Use a jumper wire to connect Pin 12 of mikroBUS 2 connector (AD6 is mapped to Port Pin PC19) to 3.3 V or GND
- Use a jumper wire to connect Pin 15 of mikroBUS 2 connector (AD7 is mapped to Port Pin PC20) to 3.3 V or GND

## Running the Application

1. Build the application using its IDE
2. Copy the output binary (named 'harmony.bin') onto the SD Card (Refer to the 'Setting up hardware' section above for setting up the SD card)
3. Insert the SD card into SDMMC slot on the board (Refer to the 'Setting up hardware' section for the correct SDMMC slot)
4. Open the Terminal application (Ex.:Tera term) on the computer.
5. Connect to the Jlink Virtual COM port and configure the serial settings as follows:
    - Baud : 115200
    - Data : 8 Bits
    - Parity : None
    - Stop : 1 Bit
    - Flow Control : None
6. Reset the board to run the application
7. The console displays the ADC Count and the ADC Input Voltage

![output](images/output_adc_user_sequence.png)
