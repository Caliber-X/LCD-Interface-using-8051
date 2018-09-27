char str,Chasrin=0;

void Serialbegin()
{
   TMOD=0x20;
   SCON=0x50;
   TH1=0xfd;
   TR1=1;
}

void Serialwrite(char byte)
{
  SBUF=byte;
  while(!TI);
  TI=0;
}

void Serialprintln(char *p)
{
  while(*p)
  {
    Serialwrite(*p);
    p++;
  }
  Serialwrite(0x0d);
}