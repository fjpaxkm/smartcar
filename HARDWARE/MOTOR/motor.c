#include "sys.h"   
#include "motor.h"
#include "timer.h"
#include "usart.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK Mini STM32������
//LED��������	   
//Author:jiapengfeng
//FAE Eamil��jpfeng@foxmail.com
//�޸�����:2015/3/12
//�汾��V1.0
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//��ʼ��PA6��PA7Ϊ�����.��ʹ���������ڵ�ʱ��Tim3		    
//��������ĳ�ʼ��
void SERVO_Init(void)
{
	PWM_Init_Tim3(SERVO_TIM_ARR-1,SERVO_TIM_PSC-1);   //PWMƵ��=72000000/(19999+1)/(71+1)=50hz	
}

//��ʼ��PA0��PA1Ϊ�����.��ʹ���������ڵ�ʱ��Tim2		    
//��������ĳ�ʼ��
void MOTOR_Init(void)
{
	PWM_Init_Tim2(MOTOR_TIM_ARR-1,MOTOR_TIM_PSC-1);   //PWMƵ��=72000000/(999+1)/(71+1)=1Khz	
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
	SERVO_PWM_VAL=SERVO_TIM_ARR-(500+angle*SERVO_TIM_DIV);    //������Ӧ����ķ���
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
		GPIOA->CRL&=0XFFFFFF00;	//PA0 ���֮ǰ����  
		GPIOA->CRL|=0X00000B3;  //PA0 ���ó��������
		MOTOR_GPIO_CHANL1=0;//PA0����
		MOTOR_PWM_CHANL2=MOTOR_TIM_ARR-speed*MOTOR_TIM_DIV;
	}else if(diection==CMD_SPEED_UP){          //backward
		GPIOA->CRL&=0XFFFFFF00;	//PA0 ���֮ǰ����  
		GPIOA->CRL|=0X0000003B;
	  MOTOR_GPIO_CHANL2=0;//PA1����		
		MOTOR_PWM_CHANL1=MOTOR_TIM_ARR-speed*MOTOR_TIM_DIV;									
	}

}
