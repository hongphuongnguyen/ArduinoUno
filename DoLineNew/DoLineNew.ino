byte SpMaxL = 255;
byte SpMaxR = 255;

#define enA  3
#define enB  5
#define in1  9
#define in2  10
#define in3  11
#define in4  12

#define out1  A4
#define out2  A3
#define out3  A2
#define out4  A1
#define out5  A0

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);     
  pinMode(in2, OUTPUT);          
  pinMode(in3, OUTPUT);     
  pinMode(in4, OUTPUT);        
  pinMode(out1, INPUT);    
  pinMode(out2, INPUT);        
  pinMode(out3, INPUT);      
  pinMode(out4, INPUT);         
  pinMode(out5, INPUT);           
}

void loop() {
  doline();
  //delay(2000);
  //Serial.println (trangThai5CamBien ());
}

void doline(){
  switch (trangThai5CamBien()){
    case 200:
      Lui(100,100);
      break;
    case 0:
      Tien(SpMaxL-20,SpMaxR);
      break;
    case 1:
      Tien(SpMaxL,200);
      break;
    case 2:
      Tien(SpMaxL,100);
      break;
    case 3:
      Tien(SpMaxL,0);
      break;
    case -1:
      Tien(200,SpMaxR);
      break;
    case -2:
      Tien(100,SpMaxR);
      break;
    case -3:
      Tien(0,SpMaxR);
      break;
    default:
      digitalWrite(in1, 0);
      digitalWrite(in2, 0);
      digitalWrite(in3, 0);
      digitalWrite(in4, 0);
      break;
  }
}

boolean IFSensor (byte PinNumb){
  // Có line là 1
  return (!digitalRead (PinNumb));
}

int trangThai5CamBien (){
  /*
      Âm là lệch phải
      Dương là lệch trái
      Mức độ lệch giảm tăng dần : 1 2 3
  */
  int sens1 = IFSensor(out1);
  int sens2 = IFSensor(out2);
  int sens3 = IFSensor(out3);
  int sens4 = IFSensor(out4);
  int sens5 = IFSensor(out5);
  switch (lechvach5mat()){
    case -3:
      return -3;
      break;
    case -2:
      return -2;
      break;
    case -1:
      return -1;
      break;
    case 0:
      if ( (abs(sens1) + abs(sens2) + abs(sens3) + abs(sens4) + abs(sens5)) == 0)
        return 200;
      else
        return 0;
      break;
    case 1:
      return 1;
      break;
    case 2:
      return 2;
      break;
    case 3:
      return 3;
      break;
  }
}

int lechvach5mat(){
  /*
      Âm là lệch phải
      Dương là lệch trái
      Mức độ lệch giảm tăng dần : 1 3 2
  */
  int sens1 = IFSensor(out1);
  int sens2 = IFSensor(out2);
  int sens3 = IFSensor(out3);
  int sens4 = IFSensor(out4);
  int sens5 = IFSensor(out5);
  int lechvach = -2 * sens1 - sens2 + sens4 + 2 * sens5;
  switch (lechvach){
    case -3:// cái này là do 2 mắt biên đều chạm vạch
      return -2;
      break;
    case -2:
      return -3;
      break;
    case -1:
      return -1;
      break;
    case 0:
      return 0;
      break;
    case 1:
      return 1;
      break;
    case 2:
      return 3;
      break;
    case 3:
      return 2;
      break;
  }
}

void Tien( byte speedL, byte speedR){
  analogWrite(enA, speedL);
  analogWrite(enB, speedR);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void Retrai(){
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void Rephai(){
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}

void Lui(byte SpeedL, byte SpeedR){
  analogWrite(enA, SpeedL);
  analogWrite(enB, SpeedR);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

