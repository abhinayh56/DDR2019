print('GCS DDR2019')

import serial

ser = serial.Serial()
ser.baudrate = 9600
ser.port = '/dev/rfcomm1'

ser.open()

while 1:
    character = input()
    if character == 'q':
        break
    ser.write(bytes(character, 'UTF-8'))

ser.close()