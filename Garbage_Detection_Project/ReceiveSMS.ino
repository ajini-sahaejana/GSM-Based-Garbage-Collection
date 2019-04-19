void receiveSMS() {
  sms_position = sms.IsSMSPresent(SMS_UNREAD);
  if (sms_position)
  {
    Serial.print("SMS postion:");
    Serial.println(sms_position, DEC);
    sms.GetSMS(sms_position, phone_number, sms_text, 100);
    Serial.println(phone_number);
    Serial.println(sms_text);
  }
}
