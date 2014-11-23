// Project 7 - Piezo Buzzer Experiment
// by Brian Schuster
// 11/22/14

#define PIEZO 3

int del = 500;

void setup(){
 pinMode(PIEZO, OUTPUT);
}

void loop(){  
 analogWrite(PIEZO, 0);
 delay(del);
 digitalWrite(PIEZO, LOW);
 delay(del);
}

