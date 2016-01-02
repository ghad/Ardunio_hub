int red = 13;
int yellow = 12;
int green = 11;
int button = 2; // button pin

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  //changeLights();

  int state = digitalRead(button);
  if (state == HIGH) {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
  }
  delay(10);
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
}


