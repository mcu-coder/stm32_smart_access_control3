#include "button4_4.h"
#include <delay.h>
#include "usart.h"


struct io_port
{                                            
        GPIO_TypeDef *GPIO_x;                 
        unsigned short GPIO_pin;
};
static struct io_port key_output[4] = {
        {GPIOB, GPIO_Pin_0}, {GPIOB, GPIO_Pin_1},
        {GPIOA, GPIO_Pin_11}, {GPIOB, GPIO_Pin_3}
};
static struct io_port key_input[4] = {
        {GPIOB, GPIO_Pin_4}, {GPIOB, GPIO_Pin_5},
        {GPIOB, GPIO_Pin_6}, {GPIOB, GPIO_Pin_7}
};
unsigned char key[4][4];
void Button4_4_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    unsigned char i;
	
//    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); 

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO, ENABLE);         
   
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); 

  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
                      
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1| GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	  GPIO_Init(GPIOA, &GPIO_InitStructure);

        for(i = 0; i < 4; i++)
        {
          GPIO_SetBits(key_output[i].GPIO_x, key_output[i].GPIO_pin);
        }
}
int Button4_4_Scan(void)
{
        unsigned char i, j;
        for(i = 0; i < 4; i++)            
        {
          delay_ms(5);
					GPIO_ResetBits(key_output[i].GPIO_x, key_output[i].GPIO_pin);   
          for(j = 0; j < 4; j++)            
          {
                  delay_ms(5); 
						      if(GPIO_ReadInputDataBit(key_input[j].GPIO_x, key_input[j].GPIO_pin) == 0)
                   {
                                key[i][j] = 1;
                   }else{
                                key[i][j] = 0;
                   }
          }
          GPIO_SetBits(key_output[i].GPIO_x, key_output[i].GPIO_pin);
        }
        if(key[0][0]==1)return 13;
        else if(key[0][1]==1)return 14;
        else if(key[0][2]==1)return 15;
        else if(key[0][3]==1)return 16;
        else if(key[1][0]==1)return 9;
        else if(key[1][1]==1)return 10;
        else if(key[1][2]==1)return 11;
        else if(key[1][3]==1)return 12;
        else if(key[2][0]==1)return 5;
        else if(key[2][1]==1)return 6;
        else if(key[2][2]==1)return 7;
        else if(key[2][3]==1)return 8;
        else if(key[3][0]==1)return 1;
        else if(key[3][1]==1)return 2;
        else if(key[3][2]==1)return 3;
        else if(key[3][3]==1)return 4;
				
				else return -1;
				
       
}


