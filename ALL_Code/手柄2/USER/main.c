#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
//#include "lcd.h"
#include "usart.h"
#include "adc.h"
#include "beep.h"
#include "oled.h"

/************************************************
 ALIENTEK��ӢSTM32������ʵ��17
 ADC ʵ��
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


int main(void)
{
    u16 key;
    delay_init();	    	 //��ʱ������ʼ��
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
    uart_init(9600);	 	//���ڳ�ʼ��Ϊ115200
  //  LED_Init();			     //LED�˿ڳ�ʼ��

  //  BEEP_Init();
//	LCD_Init();
// 	Adc_Init();		  		//ADC��ʼ��
    KEY_Init();
 //   OLED_Init();			//��ʼ��OLED
    while(1)
    {
		delay_ms(100);
		//USART_SendData(USART1, '1');
        key=KEY_Scan(0);	//�õ���ֵ
        if(key)
        {
            switch(key)
            {
            case 1: USART_SendData(USART1, '1');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0001);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
////                OLED_ShowString(0,0,"KEY1",12);
////                OLED_Refresh_Gram();
                break;
            case 2:
				USART_SendData(USART1, '2');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0002);
//						delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
////                OLED_ShowString(0,0,"KEY2",12);
////                OLED_Refresh_Gram();
                break;
            case 3: USART_SendData(USART1, '3');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0003);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
////                OLED_ShowString(0,0,"KEY3",12);
////                OLED_Refresh_Gram();
                break;
            case 4: USART_SendData(USART1, '4');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0004);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY4",12);
//                OLED_Refresh_Gram();
                break;
            case 5: USART_SendData(USART1, '5');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0005);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY5",12);
//                OLED_Refresh_Gram();
                break;
            case 6: USART_SendData(USART1, '6');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0006);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY6",12);
//                OLED_Refresh_Gram();
                break;
            case 7: USART_SendData(USART1, '7');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0007);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY7",12);
//                OLED_Refresh_Gram();
                break;
            case 8: USART_SendData(USART1, '8');
//                BEEP =1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0008);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY8",12);
//                OLED_Refresh_Gram();
                break;
            case 9: USART_SendData(USART1, '9');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0009);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY9",12);
//                OLED_Refresh_Gram();
                break;
            case 10: USART_SendData(USART1, 'A');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0010);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY10",12);
//                OLED_Refresh_Gram();
                break;
            case 11: USART_SendData(USART1, 'B');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0011);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY11",12);
//                OLED_Refresh_Gram();
                break;
            case 12: USART_SendData(USART1, 'C');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0012);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY12",12);
//                OLED_Refresh_Gram();
                break;
            }
        } else delay_ms(100);
    }



}

