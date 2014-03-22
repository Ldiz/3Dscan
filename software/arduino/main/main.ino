/********************************************************************
 * 
 * Commande scanner 3D
 * 
 ********************************************************************/

// Lasers pins
#define PIN_LASER_RIGHT 10
#define PIN_LASER_LEFT 11

// Motor pins
// Step/Dir Interface
// #define PIN_DIR 12 
// #define PIN_STEP 13   

// Wires interface
#define MOTOR_PIN_A 2
#define MOTOR_PIN_B 3
#define MOTOR_PIN_C 4
#define MOTOR_PIN_D 5
/*
  Wires states sequence for direct rotation

  Step A  B  C  D
  0    1  0  1  0
  1    0  1  1  0
  2    0  1  0  1
  3    1  0  0  1
*/

// Stepping direction
#define STEP_DIR_POS 0
#define STEP_DIR_NEG !STEP_DIR_POS

// Stepper characteristics
#define STP_PER_REVO 200
#define RED_FOCTOR 1
// Delay for stepper motor commutation (in ms)
#define STEP_DELAY 100.
// Number of motor steps between shots
#define N_STEPS 10
// Helper constants
#define PI 3.14159265358979323846
#define DEG_PER_STEP RED_FOCTOR*360/STP_PER_REVO
#define RAD_PER_STEP RED_FOCTOR*2.*PI/STP_PER_REVO


void setup() {
  // initialize serial communication:
  Serial.begin(9600);

  // Pins allocations
  pinMode(PIN_DIR        , OUTPUT);
  pinMode(PIN_STEP       , OUTPUT);

  pinMode(PIN_LASER_RIGHT, OUTPUT);
  digitalWrite(PIN_LASER_RIGHT, LOW);

  pinMode(PIN_LASER_LEFT , OUTPUT);
  digitalWrite(PIN_LASER_LEFT, LOW);
}

//      Fonctions pour faire tourner moteur d'un pas
//      usage : 
void oneStep (unsigned int Dir)
{
  static int stepNumber;
  if (Dir == STEP_DIR_POS) {
    stepNumber = (stepNumber + 1) % 4;
  }
  else {
    stepNumber = (stepNumber - 1) % 4;
  }

  switch (stepNumber) {
  case 0:    // 1010
    digitalWrite(MOTOR_PIN_A, HIGH);
    digitalWrite(MOTOR_PIN_B, LOW);
    digitalWrite(MOTOR_PIN_C, HIGH);
    digitalWrite(MOTOR_PIN_D, LOW);
    break;
  case 1:    // 0110
    digitalWrite(MOTOR_PIN_A, LOW);
    digitalWrite(MOTOR_PIN_B, HIGH);
    digitalWrite(MOTOR_PIN_C, HIGH);
    digitalWrite(MOTOR_PIN_D, LOW);
    break;
  case 2:    //0101
    digitalWrite(MOTOR_PIN_A, LOW);
    digitalWrite(MOTOR_PIN_B, HIGH);
    digitalWrite(MOTOR_PIN_C, LOW);
    digitalWrite(MOTOR_PIN_D, HIGH);
    break;
  case 3:    //1001
    digitalWrite(MOTOR_PIN_A, HIGH);
    digitalWrite(MOTOR_PIN_B, LOW);
    digitalWrite(MOTOR_PIN_C, LOW);
    digitalWrite(MOTOR_PIN_D, HIGH);
    break;
  }
}
 
// Rotation -- the sign define the sens of rotation
void steps(int nSteps) {
  int Dir; 
  if (nSteps > 0) 
    Dir = STEP_DIR_POS;
  else
    Dir = STEP_DIR_NEG; 
  for (int i = 0; i < abs(nSteps); i++) {
    oneStep(Dir);
    delayMicroseconds(STEP_DELAY);
  } // for nSpets
} // steps()


void loop() {

  // A variable to read incoming serial data into
  int inByte;
  // See if there's incoming serial data:
  if (Serial.available() > 0) {
    // Read the oldest byte in the serial buffer:
    inByte = Serial.read();
    // An echo ...
    // Serial.println(inByte);
    
    // Interpreter 
    switch (inByte) {
      // Motor rotation (M: positive, m: negative) 
    case 'M': {
      steps(N_STEPS);
      break;
    }    
    case 'm': {
      steps(-N_STEPS);
      break;
    }
      // Laser Right (R: ON, r: OFF)
    case 'R':{
      digitalWrite(PIN_LASER_RIGHT, HIGH);
      break;
    }
    case 'r': {
      digitalWrite(PIN_LASER_RIGHT, LOW);    
      break;
    } 
      // Laser Left (L: ON, l: OFF)
    case 'L': {
      digitalWrite(PIN_LASER_LEFT, HIGH);    
      break;
    }
    case 'l': 
      digitalWrite(PIN_LASER_LEFT, LOW);
    } // switch (inByte) 
  } // if (Serial)

} // loop()


