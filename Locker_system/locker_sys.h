/*
 * locker_sys.h
 *
 * Created: 11/30/2022 6:50:45 PM
 *  Author: Ve-ga
 */ 


#ifndef LOCKER_SYS_H_
#define LOCKER_SYS_H_

#include "std_macros.h"
#include "lcd.h"
#include "keypad.h"
#include "eeprom.h"
void Open_State(void);
void Close_State(void);
void Chang_Password(void);
uint8_t get_input_from_user(void);



#endif /* LOCKER_SYS_H_ */