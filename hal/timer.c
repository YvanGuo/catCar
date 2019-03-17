
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
#include  "timer.h"
#include  "driver/51/hw_timer.h"
#include  "driver/51/hw_pwm.h"
#include  "hal/pinCtl.h"

static uint8 G_ServoEnable = 0;
#define MAX_TIMER_CB_FUN (6)

typedef enum{

	NOR = 0
	
}TIMER_EVENT;

typedef struct s_timerCbFunCfg{
	
	TIME_X timerx;
	uint32 timeCnt;
	uint32 timeoutExc;
	timerEvnCbFun_t timerxEvnCbFun;
	
}s_timerCbFunCfg;

typedef struct s_timerCbFunQue{
	
	uint8 head;
	uint8 tail;
	
}s_timerCbFunQue;

static s_timerCbFunQue G_timerCbFunQue = {0, 0};

s_timerCbFunCfg G_timerEvnCbFuns[MAX_TIMER_CB_FUN] = {{0,1,NULL}, {0,1,NULL}, {0,1,NULL}, {0,1,NULL}, {0,1,NULL}};

int8 timerCbFunQueEmpty()
{
	if((G_timerCbFunQue.head)%MAX_TIMER_CB_FUN == G_timerCbFunQue.tail){
	
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
	timerEvnCbFun_t timerxEvnCbFun = NULL;
	
	
	if(timerCbFunQueEmpty()){
	
		 // queue full
		 return -1;
		
	}
	
	while((head)%MAX_TIMER_CB_FUN != G_timerCbFunQue.tail){
	
			if(timerx == G_timerEvnCbFuns[head].timerx){

				G_timerEvnCbFuns[head].timeCnt++;
				if(G_timerEvnCbFuns[head].timeCnt >= G_timerEvnCbFuns[G_timerCbFunQue.tail].timeoutExc){
				
						timerxEvnCbFun = G_timerEvnCbFuns[head].timerxEvnCbFun;
						if(NULL != timerxEvnCbFun){
							
								
							  timerxEvnCbFun(timerx);
						}
						
						G_timerEvnCbFuns[head].timeCnt = 0;
				}
				
			}
			
			head++;
		
	}
	
	return 0;
}

int8 registTimerCbFun(TIME_X timerx, uint32 timeoutExc, timerEvnCbFun_t cb)
{
	int8 queID = 0;
	if(timerCbFunQueFull()){
	
		 // queue full
		 //return -1;
		 
	}
	
	queID = G_timerCbFunQue.tail;
	G_timerEvnCbFuns[G_timerCbFunQue.tail].timerx = timerx;
	G_timerEvnCbFuns[G_timerCbFunQue.tail].timeoutExc = timeoutExc;
	G_timerEvnCbFuns[G_timerCbFunQue.tail].timeCnt = 0;
	G_timerEvnCbFuns[G_timerCbFunQue.tail].timerxEvnCbFun = cb;
	G_timerCbFunQue.tail = (G_timerCbFunQue.tail+1)%MAX_TIMER_CB_FUN;
	
	return queID;
}

int8 unregistTimerCbFun(int8 cb_FunID)
{

	if(timerCbFunQueEmpty()){
	
		 // queue empty
		 return -1;
	}
	
	G_timerEvnCbFuns[cb_FunID].timerx = 0;
	G_timerEvnCbFuns[cb_FunID].timerxEvnCbFun = NULL;
	G_timerCbFunQue.head = (G_timerCbFunQue.head+1)%MAX_TIMER_CB_FUN;
	return 0;
}

uint8 timerRegist(TIME_X timerx, uint32 timeoutExc, timerEvnCbFun_t cb)
{
	
	HW_Timer_config(timerx, 1);
	registTimerCbFun(timerx, timeoutExc, cb);
	return 0;
}

void timerxStart(TIME_X timerx)
{
	if(TIMER_0 == timerx){
	
		HW_Time0Reload();
		HW_Time0Start();
	}
	else if(TIMER_1 == timerx)
	{
		HW_Time1Reload();
		HW_Time1Start();
	}
	
}

void timerxReload(TIME_X timerx)
{
	if(TIMER_0 == timerx){
	
		HW_Time0Reload();
		
	}
	else if(TIMER_1 == timerx)
	{
		HW_Time1Reload();
	
	}
}