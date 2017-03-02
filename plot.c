#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "helpers.c"
#include "rgb.h"

COLOR **buffer;

void Plot(int x,int y){

    if (Type) {
        //Plot Mode

    } else {
        //Printing Mode
        printf("(%d, %d)", x, y);
    }
}

void plot_point() {
  static int last_x = 0;
  int i, j;
  COLOR color;

  for (i = 0; i < last_x; i++) 
      {
       for (j = 0; j < V_SIZE; j++) 
           {
            glColor3f (buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
            glBegin (GL_POINTS);
            glVertex2i (i,j);
            glEnd();
           }
      }

  for (i = last_x; i < H_SIZE; i++) 
      {
       for (j = 0; j < V_SIZE; j++) 
         {
          buffer[i][j].r = (double)(i % (H_SIZE / 10)) / (double)(H_SIZE / 10);
          buffer[i][j].g = (double)(j % (V_SIZE / 10)) / (double)(V_SIZE / 10);
          buffer[i][j].b = (double)(i) / (double)(H_SIZE);
          glColor3f (buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
          glBegin(GL_POINTS);
          glVertex2i(i,j);
          glEnd();
          last_x = i;
         }
      }

  glFlush();
}

void ini_frame(int argc, char** argv) {
  int i, j;

  buffer = (COLOR **)malloc(H_SIZE * sizeof(COLOR*));
  for (i = 0; i < H_SIZE; i++) 
      {
       buffer[i] = (COLOR *)malloc(V_SIZE * sizeof(COLOR));
      }

  for (i = 0; i < H_SIZE; i++) 
      {
       for (j = 0; j < V_SIZE; j++) 
           {
            buffer[i][j].r = 0;
            buffer[i][j].g = 0;
            buffer[i][j].b = 0;
           }
      }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(H_SIZE,V_SIZE);
  glutCreateWindow("Plot");
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-0.5, H_SIZE +0.5, -0.5, V_SIZE + 0.5);
  glutDisplayFunc(plot_point);
  glutMainLoop();
}

