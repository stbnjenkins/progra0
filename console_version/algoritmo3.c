
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "helpers.c"

int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}


void alg3_line (Point p0, Point p1){

    // trivial case p0 = p1
    if(p0.x == p1.x && p0.y == p1.y){
        //printf("(%d, %d)", p0.x, p0.y);
        return;
    }

    long double x,y,step_x,step_y;
    int j,length;

    /* If x component in both points is the same,
    then make sure p0 is the one with lower y 
    component. Otherwise, if p0.x is greater than
    p1.x, swap them.
    */

    if(p0.x > p1.x) swapPoints(&p0, &p1);

    
    length = max(p1.x - p0.x, abs(p1.y - p0.y));
    //printf("Length: %d\n\n", length);
    step_x = (long double) (p1.x - p0.x)/length;
    //printf("stepx: %Lf\n\n", step_x);
    step_y = (long double) (p1.y - p0.y)/length;
    //printf("stepy: %Lf\n\n", step_y);

    x = (long double)p0.x;
    // printf("x_initial: %Lf\n\n", x);
    y = (long double)p0.y;
    // printf("y_initial: %Lf\n\n", y);

    for(j = 0; j <= length; j++){
        //plot
        round(x);
        round(y);
        x += step_x;
        y += step_y;
    }
}

