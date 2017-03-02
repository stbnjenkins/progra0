#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pointNode.c"
#include "generator.c"
#include "algoritmo1.c"
#include "algoritmo2.c"
#include "algoritmo3.c"
#include "Bresenham.c"
#include "lineNode.c"


int main(int argc, char **argv){
    int res, n_lines, times, times_i, lines_i, i;
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

    // check times and n_lines are positive integers
    if(!(n_lines > 0 && times > 0)){
        printf("<number_lines> and <times> must be POSITIVE integers\n");
        return -1;
    }

    // printf("res: %d, lineas: %d, veces: %d\n", res, n_lines, times);
    // return 0;

    // Set seed
    srand(time(0));

    // Generar lista de lineas aleatorios
    for (i=0; i < n_lines; i++) {
        Point Ini = randPoint(res);
        Point Fin = randPoint(res);
        line_insert_node_last(Ini,Fin);
    }

    //initialzing buffer
    ini_buffer(res);

    //line_display();

    //return 0;


    // for linea in lineas Do Algorithm 1

    // timer start
    start = clock();
    for(times_i = 0; times_i < times; times_i++){
    //some setup stuff
        for (lptr = lfirst;lptr != NULL;lptr = lptr->next){
           line(lptr->point_ini, lptr->point_fin); 
        }
    }
    // timer end
    end = clock();
    cpu_time_alg1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken alg1 in seconds: %lf\n", cpu_time_alg1);
    


    // for linea in lineas  Do Algorithm 2
    // timer start
    start = clock();
    for(times_i = 0; times_i < times; times_i++){
    //some setup stuff
        for (lptr = lfirst;lptr != NULL;lptr = lptr->next){
           alg2_line(lptr->point_ini, lptr->point_fin); 
        }
    }
    // timer end
    end = clock();
    cpu_time_alg2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken alg2 in seconds: %lf\n", cpu_time_alg2);



    // for linea in lineas Do Algorithm 3
    // timer start
    start = clock();
    for(times_i = 0; times_i < times; times_i++){
    //some setup stuff
        for (lptr = lfirst;lptr != NULL;lptr = lptr->next){
           alg3_line(lptr->point_ini, lptr->point_fin); 
        }
    }
    // timer end
    end = clock();
    cpu_time_alg3 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken alg3 in seconds: %lf\n", cpu_time_alg3);



    // for linea in lineas  Do Algorithm 4
    // timer start
    start = clock();
    for(times_i = 0; times_i < times; times_i++){
    //some setup stuff
        for (lptr = lfirst;lptr != NULL;lptr = lptr->next){
           bresenham(lptr->point_ini, lptr->point_fin); 
        }
    }
    // timer end
    end = clock();
    cpu_time_alg4 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken alg4 in seconds: %lf\n", cpu_time_alg4);

    //Executing Window
    window_runner(res);
}