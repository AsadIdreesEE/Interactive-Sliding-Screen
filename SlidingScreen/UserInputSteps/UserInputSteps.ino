#include <AccelStepper.h>

const int stepsPerRevolution = 1600; // Change this according to your motor's specification
const int DIRPin = 8;  // Direction pin
const int PULPin = 9; // Step pin
const int enablePin = 4; // Enable pin

AccelStepper stepper(1, PULPin, DIRPin); // Initialize AccelStepper object

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(enablePin, OUTPUT); // Set enable pin as output
  digitalWrite(enablePin, LOW); // Enable the stepper motor
  
  stepper.setMaxSpeed(2000); // Set maximum speed in steps per second
  stepper.setAcceleration(1000); // Set acceleration in steps per second per second
}

void loop() {
  if (Serial.available() > 0) {
    int targetPosition = Serial.parseInt(); // Read the target position from the serial monitor
    Serial.print("Moving stepper motor to position ");
    Serial.println(targetPosition);
    moveToPosition(targetPosition); // Move the stepper motor to the specified position
  }
}

void moveToPosition(int targetPosition) {
  stepper.moveTo(targetPosition); // Set the target position for the stepper motor
  while (stepper.distanceToGo() != 0) {
    stepper.run(); // Continuously run the stepper motor until it reaches the target position
  }
}
