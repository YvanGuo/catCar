
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
#include "hal/timer.h"
#include "hal/pinCtl.h"
#include "driver/51/hw_timer.h"
#include "driver/51/hw_serial.h"
#include <stdio.h>

static uint16 G_ServoPulCnt = 0;
static uint16 G_ServoPulseWidth = 15;
static uint8 G_ServoCtlPin = 0;

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


void ServoPwmInterruptProc(TIME_X timerx)
{
	#if 1
	static u32 timeCnt = 0;
	timeCnt++;

	if(timeCnt > 10000){
	
		//digitalWrite_common(G_ServoCtlPin, LOW);
		
	}else{
	
		//digitalWrite_common(G_ServoCtlPin, HIGH);
	}
	
	if(timeCnt > 20000){
	
		timeCnt = 0;
	}
	
	#endif
	
	//printf("%d,%d,%d\r\n", (short)G_ServoPulseWidth, (short)G_ServoPulCnt, (unsigned int)timeCnt);
	if(G_ServoPulCnt <= G_ServoPulseWidth){
	
		digitalWrite_common(G_ServoCtlPin, HIGH);
		//PrintString1("H\r\n");
	}else{
	
		digitalWrite_common(G_ServoCtlPin, LOW);
		//PrintString1("L\r\n");
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