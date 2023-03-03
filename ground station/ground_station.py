import threading
import time

global a
a = 100

def print_cube(num):
    while(True):
        global a
        a = input()
        print(10)
        time.sleep(1)
 
def print_square(num):
    while(True):
        print(a)
        time.sleep(0.5)
 
if __name__ =="__main__":
    t1 = threading.Thread(target=print_square, args=(10,))
    t2 = threading.Thread(target=print_cube, args=(10,))
 
    t1.start()
    t2.start()
 
    # t1.join()
    # t2.join()
 
    print("Done!")


# print('GCS DDR2019')

# import serial

# ser = serial.Serial()
# ser.baudrate = 9600
# ser.port = '/dev/rfcomm1'

# ser.open()

# while 1:
#     character = input()
#     if character == 'q':
#         break
#     ser.write(bytes(character, 'UTF-8'))

# ser.close()