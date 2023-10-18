int congtac = 2;
int led = 3;
int trangthailed = 0;
void setup()
{
  pinMode(congtac, INPUT);
  pinMode(led,OUTPUT);
  digitalWrite(led, LOW);
}

void loop()
{
  int trangthaicongtac = digitalRead(congtac);
  int ledsang = digitalRead(led);
  if(trangthaicongtac == 1 && trangthailed == ledsang)
  {
    digitalWrite(led, !trangthailed);
    trangthailed = !trangthailed;
    delay(500);
  }
}
