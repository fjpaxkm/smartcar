#ifndef __MOTOR_H
#define __MOTOR_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK Mini STM32������
//MOTOR��������	   
//Jiapengfeng
//�޸�����:2015/3/10
//�汾��V1.0
//��Ȩ���У�����ؾ���
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

//ͨ���ı�TIM3->CCR1��TIM3->CCR2��ֵ���ı�ռ�ձȣ��Ӷ�����SERVO��MOTOR������
#define SERVO_PWM_VAL TIM3->CCR1  
#define MOTOR_PWM_VAL TIM3->CCR2        

//PWM�˿ڶ���
void MOTOR_Init(void);	//��ʼ��		 				    
#endif
