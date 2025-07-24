void setup() {
  pinMode(12,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  digitalWrite(12,HIGH);
  delay(1000);
  digitalWrite(12,LOW);
  delay(1000);
  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(5,LOW);
  delay(1000);
}
