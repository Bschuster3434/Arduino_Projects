// Binary to Base 10 Number Converter
// by Brian Schuster
// 11/27/14

#define N_DATA 5
#define N_LATCH 7
#define N_CLOCK 9
#define B_7 13
#define B_6 12
#define B_5 11
#define B_4 10
#define B_3 8
#define B_2 6
#define B_1 4
#define B_0 2
#define HEX_BIT 3

//Defining varables
int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142}; //LED Digital Display 0-F
int bin_0 = 0;
int bin_1 = 0;
int bin_2 = 0;
int bin_3 = 0;
int bin_4 = 0;
int bin_5 = 0;
int bin_6 = 0;
int bin_7 = 0;
int hex = 0;


void setup(){
  pinMode(N_DATA, OUTPUT);
  pinMode(N_LATCH, OUTPUT);
  pinMode(N_CLOCK, OUTPUT);
  pinMode(B_7, INPUT);
  pinMode(B_6, INPUT);
  pinMode(B_5, INPUT);
  pinMode(B_4, INPUT);
  pinMode(B_3, INPUT);
  pinMode(B_2, INPUT);
  pinMode(B_1, INPUT);
  pinMode(B_0, INPUT);
  pinMode(HEX_BIT, INPUT);
}

void displayNumber(int n, int hex_b) {
 //Controls the three number display as well as the binary output
 
 //If hex == 0, use base 10. Else, use base 16
 int base;
 if (hex_b == 0){
  base = 10;  
 }
 else {
  base = 16; 
 }
 
 
 if ( n < base ) {
  digitalWrite(N_LATCH, LOW);
  shiftOut(N_DATA, N_CLOCK, LSBFIRST, n);
  shiftOut(N_DATA, N_CLOCK, LSBFIRST, digits[n] + hex); //Adding Hex Digit to Add Decimal if the Number is hex
  shiftOut(N_DATA, N_CLOCK, LSBFIRST, 0);
  shiftOut(N_DATA, N_CLOCK, LSBFIRST, 0);
  digitalWrite(N_LATCH, HIGH);
 }
 
 else if ( n  < (base * base)) {
  int digit_0 = n % base;
  int digit_1 = n / base;
  digitalWrite(N_LATCH, LOW);
  shiftOut(N_DATA, N_CLOCK, LSBFIRST, n);
  shiftOut(N_DATA, N_CLOCK, LSBFIRST, digits[digit_0] + hex);
  shiftOut(N_DATA, N_CLOCK, LSBFIRST, digits[digit_1]);
  shiftOut(N_DATA, N_CLOCK, LSBFIRST, 0);
  digitalWrite(N_LATCH, HIGH); 
   
 }
 //We won't get to this unless the base is 10, so there is no need to change the nomenclature
 //Laziness shall prevail here
 else {
  int digit_ones = n % 10;
  int digit_tens = (n % 100) / 10;
  int digit_hundreds = n / 100;
  digitalWrite(N_LATCH, LOW);
  shiftOut(N_DATA, N_CLOCK, LSBFIRST, n);
  shiftOut(N_DATA, N_CLOCK, LSBFIRST, digits[digit_ones]);
  shiftOut(N_DATA, N_CLOCK, LSBFIRST, digits[digit_tens]);
  shiftOut(N_DATA, N_CLOCK, LSBFIRST, digits[digit_hundreds]);
  digitalWrite(N_LATCH, HIGH);   
 }

}

int change_binary(int pin, int bin) {
  if (digitalRead(pin) == HIGH) {
   bin = (bin + 1) % 2;
  }
  return bin;
 }

void loop() {
 int display_number = 
   bin_0 * 1
 + bin_1 * 2
 + bin_2 * 4
 + bin_3 * 8
 + bin_4 * 16
 + bin_5 * 32
 + bin_6 * 64
 + bin_7 * 128;

 displayNumber(display_number, hex);
 
 //Holds the Loop Here until a button is pressed
 while(digitalRead(B_0) == LOW && digitalRead(B_1) == LOW 
    && digitalRead(B_2) == LOW && digitalRead(B_3) == LOW 
    && digitalRead(B_4) == LOW && digitalRead(B_5) == LOW
    && digitalRead(B_6) == LOW && digitalRead(B_7) == LOW
    && digitalRead(HEX_BIT) == LOW){
     //Nothing happens here.
    }

  bin_0 = change_binary(B_0, bin_0);
  bin_1 = change_binary(B_1, bin_1);
  bin_2 = change_binary(B_2, bin_2);
  bin_3 = change_binary(B_3, bin_3); 
  bin_4 = change_binary(B_4, bin_4);
  bin_5 = change_binary(B_5, bin_5);
  bin_6 = change_binary(B_6, bin_6);
  bin_7 = change_binary(B_7, bin_7);  
  hex = change_binary(HEX_BIT, hex);
  
 //Does not Complete the loop until the button is released
 while(digitalRead(B_0) == HIGH || digitalRead(B_1) == HIGH
    || digitalRead(B_2) == HIGH || digitalRead(B_3) == HIGH
    || digitalRead(B_4) == HIGH || digitalRead(B_5) == HIGH
    || digitalRead(B_6) == HIGH || digitalRead(B_7) == HIGH
    || digitalRead(HEX_BIT) == HIGH) {
      //Nothing happens here either.
    }
 }

