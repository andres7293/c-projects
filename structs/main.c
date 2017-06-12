#include "stdio.h"

//To declare struct variable is necessary to write the word struct
struct point{
 int x;
 int y;
 int z;
};

void main(){
 //initialize struct point
 struct point Point;
 Point.x=0;
 Point.y=10;
 Point.z=15;
 
 printf("X: %i\n\r",Point.x);
 printf("Y: %i\n\r",Point.y);
 printf("Z: %i\n\r",Point.z);
};
