const int encoderCLK = 2;   // SW pin on the encoder
const int encoderDT = 3;   // DT pin on the encoder
const int encoderSW = 4;  // CLK pin on the encoder
int encoderPos = 0;        // current position of the encoder
int lastPos = 0;           // last position of the encoder

void setup() {
  pinMode(encoderSW, INPUT_PULLUP);  // enable internal pullup resistor for switch
  pinMode(encoderDT, INPUT_PULLUP);  // enable internal pullup resistor for DT
  pinMode(encoderCLK, INPUT_PULLUP); // enable internal pullup resistor for CLK
  Serial.begin(9600);                // initialize serial communication
}

void loop() {
  int swState = digitalRead(encoderSW);    // read the state of the switch
  int dtState = digitalRead(encoderDT);    // read the state of DT
  int clkState = digitalRead(encoderCLK);  // read the state of CLK

  // check if the encoder has been turned clockwise
  if (clkState == LOW && dtState == HIGH) {
    encoderPos++;
  }
  // check if the encoder has been turned counterclockwise
  if (clkState == LOW && dtState == LOW) {
    encoderPos--;
  }

  // check if the switch has been pressed
  if (swState == LOW) {
    Serial.println("Encoder switch pressed");
  }

  // print the current position of the encoder if it has changed
  if (encoderPos != lastPos) {
    Serial.print("Encoder position: ");
    Serial.println(encoderPos);
    lastPos = encoderPos;
  }
}
