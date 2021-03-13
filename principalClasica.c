/***
*
* Universidad Sergio Arboleda
* Escuela de Ciencias Exactas e Ingeniería
* Ciencias de la Computación e Inteligencia Artificial
* Autores: Salazar Lady - Vejarano Luis - Parrado Jessica - Pinilla Michael
* Correos:  lady.salazar01@correo.usa.edu.co, luis.vejarano01@correo.usa.edu.co, michael.pinilla01@correo.usa.edu.co, jessica.parrado01@correo.usa.edu.co
* Fecha: MARZO/2021
*
* Título: Multiplicación de Matrices Clásica y con Transpuesta
*
***/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "modulo.h"

/*
Definir la asignación de la memoria estática
*/
#define SIZE (1024*1024*64*3)
static double MEM_CHUNK[SIZE];

/*
* Función que realiza la multiplicación de matrices normal, utilizando punteros, omp y modulo.h
*/
void multiplicacion (int hilos,double *a, double *b, double *c, int N){

    int i,j,k;
    omp_set_num_threads(hilos); //Número de hilos en que se divide teniendo en cuenta el número entregado por consola
#pragma omp parallel
{
#pragma omp master // Se activa el hilo maestro que ejecuta la acción
    initMatrix(N,a,b,c);

#pragma omp for

     for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            double *auxA, *auxB, suma = 0;
            auxA = a+(i*N);
            auxB = b+j;
            for(k=0; k<N; k++, auxA++, auxB+=N){
                suma += (*auxA * *auxB);
            }
            c[i*N+j] = suma;
        }
    }


}

}

/*
* Función principal donde se guarda los valores entregados por consola, se inicializa los punteros,
* se llama a las funciones de multiplicación e inicialización de matrices
*/
int main (int argc, char **argv){
    //Tamaño de la matriz
    int N = (int) atof(argv[1]); argc--; argv++;


    int hilos = (int) atof(argv[1]); argc--; argv++;
    //Inicializar punteros
    double *a;
    double *b;
    double *c;

    a = MEM_CHUNK; //Apunta al primer elemento de MEM_CHUNK
    b = a + N*N;
    c = b + N*N;

    //Toma de tiempo para cuando comience con la multiplicación y la división de los procesos con hilos
    sample_start();
    multiplicacion(hilos, a,b,c,N);
    sample_stop();
    /* Imprime el tiempo de ejecucion */
    sample_end();

/*
    impresion(N,a);

    printf("\n\n");
    impresion(N,b);
    printf("\n\n");
    impresion(N,c);
*/

}
