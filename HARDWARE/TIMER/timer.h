#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK Mini STM32������
//ͨ�ö�ʱ�� ��������			   
//Author:jiapengfeng
//FAE Eamil��jpfeng@foxmail.com
//�޸�����:2015/3/12
//�汾��V1.0
//All rights reserved	
//********************************************************************************
//V1.1 20140306 
//����TIM1_CH1��PWM�������������� 
////////////////////////////////////////////////////////////////////////////////// 	  
  
void TIM3_Int_Init(u16 arr,u16 psc);
void TIM1_PWM_Init(u16 arr,u16 psc);
void PWM_Init_Tim2(u16 arr,u16 psc);
void PWM_Init_Tim3(u16 arr,u16 psc);
void TIM2_Cap_Init(u16 arr,u16 psc);
#endif























