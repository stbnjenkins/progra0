#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pointNode.c"
#include "generator.c"
#include "algoritmo1.c"
#include "algoritmo2.c"
#include "algoritmo3.c"
#include "Bresenham.c"

int main(int argc, char **argv){
    int res, n_lines, times, times_i, lines_i;
    clock_t start, end;
    double cpu_time_alg1, cpu_time_alg2, cpu_time_alg3, cpu_time_alg4;


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

    // timer start
    start = clock();
    for(times_i = 0; times_i < times; times_i++){
    //some setup stuff
        for(lines_i = 0; lines_i < n_lines; lines_i++){
            // drawLine(lines[lines_i].point_ini , lines[lines_i].point_fin);
        }
    }
    // timer end
    end = clock();
    cpu_time_alg1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    





    // for linea in lineas  Do Algorithm 2
    // timer start
    start = clock();
    for(times_i = 0; times_i < times; times_i++){
    //some setup stuff
        for(lines_i = 0; lines_i < n_lines; lines_i++){
            // drawLine(lines[lines_i].point_ini , lines[lines_i].point_fin);
        }
    }
    // timer end
    end = clock();
    cpu_time_alg2 = ((double) (end - start)) / CLOCKS_PER_SEC;





    // for linea in lineas Do Algorithm 3
    // timer start
    start = clock();
    for(times_i = 0; times_i < times; times_i++){
    //some setup stuff
        for(lines_i = 0; lines_i < n_lines; lines_i++){
            // drawLine(lines[lines_i].point_ini , lines[lines_i].point_fin);
        }
    }
    // timer end
    end = clock();
    cpu_time_alg3 = ((double) (end - start)) / CLOCKS_PER_SEC;






    // for linea in lineas  Do Algorithm 4
    // timer start
    start = clock();
    for(times_i = 0; times_i < times; times_i++){
    //some setup stuff
        for(lines_i = 0; lines_i < n_lines; lines_i++){
            // drawLine(lines[lines_i].point_ini , lines[lines_i].point_fin);
        }
    }
    // timer end
    end = clock();
    cpu_time_alg4 = ((double) (end - start)) / CLOCKS_PER_SEC;

}