//
// Created by riedel on 12/10/20.
//

#ifndef CLIONPROJECTS_FILE_READER_H
#define CLIONPROJECTS_FILE_READER_H

#include <stdio.h>

#define INITIAL_BUFFER_SIZE 64

typedef struct {
    FILE* file;
}file_reader_t;


/* Constructor para leer de un archivo de texto
 * devuelve 0 si se pudo abrir correctamente el archivo, devuelve
 -1 en caso contrario */
int file_reader_path_init(file_reader_t* self,char* path);

/*
 * Inicia el reader en stdin, lo carga en un buffer interno.
 */
void file_reader_standard_init(file_reader_t* self);

/*
 * Lee del File* asociado el reader, lee hasta llenar el buffer o que finaliza el archivo.
 * devuelve cuantos caracteres pudo leer correctamente.
 */
size_t file_reader_read(file_reader_t* self, char* buffer, size_t size);

/*
 * destructor, libera recursos.
 */
void file_reader_uninit(file_reader_t* self);




#endif //CLIONPROJECTS_FILE_READER_H
