int led_green = 13;
int led_yellow = 12;
int led_red = 11;


void setup() {
 pinMode(led_green, OUTPUT);
 pinMode(led_yellow, OUTPUT);
 pinMode(led_red,  OUTPUT); 
}

void loop() {
  digitalWrite(led_green, HIGH);
  delay(100);
  digitalWrite(led_green, LOW);
  delay(100);
  {digitalWrite(led_yellow, HIGH);
  delay(100);
  digitalWrite(led_yellow, LOW);
  delay(100);}
  {digitalWrite(led_red, HIGH);
  delay(100);
  digitalWrite(led_red, LOW);
  delay(100);}
}
