#include<lpc21xx.h>
#include "delay.h"
#define LCD_DATAPINS 0xff<<0
#define RS 1<<8
#define E 1<<9
void init(void);
void command(unsigned char);
void data(unsigned char);
void init(void){
IODIR0=LCD_DATAPINS|RS|E;
command(0X01);
command(0X02);
command(0X0C);
command(0X38);
}
void command(unsigned char cmd){
IOCLR0=LCD_DATAPINS;
IOSET0=cmd;
IOCLR0=RS;
IOSET0=E;
milliseconds(2);
IOCLR0=E;
}
void data(unsigned char d){
IOCLR0=LCD_DATAPINS;
IOSET0=d;
IOSET0=RS;
IOSET0=E;
milliseconds(2);
IOCLR0=E;
}
void string(unsigned char*s){
char pos=0;
while(*s){
data(*s++);
pos++;
if(pos==16)
command(0xc0);
}
}

