#define PIN_BTN A0
#define PIN_LED A1
int last;
int state;
unsigned long timer;
unsigned long bounceTime = 50;
int stateLed;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_BTN, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  state = HIGH;
  last = HIGH;
  stateLed = HIGH;
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( state==digitalRead(PIN_BTN) ) {
    timer = 0;
  } else if (timer == 0){
      timer = millis();
  } else if (millis()-timer > bounceTime){
    state = !state;
  }
  if ( last==HIGH && state==LOW ) {
    switch (stateLed){
      case HIGH:
        stateLed = LOW;
        digitalWrite(PIN_LED, LOW);
        break;
      case LOW:
        stateLed = HIGH;
        digitalWrite(PIN_LED, HIGH);
        break;
    }
  }
  last = state;
}
