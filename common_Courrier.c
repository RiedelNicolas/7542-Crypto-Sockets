//
// Created by riedel on 12/10/20.
//


#include "common_Courrier.h"
#include <stdlib.h>


void courrier_init(FileReader* self){
    self->file = stdin;
}

int fileReaderPathInit(FileReader* self, char* path){
    self->file = fopen(path,"r");
    if(self ==  NULL){
        return -1;
    }
    return 0;
}

void fileReaderUninit(FileReader* self) {
    if (self->file != stdin && self->file != NULL) {
        fclose(self->file);
    }
}

size_t fileReaderRead(FileReader* self, char* buffer, size_t size){

    if( feof(self->file) ){ //si justo se habia llegado al final del archivo.
        return 0;
    }
    return  fread(buffer,sizeof(char) ,size , self->file);
}




