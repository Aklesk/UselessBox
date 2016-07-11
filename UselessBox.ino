/*
 
 Stepper Motor Control - Useless Box
 Created by Wolf Hatch 2016
 
*/
#include <AccelStepper.h>
#include <Servo.h>

AccelStepper stepper(1, 12, 13);   // Set stepper mode (1 is driver), step pin, and direction pin.
int switches[16];                  // This stores the switch position data.
int dest = 0;                      // This tells the code where to go next. Zero is rest position, greater than 0 is a switch index number.
int switchPin = 0;                 // Temp variable used to convert the switch number to the pin number later
int inputPin = 11;                 // switch sensor input pin

Servo servo;                       // Start the servo
int servoOnPin = 10;               // The pin that turns the power to the servo on and off (powered is on)
int servoPin = 6;                  // The servo control pin
int servoRest = 175;               // The servo position at rest
int servoAct = 75;                 // The servo position when it's pressing the switch
int servoExtreme = 70;             // If the standard act position doesn't hit the switch, we may need to push a little harder.
int servoTrigger = 0;              // When this is set to 1, the servo will trigger on the next loop
int triggerWait = 0;

void setup() {
  switches[0] = 426;              // Rest position
  switches[1] = 18;               // Position of switch 1 in steps
  switches[2] = 81;               // Position of switch 2 in steps
  switches[3] = 144;              // Position of switch 3 in steps
  switches[4] = 207;              // Position of switch 4 in steps
  switches[5] = 270;              // Position of switch 5 in steps
  switches[6] = 333;              // Position of switch 6 in steps
  switches[7] = 396;              // Position of switch 7 in steps
  switches[8] = 459;              // Position of switch 8 in steps
  switches[9] = 522;              // Position of switch 9 in steps
  switches[10] = 585;             // Position of switch 10 in steps
  switches[11] = 648;             // Position of switch 11 in steps
  switches[12] = 711;             // Position of switch 12 in steps
  switches[13] = 774;             // Position of switch 13 in steps
  switches[14] = 837;             // Position of switch 14 in steps
  switches[15] = 900;             // Position of switch 15 in steps

  pinMode(31, INPUT);
  digitalWrite(31, HIGH);
  pinMode(32, INPUT);
  digitalWrite(32, HIGH);
  pinMode(33, INPUT);
  digitalWrite(33, HIGH);
  pinMode(34, INPUT);
  digitalWrite(34, HIGH);
  pinMode(35, INPUT);
  digitalWrite(35, HIGH);
  pinMode(36, INPUT);
  digitalWrite(36, HIGH);
  pinMode(37, INPUT);
  digitalWrite(37, HIGH);
  pinMode(38, INPUT);
  digitalWrite(38, HIGH);
  pinMode(39, INPUT);
  digitalWrite(39, HIGH);
  pinMode(40, INPUT);
  digitalWrite(40, HIGH);
  pinMode(41, INPUT);
  digitalWrite(41, HIGH);
  pinMode(42, INPUT);
  digitalWrite(42, HIGH);
  pinMode(43, INPUT);
  digitalWrite(43, HIGH);
  pinMode(44, INPUT);
  digitalWrite(44, HIGH);
  pinMode(45, INPUT);
  digitalWrite(45, HIGH);
  
  servo.attach(servoPin);          // Assign servo output
  pinMode(servoOnPin, OUTPUT);     // make servo on pin an output

  stepper.setMaxSpeed(500);
  stepper.setAcceleration(4000);

  pinMode(inputPin, INPUT);        // make switch an input
  digitalWrite(inputPin, HIGH);    // activate internal pull-up
  

  // First reset the servo
  delay(700);
  digitalWrite(servoOnPin, HIGH);  // Turn on the servo
  servo.write(servoRest);
  delay(700);


  // Now home the head
  stepper.moveTo(-1000);
  while(digitalRead(inputPin) != 0){ stepper.run(); }
  stepper.stop();
  stepper.setCurrentPosition(0);

  // We've homed - full speed
  stepper.setMaxSpeed(2500);
  stepper.setAcceleration(25000);
  delay(200);
  
}


void loop() {

  // First, we must decide on a destination. Check each of the switches in turn and load in the appropriate destination based upon that.
  // For each switch, check if it's active. If it is, check if if it's closer than an already picked destination
  // If no switches are active, dest will stay zero.
  dest = 0;
  if (digitalRead(31) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[1]) < abs(stepper.currentPosition() - switches[dest])){dest = 1;}}else{dest = 1;}}
  if (digitalRead(32) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[2]) < abs(stepper.currentPosition() - switches[dest])){dest = 2;}}else{dest = 2;}}
  if (digitalRead(33) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[3]) < abs(stepper.currentPosition() - switches[dest])){dest = 3;}}else{dest = 3;}}
  if (digitalRead(34) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[4]) < abs(stepper.currentPosition() - switches[dest])){dest = 4;}}else{dest = 4;}}
  if (digitalRead(35) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[5]) < abs(stepper.currentPosition() - switches[dest])){dest = 5;}}else{dest = 5;}}
  if (digitalRead(36) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[6]) < abs(stepper.currentPosition() - switches[dest])){dest = 6;}}else{dest = 6;}}
  if (digitalRead(37) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[7]) < abs(stepper.currentPosition() - switches[dest])){dest = 7;}}else{dest = 7;}}
  if (digitalRead(38) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[8]) < abs(stepper.currentPosition() - switches[dest])){dest = 8;}}else{dest = 8;}}
  if (digitalRead(39) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[9]) < abs(stepper.currentPosition() - switches[dest])){dest = 9;}}else{dest = 9;}}
  if (digitalRead(40) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[10]) < abs(stepper.currentPosition() - switches[dest])){dest = 10;}}else{dest = 10;}}
  if (digitalRead(41) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[11]) < abs(stepper.currentPosition() - switches[dest])){dest = 11;}}else{dest = 11;}}
  if (digitalRead(42) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[12]) < abs(stepper.currentPosition() - switches[dest])){dest = 12;}}else{dest = 12;}}
  if (digitalRead(43) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[13]) < abs(stepper.currentPosition() - switches[dest])){dest = 13;}}else{dest = 13;}}
  if (digitalRead(44) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[14]) < abs(stepper.currentPosition() - switches[dest])){dest = 14;}}else{dest = 14;}}
  if (digitalRead(45) == 0){if (dest != 0){if(abs(stepper.currentPosition() - switches[15]) < abs(stepper.currentPosition() - switches[dest])){dest = 15;}}else{dest = 15;}}
  

  // We should have our next destination locked in. Let's move to it, if we need to.
  if (stepper.currentPosition() != switches[dest])
  {
    stepper.runToNewPosition(switches[dest]);
  }


  // We're in position - now determine if the servo needs to trigger.
  if (dest != 0)                                          // Zero is rest position - never need to trigger the servo there
  {
    switchPin = dest + 30;
    if (digitalRead(switchPin) == 0)                    // If the switch is on, we need to trigger the servo - otherwise do nothing
    {
      
      // The servo trigger action
      servo.write(servoAct);
      triggerWait = 0;
      while(digitalRead(switchPin) == 0 && triggerWait < 6)
      {
        triggerWait += 1;
        delay(100);
      }
      
      // If the servo still hasn't hit the switch, push a little harder.
      if(triggerWait == 6)
      {
        servo.write(servoExtreme);
        delay(200);
      }

      // If the servo STILL hasn't hit the switch, re-home the head and start again.
      if(digitalRead(switchPin) == 0)
      {
          stepper.setMaxSpeed(500);
          stepper.setAcceleration(4000);
          
          // First reset the servo
          servo.write(servoRest);
          delay(700);
        
        
          // Now home the head
          stepper.moveTo(-1000);
          while(digitalRead(inputPin) != 0){ stepper.run(); }
          stepper.stop();
          stepper.setCurrentPosition(0);
        
          // We've homed - full speed
          stepper.setMaxSpeed(2500);
          stepper.setAcceleration(25000);
          delay(200);
        
      }
      
      servo.write(servoRest);
      delay(300);
    }
  }
}                                    // EOF
