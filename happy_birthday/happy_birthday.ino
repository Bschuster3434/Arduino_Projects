// Project 4 - Birthday Sketch for Laura
// by Brian Schuster
// 11/19/14

#define DATA 6
#define LATCH 8
#define CLOCK 10
#define BUTTON 2

int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};

void setup(){
 pinMode(LATCH, OUTPUT);
 pinMode(CLOCK, OUTPUT);
 pinMode(DATA, OUTPUT);
 pinMode(BUTTON, INPUT);
}

void displayNumber(int n) {
 int left, right = 0;
 if (n< 10) {
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, digits[n]);
  shiftOut(DATA, CLOCK, LSBFIRST, 0);
  digitalWrite(LATCH, HIGH);
 }
 else if (n >= 10){
 right = n % 10;
 left = n / 10;
 digitalWrite(LATCH, LOW);
 shiftOut(DATA, CLOCK, LSBFIRST, digits[right]);
 shiftOut(DATA, CLOCK, LSBFIRST, digits[left]);
 digitalWrite(LATCH, HIGH);
 }
}

int flag = 0;
int next = 26;

void loop(){
 int i;
 if ( digitalRead(BUTTON) == HIGH){
   flag = 1;}
 for (i = next + flag ; i <= next + flag; i++){
  displayNumber(i);
  delay(50);
 }
}


