#include "point.h"

typedef struct LineNode{
    Point point_ini;
    Point point_fin;
    struct LineNode *next;
} LineNode, *LineNodePtr;


LineNodePtr lnewnode, ptr;
LineNodePtr first = NULL, last = NULL;

/*
 * Creating Node
 */

LineNodePtr line_create_node(Point myPoint_ini,Point myPoint_fin){
    lnewnode = (LineNodePtr) malloc(sizeof(LineNode));
    if (lnewnode == NULL){
        printf("\nMemory was not allocated");
        return 0;
    }
    else {
        lnewnode->point_ini = myPoint_ini;
        lnewnode->point_fin = myPoint_fin;
        lnewnode->next = NULL;
        return lnewnode;
    }
}

/*
 * Inserting Node at Last
 */

void line_insert_node_last(Point myPoint_ini,Point myPoint_fin){
    lnewnode = line_create_node(myPoint_ini, myPoint_fin);
    if (first == last && last == NULL)
    {
        first = last = lnewnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        last->next = lnewnode;
        last = lnewnode;
        last->next = NULL;
    }
}    

/*
 * Displays non-empty List from Beginning to End
 */

void line_display()
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
            printf("Point1.x -> %d\nPoint1.y -> %d\nPoint2.x -> %d\nPoint2.y -> %d\n", (ptr->point_ini).x, (ptr->point_ini).y, (ptr->point_fin).x, (ptr->point_fin).y);
        }
    }
}

 