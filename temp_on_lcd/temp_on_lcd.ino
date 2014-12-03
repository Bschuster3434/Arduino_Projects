#include <DHT.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

//I2C Address from Arduino
#define I2C_ADDR    0x22 

//I2C Pins Setup for LED
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

//Arduino Pin Setup
#define temp A0 //TMP36 Pin
#define DHTPIN A1 //DHT11 Pin
#define DHTTYPE DHT11 //Type of DHT being defined

LiquidCrystal_I2C	lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
DHT dht(DHTPIN, DHTTYPE);

//Variables needed for TMP36 calculation
float sensor;
float voltage;
float f_temp;

void setup()
{
 lcd.begin (16,2); // Setting up 16,2 lcd screen
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE); 
lcd.setBacklight(HIGH); //Turning On Backlight
lcd.home (); 

 lcd.print("TMP36 | DHT11"); //Prints the top line of the arduino  
 dht.begin();
}

float tmp36Read(int n){ //Will read the temperature n times and return the average of those readings
 float totalReadings = 0;
 for (int i = 0; i < n; i ++) {
  sensor = analogRead(temp);
  voltage = (sensor*5000)/1024;
  voltage = voltage - 500;
  f_temp = voltage/10 * 1.8 + 32;
  totalReadings = totalReadings + f_temp;
 } 
 
 float finalReading = totalReadings / n;
 
 return finalReading;
 
}

void loop()
{
 float tmp_temp = tmp36Read(1000); //Get the reading from TMP36 n times
 float dht_temp = dht.readTemperature(true); //Return the temperature in Fahrenheit for the DHT11
 
 lcd.setCursor(0,1); //Put the cursor at the first space in row 1 (2nd row)
 lcd.print(tmp_temp); 
 lcd.setCursor(6,1);
 lcd.print("|");
 
 lcd.setCursor(8,1);
 lcd.print(dht_temp);
 
 delay(3000); //Delay by 3 seconds before looping
 
}
