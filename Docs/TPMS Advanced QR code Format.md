## TPMS Advanced QR Code Format For Scanning Sysgration sensors IDs
Each sensor has uniqe ID of 3 bytes long in which the left most digit (4 bits) stands for sensor location as fallows:
| value | location |
|:-------:|-------------|
| 1 | Front Left |
| 2 | Front Right |
| 3 | Rear Right |
| 4 | Rear Left |

Example sensor lable stating it's ID:

![image](https://github.com/avicarmeli/TPMS-SDR/assets/32562196/ca9029ff-314a-425b-a46a-322f1ae32081)

In this case it is Rear Left (LR is marked on sensor) so left most digit is 4 and the ID is 0AC13 as marked yeilding a complite ID of **40AC13**.

The QR code for TPMS Advanced app is composed from the 4 sensors IDs conected with & mark for example: **11AD8B&21563D&31A4F0&41A552**.

The TPMS-SDR will use constatnt fake IDs for the virtual sensors as follows:

| location | ID |
|----------|----|
| FL | 108A78 |
| FR | 208A79 |
| RR | 308A7A |
| RL | 408A7B |

The 4 sensors QR code text would be: **108A78&208A79&308A7A&408A7B**.
And the Code:

![image](https://github.com/avicarmeli/TPMS-SDR/assets/32562196/93d71995-0412-4ebb-a500-0582fb28466b)
