
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
#include "hal/timer.h"
#include "hw_timer.h"
#include "hw_pwm.h"


void Time0Reload()
{

	TR0 = 0;
	TH0 = 0xff;
	TL0 = 0xa4;

}

void Time0Start()
{

	TR0 = 1;
}

void Time0_Int() interrupt 1
{

	if(timerCbFunQueEmpty()){
	
		 // queue empty
		 return;
	}
	
	timerCbFunExce(TIMER_0);
	

}

void Time1_Int() interrupt 3
{

	if(timerCbFunQueEmpty()){
	
		 // queue empty
		 return;
	}
	
	timerCbFunExce(TIMER_1);
	

}

void Time2_Int() interrupt 12
{

	if(timerCbFunQueEmpty()){
	
		 // queue empty
		 return;
	}
	
	timerCbFunExce(TIMER_2);
	

}

void Time3_Int() interrupt 19
{

	if(timerCbFunQueEmpty()){
	
		 // queue empty
		 return;
	}
	
	timerCbFunExce(TIMER_3);
	

}

void Time4_Int() interrupt 20
{

	if(timerCbFunQueEmpty()){
	
		 // queue empty
		 return;
	}
	
	timerCbFunExce(TIMER_4);
	

}