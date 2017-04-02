/*
 * grado.h
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#ifndef GRADO_H_
#define GRADO_H_

#include "asignatura.h"
#include "cadena.h"

typedef struct
    {
	Cadena nombre;
	Cadena centro;
	ArrayAsignaturas obligatorias;
	int numObligatorias;
	ArrayAsignaturas optativas;
	int numOptativas;
	double minimoCreditosOptativas;
	TipoAsignatura tipo;

    } Grado;

typedef Grado *PGrado;
int inicializaGrado(PGrado res, const Cadena nombre, const Cadena centro,
	const ArrayAsignaturas obligatorias, int numObligatorias,
	const ArrayAsignaturas optativas, int numOptativas,
	double minimoCreditosOptativas);

void muestraGrado(Grado g);

/* FUNCIONES AUXILIARES */

Logico checkMinimoCreditosOptativas(double minimoCreditosOptativas,
	const ArrayAsignaturas optativas, int numOptativas);
double sumaCreditos(const ArrayAsignaturas optativas, int numOptativas);
Logico checkOptativasTodasIgualesCreditos(const ArrayAsignaturas optativas,
	int numOptativas);
void copiaArray(ArrayAsignaturas destino, const ArrayAsignaturas origen, int numElem);
#endif /* GRADO_H_ */
