#import matplotlib  ## 파이참 pro 버전은 과학도구를 지원하기 때문에 설정을 해줘야 한다.
#matplotlib.use('TkAgg')    ## setting - tool - python scientific - uncheck 해두면 사용하지 않아도 됨.

import matplotlib.pyplot as plt
import serial

ser = serial.Serial('com6', 9600)

plt.ion()

x_data =[]
y_data =[]

i = 0
while True:
    i = i+0.5
    a = ser.readline()
    b = float(a[0:4])
    x_data.append(i)
    y_data.append(b)
    plt.title('Distance(cm):' + str(b))
    plt.xlabel('Time(s)')
    plt.ylabel('Distance(cm)')
    plt.plot(x_data, y_data, 'b-')
    plt.pause(0.001)