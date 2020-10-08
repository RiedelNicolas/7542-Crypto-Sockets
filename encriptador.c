//
// Created by riedel on 7/10/20.
//
#include "encriptador.h"
#include <string.h>
#include <stdlib.h>

#define EXITO 0
#define ERROR 1

int cifrado_cesar(char* mensaje, int desplazamiento){

    size_t largo = strlen(mensaje);
    if (largo == 0) return ERROR;

    for (unsigned i = 0; i < largo; ++i) {
        mensaje[i] = mensaje[i] + desplazamiento ; //el overflow se encarga de la aritmetica modular
    }

    return EXITO;
}
