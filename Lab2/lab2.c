#include <reg51.h>// library containing all the registers for the given micro-controller

unsigned int i; // use unsigned if you know the variable isnt going to be negative

void delay(void);  // function protocol
void delay1(void);

void main()
{
	int j;
//	unsigned int pin;
	P2= 0x00;
//	pin = P2^1;
	while(1)
	{
		if(P2 & 0x08)
			{
				P1= 0x80;
				for (j= 0; j< 8 ; j++)
				{
				P1=P1>>1; 
				P1= P1+ 0x80;
				delay();
				}
			}
		else if (P2 & 0x04)
		{
			P1 = 0x00;
			delay1();
			P1 = 0xFF;
			delay1();
		}
		else if (P2 & 0x02)
		{ 
			P1=0xAA; 
			delay();
			P1= ~P1;
			delay();
		}
		else if (P2  == 0x00)
		{
				P1= 0x01;
				delay();
				for (j= 0; j< 8 ; j++)
				{
				P1 = P1<<1; 
				delay();
				}	
		}
	}
}
void delay(void)
{
	for (i=0; i<10000; i++)
	{
		;
	}
}
void delay1(void)
{
	for (i=0; i<50000; i++)
	{
		;
	}
}
