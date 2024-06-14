# TPMS Arduino code to read RF TPMS Sensors
![image](https://github.com/avicarmeli/TPMS-SDR/assets/32562196/2d5f958e-7c0f-45a7-ba11-a033dc294d37)

## Overview:
Some TPMS (Tyre Pressure Monitor System) sensors transmit RF data. Older car models (such as my Nissan Micra 2014) Have only warning light to indicate that the pressure of one of the tyres is too low.
It is possible to use [RTL-SDR](https://github.com/topics/rtl-sdr) with [RTL_433](https://github.com/merbanan/rtl_433) to read the RF data.
Such implementation for Arduino boards and small display was assambled as a stand alone system ([Toyota TPMS project](https://www.hackster.io/jsmsolns/arduino-tpms-tyre-pressure-display-b6e544#toc-about-tpms-2)).

This Project will use ESP32 as the main Board together with CC1101 board to read TPMS data and to send that dat over BLE so that data would be recived by eigther cellphone or Android car multimeda app that would display the data and generate needed alerts.

Specificly this project is aimed at forwording the TPMS data to [TPMS Advancved android app](https://github.com/VincentMasselis/TPMS-advanced).

## Intent:
- [X] Porting the code to ESP32.
- [ ] Sending sensors data over BLE to imitate Sysgration BLE sensors so it can be displayed in cellphone app.
