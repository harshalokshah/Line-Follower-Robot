/*------ Arduino Line Follower Code -----*/

// Sensor pins
const int LEFT_SENSOR = 2;   // Left IR sensor
const int RIGHT_SENSOR = 3;  // Right IR sensor

// Motor control pins
const int LEFT_MOTOR_P1 = 4;   // Left motor wire 1
const int LEFT_MOTOR_P2 = 5;   // Left motor wire 2
const int RIGHT_MOTOR_P1 = 6;  // Right motor wire 1
const int RIGHT_MOTOR_P2 = 7;  // Right motor wire 2

void setup() {
  // Initialize sensor pins as inputs
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  
  // Initialize motor pins as outputs
  pinMode(LEFT_MOTOR_P1, OUTPUT);
  pinMode(LEFT_MOTOR_P2, OUTPUT);
  pinMode(RIGHT_MOTOR_P1, OUTPUT);
  pinMode(RIGHT_MOTOR_P2, OUTPUT);
  
  // Initial motor state - stop
  digitalWrite(LEFT_MOTOR_P1, LOW);
  digitalWrite(LEFT_MOTOR_P2, LOW);
  digitalWrite(RIGHT_MOTOR_P1, LOW);
  digitalWrite(RIGHT_MOTOR_P2, LOW);
  
  // Optional: Add serial monitor for debugging
  // Serial.begin(9600);
}

void loop() {
  // Read sensor values (LOW = white surface, HIGH = dark line)
  bool leftDetected = digitalRead(LEFT_SENSOR);
  bool rightDetected = digitalRead(RIGHT_SENSOR);

  /* Control Logic:
   *  Both sensors white: Move forward
   *  Left on black: Turn right
   *  Right on black: Turn left
   *  Both on black: Stop
   */
  
  if (!leftDetected && !rightDetected) {
    // Move forward
    moveForward();
  } 
  else if (leftDetected && !rightDetected) {
    // Turn right
    turnRight();
  } 
  else if (!leftDetected && rightDetected) {
    // Turn left
    turnLeft();
  } 
  else {
    // Stop (both sensors detect line)
    stopMotors();
  }
}

// Motor control functions
void moveForward() {
  digitalWrite(LEFT_MOTOR_P1, HIGH);
  digitalWrite(LEFT_MOTOR_P2, LOW);
  digitalWrite(RIGHT_MOTOR_P1, HIGH);
  digitalWrite(RIGHT_MOTOR_P2, LOW);
}

void turnRight() {
  // Left motor forward, right motor stopped
  digitalWrite(LEFT_MOTOR_P1, HIGH);
  digitalWrite(LEFT_MOTOR_P2, LOW);
  digitalWrite(RIGHT_MOTOR_P1, LOW);
  digitalWrite(RIGHT_MOTOR_P2, LOW);
}

void turnLeft() {
  // Right motor forward, left motor stopped
  digitalWrite(LEFT_MOTOR_P1, LOW);
  digitalWrite(LEFT_MOTOR_P2, LOW);
  digitalWrite(RIGHT_MOTOR_P1, HIGH);
  digitalWrite(RIGHT_MOTOR_P2, LOW);
}

void stopMotors() {
  digitalWrite(LEFT_MOTOR_P1, LOW);
  digitalWrite(LEFT_MOTOR_P2, LOW);
  digitalWrite(RIGHT_MOTOR_P1, LOW);
  digitalWrite(RIGHT_MOTOR_P2, LOW);
}