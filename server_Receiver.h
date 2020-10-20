//
// Created by riedel on 18/10/20.
//

#ifndef SERVER_RECEIVER_H_
#define SERVER_RECEIVER_H_

#include "server.h"
#include "common_Encrypter.h"
typedef struct Receiver {
    Server server;
    Encrypter  encrypter;
}Receiver;

int receiverInit(Receiver* this, char* method, char* key , char* port);

void receiverRun(Receiver* this, char* buffer, size_t bufferSize);

void receiverUninit(Receiver* this);



#endif  // SERVER_RECEIVER_H_
