//
// Created by riedel on 12/10/20.
//

#ifndef CLIONPROJECTS_COMMON_SOCKET_H
#define CLIONPROJECTS_COMMON_SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>

typedef struct{
    int fd;
}Socket;

void socketInit(Socket* this);
void socketUninit(Socket* this);
void socketBindAndListen(Socket* this);
void socketAccept(Socket* this, Socket* peer);
void socketConnect(Socket*, const char* host, const char* service );
size_t socketSend(Socket* self, const char* buffer, size_t len);
size_t socketRecv(Socket* self, char* buffer, size_t len);


void

#endif //CLIONPROJECTS_COMMON_SOCKET_H

