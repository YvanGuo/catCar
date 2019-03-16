
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

/*************	功能说明	**************

本文件为STC8xxx系列的端口初始化程序,用户几乎可以不修改这个程序.


******************************************/

#include "hw_pwm.h"
#include "hal/pinCtl.h"

static uint16 G_ServoPulCnt = 0;
static uint16 G_ServoPulseWidth = 15;
static uint16 G_ServoCtlPin = 0;

void resetServoPulCnt()
{
	G_ServoPulCnt = 0;
}

void setServoPulseWidth(uint16 cnt)
{
	G_ServoPulseWidth = cnt;
}

void setServoCtlPin(uint8 pin)
{
	G_ServoCtlPin = pin;
}


void ServoPwmInterruptProc()
{

	if(G_ServoPulCnt <= G_ServoPulseWidth){
	
		digitalWrite_common(G_ServoCtlPin, HIGH);
	}else{
	
		digitalWrite_common(G_ServoCtlPin, LOW);
	}
	
	G_ServoPulCnt++;
	if(G_ServoPulCnt >= 200){
	
			G_ServoPulCnt = 0;
	}

	
}


void uartCmdProc(void *uartData)
{
	static uint8 servoPulseWidth = 15;
	uint8 *command = (uint8 *)uartData;
	
	switch(*command){
	
		case 'f':
		{
				servoPulseWidth++;
				if(servoPulseWidth >= 25){
				
					servoPulseWidth = 25;
					setServoPulseWidth(servoPulseWidth);
				}
				resetServoPulCnt();
				break;
		}
		case 'g':
		{
				servoPulseWidth--;
				if(servoPulseWidth <= 5){
				
					servoPulseWidth = 5;
					setServoPulseWidth(servoPulseWidth);
				}
				resetServoPulCnt();
				break;
		}
		case 'k':
		{
				servoPulseWidth = 15;
				setServoPulseWidth(servoPulseWidth);
				resetServoPulCnt();
				break;
		}
		default:
		{
				break;
		}
	}
	
}