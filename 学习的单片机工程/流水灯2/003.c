#include<reg52.h>
#define uint unsigned int
#define led1 P2						//�궨�壨��P2�ڶ���Ϊled ����Ϳ���ʹ��led����P2�ڣ�
unit;i,j;
void delayxms(unit);				//�����Ӻ�����ע�������������ͣ�
void main()
{
	while(1)						//��ѭ��
	{	
		led1=0xAA;					/*�������������1��3��5��7*/	
		delayxms(100);				//��ʱ100����
		led1=0X55;					/*�������������2��4��6��8*/
		delayxms(100);				//��ʱ100����
	}
}
void delayxms(uint xms)				//�Ӻ����壨ע�������������ͣ�
{
	for(i=xms;i>0;i--)				//i=xms����ʱԼx����
		for(j=110;j>0;j--);
}