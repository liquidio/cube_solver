#include "led.h"
#include "delay.h"
#include "sys.h"
#include "pwm.h"
#include "usart.h"
//#define DEBUG
extern u8  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART_RX_STA;         		//接收状态标记	
 int main(void)
 {	
	u16 i=0;
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 2
	uart_init(115200);
	LED_Init();
   while(1){
		if (USART_RX_STA){
			while(USART_RX_BUF[i] && (USART_RX_BUF[0]=='@')){
				char cur = USART_RX_BUF[i];
				char next = USART_RX_BUF[i+1];
				//90度
				if (cur == 'U' && next == ' '){
					
				}
				if (cur == 'D' && next == ' '){
					
				}
				if (cur == 'F' && next == ' '){
					
				}
				if (cur == 'B' && next == ' '){
					
				}
				if (cur == 'R' && next == ' '){
					
				}
				if (cur == 'L' && next == ' '){
					
				}
				//逆时针
				if (cur == 'U' && next == '\''){
					
				}
				if (cur == 'D' && next == '\''){
					
				}
				if (cur == 'F' && next == '\''){
					
				}
				if (cur == 'B' && next == '\''){
					
				}
				if (cur == 'R' && next == '\''){
					
				}
				if (cur == 'L' && next == '\''){
					
				}
				//180度
				if (cur == 'U' && next == '2'){
					
				}
				if (cur == 'D' && next == '2'){
					
				}
				if (cur == 'F' && next == '2'){
					
				}
				if (cur == 'B' && next == '2'){
					
				}
				if (cur == 'R' && next == '2'){
					
				}
				if (cur == 'L' && next == '2'){
					
				}
				i++;
			}
			USART_RX_STA = 0;
		}
	 }
}

