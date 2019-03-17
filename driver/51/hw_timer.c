
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
#include <stdio.h>

void HW_Time0Start()
{
	//TR0 = 1;
	Timer0_Run();
	Timer0_InterruptEnable();
}

void HW_Time0Reload()
{
	//TR0 = 0;
	Timer0_Stop();
	TH0 = 0xff;
	TL0 = 0xa4;
}

void HW_Time1Start()
{
	//TR0 = 1;
	Timer1_Run();
	Timer1_InterruptEnable();
}

void HW_Time1Reload()
{
	//TR0 = 0;
	Timer1_Stop();
	TH1 = 0xff;
	TL1 = 0xa4;
}

#if 0

void HW_TimexStart(TIME_X timerx)
{
	switch(timerx){
		case TIMER_0:{
		
			TR0 = 1;
			break;
		}
		case TIMER_1:{
			
			TR1 = 1;
			break;
		}
		case TIMER_2:{
		
			TR2 = 1;
			break;
		}
		case TIMER_3:{
		
			TR3 = 1;
			break;
		}
		case TIMER_4:{
		
			TR4 = 1;
			break;
		}
	}
	
}

void HW_TimexReload(TIME_X timerx)
{

	
	switch(timerx){
		case TIMER_0:{
		
			TR0 = 0;
			TH0 = 0xff;
			TL0 = 0xa4;
			break;
		}
		case TIMER_1:{
			
			TR1 = 1;
			TH1 = 0xff;
			TL1 = 0xa4;
			break;
		}
		case TIMER_2:{
		
			TR2 = 1;
			TH2 = 0xff;
			TL2 = 0xa4;
			break;
		}
		case TIMER_3:{
		
			TR3 = 1;
			TH3 = 0xff;
			TL3 = 0xa4;
			break;
		}
		case TIMER_4:{
		
			TR4 = 0;
			TH4 = 0xff;
			TL4 = 0xa4;
			break;
		}
	}
}
#endif


void Time0_Int() interrupt TIMER0_VECTOR
{

	if(timerCbFunQueEmpty()){
	
		 // queue empty
		 //return;
	}
	printf("in Time0_Int tttt \r\n");
	timerCbFunExce(TIMER_0);
	

}

void Time1_Int() interrupt TIMER1_VECTOR
{

	if(timerCbFunQueEmpty()){
	
		 // queue empty
		 return;
	}
	
	printf("in Time1_Int tttt \r\n");
	timerCbFunExce(TIMER_1);
	

}

void Time2_Int() interrupt TIMER2_VECTOR
{

	if(timerCbFunQueEmpty()){
	
		 // queue empty
		 return;
	}
	
	timerCbFunExce(TIMER_2);
	

}

void Time3_Int() interrupt TIMER3_VECTOR
{

	if(timerCbFunQueEmpty()){
	
		 // queue empty
		 return;
	}
	
	timerCbFunExce(TIMER_3);
	

}

void Time4_Int() interrupt TIMER4_VECTOR
{

	if(timerCbFunQueEmpty()){
	
		 // queue empty
		 return;
	}
	
	timerCbFunExce(TIMER_4);
	

}