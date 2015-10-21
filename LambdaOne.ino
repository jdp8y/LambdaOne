/*
 *  The LambdaOne Software
 *  v1.0 - Release Candidate
 *  Created by Josh Perry and Collin Rodes
 *  Code licenced under the "MIT" license.
*/

/*
 *  Code has to be re-written with adjustments such as pins, turning angles, delays, colorcodes, etc.
 *  This will not work without these being adjusted.
*/

#include "MotorDriver.h"
#include <Servo.h>
const int frontTriggerPin = 13, frontEchoPin = 12, leftTriggerPin = 9, leftEchoPin = 8, rightEchoPin = 10, rightTriggerPin = 11, backTriggerPin = 7, backEchoPin = 6;
const int straight = 0, left = 0, right = 0; // placeholder
const int backPivotPin = 2, frontPivotPin = 3;
const int maxDistance = 0; // placeholder 
const int whiteColorCode = 0, blackColorCode = 0; // placeholder
long frontLine = analogRead(A3), backLine = analogRead(A2);
long durationFront, distanceFront, durationLeft, distanceLeft, durationRight, distanceRight, durationBack, distanceBack;
Servo pivotFront, pivotBack;

void setup() {
  Serial.begin(9600);
  pinMode(frontTriggerPin, OUTPUT);
  pinMode(frontEchoPin, INPUT);
  pinMode(leftTriggerPin, OUTPUT);
  pinMode(leftEchoPin, INPUT);
  pinMode(rightTriggerPin, OUTPUT);
  pinMode(rightEchoPin, INPUT);
  pinMode(backTriggerPin, OUTPUT);
  pinMode(backEchoPin, INPUT);
  pivotBack.attach(backPivotPin);
  pivotFront.attach(frontPivotPin);
}

void frontFuctions() {
  while ((distanceFront < distanceLeft, distanceRight, distanceBack) and (maxDistance >= distanceFront)) {
    pivotFront.write(straight);
    pivotBack.write(straight);
    motordriver.goForward();
    bestOption();
  }
}

void leftFunctions() {
  while ((distanceLeft < distanceRight, distanceBack, distanceFront) and (maxDistance >= distanceLeft)) {
    pivotFront.write(left);
    pivotBack.write(left);
    motordriver.goForward();
    bestOption();
  }
}

void rightFunctions() {
  while ((distanceRight < distanceBack, distanceFront, distanceLeft) and (maxDistance >= distanceRight)) {
    pivotFront.write(right);
    pivotBack.write(right);
    motordriver.goForward();
    bestOption();
  }
}

void backFuctions() {
  while ((distanceBack < distanceFront, distanceLeft, distanceRight) and (maxDistance >= distanceBack)) {
    motordriver.goBackward();
  }
  bestOption();
}

void spinningPing() {
  while ((distanceFront, distanceLeft, distanceRight, distanceBack > maxDistance) and ((frontLine, backLine) = blackColorCode)) {
    pivotFront.write(right);
    pivotBack.write(right);
    motordriver.goForward();
    ultrasonicPing();
  }
  ultrasonicPing();
}

void dontFall() {
  while ((frontLine = blackColorCode) and (backLine = whiteColorCode)) {
    motordriver.goForward();
  }
  while ((frontLine = whiteColorCode) and (backLine = blackColorCode)) {
    motordriver.goBackward();
  }
  bestOption();
}

void bestOption() {
  if ((frontLine = blackColorCode) and (backLine = blackColorCode)) {
    if ((distanceFront < distanceLeft, distanceRight, distanceBack) and (maxDistance >= distanceFront)) {
      frontFuctions();
    }
    if ((distanceLeft < distanceRight, distanceBack, distanceFront) and (maxDistance >= distanceLeft)) {
      leftFunctions();
    }
    if ((distanceRight < distanceBack, distanceFront, distanceLeft) and (maxDistance >= distanceRight)) {
      rightFunctions();
    }
    if ((distanceBack < distanceFront, distanceLeft, distanceRight) and (maxDistance >= distanceBack)) {
      backFuctions();
    }
  }
  else {
    dontFall();
  }
}

void ultrasonicPing() {
  digitalWrite(frontTriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(frontTriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(frontTriggerPin, LOW);
  durationFront = pulseIn(frontEchoPin, HIGH);
  distanceFront = (durationFront / 2) / 29.1;
  digitalWrite(leftTriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(leftTriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(leftTriggerPin, LOW);
  durationLeft = pulseIn(leftEchoPin, HIGH);
  distanceLeft = (durationLeft / 2) / 29.1;
  digitalWrite(rightTriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(rightTriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(rightTriggerPin, LOW);
  durationRight = pulseIn(rightEchoPin, HIGH);
  distanceRight = (durationRight / 2) / 29.1;
  digitalWrite(backTriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(backTriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(backTriggerPin, LOW);
  durationBack = pulseIn(backEchoPin, HIGH);
  distanceBack = (durationBack / 2) / 29.1;
  bestOption();
}

void loop() {
  pivotBack.write(left); // placeholder
  pivotFront.write(left); // placeholder
  motordriver.goForward();
  delay(2000); // placeholder
  motordriver.stop();
  ultrasonicPing();
}
