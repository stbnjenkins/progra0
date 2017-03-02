#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "helpers.c"

void alg2_line (Point p0, Point p1){

    // trivial case p0 = p1
    if(p0.x == p1.x && p0.y == p1.y){
        //printf("(%d, %d)", p0.x, p0.y);
        return;
    }
    
    long double m,y;
    int dx,dy,i;

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
    // printf("Slope is: %Lf\n\n", m);

    y = p0.y;

    if(abs(dx) >= abs(dy)){
        for(i = p0.x; i <= p1.x; i++ ){
            round(y);
            //printf("(%d, %d)", i, (int)round(y));
            y+=m;
        }
    }else{        
        if(m == INFINITY){
            for(i = p0.y; i <= p1.y; i++){
                //printf("(%d, %d)", p0.x, i);
            }
        }
        else{
            //new
            m = (long double)dx/dy;
            y = p0.x;
            for(i = p0.y; i <= p1.y; i++ ){
                round(y);
                //printf("(%d, %d)", (int)round(y), i);
                y+=m;
            }
        }
    }    
}


// int main(){
//     Point p1;
//     p1.x = 1;
//     p1.y = 2;

//     Point p2;
//     p2.x = 4;
//     p2.y = 9;

//     // alg2_line(p1,p2);
//     alg2_line(p2,p1);
// }
