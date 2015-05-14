#ifndef __MOTOR_H
#define __MOTOR_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK Mini STM32开发板
//MOTOR驱动代码	   
//Jiapengfeng
//修改日期:2015/3/10
//版本：V1.0
//版权所有，盗版必究。
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

//通过改变TIM3->CCR1和TIM3->CCR2的值来改变占空比，从而控制SERVO和MOTOR的亮度
#define SERVO_PWM_VAL TIM3->CCR1  
#define MOTOR_PWM_VAL TIM3->CCR2        

//PWM端口定义
void MOTOR_Init(void);	//初始化		 				    
#endif
