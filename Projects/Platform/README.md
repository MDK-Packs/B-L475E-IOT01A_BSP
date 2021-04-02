Platform project
================

The **Platform** project configures the hardware of the evaluation board
and is a CMSIS-RTOS2 based software template that can be further expanded.

RTOS: Keil RTX5 Real-Time Operating System
------------------------------------------

The real-time operating system [Keil RTX5](https://arm-software.github.io/CMSIS_5/RTOS2/html/rtx5_impl.html) implements the resource management. 

It is configured with the following settings:

- [Global Dynamic Memory size](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#systemConfig): 24000 bytes
- [Default Thread Stack size](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#threadConfig): 3072 bytes
- [Event Recorder Configuration](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#evtrecConfig)
  - [Global Initialization](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#evtrecConfigGlobIni): 1
    - Start Recording: 1

Refer to [Configure RTX v5](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html) for a detailed description of all configuration options.

Board: STMicroelectronics B-L475E-IOT01A
----------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32L475VGtx
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 2 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| HCLK                    | 80 MHz
| FCLK                    | 80 MHz
| APB1                    | 80 MHz
| APB2                    | 80 MHz
| To USART1               | 80 MHz
| To UART4                | 80 MHz
| To RNG                  | 48 MHz

### GPIO Configuration and usage

| GPIO | Signal / Label    | GPIO Settings                                 | Usage
|:-----|:------------------|:----------------------------------------------|:-----
| PA0  | UART4_TX          | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D1 (TX)
| PA1  | UART4_RX          | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D0 (RX)
| PA5  | SPI1_SCK          | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D13 (SCK)
| PA6  | SPI1_MISO         | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D12 (MISO)
| PA7  | SPI1_MOSI         | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D11 (MOSI)
| PA2  | IO_D10            | Output Push Pull, Level=High, Speed=Very High | Arduino UNO R3 pin D10
| PA15 | IO_D9             | Input mode                                    | Arduino UNO R3 pin D9
| PB6  | USART1_TX         | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (ST-LINK-UART1_TX)
| PB7  | USART1_RX         | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (ST-LINK-UART1_RX)
| PC10 | SPI3_SCK          | Alternate Function, Speed=Very High           | ISM43362 pin SCK
| PC11 | SPI3_MISO         | Alternate Function, Speed=Very High           | ISM43362 pin MISO
| PC12 | SPI3_MOSI         | Alternate Function, Speed=Very High           | ISM43362 pin MOSI
| PB13 | ISM43362_WAKEUP   | Output Push Pull, Level=Low, Speed=Low        | ISM43362 pin WKUP
| PE0  | ISM43362_SPI3_NSS | Output Push Pull, Level=Low, Speed=Low        | ISM43362 pin SSN
| PE1  | ISM43362_DATARDY  | External Interrupt with Rising edge trigger   | ISM43362 pin DATARDY
| PE8  | ISM43362_RESET    | Output Push Pull, Level=Low, Speed=Low        | ISM43362 pin RSTN
| PC13 | vioBUTTON0        | not configured via CubeMX                     | Button USER
| PB14 | vioLED0           | not configured via CubeMX                     | LD2 GREEN

### NVIC Configuration

 - Priority Group = 4 bits for preemption priority 0 bits for subpriority

| NVIC Interrupt                          | Preempt Priority | Code Generation
|:----------------------------------------|:-----------------|:---------------
| Non maskable interrupt                  | 0                | Generate IRQ handler
| Hard fault interrupt                    | 0                | Generate IRQ handler
| Memory Management fault                 | 0                | Generate IRQ handler
| Prefetch fault, memory access fault     | 0                | Generate IRQ handler
| Undefined instruction or illegal state  | 0                | Generate IRQ handler
| System service call via SWI instruction | 0                | none
| Debug monitor                           | 0                | Generate IRQ handler
| Pendable request for system service     | 0                | none
| Time base: System tick timer            | 0                | none
| EXTI line 1 interrupt                   | 15               | Generate IRQ handler, Call HAL handler
| DMA1 channel2 global interrupt          | 8                | Generate IRQ handler, Call HAL handler
| DMA1 channel3 global interrupt          | 8                | Generate IRQ handler, Call HAL handler
| SPI1 global interrupt                   | 9                | Generate IRQ handler, Call HAL handler
| UART4 global interrupt                  | 8                | Generate IRQ handler, Call HAL handler
| SPI3 global interrupt                   | 9                | Generate IRQ handler, Call HAL handler
| DMA2 channel1 global interrupt          | 8                | Generate IRQ handler, Call HAL handler
| DMA2 channel2 global interrupt          | 8                | Generate IRQ handler, Call HAL handler

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA                                                | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:---------------------------------------------------|:----
| SPI1         | Full-Duplex Master, Hardware NSS Signal=off, Do Not Generate Initialization Function Call                          | yes | SPI1_RX = DMA1 Channel 2, SPI1_TX = DMA1 Channel 3 | Arduino UNO R3 connector (CN1)
| SPI3         | Full-Duplex Master, Hardware NSS Signal=off, Do Not Generate Initialization Function Call                          | yes | SPI3_RX = DMA2 Channel 1, SPI3_TX = DMA2 Channel 2 | ISM43362
| UART4        | Asynchronous, Hardware Flow Control=off, Do Not Generate Initialization Function Call                              | yes | no                                                 | Arduino UNO R3 connector (CN3)
| USART1       | Asynchronous, Hardware Flow Control=off, Baud Rate: 115200 Bits/s, Word Length: 8 Bits, Parity: None, Stop Bits: 1 | no  | no                                                 | ST-LINK Virtual COM port

**STDIO** routed to Virtual COM port (USART1)

### Security Peripherals Configuration

| Peripheral   | Mode / Settings                                                                        | IRQ | DMA                                                  | Note
|:-------------|:---------------------------------------------------------------------------------------|:----|:-----------------------------------------------------|:----
| RNG          | Activated                                                                              | no  |                                                      | Random Number Generator

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| SPI1         | SPI1
| USART4       | UART4
| WiFi0        | SPI3 (ISM43362)

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD2 GREEN (PB14)
| vioMotionGyro     | ST MEMS gyroscope (LSM6DSL)
| vioMotionAccelero | ST MEMS accelerometer (LSM6DSL)
| vioAIN0           | ST MEMS temperature (HTS221)
| vioAIN1           | ST MEMS barometer (LPS22HB)
| vioAIN2           | ST MEMS humidity (HTS221)
