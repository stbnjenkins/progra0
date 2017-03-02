#include <stdio.h>
#include <stdlib.h>

#include "pointNode.c"
#include "generator.c"

int main(int argc, char **argv){
    // Point p1;
    // p1.x = 24;
    // p1.y = 42;

    // Point p2;
    // p2.x = 48;
    // p2.y = 8;

    // // printf("Point.x -> %d\nPoint.y -> %d\n", p1.x, p1.y);
    // // printf("Point.x -> %d\nPoint.y -> %d\n", p2.x, p2.y);

    // PointNodePtr n = (PointNodePtr)malloc(sizeof(PointNode));
    // n->point = p1;
    // printf("Point.x -> %d\nPoint.y -> %d\n", (n->point).x, (n->point).y);

    // Set seed
    srand(time(0));
    int res = 500;
    int i;
    // Point h = randPoint2(500);
    // printf("Point.x -> %d\nPoint.y -> %d\n", h.x, (n->point).y);

    for(i = 0; i < 10; i++){
        Point h = randPoint(res);
        insert_node_last(h);
    }

    display();

}