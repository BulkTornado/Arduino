const uint8_t redPin = 4;
const uint8_t yellowPin = 5;
const uint8_t greenPin = 6;

const uint16_t redDelayMs = 5000;
const uint16_t yellowDelayMs = 1000;
const uint16_t greenDelayMs = 2500;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Red signal
  digitalWrite(redPin, HIGH);
  delay(redDelayMs);
  digitalWrite(redPin, LOW);

  // Green signal
  digitalWrite(greenPin, HIGH);
  delay(greenDelayMs);
  digitalWrite(greenPin, LOW);

  // Yellow signal
  digitalWrite(yellowPin, HIGH);
  delay(yellowDelayMs);
  digitalWrite(yellowPin, LOW);
}
