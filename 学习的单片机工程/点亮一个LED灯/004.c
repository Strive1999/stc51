#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar m;
void main()
{	
	m=0xfe;
	while(1)
	{	uint i,j;
		P2=m;
		for(i=100;i>0;i--)
			for(j=110;j>0;j--);
		m=_cror_(m,1);
	}
	
}void  main()

{

    uchar m= 0,n;
	uint  i,j = 0;


    while(1)                //������ѭ��  

    {

        P2 = ~(0x01 << m++);     //P0����1����jλ������j++

        for(i=1000;i>0;i--)
			for(j=110;j>0;j--);  //��ʱ

        if(m == 8)                //���j����8�����¸�j��ֵ0

        {
            j = 0;
		 
        }

     }

}