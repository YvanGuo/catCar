#ifndef __MOTOR_H__
#define __MOTOR_H__
#include "common.h"

typedef enum MOTOR{
  MOTOR_LEFT = 0,
  MOTOR_RIGHT,
  MAX_MOTOR
}MOTOR;

typedef enum MOTOR_STUTAS{
  MOTOR_STOP = 0,
  MOTOR_CLOCKWISE,
  MOTOR_ANTICLOCKWISE
}MOTOR_STUTAS;

typedef struct s_Motor{
    int8 MotorPinLeft;
    int8 MotorPinRight;
}s_Motor;

typedef struct s_MotorParam{
    s_Motor Motor[MAX_MOTOR];
    int8 MotorNum;
}s_MotorParam;

int8 initMotors(s_MotorParam *param);
int8 SetMotorSatus(MOTOR motor, MOTOR_STUTAS motorStatus);

#endif
