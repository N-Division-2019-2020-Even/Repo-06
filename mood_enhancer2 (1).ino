
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int speakerPin = 7;

int length = 28; // the number of notes

char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";

int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };

int tempo = 150;

void setup() {
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Enter TIME in");
    lcd.setCursor(0,1);
  lcd.print("HHMM format");
}

void loop() {
  for (int i = 0; i < length; i++) {

   if (notes[i] == ' ') {

     delay(beats[i] * tempo); // rest

   } else {

     playNote(notes[i], beats[i] * tempo);

   }

   // pause between notes

   delay(tempo);

    char t_input[5];
    i=0;
    if(Serial.available())
    {
      lcd.clear();
      while(Serial.available()>0){
      t_input[i]=Serial.read();
        i++;
    }
      time((int)t_input[0],(int)t_input[1],(int)t_input[2],(int)t_input[3]);
	}
  }
}
 
void time(int h1,int h2,int m1,int m2)
{ 
  h1=h1-'0';
  h2=h2-'0';
  m1=m1-'0';
  m2=m2-'0';
  int ss='0'-'0';
  int hh=(h1*10)+h2;
  int mm=(m1*10)+m2;
  while(hh<25 && mm<60 && ss<60){
    lcd.setCursor(0,0);
    	lcd.print("Time is in 24hrs");
    for(int j=1;j<60;j++)
  {
      if(mm==60)
      {
        mm=0;
        hh++;
      }
      if(hh==24)
      {
        lcd.clear();
        lcd.setCursor(0,0);
    	lcd.print("Time is in 24hrs");
        hh=0;
      }
    for(int k=0;k<10;k++)
    {
      if(ss==60)
      {
        lcd.clear();
        lcd.setCursor(0,0);
    	lcd.print("Time is in 24hrs");
        ss='0'-'0';
        mm++;
      }
      lcd.setCursor(0,1);
      lcd.print(hh);
      lcd.setCursor(2,1);
      lcd.print(":");
      lcd.setCursor(3,1);
      lcd.print(mm);
      lcd.setCursor(5,1);
      lcd.print(":");
      lcd.setCursor(6,1);
      lcd.print(ss);
    }
    ss++;
  }
}
}

void playTone(int tone, int duration) {

for (long i = 0; i < duration * 1000L; i += tone * 2) {

   digitalWrite(speakerPin, HIGH);

   delayMicroseconds(tone);

   digitalWrite(speakerPin, LOW);

   delayMicroseconds(tone);

}

}

void playNote(char note, int duration) {

char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           

                 'c', 'd', 'e', 'f', 'g', 'a', 'b',

                 'x', 'y' };

int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,

                 956,  834,  765,  593,  468,  346,  224,

                 655 , 715 };

int SPEE = 5;

// play the tone corresponding to the note name

for (int i = 0; i < 17; i++) {

   if (names[i] == note) {
    int newduration = duration/SPEE;
     playTone(tones[i], newduration);

   }

}

}
