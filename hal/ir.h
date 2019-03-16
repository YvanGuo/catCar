#ifndef __IR_H__
#define __IR_H__
#include "common.h"

typedef enum IRS{
  MOTOR_LEFT = 0,
  MOTOR_RIGHT,
  MAX_IR_NUM
}IRS;

typedef struct s_Ir{
    int8 Ir_pin;
}s_Ir;

typedef struct s_IRParam{
    s_Ir Ir[MAX_IR_NUM];
    int8 IRNum;
}s_IRParam;

int8 initIR(s_IRParam *param);
int8 getIRStartus(IRS ir);

#endif
