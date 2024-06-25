#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "PWM_Timer0.h"
#include "dcmotor.h"

int main (){

	ADC_ConfigType  ADC_Congiuration = {Internal_Voltage_Reference, F_CPU_8};

	/* initialize DC Motor driver */
	DcMotor_Init();

	/* initialize LCD driver */
	LCD_init();

	/* initialize PWM driver */
	uint8 duty_cycle;
	PWM_Timer0_Start(duty_cycle);


	/* initialize ADC driver */
	ADC_init(&ADC_Congiuration);

	/*A variable to carry the return from the temperature sensor function*/
	uint8 temp_value ;

	LCD_moveCursor(1,0);
	LCD_displayString("Temp =     C ");


	while (1){

		temp_value  = LM35_getTemperature();
		LCD_moveCursor(0,0);

		if (temp_value < 30){

			LCD_displayString("FAN IS OFF ");
			LCD_moveCursor(1,7);

			LCD_intgerToString(temp_value );

			DcMotor_Rotate(STOP, 0);
		}
		else if ((temp_value >= 30) && (temp_value < 60)) {

			LCD_displayString("FAN IS ON ");
			LCD_moveCursor(1,7);

			LCD_intgerToString(temp_value );

			DcMotor_Rotate(CW, 25);
		}
		else if ((temp_value >= 60) && (temp_value < 90)) {

			LCD_displayString("FAN IS ON ");
			LCD_moveCursor(1,7);

			LCD_intgerToString(temp_value );

			DcMotor_Rotate(CW, 50);
		}
		else if ((temp_value >= 90) && (temp_value < 120)) {

			LCD_displayString("FAN IS ON ");
			LCD_moveCursor(1,7);

			LCD_intgerToString(temp_value );

			DcMotor_Rotate(CW, 75);
		}
		else if (temp_value >= 120) {

			LCD_displayString("FAN IS ON ");
			LCD_moveCursor(1,7);

			LCD_intgerToString(temp_value );

			DcMotor_Rotate(CW, 100);

		}
	}
}
