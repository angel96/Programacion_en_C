/*
 * centro.c
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#include "centro.h"

int inicializaCentro(PCentro res, const Cadena nombre, const Cadena direccion,
	int numeroPlantas, int numeroSotanos, const ArrayEspacios espacios,
	int numEspacios)
    {

    if(!checkPlantas(numeroPlantas)){
	printf("El centro debe tener al menos una planta\n");
	return -1;
    }

    if(!checkSotanos(numeroSotanos)){
	printf("Numero de sotanos no valido\n");
	return -1;
    }

    strcpy(res->nombre, nombre);
    strcpy(res->direccion, direccion);

    res->numeroPlantas = numeroPlantas;
    res->numeroSotanos = numeroSotanos;
    copiaArray(res-> espacios, espacios, numEspacios);
    res->numEspacios=numEspacios;

    return 0;
    }

void copiaArray(ArrayEspacios destino, const ArrayEspacios origen, int numElem){
    int i;

    for(i = 0; i< numElem; i++){
	checkCapacidad(origen[i].capacidad);
	destino[i] = origen [i];
    }
}

Logico checkPlantas(int numeroPlantas){
    return numeroPlantas<1? FALSO:CIERTO;
}

Logico checkSotanos(int numeroSotanos){
    return numeroSotanos<0? FALSO:CIERTO;
}

void muestraCentro(Centro c)
    {

    printf("Nombre: %s\n", c.nombre);
    printf("Dirección: %s\n", c.direccion);
    printf("Número de plantas: %d\n", c.numeroPlantas);
    printf("Número de sótanos: %d\n", c.numeroSotanos);
    muestraEspacios(c.espacios, c.numEspacios);
    printf("Espacios: %s\n");

    }

void getConteosEspacios(const ArrayEspacios espacios, int numEspacios,
	ArrayInt c)
    {
    int i;


    for (i = 0; i < numEspacios; i++)
	{
	TipoEspacio e = espacios[i].tipo;
	switch (e)
	    {
	case TEORIA:
	    c[0]++;
	    break;
	case LABORATORIO:
	    c[1]++;
	    break;
	case SEMINARIO:
	    c[2]++;
	    break;
	case EXAMEN:
	    c[3]++;
	    break;
	case OTRO:
	    c[4]++;
	    break;
	default:
	    break;
	    }

	}
    }

