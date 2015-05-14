#ifndef __MOTOR_H
#define __MOTOR_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK Mini STM32开发板
//MOTOR驱动代码	   
//Author:jiapengfeng
//FAE Eamil：jpfeng@foxmail.com
//修改日期:2015/3/10
//版本：V1.0
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

//舵机重装载值和分频系数，PWM频率=72000000/(19999+1)/(71+1)=50hz	
#define SERVO_TIM_ARR 20000
#define SERVO_TIM_PSC 72
#define SERVO_TIM_DIV 7.8125    //MOTOR_TIM_ARR/256

//重装载值和分频系数，PWM频率=72000000/(999+1)/(71+1)=1Khz	
#define MOTOR_TIM_ARR 1000
#define MOTOR_TIM_PSC 72
#define MOTOR_TIM_DIV 4    //MOTOR_TIM_ARR/250

//通过改变TIM3->CCR1和TIM3->CCR2的值来改变占空比，从而控制SERVO的转角
#define SERVO_PWM_VAL TIM3->CCR1  
//通过改变TIM2->CCR1和TIM2->CCR2的值来改变占空比，从而控制MOTOR的转速和正反转
#define MOTOR_PWM_CHANL1 TIM2->CCR1
#define MOTOR_PWM_CHANL2 TIM2->CCR2
//LED端口定义
#define MOTOR_GPIO_CHANL1 PAout(0)	// PA0
#define MOTOR_GPIO_CHANL2 PAout(1)	// PA1	

//手势左右摆动实际有效范围
#define SERVO_ANGLE_MAX_VAL 45
#define SERVO_ANGLE_MID_VAL 0
//舵机允许转向的范围对应的PWM值(正常0~256)
#define SERVO_PWM_MAX_VAL 150
#define SERVO_PWM_MID_VAL 125
#define SERVO_PWM_MIN_VAL 100
//smartcat从buletooth读取命令的格式
#define CMD_LEN 5
#define CMD_BEGIN 	'B'
#define CMD_END 	'E'
#define CMD_TRUN_RIGHT 	'r'
#define CMD_TRUN_LEFT 	'l'
#define CMD_SPEED_UP 	'u'
#define CMD_SPEED_DOWN 	'd'

//手势上下摆动实际有效范围
#define MOTOR_ANGLE_MAX_VAL 45
#define MOTOR_ANGLE_MID_VAL 0
//电机允许调速的范围对应的PWM值(正常0~256)
#define MOTOR_PWM_MAX_VAL 250
#define MOTOR_PWM_MID_VAL 125
#define MOTOR_PWM_MIN_VAL 0

//PWM端口定义
void MOTOR_Init(void);	//电机初始化
void SERVO_Init(void);  //舵机初始化
void MOTOR_RUN(u8 diection,u16 speed);   //电机运行
void SERVO_RUN(u8 diection,u16 angle);  //舵机转向
#endif
