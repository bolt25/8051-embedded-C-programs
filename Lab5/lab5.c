//question 5

#include <reg51.h>
#include <stdio.h>

unsigned char lookUpTable[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67};
unsigned char MSB, LSB;
unsigned char num, counter;

bit updateFlag;

void delay(void);
void display(unsigned char, unsigned char);

void main(){
	unsigned char disp_posi = 0;
	MSB = 0xf4;
	LSB = 0x00;
	TMOD = 0x01;
	TH0 = MSB;
	TL0 = LSB;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	num = 0;
	while(1){
		for (counter = 0; counter <= 9; counter++){
			display(lookUpTable[num], disp_posi);
		}
		
		disp_posi++;
		disp_posi = disp_posi % 4;
		
		if (updateFlag == 1){
			updateFlag = 0;
			num++;
			num = num % 10;
		} 
	}	
}
void delay() interrupt 1{
	static int count = 0;
	count++;
	TH0 = MSB;
	TL0 = LSB;
	if (count == 1000){
		count = 0;
		updateFlag = 1;
	}
}

void display(unsigned char number, unsigned char position){
	P0 = number;
	if (position == 0)
		P2 = 0x00;
	else if (position == 1)
		P2 = 0x20;
	else if (position == 2)
		P2 = 0x40;
	else if (position == 3)
		P2 = 0x60;
	else
		printf("Position Out of Bounds \n");
}