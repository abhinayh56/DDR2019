#include <Arduino.h>

#define ML1 2
#define ML2 3
#define MR1 7
#define MR2 4
#define ENL 5
#define ENR 6

void setup_motor_pins();
void set_speed(int duty_cycle_);
void hold();
void front();
void back();
void left();
void right();


void setup(){
  Serial.begin(9600);
  
  setup_motor_pins();
  hold();  
  set_speed(100);
}

void loop(){
  if(Serial.available()>0){
    char c = Serial.read();
    Serial.println(c);
    if(c=='s'){
      hold();
    }
    if(c=='f'){
      front();
    }
    if(c=='b'){
      back();
    }
    if(c=='l'){
      left();
    }
    if(c=='r'){
      right();
    }
    if(c=='a'){
      for(int i=0; i<5; i++){
        right();
        delay(800);
        left();
        delay(800);
      }
      hold();
    }
  }
}

void setup_motor_pins(){
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);
  pinMode(ENL, OUTPUT);
  pinMode(ENR, OUTPUT);
}

void set_speed(int duty_cycle_){
  analogWrite(ENL, duty_cycle_);
  analogWrite(ENR, duty_cycle_);
}

void hold(){
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, LOW);
  digitalWrite(MR1, LOW);
  digitalWrite(MR2, LOW);
}

void front(){
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW);
}

void back(){
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, HIGH);
  digitalWrite(MR1, LOW);
  digitalWrite(MR2, HIGH);
}

void left(){
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, HIGH);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW);
}

void right(){
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW);
  digitalWrite(MR1, LOW);
  digitalWrite(MR2, HIGH);
}