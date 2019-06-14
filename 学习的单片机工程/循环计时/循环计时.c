#include<reg52.h>		//52��Ƭ��ϵ��ͷ�ļ�
#define uchar unsigned char//�궨��
#define uint unsigned int

sbit LSA=P2^2;//����138������
sbit LSB=P2^3;
sbit LSC=P2^4;

void delayxms(uint);//��ʱ��������
void saomiao(uchar,uchar);//�����ɨ�躯������
uchar num,num1;//������������
uchar shi,ge;//������������

uchar code table[]={0x3F,0x06,0x5B,0x4F,
					0x66,0x6D,0x7D,0x07,
					0x7F,0x6F,0x77,0x7C,
					0x39,0x5E,0x79,0x71};//��ʾ0~f��ֵ


void main()	//������
{
	TMOD=0X01;//���ö�ʱ��0��Ϊ������ʽ1��0000 0001��
	TH0=(65536-45872)/256;//װ��ֵ
	TL0=(65536-45872)%256;
	EA=1;//�����ж�
	ET0=1;//����ʱ��0�ж�
	TR0=1;//������ʱ��0
	while(1)
	{
		saomiao(shi,ge);
	}
	
	
	
}

void saomiao (uchar shi,uchar ge)//��ʾ�Ӻ���
{	
	LSA=1;LSB=0;LSC=0;//�����ڶ��������
	P0=table[shi];//�Ͷ�ѡ����
	delayxms(5);//��ʱ5����
	LSA=0;LSB=0;LSC=0;//������һ�������
	P0=table[ge];//�����ѡ����
	delayxms(5);//��ʱ5����
}

void delayxms(uint xms)//��ʱ����
{
	uint i,j;
	for (i=xms;i>0;i--)
		for(j=110;j>0;j--);//i=xms����ʱԼxms����
}

void T0_time() interrupt 1//�жϷ�����򣨶�ʱ��0���ж������1��
{
	TH0=(65536-45872)/256;
	TL0=(65536-45872)%256;//��װ��ֵ
	num1++;
	if(num1 == 20)//�������20�Σ�˵��һ���ʱ�䵽
	{
		num1=0;//Ȼ���num1��0�����¼�20��
		num++;
		if(num == 60)//������������������ʾ����60���0 
			num=0;
		shi=num/10;//��һ����λ������󣬷ֱ������������ʾ
		ge=num%10;//ʮλ�͸�λ
		
	}
}