#include<reg52.h>					//52ϵ�е�Ƭ��ͷ�ļ�

#define uint unsigned int //�궨��,��������
#define uchar unsigned char

sbit LSA=P2^2;		//�Ĵ�������
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit k1=P3^1;
sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;

uchar code smgduan[]={0x3F,0x06,0x5B,0x4F,
											0x66,0x6D,0x7D,0x07,
											0x7F,0x6F,0x77,0x7C,
											0x39,0x5E,0x79,0x71};//��ʾ0~F��ֵ

void delayxms(uint);			//��ʱ��������
uchar numt0,num;					//������������
void display(uchar numdis)//�������ʾ����
{
	uchar shi,ge;						//������������
	shi=numdis/10;					//��һ����λ������󣬷ֱ������������ʾ
	ge=numdis%10;						//ʮλ�͸�λ
	LSA=1;
	LSB=0;
	LSC=0;									//���ڶ�λ����ܵ���
	P0=smgduan[shi];
	delayxms(5);						//��ʱ5����
	LSA=0;
	LSB=0;
	LSC=0;									//������һλ�����
	P0=smgduan[ge];
	delayxms(5);						//��ʱ5����
}

void delayxms(uint xms)		//��ʱ����
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);		//��ʱԼxms����
}

void init()				//��ʼ������
{
	TMOD=0X01;			//���ö�ʱ��0Ϊ������ʽ1
	TH0=0X4C;				//װ��ֵ50�����ж�һ��
	TL0=0X00;
	EA=1;						//�����ж�
	ET0=1;					//����ʱ��0�ж�
}

void key()							//����������
{
	if(k1==0)							//��ⰴ��1�Ƿ���
	{
		delayxms(10);				//����ȥ��
		if(k1==0)						//�ٴμ�ⰴ��1�Ƿ���
		{
			num++;						//num����1
			if(num==60)				//��num��60ʱ���¹�0
			num=0;
			while(!k1);				//�ȴ������ͷ�
		}
	}
	
	if(k2==0)							//��ⰴ��2�Ƿ���
	{
		delayxms(10);				//����ȥ����Լ10����
		if(k2==0)						//�ٴμ�ⰴ��2�Ƿ���
		{
			if(num==0)				//��num��0ʱ���»ع�60
				num=60;
				num--;					//nun��һ
				while(!k2);			//�ȴ������ͷ�
		}
	}
	
	if(k3==0)							//��ⰴ��3�Ƿ���
	{
		delayxms(10);				//��ʱ10���룬ȥ����������
		if(k3==0)						//�ٴμ�ⰴ�����Ƿ���
			{
				num=0;					//num����
				while(!k3);			//�ȴ������ͷ�
			}
	}
	
	if(k4==0)							//��ⰴ��4�Ƿ���
	{
		delayxms(10);				//��ʱԼ10���룬ȥ������
		if(k4==0)						//�ٴμ�ⰴ��4�Ƿ�����
		{	
			while(!k4);				//�ȴ�����4�ͷ�
			TR0=~TR0;					//������ֹͣ��ʱ��0
		}
	}
}

void main()				//������
{
	init();					//���ó�ʼ������
	while(1)
	{
		key();				//���ð���������
		display(num); //���������ɨ�躯��
	}
}

void t0_time()interrupt 1	//�жϺ���
{
	TH0=0X4C;								//��װ��ֵ
	TL0=0X00;
	numt0++;
	if(numt0==20)						//���numt0������20������1���ʱ���ѵ�
	{
		numt0=0;							//Ȼ���numt0���㣬���¼�ʱ
		num++;
		if(num==60)						//���num������60��num����
		num=0;
	}
}