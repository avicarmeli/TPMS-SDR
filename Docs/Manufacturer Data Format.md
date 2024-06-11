#The TPMS BLE "manufacturer data" format
The devices cannot be connected or paired to and the devices do not receive any incoming BLE data. All data is broadcast as part of the "Manufacturer data" portion of the BLE advertisement. Manufacturer data looks like this:

000180EACA108A78E36D0000E60A00005B00
And now let's analyze in depth the received data:

bytes 0 and 1
0001 Manufacturer (see https://www.bluetooth.com/specifications/assigned-numbers/company-identifiers/)

byte 2
80 Sensor Number (80:1, 81:2, 82:3, 83:4, ...)

bytes 3 and 4
EACA Address Prefix

bytes 5, 6 and 7
108A78 Sensor Address

bytes 8, 9, 10 and 11
E36D0000 Tire pressure (in kPA)

bytes 12, 13, 14 and 15
E60A0000 Tire Temperature (in Celsius)

byte 16
5B Battery Percentage

byte 17
00 Alarm Flag (00: Ok, 01: No pressure)


Extract Tire pressure and temperature
Bytes 8,9,10 and 11 are a representation of the air pressure in kPA; Bytes 12,13,14 and 15 represent the temperature in Celsius. To get the values we need to do a little-endian conversion.

long result = byte0|byte1<<8|byte2<<16|byte3<<24

The pressure (Bytes 8,9,10,11) in kPA is obtained by dividing by 1000 the value obtained from the conversion:
kPA=result/1000.0

The pressure (Bytes 8,9,10,11) in bar is obtained by dividing by 100000 the value obtained from the conversion:
bar=result/100000.0

The temperature (Bytes 12,13,14,15) in Celsius is obtained by dividing by 100 the value obtained from the conversion:
temp=result/100.0
Battery Percentage
Byte 16 return the battery Percentage

Alarm Flag
Byte 17 return the Alarm Flag
00 Normal condition
01 No Pressure
