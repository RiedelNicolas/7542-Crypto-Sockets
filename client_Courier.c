//
// Created by riedel on 12/10/20.
//


#include "client_Courier.h"
#include <stdlib.h>
#define STDIN stdin


int courierInit(Courier* this,char* method, char* key, char* host, char* port){
    encrypterInit(&(this->encrypter), method, key);
    clientInit(&(this->client));
    return clientConnect(&(this->client), host, port);
}

size_t _courierRead(Courier* this, char* buffer, size_t bufferSize){

    if( feof(STDIN) ) { //si justo se habia llegado al final del archivo.
        return 0;
    }
    return  fread(buffer,sizeof(char) ,bufferSize , STDIN);
}

void courierRun(Courier* this, char* buffer, size_t bufferSize){
    size_t read;
    do{
        read = _courierRead(this, buffer, bufferSize);
        encrypterEncrypt(&(this->encrypter),buffer,read);
        clientSend(&(this->client), buffer, read);
    }while( read == bufferSize);

}



void courierUninit(Courier* this) {
    encrypterUninit(&(this->encrypter));
    clientUninit(&(this->client));
}

