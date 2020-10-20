//
// Created by riedel on 13/10/20.
//

#ifndef CLIENT_H_
#define CLIENT_H_

#include "common_Socket.h"

typedef struct {
    Socket socket;
}Client;

void clientInit(Client* this);
int clientConnect(Client*  this, const char* host, const char* port);
ssize_t clientSend(Client* this, const char* buffer, size_t len);
void clientUninit(Client* this);

#endif  // CLIENT_H_

