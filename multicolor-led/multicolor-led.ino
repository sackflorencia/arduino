#define PIN_B 9
#define PIN_G 10
#define PIN_R 11

void setColor(int r, int g, int b) {
  analogWrite(PIN_R, r);
  analogWrite(PIN_G, g);
  analogWrite(PIN_B,  b);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_R, OUTPUT);
}

void loop() {
  setColor(255,   0,   0); delay(1000); // Red
  setColor(  0, 255,   0); delay(1000); // Green
  setColor(  0,   0, 255); delay(1000); // Blue
  setColor(255, 255,   0); delay(1000); // Yellow
  setColor(  0, 255, 255); delay(1000); // Cyan
  setColor(255,   0, 255); delay(1000); // Magenta
  setColor(200, 255, 255); delay(1000); // White (red reduced to balance)
  setColor(  0,   0,   0); delay(1000); // Off
}
