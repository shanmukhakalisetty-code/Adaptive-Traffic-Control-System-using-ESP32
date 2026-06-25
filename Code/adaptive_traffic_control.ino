#define IR1 34
#define IR2 35

#define RED1 25
#define YELLOW1 26
#define GREEN1 27

#define RED2 14
#define YELLOW2 12
#define GREEN2 13

void setup() {
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  pinMode(RED1, OUTPUT);
  pinMode(YELLOW1, OUTPUT);
  pinMode(GREEN1, OUTPUT);

  pinMode(RED2, OUTPUT);
  pinMode(YELLOW2, OUTPUT);
  pinMode(GREEN2, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  int lane1 = digitalRead(IR1);
  int lane2 = digitalRead(IR2);

  if (lane1 == LOW) {
    digitalWrite(GREEN1, HIGH);
    digitalWrite(RED1, LOW);

    digitalWrite(RED2, HIGH);
    digitalWrite(GREEN2, LOW);

    delay(10000);
  }
  else if (lane2 == LOW) {
    digitalWrite(GREEN2, HIGH);
    digitalWrite(RED2, LOW);

    digitalWrite(RED1, HIGH);
    digitalWrite(GREEN1, LOW);

    delay(10000);
  }
  else {
    digitalWrite(GREEN1, HIGH);
    digitalWrite(RED2, HIGH);

    delay(5000);

    digitalWrite(GREEN1, LOW);
    digitalWrite(YELLOW1, HIGH);
    delay(2000);
    digitalWrite(YELLOW1, LOW);

    digitalWrite(GREEN2, HIGH);
    digitalWrite(RED2, LOW);
    digitalWrite(RED1, HIGH);

    delay(5000);

    digitalWrite(GREEN2, LOW);
    digitalWrite(YELLOW2, HIGH);
    delay(2000);
    digitalWrite(YELLOW2, LOW);
  }
}
