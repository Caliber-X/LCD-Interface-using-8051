#include<reg52.h>							 //including sfr registers for ports of the controller
#include<lcd.h>
//LCD Module Connections
sbit RS = P0^0;                                                                   
sbit EN = P0^1;                            
sbit D0 = P2^0;
sbit D1 = P2^1;
sbit D2 = P2^2;
sbit D3 = P2^3;
sbit D4 = P2^4;
sbit D5 = P2^5;
sbit D6 = P2^6;
sbit D7 = P2^7;
//LCD Delay
void Delay(int a)
{
    int j;
    int i;
    for(i=0;i<a;i++)
    {
        for(j=0;j<100;j++)
        {
        }
    }
}
//Display Data
void displaydata(unsigned char *a)
{
	  int i,j,p=0,t=1,c=0;
		char b[20];
    for(i=0;a[i]!='\0';i++)
		{
			if(a[i]!=' ')
				b[p++]=a[i];
			if(a[i]==' ' || a[i+1]=='\0')
			{
				b[p]='\0';
				if(p<=16)
					c=(16-p)/2;
				else
					c=0;
				//Printing Normally
				for(j=0;b[j]!='\0';j++)
				{
					Lcd8_Set_Cursor(t,c++);
					Lcd8_Write_Char(b[j]);
					Delay(300);
				}
				p=0;
				if(t==1)	t=2;
				else
				{
					t=1;
					Lcd8_Clear();
				}
				Delay(500);
			}
		}
}
//Main fuction
void main()
{
	Lcd8_init();
	while(1)
	{
		displaydata("Welcome to Department of Electrical Engineering");	
		Lcd8_Clear();
		Delay(3000);
	}
}