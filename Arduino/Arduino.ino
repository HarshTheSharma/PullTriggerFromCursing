// Copyright 2021 HarshTheSharma

#include <Stepper.h> // Include the header file
#define STEPS 32 //number of steps in my motor
Stepper stepper(STEPS, 8, 10, 9, 11); //initialize variable for the motor
int val = 0; //set a variable to 0 to represent off

void setup() {
  Serial.begin(9600); //start serial connection with computer
  stepper.setSpeed(200); //set servo speed
}

void loop() {

  if (Serial.available()>0) //check if there is new data
  {
    int val = Serial.parseInt(); //set variable to the data recieved
    if (val == 1); //if on, then run this
    {
      val = 500; //set servo to rotate 500 clockwise
      stepper.step(val); //rotate servo
      delay(500) //wait 500 ms
      val = -500; //set servo to rotate 500 counter-clockwise
      stepper.step(val); // rotate servo
      val = 0; //set variable to 0 to represent off
    }
  }
 

}
