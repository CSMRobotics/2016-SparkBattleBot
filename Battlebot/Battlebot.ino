#include <Servo.h>
Servo rightWheel;
const int inputPin = A1;
const int inputPinTwo = A2;
const int outputPin = 9;
const int servoOut = 10;

int motorInput;
int motorInputTwo;

void setup() {
  pinMode(outputPin, OUTPUT);
  pinMode(servoOut, OUTPUT);
  rightWheel.attach(10);
  Serial.begin(9600);
}

void loop() {
  motorInput = pulseIn(inputPin, HIGH);
  motorInputTwo= pulseIn(inputPinTwo,HIGH);

  double motorOutput = 1500;
  if(motorInputTwo > 1550){
    motorOutput = 1100 + (1800 - motorInputTwo);
  }else if(motorInputTwo < 1450){
    motorOutput = 1100 + (1800 - motorInputTwo);
  }
  //double motorOutput = 1100 + (1800 - motorInputTwo);
  if(motorInputTwo > 500) {
   rightWheel.write(motorOutput); 
  }

  Serial.println(motorInputTwo);
  if(motorInput < 1500) {
    digitalWrite(outputPin, LOW);
  } else {
    digitalWrite(outputPin, HIGH);
  }
}
