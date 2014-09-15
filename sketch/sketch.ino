// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
int pos = 140;    // variable to store the servo position 
int led = 21;

void setup() 
{ 
  Serial.begin(115200);
  delay(100);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  pinMode(led, OUTPUT);  
  myservo.write(pos);
} 
 
 
void loop() 
{ 
  while (Serial.available()){
    pos = (int)Serial.read();
    Serial.println(pos);
    if (pos == 0){}
    if (pos > 1 and pos <= 25) {
      myservo.write(135);
      digitalWrite(led, HIGH); 
    }
    if (pos >= 26 and pos <= 50) {
      myservo.write(125);
      digitalWrite(led, LOW);
    }
    if (pos >= 51 and pos <= 75) {
      myservo.write(115);
      digitalWrite(led, HIGH);       
    }
    if (pos >= 76 and pos <= 100) {
      myservo.write(100);
      digitalWrite(led, LOW);      
    }
    if (pos >= 101 and pos <= 125) {
      myservo.write(90);
      digitalWrite(led, HIGH);         
    }
    if (pos >= 126 and pos <= 150) {
      myservo.write(90);
      digitalWrite(led, LOW);      
    }
    if (pos >= 151 and pos <= 175) {
      myservo.write(80);
      digitalWrite(led, HIGH);       
    }
    if (pos >= 176 and pos <= 200) {
      myservo.write(70);
      digitalWrite(led, LOW);      
    }
    if (pos >= 201 and pos <= 225) {
      myservo.write(60);
      digitalWrite(led, HIGH);         
    }
    if (pos >= 226 and pos <= 255) {
      myservo.write(55);
      digitalWrite(led, LOW);       
    }
    if (pos >= 256 and pos <= 280) {
      myservo.write(50);
      digitalWrite(led, HIGH);        
    }
  }
} 
