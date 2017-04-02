/*
 * espacio.c
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#include "espacio.h"
#include "tipoEspacio.h"
#include <ctype.h>
#include <string.h>
#include "cadena.h"

int inicializaEspacio(PEspacio res, const Cadena nombre, int planta,
	TipoEspacio tipo, int capacidad)
    {

    if(!checkCapacidad(capacidad)){
	printf("Capacidad no admitida\n");
	return -1;
    }

    strcpy(res->nombre, nombre);
    res->planta = planta;
    res->tipo =  tipo;
    res->capacidad = capacidad;

    return 0;
    }

Logico checkCapacidad(int capacidad){
    Logico res = CIERTO;
    if(!(capacidad>0)){
	res = FALSO;
    }
    return res;
}

void muestraEspacios(const ArrayEspacios res, int nEspacios)
    {

    int i;

    for (i = 0; i < nEspacios; i++)
	{
	printf("Espacio numero %d.\n", i + 1);
	muestraEspacio(res[i]);
	printf("============================\n");
	}
    }
int leeEspacioTeclado(PEspacio res)
    {
    Cadena nombre, tipoCadena;
    int planta, capacidad;
    TipoEspacio tipo;
    printf("Introduce el nombre: ");
    fflush(stdout);
    gets(nombre);

    printf("Introduce la planta:  ");
    fflush(stdout);
    scanf("%d", planta);

    printf("Introduce la capacidad:  ");
    fflush(stdout);
    scanf("%d", capacidad);
    printf(
	    "Introduce el tipo de Espacio: (TEORIA,LABORATORIO,SEMINARIO,EXAMEN,OTRO");
    fflush(stdout);
    gets(tipoCadena);
    if (deCadenaATipoEspacio(tipoCadena, &tipo) == -1)
	{
	return -1;
	}
    return inicializaEspacio(res, nombre, planta, tipo, capacidad);
    }

void muestraEspacio(Espacio e)
    {
    Cadena tipo;
    printf("Nombre: %s\n", e.nombre);
    printf("Planta: %d\n", e.planta);
    deTipoEspacioACadena(tipo, e.tipo);
    printf("Tipo: %s\n", tipo);
    printf("Capacidad: %d\n", e.capacidad);
    }

int leeEspaciosTeclado(ArrayEspacios res)
    {
    int n;
    int i;
    int error;
    char c;
    printf("Introduce número total de Espacios: ");
    fflush(stdout);
    scanf("%d%c", &n, &c);
    while (n <= 0 || n > MAXESP)
	{
	printf("Valor incorrecto. Introduce numero total de espacios: ");
	scanf("%d%c", &n, &c);
	}
    for (i = 0; i < n; i++)
	{
	printf("Leyendo espacios número %d...\n", i + 1);
	fflush(stdout);
	error = leeEspacioTeclado(&res[i]);
	while (error == -1)
	    {
	    printf("Error, volviendo a leer espacio número %d...\n", i + 1);
	    fflush(stdout);
	    error = leeEspacioTeclado(&res[i]);
	    }
	}
    return n;
    }
int leeEspaciosFichero(const Cadena nombreFichero, ArrayEspacios res)
    {
    FILE* f;
    int i = 0;
    int n;
    f = fopen(nombreFichero, "r");
    if (f == NULL)
	{
	printf("El fichero %s no existe", nombreFichero);
	n = 0;
	}
    else
	{
	leeEspacioFichero(f, &res[i]);
	while (!feof(f) && i < MAXESP - 1)
	    {
	    i++;
	    leeEspacioFichero(f, &res[i]);
	    }
	n = i + 1;
	fclose(f);
	}
    return n;
    }

void leeEspacioFichero(FILE *f, PEspacio a)
    {
    Cadena tipo;
    char c;


    fgets(a->nombre, MAXCAR, f);
    quitaSaltoDeLinea(a->nombre);

    fscanf(f, "%d%c", &a->planta, &c);


    fgets(tipo, MAXCAR, f);
        quitaSaltoDeLinea(tipo);
        deCadenaATipoEspacio(tipo, &(a->tipo));

    fscanf(f, "%d%c", &a->capacidad, &c);


    }

