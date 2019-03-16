
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

#include "hw_serial.h"
#include "hw_pwm.h"

/*串口初始化、定时器T0、T1初始化*/
void Com_Init()
{

	IP = 0x08;
	PCON &= 0x7F;
	TMOD &= 0x00;
	TMOD |= 0x21;
	SCON = 0x50;
	TH1 = 0xfd;
	TL1 = 0xfd;
	ES = 1;
	ET1 = 0;
	TR1 = 1;
	
	TH0 = 0xff;
	TL0 = 0xa4;
	
	ET0 = 1;
	TR0 = 1;
}

void uart_ser() interrupt 4
{
	uint8 command = 0;
	
	if(0 == RI){
	
		return;
	}

	ES = 0;
	RI = 0;
	command = SBUF;
	

}