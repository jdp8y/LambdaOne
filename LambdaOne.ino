
/*
 :::      :::====  :::=======  :::====  :::====  :::====  :::=====
 :::      :::  === ::: === === :::  === :::  === :::  === :::
 ===      ======== === === === =======  ===  === ======== ===
 ===      ===  === ===     === ===  === ===  === ===  === ===
 ======== ===  === ===     === =======  =======  ===  ===  =======
    v0.9 - Release Candidate
    Created by Josh Perry and Collin Rodes
    Code licenced under the "MIT" license.
*/
#include "MotorDriver.h"
#include <Servo.h>
const int  frontTriggerPin = 13;
const int  frontEchoPin = 12;
const int  leftTriggerPin = 9;
const int  leftEchoPin = 8;
const int  rightTriggerPin = 11;
const int  rightEchoPin = 10;
const int  backTriggerPin = 7;
const int  backEchoPin = 6;
const int straight = 90;
const int left = 45;
const int right = 135;
// const int brake;
int white;
int black;
int maxdistance;
long frontLine = analogRead(A3);
long backLine = analogRead(A2);
long durationFront, distanceFront, durationLeft, distanceLeft, durationRight, distanceRight, durationBack, distanceBack;
void spinSearch();
void ultrasonicPing();
void bestOption();
Servo pivotFront;
Servo pivotBack;

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
  pivotBack.attach(3);
  pivotFront.attach(2);
}

void frontFuctions() {
  while ((distanceFront < distanceLeft, distanceRight, distanceBack) and (maxdistance >= distanceFront)) {
    pivotFront.write(straight);
    pivotBack.write(straight);
    motordriver.goForward();
    bestOption();
  }
}

void leftFunctions() {
  while ((distanceLeft < distanceRight, distanceBack, distanceFront) and (maxdistance >= distanceLeft)) {
    pivotFront.write(left);
    pivotBack.write(left);
    motordriver.goForward();
    bestOption();
  }
}

void rightFunctions() {
  while ((distanceRight < distanceBack, distanceFront, distanceLeft) and (maxdistance >= distanceRight)) {
    pivotFront.write(right);
    pivotBack.write(right);
    motordriver.goForward();
    bestOption();
  }
}

void backFuctions() {
  while ((distanceBack < distanceFront, distanceLeft, distanceRight) and (maxdistance >= distanceBack)) {
    motordriver.goBackward();
  }
  bestOption();
}

void spinSearch() {
  if ((distanceLeft > distanceRight) and ((frontLine, backLine) = black)) {
    pivotFront.write(left);
    pivotBack.write(straight);
    motordriver.goForward();
    delay(2000);
    motordriver.stop();
  }
  if ((distanceRight > distanceLeft) and ((frontLine, backLine) = black)) {
    pivotFront.write(right);
    pivotBack.write(straight);
    motordriver.goForward();
    delay(2000);
    motordriver.stop();
  }
  ultrasonicPing();
}

void bestOption() {
  if ((frontLine = black) and (backLine = black)) {
    if ((distanceFront < distanceLeft, distanceRight, distanceBack) and (maxdistance >= distanceFront)) {
      frontFuctions();
    }
    if ((distanceLeft < distanceRight, distanceBack, distanceFront) and (maxdistance >= distanceLeft)) {
      leftFunctions();
    }
    if ((distanceRight < distanceBack, distanceFront, distanceLeft) and (maxdistance >= distanceRight)) {
      rightFunctions();
    }
    if ((distanceBack < distanceFront, distanceLeft, distanceRight) and (maxdistance >= distanceBack)) {
      backFuctions();
    }
  }
  else {
    while ((frontLine = black) and (backLine = white)) {
      motordriver.goForward();
    }
    while ((frontLine = white) and (backLine = black)) {
      motordriver.goBackward();
    }
    spinSearch();
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
  pivotBack.write(left);
  pivotFront.write(right);
  motordriver.goForward();
  delay(2000);
  motordriver.stop();
  ultrasonicPing();
}
