void read_sw() {
  s_up = digitalRead(sw_up);
  s_dw = digitalRead(sw_dw);
  s_le = digitalRead(sw_left);
  s_ri = digitalRead(sw_rigth);
  s_mo = digitalRead(sw_mode);
  s_bk = digitalRead(sw_break);
  sp_d = analogRead (sp);
  //  Serial.print(s_up);    Serial.print(" ");
  //  Serial.print(s_dw);    Serial.print(" ");
  //  Serial.print(s_le);    Serial.print(" ");
  //  Serial.print(s_ri);    Serial.print(" ");
  //  Serial.print(s_mo);    Serial.print(" ");
  //  Serial.print(speed_x); Serial.print(" ");
}

void send_sw() {
  read_sw();
  msg = "";
  if (s_bk == 0) {
    x = "        ";
    msg += "X," + String(sp_d);;
  }
  if (s_up == 0) {
    x = "Go...   ";
    msg += "F," + String(sp_d);;
  }
  if (s_dw == 0) {
    x = "Back... ";
    msg += "B," + String(sp_d);;
  }
  if (s_le == 0) {
    x = "Left... ";
    msg += "L," + String(sp_d);;
  }
  if (s_ri == 0) {
    x = "Right...";
    msg += "R," + String(sp_d);;
  }
  if (s_mo == 0) {
    xxx = "Cru_ON  ";
    msg += "M," + String(sp_d);;
  }
  if (s_up && s_dw && s_le && s_ri && s_mo && s_bk == 1) {
    xxx = "Cru_OFF";
    msg += "S," + String(sp_d);
  }
}
