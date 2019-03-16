#include "common.h"
#include "ir.h"
#include "pinCtl.h"

static s_IRParam G_IRParam;

int8 initIR(s_IRParam *param)
{
  int i=0;
  
  if(!param){
     return -1;
  }
  
  if(param->IRNum >= MAX_IR_NUM){
     return -1;
  }
  
  G_IRParam.IRNum = param->IRNum;

  for(i=0; i<param->IRNum; i++)
  {
      pinMode_common(param->Ir[i].Ir_pin, INPUT);
      G_IRParam.Ir[i].Ir_pin = param->Ir[i].Ir_pin;
  }
  return 0;
}

int8 getIRStartus(IRS ir)
{
    return digitalRead_common(G_IRParam.Ir[ir].Ir_pin);
}
