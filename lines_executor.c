#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pointNode.c"
#include "algoritmo1.c"
#include "algoritmo2.c"
#include "algoritmo3.c"
#include "Bresenham.c"
#include "lineNode.c"
#include "generator.c"

int line_exec(int res, int n_lines, int times, int doplot){
    int times_i, lines_i, i;
    clock_t start, end;
    double cpu_time_alg1, cpu_time_alg2, cpu_time_alg3, cpu_time_alg4;


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
    if (doplot==1) {
        plot_framebuffer(res);
    }

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
    if (doplot==1) {
        plot_framebuffer(res);
    }


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
    if (doplot==1) {
        plot_framebuffer(res);
    }


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
    if (doplot==1) {
        plot_framebuffer(res);
    }

}