/*
 * calculator.c
 *
 *  Created on: Dec 5, 2021
 *      Author: Menna
 */
#include "lcd.h"
#include "keypad.h"

int result , sign , num1=0 , num2=0 , a =0 , b=0 , check1=0 , check2=0;

int main(void)
{
	unsigned char key;
	LCD_init();

    while(1)
    {
		/* if any switch pressed for more than 500 ms it counts more than one press */
    	while(check1 == 0){
		num1 = KeyPad_getPressedKey(); /* get the pressed key number */
		if((num1 <= 9) && (num1 >= 0))
		{
			LCD_intgerToString(num1); /* display the pressed keypad switch */
			a = a*10 + num1;
		}
		else{
			check1 =1;
			sign = num1;
			LCD_displayCharacter(sign);
		}
		_delay_ms(500); /* Press time */

    	}

		while(check2 == 0){
		num2 = KeyPad_getPressedKey(); /* get the pressed key number */
		if((num2 <= 9) && (num2 >= 0))
		{
			LCD_intgerToString(num2); /* display the pressed keypad switch */
			b = b*10 + num2;
		}
		else{
			check2 = 1;
			break;
		}
		_delay_ms(500); /* Press time */
		}

    if(KeyPad_getPressedKey() == '='){
		switch (sign){

		case '+':	result = a + b;
					LCD_goToRowColumn(3,0);
					LCD_intgerToString(result);
					break;

		case '-':   result = a - b;
					LCD_goToRowColumn(3,0);
					LCD_intgerToString(result);
					break;

		case '*':   result = a * b;
					LCD_goToRowColumn(3,0);
					LCD_intgerToString(result);
					break;

		case '%':   result = a / b;
					LCD_goToRowColumn(3,0);
					LCD_intgerToString(result);
					break;

		}

		}

    if(KeyPad_getPressedKey() == 'x'){
    	num1=0 , num2=0 , a =0 , b=0 , check1=0 , check2=0;
    	 LCD_clearScreen();
 		_delay_ms(500); /* Press time */

    }
    }
}

