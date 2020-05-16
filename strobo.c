const int leftLed = 4;   // select the pin for the left LED
const int rightLed = 5;  // select the pin for the right LED
const int tailLed = 8;   // select the pin for the tail LED
const int switchPin = 2;

const int timeBetweenLed = 430;
const int timeLedOn = 70;
// const int timePauseLed = 50; // for future use

int programType = 0;
int delayMillis = 1000;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(switchPin), changeProgram, CHANGE);
  
  // declare the ledPin as an OUTPUT:
  pinMode(leftLed, OUTPUT);
  pinMode(rightLed, OUTPUT);
  pinMode(tailLed, OUTPUT);
}

void changeProgram(int programType) {
    switch (programType) {
        case 0:
            delayMillis = 1000; // delay for key 0
            programType++;
            break;
        case 1:
            delayMillis = 2000; // delay for key 1
            programType++;
            break;
    }
}


void loop() {
    runProgram(programType);
    delay(delayMillis);
}

void runProgram(long programType) {
    switch (programType) {
        case 0:
            runProgramFlight();
            break;
        case 1:
            runProgramLanding();
            break;
        default:
            runProgramFlight();   
    }
}

void runProgramFlight() {
  digitalWrite(leftLed, HIGH);
  delay(timeLedOn);
  digitalWrite(leftLed, LOW);
  delay(timeBetweenLed);            
  
  digitalWrite(rightLed, HIGH);
  delay(timeLedOn);
  digitalWrite(rightLed, LOW);
  delay(timeBetweenLed);         
  
  digitalWrite(tailLed, HIGH);
  delay(timeLedOn);
  digitalWrite(tailLed, LOW);
  delay(timeBetweenLed);   
}

void runProgramLanding() {
  digitalWrite(leftLed, HIGH);
  delay(timeLedOn/4);
  digitalWrite(leftLed, LOW);
  delay(timeBetweenLed/4);            
  
  digitalWrite(rightLed, HIGH);
  delay(timeLedOn/4);
  digitalWrite(rightLed, LOW);
  delay(timeBetweenLed/4);         
  
  digitalWrite(tailLed, HIGH);
  delay(timeLedOn/4);
  digitalWrite(tailLed, LOW);
  delay(timeBetweenLed/4);   
}