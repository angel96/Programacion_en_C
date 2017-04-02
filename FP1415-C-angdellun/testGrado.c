/*
 * testGrado.c
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#include <stdio.h>

#include "testGrado.h"
#include <stdio.h>

int main(void){
    testInicializaGrado1();
    testInicializaGrado2();
    testInicializaGrado3();
    return 0;
}
void testInicializaGrado1(){
    printf("testInicializaGrado1 --- numero muy grande de creditos");

    ArrayAsignaturas obligatorias;
    int numObligatorias;

    ArrayAsignaturas optativas;
    int numOptativas;

    Grado g;
    int res;
    numObligatorias =  leeAsignaturasFichero("res/asignaturas.txt", obligatorias);
    numOptativas = leeAsignaturasFichero("res/asignaturas.txt", optativas);

    res = inicializaGrado(&g, "test", "test", obligatorias, numObligatorias, optativas, numOptativas, 120.0);

    if(res == -1){
	printf("Problema al crear el grado");
    } else {
	printf("Grado creado correctamente");
    }


}

void testInicializaGrado2(){
    printf("testInicializaGrado2 --- numero distinto");

    ArrayAsignaturas obligatorias;
    int numObligatorias;

    ArrayAsignaturas optativas;
    int numOptativas;

    Grado g;
    int res;
    numObligatorias =  leeAsignaturasFichero("res/asignaturas.txt", obligatorias);
    numOptativas = leeAsignaturasFichero("res/asignaturas.txt", optativas);
    optativas[0].creditos = 15.0;

    res = inicializaGrado(&g, "test", "test", obligatorias, numObligatorias, optativas, numOptativas, 12.0);

    if(res == -1){
	printf("Problema al crear el grado");
    } else {
	printf("Grado creado correctamente");
    }


}

void testInicializaGrado3(){
    printf("testInicializaGrado2 --- mismo numero");

    ArrayAsignaturas obligatorias;
    int numObligatorias;

    ArrayAsignaturas optativas;
    int numOptativas;

    Grado g;
    int res;
    numObligatorias =  leeAsignaturasFichero("res/asignaturas.txt", obligatorias);
    numOptativas = leeAsignaturasFichero("res/asignaturas.txt", optativas);

    res = inicializaGrado(&g, "test", "test", obligatorias, numObligatorias, optativas, numOptativas, 12.0);

    if(res == -1){
	printf("Problema al crear el grado");
    } else {
	printf("Grado creado correctamente");
	muestraGrado(g);
    }


}
