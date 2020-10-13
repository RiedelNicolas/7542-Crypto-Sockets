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

typedef struct{
    int fd;
}Socket;

void socketInit(Socket* this);
void socketUninit(Socket* this);
void socketBindAndListen(Socket* this,const char* host, const char* port );
void socketAccept(Socket* this, Socket* peer);
int socketConnect(Socket*, const char* host, const char* port );
size_t socketSend(Socket* self, const char* buffer, size_t len);
size_t socketRecv(Socket* self, char* buffer, size_t len);

#endif //CLIONPROJECTS_COMMON_SOCKET_H

