//
// Created by riedel on 13/10/20.
//

#include "client.h"

void clientInit(Client* this) {
    socketInit(&(this->socket));
}

int clientConnect(Client*  this, const char* host, const char* port) {
    return socketConnect(&(this->socket), host, port);
}

ssize_t clientSend(Client* this, const char* buffer, size_t len) {
    return socketSend(&(this->socket), buffer, len);
}


void clientUninit(Client* this) {
    socketUninit(&(this->socket));
}
