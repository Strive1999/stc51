#include<reg52.h> //�������ʾI LOVE U.
#include<intrins.h> 
typedef unsigned int u16;
typedef unsigned char u8;
void delayxms(u16);
u16;u,j;
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
u8 code smgduan[19]={
0x06,0x00,0x38,0x3f,
0x3e,0x79,0x00,0xbe};
void delayxms(u16 xms)
{
	for(u=xms;u>0;u--)
		for(j=110;j>0;j--);
}
void DigDisplay()
{
	u8 i;
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
		delayxms(1);  //���һ��ʱ��ɨ��	
		P0=0x00;      //����
	}
}
void main()
{	
	while(1)
	{	
		DigDisplay(); 		//�������ʾ����
	}
}
		
	/*while(1)       						//��ѭ��
    {	u8 a,i,j;
        a=0xfe;    							//����ֵ
        for(j=0;j<1;j++) 
		for(i=0;i<8;i++)  					//����һ��
        {
            P2=a;       					//����С��
			delayxms(500);
            a=_crol_(a,1); 					//��a����ѭ������һλ
        }
        a=0x7f;
        for(j=0;j<1;j++) 
		for(i=0;i<8;i++) 					//����һ��
        {
            P2=a;       					//����С��
			delayxms(500);
            a=_cror_(a,1); 					//��a����ѭ������һλ
        }        
    }
	}		
}*/
