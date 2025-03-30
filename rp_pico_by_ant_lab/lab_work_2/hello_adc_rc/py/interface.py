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

cmd = 'e'

while all_time >= tm.time()-start_time:
    ser.write(cmd.encode('ascii')) 
    simple_time = tm.time()
    file.write(str(simple_time-start_time)+' ')
    volt = ser.read(10).decode('utf-8')[:-2]
    file.write(str(volt)+'\n')
    tm.sleep(d_time)
    if float(volt) > 2.8:
        cmd = 'd'
    elif float(volt) < 0.5:
        cmd = 'e'

file.close()