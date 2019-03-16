
#include "pinCtl.h"
#include "driver/51/hw_gpioCtl51.h"
//#ifndef ARDUINO_LIB 

int32 pinMode_common(uint8 pin, PIN_MODE mode)
{
  if(mode < 0){
      return -1;
  }
	HW_GPIO_config(pin, mode);
}

void analogWrite_common(uint8 pin, int32 val)
{
    pinMode_common(pin, OUTPUT);
    if (val == 0){
        digitalWrite_common(pin, LOW);
    }
     //...
}

void digitalWrite_common(uint8 pin, int32 val)
{
  
  HW_GPIO_digitalWrite(pin, val);
}

uint8 digitalRead_common(uint8 pin)
{
	
  return HW_GPIO_digitalRead(pin);
  
}
//#endif
