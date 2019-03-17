#include "serial.h"

#define MAX_SERIAL_CB_FUN (3)

typedef struct s_serialCbFunCfg{
	
	uint8 serialx;
	serialEvnCbFun_t serialxEvnCbFun;
	
}s_serialCbFunCfg;

typedef struct s_serialCbFunQue{
	
	uint8 head;
	uint8 tail;
	
}s_serialCbFunQue;

static s_serialCbFunQue G_serialCbFunQue = {0, MAX_SERIAL_CB_FUN-1};

s_serialCbFunCfg G_serialEvnCbFuns[MAX_SERIAL_CB_FUN] = {{0,NULL}, {0,NULL}, {0,NULL}};


int8 registSerialCbFun(uint8 serialx, serialEvnCbFun_t cb)
{
	if((G_serialCbFunQue.tail+1)%MAX_SERIAL_CB_FUN == G_serialCbFunQue.head){
	
		 // queue full
		 return -1;
	}
	
	G_serialCbFunQue.tail = (G_serialCbFunQue.tail+1)%MAX_SERIAL_CB_FUN;
	G_serialEvnCbFuns[G_serialCbFunQue.tail].serialx = serialx;
	G_serialEvnCbFuns[G_serialCbFunQue.tail].serialxEvnCbFun = cb;
	return G_serialCbFunQue.tail;
}

int8 unregistSerialCbFun(int8 cb_FunID)
{

	if((G_serialCbFunQue.head+1)%MAX_SERIAL_CB_FUN == G_serialCbFunQue.tail){
	
		 // queue empty
		 return -1;
	}
	
	G_serialEvnCbFuns[cb_FunID].serialx = 0;
	G_serialEvnCbFuns[cb_FunID].serialxEvnCbFun = NULL;
	return 0;
}

int8 initSeriaX(SERIA_X seriaIndex, s_SeriaParam *param)
{
	return 0;
}

int8 uninitSeriaX(SERIA_X seriaIndex)
{

	return 0;
}

int32 serialRead(SERIA_X index, int8 *buff, int32 readSize, int32 timeOut)
{

	return 0;
}

int32 serialWrite(SERIA_X index, int8 *buff, int32 writeSize, int32 timeOut)
{

	return 0;
}