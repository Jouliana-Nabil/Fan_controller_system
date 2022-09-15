 /*===================================================================
 * Module: DC motor
 * File Name: DC_motor.h
 * Description: header file for the DC motor driver
 * Author: Jouliana Nabil
 =====================================================================*/

#ifndef PWM_H_
#define PWM_H_
#include <avr/io.h>
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 /* Description:
  * Control the DC Motor direction using L293D H-bridge.
  * Control The DC Motor Speed using PWM from MC. connect the
  * PWM PIN of Timer0 OC0(PB3) to the enable of the Motor.
  * duty cycle 100% --> Maximum Speed
  * duty cycle 50%  --> Half Maximum Speed
  * duty cycle 0%   --> Motor Stop
  */

void PWM_Timer0_Init (uint8 duty_cycle);


#endif /* PWM_H_ */
