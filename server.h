//
// Created by riedel on 13/10/20.
//

#ifndef CLIONPROJECTS_SERVER_H
#define CLIONPROJECTS_SERVER_H
#include "common_Socket.h"

typedef struct{
    Socket socket;
    Socket peer;
}Server;

void serverInit(Server * this);
int serverBindAndListen(Server*  this, const char* port, int max_listen );
void serverAcceptOne(Server* this);
ssize_t serverRecv(Server* this, char* buffer, size_t len);
void serverUninit(Server* this);

#endif //CLIONPROJECTS_SERVER_H
