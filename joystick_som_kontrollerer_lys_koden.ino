#define joyX A0
#define joyY A1
int teller = 0;
void setup() 
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
}
void loop() {
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);
  if (xValue<=256) {
    digitalWrite(12, HIGH);
  }
  else{
    digitalWrite(12, LOW);}

  if (xValue>=256 && yValue<=511){
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
  }
  else{
    digitalWrite(11, LOW);}

  if (xValue>=256 && yValue>=514){
    digitalWrite(11, LOW);
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
  }

}