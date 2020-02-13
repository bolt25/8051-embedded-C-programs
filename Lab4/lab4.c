//Que 4) a)

//#include<reg51.h>
//bit x = 0;
//static unsigned char i;
//void isr(void);
//void main()
//{
//	TMOD = 0x20;
//	EA = 1;
//	ET1 = 1;
//	
//	TH1 = 0xc3;
//	
//	P2 = 0xFF;
//	
//	TR1 = 1;
//	
//	while(1)
//	{
//		if (x == 1)
//		{
//			x=0;
//			P2 = ~P2;
//			
//			if (P2 == 0xFF){
//				i = 0;
//			}
//			else{
//				i = 3;
//			}
//		}
//	}
//}

//void isr(void) interrupt 3
//{
//	if(i != 0){
//		i--;
//	}
//	else{
//		x = 1;
//	}
//}

// Que 4) b)


#include<reg51.h>
sbit pin = P1^1;
bit pin_flag, pwm_flag = 0, timer_flag;
int MSB, LSB;

void ext0(void);
void ext1(void);
void timer0(void);

void main(){
	TMOD = 0x01;
	EA = 1;
	EX0 = 1;
	EX1 = 1;
	ET0 = 1;
	IT0 = 1;  //FOR EDGE TRIGGERING
	IT1 = 1; 	//FOR EDGE TRIGGERING
	P2 = 0xFF;
	MSB = 0xF8;	
	LSB = 0XCD;
	TH0 = MSB;
	TL0 = LSB;
	TR0 = 1;
	
	while (1){
		if (pin_flag == 1){
			pin_flag = 0;
			pin = ~pin;
		}
		else if (pwm_flag == 1){
			if (timer_flag == 1){
				timer_flag = 0;
				P2 = ~P2;
				if (P2 == 0x00){
					MSB = 0xF8;
					LSB = 0xCD;
				}
				else if (P2 == 0xFF){
					MSB = 0xFB;
					LSB = 0x33;
				}
			}
		}
	}	
}
void ext0(void) interrupt 0{
	pin_flag = 1;
}

void ext1(void) interrupt 2{
	pwm_flag = ~pwm_flag;
}

void timer0(void) interrupt 1{
		timer_flag = 1;
		TH0 = MSB;
		TL0 = LSB;
}