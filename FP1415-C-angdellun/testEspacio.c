/*
 * testEspacio.c
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#include "espacio.h"
#include "testEspacio.h"

int main (void){
    testInicializaEspacio1();
    testInicializaEspacio2();

    testLeeEspaciosFichero("res/espacios.txt");
    testLeeEspaciosTeclado();

    return 0;
}

void testInicializaEspacio1(){
    printf("\n=====================testInicializaEspacioNormal");

    Espacio result;

    int res = inicializaEspacio(&result, "A2.12", 3, LABORATORIO, 100);

    if(res == -1){
	printf("\n=========================Error en el espacio");
    } else {
	printf("\n=========================Espacio correcto");
	muestraEspacio(result);
    }
}

void testInicializaEspacio2(){
    printf("\n=====================testInicializaEspacioExcepcion");

        Espacio result;

        int res = inicializaEspacio(&result, "A2.12", 3, LABORATORIO, -1000);

        if(res == -1){
    	printf("\n=========================Error en el espacio");
        } else {
    	printf("\n=========================Espacio correcto");
    	muestraEspacio(result);
        }
}

void testLeeEspaciosFichero(const Cadena nombreFichero){
    printf("*** testLeeEspaciosFichero***\n");
       ArrayEspacios espacios;
       int nESP;
       nESP = leeEspaciosFichero(nombreFichero, espacios);
       muestraEspacios(espacios, nESP);
}

void testLeeEspaciosTeclado(){
    printf("*** testLeeEspaciosFichero***\n");
          ArrayEspacios espacios;
          int nESP;
          nESP = leeEspaciosTeclado(espacios);
          muestraEspacios(espacios, nESP);
}
