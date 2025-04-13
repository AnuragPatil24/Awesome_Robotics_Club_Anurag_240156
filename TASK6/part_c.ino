// Left Motors - IBT-2 A
#define LPWM_A 10
#define RPWM_A 9

// Right Motors - IBT-2 B
#define LPWM_B 12
#define RPWM_B 11

void setup() {
  pinMode(LPWM_A, OUTPUT);
  pinMode(RPWM_A, OUTPUT);
  pinMode(LPWM_B, OUTPUT);
  pinMode(RPWM_B, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    switch (cmd) {
      case 'F': moveForward(); break;
      case 'B': moveBackward(); break;
      case 'L': turnLeft(); break;
      case 'R': turnRight(); break;
      case 'S': stopMotors(); break;
    }
  }
}

void moveForward() {
  analogWrite(RPWM_A, 200); analogWrite(LPWM_A, 0);
  analogWrite(RPWM_B, 200); analogWrite(LPWM_B, 0);
}

void moveBackward() {
  analogWrite(RPWM_A, 0); analogWrite(LPWM_A, 200);
  analogWrite(RPWM_B, 0); analogWrite(LPWM_B, 200);
}

void turnLeft() {
  analogWrite(RPWM_A, 0); analogWrite(LPWM_A, 200);  // Left reverse
  analogWrite(RPWM_B, 200); analogWrite(LPWM_B, 0);  // Right forward
}

void turnRight() {
  analogWrite(RPWM_A, 200); analogWrite(LPWM_A, 0);  // Left forward
  analogWrite(RPWM_B, 0); analogWrite(LPWM_B, 200);  // Right reverse
}

void stopMotors() {
  analogWrite(RPWM_A, 0); analogWrite(LPWM_A, 0);
  analogWrite(RPWM_B, 0); analogWrite(LPWM_B, 0);
}