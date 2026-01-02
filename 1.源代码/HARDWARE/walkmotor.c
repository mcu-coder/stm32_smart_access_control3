#include "walkmotor.h"
#include "delay.h"
/********************************
A  	B  	C  		 D
D3 	D5 	D7		 XCLK
PC9 PB6 PE6 	 PA8
********************************/



void Walkmotor_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PB,PE端口时钟

	//GPIO初始化设置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	
}

void Walkmotor_ON(void)
{
#if (CTRLUSE==BJDJ)
	int i;
	for(i=0; i<256; i++)
	{
		Aout=1;Bout=0;Cout=0;Dout=0;delay_ms(3);
		Aout=0;Bout=1;Cout=0;Dout=0;delay_ms(3);
		 
	}Aout=0;Bout=0;Cout=0;Dout=0;
#elif (CTRLUSE==JDQ)
	Cout=1;
#endif
}
	
void Walkmotor_OFF(void)
{
#if (CTRLUSE==BJDJ)
	int i;
	for(i=0; i<256; i++)
	{
		Aout=0;Bout=0;Cout=0;Dout=1;delay_ms(5);
		Aout=0;Bout=0;Cout=1;Dout=0;delay_ms(5);
		 
	}Aout=0;Bout=0;Cout=0;Dout=0;
#elif (CTRLUSE==JDQ)
	Cout=0;
#endif
}
	

