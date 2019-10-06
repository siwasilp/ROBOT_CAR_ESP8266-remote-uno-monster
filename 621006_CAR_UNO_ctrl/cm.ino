
void command_x() {
  Serial.print(" CMD : "); Serial.print(firstVal);
  Serial.print(" SPD : "); Serial.print(secondVal);
  Serial.print(" CTRL : "); Serial.print(ctrl); Serial.print(" > ");
  usSpeed = map(secondVal, 0, 1024, 0, 255);

  if (firstVal == "L") {
    digitalWrite(EN_PIN_1, HIGH);
    digitalWrite(EN_PIN_2, HIGH);
    left();
  }
  if (firstVal == "R") {
    digitalWrite(EN_PIN_1, HIGH);
    digitalWrite(EN_PIN_2, HIGH);
    right();
  }

  if (firstVal == "X" ) {
    speedx = 0;
    ctrl = 0;
    usMotor_Status = BRAKE;
    motorGo(MOTOR_1, usMotor_Status, 0);
    motorGo(MOTOR_2, usMotor_Status, 0);
  }
  if (firstVal == "M" && ctrl == 0 && st == 1) {
    digitalWrite(EN_PIN_1, HIGH);
    digitalWrite(EN_PIN_2, HIGH);
    ctrl = 1;
    Morward();
  }
  if (firstVal == "F") {
    ctrl = 0;
    st = 1;
    digitalWrite(EN_PIN_1, HIGH);
    digitalWrite(EN_PIN_2, HIGH);
    Forward();
  }
  if (firstVal == "B") {
    ctrl = 0;
    digitalWrite(EN_PIN_1, HIGH);
    digitalWrite(EN_PIN_2, HIGH);
    Reverse();
  }
  if (firstVal == "S" && ctrl == 0 ) {
    speedx = 0;
    Stop();
  }
}
