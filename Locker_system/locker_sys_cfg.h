/*
 * locker_sys_cfg.h
 *
 * Created: 11/30/2022 11:11:35 PM
 *  Author: Ve-ga
 */ 


#ifndef LOCKER_SYS_CFG_H_
#define LOCKER_SYS_CFG_H_

#include "std_macros.h"
#define set_password()	for(int i = 0; i < 4; i++){eerpom_write(i, '0');}
#define led_on() SETBIT(PORTB,0)
#define led_off() CLRBIT(PORTB,0)
#define Buzzer_on() SETBIT(PORTB,1);
#define Buzzer_off() CLRBIT(PORTB,1);





#endif /* LOCKER_SYS_CFG_H_ */