import speech_recognition as sr

r = sr.Recognizer()



with sr.Microphone() as source:
    print("Speak Anything")
    audio = r.listen(source)

with open("knue.wav", "wb") as f:
    f.write(audio.get_wav_data())
