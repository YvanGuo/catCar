#ifndef __PIN_CTL_H__
#define __PIN_CTL_H__

#include "common.h"

//#ifndef ARDUINO_LIB 
typedef enum PIN_MODE{
  OUTPUT = 0,
  INPUT,
  INPUT_PULLUP,
  PWM
}PIN_MODE;

typedef enum PIN_STATUS{
  LOW = 0,
  HIGH
}PIN_STATUS;

//#endif
int32 pinMode_common(uint8 pin, PIN_MODE mode);
void analogWrite_common(uint8 pin, int32 val);
void digitalWrite_common(uint8 pin, int32 val);
uint8 digitalRead_common(uint8 pin);

#endif
