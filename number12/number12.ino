#define PLAYER_COUNT 2

int buttonPins[PLAYER_COUNT] = {3, 13};
int ledPins[PLAYER_COUNT] = {9, 11};

void setup() {
  for (int player = 0; player < PLAYER_COUNT; ++player) {
    pinMode(ledPins[player], OUTPUT);
    pinMode(buttonPins[player], INPUT_PULLUP);
    pinMode(7, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(2, OUTPUT);
  }
}

void loop() {
  delay(random(2000, 7000));
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
    digitalWrite(4, HIGH);
      digitalWrite(2, HIGH);
  delay(600);
  digitalWrite(5, LOW);
  for (int player = 0; ; player = (player + 1) % PLAYER_COUNT) {
    if (!digitalRead(buttonPins[player])) {
      digitalWrite(ledPins[player], 1);
      delay(1000);
      digitalWrite(ledPins[player], LOW);
      break;
    }
  }
}
