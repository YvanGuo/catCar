#ifndef __GPIO_CTL_51__
#define __GPIO_CTL_51__


#include	"common.h"
#include  "hal/pinCtl.h"

void	HW_GPIO_config(uint8 pin, PIN_MODE mode);
void  HW_GPIO_digitalWrite(uint8 pin, int32 val);
uint8 HW_GPIO_digitalRead(uint8 pin);

#endif
