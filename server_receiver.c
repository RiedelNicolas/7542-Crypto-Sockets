//
// Created by riedel on 18/10/20.
//

#include "server_receiver.h"
#define MAX_LISTEN 20
#define  STDOUT stdout
#define FAILURE -1
#define SUCCESS  0

int receiverInit(Receiver* this,char* method, char* key , char* port){
    encrypterInit(&(this->encrypter), method, key);
    serverInit(&(this->server));
    int flag;
    flag =  serverBindAndListen(&(this->server), port, MAX_LISTEN);

    if( flag!= 0){
        return flag;
    }

    serverAcceptOne(&(this->server));
    return SUCCESS;
}

void receiverRun(Receiver* this, char* buffer, size_t bufferSize){

    ssize_t received;
    do{
        received = serverRecv(&(this->server),buffer,bufferSize);
        encrypterDecrypt(&(this->encrypter),buffer,received);
        fwrite(buffer,  sizeof(char),received, STDOUT);
    }while (received == bufferSize); //SI RECIBO MENOS CORTE EL BUFFER EN ALGUN MOMENTO DEL OTRO LADO.
}

void receiverUninit(Receiver* this){
    encrypterUninit(&(this->encrypter));
    serverUninit(&(this->server));
}

#include "server_receiver.h"
