
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "helpers.c"

int min(int num1, int num2) {

   /* local variable declaration */
   int result;
 
   if (num1 < num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}

int max(int num1, int num2) {

   /* local variable declaration */
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}


void alg3_line (Point p0, Point p1){

    // trivial case p0 = p1
    if(p0.x == p1.x && p0.y == p1.y){
        printf("(%d, %d)", p0.x, p0.y);
        return;
    }

    long double x,y,step_x,step_y;
    int i,length;

    /* If x component in both points is the same,
    then make sure p0 is the one with lower y 
    component. Otherwise, if p0.x is greater than
    p1.x, swap them.
    */
    if(p0.x == p1.x){
        if(p0.y > p1.y) swapPoints(&p0, &p1);
    }else{
        if(p0.x > p1.x) swapPoints(&p0, &p1);
    }
    
    length = max(abs(p1.x - p0.x), abs(p1.y - p0.y));
    printf("Length: %d\n\n", length);
    step_x = (long double) (p1.x - p0.x)/length;
    printf("stepx: %Lf\n\n", step_x);
    step_y = (long double) (p1.y - p0.y)/length;
    printf("stepy: %Lf\n\n", step_y);

    x = (long double)p0.x;
    printf("x_initial: %Lf\n\n", x);
    y = (long double)p0.y;
    printf("y_initial: %Lf\n\n", y);

    for(i = 0; i <= length; i++){
        printf("(%d, %d)", (int)round(x), (int)round(y));
        x += step_x;
        y += step_y;
    }
    printf("\n\n");
}


// int main(){
//     // Point p1;
//     // p1.x = 6;
//     // p1.y = 5;

//     // Point p2;
//     // p2.x = 8;
//     // p2.y = 17;

//     Point p1;
//     p1.x = 1;
//     p1.y = 9;

//     Point p2;
//     p2.x = 4;
//     p2.y = 2;

//     // alg3_line(p1,p2);
//     alg3_line(p2,p1);
// }

