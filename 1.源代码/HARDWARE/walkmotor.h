#ifndef _WALKMOTOR_H
#define _WALKMOTOR_H
#include "sys.h"
/********************************
A  	B  	C  		 D
D3 	D5 	D7		 XCLK
PC9 PB6 PE6 	 PA8
********************************/
#define  Aout  PAout(15) 
#define  Bout  PAout(12)
#define  Cout  PBout(11)
#define  Dout  PBout(10)

#define BJDJ  1
#define JDQ   2
#define CTRLUSE  BJDJ

void Walkmotor_Init(void);
void Walkmotor_ON(void);
void Walkmotor_OFF(void);
	
#endif
