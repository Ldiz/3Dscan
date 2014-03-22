
#define PIN_DIR 11
#define PIN_STEP 12
#define PIN_LASER_RIGHT 10
#define PIN_LASER_LEFT 13

#define STEP_DIR_POS 0
#define STEP_DIR_NEG !STEP_DIR_POS

#define PI 3.14159265358979323846
#define STP_PER_REVO 200
#define RED_FOCTOR 1
#define DEG_PER_STEP RED_FOCTOR*360/STP_PER_REVO
#define RAD_PER_STEP RED_FOCTOR*2.*PI/STP_PER_REVO

void setup() {
  // initialize serial communication:
  Serial.begin(9600);

  // Pins allocations
  pinMode(PIN_DIR        , OUTPUT);
  pinMode(PIN_STEP       , OUTPUT);
  pinMode(PIN_LASER_RIGHT, OUTPUT);
  pinMode(PIN_LASER_LEFT , OUTPUT);
}

void step(int nSteps);
void stepDeg(double angle);
void stepRad(double angle);


void loop() {

  // A variable to read incoming serial data into
  int inByte;
  // See if there's incoming serial data:
  if (Serial.available() > 0) {
    // Read the oldest byte in the serial buffer:
    inByte = Serial.read();
    // An echo ...
    Serial.println(inByte);
    
    // Interpreter 
    switch (inByte) {
      // Motor stepping
    case 'M': {
      step(8);
      break;
    }    
    case 'L': { // Negative  rotation -- L (ASCII 76)
      step(-8);
      break;
    }
    case 'c':{
      digitalWrite(4, HIGH);
      break;
    }
    case 'd': {
      digitalWrite(5, HIGH);
      break;
    }
    case 'e': {
      digitalWrite(6, HIGH);
      break;
    }
    default: {
    }
    }
  }



void step(int steps) {

  if (steps > 0) 
    digitalWrite(PIN_DIR, STEP_DIR_POS);
  else 
    digitalWrite(PIN_DIR, STEP_DIR_NEG);

  delay(50);

  for(int i = 0; i < steps; i++) {
    digitalWrite(PIN_STEP, HIGH);
    delayMicroseconds(STEP_DELAY);
    digitalWrite(PIN_STEP, LOW);
    delayMicroseconds(STEP_DELAY);
  }
}


void step(int steps) {

  if (steps > 0) 
    digitalWrite(PIN_DIR, STEP_DIR_POS);
  else 
    digitalWrite(PIN_DIR, STEP_DIR_NEG);

  delay(50);

  for(int i = 0; i < steps; i++) {
    digitalWrite(PIN_STEP, HIGH);
    delayMicroseconds(STEP_DELAY);
    digitalWrite(PIN_STEP, LOW);
    delayMicroseconds(STEP_DELAY);
  }
}

void stepDeg(int steps) {

  if 
    digitalWrite(PIN_DIR, dir);
  delay(50);

  for(int i = 0; i < steps; i++) {
    digitalWrite(PIN_STEP, HIGH);
    delayMicroseconds(100.);
    digitalWrite(PIN_STEP, LOW);
    delayMicroseconds(100.);
  }
}

