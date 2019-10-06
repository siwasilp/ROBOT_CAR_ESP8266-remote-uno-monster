#include <Wire.h>
#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
IPAddress server(192, 168, 4, 15);
LiquidCrystal_I2C lcd(0x27, 20, 4);
WiFiClient client;

int s_up, s_dw, s_le, s_ri, s_mo,s_bk, sp_d, speed_x = 0;
byte sw_up    = D3;
byte sw_dw    = D4;
byte sw_left  = D5;
byte sw_rigth = D6;
byte sw_mode  = D7;
byte sw_break  = 10;

int  sp       = A0;
String x,xxx="" ;
byte ledPin = D0;
char ssid[] = "car";           // SSID of your AP
char pass[] = "12345678";      // password of your AP

String msg = "";    // *** OK use it
String answer = ""; // *** OK use it

void setup() {
  setup_x();
  pinMode(sw_up   , INPUT_PULLUP);
  pinMode(sw_dw   , INPUT_PULLUP);
  pinMode(sw_left , INPUT_PULLUP);
  pinMode(sw_rigth, INPUT_PULLUP);
  pinMode(sw_mode , INPUT_PULLUP);
  pinMode(sw_break , INPUT_PULLUP);
  pinMode(sp      , INPUT);
  pinMode(ledPin  , OUTPUT);
  lcd.clear();
}

void loop() {
  send_sw();
  if (millis() % 100 == 0) { // Rqs. Time SYNC [2 Sec]
    Commu_sb();
    Serial.println();
    lcd.setCursor(0, 0);
    lcd.print("Cruise > ");
    lcd.print(xxx);
    lcd.print(" ");
    lcd.setCursor(0, 1);
    lcd.print("Speed  > ");
    lcd.print(sp_d);
    lcd.print(" ");
    lcd.setCursor(0, 2);
    lcd.print("Ctrl   > ");
    lcd.print(x);
    lcd.print(" ");
    lcd.setCursor(0, 3);
    lcd.print("Cmd    > ");
    lcd.print(msg);
    lcd.print("      ");
  }
}
