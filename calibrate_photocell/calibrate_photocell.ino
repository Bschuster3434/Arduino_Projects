/* Photocell Calibration for Basement
   by Brian Schuster
   11/21/14
*/

int photocellPin = 0;
int photocellReading;
int LEDpin = 11;
int LEDbrightness;

void setup(void) {
 Serial.begin(9600);
}

void loop(void){
 photocellReading = analogRead(photocellPin);

 Serial.print("Analog reading = ");
 Serial.println(photocellReading);

 photocellReading = 1023;
 LEDbrightness = map(photocellReading, 0, 1023, 0, 255);
 analogWrite(LEDpin, LEDbrightness);

 delay(100);

}


