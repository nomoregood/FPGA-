//#ifndef __KEY_H
//#define __KEY_H	 
//#include "sys.h"
////////////////////////////////////////////////////////////////////////////////////	 
////������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
////ALIENTEK��ӢSTM32������
////������������	   
////����ԭ��@ALIENTEK
////������̳:www.openedv.com
////�޸�����:2012/9/3
////�汾��V1.0
////��Ȩ���У�����ؾ���
////Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
////All rights reserved									  
////////////////////////////////////////////////////////////////////////////////////   	 


////#define KEY0 PEin(4)   	//PE4
////#define KEY1 PEin(3)	//PE3 
////#define WK_UP PAin(0)	//PA0  WK_UP

//#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)//��ȡ����0
//#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//��ȡ����1
//#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//��ȡ����3(WK_UP) 

// 

//#define KEY0_PRES 	1	//KEY0����
//#define KEY1_PRES	  2	//KEY1����
//#define WKUP_PRES   3	//KEY_UP����(��WK_UP/KEY_UP)


//void KEY_Init(void);//IO��ʼ��
//u8 KEY_Scan(u8);  	//����ɨ�躯��					    
//#endif
#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"

#define KEY1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)
#define KEY2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)
#define KEY3 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)
#define KEY4 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)
#define KEY5 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)
#define KEY6 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)
#define KEY7 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)
#define KEY8 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)
#define KEY9 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)
#define KEY10 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)

#define KEY11  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)
#define KEY12  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)

 

void EXTIX_Init(void);//�ⲿ�жϳ�ʼ��		 		
void KEY_Init(void);//IO3��ʼ��
u8 KEY_Scan(u8 mode);//����ɨ�躯��

//u8 KEY_Scan(u8);  	//���?������?��o����y					    
#endif
