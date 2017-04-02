/*
 * testTipoAsignatura.c
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */
#include "tipoAsignatura.h"
#include <stdio.h>
#include "cadena.h"

void testConvierteCadena(TipoAsignatura tipo){
    Cadena res;
    deTipoAsignaturaACadena(res, tipo);
    printf("Cadena para %d: %s\n", tipo, res);
}

void testTipoAsignaturaCadena(const Cadena tipoCad){
    TipoAsignatura tipo;
    int res;

    res = deCadenaATipoAsignatura(tipoCad, &tipo);
    if(res == 0){
	printf("Tipo %d para cadena %s\n", tipo, tipoCad);
    } else {
	printf("Error convirtiendo cadena\n");
    }
}

int main(void){
    printf("\nTESTEANDO FUNCIONES TIPO ASIGNATURA...\n");
    printf("\n----------------------------------------");

    printf("testConvierteteCadena\n");

    testConvierteCadena(ANUAL);
    testConvierteCadena(PRIMER_CUATRIMESTRE);
    testConvierteCadena(SEGUNDO_CUATRIMESTRE);

    printf("\nAl contrario");
    printf("---------------------\n");
    testTipoAsignaturaCadena("ANUAL");
    testTipoAsignaturaCadena("PRIMER_CUATRIMESTRE");
    testTipoAsignaturaCadena("SEGUNDO_CUATRIMESTRE");
    testTipoAsignaturaCadena("?");
}
