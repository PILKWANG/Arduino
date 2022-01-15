import speech_recognition as sr
import threading

r = sr.Recognizer()

def thread_run():
    with sr.Microphone() as source:
        print("Speak Anything")
        audio = r.listen(source)
        try:
            c = r.recognize_google(audio)
            print("{}".format(c))

        except:
            print("Sorry could not recognize your voice")

        threading.Timer(4, thread_run).start()


thread_run()
