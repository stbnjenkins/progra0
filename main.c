#include <stdio.h>
#include <stdlib.h>

#include "pointNode.c"
#include "generator.c"
#include "algoritmo1.c"
#include "algoritmo2.c"
#include "algoritmo3.c"
#include "Bresenham.c"

int main(int argc, char **argv){
    int res, n_lines, times;
    // get parameters
    if (argc != 4) {
        printf("Usage <program> <resolution> <number_lines> <times>\n");
        return -1;
    }  

    // Get parameters
    res = (int) atoi(argv[1]);
    n_lines = (int) atoi(argv[2]);
    times = (int) atoi(argv[3]);

    // printf("res: %d, lineas: %d, veces: %d\n", res, n_lines, times);
    // return 0;

    // Set seed
    srand(time(0));

    // Generar lista de lineas aleatorios

    
    
    // for linea in lineas Do Algorithm 1


    // for linea in lineas  Do Algorithm 2


    // for linea in lineas Do Algorithm 3


    // for linea in lineas  Do Algorithm 4
    
    
    // for(i = 0; i < 2; i++){
    //     Point h = randPoint(res);
    //     insert_node_last(h);
    // }
    //display();

}