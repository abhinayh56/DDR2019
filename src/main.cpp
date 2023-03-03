// #include <Arduino.h>

// unsigned long t = 0;
// unsigned long last_pkt_t = 0;
// #define TIMEOUT 2000UL

// #define ML1 2
// #define ML2 3
// #define MR1 7
// #define MR2 4
// #define ENL 5
// #define ENR 6

// uint8_t pwm_L = 0;
// uint8_t pwm_R = 0;

// byte pkt_rx[8] = {0x15, 0xEC, 0x00, 0x00, 0x00, 0x00, 0x04, 0xD2};
// bool pkt_available = false;
// bool robot_init = false;
// bool timeout = false;

// void setup_motor_pins();
// void receive_data();
// void drive_robot(int8_t pwm_L, int8_t pwm_R);
// void drive_motor_L(int8_t pwm);
// void drive_motor_R(int8_t pwm);

// void setup(){
//   Serial.begin(9600);
//   setup_motor_pins();
// }

// void loop(){
//   receive_data();

//   if(robot_init==true){
//     if(timeout==false){
//       if((millis()-last_pkt_t) > TIMEOUT){
//         timeout = true;
//       }
//     }
//   }

//   if(timeout==false){
//     if((millis()-last_pkt_t) > TIMEOUT){
//       timeout = true;
//     }
//   }

//   if(timeout==false){
//     drive_robot(pwm_L, pwm_R);
//   }
//   else{
//     drive_robot(0, 0);
//   }
// }

// void setup_motor_pins(){
//   pinMode(ML1, OUTPUT);
//   pinMode(ML2, OUTPUT);
//   pinMode(MR1, OUTPUT);
//   pinMode(MR2, OUTPUT);
//   pinMode(ENL, OUTPUT);
//   pinMode(ENR, OUTPUT);
// }

// void receive_data(){
//   while(Serial.available()>0){
//     byte b = Serial.read();
//     // {0x15, 0xEC, 0x00, 0x00, 0x00, 0x00, 0x04, 0xD2}
//     for(int i=0;i<7;i++){
//       pkt_rx[i] = pkt_rx[i+1];
//     }
//     pkt_rx[7] = b;

//     if((pkt_rx[0]==0x15) && (pkt_rx[1]==0xEC) && (pkt_rx[6]==0x04) && (pkt_rx[7]==0xD2)){
//       pkt_available = ((pkt_rx[2] | pkt_rx[3] | pkt_rx[4]) == pkt_rx[5]);
//       if(pkt_available==true){
//         if(pkt_rx[2]==0x00){
//           robot_init = true;
//           pwm_L = pkt_rx[3];
//           pwm_R = pkt_rx[4];
//           pkt_available = false;
//           last_pkt_t = millis();
//         }
//       }
//     }
//   }
// }

// void drive_robot(int8_t pwm_L_, int8_t pwm_R_){
//   drive_motor_L(pwm_L_);
//   drive_motor_R(pwm_R_);
// }

// void drive_motor_L(int8_t pwm){
//   if(pwm>=0){
//     digitalWrite(ML1, HIGH);
//     digitalWrite(ML2, LOW);
//     analogWrite(ENL, pwm);
//   }
//   else{
//     digitalWrite(ML1, LOW);
//     digitalWrite(ML2, HIGH);
//     analogWrite(ENL, -pwm);
//   }
// }

// void drive_motor_R(int8_t pwm){
//   if(pwm>=0){
//     digitalWrite(MR1, HIGH);
//     digitalWrite(MR2, LOW);
//     analogWrite(ENR, pwm);
//   }
//   else{
//     digitalWrite(MR1, LOW);
//     digitalWrite(MR2, HIGH);
//     analogWrite(ENR, -pwm);
//   }
// }

// -------------------------------------------------
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

char c = 's';

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
  }

  if(c=='s'){
    hold();
  }
  else if(c=='f'){
    front();
  }
  else if(c=='b'){
    back();
  }
  else if(c=='l'){
    left();
  }
  else if(c=='r'){
    right();
  }
  else if(c=='a'){
    for(int i=0; i<5; i++){
      right();
      delay(800);
      left();
      delay(800);
    }
    hold();
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