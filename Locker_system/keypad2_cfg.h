/*
 * keypad2_cfg.h
 *
 * Created: 11/25/2022 8:03:36 AM
 *  Author: Ve-ga
 */ 


#ifndef KEYPAD2_CFG_H_
#define KEYPAD2_CFG_H_
#include "std_macros.h"

#define INIT_KEYPAD_PINS() DDRC = 0xf0; PORTC = 0xff;

#define K0() READBIT(PINC,0)
#define K1() READBIT(PINC,1)
#define K2() READBIT(PINC,2)
//#define K3() READBIT(PINC,3)
#define K4(x) if(x == 1) SETBIT(PORTC,4); else CLRBIT(PORTC,4);
#define K5(x) if(x == 1) SETBIT(PORTC,5); else CLRBIT(PORTC,5);
#define K6(x) if(x == 1) SETBIT(PORTC,6); else CLRBIT(PORTC,6);
#define K7(x) if(x == 1) SETBIT(PORTC,7); else CLRBIT(PORTC,7);




#endif /* KEYPAD2_CFG_H_ */