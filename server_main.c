//
// Created by riedel on 13/10/20.
//

#include  "server.h"

#include <stdio.h>
#define SIZE_BUFFER 64

int main(int argc, char** argv){
    char buffer[SIZE_BUFFER];
    ssize_t received;
    Server  server;
    serverInit(&server);
    serverBindAndListen(&server,argv[1],10);
    serverAcceptOne(&server);

    do{
        received = serverRecv(&server,buffer,SIZE_BUFFER);
        fwrite(buffer,  sizeof(char),received, stdout);
    }while (received == SIZE_BUFFER); //SI RECIBO MENOS CORTE EL BUFFER EN ALGUN MOMENTO DEL OTRO LADO.

    serverUninit(&server);
    return 0;
}