# Renault TPMS 433Mhz data Format

FSK 9 byte Manchester encoded TPMS with CRC.
Seen on Renault Clio, Renault Captur and maybe Dacia Sandero.

## **Packet nibbles:**

   ** F F/P PP TT II II II ?? ?? CC**

- F = flags, (seen: c0: 22% c8: 14% d0: 31% d8: 33%) maybe 110??T
- P = Pressure, 10 bit 0.75 kPa
- I = id, 24-bit little-endian
- T = Temperature in C, offset -30
- ? = Unknown, mostly 0xffff
- C = Checksum, CRC-8 truncated poly 0x07 init 0x00
