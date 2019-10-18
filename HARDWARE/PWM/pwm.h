#ifndef __PWM_H
#define __PWM_H
#include "sys.h"

//servo
extern u16  degree1,degree2;
//motor
extern u16 speed;

void two_servo_init(u16 arr,u16 psc);
void two_motor_init(u16 arr,u16 psc);
void servo_1(u8);
void servo_2(u8);
void motor_1_90();
void motor_1_180();
void motor_2_90();
void motor_2_180();
#endif
