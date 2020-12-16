#Copyright 2021 HarshTheSharma
#imports
import serial
import speech_recognition as sr
import time

#variables
Debug = True 
recognizer = sr.Recognizer()
key_phrase = '*'
arduino = serial.Serial("COM3", 9600)
time.sleep(2)
# The Google API censors swear words with "*" So this variable is essentially a list of every swear recognized by google

#A loop comparing speech from the microphone to the variable above
with sr.Microphone() as source:
    print('Please start speaking:\n')
    while True:
        audio_input = recognizer.listen(source)
        try:
            text = recognizer.recognize_google(audio_input)
            if Debug == True:
                print(str(text))
            if key_phrase.lower() in text.lower():
                print('Keyword detected in the speech.')
                serial = "1"
                time.sleep(1)
                arduino.write(serial.encode())
                
        except Exception as e:
            print('Please speak again.')