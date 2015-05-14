#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h"  
#include "key.h"
#include "timer.h"
#include "motor.h"
//Name:smartcat project code
//Description:action of the car is control by hand monvent which sense by MPU6050 and transfer data to the car controler by buletooth
//Author:jiapengfeng
//FAE Eamil��jpfeng@foxmail.com
//Change data:2015/3/12
//Version��V1.0
//All rights reserved	

extern u8  TIM2CH1_CAPTURE_STA;		//���벶��״̬		    				
extern u16	TIM2CH1_CAPTURE_VAL;	//���벶��ֵ

int main(void)
{			
//  u16 motor_pwm_val=0;
//  u16 servo_pwm_val=0;	
//  u8 key_value=0;
//  u8 start_stop_flag=0;
//u8 uart_data_len;	         //�������ݳ���
  u8 t,i,j,len;
//  u8 motor_pwm_val_change_flag=0;
  u8 cmd_data[CMD_LEN];
//u8 rev_new_cmd_num=0;
  u8 turn_diection=3;       //1:left  2:right  3:hold
  u16 turn_angle;
  u8 speed_updown=3;       //1:speed up  2:speed down  3:hold
  u16 speed_value;
  u16 cmd_value;
  u16 tempdata=1;
  u32 temp=0;              //����ʹ��
  Stm32_Clock_Init(9); //ϵͳʱ������
  delay_init(72);	     //��ʱ��ʼ��
  uart_init(72,115200);  //���ڳ�ʼ�� 
//  MOTOR_Init();		 //��ʼ����MOTOR���ӵ�Ӳ���ӿ�
  SERVO_Init();
//  KEY_Init();          //��ʼ��������Ӳ���ӿ�
  TIM2_Cap_Init(0XFFFF,72-1);		//��1Mhz��Ƶ�ʼ���
  while(1)
	{

		if(USART_RX_STA&0x8000)
			{                                              
				len=USART_RX_STA&0x3fff;//��ȡ����usart�ڵ���Ϣ�ĳ���
				printf("\r\nlen:%d\r\n",len);
				for(t=0;t<len;) {
					if(USART_RX_BUF[t] ==CMD_BEGIN) {
						t++;
						printf("\r\nfind cmd\r\n");
						for(i=0;(USART_RX_BUF[t+i]!='E')&&(i<CMD_LEN);i++) {
							cmd_data[i]=USART_RX_BUF[t+i];
							printf("\r\ncmd_data[%d]:%d\r\n",i,cmd_data[i]);
						}
						if(USART_RX_BUF[t+i] ==CMD_END) {
							printf("\r\nt:%d i:%d USART_RX_BUF[%d]:%d\r\n",t,i,t+i,USART_RX_BUF[t+i]);
							tempdata=1;                              
							for(j=i;j>2;j--) {                           //make char into int
								cmd_value+=(cmd_data[j-1]-48)*tempdata;
								printf("\r\ncmd_value:%d cmd_data[%d]-48:%d tempdata:%d\r\n",cmd_value,j-1,cmd_data[j-1]-48,tempdata);
								tempdata*=10;
							}
							switch(cmd_data[0]) {
								case 't': turn_diection=cmd_data[1];
										  turn_angle=cmd_value;
										  SERVO_RUN(turn_diection,turn_angle);
										  printf("\r\nturn_diection:%d turn_angle:%d\r\n",turn_diection,turn_angle);
										  break;
								case 's': speed_updown=cmd_data[1];
										  speed_value=cmd_value;
										  MOTOR_RUN(speed_updown,speed_value);
										  printf("\r\nspeed_updown:%d speed_value:%d\r\n",speed_updown,speed_value);
										  break;
								default:                                       //the cmd format is wrong,skip it
										  break;
							}
							cmd_value=0;
							t+=(i+1);
						}						
					}else {
						t++;
					}
				}
				USART_RX_STA=0;
			}else if(TIM2CH1_CAPTURE_STA&0X80) {//�ɹ�������һ�θߵ�ƽ
				temp=TIM2CH1_CAPTURE_STA&0X3F;
				temp*=65536;					//���ʱ���ܺ�
				temp+=TIM2CH1_CAPTURE_VAL;		//�õ��ܵĸߵ�ƽʱ��
				printf("HIGH:%d us\r\n",temp);	//��ӡ�ܵĸߵ�ƽʱ��
				TIM2CH1_CAPTURE_STA=0;			//������һ�β���
			}/*else{
				key_value=KEY_Scan(1);		//�õ���ֵ
				switch(key_value)
				{				 
					case KEY0_PRES:          //����
						motor_pwm_val+=1;
						motor_pwm_val_change_flag=1;
						break;
					case KEY1_PRES:           //����
						motor_pwm_val-=1;
						motor_pwm_val_change_flag=1;
						break;
					case WKUP_PRES:		      //��ͣ		
						start_stop_flag =!start_stop_flag; 
						printf("\r\nstart_stop_flag:%d\r\n",start_stop_flag);
						delay_ms(1000);
						break;
					default:
						delay_ms(10);
						break;			
				}
	  }
	  if(servo_pwm_val>SERVO_PWM_MAX_VAL) {
			servo_pwm_val =SERVO_PWM_MAX_VAL;
	  }
      else if(motor_pwm_val<SERVO_PWM_MIN_VAL) {	
			servo_pwm_val =SERVO_PWM_MIN_VAL;
	  }
		if((start_stop_flag==1)&&(motor_pwm_val_change_flag==1)) {
			printf("\r\nmotor_pwm_val:%d\r\n",motor_pwm_val);
			SERVO_PWM_VAL=20000-(500+motor_pwm_val*7.8125);
			motor_pwm_val_change_flag =0;
        }
		else {
			SERVO_PWM_VAL=0;
		}	*/		
	} 
}














