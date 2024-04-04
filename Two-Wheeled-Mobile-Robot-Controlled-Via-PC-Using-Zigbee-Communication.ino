
// SoftwareSerial is used to communicate with the XBee
#include <SoftwareSerial.h>

SoftwareSerial XBee(2, 3); // Arduino RX, TX (XBee Dout, Din)

// pins for connecting to L298N
int motorRpin1 = 4;
int motorRpin2 = 5;

int motorLpin1 = 6;
int motorLpin2 = 7;
int motorRpwm=9;
int motorLpwm=10;
char cc;

// Print Interface on the PC
void printMenu()
{
  XBee.println();
  XBee.println(F(" W : Move Forward "));
  XBee.println(F(" D: Turn Right "));
  XBee.println(F(" A: Turn Left "));
  XBee.println(F(" S: Revrese "));
  XBee.println();
}

// Reverse
void MoveBackward()
{
  //Right Wheel
  digitalWrite(motorRpin1, HIGH);
  digitalWrite(motorRpin2, LOW);
  //Left Wheel
  digitalWrite(motorLpin1, HIGH); 
  digitalWrite(motorLpin2, LOW);

  //Right Wheel
  analogWrite(motorRpwm, 120); //PWM pin
  //Left Wheel
  analogWrite(motorLpwm, 120); //PWM pin

  delay(250);

  //Right Wheel
  analogWrite(motorRpwm, 0); //PWM pin
  //Left Wheel
  analogWrite(motorLpwm, 0); //PWM pin
}

// Turn Right
void MoveRight()
{
  //Right Wheel
  digitalWrite(motorRpin1, LOW);
  digitalWrite(motorRpin2, HIGH);
  //Left Wheel
  digitalWrite(motorLpin1, HIGH); 
  digitalWrite(motorLpin2, LOW);

  //Right Wheel
  analogWrite(motorRpwm, 120); //PWM pin
  //Left
  analogWrite(motorLpwm, 120); //PWM pin

  delay(250);

  //Right Wheel
  analogWrite(motorRpwm, 0); //PWM pin
  //Left Wheel
  analogWrite(motorLpwm, 0); //PWM pin
}


// Turn Left
void MoveLeft()
{
  //Right Wheel
  digitalWrite(motorRpin1, HIGH);
  digitalWrite(motorRpin2, LOW);
  //Left Wheel
  digitalWrite(motorLpin1, LOW); 
  digitalWrite(motorLpin2, HIGH);

  //Right Wheel
  analogWrite(motorRpwm, 120); //PWM pin
  //Left Wheel
  analogWrite(motorLpwm, 120); //PWM pin

  delay(250);

  //Right Wheel
  analogWrite(motorRpwm, 0); //PWM pin
  //Left Wheel
  analogWrite(motorLpwm, 0); //PWM pin
}

// Reverse
void MoveForward()
{

  //Right Wheel
  digitalWrite(motorRpin1, LOW);
  digitalWrite(motorRpin2, HIGH);
  //Left Wheel
  digitalWrite(motorLpin1, LOW); 
  digitalWrite(motorLpin2, HIGH);

  //Right Wheel
  analogWrite(motorRpwm, 120); //PWM pin
  //Left Wheel
  analogWrite(motorLpwm, 120); //PWM pin

  delay(250);

  //Right Wheel
  analogWrite(motorRpwm, 0); //PWM pin
  //Left Wheel
  analogWrite(motorLpwm, 0); //PWM pin
}


void setup()
{
  // Zigbee Initialization
  XBee.begin(9600); 
  printMenu(); // Print PC Interface

  pinMode(motorLpin1, OUTPUT);
  pinMode(motorLpin2, OUTPUT);
  pinMode(motorRpin1, OUTPUT);
  pinMode(motorRpin2, OUTPUT);

}
void loop()
{
  // Check continuously for Available Commands
  if (XBee.available())
 {
    char cc = XBee.read();
    switch (cc)
    {
    case 'w':      // If Received 'w'
    case 'W':      // or 'W'
      MoveForward(); // Move Forward
      break;
    case 'd':      // If Received 'd'
    case 'D':      // or 'D'
      MoveRight(); // Turn Right
      break;
    case 's':      // If Received 'r'
    case 'S':      // or 'R'
      MoveBackward();  // Reverse
      break;
    case 'a':      // If Received 'a'
    case 'A':      // or 'A'
      MoveLeft();  // Turn Left
      break;
    
    }
  }
}
