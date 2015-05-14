#ifndef __MOTOR_H
#define __MOTOR_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK Mini STM32������
//MOTOR��������	   
//Author:jiapengfeng
//FAE Eamil��jpfeng@foxmail.com
//�޸�����:2015/3/10
//�汾��V1.0
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

//�����װ��ֵ�ͷ�Ƶϵ����PWMƵ��=72000000/(19999+1)/(71+1)=50hz	
#define SERVO_TIM_ARR 20000
#define SERVO_TIM_PSC 72
#define SERVO_TIM_DIV 7.8125    //MOTOR_TIM_ARR/256

//��װ��ֵ�ͷ�Ƶϵ����PWMƵ��=72000000/(999+1)/(71+1)=1Khz	
#define MOTOR_TIM_ARR 1000
#define MOTOR_TIM_PSC 72
#define MOTOR_TIM_DIV 4    //MOTOR_TIM_ARR/250

//ͨ���ı�TIM3->CCR1��TIM3->CCR2��ֵ���ı�ռ�ձȣ��Ӷ�����SERVO��ת��
#define SERVO_PWM_VAL TIM3->CCR1  
//ͨ���ı�TIM2->CCR1��TIM2->CCR2��ֵ���ı�ռ�ձȣ��Ӷ�����MOTOR��ת�ٺ�����ת
#define MOTOR_PWM_CHANL1 TIM2->CCR1
#define MOTOR_PWM_CHANL2 TIM2->CCR2
//LED�˿ڶ���
#define MOTOR_GPIO_CHANL1 PAout(0)	// PA0
#define MOTOR_GPIO_CHANL2 PAout(1)	// PA1	

//�������Ұڶ�ʵ����Ч��Χ
#define SERVO_ANGLE_MAX_VAL 45
#define SERVO_ANGLE_MID_VAL 0
//�������ת��ķ�Χ��Ӧ��PWMֵ(����0~256)
#define SERVO_PWM_MAX_VAL 150
#define SERVO_PWM_MID_VAL 125
#define SERVO_PWM_MIN_VAL 100
//smartcat��buletooth��ȡ����ĸ�ʽ
#define CMD_LEN 5
#define CMD_BEGIN 	'B'
#define CMD_END 	'E'
#define CMD_TRUN_RIGHT 	'r'
#define CMD_TRUN_LEFT 	'l'
#define CMD_SPEED_UP 	'u'
#define CMD_SPEED_DOWN 	'd'

//�������°ڶ�ʵ����Ч��Χ
#define MOTOR_ANGLE_MAX_VAL 45
#define MOTOR_ANGLE_MID_VAL 0
//���������ٵķ�Χ��Ӧ��PWMֵ(����0~256)
#define MOTOR_PWM_MAX_VAL 250
#define MOTOR_PWM_MID_VAL 125
#define MOTOR_PWM_MIN_VAL 0

//PWM�˿ڶ���
void MOTOR_Init(void);	//�����ʼ��
void SERVO_Init(void);  //�����ʼ��
void MOTOR_RUN(u8 diection,u16 speed);   //�������
void SERVO_RUN(u8 diection,u16 angle);  //���ת��
#endif
