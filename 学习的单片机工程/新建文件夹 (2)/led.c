////оƬA����
//#include <reg52.h>
//#define uint unsigned int
//#define uchar unsigned char
//	
//uint num=0;	//����
//uchar i=0;

//void time0_init()
//{
//	TMOD=0X01;
//	TH0=(65535-50000)/256;//��ʱ50ms
//	TL0=(65535-50000)%256;
//	TR0=1;
//	ET0=1;
//	EA=1;//��ȫ���ж�
//}
//	
//void uart_init()//���ڳ�ʼ������
//{
//	TMOD=0X20;//���ö�ʱ��T1Ϊ������ʽ2��8λ�Զ���װ�� �����ǲ���������
//	TH1=0XFD;//���ò�����Ϊ9600bps
//	TL1=0XFD;
//	TR1=1;//������ʱ��
//	PCON=0X00;
//	SCON=0X50; //������ʽ1��������9600bit/s,�������
//}
//void main()
//{
//	time0_init();//��ʱ����ʼ��
//	uart_init();//���ڳ�ʼ��
//	while(1)
//	{
//		if(num==20)//����20�ε�1s
//		{
//			num=0;
//			i=P1;//��ȡP1��8λ����
//			SBUF=i;//��������
//			while(TI==0);//�ȴ��������
//			TI=0;//���־
//		}
//	}
//}

//void Timer0() interrupt 1 //��ʱ��0�жϣ�����20�μ�1s��
//{
//	TH0=(65535-50000)/256;//��ʱ50ms
//	TL0=(65535-50000)%256;
//	num++;
//}

//оƬB����
#include <reg52.h>
#define uchar unsigned char

uchar j=0;//���ڽ��յ�������

void uart_init()//���ڳ�ʼ������
{
	TMOD=0X20;//���ö�ʱ��T1Ϊ������ʽ2��8λ�Զ���װ�� �����ǲ���������
	TH1=0XFD;//���ò�����Ϊ9600bps
	TL1=0XFD;
	TR1=1;//������ʱ��
	PCON=0X00;
	SCON=0X50; //������ʽ1��������9600bit/s,�������
}

void main()
{
	uart_init();//���ڳ�ʼ��
	while(1)
	{
			while(!RI);//�ȴ��������
		  RI=0;//���־
			j=SBUF;//��ȡ���յ�������
		  P2=j;//��8λ���ݽ��е��
	}
}
