/*
 * locker_sys.c
 *
 * Created: 11/30/2022 6:49:57 PM
 *  Author: Ve-ga
 */
#include "locker_sys.h" 
#include "locker_sys_cfg.h"
uint8_t input_pass[5], zero_conuter = 0, key, password_right = 0, wr_mes[] = "Failed", suc_mes[] = "Successful", Don_mes[] = "Done";
void Open_State(void){
	led_on();
	key = get_input_from_user();
	if(key == '0'){
		zero_conuter++;
	}
	if(zero_conuter == 10){
		set_password();
		//open_state = 2; | no password
		eerpom_write(4,2);
		LCD_write_command(1);
		zero_conuter = 0;
	}
	if(key == '*'){
		//open_state = 0; | close state
		eerpom_write(4,0);
		LCD_write_command(1);
		zero_conuter = 0;
	}
}
void Close_State(void){
	led_off();
	password_right = 1;
	for(int i = 0; i < 4; i++){
		input_pass[i] = get_input_from_user();  // check if right password
		if(input_pass[i] != eeprom_read(i)){    
			password_right = 0;
		}
	}
	if(password_right == 1){
		//open_state = 1;
		led_on();
		eerpom_write(4,1);	
		LCD_write_command(1);
		LCD_write_string(suc_mes);
	}
	else{
		LCD_write_command(1);
		LCD_write_string(wr_mes);
		Buzzer_on();
		_delay_ms(400);
		Buzzer_off();
		
	}
	_delay_ms(300);
	LCD_write_command(1);
	zero_conuter = 0;
}
void Chang_Password(void){
	// set new password;
	led_on();
	eerpom_write(4, 2);
	key = get_input_from_user();
	if(key == '*'){
		//open_state = 0; | close state
		eerpom_write(4, 0);
		LCD_write_command(1);
		zero_conuter = 0;
		return;
	}
	if(key == '/'){
		for(int i = 0; i < 4; i++){
			input_pass[i] = get_input_from_user();
		}
	}
	key = get_input_from_user();
	if(key == '*'){
		//open_state = 0;  | close state
		eerpom_write(4, 0);
		LCD_write_command(1);
		zero_conuter = 0;
		return;
	}
	if(key == '/'){  // save password
		for(int i = 0; i < 4; i++){
			eerpom_write(i, input_pass[i]);
		}
		//	open_state = 1;
		eerpom_write(4, 1);
		LCD_write_command(1);
		LCD_write_string(Don_mes);
	}
	_delay_ms(300);
	LCD_write_command(1);
	zero_conuter = 0;
}
uint8_t get_input_from_user(){
	int8_t key;
	do{
		key = KEYPAD_read();
	}while(key == -1);
	
	if(key == '/'){
		LCD_write_char(key);
	}
	else{
		LCD_write_char('*');
	}
	while(KEYPAD_read() != -1){}
	return key;
}