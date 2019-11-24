#include "LED.h"



void LED_Init(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure;
	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO,ENABLE);//ʹ��PORTC�����ù���ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				 //LED
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13;//HW
 	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIOC13
	
	GPIO_SetBits(GPIOA,GPIO_Pin_8);						 //PB.5 �����
	GPIO_SetBits(GPIOC,GPIO_Pin_13);						 //PB.5 �����
}

