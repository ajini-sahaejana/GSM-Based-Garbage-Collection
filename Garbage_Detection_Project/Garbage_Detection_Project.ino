/*===================================================================

          //Servo Motors

  =====================================================================*/

#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;

/*===================================================================

          //Ultrasonic

  =====================================================================*/

#include <NewPing.h>

#define MAX_DISTANCE 400

NewPing sonar(22, 24, MAX_DISTANCE); //TRIGGER,ECHO, MAXDISTANCE

int distance = 0;
float duration = 0;

/*===================================================================

          //Temperature Sensor

  =====================================================================*/
#include <OneWire.h>
#include <DallasTemperature.h>


#define ONE_WIRE_BUS 2 //Temp Sensor Data Wire

OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
float currenttemp;


/*===================================================================

          //GSM Module

  =====================================================================*/

#include "SIM900.h"
#include <SoftwareSerial.h>
#include "sms.h"

SMSGSM sms;

int numdata;
boolean started = false;
char smsbuffer[160];
char n[20];

char sms_position;
char phone_number[20];
char sms_text[100];
int i;

int smsflag = 0;

/*===================================================================

          //Push Button

  =====================================================================*/

const int buttonPin1 = 26;
const int buttonPin2 = 28;
int buttonState1 = 0;
int buttonState2 = 0;


/*===================================================================

          //LED and Blinking

  =====================================================================*/
const int ledPin =  23;
const int blinkPin =  30;
int blinkState = LOW;

unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 300;           // interval at which to blink (milliseconds)


/*===================================================================

          //Status Flags

  =====================================================================*/
bool tempSMSsent = 0;
bool limitSMSsent = 0;

























