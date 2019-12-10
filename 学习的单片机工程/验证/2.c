#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define led P2
uchar i,j;

void delayxms(uint);
void main()
{
	IT0=1;//�����س�����ʽ���½��أ�
	EX0=1;//��INT0���ж�����	
	EA=1;//�����ж�
	led=0x00;
	while(1)
	{
		if(1==j)
		{		
			for(i=0;i<7;i++)
			{			
				led=_crol_(led,1);	
				delayxms(300);
			}
		}
	}
}

void INT0_time()interrupt 0
{
		j++;
		if(1==j)
		{
			led=0xfe;
			for(i=0;i<7;i++)
			{
				led=_crol_(led,1);	
				delayxms(300);
			}
		}
		else if(2==j)
		{
			led=0xff;
			j=0;
		}
}

void delayxms(uint xms)
{	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}