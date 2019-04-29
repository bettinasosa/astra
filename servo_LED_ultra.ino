
int TRIG_PIN  = 13;
int ECHO_PIN  = 12;
int BAUD_RATE = 9600;
int LEDs      = 7;
int servoPin  = 9;
#include <Servo.h>

Servo myServo;



void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(LEDs, OUTPUT);

  myServo.attach(servoPin);
  Serial.begin(BAUD_RATE);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

 const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
 int distance= duration/29/2;
 if(duration==0){
   Serial.println("Warning: no pulse from sensor");
   } 
  else{
      Serial.print("distance to nearest object:");
      Serial.println(distance);
      if(distance < 20){
        digitalWrite(LEDs, HIGH);
        myServo.write(0);
        delay(30000);
        myServo.write(90);
        digitalWrite(LEDs, LOW);
        delay(300000);
        myServo.write(180);
        delay(5000);
      }
         }
      
 }
