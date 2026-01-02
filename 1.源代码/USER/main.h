#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "usart2.h"
#include "oled.h"
#include "button4_4.h"
#include "beep.h"
#include "MFRC522.h"
#include "rtc.h" 	
#include "stmflash.h"
#include "as608.h"
#include "walkmotor.h"

typedef struct 
{
	u32 HZCFlag;
	u8 passwd1[7];
	u8 passwd2[7];
	u8 cardid[10][6];
	u8 errCnt;//错误计数
	u8 errTime;//等待错误时间
}SysTemPat;


extern SysTemPat sys;

#define SYS_SAVEADDR 0x0800f000


