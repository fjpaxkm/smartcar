#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK Mini STM32开发板
//通用定时器 驱动代码			   
//Author:jiapengfeng
//FAE Eamil：jpfeng@foxmail.com
//修改日期:2015/3/12
//版本：V1.0
//All rights reserved	
//********************************************************************************
//V1.1 20140306 
//增加TIM1_CH1，PWM输出设置相关内容 
////////////////////////////////////////////////////////////////////////////////// 	  
  
void TIM3_Int_Init(u16 arr,u16 psc);
void TIM1_PWM_Init(u16 arr,u16 psc);
void PWM_Init_Tim2(u16 arr,u16 psc);
void PWM_Init_Tim3(u16 arr,u16 psc);
void TIM2_Cap_Init(u16 arr,u16 psc);
#endif























