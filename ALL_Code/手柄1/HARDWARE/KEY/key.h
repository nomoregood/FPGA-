#ifndef __KEY_H
#define __KEY_H	 
#include "MY_Struct.h"
/*����ķ�ʽ��ͨ��ֱ�Ӳ����⺯����ʽ��ȡIO*/
//#define KEY0 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) //PE4
//#define KEY1 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)	//PE3 
//#define KEY2 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2) //PE2
//#define WK_UP 	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)	//PA0
/*���淽ʽ��ͨ��λ��������ʽ��ȡIO*/
#define KEY1 		PCin(15)		//PC15
#define KEY_LD  KEY1

#define KEY2 		PBin(14)		//PB14
#define KEY_RD  KEY2
#define KEY3 		PCin(14)		//PC14
#define KEY_LU  KEY3
#define KEY4 		PBin(15)		//PB15
#define KEY_RU  KEY4
//#define KEY0_PRES 	1
//#define KEY1_PRES	2
//#define KEY2_PRES	3
//#define WKUP_PRES   4
typedef struct
{
	u8 NEW[4];								//������ֵ
	u8 OLD[4];								//	������ֵ
	TASK_STATUS KEY_STATUS;				//	��������״̬
}KEY_STRUCT;
void KEY_Init(void);	//IO��ʼ��
u8 KEY_Task(void);//����ִ�к���
extern KEY_STRUCT KEY;
#endif
