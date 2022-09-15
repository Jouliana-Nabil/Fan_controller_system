/*================================================================
 * Module: DC_motor
 * File Name: DC_motor.c
 * Description: Source file for the DC motor driver
 * Author: Jouliana Nabil
 ==================================================================*/
#include <avr/io.h>
#include "gpio.h"
#include "DC_motor.h"
#include "std_types.h"
#include "pwm.h"

/*
 * Description: Setup the direction for the two motor pins through the GPIO driver
 * Stopped DC motor at the beginning
 * No INPUTS
 * No Return
 */
void DcMotor_Init(void) {
	GPIO_setupPinDirection(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID , PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
}

/*
 * Description: responsible for rotate the DC Motor CW or A/CW
 * or stop the motor based on the state input state value
 * Send the required duty cycle to the PWM driver based on the required speed value.
 * INPUTS :
 * state: The required DC Motor state, it should be CW or A-CW or stop
 * speed: decimal value for the required motor speed, it should be from 0 to 100
 * No Return
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed) {

	uint8 duty_cycle= (uint8)(((uint16)255*speed)/100);
	PWM_Timer0_Init(duty_cycle);

	switch(state)
	{
	case DCMotor_CW:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_HIGH);
		break;
	case DCMotor_ACW:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	case DCMotor_stop:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	}
}
