#include <math.h>
#include <stdio.h>
#include "point.h"

// function to swap values of points
void swapPoints(PointPtr p0, PointPtr p1){
    Point temp = *p0;
    *p0 = *p1;
    *p1 = temp;
}

void line (Point p0, Point p1){
    long double m, b, y;
    int i, dx, dy;
    // test if ok and swap if needed
    printf("Point.x -> %d\nPoint.y -> %d\n", p0.x, p0.y);
    printf("Point.x -> %d\nPoint.y -> %d\n", p1.x, p1.y);

    // If p0 is "greater than" p1, swap them
    if(p0.x > p1.x) swapPoints(&p0, &p1);

    // Calculate slope and y-intersection
    dx = (p1.x - p0.x);
    dy = (p1.y - p0.y);

    m = (long double) dy / dx;
    printf("Slope is: %Lf\n\n", m);

    b = (long double) p0.y - m * p0.x;
    printf("Y-intersection is: %Lf\n\n", b);
    
    
    if(dx >= dy){
        for(i = p0.x; i <= p1.x; i++){
            y = (long double) m*i + b;
            printf("(%d, %d)", i, (int)round(y));
        }
    }else{
        if(m == INFINITY){
            for(i = p0.y; i <= p1.y; i++){
                printf("(%d, %d)", p0.x, i);
            }
        }else{
            for(i = p0.y; i <= p1.y; i++){
                y = (long double) (i-b)/m;
                printf("(%d, %d)", (int)round(y), i);
            }
        }
    }
    printf("\n");
}

int main(){
    Point p1;
    p1.x = 1;
    p1.y = 2;

    Point p2;
    p2.x = 9;
    p2.y = 4;

    line(p2,p1);
}


