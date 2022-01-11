import speech_recognition as sr
import threading

r = sr.Recognizer()

def thread_run():
    with sr.Microphone() as source:
        print("말해주세요")
        audio = r.listen(source)
        try:
            c = r.recognize_google(audio, language= 'ko-KR')
            print("{}".format(c))

        except:
            print("인식하지 못했습니다.")

        threading.Timer(4, thread_run).start()


thread_run()