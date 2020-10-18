//
// Created by riedel on 12/10/20.
//


#include "client_Courier.h"
#include <stdlib.h>


int courierInit(Courier* this,char* method, char* key, char* host, char* port){
    encrypterInit(&(this->encrypter), method, key);
    clientInit(&(this->client));
    return clientConnect(&(this->client), host, port);
}

size_t courierRun(Courier* this, char* buffer, size_t bufferSize){

    if( feof(this->file) ){ //si justo se habia llegado al final del archivo.
        return 0;
    }
    return  fread(buffer,sizeof(char) ,size , self->file);

}

size_t fileReaderRead(Courier* this, char* buffer, size_t size){

    if( feof(self->file) ){ //si justo se habia llegado al final del archivo.
        return 0;
    }
    return  fread(buffer,sizeof(char) ,size , self->file);
}


void courierUninit(Courier* this) {
    if (self->file != stdin && self->file != NULL) {
        fclose(self->file);
    }
}

