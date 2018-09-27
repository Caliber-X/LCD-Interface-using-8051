//LCD Module Connections
extern bit RS;                                                                   
extern bit EN;                           
extern bit D0;
extern bit D1;
extern bit D2;
extern bit D3;
extern bit D4;
extern bit D5;
extern bit D6;
extern bit D7;
//End LCD Module Connections 


void Lcd_Delay(int a)
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

//LCD 8 Bit Interfacing Functions
void Lcd8_Port(char a)
{
	if(a & 1)
		D0 = 1;
	else 
		D0 = 0;
	
	if(a & 2)
		D1 = 1;
	else
		D1 = 0;
	
	if(a & 4)
		D2 = 1;
	else
		D2 = 0;
	
	if(a & 8)
		D3 = 1;
	else
		D3 = 0;
	
	if(a & 16)
		D4 = 1;
	else
		D4 = 0;

	if(a & 32)
		D5 = 1;
	else
		D5 = 0;
	
	if(a & 64)
		D6 = 1;
	else 
		D6 = 0;
	
	if(a & 128)
		D7 = 1;
	else
		D7 = 0;
}
void Lcd8_Cmd(char a)
{ 
  RS = 0;             // => RS = 0
  Lcd8_Port(a);             //Data transfer
  EN  = 1;             // => E = 1
  Lcd_Delay(5);
  EN  = 0;             // => E = 0
}

Lcd8_Clear()
{
	  Lcd8_Cmd(1);
}

void Lcd8_Set_Cursor(char a, char b)
{
	if(a == 1)
	  Lcd8_Cmd(0x80 + b);
	else if(a == 2)
		Lcd8_Cmd(0xC0 + b);
}

void Lcd8_Init()
{
	Lcd8_Port(0x00);
	RS = 0;
	Lcd_Delay(200);
	///////////// Reset process from datasheet /////////
  Lcd8_Cmd(0x30);
	Lcd_Delay(50);
  Lcd8_Cmd(0x30);
	Lcd_Delay(110);
  Lcd8_Cmd(0x30);
  /////////////////////////////////////////////////////
  Lcd8_Cmd(0x38);    //function set
  Lcd8_Cmd(0x0C);    //display on,cursor off,blink off
  Lcd8_Cmd(0x01);    //clear display
  Lcd8_Cmd(0x06);    //entry mode, set increment
}

void Lcd8_Write_Char(char a)
{
   RS = 1;             // => RS = 1
   Lcd8_Port(a);             //Data transfer
   EN  = 1;             // => E = 1
   Lcd_Delay(5);
   EN  = 0;             // => E = 04
}

/*void Lcd8_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	 Lcd8_Write_Char(a[i]);
}
void Lcd8_Shift_Right()
{
	Lcd8_Cmd(0x1C);
}

void Lcd8_Shift_Left()
{
	Lcd8_Cmd(0x18);
}*/
//End LCD 8 Bit Interfacing Functions