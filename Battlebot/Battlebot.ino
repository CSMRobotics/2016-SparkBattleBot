const int inputPin = A1;
const int outputPin = 9;

int motorInput;

void setup() {
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  motorInput = pulseIn(inputPin, HIGH);

  Serial.println(motorInput);
  if(motorInput < 1500) {
    digitalWrite(outputPin, LOW);
  } else {
    digitalWrite(outputPin, HIGH);
  }
}
