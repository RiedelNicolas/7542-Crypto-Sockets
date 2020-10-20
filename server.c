//
// Created by riedel on 13/10/20.
//

#include "server.h"

void serverInit(Server* this) {
    socketInit(&(this->socket));
    socketInit(&(this->peer));
}

int  serverBindAndListen(Server* this, const char* port, int max_listen) {
    return socketBindAndListen(&(this->socket), port, max_listen);
}

void serverAcceptOne(Server* this) {
    socketAcceptOne(&(this->socket), &(this->peer));
}

ssize_t serverRecv(Server* this, char* buffer, size_t len) {
    return socketRecv(&(this->peer), buffer, len);
}

void serverUninit(Server* this) {
    socketUninit(&(this->socket));
    socketUninit(&(this->peer));
}
