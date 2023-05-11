const int trigPin = 3;
const int echoPin = 2;
const int outPin = 4;
int blue = 13;
int green = 12;
int red = 11;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(outPin, INPUT);  
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);    
  delayMicroseconds(2);        
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);        
  digitalWrite(trigPin, LOW);     

  long duration = pulseIn(echoPin, HIGH);  
  int distance = duration * 0.034 / 2;   

  if (distance < 100 ) { 

    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
  } else if (distance > 100 && distance < 300){
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
  } else if(distance > 300){
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}