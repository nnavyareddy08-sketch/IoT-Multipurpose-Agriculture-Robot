#include <Servo.h>

Servo myServo;

// Motor Pins
int m1 = A0;
int m2 = A1;
int m3 = A2;
int m4 = A3;

// Relay Pins
int relay1 = 24;
int relay2 = 25;

void setup() {

  Serial.begin(9600);      // USB Monitor
  Serial1.begin(9600);     // From NodeMCU

  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

  myServo.attach(5);

  Stop();

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
}

void loop() {

  if (Serial1.available()) {

    int value = Serial1.parseInt();
    Serial.println(value);

    // ===== MOTOR CONTROL =====
    if (value == 5) forward();
    else if (value == 13) backward();
    else if (value == 8) left();
    else if (value == 10) right();
    else if (value == 6) Stop();

    // ===== SERVO CONTROL =====
    else if (value == 9) myServo.write(90);
    else if (value == 14) myServo.write(10);

    // ===== RELAY CONTROL =====
    else if (value == 16) digitalWrite(relay1, LOW);
    else if (value == 17) digitalWrite(relay2, LOW);
    else if (value == 18) digitalWrite(relay1, HIGH);
    else if (value == 20) digitalWrite(relay2, HIGH);
  }
}

//////// MOTOR FUNCTIONS ////////

void backward() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void forward() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}

void left() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);

  
}

void right() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}

void Stop() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}
