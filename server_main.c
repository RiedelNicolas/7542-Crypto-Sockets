//
// Created by riedel on 13/10/20.
//

#include  "server.h"

int main(int argc, char** argv){
    Server  server;
    char mensaje[50];
    serverInit(&server);
    serverBindAndListen(&server,argv[1],10);
    serverAcceptOne(&server);
    serverRecv(&server,mensaje,50);
    printf("recibido : %s ", mensaje);
    return 0;
}