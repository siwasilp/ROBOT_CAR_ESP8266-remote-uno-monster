#include <SoftwareSerial.h>
int secondVal;
String firstVal;
int speedx=0;
int st=0;
int ctrl=0;
char xxx='x';
#define BRAKE 0
#define CW    1
#define CCW   2
#define CS_THRESHOLD 15   // Definition of safety current (Check: "1.3 Monster Shield Example").

//MOTOR 1
#define MOTOR_A1_PIN 7
#define MOTOR_B1_PIN 8

//MOTOR 2
#define MOTOR_A2_PIN 4
#define MOTOR_B2_PIN 9

#define PWM_MOTOR_1 5
#define PWM_MOTOR_2 6

#define CURRENT_SEN_1 A2
#define CURRENT_SEN_2 A3

#define EN_PIN_1 A0
#define EN_PIN_2 A1

#define MOTOR_1 0
#define MOTOR_2 1

short usSpeed = 150;  //default motor speed
unsigned short usMotor_Status = BRAKE;
SoftwareSerial ArduinoSerial(12, 11); // RX, TX
void setup() {
  pinMode(12, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(115200);
  ArduinoSerial.begin(9600);

   pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);

  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);

  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(PWM_MOTOR_2, OUTPUT);

  pinMode(CURRENT_SEN_1, OUTPUT);
  pinMode(CURRENT_SEN_2, OUTPUT);

  pinMode(EN_PIN_1, OUTPUT);
  pinMode(EN_PIN_2, OUTPUT);
}

String inData;
void loop() {
  while (ArduinoSerial.available() > 0)
  {
    char recieved = ArduinoSerial.read();
    inData += recieved;

    if (recieved == '\n')
    {
      for (int i = 0; i < inData.length(); i++) {
        if (inData.substring(i, i + 1) == ","){
        firstVal  = inData.substring(0, i);
        secondVal = inData.substring(i + 1).toInt();
        }
      }
      command_x();
      inData = ""; 
    }
  }
}
