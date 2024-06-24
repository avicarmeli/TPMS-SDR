[![Hits](https://hits.sh/github.com/avicarmeli/TPMS-SDR/hits.svg)](https://hits.sh/github.com/avicarmeli/TPMS-SDR/hits/)

# TPMS Arduino code to read RF TPMS Sensors
![image](https://github.com/avicarmeli/TPMS-SDR/assets/32562196/2d5f958e-7c0f-45a7-ba11-a033dc294d37)

## Overview:
Some TPMS (Tyre Pressure Monitor System) sensors transmit RF data. Older car models (such as my Nissan Micra 2014) Have only warning light to indicate that the pressure of one of the tyres is too low.
It is possible to use [RTL-SDR](https://github.com/topics/rtl-sdr) with [RTL_433](https://github.com/merbanan/rtl_433) to read the RF data.
Such implementation for Arduino boards and small display was assambled as a stand alone system ([Toyota TPMS project](https://www.hackster.io/jsmsolns/arduino-tpms-tyre-pressure-display-b6e544#toc-about-tpms-2)).

This Project will use ESP32 as the main Board together with CC1101 board to read TPMS data and to send that data over BLE so that data would be recived by eigther cellphone or Android car multimeda app that would display the data and generate needed alerts.

Specificly this project is aimed at forwording the TPMS data to [TPMS Advancved android app](https://github.com/VincentMasselis/TPMS-advanced).

## Intent:
- [X] Porting the code to ESP32.
- [X] Sending sensors data over BLE to imitate Sysgration BLE sensors so it can be displayed in cellphone app.

## Hardware:
### Components:
- ESP32 Dev kit such as [that.](https://www.aliexpress.com/item/1005001929935550.html?spm=a2g0o.order_list.order_list_main.70.2fcd1802a3JqO6)   -  4$
- CC1101 module such as [that.](https://www.aliexpress.com/item/1005006427924521.html?spm=a2g0o.productlist.main.3.4606552dDUIADI&algo_pvid=f668fbe3-3ef8-466c-aa06-0833614c0e76&algo_exp_id=f668fbe3-3ef8-466c-aa06-0833614c0e76-1&pdp_npi=4%40dis%21USD%218.08%212.66%21%21%2158.41%2119.20%21%40211b600b17183703870547694e856b%2112000037133340091%21sea%21IL%21127988983%21&curPageLogUid=XNWVIg16GNX4&utparam-url=scene%3Asearch%7Cquery_from%3A)  -  2.7$
- Small project box such as [that.](https://www.aliexpress.com/item/1005002656761229.html?spm=a2g0o.productlist.main.3.7e095ac2loF4tA&algo_pvid=e90d0fae-e5b0-4320-add7-939ad7654e35&algo_exp_id=e90d0fae-e5b0-4320-add7-939ad7654e35-1&pdp_npi=4%40dis%21USD%211.48%211.48%21%21%211.48%211.48%21%402103890917183704834184112e225e%2112000021581992889%21sea%21IL%21127988983%21&curPageLogUid=opAaPjyhCFQs&utparam-url=scene%3Asearch%7Cquery_from%3A)  -  1.5$
- **Total                under 8$**

### Wiering:
See wiering diagram in [DOCS](https://github.com/avicarmeli/TPMS-SDR/blob/main/Docs/ESP-SDR%20connection%20diagram.md).
