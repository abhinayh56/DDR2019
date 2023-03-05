print('GCS DDR2019')

import serial
import time

ser = serial.Serial()
ser.baudrate = 9600
# ser.port = '/dev/rfcomm3'
ser.port = '/dev/ttyACM0'
# ser.timeout = 0.15

ser.open()

def crc8(data):
    polynomial = 0x07
    crc = 0x00
    for byte in data:
        crc ^= byte
        for _ in range(8):
            if crc & 0x80:
                crc = (crc << 1) ^ polynomial
            else:
                crc <<= 1
    return crc & 0xff

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
    pwm_L = 0
    pwm_R = 0
    
    pwm_L = pwm_L & (0b1111111111111111)
    pwm_R = pwm_R & (0b1111111111111111)

    pwm_Lh = pwm_L >> 8
    pwm_Ll = pwm_L & (0b11111111)
    pwm_Rh = pwm_R >> 8
    pwm_Rl = pwm_R & (0b11111111)

    tx_pkt = [0x15, 0xEC, 0x00, pwm_Lh, pwm_Ll, pwm_Rh, pwm_Rl, 0x00, 0x04, 0xD2]

    crc = crc8(bytearray(tx_pkt[2:7]))
    tx_pkt[7] = crc
    
    tx_pkt = bytearray(tx_pkt)
    ser.write(tx_pkt)

    c = ser.readline()

    time.sleep(0.099)

ser.close()


# print('GCS DDR2019')

# import serial

# ser = serial.Serial()
# ser.baudrate = 9600
# ser.port = '/dev/rfcomm0'
# ser.timeout = 0.15

# ser.open()

# def send_command(character_tx):
#     try:
#         ser.write(bytes(character_tx, 'UTF-8'))
#         print(character_tx, '--->')
#     except:
#         print('--->', 'X' , "TX Error!")

# def receive_command():
#     try:
#         character_rx = ser.readline()
#         character_rx = str(character_rx, 'UTF-8')
#         print(character_rx, '<---')
#     except:
#         print('X', '<---', "RX Error!")

# while 1:
#     print("----------")

#     c = input(': ')

#     if(c=='q'):
#         send_command('s')
#         break
#     else:
#         send_command(c)
#         receive_command()

# ser.close()