#define IrLeft 13
#define IrMid 12
#define IrRight 2
#define MRF 3
#define MRB 9
#define MLF 10
#define MLB 11
#define pwm 150
void setup() {
  pinMode(IrLeft,INPUT);
  pinMode(IrMid,INPUT);
  pinMode(IrRight,INPUT);
  pinMode(MRF,OUTPUT);
  pinMode(MRB,OUTPUT);
  pinMode(MLF,OUTPUT);
  pinMode(MLB,OUTPUT);
  Serial.begin(9600);
}

void Forward()  {
  analogWrite(MRF,pwm);
  digitalWrite(MRB,LOW);
  analogWrite(MLF,pwm);
  digitalWrite(MLB,LOW);
}
void Right()  {
  digitalWrite(MRF,LOW);
  analogWrite(MRB,pwm);
  analogWrite(MLF,pwm);
  digitalWrite(MLB,LOW);
}
void SharpRight()  {
  digitalWrite(MRF,LOW);
  digitalWrite(MRB,LOW);
  analogWrite(MLF,pwm);
  digitalWrite(MLB,LOW);
}
void Left()  {
  analogWrite(MRF,pwm);
  digitalWrite(MRB,LOW);
  digitalWrite(MLF,LOW);
  analogWrite(MLB,pwm);
}
void SharpLeft()  {
  analogWrite(MRF,pwm);
  analogWrite(MRB,pwm);
  digitalWrite(MLF,LOW);
  analogWrite(MLB,pwm);
}

void loop() {
  int LeftVal = digitalRead(IrLeft);
  int MidVal = digitalRead(IrMid);
  int RightVal = digitalRead(IrRight);
  Serial.print(MidVal);

  if     (  LeftVal==LOW && MidVal==LOW && RightVal==LOW){
      Forward(); }
  else if(  LeftVal==HIGH && MidVal==HIGH && RightVal==LOW){
      Left(); }
  else if( LeftVal==HIGH && MidVal==LOW && RightVal==HIGH){
      Forward(); }
  else if(  LeftVal==HIGH && MidVal==LOW && RightVal==LOW){
      Left(); }
  else if(  LeftVal==LOW && MidVal==HIGH && RightVal==HIGH){
      Right();  }
  else if(  LeftVal==LOW && MidVal==HIGH && RightVal==LOW){
      Forward();  }
  else if(  LeftVal==LOW && MidVal==LOW && RightVal==HIGH){
      Right(); }
  else if(  LeftVal==LOW && MidVal==LOW && RightVal==LOW){
      Forward(); 
      }

}
