/*
 * locker.c
 *
 * Created: 11/30/2022 5:30:34 PM
 *  Author: Ve-ga
 */ 
/*#include "locker.h"
uint8_t input_pass[5], zero_conuter = 0, key, password_right = 0;
void Open_State(void){
	SETBIT(PORTB,0); // green
	key = get_input_from_user();
	if(key == '0'){
		zero_conuter++;
	}
	if(zero_conuter == 10){
		set_password();
		//open_state = 2;  // no password
		eerpom_write(4,2);
		LCD_write_command(1);
		zero_conuter = 0;
	}
	if(key == '*'){
		//open_state = 0;  //close state
		eerpom_write(4,0);
		LCD_write_command(1);
		zero_conuter = 0;
	}
	LCD_write_char('F');
}
void Close_State(void){
	CLRBIT(PORTB,0);
	password_right = 1;
	for(int i = 0; i < 4; i++){
		input_pass[i] = get_input_from_user();
		if(input_pass[i] != eeprom_read(i)){ // check if right password
			password_right = 0;
		}
	}
	if(password_right == 1){
		//open_state = 1;
		eerpom_write(4,1);
		SETBIT(PORTB,0);
	}
	else{
		// active_buzzer for 3sec
		LCD_write_command(1);
	}
	zero_conuter = 0;
}
void Chang_Password(void){
	// set new password;
	SETBIT(PORTB,0);
	key = get_input_from_user();
	if(key == '/'){
		for(int i = 0; i < 4; i++){
			input_pass[i] = get_input_from_user();
		}
	}
	key = get_input_from_user();
	if(key == '/'){  // save password
		for(int i = 0; i < 4; i++){
			eerpom_write(i, input_pass[i]);
		}
		//	open_state = 1;
		eerpom_write(4,1);
	}
	zero_conuter = 0;
}
uint8_t get_input_from_user(){
	int8_t key;
	do{
		key = KEYPAD_read();
	}while(key == -1);
	LCD_write_char(key);
	while(KEYPAD_read() != -1){}
	return key;
}
*/