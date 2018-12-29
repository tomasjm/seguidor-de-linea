void setupVars() {
  i3l = data[0];
  i2l = data[2];
  i1l = data[4];
  i0l = data[6];
  d0l = data[8];
  d1l = data[10];
  d2l = data[12];
  d3l = data[14];
}

void datosLinea() {
  Wire.requestFrom(9, 16);    // request 16 bytes from slave device #9
  while (Wire.available())   // slave may send less than requested
  {
    data[t] = Wire.read(); // receive a byte as character
    if (t < 15)
      t++;
    else
      t = 0;
  }
  setupVars();
  /*
  Serial.print("data[0]:");
  Serial.println(data[0]);
  Serial.print("data[2]:");
  Serial.println(data[2]);
  Serial.print("data[4]:");
  Serial.println(data[4]);
  Serial.print("data[6]:");
  Serial.println(data[6]);
  Serial.print("data[8]:");
  Serial.println(data[8]);
  Serial.print("data[10]:");
  Serial.println(data[10]);
  Serial.print("data[12]:");
  Serial.println(data[12]);
  Serial.print("data[14]:");
  Serial.println(data[14]);
  */
  delay(15);
}

bool superficieNegra(int dato) {
  if (dato < 50) {
    return true;  
  }  else {
    return false;
  }
}
