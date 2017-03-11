#include <stdio.h>
#include <stdlib.h>

#include "plot.c"
#include "lines_executor.c"

//Run the window
void window_runner(int res, int n_lines, int times) {
    //starting window
    char *myargv[1];
    int myargc=1;
    myargv [0]=strdup ("Plot");
    glutInit(&myargc, myargv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(res,res);
    glutCreateWindow("Plot");
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-0.5, res +0.5, -0.5, res + 0.5);
    line_exec(res,n_lines,times,1);
//  glutDisplayFunc(dummy);
    glutMainLoop();
}

int main(int argc, char **argv){
    int res, n_lines, times, doplot; 

    // get parameters
    if (argc != 5) {
        printf("Usage <program> <resolution> <number_lines> <times> <plot>\n");
        return -1;
    }  


    // Get parameters
    res = (int) atoi(argv[1]);
    n_lines = (int) atoi(argv[2]);
    times = (int) atoi(argv[3]);
    doplot = (int) atoi(argv[4]);

    // check times and n_lines are positive integers
    if(!(n_lines > 0 && times > 0 && (doplot == 1 || doplot == 0))){
        printf("<number_lines> and <times> must be POSITIVE integers, and <doplot> must be either 0 or 1\n");
        return -1;
    }

    //initialzing buffer
    ini_buffer(res);

    //Executing Window
    if (doplot == 1){
        window_runner(res,n_lines,times);
    } else {
        line_exec(res,n_lines,times,0);
    }
}