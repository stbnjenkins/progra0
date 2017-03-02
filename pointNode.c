#include "point.h"

typedef struct PointNode{
    Point point;
    struct PointNode *next;
} PointNode, *PointNodePtr;


PointNodePtr newnode, ptr;
PointNodePtr first = NULL, last = NULL;

/*
 * Creating Node
 */

PointNodePtr create_node(Point myPoint){
    newnode = (PointNodePtr) malloc(sizeof(PointNode));
    if (newnode == NULL){
        printf("\nMemory was not allocated");
        return 0;
    }
    else {
        newnode->point = myPoint;
        newnode->next = NULL;
        return newnode;
    }
}

/*
 * Inserting Node at Last
 */

void insert_node_last(Point myPoint){
    newnode = create_node(myPoint);
    if (first == last && last == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        last->next = newnode;
        last = newnode;
        last->next = NULL;
    }
}    

/*

 * Displays non-empty List from Beginning to End

 */

void display()

{

    if (first == NULL)

    {

        printf("\nEMPTY LIST:");

        printf(":No nodes in the list to display\n");

    }

    else

    {

        for (ptr = first;ptr != NULL;ptr = ptr->next)

        {    

            printf("Point.x -> %d\nPoint.y -> %d\n", (ptr->point).x, (ptr->point).y);
        }

    }

}

 