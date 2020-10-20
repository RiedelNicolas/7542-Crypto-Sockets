//
// Created by riedel on 13/10/20.
//

#include  "server_receiver.h"

#include <stdio.h>
#define SIZE_BUFFER 64

int main(int argc, char** argv){
    char buffer[SIZE_BUFFER];
    Receiver receiver;

    receiverInit(&receiver,argv[2],argv[3],argv[1]);
    receiverRun(&receiver,buffer,SIZE_BUFFER);
    receiverUninit(&receiver);

}
