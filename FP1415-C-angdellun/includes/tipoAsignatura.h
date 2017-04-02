/*
 * tipoAsignatura.h
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#ifndef TIPOASIGNATURA_H_
#define TIPOASIGNATURA_H_
#include "cadena.h"
#include <stdio.h>

typedef enum
    {
    ANUAL,
    PRIMER_CUATRIMESTRE,
    SEGUNDO_CUATRIMESTRE
    } TipoAsignatura;

void deTipoAsignaturaACadena(Cadena res, TipoAsignatura tipo);
int deCadenaATipoAsignatura(const Cadena tipo, TipoAsignatura *res);

#endif /* TIPOASIGNATURA_H_ */
