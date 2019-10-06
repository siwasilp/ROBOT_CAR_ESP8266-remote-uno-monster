void Commu_sb() {
  //======================================
  if (Serial.available()) {
    msg = Serial.readString();
  }
  //======================================
 
    client.connect(server, 80);
    digitalWrite(ledPin, LOW);
    Serial.print(" OUT > ");
    Serial.print(msg);
    client.print(msg + "\r");
    answer = client.readStringUntil('\r');
    Serial.print(" INP > " + answer);
    client.flush();
    digitalWrite(ledPin, HIGH);
    client.stop(); 
}
