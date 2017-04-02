/*
 * testCentro.c
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#include "testCentro.h"


int main(void)
    {

    testInicializaCentro1();
    testInicializaCentro2();
    testInicializaCentro3();

    testConteosEspacios();

    return 0;
    }

void testInicializaCentro1()
    {
    printf("*********************INICIALIZANDO CENTRO1**********************");

    Centro result;
    ArrayEspacios espacios;

    int res = inicializaCentro(&result, "ETSI", "REINA MERCEDES", 5, 1,
	    espacios, 6);

    if (res == -1)
	{
	printf("CENTRO NO VALIDO");
	}
    else
	{
	printf("CentroValido");
	muestraCentro(result);
	}
    }

void testInicializaCentro2()
    {
    printf(
	    "*********************INICIALIZANDO CENTRO ------>>>>>> numero de plantas negativo**********************");

    Centro result;
    ArrayEspacios espacios;

    int res = inicializaCentro(&result, "ETSI", "REINA MERCEDES", -5, 1,
	    espacios, 6);

    if (res == -1)
	{
	printf("CENTRO NO VALIDO");
	}
    else
	{
	printf("CentroValido");
	muestraCentro(result);
	}
    }

void testInicializaCentro3()
    {
    printf(
	    "*********************INICIALIZANDO CENTRO3-------->>>>>>>>>> numero de Sotanos no Validos**********************");

    Centro result;
    ArrayEspacios espacios;

    int res = inicializaCentro(&result, "ETSI", "REINA MERCEDES", 5, -1,
	    espacios, 6);

    if (res == -1)
	{
	printf("CENTRO NO VALIDO");
	}
    else
	{
	printf("CentroValido");
	muestraCentro(result);
	}
    }

void testConteosEspacios()
    {
    ArrayEspacios espacios;
    int numEsp = 0;
    ArrayInt c;

    Espacio result1;

    int res = inicializaEspacio(&result1, "A2.12", 3, LABORATORIO, 100);

    Espacio result2;

    int res2 = inicializaEspacio(&result2, "A2.11", 3, TEORIA, 100);

    Espacio result3;
    int res3 = inicializaEspacio(&result3, "A2.13", 3, SEMINARIO, 100);

    espacios[0] = result1;
    espacios[1] = result2;
    espacios[2] = result3;

    printf("\nCUENTA CADA TIPO DE ESPACIO");

    getConteosEspacios(espacios, numEsp, c);
    }

