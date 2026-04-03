/**
 * @file MotorController.ino
 * @brief Controls a cutter motor and a feeder gearmotor based on potentiometer input.
 * * The script reads an analog value from a potentiometer and scales it to set 
 * proportional PWM speeds for two separate motors. The feeder motor is capped 
 * at a lower maximum speed relative to the cutter motor to prevent jamming.
 */

// --- Hardware Pin Definitions ---
// Potentiometer Input
const int potPin = A0;   

// Cutter (DC Motor) Pins - L298N Left Side
const int cutterSpeedPin = 9;  // Enable Pin (PWM)
const int cutterDirPin = 8;    // Input 1 Pin (Direction)

// Feeder (Yellow Gearmotor) Pins - L298N Right Side
const int feederSpeedPin = 10; // Enable Pin (PWM)
const int feederDirPin = 11;   // Input 3 Pin (Direction)

// --- Configuration Constants ---
const int MAX_ANALOG_READ = 1023; // Maximum 10-bit ADC value from potentiometer
const int MAX_CUTTER_SPEED = 255; // Maximum 8-bit PWM value for high-speed chopping
const int MAX_FEEDER_SPEED = 150; // Capped PWM value so it feeds slower than the cutter chops

void setup() {
  // Initialize motor control pins as outputs
  pinMode(cutterSpeedPin, OUTPUT);
  pinMode(cutterDirPin, OUTPUT);
  pinMode(feederSpeedPin, OUTPUT);
  pinMode(feederDirPin, OUTPUT);
  
  // Lock both motors to spin in the forward direction
  digitalWrite(cutterDirPin, HIGH); 
  digitalWrite(feederDirPin, HIGH);
}

void loop() {
  // 1. Read the current potentiometer position
  int potValue = analogRead(potPin);
  
  // 2. Update motor speeds based on the reading
  updateMotorSpeeds(potValue);
}

/**
 * @brief Maps the potentiometer value to motor speeds and updates the hardware.
 * * @param potReading The raw analog reading from the potentiometer (0 - MAX_ANALOG_READ).
 */
void updateMotorSpeeds(int potReading) {
  // Calculate and set Cutter Speed
  int cutterSpeed = map(potReading, 0, MAX_ANALOG_READ, 0, MAX_CUTTER_SPEED);
  analogWrite(cutterSpeedPin, cutterSpeed);
  
  // Calculate and set Feeder Speed
  int feederSpeed = map(potReading, 0, MAX_ANALOG_READ, 0, MAX_FEEDER_SPEED); 
  analogWrite(feederSpeedPin, feederSpeed);
}