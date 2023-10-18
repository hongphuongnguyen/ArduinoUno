int congtac = 2;
int led = 3;
void setup()
{
  pinMode(congtac, INPUT_PULLUP); // khi khong nhan thi treo len 1
  pinMode(led,OUTPUT);
}

void loop()
{
  int trangthai = digitalRead(congtac);
  if(trangthai == 1)
  {
    digitalWrite(led, 0);
  }
  else
    digitalWrite(led, 1);
}
