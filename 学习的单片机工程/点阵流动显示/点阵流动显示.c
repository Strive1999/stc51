#include<reg51.h>
#include<intrins.h>

sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;

//--定义要使用的IO口--//
#define COMMONPORTS		P0

//--列选通控制--//
unsigned char code TAB[8]  = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};

//--点阵字码--//
unsigned char code CHARCODE[30][8]=
{

	 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  //动画帧1

     {0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x80},  //动画帧2

     {0x00,0xc0,0x80,0x80,0x80,0x80,0x80,0xc0},  //动画帧3

     {0x00,0xe0,0xc0,0xc0,0xc0,0xc0,0xc0,0xe0},  //动画帧4

     {0x00,0xf0,0x60,0x60,0x60,0x60,0x60,0xf0},  //动画帧5

    {0x00,0x78,0x30,0x30,0x30,0x30,0x30,0x78},  //动画帧6

    {0x00,0x3c,0x18,0x18,0x18,0x18,0x18,0x3c},  //动画帧7

    {0x00,0x1e,0x8c,0x8c,0x8c,0x0c,0x0c,0x1e},  //动画帧8
	
	{0x00,0x0F,0x86,0xC6,0xC6,0xC6,0x86,0x0F},  //动画帧9
 

    {0x00,0xc7,0xe3,0xe3,0xe3,0xc3,0xc3,0x07},  //动画帧10

    {0x00,0x63,0xf1,0xf1,0xf1,0xE1,0xc1,0x83},  //动画帧11

    {0x00,0x31,0xf8,0xf8,0xf8,0xF0,0xe0,0xc1},  //动画帧12

    {0x00,0x98,0xfc,0xfc,0xfc,0xf8,0xf0,0x60},  //动画帧13

    {0x00,0xcc,0xfe,0xfe,0xfe,0xfc,0x78,0x30},  //动画帧14

    {0x00,0x66,0xff,0xff,0xff,0x7e,0x3c,0x18},  //动画帧15

    {0x00,0x33,0x7f,0x7f,0x7f,0x3f,0x1e,0x0c},  //动画帧16

    {0x00,0x19,0x3f,0x3f,0x3f,0x1f,0x0f,0x06},  //动画帧17

    {0x00,0x8c,0x9f,0x9f,0x9f,0x8f,0x87,0x03},      //动画帧18

    {0x00,0xc6,0xcf,0xcf,0xcf,0xc7,0xC3,0x81},  //动画帧19

    {0x00,0x63,0x67,0x67,0x67,0x63,0xe1,0xc0},  //动画帧20

    {0x00,0x31,0x33,0x33,0x33,0x31,0xf0,0xe0},  //动画帧21

    {0x00,0x98,0x99,0x99,0x99,0x98,0xf8,0xf0},  //动画帧22

    {0x00,0xcc,0xcc,0xcc,0xcc,0xcc,0xfc,0x78},  //动画帧23

    {0x00,0x66,0x66,0x66,0x66,0x66,0x7e,0x3c},  //动画帧24

    {0x00,0x33,0x33,0x33,0x33,0x33,0x3f,0x1e},  //动画帧25

    {0x00,0x19,0x19,0x19,0x19,0x19,0x1f,0x0f},  //动画帧26

    {0x00,0x0c,0x0c,0x0c,0x0c,0x0c,0x0f,0x07},  //动画帧27

    {0x00,0x06,0x06,0x06,0x06,0x06,0x07,0x03},  //动画帧28

    {0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x01},  //动画帧29

    {0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00}   //动画帧30

};
void delay(unsigned int time)
{
  unsigned int i,j;
  for(i=0;i<time;i++)
    for(j=0;j<110;j++);
}

/*******************************************************************************
* 函数名         : Hc595SendByte(unsigned char dat)
* 函数功能		   : 想74H595发送一个字节的数据
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
void Hc595SendByte(unsigned char dat)
{
	unsigned char a;
	SRCLK=0;
	RCLK=0;
	for(a=0;a<8;a++)
	{
		SER=dat>>7;
		dat<<=1;

		SRCLK=1;
		_nop_();
		_nop_();
		SRCLK=0;	
	}

	RCLK=1;
	_nop_();
	_nop_();
	RCLK=0;
}
/*******************************************************************************
* 函数名         : main
* 函数功能		   : 主函数
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/

void main()
{	
 	unsigned char tab, j;
	unsigned int  i;

	while(1)
	{	
		for(i= 0; i<20; i++ )   //两个字之间的扫描间隔时间
		{
			for(tab=0;tab<8;tab++)
			{	

				Hc595SendByte(0x00);			     //消隐																
				COMMONPORTS	= TAB[tab];				 //输出字码	
				Hc595SendByte(CHARCODE[j][tab]);	
				delay(2);		
			}
			 
		}
		j++;
		if(j == 30)
		{
			j = 0;
		}
	}	
}
