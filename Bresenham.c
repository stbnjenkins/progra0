#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "helpers.c"

void bresenham(Point p0, Point p1) {

    // trivial case p0 = p1
    if(p0.x == p1.x && p0.y == p1.y){
        //printf("(%d, %d)", p0.x, p0.y);
        return;
    }

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

    //printf("Point.x -> %d\nPoint.y -> %d\n", p0.x, p0.y);
    //printf("Point.x -> %d\nPoint.y -> %d\n", p1.x, p1.y);

    //Initial Vars
    int Delta_E, Delta_NE, Delta_SE, Delta_N, Delta_S; 
    int d, xp, yp, i, xdif, ydif;
    xp = p0.x; yp = p0.y;
    xdif = p1.x-p0.x; ydif = p1.y-p0.y;

    //Common Delta
    Delta_N = -2*(xdif);
    Delta_E = 2*(ydif);
    Delta_S = 2*(xdif);
    Delta_NE = 2*((ydif)-(xdif));
    Delta_SE = 2*((ydif)+(xdif));

    //print first point
    //printf("(%d, %d)", xp, yp);

    //Calculing cases
    if(ydif >= 0) {
        if(ydif >= xdif) {
            //cuadrante 2
            d = (ydif)-2*(xdif);
            
            //ciclo
            for(i = p0.y; i < p1.y; i++){
                if (d<0){
                    //printf("(%d, %d)", xp+1, yp+1);
                    xp++; yp++; d = d + Delta_NE;
                } else{
                    //printf("(%d, %d)", xp, yp+1);
                    yp++; d = d + Delta_N;
                }
            }
        } else {
            //cuadrante 1
            d = 2*(ydif)-(xdif);

            //ciclo
            for(i = p0.x; i < p1.x; i++){
                if (d<0){
                    //printf("(%d, %d)", xp+1, yp);
                    xp++; d = d + Delta_E;
                } else{
                    //printf("(%d, %d)", xp+1, yp+1);
                    xp++; yp++; d = d + Delta_NE;
                }
            }
        }
    } else {
        if((ydif*(-1)) >= xdif) {
            //cuadrante 7
            d = (ydif)+2*(xdif);

            //ciclo
            for(i = p0.y; i > p1.y; i--){
                if (d<0){
                    //printf("(%d, %d)", xp, yp-1);
                    yp--; d = d + Delta_S;
                } else{
                    //printf("(%d, %d)", xp+1, yp-1);
                    xp++; yp--; d = d + Delta_SE;
                }
            }
        } else {
            //cuadrante 8
            d = 2*(ydif)+(xdif);

            //ciclo
            for(i = p0.x; i < p1.x; i++){
                if (d<0){
                    //printf("(%d, %d)", xp+1, yp-1);
                    xp++; yp--; d = d + Delta_SE;
                } else{
                    //printf("(%d, %d)", xp+1, yp);
                    xp++; d = d + Delta_E;
                }
            }
        }
    }
}

// int main(){
//     Point p1;
//     p1.x = 1;
//     p1.y = 9;

//     Point p2;
//     p2.x = 4;
//     p2.y = 2;

//     bresenham(p1,p2);
// }