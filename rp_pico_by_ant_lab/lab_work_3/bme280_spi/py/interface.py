import serial
import time as tm

ser = serial.Serial(
    port="COM9", 
    baudrate=115200, 
    timeout=1.0
    )

all_time = float(input('Введите время измерений: '))

file = open('data_1.csv', 'w')
ser.write('i'.encode('ascii'))
start_time = tm.time()

while all_time >= tm.time()-start_time:
    ser.write('a'.encode('ascii'))
    simple_time = tm.time()
    file.write(str(simple_time-start_time)+';')
    file.write(str(ser.read(7).decode('utf-8')[:-2])+';')
    file.write(str(ser.read(7).decode('utf-8')[:-2])+';')
    file.write(str(ser.read(7).decode('utf-8')[:-2])+';\n')
    # tm.sleep(0.5)

print('###')

file = open('data_2.csv', 'w')
ser.write('n'.encode('ascii'))
start_time = tm.time()

while all_time >= tm.time()-start_time:
    ser.write('a'.encode('ascii'))
    simple_time = tm.time()
    file.write(str(simple_time-start_time)+';')
    file.write(str(ser.read(7).decode('utf-8')[:-2])+';')
    file.write(str(ser.read(7).decode('utf-8')[:-2])+';')
    file.write(str(ser.read(7).decode('utf-8')[:-2])+';\n')
    # tm.sleep(0.5)

file.close()