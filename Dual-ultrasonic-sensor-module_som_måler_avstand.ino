const int trigPin = 11;    // TRIG-pinne til pin 9 på Arduino
const int echoPin = 12;   // ECHO-pinne til pin 10 på Arduino
const int outPin = 10;     // OUT-pinne til pin 8 på Arduino

void setup() {
  Serial.begin(9600);     // Initialiser seriell kommunikasjon
  pinMode(trigPin, OUTPUT);// Sett TRIG-pinne til utgang
  pinMode(echoPin, INPUT); // Sett ECHO-pinne til inngang
  pinMode(outPin, INPUT);  // Sett OUT-pinne til inngang
}

void loop() {
  digitalWrite(trigPin, LOW);     // Sett TRIG-pinne til lav
  delayMicroseconds(2);           // Vent i 2 mikrosekunder
  digitalWrite(trigPin, HIGH);    // Sett TRIG-pinne til høy
  delayMicroseconds(10);          // Vent i 10 mikrosekunder
  digitalWrite(trigPin, LOW);     // Sett TRIG-pinne til lav

  long duration = pulseIn(echoPin, HIGH);  // Les inn tiden for ekko
  int distance = duration * 0.034 / 2;     // Konverter til cm

  if (distance < 30 && digitalRead(outPin) == HIGH) { // Hvis gjenstand er innenfor 30 cm og OUT-pinnen er høy
    // Gjør noe når hendelsen skjer, for eksempel:
    Serial.println("Gjenstand innenfor 30 cm");
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(500); // Vent i 500 ms
}