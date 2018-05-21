#include<reg51.h>
sbit Blue = P0^0; /* assigning variables to the port of microcontroller*/
sbit B2 = P0^1;
sbit B3 = P0^2;
sbit B4 = P0^3;
sbit Ter1 = P0^7;

sbit Green = P1^0;
sbit Red = P1^1;
sbit G6 = P1^5;
sbit R6 = P1^6;
sbit T6 = P1^7;

sbit G3 = P2^0;
sbit R3 = P2^1;
sbit T3 = P2^2;
sbit G2 = P2^3;
sbit R2 = P2^4;
sbit T2 = P2^5;
sbit G1 = P2^6;
sbit R1 = P2^7;

sbit G5 = P3^0;
sbit R5 = P3^1;
sbit T5 = P3^2;
sbit G4 = P3^3;
sbit R4 = P3^4;
sbit T4 = P3^5;
sbit Tp = P3^6;
sbit Tm = P3^7;

void delay(unsigned int i) /* Creating a delay function of about 1 sec*/
{
	int count=0;
	i=i*8;
	while(count<i)
	{
		TMOD=0x01;
		TL0=0x27;
		TH0=0x10;
		TR0=1;
		while(TF0==0);
		TR0=0;
		TF0=0;
		count++;
	}
}
int time_set() /* Function to set the timeout varible of the traffic lights*/
{
	int t=20;
	  if((Tp==0)&&(Tm==0))
		{
		delay(3);
			if((Tp==0)&&(Tm==0))
			{
						Red = 1;
						Green = 1;
						Blue = 0;
						delay(3);
						Blue = 1;
						B3 = 0;
						Red = 0;
				while(1)
					{
					if((Tp==0)&&(Tm==1))
						{
							t++;
							B3 = 1;
							B2 = 0;
							delay(1);
							B3 = 0;
							B2 = 1;
						}
					if((Tp==1)&&(Tm==0))
						{
							t--;
							B3 = 1;
							B4 = 0;
							delay(1);
							B3 = 0;
							B4 = 1;
						}
					if((Tp==0)&&(Tm==0))
							{
								delay(3);
								Blue = 0;
								B3 = 1;
								delay(2);
								Blue = 1;
								break;
							}
						}
					
			}
		}
		Blue = 1;
		B2 = 1;
		B3 = 1;
		B4 = 1;
	return t;
}
void main() /* main method of the program*/
{
	int time;
	time = 20;
	Green = 1;
	Red = 0;
	B2 = 1;
	B3 = 1;
	B4 = 1;
	G1 = 1;
	R1 = 0;
	Ter1 = 1;
	G2 = 1;
	R2 = 0;
	T2 = 1;
	G3 = 1;
	R3 = 0;
	T3 = 1;
	G4 = 1;
	R4 = 0;
	T4 = 1;
	G5 = 1;
	R5 = 0;
	T5 = 1;
	G6 = 1;
	R6 = 0;
	T6 = 1;
	Tp = 1;
	Tm = 1;
	while(1) /* Infinite loop to run the switching process*/
	{
		if((Tp==0)&&(Tm==0))
			time=time_set();
			
		delay(1);
		Green = 0;
		delay(8);
		Red = 1;
		delay(time);		
		Green = 1;
		Red = 0;
		
		if((Tp==0)&&(Tm==0)) /* When both Tp and Tm are pressed simutaneously the time_set function is called*/
			time=time_set();
		
		if((Ter1==1)&&(T2==1)&&(T3==1)&&(T4==1)&&(T5==1)&&(T6==1))
		{
			
		Green = 1;
		Red = 0;
		delay(time);		
		
		}
		/* time_set function can be called at any instant of the program execution so it need to be included after each loop or statement*/
		
    if((Tp==0)&&(Tm==0)) 
			time=time_set();
			
		if(Ter1 == 0)
		{
			delay(1);
		G1 = 0;
		delay(8);
		R1 = 1;
		delay(time);		
		G1 = 1;
		R1 = 0;
		}
		
		if((Tp==0)&&(Tm==0))
			time=time_set();
			
		if(T2 == 0)
		{
			delay(1);
		G2 = 0;
		delay(8);
		R2 = 1;
		delay(time);		
		G2 = 1;
		R2 = 0;
		}
		
		if((Tp==0)&&(Tm==0))
			time=time_set();
			
		if(T3 == 0)
		{
			delay(1);
		G3 = 0;
		delay(8);
		R3 = 1;
		delay(time);		
		G3 = 1;
		R3 = 0;
		}
		
		if((Tp==0)&&(Tm==0))
			time=time_set();
			
		if(T4 == 0)
		{
			delay(1);
		G4 = 0;
		delay(8);
		R4 = 1;
		delay(time);		
		G4 = 1;
		R4 = 0;
		}
		
		if((Tp==0)&&(Tm==0))
			time=time_set();
			
		if(T5 == 0)
		{
			delay(1);
		G5 = 0;
		delay(8);
		R5 = 1;
		delay(time);		
		G5 = 1;
		R5 = 0;
		}
		
		if((Tp==0)&&(Tm==0))
			time=time_set();
			
		if(T6 == 0)
		{
			delay(1);
		G6 = 0;
		delay(8);
		R6 = 1;
		delay(time);		
		G6 = 1;
		R6 = 0;
		}
	}
}
