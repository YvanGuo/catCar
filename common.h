#ifndef __COMMON_H__
#define __COMMON_H__
#include "boardConfig.h"

#ifndef ARDUINO_LIB 
typedef int int32;
typedef unsigned int uint32;
typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;

#else
  #include<inttypes.h>
#endif

#ifdef STC8XXXX
/*********************************************************/


//#define MAIN_Fosc		22118400L	//定义主时钟
//#define MAIN_Fosc		12000000L	//定义主时钟
//#define MAIN_Fosc		11059200L	//定义主时钟
//#define MAIN_Fosc		 5529600L	//定义主时钟

/*********************************************************/
//#include <reg51.h>
#define MAIN_Fosc		24000000L	//定义主时钟

#include	"boards/51/STC8xxxx/STC8xxxx.H"


/////////////////// pin config ///////////////
#define	GPIO_PullUp		0	//上拉准双向口
#define	GPIO_HighZ		1	//浮空输入
#define	GPIO_OUT_OD		2	//开漏输出
#define	GPIO_OUT_PP		3	//推挽输出

#define	GPIO_Pin_0		0x01	//IO引脚 Px.0
#define	GPIO_Pin_1		0x02	//IO引脚 Px.1
#define	GPIO_Pin_2		0x04	//IO引脚 Px.2
#define	GPIO_Pin_3		0x08	//IO引脚 Px.3
#define	GPIO_Pin_4		0x10	//IO引脚 Px.4
#define	GPIO_Pin_5		0x20	//IO引脚 Px.5
#define	GPIO_Pin_6		0x40	//IO引脚 Px.6
#define	GPIO_Pin_7		0x80	//IO引脚 Px.7
#define	GPIO_Pin_All	0xFF	//IO所有引脚

#define	GPIO_P0			0		//
#define	GPIO_P1			1
#define	GPIO_P2			2
#define	GPIO_P3			3
#define	GPIO_P4			4
#define	GPIO_P5			5
#define	GPIO_P6			6
#define	GPIO_P7			7

/*
	本软件51单片机GPIO定义规则
	例子：如果定义LED控制的GPIO为 P1.1
	则LED的引脚在本软件中应该定义为 1x8+1 = 9
	#define LED_PIN (9)
	pinMode_common(LED_PIN, OUTPUT);
	digitalWrite_common(LED_PIN, HIGH);
*/
#define MOTOR_LEFT_PIN_LEFT 1
#define MOTOR_LEFT_PIN_RIGHT 2
#define MOTOR_RIGHT_PIN_LEFT 3
#define MOTOR_RIGHT_PIN_RIGHT 4

#define LEFT_IR_PIN 5
#define RIGHT_IR_PIN 6

#define SERVO_CTL_PIN 7

#define LED_CTL_PIN 8
//--------------------------------------------

#endif

#ifdef STC15XXXX

#define   MAIN_Fosc	  22118400L

#include	"boards/51/STC15xxxx/STC15Fxxxx.H"

/////////////////// pin config ///////////////
#define	GPIO_PullUp		0	//上拉准双向口
#define	GPIO_HighZ		1	//浮空输入
#define	GPIO_OUT_OD		2	//开漏输出
#define	GPIO_OUT_PP		3	//推挽输出

#define	GPIO_Pin_0		0x01	//IO引脚 Px.0
#define	GPIO_Pin_1		0x02	//IO引脚 Px.1
#define	GPIO_Pin_2		0x04	//IO引脚 Px.2
#define	GPIO_Pin_3		0x08	//IO引脚 Px.3
#define	GPIO_Pin_4		0x10	//IO引脚 Px.4
#define	GPIO_Pin_5		0x20	//IO引脚 Px.5
#define	GPIO_Pin_6		0x40	//IO引脚 Px.6
#define	GPIO_Pin_7		0x80	//IO引脚 Px.7
#define	GPIO_Pin_All	0xFF	//IO所有引脚

#define	GPIO_P0			0		//
#define	GPIO_P1			1
#define	GPIO_P2			2
#define	GPIO_P3			3
#define	GPIO_P4			4
#define	GPIO_P5			5
#define	GPIO_P6			6
#define	GPIO_P7			7

/*
	本软件51单片机GPIO定义规则
	例子：如果定义LED控制的GPIO为 P1.1
	则LED的引脚在本软件中应该定义为 1x8+1 = 9
	#define LED_PIN (9)
	pinMode_common(LED_PIN, OUTPUT);
	digitalWrite_common(LED_PIN, HIGH);
*/
#define MOTOR_LEFT_PIN_LEFT 1
#define MOTOR_LEFT_PIN_RIGHT 2
#define MOTOR_RIGHT_PIN_LEFT 3
#define MOTOR_RIGHT_PIN_RIGHT 4

#define LEFT_IR_PIN 5
#define RIGHT_IR_PIN 6

#define SERVO_CTL_PIN 8

#define LED_CTL_PIN 8
//--------------------------------------------

#else

/////////////////// pin config ///////////////
#define MOTOR_LEFT_PIN_LEFT 1
#define MOTOR_LEFT_PIN_RIGHT 2
#define MOTOR_RIGHT_PIN_LEFT 3
#define MOTOR_RIGHT_PIN_RIGHT 4

#define LEFT_IR_PIN 5
#define RIGHT_IR_PIN 6

#define SERVO_CTL_PIN 7
//--------------------------------------------
#endif

#define NULL (0)

#endif
