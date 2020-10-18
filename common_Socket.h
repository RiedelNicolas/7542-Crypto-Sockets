//
// Created by riedel on 12/10/20.
//

#ifndef CLIONPROJECTS_COMMON_SOCKET_H
#define CLIONPROJECTS_COMMON_SOCKET_H

#define _POSIX_C_SOURCE 201112L // Habilita getaddrinfo
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include "errno.h"
typedef struct Socket{
    int fd;
}Socket;

void socketInit(Socket* this);
void socketUninit(Socket* this);
int socketBindAndListen(Socket* this, const char* port, int maxListen );
void socketAcceptOne(Socket* this, Socket* peer);
int socketConnect(Socket* this, const char* host, const char* port );
ssize_t socketSend(Socket* this, const char* buffer, size_t len);
ssize_t socketRecv(Socket* this, char* buffer, size_t len);

#endif //CLIONPROJECTS_COMMON_SOCKET_H

