//
// Created by riedel on 13/10/20.
//

#ifndef SERVER_H_
#define SERVER_H_
#include "common_Socket.h"

typedef struct {
    Socket socket;
    Socket peer;
}Server;

void serverInit(Server* this);
int serverBindAndListen(Server*  this, const char* port, int max_listen);
void serverAcceptOne(Server* this);
ssize_t serverRecv(Server* this, char* buffer, size_t len);
void serverUninit(Server* this);

#endif  // SERVER_H_

