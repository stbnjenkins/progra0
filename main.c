#include <stdio.h>
#include <stdlib.h>

#include "pointNode.c"
#include "generator.c"

int main(int argc, char **argv){

    // Algorithm 1
    // PointNodePtr newnode, ptr;
    // PointNodePtr alg1_first = NULL, alg1_last = NULL;
    
    // Algorithm 2
    // PointNodePtr newnode;
    // PointNodePtr alg2_first = NULL, alg2_last = NULL;

    // Algorithm 3
    // PointNodePtr newnode, ptr;
    // PointNodePtr alg3_first = NULL, alg3_last = NULL;

    // Algorithm 4
    // PointNodePtr newnode, ptr;
    // PointNodePtr alg4_first = NULL, alg4_last = NULL;

    //hola
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