/*
Blinking LED
Created by Brian Schuster
11/10/14
*/

void setup()
{
 pinMode(13, OUTPUT); //Setting pin 13 to 'output' mode 
}
void loop()
{
 digitalWrite(13, HIGH);
 delay(1000);
 digitalWrite(13, LOW);
 delay(1000); 
}
