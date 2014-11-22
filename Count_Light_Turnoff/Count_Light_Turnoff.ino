// Project 5 - Counting Darkness
// by Brian Schuster
// 11/19/14
// Goal of this project is to count how many times we shut off the lights in the basement
// Utilizing two LED displays and a photosensor

//Defining Pin Variables
#define DATA 6
#define LATCH 8
#define CLOCK 10
#define PHOTOCELL 0

//Defining Digits
int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};
int pcReading;
int firstRun = 1;
int lightOnLevel = 125;
int lightOffLevel = 100;
int lightOn;
int lightCount = 0;

void setup(){
 pinMode(LATCH, OUTPUT);
 pinMode(CLOCK, OUTPUT);
 pinMode(DATA, OUTPUT);
 pinMode(PHOTOCELL, INPUT);
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



void loop(){
 pcReading = analogRead(PHOTOCELL);
 
 //Checking the light levels when the program first runs
 //If lights are on during startup, lightOn = 1
 //Else lightOn =0
 //After that, the firstRun Flag is turned off
 if (firstRun == 1){
  if (pcReading > lightOnLevel){
   lightOn = 1;
  }
  else {
   lightOn = 0;
  }
  firstRun = 0;
 }
 
 //Increment Logic
 //If the lightOn reading is 1 and the pcReading is below the LightOffLevel
 //  Increment the lightCount and turn lightOn to 0 
 //  (The Lights are Off, That Counts as One)
 //If the lightOn reading is 0 and the pcReading is above the LightOnLevel
 //  Turn lightOn to 1
 //  (The Lights are back On, we need to be ready for them to turn off)
 
 if (lightOn == 1 && pcReading < lightOffLevel){
   lightCount += 1;
   lightOn = 0;
 }
 else if (lightOn == 0 && pcReading > lightOnLevel){
   lightOn =1;
 }
 
 displayNumber(lightCount);
 delay(100);
 
}
