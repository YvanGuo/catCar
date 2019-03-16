
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


#include	"common.h"
#include  "driver/51/gpioCtl51.h"
#include	"core/51/delay.h"
#include  "hal/pinCtl.h"

/*************	功能说明	**************

本程序演示跑马灯。
程序使用P2、P6、P7口来演示，输出低驱动。用户可以修改为别的口。

******************************************/


/******************** 主函数 **************************/
void main(void)
{
	
	pinMode_common(MOTOR_LEFT_PIN_LEFT, OUTPUT);
	pinMode_common(MOTOR_LEFT_PIN_RIGHT, OUTPUT);
	pinMode_common(MOTOR_RIGHT_PIN_LEFT, OUTPUT);
	pinMode_common(MOTOR_RIGHT_PIN_RIGHT, OUTPUT);
	
	pinMode_common(LEFT_IR_PIN, INPUT);
	pinMode_common(RIGHT_IR_PIN, INPUT);
	
	while(1)
	{
		
		digitalRead_common(LEFT_IR_PIN);
		digitalRead_common(RIGHT_IR_PIN);
	}
}




