#include "drive.h"
#include "ports.h"
#include "gyro.h"
#include "API.h"
#include "controller.h"

void drive() {
  mechanumDrive();
}

void mechanumDrive() {
  int stickLX = joystickGetAnalogA(JOYSTICK_MAIN, STICK_LEFT_X);
  int stickLY = joystickGetAnalogA(JOYSTICK_MAIN, STICK_LEFT_Y);
  int stickRX = joystickGetAnalogA(JOYSTICK_MAIN, STICK_RIGHT_X);

  motorSet(MOTOR_FRONT_RIGHT, -(stickLY - stickRX - stickLX) * .99);
  motorSet(MOTOR_BACK_RIGHT, -(stickLY - stickRX + stickLX) * .99);
  motorSet(MOTOR_FRONT_LEFT, -(stickLY + stickRX + stickLX) * .99);
  motorSet(MOTOR_BACK_LEFT, (stickLY + stickRX - stickLX) * .99);
}

void robotStop() {
  motorSet(MOTOR_FRONT_RIGHT, 0);
  motorSet(MOTOR_BACK_RIGHT, 0);
  motorSet(MOTOR_FRONT_LEFT, 0);
  motorSet(MOTOR_BACK_LEFT, 0);
}

void flipperMove(FlipperDirection dir) {
  if(dir == up)
  {

  }
}

void flipperStop() {

}

void intakeStart(Direction dir) {

}

void intakeStop() {

}

void flywheelStart(int speed) {

}

void flywheelStop() {

}

void setMotorsLeft(int speed) {

}

void setMotorsRight(int speed) {

}

void gyroTurn(int degrees, Gyro gyro, int minSpeed)
{
  int direction;
  //postive direction means turning right (posiive degrees)
  if (degrees > 0)
  {
    direction = 1;
  }
  else
  {
    direction = -1;
  }
  degrees -= degrees / 10;
  int initial = getGyro(gyro);
  int slowDown = 0;
  //turn while the difference is less than the target degrees
  while (abs(initial - getGyro(gyro)) <= abs(degrees))
  {
    //if less than 38 degs to target, slow down
    int degsRemaining = abs(degrees) - abs(initial - getGyro(gyro));
    if (degsRemaining <= 38)
    {
      //slow down by a fraction of degrees remaining;
      slowDown += degsRemaining / 3;
    }
    setMotorsLeft(max(minSpeed, GYRO_TURN_SPEED - slowDown) * direction);
    setMotorsRight(max(minSpeed, GYRO_TURN_SPEED - slowDown) * direction);
    wait(20);
  }
  robotStop();
}

void robotMove(int inches) {

}

int max(int a, int b)
{
  if (a > b) {return a;}
  return b;
}
