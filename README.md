# STM32WL Open Bootloader Applications

![latest tag](https://img.shields.io/github/v/tag/STMicroelectronics/stm32wl-openbl-apps.svg?color=brightgreen)

![openbl](https://img.shields.io/badge/openbl-v6.0.1-blue.svg)

## Overview

**Open Bootloader** is an In-Application programming (IAP) provided in the STM32Cube MCU Packages and GitHub. It is fully compatible with STM32 System Bootloader so that it have the same supported interfaces and commands. It's also using the same Tools such as STM32CubeProgrammer.

**Open Bootloader** is provided as an example that can be used by any customer who wants to build and customize his own Bootloader starting from a good basis. It allows all possible bootloader operations (Read, write, erase, jump...) into internal (Flash, SRAM, OTP...) or external memory using one of the available communication interfaces (USART, I2C, SPI, USB-DFU, FDCAN...).

**Open Bootloader** supplies services to the Host (can be STM32CubeProgrammer or another user made host) in order to perform all possible Bootloader operations.

**Open Bootloader** relies on STM32Cube HAL/LL drivers for hardware system initialization such as the clocks and the communication interfaces configuration.

**Open Bootloader** code can be loaded at any address of user Flash memory with taking necessary precautions to avoid erasing or corrupting it by error (for example use write protection mechanism).

**Open Bootloader** is executed by Cortex-M processor on the non-secure domain and uses the following resources:
 - Non secure internal flash memory/SRAM1
 - Interrupts
 - Clocks and power
 - Communication interfaces
 - GPIOs
 - Systick
 - IWDG

**Open Bootloader** can be customized by changing its location (ie. load it in last user Flash sector or other sectors), its supported protocols, its supported interfaces, and its supported operations.

## Documentation

Since Open Bootloader supports exactly same protocol interfaces as STM32 System Bootloader, following list of documents provide details of how to use each protocol:
- [AN3155](https://www.st.com/resource/en/application_note/CD00264342.pdf): USART protocol used in the STM32 Bootloader
- [AN5405](https://www.st.com/resource/en/application_note/dm00660346.pdf): FDCAN protocol used in the STM32 Bootloader
- [AN4221](https://www.st.com/resource/en/application_note/DM00072315.pdf): I2C protocol used in the STM32 Bootloader
- [AN3156](https://www.st.com/resource/en/application_note/cd00264379.pdf): USB DFU protocol used in the STM32 Bootloader
- [AN4286](https://www.st.com/resource/en/application_note/DM00081379.pdf): SPI protocol used in the STM32 Bootloader

A useful introductory video series, in six parts, explaining how to use Open Bootloader step by step, can be found here: 
 - [Part 1](https://www.youtube.com/watch?v=_gejWsAn5kg): Introduction
 - [Part 2](https://www.youtube.com/watch?v=kYr7UMieRTo): Using a NUCLEO-G474RE
 - [Part 3](https://www.youtube.com/watch?v=JUBac27tOis): Loading an application
 - [Part 4](https://www.youtube.com/watch?v=7sMDBSlZ7bU): Adding support for the I2C interface
 - [Part 5](https://www.youtube.com/watch?v=rr1W5h94qLU): STLINK-V3SET I2C setup
 - [Part 6](https://www.youtube.com/watch?v=IZ6BpDIm6O0): Loading an application over I2C

## List of Supported Commands

All STM32 System Bootloader commands can be supported by Open Bootloader, which includes:
 - Get Version
 - Get Device ID
 - Get Available Command List
 - Write Memory
 - Read Memory
 - Write Protection setting
 - Read Protection setting
 - Jump to Application
 - Flash Erase
 - Special Command
 - Extended Special Command

The user can customize the list of supported commands for a specific interface by removing the commands that he don't need.
More details about how to do that can be found in the `Notes` section of the `README.md` file of the application.

## How to use

In order to make the program work, you need to do the following:
 - Open your preferred toolchain using the adequate version
 - Rebuild all files and load your image into target memory
 - Run the application
 - Run the Host (can be STM32CubeProgrammer or similar hosts) and connect to Open Bootloader using one of the available communication interfaces (USART, I2C, SPI, USB-DFU, FDCAN...)

Following physical connections can be used with STM32CubeProgrammer host:
 - USB interface can be used directly if USB connector is available on the board.
 - USART interface can be used with STLinkV2 or STLinkV3 or USB-UART bridges.
 - I2C, SPI interfaces can be used with STLinkV3 or with USB-I2C/SPI bridges.
 - FDCAN interface can be used with USB-CAN bridges.

*Note*
 - Before using an interface, make sure its IOs are not used by other components on the board that may interfere with Open Bootloader communication.
 - The list of used IOs for each interface can be found in the section `Hardware and Software environment` of the `README.md` file of the application.

---

#### *Note*

* To clone this repository along with the linked submodules, option `--recursive` has to be specified as shown below.

```
git clone --recursive https://github.com/STMicroelectronics/stm32wl-openbl-apps.git
```

* To get the latest updates, issue the following **two** commands (with the repository `stm32wl-openbl-apps` as the **current working directory**).

```
git pull
git submodule update --init --recursive
```

#### *Note*

 * If GitHub "Download ZIP" option is used instead of the `git clone` command, then the required components have to be collected manually by the user.

## Supported Development Toolchains and Compilers

 * IAR Embedded Workbench for ARM (EWARM) toolchain v8.50.9
 * RealView Microcontroller Development Kit (MDK-ARM) toolchain v5.32
 * STM32CubeIDE v1.8.0

## Supported boards

Product      | Board         | Application Version
-------------|---------------|----------
STM32WL55xx  | NUCLEO-WL55JC | v1.0.0

## Troubleshooting

Please refer to the [CONTRIBUTING.md](CONTRIBUTING.md) guide.
