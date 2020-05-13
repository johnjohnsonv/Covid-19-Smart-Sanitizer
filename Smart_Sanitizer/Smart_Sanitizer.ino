#include <Servo.h>

Servo myservo;
int pos = 0;

int pirPin = 8;
int count = 0;
int laststate = HIGH;

void setup()
{
Serial.begin(9600);
pinMode(pirPin, INPUT);
myservo.attach(9);
myservo.write(0);
  
}

void loop()
{
  int state = digitalRead(pirPin);
  if (laststate == LOW && state == HIGH) 
  {
    for (pos =0; pos <= 60; pos += 1) { 
    
    myservo.write(pos);             
    delay(15);                       
  }
  for (pos = 60; pos >=0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
     count++;
 Serial.print("No. of visitors: ");
    Serial.println(count);
  }
  laststate = state;  
}
