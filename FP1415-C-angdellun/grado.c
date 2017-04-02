/*
 * grado.c
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#include "grado.h"
#include <string.h>

int inicializaGrado(PGrado res, const Cadena nombre, const Cadena centro,
	const ArrayAsignaturas obligatorias, int numObligatorias,
	const ArrayAsignaturas optativas, int numOptativas,
	double minimoCreditosOptativas){

    if(!checkMinimoCreditosOptativas(minimoCreditosOptativas, optativas, numOptativas)){
	printf("Error con el numero de creditos minimo de las asignaturas optativas");
	return -1;
    }
    if(!checkOptativasTodasIgualesCreditos(optativas, numOptativas)){
	printf("Error con el numero de creditos minimo de las asignaturas optativas");
	return -1;
    }

    strcpy(res-> nombre, nombre);
    strcpy(res-> centro, centro);
    copiaArray(res-> obligatorias, obligatorias, numObligatorias);
    res-> numObligatorias, numObligatorias;
    copiaArray(res-> optativas, optativas, numOptativas);
    res-> numOptativas, numOptativas;
    res-> minimoCreditosOptativas, minimoCreditosOptativas;
    return 0;
}

void muestraGrado(Grado g){

    printf("Nombre: %s\n", g.nombre);
    printf("Centro: %s\n", g.centro);
    printf("Mínimo créditos optativas: %lf", g.minimoCreditosOptativas);
    printf("Asignaturas obligatorias: \n");
    muestraAsignaturas(g.obligatorias, g.numObligatorias);
    printf("Asignaturas optativas:\n");
    muestraAsignaturas(g.optativas, g.numOptativas);

}


Logico checkMinimoCreditosOptativas(double minimoCreditosOptativas, const ArrayAsignaturas optativas, int numOptativas){
    double suma = sumaCreditos(optativas, numOptativas);
    return minimoCreditosOptativas >= 0 && minimoCreditosOptativas <= suma;
}
double sumaCreditos(const ArrayAsignaturas optativas, int numOptativas){
    double suma = 0.0;
    int i ;
    for(i = 0; i< numOptativas; i++){
	suma += optativas[i].creditos;
    }
    return suma;
}

Logico checkOptativasTodasIgualesCreditos(const ArrayAsignaturas optativas, int numOptativas){
    Logico res = CIERTO;
    int i;

    for(i = 0; i< numOptativas; i++){
	if(optativas[i].creditos!= optativas[0].creditos){
	    res = FALSO;
	    break;
	}
    }
    return res;
}

void copiaArray(ArrayAsignaturas destino, const ArrayAsignaturas origen, int numElem){
    int i;

    for(i = 0; i< numElem; i++){
	destino[i] = origen [i];
    }
}

