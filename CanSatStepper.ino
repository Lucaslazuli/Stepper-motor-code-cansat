/* Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board and Arduino UNO. More info: https://www.makerguides.com */

// Include the Arduino Stepper.h library:
#include <Stepper.h>

// Define number of steps per rotation:
const int revolution = 2048; //2048 steps voor 1 volledige draai rond zijn as
const int StepperPowerPin = 2;
boolean figureCompleted = false;
// Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver

// Create stepper object called 'myStepper', note the pin order:
Stepper myStepper = Stepper(revolution, 8, 10, 9, 11);

void setup() {
  myStepper.setSpeed(8); //rpm
  pinMode(StepperPowerPin, OUTPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop() {        //geen idee of 4000ms een goede delaytime is
  if (digitalRead(12) == HIGH && figureCompleted == false) {
    digitalWrite(StepperPowerPin, HIGH);
    delay(4000);                                                                                   
    turnRight();
    delay(4000);
    turnLeft();
    delay(4000);
    turnRight();
    delay(4000);
    turnLeft();
    delay(4000);
    corkscrew();
    figureCompleted = true;
  }

  if (figureCompleted) {
    digitalWrite(StepperPowerPin, LOW);
  }

}

void turnRight() {                        //maakt effe touwtje korter in de ene richting en dan terug langer
  myStepper.step(revolution);
  myStepper.step(-revolution);
}

void turnLeft() {
  myStepper.step(-revolution);            //maakt effe touwtje korter in de andere richting en dan terug langer
  myStepper.step(revolution);
}

void corkscrew() {
  myStepper.step(2*revolution);
}
