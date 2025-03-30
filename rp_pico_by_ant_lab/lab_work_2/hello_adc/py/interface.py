import serial
import time as tm
import matplotlib.pyplot as plt
import matplotlib.pyplot as ticker
import numpy as np

file = open('data.txt', 'w')
flag = True

ser = serial.Serial(
    port="COM5", 
    baudrate=115200, 
    timeout=1.0
    )

all_time = float(input('Введите время измерений: '))
d_time = float(input('Введите промежуток времени для измерений: '))

start_time = tm.time()

while all_time >= tm.time()-start_time:
    ser.write('a'.encode('ascii'))
    simple_time = tm.time()
    file.write(str(simple_time-start_time)+' ')
    file.write(str(ser.read(10).decode('utf-8')[:-2])+'\n')
    tm.sleep(d_time)

file.close()