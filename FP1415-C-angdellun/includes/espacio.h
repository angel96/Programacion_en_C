/*
 * espacio.h
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#ifndef ESPACIO_H_
#define ESPACIO_H_

#include "cadena.h"
#include <string.h>
#include "tipoEspacio.h"
#include "logico.h"

#define MAXESP 200

typedef struct
    {
	Cadena nombre;
	int planta;
	TipoEspacio tipo;
	int capacidad;
    } Espacio;

typedef Espacio *PEspacio;
typedef Espacio ArrayEspacios[MAXESP];

int
inicializaEspacio(PEspacio res, const Cadena nombre, int planta,
	TipoEspacio tipo, int capacidad);
int
leeEspacioTeclado(PEspacio res);

void
muestraEspacio(Espacio e);

int
leeEspaciosTeclado(ArrayEspacios res);

void
muestraEspacios(const ArrayEspacios res, int nEspacios);

int
leeEspaciosFichero(const Cadena nombreFichero, ArrayEspacios res);

void leeEspacioFichero(FILE *f, PEspacio a);

Logico checkCapacidad(int capacidad);

#endif /* ESPACIO_H_ */
