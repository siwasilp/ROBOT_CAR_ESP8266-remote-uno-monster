void Stop()
{
  Serial.println("Stop");
  usMotor_Status = BRAKE;
  motorGo(MOTOR_1, usMotor_Status, 0);
  motorGo(MOTOR_2, usMotor_Status, 0);
}

void Forward()
{
  Serial.println("Forward");
  usMotor_Status = CW;
  //motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
  speedx=usSpeed;
}

void Morward()
{
  Serial.print("M_Forward > ");
  Serial.println(speedx);
  usMotor_Status = CW;
  //motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, speedx);
}

void Reverse()
{
  Serial.println("Reverse");
  usMotor_Status = CCW;
  //motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
}

void left()
{
  Serial.println("Forward");
  usMotor_Status = CW;
   motorGo(MOTOR_1, usMotor_Status, 255);
  //motorGo(MOTOR_2, usMotor_Status, usSpeed);
}

void right()
{
  Serial.println("Reverse");
  usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, 255);
  //motorGo(MOTOR_2, usMotor_Status, usSpeed);
}
