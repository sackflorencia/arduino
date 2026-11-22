#define PIN_BTN A0
#define PIN_BUZZ A1
#define PIN_LED A2
//4x7 segments
#define PIN_A 3
#define PIN_B 7
#define PIN_C 11
#define PIN_D 9
#define PIN_E 8
#define PIN_F 4
#define PIN_G 12
#define PIN_DP 10
#define PIN_D1 13
#define PIN_D2 6
#define PIN_D3 5
#define PIN_D4 2

#define REFRESH_RATE 2

//button
int last;
int state;
unsigned long timer;
unsigned long bounceTime = 50;

long time;  //led time
unsigned long reactionStart;
int phase;


void printDigit(int num, int digit) {
  switch (digit) {
    case 1:
      digitalWrite(PIN_D1, LOW);
      digitalWrite(PIN_D2, HIGH);
      digitalWrite(PIN_D3, HIGH);
      digitalWrite(PIN_D4, HIGH);
      digitalWrite(PIN_DP, LOW);
      break;
    case 2:
      digitalWrite(PIN_D1, HIGH);
      digitalWrite(PIN_D2, LOW);
      digitalWrite(PIN_D3, HIGH);
      digitalWrite(PIN_D4, HIGH);
      digitalWrite(PIN_DP, LOW);
      break;
    case 3:
      digitalWrite(PIN_D1, HIGH);
      digitalWrite(PIN_D2, HIGH);
      digitalWrite(PIN_D3, LOW);
      digitalWrite(PIN_D4, HIGH);
      digitalWrite(PIN_DP, LOW);
      break;
    case 4:
      digitalWrite(PIN_D1, HIGH);
      digitalWrite(PIN_D2, HIGH);
      digitalWrite(PIN_D3, HIGH);
      digitalWrite(PIN_D4, LOW);
      digitalWrite(PIN_DP, HIGH);
      break;
  }


  switch (num) {
    case 0:
      digitalWrite(PIN_G, LOW);
      digitalWrite(PIN_F, HIGH);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, HIGH);
      digitalWrite(PIN_D, HIGH);
      digitalWrite(PIN_C, HIGH);
      break;
    case 1:
      digitalWrite(PIN_G, LOW);
      digitalWrite(PIN_F, LOW);
      digitalWrite(PIN_A, LOW);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, LOW);
      digitalWrite(PIN_D, LOW);
      digitalWrite(PIN_C, HIGH);
      break;
    case 2:
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, LOW);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, HIGH);
      digitalWrite(PIN_D, HIGH);
      digitalWrite(PIN_C, LOW);
      break;
    case 3:
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, LOW);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, LOW);
      digitalWrite(PIN_D, HIGH);
      digitalWrite(PIN_C, HIGH);
      break;
    case 4:
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, HIGH);
      digitalWrite(PIN_A, LOW);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, LOW);
      digitalWrite(PIN_D, LOW);
      digitalWrite(PIN_C, HIGH);
      break;
    case 5:
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, HIGH);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, LOW);
      digitalWrite(PIN_E, LOW);
      digitalWrite(PIN_D, HIGH);
      digitalWrite(PIN_C, HIGH);
      break;
    case 6:
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, HIGH);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, LOW);
      digitalWrite(PIN_E, HIGH);
      digitalWrite(PIN_D, HIGH);
      digitalWrite(PIN_C, HIGH);
      break;
    case 7:
      digitalWrite(PIN_G, LOW);
      digitalWrite(PIN_F, LOW);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, LOW);
      digitalWrite(PIN_D, LOW);
      digitalWrite(PIN_C, HIGH);
      break;
    case 8:
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, HIGH);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, HIGH);
      digitalWrite(PIN_D, HIGH);
      digitalWrite(PIN_C, HIGH);
      break;
    case 9:
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, HIGH);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, LOW);
      digitalWrite(PIN_D, LOW);
      digitalWrite(PIN_C, HIGH);
      break;
  }
}

void startCountdown() {
  printDigit(3, 1);
  digitalWrite(PIN_BUZZ, HIGH);
  digitalWrite(PIN_LED, HIGH);
  delay(500);
  digitalWrite(PIN_BUZZ, LOW);
  digitalWrite(PIN_LED, LOW);
  delay(500);
  printDigit(2, 1);
  digitalWrite(PIN_BUZZ, HIGH);
  digitalWrite(PIN_LED, HIGH);
  delay(500);
  digitalWrite(PIN_BUZZ, LOW);
  digitalWrite(PIN_LED, LOW);
  delay(500);
  printDigit(1, 1);
  digitalWrite(PIN_BUZZ, HIGH);
  digitalWrite(PIN_LED, HIGH);
  delay(500);
  digitalWrite(PIN_BUZZ, LOW);
  digitalWrite(PIN_LED, LOW);
  delay(500);
}
void turnOff4x7Segments() {
  digitalWrite(PIN_D1, HIGH);
  digitalWrite(PIN_D2, HIGH);
  digitalWrite(PIN_D3, HIGH);
  digitalWrite(PIN_D4, HIGH);
  digitalWrite(PIN_DP, LOW);
  digitalWrite(PIN_G, LOW);
  digitalWrite(PIN_F, LOW);
  digitalWrite(PIN_A, LOW);
  digitalWrite(PIN_B, LOW);
  digitalWrite(PIN_E, LOW);
  digitalWrite(PIN_D, LOW);
  digitalWrite(PIN_C, LOW);
}

void printNumber(int num) {
  int d1 = num / 1000;
  int d2 = (num / 100) % 10;
  int d3 = (num / 10) % 10;
  int d4 = num % 10;

  for (int i = 0; i < REFRESH_RATE; i++) {
    printDigit(d1, 4);
    delay(1);
    printDigit(d2, 3);
    delay(1);
    printDigit(d3, 2);
    delay(1);
    printDigit(d4, 1);
    delay(2);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUZZ, OUTPUT);
  pinMode(PIN_BTN, INPUT_PULLUP);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_DP, OUTPUT);
  pinMode(PIN_D1, OUTPUT);
  pinMode(PIN_D2, OUTPUT);
  pinMode(PIN_D3, OUTPUT);
  pinMode(PIN_D4, OUTPUT);

  //boton
  state = HIGH;
  last = HIGH;

  randomSeed(analogRead(0));  //led
  phase = 1;
}


void loop() {
  if (phase == 1) {
    if (digitalRead(PIN_BTN)) {
      timer = 0;
    } else if (timer == 0) {
      timer = millis();
    } else if (millis() - timer > bounceTime) {
      state = !state;
    }
    if (last == HIGH && state == LOW) {
      startCountdown();
      turnOff4x7Segments();
      time = random(500, 10000);
      digitalWrite(PIN_LED, HIGH);
      delay(time);
      digitalWrite(PIN_LED, LOW);
      reactionStart = millis();
      phase = 2;
    }
    last = state;
  } else if (phase == 2) {
    for (int i = 0; i < 10000; i++) {
      printNumber(i);
      if (digitalRead(PIN_BTN)) {
        timer = 0;
      } else if (timer == 0) {
        timer = millis();
      } else if (millis() - timer > bounceTime) {
        state = !state;
      }
      if (last == LOW && state == HIGH) {
        unsigned long reactionTime = millis() - reactionStart;
        for (int i = 0; i <= 400; i++) {
          printNumber(reactionTime);
        }
        turnOff4x7Segments();
        phase = 1;
        break;
      }
      last = state;
    }
  }
}
