/*
 * testTipoEspacio.c
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#include "cadena.h"
#include "tipoEspacio.h"
#include <stdio.h>

void testConvierteCadena(TipoEspacio tipo){
    Cadena res;
    deTipoEspacioACadena(res, tipo);
    printf("Cadena para %d: %s\n", tipo, res);
}

void testTipoEspacioCadena(const Cadena tipoCad){
    TipoEspacio tipo;
    int res;

    res = deCadenaATipoEspacio(tipoCad, &tipo);
    if(res == 0){
	printf("Tipo %d para cadena %s\n", tipo, tipoCad);
    } else {
	printf("Error convirtiendo cadena\n");
    }
}

int main(void){
    printf("\nTESTEANDO FUNCIONES TIPO ESPACIO...\n");
    printf("\n----------------------------------------");

    printf("testConvierteteCadena\n");

    testConvierteCadena(TEORIA);
    testConvierteCadena(LABORATORIO);
    testConvierteCadena(SEMINARIO);
    testConvierteCadena(EXAMEN);
    testConvierteCadena(OTRO);

    printf("\nAl contrario");
    printf("---------------------\n");
    testTipoEspacioCadena("TEORIA");
    testTipoEspacioCadena("LABORATORIO");
    testTipoEspacioCadena("SEMINARIO");
    testTipoEspacioCadena("EXAMEN");
    testTipoEspacioCadena("OTRO");
    testTipoEspacioCadena("?");
    return 0;
}

