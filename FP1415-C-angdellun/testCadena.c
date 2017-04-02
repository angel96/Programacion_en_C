/*
 * testCadena.c
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#include "cadena.h"
#include <stdio.h>

void testQuitaSaltoCadena(Cadena c);
void mostrarCaracteres(const Cadena c);

int main(void)
    {
    Cadena conSalto = "Hola mundo!\n";
    Cadena sinSalto = "Adios Mundo!";

    printf("PRUEBA 1 - Cadena CON salto de linea");

    testQuitaSaltoCadena(conSalto);

    printf("PRUEBA 2 - Cadena SIN salto de linea");

    testQuitaSaltoCadena(sinSalto);

    }

void testQuitaSaltoCadena(Cadena c){
    quitaSaltoDeLinea(c);
    mostrarCaracteres(c);
}
void mostrarCaracteres(const Cadena c){
    int i;
    int lon = strlen(c);
    printf("(%d)", lon);
    for(i = 0; i< lon; i++){
	printf("-%c-", c[i]);
    }
    printf("\n");
}


