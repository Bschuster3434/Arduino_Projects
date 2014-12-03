#include <DHT.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x22 
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
#define temp A0
#define DHTPIN A1
#define DHTTYPE DHT11 

LiquidCrystal_I2C	lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
DHT dht(DHTPIN, DHTTYPE);

float sensor;
float voltage;
float f_temp;

void setup()
{
 lcd.begin (16,2); //  <<----- My LCD was 16x2
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home (); // go home

 lcd.print("TMP36 | DHT11");  
 dht.begin();
}

float tmp36Read(int n){
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
 float tmp_temp = tmp36Read(1000);
 float dht_temp = dht.readTemperature(true);
 
 lcd.setCursor(0,1);
 lcd.print(tmp_temp); 
 lcd.setCursor(6,1);
 lcd.print("|");
 
 lcd.setCursor(8,1);
 lcd.print(dht_temp);
 
 delay(3000);
 
}
