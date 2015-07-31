
/*
 :::      :::====  :::=======  :::====  :::====  :::====  :::=====
 :::      :::  === ::: === === :::  === :::  === :::  === :::     
 ===      ======== === === === =======  ===  === ======== ===     
 ===      ===  === ===     === ===  === ===  === ===  === ===     
 ======== ===  === ===     === =======  =======  ===  ===  =======
    v0.8 - Release Candidate
    Created by Josh Perry and Collin Rodes
    Code licenced under the "MIT" license.
*/
#include "MotorDriver.h"
#include <Servo.h>
#define  TRIGGER_PIN       13
#define  ECHO_PIN          12
#define  TRIGGER_PINLEFT   9
#define  ECHO_PINLEFT      8
#define  TRIGGER_PINRIGHT  11
#define  ECHO_PINRIGHT     10
#define  TRIGGER_PINBACK   7
#define  ECHO_PINBACK      6

Servo pivot;
Servo pivot2;

long LineFront = analogRead(A3);
long LineBack = analogRead(A2);
long duration, distance, durationleft, distanceleft, durationright, distanceright, durationback, distanceback;
int straight = 90;
int left = 45;
int right = 135;
int white;
int black;
int maxdistance;
void ultrasonic();
void nooneshome();
void control();

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PINLEFT, OUTPUT);
  pinMode(ECHO_PINLEFT, INPUT);
  pinMode(TRIGGER_PINRIGHT, OUTPUT);
  pinMode(ECHO_PINRIGHT, INPUT);
  pinMode(TRIGGER_PINBACK, OUTPUT);
  pinMode(ECHO_PINBACK, INPUT);
  pivot2.attach(3);
  pivot.attach(2);
}

void frontfunc() {
  while ((distance < distanceleft, distanceright, distanceback) and (maxdistance >= distance)) {
    pivot.write(straight);
    pivot2.write(straight);
    motordriver.goForward();
    control();
  }
}

void leftfunc() {
  while ((distanceleft < distanceright, distanceback, distance) and (maxdistance >= distanceleft)) {
    pivot.write(left);
    pivot2.write(left);
    motordriver.goForward();
    control();
  }
}

void rightfunc() {
  while ((distanceright < distanceback, distance, distanceleft) and (maxdistance >= distanceright)) {
    pivot.write(right);
    pivot2.write(right);
    motordriver.goForward();
    control();
  }
}

void backfunc() {
  while ((distanceback < distance, distanceleft, distanceright) and (maxdistance >= distanceback)) {
    motordriver.goBackward();
  }
  control();
}




void nooneshome() {
  if (distanceleft > distanceright) {
    pivot.write(left);
    pivot2.write(straight);
    motordriver.goForward();
    delay(2000);
    motordriver.stop();
  }
  if (distanceright > distanceleft) {
    pivot.write(right);
    pivot2.write(straight);
    motordriver.goForward();
    delay(2000);
    motordriver.stop();
  }
  ultrasonic();
}

void control() {
  if ((LineFront = black) and (LineBack = black)){
  if ((distance < distanceleft, distanceright, distanceback) and (maxdistance >= distance)) {
    frontfunc();
  }
  if ((distanceleft < distanceright, distanceback, distance) and (maxdistance >= distanceleft)) {
    leftfunc();
  }
  if ((distanceright < distanceback, distance, distanceleft) and (maxdistance >= distanceright)) {
    rightfunc();
  }
  if ((distanceback < distance, distanceleft, distanceright) and (maxdistance >= distanceback)) {
    backfunc();
  }
  }
  else{
    while ((LineFront = black) and (LineBack = white)){
      motordriver.goForward();
    }
    while ((LineFront = white) and (LineBack = black))
      motordriver.goBackward();
  }
}

void ultrasonic() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;
  digitalWrite(TRIGGER_PINLEFT, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PINLEFT, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PINLEFT, LOW);
  durationleft = pulseIn(ECHO_PINLEFT, HIGH);
  distanceleft = (durationleft / 2) / 29.1;
  digitalWrite(TRIGGER_PINRIGHT, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PINRIGHT, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PINRIGHT, LOW);
  durationright = pulseIn(ECHO_PINRIGHT, HIGH);
  distanceright = (durationright / 2) / 29.1;
  digitalWrite(TRIGGER_PINBACK, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PINBACK, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PINBACK, LOW);
  durationback = pulseIn(ECHO_PINBACK, HIGH);
  distanceback = (durationback / 2) / 29.1;
  control();
}

void loop() {
  pivot2.write(left);
  pivot.write(right);
  motordriver.goForward();
  delay(2000);
  motordriver.stop();
  ultrasonic();
}
