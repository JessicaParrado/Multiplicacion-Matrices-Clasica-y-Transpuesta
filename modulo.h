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
#ifndef MODULO_H_INCLUDED
#define MODULO_H_INCLUDED

/*Funciones para la toma de tiempos de ejecución*/
extern void sample_start();
extern void sample_stop();
extern void sample_end();

/* Funciones que se encuentran en "modulo.c"*/
void initMatrixT(int N, double *a, double *b, double *bT, double *c);
void initMatrix(int N, double *a, double *b, double *c);
void impresion(int N, double *matriz);
#endif