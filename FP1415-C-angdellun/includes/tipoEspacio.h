/*
 * tipoEspacio.h
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#ifndef TIPOESPACIO_H_
#define TIPOESPACIO_H_

#include "cadena.h"
#include <string.h>

typedef enum
    {
    TEORIA,
    LABORATORIO,
    SEMINARIO,
    EXAMEN,
    OTRO
    } TipoEspacio;

void deTipoEspacioACadena(Cadena res, TipoEspacio tipo);
int deCadenaATipoEspacio(const Cadena tipo, TipoEspacio *res);

#endif /* TIPOESPACIO_H_ */
