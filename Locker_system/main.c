/*
 * Locker_system.c
 *
 * Created: 11/25/2022 7:50:49 AM
 * Author : Ve-ga
 */ 

#include "locker_sys.h"
int main(void)
{
    LCD_init();
	KEYPAD_init();	
	SETBIT(DDRB,0);  // for LED
	SETBIT(DDRB,1);  // for Buzzer
	
    while (1) 
    {
		if(eeprom_read(4) == 1){
			Open_State();
			
		}
		else if(eeprom_read(4) == 0){
			Close_State();
		}
		else{
			Chang_Password();	
		}
    }
}
