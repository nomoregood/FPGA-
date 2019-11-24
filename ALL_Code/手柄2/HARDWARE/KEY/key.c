//#include "stm32f10x.h"
//#include "key.h"
//#include "sys.h" 
//#include "delay.h"
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
//								    
////������ʼ������
//void KEY_Init(void) //IO��ʼ��
//{ 
// 	GPIO_InitTypeDef GPIO_InitStructure;
// 
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//ʹ��PORTA,PORTEʱ��

//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_3;//KEY0-KEY1
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
// 	GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE4,3

//	//��ʼ�� WK_UP-->GPIOA.0	  ��������
//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0���ó����룬Ĭ������	  
//	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.0

//}
////����������
////���ذ���ֵ
////mode:0,��֧��������;1,֧��������;
////0��û���κΰ�������
////1��KEY0����
////2��KEY1����
////3��KEY3���� WK_UP
////ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY_UP!!
//u8 KEY_Scan(u8 mode)
//{	 
//	static u8 key_up=1;//�������ɿ���־
//	if(mode)key_up=1;  //֧������		  
//	if(key_up&&(KEY0==0||KEY1==0||WK_UP==1))
//	{
//		delay_ms(10);//ȥ���� 
//		key_up=0;
//		if(KEY0==0)return KEY0_PRES;
//		else if(KEY1==0)return KEY1_PRES;
//		else if(WK_UP==1)return WKUP_PRES;
//	}else if(KEY0==1&&KEY1==1&&WK_UP==0)key_up=1; 	    
// 	return 0;// �ް�������
//}


#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"
#include "led.h"
#include "usart.h"	
#include "beep.h"
//����IO��ʼ������
void KEY_Init(void) //IO��ʼ��
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��PORTBʱ��

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //����Ϊ��������
	
	//K1---PB12
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//K2---PB14
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_14;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K3---PB8
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K4---PB7
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K5---PB11
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K6---PB5
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K7---PB15
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_15;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K8---PB4
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K9---PB13
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//K10---PB6
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//K11---PB9
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//K12---PB10
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10; 
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	

}


////�����жϳ�ʼ������
//void EXTIX_Init(void)
//{
// 
//		EXTI_InitTypeDef EXTI_InitStructure;
//		NVIC_InitTypeDef NVIC_InitStructure;

//    KEY_Init();	 //�����˿ڳ�ʼ��

//  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��

	
	
////�ж��ߵ����ã��ж��ߺ�IO��ӳ��		
//	  //K11---PD12
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource12);		//???D????12��?GPIOD???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line12;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��

//		//K12---PD15
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource15);		//???D????15��?GPIOD???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line15;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//	
//		//K13---PA0
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);		//???D????0��?GPIOA???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		
//		//K14---PA1
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource1);		//???D????0��?GPIOA???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line1;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		
//		//K15---PD14
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource14);		//???D????14��?GPIOD???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line14;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		
//		//K16---PD13
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource13);		//???D????13��?GPIOD???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line13;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		
//		//K17---PD9
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource9);		//???D????9��?GPIOD???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line9;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		
//		//K18---PD10
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource10);		//???D????10��?GPIOD???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line10;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		
//		//K19---PD11
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource11);		//???D????11��?GPIOD???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line11;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		
//		//K20---PA3
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource3);		//???D????3��?GPIOA???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line3;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		
//		//K21---PA5
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource5);		//???D????5��?GPIOA???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line5;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		
//		//K22---PA7
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource7);		//???D????7��?GPIOA???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line7;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		
//		//K23---PA4
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource4);		//???D????4��?GPIOA???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line4;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		
//		//K24---PA2
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource2);		//???D????2��?GPIOA???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line2;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		
//		//KL---PE8
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource8);		//???D????8��?GPIOE???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line8;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		
//		//KR---PA6
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource6);		//???D????6��?GPIOA???����3��??e����
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line6;	//?D????����o?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???�꨺?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???��??�䣤����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//��1?��?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?��?YEXTI_InitStruct?D???����?2?��y3?��??����a����EXTI??��??��
//		

////?D??��??��??����??o����1?��?D??

//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//?��??��??��??2��? 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//������??��??3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//��1?����a2??D??�����̨�
//  	NVIC_Init(&NVIC_InitStructure); 
//		
//		NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//?��??��??��??2��? 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//������??��??3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//��1?����a2??D??�����̨�
//  	NVIC_Init(&NVIC_InitStructure); 
//		
//		NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//?��??��??��??2��? 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//������??��??3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//��1?����a2??D??�����̨�
//  	NVIC_Init(&NVIC_InitStructure); 
//		
//		NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//?��??��??��??2��? 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//������??��??3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//��1?����a2??D??�����̨�
//  	NVIC_Init(&NVIC_InitStructure); 
//		
//		NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//?��??��??��??2��? 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//������??��??3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//��1?����a2??D??�����̨�
//  	NVIC_Init(&NVIC_InitStructure); 
//		
//		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//?��??��??��??2��? 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//������??��??3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//��1?����a2??D??�����̨�
//  	NVIC_Init(&NVIC_InitStructure); 

//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//?��??��??��??2 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//������??��??1 
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//��1?����a2??D??�����̨�
//  	NVIC_Init(&NVIC_InitStructure);  	  //?��?YNVIC_InitStruct?D???����?2?��y3?��??����a����NVIC??��??��


//}




// 
////��a2??D??0��t??3��D��
//void EXTI0_IRQHandler(void)
//{
//	delay_ms(100);//????
//	if(KEY13==0)	  
//	{
//			LED4=!LED4;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x13);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line0);  //??3yLINE0��?��??D??����????  
//}

////��a2??D??1��t??3��D��
//void EXTI1_IRQHandler(void)
//{
//	delay_ms(100);//????
//	if(KEY14==0)	  
//	{
//			LED4=!LED4;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x14);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line1);  //??3yLINE1��?��??D??����????  
//}

////��a2??D??2��t??3��D��
//void EXTI2_IRQHandler(void)
//{
//	delay_ms(100);//????
//	if(KEY24==0)	  
//	{
//			LED3=!LED3;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x24);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line2);  //??3yLINE2��?��??D??����????  
//}

////��a2??D??3��t??3��D��
//void EXTI3_IRQHandler(void)
//{
//	delay_ms(100);//????
//	if(KEY20==0)	  
//	{
//			LED3=!LED3;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x20);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line3);  //??3yLINE3��?��??D??����????  
//}

////��a2??D??4��t??3��D��
//void EXTI4_IRQHandler(void)
//{
//	delay_ms(100);//????
//	if(KEY23==0)	  
//	{
//			LED2=!LED2;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x23);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line4);  //??3yLINE4��?��??D??����????  
//}


////��a2??D??5-9��t??3��D��
//void EXTI9_5_IRQHandler(void)
//{
//	delay_ms(100);//????
//	
//	if(KEY21==0)	  
//	{
//			LED3=!LED3;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x21);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line5);
//	
//	
//	if(KEYR==0)	  
//	{
////			LED2=!LED2;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x26);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line6);
//	
//	
//	if(KEY22==0)	  
//	{
//			LED3=!LED3;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x22);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line7);
//	
//	
//	if(KEYL==0)	  
//	{
////			LED2=!LED2;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x25);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line8);
//	
//	
//	if(KEY17==0)	  
//	{
//			LED5=!LED5;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x17);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line9);
//	
//}



////��a2??D??5-9��t??3��D��
//void EXTI15_10_IRQHandler(void)
//{
//	delay_ms(100);//????
//	
//	if(KEY18==0)	  
//	{
//			LED5=!LED5;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x18);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line10);
//	
//	
//	if(KEY19==0)	  
//	{
//			LED5=!LED5;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x19);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line11);
//	
//	
//	if(KEY11==0)	  
//	{
//			LED5=!LED5;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x11);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line12);
//	
//	
//	if(KEY16==0)	  
//	{
//			LED5=!LED5;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x16);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line13);
//	
//	
//	if(KEY15==0)	  
//	{
//			LED4=!LED4;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x15);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line14);
//	
//		
//	if(KEY12==0)	  
//	{
//			LED4=!LED4;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x12);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line15);
//	
//}






//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;

//0��û���κΰ�������
//1��KEY1����
//2��KEY2����
//3��KEY3����
//...
//ע��˺�������Ӧ���ȼ�,KEY1>KEY2>KEY3...!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������		  
	if(key_up&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0||KEY5==0||KEY6==0||KEY7==0||KEY8==0||KEY9==0||KEY10==0||KEY11==0||KEY12==0))
	{
		delay_ms(100);//ȥ���� 
		key_up=0;
		if(KEY1==0)return 1;
		else if(KEY2==0)return 2;
		else if(KEY3==0)return 3;
		else if(KEY4==0)return 4;
		else if(KEY5==0)return 5;
		else if(KEY6==0)return 6;
		else if(KEY7==0)return 7;
		else if(KEY8==0)return 8;
		else if(KEY9==0)return 9;
		else if(KEY10==0)return 10;
		else if(KEY11==0)return 11;
		else if(KEY12==0)return 12;
	}else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1&&KEY5==1&&KEY6==1&&KEY7==1&&KEY8==1&&KEY9==1&&KEY10==1&&KEY11==1&&KEY12==1)key_up=1; 	    
	
 	return 0;//�ް�������
}

