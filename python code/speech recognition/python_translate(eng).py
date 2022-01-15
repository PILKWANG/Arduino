import speech_recognition as sr

from os import path

from pprint import pprint

audio_file = path.join(path.dirname(path.realpath(__file__)), "knue.wav")

r = sr.Recognizer()

with sr.AudioFile(audio_file) as source :
    audio = r.record(source)

try:
    text = r.recognize_google(audio, show_all=True)
    pprint (text)

except:
    print ("Didn't work.")