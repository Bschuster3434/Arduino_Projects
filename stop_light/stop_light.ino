// Creating a Stop Light Program
// by Jim Mickelson and Brian Schuster
// 11/26/14

#define westButton 3
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastButton 13
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define blinkTime 500

boolean trafficWest = true;
int flowTime = 10000;
int changeDelay = 2000;

void setup() {
 pinMode(westButton, INPUT);
 pinMode(westRed, OUTPUT);
 pinMode(westYellow, OUTPUT);
 pinMode(westGreen, OUTPUT);
 pinMode(eastButton, INPUT);
 pinMode(eastRed, OUTPUT);
 pinMode(eastYellow, OUTPUT);
 pinMode(eastGreen, OUTPUT);
 
 digitalWrite(westRed, LOW);
 digitalWrite(westYellow, LOW);
 digitalWrite(westGreen, HIGH);
 digitalWrite(eastRed, HIGH);
 digitalWrite(eastYellow, LOW);
 digitalWrite(eastGreen, LOW);
} 

void loop() {
 if (digitalRead(westButton) == HIGH) {
  if (trafficWest != true) {
   //East Flow Traffic
   trafficWest = true;
   delay(flowTime);
   digitalWrite(eastGreen, LOW);
   digitalWrite(eastYellow, HIGH);
   delay(changeDelay);
   digitalWrite(eastYellow, LOW);
   digitalWrite(eastRed, HIGH);
   delay(changeDelay);
  for (int a = 0; a < 5; a++) {
   digitalWrite(westYellow, LOW);
   delay(blinkTime);
   digitalWrite(westYellow, HIGH);
   delay(blinkTime);
  }
  digitalWrite(westYellow, LOW);
  digitalWrite(westRed, LOW);
  digitalWrite(westGreen, HIGH);
 }
 }
 
  if (digitalRead(eastButton) == HIGH) {
   if (trafficWest == true) {
    //East Flow Traffic
    trafficWest = false;
    delay(flowTime);
    digitalWrite(westGreen, LOW);
    digitalWrite(westYellow, HIGH);
    delay(changeDelay);
    digitalWrite(westYellow, LOW);
    digitalWrite(westRed, HIGH);
    delay(changeDelay);

  for (int a = 0; a < 5; a++) {
   digitalWrite(eastYellow, LOW);
   delay(blinkTime);
   digitalWrite(eastYellow, HIGH);
   delay(blinkTime);
  }
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastRed, LOW);
  digitalWrite(eastGreen, HIGH);
}}}  

