#include<reg51.h>  							//51��Ƭ��ͷ�ļ�
#include<intrins.h> 						//����������ѭ����λ�Ӻ����Ŀ�
#define uint unsigned int    				//�궨��
#define uchar unsigned char 				//�궨��
void delay(uint);
void main()            						//������
{
    uchar a,i,j;
    while(1)        						//��ѭ��
    {
        a=0xfe;    							//����ֵ
        for(j=0;j<1;j++) 
		for(i=0;i<8;i++)  					//����һ��
        {
            P2=a;       					//����С��
			delay(1000);
            a=_crol_(a,1); 					//��a����ѭ������һλ
        }
        a=0x7f;
        for(j=0;j<1;j++) 
		for(i=0;i<8;i++) 					//����һ��
        {
            P2=a;       					//����С��
			delay(1000);
            a=_cror_(a,1); 					//��a����ѭ������һλ
        }        
    }
}
void delay(uint z)  						//��ʱ����,z��ȡֵΪ�����������ʱms������delay(200);��Լ��ʱ200ms.
{                   						//delay(500);��Լ��ʱ500ms.
    uint x,y;
    for(x=z;x>0;x--)
        for(y=110;y>0;y--);    
}