
#include "servoCommon.h"
#include "pinCtl.h"
#include "driver/51/hw_pwm.h"
#include "timer.h"

typedef struct s_ServoCfg{
    int16 pin;
    uint16 minPW;
    uint16 maxPW;
    int16 minAngle;
    int16 maxAngle;
}s_ServoCfg;

static s_ServoCfg G_ServoCfg = {-1, -1, -1, -1, -1};

static void resetFields(void)
{
	setServoPulseWidth(15);
  
}

uint16 servoReadMicroseconds()
{
  
  return 0;
}

void servoWriteMicroseconds(uint16 pulseWidth)
{
  
  setServoPulseWidth(pulseWidth);
	
}

int32 servoRead()
{
  
  return 0;
}


void servoWrite(int32 angle)
{
	uint16 pulseWidth = 5;
	
  if(angle < 0 || angle > 180){
	
		return;
	}
	
	pulseWidth = 5+angle/9;
	
  setServoPulseWidth(pulseWidth);
}

int8 servoDetach()
{
  pinMode_common(G_ServoCfg.pin, OUTPUT);
	G_ServoCfg.pin = NOT_ATTACHED;
  return 0;
}

int32 servoAttachedPin()
{ 
  return G_ServoCfg.pin; 
  
}

int16 servoAttached()
{ 
  return G_ServoCfg.pin != NOT_ATTACHED; 
}

int8 servoAttach(uint8 pin, uint16 minPulseWidth, uint16 maxPulseWidth, int16 minAngle, int16 maxAngle)
{
	if(servoAttached()){
	
		//return 0;
	}
	
  G_ServoCfg.pin = pin;
  G_ServoCfg.minPW = minPulseWidth;
  G_ServoCfg.maxPW = maxPulseWidth;
  G_ServoCfg.minAngle = minAngle;
  G_ServoCfg.maxAngle = maxAngle;
  pinMode_common(pin, PWM);
	registTimerCbFun(TIMER_0, ServoPwmInterruptProc);
	timerxStart(TIMER_0);
	return 0;
}

void ServoDefaultInit()
{
	if(servoAttached()){
	
		//return;
	}
	
  G_ServoCfg.pin = SERVO_CTL_PIN;
  G_ServoCfg.minPW = SERVO_DEFAULT_MIN_PW;
  G_ServoCfg.maxPW = SERVO_DEFAULT_MAX_PW;
  G_ServoCfg.minAngle = SERVO_DEFAULT_MIN_ANGLE;
  G_ServoCfg.maxAngle = SERVO_DEFAULT_MAX_ANGLE;
  pinMode_common(G_ServoCfg.pin, PWM);
	registTimerCbFun(TIMER_0, ServoPwmInterruptProc);
	timerxStart(TIMER_0);
}
