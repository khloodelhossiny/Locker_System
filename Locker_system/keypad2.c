/*
 * keypad2.c
 *
 * Created: 11/25/2022 8:03:03 AM
 *  Author: Ve-ga
 */ 

#include "Keypad2.h"
#include "Keypad2_cfg.h"

uint8_t const keypad_matrix[] = {
	'1','2','3',
	'4','5','6',
	'7','8','9',
	'*','0','#'
	};	

void KEYPAD_init(void){
	INIT_KEYPAD_PINS();
	
}
int8_t KEYPAD_read(void){
	K4(0);K5(1);K6(1);K7(1);
	if(K0() == 0) return keypad_matrix[0];
	if(K1() == 0) return keypad_matrix[1];
	if(K2() == 0) return keypad_matrix[2];
	//if(K3() == 0) return keypad_matrix[3];
	_delay_ms(5);
	
	K4(1);K5(0);K6(1);K7(1);
	if(K0() == 0) return keypad_matrix[3];
	if(K1() == 0) return keypad_matrix[4];
	if(K2() == 0) return keypad_matrix[5];
	//if(K3() == 0) return keypad_matrix[7];
	_delay_ms(5);
	
	K4(1);K5(1);K6(0);K7(1);
	if(K0() == 0) return keypad_matrix[6];
	if(K1() == 0) return keypad_matrix[7];
	if(K2() == 0) return keypad_matrix[8];
	//if(K3() == 0) return keypad_matrix[11];
	_delay_ms(5);
	
	K4(1);K5(1);K6(1);K7(0);
	if(K0() == 0) return keypad_matrix[9];
	if(K1() == 0) return keypad_matrix[10];
	if(K2() == 0) return keypad_matrix[11];
	//if(K3() == 0) return keypad_matrix[15];
	_delay_ms(5);
	
	
	
	return -1;
}