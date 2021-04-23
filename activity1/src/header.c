#include "user_utils.h"

void change_led_state(void)
{
	DDRC |= (1<<PC0);       // SETTING PORT C0 AS OUTPUT PORT
    DDRB &= ~(1<<PB0);      // SETTING PORT B0 AS INPUT PORT
    DDRB &= ~(1<<PB6);      // SETTING PORT B6 AS INPUT PORT
    PORTB |= (1<<PB0);
    PORTB |= (1<<PB6);

    while(1)
    {
        if(((PINB&(1<<PB0))==0)&&((PINB&(1<<PB6))==0))    //IF PIN B0 && PIN B6 IS PRESSED
        {
            PORTC |= (1<<PC0); //TURN ON THE LED
        }
        else
        {
            PORTC &= ~(1<<PC0);  //ELSE TURN OF THE LED
        }
    }
}
