//
// Created by riedel on 12/10/20.
//

#include "common_Socket.h"
#define FAILURE -1
#define SUCCESS 0
#define INVALID_FD -1

void socketInit(Socket* this){
    this->fd = INVALID_FD;
}
void socketUninit(Socket* this){
    if(this->fd !=INVALID_FD){
        shutdown(this->fd,);
        close(this->fd);
    }
}


int socketConnect(Socket*, const char* host, const char* port ){
    struct addrinfo hints, *result, *current;
    int error,fd;
    memset(&hints, 0, sizeof(hints) );
    error = getaddrinfo(host,port,&hints,&result);
        if(error != 0){
            fprintf(stderr,"error en getaddrinfo:%s\n",gai_strerror(error));
            return FAILURE;
        }

    for (current = result; current !=NULL ; current->ai_next) {
        fd = socket(current->ai_family,current->ai_socktype,current->ai_protocol);
        if(fd==INVALID_FD) {
            continue;
        }
        if(fd==NULL){
            fprintf(stderr,"Unable to connect\n");
            freeaddrinfo(result);  return FAILURE;
        }
    }
    freeaddrinfo(result); return SUCCESS;
}
