//QUE 3 a)
/*
#include <reg51.h>

unsigned char MSB = 0x0F, LSB = 0xFC;
bit x = 1;


void main()
{
	
	TMOD = 0X01;
	EA = 1;
	ET0 = 1;
	TH0 = MSB;
	TL0 = LSB;
	P1 = 0x00;
	TR0 = 1;
	while (1)
	{
		if (x == 1)
		{
			x = 0;
			P1 = ~P1;
		}
	}
}

void delay() interrupt 1
{
	static unsigned char int_cntr = 0;
	int_cntr++;
	if (int_cntr == 50)
	{
		x = 1;
		int_cntr = 0;
		TH0 = MSB;
		TL0 = LSB;
	}
}
*/


// QUE 3 b)

#include <reg51.h>

unsigned char MSB_on = 0xfd, LSB_on = 0x9a, MSB_off = 0xf6 , LSB_off = 0x66;
bit x = 1;
sbit PWM = P1^1;
sbit  switch_bit = P2^1;


void main()
{
	
	TMOD = 0X01;
	EA = 1;
	ET0 = 1;
	TH0 = MSB_on;
	TL0 = LSB_on;
	TR0 = 1;

	while (1)
	{
		if (switch_bit == 0)
		{
			MSB_on = 0xfd;
			LSB_on = 0x9a;
			MSB_off = 0xf6;
			LSB_off = 0x66;
			if (x == 1)
			{
				x = 0;
				PWM = ~PWM;
			}
		}
		else
		{
			MSB_on = 0xf1;
			LSB_on = 0x99;
			MSB_off = 0xf6;
			LSB_off = 0x66;
			if (x == 1)
			{
				x = 0;
				PWM = ~PWM;
			}		
		}
	}
}


void delay() interrupt 1
{
		x = 1;
		if (PWM == 1)
		{
			TH0 = MSB_off;
			TL0 = LSB_off;
		}
		else if (PWM == 0)
		{
			TH0 = MSB_on;
			TL0 = LSB_on;
		}
}