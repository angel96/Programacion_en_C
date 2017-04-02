/*
 * testAsignatura.c
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#include <stdio.h>
#include "asignatura.h"
#include <string.h>
#include "cadena.h"
#include "testAsignatura.h"

int main(void)
    {

    testLeeAsignaturasFichero("./res/asignaturas.txt");
    testInicializaAsignatura1();
    testInicializaAsignatura2();
    testInicializaAsignatura3();
    testInicializaAsignatura4();
    testLeeAsignaturasTeclado();
    testGetAcronimo();

    return 0;
    }

void testLeeAsignaturasFichero(const Cadena nombreFichero)
    {
    printf("*** testLeeAsignaturasFichero***\n");
    ArrayAsignaturas asignaturas;
    int nAsig;

    nAsig = leeAsignaturasFichero(nombreFichero, asignaturas);
    muestraAsignaturas(asignaturas, nAsig);
    }

void testInicializaAsignatura1()
    {

    printf("***testInicializaAsignatura1 ---- codigo mas largo***");

    Asignatura a1;

    int res = inicializaAsignatura(&a1, "Fundamentos de Programacion",
	    "12345678", 12.0, ANUAL, 1, "LSI");

    if (res == -1)
	{
	printf("====================Problema con la inicializacion");
	}
    else
	{
	printf("====================Asignatura inicializada correctamente");
	muestraAsignatura(a1);
	}

    }

void testLeeAsignaturasTeclado()
    {
    printf("*** testLeeAsignaturasTeclado***\n");
    ArrayAsignaturas asignaturas;
    int nAsig;

    nAsig = leeAsignaturasTeclado(asignaturas);
    muestraAsignaturas(asignaturas, nAsig);
    }

void testInicializaAsignatura2()
    {

    printf("***testInicializaAsignatura2---- creditos negativos***");

    Asignatura a1;

    int res = inicializaAsignatura(&a1, "Fundamentos de Programacion",
	    "1234567", -12.0, ANUAL, 1, "LSI");

    if (res == -1)
	{
	printf("====================Problema con la inicializacion");
	}
    else
	{
	printf("====================Asignatura inicializada correctamente");
	muestraAsignatura(a1);
	}

    }

void testInicializaAsignatura3()
    {

    printf("***testInicializaAsignatura3 --- años mas de 4***");

    Asignatura a1;

    int res = inicializaAsignatura(&a1, "Fundamentos de Programacion",
	    "1234567", 12.0, ANUAL, 6, "LSI");

    if (res == -1)
	{
	printf("====================Problema con la inicializacion");
	}
    else
	{
	printf("====================Asignatura inicializada correctamente");
	muestraAsignatura(a1);
	}
    }

void testInicializaAsignatura4()
    {

    printf("***testInicializaAsignatura4***");

    Asignatura a1;

    int res = inicializaAsignatura(&a1, "Fundamentos de Programacion",
	    "1234567", 12.0, ANUAL, 1, "LSI");

    if (res == -1)
	{
	printf("====================Problema con la inicializacion");
	}
    else
	{
	printf("====================Asignatura inicializada correctamente");
	muestraAsignatura(a1);
	}

    }

void testGetAcronimo()
    {

    printf("***testgetAcronimo***");
    Asignatura a;
    Cadena acronimo;

    strcpy(a.nombre, "Fundamentos de Programacion");

    getAcronimo(a, acronimo);

    printf("El acronimo de %s es %s\n", a.nombre, acronimo);
    fflush(stdout);

    strcpy(a.nombre, "Fundamentos De Programacion");

    getAcronimo(a, acronimo);

    printf("El acronimo de %s es %s\n", a.nombre, acronimo);
    fflush(stdout);

    strcpy(a.nombre, "fundamentos de programacioN");

    getAcronimo(a, acronimo);

    printf("El acronimo de %s es %s\n", a.nombre, acronimo);
    fflush(stdout);

    strcpy(a.nombre, "fundamentos de programacion");

    getAcronimo(a, acronimo);

    printf("El acronimo de %s es %s\n", a.nombre, acronimo);
    fflush(stdout);

    }

