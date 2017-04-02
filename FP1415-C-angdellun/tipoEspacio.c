/*
  * tipoEspacio.c
 *
 *  Created on: 10/5/2015
 *      Author: Angel
 */

#include <string.h>
#include "tipoEspacio.h"


void deTipoEspacioACadena(Cadena res, TipoEspacio tipo){
//TEORIA, LABORATORIO, SEMINARIO, OTRO
    switch(tipo){
    case TEORIA:
	strcpy(res, "TEORIA");
	break;
    case LABORATORIO:
	strcpy(res, "LABORATORIO");
	break;
    case SEMINARIO:
	strcpy(res, "SEMINARIO");
	break;
    case EXAMEN:
	strcpy(res, "EXAMEN");
	break;
    case OTRO:
	strcpy(res, "OTRO");
	break;
    default:
	break;
    }

}


int deCadenaATipoEspacio(const Cadena tipo, TipoEspacio *res){
//    TEORIA, LABORATORIO,
//    SEMINARIO, EXAMEN y OTRO
    if(strcmp(tipo, "TEORIA")==0){
	*res = TEORIA;
    } else if (strcmp(tipo, "LABORATORIO")==0){
	*res = LABORATORIO;
    } else if(strcmp(tipo, "SEMINARIO")==0){
	*res =  SEMINARIO;
    } else if(strcmp(tipo, "EXAMEN")==0){
	*res = EXAMEN;
    } else if (strcmp(tipo, "OTRO")==0){
	*res = OTRO;
    } else {
	return -1;
    }

    return 0;
}

