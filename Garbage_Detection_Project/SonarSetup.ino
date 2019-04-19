void pingSonar() {
  distance = (sonar.ping()) / 57;
  delay(50);
  Serial.println(distance);
}
