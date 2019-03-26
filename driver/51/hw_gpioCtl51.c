
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

/*************	����˵��	**************

���ļ�ΪSTC8xxxϵ�еĶ˿ڳ�ʼ������,�û��������Բ��޸��������.


******************************************/

#include "hw_gpioCtl51.h"

typedef struct GPIO_InitTypeDef
{
	uint8	Pin;				//Ҫ���õĶ˿�		Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
	uint8	Mode;				//IOģʽ,  4��ѡ1,	GPIO_PullUp(׼˫���),GPIO_HighZ(��������),GPIO_OUT_OD(��©ģʽ),GPIO_OUT_PP(�������)
	uint8	PullUp_3K7;			//�ڲ�����3.7K����, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
	uint8	SchmittDisable;		//��ֹʩ��������, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
} GPIO_InitTypeDef;


//========================================================================
// ����: u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx)
// ����: ��ʼ��IO��, ��IO����Ϊ׼˫��ڡ������������©���������������4��ģʽ֮һ, �����������ڲ������3.7K��������.
// ����:  GPIO: Ҫ��ʼ����IO, ȡֵGPIO_P0 ~ GPIO_P7.
//       GPIOx: �ṹ��ָ��,��ο�GPIO.h��Ķ���.
// ����: �ɹ�����0, ���󷵻�1.
// �汾: V1.0, 2018-3-22
//========================================================================
static uint8	GPIO_Inilize(uint8 GPIO, GPIO_InitTypeDef *GPIOx)
{
	if((GPIO > GPIO_P7) || (GPIOx->Mode > GPIO_OUT_PP))		return 1;	//����

	#ifdef STC8XXXX
	EAXSFR();	//������չSFR(XSFR)
	#endif
	if(GPIO == GPIO_P0)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P0M1 &= ~GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P0M1 |=  GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P0M1 |=  GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P0M1 &= ~GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //�������
		#ifdef STC8XXXX
		P0PU  = GPIOx->PullUp_3K7;		//�ڲ�����3.7K����, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		P0NCS = GPIOx->SchmittDisable;	//��ֹʩ��������, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		#endif
	}
	if(GPIO == GPIO_P1)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P1M1 &= ~GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P1M1 |=  GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P1M1 |=  GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P1M1 &= ~GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //�������
		#ifdef STC8XXXX
		P1PU  = GPIOx->PullUp_3K7;		//�ڲ�����3.7K����, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		P1NCS = GPIOx->SchmittDisable;	//��ֹʩ��������, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		#endif
	}
	if(GPIO == GPIO_P2)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P2M1 &= ~GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P2M1 |=  GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P2M1 |=  GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P2M1 &= ~GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //�������
		#ifdef STC8XXXX
		P2PU  = GPIOx->PullUp_3K7;		//�ڲ�����3.7K����, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		P2NCS = GPIOx->SchmittDisable;	//��ֹʩ��������, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		#endif
	}
	if(GPIO == GPIO_P3)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P3M1 &= ~GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P3M1 |=  GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P3M1 |=  GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P3M1 &= ~GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //�������
		#ifdef STC8XXXX
		P3PU  = GPIOx->PullUp_3K7;		//�ڲ�����3.7K����, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		P3NCS = GPIOx->SchmittDisable;	//��ֹʩ��������, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		#endif
	}
	if(GPIO == GPIO_P4)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P4M1 &= ~GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P4M1 |=  GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P4M1 |=  GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P4M1 &= ~GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //�������
		#ifdef STC8XXXX
		P4PU  = GPIOx->PullUp_3K7;		//�ڲ�����3.7K����, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		P4NCS = GPIOx->SchmittDisable;	//��ֹʩ��������, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		#endif
	}
	if(GPIO == GPIO_P5)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P5M1 &= ~GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P5M1 |=  GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P5M1 |=  GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P5M1 &= ~GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //�������
		#ifdef STC8XXXX
		P5PU  = GPIOx->PullUp_3K7;		//�ڲ�����3.7K����, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		P5NCS = GPIOx->SchmittDisable;	//��ֹʩ��������, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		#endif
	}
	if(GPIO == GPIO_P6)
	{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
		if(GPIOx->Mode == GPIO_PullUp)		P6M1 &= ~GPIOx->Pin,	P6M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P6M1 |=  GPIOx->Pin,	P6M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P6M1 |=  GPIOx->Pin,	P6M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P6M1 &= ~GPIOx->Pin,	P6M0 |=  GPIOx->Pin;	 //�������
		#ifdef STC8XXXX
		P6PU  = GPIOx->PullUp_3K7;		//�ڲ�����3.7K����, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		P6NCS = GPIOx->SchmittDisable;	//��ֹʩ��������, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		#endif
	} 
	if(GPIO == GPIO_P7)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P7M1 &= ~GPIOx->Pin,	P7M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P7M1 |=  GPIOx->Pin,	P7M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P7M1 |=  GPIOx->Pin,	P7M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P7M1 &= ~GPIOx->Pin,	P7M0 |=  GPIOx->Pin;	 //�������
		#ifdef STC8XXXX
		P7PU  = GPIOx->PullUp_3K7;		//�ڲ�����3.7K����, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		P7NCS = GPIOx->SchmittDisable;	//��ֹʩ��������, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
		#endif
	}
	
	#ifdef STC8XXXX
	EAXRAM();	//������չRAM(XRAM)
	#endif
	return 0;	//�ɹ�
}

void HW_GPIO_config(uint8 pin, PIN_MODE mode)
{
	GPIO_InitTypeDef	GPIO_InitStructure;				//�ṹ����
	pin  = 1 << pin%8;
	GPIO_InitStructure.Pin            = pin;	//ָ��Ҫ���õĶ˿�		Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
	GPIO_InitStructure.PullUp_3K7     = 0;				//�ڲ�����3.7K����, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
	GPIO_InitStructure.SchmittDisable = 0;				//��ֹʩ��������, Pin0~Pin7��PinAll, ������û����, ���� Pin0 | Pin3
	
	switch(mode){
		case OUTPUT:{
		
			GPIO_InitStructure.Mode = GPIO_OUT_PP;	//ָ��IO��ģʽ, 4��ѡ1, GPIO_PullUp(׼˫���),GPIO_HighZ(��������),GPIO_OUT_OD(��©ģʽ),GPIO_OUT_PP(�������)
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
	
	
	GPIO_Inilize(pin/8,&GPIO_InitStructure);	//��ʼ��

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
				P0 |= gpioGruopPinBit;  // ��ȡǰ��ʹ���ڲ�����������
				_nop_();  // �ȴ�����ʱ��
				_nop_();  //
				retVal = P0;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 1:{
				P1 |= gpioGruopPinBit;  // ��ȡǰ��ʹ���ڲ�����������
				_nop_();  // �ȴ�����ʱ��
				_nop_();  //
				retVal = P1;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 2:{
				P2 |= gpioGruopPinBit;  // ��ȡǰ��ʹ���ڲ�����������
				_nop_();  // �ȴ�����ʱ��
				_nop_();  //
				retVal = P2;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 3:{
				P3 |= gpioGruopPinBit;  // ��ȡǰ��ʹ���ڲ�����������
				_nop_();  // �ȴ�����ʱ��
				_nop_();  //
				retVal = P3;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 4:{
				P4 |= gpioGruopPinBit;  // ��ȡǰ��ʹ���ڲ�����������
				_nop_();  // �ȴ�����ʱ��
				_nop_();  //
				retVal = P4;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 5:{
				P6 |= gpioGruopPinBit;  // ��ȡǰ��ʹ���ڲ�����������
				_nop_();  // �ȴ�����ʱ��
				_nop_();  //
				retVal = P5;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 6:{
				P6 |= gpioGruopPinBit;  // ��ȡǰ��ʹ���ڲ�����������
				_nop_();  // �ȴ�����ʱ��
				_nop_();  //
				retVal = P6;
				retVal &= gpioGruopPinBit;
				break;
		}
		case 7:{
				P7 |= gpioGruopPinBit;  // ��ȡǰ��ʹ���ڲ�����������
				_nop_();  // �ȴ�����ʱ��
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