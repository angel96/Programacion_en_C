/*
 * asignatura.h
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#ifndef ASIGNATURA_H_
#define ASIGNATURA_H_

#include "cadena.h"
#include "logico.h"
#include "tipoAsignatura.h"
#include <stdio.h>
#define CODIGOLEN 8
#define MAXASIG 100

typedef char TipoCodigo[CODIGOLEN];

typedef struct
    {

	Cadena nombre;
	TipoCodigo codigo;
	double creditos;
	TipoAsignatura tipo;
	int curso;
	Cadena departamento;

    } Asignatura;

typedef Asignatura *PAsignatura;
typedef Asignatura ArrayAsignaturas[MAXASIG];

int inicializaAsignatura(PAsignatura res, const Cadena nombre,
	const TipoCodigo codigo, double creditos, TipoAsignatura tipo,
	int curso, const Cadena departamento);
void getAcronimo(Asignatura a, Cadena res);
int leeAsignaturaTeclado(PAsignatura res);
void muestraAsignatura(Asignatura a);
int leeAsignaturasTeclado(ArrayAsignaturas res);
void muestraAsignaturas(const ArrayAsignaturas res, int nAsig);
int leeAsignaturasFichero(const Cadena nombreFichero, ArrayAsignaturas res);
void leeAsignaturaFichero(FILE *f, PAsignatura a);

/* Funciones Auxiliares */
Logico checkCreditos(double creditos);
Logico checkCurso(int curso);
Logico checkCodigo(const TipoCodigo codigo);

#endif /* ASIGNATURA_H_ */
