import serial
import speech_recognition as sr
import time
import threading

arduino = serial.Serial('COM6', 9600)


def thread_run():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("말해주세요")
        audio = r.listen(source)
        try :
            c = r.recognize_google(audio, language= 'ko-KR')
            print("{}". format(c))
            while(1):

                if c=='멈추세요':
                    arduino.write(b'a')
                    break
                elif c=='빨간색':
                    arduino.write(b'r')
                    break
                elif c=='초록색':
                    arduino.write(b'g')
                    break
                elif c=='파란색':
                    arduino.write(b'b')
                    break
                else:
                    c= c.encode('utf-8')
                    arduino.write(c)
                    break
        except:
            print("인식하지 못했습니다.")

        threading.Timer(4, thread_run).start()

thread_run()
