ESP32-S3 based Smartwatch Project
=================================

This project aims to develop an open-source smartwatch design based around an ESP32-S3 microcontroller, as it offers many useful features, such as integrated Wi-Fi, Bluetooth and 8MB of PSRAM.  This allows a watch to be designed with a minimal number of extra components beside the MCU itself.

Component Selection
-------------------

| Component | Model | Datasheet |
|-----------|-------|-----------|
| MCU | ESP32-S3R8 | [ESP32-S3](https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf) |
| Flash | IS25WP128F-JKLE (16MB) | [IS25WP128](https://www.issi.com/WW/pdf/25LP-WP128F.pdf) |
| Display | CFAL128128B0-011W | [CFAL128128B0-011W](https://www.crystalfontz.com/products/document/3814/CFAL128128B0-011W_Datasheet.pdf) |
| Battery | RJD3048 | [RJD3048](https://www.mouser.com/datasheet/2/88/RJD-2944769.pdf) |
| Battery Clip | 3046 | [3046](https://www.mouser.com/datasheet/2/215/3046-1947340.pdf) |
| Environmental Sensor | BME280 | [BME280](https://www.mouser.com/datasheet/2/783/bst_bme280_ds002-2238172.pdf) |
| GNSS Receiver | EVA-M8Q | [EVA-M8Q](https://www.mouser.com/datasheet/2/1025/EVA_M8_FW3_DataSheet__UBX_16014189_-2010107.pdf) |
| Protection / Fuel Gauge | BQ27Z746 | [BQ27Z746](https://www.ti.com/lit/ds/symlink/bq27z746.pdf) |
| Battery Charger | TBD | |
| Main SMPS | TPS631000 | [TPS631000](https://www.ti.com/lit/ds/symlink/tps631000.pdf) |

ESP GPIO Allocation
-------------------
| GPIO | Function |
|------|----------|
| 0 | Bootloader (Strapping) |
| 1 | I<sup>2</sup>C SCL |
| 2 | I<sup>2</sup>C SDA |
| 3 | JTAG Source Select (Strapping) |
| 4 | Free |
| 5 | Free |
| 6 | Free |
| 7 | Free |
| 8 | Free |
| 9 | Free |
| 10 | Free |
| 11 | Free |
| 12 | Free |
| 13 | Free |
| 14 | Free |
| 15 | Free |
| 16 | Free |
| 17 | Free |
| 18 | Free |
| 19 | USB- |
| 20 | USB+ |
| 21 | Free |
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
| 38 | Free |
| 39 | Free (Default JTAG) |
| 40 | Free (Default JTAG) |
| 41 | Free (Default JTAG) |
| 42 | Free (Default JTAG) |
| 43 | UART 0 TX |
| 44 | UART 0 RX |
| 45 | Flash Voltage Select (Strapping) |
| 46 | ROM Messages (Strapping) |
| 47 | Free |
| 48 | Free |
