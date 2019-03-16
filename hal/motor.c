#include "common.h"
#include "motor.h"
#include "pinCtl.h"
static s_MotorParam G_MotorParam;

int8 initMotors(s_MotorParam *param)
{
  int8 i=0;
  
  if(!param){
     return -1;
  }

  if(param->MotorNum >= MAX_MOTOR){
     return -1;
  }
  G_MotorParam.MotorNum = param->MotorNum;

  for(i=0; i<param->MotorNum; i++)
  {
      pinMode_common(param->Motor[i].MotorPinLeft, OUTPUT);
      pinMode_common(param->Motor[i].MotorPinRight, OUTPUT);
      G_MotorParam.Motor[i].MotorPinLeft = param->Motor[i].MotorPinLeft;
      G_MotorParam.Motor[i].MotorPinRight = param->Motor[i].MotorPinRight;
  }
  
  return 0;
}


int8 SetMotorSatus(MOTOR motor, MOTOR_STUTAS motorStatus)
{

    switch(motorStatus){
      case MOTOR_STOP:
      {
        digitalWrite_common(G_MotorParam.Motor[motor].MotorPinLeft, 0);
        digitalWrite_common(G_MotorParam.Motor[motor].MotorPinRight, 0);
        break;  
      }
      case MOTOR_CLOCKWISE:
      {
        digitalWrite_common(G_MotorParam.Motor[motor].MotorPinLeft, 1);
        digitalWrite_common(G_MotorParam.Motor[motor].MotorPinRight, 0);
        break;  
      }
      case MOTOR_ANTICLOCKWISE:
      {
        digitalWrite_common(G_MotorParam.Motor[motor].MotorPinLeft, 0);
        digitalWrite_common(G_MotorParam.Motor[motor].MotorPinRight, 1);
        break;  
      }
    }
  
  return 0;
}
