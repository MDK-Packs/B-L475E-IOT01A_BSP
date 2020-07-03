Platform project
================

The **Platform** project configures the hardware of the evaluation board
and is a CMSIS-RTOS2 based software template that can be further expanded.

RTX5 Real-Time Operating System
-------------------------------
The [RTX5 RTOS](https://arm-software.github.io/CMSIS_5/RTOS2/html/rtx5_impl.html)
implements the resource management. It is configured with the following settings:

- Global Dynamic Memory size: 24000 bytes
- Default Thread Stack size:  3072 bytes

STMicroelectronics B-L475E-IOT01A Target Board
--------------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver USART1** routed to Virtual COM port (ST-LINK):
 - TX: ST-LINK-UART1_TX (PB6)
 - RX: ST-LINK-UART1_RX (PB7)

**CMSIS-Driver UART4** routed to Arduino UNO R3 connector (CN3):
 - TX: ARD.D1-UART4_TX (PA0)
 - RX: ARD.D0-UART4_RX (PA1)

**CMSIS-Driver SPI1** routed to Arduino UNO R3 connector (CN1):
 - SCK:  ARD.D13-SPI1_SCK/LED1 (PA5)
 - MISO: ARD.D12-SPI1_MISO     (PA6)
 - MOSI: ARD.D11-SPI1_MISO/PWM (PA7)

**GPIO** pin routed to Arduino UNO R3 connector (CN1):
 - output: ARD.D10-SPI_SSN/PWM (PA2)
 - input:  ARD.D9-PWM          (PA15)

**CMSIS-Driver WiFi0** routed to Inventek system ISM43362-M3G-L44 module:
 - SCK:  INTERNAL-SPI3_SCK   (PC10)
 - MISO: INTERNAL-SPI3_MISO  (PC11)
 - MOSI: INTERNAL-SPI3_MOSI  (PC12)
 - GPIO: ISM43362-SPI3_CSN   (PE0)
 - GPIO: ISM43362-WAKEUP     (PB13)
 - GPIO: ISM43362-RST        (PE8)
 - GPIO: ISM43362-DRDY_EXTI1 (PE1)

**CMSIS-Driver VIO** with the following board hardware mapping:
 - vioBUTTON0:        Button USER (PC13)
 - vioLED0:           LD2 GREEN (PB14)
 - vioMotionGyro:     ST MEMS gyroscope (LSM6DSL)
 - vioMotionAccelero: ST MEMS accelerometer (LSM6DSL)
 - vioAIN0:           ST MEMS humidity and temperature (HTS221)
 - vioAIN1:           ST MEMS barometer (LPS22HB)
 - vioAIN3:           ST MEMS humidity and temperature (HTS221)

The board configuration can be modified using [STM32CubeMX](https://www.keil.com/stmicroelectronics-stm32)
and is stored in the file `STCubeGenerated.ioc`.
