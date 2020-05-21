int red_pin1=9;
int blue_pin1=10;
int green_pin1=11;

int red_pin2=3;
int blue_pin2=5;
int green_pin2=6;

int but1_pin=7;
int but2_pin=8;
int but3_pin=12;
int but4_pin=13;


void setup()
{
  pinMode(red_pin1,OUTPUT);
  pinMode(blue_pin1,OUTPUT);
  pinMode(green_pin1,OUTPUT);
 
  pinMode(red_pin2,OUTPUT);
  pinMode(blue_pin2,OUTPUT);
  pinMode(green_pin2,OUTPUT);
  
  pinMode(but1_pin,INPUT);
  pinMode(but2_pin,INPUT);
  pinMode(but3_pin,INPUT);
  pinMode(but4_pin,INPUT);
  
  pinMode(4, OUTPUT);
  pinMode(2,OUTPUT);
}

void loop()
{
  int button1,button2,button3,button4;
  button1=digitalRead(but1_pin);
  button2=digitalRead(but2_pin);
  button3=digitalRead(but3_pin);
  button4=digitalRead(but4_pin);
  
  if(button1==1)
  {
    light(0,0,255);
  }
  else if(button2==1)
  {
    light(255,0,0);
  }
  else if(button3==1)
  {
    light(255,165,0);
  }
  else if(button4==1)
  {
    light(0,255,0);
  }
}

void light(int r,int g, int b)
{
  analogWrite(red_pin1,r);
  analogWrite(green_pin1,g);
  analogWrite(blue_pin1,b);
  
  analogWrite(red_pin2,r);
  analogWrite(green_pin2,g);
  analogWrite(blue_pin2,b);
  
  digitalWrite(4,HIGH);
  digitalWrite(2,LOW);
}

