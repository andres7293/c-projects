/*
Convert number to BCD
*/

#include "stdio.h"

char getMSN(char number);
char getLSN(char number);
char toBCD(char msn,char lsn);

void main()
{
  char number=25;
  char msn=getMSN(number);
  char lsn=getLSN(number);
  printf("Number = %i\n\r",number);
  printf("Most significant nibble = 0x%X\n\r",msn);
  printf("Less significant nibble = 0x%X\n\r",lsn);
  printf("BCD = dec %i \n\r",toBCD(msn,lsn));
  printf("BCD = 0x%X \n\r",toBCD(msn,lsn));
}

char getMSN(char number)
{
  char msn = number/10;
  return msn;
}

char getLSN(char number)
{
  char lsn = number % 10;
  return lsn;
}

char toBCD(char msn,char lsn)
{
  char bcd = (msn << 4)|lsn;
  return bcd;
}
