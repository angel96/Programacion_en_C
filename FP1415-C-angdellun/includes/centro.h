/*
 * centro.h
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#ifndef CENTRO_H_
#define CENTRO_H_

#include "cadena.h"
#include "espacio.h"
#include "logico.h"

typedef struct
    {
	Cadena nombre;
	Cadena direccion;
	int numeroPlantas;
	int numeroSotanos;
	ArrayEspacios espacios;
	int numEspacios;
    } Centro;

typedef Centro *PCentro;
typedef ArrayInt[5];

int inicializaCentro(PCentro res, const Cadena nombre, const Cadena direccion, int numeroPlantas,
	int numeroSotanos, const ArrayEspacios espacios, int numEspacios);

void muestraCentro (Centro c);

void getConteosEspacios(const ArrayEspacios espacios, int numEspacios, ArrayInt c);
void copiaArray(ArrayEspacios destino, const ArrayEspacios origen, int numEspacios);

Logico checkPlantas(int numeroPlantas);
Logico checkSotanos(int numeroSotanos);


#endif /* CENTRO_H_ */
