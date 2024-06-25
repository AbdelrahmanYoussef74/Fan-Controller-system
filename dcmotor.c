#include "gpio.h"
#include "dcmotor.h"
#include "PWM_Timer0.h"

void DcMotor_Init(void){

	/*Setup The Direction Of The Pins*/
	GPIO_setupPinDirection(DCMotor_Channel_ID , DCMotor_First_Pin_ID , PIN_OUTPUT);
	GPIO_setupPinDirection(DCMotor_Channel_ID , DCMotor_Second_Pin_ID , PIN_OUTPUT);

	/* Stop at the DC-Motor at the beginning through GPIO Driver*/
	GPIO_writePin(DCMotor_Channel_ID, DCMotor_First_Pin_ID, LOGIC_LOW);
	GPIO_writePin(DCMotor_Channel_ID, DCMotor_Second_Pin_ID, LOGIC_LOW);
}


void DcMotor_Rotate(DcMotor_state state, uint8 speed){

	if (state == ACW ){
		GPIO_writePin(DCMotor_Channel_ID, DCMotor_First_Pin_ID, LOGIC_LOW);
		GPIO_writePin(DCMotor_Channel_ID, DCMotor_Second_Pin_ID, LOGIC_HIGH);
		PWM_Timer0_Start(speed);

	}
	else if(state == CW ){
		GPIO_writePin(DCMotor_Channel_ID, DCMotor_First_Pin_ID, LOGIC_HIGH);
		GPIO_writePin(DCMotor_Channel_ID, DCMotor_Second_Pin_ID, LOGIC_LOW);
		PWM_Timer0_Start(speed);

	}
	else if (state == STOP){
		GPIO_writePin(DCMotor_Channel_ID, DCMotor_First_Pin_ID, LOGIC_LOW);
		GPIO_writePin(DCMotor_Channel_ID, DCMotor_Second_Pin_ID, LOGIC_LOW);
		PWM_Timer0_Start(speed);
	}
}


