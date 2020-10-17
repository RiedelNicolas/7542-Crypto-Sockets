//
// Created by riedel on 13/10/20.
//

#include "client.h"
#include <stdio.h>
#include "common_Courrier.h"

#define SIZE_BUFFER 64

int main(int argc, char** argv){
    char buffer[SIZE_BUFFER];
    FileReader fileReader;
    fileReaderStandardInit(&fileReader);
    Client client;
    clientInit(&client);
    clientConnect(&client,argv[1],argv[2]);

    size_t leido;
    do {
        leido = fileReaderRead(&fileReader,buffer,SIZE_BUFFER);
        printf("se hizo un read");
        clientSend(&client,buffer, leido);
    }while (leido==SIZE_BUFFER);

    clientUninit(&client);
    return 0;
}
