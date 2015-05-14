#include "sys.h"   
#include "motor.h"
#include "timer.h"
#include "usart.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK Mini STM32开发板
//LED驱动代码	   
//Author:jiapengfeng
//FAE Eamil：jpfeng@foxmail.com
//修改日期:2015/3/12
//版本：V1.0
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//初始化PA6和PA7为输出口.并使能这两个口的时钟Tim3		    
//电机与舵机的初始化
void SERVO_Init(void)
{
	PWM_Init_Tim3(SERVO_TIM_ARR-1,SERVO_TIM_PSC-1);   //PWM频率=72000000/(19999+1)/(71+1)=50hz	
}

//初始化PA0和PA1为输出口.并使能这两个口的时钟Tim2		    
//电机与舵机的初始化
void MOTOR_Init(void)
{
	PWM_Init_Tim2(MOTOR_TIM_ARR-1,MOTOR_TIM_PSC-1);   //PWM频率=72000000/(999+1)/(71+1)=1Khz	
}

void SERVO_RUN(u8 diection,u16 angle)
{
	angle=angle*(SERVO_PWM_MAX_VAL-SERVO_PWM_MID_VAL)/(SERVO_ANGLE_MAX_VAL-SERVO_ANGLE_MID_VAL);
	if(diection==CMD_TRUN_LEFT) {                 //trun left
		angle=SERVO_PWM_MID_VAL+angle;
	}else if(diection==CMD_TRUN_RIGHT){
		angle=SERVO_PWM_MID_VAL-angle;            //trun right
	}
	if(angle>SERVO_PWM_MAX_VAL) {
		angle =SERVO_PWM_MAX_VAL;
	}else if(angle<SERVO_PWM_MIN_VAL) {	
		angle =SERVO_PWM_MIN_VAL;
	}
	printf("\r\nSERVO_RUN:diection:%d angle:%d\r\n",diection,angle);
	SERVO_PWM_VAL=SERVO_TIM_ARR-(500+angle*SERVO_TIM_DIV);    //产生对应脉宽的方波
}

void MOTOR_RUN(u8 diection,u16 speed)
{
	speed=speed*(MOTOR_PWM_MAX_VAL-MOTOR_PWM_MIN_VAL)/(MOTOR_ANGLE_MAX_VAL-MOTOR_ANGLE_MID_VAL);
	if(speed>MOTOR_PWM_MAX_VAL) {
		speed =MOTOR_PWM_MAX_VAL;
	}else if(speed<=MOTOR_PWM_MIN_VAL) {	
		speed =MOTOR_PWM_MIN_VAL;
	}
	printf("\r\nMOTOR_RUN:diection:%d speed:%d\r\n",diection,speed);
	if(diection==CMD_SPEED_DOWN) {                 //forward
		GPIOA->CRL&=0XFFFFFF00;	//PA0 清除之前设置  
		GPIOA->CRL|=0X00000B3;  //PA0 配置成推免输出
		MOTOR_GPIO_CHANL1=0;//PA0下拉
		MOTOR_PWM_CHANL2=MOTOR_TIM_ARR-speed*MOTOR_TIM_DIV;
	}else if(diection==CMD_SPEED_UP){          //backward
		GPIOA->CRL&=0XFFFFFF00;	//PA0 清除之前设置  
		GPIOA->CRL|=0X0000003B;
	  MOTOR_GPIO_CHANL2=0;//PA1下拉		
		MOTOR_PWM_CHANL1=MOTOR_TIM_ARR-speed*MOTOR_TIM_DIV;									
	}

}
