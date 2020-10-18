//
// Created by riedel on 12/10/20.
//


#include "client_Courier.h"
#include <stdlib.h>


void CourierInit(FileReader* self){
    self->file = stdin;
}


void CourierUninit(FileReader* self) {
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




