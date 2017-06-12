#include "print.h"
#include "stdio.h"

void print(char *str,int len){
 int i=0;
 for(i=0;i<len;i++){
   printf("%c",str[i]);
 }
}
