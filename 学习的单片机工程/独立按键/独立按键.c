#include<reg52.h>	//52ϵ�е�Ƭ��ͷ�ļ�
#include<intrins.h>
#define uint unsigned int//���������ͽ�������
#define uchar unsigned char
#define led P2
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit k1=P3^1;//����P31����k1
sbit k2=P3^0;
uchar ;num;
uchar code smgduan[]={0x30,0x38,0x3f,0x3e,0x79,0x6e,0x3f,0x3e};
uint i,j;
void delayxms(uint xms)//��ʱ����������xms���뼴��ʱxms
	{	
		for(i=xms;i>0;i--)
			for(j=110;j>0;j--);
	}
	
void DigDisplay()//��̬�����ɨ�躯����ѭ��ɨ��8���������ʾ
{
	uchar i;
	for(i=0;i<8;i++)
	{
		switch(i)	 //λѡ��ѡ�����������ܣ�
		{
			case(7):
				LSA=0;LSB=0;LSC=0; break;//��ʾ��0λ
			case(6):
				LSA=1;LSB=0;LSC=0; break;//��ʾ��1λ
			case(5):
				LSA=0;LSB=1;LSC=0; break;//��ʾ��2λ
			case(4):
				LSA=1;LSB=1;LSC=0; break;//��ʾ��3λ
			case(3):
				LSA=0;LSB=0;LSC=1; break;//��ʾ��4λ
			case(2):
				LSA=1;LSB=0;LSC=1; break;//��ʾ��5λ
			case(1):
				LSA=0;LSB=1;LSC=1; break;//��ʾ��6λ
			case(0):
				LSA=1;LSB=1;LSC=1; break;//��ʾ��7λ	
			
		}		
		P0=smgduan[i];//���Ͷ���
		delayxms(500);  //���һ��ʱ��ɨ��	
		P0=0x00;      //����
	}
}


void key()//�������������жϰ���k1�Ƿ���
{
	
		if(k1==0);//���k1�Ƿ���
		{
			delayxms(10);//��������һ���Լ10ms
			if(k1==0)//�ٴ��жϰ����Ƿ���
				{	
					uchar i;
					led=0xfe;
					for(i=0;i<7;i++)
						{
							led=_crol_(led,1);			//ѭ������
							delayxms(100);
						}
				
					for(i=0;i<7;i++)
						{
							led=_cror_(led,1);//ѭ������
							delayxms(100);//��ʱ100ms
						}
				while(!k1);
				}
		
		}
		
		if(k2==0);
		{
			delayxms(10);
			if(k2==0)
			{
				DigDisplay();
			}
		while(!k2);			
		}
		
}


void main()
{
	while(1)
		{
				key();//����������
			
		}
}