#include "pwm.h"
#include "led.h"

void two_servo_init(u16 arr,u16 psc)
{  
	 GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	                                                                     	

 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9; //TIM_CH1/CH2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	
	TIM_TimeBaseStructure.TIM_Period = arr;
	TIM_TimeBaseStructure.TIM_Prescaler =psc;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);

  TIM_CtrlPWMOutputs(TIM1,ENABLE);

	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM1, ENABLE);
	
	TIM_Cmd(TIM1, ENABLE);
 
   
}

void two_motor_init(u16 arr,u16 psc){
	GPIO_InitTypeDef GPIO_InitStructure;
	//NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB,ENABLE); //使能PORTB时钟 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2|RCC_APB1Periph_TIM3,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
 	TIM_TimeBaseStructure.TIM_Period = arr; //设定计数器自动重装值  
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 	//预分频器	   
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
	
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	
  TIM_CtrlPWMOutputs(TIM2,ENABLE);
	TIM_CtrlPWMOutputs(TIM3,ENABLE);
	
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM2, ENABLE);
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	
	TIM_Cmd(TIM2, ENABLE);
	TIM_Cmd(TIM3, ENABLE);
}
u16 degree1,degree2;
u16 speed;
void servo_1(u8 dir){
	if(dir){
		TIM_SetCompare1(TIM1,degree1);
	}
		TIM_SetCompare1(TIM1,degree2);
}
void servo_2(u8 dir){
	if(dir){
		TIM_SetCompare2(TIM1,degree1);
	}else{
		TIM_SetCompare2(TIM1,degree2);
	}
}

void motor_1(){
		TIM_SetCompare1(TIM2,speed);
		TIM_SetCompare1(TIM2,0);
		TIM_SetCompare2(TIM2,speed);
		TIM_SetCompare2(TIM2,0);
		TIM_SetCompare3(TIM2,speed);
		TIM_SetCompare3(TIM2,0);
		TIM_SetCompare4(TIM2,speed);
		TIM_SetCompare4(TIM2,0);
}
void motor_1_r(){
		TIM_SetCompare4(TIM2,speed);
		TIM_SetCompare4(TIM2,0);
		TIM_SetCompare3(TIM2,speed);
		TIM_SetCompare3(TIM2,0);
		TIM_SetCompare2(TIM2,speed);
		TIM_SetCompare2(TIM2,0);
		TIM_SetCompare1(TIM2,speed);
		TIM_SetCompare1(TIM2,0);
}
void motor_2(){
		TIM_SetCompare1(TIM3,speed);
		TIM_SetCompare1(TIM3,0);
		TIM_SetCompare2(TIM3,speed);
		TIM_SetCompare2(TIM3,0);
		TIM_SetCompare3(TIM3,speed);
		TIM_SetCompare3(TIM3,0);
		TIM_SetCompare4(TIM3,speed);
		TIM_SetCompare4(TIM3,0);
}
void motor_2_r(){
		TIM_SetCompare4(TIM3,speed);
		TIM_SetCompare4(TIM3,0);
		TIM_SetCompare3(TIM3,speed);
		TIM_SetCompare3(TIM3,0);
		TIM_SetCompare2(TIM3,speed);
		TIM_SetCompare2(TIM3,0);
		TIM_SetCompare1(TIM3,speed);
		TIM_SetCompare1(TIM3,0);
}
