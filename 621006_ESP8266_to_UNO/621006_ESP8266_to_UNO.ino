//=========== ESP8266 -> TO UNO ===========

#include <ESP8266WiFi.h>
WiFiServer server(80);
IPAddress IP(192, 168, 4, 15);
IPAddress mask = (255, 255, 255, 0);

#include <SoftwareSerial.h>
SoftwareSerial NodeSerial(D5, D6); // RX | TX

byte ledPin = 2;
char ssid[] = "car";           // SSID of your AP
char pass[] = "12345678";         // password of your AP
int speed_set = 0;

void setup() {
  pinMode(D0, OUTPUT);
  Serial.begin(115200);
  Serial.println();
  Serial.println("accesspoint_bare_01.ino");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, pass);
  WiFi.softAPConfig(IP, IP, mask);
  server.begin();
  pinMode(ledPin, OUTPUT);
  Serial.println("Server started.");
  Serial.print("IP: ");     Serial.println(WiFi.softAPIP());
  Serial.print("MAC:");     Serial.println(WiFi.softAPmacAddress());
  pinMode(D5, INPUT);
  pinMode(D6, OUTPUT);
  NodeSerial.begin(9600);
}

String msg = "";       // *** OK use it
String request = "";   // *** OK use it
String firstVal;  int secondVal;
int x = 0;

void loop() {
  
  Commu_ap();  //NETWORK_GET
  
  //---- LOOP SEND-----------------------------
  if (millis() % 50 == 0) {
    Serial.print(" ESP_SEND >");
    Serial.println(request);
    NodeSerial.print(request);
    NodeSerial.print("\n");
  } 
  //----- LOOP SENSOR -------------------------
  if (millis() % 500 == 0) {
    Serial.print(" 2-REMOTE >");
    Serial.println(msg);
    msg = millis()/1000;
  } 
  
}
