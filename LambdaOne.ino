/*
     The LambdaOne Software
     v1.3 - Release Candidate
     Created by Josh Perry and Collin Rodes
     Code licenced under the "MIT" license.
*/

/*
     Code has to be re-written with adjustments such as pins, turning angles, delays, colorcodes, etc.
     This will not work without these being adjusted.
*/

#include "MotorDriver.h"
#include <Servo.h>
#define MAX_DISTANCE 0
#define BLACK_COLOR_CODE 0
#define FRONT_TRIGGER_PIN 0
#define FRONT_ECHO_PIN 0
#define LEFT_TRIGGER_PIN 0
#define LEFT_ECHO_PIN 0
#define RIGHT_TRIGGER_PIN 0
#define RIGHT_ECHO_PIN 0
#define BACK_TRIGGER_PIN 0
#define BACK_ECHO_PIN 0
#define FRONT_LINE_SENSOR A0
#define BACK_LINE_SENSOR A0
const typedef enum { front, left, right, back, outofrange } direction;
const typedef enum { on, front_on, back_on, off} level;

void johnny_five_is_not_alive()
{
  motordriver.stop();
  for(;;)
  {
    // stop
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(FRONT_TRIGGER_PIN, OUTPUT);
  pinMode(FRONT_ECHO_PIN, INPUT);
  pinMode(LEFT_TRIGGER_PIN, OUTPUT);
  pinMode(LEFT_ECHO_PIN, INPUT);
  pinMode(RIGHT_TRIGGER_PIN, OUTPUT);
  pinMode(RIGHT_ECHO_PIN, INPUT);
  pinMode(BACK_TRIGGER_PIN, OUTPUT);
  pinMode(BACK_ECHO_PIN, INPUT);
}

level on_table()
{
  long front_line = analogRead(FRONT_LINE_SENSOR), back_line = analogRead(BACK_LINE_SENSOR);
  if ((front_line == BLACK_COLOR_CODE) && (back_line == BLACK_COLOR_CODE))
    return on;
  if ((front_line == BLACK_COLOR_CODE) && (back_line != BLACK_COLOR_CODE))
    return front_on;
  if ((front_line != BLACK_COLOR_CODE) && (back_line == BLACK_COLOR_CODE))
    return back_on;
  return off;
}

void get_on_table()
{
  switch (on_table())
  {
    case on:
      return;

    case front_on:
      while (on_table() == front_on)
        motordriver.goForward();
      return;

    case back_on:
      while (on_table() == back_on)
        motordriver.goBackward();
      return;

    case off:
      johnny_five_is_not_alive();
  }
}

direction best_option()
{
  long duration_front, distance_front, duration_left, distance_left, duration_right, distance_right, duration_back, distance_back;
  digitalWrite(FRONT_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(FRONT_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(FRONT_TRIGGER_PIN, LOW);
  duration_front = pulseIn(FRONT_ECHO_PIN, HIGH);
  distance_front = (duration_front / 2) / 29.1;
  digitalWrite(LEFT_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(LEFT_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(LEFT_TRIGGER_PIN, LOW);
  duration_left = pulseIn(LEFT_ECHO_PIN, HIGH);
  distance_left = (duration_left / 2) / 29.1;
  digitalWrite(RIGHT_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(RIGHT_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(RIGHT_TRIGGER_PIN, LOW);
  duration_right = pulseIn(RIGHT_ECHO_PIN, HIGH);
  distance_right = (duration_right / 2) / 29.1;
  digitalWrite(BACK_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(BACK_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(BACK_TRIGGER_PIN, LOW);
  duration_back = pulseIn(BACK_ECHO_PIN, HIGH);
  distance_back = (duration_back / 2) / 29.1;
  if ((distance_front < distance_left, distance_right, distance_back) && (MAX_DISTANCE >= distance_front))
    return front;
  if ((distance_left < distance_right, distance_back, distance_front) && (MAX_DISTANCE >= distance_left))
    return left;
  if ((distance_right < distance_back, distance_front, distance_left) && (MAX_DISTANCE >= distance_right))
    return right;
  if ((distance_back < distance_front, distance_left, distance_right) && (MAX_DISTANCE >= distance_back))
    return back;
  return outofrange;
}

void turn_around()
{
  motordriver.goRight();
  delay(2000);
  return;
}

int main()
{
  turn_around();
  for (;;)
  {
    while (on_table() == on)
    {
      if (best_option() == front)
        motordriver.goForward();
      if (best_option() == left)
        motordriver.goLeft();
      if (best_option() == right)
        motordriver.goRight();
      if (best_option() == back)
        motordriver.goBackward();
      else
        motordriver.goForward();
    }
    get_on_table();
  }
}
