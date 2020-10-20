//
// Created by riedel on 12/10/20.
//

#ifndef CLIENT_COURIER_H_
#define CLIENT_COURIER_H_

#include <stdio.h>
#include "client.h"
#include "common_Encrypter.h"

#define SOURCE stdin
#define INITIAL_BUFFER_SIZE 64

typedef struct Courier {
    Encrypter encrypter;
    Client  client;
}Courier;


/*
 * Iniciamos
 */
int courierInit(Courier* this, char* method, char* key, char* host, char* port);



/*
 * Lee del File* asociado el reader, lee hasta llenar el buffer o que finaliza el archivo.
 * devuelve cuantos caracteres pudo leer correctamente.
 */
void courierRun(Courier* this, char* buffer, size_t bufferSize);

/*
 * destructor, libera recursos.
 */
void courierUninit(Courier* this);




#endif  // CLIENT_COURIER_H_
