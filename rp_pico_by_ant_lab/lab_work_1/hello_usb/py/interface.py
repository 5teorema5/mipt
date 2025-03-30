import serial
import time as tm

ser = serial.Serial(
    port="COM5", 
    baudrate=115200, 
    timeout=1.0
    )

while True:
    ser.write('e'.encode('ascii'))
    tm.sleep(1)
    ser.write('d'.encode('ascii'))
    tm.sleep(1)
    ser.write('r'.encode('ascii'))
    byte = input('Введите адрес памяти: ')
    ser.write(byte.encode('ascii'))
    print(ser.read(20).decode('ascii'))
