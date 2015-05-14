#include "timer.h"
#include "led.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK Mini STM32开发板
//通用定时器 驱动代码			   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2014/3/06
//版本：V1.1
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved	
//********************************************************************************
//V1.1 20140306 
//增加TIM1_CH1，PWM输出设置相关内容 
////////////////////////////////////////////////////////////////////////////////// 	  
 

//TIM1_CH1 and TIM1_CH2 PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void TIM1_PWM_Init(u16 arr,u16 psc)
{		 					 
	//此部分需手动修改IO口设置
	RCC->APB2ENR|=1<<11; 	//TIM1时钟使能    
	GPIOA->CRH&=0XFFFFFF00;	//PA8 PA9清除之前的设置
	GPIOA->CRH|=0X0000000B;	//复用功能输出 
	GPIOA->CRH|=0X000000B0;	//复用功能输出 
	
	TIM1->ARR=arr;			//设定计数器自动重装值 
	TIM1->PSC=psc;			//预分频器设置
  
	TIM1->CCMR1|=7<<4;  	//CH1 PWM2模式		 
	TIM1->CCMR1|=1<<3; 		//CH1预装载使能
	TIM1->CCMR1|=7<<12;  	//CH2 PWM2模式		 
	TIM1->CCMR1|=1<<11; 	//CH2预装载使能	
	
 	TIM1->CCER|=1<<0;   	//OC1 输出使能
	TIM1->CCER|=1<<4;   	//OC0 输出使能	  	
	TIM1->BDTR|=1<<15;   	//MOE 主输出使能	   

	TIM1->CR1=0x0080;   	//ARPE使能 
	TIM1->CR1|=0x01;    	//使能定时器1 										  
}

//TIM2_CH1 and TIM2_CH2 PWM输出初始化
//对应GPIOA1\GPIOA2\GPIOA3\GPIOA4输出PWM信号
//arr：自动重装值
//psc：时钟预分频数

void PWM_Init_Tim2(u16 arr,u16 psc)
{		 					 
	//此部分需手动修改IO口设置
	RCC->APB1ENR|=1<<0;       //TIM2时钟使能    

	GPIOA->CRL&=0XFFFFFF00;//PA0/1输出
	GPIOA->CRL|=0X000000BB;//复用功能输出 	  
	GPIOA->ODR|=3<<0;//PA0/1上拉  	
	GPIOA->CRL&=0XFFFF00FF;//PA2/3输出
	GPIOA->CRL|=0X0000BB00;//复用功能输出 	  
	GPIOA->ODR|=3<<2;//PA2/3上拉	

	TIM2->ARR=arr;//设定计数器自动重装值 
	TIM2->PSC=psc;//预分频器不分频


	TIM2->CCMR1|=7<<4;//    CH1 
	TIM2->CCMR1|=1<<3; 	
	TIM2->CCMR1|=7<<12;//	CH2 
	TIM2->CCMR1|=1<<11;
	TIM2->CCMR2|=7<<4;//	CH3 
	TIM2->CCMR2|=1<<3; 	
	TIM2->CCMR2|=7<<12;//	CH4 
	TIM2->CCMR2|=1<<11; 


	TIM2->CCER|=1<<0;//CH1
	TIM2->CCER|=1<<4;//CH2
	TIM2->CCER|=1<<8;//CH3
	TIM2->CCER|=1<<12;//CH4

	TIM2->CR1|=1<<7;   //ARPE使能 
	TIM2->CR1|=0x01;    //使能定时器3 										  
}

//TIM3_CH1 and TIM3_CH2 PWM输出初始化
//对应GPIOA6和GPIOA7输出PWM信号
//arr：自动重装值
//psc：时钟预分频数

void PWM_Init_Tim3(u16 arr,u16 psc)
{		 					 
	//此部分需手动修改IO口设置
	RCC->APB1ENR|=1<<1;       //TIM3时钟使能    
	  	
	GPIOA->CRL&=0X00FFFFFF;//PA6/7输出
	GPIOA->CRL|=0XBB000000;//复用功能输出 	  
	GPIOA->ODR|=3<<6;//PA6/7上拉

	TIM3->ARR=arr;//设定计数器自动重装值 
	TIM3->PSC=psc;//预分频器不分频

	//CH1/2 PWM2模式
	//CH1/2预装载使能	
	TIM3->CCMR1|=7<<4;//CH1		
	TIM3->CCMR1|=1<<3;// 			   	
	TIM3->CCMR1|=7<<12;//CH2
	TIM3->CCMR1|=1<<11;//


	//OC1/2 输出使能	   
	TIM3->CCER|=1<<0;//CH1  	  
	TIM3->CCER|=1<<4;//CH2



//	TIM3->EGR|=1;//更新事件 
	TIM3->CR1|=1<<7;   //ARPE使能 	   多余的一句
	TIM3->CR1|=0x01;    //使能定时器3 										  
} 














