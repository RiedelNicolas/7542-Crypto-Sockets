//
// Created by riedel on 12/10/20.
//


#include "file_reader.h"
#include <stdlib.h>


void file_reader_standard_init(file_reader_t* self){
    self->file = stdin;
}

int file_reader_path_init(file_reader_t* self,char* path){
    self->file = fopen(path,"r");
    if(self ==  NULL){
        return -1;
    }
    return 0;
}

void file_reader_uninit(file_reader_t* self) {
    if (self->file != stdin && self->file != NULL) {
        fclose(self->file);
    }
}

size_t file_reader_read(file_reader_t* self, char* buffer, size_t size){

    if( feof(self->file) ){ //si justo se habia llegado al final del archivo.
        return 0;
    }

    return  fread(buffer,sizeof(char) ,size , self->file);

}




