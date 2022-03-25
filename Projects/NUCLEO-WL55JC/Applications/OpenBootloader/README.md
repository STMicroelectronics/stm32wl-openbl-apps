## <b>Open Bootloader Application Description</b>

This application exploits Open Bootloader Middleware to demonstrate how to develop an IAP application
and how use it.

At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the Systick.
The SystemClock_Config() function is used to configure the system clock (SYSCLK)
to run at 48MHz.

Then, these protocols and memories interfaces are configured:
  - USART1
  - SPI1
  - FLASH interface
  - RAM interface
  - Option bytes interface
  - System memory interface
  - OTP interface
  - Engineering bytes interface

Then, the Open Bootloader application will wait for incoming communication on one of the supported protocols.

Once a communication is established through one of the supported protocols,
the Open Bootloader application will wait for commands sent by the host.

#### <b>Notes</b>

 1. In case of Mass Erase operation, the Open Bootloader FLASH area must be protected otherwise the Open Bootloader
    will be erased.

 2. In the `OpenBootloader_Init()` function in `app_openbootloader.c` file, the user can:
       - Select the list of supported commands for a specific interface by defining its own list of commands.

       Here is an example of how to customize USART interface commands list, here only read/write commands are supported:

        OPENBL_CommandsTypeDef USART_Cmd =
        {
          NULL,
          NULL,
          NULL,
          OPENBL_USART_ReadMemory,
          OPENBL_USART_WriteMemory,
          NULL,
          NULL,
          NULL,
          NULL,
          NULL,
          NULL,
          NULL,
          NULL,
          NULL,
          NULL,
          NULL,
          NULL,
          NULL,
          NULL,
          NULL
        };

        USART_Handle.p_Ops = &USART_Ops;
        USART_Handle.p_Cmd = &USART_Cmd;           /* Initialize the USART handle with the list of supported commands */
        OPENBL_USART_SetCommandsList(&USART_Cmd);  /* Register the list of supported commands in MW side */

       - Use the default list of supported commands for a specific interface by reusing the commands list defined in MW side.

       Here is an example of how to use USART interface default commands list:

        /* Register USART interfaces */
        USART_Handle.p_Ops = &USART_Ops;
        USART_Handle.p_Cmd = OPENBL_USART_GetCommandsList();  /* Initialize the USART handle with the default list of supported commands */

### <b>Keywords</b>

Open Bootloader, USART, SPI

### <b>Directory contents</b>

     - Core/Src/main.c                                    Main program file
     - Core/Src/stm32wlxx_hal_msp.c                       MSP Initialization file
     - Core/Src/stm32wlxx_it.c                            Interrupt handlers file
     - Core/Src/system_stm32wlxx.c                        STM32WLxx system clock configuration file
     - Core/Inc/main.h                                    Main program header file
     - Core/Inc/stm32wlxx_hal_conf.h                      HAL Library Configuration file
     - Core/Inc/stm32wlxx_it.h                            Interrupt handlers header file
     - OpenBootloader/App/app_openbootloader.c            Open Bootloader application entry point
     - OpenBootloader/App/app_openbootloader.h            Header for Open Bootloader application entry file
     - OpenBootloader/Target/common_interface.c           Contains common functions used by different interfaces
     - OpenBootloader/Target/common_interface.h           Header for common functions file
     - OpenBootloader/Target/engibytes_interface.c        Contains Engibytes interface
     - OpenBootloader/Target/engibytes_interface.h        Header for Engibytes functions file
     - OpenBootloader/Target/flash_interface.c            Contains FLASH interface
     - OpenBootloader/Target/flash_interface.h            Header of FLASH interface file
     - OpenBootloader/Target/iwdg_interface.c             Contains IWDG interface
     - OpenBootloader/Target/iwdg_interface.h             Header of IWDG interface file
     - OpenBootloader/Target/optionbytes_interface.c      Contains OptionBytes interface
     - OpenBootloader/Target/optionbytes_interface.h      Header of OptionBytes interface file
     - OpenBootloader/Target/openbootloader_conf.h        Header file that contains Open Bootloader HW dependent configuration
     - OpenBootloader/Target/otp_interface.c              Contains OTP interface
     - OpenBootloader/Target/otp_interface.h              Header of OTP interface file
     - OpenBootloader/Target/ram_interface.c              Contains RAM interface
     - OpenBootloader/Target/ram_interface.h              Header of RAM interface file
     - OpenBootloader/Target/spi_interface.c              Contains SPI interface
     - OpenBootloader/Target/spi_interface.h              Header of SPI interface file
     - OpenBootloader/Target/systemmemory_interface.c     Contains ICP interface
     - OpenBootloader/Target/systemmemory_interface.h     Header of ICP interface file
     - OpenBootloader/Target/usart_interface.c            Contains USART interface
     - OpenBootloader/Target/usart_interface.h            Header of USART interface file

### <b>Hardware and Software environment</b>

  - This application runs on STM32WL55xx devices.

  - This example has been tested with a NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC set-up to use USART:
    - To use the USART1 for communication you have to connect:
      - Tx pin of your host adapter to PA9  pin (CN5: 2)(D9)
      - Rx pin of your host adapter to PA10 pin (CN8: 3)(A2)

  - NUCLEO-WL55JC RevC set-up to use SPI
    - To use the SPI1 for communication you have to connect:
      - SCK  pin of your host adapter to PA5 pin (CN5: 6)(D13)
      - MISO pin of your host adapter to PA6 pin (CN5: 5)(D12)
      - MOSI pin of your host adapter to PA7 pin (CN5: 4)(D11)
      - NSS  pin of your host adapter to PA4 pin (CN5: 3)(D10)

### <b>How to use it ?</b>

In order to make the program work, you must do the following:

  - Open your preferred toolchain using the adequate version
  - Rebuild all files and load your image into target memory
  - Run the application
  - Run STM32CubeProgrammer and connect to Open Bootloader using USART1</br>
    Or
  - Connect your SPI host adapter and connect to Open Bootloader using SPI1</br>
