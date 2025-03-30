import matplotlib.pyplot as plt
import numpy as np

time = []
humidity = []
pressure = []
temperature = []

with open('data_2.csv', 'r') as file:
    for line in file:
        data = line.split(';')
        time.append(float(data[0]))
        humidity.append(float(data[1]))
        pressure.append(float(data[2]))
        temperature.append(float(data[3]))

fig, axs = plt.subplots(3, 1)
fig.suptitle('Результаты измерения датчиком bme280')
axs[0].plot(time, humidity, 'b-')
axs[1].plot(time, pressure, 'g-')
axs[2].plot(time, temperature, 'r-')

y_label = ['Влажность, %', 'Давление, Па', 'Температура, C']
i = 0

for ax in axs.flat:
    ax.set(xlabel='Время, с', ylabel=y_label[i])
    ax.grid()
    i+=1

fig.tight_layout()
fig.savefig('image_2.png')
