int red = 13;
int yellow = 12;
int green = 11;
int button = 2; // button pin

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, OUTPUT);
}

void loop() {
  changeLights();

  int state = digitalRead(button);
  if (state == HIGH) {
    digitalWrite(red, HIGH);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, HIGH);
  }
  delay(2000);
}

void changeLights() {
  // green off, yellow for 3 seconds
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(4000);

  // green off, yellow for 3 seconds
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
  delay(2000);

  digitalWrite(yellow, HIGH);
  delay(2000);

  // red and yellow on for 2 seconds (red is already on though)
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);

}
