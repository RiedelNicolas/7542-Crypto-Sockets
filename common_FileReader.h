//
// Created by riedel on 12/10/20.
//

#ifndef CLIONPROJECTS_COMMON_FILEREADER_H
#define CLIONPROJECTS_COMMON_FILEREADER_H

#include <stdio.h>

#define INITIAL_BUFFER_SIZE 64

typedef struct FileReader {
    FILE* file;
}FileReader;


/* Constructor para leer de un archivo de texto
 * devuelve 0 si se pudo abrir correctamente el archivo, devuelve
 -1 en caso contrario */
int fileReaderPathInit(FileReader* self, char* path);

/*
 * Inicia el reader en stdin, lo carga en un buffer interno.
 */
void fileReaderStandardInit(FileReader* self);

/*
 * Lee del File* asociado el reader, lee hasta llenar el buffer o que finaliza el archivo.
 * devuelve cuantos caracteres pudo leer correctamente.
 */
size_t fileReaderRead(FileReader* self, char* buffer, size_t size);

/*
 * destructor, libera recursos.
 */
void fileReaderUninit(FileReader* self);




#endif //CLIONPROJECTS_COMMON_FILEREADER_H
