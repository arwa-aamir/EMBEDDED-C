void setup()
{
  Serial.begin(9600); 
pinMode(6, OUTPUT);
pinMode(A0, INPUT);
attachInterrupt(3, angle,CHANGE);
}

void loop(){}
void angle(){
  int val_1=analogRead(A0);
  int speed_1=map(val_1,0,1023,0,20000);
  int del_1=20000-val_1;
  int del_2=del_1/2;

  digitalWrite(6,LOW);
  delayMicroseconds(del_2);
  digitalWrite(6,HIGH);
  delayMicroseconds(speed_1);
  digitalWrite(6,LOW);
  delayMicroseconds(del_2);
}
