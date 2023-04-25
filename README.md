ESP32-S3 based Smartwatch Project
=================================

This project aims to develop an open-source smartwatch design based around an ESP32-S3 microcontroller, as it offers many useful features, such as integrated Wi-Fi, Bluetooth and 8MB of PSRAM.  This allows a watch to be designed with a minimal number of extra components beside the MCU itself.

Component Selection
-------------------

| Component | Model | Datasheet |
|-----------|-------|-----------|
| MCU | ESP32-S3R8 | [ESP32-S3](https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf) |
| Display | CFAL128128B0-011W | [CFAL128128B0-011W](https://www.crystalfontz.com/products/document/3814/CFAL128128B0-011W_Datasheet.pdf) |
| Environmental Sensor | BME280 | [BME280](https://www.mouser.com/datasheet/2/783/bst_bme280_ds002-2238172.pdf) |
| GNSS Receiver | EVA-M8Q-0 | [EVA-M8Q](https://www.mouser.com/datasheet/2/1025/EVA_M8_FW3_DataSheet__UBX_16014189_-2010107.pdf) |
| Flash | IS25LP128F-JKLE (16MB) | [IS25WP128](https://www.issi.com/WW/pdf/25LP-WP128F.pdf) |
| | | |
| Battery Protection | BQ298012RUGR | [BQ298012](https://www.ti.com/lit/ds/symlink/bq2982.pdf) |
| Battery Charger | BQ24075RGTR | [BQ24075](https://www.ti.com/lit/ds/symlink/bq24075.pdf) |
| Fuel Gauge | BQ27441DRZR-G1A | [BQ27441-G1](https://www.ti.com/lit/ds/symlink/bq27441-g1.pdf) |
| Battery | RJD3048 | [RJD3048](https://www.mouser.com/datasheet/2/88/RJD-2944769.pdf) |
| Battery Clip | 3046 | [3046](https://www.mouser.com/datasheet/2/215/3046-1947340.pdf) |
| | | |
| Main SMPS | TPS631000DRLR | [TPS631000](https://www.ti.com/lit/ds/symlink/tps631000.pdf) |
| OLED SMPS | AP3012KTR-G1 | [AP3012](https://www.diodes.com/assets/Datasheets/AP3012.pdf) |

ESP GPIO Allocation
-------------------
| GPIO | Function |
|------|----------|
| 0 | Bootloader (Strapping) |
| 1 | I<sup>2</sup>C SDA |
| 2 | I<sup>2</sup>C SCL |
| 3 | JTAG Source Select (Strapping) |
| 4 | Charger Status |
| 5 | Power Good |
| 6 | Input Current 1 |
| 7 | Input Current 2 |
| 8 | SMPS Mode |
| 9 | OLED VCC Enable |
| 10 | OLED CS |
| 11 | OLED MOSI |
| 12 | OLED SCK |
| 13 | OLED D/C |
| 14 | OLED RST |
| 15 | 32KHz XTAL |
| 16 | 32KHz XTAL |
| 17 | GNSS RX (UART 1 TX) |
| 18 | GNSS TX (UART 1 RX) |
| 19 | USB- |
| 20 | USB+ |
| 21 | GNSS Timepulse |
| 26 | SPI CS 1 (PSRAM) |
| 27 | SPI Hold (Flash / PSRAM) |
| 28 | SPI WP (Flash / PSRAM) |
| 29 | SPI CS 0 (Flash) |
| 30 | SPI CLK (Flash / PSRAM) |
| 31 | SPI Q (Flash / PSRAM) |
| 32 | SPI D (Flash / PSRAM) |
| 33 | SPI IO 4 (PSRAM) |
| 34 | SPI IO 5 (PSRAM) |
| 35 | SPI IO 6 (PSRAM) |
| 36 | SPI IO 7 (PSRAM) |
| 37 | SPI DQS (PSRAM) |
| 38 | GNSS TX Ready |
| 39 | User Switch 1 |
| 40 | User Switch 2 |
| 41 | User Switch 3 |
| 42 | User Switch 4 |
| 43 | UART 0 TX |
| 44 | UART 0 RX |
| 45 | Flash Voltage Select (Strapping) |
| 46 | ROM Messages (Strapping) |
| 47 | Status LED 1 |
| 48 | Status LED 2 |
