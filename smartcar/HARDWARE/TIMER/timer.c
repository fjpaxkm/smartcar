#include "timer.h"
#include "led.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK Mini STM32������
//ͨ�ö�ʱ�� ��������			   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2014/3/06
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved	
//********************************************************************************
//V1.1 20140306 
//����TIM1_CH1��PWM�������������� 
////////////////////////////////////////////////////////////////////////////////// 	  
 

//TIM1_CH1 and TIM1_CH2 PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM1_PWM_Init(u16 arr,u16 psc)
{		 					 
	//�˲������ֶ��޸�IO������
	RCC->APB2ENR|=1<<11; 	//TIM1ʱ��ʹ��    
	GPIOA->CRH&=0XFFFFFF00;	//PA8 PA9���֮ǰ������
	GPIOA->CRH|=0X0000000B;	//���ù������ 
	GPIOA->CRH|=0X000000B0;	//���ù������ 
	
	TIM1->ARR=arr;			//�趨�������Զ���װֵ 
	TIM1->PSC=psc;			//Ԥ��Ƶ������
  
	TIM1->CCMR1|=7<<4;  	//CH1 PWM2ģʽ		 
	TIM1->CCMR1|=1<<3; 		//CH1Ԥװ��ʹ��
	TIM1->CCMR1|=7<<12;  	//CH2 PWM2ģʽ		 
	TIM1->CCMR1|=1<<11; 	//CH2Ԥװ��ʹ��	
	
 	TIM1->CCER|=1<<0;   	//OC1 ���ʹ��
	TIM1->CCER|=1<<4;   	//OC0 ���ʹ��	  	
	TIM1->BDTR|=1<<15;   	//MOE �����ʹ��	   

	TIM1->CR1=0x0080;   	//ARPEʹ�� 
	TIM1->CR1|=0x01;    	//ʹ�ܶ�ʱ��1 										  
}

//TIM2_CH1 and TIM2_CH2 PWM�����ʼ��
//��ӦGPIOA1\GPIOA2\GPIOA3\GPIOA4���PWM�ź�
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��

void PWM_Init_Tim2(u16 arr,u16 psc)
{		 					 
	//�˲������ֶ��޸�IO������
	RCC->APB1ENR|=1<<0;       //TIM2ʱ��ʹ��    

	GPIOA->CRL&=0XFFFFFF00;//PA0/1���
	GPIOA->CRL|=0X000000BB;//���ù������ 	  
	GPIOA->ODR|=3<<0;//PA0/1����  	
	GPIOA->CRL&=0XFFFF00FF;//PA2/3���
	GPIOA->CRL|=0X0000BB00;//���ù������ 	  
	GPIOA->ODR|=3<<2;//PA2/3����	

	TIM2->ARR=arr;//�趨�������Զ���װֵ 
	TIM2->PSC=psc;//Ԥ��Ƶ������Ƶ


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

	TIM2->CR1|=1<<7;   //ARPEʹ�� 
	TIM2->CR1|=0x01;    //ʹ�ܶ�ʱ��3 										  
}

//TIM3_CH1 and TIM3_CH2 PWM�����ʼ��
//��ӦGPIOA6��GPIOA7���PWM�ź�
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��

void PWM_Init_Tim3(u16 arr,u16 psc)
{		 					 
	//�˲������ֶ��޸�IO������
	RCC->APB1ENR|=1<<1;       //TIM3ʱ��ʹ��    
	  	
	GPIOA->CRL&=0X00FFFFFF;//PA6/7���
	GPIOA->CRL|=0XBB000000;//���ù������ 	  
	GPIOA->ODR|=3<<6;//PA6/7����

	TIM3->ARR=arr;//�趨�������Զ���װֵ 
	TIM3->PSC=psc;//Ԥ��Ƶ������Ƶ

	//CH1/2 PWM2ģʽ
	//CH1/2Ԥװ��ʹ��	
	TIM3->CCMR1|=7<<4;//CH1		
	TIM3->CCMR1|=1<<3;// 			   	
	TIM3->CCMR1|=7<<12;//CH2
	TIM3->CCMR1|=1<<11;//


	//OC1/2 ���ʹ��	   
	TIM3->CCER|=1<<0;//CH1  	  
	TIM3->CCER|=1<<4;//CH2



//	TIM3->EGR|=1;//�����¼� 
	TIM3->CR1|=1<<7;   //ARPEʹ�� 	   �����һ��
	TIM3->CR1|=0x01;    //ʹ�ܶ�ʱ��3 										  
} 














