void Readtemp() {

  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.print("Temperature is: ");
  currenttemp = sensors.getTempCByIndex(0);
  Serial.println(currenttemp);
  delay(10);
}


