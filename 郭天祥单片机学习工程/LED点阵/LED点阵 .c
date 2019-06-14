
//�ð����ϵĵ���Ϊ8*8��ֻ����ʾ�򵥵�һЩ���ӣ����Ҫ��ʾ�����ĺ���
//ͨ��ȡģ���ȡ�Ŀ���ѡ��16*16����İ���

#include<reg51.h>
#include<intrins.h>

sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;

//--����Ҫʹ�õ�IO��--//
#define COMMONPORTS		P0

//--��ѡͨ����--//
unsigned char code TAB[8]  = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};

//--��������--//
unsigned char code CHARCODE[5][8]=
{
							0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, 
							0xC3,0xE7,0xE7,0xE7,0xE7,0xE7,0xC3,0xFF, 
							0x99,0x00,0x00,0x00,0x81,0xC3,0xE7,0xFF,
							0x99,0x99,0x99,0x99,0x99,0x81,0xC3,0xFF,
							0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};
void delay(unsigned int time)
{
  unsigned int i,j;
  for(i=0;i<time;i++)
    for(j=0;j<121;j++);
}

/*******************************************************************************
* ������         : Hc595SendByte(unsigned char dat)
* ��������		   : ��74H595����һ���ֽڵ�����
* ����           : ��
* ���         	 : ��
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
* ������         : main
* ��������		   : ������
* ����           : ��
* ���         	 : ��
*******************************************************************************/

void main()
{	
 	unsigned char tab, j;
	unsigned int  i;

	while(1)
	{	
		for(i= 0; i<50; i++ )   //������֮���ɨ����ʱ��
		{
			for(tab=0;tab<8;tab++)
			{	

				Hc595SendByte(0x00);			     //����																
				COMMONPORTS	= TAB[tab];				 //�������	
				Hc595SendByte(CHARCODE[j][tab]);	
				delay(2);		
			}
			 
		}
		j++;
		if(j == 4)
		{
			j = 0;
		}
	}	
}
