#include "key.h"

KEY_STRUCT KEY = { {0},{0},OK };
//������ʼ������
void KEY_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO , ENABLE);//ʹ��GPIOAʱ��
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2 , ENABLE);  //ʹ��TIM2ʱ��
	  //=================GPIO��ʼ��==================
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15; //KKEY1 KEY2 KEY3 KEY4��Ӧ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//��ͨ����ģʽ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50M
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIO
	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIO
	  //=================TIM2��ʼ��==================
	TIM_TimeBaseInitStructure.TIM_Period = 2000 - 1; 	//�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler = 1000 - 1;  //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);//��ʼ��TIM2
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); //����ʱ��2�����ж�
	TIM_Cmd(TIM2, ENABLE); //ʹ�ܶ�ʱ��2
		//=================TIM2 �жϳ�ʼ��==================
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; //��ʱ��2�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x03; //��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00; //�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
} 
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) //����ж�
	{
		if (KEY.KEY_STATUS == OK)
		{
			(!KEY1) ? (KEY.NEW[0] = 1) : (KEY.NEW[0] = 0);//�������Ŷ�ȡֵ��״̬������ֵ
			(!KEY2) ? (KEY.NEW[1] = 1) : (KEY.NEW[1] = 0);
			(!KEY3) ? (KEY.NEW[2] = 1) : (KEY.NEW[2] = 0);
			(!KEY4) ? (KEY.NEW[3] = 1) : (KEY.NEW[3] = 0);
			KEY.KEY_STATUS = UPDAT;
		}
	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);  //����жϱ�־λ
} 
u8 KEY_Task(void)
{
	if (KEY.KEY_STATUS == UPDAT)
	{
		KEY.KEY_STATUS = BUSY;
		/****************************key1*****************************/
		if (KEY.NEW[0] && (!KEY.OLD[0]))
		{
			/***********************���°���****************************/
			for (u8 i = 0; i < 4; i++)//����״̬
			KEY.OLD[i] = KEY.NEW[i];
			KEY.KEY_STATUS = OK;
			return 1;
		}
		/****************************key2*****************************/
		if (KEY.NEW[1] && (!KEY.OLD[1]))
		{
			for (u8 i = 0; i < 4; i++)//����״̬
			KEY.OLD[i] = KEY.NEW[i];
			KEY.KEY_STATUS = OK;
			return 2;
		}
		/****************************key3*****************************/
		if (KEY.NEW[2] && (!KEY.OLD[2]))
		{
			for (u8 i = 0; i < 4; i++)//����״̬
			KEY.OLD[i] = KEY.NEW[i];
			KEY.KEY_STATUS = OK;
			return 3;
		}
		/****************************WK_UP �ԼӺ���*****************************/
		if (KEY.NEW[3] && (!KEY.OLD[3]))
		{
			for (u8 i = 0; i < 4; i++)//����״̬
			KEY.OLD[i] = KEY.NEW[i];
			KEY.KEY_STATUS = OK;
			return 4;
		}
	}
for (u8 i = 0; i < 4; i++)//����״̬
KEY.OLD[i] = KEY.NEW[i];
KEY.KEY_STATUS = OK;
return 0;	
}








