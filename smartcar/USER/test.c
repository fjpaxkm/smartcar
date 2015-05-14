#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h"  
#include "key.h"
#include "timer.h"
#include "motor.h"
//ALIENTEK Mini STM32开发板范例代码8
//PWM输出实验   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司

#define CMD_LEN 5

int main(void)
{			
 	u16 motor_pwm_val=0; 
  u8 key_value=0;
	u8 start_stop_flag=0;
//u8 uart_data_len;	         //串口数据长度
	u8 t,i,j,len;
	u8 motor_pwm_val_change_flag=0;
	u8 cmd_data[CMD_LEN];
//u8 rev_new_cmd_num=0;
  u8 turn_diection=3;       //1:left  2:right  3:hold
  u8 turn_angle;
  u8 speed_updown=3;       //1:speed up  2:speed down  3:hold
  u8 speed_value;
	u8 cmd_value;
	u16 tempdata=1;
	Stm32_Clock_Init(9); //系统时钟设置
	delay_init(72);	     //延时初始化
	uart_init(72,115200);  //串口初始化 
	MOTOR_Init();		 //初始化与MOTOR连接的硬件接口
	KEY_Init();          //初始化按键的硬件接口
  while(1)
	{

		if(USART_RX_STA&0x8000)
			{                                              
				len=USART_RX_STA&0x3fff;//????????????
        printf("\r\nlen:%d\r\n",len);
				for(t=0;t<len;) {
					if((USART_RX_BUF[t] =='B')&&(USART_RX_BUF[t+1]=='G')) {
						t+=2;
						printf("\r\nfind cmd\r\n");
						for(i=0;(USART_RX_BUF[t+i]!=0xD)&&(i<CMD_LEN);i++) {
							cmd_data[i]=USART_RX_BUF[t+i];
							printf("\r\ncmd_data[%d]:%d\r\n",i,cmd_data[i]);
						}
						printf("\r\ncmd_data[%d]:%d\r\n",t+i,USART_RX_BUF[t+i]);
						printf("\r\ncmd_data[%d]:%d\r\n",t+i+1,USART_RX_BUF[t+i+1]);
						tempdata=1;                              
						for(j=i;j>2;j--) {                           //make char into int
							cmd_value+=(cmd_data[j-1]-48)*tempdata;
							printf("\r\ncmd_value:%d cmd_data[%d]:%d tempdata:%d\r\n",cmd_value,j-1,cmd_data[j-1],tempdata);
							tempdata*=10;
						}
						switch(cmd_data[0]) {
							case 't': if(cmd_data[1]=='l') {               //turn left
													turn_diection =1;
												}else if(cmd_data[1]=='r') {         //turn right
													turn_diection =2;
												}
												turn_angle=cmd_value;
												printf("\r\nturn_diection:%d turn_angle:%d\r\n",turn_diection,turn_angle);
												break;
							case 's': if(cmd_data[1]=='u') {               //speed up
													speed_updown =1;
												}else if(cmd_data[1]=='d') {         //speed down
													speed_updown =2;
												}
												speed_value=cmd_value;
												printf("\r\nspeed_updown:%d speed_value:%d\r\n",speed_updown,speed_value);
												break;
							default:
												break;
						}
						cmd_value=0;
						t+=(i+1);						
					}
				}
			USART_RX_STA=0;
			}else{
				key_value=KEY_Scan(1);		//得到键值
				switch(key_value)
				{				 
					case KEY0_PRES:          //加速
						motor_pwm_val+=1;
						motor_pwm_val_change_flag=1;
						break;
					case KEY1_PRES:           //减速
						motor_pwm_val-=1;
						motor_pwm_val_change_flag=1;
						break;
					case WKUP_PRES:		      //启停		
						start_stop_flag =!start_stop_flag; 
						printf("\r\nstart_stop_flag:%d\r\n",start_stop_flag);
						delay_ms(1000);
						break;
					default:
						delay_ms(10);
						break;			
				}
	  }
		if(motor_pwm_val>151) {
			motor_pwm_val =151;
		}
    else if(motor_pwm_val<105) {	
			motor_pwm_val =105;
		}
		if((start_stop_flag==1)&&(motor_pwm_val_change_flag==1)) {
//		MOTOR_PWM_VAL=motor_pwm_val;
			printf("\r\nmotor_pwm_val:%d\r\n",motor_pwm_val);
			SERVO_PWM_VAL=20000-(500+motor_pwm_val*7.8125);
			motor_pwm_val_change_flag =0;
        }
		else {
//		MOTOR_PWM_VAL=0;
			SERVO_PWM_VAL=0;
		}			
	} 
}














