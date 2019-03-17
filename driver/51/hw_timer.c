
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
#include  "hal/pinCtl.h"

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

本文件为STC15xxx系列的定时器初始化和中断程序,用户可以在这个文件中修改自己需要的中断程序.


******************************************/
typedef struct
{
	uint8	TIM_Mode;		//工作模式,  	TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	uint8	TIM_Polity;		//优先级设置	PolityHigh,PolityLow
	uint8	TIM_Interrupt;	//中断允许		ENABLE,DISABLE
	uint8	TIM_ClkSource;	//时钟源		TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	uint8	TIM_ClkOut;		//可编程时钟输出,	ENABLE,DISABLE
	uint16	TIM_Value;		//装载初值
	uint8	TIM_Run;		//是否运行		ENABLE,DISABLE
} TIM_InitTypeDef;


/********************* Timer0中断函数************************/
void Time0_Int() interrupt TIMER0_VECTOR
{

	//printf("in Time0_Int tttt \r\n");
	//ServoPwmInterruptProc(0);
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


//========================================================================
// 函数: u8	Timer_Inilize(u8 TIM, TIM_InitTypeDef *TIMx)
// 描述: 定时器初始化程序.
// 参数: TIMx: 结构参数,请参考timer.h里的定义.
// 返回: 成功返回0, 空操作返回1,错误返回2.
// 版本: V1.0, 2012-10-22
//========================================================================
uint8	Timer_Inilize(TIME_X TIM, TIM_InitTypeDef *TIMx)
{
	if(TIM > TIMER_2)	return 5;	//空操作

	if(TIM == TIMER_0)
	{
		TR0 = 0;		//停止计数
		if(TIMx->TIM_Interrupt == ENABLE)		ET0 = 1;	//允许中断
		else									ET0 = 0;	//禁止中断
		if(TIMx->TIM_Polity == PolityHigh)		PT0 = 1;	//高优先级中断
		else									PT0 = 0;	//低优先级中断
		if(TIMx->TIM_Mode >  TIM_16BitAutoReloadNoMask)	return 2;	//错误
		TMOD = (TMOD & ~0x03) | TIMx->TIM_Mode;	//工作模式,0: 16位自动重装, 1: 16位定时/计数, 2: 8位自动重装, 3: 16位自动重装, 不可屏蔽中断
		if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	AUXR &= ~0x80;	//12T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		AUXR |=  0x80;	//1T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	TMOD |=  0x04;	//对外计数或分频
		else										TMOD &= ~0x04;	//定时
		if(TIMx->TIM_ClkOut == ENABLE)	INT_CLKO |=  0x01;	//输出时钟
		else							INT_CLKO &= ~0x01;	//不输出时钟
		
		TH0 = (u8)(TIMx->TIM_Value >> 8);
		TL0 = (u8)TIMx->TIM_Value;
		if(TIMx->TIM_Run == ENABLE)	TR0 = 1;	//开始运行
		return	0;		//成功
	}

	if(TIM == TIMER_1)
	{
		TR1 = 0;		//停止计数
		if(TIMx->TIM_Interrupt == ENABLE)		ET1 = 1;	//允许中断
		else									ET1 = 0;	//禁止中断
		if(TIMx->TIM_Polity == PolityHigh)		PT1 = 1;	//高优先级中断
		else									PT1 = 0;	//低优先级中断
		if(TIMx->TIM_Mode >= TIM_16BitAutoReloadNoMask)	return 2;	//错误
		TMOD = (TMOD & ~0x30) | TIMx->TIM_Mode;	//工作模式,0: 16位自动重装, 1: 16位定时/计数, 2: 8位自动重装
		if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	AUXR &= ~0x40;	//12T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		AUXR |=  0x40;	//1T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	TMOD |=  0x40;	//对外计数或分频
		else										TMOD &= ~0x40;	//定时
		if(TIMx->TIM_ClkOut == ENABLE)	INT_CLKO |=  0x02;	//输出时钟
		else							INT_CLKO &= ~0x02;	//不输出时钟
		
		TH1 = (u8)(TIMx->TIM_Value >> 8);
		TL1 = (u8)TIMx->TIM_Value;
		if(TIMx->TIM_Run == ENABLE)	TR1 = 1;	//开始运行
		return	0;		//成功
	}

	if(TIM == TIMER_2)		//Timer2,固定为16位自动重装, 中断无优先级
	{
		AUXR &= ~(1<<4);	//停止计数
		if(TIMx->TIM_Interrupt == ENABLE)			IE2  |=  (1<<2);	//允许中断
		else										IE2  &= ~(1<<2);	//禁止中断
		if(TIMx->TIM_ClkSource >  TIM_CLOCK_Ext)	return 2;
		if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	AUXR &= ~(1<<2);	//12T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		AUXR |=  (1<<2);	//1T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	AUXR |=  (1<<3);	//对外计数或分频
		else										AUXR &= ~(1<<3);	//定时
		if(TIMx->TIM_ClkOut == ENABLE)	INT_CLKO |=  0x04;	//输出时钟
		else							INT_CLKO &= ~0x04;	//不输出时钟

		TH2 = (u8)(TIMx->TIM_Value >> 8);
		TL2 = (u8)TIMx->TIM_Value;
		if(TIMx->TIM_Run == ENABLE)	AUXR |=  (1<<4);	//开始运行
		return	0;		//成功
	}
	return 2;	//错误
}

/************************ 定时器配置 ****************************/
uint8 HW_Timer_config(TIME_X timerx, uint32 preCnt)
{
	TIM_InitTypeDef		TIM_InitStructure;					//结构定义
	uint8 ret = 2;
	#if 0
	TIM_InitStructure.TIM_Mode      = TIM_16BitAutoReload;	//指定工作模式,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	TIM_InitStructure.TIM_Polity    = PolityLow;			//指定中断优先级, PolityHigh,PolityLow
	TIM_InitStructure.TIM_Interrupt = ENABLE;				//中断是否允许,   ENABLE或DISABLE
	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;			//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	TIM_InitStructure.TIM_ClkOut    = ENABLE;				//是否输出高速脉冲, ENABLE或DISABLE
	TIM_InitStructure.TIM_Value     = 65536UL - (MAIN_Fosc / (50*12));		//初值,
	TIM_InitStructure.TIM_Run       = ENABLE;				//是否初始化后启动定时器, ENABLE或DISABLE
	ret = Timer_Inilize(TIMER_0,&TIM_InitStructure);				//初始化Timer0	  Timer0,Timer1,Timer2
	#endif
	
	#if 1
	TIM_InitStructure.TIM_Mode      = TIM_16BitAutoReload;	//指定工作模式,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	TIM_InitStructure.TIM_Polity    = PolityLow;			//指定中断优先级, PolityHigh,PolityLow
	TIM_InitStructure.TIM_Interrupt = ENABLE;				//中断是否允许,   ENABLE或DISABLE
	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_1T;			//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	TIM_InitStructure.TIM_ClkOut    = ENABLE;				//是否输出高速脉冲, ENABLE或DISABLE
	TIM_InitStructure.TIM_Value     = 65536UL - (MAIN_Fosc / 10000UL);		//初值,
	TIM_InitStructure.TIM_Run       = ENABLE;				//是否初始化后启动定时器, ENABLE或DISABLE
	ret = Timer_Inilize(TIMER_0,&TIM_InitStructure);				//初始化Timer0	  Timer0,Timer1,Timer2
	#endif
	
	#if 0
	TIM_InitStructure.TIM_Mode      = TIM_16BitAutoReloadNoMask;	//指定工作模式,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	TIM_InitStructure.TIM_Polity    = PolityLow;			//指定中断优先级, PolityHigh,PolityLow
	TIM_InitStructure.TIM_Interrupt = ENABLE;				//中断是否允许,   ENABLE或DISABLE
	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_1T;			//指定时钟源, TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	TIM_InitStructure.TIM_ClkOut    = ENABLE;				//是否输出高速脉冲, ENABLE或DISABLE
	TIM_InitStructure.TIM_Value     = 65536UL - (MAIN_Fosc / 1000UL);	//初值,
	TIM_InitStructure.TIM_Run       = ENABLE;				//是否初始化后启动定时器, ENABLE或DISABLE
	ret = Timer_Inilize(TIMER_1,&TIM_InitStructure);				//初始化Timer1	  Timer0,Timer1,Timer2
	#endif

	#if 0
	TIM_InitStructure.TIM_Interrupt = ENABLE;				//中断是否允许,   ENABLE或DISABLE. (注意: Timer2固定为16位自动重装, 中断固定为低优先级)
	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;		//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	TIM_InitStructure.TIM_ClkOut    = ENABLE;				//是否输出高速脉冲, ENABLE或DISABLE
	TIM_InitStructure.TIM_Value     = 65536UL - (MAIN_Fosc / (50*12));		//初值
	TIM_InitStructure.TIM_Run       = ENABLE;				//是否初始化后启动定时器, ENABLE或DISABLE
	ret = Timer_Inilize(TIMER_2,&TIM_InitStructure);				//初始化Timer2	  Timer0,Timer1,Timer2
	#endif
	return ret;
	
}