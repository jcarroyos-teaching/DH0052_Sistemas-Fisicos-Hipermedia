#include "Servo.h"


#define DEBUG 1
#define RUNNING_TIME 8000
#define TOP_SPEED 255

#define SERVO_RAIL   11
#define SERVO_PAN   10
#define SERVO_TILT 9


Servo panServo;
Servo tiltServo;
Servo railServo;
int rDistance = 180;
int tSangle = 0;
int pSangle = 95;
int steps = 10;


void setup() {
    Serial.begin(19200);
    
    panServo.attach(SERVO_PAN);
    tiltServo.attach(SERVO_TILT);
    railServo.attach(SERVO_RAIL);
    
    panServo.write(pSangle);
    tiltServo.write(tSangle);
    railServo.write(rDistance);
}

void loop() {
  if (Serial.available()) {
    char input = Serial.read();

    if (input == 'w') {
      tSangle += steps;
    } else if (input == 's') {
      tSangle -= steps;
    } else if (input == 'd') {
      pSangle += steps;
    } else if (input == 'a') {
      pSangle -= steps;
    } else if (input == 'q') {
      rDistance += steps;
    } else if (input == 'e') {
      rDistance -= steps;
    } else if (input == 'r') {
      pSangle = 95;
      tSangle = 0;
      rDistance = 180;
    }
    // Limit servo angle between 0 and 180 degrees
    tSangle = constrain(tSangle, 0, 180);
    pSangle = constrain(pSangle, 0, 180);
    rDistance = constrain(rDistance, 10, 180);

    tiltServo.write(tSangle);  // Set servo position
    panServo.write(pSangle);  // Set servo position
    railServo.write(rDistance);  // Set servo position
  }

}
