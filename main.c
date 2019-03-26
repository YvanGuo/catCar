
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

#include	<stdio.h>
#include	"common.h"
#include  "driver/51/hw_gpioCtl51.h"
#include	"core/51/delay.h"
#include  "hal/pinCtl.h"
#include  "hal/servoCommon.h"
#include  "hal/serial.h"
#include  "hal/timer.h"
#include  "driver/51/hw_serial.h"
#include  "driver/51/hw_timer.h"


void tailAct(uint8 mode)
{

	servoWrite(mode);

}

void setup()
{

	HW_serialConfig(USART1, 115200ul);
	
	ServoDefaultInit();
	EA = 1;
	
	servoWrite(90);

	pinMode_common(MOTOR_LEFT_PIN_LEFT, OUTPUT);
	pinMode_common(MOTOR_LEFT_PIN_RIGHT, OUTPUT);
	pinMode_common(MOTOR_RIGHT_PIN_LEFT, OUTPUT);
	pinMode_common(MOTOR_RIGHT_PIN_RIGHT, OUTPUT);

	pinMode_common(LEFT_IR_PIN, INPUT_PULLUP);
	pinMode_common(RIGHT_IR_PIN, INPUT_PULLUP);
 
}


#if 1
/******************** 主函数 **************************/
void main(void)
{
	
	uint8 leftIrStatus = 0;
	uint8 rightIrStatus = 0;
	uint8 uartData[10] = {0};
	uint8 i = 0;

	setup();
	tailAct(90);
	
	while(1)
	{
		
		while (1)
		{
			delay_ms(250);

			leftIrStatus = digitalRead_common(LEFT_IR_PIN);
			rightIrStatus = digitalRead_common(RIGHT_IR_PIN);
			TX1_write2buff(leftIrStatus + '0');
			TX1_write2buff(',');
			TX1_write2buff(rightIrStatus+ '0');
			TX1_write2buff(',');
			continue;
			
			if(COM1.RX_TimeOut > 0)		//超时计数
			{
				if(--COM1.RX_TimeOut == 0)
				{
					if(COM1.RX_Cnt > 0)
					{
						for(i=0; i<COM1.RX_Cnt; i++){
					
							
							//TX1_write2buff(RX1_Buffer[i]);	//收到的数据原样返回
						}	
						
						if(RX1_Buffer[0] < 0 || RX1_Buffer[0] > 180){
						
						}else{
						
							tailAct(RX1_Buffer[0]);
							HW_GPIO_digitalWrite(MOTOR_LEFT_PIN_LEFT, RX1_Buffer[0]);
							HW_GPIO_digitalWrite(MOTOR_LEFT_PIN_RIGHT, RX1_Buffer[0]);
							HW_GPIO_digitalWrite(MOTOR_RIGHT_PIN_LEFT, RX1_Buffer[0]);
							HW_GPIO_digitalWrite(MOTOR_RIGHT_PIN_LEFT, RX1_Buffer[0]);
						}
						
					}
					COM1.RX_Cnt = 0;
				}
			}
		}
		
	}
}
#endif

#if 0
/******************** 初始化函数 **************************/
void setup(void) _task_ 0
{
	

	HW_serialConfig(USART1, 115200ul);
	pinMode_common(LED_CTL_PIN, OUTPUT); 
	ServoDefaultInit();
	EA = 1;
	
#if 0
	pinMode_common(MOTOR_LEFT_PIN_LEFT, OUTPUT);
	pinMode_common(MOTOR_LEFT_PIN_RIGHT, OUTPUT);
	pinMode_common(MOTOR_RIGHT_PIN_LEFT, OUTPUT);
	pinMode_common(MOTOR_RIGHT_PIN_RIGHT, OUTPUT);
#endif
	
	pinMode_common(LEFT_IR_PIN, INPUT_PULLUP);
	pinMode_common(RIGHT_IR_PIN, INPUT_PULLUP);

	
	
	
	os_create_task(1); 	//create thread_TailAction 
	os_create_task(2);	//create thread_CarRun
	os_delete_task(0);
}

void thread_TailAction() _task_ 1
{
	uint16 angle = 90;
	servoWrite(angle);
	
	while(1)
	{
		
		angle = (90+36)%180;
		servoWrite(angle);
		delay_ms(250);
		angle = (90-36)%180;
		servoWrite(angle);
		delay_ms(250);

	}
}


void thread_CarRun() _task_ 2
{
	uint8 leftIrStatus = 0;
	uint8 rightIrStatus = 0;
	
	while(1)
	{
		
		leftIrStatus = digitalRead_common(LEFT_IR_PIN);
		rightIrStatus = digitalRead_common(RIGHT_IR_PIN);
		delay_ms(250);
		printf("rightIrStatus = %d, leftIrStatus = %d\r\n",rightIrStatus, leftIrStatus);
	
	}
}
#endif
