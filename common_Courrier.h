//
// Created by riedel on 12/10/20.
//

#ifndef CLIONPROJECTS_COMMON_COURRIER_H
#define CLIONPROJECTS_COMMON_COURRIER_H

#include <stdio.h>

#define SOURCE stdin
#define INITIAL_BUFFER_SIZE 64

typedef struct{
    size_t leidos;
}Courrier;


/*
 * Inicia la cantidad de elementos leidos en 0.
 */
void courrierInit(Courrier* self);

/*
 * Lee del File* asociado el reader, lee hasta llenar el buffer o que finaliza el archivo.
 * devuelve cuantos caracteres pudo leer correctamente.
 */
size_t courrierRun(Courrier* self, char* buffer, size_t size);

/*
 * destructor, libera recursos.
 */
void fileReaderUninit(FileReader* self);




#endif //CLIONPROJECTS_COMMON_COURRIER_H
