#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "helpers.c"

void line (Point p0, Point p1){
    
    // trivial case p0 = p1
    if(p0.x == p1.x && p0.y == p1.y){
        //printf("(%d, %d)", p0.x, p0.y);
        return;
    }

    long double m, b, y;
    int i, dx, dy;


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
    

    // Calculate slope and y-intersection
    dx = (p1.x - p0.x);
    dy = (p1.y - p0.y);

    m = (long double) dy / dx;
    //if(m == -INFINITY) m = INFINITY;
    //printf("Slope is: %Lf\n\n", m);

    b = (long double) p0.y - m * p0.x;
   // printf("Y-intersection is: %Lf\n\n", b);
    
    
    if(dx >= abs(dy)){
        for(i = p0.x; i <= p1.x; i++){
            y = (long double) m*i + b;
            //plot
            round(y);
        }
    }else{
        if(m == INFINITY){
            for(i = p0.y; i <= p1.y; i++){
                //plot
            }
        }else{
            if(p0.y > p1.y) swapPoints(&p0, &p1);
            for(i = p0.y; i <= p1.y; i++){
                y = (long double) (i-b)/m;
                //plot
                round(y);
            }
        }
    }
}


