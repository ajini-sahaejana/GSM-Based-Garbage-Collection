void setup() {

  Serial.begin(9600);

  myservo1.attach(12);
  myservo1.write(0);
  myservo2.attach(11);
  myservo2.write(0);
  myservo3.attach(10);
  myservo3.write(0);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(blinkPin, OUTPUT);
  pinMode(32, OUTPUT);

  sensors.begin();

  if (gsm.begin(9600))
  {
    Serial.println("\nstatus=READY");
    started = true;
  }
  else
    Serial.println("\nstatus=IDLE");

  if (started) {
    sendSMS(1);
  }
}

void loop() {
  pingSonar();
  Readtemp();
  if (started)
  {
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);


    if (buttonState1 == HIGH) {
      myservo2.write(120);
      digitalWrite(ledPin, HIGH);
      Serial.println("Garbage Bin Submerged");
    }

    if (buttonState2 == HIGH) {
      myservo2.write(0);
      digitalWrite(ledPin, LOW);
      Serial.println("Garbage Bin Emerged");
    }

    if (distance < 20) {
      digitalWrite(32, HIGH);
      if (limitSMSsent == 0) {
        sendSMS(2);
        limitSMSsent = 1;
      }

      myservo1.write(90);
      delay(50);

      delay(3000);

      myservo1.write(0);
      delay(50);

      Serial.println("Garbage removed");
      pingSonar();
    }

    if (distance > 20) {
      limitSMSsent = 0;
      digitalWrite(32, LOW);
    }

    if (currenttemp >= 28) {
      blinkLED();
      Serial.println("Temperature Exceeded");
      if (tempSMSsent == 0) {
        sendSMS(3);
        tempSMSsent = 1;
      }


      receiveSMS();
      if ((sms_text[0] == 'C') || (sms_text[0] == 'c')) {
        if ((sms_text[1] == 'O') || (sms_text[1] == 'o')) {
          if ((sms_text[2] == 'M') || (sms_text[2] == 'm')) {
            if ((sms_text[3] == 'P') || (sms_text[3] == 'p')) {
              myservo3.write(90);
            }
          }
        }
      }
    } else if (currenttemp < 28) {
      tempSMSsent = 0;
      digitalWrite(blinkPin, LOW);
      myservo3.write(0);
      delay(50);

    }
  }

}





