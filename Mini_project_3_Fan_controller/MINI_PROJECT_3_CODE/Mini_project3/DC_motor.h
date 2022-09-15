 /*===================================================================
 * Module: DC motor
 * File Name: DC_motor.h
 * Description: header file for the DC motor driver
 * Author: Jouliana Nabil
 =====================================================================*/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define DC_MOTOR_IN1_PORT_ID                 PORTB_ID
#define DC_MOTOR_IN1_PIN_ID                  PIN4_ID

#define DC_MOTOR_IN2_PORT_ID                 PORTB_ID
#define DC_MOTOR_IN2_PIN_ID                  PIN5_ID

#define DC_MOTOR_EN1_PORT_ID                 PORTB_ID
#define DC_MOTOR_EN1_PIN_ID                  PIN3_ID

typedef enum
{
DCMotor_CW, DCMotor_ACW,DCMotor_stop
}DcMotor_State;



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * Description: Setup the direction for the two motor pins through the GPIO driver
 * Stopped DC motor at the beginning
 * No INPUTS
 * No Return
 */
void DcMotor_Init(void);

/*
 * Description: responsible for rotate the DC Motor CW or A/CW
 * or stop the motor based on the state input state value
 * INPUTS :
 * state: The required DC Motor state, it should be CW or A-CW or stop
 * speed: decimal value for the required motor speed, it should be from 0 to 100
 * No Return
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
