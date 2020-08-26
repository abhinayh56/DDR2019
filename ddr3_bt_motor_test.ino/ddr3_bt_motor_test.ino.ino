int ml1=2;
int ml2=3;
int mr1=7;
int mr2=4;
int enl=5;
int enr=6;

float x;

void setup()
{
  Serial.begin(9600);
  setup_motor_pins();
  hold();  
  set_speed(100);
}

void loop()
{
  if(Serial.available()>0)
  {
    x=Serial.read();
    Serial.println(char(x));
    if(x=='s')
    {
      hold();
    }
    if(x=='f')
    {
      front();
    }
    if(x=='b')
    {
      back();
    }
    if(x=='l')
    {
      left();
    }
    if(x=='r')
    {
      right();
    }
    if(x=='a')
    {
      for(int i=0; i<5; i++)
      {
        right();
        delay(800);
        left();
        delay(800);
      }
      hold();
    }
  }
}

void setup_motor_pins()
{
  pinMode(ml1,OUTPUT);
  pinMode(ml2,OUTPUT);
  pinMode(mr1,OUTPUT);
  pinMode(mr2,OUTPUT);
  pinMode(enl,OUTPUT);
  pinMode(enr,OUTPUT);
}

void set_speed(int duty_cycle_)
{
  analogWrite(enl,duty_cycle_);
  analogWrite(enr,duty_cycle_);
}

void hold()
{
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,LOW);
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,LOW);
}

void front()
{
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
}

void back()
{
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
}

void left()
{
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
}

void right()
{
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
}
