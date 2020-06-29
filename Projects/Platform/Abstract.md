Platform Project
================

The 'Platform' project configures the hardware of the evaluation board
and is a CMSIS-RTOS2 based software template that can be further expanded.

This implementation contains the following configured interface drivers:

  - CMSIS-Driver USART4 routed to Arduino UNO R3 connector
    - TX: CN3 pin 2
    - RX: CN3 pin 1

  - CMSIS-Driver SPI1 routed to Arduino UNO R3 connector
    - SCK:  CN1 pin 6
    - MISO: CN1 pin 5
    - MOSI: CN1 pin 4
    - SSN:  CN1 pin 3

  - CMSIS-Driver VIO with the following board hardware mapping
    - vioBUTTON0:        PC13 - Button USER
    - vioLED0:           PB14 - LD2 GREEN
    - vioMotionGyro:     ST MEMS gyroscope (LSM6DSL)
    - vioMotionAccelero: ST MEMS accelerometer (LSM6DSL)
    - vioAIN0:           ST MEMS humidity and temperature (HTS221)
    - vioAIN1:           ST MEMS barometer (LPS22HB)
    - vioAIN3:           ST MEMS humidity and temperature (HTS221)

The CMSIS-RTOS2 is based on RTX5 with the following configuration settings:

   - Global Dynamic Memory size: 32768 bytes

   - Default Thread Stack size: 3072 bytes
