//
// Created by riedel on 12/10/20.
//

#ifndef CLIONPROJECTS_CLIENT_Courier_H
#define CLIONPROJECTS_CLIENT_Courier_H

#include <stdio.h>
#include "client.h"
#include "common_Encrypter.h"

#define SOURCE stdin
#define INITIAL_BUFFER_SIZE 64

typedef struct Courier{
    size_t leidos;
}Courier;


/*
 * Inicia
 */
void CourierInit(Courier* self);

/*
 * Lee del File* asociado el reader, lee hasta llenar el buffer o que finaliza el archivo.
 * devuelve cuantos caracteres pudo leer correctamente.
 */
size_t CourierRun(Courier* self, char* buffer, size_t size);

/*
 * destructor, libera recursos.
 */
void fileReaderUninit(FileReader* self);




#endif //CLIONPROJECTS_CLIENT_Courier_H
