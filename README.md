ESP32-S3 based Smartwatch Project
=================================

This project aims to develop an open-source smartwatch design based around an ESP32-S3 microcontroller, as it offers many useful features, such as integrated Wi-Fi, Bluetooth and 8MB of PSRAM.  This allows a watch to be designed with a minimal number of extra components beside the MCU itself.

Component Selection
-------------------

| Component | Model | Datasheet |
|-----------|-------|-----------|
| MCU | ESP32-S3R8 | [ESP32-S3](https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf) |
| Display | CFAF240240A3-013TN  | [CFAF240240A3-013TN ](https://www.crystalfontz.com/products/document/4754/CFAF240240A3-013TNDatasheet.pdf) |
| Barometric Pressure Sensor | BMP390 | [BMP390](https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bmp390-ds002.pdf) |
| GNSS Receiver | MIA-M10Q-0 | [MIA-M10Q](https://content.u-blox.com/sites/default/files/documents/MIA-M10Q_DataSheet_UBX-22015849.pdf) |
| Flash | IS25LP128F-JKLE (16MB) | [IS25WP128](https://www.issi.com/WW/pdf/25LP-WP128F.pdf) |
| | | |
| Battery Charger | BQ24075RGTR | [BQ24075](https://www.ti.com/lit/ds/symlink/bq24075.pdf) |
| Fuel Gauge | BQ27441DRZR-G1A | [BQ27441-G1](https://www.ti.com/lit/ds/symlink/bq27441-g1.pdf) |
| Battery | ASR00007 | [ASR00007](https://www.mouser.com/datasheet/2/855/ASR00007_290mAh-3078659.pdf) |
| Battery Connector | SM02B-SRSS-TB(LF)(SN) | [SM02B-SRSS-TB(LF)(SN)](https://www.jst-mfg.com/product/pdf/eng/eSH.pdf) |
| | | |
| Main SMPS | TPS631000DRLR | [TPS631000](https://www.ti.com/lit/ds/symlink/tps631000.pdf) |
| LED Driver | | []() |

ESP GPIO Allocation
-------------------
| GPIO | Function |
|------|----------|
| 0 | Bootloader (Strapping) FREE |
| 1 | I<sup>2</sup>C SDA |
| 2 | I<sup>2</sup>C SCL |
| 3 | JTAG Source Select (Strapping) FREE |
| 4 | Power Switch |
| 5 | User Switch 1 |
| 6 | User Switch 2 |
| 7 | User Switch 3 |
| 8 | Input Current 1 |
| 9 | Input Current 2 |
| 10 | LCD CS |
| 11 | LCD MOSI |
| 12 | LCD SCK |
| 13 | FREE |
| 14 | FREE |
| 15 | 32KHz XTAL |
| 16 | 32KHz XTAL |
| 17 | GNSS RX (UART 1 TX) |
| 18 | GNSS TX (UART 1 RX) |
| 19 | USB- |
| 20 | USB+ |
| 21 | Fuel Gauge Interrupt |
| 26 | |
| ... | Flash / PSRAM |
| 37 | |
| 38 | GNSS TX Ready |
| 39 | GNSS Timepulse |
| 40 | LCD DC |
| 41 | LCD Backlight |
| 42 | LCD TE |
| 43 | UART 0 TX |
| 44 | UART 0 RX |
| 45 | Flash Voltage Select (Strapping) FREE |
| 46 | ROM Messages (Strapping) FREE |
| 47 | SMPS Mode |
| 48 | SMPS Enable |
