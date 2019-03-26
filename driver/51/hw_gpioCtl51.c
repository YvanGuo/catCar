
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

#include "hw_gpioCtl51.h"

typedef struct GPIO_InitTypeDef
{
	uint8	Pin;				//要设置的端口		Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
	uint8	Mode;				//IO模式,  4个选1,	GPIO_PullUp(准双向口),GPIO_HighZ(高阻输入),GPIO_OUT_OD(开漏模式),GPIO_OUT_PP(推挽输出)
	uint8	PullUp_3K7;			//内部上拉3.7K电阻, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
	uint8	SchmittDisable;		//禁止施密特输入, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
} GPIO_InitTypeDef;


//========================================================================
// 函数: u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx)
// 描述: 初始化IO口, 将IO设置为准双向口、推挽输出、开漏输出、高阻输入这4种模式之一, 并可以允许内部额外的3.7K上拉电阻.
// 参数:  GPIO: 要初始化的IO, 取值GPIO_P0 ~ GPIO_P7.
//       GPIOx: 结构体指针,请参考GPIO.h里的定义.
// 返回: 成功返回0, 错误返回1.
// 版本: V1.0, 2018-3-22
//========================================================================
static uint8	GPIO_Inilize(uint8 GPIO, GPIO_InitTypeDef *GPIOx)
{
	if((GPIO > GPIO_P7) || (GPIOx->Mode > GPIO_OUT_PP))		return 1;	//错误

	#ifdef STC8XXXX
	EAXSFR();	//访问扩展SFR(XSFR)
	#endif
	if(GPIO == GPIO_P0)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P0M1 &= ~GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P0M1 |=  GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P0M1 |=  GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P0M1 &= ~GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //推挽输出
		#ifdef STC8XXXX
		P0PU  = GPIOx->PullUp_3K7;		//内部上拉3.7K电阻, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		P0NCS = GPIOx->SchmittDisable;	//禁止施密特输入, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		#endif
	}
	if(GPIO == GPIO_P1)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P1M1 &= ~GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P1M1 |=  GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P1M1 |=  GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P1M1 &= ~GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //推挽输出
		#ifdef STC8XXXX
		P1PU  = GPIOx->PullUp_3K7;		//内部上拉3.7K电阻, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		P1NCS = GPIOx->SchmittDisable;	//禁止施密特输入, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		#endif
	}
	if(GPIO == GPIO_P2)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P2M1 &= ~GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P2M1 |=  GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P2M1 |=  GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P2M1 &= ~GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //推挽输出
		#ifdef STC8XXXX
		P2PU  = GPIOx->PullUp_3K7;		//内部上拉3.7K电阻, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		P2NCS = GPIOx->SchmittDisable;	//禁止施密特输入, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		#endif
	}
	if(GPIO == GPIO_P3)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P3M1 &= ~GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P3M1 |=  GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P3M1 |=  GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P3M1 &= ~GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //推挽输出
		#ifdef STC8XXXX
		P3PU  = GPIOx->PullUp_3K7;		//内部上拉3.7K电阻, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		P3NCS = GPIOx->SchmittDisable;	//禁止施密特输入, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		#endif
	}
	if(GPIO == GPIO_P4)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P4M1 &= ~GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P4M1 |=  GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P4M1 |=  GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P4M1 &= ~GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //推挽输出
		#ifdef STC8XXXX
		P4PU  = GPIOx->PullUp_3K7;		//内部上拉3.7K电阻, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		P4NCS = GPIOx->SchmittDisable;	//禁止施密特输入, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		#endif
	}
	if(GPIO == GPIO_P5)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P5M1 &= ~GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P5M1 |=  GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P5M1 |=  GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P5M1 &= ~GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //推挽输出
		#ifdef STC8XXXX
		P5PU  = GPIOx->PullUp_3K7;		//内部上拉3.7K电阻, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		P5NCS = GPIOx->SchmittDisable;	//禁止施密特输入, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		#endif
	}
	if(GPIO == GPIO_P6)
	{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
		if(GPIOx->Mode == GPIO_PullUp)		P6M1 &= ~GPIOx->Pin,	P6M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P6M1 |=  GPIOx->Pin,	P6M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P6M1 |=  GPIOx->Pin,	P6M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P6M1 &= ~GPIOx->Pin,	P6M0 |=  GPIOx->Pin;	 //推挽输出
		#ifdef STC8XXXX
		P6PU  = GPIOx->PullUp_3K7;		//内部上拉3.7K电阻, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		P6NCS = GPIOx->SchmittDisable;	//禁止施密特输入, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		#endif
	} 
	if(GPIO == GPIO_P7)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P7M1 &= ~GPIOx->Pin,	P7M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P7M1 |=  GPIOx->Pin,	P7M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P7M1 |=  GPIOx->Pin,	P7M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P7M1 &= ~GPIOx->Pin,	P7M0 |=  GPIOx->Pin;	 //推挽输出
		#ifdef STC8XXXX
		P7PU  = GPIOx->PullUp_3K7;		//内部上拉3.7K电阻, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		P7NCS = GPIOx->SchmittDisable;	//禁止施密特输入, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
		#endif
	}
	
	#ifdef STC8XXXX
	EAXRAM();	//访问扩展RAM(XRAM)
	#endif
	return 0;	//成功
}

void HW_GPIO_config(uint8 pin, PIN_MODE mode)
{
	GPIO_InitTypeDef	GPIO_InitStructure;				//结构定义
	pin  = 1 << pin%8;
	GPIO_InitStructure.Pin            = pin;	//指定要设置的端口		Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
	GPIO_InitStructure.PullUp_3K7     = 0;				//内部上拉3.7K电阻, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
	GPIO_InitStructure.SchmittDisable = 0;				//禁止施密特输入, Pin0~Pin7或PinAll, 多个项用或操作, 比如 Pin0 | Pin3
	
	switch(mode){
		case OUTPUT:{
		
			GPIO_InitStructure.Mode = GPIO_OUT_PP;	//指定IO的模式, 4个选1, GPIO_PullUp(准双向口),GPIO_HighZ(高阻输入),GPIO_OUT_OD(开漏模式),GPIO_OUT_PP(推挽输出)
			break;
		}
		case INPUT:{
		
			GPIO_InitStructure.Mode = GPIO_HighZ;
			break;
		}
		case INPUT_PULLUP:{
		
			GPIO_InitStructure.Mode = GPIO_PullUp;
			GPIO_InitStructure.PullUp_3K7 = pin%8;
			break;
		}
		case PWM:{
		
			GPIO_InitStructure.Mode = GPIO_OUT_PP;
			break;
		}
		default:
			GPIO_InitStructure.Mode = GPIO_OUT_PP;
			break;
	}
	
	
	GPIO_Inilize(pin/8,&GPIO_InitStructure);	//初始化

}

void HW_GPIO_digitalWrite(uint8 pin, int32 val)
{
	uint8 gpioGruop = pin/8;
	unsigned char gpioGruopPinBit = 1;
	gpioGruopPinBit = gpioGruopPinBit<<pin%8;
	switch(gpioGruop){
	
		case 0:{
		
				if(LOW == val){
				
					P0 &= ~gpioGruopPinBit;
				}else{
				
					P0 |= gpioGruopPinBit;
				}
				
				break;
		}
		case 1:{
		
				if(LOW == val){
				
					P1 &= ~gpioGruopPinBit;
				}else{
				
					P1 |= gpioGruopPinBit;
				}
				break;
		}
		case 2:{
		
				if(LOW == val){
				
					P2 &= ~gpioGruopPinBit;
				}else{
				
					P2 |= gpioGruopPinBit;
				}
				break;
		}
		case 3:{
		
				if(LOW == val){
				
					P3 &= ~gpioGruopPinBit;
				}else{
				
					P3 |= gpioGruopPinBit;
				}
				break;
		}
		case 4:{
		
				if(LOW == val){
				
					P4 &= ~gpioGruopPinBit;
				}else{
				
					P4 |= gpioGruopPinBit;
				}
				break;
		}
		case 5:{
		
				if(LOW == val){
				
					P5 &= ~gpioGruopPinBit;
				}else{
				
					P5 |= gpioGruopPinBit;
				}
				break;
		}
		case 6:{
		
				if(LOW == val){
				
					P6 &= ~gpioGruopPinBit;
				}else{
				
					P6 |= gpioGruopPinBit;
				}
				break;
		}
		case 7:{
		
				if(LOW == val){
				
					P7 &= ~gpioGruopPinBit;
				}else{
				
					P7 |= gpioGruopPinBit;
				}
				break;
		}
		
		default:
			break;
	}

}

uint8 HW_GPIO_digitalRead(uint8 pin)
{
	uint8 retVal = 0;
	uint8 gpioGruop = pin/8;
	unsigned char gpioGruopPinBit = 1;
	gpioGruopPinBit = gpioGruopPinBit<<pin%8;
	
	
	switch(gpioGruop){
	
		case 0:{
				P0 |= gpioGruopPinBit;  // 读取前先使能内部弱上拉电阻
				_nop_();  // 等待两个时钟
				_nop_();  //
				retVal = P0;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 1:{
				P1 |= gpioGruopPinBit;  // 读取前先使能内部弱上拉电阻
				_nop_();  // 等待两个时钟
				_nop_();  //
				retVal = P1;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 2:{
				P2 |= gpioGruopPinBit;  // 读取前先使能内部弱上拉电阻
				_nop_();  // 等待两个时钟
				_nop_();  //
				retVal = P2;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 3:{
				P3 |= gpioGruopPinBit;  // 读取前先使能内部弱上拉电阻
				_nop_();  // 等待两个时钟
				_nop_();  //
				retVal = P3;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 4:{
				P4 |= gpioGruopPinBit;  // 读取前先使能内部弱上拉电阻
				_nop_();  // 等待两个时钟
				_nop_();  //
				retVal = P4;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 5:{
				P6 |= gpioGruopPinBit;  // 读取前先使能内部弱上拉电阻
				_nop_();  // 等待两个时钟
				_nop_();  //
				retVal = P5;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 6:{
				P6 |= gpioGruopPinBit;  // 读取前先使能内部弱上拉电阻
				_nop_();  // 等待两个时钟
				_nop_();  //
				retVal = P6;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 7:{
				P7 |= gpioGruopPinBit;  // 读取前先使能内部弱上拉电阻
				_nop_();  // 等待两个时钟
				_nop_();  //
				retVal = P7;
				retVal &= gpioGruopPinBit;
				break;
		}
		
		default:
			break;
	}
	
	return retVal;

}