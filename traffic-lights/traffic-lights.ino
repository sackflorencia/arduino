void setup() {
  pinMode(3, OUTPUT);    // verde
  pinMode(7, OUTPUT);    //amarillo
  pinMode(9, OUTPUT);    //rojo
}

void loop() {
  digitalWrite(3, HIGH); // sets the digital pin 13 on
  digitalWrite(7, LOW);  // sets the digital pin 13 off
  digitalWrite(9, LOW);
  delay(2000);         
  digitalWrite(7, HIGH); // sets the digital pin 13 on
  digitalWrite(3, LOW);  // sets the digital pin 13 off
  digitalWrite(9, LOW);
  delay(700); 
  digitalWrite(9, HIGH); // sets the digital pin 13 on
  digitalWrite(3, LOW);  // sets the digital pin 13 off
  digitalWrite(7, LOW);
  delay(2000); 
  digitalWrite(7, HIGH); // sets the digital pin 13 on
  digitalWrite(3, LOW);  // sets the digital pin 13 off
  digitalWrite(9, LOW);
  delay(700); 
}