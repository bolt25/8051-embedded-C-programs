//question 6)
#include <reg51.h>
#include <intrins.h>

void ready(void);
void lcdcmd(unsigned char);
void lcddata(unsigned char);
void display(void);
void delay(unsigned int);
unsigned char code lcd1[] = "Dharmik";
unsigned char code lcd2[] = "U17EE021";
sbit busy = P0^7;
sbit resel = P2^7;
sbit rdwr = P2^6;
sbit lcden = P2^5;
unsigned char i;
void main()
{
	while(1)
	{
		display();
		lcdcmd(0x80);
		for (i = 0; i < 7 ; i++)
	{
		lcddata(lcd1[i]);
		delay(500);
	}
	lcdcmd(0xc0);
	for (i = 0; i < 8; i++)
	{
		lcddata(lcd2[i]);
		delay(500);
	}
	}
}
void display()
{
	
	lcdcmd(0x38);
	delay(10);
	lcdcmd(0x01);
	delay(10);
	lcdcmd(0x02);
	delay(10);
	lcdcmd(0x06);
	delay(10);
	lcdcmd(0x0f);
	
}

void lcddata(unsigned char temp)
{
	ready();
	P0 = temp;
	resel = 1;
	rdwr = 0;
	lcden = 1;
	delay(10);
	lcden = 0;
	return;
}

void lcdcmd(unsigned char temp)
{
	ready();
	P0 = temp;
	resel = 0;
	rdwr = 0;
	lcden = 1;
	delay(10);
	lcden = 0;
	//return;
}

void ready(void)
{
	P0 = 0xff;
	resel = 0;
	rdwr = 1;
	while (busy == 1)
	{
		lcden = 0;
		delay(1);
		lcden = 1;
	}
	lcden = 0;
	rdwr = 0;
}

void delay(unsigned int t)
{
	unsigned int i;
	unsigned int n;
	for (i=0;i<t;i++)
	{
		for(n=0;n<1000;n++)
		{
			;
		}
	}
}