#define PIN A0
int last;
int state;
unsigned long timer;
unsigned long bounceTime = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN, INPUT_PULLUP);
  state = HIGH;
  last = HIGH;
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( state==digitalRead(PIN) ) {
    timer = 0;
  } else if (timer == 0){
      timer = millis();
  } else if (millis()-timer > bounceTime){
    state = !state;
  }
  if ( last==HIGH && state==LOW ) Serial.print("button pressed");
  last = state;
}
