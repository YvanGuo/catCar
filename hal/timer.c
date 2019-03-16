
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
#include "timer.h"
#include "hw_timer.h"
#include "pwm.h"

static uint8 G_ServoEnable = 0;
#define MAX_TIMER_CB_FUN (6)

typedef enum{

	NOR = 0
	
}TIMER_EVENT;

typedef struct s_timerCbFunCfg{
	
	uint8 timerx;
	timerEvnCbFun_t timerxEvnCbFun;
	
}s_timerCbFunCfg;

typedef struct s_timerCbFunQue{
	
	uint8 head;
	uint8 tail;
	
}s_timerCbFunQue;

static s_timerCbFunQue G_timerCbFunQue = {0, MAX_TIMER_CB_FUN-1};

s_timerCbFunCfg G_timerEvnCbFuns[MAX_TIMER_CB_FUN] = {{0,NULL}, {0,NULL}, {0,NULL}, {0,NULL}, {0,NULL}};

int8 timerCbFunQueEmpty()
{
	if((G_timerCbFunQue.head+1)%MAX_TIMER_CB_FUN == G_timerCbFunQue.tail){
	
		 // queue empty
		 return 1;
		
	}else{
		
		 return 0;
	}
}

int8 timerCbFunQueFull()
{
	if((G_timerCbFunQue.tail+1)%MAX_TIMER_CB_FUN == G_timerCbFunQue.head){
	
		 // queue full
		 return 1;
		
	}else{
		
		 return 0;
	}
}

int8 timerCbFunExce(TIME_X timerx)
{
	uint8 head = G_timerCbFunQue.head;
	timerEvnCbFun_t timerxEvnCbFun;
	
	if(timerCbFunQueEmpty()){
	
		 // queue full
		 return -1;
		
	}
	
	while((head+1)%MAX_TIMER_CB_FUN != G_timerCbFunQue.tail){
	
			if(timerx == G_timerEvnCbFuns[head].timerx){
			
				timerxEvnCbFun = G_timerEvnCbFuns[head].timerxEvnCbFun;
				timerxEvnCbFun();
			}
			
			head++;
		
	}
	
	return 0;
}

int8 registTimerCbFun(TIME_X timerx, timerEvnCbFun_t cb)
{
	if(timerCbFunQueFull()){
	
		 // queue full
		 return -1;
	}
	
	G_timerCbFunQue.tail = (G_timerCbFunQue.tail+1)%MAX_TIMER_CB_FUN;
	G_timerEvnCbFuns[G_timerCbFunQue.tail].timerx = timerx;
	G_timerEvnCbFuns[G_timerCbFunQue.tail].timerxEvnCbFun = cb;
	return G_timerCbFunQue.tail;
}

int8 unregistTimerCbFun(int8 cb_FunID)
{

	if(timerCbFunQueEmpty()){
	
		 // queue empty
		 return -1;
	}
	
	G_timerEvnCbFuns[cb_FunID].timerx = 0;
	G_timerEvnCbFuns[cb_FunID].timerxEvnCbFun = NULL;
	
}
