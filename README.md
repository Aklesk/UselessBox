# UselessBox

This is a project which uses a stepper motor and metal servo to achieve a multi-switch Useless Box.
This particular version is set up for 15 switches, but more can easily be added.
This is code intended to be run on an Arduino Mega.

# Order of Action
  Wait for servo control pin to broadcast properly
  Activate power to the servo
  Reset servo position
  Set stepper to slow fixed-speed
  Move stepper towards the home switch
  When home click is found, set stepper position to zero
  Set stepper to full speed with acceleration
  
  BEGIN LOOP
  
  Decide on a destination: poll each switch for state and distance from current position, choose closest. If no switch, go to rest.
  Travel to distination (blocking)
  Check for active switch at current position
  If active switch found, activate servo until switch turns off
  If servo reaches maximum extent without switch turning off, reset servo and re-home
  Loop back to beginning.

# Physical Electronics
  Arduino Mega
  Easy Driver Stepper Driver
  Nema17 Stepper Motor
  standard metal-geared servo motor
  5V external power supply (for servo)
  12V external power supply
  One Transistor

# Required libraries
  AccelStepper.h
  Servo.h
  
# Pin assignments
  Pin 6: Servo control pin
  Pin 10: Pin connected to a transistor controlling power to the 5V supply (Servo moves randomly during intialization if powered) 
  Pin 11: Home switch to find stepper position - shorted to ground when switch is activated
  Pin 12: Stepper driver step pin
  Pin 13: Stepper driver direction pin
  Pins 31-45: Useless Box control switches
