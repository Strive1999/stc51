#include<reg52.h>
#define uint unsigned int
#define uhar unsigned char
sbit led=P2^1;
uchar; num;
void main()
	{
		TMOD=0x01;	//���ö�ʱ��0�Ĺ�����ʽΪ1��m0m1Ϊ01��
		TH0=0x4c;	//װ��ֵ11.0592M���񣬶�ʱ50ms
		TL0=0x00;
		EA=1;		//�����ж�
		ET0=1;		//����ʱ��0�ж�	
		TR0=1;		//������ʱ��0
		while(1)	//����ֹͣ������ȴ��жϷ���
		{
			if(num==20)		//�������20�Σ�˵��1���ʱ�䵽
				{
					num=0;	//Ȼ���num���㣬���¼���20��
					led=~led;//�÷����״̬ȡ��
				}	
		}
	}
	
void T0_time()interrupt 1
	{
		TH0=0x4c;		//��װ��ֵ
		TL0=0x00;
		num++;			//numÿ��1�Σ��ж�һ���Ƿ񵽴�20��
	}