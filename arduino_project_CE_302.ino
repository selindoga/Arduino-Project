#include <LiquidCrystal.h>

int Apin = 22;
int Bpin = 23;
int Cpin = 24;
int Dpin = 25;
int Epin = 26;
int Fpin = 27;
int Gpin = 28;
int Hpin = 29;

int GND4 = 33;
int GND3 = 34;
int GND2 = 35;
int GND1 = 36;

LiquidCrystal lcd(36, 37, 26, 27, 28, 29);
// int lm35 = A4; // input
//LM35 temp(A4); 

int ldr = A11; // input
int pot = A8; // input


int led3 = 46; // floor 1

int buzzer = 5; 
int relay = 6;

int JustWaitTime = 50;
int FloorWaitTime = 700;
int BuzzerTime = 150;
// SELİN DOĞA ORHAN 20180602022

void setup() {
  pinMode(Apin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  pinMode(Cpin, OUTPUT);
  pinMode(Dpin, OUTPUT);
  pinMode(Epin, OUTPUT);
  pinMode(Fpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(Hpin, OUTPUT);

  pinMode(GND1, OUTPUT); 
  pinMode(GND2, OUTPUT);
  pinMode(GND3, OUTPUT);
  pinMode(GND4, OUTPUT); 

  pinMode(led3, OUTPUT);

  //pinMode(lm35, INPUT);
  pinMode(ldr, INPUT);
  pinMode(pot, INPUT);

  lcd.begin(16,1);
  //lcd.print("Helloo birader");
  
  ResetSegments();
  digitalWrite(GND1, HIGH);
}

void loop() {
  Delay(500);
  lcd.print("Helloo birader");
  Delay(500);
  lcd.print("woooooaaa");
  
}
//ReadLM35();
  //Delay(JustWaitTime);
  //ReadPotentiometer();
  //Delay(JustWaitTime);
  //ReadLDR();
void ReadLDR(){
  int ldrv = digitalRead(ldr);
  lcd.print(ldrv);
  if(ldrv > 600){
    attachInterrupt(1,interruptLight(),CHANGE);
  }
}

void ReadPotentiometer(){
  int potm = digitalRead(pot);
  if(potm > 500){
    Buzz();
  }
}

void ReadLM35(){
  if(temp.cel() < 22){
      displayL();
    }
    if(temp.cel() > 22){
      displayH();
    }
}

void Buzz(){
  tone(buzzer, 1000);
  delay(BuzzerTime);
  noTone(buzzer);
}

void displayL(){
  ResetSegments();
  digitalWrite(Fpin, HIGH);
  digitalWrite(Epin, HIGH);
  digitalWrite(Dpin, HIGH);
}

void displayH(){
  ResetSegments();
  digitalWrite(Fpin, HIGH);
  digitalWrite(Epin, HIGH);
  digitalWrite(Gpin, HIGH);
  digitalWrite(Bpin, HIGH);
  digitalWrite(Cpin, HIGH);
}


void interruptLight(){
  digitalWrite(led3, HIGH);
  delay(300000);
  digitalWrite(led3, LOW);
}

void ResetSegments() {
  digitalWrite(Apin, LOW);
  digitalWrite(Bpin, LOW);
  digitalWrite(Cpin, LOW);
  digitalWrite(Dpin, LOW);
  digitalWrite(Epin, LOW);
  digitalWrite(Fpin, LOW);
  digitalWrite(Gpin, LOW);
  digitalWrite(Hpin, LOW);

  digitalWrite(led3, LOW);
}