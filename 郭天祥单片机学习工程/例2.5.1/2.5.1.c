#include<reg52.h>			//52ϵ�е�Ƭ��ͷ�ļ�
#define uint unsigned int	//�궨��
sbit led1=P2^0;				//������Ƭ��P1�ڵĵ�һλ
void delayxms(uint);
void main()					//������
{
	while(1)
		{
			led1=0;						/*������һ�����������*/
			delayxms(500);	
			led1=1;						/*�رյ�һ�����������*/
			delayxms(1000);
		}
}
void delayxms(uint xms)
	{   uint i,j;
		for(i=xms;i>0;i--)			
			for(j=110;j>0;j--);
	}