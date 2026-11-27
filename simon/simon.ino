#define PIN_BTN_R 2
#define PIN_BTN_G 3
#define PIN_BTN_Y 4
#define PIN_BTN_P 5
#define PIN_LED_R 11
#define PIN_LED_G 10
#define PIN_LED_B 9
#define PIN_BUZZ 12

unsigned long bounceTime = 50;

typedef struct Color {
  int red = 0;
  int blue = 0;
  int green = 0;
};

typedef struct Button {
  int pin;
  int state;
  int last;
  unsigned long timer;
  void (*onPress)();
};

void printColor(Color color){
  analogWrite(PIN_LED_R, color.red);
  analogWrite(PIN_LED_G, color.green);
  analogWrite(PIN_LED_B, color.blue);
}
void readButton(Button &button){
  if ( button.state==digitalRead(button.pin) ) {
    button.timer = 0;
  } else if (button.timer == 0){
      button.timer = millis();
  } else if (millis()-button.timer > bounceTime){
    button.state = !button.state;
  }
  if ( button.last==HIGH && button.state==LOW ) {
    button.onPress();
  }
  button.last = button.state;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  pinMode(PIN_BUZZ, OUTPUT);
  pinMode(PIN_BTN_R, INPUT_PULLUP);
  pinMode(PIN_BTN_G, INPUT_PULLUP);
  pinMode(PIN_BTN_Y, INPUT_PULLUP);
  pinMode(PIN_BTN_P, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  //colors
  Color red;
  red.red = 255;
  Color yellow;
  yellow.red =255;
  yellow.green = 255;
  Color green;
  green.green = 255;
  Color purple;
  purple.red = 128;
  purple.blue = 128;
  
  //inicializar botones
}
