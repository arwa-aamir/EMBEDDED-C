void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT_PULLUP);
  pinMode(3,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  bool i=digitalRead(2);
  if (i==LOW)
  {
    digitalWrite(3,HIGH);
  }
  else
  {
     digitalWrite(3,LOW);
  }

}
