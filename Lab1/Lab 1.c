//QUE 1 A)

//#include <reg51.h>// library containing all the registers for the given micro-controller

//unsigned int i; // use unsigned if you know the variable isnt going to be negative

//void delay(void);  // function protocol

//void main()
//{
//	while(1)
//	{
//		P1=0xFF; //initially all the LEDs on
//		delay();
//		P1= ~P1;
//		delay();
//	}
//}

//void delay()
//{
//	for (i=0; i<1000; i++)
//	{
//		;
//	}
//}

//QUE 1 B)
//#include <reg51.h>// library containing all the registers for the given micro-controller

//unsigned int i; // use unsigned if you know the variable isnt going to be negative

//void delay(void);  // function protocol

//void main()
//{
//	while(1)
//	{
//		P1=0xAA; 
//		delay();
//		P1= ~P1;
//		delay();
//	}
//}

//void delay()
//{
//	for (i=0; i<1000; i++)
//	{
//		;
//	}
//}

// QUE 1 C)
//#include <reg51.h>// library containing all the registers for the given micro-controller

//unsigned int i; // use unsigned if you know the variable isnt going to be negative

//void delay(void);  // function protocol

//void main()
//{
//	while(1)
//	{
//		P1=0x01; 
//		delay();
//		P1=0x00;
//		delay();
//	}
//}

//void delay()
//{
//	for (i=0; i<1000; i++)
//	{
//		;
//	}
//}

//QUE 1 D)
//#include <reg51.h>// library containing all the registers for the given micro-controller

//unsigned int i;// use unsigned if you know the variable isnt going to be negative
//unsigned int j;
//void delay(void);  // function protocol

//void main()
//{	
//	while(1)
//	{
//		P1= 0x01;
//		delay();
//		for (j= 0; j< 8 ; j++)
//		{
//		P1 = P1<<1; 
//		delay();
//		}	
//	}
//}

//void delay()
//{
//	for (i=0; i<65000; i++)
//	{
//		;
//	}
//}

// QUE 1 E)
//#include <reg51.h>// library containing all the registers for the given micro-controller

//unsigned int i;// use unsigned if you know the variable isnt going to be negative
//unsigned int j;
//void delay(void);  // function protocol

//void main()
//{	
//	while(1)
//	{
//		P1= 0x80;
//		delay();
//		for (j= 0; j< 8 ; j++)
//		{
//		P1 = P1>>1; 
//		delay();
//		}	
//	}
//}

//void delay()
//{
//	for (i=0; i<65000; i++)
//	{
//		;
//	}
//}