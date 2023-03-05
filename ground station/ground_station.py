print('GCS DDR2019')

import serial

ser = serial.Serial()
ser.baudrate = 9600
ser.port = '/dev/rfcomm0'
ser.timeout = 0.15

ser.open()

def send_command(character_tx):
    try:
        ser.write(bytes(character_tx, 'UTF-8'))
        print(character_tx, '--->')
    except:
        print('--->', 'X' , "TX Error!")

def receive_command():
    try:
        character_rx = ser.readline()
        character_rx = str(character_rx, 'UTF-8')
        print(character_rx, '<---')
    except:
        print('X', '<---', "RX Error!")

while 1:
    print("----------")

    c = input(': ')

    if(c=='q'):
        send_command('s')
        break
    else:
        send_command(c)
        receive_command()

ser.close()