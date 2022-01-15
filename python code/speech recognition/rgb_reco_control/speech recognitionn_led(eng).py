import serial
import speech_recognition as sr
import threading

arduino = serial.Serial('COM7', 9600)

r = sr.Recognizer()

def thread_run():
    with sr.Microphone() as source:
        print("Speak Anything")
        audio = r.listen(source)
        try:
            c = r.recognize_google(audio)
            print("{}".format(c))
            while (1):
                if c == 'off':
                    break
                elif c == 'color red':
                    arduino.write(b'r')
                    break

                elif c == 'color green':
                    arduino.write(b'g')
                    break

                elif c == 'color blue':
                    arduino.write(b'b')
                    break

                else:
                    c = c.encode('utf-8')
                    arduino.write(c)
                    break
        except:
            print("Sorry could not recognize your voice")

        threading.Timer(4, thread_run).start()


thread_run()
