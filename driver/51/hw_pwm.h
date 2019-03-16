#ifndef __PWM_H__
#define __PWM_H__


#include	"common.h"

void ServoPwmInterruptProc();
void resetServoPulCnt();
void setServoPulseWidth(uint16 cnt);
void setServoCtlPin(uint8 pin);
void uartCmdProc(void *uartData);

#endif
