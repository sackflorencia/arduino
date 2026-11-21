#define PIN_A 4
#define PIN_B 5
#define PIN_C 8
#define PIN_D 7
#define PIN_E 6
#define PIN_F 3
#define PIN_G 2
#define PIN_DP 9

void printNumber(int num){
  switch (num){
    case 0:
      digitalWrite(PIN_G, LOW);
      digitalWrite(PIN_F, HIGH);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, HIGH);
      digitalWrite(PIN_D, HIGH);
      digitalWrite(PIN_C, HIGH);
      digitalWrite(PIN_DP, LOW);
      break;
    case 1:
      digitalWrite(PIN_G, LOW);
      digitalWrite(PIN_F, LOW);
      digitalWrite(PIN_A, LOW);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, LOW);
      digitalWrite(PIN_D, LOW);
      digitalWrite(PIN_C, HIGH);
      digitalWrite(PIN_DP, LOW);
      break;
    case 2:
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, LOW);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, HIGH);
      digitalWrite(PIN_D, HIGH);
      digitalWrite(PIN_C, LOW);
      digitalWrite(PIN_DP, LOW);
      break;
    case 3:
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, LOW);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, LOW);
      digitalWrite(PIN_D, HIGH);
      digitalWrite(PIN_C, HIGH);
      digitalWrite(PIN_DP, LOW);
      break;
    case 4:
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, HIGH);
      digitalWrite(PIN_A, LOW);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, LOW);
      digitalWrite(PIN_D, LOW);
      digitalWrite(PIN_C, HIGH);
      digitalWrite(PIN_DP, LOW);
      break;
    case 5:
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, HIGH);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, LOW);
      digitalWrite(PIN_E, LOW);
      digitalWrite(PIN_D, HIGH);
      digitalWrite(PIN_C, HIGH);
      digitalWrite(PIN_DP, LOW);
      break;
    case 6: 
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, HIGH);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, LOW);
      digitalWrite(PIN_E, HIGH);
      digitalWrite(PIN_D, HIGH);
      digitalWrite(PIN_C, HIGH);
      digitalWrite(PIN_DP, LOW);
      break;
    case 7:
      digitalWrite(PIN_G, LOW);
      digitalWrite(PIN_F, LOW);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, LOW);
      digitalWrite(PIN_D, LOW);
      digitalWrite(PIN_C, HIGH);
      digitalWrite(PIN_DP, LOW);
      break;
    case 8:
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, HIGH);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, HIGH);
      digitalWrite(PIN_D, HIGH);
      digitalWrite(PIN_C, HIGH);
      digitalWrite(PIN_DP, LOW);
      break;
    case 9:
      digitalWrite(PIN_G, HIGH);
      digitalWrite(PIN_F, HIGH);
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_E, LOW);
      digitalWrite(PIN_D, LOW);
      digitalWrite(PIN_C, HIGH);
      digitalWrite(PIN_DP, LOW);
      break;
  }
}

void setup() {
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_DP, OUTPUT);
}

void loop() {
  for(int i = 0; i < 10; i++){
    printNumber(i);
    delay(1000);
  }
}
