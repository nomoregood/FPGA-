#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "LED.h"
#include "adc.h"
#include "24l01.h"
#include "key.h"

u16 t=0;

int main(void)
{
	u8 key;
	
	u8 tmp_buf;
	
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();			//��ʼ��OLED      
	Adc_Init();	 //ADC��ʼ��
	KEY_Init();
	NRF24L01_Init();
	while(NRF24L01_Check())
 	{
		LED1=0;LED2=0;
		delay_ms(200);
		LED1=1;LED2=1;
 		delay_ms(200);
	}
	NRF24L01_TX_Mode();

	while(1)
	{
		LED1 = 1;
		LED2 = 1;
		key=KEY_Task();
		if(key==0)
		{

		}
		if(key==1)  //KEY_LD
		{
//			NRF24L01_RX_Mode();		  
//			while(1)
//			{	  		    		    				 
//				if(NRF24L01_RxPacket(tmp_buf)==0)//һ�����յ���Ϣ,����ʾ����.
//					{
//						LED1=1;LED2=1;
//					}
//				else 
//					{
//						LED1=0;LED2=0;
//					}
//				delay_us(100);	   			    
//			}
				tmp_buf = '1';
				if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
				{
					LED1 = 0;
					LED2 = 0;
					delay_ms(300);
					LED1 = 1;
					LED2 = 1;
					key = 0;
				}
			
		}
		else if(key==2)    //KEY_RD
		{
//			NRF24L01_TX_Mode();
//			mode=' ';//�ӿո����ʼ  
			tmp_buf = '2';
			if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
			{
				LED1 = 1;
				LED2 = 0;
				delay_ms(300);
				LED1 = 0;
				LED2 = 1;
				delay_ms(300);
				LED1 = 1;
				key = 0;
			}

		}
		else if(key==3)    //KEY_LU    
		{
			key = 0;	 
			
			tmp_buf = '3';
			if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
			{
				LED1 = 1;
				LED2 = 0;
				delay_ms(300);
				LED1 = 0;
				LED2 = 1;
				delay_ms(300);
				LED1 = 1;
				key = 0;
				
				
			}	
			
		}
		else if(key==4)   //KEY_RU     ��һ�ΰ�������ҡ�˿���
		{ 
			key=0;
			tmp_buf = '4';
			if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
			{
				LED1 = 1;
				LED2 = 0;
				delay_ms(300);
				LED1 = 0;
				LED2 = 1;
				delay_ms(300);
				LED1 = 1;
				key = 0;
				
				while(1)   //���ϰ�����һ�α����º󣬽���ң�п���
				{
					key=KEY_Task();
					
							if(key==1)  //KEY_LD    ��ͣ
							{
								
								tmp_buf = '1';
								if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
								{
									LED1 = 0;
									LED2 = 0;
									delay_ms(300);
									LED1 = 1;
									LED2 = 1;
									key = 0;
								}
							}
							
							else if(key == 4)    //�ٴΰ������ϰ�����LED��0.5s������ɹ��������1s��ȡ��ҡ�˿��Ʋ��Ҽ�ͣ
							{
									tmp_buf = '1';   //��ָͣ��
									//LED��0.5s����ʾ
									LED1 = 0;
									LED2 = 0;
									delay_ms(500);
									LED1 = 1;
									LED2 = 1;
									key = 0;
								
								if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
								{
									LED1 = 0;
									LED2 = 0;
									delay_ms(1000);
									LED1 = 1;
									LED2 = 1;
									key = 0;
								}
									
									break;  //����while
							}
							else if(key == 0)
							{
								tmp_buf = adc_value_compare(Get_Adc(2));
								if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
								{
									LED1 = 0;
									LED2 = 0;
									delay_ms(200);
									LED1 = 1;
									LED2 = 1;
									key = 0;
								}
							}
							
				}//ң�п��� while����
			}		    
		}
	} //��ѭ������

//while(1)
//{
//	LED1=1;LED2=0;
//	delay_ms(500);
//	LED1=0;LED2=1;
//	delay_ms(500);
//}
}


