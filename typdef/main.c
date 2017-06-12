#include "stdio.h"

//Using typdef is not necessary to use the word "struct" to declare it
typedef struct point{
 int x;
 int y;
 int z;
}point;

void main(){
 //initialize struct point
 point Point;
 Point.x=0;
 Point.y=10;
 Point.z=15;
 
 printf("X: %i\n\r",Point.x);
 printf("Y: %i\n\r",Point.y);
 printf("Z: %i\n\r",Point.z);
};
