/*
 * cadena.c
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#include "cadena.h"
#include <string.h>
#include <stdio.h>

//strrchr --> localiza un caracter en una cadena,
//buscando desde el final

void quitaSaltoDeLinea(Cadena c)
    {

	//strlen(c) --> Dimension del array

    int n = strlen(c);

    if (c[n - 1] == '\n')
	{
	c[n - 1] = '\0';
	}

    }

