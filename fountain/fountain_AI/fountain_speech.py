import serial
import matplotlib.pyplot as plt
import speech_recognition as sr
import keyboard

ser = serial.Serial('COM3', 9600)
plt.ion()

x_data = []
y_data = []

i = 0
while True:
    i = i + 0.5
    a = ser.readline()
    b = float(a[0:4])
    x_data.append(i)
    y_data.append(b)
    plt.title('Pressure: ' + str(b))
    plt.xlabel('Time(s)')
    plt.plot(x_data, y_data, 'r-')
    plt.pause(0.001)

    if keyboard.is_pressed('6'):

        r = sr.Recognizer()
        with sr.Microphone() as source:
            print("Speak Anything")
            audio = r.listen(source)
            try:
                c = r.recognize_google(audio,language='ko-KR')
                print("{}".format(c))
                while (1):

                    if c == '안녕하세요':
                        ser.write(b'r')
                        break
                    elif c == '감사합니다':
                        ser.write(b'g')
                        break
                    else:
                        c = c.encode('utf-8')
                        ser.write(c)
                        break
            except:
                print("Sorry could not recognize your voice")
