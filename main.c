
/*------------------------------------------------------------------*/
/* --- STC MCU International Limited -------------------------------*/
/* --- STC 1T Series MCU RC Demo -----------------------------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ---------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ---------------------*/
/* --- Web: www.GXWMCU.com -----------------------------------------*/
/* --- QQ:  800003751 ----------------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/

#include	<stdio.h>
#include	"common.h"
#include  "driver/51/hw_gpioCtl51.h"
#include	"core/51/delay.h"
#include  "hal/pinCtl.h"
#include  "hal/servoCommon.h"
#include  "hal/serial.h"
#include  "hal/timer.h"
#include  "driver/51/hw_serial.h"
#include  "driver/51/hw_timer.h"

/******************** Ö÷º¯Êý **************************/
void main(void)
{
	uint16 angle = 90;
	uint8 ret = 0;
	uint8	i;

	HW_serialConfig(USART1, 115200ul);
	pinMode_common(LED_CTL_PIN, OUTPUT); 
	ServoDefaultInit();
	EA = 1;
	
	#if 0
	pinMode_common(MOTOR_LEFT_PIN_LEFT, OUTPUT);
	pinMode_common(MOTOR_LEFT_PIN_RIGHT, OUTPUT);
	pinMode_common(MOTOR_RIGHT_PIN_LEFT, OUTPUT);
	pinMode_common(MOTOR_RIGHT_PIN_RIGHT, OUTPUT);
	
	pinMode_common(LEFT_IR_PIN, INPUT);
	pinMode_common(RIGHT_IR_PIN, INPUT);
	#endif
	
	servoWrite(angle);
	while(1)
	{
		
		//digitalRead_common(LEFT_IR_PIN);
		//digitalRead_common(RIGHT_IR_PIN);
		//printf("hello catsssssss !!!!\r\n");
		
		angle = (90+36)%180;
		servoWrite(angle);
		delay_ms(250);
		angle = (90-36)%180;
		servoWrite(angle);
		delay_ms(250);

	}
}




