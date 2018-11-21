#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

//Joysticks
#define JOYSTICK_MAIN 1
#define JOYSTICK_PARTNER 2

//Sticks and axes
#define STICK_RIGHT_X 1
#define STICK_RIGHT_Y 2
#define STICK_LEFT_Y 3
#define STICK_LEFT_X 4

int joystickGetAnalogA(unsigned char joystick, unsigned char channel);

#endif
