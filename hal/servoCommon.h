#ifndef _SERVO_COMON_H_
#define _SERVO_COMON_H_
#include "common.h"

#define NOT_ATTACHED                    (-1)

#define SERVO_DEFAULT_MIN_PW            544
#define SERVO_DEFAULT_MAX_PW            2400
#define SERVO_DEFAULT_MIN_ANGLE         0
#define SERVO_DEFAULT_MAX_ANGLE         180

void ServoDefaultInit();

//int8 servoAttach(uint8 pin, uint16 minPulseWidth=SERVO_DEFAULT_MIN_PW, uint16 maxPulseWidth=SERVO_DEFAULT_MAX_PW, int16 minAngle=SERVO_DEFAULT_MIN_ANGLE, int16 maxAngle=SERVO_DEFAULT_MAX_ANGLE);
int8 servoAttach(uint8 pin,uint16 minPulseWidth,uint16 maxPulseWidth,int16 minAngle,int16 maxAngle);

int16 servoAttached();

int32 servoAttachedPin();

int8 servoDetach();

void servoWrite(int32 angle);

int32 servoRead();

void servoWriteMicroseconds(uint16 pulseWidth);

uint16 servoReadMicroseconds();

#endif  /* _SERVO_H_ */
