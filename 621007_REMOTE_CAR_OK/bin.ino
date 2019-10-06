
void setup_x() {
  lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("  CAR_CONTROL V1.4 ");
  lcd.setCursor(0, 1);
  lcd.print("SSID > "); lcd.print(ssid);
  lcd.setCursor(0, 2);
  lcd.print("PASS > "); lcd.print(pass);

  Serial.begin(115200);
  Serial.println();
  Serial.println("station_bare_01.ino");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);           // connects to the WiFi AP
  Serial.println();
  Serial.println("Connection to the AP");
  lcd.setCursor(0, 3);
  int ccc=0;
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(ledPin, LOW); delay(250);
    Serial.print(".");
    digitalWrite(ledPin, HIGH); delay(250);
    lcd.print("* "); 
    ccc++;
    if(ccc==19){lcd.setCursor(0, 3); ccc=0;}
  }
  Serial.println("Connected");
  Serial.print("LocalIP:"); Serial.println(WiFi.localIP());
  Serial.println("MAC:" + WiFi.macAddress());
  Serial.print("Gateway:"); Serial.println(WiFi.gatewayIP());
  Serial.print("AP MAC:"); Serial.println(WiFi.BSSIDstr());
  pinMode(ledPin, OUTPUT);
  lcd.clear();
  lcd.setCursor(0, 2);
  lcd.print("IP  > "); lcd.print(WiFi.localIP());
  lcd.setCursor(0, 3);
  lcd.print("MAC > "); lcd.print(WiFi.softAPmacAddress());
  
}
