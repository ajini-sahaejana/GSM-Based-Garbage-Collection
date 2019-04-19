int sendSMS(int x) {
  if (x == 1) {
    if (sms.SendSMS("0774739273", "Module Initialized and Ready to Use"))
    {
      Serial.println("\nSMS sent OK.");
    }
    else
    {
      Serial.println("\nError sending SMS.");
    }
  } else if (x == 2) {
    if (sms.SendSMS("0774739273", "Garbage limit Exceeded"))
    {
      Serial.println("\nSMS sent OK.");
    }
    else
    {
      Serial.println("\nError sending SMS.");
    }
  } else if (x == 3) {
    if (sms.SendSMS("0774739273", "Warning - Temperature Exceeded"))
    {
      Serial.println("\nSMS sent OK.");
    }
    else
    {
      Serial.println("\nError sending SMS.");
    }
  }
}
