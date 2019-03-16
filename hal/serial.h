#ifndef __SERIA_H__
#define __SERIA_H__
#include "common.h"


typedef enum{

	SERIA_0 = 0,
	SERIA_1,
	MAX_SERIA_NUM
}SERIA_X;

typedef struct s_SeriaParam{
    int8 pin_tx;
    int8 pin_rx;
    int32 baudrate;
    int8 flowCtl;
    int8 stopBit;
    int8 verify;
}s_SeriaParam;

typedef void(*serialEvnCbFun_t)(void *);


static s_SeriaParam G_SeriasCfg[MAX_SERIA_NUM];

int8 initSeriaX(SERIA_X seriaIndex, s_SeriaParam *param);
int8 uninitSeriaX(SERIA_X seriaIndex);

int32 serialRead(SERIA_X index, int8 *buff, int32 readSize, int32 timeOut);
int32 serialWrite(SERIA_X index, int8 *buff, int32 writeSize, int32 timeOut);

#endif
