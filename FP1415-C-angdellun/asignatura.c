/*
 * asignatura.c
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#include "asignatura.h"
#include <stdio.h>
#include "cadena.h"
#include <ctype.h>
int inicializaAsignatura(PAsignatura res, const Cadena nombre,
	const TipoCodigo codigo, double creditos, TipoAsignatura tipo,
	int curso, const Cadena departamento)
    {

    if (!checkCodigo(codigo))
	{
	printf("Error en codigo de asignatura: %s\n", codigo);
	return -1;
	}
    if (!checkCreditos(creditos))
	{
	printf("Error en creditos de asignatura: %lf\n", creditos);
	return -1;
	}

    if (!checkCurso(curso))
	{
	printf("Error en curso de asignatura: %d\n");
	return -1;
	}

    strcpy(res->nombre, nombre);
    strcpy(res->codigo, codigo);
    res->tipo = tipo;
    res->curso = curso;
    res->creditos = creditos;
    strcpy(res->departamento, departamento);

    return 0;
    }

/*************************METODOS******************************************/
void getAcronimo(Asignatura a, Cadena res)
    {
    int i = 0;
    int j = 0;
    while (a.nombre[i] != '\0')
	{
	if (isupper(a.nombre[i]))
	    {
	    res[j] = a.nombre[i];
	    j++;
	    }
	i++;
	}
    res[j] = '\0';
    }

int leeAsignaturaTeclado(PAsignatura res)
    {
    Cadena nombre, codigo, departamento, tipoCadena;
    TipoAsignatura tipo;
    int curso;
    double creditos;
    char c;
    printf("Introduce el nombre: ");
    fflush(stdout);
    gets(nombre);

    printf("Introduce el codigo: ");
    fflush(stdout);
    gets(codigo);

    printf("Introduce el departamento: ");
    fflush(stdout);
    gets(departamento);

    printf(
	    "Introduce el tipo de Asignatura (ANUAL, PRIMER_CUATRIMESTRE,_SEGUNDO_CUATRIMESTRE) : ");
    fflush(stdout);
    gets(tipoCadena);

    printf("Introduce el curso: ");
    fflush(stdout);
    scanf("%d%c", &curso, &c);

    printf("Introduce los creditos: ");
    fflush(stdout);
    scanf("%lf%c", &creditos, &c);
    if (deCadenaATipoAsignatura(tipoCadena, &tipo) == -1)
	{
	return -1;
	}
    return inicializaAsignatura(res, nombre, codigo, creditos, tipo, curso,
	    departamento);
    }

void muestraAsignatura(Asignatura a)
    {
    Cadena tipo, acronimo;
    printf("Nombre: %s\n", a.nombre);

    getAcronimo(a, acronimo);
    printf("Acrónimo: %s\n", acronimo);

    printf("Código: %s\n", a.codigo);
    printf("Créditos: %lf\n", a.creditos);

    deTipoAsignaturaACadena(tipo, a.tipo);
    printf("Tipo: %s\n", tipo);

    printf("Curso: %d\n", a.curso);
    printf("Departamento: %s\n", a.departamento);
    }
int leeAsignaturasTeclado(ArrayAsignaturas res)
    {
    int n;
    int i;
    int error;
    char c;
    printf("Introduce número total de asignaturas: ");
    fflush(stdout);
    scanf("%d%c", &n, &c);
    while (n <= 0 || n > MAXASIG)
	{
	printf("Valor incorrecto. Introduce numero total de asignaturas: ");
	scanf("%d%c", &n, &c);
	}
    for (i = 0; i < n; i++)
	{
	printf("Leyendo asignatura número %d...\n", i + 1);
	fflush(stdout);
	error = leeAsignaturaTeclado(&res[i]);
	while (error == -1)
	    {
	    printf("Error, volviendo a leer asignatura número %d...\n", i + 1);
	    fflush(stdout);
	    error = leeAsignaturaTeclado(&res[i]);
	    }
	}
    return n;
    }

void muestraAsignaturas(const ArrayAsignaturas res, int nAsig)
    {

    int j;
    for (j = 0; j < nAsig; j++)
	{
	printf("Asignatura numero %d.\n", j + 1);
	muestraAsignatura(res[j]);
	printf("============================\n");
	}

    }
int leeAsignaturasFichero(const Cadena nombreFichero, ArrayAsignaturas res)
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
	leeAsignaturaFichero(f, &res[i]);
	while (!feof(f) && i < MAXASIG - 1)
	    {
	    i++;
	    leeAsignaturaFichero(f, &res[i]);
	    }
	n = i + 1;
	fclose(f);
	}
    return n;
    }

void leeAsignaturaFichero(FILE *f, PAsignatura a)
    {
    Cadena tipo, creditos;
    char c;
    double b;

    fgets(a->nombre, MAXCAR, f);
    quitaSaltoDeLinea(a->nombre);

    fgets(a->codigo, CODIGOLEN, f);
    quitaSaltoDeLinea(a->codigo);

    fgets(creditos, MAXCAR, f);
    //CONVIERTE UNA CADENA A UN ENTERO

    //PASO EL VALOR DE LA VBLE AUX. A LA VBLE DE LA ESTRUCTURA
    a->creditos = atoi(creditos);

    fgets(tipo, MAXCAR, f);
    quitaSaltoDeLinea(tipo);
    deCadenaATipoAsignatura(tipo, &(a->tipo));

    fscanf(f, "%d%c", &a->curso, &c);

    fgets(a->departamento, MAXCAR, f);
    quitaSaltoDeLinea(a->departamento);

    }

/* CHECKERS ****************************************************************/

Logico checkCodigo(const Cadena codigo)
    {
    Logico res = CIERTO;

    int i;

    if (!codigo[7] == '\0')
	{
	res = FALSO;
	}

    for (i = 0; i < 7; i++)
	{
	if (!(codigo[i] >= '0' && codigo[i] <= '9'))
	    {
	    res = FALSO;
	    break;
	    }
	}

    return res;
    }

Logico checkCreditos(double creditos)
    {
    Logico res = CIERTO;


    if(creditos<0.){
    	res = FALSO;
    }

    return res;


    }

Logico checkCurso(int curso)
    {
	Logico res = CIERTO;

	if(curso<0 || curso > 4){
		res = FALSO;
	}

    return res;
    }

