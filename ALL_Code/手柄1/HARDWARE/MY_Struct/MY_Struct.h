#ifndef _MY_STRUCT
#define _MY_STRUCT
#include  "sys.h" 

//#define		_RUN_HW 1				//���к���ң��
//#define		_RUN_KEY 1				//���а���
//#define		_RUN_ADC 1				//	����ADC
//#define		_RUN_PID 1				//	����PID
//#define   _RUN_3PHASE 1			//	����3��SPWM
//======================

typedef enum
{
	OK,					//	�������
	UPDAT,			//	����״̬����
	BUSY,				//	����æ
}TASK_STATUS;

//typedef struct
//{
//	float Voltage;
//	u8 Frequency;
//	u8 Count[3];
//	u8 PIDFlag;
//	FRE_MODE FreqMode;
//}SysStatus;
//extern SysStatus SYS;


//#define My_CarrierArr 4096
//#define My_TableLen 168
#endif
