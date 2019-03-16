#include "carCtl.h"
#include "motor.h"

void carInit()
{
  s_MotorParam motors;
  motors.MotorNum = MAX_MOTOR;
  motors.Motor[MOTOR_LEFT].MotorPinLeft = MOTOR_LEFT_PIN_LEFT;
  motors.Motor[MOTOR_LEFT].MotorPinRight = MOTOR_LEFT_PIN_RIGHT;
  motors.Motor[MOTOR_RIGHT].MotorPinLeft = MOTOR_RIGHT_PIN_LEFT;
  motors.Motor[MOTOR_RIGHT].MotorPinRight = MOTOR_RIGHT_PIN_RIGHT;
  initMotors(&motors);
  
}

void carForward()
{
  SetMotorSatus(MOTOR_LEFT, MOTOR_CLOCKWISE);
  SetMotorSatus(MOTOR_RIGHT, MOTOR_CLOCKWISE);
}

void carBack()
{
  SetMotorSatus(MOTOR_LEFT, MOTOR_ANTICLOCKWISE);
  SetMotorSatus(MOTOR_RIGHT, MOTOR_ANTICLOCKWISE);
}

void carStop()
{
  SetMotorSatus(MOTOR_LEFT, MOTOR_STOP);
  SetMotorSatus(MOTOR_RIGHT, MOTOR_STOP);
  
}

void carTurnLeft()
{
   SetMotorSatus(MOTOR_LEFT, MOTOR_CLOCKWISE);
   SetMotorSatus(MOTOR_RIGHT, MOTOR_ANTICLOCKWISE);
  
}

void carTurnRight()
{
   SetMotorSatus(MOTOR_LEFT, MOTOR_ANTICLOCKWISE);
   SetMotorSatus(MOTOR_RIGHT, MOTOR_CLOCKWISE);
  
}
