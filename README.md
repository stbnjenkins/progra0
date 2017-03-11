# Proyecto programado 0

Este proyecto consiste en comparar el tiempo que toman diferentes algoritmos para dibujar lineas rectas,
tanto dibujando las lineas, como solo calculando las coordenadas de cada punto que pertence a la recta.

## Algoritmos

### Algoritmo 1

El primer algoritmo consiste básicamente en utilizar la ecuación de una linea recta `y=mx + b` para 
obtener para cada `x` su respectiva `y`.

### Algoritmo 2

El segundo algoritmo es una variación incremental del algoritmo 1, en la cual simplemente se va sumando en cada iteración la pendiente.

### Algoritmo 3

El algoritmo 3 es otra versión aún más mejorada en la cual se van haciendo suman incrementales en ambas dimensiones en cada iteración.

### Algoritmo 4 (Bresenham)

El famoso algoritmo de Bresenham.

## Ejecucion del programa

Hay dos versiones del programa, una que dibuja las líneas y otra que solamente calcula las coordenadas.
Ambos programas imprimen en consola el tiempo de ejecución de cada algoritmo. 

Para ejecutar el progama, 

    <programa> <resolucion> <numero de lineas> <veces> <plottear>

- resolucion: tamaño de la ventana donde se van a dibujar las líneas.
- numero de líneas: número de líneas a ser dibujadas.
- veces: número de veces que se va a calcular/dibujar las líneas.
- plottear: bandera booleana (0 ó 1) que indica si se va a querer plottear las líneas.
