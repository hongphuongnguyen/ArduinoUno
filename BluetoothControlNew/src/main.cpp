#include "SoftwareSerial.h"
SoftwareSerial HC05(3,2);
#include "Arduino.h"

char command;
byte SpMaxL = 255;
byte SpMaxR = 255;

#define enA  6
#define enB  5
#define in1  9
#define in2  10
#define in3  11
#define in4  12
#define ledFront 4
#define ledBehind 13
#define buzzer A5


void Forward( byte speedL, byte speedR);
void ForwardLeft();
void ForwardRight();
void Back(byte SpeedL, byte SpeedR);
void BackLeft();
void BackRight();
void Left();
void Right();
void Stop();
void TurnOnLedFront();
void TurnOffLedFront();
void TurnOnLedBehind();
void TurnOffLedBehind();
void TurnOnBuzzer();
void TurnOffBuzzer();

void setup() {
  HC05.begin(9600);
  Serial.begin(9600);
  pinMode(in1, OUTPUT);     
  pinMode(in2, OUTPUT);          
  pinMode(in3, OUTPUT);     
  pinMode(in4, OUTPUT);     
  pinMode(enA, OUTPUT);     
  pinMode(enB, OUTPUT);       
  pinMode(ledFront, OUTPUT);  
  pinMode(ledBehind, OUTPUT);  
  pinMode(buzzer, OUTPUT);         
}

void loop() {
  if(HC05.available() > 0)
  {
    command = HC05.read();
    //Serial.println(command);
    switch(command)
    {
      case 'F':
        Forward(SpMaxL, SpMaxR);
        break;
      case 'B':
        Back(SpMaxL, SpMaxR);
        break;
      case 'L':
        Left();
        break;
      case 'R':
        Right();
        break;
      case 'G':
        ForwardLeft();
        break;
      case 'I':
        ForwardRight();
        break;
      case 'H':
        BackLeft();
        break;
      case 'J':
        BackRight();
        break;
      case 'W':
        TurnOnLedFront();
        break;
      case 'w':
        TurnOffLedFront();
        break;
      case 'U':
        TurnOnLedBehind();
        break;
      case 'u':
        TurnOffLedBehind();
        break;
      case 'V':
        TurnOnBuzzer();
        break;
      case 'v':
        TurnOffBuzzer();
        break;
      default:
        Stop();
        break;
    }
  }
}

void Forward( byte speedL, byte speedR){
  analogWrite(enA, speedL);
  analogWrite(enB, speedR);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void ForwardLeft(){
  analogWrite(enA, 50);
  analogWrite(enB, SpMaxR);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void ForwardRight(){
  analogWrite(enA, SpMaxL);
  analogWrite(enB, 50);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void Back(byte SpeedL, byte SpeedR){
  analogWrite(enA, SpeedL);
  analogWrite(enB, SpeedR);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

void BackLeft(){
  analogWrite(enA, 50);
  analogWrite(enB, SpMaxR);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

void BackRight(){
  analogWrite(enA, SpMaxL);
  analogWrite(enB, 50);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

void Left(){
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void Right(){
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}

void Stop(){
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}

void TurnOnLedFront(){
  digitalWrite(ledFront, 1);
}

void TurnOffLedFront(){
  digitalWrite(ledFront, 0);
}

void TurnOnLedBehind(){
  digitalWrite(ledBehind, 1);
}

void TurnOffLedBehind(){
  digitalWrite(ledBehind, 0);
}

void TurnOnBuzzer(){
  digitalWrite(buzzer, 1);
}

void TurnOffBuzzer(){
  digitalWrite(buzzer, 0);
}
