#ifndef _DRIVE_H_
#define _DRIVE_H_

#include "API.h"

#define THRESHOLD 20

typedef enum {
  fast = true,
  slow = false
} FiringSpeed;

typedef enum {
  on = true,
  off = false
} FiringMode;

typedef enum {
  forward,
  reverse,
  clockwise,
  counterclockwise
} Direction;

typedef enum {
  up,
  down
} FlipperDirection;

static FiringMode firingMode = off;
static FiringSpeed firingSpeed = slow;

void drive();

void mechanumDrive();

void robotStop();

void flipperMove(FlipperDirection dir);

void flipperStop();

void intakeStart(Direction dir);

void intakeStop();

void flywheelStart(int speed);

void flywheelStop();

void setMotorsLeft(int speed);

void setMotorsRight(int speed);

void gyroTurn(int degrees, Gyro gyro, int minSpeed);

void robotMove(int inches);

int max(int a, int b);

#endif
