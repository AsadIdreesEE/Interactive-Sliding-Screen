#include <AccelStepper.h>

const int stepsPerRevolution = 1600; // Change this according to your motor's specification
const int DIRPin = 8;  // Direction pin
const int PULPin = 9; // Step pin
const int ENAPin = 4; // Enable pin
const int command; // Variable to store the received command

AccelStepper stepper(1, PULPin, DIRPin); // Initialize AccelStepper object

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(ENAPin, OUTPUT); // Set enable pin as output
  digitalWrite(ENAPin, LOW); // Enable the stepper motor
  stepper.setMaxSpeed(1200); // Set maximum speed in steps per second
  stepper.setAcceleration(900); // Set acceleration in steps per second per second
  stepper.setCurrentPosition(0); // Set the current position as origin
  //Serial.println ("Enter the Frame Number to Move the Motor:");
}

void loop() {
  if (Serial.available() > 0) {
    int command = Serial.parseInt(); // Read the Frame Number from the serial monitor
    Serial.print (command);
    switch (command) {
      case 1:
         stepper.moveTo(0);
         stepper.runToPosition();
        break;
        
      case 2:
         stepper.moveTo(3000);
         stepper.runToPosition();
        break;

      case 3:
         stepper.moveTo(6000);
         stepper.runToPosition();
        break;

      case 4:
         stepper.moveTo(9000);
         stepper.runToPosition();
        break;
    
    }
  }
}
