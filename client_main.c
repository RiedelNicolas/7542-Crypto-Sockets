//
// Created by riedel on 13/10/20.
//

#include "client.h"

int main(int argc, char** argv){
    char mensaje[50]; strcpy(mensaje,"Ping");
    Client client;
    clientInit(&client);
    clientConnect(&client,argv[1],argv[2]);
    clientSend(&client,mensaje,strlen(mensaje) );
    clientUninit(&client);
    return 0;
}
