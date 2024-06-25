#include "avr/io.h"
#include "PWM_Timer0.h"
#include "gpio.h"
#include "common_macros.h"



void PWM_Timer0_Start(uint8 duty_cycle){

	/*Fast PWM Mode */

	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	/* Non Inverted Mode */

	SET_BIT(TCCR0,COM01);


	/* Select The Prescaler */
	TCCR0 |= Clock_Divide_8;

	/* Set Compare Value*/
	OCR0  = (duty_cycle)/0.4;

	/* Setup The Direction OC0 As An Output */
	GPIO_setupPinDirection(OC0_Port, OC0_Pin, PIN_OUTPUT);

}
