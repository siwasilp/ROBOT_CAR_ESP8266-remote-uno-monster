
void Commu_ap() {
  WiFiClient client = server.available();
  //============================================
  if (Serial.available()) {
    msg = Serial.readString();
  }
  //===========================================
  if (!client) {
    return;
  }
  digitalWrite(ledPin, LOW);
  request = client.readStringUntil('\r');

//  Serial.print(" cmd > ");
//  Serial.print(firstVal);
//  Serial.print(" speed > ");
//  Serial.print(secondVal);
//  Serial.print(" INP > " + request);
//  Serial.print(  " OUT > ");    Serial.println(msg);
 
  client.println(msg + "\r");
  client.flush(); 
  client.println(request + "\r");

  digitalWrite(ledPin, HIGH);
}
//================== Commu_ap || OK. ==================
