/******************************************************************************
 * File Name: Mini_project_3_main.c
 * Description: The main Source file of the project
 * Author: Jouliana Nabil
 *******************************************************************************/
#include <avr/io.h>
#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "DC_motor.h"

int main(void){
	uint8 temp;
	LCD_init(); /* initialize LCD driver */

	ADC_ConfigType configure = { Internal , P_8 };
	ADC_init(&configure);

	DcMotor_Init(); /*initialize DC_motor driver */
	LCD_displayStringRowColumn(0,4,"FAN IS ");
	LCD_displayStringRowColumn(1,3,"Temp is ");

	while(1){

		temp = LM35_getTemperature();
		LCD_moveCursor(1,11);
		if (temp > 100)
		{
			LCD_intgerToString(temp);
		}
		else {
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}

		if (temp<30){
			LCD_displayStringRowColumn(0,11,"OFF");
			DcMotor_Rotate(DCMotor_stop,0);
		}

		if ((temp>=30) && (temp <60)){
			LCD_displayStringRowColumn(0,11,"ON ");
			DcMotor_Rotate(DCMotor_CW,25);
		}

		if ((temp>=60) && (temp <90) ){
			LCD_displayStringRowColumn(0,11,"ON ");
			DcMotor_Rotate(DCMotor_CW,50);
		}

		if ((temp>=90)&& (temp <120) ){
			LCD_displayStringRowColumn(0,11,"ON ");
			DcMotor_Rotate(DCMotor_CW,75);
		}

		if (temp>=120){
			LCD_displayStringRowColumn(0,11,"ON ");
			DcMotor_Rotate(DCMotor_CW,100);
		}

	}
}

